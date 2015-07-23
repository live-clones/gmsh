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
    tAFFECTPLUS = 421,
    tAFFECTMINUS = 422,
    tAFFECTTIMES = 423,
    tAFFECTDIVIDE = 424,
    tOR = 425,
    tAND = 426,
    tEQUAL = 427,
    tNOTEQUAL = 428,
    tLESSOREQUAL = 429,
    tGREATEROREQUAL = 430,
    tPLUSPLUS = 431,
    tMINUSMINUS = 432,
    UNARYPREC = 433
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

#line 407 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 424 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   9711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  199
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  511
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1812

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   433

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   184,     2,   194,     2,   183,     2,     2,
     189,   190,   181,   179,   195,   180,   193,   182,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     175,     2,   177,   170,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   191,     2,   192,   188,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   196,     2,   197,   198,     2,     2,     2,
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
     165,   166,   167,   168,   169,   171,   172,   173,   174,   176,
     178,   185,   186,   187
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   192,   197,   199,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   222,   226,   233,   238,   243,   257,   270,   283,
     311,   325,   338,   351,   370,   375,   376,   377,   378,   379,
     383,   385,   390,   392,   398,   502,   397,   520,   527,   538,
     537,   555,   562,   573,   572,   589,   606,   629,   628,   642,
     643,   644,   645,   646,   650,   651,   657,   657,   658,   658,
     664,   665,   666,   671,   677,   737,   766,   795,   800,   805,
     810,   815,   822,   829,   844,   849,   854,   859,   864,   873,
     879,   888,   906,   924,   933,   945,   950,   958,   978,  1001,
    1012,  1020,  1042,  1065,  1091,  1112,  1124,  1138,  1138,  1140,
    1142,  1151,  1161,  1160,  1178,  1188,  1187,  1201,  1203,  1211,
    1217,  1224,  1225,  1229,  1240,  1255,  1265,  1266,  1271,  1279,
    1288,  1296,  1314,  1318,  1324,  1332,  1336,  1342,  1350,  1354,
    1360,  1368,  1372,  1378,  1387,  1390,  1403,  1406,  1416,  1439,
    1471,  1494,  1512,  1533,  1551,  1581,  1611,  1629,  1647,  1674,
    1692,  1710,  1745,  1763,  1802,  1808,  1814,  1821,  1846,  1871,
    1888,  1907,  1941,  1977,  1995,  2012,  2028,  2065,  2070,  2075,
    2080,  2085,  2090,  2113,  2119,  2130,  2131,  2136,  2139,  2143,
    2166,  2189,  2212,  2240,  2261,  2287,  2308,  2330,  2350,  2462,
    2481,  2519,  2628,  2637,  2643,  2658,  2686,  2703,  2712,  2726,
    2740,  2746,  2752,  2761,  2770,  2779,  2793,  2849,  2867,  2884,
    2899,  2918,  2930,  2954,  2958,  2963,  2970,  2975,  2981,  2986,
    2992,  3000,  3004,  3008,  3013,  3068,  3081,  3098,  3115,  3137,
    3159,  3194,  3202,  3208,  3215,  3219,  3228,  3236,  3244,  3253,
    3252,  3267,  3266,  3281,  3280,  3295,  3294,  3308,  3315,  3322,
    3329,  3336,  3343,  3350,  3357,  3364,  3372,  3371,  3385,  3384,
    3398,  3397,  3411,  3410,  3424,  3423,  3437,  3436,  3450,  3449,
    3463,  3462,  3476,  3475,  3492,  3495,  3501,  3513,  3533,  3557,
    3561,  3565,  3569,  3573,  3579,  3585,  3589,  3593,  3597,  3601,
    3620,  3633,  3636,  3652,  3655,  3672,  3675,  3681,  3684,  3691,
    3694,  3701,  3757,  3827,  3832,  3899,  3935,  3943,  3986,  4025,
    4045,  4077,  4104,  4130,  4156,  4182,  4208,  4230,  4258,  4286,
    4290,  4294,  4322,  4361,  4400,  4421,  4442,  4469,  4473,  4483,
    4518,  4519,  4520,  4524,  4530,  4542,  4560,  4588,  4589,  4590,
    4591,  4592,  4593,  4594,  4595,  4596,  4603,  4604,  4605,  4606,
    4607,  4608,  4609,  4610,  4611,  4612,  4613,  4614,  4615,  4616,
    4617,  4618,  4619,  4620,  4621,  4622,  4623,  4624,  4625,  4626,
    4627,  4628,  4629,  4630,  4631,  4632,  4633,  4634,  4635,  4644,
    4645,  4646,  4647,  4648,  4649,  4650,  4651,  4652,  4653,  4658,
    4657,  4665,  4670,  4687,  4705,  4723,  4741,  4759,  4764,  4770,
    4782,  4799,  4817,  4835,  4853,  4874,  4879,  4884,  4894,  4904,
    4909,  4920,  4929,  4934,  4961,  4965,  4969,  4973,  4977,  4984,
    4988,  4992,  4996,  5003,  5008,  5015,  5020,  5024,  5029,  5033,
    5041,  5052,  5056,  5068,  5076,  5084,  5091,  5101,  5130,  5134,
    5138,  5142,  5146,  5150,  5154,  5158,  5162,  5191,  5220,  5249,
    5278,  5291,  5304,  5317,  5330,  5340,  5350,  5362,  5375,  5387,
    5405,  5426,  5431,  5435,  5439,  5451,  5455,  5467,  5474,  5484,
    5488,  5503,  5508,  5515,  5519,  5532,  5540,  5551,  5555,  5563,
    5569,  5575,  5583,  5591,  5598,  5613,  5627,  5641,  5653,  5669,
    5680,  5684,  5703,  5710,  5717,  5716,  5729,  5734,  5740,  5749,
    5762,  5765
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
  "tSetPartition", "tAFFECTPLUS", "tAFFECTMINUS", "tAFFECTTIMES",
  "tAFFECTDIVIDE", "'?'", "tOR", "tAND", "tEQUAL", "tNOTEQUAL", "'<'",
  "tLESSOREQUAL", "'>'", "tGREATEROREQUAL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "tPLUSPLUS", "tMINUSMINUS", "UNARYPREC", "'^'", "'('",
  "')'", "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept",
  "All", "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "$@6", "$@7", "UndefineConstants", "Enumeration",
  "FloatParameterOptions", "FloatParameterOption", "CharParameterOptions",
  "CharParameterOption", "PhysicalId0", "PhysicalId1", "PhysicalId2",
  "PhysicalId3", "InSphereCenter", "CircleOptions", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "SetPartition", "Visibility", "Command", "Loop", "Extrude", "$@8", "$@9",
  "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "ExtrudeParameters", "ExtrudeParameter",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "PeriodicTransform", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "$@21", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "$@22", "RecursiveListOfStringExprVar", "StringIndex", "String__Index", YY_NULLPTR
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
      63,   425,   426,   427,   428,    60,   429,    62,   430,    43,
      45,    42,    47,    37,    33,   431,   432,   433,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

#define YYPACT_NINF -1312

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1312)))

