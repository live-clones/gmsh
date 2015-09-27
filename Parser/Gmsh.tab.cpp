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
    tTextAttributes = 305,
    tBoundingBox = 306,
    tDraw = 307,
    tSetChanged = 308,
    tToday = 309,
    tFixRelativePath = 310,
    tCurrentDirectory = 311,
    tSyncModel = 312,
    tNewModel = 313,
    tOnelabAction = 314,
    tOnelabRun = 315,
    tCpu = 316,
    tMemory = 317,
    tTotalMemory = 318,
    tCreateTopology = 319,
    tCreateTopologyNoHoles = 320,
    tDistanceFunction = 321,
    tDefineConstant = 322,
    tUndefineConstant = 323,
    tDefineNumber = 324,
    tDefineString = 325,
    tSetNumber = 326,
    tSetString = 327,
    tPoint = 328,
    tCircle = 329,
    tEllipse = 330,
    tLine = 331,
    tSphere = 332,
    tPolarSphere = 333,
    tSurface = 334,
    tSpline = 335,
    tVolume = 336,
    tCharacteristic = 337,
    tLength = 338,
    tParametric = 339,
    tElliptic = 340,
    tRefineMesh = 341,
    tAdaptMesh = 342,
    tRelocateMesh = 343,
    tPlane = 344,
    tRuled = 345,
    tTransfinite = 346,
    tComplex = 347,
    tPhysical = 348,
    tCompound = 349,
    tPeriodic = 350,
    tUsing = 351,
    tPlugin = 352,
    tDegenerated = 353,
    tRecursive = 354,
    tRotate = 355,
    tTranslate = 356,
    tSymmetry = 357,
    tDilate = 358,
    tExtrude = 359,
    tLevelset = 360,
    tAffine = 361,
    tRecombine = 362,
    tSmoother = 363,
    tSplit = 364,
    tDelete = 365,
    tCoherence = 366,
    tIntersect = 367,
    tMeshAlgorithm = 368,
    tReverse = 369,
    tLayers = 370,
    tScaleLast = 371,
    tHole = 372,
    tAlias = 373,
    tAliasWithOptions = 374,
    tCopyOptions = 375,
    tQuadTriAddVerts = 376,
    tQuadTriNoNewVerts = 377,
    tQuadTriSngl = 378,
    tQuadTriDbl = 379,
    tRecombLaterals = 380,
    tTransfQuadTri = 381,
    tText2D = 382,
    tText3D = 383,
    tInterpolationScheme = 384,
    tTime = 385,
    tCombine = 386,
    tBSpline = 387,
    tBezier = 388,
    tNurbs = 389,
    tNurbsOrder = 390,
    tNurbsKnots = 391,
    tColor = 392,
    tColorTable = 393,
    tFor = 394,
    tIn = 395,
    tEndFor = 396,
    tIf = 397,
    tEndIf = 398,
    tExit = 399,
    tAbort = 400,
    tField = 401,
    tReturn = 402,
    tCall = 403,
    tMacro = 404,
    tShow = 405,
    tHide = 406,
    tGetValue = 407,
    tGetEnv = 408,
    tGetString = 409,
    tGetNumber = 410,
    tHomology = 411,
    tCohomology = 412,
    tBetti = 413,
    tSetOrder = 414,
    tExists = 415,
    tFileExists = 416,
    tGMSH_MAJOR_VERSION = 417,
    tGMSH_MINOR_VERSION = 418,
    tGMSH_PATCH_VERSION = 419,
    tGmshExecutableName = 420,
    tSetPartition = 421,
    tNameFromString = 422,
    tStringFromName = 423,
    tAFFECTPLUS = 424,
    tAFFECTMINUS = 425,
    tAFFECTTIMES = 426,
    tAFFECTDIVIDE = 427,
    tOR = 428,
    tAND = 429,
    tEQUAL = 430,
    tNOTEQUAL = 431,
    tLESSOREQUAL = 432,
    tGREATEROREQUAL = 433,
    tPLUSPLUS = 434,
    tMINUSMINUS = 435,
    UNARYPREC = 436
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

#line 410 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 427 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   10064

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  202
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  516
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1827

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   436

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   187,     2,   197,     2,   186,     2,     2,
     192,   193,   184,   182,   198,   183,   196,   185,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     178,     2,   180,   173,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   194,     2,   195,   191,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   199,     2,   200,   201,     2,     2,     2,
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
     165,   166,   167,   168,   169,   170,   171,   172,   174,   175,
     176,   177,   179,   181,   188,   189,   190
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
    5661,  5673,  5689,  5698,  5709,  5713,  5732,  5739,  5746,  5745,
    5758,  5763,  5769,  5778,  5791,  5794,  5798
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
  "tStrCmp", "tStrChoice", "tUpperCase", "tTextAttributes", "tBoundingBox",
  "tDraw", "tSetChanged", "tToday", "tFixRelativePath",
  "tCurrentDirectory", "tSyncModel", "tNewModel", "tOnelabAction",
  "tOnelabRun", "tCpu", "tMemory", "tTotalMemory", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tDefineNumber", "tDefineString", "tSetNumber",
  "tSetString", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     425,   426,   427,    63,   428,   429,   430,   431,    60,   432,
      62,   433,    43,    45,    42,    47,    37,    33,   434,   435,
     436,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

#define YYPACT_NINF -1337

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1337)))

