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
#define YYLAST   9648

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  199
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  513
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1815

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
    3159,  3194,  3202,  3210,  3216,  3223,  3230,  3234,  3243,  3251,
    3259,  3268,  3267,  3282,  3281,  3296,  3295,  3310,  3309,  3323,
    3330,  3337,  3344,  3351,  3358,  3365,  3372,  3379,  3387,  3386,
    3400,  3399,  3413,  3412,  3426,  3425,  3439,  3438,  3452,  3451,
    3465,  3464,  3478,  3477,  3491,  3490,  3507,  3510,  3516,  3528,
    3548,  3572,  3576,  3580,  3584,  3588,  3594,  3600,  3604,  3608,
    3612,  3616,  3635,  3648,  3651,  3667,  3670,  3687,  3690,  3696,
    3699,  3706,  3709,  3716,  3772,  3842,  3847,  3914,  3950,  3958,
    4001,  4040,  4060,  4092,  4119,  4145,  4171,  4197,  4223,  4245,
    4273,  4301,  4305,  4309,  4337,  4376,  4415,  4436,  4457,  4484,
    4488,  4498,  4533,  4534,  4535,  4539,  4545,  4557,  4575,  4603,
    4604,  4605,  4606,  4607,  4608,  4609,  4610,  4611,  4618,  4619,
    4620,  4621,  4622,  4623,  4624,  4625,  4626,  4627,  4628,  4629,
    4630,  4631,  4632,  4633,  4634,  4635,  4636,  4637,  4638,  4639,
    4640,  4641,  4642,  4643,  4644,  4645,  4646,  4647,  4648,  4649,
    4650,  4659,  4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,
    4668,  4673,  4672,  4680,  4685,  4702,  4720,  4738,  4756,  4774,
    4779,  4785,  4797,  4814,  4832,  4850,  4868,  4889,  4894,  4899,
    4909,  4919,  4924,  4935,  4944,  4949,  4976,  4980,  4984,  4988,
    4992,  4999,  5003,  5007,  5011,  5018,  5023,  5030,  5035,  5039,
    5044,  5048,  5056,  5067,  5071,  5083,  5091,  5099,  5106,  5116,
    5145,  5149,  5153,  5157,  5161,  5165,  5169,  5173,  5177,  5206,
    5235,  5264,  5293,  5306,  5319,  5332,  5345,  5355,  5365,  5377,
    5390,  5402,  5420,  5441,  5446,  5450,  5454,  5466,  5470,  5482,
    5489,  5499,  5503,  5518,  5523,  5530,  5534,  5547,  5555,  5566,
    5570,  5578,  5584,  5590,  5598,  5606,  5613,  5628,  5642,  5656,
    5668,  5684,  5695,  5699,  5718,  5725,  5732,  5731,  5744,  5749,
    5755,  5764,  5777,  5780
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

#define YYPACT_NINF -1328

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1328)))