#define YYTABLE_NINF -487

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6712,    53,   119,  6828, -1312, -1312,  3430,    12,   -42,   -89,
     -20,    24,   173,   183,   196,   238,    -4,   247,   251,    73,
     126,  -105,  -105,  -158,    85,   134,    -1,   149,   159,    15,
     186,   206,   303,   313,   327,   424,   241,   -25,   365,   377,
     712,   396,   677,   720,   236,   296,   463,   163,   320,   -78,
     -78,   354,   340,    22,   476,   488,   514,     8,    79,   523,
     543,   419,   625,   664,   670,  4896,   676,   536,   570,   577,
      17,    19, -1312,   604, -1312,   682,   800,   624, -1312,   814,
     815,    38,    44, -1312, -1312, -1312,  6576,  6576, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312,    65, -1312,  -117,   115, -1312,    48,
   -1312, -1312, -1312, -1312,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   636,
     637,   645,   660,   666,   683,  -105,   684, -1312,  -105, -1312,
   -1312, -1312, -1312, -1312,  -105,  -105,   869,   697,   708,   715,
    -105,   721,   732, -1312, -1312, -1312, -1312,  6576,  6576,  6576,
    6576,  6576,    18,   814,   610,   735,   372,   782, -1312,   749,
     873,     3,  -106,   888,  6576,  2389,  2389, -1312,  6576, -1312,
   -1312, -1312, -1312,  2389, -1312, -1312, -1312, -1312, -1312, -1312,
    2194,   814,  6576,  6394,  6576,  6576,   746,  6576,  6394,  6576,
    6576,   757,  6394,  6576,  6576,  5272,   761,   781, -1312,  6394,
    4896,  4896,  4896,   779,   789,  4896,  4896,  4896,   793,   798,
     806,   844,   850,   858,   864,   865,   831,  1046,  1000,  5272,
      17,   862,   863,   -78,   -78,   -78,  6576,  6576,   -72, -1312,
      98,   -78,   894,   909,   915,  3627,   100,   -76,   913,   923,
     928,  4896,  4896,  5272,   932,     5,   803, -1312,   842,  1077,
    1154, -1312,   976,   977,   980,  4896,  4896,   989,  1005,  1007,
     506, -1312,  1008,    37,    36,    39,    41,   701,  5460,  6576,
    3888, -1312, -1312,   475, -1312,  1175, -1312,   158,   167,  1195,
    6576,  6576,  6576,  1009,  6576,  1025,  1064,  6576,  6576, -1312,
   -1312,  6576,  1006,  1216, -1312,  1218, -1312,  1221, -1312,   500,
     837,  5642, -1312,  5272,  5272,  6576,  6576,  1032,   568,  2194,
   -1312, -1312, -1312, -1312, -1312, -1312,  5272,  1223,  1040,  6576,
    6576,  1228,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,
    6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,
    6576,  6576,  6576,  6576,  2389,  2389,  2389,  2389,  2389,  2389,
    5272,  2389,  2389,  6576,  2389,  2389,  6576,  2194,  6576,  2389,
    2389,  2389,  2389,   814,  2194,  1045,  1045,  1045,  4487,  8443,
     366,  1041,  1231,  -105,  1043, -1312,  1047,  2672,  6576, -1312,
   -1312,  6394,   102, -1312,  6576,  6576,  6576,  6576,  6576,  6576,
    6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576, -1312,
   -1312,  6576,  6576, -1312, -1312,   965,   -41,  -125, -1312, -1312,
     350,  4266, -1312,   382,   511,   613,  1050,  1053,  4675,  6394,
    3014, -1312,   402,  8788,  8809,  6576,  8830,   469,  8851,  8872,
    6576,   546,  8893,  8914,  1242,  6576,  6576,   580,  1247,  1248,
    1249,  6576,  6576,  1251,  1252,  1252,  6576,  6212,  6212,  6212,
    6212,  6576,  6576,  6576,  6394,  6394,  5830,  1066,  1256,  1067,
   -1312, -1312,   109, -1312, -1312,  4515,  6207,   -78,   -78,   610,
     610,   123,  6576,  6576,  6576,  3627,  3627,  6576,  2672,   145,
   -1312,  6576,  6576,  6576,  6576,  6576,  1259,  1261,  1265,  6576,
    1262,  6576,  6576,  1332, -1312, -1312,  6394,  6394,  6394,  1273,
    1274,  6576,  6576,  6576,  6576,  6576,  1278,   582,   814, -1312,
    1233,  6576, -1312,  1234, -1312,  1235, -1312,  1236,    46,    51,
      55,    56,  6394,  1045, -1312,  8935, -1312,   588,  6576,  5648,
   -1312,  6576,  6576,   617, -1312,  8956,  8977,  8998,  1151,  6389,
   -1312,  1092,  3071,  9019,  8466, -1312, -1312,  1461, -1312,  2031,
    6576, -1312, -1312,  1100,   653,  9040,  8489,  6576,  6394,   102,
    1285,  1286, -1312,  6576,  9061,  8512,    90,  8420,  8420,  8420,
    8420,  8420,  8420,  8420,  8420,  8420,  8420,  8420,  7328,  8420,
    8420,  8420,  8420,  8420,  8420,  8420,  7354,  7380,  7406,   495,
     632,   495,  1108,  1109,  1106,  1112,  1116,  1117,  7432,   422,
     671,  9523, -1312,  1317,  1123,  1113,   435,   671,  1114,  1130,
     437,   260,  2194,  6576,  1315,  1318,    30,   671, -1312,   -29,
      25,    33,    -5, -1312,  3882,   690, -1312,  5272,  3143,  2940,
    2327,  1035,  1035,   310,   310,   310,   310,   268,   268,  1045,
    1045,  1045,  1045,    35,  9082,  8535, -1312,  6576,  1323,     9,
    6394,  1340,  6394,  6576,  1342,  2389,  1347, -1312,   814,  1350,
    2389,  6576,  2194,  1352,  6394,  6394,  1222,  1357,  1359,  9103,
    1372,  1241,  1375,  1376,  9124,  1250,  1379,  1380,  6576,  9145,
    4025,  1161, -1312, -1312, -1312,  9166,  9187,  6576,  5272,  1384,
    1386,  9208,  1200,  9523,  1198,  1204,  9523,  1202,  1205,  9523,
    1203,  1210,  9523,  1206,  9229,  9250,  9271,   694,   695,  6394,
    1209, -1312, -1312,  2060,  2546,   -78,  6576,  6576, -1312, -1312,
    1217,  1219,  3627,  7458,  7484,  7510,  4078,   518,   -78,  3469,
    9292,  4213,  9313,  9334,  9355,  6576,  1397, -1312,  6576,  9376,
   -1312,  8558,  8581, -1312,   698,   705,   706, -1312, -1312,  8604,
    8627,  7536,  8650,   167,  6394, -1312,  1226,  1230,  4420,  1237,
    1238,  1243, -1312,  6394, -1312,  6394, -1312,  6394, -1312,  6394,
     710, -1312, -1312,  3190,  6394,  1045, -1312,  6394, -1312,  1412,
    1415,  1420,  1239,  6576,  4747,  6576,  6576, -1312,     6, -1312,
   -1312,  4937,  1245,  5272,  1424,   437,   437,  4454,   718,  5272,
   -1312, -1312,  8673,   167,   288, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312,  6576, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312,  6576,  6576,  6576, -1312,  6394,
   -1312, -1312, -1312, -1312,  2389,  5272,  2389,  2389,  2194, -1312,
   -1312, -1312, -1312, -1312,  6576, -1312, -1312,  2389, -1312, -1312,
   -1312,  6576,  1425,   170,  6576,  1440,  1442,  1460, -1312,  1443,
    1263,    17,  1446, -1312,  6394,  6394,  6394,  6394, -1312,   671,
    1447,  6576, -1312,  1266,  1267,  1272, -1312,  1451, -1312, -1312,
   -1312, -1312, -1312,   167,   167,  8696, -1312, -1312,  1281,  2389,
     524, -1312,   646,  7562, -1312, -1312, -1312,  1452, -1312, -1312,
    8420,   671,   -78,  3014, -1312,   838,  5272,  5272,  1454,  5272,
     839,  5272,  5272,  1455,  1389,  5272,  5272,  1604,  1464,  1465,
    6394,  1468,  1469,  3234, -1312, -1312,  1471, -1312,  1472,   102,
    6576,   102,  6576,   102,  6576,   102,  6576,  1473,  1474,  1475,
    1476,  1477,   725,  1482,  5125, -1312, -1312,   155,  7588,  7614,
   -1312, -1312,  4608,   -92,   -78,   -78,   -78,  1498,  1497,  1282,
    1501,  1320,    34,    49,    57,    63,   647, -1312,   165, -1312,
     518,  1503,  1505,  1506,  1507,  1509,  9523, -1312,  1726,  1316,
    1511,  1512,  1515,  1444,  6576,  1518,  1520,  6576,   -70,   730,
   -1312,  6576, -1312,  6576,  6576,  6576,   739,   743,   744,   772,
   -1312,  6576,   778,   784,  5272,  5272,  5272,  1523,  7640, -1312,
    3214,   557,  1524,  1526, -1312,  5272,  1334, -1312,  6576,  1537,
    6576,  1539, -1312,   671,  1540,  1541, -1312,  1528, -1312,  1542,
    8420,  8420,  8420,  8420,   667,  1360,  1366,  1367,  1369,  1368,
     675,   679,  9397,  1371,  1995, -1312,   441,  1382,  1558,  2155,
   -1312, -1312, -1312,    17,  6576, -1312,   791, -1312,   795,   796,
     804,   805,   102, -1312,  9523,  1387,  6576,  6576,  5272,  1373,
   -1312, -1312, -1312,  1385, -1312,  1567,    61,  1571,  6576,  4459,
    1573,  1575,    76,  1388,  1392,  1494,  1494,  5272,  1579,  1393,
    1394,  1585,  1589,  5272,  1400,  1591,  1593, -1312,  1595,  5272,
     808,  5272,  5272,  1597,  1596, -1312,  5272,  5272,  9523,  5272,
    9523,  5272,  9523,  5272,  9523,  5272,  5272,  5272,  1409,  1413,
    1609,   489, -1312,  6576,  6576,  6576,  1421,  1422,  -122,  -102,
     -83,  1429, -1312,  5272, -1312,  6576, -1312,  1605, -1312,  1615,
   -1312,  1616, -1312,  1618, -1312, -1312,  3627,   717,  5084, -1312,
    1432,  1433,  5836, -1312,  6394, -1312, -1312, -1312,  1449,  2197,
   -1312, -1312,  8719,  1621,   671,  7666,  7692,  7718,  7744, -1312,
   -1312, -1312, -1312,  9523, -1312,   671,  1641,  1643,  1516, -1312,
    6576,  6576,  6576, -1312,  1644,   517,  1457,  1647,  2304, -1312,
    2401, -1312,   102, -1312, -1312,   130, -1312, -1312, -1312, -1312,
   -1312, -1312,  2389, -1312, -1312, -1312,  2194,  1650, -1312, -1312,
      20, -1312, -1312, -1312, -1312, -1312,  2194,  6576,  1649,  1652,
      30, -1312,  1651,  8742,    17, -1312,  1654,  1659,  1660,  1661,
    5272,  6576,  7770,  7796,   829, -1312,  6576,  1664, -1312, -1312,
    2389, -1312,  7822,  4083,  9523, -1312, -1312, -1312, -1312,  6576,
    6576,   -78,  1663,  1666,  1667, -1312,  6576,  6576, -1312, -1312,
    1668,  6576, -1312, -1312,  1665,  1669,  1481,  1672,  1544,  6576,
   -1312,  1673,  1675,  1687,  1688,  1689,  1694,   968,  1696,  6394,
    6394,  6576, -1312,  6212,  5590,  9418,  2476,   610,   610,   -78,
    1698,   -78,  1700,   -78,  1702,  6576,   287,  1514,  9439, -1312,
   -1312, -1312, -1312,  5778,   175, -1312,  1704,  3693,  1705,  5272,
     -78,  3693,  1706,   840,  6576, -1312,  1707,   167, -1312,  6576,
    6576,  6576,  6576, -1312, -1312, -1312,  5272,  3688,   329,  9460,
   -1312, -1312,  4520,  5272, -1312, -1312, -1312,  5272, -1312,  1538,
     671,  4271,  4708,  2194,  1708,  2523, -1312,  1709,  1712, -1312,
    1545, -1312, -1312, -1312, -1312, -1312,  1727,   652,  9523,  6576,
    6576,  5272,  1543,   841,  9523, -1312,  1728,  6576, -1312, -1312,
    5966,  6112,   457, -1312, -1312, -1312,  6140,  6170, -1312,  6336,
    1730, -1312,  5272, -1312,  1670,  1731,  9523, -1312, -1312, -1312,
   -1312, -1312, -1312,  1546, -1312, -1312,   851,   887,  6018,  2735,
    1734,  1547, -1312,  6576, -1312,  1548,  1551,   179, -1312,  1553,
     202, -1312,  1555,   204, -1312,  1556,  8765,  1735,  5272,  1737,
    1557,  6576, -1312,  6024,   240, -1312,   891,   252,   259, -1312,
    1749,  6475, -1312,  7848,  7874,  7900,  7926,  1622,  6576, -1312,
    6576, -1312, -1312,  6394,  2771,  1751,  1563,  1755, -1312, -1312,
    3888, -1312, -1312,  2389,  9523, -1312, -1312, -1312, -1312,    17,
   -1312,  1625, -1312, -1312,  6576,  7952,  7978, -1312,  5272,  6576,
    1759, -1312,  8004, -1312, -1312,  1760,  1764,  1765,  1782,  1783,
    1784,   892,  1598, -1312,  5272,   608,   651,  6394, -1312, -1312,
     610,  3830, -1312, -1312,  3627,   518,  3627,   518,  3627,   518,
    1789, -1312,   899,  5272, -1312,  6503,   -78,  1790,  6394,   -78,
   -1312, -1312,  6576,  6576,  6576,  6576,  6576,  6824,  6852,   902,
   -1312, -1312,  1791, -1312,   903,  1159,   906,  1792, -1312,  1606,
    9523,  6576,  6576,   925,  9523, -1312,  6576,   930,   934, -1312,
   -1312, -1312, -1312, -1312, -1312,  1607,  6576,   954,  1608,   -78,
    5272,  1794,  1612,   -78,  1795,   957,  1613,  6576, -1312,  6880,
     342,  1068,  6908,   348,  1155,  6936,   368,  1194, -1312,  5272,
    1803,  1718,  5313,  1619,   379, -1312,   960,   381,  8030,  8056,
    8082,  8108,  2791, -1312, -1312,  1810, -1312,  6576, -1312,  2194,
   -1312, -1312,  6576,  9481,  8134,    29,  8160, -1312, -1312,  6576,
    6964,  1814,   -78,    83, -1312, -1312,   -78,    86, -1312,  1820,
   -1312,  6992,  1821,  6576,  1823,  1827,  6576,  1828,  1829,  6576,
    1834,  1648, -1312,  6576, -1312,   518, -1312,  6394,  1835,  6024,
    6576,  6576,  6576,  6576, -1312, -1312,  2884, -1312,   961, -1312,
    6576, -1312,  5272,  6576,  8186, -1312, -1312,   436, -1312,   440,
   -1312, -1312, -1312, -1312,  1653,  7020, -1312, -1312,  1655,  7048,
   -1312, -1312,  1656,  7076, -1312,  1840,  2837,  1254,  5501,   964,
   -1312,   481,   967,  8212,  8238,  8264,  8290,  2194,  1841,  1657,
    9502,   973,  7104,  6576,   -78,   -78,   518,  1842,   518,  1844,
     518,  1848, -1312, -1312, -1312, -1312,   518,  1849,  6394,  1852,
    6576,  6576,  6576,  6576, -1312, -1312,  2389, -1312,  1685,  1876,
    7132,   491,   499,  1322, -1312,  1690,  1492, -1312,  1691,  1576,
   -1312,  1692,  1716, -1312,   982, -1312,  8316,  8342,  8368,  8394,
     990, -1312,  1693,  5272, -1312,  1877,  6576,  6576,  1878,   518,
    1879,   518,  1885,   518, -1312,  1886,  6576,  6576,  6576,  6576,
    2389,  1888,  2389,   997, -1312,  7160,  7188, -1312,  1854, -1312,
    2090, -1312,  2340, -1312,  7216,  7244,  7272,  7300, -1312, -1312,
     998, -1312,  1904,  1905,  1906,  1910,  1911,  1913, -1312, -1312,
   -1312, -1312,  2389,  1914, -1312, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   245,     0,     0,     0,   242,     0,
       0,     0,     0,   340,   341,   342,     0,     0,     5,     7,
       6,     8,     9,    10,    20,    11,    12,    13,    14,    19,
      18,    15,    16,    17,     0,    21,   511,     0,   389,   510,
     487,   390,   391,   392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,   503,
     490,   396,   397,   398,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,   394,   395,   489,     0,     0,     0,
      66,    67,     0,     0,   187,     0,     0,     0,   347,     0,
     483,   511,   402,     0,     0,     0,     0,   227,     0,   229,
     230,   225,   226,     0,   231,   232,   109,   117,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   424,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,     0,   187,   511,     0,
       0,   337,     0,     0,     0,     0,     0,     0,     0,     0,
     510,   442,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   435,   441,     0,   436,   511,   402,     0,
       0,     0,     0,   477,     0,     0,     0,     0,     0,   223,
     224,     0,   510,     0,   241,     0,   187,     0,   187,   510,
       0,     0,   343,     0,     0,    66,    67,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   350,   349,   351,     0,     0,
       0,     0,     0,     0,     0,   186,     0,   185,     0,    68,
      69,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
     216,     0,     0,   410,   164,     0,   510,     0,   483,   484,
       0,     0,   506,     0,   107,   107,     0,     0,     0,     0,
     471,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   305,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,   187,     0,   426,   425,     0,     0,     0,     0,   187,
     187,     0,     0,     0,     0,     0,     0,     0,   255,     0,
     187,     0,     0,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,   205,   338,     0,     0,     0,     0,
       0,     0,     0,     0,    66,    67,     0,     0,     0,   448,
       0,     0,   449,     0,   450,     0,   451,     0,     0,     0,
       0,     0,     0,   349,   443,     0,   437,     0,     0,     0,
     315,    66,    67,     0,   222,     0,     0,     0,     0,     0,
     187,     0,     0,     0,     0,   243,   210,     0,   211,     0,
       0,   235,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,   415,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,   504,     0,     0,     0,     0,     0,     0,     0,
     348,     0,    59,     0,     0,     0,     0,     0,   182,     0,
       0,     0,     0,   188,     0,     0,    59,     0,     0,   365,
     364,   362,   363,   358,   360,   359,   361,   353,   352,   354,
     355,   356,   357,     0,     0,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   334,   335,   336,     0,     0,     0,     0,   303,
       0,     0,     0,   132,   133,     0,   135,   136,     0,   138,
     139,     0,   141,   142,     0,     0,     0,     0,     0,     0,
       0,   152,   187,     0,     0,     0,     0,     0,   428,   427,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,   318,     0,     0,
     206,     0,     0,   202,     0,     0,     0,   333,   332,     0,
       0,     0,     0,   415,     0,   466,     0,     0,     0,     0,
       0,     0,   452,     0,   453,     0,   454,     0,   455,     0,
       0,   348,   438,   445,     0,   354,   444,     0,   467,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,   212,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    74,     0,   404,   403,   417,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   388,   376,     0,   378,   379,
     380,   381,   382,   383,   384,     0,     0,     0,   498,     0,
     500,   494,   495,   496,     0,     0,     0,     0,     0,   423,
     502,   121,   126,    99,     0,   491,   493,     0,   401,   407,
     408,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,   409,     0,     0,     0,     0,   508,     0,
       0,     0,    44,     0,     0,     0,    57,     0,    35,    36,
      37,    38,    39,   406,   405,     0,   485,    24,    22,     0,
       0,    25,     0,     0,   217,   507,    70,   110,    71,   118,
       0,     0,     0,   473,   474,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,   306,   304,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   213,   215,     0,     0,     0,
     177,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,   246,
       0,     0,     0,     0,     0,     0,   308,   317,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   403,     0,
     468,     0,   447,     0,     0,     0,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,     0,     0,   209,     0,     0,   344,     0,     0,
       0,     0,   509,     0,     0,     0,   412,     0,   411,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
      84,    89,    91,     0,     0,   481,     0,    97,     0,     0,
       0,     0,     0,    75,   366,     0,     0,     0,     0,     0,
      30,   414,   413,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,   312,     0,     0,   134,     0,
     137,     0,   140,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,   289,     0,   295,     0,   297,     0,
     291,     0,   293,     0,   256,   285,     0,     0,     0,   200,
       0,     0,     0,   319,     0,   204,   203,   339,     0,     0,
      31,    32,     0,     0,     0,     0,     0,     0,     0,   456,
     457,   458,   459,   446,   440,     0,     0,     0,     0,   478,
       0,     0,     0,   236,     0,     0,     0,     0,     0,    87,
       0,    86,     0,    76,   219,   416,   218,   377,   385,   386,
     387,   501,     0,   420,   421,   422,     0,     0,   400,   122,
       0,   505,   127,   419,   492,    78,    59,     0,     0,     0,
       0,    77,     0,     0,     0,   479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,     0,    26,    27,
       0,    28,     0,     0,   111,   114,    72,    73,   148,     0,
       0,     0,     0,     0,     0,   151,     0,     0,   167,   168,
       0,     0,   153,   174,     0,     0,     0,     0,   144,     0,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,     0,     0,     0,     0,   187,   187,     0,
     266,     0,   268,     0,   270,     0,   435,     0,     0,   296,
     298,   292,   294,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   316,     0,   416,   469,     0,
       0,     0,     0,   470,   156,   157,     0,     0,     0,     0,
     100,   104,     0,     0,   345,    80,    79,     0,   418,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,    95,
       0,   482,   189,   190,   191,   192,     0,     0,    40,     0,
       0,     0,     0,     0,    42,   486,     0,     0,   112,   115,
       0,     0,   147,   154,   155,   159,     0,     0,   169,     0,
       0,   313,     0,   162,     0,     0,   302,   173,   149,   161,
     172,   176,   160,     0,   170,   175,     0,     0,     0,     0,
       0,     0,   432,     0,   431,     0,     0,     0,   257,     0,
       0,   258,     0,     0,   259,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,   198,     0,     0,     0,   193,
       0,     0,    33,     0,     0,     0,     0,     0,     0,   476,
       0,   238,   237,     0,     0,     0,     0,     0,   497,   499,
       0,   123,   125,     0,   128,   129,   130,    90,    92,     0,
      98,     0,    81,    45,     0,     0,     0,   434,     0,     0,
       0,    29,     0,   121,   126,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,   309,   309,     0,   105,   106,
     187,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,   187,     0,     0,     0,     0,     0,
     184,   183,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,     0,    82,     0,   471,     0,     0,   480,     0,
      41,     0,     0,     0,    43,    58,     0,     0,     0,   327,
     329,   328,   330,   331,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   300,     0,
       0,     0,   251,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,   475,   239,     0,   346,     0,   124,     0,
     131,    96,     0,     0,     0,     0,     0,   113,   116,     0,
       0,     0,     0,     0,   310,   320,     0,     0,   321,     0,
     178,     0,   272,     0,     0,   274,     0,     0,   276,     0,
       0,     0,   287,     0,   247,     0,   187,     0,     0,     0,
       0,     0,     0,     0,   158,   103,     0,   119,     0,    49,
       0,    55,     0,     0,     0,   145,   171,     0,   324,     0,
     325,   326,   429,   260,     0,     0,   267,   261,     0,     0,
     269,   262,     0,     0,   271,     0,     0,     0,   253,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,   280,
       0,   282,   288,   299,   252,   248,     0,     0,     0,     0,
       0,     0,     0,     0,   120,    46,     0,    53,     0,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,     0,   201,     0,   195,     0,     0,     0,     0,
       0,    47,     0,     0,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,   273,     0,   275,
       0,   277,     0,   196,     0,     0,     0,     0,    48,    50,
       0,    51,     0,     0,     0,     0,     0,     0,   460,   461,
     462,   463,     0,     0,    56,   322,   323,   279,   281,   283,
      52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1312, -1312, -1312, -1312,   845, -1312, -1312, -1312, -1312,   324,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312,  -382,  -100,    11,    -9, -1312,  1502, -1312, -1312,
   -1312, -1312, -1312,   447, -1312,   448, -1312, -1312, -1312, -1312,
   -1312, -1312,   846,  1940,    -2,  -479,  -250, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312,  1941, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312,  -962,  -922,
   -1312, -1312,  1480, -1312,   442, -1312, -1312, -1312, -1312,  1517,
   -1312, -1312,    54, -1312, -1311,  2175,   722,  2052,   777,  -238,
     707, -1312,    21,    10, -1312,  -360,    -3,    42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,   909,    89,    90,   663,  1377,  1383,
     898,  1085,  1549,  1750,   899,  1699,  1790,   900,  1752,   901,
     902,  1089,   336,   423,   176,   402,    91,   678,   434,  1493,
    1494,   435,  1544,  1060,  1229,  1061,  1232,   712,   715,   718,
     721,  1405,  1272,   643,   291,   396,   397,    94,    95,    96,
      97,    98,    99,   100,   292,   990,  1645,  1716,   747,  1429,
    1432,  1435,  1674,  1678,  1682,  1735,  1738,  1741,   986,   987,
    1124,   946,   709,   756,  1571,   102,   103,   104,   105,   293,
     178,   861,   484,   249,  1254,   294,   295,   296,   547,   305,
     882,  1076,   432,   428,   862,   433,   181,   298
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,    93,   479,   206,   609,   498,   611,   337,   633,   510,
     740,   741,   265,  1032,   619,   907,   180,   513,  1446,   211,
     647,   303,   390,   306,  1362,   183,   257,   179,  1167,   206,
     187,   202,   200,   201,   880,  1661,   184,   211,   203,   892,
    1156,   532,   529,   315,   534,   107,   536,   220,   182,   317,
     221,   782,   338,   222,   268,  1158,   784,   487,   488,     4,
     786,   788,   297,  1160,  1165,   669,   567,  1259,   569,  1162,
     670,   322,   325,  1309,   326,  1310,   268,   487,   488,   334,
     335,   327,  1268,   270,   198,   271,   199,   487,   488,  1668,
    -484,  1501,  1670,  1311,   258,  1312,   487,   488,   259,   269,
     185,   244,   245,   248,   250,  1147,   256,   487,   488,   646,
     260,   246,  1313,   501,  1314,   334,   335,   328,   247,     5,
     502,   313,   329,  1183,   489,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     667,   272,   668,   266,   391,   392,   373,   175,  1157,   375,
     202,   893,   894,   895,   896,   376,   377,   884,  1363,   186,
     268,   382,   395,  1159,  1066,   533,   530,  1553,   535,   189,
     537,  1161,   268,   268,   214,   193,   908,  1163,   207,   190,
     268,   887,   421,  1567,   422,   208,   511,   819,   268,  1033,
     297,   327,   191,   175,   267,   297,   427,   430,   307,   297,
     436,   212,   297,   304,   207,   393,   297,   297,   297,   297,
     188,   885,   297,   297,   297,  1662,   881,   429,   429,   886,
     733,   734,   897,   531,   316,   429,   297,   339,   908,   340,
     318,   341,   783,   437,   192,  1165,   175,   785,   871,   874,
     749,   787,   789,   194,   323,   487,   488,   195,   297,   297,
     297,   324,   487,   488,   196,   487,   488,   646,   330,   331,
     332,   333,   297,   297,   204,   334,   335,   487,   488,   487,
     488,   330,   331,   332,   333,   297,  -485,   297,   487,   488,
     634,   527,   426,   110,   490,   548,   500,   482,   483,   240,
     334,   335,   487,   488,   735,   491,  1067,  1068,   553,   499,
     804,   236,   241,   242,   237,   334,   335,   197,   742,   579,
     297,   297,   811,   205,   487,   488,  -486,   136,   137,   138,
     139,   140,   141,   297,   487,   488,   145,  1460,   209,   580,
     748,   147,   148,   149,   487,   488,   150,   551,   210,   552,
    1143,  1701,   334,   335,   487,   488,   327,   155,   487,   488,
    1166,   268,   268,   268,   268,   268,   268,   297,   268,   268,
    1441,   268,   268,   632,  1514,   213,   268,   268,   268,   268,
     268,   487,   488,   487,   488,   215,   610,   622,   612,   613,
     614,   216,   616,   617,   629,   214,   620,  1516,   297,  1518,
     624,   625,   626,   627,   637,   217,   429,   429,   429,   429,
     429,   429,   252,   429,   429,   253,   429,   429,   254,   487,
     488,   429,   429,   429,   429,   628,   330,   331,   332,   333,
     218,   487,   488,  1038,  1040,  1526,   297,   219,   487,   488,
     158,   159,  1773,   223,   646,   334,   335,  1528,  1236,   415,
     416,   417,   166,   873,  1529,   224,   418,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   549,   416,
     417,   297,   297,   334,   335,   418,   228,   714,   717,   720,
     723,  1047,   964,   548,  1437,   238,   825,   395,   395,   413,
     414,   415,   416,   417,   275,  1302,  1303,   276,   418,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   297,   297,   297,   243,   418,   775,   244,
     245,   487,   488,  1351,  1352,   268,  1461,   487,   488,   246,
     872,   875,   330,   331,   332,   333,   255,  1633,   239,   297,
     671,   738,   739,  1636,   798,   672,   297,   487,   488,   483,
     251,   334,   335,  1581,   261,  1584,   262,  1587,   487,   488,
     487,   488,   399,  1639,   400,  1202,   263,  1127,   401,  1129,
     776,  1131,   674,  1133,  1647,   297,  1649,   675,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,   836,   264,
     838,   839,   840,   841,   842,   843,   844,   685,   273,   686,
     848,   850,   851,   330,   331,   332,   333,   330,   331,   332,
     333,   860,   859,   977,   394,   487,   488,   675,   868,   487,
     488,   274,   334,   335,   978,   866,   334,   335,   883,   277,
     867,  1704,   979,   980,   981,  1705,   487,   488,   982,   983,
     984,   985,   876,  1075,   297,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   549,   416,   417,  1165,
     487,   488,  1165,   418,   685,  1165,   691,   297,   278,   297,
     487,   488,   268,   825,   279,   268,  1718,   268,   487,   488,
     299,   297,   297,  1687,  1237,   399,  1756,   400,   309,   339,
     675,   570,   921,   526,  1757,   524,   915,   525,   175,   526,
    1250,   919,   174,   676,   175,   297,   677,  1568,  1569,    48,
      49,    50,    51,  1570,  1096,  1039,  1041,   429,    56,   685,
     917,    59,   429,  1046,  1048,   300,   297,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   685,   977,   695,  1733,   418,  1736,  1203,  1739,   229,
    1572,  1573,   230,   978,  1742,   231,  1570,   232,   399,   301,
     400,   979,   980,   981,   578,  1165,   302,   982,   983,   984,
     985,   297,   399,   538,   400,   685,   539,   701,   774,   540,
     297,   541,   297,   685,   297,   792,   297,   225,   403,   967,
     226,   297,   227,   308,   297,   233,   973,  1778,   234,  1780,
     235,  1782,   988,  1091,  1092,   679,   310,   399,   677,   400,
     297,  1165,   977,   797,  1165,   311,   297,  1165,   312,   314,
    1165,   268,   399,   978,   400,   367,   368,   849,  1425,  1426,
    1357,   979,   980,   981,   369,  1242,  1097,   982,   983,   984,
     985,   685,  1483,   571,  1164,  1049,   297,  1484,   813,   370,
     814,   268,   297,   268,   268,   371,  1165,   399,  1165,   400,
    1165,   399,   685,   400,   268,   399,   429,   400,  1059,   399,
    1227,   400,   372,   374,  1230,  1055,   378,  1057,  1058,   420,
    1082,   297,   297,   297,   297,   685,   379,   889,  1063,   685,
     685,   960,   961,   685,   424,  1002,   429,   380,   429,   429,
     685,   685,  1003,  1004,   381,   685,   268,  1020,  1048,   429,
     383,  1100,  1101,   685,  1325,  1043,  1103,  1109,  1104,  1110,
     685,   384,  1140,   297,   297,   685,   297,  1184,   297,   297,
    1095,   398,   297,   297,   685,   445,  1189,   297,   685,   685,
    1190,  1191,   458,   459,   460,   419,   450,   463,   464,   465,
     455,   429,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,  1238,   685,   461,  1192,
     418,   666,  1413,   685,  1414,  1194,  1102,   456,   462,   685,
     442,  1195,   466,   506,   507,   447,  1244,   467,  1245,   451,
     685,   685,  1246,  1247,   512,   468,   457,   519,   520,   685,
     685,  1248,  1249,   685,   477,  1286,  1371,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   297,   297,   297,  1381,   418,  1382,   474,  1148,  1149,
    1150,  1576,   297,   469,  1212,   685,  1489,  1450,  1490,   470,
     327,  1217,  1218,  1219,  1220,  1221,   685,   471,  1505,   108,
     319,  1228,  1231,   472,   473,   111,   112,   113,   480,   481,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   685,   514,  1506,   297,  1381,  1381,  1527,  1565,
     492,   142,   143,   144,  1589,   146,  1590,   685,  1607,  1605,
    1608,   675,   503,  1610,   297,   493,   151,   152,   153,  1265,
     297,   494,   504,  1546,   154,  1358,   297,   505,   297,   297,
    1381,   509,  1615,   297,   297,  1227,   297,  1617,   297,  1230,
     297,  1618,   297,   297,   297,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,  1381,
     297,  1621,   685,   418,  1629,   685,  1489,  1648,  1698,   685,
     515,  1717,   685,   977,  1719,   297,  1609,   548,  1381,   297,
    1728,   297,   516,   517,   978,  1338,   518,   685,   645,  1765,
     521,   550,   979,   980,   981,  1770,  1343,  1771,   982,   983,
     984,   985,  1381,  1802,  1792,  1803,   522,   157,   523,   528,
     160,   554,   558,   561,   175,   161,   162,   163,   164,   165,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   268,
    1324,   560,   565,   418,   566,   167,   168,   568,   577,   582,
     169,   583,   586,   418,   635,   289,  1360,  1358,   636,   174,
     173,  1547,   475,  1359,   638,   681,  1364,   297,   682,   698,
     977,   727,   728,   702,   703,   704,   730,   268,   707,   708,
     297,   978,   731,   732,   429,  1634,   755,   757,   760,   979,
     980,   981,   758,  1389,  1592,   982,   983,   984,   985,   767,
     768,  1386,   773,   777,   779,   780,   781,   802,   805,   977,
     812,   820,   821,   764,   765,   766,   297,   297,   852,   853,
     978,   854,   429,   865,   869,   395,   395,   855,   979,   980,
     981,   856,   857,  1420,   982,   983,   984,   985,   864,   790,
     870,   878,   879,   863,   297,  1392,   297,   906,   297,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     684,   416,   417,   297,     7,     8,   911,   418,   914,   977,
     297,  1469,  1637,   916,   297,   818,   918,   940,   297,   922,
     978,   925,  1465,  1427,   926,  1430,   927,  1433,   979,   980,
     981,  1472,  1475,  1476,   982,   983,   984,   985,   297,   929,
     930,  1444,   931,   932,  1447,  1448,   935,   936,   945,   934,
     949,  1640,   947,   950,   951,   953,  1688,   952,   954,   297,
     955,   956,   963,   997,   639,    24,    25,   640,    27,    28,
     641,    30,   642,    32,   970,    33,   971,   977,  1010,  1024,
      38,    39,  1025,    41,    42,    43,  1011,  1026,   978,    46,
    1037,  1065,  1027,  1013,  1014,   297,   979,   980,   981,  1015,
     297,  1035,   982,   983,   984,   985,  1070,   910,  1071,   912,
    1073,  1714,  1077,  1083,  1074,  1086,  1087,  1090,  1094,  1099,
     297,  1107,  1113,    67,    68,    69,  1072,   297,  1088,  1114,
     268,  1118,  1119,     7,     8,  1121,  1122,  1125,  1153,  1126,
    1135,  1136,  1137,  1138,  1139,   297,  1141,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   297,  1151,  1152,   297,   418,   962,  1154,   395,  1155,
    1168,  1169,  1174,  1170,  1171,   429,  1172,  1175,  1176,  1758,
     297,  1177,  1178,   177,  1180,   297,  1181,  1199,  1204,   763,
    1205,  1207,  1215,   639,    24,    25,   640,    27,    28,   641,
      30,   642,    32,  1209,    33,  1211,  1213,  1214,  1216,    38,
      39,  1009,    41,    42,    43,  1222,  1223,  1224,    46,  1225,
    1016,  1234,  1017,  1226,  1018,  1240,  1019,   297,  1580,  1256,
    1583,  1022,  1586,  1258,  1023,  1239,  1251,  1261,  1257,  1266,
    1594,  1267,  1271,  1597,  1269,  1275,   297,   977,  1270,  1276,
    1277,  1278,    67,    68,    69,  1279,  1281,  1282,   978,  1283,
    1284,  1289,  1290,   320,   321,  1299,   979,   980,   981,  1300,
    1117,  1319,   982,   983,   984,   985,  1301,  1307,  1308,  1657,
    1315,  1320,  1321,  1623,  1322,  1337,  1054,  1627,  1329,  1330,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   297,  1334,   297,  1344,   418,  1345,
    1350,  1346,  1353,  1354,  1361,  1366,  1367,  1369,   809,   297,
    1372,  1078,  1079,  1080,  1081,  1373,  1374,  1375,  1385,  1393,
    1400,   977,  1394,  1395,  1398,  1401,  1667,  1402,  1403,  1407,
    1669,  1408,   978,  1404,   385,   386,   387,   388,   389,  1760,
     979,   980,   981,  1409,  1410,  1411,   982,   983,   984,   985,
    1412,   425,  1415,  1691,  1428,   431,  1431,  1724,  1434,  1438,
    1442,  1445,  1449,  1452,  1477,   297,  1479,  1120,  1480,   438,
     440,   443,   444,   268,   446,   440,   448,   449,  1468,   440,
     452,   453,  1173,  1482,  1491,  1500,   440,  1503,  1481,  1488,
    1509,  1521,  1504,  1510,  1523,  1512,  1502,  1751,  1513,  1515,
     297,  1517,  1519,  1524,   476,  1530,  1536,  1541,  1731,  1732,
    1542,  1543,  1548,   485,   486,  1555,  1559,   268,   429,   268,
    1560,  1561,   486,  1762,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,  1562,  1563,
    1564,  1788,   418,  1791,  1566,  1588,  1595,  1606,  1611,   268,
    1625,  1628,  1612,  1619,  1622,   543,   545,   440,  1626,  1642,
    1630,   977,   429,  1643,   429,  1646,  1655,   555,   556,   557,
    1666,   559,   978,  1810,   562,   563,  1671,  1673,   564,  1676,
     979,   980,   981,  1677,  1680,  1681,   982,   983,   984,   985,
    1684,  1690,   575,   576,   429,  1685,  1712,  1725,  1734,  1706,
    1737,  1708,  1710,  1726,  1740,  1743,   584,   585,  1745,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,  1753,  1754,  1774,  1777,  1779,  1759,  1761,  1763,  1772,
     618,  1781,  1783,   621,  1789,   623,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
    1804,  1805,  1806,  1764,   418,   644,  1807,  1808,   440,  1809,
    1811,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,  1658,   680,   664,   665,
    1557,  1260,  1558,    92,   101,   710,     0,  1368,  1574,   977,
       0,  1333,  1273,     0,     0,     0,   543,     0,     0,     0,
     978,     0,   689,     0,     0,     0,     0,   694,   979,   980,
     981,     0,   699,   700,   982,   983,   984,   985,   705,   706,
       0,     0,     0,   711,   713,   716,   719,   722,   724,   725,
     726,   440,   440,     0,     0,     0,     0,     0,     0,     0,
       0,  1235,     0,     0,     0,     0,     0,     0,     0,   743,
     744,   745,   385,   386,   746,     0,     0,     0,   750,   751,
     752,   753,   754,     0,     0,     0,   759,     0,   761,   762,
       0,     0,     0,   440,   440,   440,     0,     0,   769,   770,
     771,   584,   772,     7,     8,     0,     0,     0,   778,     0,
       0,  1795,     0,     0,     0,     0,     0,     0,     0,   440,
       0,     0,     0,     0,     0,   793,   795,     0,   664,   665,
       0,     0,     7,     8,     0,     0,  1416,  1417,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   772,     0,     0,
       0,     0,     0,     0,   817,   440,     0,     0,     0,     0,
     822,     0,     0,   639,    24,    25,   640,    27,    28,   641,
      30,   642,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,   639,    24,    25,   640,    27,    28,   641,    30,
     642,    32,     0,    33,     0,     0,     0,     0,    38,    39,
     877,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,  1241,    67,    68,    69,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,   905,   977,     0,   440,     0,   440,
     913,    67,    68,    69,     0,     0,   978,     0,   920,   110,
       0,   795,   923,  1335,   979,   980,   981,     0,     0,     0,
     982,   983,   984,   985,     0,   937,     0,     0,     0,     0,
       0,     0,     0,     0,   943,     0,     0,     0,   810,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   141,     0,
    1539,     0,   145,     0,     0,     0,   440,   147,   148,   149,
       0,     0,   150,   968,   969,   441,     0,   965,     0,   972,
     441,     0,     0,   155,   441,     0,     0,     0,     0,     0,
       0,   441,   996,     0,     0,   998,     0,     0,     0,     0,
       0,     0,     0,     0,  1575,     0,     0,  1796,     0,     0,
       0,   440,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,   440,     0,   440,  1596,   440,     0,     0,     0,
    1355,   440,     0,     0,   440,     0,     0,     0,     0,     0,
    1028,     0,  1030,  1031,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
     544,     0,   441,   418,     0,     0,   158,   159,     0,     0,
       0,     0,     0,     0,  1050,     0,     0,     0,   166,     0,
       0,     0,  1051,  1052,  1053,     0,   440,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,  1062,     0,     0,     0,   418,     0,     0,  1064,     0,
     454,  1069,     0,   426,   110,     0,     0,     0,     0,     0,
       0,   440,   440,   440,   440,     0,     0,  1356,  1084,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1689,     0,  1692,     0,   136,   137,
     138,   139,   140,   141,     0,   977,     0,   145,   508,     0,
       0,     0,   147,   148,   149,     0,   978,   150,     0,     0,
       0,     0,     0,   441,   979,   980,   981,   440,   155,     0,
     982,   983,   984,   985,     0,     0,     0,  1128,     0,  1130,
       0,  1132,     0,  1134,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,   544,   418,     0,     0,  1744,     0,     0,   573,   574,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   581,     0,     0,     0,   418,     0,     0,     0,     0,
       0,  1179,     0,     0,  1182,     0,   441,   441,  1185,  1478,
    1186,  1187,  1188,     0,     0,     0,     0,  1797,  1193,     0,
       0,   158,   159,     0,     0,   615,     0,     0,     0,     0,
       0,     0,     0,   166,     0,  1208,     0,  1210,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,   441,   441,
     441,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,  1243,     0,     0,   441,     0,     0,     0,     0,     0,
       0,   796,     0,  1252,  1253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1262,  1264,     0,   639,    24,
      25,   640,    27,    28,   641,    30,   642,    32,     0,    33,
     441,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
    1304,  1305,  1306,     0,   418,     0,     0,     0,     0,     0,
    1316,  1423,  1318,  1424,     0,     0,     0,    67,    68,    69,
       0,     0,     0,  1323,     7,     8,     0,     0,     0,     0,
       0,   440,     0,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,  1347,  1348,  1349,
       0,     0,   441,     0,   441,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   796,   924,     0,     0,
       0,  1508,     0,   966,   639,    24,    25,   640,    27,    28,
     641,    30,   642,    32,  1365,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,  1378,    46,
       0,     0,     0,  1384,     0,     0,     0,  1540,     0,     0,
       0,   441,     0,     0,     0,     0,  1390,  1391,     0,     0,
       0,     0,     0,  1396,  1397,     0,     0,  1654,  1399,     0,
       0,     0,     0,    67,    68,    69,  1406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,   440,  1418,     0,
    1419,     0,   890,     0,     0,     0,   441,     0,     0,     0,
       0,     0,  1436,     0,     0,   441,     0,   441,     0,   441,
       0,   441,     0,  1713,   440,     0,   441,     0,   440,   441,
       0,  1451,     0,     0,     0,     0,  1453,  1454,  1455,  1456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1464,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1474,
       0,     0,     0,   944,     0,     0,     0,     0,     0,     0,
       0,  1697,     0,     0,     0,     0,  1485,  1486,     0,     0,
       0,   441,     0,     0,  1492,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,   441,   441,   441,
    1511,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,  1525,   418,
     543,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,  1537,     0,  1538,     0,   418,
     440,     0,     0,     0,     0,     0,     0,  1545,  1036,     0,
       0,     0,   441,     0,  1044,     0,     0,     0,     0,     0,
       0,  1550,     0,     0,     0,     0,  1554,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,   548,     0,   440,   418,     0,     0,     0,     0,
    1056,  1579,     0,  1582,     0,  1585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   440,     0,     0,     0,  1598,
    1599,  1600,  1601,  1602,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,  1613,  1614,
       0,     0,   418,  1616,     0,     0,     0,     0,     0,   806,
       0,     0,     0,  1620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1631,     0,     0,     0,     0,     0,
       0,  1105,  1106,     0,  1108,     0,  1111,  1112,     0,     0,
    1115,  1116,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,  1656,     0,     0,     0,   418,  1384,
       0,     0,     0,     0,     0,     0,  1664,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1675,   891,     0,  1679,     0,     0,  1683,     0,     0,     0,
    1686,     0,     0,     0,   440,     0,   440,  1693,  1694,  1695,
    1696,     0,     0,     0,     0,     0,     0,  1700,     0,     0,
    1702,     0,     0,     0,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   684,   416,   417,  1021,  1196,
    1197,  1198,   418,     0,     0,     0,     0,     0,     0,     0,
    1206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1730,     0,  1201,     0,     0,     0,   441,     0,     0,     0,
       0,     0,     0,     0,     0,   440,     0,  1746,  1747,  1748,
    1749,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,  1255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1775,  1776,     0,     0,     0,     0,     0,
       0,     0,  1274,  1784,  1785,  1786,  1787,     0,  1280,     0,
       0,     0,     0,     0,  1285,     0,  1287,  1288,     0,     0,
       0,  1291,  1292,     0,  1293,     0,  1294,     0,  1295,     0,
    1296,  1297,  1298,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,  1317,  1123,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1328,     0,     0,     0,  1332,     0,     0,
       0,   441,   441,     0,     0,     0,     0,     0,     0,     0,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,   441,
       0,     0,     0,   441,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,  1376,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   110,     0,     0,  1388,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     7,     8,   147,   148,   149,     0,     0,   150,     0,
     151,   152,   153,     0,     0,   544,     0,     0,   154,   155,
       0,     0,     0,     0,  1255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   441,     0,     0,     0,     0,
       0,  1457,   441,     0,     0,     0,     0,     0,  1466,     0,
       0,     0,  1467,     0,     0,     0,  1471,     0,     0,     0,
       0,   639,    24,    25,   640,    27,    28,   641,    30,   642,
      32,     0,    33,     0,     0,     0,  1487,    38,    39,   441,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,  1255,     0,     0,
     441,   157,   158,   159,   160,     0,     0,     0,     0,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,  1522,   169,     0,     0,     0,     0,   170,
       0,   171,     0,   172,   173,     0,   174,     0,   175,     0,
     108,   319,     0,     0,     0,     0,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,  1255,     0,     0,   989,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,  1255,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,   108,   280,  1591,   441,
       0,   441,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   282,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,   146,     0,     0,  1624,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,     0,     0,     0,     0,
       0,   154,     0,     0,  1641,   283,     0,     0,   284,     0,
     441,   285,     0,   286,     0,     0,     0,     0,   157,     0,
       0,   160,     0,     0,     0,   287,   161,   162,   163,   164,
     165,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,   495,   496,     0,     0,
       0,   169,     0,     0,     0,     0,   497,     0,     0,     0,
       0,   173,     0,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1255,     0,     0,
       0,     0,     0,     0,   157,     0,     0,   160,     0,     0,
       0,     0,   161,   162,   163,   164,   165,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   495,  1443,     0,     0,   418,   169,     0,     0,
       0,     0,   497,  1458,     0,  1459,     0,   173,     0,   247,
     546,   108,   280,     0,     0,     0,     0,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   282,     0,     0,     0,  1255,     0,
       0,     0,     0,   142,   143,   144,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     153,     0,     0,     0,     0,     0,   154,     0,     0,     0,
     283,     0,     0,   284,     0,     0,   285,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1577,     0,  1578,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   160,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,   167,   439,     0,
     418,     0,   169,     0,     0,     0,     0,   289,     0,   888,
       0,     0,   173,     0,     0,   546,   108,   280,   110,     0,
       0,     0,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   282,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   147,   148,   149,     0,
       0,   150,     0,   151,   152,   153,     0,     0,     0,     0,
       0,   154,   155,     0,     0,   283,     0,     0,   284,     0,
       0,   285,     0,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,   939,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,   161,   162,   163,   164,   165,   166,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   167,   288,     0,     0,   418,   169,   791,     0,
       0,     0,   289,   736,   108,   280,   110,   173,     0,   290,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   282,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   147,   148,   149,     0,     0,   150,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
     155,     0,     0,   283,     0,     0,   284,     0,     0,   285,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
     992,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     167,   288,     0,     0,   418,   169,     0,     0,     0,     0,
     289,   673,   108,   319,   110,   173,     0,  1470,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,   147,   148,   149,     0,     0,   150,     0,   151,
     152,   153,     0,   108,   319,   110,     0,   154,   155,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   147,   148,   149,     0,     0,   150,     0,
     151,   152,   153,     0,     0,     0,     0,     0,   154,   155,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     157,   158,   159,   160,     0,     0,     0,  1012,   161,   162,
     163,   164,   165,   166,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   167,   168,
       0,     0,   418,   169,     0,     0,     0,     0,   289,     0,
       0,  1042,     0,   173,     0,  1263,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   157,   158,   159,   160,   418,     0,   630,     0,   161,
     162,   163,   164,   165,   166,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   167,
     168,     0,     0,   418,   169,     0,     0,     0,     0,   289,
     736,   108,   319,   110,   173,     0,  1463,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     7,
       8,   147,   148,   149,     0,     0,   150,     0,   151,   152,
     153,     0,     0,     0,     0,     0,   154,   155,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,  1146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   639,
      24,    25,   640,    27,    28,   641,    30,   642,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   157,
     158,   159,   160,   418,     0,   683,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,   169,     0,     0,     0,     0,   289,     0,   108,
     280,   281,   173,     0,  1473,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   282,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,  1029,   146,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,     0,     0,     0,   283,     0,
       0,   284,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,   639,
      24,    25,   640,    27,    28,   641,    30,   642,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     160,     0,     0,     0,     0,   161,   162,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,   167,   288,     0,     0,     0,
     169,     0,     0,     0,     0,   289,     0,   108,   280,  1326,
     173,     0,   290,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     282,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,     0,   146,  1034,     0,     0,     7,     8,     0,
       0,     0,     0,     0,   151,   152,   153,     0,     0,     0,
       0,     0,   154,     0,     0,     0,   283,     0,     0,   284,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,   639,    24,    25,
     640,    27,    28,   641,    30,   642,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   160,     0,
       0,     0,     0,   161,   162,   163,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,   167,   288,     0,     0,     0,   169,     0,
       0,     0,     0,   289,     0,   108,   280,     0,   173,     0,
    1327,   111,   112,   113,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   282,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
       0,   146,  1142,     0,     0,     7,     8,     0,     0,     0,
       0,     0,   151,   152,   153,     0,     0,     0,     0,     0,
     154,     0,     0,     0,   283,     0,     0,   284,     0,     0,
     285,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,   639,    24,    25,   640,    27,
      28,   641,    30,   642,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   160,     0,     0,     0,
       0,   161,   162,   163,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,   167,   288,     0,     0,     0,   169,     0,     0,     0,
       0,   289,     0,   108,   280,     0,   173,     0,   290,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   282,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,   146,
    1644,     0,     0,     7,     8,     0,     0,     0,     0,     0,
     151,   152,   153,     0,     0,     0,     0,     0,   154,     0,
       0,     0,   283,     0,     0,   284,     0,     0,   285,     0,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,   639,    24,    25,   640,    27,    28,   641,
      30,   642,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,     0,     0,   160,     0,     0,     0,     0,   161,
     162,   163,   164,   165,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,   167,
     439,     0,     0,     0,   169,     0,     0,     0,     0,   289,
       0,   108,   280,     0,   173,     0,   542,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   282,     0,     0,     0,     0,     0,
       0,     0,     0,   142,   143,   144,     0,   146,  1715,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     153,     0,     0,     0,     0,     0,   154,     0,     0,     0,
     283,     0,     0,   284,     0,     0,   285,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,  1421,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   160,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,   167,   439,     0,
     418,     0,   169,     0,     0,     0,     0,   289,   572,   108,
     280,     0,   173,     0,   794,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   282,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,     0,     0,     0,   283,     0,
       0,   284,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,  1440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     160,     0,     0,     0,     0,   161,   162,   163,   164,   165,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,   167,   288,     0,   418,     0,
     169,     0,     0,     0,     0,   289,   729,   108,   280,     0,
     173,     0,  1331,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     282,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,     0,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,     0,     0,     0,
       0,     0,   154,     0,     0,     0,   283,     0,     0,   284,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,     0,     0,  1495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   160,     0,
       0,     0,     0,   161,   162,   163,   164,   165,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,   495,  1443,     0,   418,     0,   169,     0,
       0,     0,     0,   497,  1507,   108,   319,   110,   173,     0,
     247,   111,   112,   113,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,   147,   148,   149,     0,     0,
     150,     0,   151,   152,   153,     0,     0,     0,     0,     0,
     154,   155,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,  1496,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,  1497,     0,     0,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,   157,   158,   159,   160,  1498,     0,     0,
       0,   161,   162,   163,   164,   165,   166,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   167,   168,     0,     0,   418,   169,   108,   280,     0,
       0,   289,   737,   111,   112,   113,   173,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     282,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,     0,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,     0,     0,     0,
       0,     0,   154,     0,     0,     0,   283,     0,     0,   284,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,     0,     0,  1499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   160,     0,
       0,     0,     0,   161,   162,   163,   164,   165,     0,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   167,   439,     0,     0,   418,   169,   108,
     319,     0,     0,   289,   803,   111,   112,   113,   173,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1531,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    1593,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,   157,     0,     0,
     160,     0,     0,     0,     0,   161,   162,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,   167,   168,     0,     0,     0,
     169,     0,    -4,    -4,    -4,   289,     0,     0,    -4,    -4,
     173,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     6,     0,     0,     0,     0,    -4,     0,     0,
       7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     9,    10,    -4,    -4,    -4,
      -4,     0,     0,     0,     0,     0,     0,    -4,    11,    12,
      13,     0,     0,     0,    14,    15,     0,    16,     0,     0,
       0,    17,    18,     0,    19,    20,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,     0,    62,    63,    64,     0,     0,
       0,     0,     0,    65,     0,     0,     0,     0,    66,    67,
      68,    69,     0,     0,    70,     0,    71,     0,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,    87,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,  1603,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,  1604,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,  1632,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,  1635,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,     0,     0,  1638,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,  1665,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,  1672,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,  1707,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,  1709,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,     0,     0,  1711,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,  1729,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,  1755,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,  1793,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,  1794,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,     0,     0,  1798,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,  1799,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,  1800,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,     0,     0,  1801,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,   837,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,   845,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,   846,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,   847,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,   858,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,   974,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,   975,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,   976,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1007,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1098,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1144,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1145,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1200,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1339,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1340,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1341,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1342,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1379,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1380,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1387,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1532,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1533,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1534,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1535,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1551,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1552,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1556,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1650,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1651,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1652,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1653,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1660,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1663,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1703,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1720,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1721,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1722,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,  1723,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,     0,     0,
       0,  1766,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,  1767,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,  1768,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,  1769,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     399,     0,   400,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,   631,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,   808,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,   816,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,   824,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,   904,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
    1000,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,  1001,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,  1005,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,  1006,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,  1008,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,  1045,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,  1093,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,  1336,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,  1370,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,  1520,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,   687,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   688,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     690,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   692,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,   693,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   696,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   697,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,   791,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,   799,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,   800,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,   801,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   807,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     815,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   823,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,   903,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   928,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   933,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,   938,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,   941,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,   942,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,   948,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   957,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     958,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   959,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,   991,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   993,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   994,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,   995,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,   999,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,  1233,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,  1422,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,  1439,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
    1462,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,  1659,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,  1727,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418
};

