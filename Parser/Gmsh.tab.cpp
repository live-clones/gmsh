/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

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
#define yylval          gmsh_yylval
#define yychar          gmsh_yychar
#define yydebug         gmsh_yydebug
#define yynerrs         gmsh_yynerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Gmsh.y"

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


/* Line 371 of yacc.c  */
#line 179 "Gmsh.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     tAFFECTDIVIDE = 421,
     tAFFECTTIMES = 422,
     tAFFECTMINUS = 423,
     tAFFECTPLUS = 424,
     tOR = 425,
     tAND = 426,
     tNOTEQUAL = 427,
     tEQUAL = 428,
     tGREATEROREQUAL = 429,
     tLESSOREQUAL = 430,
     UNARYPREC = 431,
     tMINUSMINUS = 432,
     tPLUSPLUS = 433
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 105 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;


/* Line 387 of yacc.c  */
#line 411 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void *YYPARSE_PARAM);
#else
int gmsh_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void);
#else
int gmsh_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 439 "Gmsh.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1812

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   433

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   184,     2,   194,     2,   183,     2,     2,
     189,   190,   181,   179,   195,   180,   193,   182,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     175,     2,   176,   170,     2,     2,     2,     2,     2,     2,
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
     165,   166,   167,   168,   169,   171,   172,   173,   174,   177,
     178,   185,   186,   187
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    49,    55,    61,    69,    77,    85,
      95,   102,   109,   116,   125,   126,   129,   132,   135,   138,
     141,   143,   147,   149,   153,   154,   155,   166,   168,   172,
     173,   187,   189,   193,   194,   210,   219,   234,   235,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   270,   276,   284,   292,   297,   304,   311,   319,   327,
     335,   343,   353,   363,   367,   374,   381,   388,   395,   400,
     407,   417,   424,   434,   440,   449,   458,   470,   477,   487,
     493,   501,   511,   521,   533,   541,   551,   561,   562,   564,
     565,   569,   575,   576,   586,   592,   593,   603,   604,   608,
     612,   618,   619,   622,   626,   632,   636,   637,   640,   644,
     648,   652,   658,   660,   662,   666,   668,   670,   674,   676,
     678,   682,   684,   686,   690,   691,   697,   698,   701,   709,
     718,   725,   733,   738,   746,   755,   764,   772,   780,   792,
     801,   810,   819,   828,   838,   842,   847,   858,   866,   874,
     883,   892,   905,   914,   923,   931,   940,   949,   955,   967,
     973,   983,   993,   998,  1008,  1018,  1020,  1022,  1023,  1026,
    1033,  1040,  1047,  1054,  1063,  1074,  1089,  1106,  1119,  1128,
    1137,  1144,  1159,  1164,  1171,  1178,  1182,  1187,  1193,  1200,
    1206,  1210,  1214,  1219,  1225,  1230,  1236,  1240,  1246,  1254,
    1262,  1266,  1274,  1278,  1281,  1284,  1287,  1290,  1293,  1309,
    1312,  1315,  1318,  1321,  1324,  1341,  1345,  1352,  1361,  1370,
    1381,  1383,  1386,  1388,  1392,  1397,  1399,  1405,  1417,  1431,
    1432,  1440,  1441,  1455,  1456,  1472,  1473,  1480,  1489,  1498,
    1507,  1520,  1533,  1546,  1561,  1576,  1591,  1592,  1605,  1606,
    1619,  1620,  1633,  1634,  1651,  1652,  1669,  1670,  1687,  1688,
    1707,  1708,  1727,  1728,  1747,  1749,  1752,  1758,  1766,  1776,
    1779,  1782,  1785,  1789,  1792,  1796,  1799,  1803,  1806,  1810,
    1820,  1827,  1828,  1832,  1833,  1835,  1836,  1839,  1840,  1843,
    1844,  1847,  1855,  1862,  1871,  1877,  1881,  1889,  1895,  1900,
    1907,  1919,  1931,  1950,  1969,  1982,  1995,  2008,  2019,  2030,
    2041,  2052,  2063,  2068,  2073,  2078,  2083,  2088,  2091,  2095,
    2102,  2104,  2106,  2108,  2111,  2117,  2125,  2136,  2138,  2142,
    2145,  2148,  2151,  2155,  2159,  2163,  2167,  2171,  2175,  2179,
    2183,  2187,  2191,  2195,  2199,  2203,  2207,  2213,  2218,  2223,
    2228,  2233,  2238,  2243,  2248,  2253,  2258,  2263,  2270,  2275,
    2280,  2285,  2290,  2295,  2300,  2305,  2312,  2319,  2326,  2331,
    2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,
    2352,  2359,  2364,  2366,  2371,  2376,  2381,  2386,  2391,  2396,
    2401,  2404,  2410,  2416,  2422,  2428,  2432,  2439,  2444,  2452,
    2459,  2466,  2473,  2480,  2485,  2487,  2490,  2493,  2497,  2501,
    2513,  2523,  2531,  2539,  2541,  2545,  2547,  2549,  2552,  2556,
    2561,  2567,  2569,  2571,  2574,  2578,  2582,  2588,  2593,  2596,
    2599,  2602,  2605,  2609,  2613,  2617,  2621,  2627,  2633,  2639,
    2645,  2662,  2679,  2696,  2713,  2715,  2717,  2721,  2725,  2730,
    2737,  2744,  2746,  2748,  2752,  2756,  2766,  2774,  2776,  2782,
    2786,  2793,  2795,  2799,  2801,  2803,  2807,  2814,  2816,  2818,
    2820,  2822,  2827,  2834,  2839,  2844,  2849,  2854,  2863,  2868,
    2877,  2882,  2889,  2894,  2896,  2897,  2904,  2906,  2910,  2916,
    2922,  2924
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     200,     0,    -1,   201,    -1,     1,     6,    -1,    -1,   201,
     202,    -1,   205,    -1,   204,    -1,   225,    -1,   242,    -1,
     243,    -1,   247,    -1,   248,    -1,   249,    -1,   250,    -1,
     253,    -1,   274,    -1,   275,    -1,   252,    -1,   251,    -1,
     246,    -1,   277,    -1,   176,    -1,   176,   176,    -1,    37,
     189,   291,   190,     6,    -1,    38,   189,   291,   190,     6,
      -1,    37,   189,   291,   190,   203,   291,     6,    -1,    37,
     189,   291,   195,   287,   190,     6,    -1,    38,   189,   291,
     195,   287,   190,     6,    -1,    37,   189,   291,   195,   287,
     190,   203,   291,     6,    -1,     4,   291,   196,   206,   197,
       6,    -1,   117,     4,   191,   278,   192,     6,    -1,   118,
       4,   191,   278,   192,     6,    -1,   119,     4,   191,   278,
     195,   278,   192,     6,    -1,    -1,   206,   209,    -1,   206,
     213,    -1,   206,   216,    -1,   206,   218,    -1,   206,   219,
      -1,   278,    -1,   207,   195,   278,    -1,   278,    -1,   208,
     195,   278,    -1,    -1,    -1,     4,   210,   189,   207,   190,
     211,   196,   208,   197,     6,    -1,   291,    -1,   212,   195,
     291,    -1,    -1,   126,   189,   278,   195,   278,   195,   278,
     190,   214,   196,   212,   197,     6,    -1,   291,    -1,   215,
     195,   291,    -1,    -1,   127,   189,   278,   195,   278,   195,
     278,   195,   278,   190,   217,   196,   215,   197,     6,    -1,
     128,   196,   283,   197,   196,   283,   197,     6,    -1,   128,
     196,   283,   197,   196,   283,   197,   196,   283,   197,   196,
     283,   197,     6,    -1,    -1,   129,   220,   196,   208,   197,
       6,    -1,     7,    -1,   169,    -1,   168,    -1,   167,    -1,
     166,    -1,   187,    -1,   186,    -1,   189,    -1,   191,    -1,
     190,    -1,   192,    -1,    66,   191,   227,   192,     6,    -1,
      67,   191,   230,   192,     6,    -1,    70,   223,   292,   195,
     278,   224,     6,    -1,    71,   223,   296,   195,   292,   224,
       6,    -1,   296,   221,   284,     6,    -1,     4,   223,   224,
     221,   284,     6,    -1,   295,   223,   224,   221,   284,     6,
      -1,     4,   191,   278,   192,   221,   278,     6,    -1,     4,
     189,   278,   190,   221,   278,     6,    -1,   295,   191,   278,
     192,   221,   278,     6,    -1,   295,   189,   278,   190,   221,
     278,     6,    -1,     4,   223,   196,   287,   197,   224,   221,
     284,     6,    -1,   295,   223,   196,   287,   197,   224,   221,
     284,     6,    -1,   296,   222,     6,    -1,     4,   191,   278,
     192,   222,     6,    -1,     4,   189,   278,   190,   222,     6,
      -1,   295,   191,   278,   192,   222,     6,    -1,   295,   189,
     278,   190,   222,     6,    -1,   296,     7,   292,     6,    -1,
       4,   193,     4,     7,   292,     6,    -1,     4,   191,   278,
     192,   193,     4,     7,   292,     6,    -1,     4,   193,     4,
     221,   278,     6,    -1,     4,   191,   278,   192,   193,     4,
     221,   278,     6,    -1,     4,   193,     4,   222,     6,    -1,
       4,   191,   278,   192,   193,     4,   222,     6,    -1,     4,
     193,   136,   193,     4,     7,   288,     6,    -1,     4,   191,
     278,   192,   193,   136,   193,     4,     7,   288,     6,    -1,
       4,   193,   137,     7,   289,     6,    -1,     4,   191,   278,
     192,   193,   137,     7,   289,     6,    -1,     4,   145,     7,
     278,     6,    -1,   145,   191,   278,   192,     7,     4,     6,
      -1,   145,   191,   278,   192,   193,     4,     7,   278,     6,
      -1,   145,   191,   278,   192,   193,     4,     7,   292,     6,
      -1,   145,   191,   278,   192,   193,     4,     7,   196,   287,
     197,     6,    -1,   145,   191,   278,   192,   193,     4,     6,
      -1,    96,   189,     4,   190,   193,     4,     7,   278,     6,
      -1,    96,   189,     4,   190,   193,     4,     7,   292,     6,
      -1,    -1,   195,    -1,    -1,   227,   226,   296,    -1,   227,
     226,   296,     7,   278,    -1,    -1,   227,   226,   296,     7,
     196,   284,   228,   232,   197,    -1,   227,   226,   296,     7,
     292,    -1,    -1,   227,   226,   296,     7,   196,   292,   229,
     234,   197,    -1,    -1,   230,   226,   291,    -1,   278,     7,
     292,    -1,   231,   195,   278,     7,   292,    -1,    -1,   232,
     233,    -1,   195,     4,   284,    -1,   195,     4,   196,   231,
     197,    -1,   195,     4,   292,    -1,    -1,   234,   235,    -1,
     195,     4,   278,    -1,   195,     4,   292,    -1,   195,   148,
     292,    -1,   195,     4,   196,   294,   197,    -1,   278,    -1,
     292,    -1,   292,   195,   278,    -1,   278,    -1,   292,    -1,
     292,   195,   278,    -1,   278,    -1,   292,    -1,   292,   195,
     278,    -1,   278,    -1,   292,    -1,   292,   195,   278,    -1,
      -1,   139,    76,   196,   278,   197,    -1,    -1,    88,   281,
      -1,    72,   189,   278,   190,     7,   281,     6,    -1,    92,
      72,   189,   236,   190,   221,   284,     6,    -1,    81,    82,
     284,     7,   278,     6,    -1,    75,   189,   278,   190,     7,
     284,     6,    -1,    97,    75,   284,     6,    -1,    79,   189,
     278,   190,     7,   284,     6,    -1,    73,   189,   278,   190,
       7,   284,   241,     6,    -1,    74,   189,   278,   190,     7,
     284,   241,     6,    -1,   131,   189,   278,   190,     7,   284,
       6,    -1,   132,   189,   278,   190,     7,   284,     6,    -1,
     133,   189,   278,   190,     7,   284,   135,   284,   134,   278,
       6,    -1,    75,     4,   189,   278,   190,     7,   284,     6,
      -1,    93,    75,   189,   278,   190,     7,   284,     6,    -1,
      92,    75,   189,   237,   190,   221,   284,     6,    -1,    88,
      78,   189,   278,   190,     7,   284,     6,    -1,    89,    78,
     189,   278,   190,     7,   284,   240,     6,    -1,    12,    13,
       6,    -1,    13,    78,   278,     6,    -1,    83,    78,   189,
     278,   190,     7,     5,     5,     5,     6,    -1,    76,   189,
     278,   190,     7,   284,     6,    -1,    77,   189,   278,   190,
       7,   284,     6,    -1,    78,     4,   189,   278,   190,     7,
     284,     6,    -1,    93,    78,   189,   278,   190,     7,   284,
       6,    -1,    93,    78,   189,   278,   190,     7,   284,     4,
     196,   283,   197,     6,    -1,    92,    78,   189,   238,   190,
     221,   284,     6,    -1,    91,    80,   189,   278,   190,     7,
     284,     6,    -1,    80,   189,   278,   190,     7,   284,     6,
      -1,    93,    80,   189,   278,   190,     7,   284,     6,    -1,
      92,    80,   189,   239,   190,   221,   284,     6,    -1,   100,
     281,   196,   244,   197,    -1,    99,   196,   281,   195,   281,
     195,   278,   197,   196,   244,   197,    -1,   101,   281,   196,
     244,   197,    -1,   102,   196,   281,   195,   278,   197,   196,
     244,   197,    -1,   102,   196,   281,   195,   281,   197,   196,
     244,   197,    -1,     4,   196,   244,   197,    -1,   111,    75,
     196,   287,   197,    78,   196,   278,   197,    -1,   108,    75,
     189,   278,   190,   196,   287,   197,     6,    -1,   245,    -1,
     243,    -1,    -1,   245,   242,    -1,   245,    72,   196,   287,
     197,     6,    -1,   245,    75,   196,   287,   197,     6,    -1,
     245,    78,   196,   287,   197,     6,    -1,   245,    80,   196,
     287,   197,     6,    -1,   104,    88,   189,   278,   190,     7,
     284,     6,    -1,   104,    72,   189,   278,   190,     7,   196,
     283,   197,     6,    -1,   104,    88,   189,   278,   190,     7,
     196,   281,   195,   281,   195,   287,   197,     6,    -1,   104,
      88,   189,   278,   190,     7,   196,   281,   195,   281,   195,
     281,   195,   287,   197,     6,    -1,   104,    76,   189,   278,
     190,     7,   196,   281,   195,   287,   197,     6,    -1,   104,
       4,   189,   278,   190,     7,   284,     6,    -1,   104,     4,
     189,   278,   190,     7,     5,     6,    -1,   104,     4,   196,
     278,   197,     6,    -1,   104,     4,   189,   278,   190,     7,
     196,   281,   195,   281,   195,   287,   197,     6,    -1,   109,
     196,   245,   197,    -1,   109,   145,   191,   278,   192,     6,
      -1,   109,     4,   191,   278,   192,     6,    -1,   109,   296,
       6,    -1,   109,     4,     4,     6,    -1,   136,   288,   196,
     245,   197,    -1,    98,   136,   288,   196,   245,   197,    -1,
     165,   278,   196,   245,   197,    -1,   149,     5,     6,    -1,
     150,     5,     6,    -1,   149,   196,   245,   197,    -1,    98,
     149,   196,   245,   197,    -1,   150,   196,   245,   197,    -1,
      98,   150,   196,   245,   197,    -1,     4,   292,     6,    -1,
      59,   189,   294,   190,     6,    -1,     4,     4,   191,   278,
     192,   291,     6,    -1,     4,     4,     4,   191,   278,   192,
       6,    -1,     4,   278,     6,    -1,    96,   189,     4,   190,
     193,     4,     6,    -1,   130,     4,     6,    -1,   143,     6,
      -1,   144,     6,    -1,    56,     6,    -1,    57,     6,    -1,
      50,     6,    -1,    50,   196,   278,   195,   278,   195,   278,
     195,   278,   195,   278,   195,   278,   197,     6,    -1,    51,
       6,    -1,    52,     6,    -1,    63,     6,    -1,    64,     6,
      -1,    85,     6,    -1,    86,   196,   287,   197,   196,   287,
     197,   196,   283,   197,   196,   278,   195,   278,   197,     6,
      -1,   158,   278,     6,    -1,   138,   189,   278,     8,   278,
     190,    -1,   138,   189,   278,     8,   278,     8,   278,   190,
      -1,   138,     4,   139,   196,   278,     8,   278,   197,    -1,
     138,     4,   139,   196,   278,     8,   278,     8,   278,   197,
      -1,   140,    -1,   148,     4,    -1,   146,    -1,   147,   296,
       6,    -1,   141,   189,   278,   190,    -1,   142,    -1,   103,
     281,   196,   245,   197,    -1,   103,   196,   281,   195,   281,
     195,   278,   197,   196,   245,   197,    -1,   103,   196,   281,
     195,   281,   195,   281,   195,   278,   197,   196,   245,   197,
      -1,    -1,   103,   281,   196,   245,   254,   267,   197,    -1,
      -1,   103,   196,   281,   195,   281,   195,   278,   197,   196,
     245,   255,   267,   197,    -1,    -1,   103,   196,   281,   195,
     281,   195,   281,   195,   278,   197,   196,   245,   256,   267,
     197,    -1,    -1,   103,   196,   245,   257,   267,   197,    -1,
     103,    72,   196,   278,   195,   281,   197,     6,    -1,   103,
      75,   196,   278,   195,   281,   197,     6,    -1,   103,    78,
     196,   278,   195,   281,   197,     6,    -1,   103,    72,   196,
     278,   195,   281,   195,   281,   195,   278,   197,     6,    -1,
     103,    75,   196,   278,   195,   281,   195,   281,   195,   278,
     197,     6,    -1,   103,    78,   196,   278,   195,   281,   195,
     281,   195,   278,   197,     6,    -1,   103,    72,   196,   278,
     195,   281,   195,   281,   195,   281,   195,   278,   197,     6,
      -1,   103,    75,   196,   278,   195,   281,   195,   281,   195,
     281,   195,   278,   197,     6,    -1,   103,    78,   196,   278,
     195,   281,   195,   281,   195,   281,   195,   278,   197,     6,
      -1,    -1,   103,    72,   196,   278,   195,   281,   197,   258,
     196,   267,   197,     6,    -1,    -1,   103,    75,   196,   278,
     195,   281,   197,   259,   196,   267,   197,     6,    -1,    -1,
     103,    78,   196,   278,   195,   281,   197,   260,   196,   267,
     197,     6,    -1,    -1,   103,    72,   196,   278,   195,   281,
     195,   281,   195,   278,   197,   261,   196,   267,   197,     6,
      -1,    -1,   103,    75,   196,   278,   195,   281,   195,   281,
     195,   278,   197,   262,   196,   267,   197,     6,    -1,    -1,
     103,    78,   196,   278,   195,   281,   195,   281,   195,   278,
     197,   263,   196,   267,   197,     6,    -1,    -1,   103,    72,
     196,   278,   195,   281,   195,   281,   195,   281,   195,   278,
     197,   264,   196,   267,   197,     6,    -1,    -1,   103,    75,
     196,   278,   195,   281,   195,   281,   195,   281,   195,   278,
     197,   265,   196,   267,   197,     6,    -1,    -1,   103,    78,
     196,   278,   195,   281,   195,   281,   195,   281,   195,   278,
     197,   266,   196,   267,   197,     6,    -1,   268,    -1,   267,
     268,    -1,   114,   196,   278,   197,     6,    -1,   114,   196,
     284,   195,   284,   197,     6,    -1,   114,   196,   284,   195,
     284,   195,   284,   197,     6,    -1,   115,     6,    -1,   106,
       6,    -1,   122,     6,    -1,   122,   124,     6,    -1,   123,
       6,    -1,   123,   124,     6,    -1,   120,     6,    -1,   120,
     124,     6,    -1,   121,     6,    -1,   121,   124,     6,    -1,
     116,   189,   278,   190,     7,   284,    95,   278,     6,    -1,
      95,     4,   191,   278,   192,     6,    -1,    -1,    95,     4,
     278,    -1,    -1,     4,    -1,    -1,     7,   284,    -1,    -1,
       7,   278,    -1,    -1,   105,   284,    -1,    90,    75,   285,
       7,   278,   269,     6,    -1,    90,    78,   285,   271,   270,
       6,    -1,    84,    78,   196,   278,   197,     7,   284,     6,
      -1,    90,    80,   285,   271,     6,    -1,   125,   285,     6,
      -1,   112,    78,   196,   287,   197,   278,     6,    -1,   106,
      78,   285,   272,     6,    -1,   106,    80,   285,     6,    -1,
     107,    78,   284,     7,   278,     6,    -1,    94,    75,   196,
     287,   197,     7,   196,   287,   197,   273,     6,    -1,    94,
      78,   196,   287,   197,     7,   196,   287,   197,   273,     6,
      -1,    94,    75,   196,   287,   197,     7,   196,   287,   197,
      99,   196,   281,   195,   281,   195,   278,   197,     6,    -1,
      94,    78,   196,   287,   197,     7,   196,   287,   197,    99,
     196,   281,   195,   281,   195,   278,   197,     6,    -1,    94,
      75,   196,   287,   197,     7,   196,   287,   197,   100,   281,
       6,    -1,    94,    78,   196,   287,   197,     7,   196,   287,
     197,   100,   281,     6,    -1,    94,    78,   278,   196,   287,
     197,     7,   278,   196,   287,   197,     6,    -1,    72,   196,
     287,   197,   139,    78,   196,   278,   197,     6,    -1,    75,
     196,   287,   197,   139,    78,   196,   278,   197,     6,    -1,
      72,   196,   287,   197,   139,    80,   196,   278,   197,     6,
      -1,    75,   196,   287,   197,   139,    80,   196,   278,   197,
       6,    -1,    78,   196,   287,   197,   139,    80,   196,   278,
     197,     6,    -1,   113,    78,   285,     6,    -1,   113,    75,
     285,     6,    -1,    87,    72,   285,     6,    -1,    87,    75,
     285,     6,    -1,    87,    78,   285,     6,    -1,   110,     6,
      -1,   110,     4,     6,    -1,   110,    72,   196,   287,   197,
       6,    -1,   155,    -1,   156,    -1,   157,    -1,   276,     6,
      -1,   276,   196,   284,   197,     6,    -1,   276,   196,   284,
     195,   284,   197,     6,    -1,   276,   189,   284,   190,   196,
     284,   195,   284,   197,     6,    -1,   279,    -1,   189,   278,
     190,    -1,   180,   278,    -1,   179,   278,    -1,   184,   278,
      -1,   278,   180,   278,    -1,   278,   179,   278,    -1,   278,
     181,   278,    -1,   278,   182,   278,    -1,   278,   183,   278,
      -1,   278,   188,   278,    -1,   278,   175,   278,    -1,   278,
     176,   278,    -1,   278,   178,   278,    -1,   278,   177,   278,
      -1,   278,   174,   278,    -1,   278,   173,   278,    -1,   278,
     172,   278,    -1,   278,   171,   278,    -1,   278,   170,   278,
       8,   278,    -1,    14,   223,   278,   224,    -1,    15,   223,
     278,   224,    -1,    16,   223,   278,   224,    -1,    17,   223,
     278,   224,    -1,    18,   223,   278,   224,    -1,    19,   223,
     278,   224,    -1,    20,   223,   278,   224,    -1,    21,   223,
     278,   224,    -1,    22,   223,   278,   224,    -1,    24,   223,
     278,   224,    -1,    25,   223,   278,   195,   278,   224,    -1,
      26,   223,   278,   224,    -1,    27,   223,   278,   224,    -1,
      28,   223,   278,   224,    -1,    29,   223,   278,   224,    -1,
      30,   223,   278,   224,    -1,    31,   223,   278,   224,    -1,
      32,   223,   278,   224,    -1,    33,   223,   278,   195,   278,
     224,    -1,    34,   223,   278,   195,   278,   224,    -1,    35,
     223,   278,   195,   278,   224,    -1,    23,   223,   278,   224,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   161,
      -1,   162,    -1,   163,    -1,    60,    -1,    61,    -1,    62,
      -1,    -1,    68,   223,   278,   280,   232,   224,    -1,   154,
     223,   291,   224,    -1,   296,    -1,     4,   191,   278,   192,
      -1,     4,   189,   278,   190,    -1,   295,   191,   278,   192,
      -1,   295,   189,   278,   190,    -1,   159,   189,   296,   190,
      -1,   160,   189,   292,   190,    -1,   194,   296,   223,   224,
      -1,   296,   222,    -1,     4,   191,   278,   192,   222,    -1,
       4,   189,   278,   190,   222,    -1,   295,   191,   278,   192,
     222,    -1,   295,   189,   278,   190,   222,    -1,     4,   193,
       4,    -1,     4,   191,   278,   192,   193,     4,    -1,     4,
     193,     4,   222,    -1,     4,   191,   278,   192,   193,     4,
     222,    -1,   151,   189,   291,   195,   278,   190,    -1,    45,
     189,   284,   195,   284,   190,    -1,    46,   189,   291,   195,
     291,   190,    -1,    47,   189,   291,   195,   291,   190,    -1,
      49,   189,   294,   190,    -1,   282,    -1,   180,   281,    -1,
     179,   281,    -1,   281,   180,   281,    -1,   281,   179,   281,
      -1,   196,   278,   195,   278,   195,   278,   195,   278,   195,
     278,   197,    -1,   196,   278,   195,   278,   195,   278,   195,
     278,   197,    -1,   196,   278,   195,   278,   195,   278,   197,
      -1,   189,   278,   195,   278,   195,   278,   190,    -1,   284,
      -1,   283,   195,   284,    -1,   278,    -1,   286,    -1,   196,
     197,    -1,   196,   287,   197,    -1,   180,   196,   287,   197,
      -1,   278,   181,   196,   287,   197,    -1,   284,    -1,     5,
      -1,   180,   286,    -1,   278,   181,   286,    -1,   278,     8,
     278,    -1,   278,     8,   278,     8,   278,    -1,    72,   196,
     278,   197,    -1,    72,     5,    -1,    75,     5,    -1,    78,
       5,    -1,    80,     5,    -1,    92,    72,     5,    -1,    92,
      75,     5,    -1,    92,    78,     5,    -1,    92,    80,     5,
      -1,    92,    72,   196,   287,   197,    -1,    92,    75,   196,
     287,   197,    -1,    92,    78,   196,   287,   197,    -1,    92,
      80,   196,   287,   197,    -1,    72,   139,    50,   196,   278,
     195,   278,   195,   278,   195,   278,   195,   278,   195,   278,
     197,    -1,    75,   139,    50,   196,   278,   195,   278,   195,
     278,   195,   278,   195,   278,   195,   278,   197,    -1,    78,
     139,    50,   196,   278,   195,   278,   195,   278,   195,   278,
     195,   278,   195,   278,   197,    -1,    80,   139,    50,   196,
     278,   195,   278,   195,   278,   195,   278,   195,   278,   195,
     278,   197,    -1,   243,    -1,   253,    -1,     4,   223,   224,
      -1,   295,   223,   224,    -1,    36,   191,   296,   192,    -1,
       4,   223,   196,   287,   197,   224,    -1,   295,   223,   196,
     287,   197,   224,    -1,   278,    -1,   286,    -1,   287,   195,
     278,    -1,   287,   195,   286,    -1,   196,   278,   195,   278,
     195,   278,   195,   278,   197,    -1,   196,   278,   195,   278,
     195,   278,   197,    -1,     4,    -1,     4,   193,   136,   193,
       4,    -1,   196,   290,   197,    -1,     4,   191,   278,   192,
     193,   137,    -1,   288,    -1,   290,   195,   288,    -1,   292,
      -1,   296,    -1,     4,   193,     4,    -1,     4,   191,   278,
     192,   193,     4,    -1,     5,    -1,    53,    -1,   164,    -1,
      58,    -1,   152,   189,   291,   190,    -1,   153,   189,   291,
     195,   291,   190,    -1,   153,   189,   291,   190,    -1,    41,
     223,   294,   224,    -1,    42,   189,   291,   190,    -1,    43,
     189,   291,   190,    -1,    44,   189,   291,   195,   291,   195,
     291,   190,    -1,    39,   223,   294,   224,    -1,    48,   223,
     278,   195,   292,   195,   292,   224,    -1,    40,   223,   291,
     224,    -1,    40,   223,   291,   195,   287,   224,    -1,    54,
     223,   291,   224,    -1,    55,    -1,    -1,    69,   223,   292,
     293,   234,   224,    -1,   291,    -1,   294,   195,   291,    -1,
       4,   198,   196,   278,   197,    -1,   295,   198,   196,   278,
     197,    -1,     4,    -1,   295,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
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
  "tSetPartition", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
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
  "$@22", "RecursiveListOfStringExprVar", "StringIndex", "String__Index", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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
      63,   425,   426,   427,   428,    60,    62,   429,   430,    43,
      45,    42,    47,    37,    33,   431,   432,   433,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
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
      63,    62,    61,    60,    65,    64,     0,     0,     0,     0,
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
     364,   363,   362,   358,   359,   361,   360,   353,   352,   354,
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

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1312
static const yytype_int16 yypact[] =
{
    6712,    53,   100,  6828, -1312, -1312,  3430,    12,   -42,  -124,
     -76,    24,   116,   178,   232,   238,   -70,   247,   258,   -37,
      66,   105,   105,  -158,    89,    97,    -1,   137,   149,    15,
     160,   181,   303,   313,   327,   425,   249,   -25,   385,   407,
     111,   436,   272,   476,   270,   356,   477,   -69,   372,   -78,
     -78,   393,   340,    22,   317,   521,   502,     8,    80,   528,
     548,   306,   630,   633,   670,  4896,   686,   479,   504,   522,
      17,    19, -1312,   568, -1312,   704,   754,   575, -1312,   775,
     818,    38,    44, -1312, -1312, -1312,  6576,  6576, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312,    65, -1312,   241,   113, -1312,    48,
   -1312, -1312, -1312, -1312,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   637,
     673,   697,   708,   715,   728,   105,   742, -1312,   105, -1312,
   -1312, -1312, -1312, -1312,   105,   105,   834,   746,   756,   757,
     105,   761,   779, -1312, -1312, -1312, -1312,  6576,  6576,  6576,
    6576,  6576,   147,   775,   354,   646,   420,   837, -1312,   683,
     888,   349,   117,   904,  6576,  2389,  2389, -1312,  6576, -1312,
   -1312, -1312, -1312,  2389, -1312, -1312, -1312, -1312, -1312, -1312,
    2194,   775,  6576,  6394,  6576,  6576,   780,  6576,  6394,  6576,
    6576,   788,  6394,  6576,  6576,  5272,   792,   786, -1312,  6394,
    4896,  4896,  4896,   801,   802,  4896,  4896,  4896,   815,   858,
     864,   865,   869,   870,   894,   901,   831,  1046,  1036,  5272,
      17,   909,   915,   -78,   -78,   -78,  6576,  6576,   -72, -1312,
     127,   -78,   916,   921,   966,  3627,   203,   -73,   913,   932,
     971,  4896,  4896,  5272,   975,     5,   977, -1312,   972,  1166,
    1167, -1312,   980,   981,   983,  4896,  4896,   989,   990,   994,
     506, -1312,   996,    37,    36,    39,    41,   561,  5460,  6576,
    3888, -1312, -1312,   475, -1312,  1186, -1312,   500,   251,  1187,
    6576,  6576,  6576,  1001,  6576,   999,  1057,  6576,  6576, -1312,
   -1312,  6576,  1000,  1193, -1312,  1195, -1312,  1196, -1312,  -119,
     965,  5642, -1312,  5272,  5272,  6576,  6576,  1007,   529,  2194,
   -1312, -1312, -1312, -1312, -1312, -1312,  5272,  1198,  1030,  6576,
    6576,  1218,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,
    6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,
    6576,  6576,  6576,  6576,  2389,  2389,  2389,  2389,  2389,  2389,
    5272,  2389,  2389,  6576,  2389,  2389,  6576,  2194,  6576,  2389,
    2389,  2389,  2389,   775,  2194,  1039,  1039,  1039,  4487,  8443,
     148,  1031,  1221,   105,  1033, -1312,  1034,  2672,  6576, -1312,
   -1312,  6394,   108, -1312,  6576,  6576,  6576,  6576,  6576,  6576,
    6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576,  6576, -1312,
   -1312,  6576,  6576, -1312, -1312,  1317,  -108,   -16, -1312, -1312,
     419,  4266, -1312,   432,   275,   302,  1037,  1038,  4675,  6394,
    3071, -1312,   369,  8788,  8809,  6576,  8830,   443,  8851,  8872,
    6576,   469,  8893,  8914,  1227,  6576,  6576,   546,  1232,  1233,
    1238,  6576,  6576,  1241,  1242,  1242,  6576,  6212,  6212,  6212,
    6212,  6576,  6576,  6576,  6394,  6394,  5830,  1055,  1247,  1058,
   -1312, -1312,   145, -1312, -1312,  4515,  6207,   -78,   -78,   354,
     354,   180,  6576,  6576,  6576,  3627,  3627,  6576,  2672,   240,
   -1312,  6576,  6576,  6576,  6576,  6576,  1248,  1250,  1251,  6576,
    1253,  6576,  6576,  1332, -1312, -1312,  6394,  6394,  6394,  1256,
    1257,  6576,  6576,  6576,  6576,  6576,  1262,   559,   775, -1312,
    1217,  6576, -1312,  1222, -1312,  1229, -1312,  1230,    46,    51,
      55,    56,  6394,  1039, -1312,  8935, -1312,   611,  6576,  5648,
   -1312,  6576,  6576,   560, -1312,  8956,  8977,  8998,  1132,  6389,
   -1312,  1086,  3143,  9019,  8466, -1312, -1312,  1461, -1312,  2031,
    6576, -1312, -1312,  1093,   612,  9040,  8489,  6576,  6394,   108,
    1278,  1279, -1312,  6576,  9061,  8512,   376,  8420,  8420,  8420,
    8420,  8420,  8420,  8420,  8420,  8420,  8420,  8420,  7328,  8420,
    8420,  8420,  8420,  8420,  8420,  8420,  7354,  7380,  7406,   582,
     583,   582,  1096,  1097,  1095,  1103,  1104,  1106,  7432,   490,
     635,  9523, -1312,  1460,  1108,  1098,   586,   635,  1101,  1102,
     187,   102,  2194,  6576,  1298,  1303,    30,   635, -1312,   -39,
      25,    33,   -29, -1312,  3882,   639, -1312,  5272,  3190,  2940,
    2327,  1035,  1035,   310,   310,   310,   310,   526,   526,  1039,
    1039,  1039,  1039,    35,  9082,  8535, -1312,  6576,  1307,     9,
    6394,  1306,  6394,  6576,  1312,  2389,  1314, -1312,   775,  1315,
    2389,  6576,  2194,  1320,  6394,  6394,  1183,  1339,  1341,  9103,
    1346,  1220,  1349,  1350,  9124,  1225,  1354,  1359,  6576,  9145,
    4025,  1184, -1312, -1312, -1312,  9166,  9187,  6576,  5272,  1375,
    1376,  9208,  1197,  9523,  1188,  1199,  9523,  1191,  1200,  9523,
    1202,  1203,  9523,  1205,  9229,  9250,  9271,   652,   653,  6394,
    1201, -1312, -1312,  2060,  2546,   -78,  6576,  6576, -1312, -1312,
    1204,  1206,  3627,  7458,  7484,  7510,  4078,   872,   -78,  3469,
    9292,  4213,  9313,  9334,  9355,  6576,  1382, -1312,  6576,  9376,
   -1312,  8558,  8581, -1312,   660,   664,   668, -1312, -1312,  8604,
    8627,  7536,  8650,   251,  6394, -1312,  1210,  1223,  4420,  1226,
    1231,  1234, -1312,  6394, -1312,  6394, -1312,  6394, -1312,  6394,
     672, -1312, -1312,  3214,  6394,  1039, -1312,  6394, -1312,  1385,
    1388,  1391,  1239,  6576,  4747,  6576,  6576, -1312,     6, -1312,
   -1312,  4937,  1235,  5272,  1408,   187,   187,  4454,   675,  5272,
   -1312, -1312,  8673,   251,   288, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312,  6576, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312,  6576,  6576,  6576, -1312,  6394,
   -1312, -1312, -1312, -1312,  2389,  5272,  2389,  2389,  2194, -1312,
   -1312, -1312, -1312, -1312,  6576, -1312, -1312,  2389, -1312, -1312,
   -1312,  6576,  1410,   165,  6576,  1412,  1420,  1604, -1312,  1426,
    1243,    17,  1433, -1312,  6394,  6394,  6394,  6394, -1312,   635,
    1435,  6576, -1312,  1259,  1261,  1258, -1312,  1440, -1312, -1312,
   -1312, -1312, -1312,   251,   251,  8696, -1312, -1312,  1276,  2389,
     597, -1312,   610,  7562, -1312, -1312, -1312,  1446, -1312, -1312,
    8420,   635,   -78,  3071, -1312,   793,  5272,  5272,  1448,  5272,
     796,  5272,  5272,  1449,  1377,  5272,  5272,  1726,  1451,  1452,
    6394,  1454,  1455,  3234, -1312, -1312,  1462, -1312,  1464,   108,
    6576,   108,  6576,   108,  6576,   108,  6576,  1465,  1468,  1469,
    1470,  1471,   690,  1475,  5125, -1312, -1312,   264,  7588,  7614,
   -1312, -1312,  4608,   -92,   -78,   -78,   -78,  1476,  1463,  1285,
    1477,  1293,    34,    49,    57,    63,   509, -1312,   269, -1312,
     872,  1479,  1478,  1495,  1496,  1500,  9523, -1312,  1995,  1313,
    1504,  1505,  1506,  1436,  6576,  1507,  1510,  6576,   125,   694,
   -1312,  6576, -1312,  6576,  6576,  6576,   695,   698,   705,   706,
   -1312,  6576,   710,   718,  5272,  5272,  5272,  1513,  7640, -1312,
    3830,   557,  1514,  1518, -1312,  5272,  1324, -1312,  6576,  1520,
    6576,  1521, -1312,   635,  1522,  1524, -1312,  1527, -1312,  1526,
    8420,  8420,  8420,  8420,   593,  1329,  1353,  1355,  1356,  1352,
     603,   623,  9397,  1358,  2155, -1312,   260,  1362,  1549,  2197,
   -1312, -1312, -1312,    17,  6576, -1312,   721, -1312,   724,   725,
     730,   739,   108, -1312,  9523,  1368,  6576,  6576,  5272,  1363,
   -1312, -1312, -1312,  1370, -1312,  1555,    16,  1559,  6576,  4459,
    1563,  1567,    76,  1379,  1380,  1489,  1489,  5272,  1572,  1383,
    1386,  1575,  1578,  5272,  1389,  1582,  1583, -1312,  1585,  5272,
     743,  5272,  5272,  1587,  1589, -1312,  5272,  5272,  9523,  5272,
    9523,  5272,  9523,  5272,  9523,  5272,  5272,  5272,  1400,  1401,
    1592,   195, -1312,  6576,  6576,  6576,  1404,  1405,  -122,  -102,
     -83,  1411, -1312,  5272, -1312,  6576, -1312,  1599, -1312,  1603,
   -1312,  1605, -1312,  1610, -1312, -1312,  3627,   647,  5084, -1312,
    1421,  1422,  5836, -1312,  6394, -1312, -1312, -1312,  1424,  2304,
   -1312, -1312,  8719,  1617,   635,  7666,  7692,  7718,  7744, -1312,
   -1312, -1312, -1312,  9523, -1312,   635,  1616,  1618,  1490, -1312,
    6576,  6576,  6576, -1312,  1622,   489,  1434,  1639,  2401, -1312,
    2523, -1312,   108, -1312, -1312,   421, -1312, -1312, -1312, -1312,
   -1312, -1312,  2389, -1312, -1312, -1312,  2194,  1643, -1312, -1312,
      20, -1312, -1312, -1312, -1312, -1312,  2194,  6576,  1644,  1645,
      30, -1312,  1646,  8742,    17, -1312,  1647,  1648,  1649,  1650,
    5272,  6576,  7770,  7796,   744, -1312,  6576,  1653, -1312, -1312,
    2389, -1312,  7822,  4083,  9523, -1312, -1312, -1312, -1312,  6576,
    6576,   -78,  1654,  1659,  1660, -1312,  6576,  6576, -1312, -1312,
    1661,  6576, -1312, -1312,  1663,  1664,  1473,  1666,  1512,  6576,
   -1312,  1667,  1668,  1669,  1671,  1672,  1673,   968,  1675,  6394,
    6394,  6576, -1312,  6212,  5590,  9418,  2476,   354,   354,   -78,
    1677,   -78,  1687,   -78,  1688,  6576,   329,  1509,  9439, -1312,
   -1312, -1312, -1312,  5778,   271, -1312,  1689,  3693,  1694,  5272,
     -78,  3693,  1696,   778,  6576, -1312,  1700,   251, -1312,  6576,
    6576,  6576,  6576, -1312, -1312, -1312,  5272,  3688,   782,  9460,
   -1312, -1312,  4520,  5272, -1312, -1312, -1312,  5272, -1312,  1519,
     635,  4271,  4708,  2194,  1702,  2735, -1312,  1703,  1705, -1312,
    1523, -1312, -1312, -1312, -1312, -1312,  1706,   629,  9523,  6576,
    6576,  5272,  1532,   804,  9523, -1312,  1707,  6576, -1312, -1312,
    5966,  6112,   344, -1312, -1312, -1312,  6140,  6170, -1312,  6336,
    1709, -1312,  5272, -1312,  1642,  1727,  9523, -1312, -1312, -1312,
   -1312, -1312, -1312,  1538, -1312, -1312,   805,   808,  6018,  2771,
    1729,  1541, -1312,  6576, -1312,  1542,  1543,   278, -1312,  1545,
     281, -1312,  1546,   289, -1312,  1547,  8765,  1732,  5272,  1737,
    1550,  6576, -1312,  6024,   342, -1312,   829,   348,   353, -1312,
    1739,  6475, -1312,  7848,  7874,  7900,  7926,  1614,  6576, -1312,
    6576, -1312, -1312,  6394,  2791,  1743,  1554,  1746, -1312, -1312,
    3888, -1312, -1312,  2389,  9523, -1312, -1312, -1312, -1312,    17,
   -1312,  1619, -1312, -1312,  6576,  7952,  7978, -1312,  5272,  6576,
    1747, -1312,  8004, -1312, -1312,  1749,  1751,  1754,  1755,  1756,
    1759,   838,  1570, -1312,  5272,   613,   659,  6394, -1312, -1312,
     354,  3849, -1312, -1312,  3627,   872,  3627,   872,  3627,   872,
    1764, -1312,   841,  5272, -1312,  6503,   -78,  1765,  6394,   -78,
   -1312, -1312,  6576,  6576,  6576,  6576,  6576,  6824,  6852,   842,
   -1312, -1312,  1782, -1312,   851,  1159,   887,  1783, -1312,  1594,
    9523,  6576,  6576,   891,  9523, -1312,  6576,   892,   899, -1312,
   -1312, -1312, -1312, -1312, -1312,  1598,  6576,   902,  1600,   -78,
    5272,  1789,  1601,   -78,  1792,   903,  1606,  6576, -1312,  6880,
     355,   717,  6908,   379,  1068,  6936,   381,  1155, -1312,  5272,
    1794,  1713,  5313,  1608,   418, -1312,   906,   426,  8030,  8056,
    8082,  8108,  2837, -1312, -1312,  1795, -1312,  6576, -1312,  2194,
   -1312, -1312,  6576,  9481,  8134,    29,  8160, -1312, -1312,  6576,
    6964,  1796,   -78,    83, -1312, -1312,   -78,    86, -1312,  1803,
   -1312,  6992,  1804,  6576,  1807,  1809,  6576,  1810,  1814,  6576,
    1820,  1630, -1312,  6576, -1312,   872, -1312,  6394,  1823,  6024,
    6576,  6576,  6576,  6576, -1312, -1312,  3014, -1312,   925, -1312,
    6576, -1312,  5272,  6576,  8186, -1312, -1312,   440, -1312,   481,
   -1312, -1312, -1312, -1312,  1637,  7020, -1312, -1312,  1638,  7048,
   -1312, -1312,  1651,  7076, -1312,  1829,  2884,  1194,  5501,   930,
   -1312,   491,   934,  8212,  8238,  8264,  8290,  2194,  1834,  1652,
    9502,   954,  7104,  6576,   -78,   -78,   872,  1835,   872,  1839,
     872,  1840, -1312, -1312, -1312, -1312,   872,  1843,  6394,  1844,
    6576,  6576,  6576,  6576, -1312, -1312,  2389, -1312,  1655,  1846,
    7132,   499,   508,  1254, -1312,  1657,  1322, -1312,  1658,  1492,
   -1312,  1662,  1576, -1312,   957, -1312,  8316,  8342,  8368,  8394,
     960, -1312,  1685,  5272, -1312,  1849,  6576,  6576,  1876,   872,
    1877,   872,  1878,   872, -1312,  1879,  6576,  6576,  6576,  6576,
    2389,  1880,  2389,   961, -1312,  7160,  7188, -1312,  1716, -1312,
    1854, -1312,  2090, -1312,  7216,  7244,  7272,  7300, -1312, -1312,
     964, -1312,  1881,  1882,  1883,  1885,  1886,  1888, -1312, -1312,
   -1312, -1312,  2389,  1904, -1312, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1312, -1312, -1312, -1312,   816, -1312, -1312, -1312, -1312,   299,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312,  -382,  -100,    11,    -9, -1312,  1481, -1312, -1312,
   -1312, -1312, -1312,   424, -1312,   442, -1312, -1312, -1312, -1312,
   -1312, -1312,   813,  1917,    -2,  -479,  -250, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312,  1934, -1312, -1312, -1312, -1312, -1312,
   -1312, -1312, -1312, -1312, -1312, -1312, -1312, -1312,  -962,  -922,
   -1312, -1312,  1480, -1312,   434, -1312, -1312, -1312, -1312,  1517,
   -1312, -1312,    54, -1312, -1311,  2175,   722,  2052,   777,  -238,
     701, -1312,    21,    10, -1312,  -360,    -3,    42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -487
static const yytype_int16 yytable[] =
{
     106,    93,   479,   206,   609,   498,   611,   337,   633,   510,
     740,   741,   265,  1032,   619,   907,   180,   513,  1446,   211,
     647,   303,  1259,   306,  1362,   183,   257,   179,  1167,   206,
     187,   202,   200,   201,   880,  1661,   184,   211,   203,   892,
    1156,   532,   529,   315,   534,   107,   536,   220,   182,   317,
     221,   782,   338,   222,   268,  1158,   784,   487,   488,     4,
     786,   788,   297,  1160,  1165,   185,   567,   240,   569,  1162,
     339,   322,   570,  1309,   526,  1310,   268,   487,   488,   175,
     241,   242,  1268,   667,   270,   668,   271,   487,   488,  1668,
     175,  1501,  1670,  1311,   258,  1312,   487,   488,   259,   269,
       5,   244,   245,   248,   250,  1147,   256,   487,   488,   646,
     260,   246,  1313,   186,  1314,   646,   501,   328,   247,   193,
     329,   313,   189,   502,   489,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     202,   390,   272,   266,   196,   632,   373,   884,  1157,   375,
     214,   893,   894,   895,   896,   376,   377,   887,  1363,  1066,
     268,   382,   395,  1159,   669,   533,   530,  1553,   535,   670,
     537,  1161,   268,   268,   190,   908,   225,  1163,   207,   226,
     268,   227,   908,  1567,   646,   208,   511,   819,   268,  1033,
     297,  1302,  1303,   175,   267,   297,   427,   430,   307,   297,
     436,   212,   297,   304,   207,   393,   297,   297,   297,   297,
     188,   885,   297,   297,   297,  1662,   881,   429,   429,   886,
     733,   734,   897,   531,   316,   429,   297,   339,   191,   340,
     318,   341,   783,   437,   192,  1165,   175,   785,   871,   874,
     749,   787,   789,   194,   323,   487,   488,   197,   297,   297,
     297,   324,   487,   488,   195,   487,   488,  1236,   330,   331,
     332,   333,   297,   297,   330,   331,   332,   333,   204,   330,
     331,   332,   333,   391,   392,   297,   205,   297,   334,   335,
     634,   527,   426,   110,   198,   873,   199,   482,   483,   334,
     335,  1067,  1068,   334,   335,   491,   487,   488,   553,   499,
     804,   334,   335,  -484,   330,   331,   332,   333,  1183,   579,
     297,   297,   811,   490,   487,   488,   209,   136,   137,   138,
     139,   140,   141,   297,   334,   335,   145,   548,   210,   580,
     735,   147,   148,   149,   229,   236,   150,   230,   237,   213,
     231,  1701,   232,   330,   331,   332,   333,   155,   394,   487,
     488,   268,   268,   268,   268,   268,   268,   297,   268,   268,
     214,   268,   268,   334,   335,   742,   268,   268,   268,   268,
     268,   275,   487,   488,   276,   215,   610,   622,   612,   613,
     614,   216,   616,   617,   629,   261,   620,   262,   297,   500,
     624,   625,   626,   627,   637,   217,   429,   429,   429,   429,
     429,   429,   252,   429,   429,   253,   429,   429,   254,   487,
     488,   429,   429,   429,   429,   628,   330,   331,   332,   333,
     325,   218,   326,  1038,  1040,   748,   297,   334,   335,   327,
     158,   159,  1773,   487,   488,   219,   334,   335,   487,   488,
     487,   488,   166,    48,    49,    50,    51,   487,   488,  1143,
     487,   488,    56,   223,  1166,    59,  1441,   676,   487,   488,
     677,   297,   297,  1514,   334,   335,  1516,   714,   717,   720,
     723,  1047,   964,   548,  1518,   224,   825,   395,   395,   413,
     414,   415,   416,   417,   679,  1351,  1352,   677,   418,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     549,   416,   417,   297,   297,   297,   228,   418,   775,   244,
     245,   487,   488,   487,   488,   268,  1437,   487,   488,   246,
     872,   875,   487,   488,   487,   488,   255,  1526,   421,   297,
     422,   738,   739,  1528,   798,   238,   297,   327,  1529,   483,
    1633,   233,   239,  1581,   234,  1584,   235,  1587,   487,   488,
     487,   488,   334,   335,   685,  1202,   686,  1127,   243,  1129,
     776,  1131,  -485,  1133,  1636,   297,  1639,   264,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,   836,   251,
     838,   839,   840,   841,   842,   843,   844,   487,   488,   263,
     848,   850,   851,   273,   977,   487,   488,   334,   335,   671,
     399,   860,   400,  1647,   672,   978,   401,  -486,   868,   487,
     488,  1649,   674,   979,   980,   981,   274,   675,   883,   982,
     983,   984,   985,   538,   277,  1704,   539,   278,   685,   540,
     691,   541,   876,  1075,   297,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   549,   416,   417,  1165,
     487,   488,  1165,   418,   685,  1165,   695,   297,   300,   297,
     487,   488,   268,   825,   279,   268,  1705,   268,   487,   488,
     859,   297,   297,  1687,  1237,   675,  1718,   487,   488,   551,
     299,   552,   921,   301,  1756,   524,   915,   525,   327,   526,
    1250,   919,   174,  1757,   175,   297,  1164,   415,   416,   417,
     309,   302,  1568,  1569,   418,  1039,  1041,   429,  1570,   399,
     917,   400,   429,  1046,  1048,   578,   297,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   685,   977,   701,  1733,   418,  1736,  1203,  1739,   399,
     399,   400,   400,   978,  1742,   774,   797,   308,  1572,  1573,
     310,   979,   980,   981,  1570,  1165,   311,   982,   983,   984,
     985,   297,   399,   399,   400,   400,   866,   675,   849,   312,
     297,   867,   297,   399,   297,   400,   297,  1096,   685,   967,
    1460,   297,   685,   399,   297,   400,   973,  1778,  1227,  1780,
    1097,  1782,   988,  1091,  1092,   685,   685,   813,   792,   814,
     297,  1165,   977,   399,  1165,   400,   297,  1165,  1230,  1483,
    1165,   268,   314,   978,  1484,   399,   367,   400,  1425,  1426,
    1357,   979,   980,   981,   685,  1242,   889,   982,   983,   984,
     985,   378,   398,   403,  1325,  1049,   297,   685,   685,   960,
     961,   268,   297,   268,   268,   685,  1165,  1002,  1165,   685,
    1165,  1003,   368,   685,   268,  1004,   429,   685,  1059,  1020,
     685,  1103,  1043,  1104,  1109,  1055,  1110,  1057,  1058,   419,
    1082,   297,   297,   297,   297,   685,   369,  1140,  1063,   685,
     685,  1184,  1189,   685,   420,  1190,   429,   370,   429,   429,
     685,   685,  1191,  1192,   371,   685,   268,  1194,  1048,   429,
     424,  1100,  1101,   685,  1634,  1195,  1244,   372,  1245,   685,
     685,  1246,  1247,   297,   297,   685,   297,  1248,   297,   297,
    1095,   374,   297,   297,   685,   379,  1249,   297,   685,  1381,
    1286,  1382,   458,   459,   460,   380,   381,   463,   464,   465,
     383,   429,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,  1238,   977,   384,   445,
     418,   571,  1413,   685,  1414,  1450,  1102,   450,   978,  1461,
     442,   455,   456,   506,   507,   447,   979,   980,   981,   451,
     461,   462,   982,   983,   984,   985,   457,   519,   520,  1489,
     685,  1490,  1505,   685,   466,  1506,  1371,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   297,   297,   297,  1381,   418,  1527,   474,  1148,  1149,
    1150,  1576,   297,  1381,  1212,  1565,  1589,   685,  1590,  1605,
     477,  1217,  1218,  1219,  1220,  1221,  1607,   467,  1608,   108,
     319,  1228,  1231,   468,   469,   111,   112,   113,   470,   471,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   675,   472,  1610,   297,  1381,  1227,  1615,  1617,
     473,   142,   143,   144,  1230,   146,  1618,  1381,   685,  1621,
    1629,   685,   503,  1648,   297,   480,   151,   152,   153,  1265,
     297,   481,   492,  1546,   154,  1358,   297,   493,   297,   297,
    1489,   504,  1698,   297,   297,   685,   297,  1717,   297,   685,
     297,  1719,   297,   297,   297,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,  1381,
     297,  1728,   685,   418,  1765,  1770,  1381,  1771,  1792,  1802,
     505,  1803,   494,   977,   509,   297,  1609,   548,   512,   297,
     327,   297,   514,   515,   978,  1338,   516,   517,   645,   518,
     521,   522,   979,   980,   981,   523,  1343,   528,   982,   983,
     984,   985,   550,   554,   558,   560,   561,   157,   175,   565,
     160,   566,   568,   577,   582,   161,   162,   163,   164,   165,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   268,
    1324,   583,   586,   418,   635,   167,   168,   418,   636,   174,
     169,   638,   681,   682,   698,   289,  1360,  1358,   702,   703,
     173,  1547,   475,  1359,   704,   730,  1364,   297,   707,   708,
     977,   727,   728,   731,   732,   755,   757,   268,   758,   760,
     297,   978,   767,   768,   429,  1637,   773,   777,   802,   979,
     980,   981,   779,  1389,  1592,   982,   983,   984,   985,   780,
     781,  1386,   805,   812,   820,   821,   852,   853,   865,   977,
     854,   869,   870,   764,   765,   766,   297,   297,   855,   856,
     978,   857,   429,   864,   878,   395,   395,   879,   979,   980,
     981,   906,   911,  1420,   982,   983,   984,   985,   914,   790,
     916,   918,   925,   666,   297,  1392,   297,   922,   297,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     684,   416,   417,   297,     7,     8,   926,   418,   927,   977,
     297,  1469,  1640,   929,   297,   818,   931,   932,   297,   930,
     978,   935,  1465,  1427,   934,  1430,   936,  1433,   979,   980,
     981,  1472,  1475,  1476,   982,   983,   984,   985,   297,   945,
     940,  1444,   947,   950,  1447,  1448,   952,   949,   997,   951,
     953,  1714,  1024,   955,   963,  1025,  1688,   954,  1026,   297,
     956,   970,  1010,   971,   639,    24,    25,   640,    27,    28,
     641,    30,   642,    32,  1037,    33,  1065,   977,  1070,  1011,
      38,    39,  1013,    41,    42,    43,  1071,  1014,   978,    46,
    1015,  1035,  1027,  1073,  1074,   297,   979,   980,   981,  1077,
     297,  1083,   982,   983,   984,   985,  1090,   910,  1086,   912,
    1087,  1758,  1094,  1099,  1088,  1107,  1113,  1114,  1118,  1119,
     297,  1121,  1122,    67,    68,    69,   863,   297,  1125,  1152,
     268,  1126,  1135,     7,     8,  1136,  1137,  1138,  1139,  1141,
    1151,  1153,  1155,  1154,  1169,   297,  1168,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   297,  1170,  1171,   297,   418,   962,  1172,   395,  1174,
    1175,  1176,  1177,  1180,  1178,   429,  1181,  1199,  1204,  1760,
     297,  1207,  1205,   177,  1222,   297,  1209,  1211,  1213,   763,
    1214,  1215,  1216,   639,    24,    25,   640,    27,    28,   641,
      30,   642,    32,  1223,    33,  1224,  1225,  1226,  1234,    38,
      39,  1009,    41,    42,    43,  1239,  1240,  1251,    46,  1256,
    1016,  1258,  1017,  1257,  1018,  1261,  1019,   297,  1580,  1266,
    1583,  1022,  1586,  1267,  1023,  1269,  1270,  1271,  1275,  1276,
    1594,  1278,  1277,  1597,  1279,  1281,   297,   977,  1282,  1283,
    1284,  1289,    67,    68,    69,  1290,  1299,  1300,   978,  1301,
    1307,  1308,  1315,   320,   321,  1319,   979,   980,   981,  1320,
    1072,  1321,   982,   983,   984,   985,  1322,  1329,  1330,  1657,
    1334,  1337,  1344,  1623,  1345,  1346,  1054,  1627,  1350,  1353,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   297,  1354,   297,  1361,   418,  1367,
    1366,  1404,  1369,  1372,  1373,  1374,  1375,  1385,   809,   297,
    1393,  1078,  1079,  1080,  1081,  1394,  1395,  1398,  1400,  1402,
    1401,   977,  1403,  1407,  1408,  1409,  1667,  1410,  1411,  1412,
    1669,  1415,   978,  1428,   385,   386,   387,   388,   389,  1762,
     979,   980,   981,  1431,  1434,  1442,   982,   983,   984,   985,
    1445,   425,  1449,  1691,  1438,   431,  1452,  1724,  1477,  1468,
    1479,  1480,  1482,  1491,  1500,   297,  1481,  1120,  1502,   438,
     440,   443,   444,   268,   446,   440,   448,   449,  1488,   440,
     452,   453,  1117,  1503,  1504,  1509,   440,  1510,  1521,  1512,
    1513,  1515,  1517,  1519,  1523,  1530,  1524,  1751,  1536,  1541,
     297,  1542,  1543,  1555,   476,  1559,  1548,  1560,  1731,  1732,
    1561,  1562,  1563,   485,   486,  1564,  1566,   268,   429,   268,
    1588,  1595,   486,  1764,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,  1606,  1611,
    1612,  1788,   418,  1791,  1619,  1625,  1622,  1626,  1628,   268,
    1642,  1655,  1666,  1630,  1646,   543,   545,   440,  1643,  1671,
    1673,   977,   429,  1676,   429,  1677,  1680,   555,   556,   557,
    1681,   559,   978,  1810,   562,   563,  1684,  1685,   564,  1690,
     979,   980,   981,  1706,  1708,  1712,   982,   983,   984,   985,
    1725,  1734,   575,   576,   429,  1737,  1740,  1710,  1726,  1743,
    1745,  1753,  1754,  1759,  1761,  1774,   584,   585,  1763,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,  1772,  1777,  1779,  1781,  1783,  1789,  1804,  1805,  1806,
     618,  1807,  1808,   621,  1809,   623,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
    1811,  1658,  1260,  1795,   418,   644,   680,  1557,   440,  1273,
      92,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,  1558,   101,   664,   665,
    1574,  1368,     0,     0,     0,   710,     0,     0,     0,   977,
       0,  1333,     0,     0,     0,     0,   543,     0,     0,     0,
     978,     0,   689,     0,     0,     0,     0,   694,   979,   980,
     981,     0,   699,   700,   982,   983,   984,   985,   705,   706,
       0,     0,     0,   711,   713,   716,   719,   722,   724,   725,
     726,   440,   440,     0,     0,     0,     0,     0,     0,     0,
       0,  1173,     0,     0,     0,     0,     0,     0,     0,   743,
     744,   745,   385,   386,   746,     0,     0,     0,   750,   751,
     752,   753,   754,     0,     0,     0,   759,     0,   761,   762,
       0,     0,     0,   440,   440,   440,     0,     0,   769,   770,
     771,   584,   772,     7,     8,     0,     0,     0,   778,     0,
       0,  1796,     0,     0,     0,     0,     0,     0,     0,   440,
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
       0,  1235,    67,    68,    69,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,   905,   977,     0,   440,     0,   440,
     913,    67,    68,    69,     0,     0,   978,     0,   920,   110,
       0,   795,   923,  1241,   979,   980,   981,     0,     0,     0,
     982,   983,   984,   985,     0,   937,     0,     0,     0,     0,
       0,     0,     0,     0,   943,     0,     0,     0,   810,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   141,     0,
    1539,     0,   145,     0,     0,     0,   440,   147,   148,   149,
       0,     0,   150,   968,   969,   441,     0,   965,     0,   972,
     441,     0,     0,   155,   441,     0,     0,     0,     0,     0,
       0,   441,   996,     0,     0,   998,     0,     0,     0,     0,
       0,     0,     0,     0,  1575,     0,     0,  1797,     0,     0,
       0,   440,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,   440,     0,   440,  1596,   440,     0,     0,     0,
    1335,   440,     0,     0,   440,     0,     0,     0,     0,     0,
    1028,     0,  1030,  1031,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
     544,     0,   441,   418,     0,     0,   158,   159,     0,     0,
       0,     0,     0,     0,  1050,     0,     0,     0,   166,     0,
       0,     0,  1051,  1052,  1053,     0,   440,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,  1062,     0,     0,     0,   418,     0,     0,  1064,     0,
     454,  1069,     0,   426,   110,     0,     0,     0,     0,     0,
       0,   440,   440,   440,   440,     0,     0,  1355,  1084,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1689,     0,  1692,     0,   136,   137,
     138,   139,   140,   141,     0,     0,     0,   145,   508,     0,
       0,     0,   147,   148,   149,     0,     0,   150,     0,     0,
       0,     0,     0,   441,     0,     0,     0,   440,   155,     0,
       0,     0,     0,     0,     0,     0,     0,  1128,     0,  1130,
       0,  1132,     0,  1134,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,   544,   418,     0,     0,  1744,     0,     0,   573,   574,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   581,     0,     0,     0,   418,     0,     0,     0,     0,
       0,  1179,     0,     0,  1182,     0,   441,   441,  1185,  1356,
    1186,  1187,  1188,     0,     0,     0,     0,     0,  1193,     0,
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
       0,  1478,     0,   966,   639,    24,    25,   640,    27,    28,
     641,    30,   642,    32,  1365,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,  1378,    46,
       0,     0,     0,  1384,     0,     0,     0,  1508,     0,     0,
       0,   441,     0,     0,     0,     0,  1390,  1391,     0,     0,
       0,     0,     0,  1396,  1397,     0,     0,  1540,  1399,     0,
       0,     0,     0,    67,    68,    69,  1406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,   440,  1418,     0,
    1419,     0,   890,     0,     0,     0,   441,     0,     0,     0,
       0,     0,  1436,     0,     0,   441,     0,   441,     0,   441,
       0,   441,     0,  1654,   440,     0,   441,     0,   440,   441,
       0,  1451,     0,     0,     0,     0,  1453,  1454,  1455,  1456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1464,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1474,
       0,     0,     0,   944,     0,     0,     0,     0,     0,     0,
    1713,     0,     0,     0,     0,     0,  1485,  1486,     0,     0,
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
     417,  1697,     0,     0,   440,   418,     0,     0,     0,     0,
    1056,  1579,     0,  1582,     0,  1585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   440,     0,     0,     0,  1598,
    1599,  1600,  1601,  1602,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,  1613,  1614,
       0,     0,   418,  1616,     0,     0,     0,     0,     0,   548,
       0,     0,     0,  1620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1631,     0,     0,     0,     0,     0,
       0,  1105,  1106,     0,  1108,     0,  1111,  1112,     0,     0,
    1115,  1116,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,  1656,     0,     0,     0,   418,  1384,
       0,     0,     0,     0,     0,     0,  1664,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1675,   806,     0,  1679,     0,     0,  1683,     0,     0,     0,
    1686,     0,     0,     0,   440,     0,   440,  1693,  1694,  1695,
    1696,     0,     0,     0,     0,     0,     0,  1700,     0,     0,
    1702,     0,     0,     0,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   891,  1196,
    1197,  1198,   418,     0,     0,     0,     0,     0,     0,     0,
    1206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1730,     0,  1021,     0,     0,     0,   441,     0,     0,     0,
       0,     0,     0,     0,     0,   440,     0,  1746,  1747,  1748,
    1749,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   684,   416,   417,     0,     0,     0,     0,   418,
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
       0,     0,     0,     0,     0,     0,     0,  1255,  1201,     0,
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
     414,   415,   416,   417,     0,     0,     0,     0,   418,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   157,
       0,     0,   160,     0,  1577,     0,  1578,   161,   162,   163,
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

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1312)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,   240,     4,   364,   255,   366,   107,   390,     4,
     489,   490,     4,     7,   374,     6,     6,   267,  1329,     4,
     402,     4,     6,     4,     4,    13,     4,     6,   990,     4,
       6,   189,    21,    22,     4,     6,    78,     4,   196,     4,
       6,     5,     5,     5,     5,     3,     5,    72,     6,     5,
      75,     5,     4,    78,    57,     6,     5,   179,   180,     6,
       5,     5,    65,     6,   986,   189,   316,   136,   318,     6,
     189,     6,   191,   195,   193,   197,    79,   179,   180,   198,
     149,   150,     6,   191,     4,   193,     6,   179,   180,     6,
     198,  1402,     6,   195,    72,   197,   179,   180,    76,    57,
       0,   179,   180,    49,    50,   197,    52,   179,   180,     7,
      88,   189,   195,   189,   197,     7,   189,   106,   196,   189,
       7,    79,     6,   196,   196,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     189,     4,    72,   145,   191,     7,   145,   196,   124,   148,
     189,   126,   127,   128,   129,   154,   155,   196,   148,     4,
     173,   160,   174,   124,   190,   139,   139,  1488,   139,   195,
     139,   124,   185,   186,     6,   176,    75,   124,   189,    78,
     193,    80,   176,  1504,     7,   196,   191,   579,   201,   193,
     203,     6,     7,   198,   196,   208,   185,   186,   189,   212,
     200,   196,   215,   196,   189,   173,   219,   220,   221,   222,
     196,   196,   225,   226,   227,   196,   196,   185,   186,   196,
     480,   481,   197,   196,   196,   193,   239,   189,     6,   191,
     196,   193,   196,   201,     6,  1167,   198,   196,   630,   631,
     500,   196,   196,     6,   189,   179,   180,   191,   261,   262,
     263,   196,   179,   180,     6,   179,   180,     7,   166,   167,
     168,   169,   275,   276,   166,   167,   168,   169,   189,   166,
     167,   168,   169,   136,   137,   288,   189,   290,   186,   187,
     390,   280,     4,     5,   189,   193,   191,   243,   244,   186,
     187,   136,   137,   186,   187,   251,   179,   180,   297,   255,
     560,   186,   187,   196,   166,   167,   168,   169,   193,   328,
     323,   324,   572,   196,   179,   180,   189,    39,    40,    41,
      42,    43,    44,   336,   186,   187,    48,     8,   189,   329,
     195,    53,    54,    55,    72,    75,    58,    75,    78,   189,
      78,  1662,    80,   166,   167,   168,   169,    69,     4,   179,
     180,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     189,   374,   375,   186,   187,   195,   379,   380,   381,   382,
     383,    75,   179,   180,    78,    82,   365,   377,   367,   368,
     369,    78,   371,   372,   384,    78,   375,    80,   401,   196,
     379,   380,   381,   382,   393,    78,   364,   365,   366,   367,
     368,   369,    72,   371,   372,    75,   374,   375,    78,   179,
     180,   379,   380,   381,   382,   383,   166,   167,   168,   169,
     189,     6,   191,   815,   816,   195,   439,   186,   187,   198,
     152,   153,  1753,   179,   180,   196,   186,   187,   179,   180,
     179,   180,   164,    99,   100,   101,   102,   179,   180,   195,
     179,   180,   108,    78,   195,   111,   195,   192,   179,   180,
     195,   474,   475,   195,   186,   187,   195,   467,   468,   469,
     470,   193,   732,     8,   195,    78,   586,   489,   490,   179,
     180,   181,   182,   183,   192,     6,     7,   195,   188,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   516,   517,   518,    80,   188,   527,   179,
     180,   179,   180,   179,   180,   528,   197,   179,   180,   189,
     630,   631,   179,   180,   179,   180,   196,   195,   189,   542,
     191,   487,   488,   195,   553,   189,   549,   198,   195,   495,
     195,    75,    75,  1515,    78,  1517,    80,  1519,   179,   180,
     179,   180,   186,   187,   195,     8,   197,   949,   196,   951,
     528,   953,   196,   955,   195,   578,   195,    75,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   196,
     599,   600,   601,   602,   603,   604,   605,   179,   180,    78,
     609,   610,   611,    75,    95,   179,   180,   186,   187,   190,
     190,   620,   192,   195,   195,   106,   196,   196,   627,   179,
     180,   195,   190,   114,   115,   116,    78,   195,   637,   120,
     121,   122,   123,    72,     4,   195,    75,     4,   195,    78,
     197,    80,   632,   881,   647,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,  1581,
     179,   180,  1584,   188,   195,  1587,   197,   670,   189,   672,
     179,   180,   675,   773,     4,   678,   195,   680,   179,   180,
     190,   684,   685,  1645,  1066,   195,   195,   179,   180,   189,
       4,   191,   682,   189,   195,   189,   675,   191,   198,   193,
    1082,   680,   196,   195,   198,   708,   197,   181,   182,   183,
       6,   189,    99,   100,   188,   815,   816,   675,   105,   190,
     678,   192,   680,   823,   824,   196,   729,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   195,    95,   197,  1706,   188,  1708,   190,  1710,   190,
     190,   192,   192,   106,  1716,   196,   196,   189,    99,   100,
       6,   114,   115,   116,   105,  1687,   191,   120,   121,   122,
     123,   774,   190,   190,   192,   192,   190,   195,   195,     4,
     783,   195,   785,   190,   787,   192,   789,   190,   195,   735,
       8,   794,   195,   190,   797,   192,   742,  1759,   195,  1761,
     190,  1763,   748,   903,   904,   195,   195,   195,   197,   197,
     813,  1733,    95,   190,  1736,   192,   819,  1739,   195,   190,
    1742,   824,     4,   106,   195,   190,   189,   192,  1307,  1308,
    1212,   114,   115,   116,   195,  1073,   197,   120,   121,   122,
     123,     7,   196,     6,   197,   824,   849,   195,   195,   197,
     197,   854,   855,   856,   857,   195,  1778,   197,  1780,   195,
    1782,   197,   189,   195,   867,   197,   824,   195,   858,   197,
     195,    78,   197,    80,    78,   854,    80,   856,   857,   196,
     889,   884,   885,   886,   887,   195,   189,   197,   867,   195,
     195,   197,   197,   195,     6,   197,   854,   189,   856,   857,
     195,   195,   197,   197,   189,   195,   909,   197,  1008,   867,
       6,   920,   921,   195,   197,   197,   195,   189,   197,   195,
     195,   197,   197,   926,   927,   195,   929,   197,   931,   932,
     909,   189,   935,   936,   195,   189,   197,   940,   195,   195,
     197,   197,   220,   221,   222,   189,   189,   225,   226,   227,
     189,   909,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,  1066,    95,   189,   189,
     188,     6,     4,   195,     6,   197,   922,   189,   106,   197,
     203,   189,   196,   261,   262,   208,   114,   115,   116,   212,
     189,   189,   120,   121,   122,   123,   219,   275,   276,   195,
     195,   197,   197,   195,   189,   197,  1244,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,  1024,  1025,  1026,   195,   188,   197,   196,   974,   975,
     976,  1510,  1035,   195,  1043,   197,   195,   195,   197,   197,
       4,  1050,  1051,  1052,  1053,  1054,   195,   189,   197,     3,
       4,  1060,  1061,   189,   189,     9,    10,    11,   189,   189,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   195,   189,   197,  1088,   195,   195,   197,   197,
     189,    45,    46,    47,   195,    49,   197,   195,   195,   197,
     197,   195,   189,   197,  1107,   196,    60,    61,    62,  1099,
    1113,   196,   196,  1473,    68,  1215,  1119,   196,  1121,  1122,
     195,   189,   197,  1126,  1127,   195,  1129,   197,  1131,   195,
    1133,   197,  1135,  1136,  1137,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   195,
    1153,   197,   195,   188,   197,   195,   195,   197,   197,   195,
     189,   197,   196,    95,   189,  1168,     7,     8,   191,  1172,
     198,  1174,     6,     6,   106,  1184,   196,   196,   401,   196,
     191,   191,   114,   115,   116,   191,  1195,   191,   120,   121,
     122,   123,     6,     6,   193,   196,   139,   151,   198,     6,
     154,     6,     6,   196,     6,   159,   160,   161,   162,   163,
     175,   176,   177,   178,   179,   180,   181,   182,   183,  1222,
    1166,   191,     4,   188,   193,   179,   180,   188,     7,   196,
     184,   197,   195,   195,     7,   189,  1226,  1337,     6,     6,
     194,  1479,   196,  1222,     6,   190,  1236,  1250,     7,     7,
      95,   474,   475,     6,   196,     7,     6,  1260,     7,     6,
    1263,   106,     6,     6,  1222,   197,     4,    50,   136,   114,
     115,   116,    50,  1263,  1524,   120,   121,   122,   123,    50,
      50,  1260,   196,   190,     6,     6,   190,   190,   190,    95,
     195,   190,   190,   516,   517,   518,  1299,  1300,   195,   195,
     106,   195,  1260,   195,     6,  1307,  1308,     4,   114,   115,
     116,     4,     6,  1303,   120,   121,   122,   123,     6,   542,
       6,     6,   139,     6,  1327,  1271,  1329,     7,  1331,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,  1346,    12,    13,     7,   188,     7,    95,
    1353,  1360,   197,     7,  1357,   578,     7,     7,  1361,   139,
     106,     7,  1352,  1309,   139,  1311,     7,  1313,   114,   115,
     116,  1361,  1362,  1363,   120,   121,   122,   123,  1381,     4,
     196,  1327,     6,   195,  1330,  1331,   195,   190,     6,   190,
     190,   197,     7,   190,   193,     7,  1646,   195,     7,  1402,
     195,   197,   192,   197,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     6,    83,     6,    95,     6,   196,
      88,    89,   196,    91,    92,    93,     6,   196,   106,    97,
     196,   196,   193,     7,   191,  1438,   114,   115,   116,     6,
    1443,     6,   120,   121,   122,   123,     6,   670,   189,   672,
     189,   197,   176,     7,   196,     7,     7,    80,     7,     7,
    1463,     7,     7,   131,   132,   133,     6,  1470,     6,     6,
    1473,     7,     7,    12,    13,     7,     7,     7,     7,     4,
       4,   196,   189,     6,     6,  1488,     7,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,  1504,     7,     7,  1507,   188,   729,     7,  1510,   196,
       6,     6,     6,     6,    78,  1473,     6,     4,     4,   197,
    1523,   197,     4,     6,   195,  1528,     6,     6,     6,   197,
       6,     4,     6,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   190,    83,   190,   190,   195,   190,    88,
      89,   774,    91,    92,    93,   193,     7,   189,    97,   196,
     783,     6,   785,   193,   787,     6,   789,  1570,  1514,     6,
    1516,   794,  1518,     6,   797,   196,   196,    88,     6,   196,
    1526,     6,   196,  1529,     6,   196,  1589,    95,     6,     6,
       5,     4,   131,   132,   133,     6,   196,   196,   106,     7,
     196,   196,   191,    86,    87,     6,   114,   115,   116,     6,
       6,     6,   120,   121,   122,   123,     6,   196,   196,  1609,
     196,     4,     6,  1569,     6,   135,   849,  1573,     6,   195,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,  1647,     6,  1649,     4,   188,     4,
       6,   139,     6,     6,     6,     6,     6,     4,   197,  1662,
       6,   884,   885,   886,   887,     6,     6,     6,     5,   196,
       6,    95,     6,     6,     6,     6,  1622,     6,     6,     6,
    1626,     6,   106,     6,   167,   168,   169,   170,   171,   197,
     114,   115,   116,     6,     6,     6,   120,   121,   122,   123,
       6,   184,     6,  1649,   195,   188,     6,  1697,     6,   190,
       7,     6,     6,     6,     5,  1718,   193,   940,    76,   202,
     203,   204,   205,  1726,   207,   208,   209,   210,   196,   212,
     213,   214,     6,     6,   196,     6,   219,   196,     6,   197,
     197,   196,   196,   196,     7,     6,   196,  1726,   134,     6,
    1753,   197,     6,     6,   237,     6,   137,     6,  1704,  1705,
       6,     6,     6,   246,   247,     6,   196,  1770,  1726,  1772,
       6,     6,   255,   197,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,     6,     6,
     196,  1770,   188,  1772,   196,     6,   196,   196,     6,  1802,
       6,     6,     6,   197,   196,   288,   289,   290,    95,     6,
       6,    95,  1770,     6,  1772,     6,     6,   300,   301,   302,
       6,   304,   106,  1802,   307,   308,     6,   197,   311,     6,
     114,   115,   116,   196,   196,     6,   120,   121,   122,   123,
       6,     6,   325,   326,  1802,     6,     6,   196,   196,     6,
       6,   196,     6,   196,   196,     6,   339,   340,   196,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   196,     6,     6,     6,     6,     6,     6,     6,     6,
     373,     6,     6,   376,     6,   378,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       6,  1612,  1096,   197,   188,   398,   435,  1493,   401,  1106,
       3,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,  1494,     3,   421,   422,
    1506,  1240,    -1,    -1,    -1,   465,    -1,    -1,    -1,    95,
      -1,  1174,    -1,    -1,    -1,    -1,   439,    -1,    -1,    -1,
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
      41,    42,    43,    44,    -1,    -1,    -1,    48,   263,    -1,
      -1,    -1,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,   401,    -1,    -1,    -1,   940,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   950,    -1,   952,
      -1,   954,    -1,   956,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,   439,   188,    -1,    -1,  1718,    -1,    -1,   323,   324,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   336,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,  1004,    -1,    -1,  1007,    -1,   474,   475,  1011,     6,
    1013,  1014,  1015,    -1,    -1,    -1,    -1,    -1,  1021,    -1,
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
       6,    -1,    -1,    -1,    -1,    -1,  1379,  1380,    -1,    -1,
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
     183,     7,    -1,    -1,  1507,   188,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1662,     8,    -1,
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
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,   151,
      -1,    -1,   154,    -1,   195,    -1,   197,   159,   160,   161,
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
     166,   167,   168,   169,   186,   187,   221,   222,     4,   189,
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
     216,   218,   219,   190,   192,   278,     4,     6,   176,   203,
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
       6,   222,   222,   192,   176,   291,   190,   190,   195,     7,
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 192 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 203 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 210 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 211 "Gmsh.y"
    { return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 212 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 213 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 214 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 215 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 216 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 217 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 218 "Gmsh.y"
    { return 1; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 223 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 227 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 234 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 239 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 244 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
      FILE *fp = Fopen(tmp.c_str(), (yyvsp[(5) - (7)].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[(3) - (7)].c));
	fclose(fp);
      }
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 258 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 271 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 284 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(8) - (9)].c));
	FILE *fp = Fopen(tmp.c_str(), (yyvsp[(7) - (9)].c));
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmp.c_str());
	}
	else{
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
      List_Delete((yyvsp[(5) - (9)].l));
    }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 312 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (6)].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[(2) - (6)].c));
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
	new PView(ViewData);
      }
      else
	delete ViewData;
