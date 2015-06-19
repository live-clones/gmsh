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
     tLines = 336,
     tSurfaces = 337,
     tCharacteristic = 338,
     tLength = 339,
     tParametric = 340,
     tElliptic = 341,
     tRefineMesh = 342,
     tAdaptMesh = 343,
     tRelocateMesh = 344,
     tPlane = 345,
     tRuled = 346,
     tTransfinite = 347,
     tComplex = 348,
     tPhysical = 349,
     tCompound = 350,
     tPeriodic = 351,
     tTransform = 352,
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
     tRecombine = 363,
     tSmoother = 364,
     tSplit = 365,
     tDelete = 366,
     tCoherence = 367,
     tIntersect = 368,
     tMeshAlgorithm = 369,
     tReverse = 370,
     tLayers = 371,
     tScaleLast = 372,
     tHole = 373,
     tAlias = 374,
     tAliasWithOptions = 375,
     tCopyOptions = 376,
     tQuadTriAddVerts = 377,
     tQuadTriNoNewVerts = 378,
     tQuadTriSngl = 379,
     tQuadTriDbl = 380,
     tRecombLaterals = 381,
     tTransfQuadTri = 382,
     tText2D = 383,
     tText3D = 384,
     tInterpolationScheme = 385,
     tTime = 386,
     tCombine = 387,
     tBSpline = 388,
     tBezier = 389,
     tNurbs = 390,
     tNurbsOrder = 391,
     tNurbsKnots = 392,
     tColor = 393,
     tColorTable = 394,
     tFor = 395,
     tIn = 396,
     tEndFor = 397,
     tIf = 398,
     tEndIf = 399,
     tExit = 400,
     tAbort = 401,
     tField = 402,
     tReturn = 403,
     tCall = 404,
     tMacro = 405,
     tShow = 406,
     tHide = 407,
     tGetValue = 408,
     tGetEnv = 409,
     tGetString = 410,
     tGetNumber = 411,
     tHomology = 412,
     tCohomology = 413,
     tBetti = 414,
     tSetOrder = 415,
     tExists = 416,
     tFileExists = 417,
     tGMSH_MAJOR_VERSION = 418,
     tGMSH_MINOR_VERSION = 419,
     tGMSH_PATCH_VERSION = 420,
     tGmshExecutableName = 421,
     tSetPartition = 422,
     tAFFECTDIVIDE = 423,
     tAFFECTTIMES = 424,
     tAFFECTMINUS = 425,
     tAFFECTPLUS = 426,
     tOR = 427,
     tAND = 428,
     tNOTEQUAL = 429,
     tEQUAL = 430,
     tGREATEROREQUAL = 431,
     tLESSOREQUAL = 432,
     UNARYPREC = 433,
     tMINUSMINUS = 434,
     tPLUSPLUS = 435
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
#line 413 "Gmsh.tab.cpp"
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
#line 441 "Gmsh.tab.cpp"

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
#define YYLAST   9816

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  201
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  511
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1814

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   435

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   186,     2,   196,     2,   185,     2,     2,
     191,   192,   183,   181,   197,   182,   195,   184,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     177,     2,   178,   172,     2,     2,     2,     2,     2,     2,
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
     176,   179,   180,   187,   188,   189
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
    1907,  1920,  1933,  1952,  1971,  1984,  1997,  2010,  2021,  2032,
    2043,  2054,  2065,  2070,  2075,  2080,  2085,  2090,  2093,  2097,
    2104,  2106,  2108,  2110,  2113,  2119,  2127,  2138,  2140,  2144,
    2147,  2150,  2153,  2157,  2161,  2165,  2169,  2173,  2177,  2181,
    2185,  2189,  2193,  2197,  2201,  2205,  2209,  2215,  2220,  2225,
    2230,  2235,  2240,  2245,  2250,  2255,  2260,  2265,  2272,  2277,
    2282,  2287,  2292,  2297,  2302,  2307,  2314,  2321,  2328,  2333,
    2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,
    2354,  2361,  2366,  2368,  2373,  2378,  2383,  2388,  2393,  2398,
    2403,  2406,  2412,  2418,  2424,  2430,  2434,  2441,  2446,  2454,
    2461,  2468,  2475,  2482,  2487,  2489,  2492,  2495,  2499,  2503,
    2515,  2525,  2533,  2541,  2543,  2547,  2549,  2551,  2554,  2558,
    2563,  2569,  2571,  2573,  2576,  2580,  2584,  2590,  2595,  2598,
    2601,  2604,  2607,  2611,  2615,  2619,  2623,  2629,  2635,  2641,
    2647,  2664,  2681,  2698,  2715,  2717,  2719,  2723,  2727,  2732,
    2739,  2746,  2748,  2750,  2754,  2758,  2768,  2776,  2778,  2784,
    2788,  2795,  2797,  2801,  2803,  2805,  2809,  2816,  2818,  2820,
    2822,  2824,  2829,  2836,  2841,  2846,  2851,  2856,  2865,  2870,
    2879,  2884,  2891,  2896,  2898,  2899,  2906,  2908,  2912,  2918,
    2924,  2926
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     202,     0,    -1,   203,    -1,     1,     6,    -1,    -1,   203,
     204,    -1,   207,    -1,   206,    -1,   227,    -1,   244,    -1,
     245,    -1,   249,    -1,   250,    -1,   251,    -1,   252,    -1,
     255,    -1,   276,    -1,   277,    -1,   254,    -1,   253,    -1,
     248,    -1,   279,    -1,   178,    -1,   178,   178,    -1,    37,
     191,   293,   192,     6,    -1,    38,   191,   293,   192,     6,
      -1,    37,   191,   293,   192,   205,   293,     6,    -1,    37,
     191,   293,   197,   289,   192,     6,    -1,    38,   191,   293,
     197,   289,   192,     6,    -1,    37,   191,   293,   197,   289,
     192,   205,   293,     6,    -1,     4,   293,   198,   208,   199,
       6,    -1,   119,     4,   193,   280,   194,     6,    -1,   120,
       4,   193,   280,   194,     6,    -1,   121,     4,   193,   280,
     197,   280,   194,     6,    -1,    -1,   208,   211,    -1,   208,
     215,    -1,   208,   218,    -1,   208,   220,    -1,   208,   221,
      -1,   280,    -1,   209,   197,   280,    -1,   280,    -1,   210,
     197,   280,    -1,    -1,    -1,     4,   212,   191,   209,   192,
     213,   198,   210,   199,     6,    -1,   293,    -1,   214,   197,
     293,    -1,    -1,   128,   191,   280,   197,   280,   197,   280,
     192,   216,   198,   214,   199,     6,    -1,   293,    -1,   217,
     197,   293,    -1,    -1,   129,   191,   280,   197,   280,   197,
     280,   197,   280,   192,   219,   198,   217,   199,     6,    -1,
     130,   198,   285,   199,   198,   285,   199,     6,    -1,   130,
     198,   285,   199,   198,   285,   199,   198,   285,   199,   198,
     285,   199,     6,    -1,    -1,   131,   222,   198,   210,   199,
       6,    -1,     7,    -1,   171,    -1,   170,    -1,   169,    -1,
     168,    -1,   189,    -1,   188,    -1,   191,    -1,   193,    -1,
     192,    -1,   194,    -1,    66,   193,   229,   194,     6,    -1,
      67,   193,   232,   194,     6,    -1,    70,   225,   294,   197,
     280,   226,     6,    -1,    71,   225,   298,   197,   294,   226,
       6,    -1,   298,   223,   286,     6,    -1,     4,   225,   226,
     223,   286,     6,    -1,   297,   225,   226,   223,   286,     6,
      -1,     4,   193,   280,   194,   223,   280,     6,    -1,     4,
     191,   280,   192,   223,   280,     6,    -1,   297,   193,   280,
     194,   223,   280,     6,    -1,   297,   191,   280,   192,   223,
     280,     6,    -1,     4,   225,   198,   289,   199,   226,   223,
     286,     6,    -1,   297,   225,   198,   289,   199,   226,   223,
     286,     6,    -1,   298,   224,     6,    -1,     4,   193,   280,
     194,   224,     6,    -1,     4,   191,   280,   192,   224,     6,
      -1,   297,   193,   280,   194,   224,     6,    -1,   297,   191,
     280,   192,   224,     6,    -1,   298,     7,   294,     6,    -1,
       4,   195,     4,     7,   294,     6,    -1,     4,   193,   280,
     194,   195,     4,     7,   294,     6,    -1,     4,   195,     4,
     223,   280,     6,    -1,     4,   193,   280,   194,   195,     4,
     223,   280,     6,    -1,     4,   195,     4,   224,     6,    -1,
       4,   193,   280,   194,   195,     4,   224,     6,    -1,     4,
     195,   138,   195,     4,     7,   290,     6,    -1,     4,   193,
     280,   194,   195,   138,   195,     4,     7,   290,     6,    -1,
       4,   195,   139,     7,   291,     6,    -1,     4,   193,   280,
     194,   195,   139,     7,   291,     6,    -1,     4,   147,     7,
     280,     6,    -1,   147,   193,   280,   194,     7,     4,     6,
      -1,   147,   193,   280,   194,   195,     4,     7,   280,     6,
      -1,   147,   193,   280,   194,   195,     4,     7,   294,     6,
      -1,   147,   193,   280,   194,   195,     4,     7,   198,   289,
     199,     6,    -1,   147,   193,   280,   194,   195,     4,     6,
      -1,    99,   191,     4,   192,   195,     4,     7,   280,     6,
      -1,    99,   191,     4,   192,   195,     4,     7,   294,     6,
      -1,    -1,   197,    -1,    -1,   229,   228,   298,    -1,   229,
     228,   298,     7,   280,    -1,    -1,   229,   228,   298,     7,
     198,   286,   230,   234,   199,    -1,   229,   228,   298,     7,
     294,    -1,    -1,   229,   228,   298,     7,   198,   294,   231,
     236,   199,    -1,    -1,   232,   228,   293,    -1,   280,     7,
     294,    -1,   233,   197,   280,     7,   294,    -1,    -1,   234,
     235,    -1,   197,     4,   286,    -1,   197,     4,   198,   233,
     199,    -1,   197,     4,   294,    -1,    -1,   236,   237,    -1,
     197,     4,   280,    -1,   197,     4,   294,    -1,   197,   150,
     294,    -1,   197,     4,   198,   296,   199,    -1,   280,    -1,
     294,    -1,   294,   197,   280,    -1,   280,    -1,   294,    -1,
     294,   197,   280,    -1,   280,    -1,   294,    -1,   294,   197,
     280,    -1,   280,    -1,   294,    -1,   294,   197,   280,    -1,
      -1,   141,    76,   198,   280,   199,    -1,    -1,    90,   283,
      -1,    72,   191,   280,   192,     7,   283,     6,    -1,    94,
      72,   191,   238,   192,   223,   286,     6,    -1,    83,    84,
     286,     7,   280,     6,    -1,    75,   191,   280,   192,     7,
     286,     6,    -1,   100,    75,   286,     6,    -1,    79,   191,
     280,   192,     7,   286,     6,    -1,    73,   191,   280,   192,
       7,   286,   243,     6,    -1,    74,   191,   280,   192,     7,
     286,   243,     6,    -1,   133,   191,   280,   192,     7,   286,
       6,    -1,   134,   191,   280,   192,     7,   286,     6,    -1,
     135,   191,   280,   192,     7,   286,   137,   286,   136,   280,
       6,    -1,    75,     4,   191,   280,   192,     7,   286,     6,
      -1,    95,    75,   191,   280,   192,     7,   286,     6,    -1,
      94,    75,   191,   239,   192,   223,   286,     6,    -1,    90,
      78,   191,   280,   192,     7,   286,     6,    -1,    91,    78,
     191,   280,   192,     7,   286,   242,     6,    -1,    12,    13,
       6,    -1,    13,    78,   280,     6,    -1,    85,    78,   191,
     280,   192,     7,     5,     5,     5,     6,    -1,    76,   191,
     280,   192,     7,   286,     6,    -1,    77,   191,   280,   192,
       7,   286,     6,    -1,    78,     4,   191,   280,   192,     7,
     286,     6,    -1,    95,    78,   191,   280,   192,     7,   286,
       6,    -1,    95,    78,   191,   280,   192,     7,   286,     4,
     198,   285,   199,     6,    -1,    94,    78,   191,   240,   192,
     223,   286,     6,    -1,    93,    80,   191,   280,   192,     7,
     286,     6,    -1,    80,   191,   280,   192,     7,   286,     6,
      -1,    95,    80,   191,   280,   192,     7,   286,     6,    -1,
      94,    80,   191,   241,   192,   223,   286,     6,    -1,   103,
     283,   198,   246,   199,    -1,   102,   198,   283,   197,   283,
     197,   280,   199,   198,   246,   199,    -1,   104,   283,   198,
     246,   199,    -1,   105,   198,   283,   197,   280,   199,   198,
     246,   199,    -1,   105,   198,   283,   197,   283,   199,   198,
     246,   199,    -1,     4,   198,   246,   199,    -1,   113,    75,
     198,   289,   199,    78,   198,   280,   199,    -1,   110,    75,
     191,   280,   192,   198,   289,   199,     6,    -1,   247,    -1,
     245,    -1,    -1,   247,   244,    -1,   247,    72,   198,   289,
     199,     6,    -1,   247,    75,   198,   289,   199,     6,    -1,
     247,    78,   198,   289,   199,     6,    -1,   247,    80,   198,
     289,   199,     6,    -1,   107,    90,   191,   280,   192,     7,
     286,     6,    -1,   107,    72,   191,   280,   192,     7,   198,
     285,   199,     6,    -1,   107,    90,   191,   280,   192,     7,
     198,   283,   197,   283,   197,   289,   199,     6,    -1,   107,
      90,   191,   280,   192,     7,   198,   283,   197,   283,   197,
     283,   197,   289,   199,     6,    -1,   107,    76,   191,   280,
     192,     7,   198,   283,   197,   289,   199,     6,    -1,   107,
       4,   191,   280,   192,     7,   286,     6,    -1,   107,     4,
     191,   280,   192,     7,     5,     6,    -1,   107,     4,   198,
     280,   199,     6,    -1,   107,     4,   191,   280,   192,     7,
     198,   283,   197,   283,   197,   289,   199,     6,    -1,   111,
     198,   247,   199,    -1,   111,   147,   193,   280,   194,     6,
      -1,   111,     4,   193,   280,   194,     6,    -1,   111,   298,
       6,    -1,   111,     4,     4,     6,    -1,   138,   290,   198,
     247,   199,    -1,   101,   138,   290,   198,   247,   199,    -1,
     167,   280,   198,   247,   199,    -1,   151,     5,     6,    -1,
     152,     5,     6,    -1,   151,   198,   247,   199,    -1,   101,
     151,   198,   247,   199,    -1,   152,   198,   247,   199,    -1,
     101,   152,   198,   247,   199,    -1,     4,   294,     6,    -1,
      59,   191,   296,   192,     6,    -1,     4,     4,   193,   280,
     194,   293,     6,    -1,     4,     4,     4,   193,   280,   194,
       6,    -1,     4,   280,     6,    -1,    99,   191,     4,   192,
     195,     4,     6,    -1,   132,     4,     6,    -1,   145,     6,
      -1,   146,     6,    -1,    56,     6,    -1,    57,     6,    -1,
      50,     6,    -1,    50,   198,   280,   197,   280,   197,   280,
     197,   280,   197,   280,   197,   280,   199,     6,    -1,    51,
       6,    -1,    52,     6,    -1,    63,     6,    -1,    64,     6,
      -1,    87,     6,    -1,    88,   198,   289,   199,   198,   289,
     199,   198,   285,   199,   198,   280,   197,   280,   199,     6,
      -1,   160,   280,     6,    -1,   140,   191,   280,     8,   280,
     192,    -1,   140,   191,   280,     8,   280,     8,   280,   192,
      -1,   140,     4,   141,   198,   280,     8,   280,   199,    -1,
     140,     4,   141,   198,   280,     8,   280,     8,   280,   199,
      -1,   142,    -1,   150,     4,    -1,   148,    -1,   149,   298,
       6,    -1,   143,   191,   280,   192,    -1,   144,    -1,   106,
     283,   198,   247,   199,    -1,   106,   198,   283,   197,   283,
     197,   280,   199,   198,   247,   199,    -1,   106,   198,   283,
     197,   283,   197,   283,   197,   280,   199,   198,   247,   199,
      -1,    -1,   106,   283,   198,   247,   256,   269,   199,    -1,
      -1,   106,   198,   283,   197,   283,   197,   280,   199,   198,
     247,   257,   269,   199,    -1,    -1,   106,   198,   283,   197,
     283,   197,   283,   197,   280,   199,   198,   247,   258,   269,
     199,    -1,    -1,   106,   198,   247,   259,   269,   199,    -1,
     106,    72,   198,   280,   197,   283,   199,     6,    -1,   106,
      75,   198,   280,   197,   283,   199,     6,    -1,   106,    78,
     198,   280,   197,   283,   199,     6,    -1,   106,    72,   198,
     280,   197,   283,   197,   283,   197,   280,   199,     6,    -1,
     106,    75,   198,   280,   197,   283,   197,   283,   197,   280,
     199,     6,    -1,   106,    78,   198,   280,   197,   283,   197,
     283,   197,   280,   199,     6,    -1,   106,    72,   198,   280,
     197,   283,   197,   283,   197,   283,   197,   280,   199,     6,
      -1,   106,    75,   198,   280,   197,   283,   197,   283,   197,
     283,   197,   280,   199,     6,    -1,   106,    78,   198,   280,
     197,   283,   197,   283,   197,   283,   197,   280,   199,     6,
      -1,    -1,   106,    72,   198,   280,   197,   283,   199,   260,
     198,   269,   199,     6,    -1,    -1,   106,    75,   198,   280,
     197,   283,   199,   261,   198,   269,   199,     6,    -1,    -1,
     106,    78,   198,   280,   197,   283,   199,   262,   198,   269,
     199,     6,    -1,    -1,   106,    72,   198,   280,   197,   283,
     197,   283,   197,   280,   199,   263,   198,   269,   199,     6,
      -1,    -1,   106,    75,   198,   280,   197,   283,   197,   283,
     197,   280,   199,   264,   198,   269,   199,     6,    -1,    -1,
     106,    78,   198,   280,   197,   283,   197,   283,   197,   280,
     199,   265,   198,   269,   199,     6,    -1,    -1,   106,    72,
     198,   280,   197,   283,   197,   283,   197,   283,   197,   280,
     199,   266,   198,   269,   199,     6,    -1,    -1,   106,    75,
     198,   280,   197,   283,   197,   283,   197,   283,   197,   280,
     199,   267,   198,   269,   199,     6,    -1,    -1,   106,    78,
     198,   280,   197,   283,   197,   283,   197,   283,   197,   280,
     199,   268,   198,   269,   199,     6,    -1,   270,    -1,   269,
     270,    -1,   116,   198,   280,   199,     6,    -1,   116,   198,
     286,   197,   286,   199,     6,    -1,   116,   198,   286,   197,
     286,   197,   286,   199,     6,    -1,   117,     6,    -1,   108,
       6,    -1,   124,     6,    -1,   124,   126,     6,    -1,   125,
       6,    -1,   125,   126,     6,    -1,   122,     6,    -1,   122,
     126,     6,    -1,   123,     6,    -1,   123,   126,     6,    -1,
     118,   191,   280,   192,     7,   286,    98,   280,     6,    -1,
      98,     4,   193,   280,   194,     6,    -1,    -1,    98,     4,
     280,    -1,    -1,     4,    -1,    -1,     7,   286,    -1,    -1,
       7,   280,    -1,    -1,    98,   286,    -1,    92,    75,   287,
       7,   280,   271,     6,    -1,    92,    78,   287,   273,   272,
       6,    -1,    86,    78,   198,   280,   199,     7,   286,     6,
      -1,    92,    80,   287,   273,     6,    -1,   127,   287,     6,
      -1,   114,    78,   198,   289,   199,   280,     6,    -1,   108,
      78,   287,   274,     6,    -1,   108,    80,   287,     6,    -1,
     109,    78,   286,     7,   280,     6,    -1,    96,    75,   198,
     289,   199,     7,   198,   289,   199,    97,   275,     6,    -1,
      96,    78,   198,   289,   199,     7,   198,   289,   199,    97,
     275,     6,    -1,    96,    75,   198,   289,   199,     7,   198,
     289,   199,   102,   198,   283,   197,   283,   197,   280,   199,
       6,    -1,    96,    78,   198,   289,   199,     7,   198,   289,
     199,   102,   198,   283,   197,   283,   197,   280,   199,     6,
      -1,    96,    75,   198,   289,   199,     7,   198,   289,   199,
     103,   283,     6,    -1,    96,    78,   198,   289,   199,     7,
     198,   289,   199,   103,   283,     6,    -1,    96,    78,   280,
     198,   289,   199,     7,   280,   198,   289,   199,     6,    -1,
      72,   198,   289,   199,   141,    78,   198,   280,   199,     6,
      -1,    75,   198,   289,   199,   141,    78,   198,   280,   199,
       6,    -1,    72,   198,   289,   199,   141,    80,   198,   280,
     199,     6,    -1,    75,   198,   289,   199,   141,    80,   198,
     280,   199,     6,    -1,    78,   198,   289,   199,   141,    80,
     198,   280,   199,     6,    -1,   115,    78,   287,     6,    -1,
     115,    75,   287,     6,    -1,    89,    72,   287,     6,    -1,
      89,    75,   287,     6,    -1,    89,    78,   287,     6,    -1,
     112,     6,    -1,   112,     4,     6,    -1,   112,    72,   198,
     289,   199,     6,    -1,   157,    -1,   158,    -1,   159,    -1,
     278,     6,    -1,   278,   198,   286,   199,     6,    -1,   278,
     198,   286,   197,   286,   199,     6,    -1,   278,   191,   286,
     192,   198,   286,   197,   286,   199,     6,    -1,   281,    -1,
     191,   280,   192,    -1,   182,   280,    -1,   181,   280,    -1,
     186,   280,    -1,   280,   182,   280,    -1,   280,   181,   280,
      -1,   280,   183,   280,    -1,   280,   184,   280,    -1,   280,
     185,   280,    -1,   280,   190,   280,    -1,   280,   177,   280,
      -1,   280,   178,   280,    -1,   280,   180,   280,    -1,   280,
     179,   280,    -1,   280,   176,   280,    -1,   280,   175,   280,
      -1,   280,   174,   280,    -1,   280,   173,   280,    -1,   280,
     172,   280,     8,   280,    -1,    14,   225,   280,   226,    -1,
      15,   225,   280,   226,    -1,    16,   225,   280,   226,    -1,
      17,   225,   280,   226,    -1,    18,   225,   280,   226,    -1,
      19,   225,   280,   226,    -1,    20,   225,   280,   226,    -1,
      21,   225,   280,   226,    -1,    22,   225,   280,   226,    -1,
      24,   225,   280,   226,    -1,    25,   225,   280,   197,   280,
     226,    -1,    26,   225,   280,   226,    -1,    27,   225,   280,
     226,    -1,    28,   225,   280,   226,    -1,    29,   225,   280,
     226,    -1,    30,   225,   280,   226,    -1,    31,   225,   280,
     226,    -1,    32,   225,   280,   226,    -1,    33,   225,   280,
     197,   280,   226,    -1,    34,   225,   280,   197,   280,   226,
      -1,    35,   225,   280,   197,   280,   226,    -1,    23,   225,
     280,   226,    -1,     3,    -1,     9,    -1,    10,    -1,    11,
      -1,   163,    -1,   164,    -1,   165,    -1,    60,    -1,    61,
      -1,    62,    -1,    -1,    68,   225,   280,   282,   234,   226,
      -1,   156,   225,   293,   226,    -1,   298,    -1,     4,   193,
     280,   194,    -1,     4,   191,   280,   192,    -1,   297,   193,
     280,   194,    -1,   297,   191,   280,   192,    -1,   161,   191,
     298,   192,    -1,   162,   191,   294,   192,    -1,   196,   298,
     225,   226,    -1,   298,   224,    -1,     4,   193,   280,   194,
     224,    -1,     4,   191,   280,   192,   224,    -1,   297,   193,
     280,   194,   224,    -1,   297,   191,   280,   192,   224,    -1,
       4,   195,     4,    -1,     4,   193,   280,   194,   195,     4,
      -1,     4,   195,     4,   224,    -1,     4,   193,   280,   194,
     195,     4,   224,    -1,   153,   191,   293,   197,   280,   192,
      -1,    45,   191,   286,   197,   286,   192,    -1,    46,   191,
     293,   197,   293,   192,    -1,    47,   191,   293,   197,   293,
     192,    -1,    49,   191,   296,   192,    -1,   284,    -1,   182,
     283,    -1,   181,   283,    -1,   283,   182,   283,    -1,   283,
     181,   283,    -1,   198,   280,   197,   280,   197,   280,   197,
     280,   197,   280,   199,    -1,   198,   280,   197,   280,   197,
     280,   197,   280,   199,    -1,   198,   280,   197,   280,   197,
     280,   199,    -1,   191,   280,   197,   280,   197,   280,   192,
      -1,   286,    -1,   285,   197,   286,    -1,   280,    -1,   288,
      -1,   198,   199,    -1,   198,   289,   199,    -1,   182,   198,
     289,   199,    -1,   280,   183,   198,   289,   199,    -1,   286,
      -1,     5,    -1,   182,   288,    -1,   280,   183,   288,    -1,
     280,     8,   280,    -1,   280,     8,   280,     8,   280,    -1,
      72,   198,   280,   199,    -1,    72,     5,    -1,    75,     5,
      -1,    78,     5,    -1,    80,     5,    -1,    94,    72,     5,
      -1,    94,    75,     5,    -1,    94,    78,     5,    -1,    94,
      80,     5,    -1,    94,    72,   198,   289,   199,    -1,    94,
      75,   198,   289,   199,    -1,    94,    78,   198,   289,   199,
      -1,    94,    80,   198,   289,   199,    -1,    72,   141,    50,
     198,   280,   197,   280,   197,   280,   197,   280,   197,   280,
     197,   280,   199,    -1,    75,   141,    50,   198,   280,   197,
     280,   197,   280,   197,   280,   197,   280,   197,   280,   199,
      -1,    78,   141,    50,   198,   280,   197,   280,   197,   280,
     197,   280,   197,   280,   197,   280,   199,    -1,    80,   141,
      50,   198,   280,   197,   280,   197,   280,   197,   280,   197,
     280,   197,   280,   199,    -1,   245,    -1,   255,    -1,     4,
     225,   226,    -1,   297,   225,   226,    -1,    36,   193,   298,
     194,    -1,     4,   225,   198,   289,   199,   226,    -1,   297,
     225,   198,   289,   199,   226,    -1,   280,    -1,   288,    -1,
     289,   197,   280,    -1,   289,   197,   288,    -1,   198,   280,
     197,   280,   197,   280,   197,   280,   199,    -1,   198,   280,
     197,   280,   197,   280,   199,    -1,     4,    -1,     4,   195,
     138,   195,     4,    -1,   198,   292,   199,    -1,     4,   193,
     280,   194,   195,   139,    -1,   290,    -1,   292,   197,   290,
      -1,   294,    -1,   298,    -1,     4,   195,     4,    -1,     4,
     193,   280,   194,   195,     4,    -1,     5,    -1,    53,    -1,
     166,    -1,    58,    -1,   154,   191,   293,   192,    -1,   155,
     191,   293,   197,   293,   192,    -1,   155,   191,   293,   192,
      -1,    41,   225,   296,   226,    -1,    42,   191,   293,   192,
      -1,    43,   191,   293,   192,    -1,    44,   191,   293,   197,
     293,   197,   293,   192,    -1,    39,   225,   296,   226,    -1,
      48,   225,   280,   197,   294,   197,   294,   226,    -1,    40,
     225,   293,   226,    -1,    40,   225,   293,   197,   289,   226,
      -1,    54,   225,   293,   226,    -1,    55,    -1,    -1,    69,
     225,   294,   295,   236,   226,    -1,   293,    -1,   296,   197,
     293,    -1,     4,   200,   198,   280,   199,    -1,   297,   200,
     198,   280,   199,    -1,     4,    -1,   297,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
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
    3160,  3195,  3203,  3209,  3216,  3220,  3229,  3237,  3245,  3254,
    3253,  3268,  3267,  3282,  3281,  3296,  3295,  3309,  3316,  3323,
    3330,  3337,  3344,  3351,  3358,  3365,  3373,  3372,  3386,  3385,
    3399,  3398,  3412,  3411,  3425,  3424,  3438,  3437,  3451,  3450,
    3464,  3463,  3477,  3476,  3493,  3496,  3502,  3514,  3534,  3558,
    3562,  3566,  3570,  3574,  3580,  3586,  3590,  3594,  3598,  3602,
    3621,  3634,  3637,  3653,  3656,  3673,  3676,  3682,  3685,  3692,
    3695,  3702,  3758,  3828,  3833,  3900,  3936,  3944,  3987,  4026,
    4046,  4075,  4100,  4125,  4151,  4176,  4201,  4224,  4252,  4280,
    4284,  4288,  4316,  4355,  4394,  4415,  4436,  4463,  4467,  4477,
    4512,  4513,  4514,  4518,  4524,  4536,  4554,  4582,  4583,  4584,
    4585,  4586,  4587,  4588,  4589,  4590,  4597,  4598,  4599,  4600,
    4601,  4602,  4603,  4604,  4605,  4606,  4607,  4608,  4609,  4610,
    4611,  4612,  4613,  4614,  4615,  4616,  4617,  4618,  4619,  4620,
    4621,  4622,  4623,  4624,  4625,  4626,  4627,  4628,  4629,  4638,
    4639,  4640,  4641,  4642,  4643,  4644,  4645,  4646,  4647,  4652,
    4651,  4659,  4664,  4681,  4699,  4717,  4735,  4753,  4758,  4764,
    4776,  4793,  4811,  4829,  4847,  4868,  4873,  4878,  4888,  4898,
    4903,  4914,  4923,  4928,  4955,  4959,  4963,  4967,  4971,  4978,
    4982,  4986,  4990,  4997,  5002,  5009,  5014,  5018,  5023,  5027,
    5035,  5046,  5050,  5062,  5070,  5078,  5085,  5095,  5124,  5128,
    5132,  5136,  5140,  5144,  5148,  5152,  5156,  5185,  5214,  5243,
    5272,  5285,  5298,  5311,  5324,  5334,  5344,  5356,  5369,  5381,
    5399,  5420,  5425,  5429,  5433,  5445,  5449,  5461,  5468,  5478,
    5482,  5497,  5502,  5509,  5513,  5526,  5534,  5545,  5549,  5557,
    5563,  5569,  5577,  5585,  5592,  5607,  5621,  5635,  5647,  5663,
    5674,  5678,  5697,  5704,  5711,  5710,  5723,  5728,  5734,  5743,
    5756,  5759
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
  "tSpline", "tVolume", "tLines", "tSurfaces", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tTransform", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse",
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl",
  "tQuadTriDbl", "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
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
     425,   426,    63,   427,   428,   429,   430,    60,    62,   431,
     432,    43,    45,    42,    47,    37,    33,   433,   434,   435,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

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
     254,   254,   254,   254,   254,   254,   255,   255,   255,   256,
     255,   257,   255,   258,   255,   259,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   260,   255,   261,   255,
     262,   255,   263,   255,   264,   255,   265,   255,   266,   255,
     267,   255,   268,   255,   269,   269,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   272,   272,   273,   273,   274,   274,   275,
     275,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   277,   277,   277,
     278,   278,   278,   279,   279,   279,   279,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   282,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   283,   283,   283,   283,   283,   284,
     284,   284,   284,   285,   285,   286,   286,   286,   286,   286,
     286,   287,   287,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   289,   289,   289,   289,   290,   290,   290,   290,   291,
     291,   292,   292,   293,   293,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   295,   294,   296,   296,   297,   297,
     298,   298
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
      12,    12,    18,    18,    12,    12,    12,    10,    10,    10,
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
       0,     0,     0,   163,     0,     0,     0,     0,   105,   106,
     187,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,   187,     0,     0,     0,     0,     0,
     184,   183,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,     0,    82,     0,   471,     0,     0,   480,     0,
      41,     0,     0,     0,    43,    58,     0,     0,     0,   327,
     329,   328,   330,   331,   166,     0,     0,     0,   309,     0,
       0,   309,     0,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   300,     0,     0,
       0,   251,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,   475,   239,     0,   346,     0,   124,     0,   131,
      96,     0,     0,     0,     0,     0,   113,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   178,
       0,   272,     0,     0,   274,     0,     0,   276,     0,     0,
       0,   287,     0,   247,     0,   187,     0,     0,     0,     0,
       0,     0,     0,   158,   103,     0,   119,     0,    49,     0,
      55,     0,     0,     0,   145,   171,   310,   320,     0,   324,
     321,     0,   325,   326,   429,   260,     0,     0,   267,   261,
       0,     0,   269,   262,     0,     0,   271,     0,     0,     0,
     253,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,   280,     0,   282,   288,   299,   252,   248,     0,     0,
       0,     0,     0,     0,     0,     0,   120,    46,     0,    53,
       0,     0,     0,     0,     0,     0,   263,     0,     0,   264,
       0,     0,   265,     0,     0,   201,     0,   195,     0,     0,
       0,     0,     0,    47,     0,     0,   228,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,     0,   273,
       0,   275,     0,   277,     0,   196,     0,     0,     0,     0,
      48,    50,     0,    51,     0,     0,     0,     0,     0,     0,
     460,   461,   462,   463,     0,     0,    56,   322,   323,   279,
     281,   283,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,   909,    89,    90,   663,  1377,  1383,
     898,  1085,  1549,  1752,   899,  1701,  1792,   900,  1754,   901,
     902,  1089,   336,   423,   176,   402,    91,   678,   434,  1493,
    1494,   435,  1544,  1060,  1229,  1061,  1232,   712,   715,   718,
     721,  1405,  1272,   643,   291,   396,   397,    94,    95,    96,
      97,    98,    99,   100,   292,   990,  1644,  1718,   747,  1429,
    1432,  1435,  1676,  1680,  1684,  1737,  1740,  1743,   986,   987,
    1124,   946,   709,   756,  1622,   102,   103,   104,   105,   293,
     178,   861,   484,   249,  1254,   294,   295,   296,   547,   305,
     882,  1076,   432,   428,   862,   433,   181,   298
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1326
static const yytype_int16 yypact[] =
{
    6493,    12,    30,  6611, -1326, -1326,  1547,    57,   -31,   -90,
     -65,    51,   151,   170,   190,   251,    79,   274,   301,   129,
     167,   -78,   -78,  -116,   153,   179,    13,   196,   204,    16,
     238,   246,   361,   388,   419,   472,   287,   -19,   424,   430,
     710,   446,   653,   717,    15,   338,   490,   -46,   401,   115,
     115,   405,   193,   408,   225,   528,   534,    31,    19,   549,
     562,   102,   644,   648,   651,  4657,   658,   480,   527,   536,
      28,     8, -1326,   539, -1326,   732,   744,   558, -1326,   754,
     757,    35,    36, -1326, -1326, -1326,  6355,  6355, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,    55, -1326,   -93,   293, -1326,     2,
   -1326, -1326, -1326, -1326,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   586,
     598,   602,   608,   633,   642,   -78,   645, -1326,   -78, -1326,
   -1326, -1326, -1326, -1326,   -78,   -78,   765,   659,   685,   689,
     -78,   695,   698, -1326, -1326, -1326, -1326,  6355,  6355,  6355,
    6355,  6355,   145,   754,   347,   621,   399,  1356, -1326,   625,
     835,   235,  -125,   838,  6355,  1013,  1013, -1326,  6355, -1326,
   -1326, -1326, -1326,  1013, -1326, -1326, -1326, -1326, -1326, -1326,
     701,   754,  6355,  6171,  6355,  6355,   706,  6355,  6171,  6355,
    6355,   713,  6171,  6355,  6355,  5037,   730,   667, -1326,  6171,
    4657,  4657,  4657,   740,   763,  4657,  4657,  4657,   767,   773,
     778,   784,   807,   817,   825,   829,   681,   113,   858,  5037,
      28,   696,   712,   115,   115,   115,  6355,  6355,  -103, -1326,
     120,   115,   716,   750,   761,  2123,   161,    88,   840,   867,
     868,  4657,  4657,  5037,   897,    20,   814, -1326,   819,   929,
    1085, -1326,   904,   910,   915,  4657,  4657,   903,   921,   924,
     509, -1326,   927,    23,     9,    24,    50,   657,  5227,  6355,
    3639, -1326, -1326,  3797, -1326,  1115, -1326,   385,    63,  1116,
    6355,  6355,  6355,   930,  6355,   931,   986,  6355,  6355, -1326,
   -1326,  6355,   935,  1125, -1326,  1130, -1326,  1131, -1326,   407,
    1448,  5411, -1326,  5037,  5037,  6355,  6355,   940,   570,   701,
   -1326, -1326, -1326, -1326, -1326, -1326,  5037,  1133,   947,  6355,
    6355,  1137,  6355,  6355,  6355,  6355,  6355,  6355,  6355,  6355,
    6355,  6355,  6355,  6355,  6355,  6355,  6355,  6355,  6355,  6355,
    6355,  6355,  6355,  6355,  1013,  1013,  1013,  1013,  1013,  1013,
    5037,  1013,  1013,  6355,  1013,  1013,  6355,   701,  6355,  1013,
    1013,  1013,  1013,   754,   701,   952,   952,   952,  8849,  8504,
     305,   950,  1139,   -78,   949, -1326,   953,  3682,  6355, -1326,
   -1326,  6171,   177, -1326,  6355,  6355,  6355,  6355,  6355,  6355,
    6355,  6355,  6355,  6355,  6355,  6355,  6355,  6355,  6355, -1326,
   -1326,  6355,  6355, -1326, -1326,  1496,   553,  -153, -1326, -1326,
     202,  4272, -1326,   223,   135,   262,   951,   957,  8870,  6171,
    3975, -1326,   413,  8891,  8912,  6355,  8933,   435,  8954,  8975,
    6355,   471,  8996,  9017,  1142,  6355,  6355,   488,  1151,  1152,
    1153,  6355,  6355,  1149,  1154,  1154,  6355,  5987,  5987,  5987,
    5987,  6355,  6355,  6355,  6171,  6171,  5601,   968,  1156,   965,
   -1326, -1326,   -26, -1326, -1326,  5982,  6166,   115,   115,   347,
     347,   156,  6355,  6355,  6355,  2123,  2123,  6355,  3682,   176,
   -1326,  6355,  6355,  6355,  6355,  6355,  1157,  1160,  1163,  6355,
    1166,  6355,  6355,  1348, -1326, -1326,  6171,  6171,  6171,  1167,
    1170,  6355,  6355,  6355,  6355,  6355,  1173,   581,   754, -1326,
    1128,  6355, -1326,  1158, -1326,  1159, -1326,  1161,    41,    44,
      46,    47,  6171,   952, -1326,  9038, -1326,   511,  6355,  5417,
   -1326,  6355,  6355,   589, -1326,  9059,  9080,  9101,  1042,  7363,
   -1326,   983,  4175,  9122,  8527, -1326, -1326,  2384, -1326,  2525,
    6355, -1326, -1326,  1020,   522,  9143,  8550,  6355,  6171,   177,
    1208,  1209, -1326,  6355,  9164,  8573,   -37,  8481,  8481,  8481,
    8481,  8481,  8481,  8481,  8481,  8481,  8481,  8481,  7389,  8481,
    8481,  8481,  8481,  8481,  8481,  8481,  7415,  7441,  7467,   158,
     604,   158,  1026,  1028,  1027,  1032,  1033,  1038,  7493,   273,
     573,  9626, -1326,  1604,  1039,  1046,   372,   573,  1047,  1048,
     321,   146,   701,  6355,  1236,  1240,    32,   573, -1326,   100,
      34,    33,   128, -1326,  5885,   579, -1326,  5037,  4244,  2767,
    2510,  1294,  1294,   322,   322,   322,   322,   505,   505,   952,
     952,   952,   952,    38,  9185,  8596, -1326,  6355,  1241,    10,
    6171,  1243,  6171,  6355,  1244,  1013,  1245, -1326,   754,  1246,
    1013,  6355,   701,  1239,  6171,  6171,  1112,  1247,  1248,  9206,
    1249,  1118,  1254,  1255,  9227,  1122,  1262,  1264,  6355,  9248,
    5913,  1067, -1326, -1326, -1326,  9269,  9290,  6355,  5037,  1272,
    1271,  9311,  1086,  9626,  1082,  1090,  9626,  1087,  1091,  9626,
    1088,  1094,  9626,  1092,  9332,  9353,  9374,   603,   616,  6171,
    1093, -1326, -1326,  2702,  3023,   115,  6355,  6355, -1326, -1326,
    1095,  1096,  2123,  7519,  7545,  7571,  4021,   855,   115,  3453,
    9395,  5945,  9416,  9437,  9458,  6355,  1281, -1326,  6355,  9479,
   -1326,  8619,  8642, -1326,   631,   632,   635, -1326, -1326,  8665,
    8688,  7597,  8711,    63,  6171, -1326,  1098,  1100,  6113,  1101,
    1102,  1103, -1326,  6171, -1326,  6171, -1326,  6171, -1326,  6171,
     640, -1326, -1326,  4365,  6171,   952, -1326,  6171, -1326,  1286,
    1296,  1297,  1114,  6355,  4506,  6355,  6355, -1326,    43, -1326,
   -1326,  4699,  1113,  5037,  1301,   321,   321,  6252,   650,  5037,
   -1326, -1326,  8734,    63,   400, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326,  6355, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326,  6355,  6355,  6355, -1326,  6171,
   -1326, -1326, -1326, -1326,  1013,  5037,  1013,  1013,   701, -1326,
   -1326, -1326, -1326, -1326,  6355, -1326, -1326,  1013, -1326, -1326,
   -1326,  6355,  1304,   150,  6355,  1307,  1309,  1654, -1326,  1311,
    1123,    28,  1313, -1326,  6171,  6171,  6171,  6171, -1326,   573,
    1314,  6355, -1326,  1134,  1136,  1135, -1326,  1323, -1326, -1326,
   -1326, -1326, -1326,    63,    63,  8757, -1326, -1326,  1143,  1013,
     506, -1326,   542,  7623, -1326, -1326, -1326,  1327, -1326, -1326,
    8481,   573,   115,  3975, -1326,   779,  5037,  5037,  1333,  5037,
     780,  5037,  5037,  1334,  1265,  5037,  5037,  1762,  1335,  1337,
    6171,  1339,  1340,  1934, -1326, -1326,  1345, -1326,  1346,   177,
    6355,   177,  6355,   177,  6355,   177,  6355,  1352,  1357,  1360,
    1361,  1362,   664,  1351,  4889, -1326, -1326,   200,  7649,  7675,
   -1326, -1326,  6280,  -113,   115,   115,   115,  1359,  1364,  1174,
    1365,  1182,    60,    61,    68,    75,   -14, -1326,   237, -1326,
     855,  1370,  1373,  1377,  1378,  1382,  9626, -1326,  1804,  1192,
    1385,  1386,  1387,  1274,  6355,  1388,  1390,  6355,   -70,   671,
   -1326,  6355, -1326,  6355,  6355,  6355,   674,   675,   688,   693,
   -1326,  6355,   703,   704,  5037,  5037,  5037,  1393,  7701, -1326,
    4384,  1315,  1394,  1396, -1326,  5037,  1202, -1326,  6355,  1397,
    6355,  1398, -1326,   573,  1399,  1401, -1326,  1404, -1326,  1403,
    8481,  8481,  8481,  8481,   614,  1205,  1218,  1219,  1222,  1221,
     620,   628,  9500,  1227,  2090, -1326,   349,  1234,  1423,  2188,
   -1326, -1326, -1326,    28,  6355, -1326,   708, -1326,   714,   719,
     720,   723,   177, -1326,  9626,  1253,  6355,  6355,  5037,  1238,
   -1326, -1326, -1326,  1237, -1326,  1428,    25,  1431,  6355,  4216,
    1439,  1440,    59,  1251,  1252,  1366,  1366,  5037,  1441,  1260,
    1261,  1445,  1446,  5037,  1266,  1456,  1457, -1326,  1460,  5037,
     728,  5037,  5037,  1462,  1463, -1326,  5037,  5037,  9626,  5037,
    9626,  5037,  9626,  5037,  9626,  5037,  5037,  5037,  1270,  1282,
    1479,   567, -1326,  6355,  6355,  6355,  1305,  1308,  -110,   -85,
     111,  1316, -1326,  5037, -1326,  6355, -1326,  1504, -1326,  1505,
   -1326,  1506, -1326,  1507, -1326, -1326,  2123,   434,  4847, -1326,
    1318,  1319,  5607, -1326,  6171, -1326, -1326, -1326,  1320,  2490,
   -1326, -1326,  8780,  1510,   573,  7727,  7753,  7779,  7805, -1326,
   -1326, -1326, -1326,  9626, -1326,   573,  1513,  1515,  1389, -1326,
    6355,  6355,  6355, -1326,  1516,   672,  1326,  1518,  2556, -1326,
    2744, -1326,   177, -1326, -1326,   142, -1326, -1326, -1326, -1326,
   -1326, -1326,  1013, -1326, -1326, -1326,   701,  1538, -1326, -1326,
      39, -1326, -1326, -1326, -1326, -1326,   701,  6355,  1537,  1540,
      32, -1326,  1539,  8803,    28, -1326,  1542,  1543,  1548,  1549,
    5037,  6355,  7831,  7857,   737, -1326,  6355,  1556, -1326, -1326,
    1013, -1326,  7883,  3836,  9626, -1326, -1326, -1326, -1326,  6355,
    6355,   115,  1577,  1578,  1591, -1326,  6355,  6355, -1326, -1326,
    1592,  6355, -1326, -1326,  1594,  1597,  1355,  1598,  1465,  6355,
   -1326,  1605,  1606,  1607,  1608,  1611,  1613,   934,  1628,  6171,
    6171,  6355, -1326,  5987,  6607,  9521,  5359,   347,   347,   115,
    1630,   115,  1631,   115,  1635,  6355,   810,  1447,  9542, -1326,
   -1326, -1326, -1326,  6635,   286, -1326,  1640,  3325,  1641,  5037,
     115,  3325,  1643,   742,  6355, -1326,  1644,    63, -1326,  6355,
    6355,  6355,  6355, -1326, -1326, -1326,  5037,  5549,   861,  9563,
   -1326, -1326,  4277,  5037, -1326, -1326, -1326,  5037, -1326,  1459,
     573,  4026,  4467,   701,  1646,  2805, -1326,  1647,  1649, -1326,
    1458, -1326, -1326, -1326, -1326, -1326,  1650,   560,  9626,  6355,
    6355,  5037,  1461,   745,  9626, -1326,  1651,  6355, -1326, -1326,
    6663,  6691,   530, -1326, -1326, -1326,  6719,  6747, -1326,  6775,
    1656, -1326,  5037, -1326,  1587,  1658,  9626, -1326, -1326, -1326,
   -1326, -1326, -1326,  1467, -1326, -1326,   746,   768,  5791,  2825,
    1660,  1469, -1326,  6355, -1326,  1483,  1484,   314, -1326,  1486,
     319, -1326,  1487,   346, -1326,  1489,  8826,  1682,  5037,  1683,
    1491,  6355, -1326,  5797,   352, -1326,   771,   363,   366, -1326,
    1685,  6803, -1326,  7909,  7935,  7961,  7987,  1557,  6355, -1326,
    6355, -1326, -1326,  6171,  3119,  1686,  1497,  1689, -1326, -1326,
    3639, -1326, -1326,  1013,  9626, -1326, -1326, -1326, -1326,    28,
   -1326,  1558, -1326, -1326,  6355,  8013,  8039, -1326,  5037,  6355,
    1692, -1326,  8065, -1326, -1326,  1693,  1698,  1699,  1700,  1701,
    1708,   777,  1517, -1326,  5037,   330,   438,  6171, -1326, -1326,
     347,  5739, -1326, -1326,  2123,   855,  2123,   855,  2123,   855,
    1710, -1326,   802,  5037, -1326,  6831,   115,  1712,  6171,   115,
   -1326, -1326,  6355,  6355,  6355,  6355,  6355,  6859,  6887,   805,
   -1326, -1326,  1713, -1326,   806,  3454,   815,  1720, -1326,  1529,
    9626,  6355,  6355,   816,  9626, -1326,  6355,   827,   828, -1326,
   -1326, -1326, -1326, -1326, -1326,  1532,  6355,   831,  1633,  1534,
     115,  1633,  1536,   115,   850,  1545,  6355, -1326,  6915,   380,
     976,  6943,   386,  1109,  6971,   390,  1150, -1326,  5037,  1729,
    1638,  5079,  1541,   457, -1326,   851,   460,  8091,  8117,  8143,
    8169,  3385, -1326, -1326,  1740, -1326,  6355, -1326,   701, -1326,
   -1326,  6355,  9584,  8195,    52,  8221, -1326, -1326,  6355,  6999,
    1742,  5037,  1744,   115,    74,  1745,   115,    82,  1748, -1326,
    7027,  1753,  6355,  1758,  1767,  6355,  1768,  1769,  6355,  1785,
    1593, -1326,  6355, -1326,   855, -1326,  6171,  1790,  5797,  6355,
    6355,  6355,  6355, -1326, -1326,  3778, -1326,   865, -1326,  6355,
   -1326,  5037,  6355,  8247, -1326, -1326, -1326, -1326,   469, -1326,
   -1326,   477, -1326, -1326, -1326, -1326,  1599,  7055, -1326, -1326,
    1600,  7083, -1326, -1326,  1609,  7111, -1326,  1796,  3417,  1214,
    5269,   866, -1326,   479,   873,  8273,  8299,  8325,  8351,   701,
    1797,  1614,  9605,   876,  7139,  6355,   115,   115,   855,  1798,
     855,  1799,   855,  1800, -1326, -1326, -1326, -1326,   855,  1803,
    6171,  1805,  6355,  6355,  6355,  6355, -1326, -1326,  1013, -1326,
    1615,  1809,  7167,   483,   502,  1258, -1326,  1619,  1965, -1326,
    1620,  2079, -1326,  1621,  2124, -1326,   884, -1326,  8377,  8403,
    8429,  8455,   898, -1326,  1622,  5037, -1326,  1815,  6355,  6355,
    1817,   855,  1818,   855,  1834,   855, -1326,  1839,  6355,  6355,
    6355,  6355,  1013,  1841,  1013,   906, -1326,  7195,  7223, -1326,
    2427, -1326,  2513, -1326,  2644, -1326,  7251,  7279,  7307,  7335,
   -1326, -1326,   912, -1326,  1842,  1843,  1844,  1845,  1846,  1850,
   -1326, -1326, -1326, -1326,  1013,  1852, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1326, -1326, -1326, -1326,   766, -1326, -1326, -1326, -1326,   248,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,  -369,  -100,  1068,    26, -1326,  1430, -1326, -1326,
   -1326, -1326, -1326,   370, -1326,   373, -1326, -1326, -1326, -1326,
   -1326, -1326,   760,  1865,    -2,  -481,  -233, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,  1866, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,  -870,  -975,
   -1326, -1326,  1405, -1326,   300, -1326, -1326, -1326, -1326,  1553,
   -1326, -1326,   900, -1326, -1325,  2118,   735,  2283,  -193,  -238,
     637, -1326,    21,    54, -1326,  -361,    -3,    42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -487
static const yytype_int16 yytable[] =
{
     106,    93,   479,   609,  1446,   611,   338,   337,   740,   741,
     442,  1165,   306,   619,   532,   447,   907,   206,     4,   451,
     211,   633,   498,   270,   510,   271,   457,   179,   529,   534,
       5,  1259,   303,   647,   513,   265,   880,   211,   206,   669,
     315,   317,   892,  1362,   670,   107,   782,   184,   182,   784,
    1032,   786,   788,   220,   268,   536,   221,   187,  1660,   222,
     180,   322,   297,   334,   335,  1268,  1156,  1158,   487,   488,
     183,   487,   488,  -484,  1160,   202,   268,  1501,   487,   488,
    1669,  1162,   203,   567,   977,   569,  1147,  1309,  1672,  1310,
     236,   272,   240,   237,   978,   489,   487,   488,   325,   269,
     326,   185,   979,   980,   981,   241,   242,   327,   982,   983,
     984,   985,  1311,   198,  1312,   199,   108,   319,   334,   335,
    1167,   313,   111,   112,   113,  1183,   186,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   390,
     533,   334,   335,   646,  1066,   487,   488,   189,   142,   143,
     144,  -485,   146,  1553,   530,   535,   893,   894,   895,   896,
     268,   735,   395,   151,   152,   153,   190,   275,   266,  1567,
     276,   154,   268,   268,   646,  1164,  1157,  1159,   908,  1363,
     268,   537,  1165,   339,  1161,   340,   191,   341,   268,   307,
     297,  1163,   175,   908,   207,   297,   427,   430,   645,   297,
     819,   208,   297,   511,   212,   393,   297,   297,   297,   297,
     175,   531,   297,   297,   297,   207,   304,   429,   429,   267,
     881,   886,   885,   316,   318,   429,   297,   897,  1033,   783,
     487,   488,   785,   437,   787,   789,   323,   733,   734,   188,
    1661,   334,   335,   324,   436,   487,   488,   192,   297,   297,
     297,   871,   874,   487,   488,   252,   157,   749,   253,   160,
     193,   254,   297,   297,   161,   162,   163,   164,   165,   501,
     194,   727,   728,   391,   392,   297,   502,   297,  1067,  1068,
     634,   202,   487,   488,   167,   168,   244,   245,   884,   169,
     329,   487,   488,   261,   289,   262,   246,   195,  1313,   173,
    1314,   475,   632,   247,   330,   331,   332,   333,   490,   214,
     297,   297,   196,   764,   765,   766,   887,   804,   646,   676,
     334,   335,   677,   297,   334,   335,  1703,   487,   488,   811,
    -486,   873,   487,   488,   204,   330,   331,   332,   333,   790,
     399,   394,   400,   742,   579,   675,  1236,   487,   488,   500,
     197,   268,   268,   268,   268,   268,   268,   297,   268,   268,
     205,   268,   268,   748,   244,   245,   268,   268,   268,   268,
     268,   487,   488,   580,   246,   818,   610,   209,   612,   613,
     614,   255,   616,   617,   671,   210,   620,  1143,   297,   672,
     624,   625,   626,   627,   426,   110,   429,   429,   429,   429,
     429,   429,   257,   429,   429,   674,   429,   429,   487,   488,
     675,   429,   429,   429,   429,   628,   421,  1568,   422,   213,
    1775,   622,  1569,  1570,  1166,   327,   297,   214,   629,   136,
     137,   138,   139,   140,   141,   215,  1038,  1040,   145,    48,
      49,    50,    51,   147,   148,   149,   679,    56,   150,   677,
      59,   330,   331,   332,   333,   859,   216,   487,   488,   155,
     675,   297,   297,   330,   331,   332,   333,   910,   218,   912,
     258,   334,   335,  1441,   259,   219,   825,   395,   395,   330,
     331,   332,   333,   334,   335,   487,   488,   217,   260,   964,
     487,   488,   223,   413,   414,   415,   416,   417,   224,   334,
     335,  1514,   418,   297,   297,   297,  1516,   330,   331,   332,
     333,   714,   717,   720,   723,   268,   228,   487,   488,   238,
     872,   875,   977,   487,   488,  1571,   962,   334,   335,   297,
    1572,  1573,   978,  1518,   487,   488,   297,   487,   488,  1526,
     979,   980,   981,   775,   158,   159,   982,   983,   984,   985,
    1528,   487,   488,  1529,   866,   239,   166,   487,   488,   867,
     776,   487,   488,  1302,  1303,   297,   551,  1632,   552,   798,
    1127,  1009,  1129,  1635,  1131,   327,  1133,  1638,   334,   335,
    1016,   399,  1017,   400,  1018,  1047,  1019,   401,   339,   243,
     570,  1022,   526,   251,  1023,  1165,   263,   175,  1165,   264,
     685,  1165,   686,   826,   827,   828,   829,   830,   831,   832,
     833,   834,   835,   836,   273,   838,   839,   840,   841,   842,
     843,   844,   685,  1325,   691,   848,   850,   851,   487,   488,
     274,   487,   488,  1075,   297,  1580,   860,  1583,   277,  1586,
     487,   488,   278,   868,  1646,   279,  1054,  1648,   487,   488,
     487,   488,   299,   883,   487,   488,  1706,   297,   685,   297,
     695,   300,   268,   825,  1707,   268,  1720,   268,  1351,  1352,
    1758,   297,   297,   487,   488,   685,   876,   701,   415,   416,
     417,  1078,  1079,  1080,  1081,   418,   915,  1237,  1096,  1759,
     524,   919,   525,   685,   526,   297,   110,   174,   685,   175,
     792,   487,   488,  1250,  1165,  1039,  1041,   429,   301,   813,
     917,   814,   429,  1046,  1048,   229,   297,   302,   230,   538,
     308,   231,   539,   232,  1097,   540,   921,   541,   309,   685,
     136,   137,   138,   139,   140,   141,   667,  1120,   668,   145,
     310,   311,  1483,   175,   147,   148,   149,  1484,   312,   150,
    1165,   314,   399,  1165,   400,   399,  1165,   400,   578,  1165,
     155,   297,   378,   399,  1689,   400,   685,   367,   889,   774,
     297,   399,   297,   400,   297,   225,   297,   797,   226,   368,
     227,   297,   233,   369,   297,   234,   399,   235,   400,   370,
     685,   849,   960,  1091,  1092,  1165,   399,  1165,   400,  1165,
     297,   685,   399,   685,   400,   961,   297,  1227,   548,   398,
     399,   268,   400,   419,   371,  1230,  1425,  1426,   685,   685,
    1002,  1003,   685,   372,  1004,  1242,   374,   685,  1735,  1020,
    1738,   420,  1741,  1357,   424,  1049,   297,   685,  1744,  1043,
     379,   268,   297,   268,   268,   158,   159,  1103,  1109,  1104,
    1110,   685,   477,  1140,   268,   456,   429,   166,   685,  1460,
    1184,   685,   685,  1189,  1190,  1055,   380,  1057,  1058,   474,
     381,   297,   297,   297,   297,   685,   383,  1191,  1063,   384,
     685,  1780,  1192,  1782,   480,  1784,   429,   445,   429,   429,
     685,   685,  1194,  1195,   450,  1244,   268,  1245,  1048,   429,
     481,   685,  1059,  1246,   492,  1082,   685,   685,  1247,  1248,
     685,   455,  1249,   297,   297,   685,   297,  1286,   297,   297,
    1095,   461,   297,   297,  1381,   514,  1382,   297,  1413,   685,
    1414,  1450,  1489,   685,  1490,  1505,  1100,  1101,   493,   248,
     250,   429,   256,   977,   462,   458,   459,   460,   466,   494,
     463,   464,   465,   978,   467,   685,  1238,  1506,  1381,   468,
    1527,   979,   980,   981,  1381,   469,  1565,   982,   983,   984,
     985,  1333,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   549,   416,   417,   506,   507,   470,  1588,
     418,  1589,   685,  1606,  1604,  1607,  1371,   512,   471,  1437,
     519,   520,   675,  1381,  1609,  1614,   472,   426,   110,   327,
     473,   297,   297,   297,  1227,  1230,  1616,  1617,  1381,  1575,
    1620,   503,   297,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   685,   685,  1628,
    1647,   418,   136,   137,   138,   139,   140,   141,   504,   505,
    1461,   145,  1489,   685,  1700,  1719,   147,   148,   149,  1212,
     685,   150,  1721,  1381,   977,  1730,  1217,  1218,  1219,  1220,
    1221,   685,   155,  1767,   978,   297,  1228,  1231,   509,   200,
     201,   515,   979,   980,   981,  1772,   521,  1773,   982,   983,
     984,   985,   516,  1381,   297,  1794,  1416,  1417,   517,  1804,
     297,  1805,  1546,   518,   522,  1358,   297,   523,   297,   297,
     528,   550,   554,   297,   297,   558,   297,   561,   297,   560,
     297,   565,   297,   297,   297,   175,   566,   568,   577,   582,
     583,   586,   418,   482,   483,   635,   636,   174,   681,   698,
     297,   491,   638,  1265,   682,   499,   707,   702,   703,   704,
     730,   708,   731,   732,   755,   297,   757,   158,   159,   297,
     758,   297,   760,   767,   328,  1633,   768,   773,   777,   166,
     802,   805,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   977,   779,   780,
    1338,   781,   812,   373,   820,   821,   375,   978,   852,   268,
     853,  1343,   376,   377,   854,   979,   980,   981,   382,   855,
     856,   982,   983,   984,   985,   857,   864,  1358,   865,   869,
     870,  1547,   878,  1359,   879,   906,   922,   297,   977,   911,
     914,   916,   918,   925,   926,   927,   929,   268,   978,   930,
     297,   931,   932,   934,   429,   940,   979,   980,   981,   935,
    1539,   936,   982,   983,   984,   985,   945,   947,   949,   950,
    1360,  1386,   951,   953,   952,   954,   955,   997,   963,   956,
    1364,  1591,  1010,  1024,   970,   971,   297,   297,  1011,  1013,
    1014,  1015,   429,  1025,  1026,   395,   395,  1037,  1636,  1027,
    1065,  1035,   977,  1070,  1574,  1071,  1074,  1389,  1073,  1077,
    1083,  1094,   978,  1202,   297,  1086,   297,  1087,   297,  1090,
     979,   980,   981,  1088,  1099,  1595,   982,   983,   984,   985,
    1107,  1113,  1118,   297,  1119,  1114,  1121,  1122,   527,  1639,
     297,  1125,  1178,  1126,   297,  1141,   977,  1420,   297,  1135,
       7,     8,   403,  1151,  1136,   553,   978,  1137,  1138,  1139,
    1152,  1154,  1153,  1155,   979,   980,   981,  1168,   297,  1169,
     982,   983,   984,   985,  1170,  1171,  1469,   738,   739,  1172,
    1174,  1175,  1176,  1177,  1180,   483,  1181,  1199,  1204,   297,
    1205,  1207,  1222,  1209,  1211,  1213,  1465,  1214,  1215,  1216,
    1223,  1224,  1690,  1716,  1225,  1472,  1475,  1476,  1226,  1234,
     639,    24,    25,   640,    27,    28,   641,    30,   642,  1239,
    1240,    32,  1257,    33,  1258,   297,  1256,  1261,    38,    39,
     297,    41,    42,    43,  1251,  1266,  1267,  1275,    46,  1269,
    1270,  1278,  1279,  1691,   571,  1694,  1271,  1760,  1276,  1277,
     297,   637,  1282,  1283,  1281,  1284,  1289,   297,  1299,  1290,
     268,   409,   410,   411,   412,   413,   414,   415,   416,   417,
    1300,    67,    68,    69,   418,   297,  1301,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   297,   666,  1307,   297,   418,  1308,  1203,   395,  1315,
    1319,  1320,  1321,  1322,  1337,   429,  1329,  1330,  1334,  1344,
     297,  1345,  1350,  1353,  1354,   297,  1346,  1746,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,  1361,  1366,  1367,  1369,   418,   763,  1372,  1373,
     108,   109,   110,  1402,  1374,  1375,   111,   112,   113,   177,
    1385,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,  1393,  1394,   297,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,  1395,  1398,  1400,
     147,   148,   149,  1401,  1403,   150,  1404,   151,   152,   153,
     863,  1407,  1408,  1409,  1410,   154,   155,  1411,   297,  1412,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,  1415,   967,  1428,  1431,   418,   320,
     321,  1434,   973,   297,  1438,   297,  1442,  1445,   988,  1449,
    1452,  1468,  1477,  1481,  1479,  1480,  1482,  1491,   297,  1488,
    1072,  1500,  1656,  1502,  1503,  1504,  1509,  1510,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,  1512,  1513,  1515,  1517,   418,  1519,  1521,  1524,
    1523,  1530,  1541,  1536,   156,  1543,  1542,  1548,  1555,  1559,
     157,   158,   159,   160,  1560,  1561,  1562,  1563,   161,   162,
     163,   164,   165,   166,  1564,  1566,  1587,   297,  1594,  1605,
     385,   386,   387,   388,   389,   268,  1610,  1611,   167,   168,
    1618,  1621,  1623,   169,  1626,  1641,  1642,   425,   170,  1645,
     171,   431,   172,   173,  1629,   174,  1654,   175,  1665,  1753,
    1667,  1670,   297,  1726,  1673,   438,   440,   443,   444,  1675,
     446,   440,   448,   449,  1678,   440,   452,   453,  1117,   268,
     429,   268,   440,  1679,  1682,  1683,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     476,  1686,  1687,  1790,   418,  1793,  1692,  1708,  1710,   485,
     486,   268,  1714,  1727,  1736,  1739,  1742,  1712,   486,  1745,
    1173,  1747,  1728,  1755,   429,  1756,   429,  1761,  1763,  1765,
    1774,  1776,  1102,  1779,  1781,  1812,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
    1783,   543,   545,   440,   418,  1785,   429,  1791,  1806,  1807,
    1808,  1809,  1810,   555,   556,   557,  1811,   559,  1813,  1657,
     562,   563,  1260,  1557,   564,   680,  1273,  1558,    92,   101,
     710,  1625,     0,     0,  1148,  1149,  1150,  1368,   575,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   584,   585,     0,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   618,     0,     0,   621,
       0,   623,     0,     0,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,   644,   418,     0,   440,     0,     0,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,     0,     0,   664,   665,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,   543,     0,   418,     0,     0,     0,   689,     0,
       0,     0,     0,   694,     0,     0,     0,     0,   699,   700,
       0,     0,     0,     0,   705,   706,     0,     0,     0,   711,
     713,   716,   719,   722,   724,   725,   726,   440,   440,     0,
       0,     0,  1123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   743,   744,   745,   385,   386,
     746,     0,     0,     0,   750,   751,   752,   753,   754,     0,
       0,     0,   759,   977,   761,   762,  1324,     0,     0,   440,
     440,   440,     0,   978,   769,   770,   771,   584,   772,     0,
       0,   979,   980,   981,   778,     0,     0,   982,   983,   984,
     985,     0,     0,     0,     0,   440,  1235,     0,     0,     0,
       0,   793,   795,     0,   664,   665,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,   772,   418,     0,   108,   319,     0,     0,
     817,   440,   111,   112,   113,     0,   822,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,  1762,     0,     0,     0,   142,   143,
     144,  1392,   146,     0,     0,     0,     0,   977,     0,     0,
       0,     0,     0,   151,   152,   153,   877,   978,     0,     0,
       0,   154,     0,     0,  1241,   979,   980,   981,     0,     0,
       0,   982,   983,   984,   985,     0,     0,     0,     0,  1427,
       0,  1430,     0,  1433,     0,     0,     0,     0,     0,     0,
     905,     0,   977,   440,     0,   440,   913,  1444,     0,     0,
    1447,  1448,   978,     0,   920,     0,     0,   795,   923,     0,
     979,   980,   981,     0,     0,     0,   982,   983,   984,   985,
       0,   937,     0,     0,     0,     0,     0,     0,     0,     0,
     943,     0,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   157,     0,  1764,   160,
     418,     0,   440,     0,   161,   162,   163,   164,   165,   968,
     969,     0,     0,     0,     0,   972,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,     0,     0,   996,   169,
       0,   998,     0,     0,   497,     0,     0,     0,     0,   173,
       0,   247,     0,  1766,     0,     0,     0,   440,     0,     0,
       0,     0,     0,   454,     0,     0,   440,     0,   440,     0,
     440,     0,   440,     0,     0,     0,     0,   440,     0,     0,
     440,     0,     0,     0,     0,     0,  1028,   478,  1030,  1031,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,   508,     0,     0,     0,     0,     0,     0,     0,     0,
    1050,     0,     0,     0,     0,     0,     7,     8,  1051,  1052,
    1053,     0,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1579,     0,  1582,  1062,  1585,     0,
       0,     0,     0,     0,  1064,     0,  1593,  1069,     0,  1596,
       0,     0,     0,     0,     0,     0,     0,   440,   440,   440,
     440,   573,   574,     0,  1084,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   581,     0,   639,    24,    25,   640,
      27,    28,   641,    30,   642,     0,     0,    32,     0,    33,
    1624,     0,     0,  1627,    38,    39,     0,    41,    42,    43,
       0,     0,     0,     0,    46,     0,   441,     0,   615,     0,
       0,   441,     0,   440,     0,   441,  1335,     0,     0,     0,
       0,     0,   441,  1128,     0,  1130,     0,  1132,     0,  1134,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,  1668,     0,   977,  1671,     0,     0,     0,
       0,     0,     0,     0,     0,   978,     0,     7,     8,     0,
       0,     0,     0,   979,   980,   981,     0,     0,  1693,   982,
     983,   984,   985,     0,     0,     0,     0,  1179,     0,     0,
    1182,     0,  1355,     0,  1185,     0,  1186,  1187,  1188,     0,
       0,   544,     0,   441,  1193,     0,     0,     0,     0,     0,
       0,     0,     0,   809,     0,     0,     0,     0,     0,     0,
       0,  1208,     0,  1210,     0,     0,     0,   639,    24,    25,
     640,    27,    28,   641,    30,   642,  1733,  1734,    32,     0,
      33,   977,     0,     0,     0,    38,    39,     0,    41,    42,
      43,   978,     0,     0,     0,    46,  1797,  1243,     0,   979,
     980,   981,     0,     0,     0,   982,   983,   984,   985,  1252,
    1253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1262,  1264,     0,     0,     0,     0,     0,    67,    68,
      69,     0,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,   441,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,  1304,  1305,  1306,     0,
     418,     0,     0,     0,     0,     0,  1316,     0,  1318,     0,
       0,     0,  1798,     0,     7,     8,     0,     0,     0,  1323,
       0,     0,   544,     0,   810,     0,     0,   440,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   977,     0,     0,     0,   418,     0,     0,     0,
    1356,     0,   978,  1347,  1348,  1349,     0,   441,   441,     0,
     979,   980,   981,     0,     0,   890,   982,   983,   984,   985,
       0,     0,     0,     0,   639,    24,    25,   640,    27,    28,
     641,    30,   642,     0,     0,    32,     0,    33,     0,     0,
    1365,     0,    38,    39,     0,    41,    42,    43,     0,   441,
     441,   441,    46,     0,  1378,     0,     0,     0,     0,  1384,
       0,  1478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1390,  1391,     0,   441,   944,     0,     0,  1396,
    1397,  1508,   796,     0,  1399,    67,    68,    69,     0,     0,
       0,     0,  1406,  1799,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   440,  1418,     0,  1419,     0,     0,     0,
       0,   441,     0,     0,     0,     0,     0,     0,  1436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,     0,     0,   440,     0,     0,  1451,     0,     0,
       0,     0,  1453,  1454,  1455,  1456,     0,     0,     0,     0,
       0,   965,     0,     0,     0,  1464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1474,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,  1036,  1485,  1486,   418,     0,     0,  1044,     0,     0,
    1492,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   441,     0,   441,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   796,   924,     0,
       0,     0,     0,  1056,     0,     0,  1511,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,  1525,   418,   543,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,  1537,   441,  1538,     0,   418,   440,     0,     0,     0,
       0,     0,     0,  1545,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,  1550,     0,     0,
       0,     0,  1554,     0,  1105,  1106,     0,  1108,     0,  1111,
    1112,     0,     0,  1115,  1116,     0,     0,   441,     0,     0,
     440,     0,     0,     0,     0,     0,   441,  1578,   441,  1581,
     441,  1584,   441,     0,     0,     0,     0,   441,     0,     0,
     441,   440,     0,     0,     0,  1597,  1598,  1599,  1600,  1601,
       0,     0,     0,     0,     0,   639,    24,    25,   640,    27,
      28,   641,    30,   642,  1612,  1613,    32,     0,    33,  1615,
       0,     0,     0,    38,    39,     0,    41,    42,    43,  1619,
       0,     0,     0,    46,     0,  1540,     0,     0,     0,  1630,
       0,     0,   441,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1196,  1197,  1198,     0,     0,     0,     0,     0,
       0,     0,     0,  1206,     0,     0,    67,    68,    69,  1655,
       0,     0,     0,     0,  1384,     0,     0,   441,   441,   441,
     441,  1663,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1677,     0,     0,  1681,     0,
       0,  1685,     0,     0,     0,  1688,     0,     0,     0,   440,
       0,   440,  1695,  1696,  1697,  1698,  1255,     0,     0,     0,
       0,     0,  1702,     0,     0,  1704,     0,     0,     0,     0,
       0,     0,   966,   441,     0,  1274,     0,     0,     0,     0,
       0,  1280,     0,     0,     0,     0,     0,  1285,     0,  1287,
    1288,     0,     0,     0,  1291,  1292,     0,  1293,     0,  1294,
       0,  1295,     0,  1296,  1297,  1298,     0,     0,  1732,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1317,     0,   440,     0,  1748,  1749,  1750,  1751,     0,
       0,     0,     0,     0,     0,     0,  1328,     0,     0,     0,
    1332,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,  1777,  1778,     0,     0,     0,     0,     0,     0,     0,
       0,  1786,  1787,  1788,  1789,     0,     0,     0,   108,   280,
       0,     0,     0,     0,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   282,     0,     0,     0,     0,     0,     0,  1376,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,  1388,     0,     0,     0,   151,   152,   153,     0,     0,
       0,  1653,     0,   154,     0,     0,     0,   283,     0,     0,
     284,     0,     0,   285,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,     0,  1715,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,  1255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,     0,     0,
       0,  1608,   548,     0,  1457,     7,     8,     0,     0,     0,
       0,  1466,     0,     0,     0,  1467,     0,     0,   157,  1471,
       0,   160,     0,     0,     0,     0,   161,   162,   163,   164,
     165,     0,     0,     0,     0,     0,     0,     0,     0,  1487,
       0,     0,     0,     0,     0,     0,   495,  1443,     0,     0,
       0,   169,     0,     0,     0,     0,   497,     0,     0,     0,
    1255,   173,     0,   247,   546,   639,    24,    25,   640,    27,
      28,   641,    30,   642,     0,     0,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,     0,    46,     0,     0,  1522,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,   441,   441,     0,     0,    67,    68,    69,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,  1255,   418,     0,     0,
     441,     0,     0,     0,   441,     0,     0,     0,     0,     0,
       0,     0,  1255,     0,     0,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   684,   416,   417,
       0,  1590,   108,   280,   418,     0,     0,     0,   111,   112,
     113,     0,   989,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   151,
     152,   153,     0,     0,     0,     0,  1640,   154,     0,     0,
       0,   283,     0,     0,   284,     0,     0,   285,     0,   286,
       0,     0,     0,     0,     0,     0,   544,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,  1666,
       0,    48,    49,    50,    51,    52,   441,     0,     0,    56,
       0,     0,    59,   441,   639,    24,    25,   640,    27,    28,
     641,    30,   642,     0,     0,    32,     0,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,  1255,
       0,     0,    46,     0,     0,  1699,     0,     0,     0,     0,
     441,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   548,     0,     0,     0,     0,
       0,   441,     0,     0,     0,    67,    68,    69,     0,     0,
     167,   439,     0,     0,     0,   169,     0,     0,     0,     0,
     289,     0,     0,     0,     0,   173,     0,     0,   546,   108,
     280,   110,     0,     0,     0,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   282,  1255,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   147,
     148,   149,     0,     0,   150,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,   155,     0,     0,   283,     0,
       0,   284,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   441,
     287,   441,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,    56,     0,     0,    59,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     549,   416,   417,   548,     0,     0,     0,   418,     0,   157,
     158,   159,   160,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   166,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   288,     0,
       0,     0,   169,     0,     0,     0,     0,   289,     0,   108,
     280,   110,   173,     0,   290,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   282,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   147,
     148,   149,     0,     0,   150,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,   155,     0,     0,   283,     0,
       0,   284,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   684,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,   160,   806,     0,     0,     0,   161,   162,   163,
     164,   165,   166,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   167,   288,     0,
       0,   418,   169,   791,     0,     0,     0,   289,   736,   108,
     319,   110,   173,     0,  1470,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   891,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   147,
     148,   149,     0,     0,   150,     0,   151,   152,   153,     0,
     108,   319,   110,     0,   154,   155,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     147,   148,   149,     0,     0,   150,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,   155,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,   157,
     158,   159,   160,  1021,     0,     0,     0,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1201,     0,     0,     0,     0,   167,   168,     0,
       0,     0,   169,     0,     0,     0,     0,   289,     0,     0,
       0,     0,   173,     0,  1263,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     157,   158,   159,   160,   418,     0,     0,     0,   161,   162,
     163,   164,   165,   166,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   167,   168,
       0,     0,   418,   169,     0,     0,     0,     0,   289,   673,
     108,   319,   110,   173,     0,  1463,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     7,     8,
     147,   148,   149,     0,     0,   150,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,   155,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,   639,    24,
      25,   640,    27,    28,   641,    30,   642,     0,     0,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,   166,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,   167,   168,
       0,     0,     0,   169,     0,     0,     0,     0,   289,     0,
     108,   280,   281,   173,     0,  1473,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,  1029,   146,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   639,    24,    25,   640,    27,    28,   641,    30,   642,
       0,     0,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,   167,   288,
       0,     0,     0,   169,     0,     0,     0,     0,   289,     0,
     108,   280,  1326,   173,     0,   290,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,  1034,     0,
       0,     7,     8,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   639,    24,    25,   640,    27,    28,   641,    30,   642,
       0,     0,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,   167,   288,
       0,     0,     0,   169,     0,     0,     0,     0,   289,     0,
     108,   280,     0,   173,     0,  1327,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,  1142,     0,
       0,     7,     8,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   639,    24,    25,   640,    27,    28,   641,    30,   642,
       0,     0,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,   167,   288,
       0,     0,     0,   169,     0,     0,     0,     0,   289,     0,
     108,   280,     0,   173,     0,   290,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,  1643,     0,
       0,     7,     8,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   639,    24,    25,   640,    27,    28,   641,    30,   642,
       0,     0,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,   167,   439,
       0,     0,     0,   169,     0,     0,     0,     0,   289,     0,
     108,   280,     0,   173,     0,   542,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,  1717,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1423,     0,  1424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,   167,   439,
       0,   418,     0,   169,     0,     0,     0,     0,   289,   572,
     108,   280,     0,   173,     0,   794,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1458,     0,  1459,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,   167,   288,
       0,   418,     0,   169,     0,     0,     0,     0,   289,   729,
     108,   280,     0,   173,     0,  1331,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   283,
       0,     0,   284,     0,     0,   285,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1576,     0,  1577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,   495,  1443,
       0,   418,     0,   169,     0,     0,     0,     0,   497,  1507,
     108,   319,   110,   173,     0,   247,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     147,   148,   149,     0,     0,   150,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,   155,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,   888,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,   939,     0,     0,     0,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
     157,   158,   159,   160,   992,     0,     0,     0,   161,   162,
     163,   164,   165,   166,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   167,   168,
       0,     0,   418,   169,   108,   280,     0,     0,   289,   736,
     111,   112,   113,   173,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   282,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
       0,     0,     0,   283,     0,     0,   284,     0,     0,   285,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,    56,     0,     0,    59,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1012,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,     0,   160,     0,     0,
       0,     0,   161,   162,   163,   164,   165,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   167,   439,     0,     0,   418,   169,   108,   319,
       0,     0,   289,   737,   111,   112,   113,   173,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,     0,     0,
       0,     0,     0,   154,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,  1042,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,  1146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,   157,     0,
       0,   160,     0,     0,     0,     0,   161,   162,   163,   164,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,     0,     0,   167,   168,     0,     0,
       0,   169,     0,    -4,    -4,    -4,   289,     0,     0,    -4,
      -4,   173,    -4,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     6,     0,     0,     0,     0,
      -4,     0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     9,    10,
      -4,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
      -4,    11,    12,    13,     0,     0,     0,    14,    15,     0,
      16,     0,     0,     0,    17,    18,     0,    19,    20,     0,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,    63,    64,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,    66,    67,    68,    69,     0,     0,    70,
       0,    71,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,    87,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,  1421,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,  1440,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1495,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    1496,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,  1497,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,  1498,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,  1499,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1531,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    1592,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,  1602,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,  1603,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,  1631,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1634,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    1637,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,  1664,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,  1674,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,  1709,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1711,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    1713,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,  1731,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,  1757,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,  1795,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,  1796,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    1800,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,  1801,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,  1802,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,  1803,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
     803,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,   837,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,   845,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,   846,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,   847,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
     858,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,   974,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,   975,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,   976,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1007,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1098,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1144,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1145,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,  1200,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1339,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1340,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1341,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1342,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,  1379,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1380,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1387,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1532,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1533,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,  1534,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1535,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1551,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1552,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1556,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,  1649,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1650,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1651,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1652,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1659,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,  1662,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1705,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1722,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1723,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1724,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     0,  1725,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,  1768,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
    1769,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1770,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,  1771,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   399,     0,   400,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,   631,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,   808,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,   816,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,   824,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
     904,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,     0,     0,  1000,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,     0,     0,  1001,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,     0,     0,  1005,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
       0,     0,  1006,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,     0,     0,  1008,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,     0,     0,  1045,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,     0,
       0,  1093,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,     0,     0,  1336,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,     0,     0,  1370,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,     0,     0,
    1520,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   630,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,   683,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   687,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   688,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,   690,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,   692,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,   693,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,   696,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   697,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     791,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   799,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,   800,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   801,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   807,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,   815,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,   823,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,   903,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,   928,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   933,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     938,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   941,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,   942,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,   948,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,   957,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,   958,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,   959,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,   991,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418,     0,   993,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,     0,     0,     0,     0,   418,     0,   994,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,     0,     0,     0,     0,   418,     0,
     995,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,     0,     0,   418,
       0,   999,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,     0,     0,     0,     0,
     418,     0,  1233,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,     0,     0,     0,
       0,   418,     0,  1422,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,     0,     0,
       0,     0,   418,     0,  1439,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,     0,
       0,     0,     0,   418,     0,  1462,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
       0,     0,     0,     0,   418,     0,  1658,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,     0,     0,     0,   418,     0,  1729,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     0,     0,     0,     0,   418
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1326)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,   240,   364,  1329,   366,     4,   107,   489,   490,
     203,   986,     4,   374,     5,   208,     6,     4,     6,   212,
       4,   390,   255,     4,     4,     6,   219,     6,     5,     5,
       0,     6,     4,   402,   267,     4,     4,     4,     4,   192,
       5,     5,     4,     4,   197,     3,     5,    78,     6,     5,
       7,     5,     5,    72,    57,     5,    75,     6,     6,    78,
       6,     6,    65,   188,   189,     6,     6,     6,   181,   182,
      13,   181,   182,   198,     6,   191,    79,  1402,   181,   182,
       6,     6,   198,   316,    98,   318,   199,   197,     6,   199,
      75,    72,   138,    78,   108,   198,   181,   182,   191,    57,
     193,   191,   116,   117,   118,   151,   152,   200,   122,   123,
     124,   125,   197,   191,   199,   193,     3,     4,   188,   189,
     990,    79,     9,    10,    11,   195,   191,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     4,
     141,   188,   189,     7,     4,   181,   182,     6,    45,    46,
      47,   198,    49,  1488,   141,   141,   128,   129,   130,   131,
     173,   197,   174,    60,    61,    62,     6,    75,   147,  1504,
      78,    68,   185,   186,     7,   199,   126,   126,   178,   150,
     193,   141,  1167,   191,   126,   193,     6,   195,   201,   191,
     203,   126,   200,   178,   191,   208,   185,   186,   401,   212,
     579,   198,   215,   193,   198,   173,   219,   220,   221,   222,
     200,   198,   225,   226,   227,   191,   198,   185,   186,   198,
     198,   198,   198,   198,   198,   193,   239,   199,   195,   198,
     181,   182,   198,   201,   198,   198,   191,   480,   481,   198,
     198,   188,   189,   198,   200,   181,   182,     6,   261,   262,
     263,   630,   631,   181,   182,    72,   153,   500,    75,   156,
     191,    78,   275,   276,   161,   162,   163,   164,   165,   191,
       6,   474,   475,   138,   139,   288,   198,   290,   138,   139,
     390,   191,   181,   182,   181,   182,   181,   182,   198,   186,
       7,   181,   182,    78,   191,    80,   191,     6,   197,   196,
     199,   198,     7,   198,   168,   169,   170,   171,   198,   191,
     323,   324,   193,   516,   517,   518,   198,   560,     7,   194,
     188,   189,   197,   336,   188,   189,  1661,   181,   182,   572,
     198,   195,   181,   182,   191,   168,   169,   170,   171,   542,
     192,     4,   194,   197,   328,   197,     7,   181,   182,   198,
     193,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     191,   374,   375,   197,   181,   182,   379,   380,   381,   382,
     383,   181,   182,   329,   191,   578,   365,   191,   367,   368,
     369,   198,   371,   372,   192,   191,   375,   197,   401,   197,
     379,   380,   381,   382,     4,     5,   364,   365,   366,   367,
     368,   369,     4,   371,   372,   192,   374,   375,   181,   182,
     197,   379,   380,   381,   382,   383,   191,    97,   193,   191,
    1755,   377,   102,   103,   197,   200,   439,   191,   384,    39,
      40,    41,    42,    43,    44,    84,   815,   816,    48,   102,
     103,   104,   105,    53,    54,    55,   194,   110,    58,   197,
     113,   168,   169,   170,   171,   192,    78,   181,   182,    69,
     197,   474,   475,   168,   169,   170,   171,   670,     6,   672,
      72,   188,   189,   197,    76,   198,   586,   489,   490,   168,
     169,   170,   171,   188,   189,   181,   182,    78,    90,   732,
     181,   182,    78,   181,   182,   183,   184,   185,    78,   188,
     189,   197,   190,   516,   517,   518,   197,   168,   169,   170,
     171,   467,   468,   469,   470,   528,    80,   181,   182,   191,
     630,   631,    98,   181,   182,    97,   729,   188,   189,   542,
     102,   103,   108,   197,   181,   182,   549,   181,   182,   197,
     116,   117,   118,   527,   154,   155,   122,   123,   124,   125,
     197,   181,   182,   197,   192,    75,   166,   181,   182,   197,
     528,   181,   182,     6,     7,   578,   191,   197,   193,   553,
     949,   774,   951,   197,   953,   200,   955,   197,   188,   189,
     783,   192,   785,   194,   787,   195,   789,   198,   191,   198,
     193,   794,   195,   198,   797,  1580,    78,   200,  1583,    75,
     197,  1586,   199,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,    75,   599,   600,   601,   602,   603,
     604,   605,   197,   199,   199,   609,   610,   611,   181,   182,
      78,   181,   182,   881,   647,  1515,   620,  1517,     4,  1519,
     181,   182,     4,   627,   197,     4,   849,   197,   181,   182,
     181,   182,     4,   637,   181,   182,   197,   670,   197,   672,
     199,   191,   675,   773,   197,   678,   197,   680,     6,     7,
     197,   684,   685,   181,   182,   197,   632,   199,   183,   184,
     185,   884,   885,   886,   887,   190,   675,  1066,   192,   197,
     191,   680,   193,   197,   195,   708,     5,   198,   197,   200,
     199,   181,   182,  1082,  1689,   815,   816,   675,   191,   197,
     678,   199,   680,   823,   824,    72,   729,   191,    75,    72,
     191,    78,    75,    80,   192,    78,   682,    80,     6,   197,
      39,    40,    41,    42,    43,    44,   193,   940,   195,    48,
       6,   193,   192,   200,    53,    54,    55,   197,     4,    58,
    1735,     4,   192,  1738,   194,   192,  1741,   194,   198,  1744,
      69,   774,     7,   192,  1644,   194,   197,   191,   199,   198,
     783,   192,   785,   194,   787,    75,   789,   198,    78,   191,
      80,   794,    75,   191,   797,    78,   192,    80,   194,   191,
     197,   197,   199,   903,   904,  1780,   192,  1782,   194,  1784,
     813,   197,   192,   197,   194,   199,   819,   197,     8,   198,
     192,   824,   194,   198,   191,   197,  1307,  1308,   197,   197,
     199,   199,   197,   191,   199,  1073,   191,   197,  1708,   199,
    1710,     6,  1712,  1212,     6,   824,   849,   197,  1718,   199,
     191,   854,   855,   856,   857,   154,   155,    78,    78,    80,
      80,   197,     4,   199,   867,   198,   824,   166,   197,     8,
     199,   197,   197,   199,   199,   854,   191,   856,   857,   198,
     191,   884,   885,   886,   887,   197,   191,   199,   867,   191,
     197,  1761,   199,  1763,   198,  1765,   854,   191,   856,   857,
     197,   197,   199,   199,   191,   197,   909,   199,  1008,   867,
     198,   197,   858,   199,   198,   889,   197,   197,   199,   199,
     197,   191,   199,   926,   927,   197,   929,   199,   931,   932,
     909,   191,   935,   936,   197,     6,   199,   940,     4,   197,
       6,   199,   197,   197,   199,   199,   920,   921,   198,    49,
      50,   909,    52,    98,   191,   220,   221,   222,   191,   198,
     225,   226,   227,   108,   191,   197,  1066,   199,   197,   191,
     199,   116,   117,   118,   197,   191,   199,   122,   123,   124,
     125,  1174,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   261,   262,   191,   197,
     190,   199,   197,   197,   199,   199,  1244,   193,   191,   199,
     275,   276,   197,   197,   199,   199,   191,     4,     5,   200,
     191,  1024,  1025,  1026,   197,   197,   199,   199,   197,  1510,
     199,   191,  1035,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   197,   197,   199,
     199,   190,    39,    40,    41,    42,    43,    44,   191,   191,
     199,    48,   197,   197,   199,   199,    53,    54,    55,  1043,
     197,    58,   199,   197,    98,   199,  1050,  1051,  1052,  1053,
    1054,   197,    69,   199,   108,  1088,  1060,  1061,   191,    21,
      22,     6,   116,   117,   118,   197,   193,   199,   122,   123,
     124,   125,   198,   197,  1107,   199,  1299,  1300,   198,   197,
    1113,   199,  1473,   198,   193,  1215,  1119,   193,  1121,  1122,
     193,     6,     6,  1126,  1127,   195,  1129,   141,  1131,   198,
    1133,     6,  1135,  1136,  1137,   200,     6,     6,   198,     6,
     193,     4,   190,   243,   244,   195,     7,   198,   197,     7,
    1153,   251,   199,  1099,   197,   255,     7,     6,     6,     6,
     192,     7,     6,   198,     7,  1168,     6,   154,   155,  1172,
       7,  1174,     6,     6,   106,   199,     6,     4,    50,   166,
     138,   198,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    98,    50,    50,
    1184,    50,   192,   145,     6,     6,   148,   108,   192,  1222,
     192,  1195,   154,   155,   197,   116,   117,   118,   160,   197,
     197,   122,   123,   124,   125,   197,   197,  1337,   192,   192,
     192,  1479,     6,  1222,     4,     4,     7,  1250,    98,     6,
       6,     6,     6,   141,     7,     7,     7,  1260,   108,   141,
    1263,     7,     7,   141,  1222,   198,   116,   117,   118,     7,
    1463,     7,   122,   123,   124,   125,     4,     6,   192,   197,
    1226,  1260,   192,   192,   197,   197,   192,     6,   195,   197,
    1236,  1524,   194,     7,   199,   199,  1299,  1300,   198,   198,
     198,   198,  1260,     7,     7,  1307,  1308,     6,   199,   195,
       6,   198,    98,     6,  1507,     6,   193,  1263,     7,     6,
       6,   178,   108,     8,  1327,   191,  1329,   191,  1331,     6,
     116,   117,   118,   198,     7,  1528,   122,   123,   124,   125,
       7,     7,     7,  1346,     7,    80,     7,     7,   280,   199,
    1353,     6,    78,     7,  1357,     4,    98,  1303,  1361,     7,
      12,    13,     6,     4,     7,   297,   108,     7,     7,     7,
       6,     6,   198,   191,   116,   117,   118,     7,  1381,     6,
     122,   123,   124,   125,     7,     7,  1360,   487,   488,     7,
     198,     6,     6,     6,     6,   495,     6,     4,     4,  1402,
       4,   199,   197,     6,     6,     6,  1352,     6,     4,     6,
     192,   192,  1645,   199,   192,  1361,  1362,  1363,   197,   192,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   195,
       7,    83,   195,    85,     6,  1438,   198,     6,    90,    91,
    1443,    93,    94,    95,   191,     6,     6,     6,   100,   198,
     198,     6,     6,  1646,     6,  1648,    90,   199,   198,   198,
    1463,   393,     6,     6,   198,     5,     4,  1470,   198,     6,
    1473,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     198,   133,   134,   135,   190,  1488,     7,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,  1504,     6,   198,  1507,   190,   198,   192,  1510,   193,
       6,     6,     6,     6,     4,  1473,   198,   198,   198,     6,
    1523,     6,     6,   197,     6,  1528,   137,  1720,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     4,     6,     4,     6,   190,   199,     6,     6,
       3,     4,     5,   198,     6,     6,     9,    10,    11,     6,
       4,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     6,     6,  1588,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     6,     6,     5,
      53,    54,    55,     6,     6,    58,   141,    60,    61,    62,
       6,     6,     6,     6,     6,    68,    69,     6,  1621,     6,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     6,   735,     6,     6,   190,    86,
      87,     6,   742,  1646,   197,  1648,     6,     6,   748,     6,
       6,   192,     6,   195,     7,     6,     6,     6,  1661,   198,
       6,     5,  1608,    76,     6,   198,     6,   198,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   199,   199,   198,   198,   190,   198,     6,   198,
       7,     6,     6,   136,   147,     6,   199,   139,     6,     6,
     153,   154,   155,   156,     6,     6,     6,     6,   161,   162,
     163,   164,   165,   166,     6,   198,     6,  1720,     6,     6,
     167,   168,   169,   170,   171,  1728,     6,   198,   181,   182,
     198,    98,   198,   186,   198,     6,    98,   184,   191,   198,
     193,   188,   195,   196,   199,   198,     6,   200,     6,  1728,
       6,     6,  1755,  1699,     6,   202,   203,   204,   205,     6,
     207,   208,   209,   210,     6,   212,   213,   214,     6,  1772,
    1728,  1774,   219,     6,     6,     6,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     237,     6,   199,  1772,   190,  1774,     6,   198,   198,   246,
     247,  1804,     6,     6,     6,     6,     6,   198,   255,     6,
       6,     6,   198,   198,  1772,     6,  1774,   198,   198,   198,
     198,     6,   922,     6,     6,  1804,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       6,   288,   289,   290,   190,     6,  1804,     6,     6,     6,
       6,     6,     6,   300,   301,   302,     6,   304,     6,  1611,
     307,   308,  1096,  1493,   311,   435,  1106,  1494,     3,     3,
     465,  1571,    -1,    -1,   974,   975,   976,  1240,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   339,   340,    -1,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,   376,
      -1,   378,    -1,    -1,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,   398,   190,    -1,   401,    -1,    -1,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,    -1,    -1,   421,   422,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,   439,    -1,   190,    -1,    -1,    -1,   445,    -1,
      -1,    -1,    -1,   450,    -1,    -1,    -1,    -1,   455,   456,
      -1,    -1,    -1,    -1,   461,   462,    -1,    -1,    -1,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,   493,   494,   495,   496,
     497,    -1,    -1,    -1,   501,   502,   503,   504,   505,    -1,
      -1,    -1,   509,    98,   511,   512,  1166,    -1,    -1,   516,
     517,   518,    -1,   108,   521,   522,   523,   524,   525,    -1,
      -1,   116,   117,   118,   531,    -1,    -1,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   542,     6,    -1,    -1,    -1,
      -1,   548,   549,    -1,   551,   552,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,   570,   190,    -1,     3,     4,    -1,    -1,
     577,   578,     9,    10,    11,    -1,   583,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    45,    46,
      47,  1271,    49,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,   633,   108,    -1,    -1,
      -1,    68,    -1,    -1,     6,   116,   117,   118,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,    -1,    -1,    -1,  1309,
      -1,  1311,    -1,  1313,    -1,    -1,    -1,    -1,    -1,    -1,
     667,    -1,    98,   670,    -1,   672,   673,  1327,    -1,    -1,
    1330,  1331,   108,    -1,   681,    -1,    -1,   684,   685,    -1,
     116,   117,   118,    -1,    -1,    -1,   122,   123,   124,   125,
      -1,   698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     707,    -1,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   153,    -1,   199,   156,
     190,    -1,   729,    -1,   161,   162,   163,   164,   165,   736,
     737,    -1,    -1,    -1,    -1,   742,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,    -1,    -1,   755,   186,
      -1,   758,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,   199,    -1,    -1,    -1,   774,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,   783,    -1,   785,    -1,
     787,    -1,   789,    -1,    -1,    -1,    -1,   794,    -1,    -1,
     797,    -1,    -1,    -1,    -1,    -1,   803,   239,   805,   806,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     837,    -1,    -1,    -1,    -1,    -1,    12,    13,   845,   846,
     847,    -1,   849,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1514,    -1,  1516,   864,  1518,    -1,
      -1,    -1,    -1,    -1,   871,    -1,  1526,   874,    -1,  1529,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   884,   885,   886,
     887,   323,   324,    -1,   891,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   336,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    -1,    83,    -1,    85,
    1570,    -1,    -1,  1573,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    -1,    -1,   100,    -1,   203,    -1,   370,    -1,
      -1,   208,    -1,   940,    -1,   212,     6,    -1,    -1,    -1,
      -1,    -1,   219,   950,    -1,   952,    -1,   954,    -1,   956,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
      -1,    -1,    -1,  1623,    -1,    98,  1626,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    12,    13,    -1,
      -1,    -1,    -1,   116,   117,   118,    -1,    -1,  1648,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,  1004,    -1,    -1,
    1007,    -1,     6,    -1,  1011,    -1,  1013,  1014,  1015,    -1,
      -1,   288,    -1,   290,  1021,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,    -1,  1040,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,  1706,  1707,    83,    -1,
      85,    98,    -1,    -1,    -1,    90,    91,    -1,    93,    94,
      95,   108,    -1,    -1,    -1,   100,   199,  1074,    -1,   116,
     117,   118,    -1,    -1,    -1,   122,   123,   124,   125,  1086,
    1087,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1098,  1099,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,    -1,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,   401,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,  1143,  1144,  1145,    -1,
     190,    -1,    -1,    -1,    -1,    -1,  1153,    -1,  1155,    -1,
      -1,    -1,   199,    -1,    12,    13,    -1,    -1,    -1,  1166,
      -1,    -1,   439,    -1,   199,    -1,    -1,  1174,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    98,    -1,    -1,    -1,   190,    -1,    -1,    -1,
       6,    -1,   108,  1200,  1201,  1202,    -1,   474,   475,    -1,
     116,   117,   118,    -1,    -1,   647,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,    -1,
    1237,    -1,    90,    91,    -1,    93,    94,    95,    -1,   516,
     517,   518,   100,    -1,  1251,    -1,    -1,    -1,    -1,  1256,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1269,  1270,    -1,   542,   708,    -1,    -1,  1276,
    1277,     6,   549,    -1,  1281,   133,   134,   135,    -1,    -1,
      -1,    -1,  1289,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1299,  1300,  1301,    -1,  1303,    -1,    -1,    -1,
      -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,  1315,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1327,    -1,    -1,    -1,  1331,    -1,    -1,  1334,    -1,    -1,
      -1,    -1,  1339,  1340,  1341,  1342,    -1,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,  1352,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1362,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,   813,  1379,  1380,   190,    -1,    -1,   819,    -1,    -1,
    1387,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   670,    -1,   672,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,   685,    -1,
      -1,    -1,    -1,   855,    -1,    -1,  1423,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,  1441,   190,  1443,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,  1458,   729,  1460,    -1,   190,  1463,    -1,    -1,    -1,
      -1,    -1,    -1,  1470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,  1484,    -1,    -1,
      -1,    -1,  1489,    -1,   926,   927,    -1,   929,    -1,   931,
     932,    -1,    -1,   935,   936,    -1,    -1,   774,    -1,    -1,
    1507,    -1,    -1,    -1,    -1,    -1,   783,  1514,   785,  1516,
     787,  1518,   789,    -1,    -1,    -1,    -1,   794,    -1,    -1,
     797,  1528,    -1,    -1,    -1,  1532,  1533,  1534,  1535,  1536,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,  1551,  1552,    83,    -1,    85,  1556,
      -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,  1566,
      -1,    -1,    -1,   100,    -1,     6,    -1,    -1,    -1,  1576,
      -1,    -1,   849,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1024,  1025,  1026,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1035,    -1,    -1,   133,   134,   135,  1606,
      -1,    -1,    -1,    -1,  1611,    -1,    -1,   884,   885,   886,
     887,  1618,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1632,    -1,    -1,  1635,    -1,
      -1,  1638,    -1,    -1,    -1,  1642,    -1,    -1,    -1,  1646,
      -1,  1648,  1649,  1650,  1651,  1652,  1088,    -1,    -1,    -1,
      -1,    -1,  1659,    -1,    -1,  1662,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   940,    -1,  1107,    -1,    -1,    -1,    -1,
      -1,  1113,    -1,    -1,    -1,    -1,    -1,  1119,    -1,  1121,
    1122,    -1,    -1,    -1,  1126,  1127,    -1,  1129,    -1,  1131,
      -1,  1133,    -1,  1135,  1136,  1137,    -1,    -1,  1705,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1153,    -1,  1720,    -1,  1722,  1723,  1724,  1725,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,
    1172,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,  1758,  1759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1768,  1769,  1770,  1771,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,  1250,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,  1263,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,     6,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,     6,    -1,    -1,    -1,   102,   103,   104,
     105,   106,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1174,    -1,    -1,
      -1,     7,     8,    -1,  1346,    12,    13,    -1,    -1,    -1,
      -1,  1353,    -1,    -1,    -1,  1357,    -1,    -1,   153,  1361,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1381,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
    1402,   196,    -1,   198,   199,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    -1,    -1,   100,    -1,    -1,  1438,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,  1299,  1300,    -1,    -1,   133,   134,   135,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,  1488,   190,    -1,    -1,
    1327,    -1,    -1,    -1,  1331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1504,    -1,    -1,    -1,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,  1523,     3,     4,   190,    -1,    -1,    -1,     9,    10,
      11,    -1,   199,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,  1588,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,  1443,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,  1621,
      -1,   102,   103,   104,   105,   106,  1463,    -1,    -1,   110,
      -1,    -1,   113,  1470,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    91,    -1,    93,    94,    95,    -1,  1661,
      -1,    -1,   100,    -1,    -1,     7,    -1,    -1,    -1,    -1,
    1507,    -1,   153,    -1,    -1,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,   165,     8,    -1,    -1,    -1,    -1,
      -1,  1528,    -1,    -1,    -1,   133,   134,   135,    -1,    -1,
     181,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   199,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,  1755,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1646,
      94,  1648,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,   113,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     8,    -1,    -1,    -1,   190,    -1,   153,
     154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,  1720,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,     3,
       4,     5,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,   155,   156,     8,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,   192,    -1,    -1,    -1,   191,   197,     3,
       4,     5,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     8,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,
       3,     4,     5,    -1,    68,    69,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    -1,    -1,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   153,
     154,   155,   156,     8,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,   181,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,    -1,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     153,   154,   155,   156,   190,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   181,   182,
      -1,    -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,
       3,     4,     5,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    12,    13,
      53,    54,    55,    -1,    -1,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,
       3,     4,     5,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,   199,    49,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,   181,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,
       3,     4,     5,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,   199,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,   181,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,
       3,     4,    -1,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,   199,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,   181,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,
       3,     4,    -1,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,   199,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,   181,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,
       3,     4,    -1,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,   181,   182,
      -1,   190,    -1,   186,    -1,    -1,    -1,    -1,   191,   198,
       3,     4,    -1,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,   181,   182,
      -1,   190,    -1,   186,    -1,    -1,    -1,    -1,   191,   198,
       3,     4,    -1,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,   181,   182,
      -1,   190,    -1,   186,    -1,    -1,    -1,    -1,   191,   198,
       3,     4,     5,   196,    -1,   198,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    -1,    -1,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,   199,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   181,   182,
      -1,    -1,   190,   186,     3,     4,    -1,    -1,   191,   197,
       9,    10,    11,   196,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,
      -1,   110,    -1,    -1,   113,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,    -1,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   181,   182,    -1,    -1,   190,   186,     3,     4,
      -1,    -1,   191,   197,     9,    10,    11,   196,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,   153,    -1,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,   181,   182,    -1,    -1,
      -1,   186,    -1,    50,    51,    52,   191,    -1,    -1,    56,
      57,   196,    59,    -1,    -1,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,   119,   120,   121,     4,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    12,    13,   132,   133,   134,   135,    -1,
      -1,   138,    -1,   140,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    37,    38,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      59,    -1,    -1,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,    -1,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,    -1,    -1,   138,
      -1,   140,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,   192,    -1,   194,   172,   173,   174,   175,
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
     184,   185,    -1,    -1,    -1,    -1,   190
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   202,   203,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    56,    57,    59,    63,    64,    66,
      67,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    83,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   119,   120,   121,   127,   132,   133,   134,   135,
     138,   140,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   157,   158,   159,   160,   167,   204,   206,
     207,   227,   244,   245,   248,   249,   250,   251,   252,   253,
     254,   255,   276,   277,   278,   279,   297,   298,     3,     4,
       5,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    53,    54,    55,
      58,    60,    61,    62,    68,    69,   147,   153,   154,   155,
     156,   161,   162,   163,   164,   165,   166,   181,   182,   186,
     191,   193,   195,   196,   198,   200,   225,   280,   281,   293,
     294,   297,   298,    13,    78,   191,   191,     6,   198,     6,
       6,     6,     6,   191,     6,     6,   193,   193,   191,   193,
     225,   225,   191,   198,   191,   191,     4,   191,   198,   191,
     191,     4,   198,   191,   191,    84,    78,    78,     6,   198,
      72,    75,    78,    78,    78,    75,    78,    80,    80,    72,
      75,    78,    80,    75,    78,    80,    75,    78,   191,    75,
     138,   151,   152,   198,   181,   182,   191,   198,   283,   284,
     283,   198,    72,    75,    78,   198,   283,     4,    72,    76,
      90,    78,    80,    78,    75,     4,   147,   198,   297,   298,
       4,     6,    72,    75,    78,    75,    78,     4,     4,     4,
       4,     5,    36,    72,    75,    78,    80,    94,   182,   191,
     198,   245,   255,   280,   286,   287,   288,   297,   298,     4,
     191,   191,   191,     4,   198,   290,     4,   191,   191,     6,
       6,   193,     4,   298,     4,     5,   198,     5,   198,     4,
     280,   280,     6,   191,   198,   191,   193,   200,   225,     7,
     168,   169,   170,   171,   188,   189,   223,   224,     4,   191,
     193,   195,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   191,   191,   191,
     191,   191,   191,   225,   191,   225,   225,   225,     7,   191,
     191,   191,   225,   191,   191,   280,   280,   280,   280,   280,
       4,   138,   139,   298,     4,   245,   246,   247,   198,   192,
     194,   198,   226,     6,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   190,   198,
       6,   191,   193,   224,     6,   280,     4,   293,   294,   298,
     293,   280,   293,   296,   229,   232,   294,   298,   280,   182,
     280,   288,   289,   280,   280,   191,   280,   289,   280,   280,
     191,   289,   280,   280,   286,   191,   198,   289,   287,   287,
     287,   191,   191,   287,   287,   287,   191,   191,   191,   191,
     191,   191,   191,   191,   198,   198,   280,     4,   286,   290,
     198,   198,   283,   283,   283,   280,   280,   181,   182,   198,
     198,   283,   198,   198,   198,   181,   182,   191,   247,   283,
     198,   191,   198,   191,   191,   191,   287,   287,   286,   191,
       4,   193,   193,   247,     6,     6,   198,   198,   198,   287,
     287,   193,   193,   193,   191,   193,   195,   225,   193,     5,
     141,   198,     5,   141,     5,   141,     5,   141,    72,    75,
      78,    80,   198,   280,   288,   280,   199,   289,     8,   183,
       6,   191,   193,   225,     6,   280,   280,   280,   195,   280,
     198,   141,   280,   280,   280,     6,     6,   247,     6,   247,
     193,     6,   198,   286,   286,   280,   280,   198,   198,   226,
     294,   286,     6,   193,   280,   280,     4,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   296,
     293,   296,   293,   293,   293,   286,   293,   293,   280,   296,
     293,   280,   294,   280,   293,   293,   293,   293,   298,   294,
     192,   194,     7,   223,   224,   195,     7,   225,   199,    72,
      75,    78,    80,   244,   280,   289,     7,   223,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   208,   280,   280,     6,   193,   195,   192,
     197,   192,   197,   197,   192,   197,   194,   197,   228,   194,
     228,   197,   197,   192,   183,   197,   199,   192,   192,   280,
     192,   199,   192,   192,   280,   199,   192,   192,     7,   280,
     280,   199,     6,     6,     6,   280,   280,     7,     7,   273,
     273,   280,   238,   280,   294,   239,   280,   294,   240,   280,
     294,   241,   280,   294,   280,   280,   280,   289,   289,   198,
     192,     6,   198,   247,   247,   197,   197,   197,   283,   283,
     246,   246,   197,   280,   280,   280,   280,   259,   197,   247,
     280,   280,   280,   280,   280,     7,   274,     6,     7,   280,
       6,   280,   280,   199,   289,   289,   289,     6,     6,   280,
     280,   280,   280,     4,   198,   226,   298,    50,   280,    50,
      50,    50,     5,   198,     5,   198,     5,   198,     5,   198,
     289,   192,   199,   280,   198,   280,   288,   198,   226,   192,
     192,   192,   138,   197,   247,   198,     8,   192,   194,   199,
     199,   247,   192,   197,   199,   192,   194,   280,   289,   223,
       6,     6,   280,   192,   194,   224,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   197,   226,   226,
     226,   226,   226,   226,   226,   197,   197,   197,   226,   197,
     226,   226,   192,   192,   197,   197,   197,   197,   197,   192,
     226,   282,   295,     6,   197,   192,   192,   197,   226,   192,
     192,   223,   224,   195,   223,   224,   294,   280,     6,     4,
       4,   198,   291,   226,   198,   198,   198,   198,   199,   199,
     286,     8,     4,   128,   129,   130,   131,   199,   211,   215,
     218,   220,   221,   192,   194,   280,     4,     6,   178,   205,
     289,     6,   289,   280,     6,   293,     6,   298,     6,   293,
     280,   294,     7,   280,   288,   141,     7,     7,   192,     7,
     141,     7,     7,   192,   141,     7,     7,   280,   192,   199,
     198,   192,   192,   280,   286,     4,   272,     6,   192,   192,
     197,   192,   197,   192,   197,   192,   197,   192,   192,   192,
     199,   199,   289,   195,   247,   199,   199,   283,   280,   280,
     199,   199,   280,   283,   197,   197,   197,    98,   108,   116,
     117,   118,   122,   123,   124,   125,   269,   270,   283,   199,
     256,   192,   199,   192,   192,   192,   280,     6,   280,   192,
     194,   194,   199,   199,   199,   194,   194,   197,   194,   289,
     194,   198,   199,   198,   198,   198,   289,   289,   289,   289,
     199,     8,   289,   289,     7,     7,     7,   195,   280,   199,
     280,   280,     7,   195,   199,   198,   286,     6,   223,   224,
     223,   224,   199,   199,   286,   194,   224,   195,   224,   293,
     280,   280,   280,   280,   289,   293,   286,   293,   293,   294,
     234,   236,   280,   293,   280,     6,     4,   138,   139,   280,
       6,     6,     6,     7,   193,   290,   292,     6,   289,   289,
     289,   289,   226,     6,   280,   212,   191,   191,   198,   222,
       6,   224,   224,   194,   178,   293,   192,   192,   197,     7,
     226,   226,   283,    78,    80,   286,   286,     7,   286,    78,
      80,   286,   286,     7,    80,   286,   286,     6,     7,     7,
     289,     7,     7,    98,   271,     6,     7,   223,   280,   223,
     280,   223,   280,   223,   280,     7,     7,     7,     7,     7,
     199,     4,   199,   197,   197,   197,   199,   199,   283,   283,
     283,     4,     6,   198,     6,   191,     6,   126,     6,   126,
       6,   126,     6,   126,   199,   270,   197,   269,     7,     6,
       7,     7,     7,     6,   198,     6,     6,     6,    78,   280,
       6,     6,   280,   195,   199,   280,   280,   280,   280,   199,
     199,   199,   199,   280,   199,   199,   286,   286,   286,     4,
     197,     8,     8,   192,     4,     4,   286,   199,   280,     6,
     280,     6,   226,     6,     6,     4,     6,   226,   226,   226,
     226,   226,   197,   192,   192,   192,   197,   197,   226,   235,
     197,   226,   237,   192,   192,     6,     7,   223,   224,   195,
       7,     6,   290,   280,   197,   199,   199,   199,   199,   199,
     223,   191,   280,   280,   285,   286,   198,   195,     6,     6,
     205,     6,   280,   198,   280,   294,     6,     6,     6,   198,
     198,    90,   243,   243,   286,     6,   198,   198,     6,     6,
     286,   198,     6,     6,     5,   286,   199,   286,   286,     4,
       6,   286,   286,   286,   286,   286,   286,   286,   286,   198,
     198,     7,     6,     7,   280,   280,   280,   198,   198,   197,
     199,   197,   199,   197,   199,   193,   280,   286,   280,     6,
       6,     6,     6,   280,   283,   199,     5,   198,   286,   198,
     198,   198,   286,   289,   198,     6,   194,     4,   226,   197,
     197,   197,   197,   226,     6,     6,   137,   280,   280,   280,
       6,     6,     7,   197,     6,     6,     6,   223,   224,   293,
     294,     4,     4,   150,   294,   280,     6,     4,   291,     6,
     194,   290,     6,     6,     6,     6,   286,   209,   280,   197,
     197,   197,   199,   210,   280,     4,   293,   197,   286,   294,
     280,   280,   283,     6,     6,     6,   280,   280,     6,   280,
       5,     6,   198,     6,   141,   242,   280,     6,     6,     6,
       6,     6,     6,     4,     6,     6,   289,   289,   280,   280,
     294,   199,   192,   197,   199,   246,   246,   283,     6,   260,
     283,     6,   261,   283,     6,   262,   280,   199,   197,   192,
     199,   197,     6,   182,   283,     6,   285,   283,   283,     6,
     199,   280,     6,   280,   280,   280,   280,   286,   197,   199,
       8,   199,   192,   198,   280,   294,   286,   286,   192,   226,
     198,   286,   294,   198,   280,   294,   294,     6,     6,     7,
       6,   195,     6,   192,   197,   280,   280,   286,   198,   197,
     199,     6,   280,   230,   231,   199,   199,   199,   199,   199,
       5,   285,    76,     6,   198,   199,   199,   198,     6,     6,
     198,   280,   199,   199,   197,   198,   197,   198,   197,   198,
     194,     6,   286,     7,   198,   280,   197,   199,   197,   197,
       6,   199,   197,   197,   197,   197,   136,   280,   280,   289,
       6,     6,   199,     6,   233,   280,   296,   290,   139,   213,
     280,   197,   197,   285,   280,     6,   197,   234,   236,     6,
       6,     6,     6,     6,     6,   199,   198,   285,    97,   102,
     103,    97,   102,   103,   289,   246,   197,   199,   280,   283,
     269,   280,   283,   269,   280,   283,   269,     6,   197,   199,
     286,   247,   199,   283,     6,   289,   283,   280,   280,   280,
     280,   280,   199,   199,   199,     6,   197,   199,     7,   199,
       6,   198,   280,   280,   199,   280,   199,   199,   198,   280,
     199,    98,   275,   198,   283,   275,   198,   283,   199,   199,
     280,   199,   197,   199,   199,   197,   199,   199,   197,   199,
     286,     6,    98,   199,   257,   198,   197,   199,   197,   197,
     197,   197,   197,     6,     6,   280,   294,   210,   192,   197,
       6,   198,   197,   280,   199,     6,   286,     6,   283,     6,
       6,   283,     6,     6,   199,     6,   263,   280,     6,     6,
     264,   280,     6,     6,   265,   280,     6,   199,   280,   269,
     247,   289,     6,   283,   289,   280,   280,   280,   280,     7,
     199,   216,   280,   285,   280,   197,   197,   197,   198,   199,
     198,   199,   198,   199,     6,     6,   199,   199,   258,   199,
     197,   199,   197,   197,   197,   197,   294,     6,   198,   192,
     199,   199,   280,   283,   283,   269,     6,   266,   269,     6,
     267,   269,     6,   268,   269,     6,   289,     6,   280,   280,
     280,   280,   214,   293,   219,   198,     6,   199,   197,   197,
     199,   198,   199,   198,   199,   198,   199,   199,   197,   197,
     197,   197,   197,   199,   198,   285,     6,   280,   280,     6,
     269,     6,   269,     6,   269,     6,   280,   280,   280,   280,
     293,     6,   217,   293,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   197,   199,     6,     6,     6,     6,
       6,     6,   293,     6
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
#line 193 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 210 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 211 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 212 "Gmsh.y"
    { return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 213 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 214 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 215 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 216 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 217 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 218 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 219 "Gmsh.y"
    { return 1; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 224 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 228 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 235 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 240 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 245 "Gmsh.y"
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
#line 259 "Gmsh.y"
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
#line 272 "Gmsh.y"
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
#line 285 "Gmsh.y"
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
#line 313 "Gmsh.y"
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
#line 327 "Gmsh.y"
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
#line 340 "Gmsh.y"
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
#line 353 "Gmsh.y"
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
#line 371 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 385 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 387 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 392 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 394 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 399 "Gmsh.y"
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
#line 503 "Gmsh.y"
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
#line 513 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 522 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 529 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 539 "Gmsh.y"
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
#line 548 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 557 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 564 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 574 "Gmsh.y"
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
#line 582 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 592 "Gmsh.y"
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
#line 611 "Gmsh.y"
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
#line 630 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    {
    }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 643 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 644 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 645 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 646 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 647 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 652 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 658 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 658 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 659 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 659 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 668 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 673 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 679 "Gmsh.y"
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
#line 739 "Gmsh.y"
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
#line 768 "Gmsh.y"
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
#line 797 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 802 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 807 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 812 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 817 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 824 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 831 "Gmsh.y"
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
#line 846 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 851 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 856 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 861 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 866 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 875 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 881 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 890 "Gmsh.y"
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
#line 908 "Gmsh.y"
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
#line 926 "Gmsh.y"
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
#line 935 "Gmsh.y"
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
#line 947 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 952 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 960 "Gmsh.y"
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
#line 980 "Gmsh.y"
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
#line 1003 "Gmsh.y"
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
#line 1014 "Gmsh.y"
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
#line 1022 "Gmsh.y"
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
#line 1044 "Gmsh.y"
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
#line 1067 "Gmsh.y"
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
#line 1093 "Gmsh.y"
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
#line 1114 "Gmsh.y"
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
#line 1126 "Gmsh.y"
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
#line 1144 "Gmsh.y"
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
#line 1153 "Gmsh.y"
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
#line 1162 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1164 "Gmsh.y"
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
#line 1180 "Gmsh.y"
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
#line 1189 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1191 "Gmsh.y"
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
#line 1205 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1213 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1219 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1231 "Gmsh.y"
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
#line 1242 "Gmsh.y"
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
#line 1257 "Gmsh.y"
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
#line 1273 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1281 "Gmsh.y"
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
#line 1290 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1298 "Gmsh.y"
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
#line 1316 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1320 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1326 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1334 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1338 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1344 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1352 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1356 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1362 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1370 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1374 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1380 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1388 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1392 "Gmsh.y"
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
#line 1404 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1408 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1418 "Gmsh.y"
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
#line 1441 "Gmsh.y"
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
#line 1473 "Gmsh.y"
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
#line 1496 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1535 "Gmsh.y"
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
#line 1553 "Gmsh.y"
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
#line 1583 "Gmsh.y"
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
#line 1613 "Gmsh.y"
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
#line 1631 "Gmsh.y"
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
#line 1650 "Gmsh.y"
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
#line 1676 "Gmsh.y"
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
#line 1694 "Gmsh.y"
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
#line 1712 "Gmsh.y"
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
#line 1747 "Gmsh.y"
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
#line 1765 "Gmsh.y"
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
#line 1804 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1810 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1816 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1823 "Gmsh.y"
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
#line 1848 "Gmsh.y"
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
#line 1873 "Gmsh.y"
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
#line 1890 "Gmsh.y"
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
#line 1910 "Gmsh.y"
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
#line 1943 "Gmsh.y"
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
#line 1979 "Gmsh.y"
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
#line 1997 "Gmsh.y"
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
#line 2014 "Gmsh.y"
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
#line 2030 "Gmsh.y"
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
#line 2067 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2072 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2077 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2082 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2087 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 2092 "Gmsh.y"
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
#line 2115 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 2121 "Gmsh.y"
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
#line 2131 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 2132 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 2137 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 2141 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 2145 "Gmsh.y"
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
#line 2168 "Gmsh.y"
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
#line 2191 "Gmsh.y"
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
#line 2214 "Gmsh.y"
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
#line 2242 "Gmsh.y"
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
#line 2263 "Gmsh.y"
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
#line 2290 "Gmsh.y"
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
#line 2311 "Gmsh.y"
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
#line 2332 "Gmsh.y"
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
#line 2352 "Gmsh.y"
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
#line 2464 "Gmsh.y"
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
#line 2483 "Gmsh.y"
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
#line 2522 "Gmsh.y"
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
#line 2630 "Gmsh.y"
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
#line 2639 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2645 "Gmsh.y"
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
#line 2660 "Gmsh.y"
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
#line 2688 "Gmsh.y"
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
#line 2705 "Gmsh.y"
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
#line 2714 "Gmsh.y"
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
#line 2728 "Gmsh.y"
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
#line 2742 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 2748 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2754 "Gmsh.y"
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
#line 2763 "Gmsh.y"
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
#line 2772 "Gmsh.y"
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
#line 2781 "Gmsh.y"
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
#line 2795 "Gmsh.y"
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
#line 2851 "Gmsh.y"
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
#line 2869 "Gmsh.y"
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
#line 2886 "Gmsh.y"
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
#line 2901 "Gmsh.y"
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
#line 2920 "Gmsh.y"
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
#line 2932 "Gmsh.y"
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
#line 2956 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2960 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 2965 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 2972 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 2977 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 2983 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 2988 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 2994 "Gmsh.y"
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
#line 3002 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3006 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3010 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3016 "Gmsh.y"
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
#line 3070 "Gmsh.y"
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
#line 3083 "Gmsh.y"
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
#line 3100 "Gmsh.y"
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
#line 3117 "Gmsh.y"
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
#line 3139 "Gmsh.y"
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
#line 3161 "Gmsh.y"
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
#line 3196 "Gmsh.y"
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
#line 3204 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3210 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3217 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3221 "Gmsh.y"
    {
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3230 "Gmsh.y"
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
#line 3238 "Gmsh.y"
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
#line 3246 "Gmsh.y"
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
#line 3254 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3260 "Gmsh.y"
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
#line 3268 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3274 "Gmsh.y"
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
#line 3282 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3288 "Gmsh.y"
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
#line 3296 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3310 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3317 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3324 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3345 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3352 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3366 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3373 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3379 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3386 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3392 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3399 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3412 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3418 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3425 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3431 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3438 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3444 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3451 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3457 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3464 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3470 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3477 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3483 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3494 "Gmsh.y"
    {
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3497 "Gmsh.y"
    {
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3503 "Gmsh.y"
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
#line 3515 "Gmsh.y"
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
#line 3535 "Gmsh.y"
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
#line 3559 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3563 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3567 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3571 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3575 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3581 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3587 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3591 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3595 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3599 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3603 "Gmsh.y"
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
#line 3622 "Gmsh.y"
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
#line 3634 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3638 "Gmsh.y"
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
#line 3653 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3657 "Gmsh.y"
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
#line 3673 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3677 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 3682 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 3686 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3692 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 3696 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 3703 "Gmsh.y"
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
#line 3759 "Gmsh.y"
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
#line 3829 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 3834 "Gmsh.y"
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
#line 3901 "Gmsh.y"
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
#line 3937 "Gmsh.y"
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
#line 3945 "Gmsh.y"
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
#line 3988 "Gmsh.y"
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
#line 4027 "Gmsh.y"
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
		if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
			yymsg(0, "Number of master lines (%d) different from number of "
						"slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
		}
		else{
			if (List_Nbr((yyvsp[(11) - (12)].l)) < 12){
				yymsg(0, "Affine transformation requires at least 12 entries");
			}
			else {
				
				std::vector<double> transfo(16,0);
				for(int i = 0; i < List_Nbr((yyvsp[(11) - (12)].l)); i++) List_Read((yyvsp[(11) - (12)].l), i, &transfo[i]);
				
				for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){ 
					double d_master, d_slave;
					List_Read((yyvsp[(8) - (12)].l), i, &d_master);
					List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
					int j_master = (int)d_master;
					int j_slave  = (int)d_slave;
					
					addPeriodicEdge(j_slave,j_master,transfo);
				}
			}
		}	
		List_Delete((yyvsp[(8) - (12)].l));
		List_Delete((yyvsp[(4) - (12)].l));
	}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4076 "Gmsh.y"
    {
		if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
			yymsg(0, "Number of master faces (%d) different from number of "
						"slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
		}
		else{
			if (List_Nbr((yyvsp[(11) - (12)].l)) < 12){
				yymsg(0, "Affine transformation requires at least 12 entries");
			}
			else {
				std::vector<double> transfo(16,0);
				for(int i = 0; i < List_Nbr((yyvsp[(11) - (12)].l)); i++) List_Read((yyvsp[(11) - (12)].l), i, &transfo[i]);
				
				for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){ 
					double d_master, d_slave;
					List_Read((yyvsp[(8) - (12)].l), i, &d_master);
					List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
					addPeriodicFace(d_slave,d_master,transfo);
				}
			}
		}
		List_Delete((yyvsp[(4) - (12)].l));
		List_Delete((yyvsp[(8) - (12)].l));
	}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 4101 "Gmsh.y"
    {		
		if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
			yymsg(0, "Number of master edges (%d) different from number of "
						"slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
		}
		else{
			SPoint3 origin((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
			SPoint3 axis((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
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
#line 4126 "Gmsh.y"
    {
		if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
			yymsg(0, "Number of master faces (%d) different from number of "
						"slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
		}
		else{
				
			SPoint3 origin((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
			SPoint3 axis((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
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
#line 4152 "Gmsh.y"
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
#line 4177 "Gmsh.y"
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
#line 4202 "Gmsh.y"
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
				std::cout << "edge " << ds << " to " << dm << std::endl;
			}
			addPeriodicFace(j_slave,j_master,edgeCounterParts);
		}
		List_Delete((yyvsp[(5) - (12)].l));
		List_Delete((yyvsp[(10) - (12)].l));
	}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4225 "Gmsh.y"
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
#line 4253 "Gmsh.y"
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
#line 4281 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4285 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4289 "Gmsh.y"
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
#line 4317 "Gmsh.y"
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
#line 4356 "Gmsh.y"
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
#line 4395 "Gmsh.y"
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
#line 4416 "Gmsh.y"
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
#line 4437 "Gmsh.y"
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
#line 4464 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
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
#line 4478 "Gmsh.y"
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
#line 4512 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4513 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4514 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4519 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4525 "Gmsh.y"
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
#line 4537 "Gmsh.y"
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
#line 4555 "Gmsh.y"
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
#line 4582 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4583 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4584 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4585 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4586 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4587 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4588 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4589 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4591 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4597 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4598 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4599 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4600 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4601 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4602 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4603 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4604 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4605 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4606 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4607 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4608 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4609 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4610 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4611 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4612 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4613 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4614 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4615 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4616 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4617 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4618 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4619 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4621 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4622 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4623 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4624 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4625 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4626 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4627 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4629 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4638 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 4639 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 4640 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4641 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4642 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4643 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4644 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 4645 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4646 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4647 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4652 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4654 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4660 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4665 "Gmsh.y"
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
#line 4682 "Gmsh.y"
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
#line 4700 "Gmsh.y"
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
#line 4718 "Gmsh.y"
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
#line 4736 "Gmsh.y"
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
#line 4754 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4759 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4765 "Gmsh.y"
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
#line 4777 "Gmsh.y"
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
#line 4794 "Gmsh.y"
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
#line 4812 "Gmsh.y"
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
#line 4830 "Gmsh.y"
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
#line 4848 "Gmsh.y"
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
#line 4869 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4874 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4879 "Gmsh.y"
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
#line 4889 "Gmsh.y"
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
#line 4899 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4904 "Gmsh.y"
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
#line 4915 "Gmsh.y"
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
#line 4924 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4929 "Gmsh.y"
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
#line 4956 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4960 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4964 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4968 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4972 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4979 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4983 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4987 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4991 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4998 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 5003 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 5010 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 5015 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 5019 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 5024 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 5028 "Gmsh.y"
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
#line 5036 "Gmsh.y"
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
#line 5047 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 5051 "Gmsh.y"
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
#line 5063 "Gmsh.y"
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
#line 5071 "Gmsh.y"
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
#line 5079 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5086 "Gmsh.y"
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
#line 5096 "Gmsh.y"
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
#line 5125 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5129 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5133 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5137 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5141 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5145 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5149 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5153 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5157 "Gmsh.y"
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
#line 5186 "Gmsh.y"
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
#line 5215 "Gmsh.y"
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
#line 5244 "Gmsh.y"
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
#line 5274 "Gmsh.y"
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
#line 5287 "Gmsh.y"
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
#line 5300 "Gmsh.y"
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
#line 5313 "Gmsh.y"
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
#line 5325 "Gmsh.y"
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
#line 5335 "Gmsh.y"
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
#line 5345 "Gmsh.y"
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
#line 5357 "Gmsh.y"
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
#line 5370 "Gmsh.y"
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
#line 5382 "Gmsh.y"
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
#line 5400 "Gmsh.y"
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
#line 5421 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5426 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5430 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5434 "Gmsh.y"
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
#line 5446 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5450 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5462 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5469 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5479 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5483 "Gmsh.y"
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
#line 5498 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5503 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5510 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5514 "Gmsh.y"
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
#line 5527 "Gmsh.y"
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
#line 5535 "Gmsh.y"
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
#line 5546 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 5550 "Gmsh.y"
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
#line 5558 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 5564 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 5570 "Gmsh.y"
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
#line 5578 "Gmsh.y"
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
#line 5586 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 5593 "Gmsh.y"
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
#line 5608 "Gmsh.y"
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
#line 5622 "Gmsh.y"
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
#line 5636 "Gmsh.y"
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
#line 5648 "Gmsh.y"
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
#line 5664 "Gmsh.y"
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
#line 5675 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 5679 "Gmsh.y"
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
#line 5698 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 5705 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 5711 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 5713 "Gmsh.y"
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
#line 5724 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 5729 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 5735 "Gmsh.y"
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
#line 5744 "Gmsh.y"
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
#line 5757 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 5760 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 12008 "Gmsh.tab.cpp"
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
#line 5764 "Gmsh.y"


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
										 const std::vector<double>& affineTransform) {
	
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
										 const std::map<int,int>& edgeCounterparts) {
	
	Surface *target = FindSurface(abs(iTarget));	
	
	std::cout << "Encoding periodic connection between " << iTarget << " and " << iSource << std::endl;
	std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
	for (;sIter!=edgeCounterparts.end();++sIter) {
		std::cout << sIter->first << " - " << sIter->second << std::endl;
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
		if (!target || !source)  Msg::Error("Could not find surface %d or %d for periodic copy",
																				iTarget,iSource);
		target->setMeshMaster(source,edgeCounterparts);
	}
}

void addPeriodicEdge(int iTarget,int iSource,
										 const std::vector<double>& affineTransform) {
	
	Curve *target = FindCurve(abs(iTarget));
	if (target) {
		GEO_Internals::MasterEdge& me = GModel::current()->getGEOInternals()->periodicEdges[iTarget];
		me.tag = iSource;
		me.affineTransform = affineTransform;
		
		GEO_Internals::MasterEdge& test = GModel::current()->getGEOInternals()->periodicEdges[iTarget];
	}
	else{
		GEdge *target = GModel::current()->getEdgeByTag(abs(iTarget)); 
		GEdge *source = GModel::current()->getEdgeByTag(abs(iSource)); 
		if (!target || !source) Msg::Error("Could not find surface %d or %d for periodic copy",
																			 iTarget,iSource);
		if (affineTransform.size() == 16) {
			target->setMeshMaster(source,affineTransform);
		}
		else {
			target->setMeshMaster(source,iSource*iTarget < 0 ? -1:1);
		}
	}
}

void computeAffineTransformation(SPoint3& origin,
																 SPoint3& axis,
																 double angle,
																 SPoint3& translation,
																 std::vector<double>& tfo) {

	tfo.resize(16,0.0);

	angle *= acos(-1.)/180.;
	
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
	for (size_t i=0;i<3;i++) {
		int tIdx = i*4+3;
		tfo[tIdx] = translation[i];
		for (int j=0;j<3;j++,idx++) {
			tfo[tIdx] -= tfo[idx] * origin[j];
		}
		idx++;
	}
	
	for (int i=0;i<4;i++) tfo[12+i] = 0;
	tfo[15] = 1;
}