static const yytype_int16 yycheck[] =
{
       3,     3,   240,     4,   364,   255,   366,   107,   390,     4,
     489,   490,     4,     7,   374,     6,     6,   267,  1329,     4,
     402,     4,     4,     4,     4,    13,     4,     6,   990,     4,
       6,   189,    21,    22,     4,     6,    78,     4,   196,     4,
       6,     5,     5,     5,     5,     3,     5,    72,     6,     5,
      75,     5,     4,    78,    57,     6,     5,   179,   180,     6,
       5,     5,    65,     6,   986,   190,   316,     6,   318,     6,
     195,     6,   189,   195,   191,   197,    79,   179,   180,   185,
     186,   198,     6,     4,   189,     6,   191,   179,   180,     6,
     196,  1402,     6,   195,    72,   197,   179,   180,    76,    57,
     189,   179,   180,    49,    50,   197,    52,   179,   180,     7,
      88,   189,   195,   189,   197,   185,   186,   106,   196,     0,
     196,    79,     7,   193,   196,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     191,    72,   193,   145,   136,   137,   145,   198,   124,   148,
     189,   126,   127,   128,   129,   154,   155,   196,   148,   189,
     173,   160,   174,   124,     4,   139,   139,  1488,   139,     6,
     139,   124,   185,   186,   189,   189,   177,   124,   189,     6,
     193,   196,   189,  1504,   191,   196,   191,   579,   201,   193,
     203,   198,     6,   198,   196,   208,   185,   186,   189,   212,
     200,   196,   215,   196,   189,   173,   219,   220,   221,   222,
     196,   196,   225,   226,   227,   196,   196,   185,   186,   196,
     480,   481,   197,   196,   196,   193,   239,   189,   177,   191,
     196,   193,   196,   201,     6,  1167,   198,   196,   630,   631,
     500,   196,   196,     6,   189,   179,   180,     6,   261,   262,
     263,   196,   179,   180,   191,   179,   180,     7,   166,   167,
     168,   169,   275,   276,   189,   185,   186,   179,   180,   179,
     180,   166,   167,   168,   169,   288,   196,   290,   179,   180,
     390,   280,     4,     5,   196,     8,   196,   243,   244,   136,
     185,   186,   179,   180,   195,   251,   136,   137,   297,   255,
     560,    75,   149,   150,    78,   185,   186,   191,   195,   328,
     323,   324,   572,   189,   179,   180,   196,    39,    40,    41,
      42,    43,    44,   336,   179,   180,    48,     8,   189,   329,
     195,    53,    54,    55,   179,   180,    58,   189,   189,   191,
     195,  1662,   185,   186,   179,   180,   198,    69,   179,   180,
     195,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     195,   374,   375,     7,   195,   189,   379,   380,   381,   382,
     383,   179,   180,   179,   180,    82,   365,   377,   367,   368,
     369,    78,   371,   372,   384,   189,   375,   195,   401,   195,
     379,   380,   381,   382,   393,    78,   364,   365,   366,   367,
     368,   369,    72,   371,   372,    75,   374,   375,    78,   179,
     180,   379,   380,   381,   382,   383,   166,   167,   168,   169,
       6,   179,   180,   815,   816,   195,   439,   196,   179,   180,
     152,   153,  1753,    78,     7,   185,   186,   195,     7,   181,
     182,   183,   164,   193,   195,    78,   188,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   474,   475,   185,   186,   188,    80,   467,   468,   469,
     470,   193,   732,     8,   197,   189,   586,   489,   490,   179,
     180,   181,   182,   183,    75,     6,     7,    78,   188,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   516,   517,   518,   196,   188,   527,   179,
     180,   179,   180,     6,     7,   528,   197,   179,   180,   189,
     630,   631,   166,   167,   168,   169,   196,   195,    75,   542,
     190,   487,   488,   195,   553,   195,   549,   179,   180,   495,
     196,   185,   186,  1515,    78,  1517,    80,  1519,   179,   180,
     179,   180,   190,   195,   192,     8,    78,   949,   196,   951,
     528,   953,   190,   955,   195,   578,   195,   195,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,    75,
     599,   600,   601,   602,   603,   604,   605,   195,    75,   197,
     609,   610,   611,   166,   167,   168,   169,   166,   167,   168,
     169,   620,   190,    95,     4,   179,   180,   195,   627,   179,
     180,    78,   185,   186,   106,   190,   185,   186,   637,     4,
     195,   195,   114,   115,   116,   195,   179,   180,   120,   121,
     122,   123,   632,   881,   647,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,  1581,
     179,   180,  1584,   188,   195,  1587,   197,   670,     4,   672,
     179,   180,   675,   773,     4,   678,   195,   680,   179,   180,
       4,   684,   685,  1645,  1066,   190,   195,   192,     6,   189,
     195,   191,   682,   193,   195,   189,   675,   191,   198,   193,
    1082,   680,   196,   192,   198,   708,   195,    99,   100,    99,
     100,   101,   102,   105,   190,   815,   816,   675,   108,   195,
     678,   111,   680,   823,   824,   189,   729,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   195,    95,   197,  1706,   188,  1708,   190,  1710,    72,
      99,   100,    75,   106,  1716,    78,   105,    80,   190,   189,
     192,   114,   115,   116,   196,  1687,   189,   120,   121,   122,
     123,   774,   190,    72,   192,   195,    75,   197,   196,    78,
     783,    80,   785,   195,   787,   197,   789,    75,     6,   735,
      78,   794,    80,   189,   797,    75,   742,  1759,    78,  1761,
      80,  1763,   748,   903,   904,   192,     6,   190,   195,   192,
     813,  1733,    95,   196,  1736,   191,   819,  1739,     4,     4,
    1742,   824,   190,   106,   192,   189,   189,   195,  1307,  1308,
    1212,   114,   115,   116,   189,  1073,   190,   120,   121,   122,
     123,   195,   190,     6,   197,   824,   849,   195,   195,   189,
     197,   854,   855,   856,   857,   189,  1778,   190,  1780,   192,
    1782,   190,   195,   192,   867,   190,   824,   192,   858,   190,
     195,   192,   189,   189,   195,   854,     7,   856,   857,     6,
     889,   884,   885,   886,   887,   195,   189,   197,   867,   195,
     195,   197,   197,   195,     6,   197,   854,   189,   856,   857,
     195,   195,   197,   197,   189,   195,   909,   197,  1008,   867,
     189,   920,   921,   195,   197,   197,    78,    78,    80,    80,
     195,   189,   197,   926,   927,   195,   929,   197,   931,   932,
     909,   196,   935,   936,   195,   189,   197,   940,   195,   195,
     197,   197,   220,   221,   222,   196,   189,   225,   226,   227,
     189,   909,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,  1066,   195,   189,   197,
     188,     6,     4,   195,     6,   197,   922,   196,   189,   195,
     203,   197,   189,   261,   262,   208,   195,   189,   197,   212,
     195,   195,   197,   197,   191,   189,   219,   275,   276,   195,
     195,   197,   197,   195,     4,   197,  1244,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,  1024,  1025,  1026,   195,   188,   197,   196,   974,   975,
     976,  1510,  1035,   189,  1043,   195,   195,   197,   197,   189,
     198,  1050,  1051,  1052,  1053,  1054,   195,   189,   197,     3,
       4,  1060,  1061,   189,   189,     9,    10,    11,   196,   196,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   195,     6,   197,  1088,   195,   195,   197,   197,
     196,    45,    46,    47,   195,    49,   197,   195,   195,   197,
     197,   195,   189,   197,  1107,   196,    60,    61,    62,  1099,
    1113,   196,   189,  1473,    68,  1215,  1119,   189,  1121,  1122,
     195,   189,   197,  1126,  1127,   195,  1129,   197,  1131,   195,
    1133,   197,  1135,  1136,  1137,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   195,
    1153,   197,   195,   188,   197,   195,   195,   197,   197,   195,
       6,   197,   195,    95,   197,  1168,     7,     8,   195,  1172,
     197,  1174,   196,   196,   106,  1184,   196,   195,   401,   197,
     191,     6,   114,   115,   116,   195,  1195,   197,   120,   121,
     122,   123,   195,   195,   197,   197,   191,   151,   191,   191,
     154,     6,   193,   139,   198,   159,   160,   161,   162,   163,
     175,   176,   177,   178,   179,   180,   181,   182,   183,  1222,
    1166,   196,     6,   188,     6,   179,   180,     6,   196,     6,
     184,   191,     4,   188,   193,   189,  1226,  1337,     7,   196,
     194,  1479,   196,  1222,   197,   195,  1236,  1250,   195,     7,
      95,   474,   475,     6,     6,     6,   190,  1260,     7,     7,
    1263,   106,     6,   196,  1222,   197,     7,     6,     6,   114,
     115,   116,     7,  1263,  1524,   120,   121,   122,   123,     6,
       6,  1260,     4,    50,    50,    50,    50,   136,   196,    95,
     190,     6,     6,   516,   517,   518,  1299,  1300,   190,   190,
     106,   195,  1260,   190,   190,  1307,  1308,   195,   114,   115,
     116,   195,   195,  1303,   120,   121,   122,   123,   195,   542,
     190,     6,     4,     6,  1327,  1271,  1329,     4,  1331,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,  1346,    12,    13,     6,   188,     6,    95,
    1353,  1360,   197,     6,  1357,   578,     6,   196,  1361,     7,
     106,   139,  1352,  1309,     7,  1311,     7,  1313,   114,   115,
     116,  1361,  1362,  1363,   120,   121,   122,   123,  1381,     7,
     139,  1327,     7,     7,  1330,  1331,     7,     7,     4,   139,
     190,   197,     6,   195,   190,   190,  1646,   195,   195,  1402,
     190,   195,   193,     6,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   197,    83,   197,    95,   192,     7,
      88,    89,     7,    91,    92,    93,   196,     7,   106,    97,
       6,     6,   193,   196,   196,  1438,   114,   115,   116,   196,
    1443,   196,   120,   121,   122,   123,     6,   670,     6,   672,
       7,   197,     6,     6,   191,   189,   189,     6,   177,     7,
    1463,     7,     7,   131,   132,   133,     6,  1470,   196,    80,
    1473,     7,     7,    12,    13,     7,     7,     6,   196,     7,
       7,     7,     7,     7,     7,  1488,     4,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,  1504,     4,     6,  1507,   188,   729,     6,  1510,   189,
       7,     6,   196,     7,     7,  1473,     7,     6,     6,   197,
    1523,     6,    78,     6,     6,  1528,     6,     4,     4,   197,
       4,   197,     4,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     6,    83,     6,     6,     6,     6,    88,
      89,   774,    91,    92,    93,   195,   190,   190,    97,   190,
     783,   190,   785,   195,   787,     7,   789,  1570,  1514,   196,
    1516,   794,  1518,     6,   797,   193,   189,     6,   193,     6,
    1526,     6,    88,  1529,   196,     6,  1589,    95,   196,   196,
     196,     6,   131,   132,   133,     6,   196,     6,   106,     6,
       5,     4,     6,    86,    87,   196,   114,   115,   116,   196,
       6,     6,   120,   121,   122,   123,     7,   196,   196,  1609,
     191,     6,     6,  1569,     6,     4,   849,  1573,   196,   196,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,  1647,   196,  1649,     6,   188,     6,
       6,   135,   195,     6,     4,     6,     4,     6,   197,  1662,
       6,   884,   885,   886,   887,     6,     6,     6,     4,     6,
       5,    95,     6,     6,     6,     6,  1622,   196,     6,     6,
    1626,     6,   106,   139,   167,   168,   169,   170,   171,   197,
     114,   115,   116,     6,     6,     6,   120,   121,   122,   123,
       6,   184,     6,  1649,     6,   188,     6,  1697,     6,   195,
       6,     6,     6,     6,     6,  1718,     7,   940,     6,   202,
     203,   204,   205,  1726,   207,   208,   209,   210,   190,   212,
     213,   214,     6,     6,     6,     5,   219,     6,   193,   196,
       6,     6,   196,   196,     7,   197,    76,  1726,   197,   196,
    1753,   196,   196,   196,   237,     6,   134,     6,  1704,  1705,
     197,     6,   137,   246,   247,     6,     6,  1770,  1726,  1772,
       6,     6,   255,   197,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,     6,     6,
       6,  1770,   188,  1772,   196,     6,     6,     6,     6,  1802,
       6,     6,   196,   196,   196,   288,   289,   290,   196,     6,
     197,    95,  1770,    95,  1772,   196,     6,   300,   301,   302,
       6,   304,   106,  1802,   307,   308,     6,     6,   311,     6,
     114,   115,   116,     6,     6,     6,   120,   121,   122,   123,
       6,     6,   325,   326,  1802,   197,     6,     6,     6,   196,
       6,   196,   196,   196,     6,     6,   339,   340,     6,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   196,     6,     6,     6,     6,   196,   196,   196,   196,
     373,     6,     6,   376,     6,   378,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       6,     6,     6,   197,   188,   398,     6,     6,   401,     6,
       6,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,  1612,   435,   421,   422,
    1493,  1096,  1494,     3,     3,   465,    -1,  1240,  1506,    95,
      -1,  1174,  1106,    -1,    -1,    -1,   439,    -1,    -1,    -1,
     106,    -1,   445,    -1,    -1,    -1,    -1,   450,   114,   115,
     116,    -1,   455,   456,   120,   121,   122,   123,   461,   462,
      -1,    -1,    -1,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,
     493,   494,   495,   496,   497,    -1,    -1,    -1,   501,   502,
     503,   504,   505,    -1,    -1,    -1,   509,    -1,   511,   512,
      -1,    -1,    -1,   516,   517,   518,    -1,    -1,   521,   522,
     523,   524,   525,    12,    13,    -1,    -1,    -1,   531,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,   548,   549,    -1,   551,   552,
      -1,    -1,    12,    13,    -1,    -1,  1299,  1300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   570,    -1,    -1,
      -1,    -1,    -1,    -1,   577,   578,    -1,    -1,    -1,    -1,
     583,    -1,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
     633,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,     6,   131,   132,   133,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,   667,    95,    -1,   670,    -1,   672,
     673,   131,   132,   133,    -1,    -1,   106,    -1,   681,     5,
      -1,   684,   685,     6,   114,   115,   116,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,   698,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   707,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
    1463,    -1,    48,    -1,    -1,    -1,   729,    53,    54,    55,
      -1,    -1,    58,   736,   737,   203,    -1,   197,    -1,   742,
     208,    -1,    -1,    69,   212,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   755,    -1,    -1,   758,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1507,    -1,    -1,   197,    -1,    -1,
      -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     783,    -1,   785,    -1,   787,  1528,   789,    -1,    -1,    -1,
       6,   794,    -1,    -1,   797,    -1,    -1,    -1,    -1,    -1,
     803,    -1,   805,   806,    -1,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
     288,    -1,   290,   188,    -1,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   837,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   845,   846,   847,    -1,   849,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   864,    -1,    -1,    -1,   188,    -1,    -1,   871,    -1,
     215,   874,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,   884,   885,   886,   887,    -1,    -1,     6,   891,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1647,    -1,  1649,    -1,    39,    40,
      41,    42,    43,    44,    -1,    95,    -1,    48,   263,    -1,
      -1,    -1,    53,    54,    55,    -1,   106,    58,    -1,    -1,
      -1,    -1,    -1,   401,   114,   115,   116,   940,    69,    -1,
     120,   121,   122,   123,    -1,    -1,    -1,   950,    -1,   952,
      -1,   954,    -1,   956,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,   439,   188,    -1,    -1,  1718,    -1,    -1,   323,   324,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   336,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,  1004,    -1,    -1,  1007,    -1,   474,   475,  1011,     6,
    1013,  1014,  1015,    -1,    -1,    -1,    -1,   197,  1021,    -1,
      -1,   152,   153,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,  1038,    -1,  1040,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,   517,
     518,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,  1074,    -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,  1086,  1087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1098,  1099,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
     578,    -1,    -1,    -1,    88,    89,    -1,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,    -1,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
    1143,  1144,  1145,    -1,   188,    -1,    -1,    -1,    -1,    -1,
    1153,   195,  1155,   197,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,  1166,    12,    13,    -1,    -1,    -1,    -1,
      -1,  1174,    -1,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,  1200,  1201,  1202,
      -1,    -1,   670,    -1,   672,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   684,   685,    -1,    -1,
      -1,     6,    -1,   197,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,  1237,    83,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    -1,    -1,  1251,    97,
      -1,    -1,    -1,  1256,    -1,    -1,    -1,     6,    -1,    -1,
      -1,   729,    -1,    -1,    -1,    -1,  1269,  1270,    -1,    -1,
      -1,    -1,    -1,  1276,  1277,    -1,    -1,     6,  1281,    -1,
      -1,    -1,    -1,   131,   132,   133,  1289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1299,  1300,  1301,    -1,
    1303,    -1,   647,    -1,    -1,    -1,   774,    -1,    -1,    -1,
      -1,    -1,  1315,    -1,    -1,   783,    -1,   785,    -1,   787,
      -1,   789,    -1,     6,  1327,    -1,   794,    -1,  1331,   797,
      -1,  1334,    -1,    -1,    -1,    -1,  1339,  1340,  1341,  1342,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1352,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1362,
      -1,    -1,    -1,   708,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    -1,    -1,  1379,  1380,    -1,    -1,
      -1,   849,    -1,    -1,  1387,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   884,   885,   886,   887,
    1423,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,  1441,   188,
    1443,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,  1458,    -1,  1460,    -1,   188,
    1463,    -1,    -1,    -1,    -1,    -1,    -1,  1470,   813,    -1,
      -1,    -1,   940,    -1,   819,    -1,    -1,    -1,    -1,    -1,
      -1,  1484,    -1,    -1,    -1,    -1,  1489,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,     8,    -1,  1507,   188,    -1,    -1,    -1,    -1,
     855,  1514,    -1,  1516,    -1,  1518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1528,    -1,    -1,    -1,  1532,
    1533,  1534,  1535,  1536,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,  1551,  1552,
      -1,    -1,   188,  1556,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,  1566,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1577,    -1,    -1,    -1,    -1,    -1,
      -1,   926,   927,    -1,   929,    -1,   931,   932,    -1,    -1,
     935,   936,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,  1607,    -1,    -1,    -1,   188,  1612,
      -1,    -1,    -1,    -1,    -1,    -1,  1619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1633,     8,    -1,  1636,    -1,    -1,  1639,    -1,    -1,    -1,
    1643,    -1,    -1,    -1,  1647,    -1,  1649,  1650,  1651,  1652,
    1653,    -1,    -1,    -1,    -1,    -1,    -1,  1660,    -1,    -1,
    1663,    -1,    -1,    -1,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,     8,  1024,
    1025,  1026,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1035,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1703,    -1,     8,    -1,    -1,    -1,  1174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1718,    -1,  1720,  1721,  1722,
    1723,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,  1088,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1756,  1757,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1107,  1766,  1767,  1768,  1769,    -1,  1113,    -1,
      -1,    -1,    -1,    -1,  1119,    -1,  1121,  1122,    -1,    -1,
      -1,  1126,  1127,    -1,  1129,    -1,  1131,    -1,  1133,    -1,
    1135,  1136,  1137,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,  1153,    95,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1168,    -1,    -1,    -1,  1172,    -1,    -1,
      -1,  1299,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,  1327,
      -1,    -1,    -1,  1331,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,  1250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,  1263,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    12,    13,    53,    54,    55,    -1,    -1,    58,    -1,
      60,    61,    62,    -1,    -1,  1443,    -1,    -1,    68,    69,
      -1,    -1,    -1,    -1,  1329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1463,    -1,    -1,    -1,    -1,
      -1,  1346,  1470,    -1,    -1,    -1,    -1,    -1,  1353,    -1,
      -1,    -1,  1357,    -1,    -1,    -1,  1361,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,  1381,    88,    89,  1507,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,  1402,    -1,    -1,
    1528,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,    -1,    -1,  1438,   184,    -1,    -1,    -1,    -1,   189,
      -1,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,  1488,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,  1504,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,     3,     4,  1523,  1647,
      -1,  1649,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,  1570,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,  1589,    72,    -1,    -1,    75,    -1,
    1718,    78,    -1,    80,    -1,    -1,    -1,    -1,   151,    -1,
      -1,   154,    -1,    -1,    -1,    92,   159,   160,   161,   162,
     163,    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,   108,    -1,    -1,   111,    -1,   179,   180,    -1,    -1,
      -1,   184,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1662,    -1,    -1,
      -1,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,    -1,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   179,   180,    -1,    -1,   188,   184,    -1,    -1,
      -1,    -1,   189,   195,    -1,   197,    -1,   194,    -1,   196,
     197,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,  1753,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,   179,   180,    -1,
     188,    -1,   184,    -1,    -1,    -1,    -1,   189,    -1,   197,
      -1,    -1,   194,    -1,    -1,   197,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    54,    55,    -1,
      -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,   108,    -1,    -1,   111,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   164,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   179,   180,    -1,    -1,   188,   184,   190,    -1,
      -1,    -1,   189,   195,     3,     4,     5,   194,    -1,   196,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,
      -1,    -1,   111,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     179,   180,    -1,    -1,   188,   184,    -1,    -1,    -1,    -1,
     189,   195,     3,     4,     5,   194,    -1,   196,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    54,    55,    -1,    -1,    58,    -1,    60,
      61,    62,    -1,     3,     4,     5,    -1,    68,    69,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     151,   152,   153,   154,    -1,    -1,    -1,   197,   159,   160,
     161,   162,   163,   164,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   179,   180,
      -1,    -1,   188,   184,    -1,    -1,    -1,    -1,   189,    -1,
      -1,   197,    -1,   194,    -1,   196,    -1,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   151,   152,   153,   154,   188,    -1,   190,    -1,   159,
     160,   161,   162,   163,   164,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   179,
     180,    -1,    -1,   188,   184,    -1,    -1,    -1,    -1,   189,
     195,     3,     4,     5,   194,    -1,   196,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    12,
      13,    53,    54,    55,    -1,    -1,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,
      93,    -1,    -1,    -1,    97,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   151,
     152,   153,   154,   188,    -1,   190,    -1,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,
      -1,    -1,   184,    -1,    -1,    -1,    -1,   189,    -1,     3,
       4,     5,   194,    -1,   196,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,   197,    49,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,   179,   180,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,   189,    -1,     3,     4,     5,
     194,    -1,   196,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,   197,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,   108,    -1,    -1,   111,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    83,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,   179,   180,    -1,    -1,    -1,   184,    -1,
      -1,    -1,    -1,   189,    -1,     3,     4,    -1,   194,    -1,
     196,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,   197,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
     108,    -1,    -1,   111,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,   179,   180,    -1,    -1,    -1,   184,    -1,    -1,    -1,
      -1,   189,    -1,     3,     4,    -1,   194,    -1,   196,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
     197,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,    -1,
      -1,   111,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,   179,
     180,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,   189,
      -1,     3,     4,    -1,   194,    -1,   196,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,   179,   180,    -1,
     188,    -1,   184,    -1,    -1,    -1,    -1,   189,   196,     3,
       4,    -1,   194,    -1,   196,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,   179,   180,    -1,   188,    -1,
     184,    -1,    -1,    -1,    -1,   189,   196,     3,     4,    -1,
     194,    -1,   196,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,   108,    -1,    -1,   111,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,   179,   180,    -1,   188,    -1,   184,    -1,
      -1,    -1,    -1,   189,   196,     3,     4,     5,   194,    -1,
     196,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,
      58,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   197,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   179,   180,    -1,    -1,   188,   184,     3,     4,    -1,
      -1,   189,   195,     9,    10,    11,   194,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,   108,    -1,    -1,   111,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   179,   180,    -1,    -1,   188,   184,     3,
       4,    -1,    -1,   189,   195,     9,    10,    11,   194,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,   179,   180,    -1,    -1,    -1,
     184,    -1,    50,    51,    52,   189,    -1,    -1,    56,    57,
     194,    59,    -1,    -1,    -1,    63,    64,    -1,    66,    67,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,     4,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      12,    13,   130,   131,   132,   133,    -1,    -1,   136,    -1,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    37,    38,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,   165,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    -1,    59,    -1,    -1,
      -1,    63,    64,    -1,    66,    67,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,    -1,    -1,   136,    -1,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     190,    -1,   192,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,   192,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,   192,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
     192,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,   192,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   192,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,   192,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,   192,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     190,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,   190,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,   190,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,   190,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,   190,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,   190,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,   190,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     190,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,   190,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,   190,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,   190,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,   190,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,   190,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,   190,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     190,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,   190,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,   190,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,   190,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,   190,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,   190,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,   190,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,   190,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
     190,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,   190,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,   190,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   200,   201,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    56,    57,    59,    63,    64,    66,
      67,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   106,   107,   108,   109,   110,   111,
     112,   113,   117,   118,   119,   125,   130,   131,   132,   133,
     136,   138,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   155,   156,   157,   158,   165,   202,   204,
     205,   225,   242,   243,   246,   247,   248,   249,   250,   251,
     252,   253,   274,   275,   276,   277,   295,   296,     3,     4,
       5,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    53,    54,    55,
      58,    60,    61,    62,    68,    69,   145,   151,   152,   153,
     154,   159,   160,   161,   162,   163,   164,   179,   180,   184,
     189,   191,   193,   194,   196,   198,   223,   278,   279,   291,
     292,   295,   296,    13,    78,   189,   189,     6,   196,     6,
       6,     6,     6,   189,     6,     6,   191,   191,   189,   191,
     223,   223,   189,   196,   189,   189,     4,   189,   196,   189,
     189,     4,   196,   189,   189,    82,    78,    78,     6,   196,
      72,    75,    78,    78,    78,    75,    78,    80,    80,    72,
      75,    78,    80,    75,    78,    80,    75,    78,   189,    75,
     136,   149,   150,   196,   179,   180,   189,   196,   281,   282,
     281,   196,    72,    75,    78,   196,   281,     4,    72,    76,
      88,    78,    80,    78,    75,     4,   145,   196,   295,   296,
       4,     6,    72,    75,    78,    75,    78,     4,     4,     4,
       4,     5,    36,    72,    75,    78,    80,    92,   180,   189,
     196,   243,   253,   278,   284,   285,   286,   295,   296,     4,
     189,   189,   189,     4,   196,   288,     4,   189,   189,     6,
       6,   191,     4,   296,     4,     5,   196,     5,   196,     4,
     278,   278,     6,   189,   196,   189,   191,   198,   223,     7,
     166,   167,   168,   169,   185,   186,   221,   222,     4,   189,
     191,   193,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   189,   189,   189,
     189,   189,   189,   223,   189,   223,   223,   223,     7,   189,
     189,   189,   223,   189,   189,   278,   278,   278,   278,   278,
       4,   136,   137,   296,     4,   243,   244,   245,   196,   190,
     192,   196,   224,     6,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   188,   196,
       6,   189,   191,   222,     6,   278,     4,   291,   292,   296,
     291,   278,   291,   294,   227,   230,   292,   296,   278,   180,
     278,   286,   287,   278,   278,   189,   278,   287,   278,   278,
     189,   287,   278,   278,   284,   189,   196,   287,   285,   285,
     285,   189,   189,   285,   285,   285,   189,   189,   189,   189,
     189,   189,   189,   189,   196,   196,   278,     4,   284,   288,
     196,   196,   281,   281,   281,   278,   278,   179,   180,   196,
     196,   281,   196,   196,   196,   179,   180,   189,   245,   281,
     196,   189,   196,   189,   189,   189,   285,   285,   284,   189,
       4,   191,   191,   245,     6,     6,   196,   196,   196,   285,
     285,   191,   191,   191,   189,   191,   193,   223,   191,     5,
     139,   196,     5,   139,     5,   139,     5,   139,    72,    75,
      78,    80,   196,   278,   286,   278,   197,   287,     8,   181,
       6,   189,   191,   223,     6,   278,   278,   278,   193,   278,
     196,   139,   278,   278,   278,     6,     6,   245,     6,   245,
     191,     6,   196,   284,   284,   278,   278,   196,   196,   224,
     292,   284,     6,   191,   278,   278,     4,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   294,
     291,   294,   291,   291,   291,   284,   291,   291,   278,   294,
     291,   278,   292,   278,   291,   291,   291,   291,   296,   292,
     190,   192,     7,   221,   222,   193,     7,   223,   197,    72,
      75,    78,    80,   242,   278,   287,     7,   221,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   206,   278,   278,     6,   191,   193,   190,
     195,   190,   195,   195,   190,   195,   192,   195,   226,   192,
     226,   195,   195,   190,   181,   195,   197,   190,   190,   278,
     190,   197,   190,   190,   278,   197,   190,   190,     7,   278,
     278,   197,     6,     6,     6,   278,   278,     7,     7,   271,
     271,   278,   236,   278,   292,   237,   278,   292,   238,   278,
     292,   239,   278,   292,   278,   278,   278,   287,   287,   196,
     190,     6,   196,   245,   245,   195,   195,   195,   281,   281,
     244,   244,   195,   278,   278,   278,   278,   257,   195,   245,
     278,   278,   278,   278,   278,     7,   272,     6,     7,   278,
       6,   278,   278,   197,   287,   287,   287,     6,     6,   278,
     278,   278,   278,     4,   196,   224,   296,    50,   278,    50,
      50,    50,     5,   196,     5,   196,     5,   196,     5,   196,
     287,   190,   197,   278,   196,   278,   286,   196,   224,   190,
     190,   190,   136,   195,   245,   196,     8,   190,   192,   197,
     197,   245,   190,   195,   197,   190,   192,   278,   287,   221,
       6,     6,   278,   190,   192,   222,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   195,   224,   224,
     224,   224,   224,   224,   224,   195,   195,   195,   224,   195,
     224,   224,   190,   190,   195,   195,   195,   195,   195,   190,
     224,   280,   293,     6,   195,   190,   190,   195,   224,   190,
     190,   221,   222,   193,   221,   222,   292,   278,     6,     4,
       4,   196,   289,   224,   196,   196,   196,   196,   197,   197,
     284,     8,     4,   126,   127,   128,   129,   197,   209,   213,
     216,   218,   219,   190,   192,   278,     4,     6,   177,   203,
     287,     6,   287,   278,     6,   291,     6,   296,     6,   291,
     278,   292,     7,   278,   286,   139,     7,     7,   190,     7,
     139,     7,     7,   190,   139,     7,     7,   278,   190,   197,
     196,   190,   190,   278,   284,     4,   270,     6,   190,   190,
     195,   190,   195,   190,   195,   190,   195,   190,   190,   190,
     197,   197,   287,   193,   245,   197,   197,   281,   278,   278,
     197,   197,   278,   281,   195,   195,   195,    95,   106,   114,
     115,   116,   120,   121,   122,   123,   267,   268,   281,   197,
     254,   190,   197,   190,   190,   190,   278,     6,   278,   190,
     192,   192,   197,   197,   197,   192,   192,   195,   192,   287,
     192,   196,   197,   196,   196,   196,   287,   287,   287,   287,
     197,     8,   287,   287,     7,     7,     7,   193,   278,   197,
     278,   278,     7,   193,   197,   196,   284,     6,   221,   222,
     221,   222,   197,   197,   284,   192,   222,   193,   222,   291,
     278,   278,   278,   278,   287,   291,   284,   291,   291,   292,
     232,   234,   278,   291,   278,     6,     4,   136,   137,   278,
       6,     6,     6,     7,   191,   288,   290,     6,   287,   287,
     287,   287,   224,     6,   278,   210,   189,   189,   196,   220,
       6,   222,   222,   192,   177,   291,   190,   190,   195,     7,
     224,   224,   281,    78,    80,   284,   284,     7,   284,    78,
      80,   284,   284,     7,    80,   284,   284,     6,     7,     7,
     287,     7,     7,    95,   269,     6,     7,   221,   278,   221,
     278,   221,   278,   221,   278,     7,     7,     7,     7,     7,
     197,     4,   197,   195,   195,   195,   197,   197,   281,   281,
     281,     4,     6,   196,     6,   189,     6,   124,     6,   124,
       6,   124,     6,   124,   197,   268,   195,   267,     7,     6,
       7,     7,     7,     6,   196,     6,     6,     6,    78,   278,
       6,     6,   278,   193,   197,   278,   278,   278,   278,   197,
     197,   197,   197,   278,   197,   197,   284,   284,   284,     4,
     195,     8,     8,   190,     4,     4,   284,   197,   278,     6,
     278,     6,   224,     6,     6,     4,     6,   224,   224,   224,
     224,   224,   195,   190,   190,   190,   195,   195,   224,   233,
     195,   224,   235,   190,   190,     6,     7,   221,   222,   193,
       7,     6,   288,   278,   195,   197,   197,   197,   197,   197,
     221,   189,   278,   278,   283,   284,   196,   193,     6,     6,
     203,     6,   278,   196,   278,   292,     6,     6,     6,   196,
     196,    88,   241,   241,   284,     6,   196,   196,     6,     6,
     284,   196,     6,     6,     5,   284,   197,   284,   284,     4,
       6,   284,   284,   284,   284,   284,   284,   284,   284,   196,
     196,     7,     6,     7,   278,   278,   278,   196,   196,   195,
     197,   195,   197,   195,   197,   191,   278,   284,   278,     6,
       6,     6,     6,   278,   281,   197,     5,   196,   284,   196,
     196,   196,   284,   287,   196,     6,   192,     4,   224,   195,
     195,   195,   195,   224,     6,     6,   135,   278,   278,   278,
       6,     6,     7,   195,     6,     6,     6,   221,   222,   291,
     292,     4,     4,   148,   292,   278,     6,     4,   289,     6,
     192,   288,     6,     6,     6,     6,   284,   207,   278,   195,
     195,   195,   197,   208,   278,     4,   291,   195,   284,   292,
     278,   278,   281,     6,     6,     6,   278,   278,     6,   278,
       5,     6,   196,     6,   139,   240,   278,     6,     6,     6,
       6,     6,     6,     4,     6,     6,   287,   287,   278,   278,
     292,   197,   190,   195,   197,   244,   244,   281,     6,   258,
     281,     6,   259,   281,     6,   260,   278,   197,   195,   190,
     197,   195,     6,   180,   281,     6,   283,   281,   281,     6,
     197,   278,     6,   278,   278,   278,   278,   284,   195,   197,
       8,   197,   190,   196,   278,   292,   284,   284,   190,   224,
     196,   284,   292,   196,   278,   292,   292,     6,     6,     7,
       6,   193,     6,   190,   195,   278,   278,   284,   196,   195,
     197,     6,   278,   228,   229,   197,   197,   197,   197,   197,
       5,   283,    76,     6,   196,   197,   197,   196,     6,     6,
     196,   278,   197,   197,   195,   196,   195,   196,   195,   196,
     192,     6,   284,     7,   196,   278,   195,   197,   195,   195,
       6,   197,   195,   195,   195,   195,   134,   278,   278,   287,
       6,     6,   197,     6,   231,   278,   294,   288,   137,   211,
     278,   195,   195,   283,   278,     6,   195,   232,   234,     6,
       6,     6,     6,     6,     6,   197,   196,   283,    99,   100,
     105,   273,    99,   100,   273,   287,   244,   195,   197,   278,
     281,   267,   278,   281,   267,   278,   281,   267,     6,   195,
     197,   284,   245,   197,   281,     6,   287,   281,   278,   278,
     278,   278,   278,   197,   197,   197,     6,   195,   197,     7,
     197,     6,   196,   278,   278,   197,   278,   197,   197,   196,
     278,   197,   196,   281,   284,     6,   196,   281,     6,   197,
     197,   278,   197,   195,   197,   197,   195,   197,   197,   195,
     197,   284,     6,    95,   197,   255,   196,   195,   197,   195,
     195,   195,   195,   195,     6,     6,   278,   292,   208,   190,
     195,     6,   196,   195,   278,   197,     6,   281,     6,   281,
       6,     6,   197,     6,   261,   278,     6,     6,   262,   278,
       6,     6,   263,   278,     6,   197,   278,   267,   245,   287,
       6,   281,   287,   278,   278,   278,   278,     7,   197,   214,
     278,   283,   278,   195,   195,   195,   196,   197,   196,   197,
     196,   197,     6,     6,   197,   197,   256,   197,   195,   197,
     195,   195,   195,   195,   292,     6,   196,   190,   197,   197,
     278,   281,   281,   267,     6,   264,   267,     6,   265,   267,
       6,   266,   267,     6,   287,     6,   278,   278,   278,   278,
     212,   291,   217,   196,     6,   197,   195,   195,   197,   196,
     197,   196,   197,   196,   197,   197,   195,   195,   195,   195,
     195,   197,   196,   283,     6,   278,   278,     6,   267,     6,
     267,     6,   267,     6,   278,   278,   278,   278,   291,     6,
     215,   291,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   195,   197,     6,     6,     6,     6,     6,     6,
     291,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   199,   200,   200,   201,   201,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   203,   203,   204,   204,   204,   204,   204,   204,
     205,   205,   205,   205,   206,   206,   206,   206,   206,   206,
     207,   207,   208,   208,   210,   211,   209,   212,   212,   214,
     213,   215,   215,   217,   216,   218,   218,   220,   219,   221,
     221,   221,   221,   221,   222,   222,   223,   223,   224,   224,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   226,   226,   227,
     227,   227,   228,   227,   227,   229,   227,   230,   230,   231,
     231,   232,   232,   233,   233,   233,   234,   234,   235,   235,
     235,   235,   236,   236,   236,   237,   237,   237,   238,   238,
     238,   239,   239,   239,   240,   240,   241,   241,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   243,   243,   243,
     243,   243,   243,   243,   243,   244,   244,   245,   245,   245,
     245,   245,   245,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   247,   247,   247,   247,   247,   248,   248,   249,
     250,   250,   250,   250,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   253,   253,   253,   254,
     253,   255,   253,   256,   253,   257,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   258,   253,   259,   253,
     260,   253,   261,   253,   262,   253,   263,   253,   264,   253,
     265,   253,   266,   253,   267,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   269,   269,   270,   270,   271,   271,   272,   272,   273,
     273,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   275,   275,   275,
     276,   276,   276,   277,   277,   277,   277,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   280,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   281,   281,   281,   281,   281,   282,
     282,   282,   282,   283,   283,   284,   284,   284,   284,   284,
     284,   285,   285,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   287,   287,   287,   287,   288,   288,   288,   288,   289,
     289,   290,   290,   291,   291,   291,   291,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   293,   292,   294,   294,   295,   295,
     296,   296
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
       1,     2,     1,     3,     4,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     2,     3,     2,     3,     2,     3,     2,     3,     9,
       6,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     7,     6,     8,     5,     3,     7,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,    10,    10,
      10,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     4,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     5,     5,     3,     6,     4,     7,     6,
       6,     6,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     5,     5,     5,     5,
      16,    16,    16,    16,     1,     1,     3,     3,     4,     6,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     3,     6,     1,     1,     1,
       1,     4,     6,     4,     4,     4,     4,     8,     4,     8,
       4,     6,     4,     1,     0,     6,     1,     3,     5,     5,
       1,     1
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
#line 192 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 203 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 204 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 205 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 206 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 207 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4290 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 227 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 234 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 239 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 244 "Gmsh.y" /* yacc.c:1646  */
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
#line 4384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 258 "Gmsh.y" /* yacc.c:1646  */
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
#line 4401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 271 "Gmsh.y" /* yacc.c:1646  */
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
#line 4418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 284 "Gmsh.y" /* yacc.c:1646  */
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
#line 4445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "Gmsh.y" /* yacc.c:1646  */
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
#line 4463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 326 "Gmsh.y" /* yacc.c:1646  */
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
#line 4480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 339 "Gmsh.y" /* yacc.c:1646  */
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
#line 4497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 352 "Gmsh.y" /* yacc.c:1646  */
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
#line 4516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 370 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 384 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 393 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 398 "Gmsh.y" /* yacc.c:1646  */
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
#line 4658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 502 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 4672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 512 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 521 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 528 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 538 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 4717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 547 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 556 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 563 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 573 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 4761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 581 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 591 "Gmsh.y" /* yacc.c:1646  */
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
#line 4791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 610 "Gmsh.y" /* yacc.c:1646  */
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
#line 4811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 629 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 635 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4828 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 642 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4846 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4858 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4864 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 4882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 4888 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 4894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 667 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 4903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 672 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 4913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 678 "Gmsh.y" /* yacc.c:1646  */
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
#line 4977 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 738 "Gmsh.y" /* yacc.c:1646  */
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
#line 5010 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 767 "Gmsh.y" /* yacc.c:1646  */
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
#line 5043 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 796 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 801 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 806 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 811 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5079 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 816 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 823 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 830 "Gmsh.y" /* yacc.c:1646  */
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
#line 5120 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 845 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5129 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 855 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 860 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 865 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 874 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5176 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 880 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5186 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 889 "Gmsh.y" /* yacc.c:1646  */
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
#line 5208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 907 "Gmsh.y" /* yacc.c:1646  */
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
#line 5230 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 925 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 934 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 946 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 951 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 959 "Gmsh.y" /* yacc.c:1646  */
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
#line 5298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 979 "Gmsh.y" /* yacc.c:1646  */
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
#line 5322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1002 "Gmsh.y" /* yacc.c:1646  */
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
#line 5337 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1013 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 5349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1021 "Gmsh.y" /* yacc.c:1646  */
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
#line 5375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1043 "Gmsh.y" /* yacc.c:1646  */
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
#line 5402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1066 "Gmsh.y" /* yacc.c:1646  */
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
#line 5432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1092 "Gmsh.y" /* yacc.c:1646  */
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
#line 5454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1113 "Gmsh.y" /* yacc.c:1646  */
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
#line 5470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1125 "Gmsh.y" /* yacc.c:1646  */
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
#line 5486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1143 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 5499 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1152 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 5512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1161 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5518 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1163 "Gmsh.y" /* yacc.c:1646  */
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
#line 5538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1179 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 5551 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1188 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1190 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 5571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1204 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5581 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1212 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1218 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1230 "Gmsh.y" /* yacc.c:1646  */
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
#line 5615 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1241 "Gmsh.y" /* yacc.c:1646  */
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
#line 5633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1256 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5645 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1272 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1280 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1289 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1297 "Gmsh.y" /* yacc.c:1646  */
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
#line 5696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1315 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1319 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1325 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5723 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1333 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1337 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1343 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1351 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5758 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1355 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1361 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1369 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1373 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1379 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5804 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1387 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1391 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 5826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1403 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1407 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1417 "Gmsh.y" /* yacc.c:1646  */
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
#line 5869 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1440 "Gmsh.y" /* yacc.c:1646  */
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
#line 5905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1472 "Gmsh.y" /* yacc.c:1646  */
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
#line 5929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1495 "Gmsh.y" /* yacc.c:1646  */
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
#line 5951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1513 "Gmsh.y" /* yacc.c:1646  */
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
#line 5976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1534 "Gmsh.y" /* yacc.c:1646  */
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
#line 5998 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1552 "Gmsh.y" /* yacc.c:1646  */
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
#line 6032 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1582 "Gmsh.y" /* yacc.c:1646  */
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
#line 6066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1612 "Gmsh.y" /* yacc.c:1646  */
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
#line 6088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1630 "Gmsh.y" /* yacc.c:1646  */
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
#line 6110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1649 "Gmsh.y" /* yacc.c:1646  */
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
#line 6140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1675 "Gmsh.y" /* yacc.c:1646  */
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
#line 6162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1693 "Gmsh.y" /* yacc.c:1646  */
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
#line 6184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1711 "Gmsh.y" /* yacc.c:1646  */
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
#line 6220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1746 "Gmsh.y" /* yacc.c:1646  */
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
#line 6242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1764 "Gmsh.y" /* yacc.c:1646  */
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
#line 6285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1803 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6295 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1809 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1815 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1822 "Gmsh.y" /* yacc.c:1646  */
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
#line 6345 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1847 "Gmsh.y" /* yacc.c:1646  */
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
#line 6374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1872 "Gmsh.y" /* yacc.c:1646  */
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
#line 6395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1889 "Gmsh.y" /* yacc.c:1646  */
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
#line 6418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1909 "Gmsh.y" /* yacc.c:1646  */
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
#line 6455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1942 "Gmsh.y" /* yacc.c:1646  */
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
#line 6491 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1978 "Gmsh.y" /* yacc.c:1646  */
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
#line 6513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1996 "Gmsh.y" /* yacc.c:1646  */
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
#line 6534 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2013 "Gmsh.y" /* yacc.c:1646  */
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
#line 6554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2029 "Gmsh.y" /* yacc.c:1646  */
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
#line 6590 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2066 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2071 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2076 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2081 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2086 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2091 "Gmsh.y" /* yacc.c:1646  */
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
#line 6662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2114 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2120 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 6684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2130 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2131 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2136 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2140 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2144 "Gmsh.y" /* yacc.c:1646  */
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
#line 6739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2167 "Gmsh.y" /* yacc.c:1646  */
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
#line 6766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2190 "Gmsh.y" /* yacc.c:1646  */
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
#line 6793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2213 "Gmsh.y" /* yacc.c:1646  */
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
#line 6820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2241 "Gmsh.y" /* yacc.c:1646  */
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
#line 6845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2262 "Gmsh.y" /* yacc.c:1646  */
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
#line 6875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2289 "Gmsh.y" /* yacc.c:1646  */
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
#line 6899 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2310 "Gmsh.y" /* yacc.c:1646  */
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
#line 6924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2331 "Gmsh.y" /* yacc.c:1646  */
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
#line 6948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2351 "Gmsh.y" /* yacc.c:1646  */
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
#line 7064 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2463 "Gmsh.y" /* yacc.c:1646  */
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
#line 7087 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2482 "Gmsh.y" /* yacc.c:1646  */
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
#line 7129 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2521 "Gmsh.y" /* yacc.c:1646  */
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
#line 7236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2629 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2638 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2644 "Gmsh.y" /* yacc.c:1646  */
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
#line 7278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2659 "Gmsh.y" /* yacc.c:1646  */
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
#line 7310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2687 "Gmsh.y" /* yacc.c:1646  */
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
#line 7326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2704 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2713 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2727 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2741 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2747 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2753 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2762 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2771 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7424 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2780 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2794 "Gmsh.y" /* yacc.c:1646  */
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
#line 7497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2850 "Gmsh.y" /* yacc.c:1646  */
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
#line 7519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2868 "Gmsh.y" /* yacc.c:1646  */
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
#line 7540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2885 "Gmsh.y" /* yacc.c:1646  */
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
#line 7559 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2900 "Gmsh.y" /* yacc.c:1646  */
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
#line 7582 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2919 "Gmsh.y" /* yacc.c:1646  */
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
#line 7598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2931 "Gmsh.y" /* yacc.c:1646  */
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
#line 7626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2955 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2959 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2964 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2971 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2976 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2982 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2987 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 2993 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 7704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3001 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3005 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3009 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3015 "Gmsh.y" /* yacc.c:1646  */
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
#line 7787 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3069 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[-1].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
#line 7799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3082 "Gmsh.y" /* yacc.c:1646  */
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
#line 7820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3099 "Gmsh.y" /* yacc.c:1646  */
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
#line 7841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3116 "Gmsh.y" /* yacc.c:1646  */
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
#line 7867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3138 "Gmsh.y" /* yacc.c:1646  */
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
#line 7893 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3160 "Gmsh.y" /* yacc.c:1646  */
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
#line 7932 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3195 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 7944 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3203 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 7954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3209 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 7965 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3216 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    }
#line 7973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3220 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 7980 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3229 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 7992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3237 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3245 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8016 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3253 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3259 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8038 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3267 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3273 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3281 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3287 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3295 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8092 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3301 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8103 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3309 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3323 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3330 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3337 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3344 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8169 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3351 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8180 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3358 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3365 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8202 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3372 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8212 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3378 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3385 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8233 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3391 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8244 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3398 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3404 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3411 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3417 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3424 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3430 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3437 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3443 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3450 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3456 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3463 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3469 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8370 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3476 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3482 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3493 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3496 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3502 "Gmsh.y" /* yacc.c:1646  */
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
#line 8421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3514 "Gmsh.y" /* yacc.c:1646  */
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
#line 8445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3534 "Gmsh.y" /* yacc.c:1646  */
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
#line 8472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3558 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3562 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8488 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3566 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3570 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8504 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3574 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3580 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8524 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3590 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3594 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3598 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8556 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3602 "Gmsh.y" /* yacc.c:1646  */
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
#line 8579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3621 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 8591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3633 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3637 "Gmsh.y" /* yacc.c:1646  */
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
#line 8616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3652 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8624 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3656 "Gmsh.y" /* yacc.c:1646  */
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
#line 8642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3672 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8650 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3676 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3681 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8666 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3685 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3691 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3695 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3702 "Gmsh.y" /* yacc.c:1646  */
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
#line 8750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3758 "Gmsh.y" /* yacc.c:1646  */
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
#line 8824 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3828 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 8833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3833 "Gmsh.y" /* yacc.c:1646  */
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
#line 8904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3900 "Gmsh.y" /* yacc.c:1646  */
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
#line 8944 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3936 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 8956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3944 "Gmsh.y" /* yacc.c:1646  */
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
#line 9003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3987 "Gmsh.y" /* yacc.c:1646  */
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
#line 9046 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 4026 "Gmsh.y" /* yacc.c:1646  */
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
#line 9070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4047 "Gmsh.y" /* yacc.c:1646  */
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
#line 9105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4079 "Gmsh.y" /* yacc.c:1646  */
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
#line 9135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4106 "Gmsh.y" /* yacc.c:1646  */
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
#line 9164 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4132 "Gmsh.y" /* yacc.c:1646  */
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
#line 9193 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4158 "Gmsh.y" /* yacc.c:1646  */
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
#line 9222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4184 "Gmsh.y" /* yacc.c:1646  */
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
#line 9251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4210 "Gmsh.y" /* yacc.c:1646  */
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
#line 9276 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4231 "Gmsh.y" /* yacc.c:1646  */
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
#line 9308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4259 "Gmsh.y" /* yacc.c:1646  */
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
#line 9340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4287 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4291 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4295 "Gmsh.y" /* yacc.c:1646  */
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
#line 9388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4323 "Gmsh.y" /* yacc.c:1646  */
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
#line 9431 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4362 "Gmsh.y" /* yacc.c:1646  */
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
#line 9474 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4401 "Gmsh.y" /* yacc.c:1646  */
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
#line 9499 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4422 "Gmsh.y" /* yacc.c:1646  */
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
#line 9524 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4443 "Gmsh.y" /* yacc.c:1646  */
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
#line 9549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4470 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4474 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 9571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4484 "Gmsh.y" /* yacc.c:1646  */
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
#line 9605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4518 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4519 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4520 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4525 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4531 "Gmsh.y" /* yacc.c:1646  */
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
#line 9649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4543 "Gmsh.y" /* yacc.c:1646  */
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
#line 9671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4561 "Gmsh.y" /* yacc.c:1646  */
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
#line 9698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4588 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4589 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4590 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9716 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4591 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4592 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4593 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4594 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4595 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4597 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9757 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4603 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4605 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4606 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4607 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9787 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4608 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4609 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 9799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 9805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4611 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 9811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4612 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 9817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4613 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 9823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4614 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 9829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4615 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 9835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4616 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 9841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4617 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 9847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4618 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 9853 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4619 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 9859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 9865 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4621 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 9871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4622 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 9877 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4623 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 9883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 9889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4625 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 9895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4626 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 9901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4627 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 9907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 9913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4629 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 9919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 9925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 9931 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 9937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4633 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 9943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4634 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 9949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4635 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 9955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 9961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 9967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 9973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 9979 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 9985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 9991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 9997 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4653 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10015 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4658 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4660 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10031 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4671 "Gmsh.y" /* yacc.c:1646  */
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
#line 10061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4688 "Gmsh.y" /* yacc.c:1646  */
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
#line 10083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4706 "Gmsh.y" /* yacc.c:1646  */
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
#line 10105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4724 "Gmsh.y" /* yacc.c:1646  */
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
#line 10127 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4742 "Gmsh.y" /* yacc.c:1646  */
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
#line 10149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4760 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4765 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10168 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4771 "Gmsh.y" /* yacc.c:1646  */
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
#line 10184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4783 "Gmsh.y" /* yacc.c:1646  */
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
#line 10205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4800 "Gmsh.y" /* yacc.c:1646  */
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
#line 10227 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4818 "Gmsh.y" /* yacc.c:1646  */
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
#line 10249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4836 "Gmsh.y" /* yacc.c:1646  */
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
#line 10271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4854 "Gmsh.y" /* yacc.c:1646  */
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
#line 10293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4875 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4880 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4885 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4895 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4905 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4910 "Gmsh.y" /* yacc.c:1646  */
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
#line 10363 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4921 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 4930 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4935 "Gmsh.y" /* yacc.c:1646  */
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
#line 10413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4962 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 4966 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4970 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 4974 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 4978 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 4989 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 4993 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 4997 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5004 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5016 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5021 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5030 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10536 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5034 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5042 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 10560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5053 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5057 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 10581 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10593 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5077 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 10605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5085 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5092 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 10630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5102 "Gmsh.y" /* yacc.c:1646  */
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
#line 10663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5131 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5135 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5139 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5143 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5151 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5155 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5159 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5163 "Gmsh.y" /* yacc.c:1646  */
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
#line 10760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5192 "Gmsh.y" /* yacc.c:1646  */
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
#line 10793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5221 "Gmsh.y" /* yacc.c:1646  */
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
#line 10826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5250 "Gmsh.y" /* yacc.c:1646  */
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
#line 10859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5280 "Gmsh.y" /* yacc.c:1646  */
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
#line 10875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5293 "Gmsh.y" /* yacc.c:1646  */
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
#line 10891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5306 "Gmsh.y" /* yacc.c:1646  */
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
#line 10907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5319 "Gmsh.y" /* yacc.c:1646  */
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
#line 10923 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 10937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5341 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 10951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5351 "Gmsh.y" /* yacc.c:1646  */
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
#line 10967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5363 "Gmsh.y" /* yacc.c:1646  */
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
#line 10983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5376 "Gmsh.y" /* yacc.c:1646  */
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
#line 10999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5388 "Gmsh.y" /* yacc.c:1646  */
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
#line 11021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5406 "Gmsh.y" /* yacc.c:1646  */
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
#line 11043 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5427 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5432 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5436 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11068 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5440 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5452 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5456 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5468 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11108 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5475 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5485 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11127 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5489 "Gmsh.y" /* yacc.c:1646  */
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
#line 11143 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5504 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11152 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5509 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11160 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5516 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11168 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5520 "Gmsh.y" /* yacc.c:1646  */
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
#line 11185 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5533 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5541 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5552 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5556 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5564 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5570 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5576 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11261 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5584 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5592 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5599 "Gmsh.y" /* yacc.c:1646  */
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
#line 11303 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5614 "Gmsh.y" /* yacc.c:1646  */
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
#line 11321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5628 "Gmsh.y" /* yacc.c:1646  */
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
#line 11339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5642 "Gmsh.y" /* yacc.c:1646  */
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
#line 11355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5654 "Gmsh.y" /* yacc.c:1646  */
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
#line 11375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5670 "Gmsh.y" /* yacc.c:1646  */
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
#line 11390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5681 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5685 "Gmsh.y" /* yacc.c:1646  */
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
#line 11421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5704 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5711 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5717 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5719 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5730 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5735 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5741 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5750 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11499 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5763 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5766 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11515 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5770 "Gmsh.y" /* yacc.c:1906  */


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