#endif
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 326 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 339 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 352 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (8)].c), "View")){
	int index = (int)(yyvsp[(4) - (8)].d), index2 = (int)(yyvsp[(6) - (8)].d);
	if(index >= 0 && index < (int)PView::list.size() &&
           index2 >= 0 && index2 < (int)PView::list.size()){
          PView::list[index2]->setOptions(PView::list[index]->getOptions());
        }
        else
	  yymsg(0, "Unknown view %d or %d", index, index2);
      }
#endif
      Free((yyvsp[(2) - (8)].c));
    }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 370 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 384 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 386 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 391 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 393 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 398 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strncmp((yyvsp[(1) - (1)].c), "SP", 2)){
	ViewValueList = &ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VP", 2)){
	ViewValueList = &ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TP", 2)){
	ViewValueList = &ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SL", 2)){
	ViewValueList = &ViewData->SL; ViewNumList = &ViewData->NbSL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VL", 2)){
	ViewValueList = &ViewData->VL; ViewNumList = &ViewData->NbVL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TL", 2)){
	ViewValueList = &ViewData->TL; ViewNumList = &ViewData->NbTL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "ST", 2)){
	ViewValueList = &ViewData->ST; ViewNumList = &ViewData->NbST;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VT", 2)){
	ViewValueList = &ViewData->VT; ViewNumList = &ViewData->NbVT;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TT", 2)){
	ViewValueList = &ViewData->TT; ViewNumList = &ViewData->NbTT;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SQ", 2)){
	ViewValueList = &ViewData->SQ; ViewNumList = &ViewData->NbSQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VQ", 2)){
	ViewValueList = &ViewData->VQ; ViewNumList = &ViewData->NbVQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TQ", 2)){
	ViewValueList = &ViewData->TQ; ViewNumList = &ViewData->NbTQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SS", 2)){
	ViewValueList = &ViewData->SS; ViewNumList = &ViewData->NbSS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VS", 2)){
	ViewValueList = &ViewData->VS; ViewNumList = &ViewData->NbVS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TS", 2)){
	ViewValueList = &ViewData->TS; ViewNumList = &ViewData->NbTS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SH", 2)){
	ViewValueList = &ViewData->SH; ViewNumList = &ViewData->NbSH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VH", 2)){
	ViewValueList = &ViewData->VH; ViewNumList = &ViewData->NbVH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TH", 2)){
	ViewValueList = &ViewData->TH; ViewNumList = &ViewData->NbTH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SI", 2)){
	ViewValueList = &ViewData->SI; ViewNumList = &ViewData->NbSI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VI", 2)){
	ViewValueList = &ViewData->VI; ViewNumList = &ViewData->NbVI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TI", 2)){
	ViewValueList = &ViewData->TI; ViewNumList = &ViewData->NbTI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SY", 2)){
	ViewValueList = &ViewData->SY; ViewNumList = &ViewData->NbSY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VY", 2)){
	ViewValueList = &ViewData->VY; ViewNumList = &ViewData->NbVY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TY", 2)){
	ViewValueList = &ViewData->TY; ViewNumList = &ViewData->NbTY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else{
	yymsg(0, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoord.clear();
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 502 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 521 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 528 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 538 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 547 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 556 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 563 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 573 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 581 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 591 "Gmsh.y"
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
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (8)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (8)].l)));
#endif
    }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 610 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(9) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(12) - (14)].l)));