#define YYTABLE_NINF -489

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7056,    57,    77,  7173, -1337, -1337,  3458,    93,   -55,   -73,
     -63,    41,   127,   141,   154,   158,   -18,   189,   203,    62,
      70,   -98,   -98,  -142,    78,    99,    25,   110,   116,    14,
     129,   136,   153,   268,   274,   331,   161,   421,   278,   311,
     208,   328,   315,   370,   -42,   241,   385,   -39,   271,   137,
     137,   282,   273,    28,   338,   395,   409,    12,    61,   449,
     427,   118,   528,   537,   552,  4964,   555,   363,   400,   412,
      19,    -1, -1337,   450, -1337,   613,   649,   447, -1337,   359,
    5233,    33,    34, -1337, -1337, -1337,  6918,  6918,   492, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,    52, -1337,   -23,    97, -1337,
       6, -1337, -1337, -1337, -1337,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     503,   509,   540,   541,   544,   547,   -98,   -98,   556, -1337,
     -98, -1337, -1337, -1337, -1337, -1337,   -98,   -98,   753,   569,
     583,   586,   -98,   595,   596, -1337, -1337, -1337, -1337,   662,
    6918,  6918,  6918,  6918,  6918,    44,    17,    42,   605,   -43,
     728, -1337,   652,   795,   139,   -64,   855,  6918,  5042,  5042,
   -1337,  6918, -1337, -1337, -1337, -1337,  5042, -1337, -1337, -1337,
   -1337, -1337, -1337,  3276,    17,  6918,  6733,  6918,  6918,   676,
    6918,  6733,  6918,  6918,   687,  6733,  6918,  6918,  5346,   703,
     681, -1337,  6733,  4964,  4964,  4964,   732,   737,  4964,  4964,
    4964,   744,   754,   758,   769,   775,   776,   780,   783,   738,
    6301,   941,  5346,    19,   755,   777,   137,   137,   137,  6918,
    6918,   -99, -1337,   160,   137,   812,   860,   861,  6357,   162,
    -139,   787,   791,   881,  4964,  4964,  5346,   907,     5,   908,
   -1337,   900,  1097,  1098, -1337,   909,   911,   912,  4964,  4964,
     913,   918,   919,   529, -1337,   920,    15,    21,    26,    40,
     472,  5537,  6918,  3940, -1337, -1337,  1997, -1337,  1111, -1337,
     345,   193,  1112,  6918,  6918,  6918,   926,  6918,   924,   984,
    6918,  6918, -1337, -1337,  6918,   925,  1123,  1124, -1337, -1337,
    1126, -1337,  1129, -1337,   258,  1047,  4480,  5042, -1337,  5346,
    5346,  6918,  6918,   937,   114,  3276, -1337, -1337, -1337, -1337,
   -1337, -1337,  5346,  1131,   946,  6918,  6918,  1138,  6918,  6918,
    6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,
    6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,
    5042,  5042,  5042,  5042,  5042,  5042,  5346,  5042,  5042,  6918,
    3276,  5042,  5042,  6918,  3276,  6918,  5042,  5042,  5042,  5042,
      17,  3276,    17,   953,   953,   953,  4547,  8793,   111,   950,
    1144,   -98,   956, -1337,   952,  3984,  6918, -1337, -1337,  6733,
      18, -1337,  6918,  6918,  6918,  6918,  6918,  6918,  6918,  6918,
    6918,  6918,  6918,  6918,  6918,  6918,  6918, -1337, -1337,  6918,
    6918, -1337, -1337,  1255,   390,   212, -1337, -1337,   317,  5150,
   -1337,   428,   103,   354,   958,   960,  4738,  6733,  2054, -1337,
     430,  9138,  9159,  6918,  9180,   454,  9201,  9222,  6918,   465,
    9243,  9264,  1150,  6918,  6918,   480,  1153,  1154,  1156,  6918,
    6918,  1159,  1160,  1160,  6918,  6548,  6548,  6548,  6548,  6918,
    6918,  6918,  6733,  6733,  7728,   970,  1162,   974, -1337, -1337,
     112, -1337, -1337,  5341,  5532,   137,   137,    42,    42,   168,
    6918,  6918,  6918,  6357,  6357,  6918,  3984,   194, -1337,  6918,
    6918,  6918,  6918,  6918,  1167,  1173,  1174,  6918,  1176,  6918,
    6918,  1413, -1337, -1337,  6733,  6733,  6733,  1177,  1179,  6918,
    6918,  6918,  6918,  6918,  1183,   163,    17, -1337,  1143,  6918,
   -1337,  1145, -1337,  1151, -1337,  1158,    35,    36,    38,    39,
    6733,   953, -1337,  9285, -1337,   522,  6918,  5728, -1337,  6918,
    6918,   312, -1337,  9306,  9327,  9348,  1063,  5723, -1337,  1002,
    3377,  9369,  8816, -1337, -1337, -1337,  1554, -1337,  1666,  6918,
   -1337, -1337,  1012,  1017,   526,  9390,  8839,  6918,  6733,    18,
    1205,  1206, -1337,  6918,  9411,  8862,   166,  8770,  8770,  8770,
    8770,  8770,  8770,  8770,  8770,  8770,  8770,  8770,  5914,  8770,
    8770,  8770,  8770,  8770,  8770,  8770,  6105,  6352,  6728,   455,
     551,   455,  1020,  1021,  1018,  1019,  1037,  1038,  7782,   600,
     575,   600,  9873, -1337,  1286,  1039,  1022,   579,   600,  1025,
    1046,  1045,   134,    83,  3276,  6918,  1235,  1239,    29,   600,
   -1337,  -124,    31,    32,   -27, -1337,  5286,   599, -1337,  5346,
    3410,  2576,  3663,   691,   691,   397,   397,   397,   397,   506,
     506,   953,   953,   953,   953,    10,  9432,  8885, -1337,  6918,
    1240,    16,  6733,  1241,  6733,  6918,  1242,  5042,  1243, -1337,
      17,  1244,  5042,  6918,  3276,  1248,  6733,  6733,  1118,  1253,
    1256,  9453,  1258,  1127,  1259,  1262,  9474,  1130,  1264,  1266,
    6918,  9495,  5477,  1075, -1337, -1337, -1337,  9516,  9537,  6918,
    5346,  1275,  1274,  9558,  1088,  9873,  1095,  1101,  9873,  1099,
    1102,  9873,  1100,  1106,  9873,  1103,  9579,  9600,  9621,   602,
     607,  6733,  1104, -1337, -1337,  1967,  2127,   137,  6918,  6918,
   -1337, -1337,  1105,  1107,  6357,  7808,  7834,  7860,  4959,  1054,
     137,  2368,  9642,  5668,  9663,  9684,  9705,  6918,  1298, -1337,
    6918,  9726, -1337,  8908,  8931, -1337,   610,   611,   614, -1337,
   -1337,  8954,  8977,  7886,  9000,   193,  6733, -1337,  1113,  1110,
    5859,  1116,  1119,  1120, -1337,  6733, -1337,  6733, -1337,  6733,
   -1337,  6733,   617, -1337, -1337,  3501,  6733,   953, -1337,  6733,
   -1337,  1299,  1303,  1315,  1128,  6918,  2597,  6918,  6918, -1337,
      54, -1337, -1337,  2734, -1337,  1133,  5346,  1317,   134,   134,
    6050,   620,  5346, -1337, -1337,  9023,   193,  1149, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
    6918, -1337, -1337, -1337, -1337, -1337, -1337, -1337,  6918,  6918,
    6918, -1337,  6733, -1337, -1337, -1337, -1337,  5042,  5346,  5042,
    5042,  3276, -1337, -1337, -1337, -1337, -1337, -1337,  6918, -1337,
   -1337,  5042, -1337, -1337, -1337, -1337,  6918,  1319,   155,  6918,
    1321,  1323,  1520, -1337,  1326,  1136,    19,  1328, -1337,  6733,
    6733,  6733,  6733, -1337,   600,  1329,  6918, -1337,  1148,  1152,
    1137, -1337,  1336, -1337, -1337, -1337, -1337, -1337,   193,   193,
    9046, -1337, -1337,  1166,  5042,   581, -1337,   592,  7912, -1337,
   -1337, -1337,  1340, -1337, -1337,  8770,   600,   137,  2054, -1337,
     745,  5346,  5346,  1341,  5346,   746,  5346,  5346,  1342,  1269,
    5346,  5346,  1704,  1345,  1346,  6733,  1347,  1348,  3721, -1337,
   -1337,  1350, -1337,  1352,    18,  6918,    18,  6918,    18,  6918,
      18,  6918,  1355,  1356,  1359,  1360,  1361,   630,  1353,  2771,
   -1337, -1337,   238,  7938,  7964, -1337, -1337,  6254,   -80,   137,
     137,   137,  1366,  1368,  1178,  1370,  1180,    11,    24,    43,
      45,    -8, -1337,   255, -1337,  1054,  1371,  1373,  1374,  1375,
    1376,  9873, -1337,  1818,  1185,  1379,  1381,  1382,  1313,  6918,
    1391,  1392,  6918,  -117,   635, -1337,  6918, -1337,  6918,  6918,
    6918,   657,   685,   688,   689, -1337,  6918,   693,   694,  5346,
    5346,  5346,  1395,  7990, -1337,  3535,   813,  1400,  1401, -1337,
    5346,  1207, -1337,  6918,  1402,  6918,  1403, -1337,   600,  1404,
    1405, -1337,  1408, -1337,  1407,  8770,  8770,  8770,  8770,   557,
    1208,  1222,  1223,  1224,  1221,   561,   571,  9747,  1227,  2089,
   -1337,   146,  1225,  1415,  2157, -1337, -1337, -1337,    19,  6918,
   -1337,   717, -1337,   718,   727,   730,   735,    18, -1337,  9873,
    1231,  6918,  6918,  5346,  1228, -1337, -1337, -1337,  1246, -1337,
    1418,    80,  1438,  6918,  4520,  1442,  1443,    22,  1252,  1254,
    1363,  1363,  5346,  1448,  1257,  1277,  1451,  1452,  5346,  1281,
    1467,  1468, -1337,  1473,  5346,   742,  5346,  5346,  1477,  1478,
   -1337,  5346,  5346,  9873,  5346,  9873,  5346,  9873,  5346,  9873,
    5346,  5346,  5346,  1284,  1297,  1491,   441, -1337,  6918,  6918,
    6918,  1300,  1302,  -113,  -109,   -52,  1314, -1337,  5346, -1337,
    6918, -1337,  1503, -1337,  1504, -1337,  1506, -1337,  1507, -1337,
   -1337,  6357,   516,  5155, -1337,  1316,  1318,  5919, -1337,  6733,
   -1337, -1337, -1337,  1322,  2341, -1337, -1337,  9069,  1510,   600,
    8016,  8042,  8068,  8094, -1337, -1337, -1337, -1337,  9873, -1337,
     600,  1512,  1514,  1386, -1337,  6918,  6918,  6918, -1337,  1518,
     486,  1327,  1521,  2365, -1337,  2404, -1337,    18, -1337, -1337,
     223, -1337, -1337, -1337, -1337, -1337, -1337,  5042, -1337, -1337,
   -1337,  3276,  1524, -1337, -1337,     8, -1337, -1337, -1337, -1337,
   -1337,  3276,  6918,  1523,  1526,    29, -1337,  1525,  9092,    19,
   -1337,  1527,  1528,  1530,  1531,  5346,  6918,  8120,  8146,   751,
   -1337,  6918,  1534, -1337, -1337,  5042, -1337,  8172,  4138,  9873,
   -1337, -1337, -1337, -1337,  6918,  6918,   137,  1533,  1536,  1537,
   -1337,  6918,  6918, -1337, -1337,  1538,  6918, -1337, -1337,  1545,
    1546,  1333,  1547,  1411,  6918, -1337,  1548,  1549,  1550,  1551,
    1553,  1555,   949,  1557,  6733,  6733,  6918, -1337,  6548,  6296,
    9768,  4078,    42,    42,   137,  1559,   137,  1562,   137,  1564,
    6918,   387,  1377,  9789, -1337, -1337, -1337, -1337,  6446,   275,
   -1337,  1565,  3726,  1567,  5346,   137,  3726,  1568,   762,  6918,
   -1337,  1570,   193, -1337,  6918,  6918,  6918,  6918, -1337, -1337,
   -1337,  5346,  4269,   663,  9810, -1337, -1337,  4582,  5346, -1337,
   -1337, -1337,  5346, -1337,  1384,   600,  4329,  4773,  3276,  1572,
    2559, -1337,  1573,  1575, -1337,  1383, -1337, -1337, -1337, -1337,
   -1337,  1577,   593,  9873,  6918,  6918,  5346,  1385,   765,  9873,
   -1337,  1579,  6918, -1337, -1337,  6474,  6504,   335, -1337, -1337,
   -1337,  6673,  6815, -1337,  6843,  1582, -1337,  5346, -1337,  1515,
    1583,  9873, -1337, -1337, -1337, -1337, -1337, -1337,  1394, -1337,
   -1337,   766,   773,  7755,  2835,  1585,  1396, -1337,  6918, -1337,
    1397,  1398,   286, -1337,  1406,   304, -1337,  1410,   316, -1337,
    1416,  9115,  1588,  5346,  1589,  1417,  6918, -1337,  6110,   321,
   -1337,   784,   346,   352, -1337,  1593,  7168, -1337,  8198,  8224,
    8250,  8276,  1465,  6918, -1337,  6918, -1337, -1337,  6733,  2856,
    1596,  1412,  1597, -1337, -1337,  3940, -1337, -1337,  5042,  9873,
   -1337, -1337, -1337, -1337,    19, -1337,  1472, -1337, -1337,  6918,
    8302,  8328, -1337,  5346,  6918,  1600, -1337,  8354, -1337, -1337,
    1608,  1611,  1612,  1613,  1614,  1615,   802,  1423, -1337,  5346,
     608,   641,  6733, -1337, -1337,    42,  4671, -1337, -1337,  6357,
    1054,  6357,  1054,  6357,  1054,  1617, -1337,   803,  5346, -1337,
    7196,   137,  1618,  6733,   137, -1337, -1337,  6918,  6918,  6918,
    6918,  6918,  7224,  7252,   807, -1337, -1337,  1620, -1337,   810,
    2296,   814,  1633, -1337,  1441,  9873,  6918,  6918,   819,  9873,
   -1337,  6918,   820,   825, -1337, -1337, -1337, -1337, -1337, -1337,
    1446,  6918,   828,  1450,   137,  5346,  1635,  1454,   137,  1636,
     829,  1455,  6918, -1337,  7280,   360,   553,  7308,   392,   589,
    7336,   431,   928, -1337,  5346,  1644,  1558,  3168,  1457,   453,
   -1337,   832,   461,  8380,  8406,  8432,  8458,  2937, -1337, -1337,
    1645, -1337,  6918, -1337,  3276, -1337, -1337,  6918,  9831,  8484,
      49,  8510, -1337, -1337,  6918,  7364,  1651,   137,    76, -1337,
   -1337,   137,    91, -1337,  1652, -1337,  7392,  1654,  6918,  1660,
    1661,  6918,  1662,  1663,  6918,  1664,  1471, -1337,  6918, -1337,
    1054, -1337,  6733,  1667,  6110,  6918,  6918,  6918,  6918, -1337,
   -1337,  3175, -1337,   833, -1337,  6918, -1337,  5346,  6918,  8536,
   -1337, -1337,   464, -1337,   490, -1337, -1337, -1337, -1337,  1476,
    7420, -1337, -1337,  1481,  7448, -1337, -1337,  1482,  7476, -1337,
    1670,  2984,  1161,  4812,   841, -1337,   500,   842,  8562,  8588,
    8614,  8640,  3276,  1671,  1483,  9852,   848,  7504,  6918,   137,
     137,  1054,  1677,  1054,  1678,  1054,  1679, -1337, -1337, -1337,
   -1337,  1054,  1683,  6733,  1684,  6918,  6918,  6918,  6918, -1337,
   -1337,  5042, -1337,  1508,  1702,  7532,   517,   520,  1279, -1337,
    1513,  1806, -1337,  1516,  2521, -1337,  1517,  2763, -1337,   857,
   -1337,  8666,  8692,  8718,  8744,   858, -1337,  1522,  5346, -1337,
    1703,  6918,  6918,  1707,  1054,  1708,  1054,  1711,  1054, -1337,
    1713,  6918,  6918,  6918,  6918,  5042,  1714,  5042,   869, -1337,
    7560,  7588, -1337,  2862, -1337,  2949, -1337,  3087, -1337,  7616,
    7644,  7672,  7700, -1337, -1337,   870, -1337,  1716,  1717,  1718,
    1720,  1721,  1722, -1337, -1337, -1337, -1337,  5042,  1723, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   247,     0,     0,     0,   243,     0,
       0,     0,     0,   342,   343,   344,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    20,    11,    12,    13,    14,
      19,    18,    15,    16,    17,     0,    21,   515,     0,   391,
     514,   489,   392,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
       0,   507,   493,   398,   399,   400,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   395,   396,   397,   492,     0,
       0,     0,     0,    66,    67,     0,     0,   187,     0,     0,
       0,   349,     0,   485,   515,   404,     0,     0,     0,     0,
     227,     0,   229,   230,   225,   226,     0,   231,   232,   109,
     117,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   426,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   514,     0,
     187,   515,     0,     0,   339,     0,     0,     0,     0,     0,
       0,     0,     0,   514,   444,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   466,   467,   437,   443,     0,   438,
     515,   404,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,   223,   224,     0,   514,     0,     0,   241,   242,
       0,   187,     0,   187,   514,     0,     0,     0,   345,     0,
       0,    66,    67,     0,     0,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,   351,   353,     0,     0,     0,     0,
       0,     0,     0,   186,     0,   185,     0,    68,    69,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,   216,     0,
       0,   412,   164,     0,   514,     0,   485,   486,     0,     0,
     510,     0,   107,   107,     0,     0,     0,     0,   473,   474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,   307,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   187,
       0,   428,   427,     0,     0,     0,     0,   187,   187,     0,
       0,     0,     0,     0,     0,     0,   257,     0,   187,     0,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,   205,   340,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,     0,   450,     0,     0,
     451,     0,   452,     0,   453,     0,     0,     0,     0,     0,
       0,   351,   445,     0,   439,     0,     0,     0,   317,    66,
      67,     0,   222,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,   245,   244,   210,     0,   211,     0,     0,
     235,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,   417,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   401,   508,     0,     0,     0,     0,     0,     0,
       0,     0,   350,     0,    59,     0,     0,     0,     0,     0,
     182,     0,     0,     0,     0,   188,     0,     0,    59,     0,
       0,   367,   366,   364,   365,   360,   362,   361,   363,   355,
     354,   356,   357,   358,   359,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,   337,   338,     0,     0,     0,
       0,   305,     0,     0,     0,   132,   133,     0,   135,   136,
       0,   138,   139,     0,   141,   142,     0,     0,     0,     0,
       0,     0,     0,   152,   187,     0,     0,     0,     0,     0,
     430,   429,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,   320,
       0,     0,   206,     0,     0,   202,     0,     0,     0,   335,
     334,     0,     0,     0,     0,   417,     0,   468,     0,     0,
       0,     0,     0,     0,   454,     0,   455,     0,   456,     0,
     457,     0,     0,   350,   440,   447,     0,   356,   446,     0,
     469,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,   212,   214,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    74,     0,   406,   405,   419,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   390,   378,
       0,   380,   381,   382,   383,   384,   385,   386,     0,     0,
       0,   501,     0,   504,   497,   498,   499,     0,     0,     0,
       0,     0,   502,   425,   506,   121,   126,    99,     0,   494,
     496,     0,   403,   409,   410,   490,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,   411,     0,
       0,     0,     0,   512,     0,     0,     0,    44,     0,     0,
       0,    57,     0,    35,    36,    37,    38,    39,   408,   407,
       0,   487,    24,    22,     0,     0,    25,     0,     0,   217,
     511,    70,   110,    71,   118,     0,     0,     0,   475,   476,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   308,
     306,     0,   316,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,   215,     0,     0,     0,   177,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,     0,   248,     0,     0,     0,     0,     0,
       0,   310,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,     0,   470,     0,   449,     0,     0,
       0,     0,     0,     0,     0,   441,     0,     0,     0,     0,
       0,     0,     0,     0,   207,     0,     0,     0,     0,   209,
       0,     0,   346,     0,     0,     0,     0,   513,     0,     0,
       0,   414,     0,   413,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,    84,    89,    91,     0,     0,
     483,     0,    97,     0,     0,     0,     0,     0,    75,   368,
       0,     0,     0,     0,     0,    30,   416,   415,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
     314,     0,     0,   134,     0,   137,     0,   140,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,     0,   291,
       0,   297,     0,   299,     0,   293,     0,   295,     0,   258,
     287,     0,     0,     0,   200,     0,     0,     0,   321,     0,
     204,   203,   341,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,   458,   459,   460,   461,   448,   442,
       0,     0,     0,     0,   480,     0,     0,     0,   236,     0,
       0,     0,     0,     0,    87,     0,    86,     0,    76,   219,
     418,   218,   379,   387,   388,   389,   505,     0,   422,   423,
     424,     0,     0,   402,   122,     0,   509,   127,   421,   495,
      78,    59,     0,     0,     0,     0,    77,     0,     0,     0,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,     0,     0,    26,    27,     0,    28,     0,     0,   111,
     114,    72,    73,   148,     0,     0,     0,     0,     0,     0,
     151,     0,     0,   167,   168,     0,     0,   153,   174,     0,
       0,     0,     0,   144,     0,   313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,   187,   187,     0,   268,     0,   270,     0,   272,
       0,   437,     0,     0,   298,   300,   294,   296,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,     0,   418,   471,     0,     0,     0,     0,   472,   156,
     157,     0,     0,     0,     0,   100,   104,     0,     0,   347,
      80,    79,     0,   420,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    95,     0,   484,   189,   190,   191,
     192,     0,     0,    40,     0,     0,     0,     0,     0,    42,
     488,     0,     0,   112,   115,     0,     0,   147,   154,   155,
     159,     0,     0,   169,     0,     0,   315,     0,   162,     0,
       0,   304,   173,   149,   161,   172,   176,   160,     0,   170,
     175,     0,     0,     0,     0,     0,     0,   434,     0,   433,
       0,     0,     0,   259,     0,     0,   260,     0,     0,   261,
       0,     0,     0,     0,     0,     0,     0,   199,     0,     0,
     198,     0,     0,     0,   193,     0,     0,    33,     0,     0,
       0,     0,     0,     0,   478,     0,   238,   237,     0,     0,
       0,     0,     0,   500,   503,     0,   123,   125,     0,   128,
     129,   130,    90,    92,     0,    98,     0,    81,    45,     0,
       0,     0,   436,     0,     0,     0,    29,     0,   121,   126,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
     311,   311,     0,   105,   106,   187,     0,   180,   181,     0,
       0,     0,     0,     0,     0,     0,   288,     0,     0,   187,
       0,     0,     0,     0,     0,   184,   183,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,     0,    82,     0,
     473,     0,     0,   482,     0,    41,     0,     0,     0,    43,
      58,     0,     0,     0,   329,   331,   330,   332,   333,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   302,     0,     0,     0,   253,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,   477,   239,
       0,   348,     0,   124,     0,   131,    96,     0,     0,     0,
       0,     0,   113,   116,     0,     0,     0,     0,     0,   312,
     322,     0,     0,   323,     0,   178,     0,   274,     0,     0,
     276,     0,     0,   278,     0,     0,     0,   289,     0,   249,
       0,   187,     0,     0,     0,     0,     0,     0,     0,   158,
     103,     0,   119,     0,    49,     0,    55,     0,     0,     0,
     145,   171,     0,   326,     0,   327,   328,   431,   262,     0,
       0,   269,   263,     0,     0,   271,   264,     0,     0,   273,
       0,     0,     0,   255,     0,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,   282,     0,   284,   290,   301,   254,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   120,
      46,     0,    53,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   266,     0,     0,   267,     0,     0,   201,     0,
     195,     0,     0,     0,     0,     0,    47,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,   275,     0,   277,     0,   279,     0,   196,     0,
       0,     0,     0,    48,    50,     0,    51,     0,     0,     0,
       0,     0,     0,   462,   463,   464,   465,     0,     0,    56,
     324,   325,   281,   283,   285,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1337, -1337, -1337, -1337,   621, -1337, -1337, -1337, -1337,   104,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,  -346,   -66,   959,    -4, -1337,  1229, -1337, -1337,
   -1337, -1337, -1337,   225, -1337,   226, -1337, -1337, -1337, -1337,
   -1337, -1337,   615,  1731,    -2,  -491,  -243, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,  1734, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,  -994,  -935,
   -1337, -1337,  1276, -1337,   230, -1337, -1337, -1337, -1337,  1605,
   -1337, -1337,   262, -1337, -1336,  2271,  -102,  2392,   763,  -238,
     497, -1337,    89,    13, -1337,  -368,    -3,    53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    89,   924,    90,    91,   675,  1392,  1398,
     913,  1100,  1564,  1765,   914,  1714,  1805,   915,  1767,   916,
     917,  1104,   342,   431,   179,   410,    92,   690,   442,  1508,
    1509,   443,  1559,  1075,  1244,  1076,  1247,   724,   727,   730,
     733,  1420,  1287,   655,   294,   404,   405,    95,    96,    97,
      98,    99,   100,   101,   295,  1005,  1660,  1731,   759,  1444,
    1447,  1450,  1689,  1693,  1697,  1750,  1753,  1756,  1001,  1002,
    1139,   961,   721,   768,  1586,   103,   104,   105,   106,   296,
     181,   875,   492,   252,  1269,   297,   298,   299,   555,   308,
     897,  1091,   440,   436,   876,   441,   184,   301
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,    94,   619,   309,   621,   487,   752,   753,  1461,   518,
     344,  1182,  1377,   630,   907,   506,   268,  1171,   214,   183,
     537,   315,   922,   306,   187,   658,   540,   521,  1283,   209,
    1173,   542,   260,   895,   239,   209,   214,   240,   320,   322,
     794,   796,   343,   798,   800,   544,   402,   190,   398,  1175,
     205,  1177,   645,   509,   271,  1676,   108,   206,   328,   185,
     510,  1047,   300,     4,   659,   273,  1180,   274,   205,   495,
     496,   340,   341,   495,   496,   899,   271,     5,   576,  1198,
     578,  1516,  1683,   495,   496,  1324,  1274,  1325,   992,  1326,
     658,  1327,   316,   319,   201,   182,   202,  1685,   243,   993,
     497,   261,   495,   496,   335,   262,   186,   994,   995,   996,
     272,   244,   245,   997,   998,   999,  1000,   263,   644,   188,
    1162,   466,   467,   468,   340,   341,   471,   472,   473,   189,
     495,   496,   317,   192,   275,  -486,  1172,   908,   909,   910,
     911,   658,    48,    49,    50,    51,  1328,   193,  1329,  1174,
     407,    56,   408,  1251,    59,   538,   409,  1378,   269,  1081,
     194,   541,   514,   515,   195,   217,   543,  1568,  1176,   331,
    1178,   332,   902,   271,   196,   403,   527,   528,   333,    88,
     545,   399,   400,  1582,    88,   271,   271,   336,   337,   338,
     339,   310,  1179,   271,   278,   197,   923,   279,   345,   519,
     346,   271,   347,   300,   495,   496,   178,   178,   300,   198,
     912,   270,   300,   215,   539,   300,   444,   210,   307,   300,
     300,   300,   300,   210,   211,   300,   300,   300,   896,   401,
     900,   901,   321,   323,   795,   797,   218,   799,   801,   300,
     191,   437,   437,   832,   329,   745,   746,  1180,  1677,   437,
    1048,   330,   336,   337,   338,   339,   199,   445,   495,   496,
     923,   300,   300,   300,   200,   761,   336,   337,   338,   339,
     207,   340,   341,   495,   496,   300,   300,   435,   438,   888,
     336,   337,   338,   339,   228,   340,   341,   229,   300,   230,
     300,   208,  1082,  1083,   495,   496,   886,   889,   688,   340,
     341,   689,   212,   336,   337,   338,   339,   407,   213,   408,
     747,   251,   253,   588,   259,   336,   337,   338,   339,   247,
     248,   216,   340,   341,   271,   816,   300,   300,   217,   249,
     589,   429,   646,   430,   340,   341,   250,   221,   823,   300,
     333,  1716,   495,   496,   495,   496,   255,   219,   590,   256,
     495,   496,   257,   220,   340,   341,   407,   226,   408,   498,
     222,   508,   786,   315,   111,  -487,   754,   271,   271,   271,
     271,   271,   271,   300,   271,   271,   495,   496,   271,   271,
     437,   340,   341,   271,   271,   271,   271,   271,   232,   271,
     227,   233,   760,   629,   234,   556,   235,   633,   137,   138,
     139,   140,   141,   142,   640,   681,   300,   146,   147,   231,
     682,   340,   341,   149,   150,   151,   582,   264,   152,   265,
     495,   496,  -488,   437,   437,   437,   437,   437,   437,   157,
     437,   437,  1788,   241,   437,   437,  1158,   495,   496,   437,
     437,   437,   437,   639,   300,   641,   236,  1317,  1318,   237,
     345,   238,   579,  1181,   534,   247,   248,   495,   496,   178,
     620,   242,   622,   623,   624,   249,   626,   627,   495,   496,
     246,   631,   258,  1456,   266,   635,   636,   637,   638,   300,
     300,   254,  1053,  1055,  1529,   267,   495,   496,   726,   729,
     732,   735,  1366,  1367,   223,   403,   403,   224,   495,   496,
     225,   979,  1531,   495,   496,   407,   277,   408,   490,   491,
     683,   809,   160,   161,  1533,   684,   499,   495,   496,  1541,
     507,   300,   300,   300,   168,   276,    88,   169,   495,   496,
     838,   787,   280,   271,   495,   496,  1596,   559,  1599,   560,
    1602,   281,   495,   496,  1543,   546,   333,   300,   547,   691,
    1544,   548,   689,   549,   300,   303,   282,   810,  1648,   302,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   557,   424,   425,   495,   496,   887,   890,   426,   421,
     422,   423,   424,   425,   679,   300,   680,  1452,   426,   788,
    1651,   178,   304,   839,   840,   841,   842,   843,   844,   845,
     846,   847,   848,   849,   305,   851,   852,   853,   854,   855,
     856,   857,   992,   495,   496,   861,   863,   864,  1142,   312,
    1144,   686,  1146,   993,  1148,   872,   687,   874,   697,  1654,
     698,   994,   995,   996,   882,   495,   496,   997,   998,   999,
    1000,   314,   311,   495,   496,   898,   495,   496,   407,   992,
     408,  1662,   697,   687,   703,   313,   300,   891,  1090,  1664,
     993,  1180,  1719,   697,  1180,   707,  1702,  1180,   994,   995,
     996,  1475,   495,   496,   997,   998,   999,  1000,   697,   300,
     713,   300,   495,   496,   271,   992,   327,   271,  1720,   271,
     423,   424,   425,   300,   300,   373,   993,   426,  1733,   495,
     496,   374,   495,   496,   994,   995,   996,   936,  1583,  1584,
     997,   998,   999,  1000,  1585,  1771,  1340,   300,  1772,   838,
     697,   532,   804,   533,   826,   534,   827,  1748,   177,  1751,
     178,  1754,   375,   376,   411,  1252,   377,  1757,   300,   378,
     437,  1587,  1588,   932,   407,   437,   408,  1585,   381,   862,
     407,  1265,   408,  1649,   407,   697,   408,   750,   751,  1242,
     385,   386,  1054,  1056,   407,   491,   408,  1180,   873,  1245,
    1061,  1063,   880,   687,  1111,   387,   930,   881,   388,   697,
    1793,   934,  1795,   300,  1797,  1112,  1498,   390,   391,  1652,
     697,  1499,   300,   407,   300,   408,   300,   697,   300,   904,
     697,   428,   975,   300,   406,   697,   300,   976,   697,   697,
    1017,  1018,   697,  1180,  1019,   697,  1180,  1035,   697,  1180,
    1058,  1217,  1180,   300,  1118,  1124,  1119,  1125,   697,   300,
    1155,  1440,  1441,   697,   271,  1199,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
    1257,   427,  1106,  1107,   426,   697,   392,  1204,  1180,   300,
    1180,   432,  1180,  1476,   271,   300,   271,   271,   453,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   271,   458,
     464,  1372,   426,   697,  1074,  1205,   697,   697,  1206,  1207,
     437,   697,   697,  1209,  1210,   463,   300,   300,   300,   300,
    1097,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,  1259,   697,  1260,  1261,   426,
     437,   271,   437,   437,   469,   697,  1064,  1262,   697,   470,
    1263,  1115,  1116,   697,   437,  1264,   474,   482,   300,   300,
     697,   300,  1301,   300,   300,   485,   475,   300,   300,  1396,
     476,  1397,   300,  1428,   488,  1429,  1070,  1063,  1072,  1073,
     697,   477,  1465,  1504,   697,  1505,  1520,   478,   479,   450,
    1078,   697,   480,  1521,   455,   481,   489,   437,   459,   511,
     203,   204,  1396,   512,  1542,   465,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
    1396,  1604,  1580,  1605,   426,   697,  1218,  1620,  1622,   982,
    1623,   500,   687,  1110,  1625,  1253,   988,  1396,  1242,  1630,
    1632,  1386,  1003,  1245,   992,  1633,  1396,   697,  1636,  1644,
     697,  1504,  1663,  1713,  1591,   993,   300,   300,   300,   697,
     697,  1732,  1734,   994,   995,   996,  1396,   300,  1743,   997,
     998,   999,  1000,   580,  1227,   697,  1785,  1780,  1786,   501,
     502,  1232,  1233,  1234,  1235,  1236,   334,  1396,  1817,  1807,
    1818,  1243,  1246,   513,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   517,
     300,   333,   520,   522,   523,   379,   380,   529,   524,   382,
     525,   526,   530,   531,   536,   383,   384,   558,   562,   300,
    1561,   389,   566,   568,   569,   300,   178,  1280,  1655,   573,
     574,   300,   575,   300,   300,   577,   587,   592,   300,   300,
     593,   300,   596,   300,   426,   300,   647,   300,   300,   300,
     992,   648,   650,   434,   111,   177,   693,   710,   694,   714,
     715,   993,   716,   742,  1373,   300,   719,   720,   743,   994,
     995,   996,   657,   744,   767,   997,   998,   999,  1000,   769,
     300,   770,   772,   779,   300,   780,   300,   785,   137,   138,
     139,   140,   141,   142,   789,  1353,   791,   146,   147,  1117,
     814,   817,   792,   149,   150,   151,  1358,   824,   152,   793,
     825,   833,   834,   865,   866,   879,   867,   868,   883,   157,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   271,   869,   870,   878,   426,   884,
     885,   893,   535,   894,   921,   739,   740,   926,   929,   931,
     933,  1163,  1164,  1165,  1375,   937,  1562,   992,   940,   561,
     941,   678,   300,   942,  1379,   944,   946,   945,   993,   947,
     949,   950,   271,   951,   955,   300,   994,   995,   996,   960,
     962,   964,   997,   998,   999,  1000,  1373,   776,   777,   778,
     437,  1404,   877,   965,   966,   968,  1607,   967,   969,   970,
     978,   971,   160,   161,  1012,   985,  1039,   986,  1025,  1026,
    1040,   300,   300,   802,   168,  1028,    88,   169,  1029,  1030,
     403,   403,  1041,  1052,  1042,  1080,  1374,  1085,   437,  1086,
    1089,  1435,  1050,  1088,  1092,  1098,  1103,   340,   341,   300,
    1101,   300,  1105,   300,  1102,  1062,  1109,  1114,  1122,  1128,
    1129,   831,  1133,  1134,  1136,  1137,  1140,  1156,   300,  1141,
     649,  1729,  1150,  1151,  1401,   300,  1152,  1153,  1154,   300,
    1166,  1484,  1170,   300,  1167,   992,  1169,  1168,  1183,  1184,
    1480,  1185,  1186,  1187,  1189,  1190,   993,  1191,  1192,  1487,
    1490,  1491,  1193,   300,   994,   995,   996,  1195,  1196,  1214,
     997,   998,   999,  1000,  1219,  1220,  1237,  1222,  1224,  1226,
    1228,  1229,  1230,  1231,   300,  1238,  1239,  1240,  1703,  1241,
    1249,  1254,  1255,  1266,  1273,     7,     8,  1271,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,  1272,  1339,  1276,   925,   426,   927,  1281,  1282,
     300,  1284,  1286,  1285,  1290,   300,  1291,  1293,  1294,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,  1297,  1298,   300,  1292,   426,  1299,  1773,
    1296,  1304,   300,  1314,  1305,   271,   651,    24,    25,   652,
      27,    28,   653,    30,   654,    32,  1315,    33,  1316,  1322,
     300,  1323,    38,    39,   977,    41,    42,    43,  1330,  1334,
    1335,    46,  1336,  1337,  1352,  1344,   300,  1345,  1359,   300,
    1360,  1349,  1361,   403,  1365,  1368,  1087,  1369,  1376,  1381,
    1382,  1384,  1417,  1387,  1388,   300,  1389,  1390,  1400,  1408,
     300,   437,  1409,  1410,  1413,    67,    68,    69,  1407,  1024,
    1415,  1419,  1416,  1418,  1422,  1423,  1424,  1425,  1031,  1426,
    1032,  1427,  1033,  1430,  1034,  1443,     7,     8,  1446,  1037,
    1449,  1457,  1038,  1460,  1464,  1453,  1467,  1483,  1492,  1496,
    1494,  1495,   300,  1497,  1503,  1506,  1442,  1515,  1445,  1518,
    1448,  1524,  1517,  1519,  1536,  1525,  1538,  1527,  1528,  1545,
    1551,   300,  1556,  1558,  1459,  1530,  1570,  1462,  1463,  1532,
    1563,   180,  1557,   775,  1574,  1534,  1539,  1575,  1576,  1577,
    1578,  1579,  1581,  1603,  1610,  1069,  1621,   651,    24,    25,
     652,    27,    28,   653,    30,   654,    32,  1672,    33,  1626,
    1627,  1640,  1643,    38,    39,  1634,    41,    42,    43,  1637,
    1657,  1670,    46,  1641,  1658,  1645,  1661,  1681,  1686,   300,
    1688,   300,  1093,  1094,  1095,  1096,  1691,  1692,  1695,  1696,
    1699,  1700,   692,  1705,   300,  1721,  1727,  1740,     7,     8,
    1723,  1725,  1741,  1749,  1752,  1755,    67,    68,    69,  1758,
    1760,   325,   326,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,  1768,  1769,  1789,
    1132,   426,  1774,  1792,  1794,  1776,  1778,  1796,  1135,  1798,
    1804,  1787,  1819,  1820,  1821,  1739,  1822,  1823,  1824,  1826,
     300,  1673,  1275,  1572,    93,  1573,  1288,   102,   271,   651,
      24,    25,   652,    27,    28,   653,    30,   654,    32,   722,
      33,  1589,  1383,     0,   821,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
       0,     0,   271,     0,   271,     0,     0,     0,     0,     0,
       0,  1595,   433,  1598,   437,  1601,   439,     0,    67,    68,
      69,     0,     0,  1609,     0,     0,  1612,     0,     0,     0,
     446,   448,   451,   452,   271,   454,   448,   456,   457,     0,
     448,   460,   461,     0,  1188,     0,     0,   448,     0,     0,
    1766,     0,     0,     0,     0,     0,     0,     0,   437,     0,
     437,     0,     0,     0,     0,   484,  1638,     0,     0,     0,
    1642,     0,     0,     0,   493,   494,     0,     0,     0,     0,
       0,     0,     0,   494,     0,     0,   822,     0,     0,     0,
     437,     0,     0,     0,  1803,     0,  1806,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,   551,   553,   448,  1682,
       0,     0,   992,  1684,     0,     0,  1825,     0,   563,   564,
     565,     0,   567,   993,     0,   570,   571,     0,     0,   572,
       0,   994,   995,   996,     0,     0,  1706,   997,   998,   999,
    1000,     0,     0,     0,     0,     0,   585,   586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,  1348,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,     0,     0,     7,
       8,  1746,  1747,     0,   628,     0,     0,     0,   632,     0,
     634,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   556,  1775,     0,     0,   426,
       0,   656,     0,     0,   448,     0,     0,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,     0,     0,   676,   677,     0,     0,     0,     0,
     651,    24,    25,   652,    27,    28,   653,    30,   654,    32,
       0,    33,   551,     0,     0,     0,    38,    39,   701,    41,
      42,    43,   556,   706,     0,    46,     0,     0,   711,   712,
       0,     0,     0,     0,   717,   718,     0,  1431,  1432,   723,
     725,   728,   731,   734,   736,   737,   738,   448,   448,     0,
       0,     0,     0,     0,     0,  1250,     0,     0,     0,    67,
      68,    69,     0,     0,     0,   755,   756,   757,   393,   394,
     758,     0,     0,     0,   762,   763,   764,   765,   766,     0,
       0,     0,   771,     0,   773,   774,     0,     0,     0,   448,
     448,   448,     0,     0,   781,   782,   783,   594,   784,     7,
       8,     0,     0,     0,   790,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   448,     0,     0,     0,     0,
       0,   805,   807,  1256,   676,   677,     0,   980,     0,     0,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   557,   424,   425,   784,     0,     0,     0,   426,     0,
       0,     0,   830,   448,     0,     0,     0,     0,   835,     0,
     651,    24,    25,   652,    27,    28,   653,    30,   654,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   696,   424,
     425,  1554,     0,     0,     0,   426,     0,     0,     0,     0,
     892,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,     0,     0,   920,  1590,     0,   448,     0,   448,
     928,     0,     0,     0,     0,     0,     0,     0,   935,     0,
       0,   807,   938,  1624,   556,     0,  1611,     0,     0,     0,
       0,     0,     0,     0,     0,   952,     0,     0,     0,     0,
       0,     0,     0,     0,   958,     0,     0,   981,     0,     0,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,   448,  1350,   426,     0,
       0,     0,     0,   983,   984,     0,     0,     0,     0,   987,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1370,  1011,     0,     0,  1013,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   448,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,   448,     0,   448,     0,   448,     0,     0,     0,
    1371,   448,     0,     0,   448,     0,     0,     0,     0,     0,
    1043,     0,  1045,  1046,     0,  1704,     0,  1707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,    24,    25,   652,    27,    28,   653,    30,   654,
      32,     0,    33,     0,     0,  1065,     0,    38,    39,     0,
      41,    42,    43,  1066,  1067,  1068,    46,   448,     0,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     696,   424,   425,  1077,     0,     0,     0,   426,     0,   462,
       0,  1079,     0,     0,  1084,     0,  1759,     0,     0,     0,
      67,    68,    69,     0,   448,   448,   448,   448,     0,     0,
       0,  1099,     0,   486,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,     0,     0,     0,   516,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,     0,     0,
     448,     0,     0,     0,     0,  1493,     0,     0,  1004,     0,
    1143,     0,  1145,     0,  1147,     0,  1149,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,   449,     0,
     583,   584,     0,   449,     0,     0,     0,   449,     0,     7,
       8,     0,     0,   591,   449,     0,     0,   992,     0,     0,
       0,     0,     0,     0,  1194,     0,     0,  1197,   993,     0,
       0,  1200,     0,  1201,  1202,  1203,   994,   995,   996,     0,
       0,  1208,   997,   998,   999,  1000,     0,   625,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1223,     0,
    1225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     651,    24,    25,   652,    27,    28,   653,    30,   654,    32,
       0,    33,     0,   552,     0,   449,    38,    39,     0,    41,
      42,    43,     0,     0,  1258,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1267,  1268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1277,  1279,
       0,  1777,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     7,     8,     0,     0,
     426,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,  1319,  1320,  1321,     0,   426,     0,     0,
       0,     0,     0,  1331,     0,  1333,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,  1338,     0,     0,     0,
       0,     0,     0,     0,   448,     0,     0,  1044,     0,     0,
       0,   449,     0,     0,     0,     0,     0,   651,    24,    25,
     652,    27,    28,   653,    30,   654,    32,     0,    33,     0,
    1362,  1363,  1364,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,   552,
       0,  1523,     0,     0,   651,    24,    25,   652,    27,    28,
     653,    30,   654,    32,     0,    33,     0,  1380,     0,   992,
      38,    39,  1555,    41,    42,    43,    67,    68,    69,    46,
     993,  1393,     0,     0,   449,   449,  1399,     0,   994,   995,
     996,     0,     0,     0,   997,   998,   999,  1000,     0,  1405,
    1406,     0,     0,     0,     0,     0,  1411,  1412,     0,     0,
       0,  1414,     0,    67,    68,    69,     0,     0,     0,  1421,
       0,     0,     0,     0,     0,     0,   449,   449,   449,   448,
     448,  1433,     0,  1434,     0,     0,     0,     0,     0,     0,
     905,     0,     0,     0,  1049,  1451,     0,     0,     0,     0,
       0,     0,   449,  1669,     0,     0,     0,   448,     0,   808,
       0,   448,     0,     0,  1466,     0,     0,     0,   992,  1468,
    1469,  1470,  1471,  1779,     0,     0,     0,     0,     0,   993,
       0,  1157,  1479,     0,     0,     0,     0,   994,   995,   996,
     449,     0,  1489,   997,   998,   999,  1000,     0,     0,     0,
    1728,   959,     0,     0,     0,     0,     0,     0,     0,  1500,
    1501,     0,     0,     0,     0,     0,     0,  1507,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,     0,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,  1526,     0,   992,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,   993,     0,     0,     0,
       0,  1540,  1810,   551,   994,   995,   996,     0,     0,     0,
     997,   998,   999,  1000,   449,     0,   449,     0,  1552,     0,
    1553,     0,     0,   448,     0,     0,     0,     0,   808,   939,
    1560,     0,     0,     0,     0,     0,     0,  1051,     0,     0,
       0,     0,     0,  1059,  1565,     0,     0,     0,     0,  1569,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,   448,   426,     0,
       0,     0,     0,   449,  1594,     0,  1597,     0,  1600,  1071,
       0,     0,     0,     0,     0,     0,     0,     0,   448,  1811,
       0,     0,  1613,  1614,  1615,  1616,  1617,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,  1628,  1629,     0,     0,   426,  1631,     0,   449,     0,
       7,     8,  1712,   992,     0,     0,  1635,   449,     0,   449,
       0,   449,     0,   449,   993,     0,     0,  1646,   449,     0,
       0,   449,   994,   995,   996,     0,     0,     0,   997,   998,
     999,  1000,  1120,  1121,     0,  1123,     0,  1126,  1127,     0,
       0,  1130,  1131,     0,     0,     0,     0,  1671,     0,     0,
       0,     0,  1399,     0,     0,     0,     0,     0,     0,  1679,
       0,   651,    24,    25,   652,    27,    28,   653,    30,   654,
      32,     0,    33,  1690,   449,     0,  1694,    38,    39,  1698,
      41,    42,    43,  1701,     0,     0,    46,   448,     0,   448,
    1708,  1709,  1710,  1711,     0,     0,     0,     0,     0,     0,
    1715,   111,     0,  1717,     0,     0,     0,  1812,     0,     0,
       0,   449,   449,   449,   449,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
    1211,  1212,  1213,     0,     0,   137,   138,   139,   140,   141,
     142,  1221,     0,  1745,   146,   147,     0,     0,     0,     0,
     149,   150,   151,     0,     0,   152,     0,     0,   448,     0,
    1761,  1762,  1763,  1764,     0,     0,   157,   449,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,  1659,     0,
       0,     0,     0,     0,  1270,     0,  1790,  1791,     0,     0,
       0,     0,     0,     0,     0,   818,  1799,  1800,  1801,  1802,
       0,     0,     0,  1289,     0,     0,     0,     0,     0,  1295,
       0,     0,     0,     0,     0,  1300,     0,  1302,  1303,     0,
       0,     0,  1306,  1307,     0,  1308,     0,  1309,   906,  1310,
       0,  1311,  1312,  1313,     0,     0,     0,     0,     0,   160,
     161,     0,     0,     0,     0,     0,     0,     0,     0,  1332,
       0,   168,     0,     0,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1343,     0,     0,     0,  1347,     0,
       0,   109,   110,   111,     0,     0,     0,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,  1036,
       0,     0,   149,   150,   151,     0,     0,   152,     0,   153,
     154,   155,     0,     0,     0,     0,     0,   156,   157,     0,
       0,     0,     0,     0,     0,     0,  1391,     0,     0,     0,
       0,     0,     0,  1216,     0,     0,     0,     0,     0,  1403,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,     0,   426,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,   158,     0,     0,     0,     0,     0,
     159,   160,   161,   162,     0,  1270,     0,     0,   163,   164,
     165,   166,   167,   168,     0,    88,   169,     0,     0,     0,
       0,     0,  1472,     0,     0,     0,     0,     0,     0,  1481,
     170,   171,     0,  1482,     0,   172,     0,  1486,     0,     0,
     173,     0,   174,     0,   175,   176,     0,   177,     0,   178,
       0,     0,     0,     0,     0,     0,     0,  1502,     0,     0,
       0,     0,     0,     0,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,  1270,     0,
       0,     0,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   449,   449,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,  1537,     0,   426,     0,     0,   109,
     283,     0,     0,     0,   449,   112,   113,   114,   449,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   285,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,  1270,     0,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,   155,
    1270,     0,     0,     0,     0,   156,     0,     0,     0,   286,
       0,     0,   287,     0,     0,   288,     0,   289,     0,  1606,
       0,     0,     0,     0,     0,     0,     0,  1138,     0,   290,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     552,     0,     0,     0,   426,     0,  1639,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,     0,     0,     0,     0,  1656,     0,   449,   159,     0,
       0,   162,     0,     0,     0,     0,   163,   164,   165,   166,
     167,     0,     0,    88,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   503,  1458,
       0,     0,   426,   172,   449,     0,     0,     0,   505,     0,
       0,     0,     0,   176,     0,   250,   554,     0,     0,     0,
       0,     0,     0,     0,     0,   449,     0,     0,     0,     0,
       0,     0,     0,   109,   283,     0,     0,     0,  1270,   112,
     113,   114,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   285,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,     0,     0,
     148,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,   153,   154,   155,     0,     0,     0,     0,     0,   156,
       0,     0,     0,   286,     0,     0,   287,     0,     0,   288,
       0,   289,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,     0,  1270,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   449,     0,   449,   651,    24,    25,
     652,    27,    28,   653,    30,   654,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,     0,   162,     0,     0,     0,     0,
     163,   164,   165,   166,   167,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,   170,   447,     0,   449,     0,   172,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   176,     0,     0,
     554,   109,   283,   111,     0,     0,     0,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   285,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,     0,   149,   150,   151,     0,     0,   152,     0,   153,
     154,   155,     0,     0,     0,     0,     0,   156,   157,     0,
       0,   286,     0,     0,   287,     0,     0,   288,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1438,     0,  1439,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,   161,   162,     0,     0,     0,     0,   163,   164,
     165,   166,   167,   168,     0,    88,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   291,     0,     0,     0,   172,     0,     0,     0,     0,
     292,     0,   109,   283,   111,   176,     0,   293,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   285,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,   149,   150,   151,     0,     0,   152,     0,
     153,   154,   155,     0,     0,     0,     0,     0,   156,   157,
       0,     0,   286,     0,     0,   287,     0,     0,   288,     0,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,     0,     0,     0,     0,     0,  1473,     0,  1474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,   162,     0,     0,     0,     0,   163,
     164,   165,   166,   167,   168,     0,    88,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   291,     0,     0,     0,   172,     0,     0,     0,
       0,   292,     0,   109,   324,   111,   176,     0,  1485,   112,
     113,   114,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,     0,   149,   150,   151,     0,     0,   152,
       0,   153,   154,   155,     0,   109,   324,   111,     0,   156,
     157,   112,   113,   114,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,   149,   150,   151,     0,
       0,   152,     0,   153,   154,   155,     0,     0,     0,     0,
       0,   156,   157,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,   159,   160,   161,   162,     0,     0,     0,   581,
     163,   164,   165,   166,   167,   168,     0,    88,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,     0,     0,     0,   172,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   176,     0,  1278,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   159,   160,   161,   162,   426,     0,
     642,     0,   163,   164,   165,   166,   167,   168,     0,    88,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   171,     0,     0,     0,   172,
       0,     0,     0,     0,   292,     0,   109,   324,   111,   176,
       0,  1478,   112,   113,   114,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     7,     8,     0,   149,   150,   151,
       0,     0,   152,     0,   153,   154,   155,     0,     0,     0,
       0,     0,   156,   157,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,     0,     0,     0,     0,     0,  1592,
       0,  1593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   651,    24,    25,   652,    27,
      28,   653,    30,   654,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   159,   160,   161,   162,   426,
       0,   695,     0,   163,   164,   165,   166,   167,   168,     0,
      88,   169,     0,     0,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   171,     0,     0,     0,
     172,     0,     0,     0,     0,   292,     0,   109,   283,   284,
     176,     0,  1488,   112,   113,   114,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     285,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,   145,  1730,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,     0,     0,
       0,     0,     0,   156,     0,     0,     0,   286,     0,     0,
     287,     0,     0,   288,     0,   289,   434,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,   137,   138,   139,   140,   141,   142,     0,     0,     0,
     146,   147,     0,     0,     0,     0,   149,   150,   151,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,     0,   159,     0,     0,   162,
       0,     0,     0,     0,   163,   164,   165,   166,   167,     0,
       0,    88,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   170,   291,     0,     0,
     426,   172,   803,     0,     0,     0,   292,   748,   109,   283,
    1341,   176,     0,   293,   112,   113,   114,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   285,     0,     0,     0,   160,   161,     0,     0,     0,
     143,   144,   145,     0,     0,   148,     0,   168,     0,    88,
     169,     0,     0,     0,     0,     0,   153,   154,   155,     0,
       0,     0,     0,     0,   156,     0,     0,     0,   286,     0,
       0,   287,     0,     0,   288,     0,   289,   318,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   146,   147,     0,     0,     0,     0,   149,   150,   151,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,     0,     0,     0,   159,     0,     0,
     162,     0,     0,     0,     0,   163,   164,   165,   166,   167,
       0,     0,    88,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   170,   291,     0,
       0,   426,   172,     0,     0,     0,     0,   292,   685,   109,
     283,     0,   176,     0,  1342,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   285,     0,     0,     0,   160,   161,     0,     0,
       0,   143,   144,   145,     0,     0,   148,     0,   168,     0,
       0,   169,     0,     0,     0,     0,     0,   153,   154,   155,
       0,     0,     0,     0,     0,   156,     0,     0,     0,   286,
       0,     0,   287,     0,     0,   288,     0,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,   903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
       0,   162,     0,     0,     0,     0,   163,   164,   165,   166,
     167,     0,     0,    88,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   170,   291,
       0,     0,   426,   172,     0,     0,     0,     0,   292,   748,
     109,   283,     0,   176,     0,   293,   112,   113,   114,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   285,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,     0,     0,     0,     0,     0,   156,     0,     0,     0,
     286,     0,     0,   287,     0,     0,   288,     0,   289,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,     0,   426,     0,
       0,     0,     0,     0,     0,     0,     0,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,   162,     0,     0,     0,     0,   163,   164,   165,
     166,   167,     0,     0,    88,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   170,
     447,     0,     0,   426,   172,     0,     0,     0,     0,   292,
     749,   109,   283,     0,   176,     0,   550,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   285,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,     0,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,     0,     0,     0,     0,     0,   156,     0,     0,
       0,   286,     0,     0,   287,     0,     0,   288,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,  1007,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,     0,     0,   162,     0,     0,     0,     0,   163,   164,
     165,   166,   167,     0,     0,    88,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     170,   447,     0,     0,   426,   172,     0,     0,     0,     0,
     292,   815,   109,   283,     0,   176,     0,   806,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   285,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   155,     0,     0,     0,     0,     0,   156,     0,
       0,     0,   286,     0,     0,   287,     0,     0,   288,     0,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,     0,     0,     0,     0,     0,     0,     0,  1027,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,     0,     0,   162,     0,     0,     0,     0,   163,
     164,   165,   166,   167,     0,     0,    88,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   170,   291,     0,     0,   426,   172,     0,     0,     0,
       0,   292,   850,   109,   283,     0,   176,     0,  1346,   112,
     113,   114,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   285,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,     0,     0,     0,     0,     0,   156,
       0,     0,     0,   286,     0,     0,   287,     0,     0,   288,
       0,   289,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
    1057,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,     0,   162,     0,     0,     0,     0,
     163,   164,   165,   166,   167,     0,     0,    88,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   503,  1458,     0,     0,   426,   172,     0,     0,
       0,     0,   505,   858,   109,   324,     0,   176,     0,   250,
     112,   113,   114,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   324,   153,   154,   155,     0,   112,   113,   114,     0,
     156,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,     0,     0,     0,     0,     0,   156,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,   159,  1161,     0,   162,     0,     0,     0,
       0,   163,   164,   165,   166,   167,     0,     0,    88,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   170,   171,     0,     0,   426,   172,     0,
       0,     0,     0,   292,     0,     0,  1436,     0,   176,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,   162,     0,     0,     0,     0,   163,   164,   165,
     166,   167,     0,     0,    88,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   503,
     504,     0,     0,   426,   172,     0,     0,     0,     0,   505,
     859,   109,   324,   111,   176,     0,   250,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,     0,   149,   150,   151,     0,     0,   152,     0,   153,
     154,   155,     0,     0,     0,     0,     0,   156,   157,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,  1455,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,  1510,     0,     0,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
     159,   160,   161,   162,  1511,     0,     0,     0,   163,   164,
     165,   166,   167,   168,     0,    88,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171,     0,     0,     0,   172,   109,   283,     0,     0,
     292,     0,   112,   113,   114,   176,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   285,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,   155,     0,     0,     0,
       0,     0,   156,     0,     0,     0,   286,     0,     0,   287,
       0,     0,   288,     0,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
       0,     0,     0,  1512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,   162,     0,
       0,     0,     0,   163,   164,   165,   166,   167,     0,     0,
      88,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   170,   447,     0,     0,   426,
     172,   109,   324,     0,     0,   292,   860,   112,   113,   114,
     176,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,     0,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,     0,     0,     0,     0,     0,   156,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,     0,     0,
       0,     0,     0,     0,     0,  1513,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
       0,     0,     0,  1514,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
     159,     0,     0,   162,     0,     0,     0,     0,   163,   164,
     165,   166,   167,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,     0,
     170,   171,     0,     0,     0,   172,     0,    -4,    -4,    -4,
     292,     0,     0,    -4,    -4,   176,    -4,     0,     0,     0,
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
       0,     0,    -4,    -4,    11,    12,    13,     0,     0,     0,
      14,    15,     0,    16,     0,     0,     0,    17,    18,     0,
      19,    20,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,    63,    64,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,    66,    67,    68,    69,     0,     0,
      70,     0,    71,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,    87,
      88,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,  1546,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,  1608,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,  1618,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,  1619,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
    1647,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,  1650,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,  1653,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,  1680,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,  1687,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
    1722,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,  1724,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,  1726,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,  1744,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,  1770,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
    1808,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,  1809,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,  1813,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,  1814,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,  1815,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
    1816,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,   741,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,     0,     0,
       0,     0,     0,     0,  1522,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
     871,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,   989,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,   990,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,   991,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1022,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1113,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1159,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1160,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,  1215,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1354,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1355,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1356,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1357,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,  1394,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1395,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1402,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1547,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1548,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,  1549,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1550,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1566,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1567,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1571,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,  1665,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1666,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1667,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1668,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1675,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,  1678,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1718,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1735,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1736,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1737,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,  1738,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,     0,  1781,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
    1782,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,  1783,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,  1784,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,   407,     0,   408,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,     0,     0,   643,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,   820,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,     0,     0,   829,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,   837,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,     0,     0,
     919,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,     0,     0,  1015,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,     0,     0,  1016,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,     0,     0,  1020,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,     0,   426,     0,
       0,     0,  1021,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,     0,     0,  1023,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,     0,     0,  1060,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,     0,
       0,  1108,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,     0,     0,  1351,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,     0,     0,  1385,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,     0,     0,
    1535,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,   699,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,   700,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,   702,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,   704,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,   705,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,   708,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,   709,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,   803,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,   811,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,     0,   426,     0,
     812,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,   813,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,   819,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,   828,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,   836,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,   918,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,   943,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,   948,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,   953,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,   956,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,     0,   426,     0,
     957,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,   963,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,   972,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,   973,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,   974,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,  1006,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426,     0,  1008,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     0,     0,     0,     0,   426,     0,  1009,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,     0,     0,     0,     0,   426,     0,  1010,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,     0,     0,     0,     0,   426,     0,  1014,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,     0,     0,     0,     0,   426,     0,
    1248,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,     0,     0,     0,     0,   426,
       0,  1437,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     426,     0,  1454,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   426,     0,  1477,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,     0,     0,
       0,     0,   426,     0,  1674,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,     0,
       0,     0,     0,   426,     0,  1742,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
       0,     0,     0,     0,   426
};