#define YYTABLE_NINF -489

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6537,    23,    58,  6653, -1328, -1328,  3448,    31,   -40,  -125,
    -109,    50,    92,   155,   183,   187,    93,   226,   280,   -69,
     214,   -68,   -68,  -114,   164,   231,     5,   239,   245,    18,
     282,   332,   468,   335,   485,   565,   396,   576,   522,   534,
     274,   535,   625,   460,   173,   437,   580,   -76,   505,   123,
     123,   511,   373,   388,   212,   603,   613,    15,   106,   636,
     648,   397,   723,   743,   765,  4721,   776,   607,   629,   644,
      33,     7, -1328,   662, -1328,   819,   823,   661, -1328,  2727,
    3122,    12,    41, -1328, -1328, -1328,  6401,  6401, -1328, -1328,
   -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328,
   -1328, -1328, -1328, -1328,    49, -1328,  -105,    98, -1328,     6,
   -1328, -1328, -1328, -1328,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   670,
     679,   693,   706,   711,   718,   -68,   745, -1328,   -68, -1328,
   -1328, -1328, -1328, -1328,   -68,   -68,   865,   749,   753,   764,
     -68,   789,   805, -1328, -1328, -1328, -1328,  6401,  6401,  6401,
    6401,  6401,    26,   885,   357,   802,   271,   785, -1328,   807,
    1001,   -78,   141,  1002,  6401,  3367,  3367, -1328,  6401, -1328,
   -1328, -1328, -1328,  3367, -1328, -1328, -1328, -1328, -1328, -1328,
    2463,   885,  6401,  6219,  6401,  6401,   838,  6401,  6219,  6401,
    6401,   841,  6219,  6401,  6401,  5097,   849,   846, -1328,  6219,
    4721,  4721,  4721,   861,   867,  4721,  4721,  4721,   868,   872,
     873,   897,   904,   935,   936,   966,   847,  1049,  1104,  5097,
      33,   958,   983,   123,   123,   123,  6401,  6401,  -144, -1328,
    -108,   123,   984,  1003,  1005,  3645,   -72,   -87,   972,  1009,
    1013,  4721,  4721,  5097,  1015,    22,  1014, -1328,  1008,  1201,
    1207, -1328,  1018,  1019,  1020,  4721,  4721,  1026,  1027,  1028,
     500, -1328,  1029,    29,    16,    19,    34,   683,  5285,  6401,
    3711, -1328, -1328,  1115, -1328,  1215, -1328,    72,   114,  1218,
    6401,  6401,  6401,  1032,  6401,  1030,  1088,  6401,  6401, -1328,
   -1328,  6401,  1224,  1225, -1328, -1328,  1226, -1328,  1228, -1328,
     586,   840,  5279, -1328,  5097,  5097,  6401,  6401,  1039,   481,
    2463, -1328, -1328, -1328, -1328, -1328, -1328,  5097,  1230,  1046,
    6401,  6401,  1237,  6401,  6401,  6401,  6401,  6401,  6401,  6401,
    6401,  6401,  6401,  6401,  6401,  6401,  6401,  6401,  6401,  6401,
    6401,  6401,  6401,  6401,  6401,  3367,  3367,  3367,  3367,  3367,
    3367,  5097,  3367,  3367,  6401,  3367,  3367,  6401,  2463,  6401,
    3367,  3367,  3367,  3367,   885,  2463,  1054,  1054,  1054,  4312,
    8380,   147,  1055,  1240,  1053,   -68,  1056, -1328,  1057,  3952,
    6401, -1328, -1328,  6219,   112, -1328,  6401,  6401,  6401,  6401,
    6401,  6401,  6401,  6401,  6401,  6401,  6401,  6401,  6401,  6401,
    6401, -1328, -1328,  6401,  6401, -1328, -1328,  1274,    -6,  -172,
   -1328, -1328,   347,  4340, -1328,   554,   204,   304,  1058,  1060,
    4500,  6219,  2080, -1328,   224,  8725,  8746,  6401,  8767,   289,
    8788,  8809,  6401,   303,  8830,  8851,  1249,  6401,  6401,   416,
    1251,  1253,  1255,  6401,  6401,  1258,  1259,  1259,  6401,  6037,
    6037,  6037,  6037,  6401,  6401,  6401,  6219,  6219,  5467,  1072,
    1262,  1068, -1328, -1328,   109, -1328, -1328,  5844,  6032,   123,
     123,   357,   357,   116,  6401,  6401,  6401,  3645,  3645,  6401,
    3952,   156, -1328,  6401,  6401,  6401,  6401,  6401,  1263,  1265,
    1267,  6401,  1266,  6401,  6401,   908, -1328, -1328,  6219,  6219,
    6219,  1271,  1272,  6401,  6401,  6401,  6401,  6401,  1275,   532,
     885, -1328,  1219,  6401, -1328,  1231, -1328,  1232, -1328,  1233,
      44,    45,    46,    48,  6219,  1054, -1328,  8872, -1328,   435,
    6401,  5473, -1328,  6401,  6401,   608, -1328,  8893,  8914,  8935,
    1165,  6214, -1328,  1106,  3032,  8956,  8403, -1328, -1328, -1328,
    1335, -1328,  2049,  6401, -1328, -1328,  1114,   455,  8977,  8426,
    6401,  6219,   112,  1300,  1301, -1328,  6401,  8998,  8449,   190,
    8357,  8357,  8357,  8357,  8357,  8357,  8357,  8357,  8357,  8357,
    8357,  7265,  8357,  8357,  8357,  8357,  8357,  8357,  8357,  7291,
    7317,  7343,   598,   640,   598,  1121,  1122,  1118,  1119,  1120,
    1123,  7369,   567,   502,  9460, -1328,  1304,  1124,  1127,   591,
     502,  1130,  1131,   162,   108,  2463,  6401,  1316,  1319,    38,
     502, -1328,   -22,    37,    43,    -8, -1328,  4433,   581, -1328,
    5097,  3089,  2958,  2212,   964,   964,   461,   461,   461,   461,
     620,   620,  1054,  1054,  1054,  1054,    24,  9019,  8472, -1328,
    6401,  1320,    14,  6219,  1324,  6219,  6401,  1343,  3367,  1345,
   -1328,   885,  1349,  3367,  6401,  2463,  1318,  6219,  6219,  1187,
    1351,  1352,  9040,  1353,  1217,  1355,  1357,  9061,  1243,  1360,
    1362,  6401,  9082,  5227,  1189, -1328, -1328, -1328,  9103,  9124,
    6401,  5097,  1379,  1380,  9145,  1199,  9460,  1195,  1202,  9460,
    1196,  1203,  9460,  1200,  1204,  9460,  1205,  9166,  9187,  9208,
     615,   646,  6219,  1206, -1328, -1328,  2270,  2363,   123,  6401,
    6401, -1328, -1328,  1208,  1209,  3645,  7395,  7421,  7447,  4091,
    1257,   123,  2564,  9229,  5415,  9250,  9271,  9292,  6401,  1390,
   -1328,  6401,  9313, -1328,  8495,  8518, -1328,   647,   697,   701,
   -1328, -1328,  8541,  8564,  7473,  8587,   114,  6219, -1328,  1211,
    1221,  5603,  1223,  1229,  1234, -1328,  6219, -1328,  6219, -1328,
    6219, -1328,  6219,   708, -1328, -1328,  3161,  6219,  1054, -1328,
    6219, -1328,  1391,  1394,  1397,  1227,  6401,  3487,  6401,  6401,
   -1328,    56, -1328, -1328,  4572,  1235,  5097,  1415,   162,   162,
    5791,   709,  5097, -1328, -1328,  8610,   114,   302, -1328, -1328,
   -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328,
    6401, -1328, -1328, -1328, -1328, -1328, -1328, -1328,  6401,  6401,
    6401, -1328,  6219, -1328, -1328, -1328, -1328,  3367,  5097,  3367,
    3367,  2463, -1328, -1328, -1328, -1328, -1328,  6401, -1328, -1328,
    3367, -1328, -1328, -1328,  6401,  1416,    39,  6401,  1423,  1427,
    1494, -1328,  1428,  1245,    33,  1431, -1328,  6219,  6219,  6219,
    6219, -1328,   502,  1433,  6401, -1328,  1252,  1269,  1238, -1328,
    1434, -1328, -1328, -1328, -1328, -1328,   114,   114,  8633, -1328,
   -1328,  1282,  3367,   655, -1328,   663,  7499, -1328, -1328, -1328,
    1435, -1328, -1328,  8357,   502,   123,  2080, -1328,   830,  5097,
    5097,  1453,  5097,   833,  5097,  5097,  1454,  1384,  5097,  5097,
    1742,  1458,  1462,  6219,  1464,  1465,  3705, -1328, -1328,  1483,
   -1328,  1484,   112,  6401,   112,  6401,   112,  6401,   112,  6401,
    1486,  1489,  1490,  1491,  1495,   721,  1497,  4762, -1328, -1328,
     179,  7525,  7551, -1328, -1328,  5937,   -83,   123,   123,   123,
    1499,  1502,  1313,  1504,  1323,    53,    55,    60,    62,   321,
   -1328,   203, -1328,  1257,  1509,  1511,  1517,  1518,  1519,  9460,
   -1328,  1920,  1331,  1523,  1524,  1525,  1455,  6401,  1528,  1529,
    6401,   132,   722, -1328,  6401, -1328,  6401,  6401,  6401,   727,
     728,   733,   742, -1328,  6401,   746,   750,  5097,  5097,  5097,
    1535,  7577, -1328,  3208,   560,  1537,  1541, -1328,  5097,  1375,
   -1328,  6401,  1534,  6401,  1540, -1328,   502,  1568,  1570, -1328,
    1573, -1328,  1575,  8357,  8357,  8357,  8357,   671,  1389,  1395,
    1398,  1400,  1392,   684,   698,  9334,  1401,  1977, -1328,   264,
    1404,  1585,  2015, -1328, -1328, -1328,    33,  6401, -1328,   751,
   -1328,   754,   755,   774,   775,   112, -1328,  9460,  1409,  6401,
    6401,  5097,  1403, -1328, -1328, -1328,  1407, -1328,  1596,    25,
    1597,  6401,  4284,  1598,  1600,    73,  1411,  1413,  1522,  1522,
    5097,  1606,  1418,  1419,  1610,  1611,  5097,  1424,  1615,  1617,
   -1328,  1619,  5097,   779,  5097,  5097,  1623,  1622, -1328,  5097,
    5097,  9460,  5097,  9460,  5097,  9460,  5097,  9460,  5097,  5097,
    5097,  1441,  1442,  1632,   378, -1328,  6401,  6401,  6401,  1444,
    1447,  -110,  -103,   -79,  1438, -1328,  5097, -1328,  6401, -1328,
    1639, -1328,  1640, -1328,  1642, -1328,  1647, -1328, -1328,  3645,
     513,  4909, -1328,  1459,  1467,  5661, -1328,  6219, -1328, -1328,
   -1328,  1482,  2125, -1328, -1328,  8656,  1650,   502,  7603,  7629,
    7655,  7681, -1328, -1328, -1328, -1328,  9460, -1328,   502,  1654,
    1655,  1545, -1328,  6401,  6401,  6401, -1328,  1675,   446,  1493,
    1679,  2422, -1328,  2493, -1328,   112, -1328, -1328,   340, -1328,
   -1328, -1328, -1328, -1328, -1328,  3367, -1328, -1328, -1328,  2463,
    1682, -1328, -1328,     9, -1328, -1328, -1328, -1328, -1328,  2463,
    6401,  1683,  1687,    38, -1328,  1691,  8679,    33, -1328,  1692,
    1698,  1699,  1701,  5097,  6401,  7707,  7733,   780, -1328,  6401,
    1704, -1328, -1328,  3367, -1328,  7759,  3908,  9460, -1328, -1328,
   -1328, -1328,  6401,  6401,   123,  1703,  1705,  1708, -1328,  6401,
    6401, -1328, -1328,  1709,  6401, -1328, -1328,  1714,  1715,  1527,
    1718,  1586,  6401, -1328,  1722,  1725,  1726,  1732,  1737,  1741,
     986,  1743,  6219,  6219,  6401, -1328,  6037,  5965,  9355,  4038,
     357,   357,   123,  1746,   123,  1748,   123,  1750,  6401,   331,
    1562,  9376, -1328, -1328, -1328, -1328,  5995,   267, -1328,  1752,
    1533,  1753,  5097,   123,  1533,  1754,   798,  6401, -1328,  1759,
     114, -1328,  6401,  6401,  6401,  6401, -1328, -1328, -1328,  5097,
    4245,   486,  9397, -1328, -1328,  4345,  5097, -1328, -1328, -1328,
    5097, -1328,  1577,   502,  4096,  4533,  2463,  1762,  2541, -1328,
    1766,  1771, -1328,  1591, -1328, -1328, -1328, -1328, -1328,  1779,
     675,  9460,  6401,  6401,  5097,  1590,   809,  9460, -1328,  1782,
    6401, -1328, -1328,  6161,  6300,   377, -1328, -1328, -1328,  6328,
    6649, -1328,  6677,  1784, -1328,  5097, -1328,  1716,  1785,  9460,
   -1328, -1328, -1328, -1328, -1328, -1328,  1594, -1328, -1328,   839,
     854,  5655,  2753,  1787,  1599, -1328,  6401, -1328,  1601,  1602,
     290, -1328,  1604,   298, -1328,  1605,   344, -1328,  1607,  8702,
    1791,  5097,  1797,  1612,  6401, -1328,  5849,   350, -1328,   890,
     352,   354, -1328,  1803,  6705, -1328,  7785,  7811,  7837,  7863,
    1676,  6401, -1328,  6401, -1328, -1328,  6219,  2789,  1805,  1616,
    1806, -1328, -1328,  3711, -1328, -1328,  3367,  9460, -1328, -1328,
   -1328, -1328,    33, -1328,  1677, -1328, -1328,  6401,  7889,  7915,
   -1328,  5097,  6401,  1810, -1328,  7941, -1328, -1328,  1812,  1813,
    1817,  1818,  1819,  1821,   894,  1633, -1328,  5097,   392,   616,
    6219, -1328, -1328,   357,  4279, -1328, -1328,  3645,  1257,  3645,
    1257,  3645,  1257,  1822, -1328,   895,  5097, -1328,  6733,   123,
    1824,  6219,   123, -1328, -1328,  6401,  6401,  6401,  6401,  6401,
    6761,  6789,   902, -1328, -1328,  1831, -1328,   905,  1162,   906,
    1832, -1328,  1645,  9460,  6401,  6401,   909,  9460, -1328,  6401,
     919,   923, -1328, -1328, -1328, -1328, -1328, -1328,  1646,  6401,
     933,  1648,   123,  5097,  1839,  1652,   123,  1843,   937,  1653,
    6401, -1328,  6817,   375,   650,  6845,   379,   700,  6873,   381,
    1043, -1328,  5097,  1845,  1757,  4950,  1657,   385, -1328,   953,
     422,  7967,  7993,  8019,  8045,  2809, -1328, -1328,  1858, -1328,
    6401, -1328,  2463, -1328, -1328,  6401,  9418,  8071,    51,  8097,
   -1328, -1328,  6401,  6901,  1859,   123,    77, -1328, -1328,   123,
      89, -1328,  1860, -1328,  6929,  1861,  6401,  1863,  1864,  6401,
    1865,  1868,  6401,  1891,  1702, -1328,  6401, -1328,  1257, -1328,
    6219,  1892,  5849,  6401,  6401,  6401,  6401, -1328, -1328,  2902,
   -1328,   965, -1328,  6401, -1328,  5097,  6401,  8123, -1328, -1328,
     427, -1328,   430, -1328, -1328, -1328, -1328,  1706,  6957, -1328,
   -1328,  1707,  6985, -1328, -1328,  1711,  7013, -1328,  1894,  2855,
    1061,  5138,   976, -1328,   444,   990,  8149,  8175,  8201,  8227,
    2463,  1895,  1712,  9439,   991,  7041,  6401,   123,   123,  1257,
    1898,  1257,  1899,  1257,  1904, -1328, -1328, -1328, -1328,  1257,
    1921,  6219,  1922,  6401,  6401,  6401,  6401, -1328, -1328,  3367,
   -1328,  1733,  1925,  7069,   458,   507,  1399, -1328,  1738,  1536,
   -1328,  1758,  1660, -1328,  1761,  1740, -1328,   995, -1328,  8253,
    8279,  8305,  8331,   996, -1328,  1763,  5097, -1328,  1927,  6401,
    6401,  1930,  1257,  1947,  1257,  1952,  1257, -1328,  1955,  6401,
    6401,  6401,  6401,  3367,  1957,  3367,   999, -1328,  7097,  7125,
   -1328,  1871, -1328,  2707, -1328,  2993, -1328,  7153,  7181,  7209,
    7237, -1328, -1328,  1000, -1328,  1958,  1959,  1961,  1962,  1963,
    1964, -1328, -1328, -1328, -1328,  3367,  1965, -1328, -1328, -1328,
   -1328, -1328, -1328, -1328, -1328
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   247,     0,     0,     0,   243,     0,
       0,     0,     0,   342,   343,   344,     0,     0,     5,     7,
       6,     8,     9,    10,    20,    11,    12,    13,    14,    19,
      18,    15,    16,    17,     0,    21,   513,     0,   391,   512,
     489,   392,   393,   394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,     0,   505,
     492,   398,   399,   400,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   491,     0,     0,     0,
      66,    67,     0,     0,   187,     0,     0,     0,   349,     0,
     485,   513,   404,     0,     0,     0,     0,   227,     0,   229,
     230,   225,   226,     0,   231,   232,   109,   117,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,   187,   513,     0,
       0,   339,     0,     0,     0,     0,     0,     0,     0,     0,
     512,   444,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,   467,   437,   443,     0,   438,   513,   404,     0,
       0,     0,     0,   479,     0,     0,     0,     0,     0,   223,
     224,     0,     0,     0,   241,   242,     0,   187,     0,   187,
     512,     0,     0,   345,     0,     0,    66,    67,     0,     0,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   351,   353,     0,
       0,     0,     0,     0,   512,     0,     0,   186,     0,   185,
       0,    68,    69,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,   216,     0,     0,   412,   164,     0,   512,     0,
     485,   486,     0,     0,   508,     0,   107,   107,     0,     0,
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
       0,     0,   187,     0,     0,     0,     0,   244,   245,   210,
       0,   211,     0,     0,   235,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   401,   506,     0,     0,     0,     0,
       0,     0,     0,   350,     0,    59,     0,     0,     0,     0,
       0,   182,     0,     0,     0,     0,   188,     0,     0,    59,
       0,     0,   367,   366,   364,   365,   360,   362,   361,   363,
     355,   354,   356,   357,   358,   359,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   337,   338,     0,     0,
       0,     0,   305,     0,     0,     0,   132,   133,     0,   135,
     136,     0,   138,   139,     0,   141,   142,     0,     0,     0,
       0,     0,     0,     0,   152,   187,     0,     0,     0,     0,
       0,   430,   429,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     0,     0,     0,     0,     0,     0,
     320,     0,     0,   206,     0,     0,   202,     0,     0,     0,
     335,   334,     0,     0,     0,     0,   417,     0,   468,     0,
       0,     0,     0,     0,     0,   454,     0,   455,     0,   456,
       0,   457,     0,     0,   350,   440,   447,     0,   356,   446,
       0,   469,     0,     0,     0,     0,     0,     0,     0,     0,
     246,     0,   212,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    74,     0,   406,   405,   419,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   390,   378,
       0,   380,   381,   382,   383,   384,   385,   386,     0,     0,
       0,   500,     0,   502,   496,   497,   498,     0,     0,     0,
       0,     0,   425,   504,   121,   126,    99,     0,   493,   495,
       0,   403,   409,   410,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,   411,     0,     0,     0,
       0,   510,     0,     0,     0,    44,     0,     0,     0,    57,
       0,    35,    36,    37,    38,    39,   408,   407,     0,   487,
      24,    22,     0,     0,    25,     0,     0,   217,   509,    70,
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
     346,     0,     0,     0,     0,   511,     0,     0,     0,   414,
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
     379,   387,   388,   389,   503,     0,   422,   423,   424,     0,
       0,   402,   122,     0,   507,   127,   421,   494,    78,    59,
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
       0,   499,   501,     0,   123,   125,     0,   128,   129,   130,
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
   -1328, -1328, -1328, -1328,   875, -1328, -1328, -1328, -1328,   360,
   -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328,
   -1328, -1328,  -379,   -67,    11,    -9, -1328,  1539, -1328, -1328,
   -1328, -1328, -1328,   476, -1328,   483, -1328, -1328, -1328, -1328,
   -1328, -1328,   869,  1978,    -2,  -484,  -252, -1328, -1328, -1328,
   -1328, -1328, -1328, -1328,  1979, -1328, -1328, -1328, -1328, -1328,
   -1328, -1328, -1328, -1328, -1328, -1328, -1328, -1328,  -902,  -908,
   -1328, -1328,  1521, -1328,   488, -1328, -1328, -1328, -1328,  1532,
   -1328, -1328,    54, -1328, -1327,  2190,   492,  2067,  1287,  -238,
     756, -1328,    21,    10, -1328,  -361,    -3,    42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,   912,    89,    90,   666,  1380,  1386,
     901,  1088,  1552,  1753,   902,  1702,  1793,   903,  1755,   904,
     905,  1092,   337,   425,   176,   404,    91,   681,   436,  1496,
    1497,   437,  1547,  1063,  1232,  1064,  1235,   715,   718,   721,
     724,  1408,  1275,   646,   291,   398,   399,    94,    95,    96,
      97,    98,    99,   100,   292,   993,  1648,  1719,   750,  1432,
    1435,  1438,  1677,  1681,  1685,  1738,  1741,  1744,   989,   990,
    1127,   949,   712,   759,  1574,   102,   103,   104,   105,   293,
     178,   864,   486,   249,  1257,   294,   295,   296,   549,   305,
     885,  1079,   434,   430,   865,   435,   181,   298
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,    93,   481,   500,   612,  1449,   614,   743,   744,   206,
     339,   306,   636,  1365,   622,   515,   180,   316,   672,   265,
     910,   534,   211,   673,   536,   650,   512,   179,   895,     4,
     391,  1262,   200,   201,   531,   489,   490,   303,   184,   538,
     338,   206,   883,  1069,   183,   107,   318,   211,   182,   785,
     787,   789,   491,   791,   268,   323,   187,  1664,     5,  1159,
     240,  1161,   297,  1035,   185,   570,  1163,   572,  1165,   489,
     490,   489,   490,   241,   242,   202,   489,   490,  1504,  1271,
     186,  1168,   203,  1671,   326,  1312,   327,  1313,   492,   313,
     315,  1170,  1314,   328,  1315,  1673,   489,   490,   189,   269,
     489,   490,   503,   248,   250,   330,   256,   489,   490,   504,
     270,   423,   271,   424,  1150,   649,  1316,   329,  1317,   649,
     328,   198,   196,   199,   502,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     896,   897,   898,   899,   635,   535,   374,  1366,   537,   376,
     266,   190,   392,   393,  1556,   377,   378,   202,   532,   649,
     268,   383,   397,   539,   887,  1070,  1071,  1160,   272,  1162,
    1570,   214,   268,   268,  1164,   670,  1166,   671,   890,   191,
     268,   911,   175,   192,   207,   340,   307,   341,   268,   342,
     297,   208,   911,   822,   175,   297,   429,   432,   317,   297,
     438,   267,   297,   513,   212,   395,   297,   297,   297,   297,
     175,   900,   297,   297,   297,   533,   207,   431,   431,   304,
     736,   737,   194,   888,   884,   431,   297,   319,   324,   889,
     786,   788,   790,   439,   792,   325,   188,  1665,   236,  1036,
     752,   237,   489,   490,   874,   877,   489,   490,   297,   297,
     297,   553,  1168,   554,   331,   332,   333,   334,   489,   490,
     328,  1239,   297,   297,   331,   332,   333,   334,   331,   332,
     333,   334,   193,   335,   336,   297,   195,   297,   489,   490,
     261,   529,   262,   335,   336,   489,   490,   484,   485,   335,
     336,   876,   244,   245,   738,   493,   428,   110,   555,   501,
     807,   745,   246,   331,   332,   333,   334,   335,   336,   247,
     582,   297,   297,   814,   637,  1186,   335,   336,   331,   332,
     333,   334,   335,   336,   297,   489,   490,  -486,  1704,   550,
     583,   136,   137,   138,   139,   140,   141,   335,   336,   225,
     145,   751,   226,   204,   227,   147,   148,   149,   489,   490,
     150,   396,   268,   268,   268,   268,   268,   268,   297,   268,
     268,   155,   268,   268,  1146,   335,   336,   268,   268,   268,
     268,   268,   489,   490,  1305,  1306,  -487,   613,   625,   615,
     616,   617,   257,   619,   620,   632,   679,   623,  1169,   680,
     297,   627,   628,   629,   630,   197,   640,   431,   431,   431,
     431,   431,   431,   216,   431,   431,   980,   431,   431,   688,
     205,   689,   431,   431,   431,   431,   631,   981,   209,  1776,
     331,   332,   333,   334,   210,   982,   983,   984,   297,  1041,
    1043,   985,   986,   987,   988,   252,   489,   490,   253,   335,
     336,   254,  1354,  1355,   158,   159,    48,    49,    50,    51,
     258,   401,  1444,   402,   259,    56,   166,   403,    59,   489,
     490,   213,   275,   297,   297,   276,   260,   489,   490,   717,
     720,   723,   726,   967,   688,  1517,   694,   335,   336,   397,
     397,  1571,  1572,  1519,  1463,  1050,   682,  1573,   688,   680,
     698,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   551,   418,   419,   297,   297,   297,  1167,   420,
     778,   214,   828,   489,   490,   335,   336,   268,  1440,   489,
     490,   489,   490,   489,   490,   233,  -488,   674,   234,  1521,
     235,   297,   675,   741,   742,  1529,   801,  1531,   297,  1532,
     215,   485,   244,   245,   489,   490,   489,   490,   489,   490,
     489,   490,   246,   217,   489,   490,   875,   878,  1205,   255,
    1636,   218,   779,  1130,  1639,  1132,  1642,  1134,   297,  1136,
    1650,   829,   830,   831,   832,   833,   834,   835,   836,   837,
     838,   839,   219,   841,   842,   843,   844,   845,   846,   847,
     223,   489,   490,   851,   853,   854,   489,   490,   980,   489,
     490,   688,   224,   704,   863,   228,  1584,  1652,  1587,   981,
    1590,   871,  1707,   489,   490,  1708,   238,   982,   983,   984,
     688,   886,   795,   985,   986,   987,   988,   489,   490,  1721,
     415,   416,   417,   418,   419,   879,  1078,   297,   220,   420,
     816,   221,   817,  1759,   222,   239,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     297,   401,   297,   402,   420,   268,  1168,   581,   268,  1168,
     268,   263,  1168,  1464,   297,   297,   489,   490,   264,   526,
    1240,   527,   401,   528,   402,   924,   174,   229,   175,   918,
     230,   243,  1760,   231,   922,   232,  1253,   251,   297,   828,
    1328,   273,   460,   461,   462,  1575,  1576,   465,   466,   467,
     431,  1573,   401,   920,   402,   431,   274,   277,   777,   297,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   677,   980,  1690,   278,   420,   678,
    1206,  1042,  1044,   508,   509,   540,   981,   862,   541,  1049,
    1051,   542,   678,   543,   982,   983,   984,   521,   522,   279,
     985,   986,   987,   988,   297,   340,   688,   573,   892,   528,
     299,   869,  1168,   297,   175,   297,   870,   297,   401,   297,
     402,   405,   970,   678,   297,   980,   300,   297,   401,   976,
     402,   417,   418,   419,   800,   991,   981,  1736,   420,  1739,
     688,  1742,   963,   297,   982,   983,   984,  1745,   301,   297,
     985,   986,   987,   988,   268,   309,  1428,  1429,  1168,   310,
     401,  1168,   402,   302,  1168,   852,  1360,  1168,  1245,  1094,
    1095,   688,   688,   964,  1005,  1099,   574,  1637,  1052,   297,
     688,   308,   311,  1100,   268,   297,   268,   268,   688,   368,
    1781,   401,  1783,   402,  1785,  1486,   688,   268,   369,   431,
    1487,  1062,   379,  1168,   401,  1168,   402,  1168,  1058,  1230,
    1060,  1061,   370,  1085,   297,   297,   297,   297,   401,   394,
     402,  1066,   688,  1233,  1006,   371,   688,  1640,  1007,   431,
     372,   431,   431,   688,   688,  1023,  1046,   373,  1106,   268,
    1107,  1112,   431,  1113,  1103,  1104,   688,   688,  1143,  1187,
       7,     8,   688,   688,  1192,  1193,   297,   297,   688,   297,
    1194,   297,   297,  1098,   375,   297,   297,   688,   380,  1195,
     297,   688,   381,  1197,  1051,   688,  1247,  1198,  1248,   688,
     688,  1249,  1250,   382,   431,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   688,
     688,  1251,  1252,   420,   688,  1384,  1289,  1385,   384,  1105,
     642,    24,    25,   643,    27,    28,   644,    30,   645,    32,
    1416,    33,  1417,   688,   385,  1453,    38,    39,   400,    41,
      42,    43,  1241,   421,  1492,    46,  1493,   422,   426,  1374,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   297,   297,   297,   447,   420,  1579,
     452,  1151,  1152,  1153,   688,   297,  1508,  1215,   457,    67,
      68,    69,   458,   476,  1220,  1221,  1222,  1223,  1224,   688,
     463,  1509,   108,   320,  1231,  1234,   464,   468,   111,   112,
     113,   469,   470,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,  1384,   471,  1530,   297,  1384,
    1592,  1568,  1593,   472,   142,   143,   144,   688,   146,  1608,
    1610,   678,  1611,  1613,  1384,   766,  1618,   297,   479,   151,
     152,   153,  1268,   297,  1230,  1549,  1620,   154,  1233,   297,
    1621,   297,   297,   550,   473,   474,   297,   297,  1384,   297,
    1624,   297,   688,   297,  1632,   297,   297,   297,   980,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   688,   981,
    1651,  1361,   420,   297,   482,   475,   980,   982,   983,   984,
    1492,   505,  1701,   985,   986,   987,   988,   981,   297,  1612,
     550,   688,   297,  1720,   297,   982,   983,   984,  1341,   483,
     494,   985,   986,   987,   988,   688,  1384,  1722,  1731,  1346,
     688,  1773,  1768,  1774,  1384,  1805,  1795,  1806,   506,   495,
     157,   496,   507,   160,   511,   514,   328,   516,   161,   162,
     163,   164,   165,   517,   518,   519,   520,   523,   524,   525,
     530,   552,   268,  1327,   556,   560,   562,   563,   167,   168,
     567,   568,   569,   169,   571,   580,   585,   586,   289,  1363,
    1643,   589,   420,   173,  1550,   477,  1362,   639,   638,  1367,
     297,   175,   174,   684,   641,   685,   701,   705,  1717,   706,
     268,   707,   733,   297,   735,   710,   711,   431,   734,   780,
     758,   760,   763,  1361,   761,  1595,  1392,   770,   771,   776,
     669,   782,   783,   784,  1389,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   551,   418,   419,   297,
     297,   805,   808,   420,   815,   431,   823,   824,   397,   397,
     866,   855,   856,   857,   858,   859,  1423,   868,   860,   867,
     872,   873,   881,   882,   909,   925,   928,   297,  1395,   297,
     914,   297,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   687,   418,   419,   297,     7,     8,   917,
     420,   919,   980,   297,  1472,   921,   933,   297,   929,   930,
     932,   297,   934,   981,   935,  1468,  1430,   938,  1433,   939,
    1436,   982,   983,   984,  1475,  1478,  1479,   985,   986,   987,
     988,   297,   937,   948,  1447,   943,   950,  1450,  1451,   952,
     953,   955,   954,   956,   958,   957,  1000,  1691,  1027,   966,
     959,  1028,   297,  1013,  1029,   973,   974,   642,    24,    25,
     643,    27,    28,   644,    30,   645,    32,  1014,    33,  1016,
    1030,  1040,  1068,    38,    39,  1017,    41,    42,    43,  1073,
    1018,  1038,    46,  1074,  1091,  1076,  1077,  1080,   297,  1086,
    1093,  1089,  1102,   297,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,  1090,  1097,
    1110,  1116,   420,   297,  1117,  1121,    67,    68,    69,  1122,
     297,  1124,  1125,   268,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   297,  1128,
     444,  1129,   420,  1138,   980,   449,  1139,  1140,  1141,   453,
    1075,  1144,  1142,  1154,   297,   981,   459,   297,  1155,  1156,
    1157,   397,  1158,   982,   983,   984,  1171,  1172,   431,   985,
     986,   987,   988,   297,  1173,  1174,  1175,  1177,   297,  1178,
    1179,  1180,   812,  1181,  1183,  1184,   108,   280,   177,  1202,
    1212,  1207,   111,   112,   113,  1208,  1214,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   282,
     297,  1583,  1210,  1586,  1216,  1589,  1217,  1218,   142,   143,
     144,  1219,   146,  1597,  1225,  1226,  1600,  1229,  1227,   297,
    1228,  1237,  1243,   151,   152,   153,  1761,  1242,  1254,  1259,
    1260,   154,  1261,  1264,  1269,   283,  1270,  1272,   284,  1273,
    1274,   285,  1278,   286,  1279,  1280,  1281,  1282,   321,   322,
    1284,  1285,  1660,  1286,  1287,   287,  1626,  1292,  1293,  1318,
    1630,   980,    48,    49,    50,    51,    52,  1302,  1303,  1304,
    1310,    56,   981,  1311,    59,  1322,  1323,   297,  1324,   297,
     982,   983,   984,  1325,  1340,  1332,   985,   986,   987,   988,
    1347,  1348,   297,  1333,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,  1337,  1670,
    1349,  1353,   420,  1672,   157,  1357,  1364,   160,  1356,  1369,
     648,  1370,   161,   162,   163,   164,   165,  1372,  1375,   386,
     387,   388,   389,   390,  1376,  1377,  1694,  1378,  1388,  1396,
    1727,  1397,   497,  1446,  1398,  1401,   427,   169,   297,  1403,
     433,  1404,   499,  1405,  1406,  1407,   268,   173,  1410,   247,
     548,  1411,  1412,  1763,   440,   442,   445,   446,  1413,   448,
     442,   450,   451,  1414,   442,   454,   455,  1415,  1120,  1418,
    1754,   442,  1431,   297,  1434,   980,  1437,  1441,  1445,  1448,
    1452,  1734,  1735,   730,   731,  1455,   981,  1471,  1480,   478,
     268,   431,   268,  1482,   982,   983,   984,  1483,   487,   488,
     985,   986,   987,   988,  1484,  1485,  1491,   488,  1494,  1503,
    1507,  1506,  1505,  1512,  1791,  1513,  1794,  1524,  1515,  1516,
    1518,  1520,   268,  1522,  1526,   767,   768,   769,  1527,  1533,
    1539,  1544,  1546,  1545,  1551,   431,  1558,   431,  1562,  1563,
     545,   547,   442,  1564,  1565,  1566,  1813,  1567,  1591,  1569,
    1598,   793,   557,   558,   559,   980,   561,  1609,  1614,   564,
     565,  1615,  1622,   566,  1625,  1628,   981,   431,  1629,  1631,
    1633,  1645,  1646,  1649,   982,   983,   984,  1765,   578,   579,
     985,   986,   987,   988,  1658,  1669,  1674,  1676,   821,  1679,
    1680,  1683,   587,   588,  1684,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,  1687,  1693,  1688,
    1715,  1728,  1709,  1711,  1737,  1740,   621,  1713,  1729,   624,
    1743,   626,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,  1176,  1746,  1748,  1756,
     420,  1757,   647,  1777,  1762,   442,  1780,  1767,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,  1782,  1764,   667,   668,  1766,  1784,  1775,
     913,  1786,   915,  1792,  1807,  1808,   980,  1809,  1810,  1811,
    1812,  1814,  1560,   545,  1263,  1661,   683,   981,  1276,   692,
    1561,    92,   101,  1238,   697,   982,   983,   984,   713,   702,
     703,   985,   986,   987,   988,   708,   709,  1577,     0,  1371,
     714,   716,   719,   722,   725,   727,   728,   729,   442,   442,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
       0,  1244,     0,     0,     0,     0,   746,   747,   748,   386,
     387,   749,     0,     0,     0,   753,   754,   755,   756,   757,
       0,     0,     0,   762,     0,   764,   765,     0,     0,     0,
     442,   442,   442,     0,     0,   772,   773,   774,   587,   775,
       0,     7,     8,     0,  1012,   781,     0,     0,  1798,     0,
       0,     0,     0,  1019,     0,  1020,   442,  1021,     0,  1022,
       0,     0,   796,   798,  1025,   667,   668,  1026,   550,     0,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,   775,     0,     0,   420,     0,
       0,     0,   820,   442,     0,     0,     0,     0,   825,     0,
       0,   642,    24,    25,   643,    27,    28,   644,    30,   645,
      32,  1338,    33,     0,     0,     0,     0,    38,    39,  1057,
      41,    42,    43,     0,     0,     0,    46,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,   880,     0,
       0,     0,     0,     0,  1081,  1082,  1083,  1084,     0,     0,
      67,    68,    69,     0,     0,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,   908,   420,     0,   442,     0,   442,   916,     0,
       0,     0,     0,     0,     0,     0,   923,     0,     0,   798,
     926,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1123,     0,     0,   940,     0,     0,     0,     0,     0,     0,
       0,     0,   946,     0,     0,     0,   813,     0,     0,     0,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   687,   418,   419,   442,     0,     0,     0,   420,     0,
     443,   971,   972,     0,     0,   443,     0,   975,     0,   443,
       0,     0,     7,     8,     0,     0,   443,     0,     0,     0,
     999,     0,     0,  1001,     0,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   442,
       0,     0,     0,   420,     0,     0,     0,     0,   442,     0,
     442,     0,   442,     0,   442,     0,     0,     0,     0,   442,
       0,     0,   442,     0,     0,     0,     0,     0,  1031,     0,
    1033,  1034,   642,    24,    25,   643,    27,    28,   644,    30,
     645,    32,     0,    33,     0,   546,     0,   443,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,     0,  1053,     0,     0,     7,     8,     0,     0,     0,
    1054,  1055,  1056,     0,   442,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,  1065,
     420,    67,    68,    69,     0,   456,  1067,     0,     0,  1072,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   442,
     442,   442,   442,     0,     0,     0,  1087,     0,  1358,   480,
       0,     0,     0,     0,     0,   642,    24,    25,   643,    27,
      28,   644,    30,   645,    32,     0,    33,     0,     0,     0,
       0,    38,    39,   510,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,  1336,     0,     0,   968,   110,     0,
     443,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1131,     0,  1133,     0,  1135,
       0,  1137,     0,     0,    67,    68,    69,     0,     0,  1359,
       0,     0,   136,   137,   138,   139,   140,   141,   546,     0,
       0,   145,     0,     0,   576,   577,   147,   148,   149,     0,
       0,   150,     0,     0,     0,     0,     0,   584,     0,     0,
       0,     0,   155,     0,     0,     0,     0,     0,     0,  1182,
       0,     0,  1185,   443,   443,     0,  1188,  1481,  1189,  1190,
    1191,     0,     0,     0,     0,     0,  1196,     0,     0,     0,
     969,   618,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1211,     0,  1213,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   443,   443,   443,     0,  1419,
    1420,     0,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,  1246,
     420,   443,     0,     0,     0,   158,   159,     0,   799,     0,
       0,  1255,  1256,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,  1265,  1267,     0,   642,    24,    25,   643,
      27,    28,   644,    30,   645,    32,     0,    33,   443,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,     0,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,  1307,  1308,
    1309,   420,     0,     0,     0,     0,     0,     0,  1319,     0,
    1321,     0,     0,     0,     0,    67,    68,    69,     0,     0,
       0,  1326,     0,     0,     0,     0,     0,     0,     0,   442,
       0,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,   312,   110,     0,     0,  1350,  1351,  1352,     0,     0,
     443,     0,   443,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1542,   799,   927,     0,     0,     0,  1511,
       0,   992,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,  1368,     0,     0,   145,     0,     0,     0,     0,
     147,   148,   149,     0,     0,   150,  1381,     0,     0,     0,
       0,  1387,     0,     0,     0,  1543,   155,  1578,     0,   443,
       0,     0,   980,     0,  1393,  1394,     0,     0,     0,     0,
       0,  1399,  1400,   981,     0,  1657,  1402,     0,  1599,     0,
       0,   982,   983,   984,  1409,     0,     0,   985,   986,   987,
     988,     0,     0,     0,   442,   442,  1421,     0,  1422,     0,
     893,     0,     0,     0,   443,     0,     0,     0,     0,     0,
    1439,     0,     0,   443,     0,   443,     0,   443,     0,   443,
       0,  1716,   442,     0,   443,     0,   442,   443,     0,  1454,
       0,     0,     0,     0,  1456,  1457,  1458,  1459,     0,   158,
     159,     0,     0,     0,     0,     0,     0,  1467,     0,     0,
       0,   166,     0,     0,     0,     0,     0,  1477,     0,     0,
       0,   947,     0,     0,  1799,     0,     0,     0,     0,  1700,
       0,     0,     0,     0,  1488,  1489,     0,     0,     0,   443,
       0,     0,  1495,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,  1692,     0,  1695,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   443,   443,   443,   443,  1514,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,  1528,   420,   545,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,  1540,     0,  1541,     0,   420,   442,     0,
       0,     0,     0,     0,     0,  1548,  1039,     0,  1747,     0,
     443,     0,  1047,     0,     0,     0,     0,     0,     0,  1553,
       0,     0,     0,     0,  1557,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
     809,     0,   442,   420,     0,     0,     0,     0,  1059,  1582,
       0,  1585,     0,  1588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   442,     0,     0,     0,  1601,  1602,  1603,
    1604,  1605,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,  1616,  1617,   980,     0,
     420,  1619,     0,     0,     0,     0,     0,   894,     0,   981,
       0,  1623,     0,     0,     0,     0,     0,   982,   983,   984,
       0,     0,  1634,   985,   986,   987,   988,     0,     0,  1108,
    1109,     0,  1111,     0,  1114,  1115,   314,   110,  1118,  1119,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,  1659,     0,     0,     0,   420,  1387,     0,     0,
       0,     0,     0,     0,  1667,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,     0,  1678,  1024,
     145,  1682,     0,     0,  1686,   147,   148,   149,  1689,     0,
     150,     0,   442,     0,   442,  1696,  1697,  1698,  1699,     0,
    1800,   155,     0,     0,     0,  1703,     0,     0,  1705,     0,
       0,     0,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,  1204,  1199,  1200,  1201,
     420,     0,     0,     0,     0,     0,     0,     0,  1209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1733,     0,
       0,     0,     0,     0,   443,     0,     0,     0,     0,     0,
       0,     0,     0,   442,     0,  1749,  1750,  1751,  1752,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,   158,   159,     0,   420,     0,     0,
       0,  1258,     0,     0,     0,     0,   166,     0,     0,     0,
       0,  1778,  1779,     0,     0,     0,     0,     0,     0,     0,
    1277,  1787,  1788,  1789,  1790,     0,  1283,     0,     0,     0,
       0,     0,  1288,     0,  1290,  1291,     0,     0,     0,  1294,
    1295,     0,  1296,     0,  1297,     0,  1298,     0,  1299,  1300,
    1301,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,  1320,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1331,     0,     0,     0,  1335,     0,     0,     0,   443,
     443,   428,   110,     0,     0,     0,     0,     0,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,   443,     0,     0,
       0,   443,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   145,     0,     0,     0,     0,
     147,   148,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,  1379,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,     0,     0,  1391,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     7,
       8,   147,   148,   149,     0,     0,   150,     0,   151,   152,
     153,     0,     0,   546,     0,     0,   154,   155,     0,   158,
     159,     0,  1258,     0,     0,     0,     0,     0,     0,     0,
       0,   166,     0,   443,     0,     0,     0,     0,     0,  1460,
     443,     0,     0,     0,     0,     0,  1469,     0,     0,     0,
    1470,     0,     0,     0,  1474,     0,     0,     0,     0,   642,
      24,    25,   643,    27,    28,   644,    30,   645,    32,     0,
      33,     0,     0,     0,  1490,    38,    39,   443,    41,    42,
      43,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,  1258,     0,     0,   443,   157,
     158,   159,   160,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,  1525,   169,     0,     0,     0,     0,   170,     0,   171,
       0,   172,   173,     0,   174,     0,   175,     0,   108,   320,
       0,     0,     0,     0,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,  1258,     0,     0,  1032,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,  1258,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,     0,     0,
       0,     0,     0,   154,   108,   280,  1594,   443,     0,   443,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   282,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,  1627,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
       0,     0,  1644,   283,     0,     0,   284,     0,   443,   285,
       0,   286,     0,     0,     0,     0,   157,     0,     0,   160,
    1126,     0,     0,   287,   161,   162,   163,   164,   165,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   497,   498,     0,     0,     0,   169,
       0,     0,     0,     0,   499,     0,     0,     0,     0,   173,
       0,   247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1258,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
     167,   441,     0,   420,     0,   169,     0,     0,     0,     0,
     289,     0,     0,     0,     0,   173,     0,     0,   548,     0,
       0,   108,   280,   110,     0,     0,     0,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   282,     0,  1258,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   147,   148,   149,     7,     8,   150,     0,   151,   152,
     153,     0,     0,     0,     0,     0,   154,   155,     0,     0,
     283,     0,     0,   284,     0,     0,   285,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,   642,    24,    25,   643,    27,    28,
     644,    30,   645,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,   160,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,   167,   288,     0,
       0,     0,   169,     0,     0,     0,     0,   289,     0,   108,
     280,   110,   173,     0,   290,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   282,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   147,
     148,   149,     0,     0,   150,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,   155,     0,     0,   283,     0,
       0,   284,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,     0,     0,
       0,     0,     0,  1426,     0,  1427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
     160,     0,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   167,   288,     0,     0,   420,
     169,   794,     0,     0,     0,   289,   739,   108,   320,   110,
     173,     0,  1473,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,   147,   148,   149,
       0,     0,   150,     0,   151,   152,   153,     0,   108,   320,
     110,     0,   154,   155,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   147,   148,
     149,     0,     0,   150,     0,   151,   152,   153,     0,     0,
       0,     0,     0,   154,   155,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,   157,   158,   159,   160,     0,
    1461,     0,  1462,   161,   162,   163,   164,   165,   166,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   167,   168,     0,     0,   420,   169,     0,
       0,     0,     0,   289,  1580,     0,  1581,     0,   173,     0,
    1266,     0,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   157,   158,   159,   160,
     420,     0,   633,     0,   161,   162,   163,   164,   165,   166,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   167,   168,     0,     0,   420,   169,
       0,     0,     0,     0,   289,   676,   108,   320,   110,   173,
       0,  1466,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     7,     8,   147,   148,   149,     0,
       0,   150,     0,   151,   152,   153,     0,     0,     0,     0,
       0,   154,   155,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
     891,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   642,    24,    25,   643,    27,    28,
     644,    30,   645,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   157,   158,   159,   160,   420,     0,
     686,     0,   161,   162,   163,   164,   165,   166,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,     0,   167,   168,     0,     0,     0,   169,     0,     0,
       0,     0,   289,     0,   108,   280,   281,   173,     0,  1476,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   282,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,  1037,
     146,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
       0,     0,     0,   283,     0,     0,   284,     0,     0,   285,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   642,    24,    25,   643,    27,    28,
     644,    30,   645,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
     167,   288,     0,     0,     0,   169,     0,     0,     0,     0,
     289,     0,   108,   280,  1329,   173,     0,   290,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,  1145,
       0,     0,     7,     8,     0,     0,     0,     0,     0,   151,
     152,   153,     0,     0,     0,     0,     0,   154,     0,     0,
       0,   283,     0,     0,   284,     0,     0,   285,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,   642,    24,    25,   643,    27,    28,   644,    30,
     645,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,   167,   288,
       0,     0,     0,   169,     0,     0,     0,     0,   289,     0,
     108,   280,     0,   173,     0,  1330,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,  1647,     0,     0,
       7,     8,     0,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
     642,    24,    25,   643,    27,    28,   644,    30,   645,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
       0,   160,     0,     0,     0,     0,   161,   162,   163,   164,
     165,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,   167,   288,     0,     0,
       0,   169,     0,     0,     0,     0,   289,     0,   108,   280,
       0,   173,     0,   290,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   282,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,  1718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,     0,     0,
       0,     0,     0,   154,     0,     0,     0,   283,     0,     0,
     284,     0,     0,   285,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,   942,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,     0,     0,   160,
       0,     0,     0,     0,   161,   162,   163,   164,   165,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,   167,   441,     0,   420,     0,   169,
       0,     0,     0,     0,   289,   575,   108,   280,     0,   173,
       0,   544,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   282,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,     0,     0,     0,     0,
       0,   154,     0,     0,     0,   283,     0,     0,   284,     0,
       0,   285,     0,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,   995,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,     0,   160,     0,     0,
       0,     0,   161,   162,   163,   164,   165,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,   167,   441,     0,   420,     0,   169,     0,     0,
       0,     0,   289,   732,   108,   280,     0,   173,     0,   797,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   282,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
       0,     0,     0,   283,     0,     0,   284,     0,     0,   285,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
    1015,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
     167,   288,     0,   420,     0,   169,     0,     0,     0,     0,
     289,  1510,   108,   280,     0,   173,     0,  1334,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,     0,     0,     0,     0,     0,   154,     0,     0,
       0,   283,     0,     0,   284,     0,     0,   285,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1045,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   497,  1446,
       0,     0,   420,   169,     0,     0,     0,     0,   499,   739,
     108,   320,   110,   173,     0,   247,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     147,   148,   149,     0,     0,   150,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,   155,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,  1149,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,  1424,     0,     0,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,   157,   158,
     159,   160,  1443,     0,     0,     0,   161,   162,   163,   164,
     165,   166,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   167,   168,     0,     0,
     420,   169,   108,   280,     0,     0,   289,   740,   111,   112,
     113,   173,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,     0,     0,     0,     0,     0,   154,     0,     0,
       0,   283,     0,     0,   284,     0,     0,   285,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   167,   441,
       0,     0,   420,   169,   108,   320,     0,     0,   289,   806,
     111,   112,   113,   173,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,  1499,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,     0,     0,
       0,     0,     0,     0,     0,  1500,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
     167,   168,     0,     0,     0,   169,     0,    -4,    -4,    -4,
     289,     0,     0,    -4,    -4,   173,    -4,     0,     0,     0,
      -4,    -4,     0,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     6,     0,     0,
       0,     0,    -4,     0,     0,     7,     8,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       9,    10,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,    11,    12,    13,     0,     0,     0,    14,
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
      85,    86,     0,     0,     0,     0,     0,     0,    87,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,     0,     0,  1501,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,  1502,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,  1534,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
    1596,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1606,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,     0,     0,  1607,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,  1635,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,  1638,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
    1641,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1668,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,     0,     0,  1675,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,  1710,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,  1712,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
    1714,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1732,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,     0,     0,  1758,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,  1796,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,  1797,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
    1801,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1802,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,     0,     0,  1803,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,  1804,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
     840,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,   848,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,   849,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,   850,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,   861,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
     977,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,   978,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,   979,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1010,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1101,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1147,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1148,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,  1203,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1342,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1343,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1344,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1345,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,  1382,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1383,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1390,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1535,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1536,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,  1537,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1538,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1554,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1555,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1559,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,  1653,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1654,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1655,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1656,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1663,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,  1666,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1706,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1723,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1724,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1725,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,  1726,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,  1769,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,  1770,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
    1771,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,  1772,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,   401,     0,   402,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420,     0,
       0,     0,   634,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,   811,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
       0,     0,     0,     0,   420,     0,     0,     0,   819,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,   827,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     420,     0,     0,     0,   907,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,     0,     0,  1003,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,     0,     0,
    1004,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,     0,     0,  1008,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,     0,     0,
       0,     0,   420,     0,     0,     0,  1009,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,     0,     0,  1011,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420,     0,
       0,     0,  1048,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,     0,     0,  1096,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
       0,     0,     0,     0,   420,     0,     0,     0,  1339,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,     0,
       0,  1373,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     420,     0,     0,     0,  1523,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,   690,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
       0,     0,     0,     0,   420,     0,   691,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,   693,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,   695,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,   696,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420,     0,
     699,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,   700,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     420,     0,   794,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,   802,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,     0,     0,
       0,     0,   420,     0,   803,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,   804,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
       0,     0,     0,     0,   420,     0,   810,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,   818,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,   826,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,   906,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420,     0,
     931,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,   936,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     420,     0,   941,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,   944,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,     0,     0,
       0,     0,   420,     0,   945,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,   951,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
       0,     0,     0,     0,   420,     0,   960,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,   961,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,   962,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,   994,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420,     0,
     996,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,   420,
       0,   997,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,     0,     0,     0,     0,
     420,     0,   998,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,     0,  1002,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,     0,     0,
       0,     0,   420,     0,  1236,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,   420,     0,  1425,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
       0,     0,     0,     0,   420,     0,  1442,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   420,     0,  1465,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,   420,     0,  1662,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,     0,     0,     0,     0,   420,     0,  1730,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,     0,     0,     0,     0,   420
};