#endif
    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 629 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 635 "Gmsh.y"
    {
    }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 642 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 643 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 644 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 645 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 646 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 650 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 657 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 657 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 658 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 658 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 667 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 672 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 678 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c)) && (yyvsp[(2) - (4)].i) && List_Nbr((yyvsp[(3) - (4)].l)) == 1){
        yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if(!(yyvsp[(2) - (4)].i)) s.list = (List_Nbr((yyvsp[(3) - (4)].l)) != 1); // list if 0 or > 1 elements
        if(!s.list){ // single expression
          if(List_Nbr((yyvsp[(3) - (4)].l)) != 1){
            yymsg(0, "Cannot assign list to variable '%s'", (yyvsp[(1) - (4)].c));
          }
          else{
            double d;
            List_Read((yyvsp[(3) - (4)].l), 0, &d);
            if(s.value.empty()){
              if((yyvsp[(2) - (4)].i)) yymsg(1, "Uninitialized variable '%s'", (yyvsp[(1) - (4)].c));
              s.value.resize(1, 0.);
            }
            switch((yyvsp[(2) - (4)].i)){
            case 0 : s.value[0] = d; break;
            case 1 : s.value[0] += d; break;
            case 2 : s.value[0] -= d; break;
            case 3 : s.value[0] *= d; break;
            case 4 :
              if(d) s.value[0] /= d;
              else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), d);
              break;
            }
          }
        }
        else{ // list of expressions
          switch((yyvsp[(2) - (4)].i)){
          case 0: // affect
            s.value.clear(); // fall-through
          case 1: // append
            for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
              double d;
              List_Read((yyvsp[(3) - (4)].l), i, &d);
              s.value.push_back(d);
            }
            break;
          case 2: // remove
            for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
              double d;
              List_Read((yyvsp[(3) - (4)].l), i, &d);
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
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 738 "Gmsh.y"
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
      s.list = true;
      double d;
      switch((yyvsp[(4) - (6)].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 767 "Gmsh.y"
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
      s.list = true;
      double d;
      switch((yyvsp[(4) - (6)].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 796 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 801 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 806 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 811 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 816 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 823 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 830 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
        if(!s.list && s.value.empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (3)].c));
        else if(!s.list)
          s.value[0] += (yyvsp[(2) - (3)].i);
        else
          yymsg(0, "Variable '%s' is a list", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 845 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 850 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 855 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 860 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 865 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 874 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 880 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 889 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), d)){
	switch((yyvsp[(4) - (6)].i)){
	case 0 : d = (yyvsp[(5) - (6)].d); break;
	case 1 : d += (yyvsp[(5) - (6)].d); break;
	case 2 : d -= (yyvsp[(5) - (6)].d); break;
	case 3 : d *= (yyvsp[(5) - (6)].d); break;
	case 4 :
	  if((yyvsp[(5) - (6)].d)) d /= (yyvsp[(5) - (6)].d);
	  else yymsg(0, "Division by zero in '%s.%s /= %g'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), d);
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 907 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), d)){
	switch((yyvsp[(7) - (9)].i)){
	case 0 : d = (yyvsp[(8) - (9)].d); break;
	case 1 : d += (yyvsp[(8) - (9)].d); break;
	case 2 : d -= (yyvsp[(8) - (9)].d); break;
	case 3 : d *= (yyvsp[(8) - (9)].d); break;
	case 4 :
	  if((yyvsp[(8) - (9)].d)) d /= (yyvsp[(8) - (9)].d);
	  else yymsg(0, "Division by zero in '%s[%d].%s /= %g'", (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), d);
      }
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 925 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 934 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 946 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 951 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 959 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable(0);
      if(!ct)
	yymsg(0, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[(5) - (6)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[(5) - (6)].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 979 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable((int)(yyvsp[(3) - (9)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (9)].d));
      else{
	ct->size = List_Nbr((yyvsp[(8) - (9)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)(yyvsp[(3) - (9)].d));
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[(8) - (9)].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 1002 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[(4) - (5)].d));
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[(4) - (5)].d));
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 1013 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 1021 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->numericalValue((yyvsp[(8) - (9)].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
#endif
      Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 1043 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string((yyvsp[(8) - (9)].c)); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
#endif
      Free((yyvsp[(6) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 1066 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  std::list<int> vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	    double id;
	    List_Read((yyvsp[(9) - (11)].l), i, &id);
	    vl.push_back((int)id);
	  }
          option->list(vl);
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (11)].c), (int)(yyvsp[(3) - (11)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (11)].d));
#endif
      Free((yyvsp[(6) - (11)].c));
      List_Delete((yyvsp[(9) - (11)].l));
    }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 1092 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (7)].d));
      if(field){
        FieldCallback *callback = field->callbacks[(yyvsp[(6) - (7)].c)];
        if(callback) {
          callback->run();
        }
        else
          yymsg(0, "Unknown callback '%s' in field %i of type '%s'",
              (yyvsp[(6) - (7)].c), (int)(yyvsp[(3) - (7)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (7)].d));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 1113 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 1125 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1143 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 1152 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1161 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1163 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[(6) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(6) - (9)].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].l));
    }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1179 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1188 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1190 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 1204 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1212 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1218 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1230 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
        double v;
        List_Read((yyvsp[(3) - (3)].l), i, &v);
        floatOptions[key].push_back(v);
      }
      Free((yyvsp[(2) - (3)].c));
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 1241 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[(4) - (5)].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[(4) - (5)].l), i))->s);
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1256 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1272 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1280 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1289 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1297 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        char *s;
        List_Read((yyvsp[(4) - (5)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(2) - (5)].c));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1315 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1325 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1333 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1337 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1343 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1351 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1355 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1361 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1369 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1373 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1379 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1387 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1391 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[(4) - (5)].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[(4) - (5)].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1403 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1407 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1417 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
	yymsg(0, "Point %d already exists", num);
      }
      else{
	double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
	double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
	double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
	double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
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
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1440 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1472 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v){
	  v->lc = (yyvsp[(5) - (6)].d);
        }
	else{
	  GVertex *gv = GModel::current()->getVertexByTag((int)d);
	  if(gv)
	    gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1495 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1513 "Gmsh.y"
    {
      for (int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
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
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1534 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1552 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          c->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          c->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          c->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          rc->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          rc->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          rc->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1582 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          c->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          c->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          c->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          rc->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          rc->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          rc->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1612 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1630 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1649 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      if(List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1 != List_Nbr((yyvsp[(8) - (11)].l))){
	yymsg(0, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[(3) - (11)].d), List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(6) - (11)].l)), (int)(yyvsp[(10) - (11)].d), List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(0, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (11)].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)(yyvsp[(10) - (11)].d), temp, (yyvsp[(8) - (11)].l),
				  -1, -1, 0., 1.);
	  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1675 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindEdgeLoop(num)){
	yymsg(0, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1693 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        Curve *c = Create_Curve(num, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++)
          c->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	End_Curve(c);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1711 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1746 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1764 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (9)].d), type = 0;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[(7) - (9)].l), 0, &d);
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
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  s->InSphereCenter = (yyvsp[(8) - (9)].l);
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1803 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1809 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1815 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1822 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(0, "Sphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
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
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1847 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(0, "PolarSphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
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
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1872 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurfaceLoop(num)){
	yymsg(0, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1889 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	}
        // Added by Trevor Strickler
	setSurfaceGeneratrices(s, (List_T*) 0 );
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1909 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (12)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
        Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (12)].l)); i++)
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (12)].l), i));
	for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
          if(i > 3){
            yymsg(0, "Too many boundary specifiers in compound surface");
            break;
          }
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i);
          for (int j = 0; j < List_Nbr(l); j++){
            s->compoundBoundary[i].push_back((int)*(double*)List_Pointer(l, j));
	  }
	}
        // Added by Trevor Strickler
        setSurfaceGeneratrices(s, (List_T*) 0 );

	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (12)].l));
      for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
      List_Delete((yyvsp[(10) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1942 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1978 "Gmsh.y"
    {
      yymsg(0, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1996 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 2013 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++)
          v->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2029 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2066 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2071 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2076 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2081 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2086 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 2091 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          List_Add((yyval.l), &TheShape);
        }
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "Boundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), false);
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), true);
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 2114 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 2120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 2130 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 2131 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 2136 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 2140 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 2144 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
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
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 2167 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
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
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 2190 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
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
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 2213 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
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
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 2241 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(7) - (8)].l)) == 4){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[(7) - (8)].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
#endif
    }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 2262 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      int t = (int)(yyvsp[(4) - (10)].d);
      if(FindLevelSet(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	//Msg::Info("nb = %d \n",List_Nbr($8) );
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    //Msg::Info("nb j = %d \n",List_Nbr(l) );
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        LevelSet *l = Create_LevelSet(ls->getTag(), ls);
        Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i));
      List_Delete((yyvsp[(8) - (10)].l));