static const yytype_int16 yycheck[] =
{
       3,     3,   370,     4,   372,   243,   497,   498,  1344,     4,
       4,  1005,     4,   381,     4,   258,     4,     6,     4,     6,
       5,     4,     6,     4,    79,     7,     5,   270,     6,     4,
       6,     5,     4,     4,    76,     4,     4,    79,     5,     5,
       5,     5,   108,     5,     5,     5,     4,     6,     4,     6,
     192,     6,   398,   192,    57,     6,     3,   199,     6,     6,
     199,     7,    65,     6,   410,     4,  1001,     6,   192,   182,
     183,   188,   189,   182,   183,   199,    79,     0,   321,   196,
     323,  1417,     6,   182,   183,   198,     6,   200,    96,   198,
       7,   200,    79,    80,   192,     6,   194,     6,   137,   107,
     199,    73,   182,   183,     7,    77,    13,   115,   116,   117,
      57,   150,   151,   121,   122,   123,   124,    89,     7,   192,
     200,   223,   224,   225,   188,   189,   228,   229,   230,   192,
     182,   183,    79,     6,    73,   199,   125,   127,   128,   129,
     130,     7,   100,   101,   102,   103,   198,     6,   200,   125,
     193,   109,   195,     7,   112,   140,   199,   149,   146,     4,
       6,   140,   264,   265,     6,   192,   140,  1503,   125,   192,
     125,   194,   199,   176,   192,   177,   278,   279,   201,   167,
     140,   137,   138,  1519,   167,   188,   189,   169,   170,   171,
     172,   192,   200,   196,    76,     6,   180,    79,   192,   194,
     194,   204,   196,   206,   182,   183,   201,   201,   211,     6,
     200,   199,   215,   199,   199,   218,   203,   192,   199,   222,
     223,   224,   225,   192,   199,   228,   229,   230,   199,   176,
     199,   199,   199,   199,   199,   199,    83,   199,   199,   242,
     199,   188,   189,   589,   192,   488,   489,  1182,   199,   196,
     196,   199,   169,   170,   171,   172,   194,   204,   182,   183,
     180,   264,   265,   266,   194,   508,   169,   170,   171,   172,
     192,   188,   189,   182,   183,   278,   279,   188,   189,   196,
     169,   170,   171,   172,    76,   188,   189,    79,   291,    81,
     293,   192,   137,   138,   182,   183,   642,   643,   195,   188,
     189,   198,   192,   169,   170,   171,   172,   193,   192,   195,
     198,    49,    50,   199,    52,   169,   170,   171,   172,   182,
     183,   192,   188,   189,   327,   568,   329,   330,   192,   192,
     334,   192,   398,   194,   188,   189,   199,     6,   581,   342,
     201,  1677,   182,   183,   182,   183,    73,    79,   335,    76,
     182,   183,    79,    79,   188,   189,   193,    79,   195,   199,
     199,   199,   199,     4,     5,   199,   198,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   182,   183,   381,   382,
     327,   188,   189,   386,   387,   388,   389,   390,    73,   392,
      79,    76,   198,   380,    79,     8,    81,   384,    39,    40,
      41,    42,    43,    44,   391,   193,   409,    48,    49,    81,
     198,   188,   189,    54,    55,    56,   327,    79,    59,    81,
     182,   183,   199,   370,   371,   372,   373,   374,   375,    70,
     377,   378,  1768,   192,   381,   382,   198,   182,   183,   386,
     387,   388,   389,   390,   447,   392,    76,     6,     7,    79,
     192,    81,   194,   198,   196,   182,   183,   182,   183,   201,
     371,    76,   373,   374,   375,   192,   377,   378,   182,   183,
     199,   382,   199,   198,    79,   386,   387,   388,   389,   482,
     483,   199,   828,   829,   198,    76,   182,   183,   475,   476,
     477,   478,     6,     7,    73,   497,   498,    76,   182,   183,
      79,   744,   198,   182,   183,   193,    79,   195,   246,   247,
     193,   199,   153,   154,   198,   198,   254,   182,   183,   198,
     258,   524,   525,   526,   165,    76,   167,   168,   182,   183,
     596,   535,     4,   536,   182,   183,  1530,   192,  1532,   194,
    1534,     4,   182,   183,   198,    73,   201,   550,    76,   195,
     198,    79,   198,    81,   557,   192,     4,   561,   198,     4,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   182,   183,   642,   643,   191,   182,
     183,   184,   185,   186,   194,   588,   196,   200,   191,   536,
     198,   201,   192,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   192,   609,   610,   611,   612,   613,
     614,   615,    96,   182,   183,   619,   620,   621,   964,     6,
     966,   193,   968,   107,   970,   629,   198,   631,   198,   198,
     200,   115,   116,   117,   638,   182,   183,   121,   122,   123,
     124,   194,   192,   182,   183,   649,   182,   183,   193,    96,
     195,   198,   198,   198,   200,     6,   659,   644,   896,   198,
     107,  1596,   198,   198,  1599,   200,  1660,  1602,   115,   116,
     117,     8,   182,   183,   121,   122,   123,   124,   198,   682,
     200,   684,   182,   183,   687,    96,   194,   690,   198,   692,
     184,   185,   186,   696,   697,   192,   107,   191,   198,   182,
     183,   192,   182,   183,   115,   116,   117,   694,   100,   101,
     121,   122,   123,   124,   106,   198,   200,   720,   198,   785,
     198,   192,   200,   194,   198,   196,   200,  1721,   199,  1723,
     201,  1725,   192,   192,     6,  1081,   192,  1731,   741,   192,
     687,   100,   101,   690,   193,   692,   195,   106,   192,   198,
     193,  1097,   195,   200,   193,   198,   195,   495,   496,   198,
       7,   192,   828,   829,   193,   503,   195,  1702,   193,   198,
     836,   837,   193,   198,   193,   192,   687,   198,   192,   198,
    1774,   692,  1776,   786,  1778,   193,   193,   192,   192,   200,
     198,   198,   795,   193,   797,   195,   799,   198,   801,   200,
     198,     6,   200,   806,   199,   198,   809,   200,   198,   198,
     200,   200,   198,  1748,   200,   198,  1751,   200,   198,  1754,
     200,     8,  1757,   826,    79,    79,    81,    81,   198,   832,
     200,  1322,  1323,   198,   837,   200,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
    1088,   199,   918,   919,   191,   198,   194,   200,  1793,   862,
    1795,     6,  1797,   200,   867,   868,   869,   870,   192,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   881,   192,
     199,  1227,   191,   198,   871,   200,   198,   198,   200,   200,
     837,   198,   198,   200,   200,   192,   899,   900,   901,   902,
     904,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   198,   198,   200,   200,   191,
     867,   924,   869,   870,   192,   198,   837,   200,   198,   192,
     200,   935,   936,   198,   881,   200,   192,   199,   941,   942,
     198,   944,   200,   946,   947,     4,   192,   950,   951,   198,
     192,   200,   955,     4,   199,     6,   867,  1023,   869,   870,
     198,   192,   200,   198,   198,   200,   200,   192,   192,   206,
     881,   198,   192,   200,   211,   192,   199,   924,   215,   192,
      21,    22,   198,   192,   200,   222,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     198,   198,   200,   200,   191,   198,   193,   200,   198,   747,
     200,   199,   198,   924,   200,  1081,   754,   198,   198,   200,
     200,  1259,   760,   198,    96,   200,   198,   198,   200,   200,
     198,   198,   200,   200,  1525,   107,  1039,  1040,  1041,   198,
     198,   200,   200,   115,   116,   117,   198,  1050,   200,   121,
     122,   123,   124,     6,  1058,   198,   198,   200,   200,   199,
     199,  1065,  1066,  1067,  1068,  1069,   107,   198,   198,   200,
     200,  1075,  1076,   192,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   192,
    1103,   201,   194,     6,     6,   146,   147,   194,   199,   150,
     199,   199,   194,   194,   194,   156,   157,     6,     6,  1122,
    1488,   162,   196,   199,   140,  1128,   201,  1114,   200,     6,
       6,  1134,     6,  1136,  1137,     6,   199,     6,  1141,  1142,
     194,  1144,     4,  1146,   191,  1148,   196,  1150,  1151,  1152,
      96,     7,   200,     4,     5,   199,   198,     7,   198,     6,
       6,   107,     6,   193,  1230,  1168,     7,     7,     6,   115,
     116,   117,   409,   199,     7,   121,   122,   123,   124,     6,
    1183,     7,     6,     6,  1187,     6,  1189,     4,    39,    40,
      41,    42,    43,    44,    51,  1199,    51,    48,    49,   937,
     137,   199,    51,    54,    55,    56,  1210,   195,    59,    51,
     193,     6,     6,   193,   193,   193,   198,   198,   193,    70,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,  1237,   198,   198,   198,   191,   193,
     195,     6,   283,     4,     4,   482,   483,     6,     6,     6,
       6,   989,   990,   991,  1241,     7,  1494,    96,   140,   300,
       7,     6,  1265,     7,  1251,     7,     7,   140,   107,     7,
     140,     7,  1275,     7,   199,  1278,   115,   116,   117,     4,
       6,   193,   121,   122,   123,   124,  1352,   524,   525,   526,
    1237,  1278,     6,   198,   193,   193,  1539,   198,   198,   193,
     196,   198,   153,   154,     6,   200,     7,   200,   195,   199,
       7,  1314,  1315,   550,   165,   199,   167,   168,   199,   199,
    1322,  1323,     7,     6,   196,     6,  1237,     6,  1275,     6,
     194,  1318,   199,     7,     6,     6,   199,   188,   189,  1342,
     192,  1344,     6,  1346,   192,   196,   180,     7,     7,     7,
      81,   588,     7,     7,     7,     7,     6,     4,  1361,     7,
     401,   200,     7,     7,  1275,  1368,     7,     7,     7,  1372,
       4,  1375,   192,  1376,     6,    96,     6,   199,     7,     6,
    1367,     7,     7,     7,   199,     6,   107,     6,     6,  1376,
    1377,  1378,    79,  1396,   115,   116,   117,     6,     6,     4,
     121,   122,   123,   124,     4,     4,   198,   200,     6,     6,
       6,     6,     4,     6,  1417,   193,   193,   193,  1661,   198,
     193,   196,     7,   192,     6,    12,    13,   199,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   196,  1181,     6,   682,   191,   684,     6,     6,
    1453,   199,    89,   199,     6,  1458,   199,     6,     6,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     6,     6,  1478,   199,   191,     5,   200,
     199,     4,  1485,   199,     6,  1488,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,   199,    84,     7,   199,
    1503,   199,    89,    90,   741,    92,    93,    94,   194,     6,
       6,    98,     6,     6,     4,   199,  1519,   199,     6,  1522,
       6,   199,   136,  1525,     6,   198,     6,     6,     4,     6,
       4,     6,   199,     6,     6,  1538,     6,     6,     4,     6,
    1543,  1488,     6,     6,     6,   132,   133,   134,  1286,   786,
       5,   140,     6,     6,     6,     6,     6,     6,   795,     6,
     797,     6,   799,     6,   801,     6,    12,    13,     6,   806,
       6,     6,   809,     6,     6,   198,     6,   193,     6,   196,
       7,     6,  1585,     6,   199,     6,  1324,     5,  1326,     6,
    1328,     6,    77,   199,     6,   199,     7,   200,   200,     6,
     135,  1604,     6,     6,  1342,   199,     6,  1345,  1346,   199,
     138,     6,   200,   200,     6,   199,   199,     6,     6,     6,
       6,     6,   199,     6,     6,   862,     6,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,  1624,    84,     6,
     199,     6,     6,    89,    90,   199,    92,    93,    94,   199,
       6,     6,    98,   199,    96,   200,   199,     6,     6,  1662,
       6,  1664,   899,   900,   901,   902,     6,     6,     6,     6,
       6,   200,   443,     6,  1677,   199,     6,     6,    12,    13,
     199,   199,   199,     6,     6,     6,   132,   133,   134,     6,
       6,    86,    87,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   199,     6,     6,
       6,   191,   199,     6,     6,   199,   199,     6,   955,     6,
       6,   199,     6,     6,     6,  1712,     6,     6,     6,     6,
    1733,  1627,  1111,  1508,     3,  1509,  1121,     3,  1741,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   473,
      84,  1521,  1255,    -1,   200,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,  1768,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,   174,
      -1,    -1,  1785,    -1,  1787,    -1,    -1,    -1,    -1,    -1,
      -1,  1529,   187,  1531,  1741,  1533,   191,    -1,   132,   133,
     134,    -1,    -1,  1541,    -1,    -1,  1544,    -1,    -1,    -1,
     205,   206,   207,   208,  1817,   210,   211,   212,   213,    -1,
     215,   216,   217,    -1,     6,    -1,    -1,   222,    -1,    -1,
    1741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1785,    -1,
    1787,    -1,    -1,    -1,    -1,   240,  1584,    -1,    -1,    -1,
    1588,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,   200,    -1,    -1,    -1,
    1817,    -1,    -1,    -1,  1785,    -1,  1787,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,   291,   292,   293,  1637,
      -1,    -1,    96,  1641,    -1,    -1,  1817,    -1,   303,   304,
     305,    -1,   307,   107,    -1,   310,   311,    -1,    -1,   314,
      -1,   115,   116,   117,    -1,    -1,  1664,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,   331,   332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,   346,  1189,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,    -1,    -1,    -1,    -1,    12,
      13,  1719,  1720,    -1,   379,    -1,    -1,    -1,   383,    -1,
     385,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     8,   200,    -1,    -1,   191,
      -1,   406,    -1,    -1,   409,    -1,    -1,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    84,   447,    -1,    -1,    -1,    89,    90,   453,    92,
      93,    94,     8,   458,    -1,    98,    -1,    -1,   463,   464,
      -1,    -1,    -1,    -1,   469,   470,    -1,  1314,  1315,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,   500,   501,   502,   503,   504,
     505,    -1,    -1,    -1,   509,   510,   511,   512,   513,    -1,
      -1,    -1,   517,    -1,   519,   520,    -1,    -1,    -1,   524,
     525,   526,    -1,    -1,   529,   530,   531,   532,   533,    12,
      13,    -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,
      -1,   556,   557,     6,   559,   560,    -1,   200,    -1,    -1,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   579,    -1,    -1,    -1,   191,    -1,
      -1,    -1,   587,   588,    -1,    -1,    -1,    -1,   593,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    84,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,  1478,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,   679,  1522,    -1,   682,    -1,   684,
     685,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   693,    -1,
      -1,   696,   697,     7,     8,    -1,  1543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   719,    -1,    -1,   200,    -1,    -1,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,   741,     6,   191,    -1,
      -1,    -1,    -1,   748,   749,    -1,    -1,    -1,    -1,   754,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,   767,    -1,    -1,   770,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   786,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     795,    -1,   797,    -1,   799,    -1,   801,    -1,    -1,    -1,
       6,   806,    -1,    -1,   809,    -1,    -1,    -1,    -1,    -1,
     815,    -1,   817,   818,    -1,  1662,    -1,  1664,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    -1,    -1,   850,    -1,    89,    90,    -1,
      92,    93,    94,   858,   859,   860,    98,   862,    -1,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   878,    -1,    -1,    -1,   191,    -1,   218,
      -1,   886,    -1,    -1,   889,    -1,  1733,    -1,    -1,    -1,
     132,   133,   134,    -1,   899,   900,   901,   902,    -1,    -1,
      -1,   906,    -1,   242,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,   266,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
     955,    -1,    -1,    -1,    -1,     6,    -1,    -1,   200,    -1,
     965,    -1,   967,    -1,   969,    -1,   971,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,   206,    -1,
     329,   330,    -1,   211,    -1,    -1,    -1,   215,    -1,    12,
      13,    -1,    -1,   342,   222,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,  1019,    -1,    -1,  1022,   107,    -1,
      -1,  1026,    -1,  1028,  1029,  1030,   115,   116,   117,    -1,
      -1,  1036,   121,   122,   123,   124,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1053,    -1,
    1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    84,    -1,   291,    -1,   293,    89,    90,    -1,    92,
      93,    94,    -1,    -1,  1089,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1101,  1102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,  1114,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    12,    13,    -1,    -1,
     191,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,  1158,  1159,  1160,    -1,   191,    -1,    -1,
      -1,    -1,    -1,  1168,    -1,  1170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,  1181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1189,    -1,    -1,   200,    -1,    -1,
      -1,   409,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,    -1,
    1215,  1216,  1217,    89,    90,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,     6,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    84,    -1,  1252,    -1,    96,
      89,    90,     6,    92,    93,    94,   132,   133,   134,    98,
     107,  1266,    -1,    -1,   482,   483,  1271,    -1,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,  1284,
    1285,    -1,    -1,    -1,    -1,    -1,  1291,  1292,    -1,    -1,
      -1,  1296,    -1,   132,   133,   134,    -1,    -1,    -1,  1304,
      -1,    -1,    -1,    -1,    -1,    -1,   524,   525,   526,  1314,
    1315,  1316,    -1,  1318,    -1,    -1,    -1,    -1,    -1,    -1,
     659,    -1,    -1,    -1,   200,  1330,    -1,    -1,    -1,    -1,
      -1,    -1,   550,     6,    -1,    -1,    -1,  1342,    -1,   557,
      -1,  1346,    -1,    -1,  1349,    -1,    -1,    -1,    96,  1354,
    1355,  1356,  1357,   200,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   200,  1367,    -1,    -1,    -1,    -1,   115,   116,   117,
     588,    -1,  1377,   121,   122,   123,   124,    -1,    -1,    -1,
       6,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1394,
    1395,    -1,    -1,    -1,    -1,    -1,    -1,  1402,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,  1438,    -1,    96,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,
      -1,  1456,   200,  1458,   115,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,   682,    -1,   684,    -1,  1473,    -1,
    1475,    -1,    -1,  1478,    -1,    -1,    -1,    -1,   696,   697,
    1485,    -1,    -1,    -1,    -1,    -1,    -1,   826,    -1,    -1,
      -1,    -1,    -1,   832,  1499,    -1,    -1,    -1,    -1,  1504,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,  1522,   191,    -1,
      -1,    -1,    -1,   741,  1529,    -1,  1531,    -1,  1533,   868,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1543,   200,
      -1,    -1,  1547,  1548,  1549,  1550,  1551,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,  1566,  1567,    -1,    -1,   191,  1571,    -1,   786,    -1,
      12,    13,     7,    96,    -1,    -1,  1581,   795,    -1,   797,
      -1,   799,    -1,   801,   107,    -1,    -1,  1592,   806,    -1,
      -1,   809,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,   941,   942,    -1,   944,    -1,   946,   947,    -1,
      -1,   950,   951,    -1,    -1,    -1,    -1,  1622,    -1,    -1,
      -1,    -1,  1627,    -1,    -1,    -1,    -1,    -1,    -1,  1634,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,  1648,   862,    -1,  1651,    89,    90,  1654,
      92,    93,    94,  1658,    -1,    -1,    98,  1662,    -1,  1664,
    1665,  1666,  1667,  1668,    -1,    -1,    -1,    -1,    -1,    -1,
    1675,     5,    -1,  1678,    -1,    -1,    -1,   200,    -1,    -1,
      -1,   899,   900,   901,   902,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1039,  1040,  1041,    -1,    -1,    39,    40,    41,    42,    43,
      44,  1050,    -1,  1718,    48,    49,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    59,    -1,    -1,  1733,    -1,
    1735,  1736,  1737,  1738,    -1,    -1,    70,   955,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,   200,    -1,
      -1,    -1,    -1,    -1,  1103,    -1,  1771,  1772,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,  1781,  1782,  1783,  1784,
      -1,    -1,    -1,  1122,    -1,    -1,    -1,    -1,    -1,  1128,
      -1,    -1,    -1,    -1,    -1,  1134,    -1,  1136,  1137,    -1,
      -1,    -1,  1141,  1142,    -1,  1144,    -1,  1146,     8,  1148,
      -1,  1150,  1151,  1152,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1168,
      -1,   165,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1183,    -1,    -1,    -1,  1187,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     8,
      -1,    -1,    54,    55,    56,    -1,    -1,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1265,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,  1278,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1189,    -1,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,    -1,  1344,    -1,    -1,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,  1361,    -1,    -1,    -1,    -1,    -1,    -1,  1368,
     182,   183,    -1,  1372,    -1,   187,    -1,  1376,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,    -1,   199,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1396,    -1,    -1,
      -1,    -1,    -1,    -1,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,  1417,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1314,  1315,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,  1453,    -1,   191,    -1,    -1,     3,
       4,    -1,    -1,    -1,  1342,     9,    10,    11,  1346,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,  1503,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
    1519,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    81,    -1,  1538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,   109,    -1,    -1,   112,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
    1458,    -1,    -1,    -1,   191,    -1,  1585,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1478,    -1,    -1,    -1,    -1,  1604,    -1,  1485,   152,    -1,
      -1,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,    -1,    -1,   167,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   182,   183,
      -1,    -1,   191,   187,  1522,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1543,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,  1677,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,  1768,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,
      -1,    -1,   112,    -1,  1662,    -1,  1664,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,
      -1,    -1,   182,   183,    -1,  1733,    -1,   187,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,
     200,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,   109,    -1,    -1,
     112,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
     192,    -1,     3,     4,     5,   197,    -1,   199,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    59,    -1,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,    -1,
      -1,   112,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,
      -1,   192,    -1,     3,     4,     5,   197,    -1,   199,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    59,
      -1,    61,    62,    63,    -1,     3,     4,     5,    -1,    69,
      70,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    59,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,   152,   153,   154,   155,    -1,    -1,    -1,   199,
     160,   161,   162,   163,   164,   165,    -1,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,   199,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   152,   153,   154,   155,   191,    -1,
     193,    -1,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,   192,    -1,     3,     4,     5,   197,
      -1,   199,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    12,    13,    -1,    54,    55,    56,
      -1,    -1,    59,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   152,   153,   154,   155,   191,
      -1,   193,    -1,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,    -1,    -1,    -1,
     187,    -1,    -1,    -1,    -1,   192,    -1,     3,     4,     5,
     197,    -1,   199,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,   200,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    79,    -1,    81,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,   152,    -1,    -1,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,    -1,
      -1,   167,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   182,   183,    -1,    -1,
     191,   187,   193,    -1,    -1,    -1,   192,   198,     3,     4,
       5,   197,    -1,   199,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,   153,   154,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    50,    -1,   165,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    79,    -1,    81,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,   109,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,   152,    -1,    -1,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
      -1,    -1,   167,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   182,   183,    -1,
      -1,   191,   187,    -1,    -1,    -1,    -1,   192,   198,     3,
       4,    -1,   197,    -1,   199,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,   153,   154,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    50,    -1,   165,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,   109,    -1,    -1,   112,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,    -1,    -1,   167,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   182,   183,
      -1,    -1,   191,   187,    -1,    -1,    -1,    -1,   192,   198,
       3,     4,    -1,   197,    -1,   199,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,   109,    -1,    -1,   112,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,    -1,    -1,   167,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   182,
     183,    -1,    -1,   191,   187,    -1,    -1,    -1,    -1,   192,
     198,     3,     4,    -1,   197,    -1,   199,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,   109,    -1,    -1,
     112,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,    -1,    -1,   167,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     182,   183,    -1,    -1,   191,   187,    -1,    -1,    -1,    -1,
     192,   198,     3,     4,    -1,   197,    -1,   199,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,    -1,
      -1,   112,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,    -1,    -1,   167,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   182,   183,    -1,    -1,   191,   187,    -1,    -1,    -1,
      -1,   192,   198,     3,     4,    -1,   197,    -1,   199,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,   109,
      -1,    -1,   112,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,    -1,    -1,   167,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   182,   183,    -1,    -1,   191,   187,    -1,    -1,
      -1,    -1,   192,   198,     3,     4,    -1,   197,    -1,   199,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    61,    62,    63,    -1,     9,    10,    11,    -1,
      69,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,   200,    -1,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,    -1,    -1,   167,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   182,   183,    -1,    -1,   191,   187,    -1,
      -1,    -1,    -1,   192,    -1,    -1,   200,    -1,   197,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,    -1,    -1,   167,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   182,
     183,    -1,    -1,   191,   187,    -1,    -1,    -1,    -1,   192,
     198,     3,     4,     5,   197,    -1,   199,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    -1,    -1,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   200,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,    -1,    -1,    -1,   187,     3,     4,    -1,    -1,
     192,    -1,     9,    10,    11,   197,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,   109,    -1,    -1,   112,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,    -1,    -1,
     167,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   182,   183,    -1,    -1,   191,
     187,     3,     4,    -1,    -1,   192,   198,     9,    10,    11,
     197,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
     152,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
     182,   183,    -1,    -1,    -1,   187,    -1,    51,    52,    53,
     192,    -1,    -1,    57,    58,   197,    60,    -1,    -1,    -1,
      64,    65,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,   118,   119,   120,     4,    -1,    -1,
      -1,    -1,   126,    -1,    -1,    12,    13,   131,   132,   133,
     134,    -1,    -1,   137,    -1,   139,    -1,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      37,    38,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    -1,    60,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,    -1,    -1,
     137,    -1,   139,    -1,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,   193,    -1,   195,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,   195,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,   195,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
     195,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,   195,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,   195,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,   195,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,   195,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,   195,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,   195,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,   195,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
     195,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,   193,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,   193,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,   193,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,   193,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,   193,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,   193,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,   193,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
     193,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,   193,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,   193,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,   193,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,   193,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,   193,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,   193,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,   193,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
     193,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,   193,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,   193,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,   193,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,   193,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,   193,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,   193,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,   193,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
     193,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,   193,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,   193,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,    -1,   193,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,   193,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,   193,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   203,   204,     6,     0,     4,    12,    13,    37,
      38,    51,    52,    53,    57,    58,    60,    64,    65,    67,
      68,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   107,   108,   109,   110,   111,   112,
     113,   114,   118,   119,   120,   126,   131,   132,   133,   134,
     137,   139,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   156,   157,   158,   159,   166,   167,   205,
     207,   208,   228,   245,   246,   249,   250,   251,   252,   253,
     254,   255,   256,   277,   278,   279,   280,   298,   299,     3,
       4,     5,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    54,
      55,    56,    59,    61,    62,    63,    69,    70,   146,   152,
     153,   154,   155,   160,   161,   162,   163,   164,   165,   168,
     182,   183,   187,   192,   194,   196,   197,   199,   201,   226,
     281,   282,   294,   295,   298,   299,    13,    79,   192,   192,
       6,   199,     6,     6,     6,     6,   192,     6,     6,   194,
     194,   192,   194,   226,   226,   192,   199,   192,   192,     4,
     192,   199,   192,   192,     4,   199,   192,   192,    83,    79,
      79,     6,   199,    73,    76,    79,    79,    79,    76,    79,
      81,    81,    73,    76,    79,    81,    76,    79,    81,    76,
      79,   192,    76,   137,   150,   151,   199,   182,   183,   192,
     199,   284,   285,   284,   199,    73,    76,    79,   199,   284,
       4,    73,    77,    89,    79,    81,    79,    76,     4,   146,
     199,   298,   299,     4,     6,    73,    76,    79,    76,    79,
       4,     4,     4,     4,     5,    36,    73,    76,    79,    81,
      93,   183,   192,   199,   246,   256,   281,   287,   288,   289,
     298,   299,     4,   192,   192,   192,     4,   199,   291,     4,
     192,   192,     6,     6,   194,     4,   295,   299,     4,   295,
       5,   199,     5,   199,     4,   281,   281,   194,     6,   192,
     199,   192,   194,   201,   226,     7,   169,   170,   171,   172,
     188,   189,   224,   225,     4,   192,   194,   196,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   192,   192,   192,   192,   192,   192,   226,
     226,   192,   226,   226,   226,     7,   192,   192,   192,   226,
     192,   192,   194,   281,   281,   281,   281,   281,     4,   137,
     138,   299,     4,   246,   247,   248,   199,   193,   195,   199,
     227,     6,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   191,   199,     6,   192,
     194,   225,     6,   281,     4,   294,   295,   299,   294,   281,
     294,   297,   230,   233,   295,   299,   281,   183,   281,   289,
     290,   281,   281,   192,   281,   290,   281,   281,   192,   290,
     281,   281,   287,   192,   199,   290,   288,   288,   288,   192,
     192,   288,   288,   288,   192,   192,   192,   192,   192,   192,
     192,   192,   199,   199,   281,     4,   287,   291,   199,   199,
     284,   284,   284,   281,   281,   182,   183,   199,   199,   284,
     199,   199,   199,   182,   183,   192,   248,   284,   199,   192,
     199,   192,   192,   192,   288,   288,   287,   192,     4,   194,
     194,   248,     6,     6,   199,   199,   199,   288,   288,   194,
     194,   194,   192,   194,   196,   226,   194,     5,   140,   199,
       5,   140,     5,   140,     5,   140,    73,    76,    79,    81,
     199,   281,   289,   281,   200,   290,     8,   184,     6,   192,
     194,   226,     6,   281,   281,   281,   196,   281,   199,   140,
     281,   281,   281,     6,     6,     6,   248,     6,   248,   194,
       6,   199,   294,   287,   287,   281,   281,   199,   199,   227,
     295,   287,     6,   194,   281,   281,     4,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   297,
     294,   297,   294,   294,   294,   287,   294,   294,   281,   295,
     297,   294,   281,   295,   281,   294,   294,   294,   294,   299,
     295,   299,   193,   195,     7,   224,   225,   196,     7,   226,
     200,    73,    76,    79,    81,   245,   281,   290,     7,   224,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   209,   281,   281,     6,   194,
     196,   193,   198,   193,   198,   198,   193,   198,   195,   198,
     229,   195,   229,   198,   198,   193,   184,   198,   200,   193,
     193,   281,   193,   200,   193,   193,   281,   200,   193,   193,
       7,   281,   281,   200,     6,     6,     6,   281,   281,     7,
       7,   274,   274,   281,   239,   281,   295,   240,   281,   295,
     241,   281,   295,   242,   281,   295,   281,   281,   281,   290,
     290,   199,   193,     6,   199,   248,   248,   198,   198,   198,
     284,   284,   247,   247,   198,   281,   281,   281,   281,   260,
     198,   248,   281,   281,   281,   281,   281,     7,   275,     6,
       7,   281,     6,   281,   281,   200,   290,   290,   290,     6,
       6,   281,   281,   281,   281,     4,   199,   227,   299,    51,
     281,    51,    51,    51,     5,   199,     5,   199,     5,   199,
       5,   199,   290,   193,   200,   281,   199,   281,   289,   199,
     227,   193,   193,   193,   137,   198,   248,   199,     8,   193,
     195,   200,   200,   248,   195,   193,   198,   200,   193,   195,
     281,   290,   224,     6,     6,   281,   193,   195,   225,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     198,   227,   227,   227,   227,   227,   227,   227,   198,   198,
     198,   227,   198,   227,   227,   193,   193,   198,   198,   198,
     198,   198,   227,   193,   227,   283,   296,     6,   198,   193,
     193,   198,   227,   193,   193,   195,   224,   225,   196,   224,
     225,   295,   281,     6,     4,     4,   199,   292,   227,   199,
     199,   199,   199,   200,   200,   287,     8,     4,   127,   128,
     129,   130,   200,   212,   216,   219,   221,   222,   193,   195,
     281,     4,     6,   180,   206,   290,     6,   290,   281,     6,
     294,     6,   299,     6,   294,   281,   295,     7,   281,   289,
     140,     7,     7,   193,     7,   140,     7,     7,   193,   140,
       7,     7,   281,   193,   200,   199,   193,   193,   281,   287,
       4,   273,     6,   193,   193,   198,   193,   198,   193,   198,
     193,   198,   193,   193,   193,   200,   200,   290,   196,   248,
     200,   200,   284,   281,   281,   200,   200,   281,   284,   198,
     198,   198,    96,   107,   115,   116,   117,   121,   122,   123,
     124,   270,   271,   284,   200,   257,   193,   200,   193,   193,
     193,   281,     6,   281,   193,   195,   195,   200,   200,   200,
     195,   195,   198,   195,   290,   195,   199,   200,   199,   199,
     199,   290,   290,   290,   290,   200,     8,   290,   290,     7,
       7,     7,   196,   281,   200,   281,   281,     7,   196,   200,
     199,   287,     6,   224,   225,   224,   225,   200,   200,   287,
     195,   225,   196,   225,   294,   281,   281,   281,   281,   290,
     294,   287,   294,   294,   295,   235,   237,   281,   294,   281,
       6,     4,   137,   138,   281,     6,     6,     6,     7,   194,
     291,   293,     6,   290,   290,   290,   290,   227,     6,   281,
     213,   192,   192,   199,   223,     6,   225,   225,   195,   180,
     294,   193,   193,   198,     7,   227,   227,   284,    79,    81,
     287,   287,     7,   287,    79,    81,   287,   287,     7,    81,
     287,   287,     6,     7,     7,   290,     7,     7,    96,   272,
       6,     7,   224,   281,   224,   281,   224,   281,   224,   281,
       7,     7,     7,     7,     7,   200,     4,   200,   198,   198,
     198,   200,   200,   284,   284,   284,     4,     6,   199,     6,
     192,     6,   125,     6,   125,     6,   125,     6,   125,   200,
     271,   198,   270,     7,     6,     7,     7,     7,     6,   199,
       6,     6,     6,    79,   281,     6,     6,   281,   196,   200,
     281,   281,   281,   281,   200,   200,   200,   200,   281,   200,
     200,   287,   287,   287,     4,   198,     8,     8,   193,     4,
       4,   287,   200,   281,     6,   281,     6,   227,     6,     6,
       4,     6,   227,   227,   227,   227,   227,   198,   193,   193,
     193,   198,   198,   227,   236,   198,   227,   238,   193,   193,
       6,     7,   224,   225,   196,     7,     6,   291,   281,   198,
     200,   200,   200,   200,   200,   224,   192,   281,   281,   286,
     287,   199,   196,     6,     6,   206,     6,   281,   199,   281,
     295,     6,     6,     6,   199,   199,    89,   244,   244,   287,
       6,   199,   199,     6,     6,   287,   199,     6,     6,     5,
     287,   200,   287,   287,     4,     6,   287,   287,   287,   287,
     287,   287,   287,   287,   199,   199,     7,     6,     7,   281,
     281,   281,   199,   199,   198,   200,   198,   200,   198,   200,
     194,   281,   287,   281,     6,     6,     6,     6,   281,   284,
     200,     5,   199,   287,   199,   199,   199,   287,   290,   199,
       6,   195,     4,   227,   198,   198,   198,   198,   227,     6,
       6,   136,   281,   281,   281,     6,     6,     7,   198,     6,
       6,     6,   224,   225,   294,   295,     4,     4,   149,   295,
     281,     6,     4,   292,     6,   195,   291,     6,     6,     6,
       6,   287,   210,   281,   198,   198,   198,   200,   211,   281,
       4,   294,   198,   287,   295,   281,   281,   284,     6,     6,
       6,   281,   281,     6,   281,     5,     6,   199,     6,   140,
     243,   281,     6,     6,     6,     6,     6,     6,     4,     6,
       6,   290,   290,   281,   281,   295,   200,   193,   198,   200,
     247,   247,   284,     6,   261,   284,     6,   262,   284,     6,
     263,   281,   200,   198,   193,   200,   198,     6,   183,   284,
       6,   286,   284,   284,     6,   200,   281,     6,   281,   281,
     281,   281,   287,   198,   200,     8,   200,   193,   199,   281,
     295,   287,   287,   193,   227,   199,   287,   295,   199,   281,
     295,   295,     6,     6,     7,     6,   196,     6,   193,   198,
     281,   281,   287,   199,   198,   200,     6,   281,   231,   232,
     200,   200,   200,   200,   200,     5,   286,    77,     6,   199,
     200,   200,   199,     6,     6,   199,   281,   200,   200,   198,
     199,   198,   199,   198,   199,   195,     6,   287,     7,   199,
     281,   198,   200,   198,   198,     6,   200,   198,   198,   198,
     198,   135,   281,   281,   290,     6,     6,   200,     6,   234,
     281,   297,   291,   138,   214,   281,   198,   198,   286,   281,
       6,   198,   235,   237,     6,     6,     6,     6,     6,     6,
     200,   199,   286,   100,   101,   106,   276,   100,   101,   276,
     290,   247,   198,   200,   281,   284,   270,   281,   284,   270,
     281,   284,   270,     6,   198,   200,   287,   248,   200,   284,
       6,   290,   284,   281,   281,   281,   281,   281,   200,   200,
     200,     6,   198,   200,     7,   200,     6,   199,   281,   281,
     200,   281,   200,   200,   199,   281,   200,   199,   284,   287,
       6,   199,   284,     6,   200,   200,   281,   200,   198,   200,
     200,   198,   200,   200,   198,   200,   287,     6,    96,   200,
     258,   199,   198,   200,   198,   198,   198,   198,   198,     6,
       6,   281,   295,   211,   193,   198,     6,   199,   198,   281,
     200,     6,   284,     6,   284,     6,     6,   200,     6,   264,
     281,     6,     6,   265,   281,     6,     6,   266,   281,     6,
     200,   281,   270,   248,   290,     6,   284,   290,   281,   281,
     281,   281,     7,   200,   217,   281,   286,   281,   198,   198,
     198,   199,   200,   199,   200,   199,   200,     6,     6,   200,
     200,   259,   200,   198,   200,   198,   198,   198,   198,   295,
       6,   199,   193,   200,   200,   281,   284,   284,   270,     6,
     267,   270,     6,   268,   270,     6,   269,   270,     6,   290,
       6,   281,   281,   281,   281,   215,   294,   220,   199,     6,
     200,   198,   198,   200,   199,   200,   199,   200,   199,   200,
     200,   198,   198,   198,   198,   198,   200,   199,   286,     6,
     281,   281,     6,   270,     6,   270,     6,   270,     6,   281,
     281,   281,   281,   294,     6,   218,   294,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   198,   200,     6,
       6,     6,     6,     6,     6,   294,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   202,   203,   203,   204,   204,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   206,   206,   207,   207,   207,   207,   207,   207,
     208,   208,   208,   208,   209,   209,   209,   209,   209,   209,
     210,   210,   211,   211,   213,   214,   212,   215,   215,   217,
     216,   218,   218,   220,   219,   221,   221,   223,   222,   224,
     224,   224,   224,   224,   225,   225,   226,   226,   227,   227,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   229,   229,   230,
     230,   230,   231,   230,   230,   232,   230,   233,   233,   234,
     234,   235,   235,   236,   236,   236,   237,   237,   238,   238,
     238,   238,   239,   239,   239,   240,   240,   240,   241,   241,
     241,   242,   242,   242,   243,   243,   244,   244,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   246,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   248,   248,   248,
     248,   248,   248,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   250,   250,   250,   250,   250,   251,   251,   252,
     253,   253,   253,   253,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   256,   256,
     256,   257,   256,   258,   256,   259,   256,   260,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   261,   256,
     262,   256,   263,   256,   264,   256,   265,   256,   266,   256,
     267,   256,   268,   256,   269,   256,   270,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   272,   272,   273,   273,   274,   274,   275,
     275,   276,   276,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   278,
     278,   278,   279,   279,   279,   280,   280,   280,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   284,   284,   284,   284,
     284,   285,   285,   285,   285,   286,   286,   287,   287,   287,
     287,   287,   287,   288,   288,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   290,   290,   290,   290,   291,   291,   291,
     291,   292,   292,   293,   293,   294,   294,   294,   294,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   296,   295,
     297,   297,   298,   298,   299,   299,   299
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
       8,     4,     4,     8,     4,     6,     4,     1,     0,     6,
       1,     3,     5,     5,     1,     1,     4
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
#line 4315 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 204 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 205 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4333 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4345 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4363 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4369 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4381 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4393 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4399 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4427 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4436 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4445 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4463 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4480 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4497 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4524 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4542 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4559 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4576 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 371 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 385 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4629 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4737 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4751 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 513 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 522 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 529 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4783 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 548 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 557 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 564 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4828 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 582 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4850 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4870 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4890 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 630 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4900 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 636 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4931 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 4961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 4967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 4973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 668 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 4982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 673 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 4992 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5056 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5089 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5122 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 797 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5131 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 802 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 807 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 812 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 817 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5169 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 824 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5180 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5199 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 846 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 851 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 856 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 861 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5235 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 866 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 875 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5255 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 881 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5265 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5287 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5309 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5322 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 947 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 952 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5353 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5377 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5401 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5416 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5428 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5454 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5481 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5511 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5533 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5549 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5565 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5578 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1162 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5597 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5617 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1189 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5636 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5650 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1205 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5660 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1213 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1219 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5679 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5694 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5712 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1273 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5735 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1290 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5758 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1326 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1334 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5810 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1344 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1352 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5837 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1362 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1370 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5864 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5891 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1404 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1408 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5921 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5948 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5984 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6008 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6030 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6055 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6077 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6111 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6145 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6167 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6189 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6219 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6241 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6263 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6299 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6321 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6364 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1804 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1810 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1816 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6395 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6424 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6453 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6474 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6497 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6534 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6570 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6592 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6613 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6633 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6669 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2067 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6678 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2072 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2077 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2082 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2087 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6714 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2115 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6751 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2131 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2132 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2137 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2141 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6791 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6818 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6845 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6872 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6899 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6924 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6954 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6978 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7003 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7027 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7143 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7166 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7208 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7315 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2639 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7338 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7357 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7389 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7405 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7418 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7431 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2742 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2748 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7464 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7477 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7490 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7503 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7516 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7576 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7598 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7619 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7638 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7661 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7677 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2956 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2960 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2965 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7733 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2972 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2977 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2983 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2988 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7771 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3002 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3006 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3010 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7808 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7866 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7878 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7899 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7920 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7946 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7972 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8011 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8023 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3212 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3218 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3225 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8067 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3232 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    }
#line 8075 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3236 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8082 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8094 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8106 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3269 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8128 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3283 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8150 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3297 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8172 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3311 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8194 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3317 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3325 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8216 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3332 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8227 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3346 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3353 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3367 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3381 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3388 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3394 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3401 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3407 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3414 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3420 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3427 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3433 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3440 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3446 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3453 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3459 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3466 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3479 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3485 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3492 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3498 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3509 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8500 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3512 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8507 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8523 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8547 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3574 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8582 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3578 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8590 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3582 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8606 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3590 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3596 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3602 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3606 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3610 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8650 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8658 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8681 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8701 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3668 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8726 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3688 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3692 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3697 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3701 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8776 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3707 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8792 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8852 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3844 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 8935 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9006 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9046 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9058 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9105 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9148 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9172 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9207 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9237 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9266 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9295 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9324 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9353 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9378 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9410 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4303 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4307 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9458 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9490 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9533 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9576 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9601 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9626 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4486 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9659 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9673 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9707 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4534 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4535 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4536 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4541 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9735 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9751 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9773 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4605 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4606 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9818 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4607 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9824 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4608 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4609 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4611 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9848 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4613 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4619 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9865 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4621 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9877 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4622 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4623 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4625 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 9901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4626 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 9907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4627 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 9913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 9919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4629 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 9925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 9931 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 9937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 9943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4633 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 9949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4634 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 9955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4635 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 9961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4636 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 9967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4637 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 9973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4638 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 9979 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4639 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 9985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4640 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 9991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4641 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 9997 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4642 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10015 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10027 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4660 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4661 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10075 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10087 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10099 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10111 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4669 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4674 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4676 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10142 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10163 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10185 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10207 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10229 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4781 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10270 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10286 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10307 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10329 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10351 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10373 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4891 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4896 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10413 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10427 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4921 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10450 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10465 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4946 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10487 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10515 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4978 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 4982 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10531 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 4986 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10539 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10547 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10555 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5001 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5013 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5020 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5037 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10621 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5041 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10638 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10650 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10670 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10683 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10695 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10707 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5101 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10718 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10732 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10765 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5151 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5155 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10789 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5159 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5163 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5167 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10813 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5171 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5175 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10829 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10862 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10895 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10928 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10961 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10977 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10993 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11009 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11025 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11039 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11053 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11069 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11085 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11101 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11123 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5443 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5448 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5452 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11170 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5468 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11199 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5484 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11210 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5491 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5501 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11229 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5520 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5525 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11262 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5532 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11270 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11287 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11299 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5572 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11327 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5584 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5590 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11359 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11371 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5612 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11394 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11413 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11431 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11449 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11465 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11485 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5699 "Gmsh.y" /* yacc.c:1646  */
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
#line 11513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5710 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5714 "Gmsh.y" /* yacc.c:1646  */
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
#line 11544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5733 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11555 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5740 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11565 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5746 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5748 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11583 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5759 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5764 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5770 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11610 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5779 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11622 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5792 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5795 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5799 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11644 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5802 "Gmsh.y" /* yacc.c:1906  */


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