static const yytype_int16 yycheck[] =
{
       3,     3,   240,   255,   365,  1332,   367,   491,   492,     4,
       4,     4,   391,     4,   375,   267,     6,     5,   190,     4,
       6,     5,     4,   195,     5,   404,     4,     6,     4,     6,
       4,     6,    21,    22,     5,   179,   180,     4,    78,     5,
     107,     4,     4,     4,    13,     3,     5,     4,     6,     5,
       5,     5,   196,     5,    57,     6,     6,     6,     0,     6,
     136,     6,    65,     7,   189,   317,     6,   319,     6,   179,
     180,   179,   180,   149,   150,   189,   179,   180,  1405,     6,
     189,   989,   196,     6,   189,   195,   191,   197,   196,    79,
      80,   993,   195,   198,   197,     6,   179,   180,     6,    57,
     179,   180,   189,    49,    50,     7,    52,   179,   180,   196,
       4,   189,     6,   191,   197,     7,   195,   106,   197,     7,
     198,   189,   191,   191,   196,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     126,   127,   128,   129,     7,   139,   145,   148,   139,   148,
     145,     6,   136,   137,  1491,   154,   155,   189,   139,     7,
     173,   160,   174,   139,   196,   136,   137,   124,    72,   124,
    1507,   189,   185,   186,   124,   191,   124,   193,   196,     6,
     193,   177,   198,     6,   189,   189,   189,   191,   201,   193,
     203,   196,   177,   582,   198,   208,   185,   186,   196,   212,
     200,   196,   215,   191,   196,   173,   219,   220,   221,   222,
     198,   197,   225,   226,   227,   196,   189,   185,   186,   196,
     482,   483,     6,   196,   196,   193,   239,   196,   189,   196,
     196,   196,   196,   201,   196,   196,   196,   196,    75,   193,
     502,    78,   179,   180,   633,   634,   179,   180,   261,   262,
     263,   189,  1170,   191,   166,   167,   168,   169,   179,   180,
     198,     7,   275,   276,   166,   167,   168,   169,   166,   167,
     168,   169,   189,   185,   186,   288,     6,   290,   179,   180,
      78,   280,    80,   185,   186,   179,   180,   243,   244,   185,
     186,   193,   179,   180,   195,   251,     4,     5,   297,   255,
     562,   195,   189,   166,   167,   168,   169,   185,   186,   196,
     329,   324,   325,   575,   391,   193,   185,   186,   166,   167,
     168,   169,   185,   186,   337,   179,   180,   196,  1665,     8,
     330,    39,    40,    41,    42,    43,    44,   185,   186,    75,
      48,   195,    78,   189,    80,    53,    54,    55,   179,   180,
      58,     4,   365,   366,   367,   368,   369,   370,   371,   372,
     373,    69,   375,   376,   195,   185,   186,   380,   381,   382,
     383,   384,   179,   180,     6,     7,   196,   366,   378,   368,
     369,   370,     4,   372,   373,   385,   192,   376,   195,   195,
     403,   380,   381,   382,   383,   191,   395,   365,   366,   367,
     368,   369,   370,    78,   372,   373,    95,   375,   376,   195,
     189,   197,   380,   381,   382,   383,   384,   106,   189,  1756,
     166,   167,   168,   169,   189,   114,   115,   116,   441,   818,
     819,   120,   121,   122,   123,    72,   179,   180,    75,   185,
     186,    78,     6,     7,   152,   153,    99,   100,   101,   102,
      72,   190,   195,   192,    76,   108,   164,   196,   111,   179,
     180,   189,    75,   476,   477,    78,    88,   179,   180,   469,
     470,   471,   472,   735,   195,   195,   197,   185,   186,   491,
     492,    99,   100,   195,     8,   193,   192,   105,   195,   195,
     197,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   518,   519,   520,   197,   188,
     529,   189,   589,   179,   180,   185,   186,   530,   197,   179,
     180,   179,   180,   179,   180,    75,   196,   190,    78,   195,
      80,   544,   195,   489,   490,   195,   555,   195,   551,   195,
      82,   497,   179,   180,   179,   180,   179,   180,   179,   180,
     179,   180,   189,    78,   179,   180,   633,   634,     8,   196,
     195,     6,   530,   952,   195,   954,   195,   956,   581,   958,
     195,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   196,   602,   603,   604,   605,   606,   607,   608,
      78,   179,   180,   612,   613,   614,   179,   180,    95,   179,
     180,   195,    78,   197,   623,    80,  1518,   195,  1520,   106,
    1522,   630,   195,   179,   180,   195,   189,   114,   115,   116,
     195,   640,   197,   120,   121,   122,   123,   179,   180,   195,
     179,   180,   181,   182,   183,   635,   884,   650,    72,   188,
     195,    75,   197,   195,    78,    75,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     673,   190,   675,   192,   188,   678,  1584,   196,   681,  1587,
     683,    78,  1590,   197,   687,   688,   179,   180,    75,   189,
    1069,   191,   190,   193,   192,   685,   196,    72,   198,   678,
      75,   196,   195,    78,   683,    80,  1085,   196,   711,   776,
     197,    75,   220,   221,   222,    99,   100,   225,   226,   227,
     678,   105,   190,   681,   192,   683,    78,     4,   196,   732,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   190,    95,  1648,     4,   188,   195,
     190,   818,   819,   261,   262,    72,   106,   190,    75,   826,
     827,    78,   195,    80,   114,   115,   116,   275,   276,     4,
     120,   121,   122,   123,   777,   189,   195,   191,   197,   193,
       4,   190,  1690,   786,   198,   788,   195,   790,   190,   792,
     192,     6,   738,   195,   797,    95,   189,   800,   190,   745,
     192,   181,   182,   183,   196,   751,   106,  1709,   188,  1711,
     195,  1713,   197,   816,   114,   115,   116,  1719,   189,   822,
     120,   121,   122,   123,   827,     6,  1310,  1311,  1736,     6,
     190,  1739,   192,   189,  1742,   195,  1215,  1745,  1076,   906,
     907,   195,   195,   197,   197,   190,     6,   197,   827,   852,
     195,   189,   191,   190,   857,   858,   859,   860,   195,   189,
    1762,   190,  1764,   192,  1766,   190,   195,   870,   189,   827,
     195,   861,     7,  1781,   190,  1783,   192,  1785,   857,   195,
     859,   860,   189,   892,   887,   888,   889,   890,   190,     4,
     192,   870,   195,   195,   197,   189,   195,   197,   197,   857,
     189,   859,   860,   195,   195,   197,   197,   189,    78,   912,
      80,    78,   870,    80,   923,   924,   195,   195,   197,   197,
      12,    13,   195,   195,   197,   197,   929,   930,   195,   932,
     197,   934,   935,   912,   189,   938,   939,   195,   189,   197,
     943,   195,   189,   197,  1011,   195,   195,   197,   197,   195,
     195,   197,   197,   189,   912,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   195,
     195,   197,   197,   188,   195,   195,   197,   197,   189,   925,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       4,    83,     6,   195,   189,   197,    88,    89,   196,    91,
      92,    93,  1069,   196,   195,    97,   197,     6,     6,  1247,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,  1027,  1028,  1029,   189,   188,  1513,
     189,   977,   978,   979,   195,  1038,   197,  1046,   189,   131,
     132,   133,   196,   196,  1053,  1054,  1055,  1056,  1057,   195,
     189,   197,     3,     4,  1063,  1064,   189,   189,     9,    10,
      11,   189,   189,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   195,   189,   197,  1091,   195,
     195,   197,   197,   189,    45,    46,    47,   195,    49,   197,
     195,   195,   197,   197,   195,   197,   197,  1110,     4,    60,
      61,    62,  1102,  1116,   195,  1476,   197,    68,   195,  1122,
     197,  1124,  1125,     8,   189,   189,  1129,  1130,   195,  1132,
     197,  1134,   195,  1136,   197,  1138,  1139,  1140,    95,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   195,   106,
     197,  1218,   188,  1156,   196,   189,    95,   114,   115,   116,
     195,   189,   197,   120,   121,   122,   123,   106,  1171,     7,
       8,   195,  1175,   197,  1177,   114,   115,   116,  1187,   196,
     196,   120,   121,   122,   123,   195,   195,   197,   197,  1198,
     195,   195,   197,   197,   195,   195,   197,   197,   189,   196,
     151,   196,   189,   154,   189,   191,   198,     6,   159,   160,
     161,   162,   163,     6,   196,   196,   196,   191,   191,   191,
     191,     6,  1225,  1169,     6,   193,   196,   139,   179,   180,
       6,     6,     6,   184,     6,   196,     6,   191,   189,  1229,
     197,     4,   188,   194,  1482,   196,  1225,     7,   193,  1239,
    1253,   198,   196,   195,   197,   195,     7,     6,   197,     6,
    1263,     6,   190,  1266,   196,     7,     7,  1225,     6,    50,
       7,     6,     6,  1340,     7,  1527,  1266,     6,     6,     4,
       6,    50,    50,    50,  1263,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,  1302,
    1303,   136,   196,   188,   190,  1263,     6,     6,  1310,  1311,
       6,   190,   190,   195,   195,   195,  1306,   190,   195,   195,
     190,   190,     6,     4,     4,     7,   139,  1330,  1274,  1332,
       6,  1334,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,  1349,    12,    13,     6,
     188,     6,    95,  1356,  1363,     6,   139,  1360,     7,     7,
       7,  1364,     7,   106,     7,  1355,  1312,     7,  1314,     7,
    1316,   114,   115,   116,  1364,  1365,  1366,   120,   121,   122,
     123,  1384,   139,     4,  1330,   196,     6,  1333,  1334,   190,
     195,   195,   190,   190,   190,   195,     6,  1649,     7,   193,
     195,     7,  1405,   192,     7,   197,   197,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   196,    83,   196,
     193,     6,     6,    88,    89,   196,    91,    92,    93,     6,
     196,   196,    97,     6,   196,     7,   191,     6,  1441,     6,
       6,   189,     7,  1446,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   189,   177,
       7,     7,   188,  1466,    80,     7,   131,   132,   133,     7,
    1473,     7,     7,  1476,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,  1491,     6,
     203,     7,   188,     7,    95,   208,     7,     7,     7,   212,
       6,     4,     7,     4,  1507,   106,   219,  1510,     6,   196,
       6,  1513,   189,   114,   115,   116,     7,     6,  1476,   120,
     121,   122,   123,  1526,     7,     7,     7,   196,  1531,     6,
       6,     6,   197,    78,     6,     6,     3,     4,     6,     4,
       6,     4,     9,    10,    11,     4,     6,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    1573,  1517,   197,  1519,     6,  1521,     6,     4,    45,    46,
      47,     6,    49,  1529,   195,   190,  1532,   195,   190,  1592,
     190,   190,     7,    60,    61,    62,   197,   193,   189,   196,
     193,    68,     6,     6,     6,    72,     6,   196,    75,   196,
      88,    78,     6,    80,   196,   196,     6,     6,    86,    87,
     196,     6,  1612,     6,     5,    92,  1572,     4,     6,   191,
    1576,    95,    99,   100,   101,   102,   103,   196,   196,     7,
     196,   108,   106,   196,   111,     6,     6,  1650,     6,  1652,
     114,   115,   116,     6,     4,   196,   120,   121,   122,   123,
       6,     6,  1665,   196,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   196,  1625,
     135,     6,   188,  1629,   151,     6,     4,   154,   195,     6,
     403,     4,   159,   160,   161,   162,   163,     6,     6,   167,
     168,   169,   170,   171,     6,     6,  1652,     6,     4,     6,
    1700,     6,   179,   180,     6,     6,   184,   184,  1721,     5,
     188,     6,   189,   196,     6,   139,  1729,   194,     6,   196,
     197,     6,     6,   197,   202,   203,   204,   205,     6,   207,
     208,   209,   210,     6,   212,   213,   214,     6,     6,     6,
    1729,   219,     6,  1756,     6,    95,     6,   195,     6,     6,
       6,  1707,  1708,   476,   477,     6,   106,   190,     6,   237,
    1773,  1729,  1775,     7,   114,   115,   116,     6,   246,   247,
     120,   121,   122,   123,   193,     6,   196,   255,     6,     5,
     196,     6,    76,     6,  1773,   196,  1775,     6,   197,   197,
     196,   196,  1805,   196,     7,   518,   519,   520,   196,     6,
     134,     6,     6,   197,   137,  1773,     6,  1775,     6,     6,
     288,   289,   290,     6,     6,     6,  1805,     6,     6,   196,
       6,   544,   300,   301,   302,    95,   304,     6,     6,   307,
     308,   196,   196,   311,   196,     6,   106,  1805,   196,     6,
     197,     6,    95,   196,   114,   115,   116,   197,   326,   327,
     120,   121,   122,   123,     6,     6,     6,     6,   581,     6,
       6,     6,   340,   341,     6,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     6,     6,   197,
       6,     6,   196,   196,     6,     6,   374,   196,   196,   377,
       6,   379,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,     6,     6,     6,   196,
     188,     6,   400,     6,   196,   403,     6,   197,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,     6,   196,   423,   424,   196,     6,   196,
     673,     6,   675,     6,     6,     6,    95,     6,     6,     6,
       6,     6,  1496,   441,  1099,  1615,   437,   106,  1109,   447,
    1497,     3,     3,     6,   452,   114,   115,   116,   467,   457,
     458,   120,   121,   122,   123,   463,   464,  1509,    -1,  1243,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   732,
      -1,     6,    -1,    -1,    -1,    -1,   494,   495,   496,   497,
     498,   499,    -1,    -1,    -1,   503,   504,   505,   506,   507,
      -1,    -1,    -1,   511,    -1,   513,   514,    -1,    -1,    -1,
     518,   519,   520,    -1,    -1,   523,   524,   525,   526,   527,
      -1,    12,    13,    -1,   777,   533,    -1,    -1,   197,    -1,
      -1,    -1,    -1,   786,    -1,   788,   544,   790,    -1,   792,
      -1,    -1,   550,   551,   797,   553,   554,   800,     8,    -1,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,   573,    -1,    -1,   188,    -1,
      -1,    -1,   580,   581,    -1,    -1,    -1,    -1,   586,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     6,    83,    -1,    -1,    -1,    -1,    88,    89,   852,
      91,    92,    93,    -1,    -1,    -1,    97,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,   636,    -1,
      -1,    -1,    -1,    -1,   887,   888,   889,   890,    -1,    -1,
     131,   132,   133,    -1,    -1,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,   670,   188,    -1,   673,    -1,   675,   676,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,   687,
     688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     943,    -1,    -1,   701,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   710,    -1,    -1,    -1,   197,    -1,    -1,    -1,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   732,    -1,    -1,    -1,   188,    -1,
     203,   739,   740,    -1,    -1,   208,    -1,   745,    -1,   212,
      -1,    -1,    12,    13,    -1,    -1,   219,    -1,    -1,    -1,
     758,    -1,    -1,   761,    -1,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   777,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,   786,    -1,
     788,    -1,   790,    -1,   792,    -1,    -1,    -1,    -1,   797,
      -1,    -1,   800,    -1,    -1,    -1,    -1,    -1,   806,    -1,
     808,   809,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,   288,    -1,   290,    88,    89,
      -1,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,   840,    -1,    -1,    12,    13,    -1,    -1,    -1,
     848,   849,   850,    -1,   852,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,   867,
     188,   131,   132,   133,    -1,   215,   874,    -1,    -1,   877,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   887,
     888,   889,   890,    -1,    -1,    -1,   894,    -1,     6,   239,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,   263,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,  1177,    -1,    -1,   197,     5,    -1,
     403,    -1,    -1,    -1,    -1,   943,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   953,    -1,   955,    -1,   957,
      -1,   959,    -1,    -1,   131,   132,   133,    -1,    -1,     6,
      -1,    -1,    39,    40,    41,    42,    43,    44,   441,    -1,
      -1,    48,    -1,    -1,   324,   325,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,  1007,
      -1,    -1,  1010,   476,   477,    -1,  1014,     6,  1016,  1017,
    1018,    -1,    -1,    -1,    -1,    -1,  1024,    -1,    -1,    -1,
     197,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1041,    -1,  1043,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   518,   519,   520,    -1,  1302,
    1303,    -1,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,  1077,
     188,   544,    -1,    -1,    -1,   152,   153,    -1,   551,    -1,
      -1,  1089,  1090,    -1,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    -1,  1101,  1102,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,   581,    -1,
      -1,    -1,    88,    89,    -1,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,  1146,  1147,
    1148,   188,    -1,    -1,    -1,    -1,    -1,    -1,  1156,    -1,
    1158,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,  1169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1177,
      -1,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,     4,     5,    -1,    -1,  1203,  1204,  1205,    -1,    -1,
     673,    -1,   675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1466,   687,   688,    -1,    -1,    -1,     6,
      -1,   197,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,  1240,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      53,    54,    55,    -1,    -1,    58,  1254,    -1,    -1,    -1,
      -1,  1259,    -1,    -1,    -1,     6,    69,  1510,    -1,   732,
      -1,    -1,    95,    -1,  1272,  1273,    -1,    -1,    -1,    -1,
      -1,  1279,  1280,   106,    -1,     6,  1284,    -1,  1531,    -1,
      -1,   114,   115,   116,  1292,    -1,    -1,   120,   121,   122,
     123,    -1,    -1,    -1,  1302,  1303,  1304,    -1,  1306,    -1,
     650,    -1,    -1,    -1,   777,    -1,    -1,    -1,    -1,    -1,
    1318,    -1,    -1,   786,    -1,   788,    -1,   790,    -1,   792,
      -1,     6,  1330,    -1,   797,    -1,  1334,   800,    -1,  1337,
      -1,    -1,    -1,    -1,  1342,  1343,  1344,  1345,    -1,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,    -1,  1365,    -1,    -1,
      -1,   711,    -1,    -1,   197,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,  1382,  1383,    -1,    -1,    -1,   852,
      -1,    -1,  1390,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,  1650,    -1,  1652,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   887,   888,   889,   890,  1426,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,  1444,   188,  1446,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,  1461,    -1,  1463,    -1,   188,  1466,    -1,
      -1,    -1,    -1,    -1,    -1,  1473,   816,    -1,  1721,    -1,
     943,    -1,   822,    -1,    -1,    -1,    -1,    -1,    -1,  1487,
      -1,    -1,    -1,    -1,  1492,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
       8,    -1,  1510,   188,    -1,    -1,    -1,    -1,   858,  1517,
      -1,  1519,    -1,  1521,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1531,    -1,    -1,    -1,  1535,  1536,  1537,
    1538,  1539,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,  1554,  1555,    95,    -1,
     188,  1559,    -1,    -1,    -1,    -1,    -1,     8,    -1,   106,
      -1,  1569,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
      -1,    -1,  1580,   120,   121,   122,   123,    -1,    -1,   929,
     930,    -1,   932,    -1,   934,   935,     4,     5,   938,   939,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,  1610,    -1,    -1,    -1,   188,  1615,    -1,    -1,
      -1,    -1,    -1,    -1,  1622,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,  1636,     8,
      48,  1639,    -1,    -1,  1642,    53,    54,    55,  1646,    -1,
      58,    -1,  1650,    -1,  1652,  1653,  1654,  1655,  1656,    -1,
     197,    69,    -1,    -1,    -1,  1663,    -1,    -1,  1666,    -1,
      -1,    -1,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,     8,  1027,  1028,  1029,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1038,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1706,    -1,
      -1,    -1,    -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1721,    -1,  1723,  1724,  1725,  1726,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,   152,   153,    -1,   188,    -1,    -1,
      -1,  1091,    -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,
      -1,  1759,  1760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1110,  1769,  1770,  1771,  1772,    -1,  1116,    -1,    -1,    -1,
      -1,    -1,  1122,    -1,  1124,  1125,    -1,    -1,    -1,  1129,
    1130,    -1,  1132,    -1,  1134,    -1,  1136,    -1,  1138,  1139,
    1140,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,  1156,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1171,    -1,    -1,    -1,  1175,    -1,    -1,    -1,  1302,
    1303,     4,     5,    -1,    -1,    -1,    -1,    -1,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,  1330,    -1,    -1,
      -1,  1334,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,  1253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,  1266,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    12,
      13,    53,    54,    55,    -1,    -1,    58,    -1,    60,    61,
      62,    -1,    -1,  1446,    -1,    -1,    68,    69,    -1,   152,
     153,    -1,  1332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,  1466,    -1,    -1,    -1,    -1,    -1,  1349,
    1473,    -1,    -1,    -1,    -1,    -1,  1356,    -1,    -1,    -1,
    1360,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,  1384,    88,    89,  1510,    91,    92,
      93,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,  1405,    -1,    -1,  1531,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,
      -1,  1441,   184,    -1,    -1,    -1,    -1,   189,    -1,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,  1491,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,  1507,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,     3,     4,  1526,  1650,    -1,  1652,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,  1573,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,  1592,    72,    -1,    -1,    75,    -1,  1721,    78,
      -1,    80,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,
      95,    -1,    -1,    92,   159,   160,   161,   162,   163,    -1,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,
      -1,    -1,   111,    -1,   179,   180,    -1,    -1,    -1,   184,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
     179,   180,    -1,   188,    -1,   184,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,   194,    -1,    -1,   197,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,  1756,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    55,    12,    13,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,
      72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,   179,   180,    -1,
      -1,    -1,   184,    -1,    -1,    -1,    -1,   189,    -1,     3,
       4,     5,   194,    -1,   196,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   179,   180,    -1,    -1,   188,
     184,   190,    -1,    -1,    -1,   189,   195,     3,     4,     5,
     194,    -1,   196,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    54,    55,
      -1,    -1,    58,    -1,    60,    61,    62,    -1,     3,     4,
       5,    -1,    68,    69,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,   151,   152,   153,   154,    -1,
     195,    -1,   197,   159,   160,   161,   162,   163,   164,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   179,   180,    -1,    -1,   188,   184,    -1,
      -1,    -1,    -1,   189,   195,    -1,   197,    -1,   194,    -1,
     196,    -1,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   151,   152,   153,   154,
     188,    -1,   190,    -1,   159,   160,   161,   162,   163,   164,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   179,   180,    -1,    -1,   188,   184,
      -1,    -1,    -1,    -1,   189,   195,     3,     4,     5,   194,
      -1,   196,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    12,    13,    53,    54,    55,    -1,
      -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   151,   152,   153,   154,   188,    -1,
     190,    -1,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,    -1,    -1,    -1,   184,    -1,    -1,
      -1,    -1,   189,    -1,     3,     4,     5,   194,    -1,   196,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,   197,
      49,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,
      -1,    -1,   111,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
     179,   180,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
     189,    -1,     3,     4,     5,   194,    -1,   196,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,   197,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,
     111,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,   179,   180,
      -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,   189,    -1,
       3,     4,    -1,   194,    -1,   196,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,   197,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      92,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,   179,   180,    -1,    -1,
      -1,   184,    -1,    -1,    -1,    -1,   189,    -1,     3,     4,
      -1,   194,    -1,   196,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,   108,    -1,    -1,   111,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,   179,   180,    -1,   188,    -1,   184,
      -1,    -1,    -1,    -1,   189,   196,     3,     4,    -1,   194,
      -1,   196,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,   108,    -1,    -1,   111,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,   179,   180,    -1,   188,    -1,   184,    -1,    -1,
      -1,    -1,   189,   196,     3,     4,    -1,   194,    -1,   196,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,
      -1,    -1,   111,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
     179,   180,    -1,   188,    -1,   184,    -1,    -1,    -1,    -1,
     189,   196,     3,     4,    -1,   194,    -1,   196,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,
     111,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   179,   180,
      -1,    -1,   188,   184,    -1,    -1,    -1,    -1,   189,   195,
       3,     4,     5,   194,    -1,   196,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    -1,    -1,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,    -1,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   197,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   179,   180,    -1,    -1,
     188,   184,     3,     4,    -1,    -1,   189,   195,     9,    10,
      11,   194,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,
     111,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   179,   180,
      -1,    -1,   188,   184,     3,     4,    -1,    -1,   189,   195,
       9,    10,    11,   194,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
     179,   180,    -1,    -1,    -1,   184,    -1,    50,    51,    52,
     189,    -1,    -1,    56,    57,   194,    59,    -1,    -1,    -1,
      63,    64,    -1,    66,    67,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,     4,    -1,    -1,
      -1,    -1,   125,    -1,    -1,    12,    13,   130,   131,   132,
     133,    -1,    -1,   136,    -1,   138,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
      37,    38,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    50,    51,    52,    -1,    -1,    -1,    56,
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
     157,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,   192,
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
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188
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
       6,   191,     4,   292,     4,   292,     5,   196,     5,   196,
       4,   278,   278,     6,   189,   196,   189,   191,   198,   223,
       7,   166,   167,   168,   169,   185,   186,   221,   222,     4,
     189,   191,   193,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   189,   189,
     189,   189,   189,   189,   223,   189,   223,   223,   223,     7,
     189,   189,   189,   223,   189,   189,   278,   278,   278,   278,
     278,     4,   136,   137,     4,   296,     4,   243,   244,   245,
     196,   190,   192,   196,   224,     6,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     188,   196,     6,   189,   191,   222,     6,   278,     4,   291,
     292,   296,   291,   278,   291,   294,   227,   230,   292,   296,
     278,   180,   278,   286,   287,   278,   278,   189,   278,   287,
     278,   278,   189,   287,   278,   278,   284,   189,   196,   287,
     285,   285,   285,   189,   189,   285,   285,   285,   189,   189,
     189,   189,   189,   189,   189,   189,   196,   196,   278,     4,
     284,   288,   196,   196,   281,   281,   281,   278,   278,   179,
     180,   196,   196,   281,   196,   196,   196,   179,   180,   189,
     245,   281,   196,   189,   196,   189,   189,   189,   285,   285,
     284,   189,     4,   191,   191,   245,     6,     6,   196,   196,
     196,   285,   285,   191,   191,   191,   189,   191,   193,   223,
     191,     5,   139,   196,     5,   139,     5,   139,     5,   139,
      72,    75,    78,    80,   196,   278,   286,   278,   197,   287,
       8,   181,     6,   189,   191,   223,     6,   278,   278,   278,
     193,   278,   196,   139,   278,   278,   278,     6,     6,     6,
     245,     6,   245,   191,     6,   196,   284,   284,   278,   278,
     196,   196,   224,   292,   284,     6,   191,   278,   278,     4,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   294,   291,   294,   291,   291,   291,   284,   291,
     291,   278,   294,   291,   278,   292,   278,   291,   291,   291,
     291,   296,   292,   190,   192,     7,   221,   222,   193,     7,
     223,   197,    72,    75,    78,    80,   242,   278,   287,     7,
     221,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   206,   278,   278,     6,
     191,   193,   190,   195,   190,   195,   195,   190,   195,   192,
     195,   226,   192,   226,   195,   195,   190,   181,   195,   197,
     190,   190,   278,   190,   197,   190,   190,   278,   197,   190,
     190,     7,   278,   278,   197,     6,     6,     6,   278,   278,
       7,     7,   271,   271,   278,   236,   278,   292,   237,   278,
     292,   238,   278,   292,   239,   278,   292,   278,   278,   278,
     287,   287,   196,   190,     6,   196,   245,   245,   195,   195,
     195,   281,   281,   244,   244,   195,   278,   278,   278,   278,
     257,   195,   245,   278,   278,   278,   278,   278,     7,   272,
       6,     7,   278,     6,   278,   278,   197,   287,   287,   287,
       6,     6,   278,   278,   278,   278,     4,   196,   224,   296,
      50,   278,    50,    50,    50,     5,   196,     5,   196,     5,
     196,     5,   196,   287,   190,   197,   278,   196,   278,   286,
     196,   224,   190,   190,   190,   136,   195,   245,   196,     8,
     190,   192,   197,   197,   245,   190,   195,   197,   190,   192,
     278,   287,   221,     6,     6,   278,   190,   192,   222,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     195,   224,   224,   224,   224,   224,   224,   224,   195,   195,
     195,   224,   195,   224,   224,   190,   190,   195,   195,   195,
     195,   195,   190,   224,   280,   293,     6,   195,   190,   190,
     195,   224,   190,   190,   221,   222,   193,   221,   222,   292,
     278,     6,     4,     4,   196,   289,   224,   196,   196,   196,
     196,   197,   197,   284,     8,     4,   126,   127,   128,   129,
     197,   209,   213,   216,   218,   219,   190,   192,   278,     4,
       6,   177,   203,   287,     6,   287,   278,     6,   291,     6,
     296,     6,   291,   278,   292,     7,   278,   286,   139,     7,
       7,   190,     7,   139,     7,     7,   190,   139,     7,     7,
     278,   190,   197,   196,   190,   190,   278,   284,     4,   270,
       6,   190,   190,   195,   190,   195,   190,   195,   190,   195,
     190,   190,   190,   197,   197,   287,   193,   245,   197,   197,
     281,   278,   278,   197,   197,   278,   281,   195,   195,   195,
      95,   106,   114,   115,   116,   120,   121,   122,   123,   267,
     268,   281,   197,   254,   190,   197,   190,   190,   190,   278,
       6,   278,   190,   192,   192,   197,   197,   197,   192,   192,
     195,   192,   287,   192,   196,   197,   196,   196,   196,   287,
     287,   287,   287,   197,     8,   287,   287,     7,     7,     7,
     193,   278,   197,   278,   278,     7,   193,   197,   196,   284,
       6,   221,   222,   221,   222,   197,   197,   284,   192,   222,
     193,   222,   291,   278,   278,   278,   278,   287,   291,   284,
     291,   291,   292,   232,   234,   278,   291,   278,     6,     4,
     136,   137,   278,     6,     6,     6,     7,   191,   288,   290,
       6,   287,   287,   287,   287,   224,     6,   278,   210,   189,
     189,   196,   220,     6,   222,   222,   192,   177,   291,   190,
     190,   195,     7,   224,   224,   281,    78,    80,   284,   284,
       7,   284,    78,    80,   284,   284,     7,    80,   284,   284,
       6,     7,     7,   287,     7,     7,    95,   269,     6,     7,
     221,   278,   221,   278,   221,   278,   221,   278,     7,     7,
       7,     7,     7,   197,     4,   197,   195,   195,   195,   197,
     197,   281,   281,   281,     4,     6,   196,     6,   189,     6,
     124,     6,   124,     6,   124,     6,   124,   197,   268,   195,
     267,     7,     6,     7,     7,     7,     6,   196,     6,     6,
       6,    78,   278,     6,     6,   278,   193,   197,   278,   278,
     278,   278,   197,   197,   197,   197,   278,   197,   197,   284,
     284,   284,     4,   195,     8,     8,   190,     4,     4,   284,
     197,   278,     6,   278,     6,   224,     6,     6,     4,     6,
     224,   224,   224,   224,   224,   195,   190,   190,   190,   195,
     195,   224,   233,   195,   224,   235,   190,   190,     6,     7,
     221,   222,   193,     7,     6,   288,   278,   195,   197,   197,
     197,   197,   197,   221,   189,   278,   278,   283,   284,   196,
     193,     6,     6,   203,     6,   278,   196,   278,   292,     6,
       6,     6,   196,   196,    88,   241,   241,   284,     6,   196,
     196,     6,     6,   284,   196,     6,     6,     5,   284,   197,
     284,   284,     4,     6,   284,   284,   284,   284,   284,   284,
     284,   284,   196,   196,     7,     6,     7,   278,   278,   278,
     196,   196,   195,   197,   195,   197,   195,   197,   191,   278,
     284,   278,     6,     6,     6,     6,   278,   281,   197,     5,
     196,   284,   196,   196,   196,   284,   287,   196,     6,   192,
       4,   224,   195,   195,   195,   195,   224,     6,     6,   135,
     278,   278,   278,     6,     6,     7,   195,     6,     6,     6,
     221,   222,   291,   292,     4,     4,   148,   292,   278,     6,
       4,   289,     6,   192,   288,     6,     6,     6,     6,   284,
     207,   278,   195,   195,   195,   197,   208,   278,     4,   291,
     195,   284,   292,   278,   278,   281,     6,     6,     6,   278,
     278,     6,   278,     5,     6,   196,     6,   139,   240,   278,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   287,
     287,   278,   278,   292,   197,   190,   195,   197,   244,   244,
     281,     6,   258,   281,     6,   259,   281,     6,   260,   278,
     197,   195,   190,   197,   195,     6,   180,   281,     6,   283,
     281,   281,     6,   197,   278,     6,   278,   278,   278,   278,
     284,   195,   197,     8,   197,   190,   196,   278,   292,   284,
     284,   190,   224,   196,   284,   292,   196,   278,   292,   292,
       6,     6,     7,     6,   193,     6,   190,   195,   278,   278,
     284,   196,   195,   197,     6,   278,   228,   229,   197,   197,
     197,   197,   197,     5,   283,    76,     6,   196,   197,   197,
     196,     6,     6,   196,   278,   197,   197,   195,   196,   195,
     196,   195,   196,   192,     6,   284,     7,   196,   278,   195,
     197,   195,   195,     6,   197,   195,   195,   195,   195,   134,
     278,   278,   287,     6,     6,   197,     6,   231,   278,   294,
     288,   137,   211,   278,   195,   195,   283,   278,     6,   195,
     232,   234,     6,     6,     6,     6,     6,     6,   197,   196,
     283,    99,   100,   105,   273,    99,   100,   273,   287,   244,
     195,   197,   278,   281,   267,   278,   281,   267,   278,   281,
     267,     6,   195,   197,   284,   245,   197,   281,     6,   287,
     281,   278,   278,   278,   278,   278,   197,   197,   197,     6,
     195,   197,     7,   197,     6,   196,   278,   278,   197,   278,
     197,   197,   196,   278,   197,   196,   281,   284,     6,   196,
     281,     6,   197,   197,   278,   197,   195,   197,   197,   195,
     197,   197,   195,   197,   284,     6,    95,   197,   255,   196,
     195,   197,   195,   195,   195,   195,   195,     6,     6,   278,
     292,   208,   190,   195,     6,   196,   195,   278,   197,     6,
     281,     6,   281,     6,     6,   197,     6,   261,   278,     6,
       6,   262,   278,     6,     6,   263,   278,     6,   197,   278,
     267,   245,   287,     6,   281,   287,   278,   278,   278,   278,
       7,   197,   214,   278,   283,   278,   195,   195,   195,   196,
     197,   196,   197,   196,   197,     6,     6,   197,   197,   256,
     197,   195,   197,   195,   195,   195,   195,   292,     6,   196,
     190,   197,   197,   278,   281,   281,   267,     6,   264,   267,
       6,   265,   267,     6,   266,   267,     6,   287,     6,   278,
     278,   278,   278,   212,   291,   217,   196,     6,   197,   195,
     195,   197,   196,   197,   196,   197,   196,   197,   197,   195,
     195,   195,   195,   195,   197,   196,   283,     6,   278,   278,
       6,   267,     6,   267,     6,   267,     6,   278,   278,   278,
     278,   291,     6,   215,   291,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   195,   197,     6,     6,     6,
       6,     6,     6,   291,     6
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
     252,   252,   252,   252,   252,   252,   252,   252,   253,   253,
     253,   254,   253,   255,   253,   256,   253,   257,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   258,   253,
     259,   253,   260,   253,   261,   253,   262,   253,   263,   253,
     264,   253,   265,   253,   266,   253,   267,   267,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   269,   269,   270,   270,   271,   271,   272,
     272,   273,   273,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   275,
     275,   275,   276,   276,   276,   277,   277,   277,   277,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   280,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   281,   281,   281,   281,
     281,   282,   282,   282,   282,   283,   283,   284,   284,   284,
     284,   284,   284,   285,   285,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   287,   288,   288,   288,
     288,   289,   289,   290,   290,   291,   291,   291,   291,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   293,   292,   294,   294,
     295,   295,   296,   296
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
       1,     1,     1,     4,     6,     4,     4,     4,     4,     8,
       4,     8,     4,     6,     4,     1,     0,     6,     1,     3,
       5,     5,     1,     1
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
#line 4222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 203 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4228 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 204 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4234 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 205 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4240 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 206 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4246 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 207 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4258 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4276 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4300 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 227 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 234 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 239 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4352 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4370 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4387 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4404 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4431 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4449 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4466 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4483 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 370 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 384 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4518 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4524 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4530 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 393 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4536 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4644 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 512 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 521 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 528 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4690 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 547 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 556 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 563 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4735 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 581 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4757 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4777 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 629 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 635 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 642 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 4868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 4874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 4880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 667 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 4889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 672 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 4899 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4963 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4996 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 796 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5038 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 801 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 806 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 811 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 816 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 823 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5087 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5106 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 845 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5124 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 855 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 860 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 865 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5152 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 874 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 880 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5172 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5194 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5216 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5229 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 946 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 951 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5260 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5284 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5308 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5323 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5335 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5361 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5388 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5418 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5440 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5456 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5472 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5485 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1161 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5504 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5524 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5537 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1188 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5543 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1204 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5567 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1212 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1218 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5586 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5601 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5619 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1272 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5642 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1289 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5665 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1315 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1319 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1325 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1333 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1337 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1343 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1351 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1355 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1361 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1369 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1373 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1379 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1387 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5798 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1403 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1407 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5828 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5855 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5891 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5915 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5937 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5962 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5984 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6018 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6052 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6074 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6096 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6126 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6148 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6170 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6206 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6228 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1803 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1809 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1815 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6302 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6331 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6360 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6381 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6404 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6441 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6477 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6499 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6520 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6540 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2066 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6585 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2071 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6594 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2076 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2081 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2086 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6621 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6648 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2114 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6658 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2130 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2131 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2136 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2140 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6698 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6725 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6752 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6779 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6806 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6831 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6861 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6885 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6910 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6934 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7050 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7073 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7115 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7222 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7235 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2638 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7245 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7264 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7296 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7312 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7325 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7338 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2741 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2747 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7371 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7384 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7397 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7410 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7423 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7483 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7505 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7526 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7545 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7568 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7584 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2955 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7620 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2959 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2964 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2971 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2976 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2982 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2987 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7678 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3001 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3005 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3009 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7715 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7773 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7785 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7806 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7827 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7853 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7879 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7918 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7930 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3203 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 7942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3211 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 7952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3217 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 7963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3224 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 7974 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3231 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    }
#line 7982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3235 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 7989 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3244 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3252 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3260 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8025 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3268 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3274 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3282 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3288 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3296 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8079 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3302 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8091 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3310 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8112 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8134 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3345 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3352 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3359 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3366 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3373 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3387 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3393 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3400 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3406 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8253 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3413 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8263 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3419 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3426 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3432 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8295 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3439 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3445 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3452 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3458 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8337 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3465 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3471 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8358 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3478 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3484 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3491 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8389 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3497 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3508 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3511 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3517 "Gmsh.y" /* yacc.c:1646  */
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
#line 8430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3529 "Gmsh.y" /* yacc.c:1646  */
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
#line 8454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3549 "Gmsh.y" /* yacc.c:1646  */
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
#line 8481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3573 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8489 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3577 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3581 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3585 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3589 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3595 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3601 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3605 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3609 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3613 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8565 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3617 "Gmsh.y" /* yacc.c:1646  */
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
#line 8588 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3636 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 8600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3648 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3652 "Gmsh.y" /* yacc.c:1646  */
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
#line 8625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3667 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3671 "Gmsh.y" /* yacc.c:1646  */
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
#line 8651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3687 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3691 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8667 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3696 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8675 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3700 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3706 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3710 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3717 "Gmsh.y" /* yacc.c:1646  */
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
#line 8759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3773 "Gmsh.y" /* yacc.c:1646  */
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
#line 8833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3843 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 8842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3848 "Gmsh.y" /* yacc.c:1646  */
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
#line 8913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3915 "Gmsh.y" /* yacc.c:1646  */
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
#line 8953 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3951 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 8965 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3959 "Gmsh.y" /* yacc.c:1646  */
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
#line 9012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4002 "Gmsh.y" /* yacc.c:1646  */
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
#line 9055 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4041 "Gmsh.y" /* yacc.c:1646  */
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
#line 9079 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4062 "Gmsh.y" /* yacc.c:1646  */
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
#line 9114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4094 "Gmsh.y" /* yacc.c:1646  */
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
#line 9144 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4121 "Gmsh.y" /* yacc.c:1646  */
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
#line 9173 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4147 "Gmsh.y" /* yacc.c:1646  */
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
#line 9202 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4173 "Gmsh.y" /* yacc.c:1646  */
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
#line 9231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4199 "Gmsh.y" /* yacc.c:1646  */
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
#line 9260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4225 "Gmsh.y" /* yacc.c:1646  */
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
#line 9285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4246 "Gmsh.y" /* yacc.c:1646  */
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
#line 9317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4274 "Gmsh.y" /* yacc.c:1646  */
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
#line 9349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4302 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4306 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4310 "Gmsh.y" /* yacc.c:1646  */
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
#line 9397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4338 "Gmsh.y" /* yacc.c:1646  */
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
#line 9440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4377 "Gmsh.y" /* yacc.c:1646  */
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
#line 9483 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4416 "Gmsh.y" /* yacc.c:1646  */
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
#line 9508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4437 "Gmsh.y" /* yacc.c:1646  */
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
#line 9533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4458 "Gmsh.y" /* yacc.c:1646  */
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
#line 9558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4485 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9566 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4489 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 9580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4499 "Gmsh.y" /* yacc.c:1646  */
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
#line 9614 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4533 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9620 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4534 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4535 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9632 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4540 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4546 "Gmsh.y" /* yacc.c:1646  */
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
#line 9658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4558 "Gmsh.y" /* yacc.c:1646  */
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
#line 9680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4576 "Gmsh.y" /* yacc.c:1646  */
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
#line 9707 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4603 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4605 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4606 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4607 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4608 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4609 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9755 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4612 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4618 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4619 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4621 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4622 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4623 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 9808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4625 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 9814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4626 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 9820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4627 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 9826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 9832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4629 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 9838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 9844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 9850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 9856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4633 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 9862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4634 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 9868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4635 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 9874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4636 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 9880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4637 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 9886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4638 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 9892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4639 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 9898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4640 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 9904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4641 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 9910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4642 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 9916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 9922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 9928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 9934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 9940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 9946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 9952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 9958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 9964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 9970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4660 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 9976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4661 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 9982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 9988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 9994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10018 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4673 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10030 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4675 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4681 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10049 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4686 "Gmsh.y" /* yacc.c:1646  */
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
#line 10070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4703 "Gmsh.y" /* yacc.c:1646  */
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
#line 10092 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4721 "Gmsh.y" /* yacc.c:1646  */
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
#line 10114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4739 "Gmsh.y" /* yacc.c:1646  */
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
#line 10136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4757 "Gmsh.y" /* yacc.c:1646  */
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
#line 10158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4775 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4780 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4786 "Gmsh.y" /* yacc.c:1646  */
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
#line 10193 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4798 "Gmsh.y" /* yacc.c:1646  */
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
#line 10214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4815 "Gmsh.y" /* yacc.c:1646  */
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
#line 10236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4833 "Gmsh.y" /* yacc.c:1646  */
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
#line 10258 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4851 "Gmsh.y" /* yacc.c:1646  */
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
#line 10280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4869 "Gmsh.y" /* yacc.c:1646  */
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
#line 10302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4890 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4895 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4900 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4910 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4920 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 4925 "Gmsh.y" /* yacc.c:1646  */
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
#line 10372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4936 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4945 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 4950 "Gmsh.y" /* yacc.c:1646  */
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
#line 10422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4977 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 4981 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10438 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10446 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 4989 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 4993 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5000 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5004 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5008 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5012 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5019 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5024 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5031 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5036 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5040 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10537 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5045 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10545 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5049 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5057 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 10569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5068 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5072 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 10590 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5084 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5092 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 10614 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5100 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5107 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 10639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5117 "Gmsh.y" /* yacc.c:1646  */
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
#line 10672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5146 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5150 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10688 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5154 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5158 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5162 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5166 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5170 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5174 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5178 "Gmsh.y" /* yacc.c:1646  */
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
#line 10769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5207 "Gmsh.y" /* yacc.c:1646  */
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
#line 10802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5236 "Gmsh.y" /* yacc.c:1646  */
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
#line 10835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5265 "Gmsh.y" /* yacc.c:1646  */
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
#line 10868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5295 "Gmsh.y" /* yacc.c:1646  */
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
#line 10884 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5308 "Gmsh.y" /* yacc.c:1646  */
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
#line 10900 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5321 "Gmsh.y" /* yacc.c:1646  */
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
#line 10916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5334 "Gmsh.y" /* yacc.c:1646  */
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
#line 10932 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5346 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 10946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 10960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5366 "Gmsh.y" /* yacc.c:1646  */
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
#line 10976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5378 "Gmsh.y" /* yacc.c:1646  */
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
#line 10992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5391 "Gmsh.y" /* yacc.c:1646  */
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
#line 11008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5403 "Gmsh.y" /* yacc.c:1646  */
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
#line 11030 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5421 "Gmsh.y" /* yacc.c:1646  */
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
#line 11052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5442 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5447 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5451 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5455 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5467 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11098 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5471 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11106 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5483 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5490 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5500 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5504 "Gmsh.y" /* yacc.c:1646  */
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
#line 11152 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5519 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5524 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11169 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5531 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5535 "Gmsh.y" /* yacc.c:1646  */
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
#line 11194 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5548 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5556 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11218 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5567 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5571 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5579 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5585 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11258 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5591 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5599 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5607 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5614 "Gmsh.y" /* yacc.c:1646  */
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
#line 11312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5629 "Gmsh.y" /* yacc.c:1646  */
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
#line 11330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5643 "Gmsh.y" /* yacc.c:1646  */
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
#line 11348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5657 "Gmsh.y" /* yacc.c:1646  */
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
#line 11364 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5669 "Gmsh.y" /* yacc.c:1646  */
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
#line 11384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5685 "Gmsh.y" /* yacc.c:1646  */
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
#line 11399 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5696 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5700 "Gmsh.y" /* yacc.c:1646  */
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
#line 11430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5719 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5726 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5732 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11457 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5734 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5745 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5750 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5756 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5765 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5778 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5781 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11524 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5785 "Gmsh.y" /* yacc.c:1906  */


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