#endif
    }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 2289 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 0){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double n[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt, n, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
#endif
    }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 2310 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(14) - (16)].l)) == 0){
        int t = (int)(yyvsp[(4) - (16)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt1[3] = {(yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2]};
          double pt2[3] = {(yyvsp[(10) - (16)].v)[0], (yyvsp[(10) - (16)].v)[1], (yyvsp[(10) - (16)].v)[2]};
          double pt3[3] = {(yyvsp[(12) - (16)].v)[0], (yyvsp[(12) - (16)].v)[1], (yyvsp[(12) - (16)].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (16)].d));
#endif
    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 2331 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(10) - (12)].l)) == 1){
        int t = (int)(yyvsp[(4) - (12)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(10) - (12)].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (12)].d));
#endif
    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 2351 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Intersection")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Cut")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Crack")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Crack %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCrack(vl);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Reverse")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(7) - (8)].l), 0, &d);
          LevelSet *pl = FindLevelSet((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Levelset Reverse %d : unknown levelset %d", t, (int)d);
          else ls = new gLevelsetReverse(pl->ls);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[(2) - (8)].c), "PostView")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[(7) - (8)].l)) > 0){
            double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            LevelSet *l = Create_LevelSet(ls->getTag(), ls);
            Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
      Free((yyvsp[(2) - (8)].c));
#endif
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2463 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "MathEval")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[(7) - (8)].c), t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (8)].c)); Free((yyvsp[(7) - (8)].c));
#endif
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2482 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, false);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "CutMeshTri")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
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
      Free((yyvsp[(2) - (6)].c));
#endif
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2521 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cone") && List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 2){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Ellipsoid") && List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Quadric") && List_Nbr((yyvsp[(12) - (14)].l)) == 5){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[5];
          for(int i = 0; i < 5; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGeneralQuadric(pt, dir, d[0], d[1],
                                                      d[2], d[3], d[4], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
      Free((yyvsp[(2) - (14)].c));
#endif
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2629 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2638 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2644 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[(2) - (6)].c));
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 2659 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	GModel::current()->getGEOInternals()->reset_physicals();
	GModel::current()->deletePhysicalGroups();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Variables")){
	gmsh_yysymbols.clear();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Options")){
        ReInitOptions(0);
        InitOptionsGUI(0);
      }
      else{
	if(gmsh_yysymbols.count((yyvsp[(2) - (3)].c)))
	  gmsh_yysymbols.erase((yyvsp[(2) - (3)].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[(2) - (3)].c));
      }
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 2687 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (4)].c), "Empty") && !strcmp((yyvsp[(3) - (4)].c), "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(0, "Unknown command 'Delete %s %s'", (yyvsp[(2) - (4)].c), (yyvsp[(3) - (4)].c));
#endif
      Free((yyvsp[(2) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 2704 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 2713 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 2727 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 2741 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 2747 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2753 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 2762 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2771 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2780 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2794 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "Print")){
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	MergeFile(tmp, true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "NonBlockingSystemCall")){
	SystemCall((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "System") || !strcmp((yyvsp[(1) - (3)].c), "SystemCall")){
	SystemCall((yyvsp[(2) - (3)].c), true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName")){
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "CreateDir")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateSingleDir(tmp);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "OnelabRun")){
        Msg::RunOnelabClient((yyvsp[(2) - (3)].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2850 "Gmsh.y"
    {
      int n = List_Nbr((yyvsp[(3) - (5)].l));
      if(n == 1){
        char *s; List_Read((yyvsp[(3) - (5)].l), 0, &s);
        Msg::RunOnelabClient(s);
        Free(s);
      }
      else if(n == 2){
        char *s, *t; List_Read((yyvsp[(3) - (5)].l), 0, &s); List_Read((yyvsp[(3) - (5)].l), 1, &t);
        Msg::RunOnelabClient(s, t);
        Free(s); Free(t);
      }
      else{
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      List_Delete((yyvsp[(3) - (5)].l));
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2868 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2885 "Gmsh.y"
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->setBackgroundMesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2900 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")){
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
	GModel::current()->importGEOInternals();
	GModel::current()->mesh((int)(yyvsp[(2) - (3)].d));
	CTX::instance()->lock = lock;
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2919 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[(3) - (7)].c), (yyvsp[(6) - (7)].c), 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", (yyvsp[(6) - (7)].c), (yyvsp[(3) - (7)].c));
       }
#endif
       Free((yyvsp[(3) - (7)].c)); Free((yyvsp[(6) - (7)].c));
     }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2931 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2955 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2959 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 2964 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 2971 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 2976 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 2982 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 2987 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 2993 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3001 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3005 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3009 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      int lock = CTX::instance()->lock;
      CTX::instance()->lock = 0;
      std::vector<int> technique;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (16)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (16)].l), i, &d);
        technique.push_back((int)d);
      }
      if(technique.empty()){
        yyerror("Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (16)].l)); i++){
          double d;
          List_Read((yyvsp[(6) - (16)].l), i, &d);
          LevelSet *l = FindLevelSet((int)d);
          if(l) f.push_back(l->ls);
          else yymsg(0, "Unknown Levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yyerror("Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[(9) - (16)].l)) != (int)f.size()){
            yyerror("Number of parameters != number of levelsets");
          }
          else{
            std::vector<std::vector<double> > parameters;
            parameters.resize(List_Nbr((yyvsp[(9) - (16)].l)));
            for(int i = 0; i < List_Nbr((yyvsp[(9) - (16)].l)); i++){
              List_T *l = *(List_T**)List_Pointer((yyvsp[(9) - (16)].l), i);
              for(int j = 0; j < List_Nbr(l); j++){
                double d;
                List_Read(l, j, &d);
                parameters[i].push_back(d);
              }
            }
            int niter = (int)(yyvsp[(12) - (16)].d);
            bool meshAll = ((yyvsp[(14) - (16)].d) == 0) ? false : true;
            GModel::current()->importGEOInternals();
            GModel::current()->adaptMesh(technique, f, parameters, niter, meshAll);
          }
        }
      }
      List_Delete((yyvsp[(3) - (16)].l));
      List_Delete((yyvsp[(6) - (16)].l));
      for(int i = 0; i < List_Nbr((yyvsp[(9) - (16)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(9) - (16)].l), i));
      List_Delete((yyvsp[(9) - (16)].l));
      CTX::instance()->lock = lock;
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3069 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3082 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3099 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3116 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[(2) - (8)].c));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[(2) - (10)].c));
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3160 "Gmsh.y"
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
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3195 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3203 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3209 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3216 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3220 "Gmsh.y"
    {
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3229 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3237 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3253 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3267 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3281 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3287 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3295 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3301 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3309 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3323 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3330 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3337 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3344 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3351 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3358 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3365 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3372 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3378 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3385 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3391 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3398 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3404 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3411 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3417 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3424 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3430 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3437 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3443 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3450 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3456 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3463 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3469 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3476 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3482 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3493 "Gmsh.y"
    {
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3496 "Gmsh.y"
    {
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3502 "Gmsh.y"
    {
      int n = (int)fabs((yyvsp[(3) - (5)].d));
      if(n){ // we accept n==0 to easily disable layers
        extr.mesh.ExtrudeMesh = true;
        extr.mesh.NbLayer = 1;
        extr.mesh.NbElmLayer.clear();
        extr.mesh.hLayer.clear();
        extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
        extr.mesh.hLayer.push_back(1.);
      }
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3514 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (7)].l));
      if(List_Nbr((yyvsp[(3) - (7)].l)) == List_Nbr((yyvsp[(5) - (7)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
	  double d;
	  List_Read((yyvsp[(3) - (7)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(5) - (7)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d}", List_Nbr((yyvsp[(3) - (7)].l)), List_Nbr((yyvsp[(5) - (7)].l)));
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3534 "Gmsh.y"
    {
      yymsg(0, "Explicit region numbers in layers are deprecated");
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (9)].l));
      if(List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(5) - (9)].l)) && List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(7) - (9)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	  double d;
	  List_Read((yyvsp[(3) - (9)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(7) - (9)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d, %d}", List_Nbr((yyvsp[(3) - (9)].l)),
	      List_Nbr((yyvsp[(5) - (9)].l)), List_Nbr((yyvsp[(7) - (9)].l)));
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(5) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3558 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3562 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3566 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3570 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3574 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3580 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3586 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3590 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3594 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3598 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3602 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
	extr.mesh.Holes[num].second.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(6) - (9)].l)); i++){
	  double d;
	  List_Read((yyvsp[(6) - (9)].l), i, &d);
	  extr.mesh.Holes[num].second.push_back((int)d);
	}
      }
      List_Delete((yyvsp[(6) - (9)].l));
    }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 3621 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3633 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3637 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Progression") || !strcmp((yyvsp[(2) - (3)].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump"))
        (yyval.v)[0] = 2.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[(3) - (3)].d);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 3652 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3656 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
	(yyval.i) = -1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "AlternateRight"))
	(yyval.i) = 2;
      else if(!strcmp((yyvsp[(1) - (1)].c), "AlternateLeft"))
	(yyval.i) = -2;
      else // "Alternate" -> "Alternate Right"
	(yyval.i) = 2;
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 3672 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3676 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 3681 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 3685 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3691 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 3695 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 3702 "Gmsh.y"
    {
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
      if(!(yyvsp[(3) - (7)].l)){
        List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->Method = MESH_TRANSFINITE;
            c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            c->typeTransfinite = type;
            c->coeffTransfinite = coef;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.method = MESH_TRANSFINITE;
            (*it)->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            (*it)->meshAttributes.typeTransfinite = type;
            (*it)->meshAttributes.coeffTransfinite = coef;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (7)].l), i, &d);
          int j = (int)fabs(d);
          for(int sign = -1; sign <= 1; sign += 2){
            Curve *c = FindCurve(sign * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
              c->typeTransfinite = type * sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sign * j);
              if(ge){
                ge->meshAttributes.method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
                ge->meshAttributes.typeTransfinite = type * sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sign > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete((yyvsp[(3) - (7)].l));
      }
    }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 3758 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (6)].l));
      if(k != 0 && k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface: 0, 3 or 4 points needed");
      }
      else{
        if(!(yyvsp[(3) - (6)].l)){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Surface *s;
              List_Read(tmp, i, &s);
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[(5) - (6)].i);
              List_Reset(s->TrsfPoints);
            }
          }
          else{
            for(GModel::fiter it = GModel::current()->firstFace();
                it != GModel::current()->lastFace(); it++){
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
              (*it)->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (6)].l), i, &d);
            Surface *s = FindSurface((int)d);
            if(s){
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[(5) - (6)].i);
              List_Reset(s->TrsfPoints);
              for(int j = 0; j < k; j++){
                double p;
                List_Read((yyvsp[(4) - (6)].l), j, &p);
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
                gf->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
                for(int j = 0; j < k; j++){
                  double p;
                  List_Read((yyvsp[(4) - (6)].l), j, &p);
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
          List_Delete((yyvsp[(3) - (6)].l));
        }
      }
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 3828 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 3833 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (5)].l));
      if(k != 0 && k != 6 && k != 8){
        yymsg(0, "Wrong definition of Transfinite Volume: "
              "%d points instead of 6 or 8", k);
      }
      else{
        if(!(yyvsp[(3) - (5)].l)){
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
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (5)].l), i, &d);
            Volume *v = FindVolume((int)d);
            if(v){
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
              for(int i = 0; i < k; i++){
                double p;
                List_Read((yyvsp[(4) - (5)].l), i, &p);
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
                  List_Read((yyvsp[(4) - (5)].l), i, &p);
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
          List_Delete((yyvsp[(3) - (5)].l));
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 3900 "Gmsh.y"
    {
      if(!(yyvsp[(2) - (3)].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[(2) - (3)].l)); i++){
          double d;
          List_Read((yyvsp[(2) - (3)].l), i, &d);
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
        List_Delete((yyvsp[(2) - (3)].l));
      }
    }
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 3936 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 3944 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (5)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.recombine = 1;
            (*it)->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[(4) - (5)].i);
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.recombine = 1;
              gf->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
    }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 3987 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
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
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 4026 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (6)].l), i, &d);
        int j = (int)d;
        Surface *s = FindSurface(j);
        if(s){
          s->TransfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(j);
          if(gf)
            gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
          else
            yymsg(1, "Unknown surface %d", (int)(yyvsp[(5) - (6)].d));
        }
      }
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 4047 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[(10) - (11)].l)) != 0) {
          if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr((yyvsp[(10) - (11)].l)));
          }
          else {
            transfo.resize(List_Nbr((yyvsp[(10) - (11)].l)));
            for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++)
              List_Read((yyvsp[(10) - (11)].l), i, &transfo[i]);
          }
        }
        for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (11)].l), i, &d_master);
          List_Read((yyvsp[(4) - (11)].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          addPeriodicEdge(j_slave, j_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4079 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
        }
        else {
          std::vector<double> transfo(16,0);
          for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++)
            List_Read((yyvsp[(10) - (11)].l), i, &transfo[i]);
          for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
            double d_master, d_slave;
            List_Read((yyvsp[(8) - (11)].l), i, &d_master);
            List_Read((yyvsp[(4) - (11)].l), i, &d_slave);
            addPeriodicFace(d_slave,d_master,transfo);
          }
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 4106 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (18)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (18)].l), i, &d_master);
          List_Read((yyvsp[(4) - (18)].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 4132 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (18)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (18)].l), i, &d_master);
          List_Read((yyvsp[(4) - (18)].l), i, &d_slave);
          addPeriodicFace(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4158 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (12)].l), i, &d_master);
          List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4184 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (12)].l), i, &d_master);
          List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
          addPeriodicFace(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4210 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
          double ds,dm;
          List_Read((yyvsp[(5) - (12)].l),i,&ds);
          List_Read((yyvsp[(10) - (12)].l),i,&dm);
          edgeCounterParts[(int) ds] = (int) dm;
        }
        addPeriodicFace(j_slave,j_master,edgeCounterParts);
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4231 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
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
          yymsg(0, "Unknown surface %d", (int)(yyvsp[(8) - (10)].d));
      }
    }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4259 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
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
          yymsg(0, "Unknown surface %d", (int)(yyvsp[(8) - (10)].d));
      }
    }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 4287 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4291 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4295 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedSurfaces(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
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
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4323 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
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
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4362 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
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
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4401 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::viter it = GModel::current()->firstVertex();
            it != GModel::current()->lastVertex(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GVertex *gv = GModel::current()->getVertexByTag((int)d);
          if(gv){
            gv->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown point %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4422 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GEdge *ge = GModel::current()->getEdgeByTag((int)d);
          if(ge){
            ge->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown line %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4443 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GFace *gf = GModel::current()->getFaceByTag((int)d);
          if(gf){
            gf->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown surface %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4470 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4474 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4484 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (6)].l)) >= 2){
        double d;
        List_Read((yyvsp[(4) - (6)].l), 0, &d);
        Vertex *target = FindPoint((int)d);
        if(!target)
          yymsg(0, "Could not find Point %d", (int)d);
        else{
          double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
          for(int i = 1; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
            List_Read((yyvsp[(4) - (6)].l), i, &d);
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
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4518 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4519 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4520 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4525 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4531 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (5)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (5)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (5)].l));
    }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4543 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (7)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (7)].l)); i++){
        double d;
        List_Read((yyvsp[(5) - (7)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4561 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(6) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(6) - (10)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (10)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (10)].l), i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[(1) - (10)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(6) - (10)].l));
      List_Delete((yyvsp[(8) - (10)].l));
      List_Delete((yyvsp[(3) - (10)].l));
    }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4588 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4589 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4590 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4591 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4592 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4593 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4594 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4595 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4597 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4603 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4604 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4605 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4606 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4607 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4608 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4609 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4610 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4611 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4612 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4613 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4614 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4615 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4616 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4617 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4618 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4619 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4621 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4622 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4623 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4624 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4625 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4626 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4627 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4629 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4630 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4631 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4632 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4633 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4634 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4635 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4644 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 4645 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 4646 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4647 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4648 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4649 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4650 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 4651 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4652 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4653 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4658 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4660 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4666 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4671 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (1)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4688 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4706 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4724 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4742 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4760 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4765 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4771 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (4)].c)]);
	(yyval.d) = s.value.size();
      }
      Free((yyvsp[(2) - (4)].c));
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4783 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (2)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (2)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[0] += (yyvsp[(2) - (2)].i));
      }
      Free((yyvsp[(1) - (2)].c));
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4800 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4818 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4836 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4854 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4875 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4880 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4885 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d)){
	d += (yyvsp[(4) - (4)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4895 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d)){
	d += (yyvsp[(7) - (7)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4905 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4910 "Gmsh.y"
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (6)].l), i, &d);
        matches += List_Search((yyvsp[(5) - (6)].l), &d, fcmp_double);
      }
      (yyval.d) = matches;
      Free((yyvsp[(3) - (6)].l)); Free((yyvsp[(5) - (6)].l));
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4921 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4930 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4935 "Gmsh.y"
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[(3) - (4)].l)) % 2){
        yyerror("Number of text attributes should be even");
      }
      else{
        for(int i = 0 ; i < List_Nbr((yyvsp[(3) - (4)].l)); i += 2){
          char *s1, *s2; List_Read((yyvsp[(3) - (4)].l), i, &s1); List_Read((yyvsp[(3) - (4)].l), i + 1, &s2);
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
      List_Delete((yyvsp[(3) - (4)].l));
      (yyval.d) = (double)((align<<16)|(font<<8)|(fontsize));
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4962 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4966 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4970 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4974 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4978 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4985 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4989 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4993 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4997 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 5004 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 5009 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 5016 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 5021 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 5025 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 5030 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 5034 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 5042 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 5053 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 5057 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 5069 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 5077 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 5085 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5092 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   }
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 5102 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
        GVertex *gv = GModel::current()->getVertexByTag((int)(yyvsp[(3) - (4)].d));
        if(gv){
          double x = gv->x(), y = gv->y(), z = gv->z();
          List_Add((yyval.l), &x);
          List_Add((yyval.l), &y);
          List_Add((yyval.l), &z);
        }
        else{
          yymsg(0, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
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
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5131 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5135 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5139 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5143 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5147 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5151 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5155 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5159 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5163 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
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
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5192 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
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
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5221 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
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
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5250 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
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
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5280 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 0);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5293 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 1);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5306 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 2);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5319 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 3);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5331 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5341 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5351 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5363 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5376 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(3) - (4)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(3) - (4)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(3) - (4)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5388 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5406 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5427 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5432 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5436 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5440 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 5452 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5456 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5468 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5475 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5485 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5489 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = GetColorTable((int)(yyvsp[(3) - (6)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (6)].d));
      else{
	for(int i = 0; i < ct->size; i++)
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5504 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5509 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5516 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5520 "Gmsh.y"
    {
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.c) = (yyvsp[(1) - (1)].c);
      }
      else{
	std::string val = gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)];
	(yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
	strcpy((yyval.c), val.c_str());
	Free((yyvsp[(1) - (1)].c));
      }
    }
    break;

  case 485:
/* Line 1787 of yacc.c  */
#line 5533 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 5541 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 5552 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 5556 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 5564 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 5570 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 5576 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 5584 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 5592 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 5599 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[(3) - (4)].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 5614 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c)) - 1; i >= 0; i--){
	if((yyvsp[(3) - (4)].c)[i] == '.'){
	  strncpy((yyval.c), (yyvsp[(3) - (4)].c), i);
	  (yyval.c)[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy((yyval.c), (yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 5628 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c)) - 1; i >= 0; i--){
	if((yyvsp[(3) - (4)].c)[i] == '/' || (yyvsp[(3) - (4)].c)[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy((yyval.c), (yyvsp[(3) - (4)].c));
      else
	strcpy((yyval.c), &(yyvsp[(3) - (4)].c)[i+1]);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 5642 "Gmsh.y"
    {
      std::string input = (yyvsp[(3) - (8)].c);
      std::string substr_old = (yyvsp[(5) - (8)].c);
      std::string substr_new = (yyvsp[(7) - (8)].c);
      std::string ret = ReplaceSubString(substr_old, substr_new, input);
      (yyval.c) = (char *)Malloc((ret.size() + 1) * sizeof(char));
      strcpy((yyval.c), ret.c_str());
      Free((yyvsp[(3) - (8)].c));
      Free((yyvsp[(5) - (8)].c));
      Free((yyvsp[(7) - (8)].c));
    }
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 5654 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[(3) - (4)].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
        if(i != List_Nbr((yyvsp[(3) - (4)].l)) - 1) strcat((yyval.c), "\n");
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 5670 "Gmsh.y"
    {
      if((yyvsp[(3) - (8)].d)){
        (yyval.c) = (yyvsp[(5) - (8)].c);
        Free((yyvsp[(7) - (8)].c));
      }
      else{
        (yyval.c) = (yyvsp[(7) - (8)].c);
        Free((yyvsp[(5) - (8)].c));
      }
    }
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 5681 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 5685 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].l), tmpstring);
      if(i < 0){
	yymsg(0, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else if(i > 0){
	yymsg(0, "%d extra argument%s in Sprintf", i, (i > 1) ? "s" : "");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else{
	(yyval.c) = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 5704 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 5711 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 5717 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 5719 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 5730 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 5735 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 5741 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 5750 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 5763 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 5766 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11985 "Gmsh.tab.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 5770 "Gmsh.y"


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
