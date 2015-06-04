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

struct doubleXstring{
  double d;
  char *s;
};


/* Line 371 of yacc.c  */
#line 173 "Gmsh.tab.cpp"

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
     tRecombine = 360,
     tSmoother = 361,
     tSplit = 362,
     tDelete = 363,
     tCoherence = 364,
     tIntersect = 365,
     tMeshAlgorithm = 366,
     tReverse = 367,
     tLayers = 368,
     tScaleLast = 369,
     tHole = 370,
     tAlias = 371,
     tAliasWithOptions = 372,
     tCopyOptions = 373,
     tQuadTriAddVerts = 374,
     tQuadTriNoNewVerts = 375,
     tQuadTriSngl = 376,
     tQuadTriDbl = 377,
     tRecombLaterals = 378,
     tTransfQuadTri = 379,
     tText2D = 380,
     tText3D = 381,
     tInterpolationScheme = 382,
     tTime = 383,
     tCombine = 384,
     tBSpline = 385,
     tBezier = 386,
     tNurbs = 387,
     tNurbsOrder = 388,
     tNurbsKnots = 389,
     tColor = 390,
     tColorTable = 391,
     tFor = 392,
     tIn = 393,
     tEndFor = 394,
     tIf = 395,
     tEndIf = 396,
     tExit = 397,
     tAbort = 398,
     tField = 399,
     tReturn = 400,
     tCall = 401,
     tMacro = 402,
     tShow = 403,
     tHide = 404,
     tGetValue = 405,
     tGetEnv = 406,
     tGetString = 407,
     tGetNumber = 408,
     tHomology = 409,
     tCohomology = 410,
     tBetti = 411,
     tSetOrder = 412,
     tExists = 413,
     tFileExists = 414,
     tGMSH_MAJOR_VERSION = 415,
     tGMSH_MINOR_VERSION = 416,
     tGMSH_PATCH_VERSION = 417,
     tGmshExecutableName = 418,
     tSetPartition = 419,
     tAFFECTDIVIDE = 420,
     tAFFECTTIMES = 421,
     tAFFECTMINUS = 422,
     tAFFECTPLUS = 423,
     tOR = 424,
     tAND = 425,
     tNOTEQUAL = 426,
     tEQUAL = 427,
     tGREATEROREQUAL = 428,
     tLESSOREQUAL = 429,
     UNARYPREC = 430,
     tMINUSMINUS = 431,
     tPLUSPLUS = 432
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 99 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;


/* Line 387 of yacc.c  */
#line 404 "Gmsh.tab.cpp"
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
#line 432 "Gmsh.tab.cpp"

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
#define YYLAST   9498

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  198
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  506
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1774

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   432

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   183,     2,   193,     2,   182,     2,     2,
     188,   189,   180,   178,   194,   179,   192,   181,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     174,     2,   175,   169,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   190,     2,   191,   187,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   195,     2,   196,   197,     2,     2,     2,
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
     165,   166,   167,   168,   170,   171,   172,   173,   176,   177,
     184,   185,   186
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
    1907,  1914,  1928,  1939,  1950,  1961,  1972,  1983,  1988,  1993,
    1998,  2003,  2008,  2011,  2015,  2022,  2024,  2026,  2028,  2031,
    2037,  2045,  2056,  2058,  2062,  2065,  2068,  2071,  2075,  2079,
    2083,  2087,  2091,  2095,  2099,  2103,  2107,  2111,  2115,  2119,
    2123,  2127,  2133,  2138,  2143,  2148,  2153,  2158,  2163,  2168,
    2173,  2178,  2183,  2190,  2195,  2200,  2205,  2210,  2215,  2220,
    2225,  2232,  2239,  2246,  2251,  2253,  2255,  2257,  2259,  2261,
    2263,  2265,  2267,  2269,  2271,  2272,  2279,  2284,  2286,  2291,
    2296,  2301,  2306,  2311,  2316,  2321,  2324,  2330,  2336,  2342,
    2348,  2352,  2359,  2364,  2372,  2379,  2386,  2393,  2400,  2405,
    2407,  2410,  2413,  2417,  2421,  2433,  2443,  2451,  2459,  2461,
    2465,  2467,  2469,  2472,  2476,  2481,  2487,  2489,  2491,  2494,
    2498,  2502,  2508,  2513,  2516,  2519,  2522,  2525,  2529,  2533,
    2537,  2541,  2547,  2553,  2559,  2565,  2582,  2599,  2616,  2633,
    2635,  2637,  2641,  2645,  2650,  2657,  2664,  2666,  2668,  2672,
    2676,  2686,  2694,  2696,  2702,  2706,  2713,  2715,  2719,  2721,
    2723,  2727,  2734,  2736,  2738,  2740,  2742,  2747,  2754,  2759,
    2764,  2769,  2774,  2783,  2788,  2797,  2802,  2809,  2814,  2816,
    2817,  2824,  2826,  2830,  2836,  2842,  2844
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     199,     0,    -1,   200,    -1,     1,     6,    -1,    -1,   200,
     201,    -1,   204,    -1,   203,    -1,   224,    -1,   241,    -1,
     242,    -1,   246,    -1,   247,    -1,   248,    -1,   249,    -1,
     252,    -1,   273,    -1,   274,    -1,   251,    -1,   250,    -1,
     245,    -1,   276,    -1,   175,    -1,   175,   175,    -1,    37,
     188,   290,   189,     6,    -1,    38,   188,   290,   189,     6,
      -1,    37,   188,   290,   189,   202,   290,     6,    -1,    37,
     188,   290,   194,   286,   189,     6,    -1,    38,   188,   290,
     194,   286,   189,     6,    -1,    37,   188,   290,   194,   286,
     189,   202,   290,     6,    -1,     4,   290,   195,   205,   196,
       6,    -1,   116,     4,   190,   277,   191,     6,    -1,   117,
       4,   190,   277,   191,     6,    -1,   118,     4,   190,   277,
     194,   277,   191,     6,    -1,    -1,   205,   208,    -1,   205,
     212,    -1,   205,   215,    -1,   205,   217,    -1,   205,   218,
      -1,   277,    -1,   206,   194,   277,    -1,   277,    -1,   207,
     194,   277,    -1,    -1,    -1,     4,   209,   188,   206,   189,
     210,   195,   207,   196,     6,    -1,   290,    -1,   211,   194,
     290,    -1,    -1,   125,   188,   277,   194,   277,   194,   277,
     189,   213,   195,   211,   196,     6,    -1,   290,    -1,   214,
     194,   290,    -1,    -1,   126,   188,   277,   194,   277,   194,
     277,   194,   277,   189,   216,   195,   214,   196,     6,    -1,
     127,   195,   282,   196,   195,   282,   196,     6,    -1,   127,
     195,   282,   196,   195,   282,   196,   195,   282,   196,   195,
     282,   196,     6,    -1,    -1,   128,   219,   195,   207,   196,
       6,    -1,     7,    -1,   168,    -1,   167,    -1,   166,    -1,
     165,    -1,   186,    -1,   185,    -1,   188,    -1,   190,    -1,
     189,    -1,   191,    -1,    66,   190,   226,   191,     6,    -1,
      67,   190,   229,   191,     6,    -1,    70,   222,   291,   194,
     277,   223,     6,    -1,    71,   222,   295,   194,   291,   223,
       6,    -1,   295,   220,   283,     6,    -1,     4,   222,   223,
     220,   283,     6,    -1,   294,   222,   223,   220,   283,     6,
      -1,     4,   190,   277,   191,   220,   277,     6,    -1,     4,
     188,   277,   189,   220,   277,     6,    -1,   294,   190,   277,
     191,   220,   277,     6,    -1,   294,   188,   277,   189,   220,
     277,     6,    -1,     4,   222,   195,   286,   196,   223,   220,
     283,     6,    -1,   294,   222,   195,   286,   196,   223,   220,
     283,     6,    -1,   295,   221,     6,    -1,     4,   190,   277,
     191,   221,     6,    -1,     4,   188,   277,   189,   221,     6,
      -1,   294,   190,   277,   191,   221,     6,    -1,   294,   188,
     277,   189,   221,     6,    -1,   295,     7,   291,     6,    -1,
       4,   192,     4,     7,   291,     6,    -1,     4,   190,   277,
     191,   192,     4,     7,   291,     6,    -1,     4,   192,     4,
     220,   277,     6,    -1,     4,   190,   277,   191,   192,     4,
     220,   277,     6,    -1,     4,   192,     4,   221,     6,    -1,
       4,   190,   277,   191,   192,     4,   221,     6,    -1,     4,
     192,   135,   192,     4,     7,   287,     6,    -1,     4,   190,
     277,   191,   192,   135,   192,     4,     7,   287,     6,    -1,
       4,   192,   136,     7,   288,     6,    -1,     4,   190,   277,
     191,   192,   136,     7,   288,     6,    -1,     4,   144,     7,
     277,     6,    -1,   144,   190,   277,   191,     7,     4,     6,
      -1,   144,   190,   277,   191,   192,     4,     7,   277,     6,
      -1,   144,   190,   277,   191,   192,     4,     7,   291,     6,
      -1,   144,   190,   277,   191,   192,     4,     7,   195,   286,
     196,     6,    -1,   144,   190,   277,   191,   192,     4,     6,
      -1,    96,   188,     4,   189,   192,     4,     7,   277,     6,
      -1,    96,   188,     4,   189,   192,     4,     7,   291,     6,
      -1,    -1,   194,    -1,    -1,   226,   225,   295,    -1,   226,
     225,   295,     7,   277,    -1,    -1,   226,   225,   295,     7,
     195,   283,   227,   231,   196,    -1,   226,   225,   295,     7,
     291,    -1,    -1,   226,   225,   295,     7,   195,   291,   228,
     233,   196,    -1,    -1,   229,   225,   290,    -1,   277,     7,
     291,    -1,   230,   194,   277,     7,   291,    -1,    -1,   231,
     232,    -1,   194,     4,   283,    -1,   194,     4,   195,   230,
     196,    -1,   194,     4,   291,    -1,    -1,   233,   234,    -1,
     194,     4,   277,    -1,   194,     4,   291,    -1,   194,   147,
     291,    -1,   194,     4,   195,   293,   196,    -1,   277,    -1,
     291,    -1,   291,   194,   277,    -1,   277,    -1,   291,    -1,
     291,   194,   277,    -1,   277,    -1,   291,    -1,   291,   194,
     277,    -1,   277,    -1,   291,    -1,   291,   194,   277,    -1,
      -1,   138,    76,   195,   277,   196,    -1,    -1,    88,   280,
      -1,    72,   188,   277,   189,     7,   280,     6,    -1,    92,
      72,   188,   235,   189,   220,   283,     6,    -1,    81,    82,
     283,     7,   277,     6,    -1,    75,   188,   277,   189,     7,
     283,     6,    -1,    97,    75,   283,     6,    -1,    79,   188,
     277,   189,     7,   283,     6,    -1,    73,   188,   277,   189,
       7,   283,   240,     6,    -1,    74,   188,   277,   189,     7,
     283,   240,     6,    -1,   130,   188,   277,   189,     7,   283,
       6,    -1,   131,   188,   277,   189,     7,   283,     6,    -1,
     132,   188,   277,   189,     7,   283,   134,   283,   133,   277,
       6,    -1,    75,     4,   188,   277,   189,     7,   283,     6,
      -1,    93,    75,   188,   277,   189,     7,   283,     6,    -1,
      92,    75,   188,   236,   189,   220,   283,     6,    -1,    88,
      78,   188,   277,   189,     7,   283,     6,    -1,    89,    78,
     188,   277,   189,     7,   283,   239,     6,    -1,    12,    13,
       6,    -1,    13,    78,   277,     6,    -1,    83,    78,   188,
     277,   189,     7,     5,     5,     5,     6,    -1,    76,   188,
     277,   189,     7,   283,     6,    -1,    77,   188,   277,   189,
       7,   283,     6,    -1,    78,     4,   188,   277,   189,     7,
     283,     6,    -1,    93,    78,   188,   277,   189,     7,   283,
       6,    -1,    93,    78,   188,   277,   189,     7,   283,     4,
     195,   282,   196,     6,    -1,    92,    78,   188,   237,   189,
     220,   283,     6,    -1,    91,    80,   188,   277,   189,     7,
     283,     6,    -1,    80,   188,   277,   189,     7,   283,     6,
      -1,    93,    80,   188,   277,   189,     7,   283,     6,    -1,
      92,    80,   188,   238,   189,   220,   283,     6,    -1,   100,
     280,   195,   243,   196,    -1,    99,   195,   280,   194,   280,
     194,   277,   196,   195,   243,   196,    -1,   101,   280,   195,
     243,   196,    -1,   102,   195,   280,   194,   277,   196,   195,
     243,   196,    -1,   102,   195,   280,   194,   280,   196,   195,
     243,   196,    -1,     4,   195,   243,   196,    -1,   110,    75,
     195,   286,   196,    78,   195,   277,   196,    -1,   107,    75,
     188,   277,   189,   195,   286,   196,     6,    -1,   244,    -1,
     242,    -1,    -1,   244,   241,    -1,   244,    72,   195,   286,
     196,     6,    -1,   244,    75,   195,   286,   196,     6,    -1,
     244,    78,   195,   286,   196,     6,    -1,   244,    80,   195,
     286,   196,     6,    -1,   104,    88,   188,   277,   189,     7,
     283,     6,    -1,   104,    72,   188,   277,   189,     7,   195,
     282,   196,     6,    -1,   104,    88,   188,   277,   189,     7,
     195,   280,   194,   280,   194,   286,   196,     6,    -1,   104,
      88,   188,   277,   189,     7,   195,   280,   194,   280,   194,
     280,   194,   286,   196,     6,    -1,   104,    76,   188,   277,
     189,     7,   195,   280,   194,   286,   196,     6,    -1,   104,
       4,   188,   277,   189,     7,   283,     6,    -1,   104,     4,
     188,   277,   189,     7,     5,     6,    -1,   104,     4,   195,
     277,   196,     6,    -1,   104,     4,   188,   277,   189,     7,
     195,   280,   194,   280,   194,   286,   196,     6,    -1,   108,
     195,   244,   196,    -1,   108,   144,   190,   277,   191,     6,
      -1,   108,     4,   190,   277,   191,     6,    -1,   108,     4,
       6,    -1,   108,     4,     4,     6,    -1,   135,   287,   195,
     244,   196,    -1,    98,   135,   287,   195,   244,   196,    -1,
     164,   277,   195,   244,   196,    -1,   148,     5,     6,    -1,
     149,     5,     6,    -1,   148,   195,   244,   196,    -1,    98,
     148,   195,   244,   196,    -1,   149,   195,   244,   196,    -1,
      98,   149,   195,   244,   196,    -1,     4,   291,     6,    -1,
      59,   188,   293,   189,     6,    -1,     4,     4,   190,   277,
     191,   290,     6,    -1,     4,     4,     4,   190,   277,   191,
       6,    -1,     4,   277,     6,    -1,    96,   188,     4,   189,
     192,     4,     6,    -1,   129,     4,     6,    -1,   142,     6,
      -1,   143,     6,    -1,    56,     6,    -1,    57,     6,    -1,
      50,     6,    -1,    50,   195,   277,   194,   277,   194,   277,
     194,   277,   194,   277,   194,   277,   196,     6,    -1,    51,
       6,    -1,    52,     6,    -1,    63,     6,    -1,    64,     6,
      -1,    85,     6,    -1,    86,   195,   286,   196,   195,   286,
     196,   195,   282,   196,   195,   277,   194,   277,   196,     6,
      -1,   157,   277,     6,    -1,   137,   188,   277,     8,   277,
     189,    -1,   137,   188,   277,     8,   277,     8,   277,   189,
      -1,   137,     4,   138,   195,   277,     8,   277,   196,    -1,
     137,     4,   138,   195,   277,     8,   277,     8,   277,   196,
      -1,   139,    -1,   147,     4,    -1,   145,    -1,   146,   295,
       6,    -1,   140,   188,   277,   189,    -1,   141,    -1,   103,
     280,   195,   244,   196,    -1,   103,   195,   280,   194,   280,
     194,   277,   196,   195,   244,   196,    -1,   103,   195,   280,
     194,   280,   194,   280,   194,   277,   196,   195,   244,   196,
      -1,    -1,   103,   280,   195,   244,   253,   266,   196,    -1,
      -1,   103,   195,   280,   194,   280,   194,   277,   196,   195,
     244,   254,   266,   196,    -1,    -1,   103,   195,   280,   194,
     280,   194,   280,   194,   277,   196,   195,   244,   255,   266,
     196,    -1,    -1,   103,   195,   244,   256,   266,   196,    -1,
     103,    72,   195,   277,   194,   280,   196,     6,    -1,   103,
      75,   195,   277,   194,   280,   196,     6,    -1,   103,    78,
     195,   277,   194,   280,   196,     6,    -1,   103,    72,   195,
     277,   194,   280,   194,   280,   194,   277,   196,     6,    -1,
     103,    75,   195,   277,   194,   280,   194,   280,   194,   277,
     196,     6,    -1,   103,    78,   195,   277,   194,   280,   194,
     280,   194,   277,   196,     6,    -1,   103,    72,   195,   277,
     194,   280,   194,   280,   194,   280,   194,   277,   196,     6,
      -1,   103,    75,   195,   277,   194,   280,   194,   280,   194,
     280,   194,   277,   196,     6,    -1,   103,    78,   195,   277,
     194,   280,   194,   280,   194,   280,   194,   277,   196,     6,
      -1,    -1,   103,    72,   195,   277,   194,   280,   196,   257,
     195,   266,   196,     6,    -1,    -1,   103,    75,   195,   277,
     194,   280,   196,   258,   195,   266,   196,     6,    -1,    -1,
     103,    78,   195,   277,   194,   280,   196,   259,   195,   266,
     196,     6,    -1,    -1,   103,    72,   195,   277,   194,   280,
     194,   280,   194,   277,   196,   260,   195,   266,   196,     6,
      -1,    -1,   103,    75,   195,   277,   194,   280,   194,   280,
     194,   277,   196,   261,   195,   266,   196,     6,    -1,    -1,
     103,    78,   195,   277,   194,   280,   194,   280,   194,   277,
     196,   262,   195,   266,   196,     6,    -1,    -1,   103,    72,
     195,   277,   194,   280,   194,   280,   194,   280,   194,   277,
     196,   263,   195,   266,   196,     6,    -1,    -1,   103,    75,
     195,   277,   194,   280,   194,   280,   194,   280,   194,   277,
     196,   264,   195,   266,   196,     6,    -1,    -1,   103,    78,
     195,   277,   194,   280,   194,   280,   194,   280,   194,   277,
     196,   265,   195,   266,   196,     6,    -1,   267,    -1,   266,
     267,    -1,   113,   195,   277,   196,     6,    -1,   113,   195,
     283,   194,   283,   196,     6,    -1,   113,   195,   283,   194,
     283,   194,   283,   196,     6,    -1,   114,     6,    -1,   105,
       6,    -1,   121,     6,    -1,   121,   123,     6,    -1,   122,
       6,    -1,   122,   123,     6,    -1,   119,     6,    -1,   119,
     123,     6,    -1,   120,     6,    -1,   120,   123,     6,    -1,
     115,   188,   277,   189,     7,   283,    95,   277,     6,    -1,
      95,     4,   190,   277,   191,     6,    -1,    -1,    95,     4,
     277,    -1,    -1,     4,    -1,    -1,     7,   283,    -1,    -1,
       7,   277,    -1,    -1,    95,   283,    -1,    90,    75,   284,
       7,   277,   268,     6,    -1,    90,    78,   284,   270,   269,
       6,    -1,    84,    78,   195,   277,   196,     7,   283,     6,
      -1,    90,    80,   284,   270,     6,    -1,   124,   284,     6,
      -1,   111,    78,   195,   286,   196,   277,     6,    -1,   105,
      78,   284,   271,     6,    -1,   105,    80,   284,     6,    -1,
     106,    78,   283,     7,   277,     6,    -1,    94,    75,   283,
       7,   283,     6,    -1,    94,    78,   277,   195,   286,   196,
       7,   277,   195,   286,   196,   272,     6,    -1,    72,   195,
     286,   196,   138,    78,   195,   277,   196,     6,    -1,    75,
     195,   286,   196,   138,    78,   195,   277,   196,     6,    -1,
      72,   195,   286,   196,   138,    80,   195,   277,   196,     6,
      -1,    75,   195,   286,   196,   138,    80,   195,   277,   196,
       6,    -1,    78,   195,   286,   196,   138,    80,   195,   277,
     196,     6,    -1,   112,    78,   284,     6,    -1,   112,    75,
     284,     6,    -1,    87,    72,   284,     6,    -1,    87,    75,
     284,     6,    -1,    87,    78,   284,     6,    -1,   109,     6,
      -1,   109,     4,     6,    -1,   109,    72,   195,   286,   196,
       6,    -1,   154,    -1,   155,    -1,   156,    -1,   275,     6,
      -1,   275,   195,   283,   196,     6,    -1,   275,   195,   283,
     194,   283,   196,     6,    -1,   275,   188,   283,   189,   195,
     283,   194,   283,   196,     6,    -1,   278,    -1,   188,   277,
     189,    -1,   179,   277,    -1,   178,   277,    -1,   183,   277,
      -1,   277,   179,   277,    -1,   277,   178,   277,    -1,   277,
     180,   277,    -1,   277,   181,   277,    -1,   277,   182,   277,
      -1,   277,   187,   277,    -1,   277,   174,   277,    -1,   277,
     175,   277,    -1,   277,   177,   277,    -1,   277,   176,   277,
      -1,   277,   173,   277,    -1,   277,   172,   277,    -1,   277,
     171,   277,    -1,   277,   170,   277,    -1,   277,   169,   277,
       8,   277,    -1,    14,   222,   277,   223,    -1,    15,   222,
     277,   223,    -1,    16,   222,   277,   223,    -1,    17,   222,
     277,   223,    -1,    18,   222,   277,   223,    -1,    19,   222,
     277,   223,    -1,    20,   222,   277,   223,    -1,    21,   222,
     277,   223,    -1,    22,   222,   277,   223,    -1,    24,   222,
     277,   223,    -1,    25,   222,   277,   194,   277,   223,    -1,
      26,   222,   277,   223,    -1,    27,   222,   277,   223,    -1,
      28,   222,   277,   223,    -1,    29,   222,   277,   223,    -1,
      30,   222,   277,   223,    -1,    31,   222,   277,   223,    -1,
      32,   222,   277,   223,    -1,    33,   222,   277,   194,   277,
     223,    -1,    34,   222,   277,   194,   277,   223,    -1,    35,
     222,   277,   194,   277,   223,    -1,    23,   222,   277,   223,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   160,
      -1,   161,    -1,   162,    -1,    60,    -1,    61,    -1,    62,
      -1,    -1,    68,   222,   277,   279,   231,   223,    -1,   153,
     222,   290,   223,    -1,   295,    -1,     4,   190,   277,   191,
      -1,     4,   188,   277,   189,    -1,   294,   190,   277,   191,
      -1,   294,   188,   277,   189,    -1,   158,   188,   295,   189,
      -1,   159,   188,   291,   189,    -1,   193,   295,   222,   223,
      -1,   295,   221,    -1,     4,   190,   277,   191,   221,    -1,
       4,   188,   277,   189,   221,    -1,   294,   190,   277,   191,
     221,    -1,   294,   188,   277,   189,   221,    -1,     4,   192,
       4,    -1,     4,   190,   277,   191,   192,     4,    -1,     4,
     192,     4,   221,    -1,     4,   190,   277,   191,   192,     4,
     221,    -1,   150,   188,   290,   194,   277,   189,    -1,    45,
     188,   283,   194,   283,   189,    -1,    46,   188,   290,   194,
     290,   189,    -1,    47,   188,   290,   194,   290,   189,    -1,
      49,   188,   293,   189,    -1,   281,    -1,   179,   280,    -1,
     178,   280,    -1,   280,   179,   280,    -1,   280,   178,   280,
      -1,   195,   277,   194,   277,   194,   277,   194,   277,   194,
     277,   196,    -1,   195,   277,   194,   277,   194,   277,   194,
     277,   196,    -1,   195,   277,   194,   277,   194,   277,   196,
      -1,   188,   277,   194,   277,   194,   277,   189,    -1,   283,
      -1,   282,   194,   283,    -1,   277,    -1,   285,    -1,   195,
     196,    -1,   195,   286,   196,    -1,   179,   195,   286,   196,
      -1,   277,   180,   195,   286,   196,    -1,   283,    -1,     5,
      -1,   179,   285,    -1,   277,   180,   285,    -1,   277,     8,
     277,    -1,   277,     8,   277,     8,   277,    -1,    72,   195,
     277,   196,    -1,    72,     5,    -1,    75,     5,    -1,    78,
       5,    -1,    80,     5,    -1,    92,    72,     5,    -1,    92,
      75,     5,    -1,    92,    78,     5,    -1,    92,    80,     5,
      -1,    92,    72,   195,   286,   196,    -1,    92,    75,   195,
     286,   196,    -1,    92,    78,   195,   286,   196,    -1,    92,
      80,   195,   286,   196,    -1,    72,   138,    50,   195,   277,
     194,   277,   194,   277,   194,   277,   194,   277,   194,   277,
     196,    -1,    75,   138,    50,   195,   277,   194,   277,   194,
     277,   194,   277,   194,   277,   194,   277,   196,    -1,    78,
     138,    50,   195,   277,   194,   277,   194,   277,   194,   277,
     194,   277,   194,   277,   196,    -1,    80,   138,    50,   195,
     277,   194,   277,   194,   277,   194,   277,   194,   277,   194,
     277,   196,    -1,   242,    -1,   252,    -1,     4,   222,   223,
      -1,   294,   222,   223,    -1,    36,   190,   295,   191,    -1,
       4,   222,   195,   286,   196,   223,    -1,   294,   222,   195,
     286,   196,   223,    -1,   277,    -1,   285,    -1,   286,   194,
     277,    -1,   286,   194,   285,    -1,   195,   277,   194,   277,
     194,   277,   194,   277,   196,    -1,   195,   277,   194,   277,
     194,   277,   196,    -1,     4,    -1,     4,   192,   135,   192,
       4,    -1,   195,   289,   196,    -1,     4,   190,   277,   191,
     192,   136,    -1,   287,    -1,   289,   194,   287,    -1,   291,
      -1,   295,    -1,     4,   192,     4,    -1,     4,   190,   277,
     191,   192,     4,    -1,     5,    -1,    53,    -1,   163,    -1,
      58,    -1,   151,   188,   290,   189,    -1,   152,   188,   290,
     194,   290,   189,    -1,   152,   188,   290,   189,    -1,    41,
     222,   293,   223,    -1,    42,   188,   290,   189,    -1,    43,
     188,   290,   189,    -1,    44,   188,   290,   194,   290,   194,
     290,   189,    -1,    39,   222,   293,   223,    -1,    48,   222,
     277,   194,   291,   194,   291,   223,    -1,    40,   222,   290,
     223,    -1,    40,   222,   290,   194,   286,   223,    -1,    54,
     222,   290,   223,    -1,    55,    -1,    -1,    69,   222,   291,
     292,   233,   223,    -1,   290,    -1,   293,   194,   290,    -1,
       4,   197,   195,   277,   196,    -1,   294,   197,   195,   277,
     196,    -1,     4,    -1,   294,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   191,   193,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   216,   220,   227,   232,   237,   251,   264,   277,
     305,   319,   332,   345,   364,   369,   370,   371,   372,   373,
     377,   379,   384,   386,   392,   496,   391,   514,   521,   532,
     531,   549,   556,   567,   566,   583,   600,   623,   622,   636,
     637,   638,   639,   640,   644,   645,   651,   651,   652,   652,
     658,   659,   660,   665,   671,   731,   760,   789,   794,   799,
     804,   809,   816,   823,   838,   843,   848,   853,   858,   867,
     873,   882,   900,   918,   927,   939,   944,   952,   972,   995,
    1006,  1014,  1036,  1059,  1085,  1106,  1118,  1132,  1132,  1134,
    1136,  1145,  1155,  1154,  1172,  1182,  1181,  1195,  1197,  1205,
    1211,  1218,  1219,  1223,  1234,  1249,  1259,  1260,  1265,  1273,
    1282,  1290,  1308,  1312,  1318,  1326,  1330,  1336,  1344,  1348,
    1354,  1362,  1366,  1372,  1381,  1384,  1397,  1400,  1410,  1433,
    1465,  1488,  1506,  1527,  1545,  1575,  1605,  1623,  1641,  1668,
    1686,  1704,  1739,  1757,  1796,  1802,  1808,  1815,  1840,  1865,
    1882,  1901,  1935,  1971,  1989,  2006,  2022,  2059,  2064,  2069,
    2074,  2079,  2084,  2107,  2113,  2124,  2125,  2130,  2133,  2137,
    2160,  2183,  2206,  2234,  2255,  2281,  2302,  2324,  2344,  2456,
    2475,  2513,  2622,  2631,  2637,  2652,  2680,  2697,  2706,  2720,
    2734,  2740,  2746,  2755,  2764,  2773,  2787,  2843,  2861,  2878,
    2893,  2912,  2924,  2948,  2952,  2957,  2964,  2969,  2975,  2980,
    2986,  2994,  2998,  3002,  3007,  3062,  3075,  3092,  3109,  3131,
    3153,  3188,  3196,  3202,  3209,  3213,  3222,  3230,  3238,  3247,
    3246,  3261,  3260,  3275,  3274,  3289,  3288,  3302,  3309,  3316,
    3323,  3330,  3337,  3344,  3351,  3358,  3366,  3365,  3379,  3378,
    3392,  3391,  3405,  3404,  3418,  3417,  3431,  3430,  3444,  3443,
    3457,  3456,  3470,  3469,  3486,  3489,  3495,  3507,  3527,  3551,
    3555,  3559,  3563,  3567,  3573,  3579,  3583,  3587,  3591,  3595,
    3614,  3627,  3630,  3646,  3649,  3666,  3669,  3675,  3678,  3685,
    3688,  3695,  3751,  3821,  3826,  3893,  3929,  3937,  3980,  4019,
    4039,  4066,  4115,  4143,  4171,  4175,  4179,  4207,  4246,  4285,
    4306,  4327,  4354,  4358,  4368,  4403,  4404,  4405,  4409,  4415,
    4427,  4445,  4473,  4474,  4475,  4476,  4477,  4478,  4479,  4480,
    4481,  4488,  4489,  4490,  4491,  4492,  4493,  4494,  4495,  4496,
    4497,  4498,  4499,  4500,  4501,  4502,  4503,  4504,  4505,  4506,
    4507,  4508,  4509,  4510,  4511,  4512,  4513,  4514,  4515,  4516,
    4517,  4518,  4519,  4520,  4529,  4530,  4531,  4532,  4533,  4534,
    4535,  4536,  4537,  4538,  4543,  4542,  4550,  4555,  4572,  4590,
    4608,  4626,  4644,  4649,  4655,  4667,  4684,  4702,  4720,  4738,
    4759,  4764,  4769,  4779,  4789,  4794,  4805,  4814,  4819,  4846,
    4850,  4854,  4858,  4862,  4869,  4873,  4877,  4881,  4888,  4893,
    4900,  4905,  4909,  4914,  4918,  4926,  4937,  4941,  4953,  4961,
    4969,  4976,  4986,  5015,  5019,  5023,  5027,  5031,  5035,  5039,
    5043,  5047,  5076,  5105,  5134,  5163,  5176,  5189,  5202,  5215,
    5225,  5235,  5247,  5260,  5272,  5290,  5311,  5316,  5320,  5324,
    5336,  5340,  5352,  5359,  5369,  5373,  5388,  5393,  5400,  5404,
    5417,  5425,  5436,  5440,  5448,  5454,  5460,  5468,  5476,  5483,
    5498,  5512,  5526,  5538,  5554,  5565,  5569,  5588,  5595,  5602,
    5601,  5614,  5619,  5625,  5634,  5647,  5650
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
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,    63,
     424,   425,   426,   427,    60,    62,   428,   429,    43,    45,
      42,    47,    37,    33,   430,   431,   432,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   198,   199,   199,   200,   200,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   203,   203,   203,   203,
     204,   204,   204,   204,   205,   205,   205,   205,   205,   205,
     206,   206,   207,   207,   209,   210,   208,   211,   211,   213,
     212,   214,   214,   216,   215,   217,   217,   219,   218,   220,
     220,   220,   220,   220,   221,   221,   222,   222,   223,   223,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   225,   225,   226,
     226,   226,   227,   226,   226,   228,   226,   229,   229,   230,
     230,   231,   231,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   235,   235,   235,   236,   236,   236,   237,   237,
     237,   238,   238,   238,   239,   239,   240,   240,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   242,   242,   242,
     242,   242,   242,   242,   242,   243,   243,   244,   244,   244,
     244,   244,   244,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   246,   246,   246,   246,   246,   247,   247,   248,
     249,   249,   249,   249,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   252,   252,   253,
     252,   254,   252,   255,   252,   256,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   257,   252,   258,   252,
     259,   252,   260,   252,   261,   252,   262,   252,   263,   252,
     264,   252,   265,   252,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   268,   269,   269,   270,   270,   271,   271,   272,
     272,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   274,   274,   274,   275,   275,   275,   276,   276,
     276,   276,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   280,
     280,   280,   280,   280,   281,   281,   281,   281,   282,   282,
     283,   283,   283,   283,   283,   283,   284,   284,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   286,   286,   286,   286,
     287,   287,   287,   287,   288,   288,   289,   289,   290,   290,
     290,   290,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   292,
     291,   293,   293,   294,   294,   295,   295
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
       6,    13,    10,    10,    10,    10,    10,     4,     4,     4,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     5,     5,     5,     5,
       3,     6,     4,     7,     6,     6,     6,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     3,     3,     3,
       3,     5,     5,     5,     5,    16,    16,    16,    16,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     1,     1,     1,     4,     6,     4,     4,
       4,     4,     8,     4,     8,     4,     6,     4,     1,     0,
       6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   245,     0,     0,     0,   242,     0,
       0,     0,     0,   335,   336,   337,     0,     0,     5,     7,
       6,     8,     9,    10,    20,    11,    12,    13,    14,    19,
      18,    15,    16,    17,     0,    21,   506,     0,   384,   505,
     482,   385,   386,   387,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,     0,   498,
     485,   391,   392,   393,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   388,   389,   390,   484,     0,     0,     0,
      66,    67,     0,     0,   187,     0,     0,     0,   342,     0,
     478,   506,   397,     0,     0,     0,     0,   227,     0,   229,
     230,   225,   226,     0,   231,   232,   109,   117,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   419,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   332,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     460,   430,   436,     0,   431,   506,   397,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,   223,   224,     0,
     505,   506,     0,   241,     0,   187,     0,   187,   505,     0,
       0,   338,     0,     0,    66,    67,     0,     0,    59,    63,
      62,    61,    60,    65,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   344,   346,     0,     0,     0,
       0,     0,     0,     0,   186,     0,   185,     0,    68,    69,
       0,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,   216,
       0,     0,   405,   164,     0,   505,     0,   478,   479,     0,
       0,   501,     0,   107,   107,     0,     0,     0,     0,   466,
     467,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   305,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   187,
       0,   421,   420,     0,     0,     0,     0,   187,   187,     0,
       0,     0,     0,     0,     0,     0,   255,     0,   187,     0,
       0,     0,     0,     0,   307,     0,     0,     0,     0,   205,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,     0,   443,     0,     0,
     444,     0,   445,     0,   446,     0,     0,     0,     0,     0,
       0,   344,   438,     0,   432,     0,     0,     0,   315,    66,
      67,     0,   222,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,   243,   210,     0,   211,     0,     0,   235,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,   410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
     499,     0,     0,     0,     0,     0,     0,     0,   343,     0,
      59,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,   188,     0,     0,    59,     0,     0,   360,   359,   358,
     357,   353,   354,   356,   355,   348,   347,   349,   350,   351,
     352,     0,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     329,   330,   331,     0,     0,     0,     0,   303,     0,     0,
       0,   132,   133,     0,   135,   136,     0,   138,   139,     0,
     141,   142,     0,     0,     0,     0,     0,     0,   152,   187,
       0,     0,     0,     0,     0,   423,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,   318,     0,     0,   206,     0,     0,
     202,     0,     0,     0,   328,   327,     0,     0,     0,     0,
     410,     0,   461,     0,     0,     0,     0,     0,     0,   447,
       0,   448,     0,   449,     0,   450,     0,     0,   343,   433,
     440,     0,   349,   439,     0,   462,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,   212,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    74,     0,
     399,   398,   412,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   383,   371,     0,   373,   374,   375,   376,   377,
     378,   379,     0,     0,     0,   493,     0,   495,   489,   490,
     491,     0,     0,     0,     0,     0,   418,   497,   121,   126,
      99,     0,   486,   488,     0,   396,   402,   403,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
     404,     0,     0,     0,     0,   503,     0,     0,     0,    44,
       0,     0,     0,    57,     0,    35,    36,    37,    38,    39,
     401,   400,     0,   480,    24,    22,     0,     0,    25,     0,
       0,   217,   502,    70,   110,    71,   118,     0,     0,     0,
     468,   469,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,   306,   304,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,   215,     0,     0,     0,   177,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,   246,     0,     0,     0,     0,
       0,     0,   308,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,     0,   463,     0,   442,     0,
       0,     0,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
     209,     0,     0,   339,     0,     0,     0,     0,   504,     0,
       0,     0,   407,     0,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,    84,    89,    91,     0,
       0,   476,     0,    97,     0,     0,     0,     0,     0,    75,
     361,     0,     0,     0,     0,     0,    30,   409,   408,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,   312,     0,     0,   134,     0,   137,     0,   140,     0,
     143,     0,     0,     0,   320,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,     0,   289,
       0,   295,     0,   297,     0,   291,     0,   293,     0,   256,
     285,     0,     0,     0,   200,     0,     0,     0,   319,     0,
     204,   203,   334,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,   451,   452,   453,   454,   441,   435,
       0,     0,     0,     0,   473,     0,     0,     0,   236,     0,
       0,     0,     0,     0,    87,     0,    86,     0,    76,   219,
     411,   218,   372,   380,   381,   382,   496,     0,   415,   416,
     417,     0,     0,   395,   122,     0,   500,   127,   414,   487,
      78,    59,     0,     0,     0,     0,    77,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     428,     0,     0,    26,    27,     0,    28,     0,     0,   111,
     114,    72,    73,   148,     0,     0,     0,     0,     0,     0,
     151,     0,     0,   167,   168,     0,     0,   153,   174,     0,
       0,     0,     0,   144,     0,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
     187,   187,     0,   266,     0,   268,     0,   270,     0,   430,
       0,     0,   296,   298,   292,   294,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,     0,
     411,   464,     0,     0,     0,     0,   465,   156,   157,     0,
       0,     0,     0,   100,   104,     0,     0,   340,    80,    79,
       0,   413,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,   477,   189,   190,   191,   192,     0,
       0,    40,     0,     0,     0,     0,     0,    42,   481,     0,
       0,   112,   115,     0,     0,   147,   154,   155,   159,     0,
       0,   169,     0,     0,   313,     0,   162,     0,     0,   302,
     173,   149,   161,   172,   176,   160,     0,   170,   175,     0,
       0,     0,     0,   427,     0,   426,     0,     0,     0,   257,
       0,     0,   258,     0,     0,   259,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,   198,     0,     0,     0,
     193,     0,     0,    33,     0,     0,     0,     0,     0,     0,
     471,     0,   238,   237,     0,     0,     0,     0,     0,   492,
     494,     0,   123,   125,     0,   128,   129,   130,    90,    92,
       0,    98,     0,    81,    45,     0,     0,     0,   429,     0,
       0,     0,    29,     0,   121,   126,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,   105,   106,   187,
       0,   180,   181,     0,     0,     0,     0,     0,     0,     0,
     286,     0,     0,   187,     0,     0,     0,     0,     0,   184,
     183,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,    82,     0,   466,     0,     0,   475,     0,    41,
       0,     0,     0,    43,    58,     0,     0,     0,   322,   324,
     323,   325,   326,   166,     0,     0,     0,     0,     0,     0,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     300,     0,     0,     0,   251,     0,     0,   194,     0,     0,
       0,     0,     0,     0,     0,   470,   239,     0,   341,     0,
     124,     0,   131,    96,     0,     0,     0,     0,     0,   113,
     116,     0,     0,     0,   309,   178,     0,   272,     0,     0,
     274,     0,     0,   276,     0,     0,     0,   287,     0,   247,
       0,   187,     0,     0,     0,     0,     0,     0,     0,   158,
     103,     0,   119,     0,    49,     0,    55,     0,     0,     0,
     145,   171,     0,     0,   424,   260,     0,     0,   267,   261,
       0,     0,   269,   262,     0,     0,   271,     0,     0,     0,
     253,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,   321,     0,   278,
       0,   280,     0,   282,   288,   299,   252,   248,     0,     0,
       0,     0,     0,     0,     0,     0,   120,    46,     0,    53,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,     0,   201,     0,   195,     0,     0,     0,     0,
       0,    47,     0,     0,   228,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   273,     0,   275,     0,   277,     0,   196,
       0,     0,     0,     0,    48,    50,     0,    51,     0,     0,
       0,     0,   455,   456,   457,   458,     0,     0,    56,   279,
     281,   283,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,   906,    89,    90,   661,  1370,  1376,
     895,  1081,  1538,  1720,   896,  1671,  1756,   897,  1722,   898,
     899,  1085,   335,   422,   176,   401,    91,   676,   433,  1484,
    1485,   434,  1533,  1056,  1224,  1057,  1227,   710,   713,   716,
     719,  1398,  1267,   641,   289,   395,   396,    94,    95,    96,
      97,    98,    99,   100,   290,   986,  1620,  1688,   744,  1420,
    1423,  1426,  1646,  1650,  1654,  1705,  1708,  1711,   982,   983,
    1120,   943,   707,   753,  1643,   102,   103,   104,   105,   291,
     178,   858,   482,   249,  1249,   292,   293,   294,   545,   303,
     879,  1072,   431,   427,   859,   432,   181,   296
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1299
static const yytype_int16 yypact[] =
{
    6631,     8,    64,  6746, -1299, -1299,  3341,    67,   -56,  -139,
     -96,    46,   116,   130,   154,   185,    60,   246,   257,    86,
     122,   -76,   -76,  -162,   167,   181,     1,   194,   206,    16,
     317,   322,   291,   451,   463,   546,   361,    73,   484,   497,
     540,   516,   446,   547,   186,   419,   555,   182,   438,   249,
     249,   459,   450,    28,   439,   570,   576,     9,    75,   588,
     605,   233,   667,   684,   689,  4765,   700,   508,   513,   520,
      26,     7, -1299,   528, -1299,   660,   714,   535, -1299,   726,
     734,    36,    37, -1299, -1299, -1299,  6496,  6496, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,    49, -1299,  -115,    89, -1299,    11,
   -1299, -1299, -1299, -1299,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   551,
     559,   571,   574,   578,   586,   -76,   587, -1299,   -76, -1299,
   -1299, -1299, -1299, -1299,   -76,   -76,   736,   597,   602,   628,
     -76,   631,   632, -1299, -1299, -1299, -1299,  6496,  6496,  6496,
    6496,  6496,    27,   726,    42,   598,   235,   123, -1299,   599,
     828,   -10,  -125,   832,  6496,  1094,  1094, -1299,  6496, -1299,
   -1299, -1299, -1299,  1094, -1299, -1299, -1299, -1299, -1299, -1299,
    1601,   726,  6496,  6315,  6496,  6496,   656,  6496,  6315,  6496,
    6496,   675,  6315,  6496,  6496,  5139,   679,   665, -1299,  6315,
    4765,  4765,  4765,   682,   695,  4765,  4765,  4765,   713,   719,
     731,   744,   747,   751,   769,   808,  5139,  6496,   793,  5139,
      26,   681,   827,   249,   249,   249,  6496,  6496,   -84, -1299,
     -80,   249,   829,   830,   831,  6074,   -55,   -82,   812,   835,
     839,  4765,  4765,  5139,   841,    63,   842, -1299,   884, -1299,
     836,   838,   840,  4765,  4765,   844,   846,   852,   241, -1299,
     854,    20,    12,    18,    31,   488,  5326,  6496,  3762, -1299,
   -1299,  2303, -1299,  1039, -1299,   138,   151,  1040,  6496,  6496,
    6496,   857,  6496,   855,   938,  6496,  6496, -1299, -1299,  6496,
     880,   881,  1073, -1299,  1074, -1299,  1077, -1299,   272,   171,
    4292, -1299,  5139,  5139,  6496,  6496,   889,   270,  1601, -1299,
   -1299, -1299, -1299, -1299, -1299,  5139,  1080,   897,  6496,  6496,
    1084,  6496,  6496,  6496,  6496,  6496,  6496,  6496,  6496,  6496,
    6496,  6496,  6496,  6496,  6496,  6496,  6496,  6496,  6496,  6496,
    6496,  6496,  6496,  1094,  1094,  1094,  1094,  1094,  1094,  5139,
    1094,  1094,  6496,  1094,  1094,  6496,  1601,  6496,  1094,  1094,
    1094,  1094,   726,  1601,   902,   902,   902,  4358,  8231,   121,
     898,  1086,   -76,   899, -1299,   905,  4182,  6496, -1299, -1299,
    6315,   114, -1299,  6496,  6496,  6496,  6496,  6496,  6496,  6496,
    6496,  6496,  6496,  6496,  6496,  6496,  6496,  6496, -1299, -1299,
    6496,  6496, -1299, -1299,   834,   132,   -30, -1299, -1299,   -15,
    4386, -1299,    78,   279,   336,   901,   908,  6101,  6315,  3543,
   -1299,   355,  8576,  8597,  6496,  8618,   417,  8639,  8660,  6496,
     532,  8681,  8702,  1097,  6496,  6496,   550,  1101,  1102,  1103,
    6496,  6496,  1104,  1106,  1106,  6496,  6134,  6134,  6134,  6134,
    6496,  6496,  6496,  1109,  4759,   921,  1111,   923, -1299, -1299,
    -140, -1299, -1299,  4573,  5134,   249,   249,    42,    42,   310,
    6496,  6496,  6496,  6074,  6074,  6496,  4182,   312, -1299,  6496,
    6496,  6496,  6496,  6496,  1114,  1117,  1118,  6496,  1121, -1299,
    6496,  6496,  1119, -1299,  6315,  6315,  6315,  1133,  1134,  6496,
    6496,  6496,  6496,  6496,  1137,   473,   726, -1299,  1093,  6496,
   -1299,  1100, -1299,  1105, -1299,  1107,    40,    43,    45,    48,
    6315,   902, -1299,  8723, -1299,   556,  6496,  5513, -1299,  6496,
    6496,   500, -1299,  8744,  8765,  8786,  1009,  5321, -1299,   956,
    3580,  8807,  8254, -1299, -1299,  1310, -1299,  1336,  6496, -1299,
   -1299,   964,   557,  8828,  8277,  6496,  6315,   114,  1148,  1150,
   -1299,  6496,  8849,  8300,   -68,  8208,  8208,  8208,  8208,  8208,
    8208,  8208,  8208,  8208,  8208,  8208,  5508,  8208,  8208,  8208,
    8208,  8208,  8208,  8208,  5695,  5882,  6129,   277,   511,   277,
     969,   970,   967,   968,   971,   973,  6310,   165,   569,  9311,
   -1299,  1415,   974,   980,   224,   569,   991,   993,   148,     0,
    1601,  6496,  1179,  1182,    30,   569, -1299,   -34,    25,    33,
     215, -1299,  4536,   606, -1299,  5139,  3718,  1451,  1549,   997,
     997,   554,   554,   554,   554,   505,   505,   902,   902,   902,
     902,     6,  8870,  8323, -1299,  6496,  1183,    13,  6315,  1184,
    6315,  6496,  1195,  1094,  1198, -1299,   726,  1199,  1094,  6496,
    1601,  1181,  6315,  6315,  1051,  1202,  1210,  8891,  1211,  1068,
    1212,  1213,  8912,  1087,  1217,  1219,  6496,  8933,  4707,  1041,
   -1299, -1299, -1299,  8954,  8975,  6496,  5139,  1230,  1229,  8996,
    1048,  9311,  1045,  1054,  9311,  1046,  1055,  9311,  1053,  1059,
    9311,  1060,  9017,  9038,  9059,  5139,  6315,  1064, -1299, -1299,
    1482,  2010,   249,  6496,  6496, -1299, -1299,  1063,  1065,  6074,
    7246,  7272,  7298,  3951,   823,   249,  2040,  9080,  4894,  9101,
    9122,  9143,  6496,  1254, -1299,  6496,  9164, -1299,  8346,  8369,
   -1299,   609,   610,   618, -1299, -1299,  8392,  8415,  7324,  8438,
     151,  6315, -1299,  1071,  1070,  5081,  1072,  1075,  1079, -1299,
    6315, -1299,  6315, -1299,  6315, -1299,  6315,   621, -1299, -1299,
    3756,  6315,   902, -1299,  6315, -1299,  1262,  1268,  1274,  1090,
    6496,  2229,  6496,  6496, -1299,    70, -1299, -1299,  2331,  1088,
    5139,  1278,   148,   148,  5268,   629,  5139, -1299, -1299,  8461,
     151,   492, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,  6496, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,  6496,  6496,  6496, -1299,  6315, -1299, -1299, -1299,
   -1299,  1094,  5139,  1094,  1094,  1601, -1299, -1299, -1299, -1299,
   -1299,  6496, -1299, -1299,  1094, -1299, -1299, -1299,  6496,  1279,
     115,  6496,  1280,  1281,  1749, -1299,  1282,  1110,    26,  1284,
   -1299,  6315,  6315,  6315,  6315, -1299,   569,  1285,  6496, -1299,
    1113,  1115,  1098, -1299,  1286, -1299, -1299, -1299, -1299, -1299,
     151,   151,  8484, -1299, -1299,  1120,  1094,   298, -1299,   306,
    7350, -1299, -1299, -1299,  1287, -1299, -1299,  8208,   569,   249,
    3543, -1299,   746,  5139,  5139,  1290,  5139,   750,  5139,  5139,
    1295,  1225,  5139,  5139,  1975,  1300,  1301,  6315,  1302,  1303,
    3917, -1299, -1299,  1305, -1299,  1306,   114,  6496,   114,  6496,
     114,  6496,   114,  6496,  1307,  1311,  1313,  1319,   639,  1308,
    2445, -1299, -1299,   315,  7376,  7402, -1299, -1299,  5455,   -91,
     249,   249,   249,  1323,  1324,  1136,  1326,  1145,    34,    50,
      52,    53,   -12, -1299,   320, -1299,   823,  1327,  1329,  1330,
    1331,  1332,  9311, -1299,  2376,  1146,  1334,  1344,  1346,  1275,
    6496,  1351,  1352,  6496,   198,   645, -1299,  6496, -1299,  6496,
    6496,  6496,   651,   658,   659,   662, -1299,  6496,   663,   672,
    5139,  5139,  5139,  1355,  7428, -1299,  3898,  1705,  1356,  1357,
   -1299,  5139,  1160, -1299,  6496,  1361,  6496,  1362, -1299,   569,
    1363,  1364, -1299,  1358, -1299,  1367,  8208,  8208,  8208,  8208,
     521,  1169,  1185,  1186,  1187,  1200,   593,   607,  9185,  1188,
    2444, -1299,   316,  1203,  1371,  2502, -1299, -1299, -1299,    26,
    6496, -1299,   677, -1299,   688,   692,   693,   697,   114, -1299,
    9311,  1191,  6496,  6496,  5139,  1201, -1299, -1299, -1299,  1205,
   -1299,  1374,    72,  1394,  6496,  4330,  1398,  1399,    15,  1223,
    1227,  1318,  1318,  5139,  1414,  1235,  1237,  1428,  1429,  5139,
    1241,  1431,  1432, -1299,  1434,  5139,   702,  5139,  5139,  1439,
    1440, -1299,  5139,  5139,  9311,  5139,  9311,  5139,  9311,  5139,
    9311,  5139,  5139,  5139, -1299,  1441,   433, -1299,  6496,  6496,
    6496,  1252,  1255,   178,   202,   238,  1259, -1299,  5139, -1299,
    6496, -1299,  1446, -1299,  1447, -1299,  1448, -1299,  1450, -1299,
   -1299,  6074,   650,  4952, -1299,  1264,  1265,  5700, -1299,  6315,
   -1299, -1299, -1299,  1267,  2534, -1299, -1299,  8507,  1453,   569,
    7454,  7480,  7506,  7532, -1299, -1299, -1299, -1299,  9311, -1299,
     569,  1467,  1468,  1341, -1299,  6496,  6496,  6496, -1299,  1471,
     563,  1304,  1493,  2745, -1299,  2853, -1299,   114, -1299, -1299,
      83, -1299, -1299, -1299, -1299, -1299, -1299,  1094, -1299, -1299,
   -1299,  1601,  1497, -1299, -1299,    24, -1299, -1299, -1299, -1299,
   -1299,  1601,  6496,  1494,  1499,    30, -1299,  1498,  8530,    26,
   -1299,  1501,  1502,  1504,  1505,  5139,  6496,  7558,  7584,   703,
   -1299,  6496,  1508, -1299, -1299,  1094, -1299,  7610,  3956,  9311,
   -1299, -1299, -1299, -1299,  6496,  6496,   249,  1507,  1509,  1510,
   -1299,  6496,  6496, -1299, -1299,  1511,  6496, -1299, -1299,  1513,
    1514,  1328,  1515,  1381,  6496, -1299,  1516,  1518,  1520,  1522,
    1524,  1525,   896,  1527,  6496, -1299,  6134,  5642,  9206,  4325,
      42,    42,   249,  1528,   249,  1529,   249,  1530,  6496,   276,
    1345,  9227, -1299, -1299, -1299, -1299,  5829,   360, -1299,  1532,
    3549,  1535,  5139,   249,  3549,  1536,   710,  6496, -1299,  1537,
     151, -1299,  6496,  6496,  6496,  6496, -1299, -1299, -1299,  5139,
    4479,   791,  9248, -1299, -1299,  4391,  5139, -1299, -1299, -1299,
    5139, -1299,  1359,   569,  4143,  4578,  1601,  1538,  2899, -1299,
    1540,  1539, -1299,  1360, -1299, -1299, -1299, -1299, -1299,  1544,
     354,  9311,  6496,  6496,  5139,  1369,   716,  9311, -1299,  1547,
    6496, -1299, -1299,  6035,  6068,   458, -1299, -1299, -1299,  6257,
    6396, -1299,  6424,  1561, -1299,  5139, -1299,  1491,  1563,  9311,
   -1299, -1299, -1299, -1299, -1299, -1299,  1377, -1299, -1299,  4946,
    3032,  1570,  1382, -1299,  6496, -1299,  1384,  1385,   380, -1299,
    1383,   393, -1299,  1403,   423, -1299,  1404,  8553,  1594,  5139,
    1596,  1409,  6496, -1299,  5887,   425, -1299,   717,   427,   445,
   -1299,  1599,  6742, -1299,  7636,  7662,  7688,  7714,  1474,  6496,
   -1299,  6496, -1299, -1299,  6315,  3146,  1602,  1413,  1604, -1299,
   -1299,  3762, -1299, -1299,  1094,  9311, -1299, -1299, -1299, -1299,
      26, -1299,  1475, -1299, -1299,  6496,  7740,  7766, -1299,  5139,
    6496,  1609, -1299,  7792, -1299, -1299,  1610,  1612,  1614,  1629,
    1630,  1631,   720,  1452, -1299,  5139,  6315, -1299, -1299,    42,
    4507, -1299, -1299,  6074,   823,  6074,   823,  6074,   823,  1642,
   -1299,   721,  5139, -1299,  6770,   249,  1644,  6315,   249, -1299,
   -1299,  6496,  6496,  6496,  6496,  6496,  6798,  6826,   728, -1299,
   -1299,  1645, -1299,   737,  3498,   752,  1646, -1299,  1458,  9311,
    6496,  6496,   755,  9311, -1299,  6496,   756,   759, -1299, -1299,
   -1299, -1299, -1299, -1299,  1462,  6496,   760,   780,  1464,  6496,
   -1299,  6854,   453,  1108,  6882,   456,  1158,  6910,   478,  1350,
   -1299,  5139,  1652,  1566,  2657,  1473,   480, -1299,   781,   482,
    7818,  7844,  7870,  7896,  3243, -1299, -1299,  1656, -1299,  6496,
   -1299,  1601, -1299, -1299,  6496,  9269,  7922,    51,  7948, -1299,
   -1299,  6496,  6938,  1663,  1576, -1299,  6966,  1666,  6496,  1667,
    1668,  6496,  1669,  1670,  6496,  1671,  1485, -1299,  6496, -1299,
     823, -1299,  6315,  1676,  5887,  6496,  6496,  6496,  6496, -1299,
   -1299,  1309, -1299,   785, -1299,  6496, -1299,  5139,  6496,  7974,
   -1299, -1299,  5139,  1677, -1299, -1299,  1490,  6994, -1299, -1299,
    1495,  7022, -1299, -1299,  1512,  7050, -1299,  1680,  3287,  1695,
    2806,   786, -1299,   503,   789,  8000,  8026,  8052,  8078,  1601,
    1682,  1517,  9290,   790,  7078,  6496, -1299, -1299,   823,  1683,
     823,  1685,   823,  1686, -1299, -1299, -1299, -1299,   823,  1687,
    6315,  1688,  6496,  6496,  6496,  6496, -1299, -1299,  1094, -1299,
    1519,  1690,  7106,  2068, -1299,  1521,  2089, -1299,  1523,  2118,
   -1299,  1543,  2139, -1299,   794, -1299,  8104,  8130,  8156,  8182,
     795, -1299,  1545,  5139, -1299,  1691,  1696,   823,  1711,   823,
    1726,   823, -1299,  1728,  6496,  6496,  6496,  6496,  1094,  1735,
    1094,   801, -1299, -1299,  2681, -1299,  2752, -1299,  2846, -1299,
    7134,  7162,  7190,  7218, -1299, -1299,   805, -1299,  1738,  1739,
    1740,  1741, -1299, -1299, -1299, -1299,  1094,  1742, -1299, -1299,
   -1299, -1299, -1299, -1299
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1299, -1299, -1299, -1299,   619, -1299, -1299, -1299, -1299,   155,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,  -338,   -64,   937,    -9, -1299,  1316, -1299, -1299,
   -1299, -1299, -1299,   273, -1299,   269, -1299, -1299, -1299, -1299,
   -1299, -1299,   654,  1755,    -2,  -479,  -249, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,  1757, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,  -951,  -917,
   -1299, -1299,  1298, -1299, -1299, -1299, -1299, -1299, -1299,  1496,
   -1299, -1299,    22, -1299, -1298,  2133,  -136,  1818,   -73,  -237,
     530, -1299,    21,    10, -1299,  -361,    -3,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -482
static const yytype_int16 yytable[] =
{
     106,    93,   607,   477,   609,   206,   496,   644,   737,   738,
     889,   304,   617,   265,     4,   337,   180,   530,   512,   904,
     211,  1263,   184,   532,  1437,   527,   202,   179,  1355,   206,
     301,   389,   257,   203,   877,  1162,   534,   211,   485,   486,
    1151,   314,   316,   336,   107,   779,   393,   182,   781,   185,
     783,   631,   187,   785,   732,   321,  1153,  1636,  1155,  1157,
     333,   334,   295,   645,     5,  1160,   565,   508,   567,   509,
    -479,   248,   250,   324,   256,   325,   311,  1028,  1254,   268,
     183,   269,   326,   973,   457,   458,   459,   485,   486,   462,
     463,   464,   186,   974,   485,   486,   328,  1492,   485,   486,
     258,   975,   976,   977,   259,  1142,   499,   978,   979,   980,
     981,   487,   198,   500,   199,   488,   260,   333,   334,  1062,
     312,   644,   189,   485,   486,   504,   505,  -480,   630,   402,
     441,   890,   891,   892,   893,   446,   190,   517,   518,   450,
     498,    48,    49,    50,    51,   220,   456,   270,   221,    56,
     531,   222,    59,   266,   202,   644,   533,  1152,   528,   667,
     191,   881,   390,   391,   668,   329,   330,   331,   332,   535,
     311,  1356,   394,  1154,   669,  1156,  1158,   569,   420,   670,
     421,  1542,   311,   311,  1159,   333,   334,   326,   905,   207,
     311,   192,   870,   485,   486,   305,   208,  1556,   311,   338,
     295,   339,   894,   340,   267,   295,   426,   429,   175,   295,
     435,   212,   295,   207,   392,   529,   295,   295,   295,   295,
     882,   302,   295,   295,   295,   878,   428,   428,   883,   730,
     731,   315,   317,   295,   428,   780,   295,   322,   782,   816,
     784,   188,   436,   786,   323,  1160,  1637,   905,   193,   746,
    1063,  1064,   194,   510,   329,   330,   331,   332,   295,   295,
     295,   236,  1029,   195,   237,   480,   481,   672,   333,   334,
     295,   295,   673,   489,   333,   334,   196,   497,  -481,   329,
     330,   331,   332,   295,   546,   295,   329,   330,   331,   332,
     868,   871,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   333,   334,   273,   801,
     417,   274,   197,   329,   330,   331,   332,   240,   577,   295,
     295,   808,   665,  1231,   666,   632,   549,   643,   550,   175,
     241,   242,   295,   333,   334,   326,   333,   334,   578,  1673,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   856,   204,   485,   486,   417,   673,
     311,   311,   311,   311,   311,   311,   295,   311,   311,   205,
     311,   311,  1302,   215,  1303,   311,   311,   311,   311,   311,
     485,   486,   209,   333,   334,   608,   620,   610,   611,   612,
    1178,   614,   615,   627,   210,   618,  1304,   295,  1305,   622,
     623,   624,   625,   214,   428,   428,   428,   428,   428,   428,
     884,   428,   428,   863,   428,   428,   485,   486,   864,   428,
     428,   428,   428,   626,   398,  1741,   399,   244,   245,   522,
     400,   523,  1306,   524,  1307,   295,   174,   246,   175,  1295,
    1296,   761,   762,   763,   247,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   547,   415,   416,   398,
     338,   399,   568,   417,   524,   576,   398,   787,   399,   175,
     674,   673,  1428,   675,  1034,  1036,   712,   715,   718,   721,
     960,   329,   330,   331,   332,   394,   394,  1092,   485,   486,
     485,   486,   683,   485,   486,  1093,   425,   110,   485,   486,
     683,   333,   334,   815,   739,   213,   745,   735,   736,  1138,
     214,   295,   295,   295,  1161,   481,   772,   261,   229,   262,
     822,   230,   252,   311,   231,   253,   232,   677,   254,   216,
     675,   136,   137,   138,   139,   140,   141,   295,   485,   486,
     145,   217,   795,  1474,   295,   147,   148,   149,  1475,   683,
     150,   684,   218,  1563,  1432,  1566,   219,  1569,   485,   486,
     536,   155,   223,   537,   869,   872,   538,   773,   539,  1344,
    1345,   485,   486,   295,  1503,   224,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   833,  1505,   835,   836,
     837,   838,   839,   840,   841,   907,   228,   909,   845,   847,
     848,   485,   486,   485,   486,   485,   486,   238,  1123,   857,
    1125,   683,  1127,   689,  1129,   225,   865,  1507,   226,  1515,
     227,  1517,   233,   485,   486,   234,   880,   235,   244,   245,
     239,   485,   486,   243,   485,   486,   485,   486,   246,  1518,
     873,  1071,   295,   158,   159,   255,  1160,  1608,   263,  1160,
    1611,   264,  1160,   958,   251,   166,   485,   486,   485,   486,
     485,   486,   398,   271,   399,   295,   307,   295,   771,  1659,
     311,   275,  1614,   311,  1622,   311,  1624,   333,   334,   295,
     295,   485,   486,   272,  1043,   414,   415,   416,   276,   398,
     918,   399,   417,   277,   912,   794,   298,  1690,  1005,   916,
     398,   299,   399,   295,   297,   846,   822,  1012,   300,  1013,
     398,  1014,   399,  1015,   428,   683,   306,   914,  1018,   428,
     308,  1019,   295,   295,  1232,   309,   683,  1703,   693,  1706,
     310,  1709,   412,   413,   414,   415,   416,  1712,   313,   366,
    1245,   417,  1160,   377,   683,   973,   699,   367,  1035,  1037,
     683,   810,   789,   811,   963,   974,  1042,  1044,   398,   368,
     399,   969,   369,   975,   976,   977,   370,   984,   295,   978,
     979,   980,   981,  1050,   371,   373,  1744,   295,  1746,   295,
    1748,   295,   398,   295,   399,   378,  1160,  1222,   295,  1160,
     379,   295,  1160,   397,   418,  1160,   398,   475,   399,  1451,
     683,  1225,   886,   683,   683,   998,   999,   295,  1074,  1075,
    1076,  1077,   683,   295,  1000,   683,   380,  1016,   311,   382,
     383,  1416,  1417,   683,  1099,  1039,  1100,  1160,  1105,  1160,
    1106,  1160,  1237,   683,   419,  1135,  1087,  1088,   423,   683,
     664,  1179,  1045,   295,   444,   683,  1318,  1184,   311,   295,
     311,   311,   683,   683,  1185,  1186,   683,   683,  1187,  1189,
     455,   311,   428,   449,  1116,  1055,   683,   454,  1190,  1350,
     460,  1239,  1051,  1240,  1053,  1054,   478,  1078,   295,   295,
     295,   295,   683,   461,  1241,  1059,   683,   683,  1242,  1243,
     513,   683,   428,  1244,   428,   428,   683,  1374,  1281,  1375,
    1406,   465,  1407,   311,   683,   428,  1441,   466,  1096,  1097,
    1480,  1374,  1481,  1516,  1374,  1571,  1554,  1572,   973,   467,
     295,   295,   683,   295,  1587,   295,   295,  1091,   974,   295,
     295,  1589,   468,  1590,   295,   469,   975,   976,   977,   470,
    1044,  1098,   978,   979,   980,   981,   673,   428,  1592,  1374,
    1222,  1597,  1599,  1225,  1374,  1600,  1603,   471,   200,   201,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   683,   683,  1604,  1623,   417,  1480,
     683,  1670,  1689,   683,  1374,  1691,  1700,  1452,   683,  1738,
    1733,  1739,  1143,  1144,  1145,  1374,   472,  1758,  1233,  1766,
     501,  1767,  1364,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   295,   295,   295,
    1558,   417,   479,   502,   490,   491,   492,   503,   295,   507,
    1207,   514,   511,   515,   519,   516,   520,  1212,  1213,  1214,
    1215,  1216,   521,   327,   526,   548,   552,  1223,  1226,   556,
     558,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   559,   175,   326,   563,
     564,   295,   372,   566,   575,   374,   580,   581,   584,   417,
     633,   375,   376,   634,   174,   679,  1326,   381,   425,   110,
     295,   636,   680,  1535,   696,  1260,   295,   700,   701,   702,
     727,   705,   295,   706,   295,   295,   725,   728,   729,   295,
     295,   752,   295,   754,   295,   755,   295,   757,   295,   295,
     295,     7,     8,   136,   137,   138,   139,   140,   141,   764,
     765,   770,   145,   774,   799,   295,  1351,   147,   148,   149,
     776,   802,   150,   809,   817,   777,   818,   778,   849,   850,
     295,   851,   852,   155,   295,   853,   295,   854,   861,   862,
    1331,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     866,  1336,   867,  1317,   417,   875,   876,   903,   919,   922,
     908,   637,    24,    25,   638,    27,    28,   639,    30,   640,
      32,   911,    33,   973,   913,   915,   927,    38,    39,   923,
      41,    42,    43,   974,   311,   525,    46,   924,   926,   928,
     929,   975,   976,   977,   932,   931,   933,   978,   979,   980,
     981,  1353,   551,  1536,   942,   944,   937,   946,  1352,   947,
     949,  1357,   295,   948,   950,   158,   159,   951,   952,    67,
      68,    69,   311,   973,   953,   295,   959,   166,   428,   966,
     993,   967,  1006,   974,  1574,  1007,  1351,  1009,  1382,  1020,
    1010,   975,   976,   977,  1011,  1021,  1379,   978,   979,   980,
     981,  1022,  1023,  1031,  1033,  1061,  1066,  1067,  1385,  1069,
    1073,  1079,  1086,  1084,  1095,  1090,   428,  1103,   394,   394,
    1070,  1082,  1109,  1083,  1609,  1110,  1411,  1114,  1115,  1117,
    1118,  1121,  1136,  1122,  1131,   760,  1669,   295,  1132,   295,
    1133,   295,     7,     8,  1418,  1134,  1421,  1146,  1424,   635,
    1147,  1148,  1149,  1150,  1163,  1164,   295,  1165,  1166,  1167,
    1170,  1169,  1435,   295,  1460,  1438,  1439,   295,     7,     8,
    1171,   295,  1172,  1173,  1612,  1456,  1202,  1175,  1176,  1194,
    1199,  1200,  1210,  1217,  1463,  1466,  1467,  1204,  1206,  1208,
    1209,   295,  1660,  1211,  1218,  1219,  1220,  1229,  1235,  1246,
    1253,  1528,   637,    24,    25,   638,    27,    28,   639,    30,
     640,    32,   295,    33,  1221,  1234,  1251,  1252,    38,    39,
    1256,    41,    42,    43,  1261,  1262,  1266,    46,   637,    24,
      25,   638,    27,    28,   639,    30,   640,    32,  1264,    33,
    1270,   860,  1265,  1557,    38,    39,   295,    41,    42,    43,
    1271,   295,  1272,    46,  1273,  1274,  1276,  1277,  1278,  1279,
      67,    68,    69,  1284,  1578,   973,  1285,  1300,  1294,  1308,
    1301,   295,  1312,  1313,  1314,   974,  1315,  1330,   295,  1322,
    1323,   311,  1327,   975,   976,   977,    67,    68,    69,   978,
     979,   980,   981,  1337,  1338,  1339,   295,  1343,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   295,   295,     7,     8,   417,   394,  1346,  1347,
    1359,  1354,   177,  1360,  1362,   428,   806,  1365,  1366,   295,
    1367,  1368,  1378,  1386,   295,  1387,  1388,  1391,  1393,  1397,
    1394,  1396,  1400,  1395,  1401,  1562,  1402,  1565,  1403,  1568,
    1404,  1405,   807,  1408,  1419,  1422,  1425,  1576,  1433,  1429,
    1579,  1436,  1440,  1443,  1468,  1471,  1615,  1470,  1459,  1661,
    1473,  1664,  1472,  1482,   637,    24,    25,   638,    27,    28,
     639,    30,   640,    32,  1479,    33,  1491,  1493,   295,  1494,
      38,    39,  1495,    41,    42,    43,  1498,  1499,  1504,    46,
    1501,  1502,   319,   320,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,  1506,  1508,
    1510,  1632,   417,  1512,  1513,  1519,   110,  1525,  1530,  1531,
    1532,  1537,    67,    68,    69,  1544,  1548,  1714,  1549,   295,
    1550,   295,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   295,  1551,  1552,  1553,   417,   295,
     136,   137,   138,   139,   140,   141,  1663,  1555,  1570,   145,
    1577,  1588,  1593,  1594,   147,   148,   149,  1601,  1617,   150,
    1605,  1618,  1630,   384,   385,   386,   387,   388,  1621,  1641,
     155,  1642,  1645,  1648,  1649,  1652,  1653,  1656,   961,  1696,
     424,  1657,  1662,  1677,   430,  1678,  1684,   295,  1697,  1704,
    1680,  1707,  1710,  1713,  1715,   311,  1724,  1742,   437,   439,
     442,   443,  1743,   445,   439,   447,   448,  1682,   439,   451,
     452,  1255,  1698,  1197,  1723,   439,  1727,  1745,  1729,  1721,
     295,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,  1747,   474,  1749,   311,   417,   311,  1731,   428,
    1740,  1755,   483,   484,  1768,  1769,  1770,  1771,  1773,  1633,
     678,   484,   158,   159,  1547,  1068,  1268,  1546,    92,  1754,
     101,  1757,   708,   311,   166,  1361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
       0,   428,   541,   543,   439,     0,     0,  1772,     0,     0,
     973,     0,     0,     0,   553,   554,   555,     0,   557,     0,
     974,   560,   561,     0,     0,   562,     0,   428,   975,   976,
     977,     0,     0,     0,   978,   979,   980,   981,     0,     0,
     573,   574,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   582,   583,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,     0,
       0,   619,     0,   621,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,  1686,   417,   642,  1198,     0,   439,     0,     0,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,     0,     0,   662,   663,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,   541,     0,   417,     0,     0,     0,
     687,     0,     0,     0,     0,   692,     0,     0,     0,     0,
     697,   698,     0,     0,     0,     0,   703,   704,     0,     0,
       0,   709,   711,   714,   717,   720,   722,   723,   724,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1113,     0,     0,     0,     0,   740,   741,   742,   384,
     385,   743,     0,     0,     0,   747,   748,   749,   750,   751,
       0,     0,     0,   756,     0,     0,   758,   759,     0,     0,
     439,   439,   439,     0,     0,   766,   767,   768,   582,   769,
       0,   440,     7,     8,     0,   775,   440,     0,     0,     0,
     440,     0,     0,     0,     0,     0,   439,   440,     0,     0,
       0,     0,   790,   792,     0,   662,   663,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   769,     0,     0,     0,     0,     0,
       0,   814,   439,     0,     0,     0,     0,   819,     0,     0,
       0,     0,   637,    24,    25,   638,    27,    28,   639,    30,
     640,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,   542,     0,   440,    46,     0,     0,
       0,     0,   637,    24,    25,   638,    27,    28,   639,    30,
     640,    32,     0,    33,     0,     0,     0,   874,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
      67,    68,    69,     0,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,   902,   417,   973,   439,     0,   439,   910,     0,     0,
      67,    68,    69,   974,     0,   917,     0,     0,   792,   920,
       0,   975,   976,   977,   973,     0,     0,   978,   979,   980,
     981,     0,   934,     0,   974,     0,     0,     0,     0,     0,
       0,   940,   975,   976,   977,     0,   962,     0,   978,   979,
     980,   981,     0,   973,     0,     0,     0,     0,   440,     0,
       0,     0,   439,   974,     0,     0,     0,     0,     0,   964,
     965,   975,   976,   977,   973,   968,   985,   978,   979,   980,
     981,     7,     8,     0,   974,     0,     0,     0,   992,     0,
       0,   994,   975,   976,   977,     0,   542,     0,   978,   979,
     980,   981,     0,     0,  1726,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,   439,     0,   439,     0,
     439,     0,   439,     0,     0,  1728,     0,   439,     0,     0,
     439,     0,     0,     0,     0,     0,  1024,     0,  1026,  1027,
       0,   637,    24,    25,   638,    27,    28,   639,    30,   640,
      32,   546,    33,     0,  1730,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
    1046,     0,   440,   440,   440,  1732,     0,     0,  1047,  1048,
    1049,     0,   439,     7,     8,     0,     0,     0,   453,     0,
       0,     0,     0,     0,     0,     0,     0,  1058,   440,    67,
      68,    69,     0,     0,  1060,   793,     0,  1065,     0,   473,
       0,     0,   476,     0,     0,     0,     0,   439,   439,   439,
     439,     0,  1168,     0,  1080,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   440,     0,   506,     0,     0,     0,
       0,     0,     0,   637,    24,    25,   638,    27,    28,   639,
      30,   640,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,  1025,     0,     0,    46,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1124,     0,  1126,     0,  1128,     0,  1130,
    1230,     0,     0,     0,     0,   571,   572,     7,     8,     0,
       0,    67,    68,    69,     0,     0,     0,     0,   579,     0,
       0,     0,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   547,   415,   416,   440,     0,   440,     0,
     417,     0,     0,     0,     0,     0,  1174,     0,     0,  1177,
     793,   921,   613,  1180,     0,  1181,  1182,  1183,  1236,     0,
       0,     0,     0,  1188,     0,     0,     0,   637,    24,    25,
     638,    27,    28,   639,    30,   640,    32,  1030,    33,     0,
    1203,     0,  1205,    38,    39,     0,    41,    42,    43,     0,
    1328,     0,    46,     0,   440,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,  1238,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,  1247,  1248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   440,
    1257,  1259,     0,     0,     0,     0,     0,     0,   440,     0,
     440,     0,   440,     0,   440,     0,     0,     0,     0,   440,
       0,     0,   440,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,  1297,  1298,  1299,     0,     0,     0,
       0,  1137,     0,     0,  1309,     0,  1311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1316,     0,     0,
       0,     0,     0,     0,   440,   439,     0,     0,     0,     7,
       8,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,  1340,  1341,  1342,     0,     0,     0,     0,     0,   440,
     440,   440,   440,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1358,   637,
      24,    25,   638,    27,    28,   639,    30,   640,    32,     0,
      33,     0,  1371,     0,     0,    38,    39,  1377,    41,    42,
      43,  1348,     0,     0,    46,   440,     0,     0,     0,     0,
    1383,  1384,     0,     0,     0,     0,     0,  1389,  1390,     0,
       0,     0,  1392,     0,     0,     0,   973,     0,   887,     0,
    1399,     0,     0,     0,     0,     0,   974,    67,    68,    69,
    1409,     0,  1410,     0,   975,   976,   977,     0,     0,     0,
     978,   979,   980,   981,  1427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   439,     0,     7,     8,
     439,     0,     0,  1442,     0,     0,     0,     0,  1444,  1445,
    1446,  1447,     0,     0,     0,     0,     0,     0,     0,   941,
       0,  1455,     0,     0,     0,     0,     0,   973,     0,     0,
       0,  1465,     0,  1619,     0,     0,     0,   974,   957,  1349,
       0,     0,     0,     0,     0,   975,   976,   977,  1476,  1477,
       0,   978,   979,   980,   981,     0,  1483,  1759,   637,    24,
      25,   638,    27,    28,   639,    30,   640,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,  1469,     0,     0,     0,     0,
    1500,     0,     0,     0,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,  1514,     0,
     541,     0,   417,     0,     0,     0,    67,    68,    69,     0,
       0,   973,     0,  1032,     0,  1526,     0,  1527,  1760,  1040,
     439,   974,     0,     0,     0,     0,     0,  1534,     0,   975,
     976,   977,     0,     0,     0,   978,   979,   980,   981,     0,
       0,  1539,     0,     0,     0,     0,  1543,     0,     0,     0,
       0,     0,     0,     0,     0,  1052,     0,   440,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1561,
       0,  1564,  1687,  1567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   439,     0,     0,     0,  1580,  1581,  1582,
    1583,  1584,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,  1595,  1596,  1497,     0,
     417,  1598,  1761,     0,     0,     0,     0,     0,     0,     0,
       0,  1602,     0,     0,     0,  1606,  1101,  1102,     0,  1104,
       0,  1107,  1108,     0,     0,  1111,  1112,     0,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,  1631,   417,     0,     0,     0,
    1377,     0,     0,     0,     0,     0,     0,  1639,     0,     0,
       0,     0,     0,     0,  1647,     0,     0,  1651,     0,     0,
    1655,     0,     0,     0,  1658,     0,     0,     0,   439,     0,
     439,  1665,  1666,  1667,  1668,     0,     0,     0,     0,     0,
       0,  1672,     0,     0,  1674,     0,     0,     0,   440,     0,
       0,     0,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1529,  1191,  1192,  1193,     0,     0,     0,     0,
       0,     0,     0,     0,  1201,     0,     0,     0,     0,     0,
       0,  1702,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   439,     0,  1716,  1717,
    1718,  1719,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,  1250,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1750,  1751,  1752,  1753,     0,     0,  1269,     0,     0,     0,
       0,     0,  1275,     0,     0,     0,     0,     0,  1280,  1629,
    1282,  1283,   542,     0,     0,  1286,  1287,     0,  1288,     0,
    1289,     0,  1290,     0,  1291,  1292,  1293,     0,     0,     0,
       0,     0,   440,     0,     0,     0,     0,     0,     0,   440,
       0,  1310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1685,     0,     0,  1321,     0,     0,     0,
    1325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   440,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,   440,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,     0,     0,     0,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,  1369,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,  1381,     0,     0,   147,   148,   149,     0,     0,   150,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
     155,     0,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,     0,     0,     0,     0,
     417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1250,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,  1448,     0,   417,     0,     0,     0,     0,  1457,
       0,     0,     0,  1458,     0,   156,     0,  1462,     0,     0,
       0,   157,   158,   159,   160,     0,     0,     0,     0,   161,
     162,   163,   164,   165,   166,  1591,   546,  1478,   440,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,     0,   169,     0,     0,     0,  1250,   170,
       0,   171,     0,   172,   173,     0,   174,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   546,   108,   278,     0,     0,     0,     0,   111,   112,
     113,     0,  1511,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   280,     0,     0,   803,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,  1250,     0,     0,     0,     0,   154,     0,     0,
       0,   281,     0,     0,   282,     0,     0,   283,  1250,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,     0,     0,     0,  1573,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   682,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   160,     0,  1616,     0,     0,   161,   162,   163,
     164,   165,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   682,   415,   416,   888,   493,  1434,     0,
     417,     0,   169,     0,     0,     0,     0,   495,     0,     0,
       0,     0,   173,     0,   247,   544,     0,     0,     0,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,  1017,   108,   278,   417,     0,     0,
    1250,   111,   112,   113,     0,  1676,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,     0,     0,     0,     0,     0,
     154,     0,     0,     0,   281,     0,     0,   282,     0,     0,
     283,     0,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,     0,  1250,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,  1196,     0,     0,     0,
       0,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
     167,   438,     0,   417,     0,   169,     0,     0,     0,     0,
     287,     0,     0,     0,     0,   173,     0,     0,   544,   108,
     278,   110,     0,     0,     0,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   280,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   147,
     148,   149,  1119,     0,   150,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,   155,     0,     0,   281,     0,
       0,   282,     0,     0,   283,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,   157,   158,   159,   160,
       0,     0,     0,     0,   161,   162,   163,   164,   165,   166,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   167,   286,     0,     0,   417,   169,
     788,     0,     0,     0,   287,   733,   108,   278,   110,   173,
       0,   288,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   280,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     7,     8,   147,   148,   149,     0,
       0,   150,     0,   151,   152,   153,     0,     0,     0,     0,
       0,   154,   155,     0,     0,   281,     0,     0,   282,     0,
       0,   283,     0,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
      56,     0,     0,    59,   637,    24,    25,   638,    27,    28,
     639,    30,   640,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,   161,   162,   163,   164,   165,   166,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,   167,   286,     0,     0,     0,   169,     0,     0,     0,
       0,   287,     0,   108,   318,   110,   173,     0,  1461,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   147,   148,   149,     0,     0,   150,     0,
     151,   152,   153,     0,   108,   318,   110,     0,   154,   155,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   147,   148,   149,     0,     0,   150,
       0,   151,   152,   153,     0,     0,     0,     0,     0,   154,
     155,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
     157,   158,   159,   160,     0,     0,     0,   570,   161,   162,
     163,   164,   165,   166,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   167,   168,
       0,     0,   417,   169,     0,     0,     0,     0,   287,  1414,
       0,  1415,     0,   173,     0,  1258,     0,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   157,   158,   159,   160,   417,     0,   628,     0,   161,
     162,   163,   164,   165,   166,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   167,
     168,     0,     0,   417,   169,     0,     0,     0,     0,   287,
     671,   108,   318,   110,   173,     0,  1454,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   147,   148,   149,     0,     0,   150,     0,   151,   152,
     153,     0,     0,     0,     0,     0,   154,   155,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,     0,  1449,     0,  1450,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,     0,     0,     0,     0,
       0,  1559,     0,  1560,     0,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,   157,   158,
     159,   160,   885,     0,     0,     0,   161,   162,   163,   164,
     165,   166,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   167,   168,     0,     0,
     417,   169,     0,     0,     0,     0,   287,   733,   108,   278,
     279,   173,     0,  1464,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,     0,     0,
       0,     0,     0,   154,     0,     0,     0,   281,     0,     0,
     282,     0,     0,   283,     0,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,     0,     0,     0,     0,
       0,     0,     0,   936,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   160,     0,
       0,     0,     0,   161,   162,   163,   164,   165,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,   167,   286,     0,   417,     0,   169,     0,
       0,     0,     0,   287,   726,   108,   278,  1319,   173,     0,
     288,   111,   112,   113,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,     0,     0,     0,     0,     0,
     154,     0,     0,     0,   281,     0,     0,   282,     0,     0,
     283,     0,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,    56,
       0,     0,    59,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
     988,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
     167,   286,     0,   417,     0,   169,     0,     0,     0,     0,
     287,  1496,   108,   278,     0,   173,     0,  1320,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,     0,     0,     0,     0,     0,   154,     0,     0,
       0,   281,     0,     0,   282,     0,     0,   283,     0,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,    56,     0,     0,    59,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417,     0,
       0,     0,     0,     0,     0,     0,     0,  1008,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   160,     0,     0,     0,     0,   161,   162,   163,
     164,   165,     0,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   167,   286,     0,
       0,   417,   169,     0,     0,     0,     0,   287,   734,   108,
     278,     0,   173,     0,   288,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,     0,     0,     0,   281,     0,
       0,   282,     0,     0,   283,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,  1038,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,     0,     0,   160,
       0,     0,     0,     0,   161,   162,   163,   164,   165,     0,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   167,   438,     0,     0,   417,   169,
       0,     0,     0,     0,   287,   800,   108,   278,     0,   173,
       0,   540,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,     0,     0,     0,     0,
       0,   154,     0,     0,     0,   281,     0,     0,   282,     0,
       0,   283,     0,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
      56,     0,     0,    59,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,     0,   417,     0,     0,     0,     0,     0,     0,     0,
       0,  1141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   160,     0,     0,     0,
       0,   161,   162,   163,   164,   165,     0,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   167,   438,     0,     0,   417,   169,     0,     0,     0,
       0,   287,   834,   108,   278,     0,   173,     0,   791,   111,
     112,   113,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   280,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   153,     0,     0,     0,     0,     0,   154,     0,
       0,     0,   281,     0,     0,   282,     0,     0,   283,     0,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,  1412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,     0,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   167,   286,
       0,     0,   417,   169,     0,     0,     0,     0,   287,   842,
     108,   278,     0,   173,     0,  1324,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   281,
       0,     0,   282,     0,     0,   283,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,    56,     0,     0,    59,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,     0,     0,     0,  1431,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     160,     0,     0,     0,     0,   161,   162,   163,   164,   165,
       0,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   493,  1434,     0,     0,   417,
     169,     0,     0,     0,     0,   495,   843,   108,   318,     0,
     173,     0,   247,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,     0,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   108,   318,   110,
       0,     0,   154,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,   147,   148,   149,
       0,     0,   150,     0,   151,   152,   153,     0,     0,     0,
       0,     0,   154,   155,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,     0,   417,     0,   157,     0,     0,   160,     0,     0,
       0,  1486,   161,   162,   163,   164,   165,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,   493,   494,     0,   417,     0,   169,     0,     0,
       0,     0,   495,     0,  1487,     0,     0,   173,     0,   247,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   157,   158,   159,   160,   417,     0,
     681,     0,   161,   162,   163,   164,   165,   166,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   167,   168,     0,     0,   417,   169,   108,   278,
       0,     0,   287,   844,   111,   112,   113,   173,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   152,   153,     0,     0,
       0,     0,     0,   154,     0,     0,     0,   281,     0,     0,
     282,     0,     0,   283,     0,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,     0,     0,     0,     0,
       0,     0,     0,  1488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   160,     0,
       0,     0,     0,   161,   162,   163,   164,   165,     0,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   167,   438,     0,     0,   417,   169,   108,
     318,     0,     0,   287,   855,   111,   112,   113,   173,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,     0,
       0,     0,     0,     0,   154,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,     0,  1489,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
    1490,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,   157,     0,     0,   160,
       0,     0,     0,     0,   161,   162,   163,   164,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,   167,   168,     0,     0,     0,   169,
       0,    -4,    -4,    -4,   287,     0,     0,    -4,    -4,   173,
      -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       6,     0,     0,     0,     0,    -4,     0,     0,     7,     8,
      -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,     9,    10,    -4,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,    -4,    11,    12,    13,     0,
       0,     0,    14,    15,     0,    16,     0,     0,     0,    17,
      18,     0,    19,    20,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,    63,    64,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,    67,    68,    69,     0,
       0,    70,     0,    71,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
      87,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,  1520,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,     0,     0,  1575,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,  1585,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,     0,  1586,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
    1607,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,  1610,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,     0,     0,  1613,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,  1640,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,     0,  1644,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
    1679,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,  1681,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,     0,     0,  1683,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,  1701,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,     0,  1725,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
    1762,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,  1763,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,     0,     0,  1764,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,  1765,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
     970,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,   971,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,   972,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1003,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1094,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1139,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1140,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,  1195,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1332,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1333,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1334,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1335,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,  1372,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1373,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1380,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1521,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1522,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,  1523,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1524,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1540,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1541,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1545,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,  1625,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1626,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1627,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1628,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1635,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,  1638,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1675,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1692,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1693,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1694,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,     0,
       0,     0,  1695,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,  1734,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,  1735,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
    1736,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,     0,     0,     0,  1737,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,   398,     0,   399,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417,     0,
       0,     0,   629,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,   805,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,     0,     0,   813,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,   821,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,     0,     0,     0,     0,
     417,     0,     0,     0,   901,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,     0,     0,   996,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,     0,     0,
     997,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,     0,     0,  1001,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,     0,   417,     0,     0,     0,  1002,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,     0,     0,  1004,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417,     0,
       0,     0,  1041,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,     0,     0,  1089,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,     0,     0,  1329,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,     0,
       0,  1363,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,     0,     0,     0,     0,
     417,     0,     0,     0,  1509,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,   685,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,   686,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,   688,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,   690,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,   691,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417,     0,
     694,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,   695,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,     0,     0,     0,     0,
     417,     0,   788,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,   796,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,     0,   417,     0,   797,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,   798,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,   804,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,   812,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,   820,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,   900,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417,     0,
     925,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,   930,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,     0,     0,     0,     0,
     417,     0,   935,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,   938,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,     0,   417,     0,   939,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,   945,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,   954,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,   955,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,   956,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,   987,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417,     0,
     989,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
       0,   990,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,     0,     0,     0,     0,
     417,     0,   991,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,     0,     0,     0,
       0,   417,     0,   995,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,     0,   417,     0,  1228,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,     0,  1413,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,     0,  1430,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,     0,     0,     0,     0,   417,     0,  1453,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,     0,  1634,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,     0,     0,     0,     0,   417,     0,  1699,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,     0,     0,     0,     0,   417
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1299)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,   363,   240,   365,     4,   255,     7,   487,   488,
       4,     4,   373,     4,     6,     4,     6,     5,   267,     6,
       4,     6,    78,     5,  1322,     5,   188,     6,     4,     4,
       4,     4,     4,   195,     4,   986,     5,     4,   178,   179,
       6,     5,     5,   107,     3,     5,     4,     6,     5,   188,
       5,   389,     6,     5,   194,     6,     6,     6,     6,     6,
     185,   186,    65,   401,     0,   982,   315,     4,   317,     6,
     195,    49,    50,   188,    52,   190,    79,     7,     6,     4,
      13,     6,   197,    95,   220,   221,   222,   178,   179,   225,
     226,   227,   188,   105,   178,   179,     7,  1395,   178,   179,
      72,   113,   114,   115,    76,   196,   188,   119,   120,   121,
     122,   195,   188,   195,   190,   195,    88,   185,   186,     4,
      79,     7,     6,   178,   179,   261,   262,   195,     7,     6,
     203,   125,   126,   127,   128,   208,     6,   273,   274,   212,
     195,    99,   100,   101,   102,    72,   219,    72,    75,   107,
     138,    78,   110,   144,   188,     7,   138,   123,   138,   189,
       6,   195,   135,   136,   194,   165,   166,   167,   168,   138,
     173,   147,   174,   123,   189,   123,   123,     6,   188,   194,
     190,  1479,   185,   186,   196,   185,   186,   197,   175,   188,
     193,     6,   192,   178,   179,   188,   195,  1495,   201,   188,
     203,   190,   196,   192,   195,   208,   185,   186,   197,   212,
     200,   195,   215,   188,   173,   195,   219,   220,   221,   222,
     195,   195,   225,   226,   227,   195,   185,   186,   195,   478,
     479,   195,   195,   236,   193,   195,   239,   188,   195,   577,
     195,   195,   201,   195,   195,  1162,   195,   175,   188,   498,
     135,   136,     6,   190,   165,   166,   167,   168,   261,   262,
     263,    75,   192,     6,    78,   243,   244,   189,   185,   186,
     273,   274,   194,   251,   185,   186,   190,   255,   195,   165,
     166,   167,   168,   286,     8,   288,   165,   166,   167,   168,
     628,   629,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   185,   186,    75,   558,
     187,    78,   190,   165,   166,   167,   168,   135,   327,   322,
     323,   570,   190,     7,   192,   389,   188,   400,   190,   197,
     148,   149,   335,   185,   186,   197,   185,   186,   328,  1637,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   189,   188,   178,   179,   187,   194,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   188,
     373,   374,   194,    82,   196,   378,   379,   380,   381,   382,
     178,   179,   188,   185,   186,   364,   376,   366,   367,   368,
     192,   370,   371,   383,   188,   374,   194,   400,   196,   378,
     379,   380,   381,   188,   363,   364,   365,   366,   367,   368,
     195,   370,   371,   189,   373,   374,   178,   179,   194,   378,
     379,   380,   381,   382,   189,  1723,   191,   178,   179,   188,
     195,   190,   194,   192,   196,   438,   195,   188,   197,     6,
       7,   514,   515,   516,   195,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   189,
     188,   191,   190,   187,   192,   195,   189,   540,   191,   197,
     191,   194,   196,   194,   812,   813,   466,   467,   468,   469,
     729,   165,   166,   167,   168,   487,   488,   189,   178,   179,
     178,   179,   194,   178,   179,   189,     4,     5,   178,   179,
     194,   185,   186,   576,   194,   188,   194,   485,   486,   194,
     188,   514,   515,   516,   194,   493,   525,    78,    72,    80,
     584,    75,    72,   526,    78,    75,    80,   191,    78,    78,
     194,    39,    40,    41,    42,    43,    44,   540,   178,   179,
      48,    78,   551,   189,   547,    53,    54,    55,   194,   194,
      58,   196,     6,  1504,   194,  1506,   195,  1508,   178,   179,
      72,    69,    78,    75,   628,   629,    78,   526,    80,     6,
       7,   178,   179,   576,   194,    78,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   194,   597,   598,
     599,   600,   601,   602,   603,   668,    80,   670,   607,   608,
     609,   178,   179,   178,   179,   178,   179,   188,   946,   618,
     948,   194,   950,   196,   952,    75,   625,   194,    78,   194,
      80,   194,    75,   178,   179,    78,   635,    80,   178,   179,
      75,   178,   179,   195,   178,   179,   178,   179,   188,   194,
     630,   878,   645,   151,   152,   195,  1563,   194,    78,  1566,
     194,    75,  1569,   726,   195,   163,   178,   179,   178,   179,
     178,   179,   189,    75,   191,   668,     6,   670,   195,  1620,
     673,     4,   194,   676,   194,   678,   194,   185,   186,   682,
     683,   178,   179,    78,   192,   180,   181,   182,     4,   189,
     680,   191,   187,     4,   673,   195,   188,   194,   771,   678,
     189,   188,   191,   706,     4,   194,   770,   780,   188,   782,
     189,   784,   191,   786,   673,   194,   188,   676,   791,   678,
       6,   794,   725,   726,  1062,   190,   194,  1678,   196,  1680,
       4,  1682,   178,   179,   180,   181,   182,  1688,     4,   188,
    1078,   187,  1659,     7,   194,    95,   196,   188,   812,   813,
     194,   194,   196,   196,   732,   105,   820,   821,   189,   188,
     191,   739,   188,   113,   114,   115,   188,   745,   771,   119,
     120,   121,   122,   846,   188,   188,  1727,   780,  1729,   782,
    1731,   784,   189,   786,   191,   188,  1703,   194,   791,  1706,
     188,   794,  1709,   195,   195,  1712,   189,     4,   191,     8,
     194,   194,   196,   194,   194,   196,   196,   810,   881,   882,
     883,   884,   194,   816,   196,   194,   188,   196,   821,   188,
     188,  1300,  1301,   194,    78,   196,    80,  1744,    78,  1746,
      80,  1748,  1069,   194,     6,   196,   900,   901,     6,   194,
       6,   196,   821,   846,   188,   194,   196,   196,   851,   852,
     853,   854,   194,   194,   196,   196,   194,   194,   196,   196,
     195,   864,   821,   188,   937,   855,   194,   188,   196,  1207,
     188,   194,   851,   196,   853,   854,   195,   886,   881,   882,
     883,   884,   194,   188,   196,   864,   194,   194,   196,   196,
       6,   194,   851,   196,   853,   854,   194,   194,   196,   196,
       4,   188,     6,   906,   194,   864,   196,   188,   917,   918,
     194,   194,   196,   196,   194,   194,   196,   196,    95,   188,
     923,   924,   194,   926,   196,   928,   929,   906,   105,   932,
     933,   194,   188,   196,   937,   188,   113,   114,   115,   188,
    1004,   919,   119,   120,   121,   122,   194,   906,   196,   194,
     194,   196,   196,   194,   194,   196,   196,   188,    21,    22,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   194,   194,   196,   196,   187,   194,
     194,   196,   196,   194,   194,   196,   196,   196,   194,   194,
     196,   196,   970,   971,   972,   194,   188,   196,  1062,   194,
     188,   196,  1239,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,  1020,  1021,  1022,
    1499,   187,   195,   188,   195,   195,   195,   188,  1031,   188,
    1039,   195,   190,   195,   190,   195,   190,  1046,  1047,  1048,
    1049,  1050,   190,   106,   190,     6,     6,  1056,  1057,   192,
     195,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   138,   197,   197,     6,
       6,  1084,   145,     6,   195,   148,     6,   190,     4,   187,
     192,   154,   155,     7,   195,   194,  1169,   160,     4,     5,
    1103,   196,   194,  1464,     7,  1095,  1109,     6,     6,     6,
     189,     7,  1115,     7,  1117,  1118,     7,     6,   195,  1122,
    1123,     7,  1125,     6,  1127,     7,  1129,     6,  1131,  1132,
    1133,    12,    13,    39,    40,    41,    42,    43,    44,     6,
       6,     4,    48,    50,   135,  1148,  1210,    53,    54,    55,
      50,   195,    58,   189,     6,    50,     6,    50,   189,   189,
    1163,   194,   194,    69,  1167,   194,  1169,   194,   194,   189,
    1179,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     189,  1190,   189,  1161,   187,     6,     4,     4,     7,   138,
       6,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     6,    83,    95,     6,     6,   138,    88,    89,     7,
      91,    92,    93,   105,  1217,   278,    97,     7,     7,     7,
       7,   113,   114,   115,     7,   138,     7,   119,   120,   121,
     122,  1221,   295,  1470,     4,     6,   195,   189,  1217,   194,
     194,  1231,  1245,   189,   189,   151,   152,   194,   189,   130,
     131,   132,  1255,    95,   194,  1258,   192,   163,  1217,   196,
       6,   196,   191,   105,  1513,   195,  1330,   195,  1258,     7,
     195,   113,   114,   115,   195,     7,  1255,   119,   120,   121,
     122,     7,   192,   195,     6,     6,     6,     6,  1266,     7,
       6,     6,     6,   195,     7,   175,  1255,     7,  1300,  1301,
     190,   188,     7,   188,   196,    80,  1296,     7,     7,     7,
       7,     6,     4,     7,     7,   196,     7,  1320,     7,  1322,
       7,  1324,    12,    13,  1302,     6,  1304,     4,  1306,   392,
       6,   195,     6,   188,     7,     6,  1339,     7,     7,     7,
       6,   195,  1320,  1346,  1353,  1323,  1324,  1350,    12,    13,
       6,  1354,     6,    78,   196,  1345,   196,     6,     6,     4,
       4,     4,     4,   194,  1354,  1355,  1356,     6,     6,     6,
       6,  1374,  1621,     6,   189,   189,   189,   189,     7,   188,
       6,  1454,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,  1395,    83,   194,   192,   195,   192,    88,    89,
       6,    91,    92,    93,     6,     6,    88,    97,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   195,    83,
       6,     6,   195,  1496,    88,    89,  1429,    91,    92,    93,
     195,  1434,   195,    97,     6,     6,   195,     6,     6,     5,
     130,   131,   132,     4,  1517,    95,     6,   195,     7,   190,
     195,  1454,     6,     6,     6,   105,     6,     4,  1461,   195,
     195,  1464,   195,   113,   114,   115,   130,   131,   132,   119,
     120,   121,   122,     6,     6,   134,  1479,     6,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,  1495,  1496,    12,    13,   187,  1499,   194,     6,
       6,     4,     6,     4,     6,  1464,   196,     6,     6,  1512,
       6,     6,     4,     6,  1517,     6,     6,     6,     5,   138,
       6,     6,     6,   195,     6,  1503,     6,  1505,     6,  1507,
       6,     6,   196,     6,     6,     6,     6,  1515,     6,   194,
    1518,     6,     6,     6,     6,     6,   196,     7,   189,  1622,
       6,  1624,   192,     6,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   195,    83,     5,    76,  1571,     6,
      88,    89,   195,    91,    92,    93,     6,   195,   195,    97,
     196,   196,    86,    87,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   195,   195,
       6,  1591,   187,     7,   195,     6,     5,   133,     6,   196,
       6,   136,   130,   131,   132,     6,     6,  1690,     6,  1622,
       6,  1624,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,  1637,     6,     6,     6,   187,  1642,
      39,    40,    41,    42,    43,    44,  1624,   195,     6,    48,
       6,     6,     6,   195,    53,    54,    55,   195,     6,    58,
     196,    95,     6,   167,   168,   169,   170,   171,   195,     6,
      69,    95,     6,     6,     6,     6,     6,     6,   196,  1669,
     184,   196,     6,     6,   188,   195,     6,  1690,     6,     6,
     195,     6,     6,     6,     6,  1698,     6,     6,   202,   203,
     204,   205,     6,   207,   208,   209,   210,   195,   212,   213,
     214,  1092,   195,     8,   195,   219,   195,     6,   195,  1698,
    1723,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,     6,   237,     6,  1738,   187,  1740,   195,  1698,
     195,     6,   246,   247,     6,     6,     6,     6,     6,  1594,
     434,   255,   151,   152,  1485,     6,  1102,  1484,     3,  1738,
       3,  1740,   464,  1766,   163,  1235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1738,
      -1,  1740,   286,   287,   288,    -1,    -1,  1766,    -1,    -1,
      95,    -1,    -1,    -1,   298,   299,   300,    -1,   302,    -1,
     105,   305,   306,    -1,    -1,   309,    -1,  1766,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,
     324,   325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   338,   339,    -1,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,   375,    -1,   377,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,   196,   187,   397,   189,    -1,   400,    -1,    -1,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,    -1,    -1,   420,   421,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   438,    -1,   187,    -1,    -1,    -1,
     444,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,
     454,   455,    -1,    -1,    -1,    -1,   460,   461,    -1,    -1,
      -1,   465,   466,   467,   468,   469,   470,   471,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,   490,   491,   492,   493,
     494,   495,    -1,    -1,    -1,   499,   500,   501,   502,   503,
      -1,    -1,    -1,   507,    -1,    -1,   510,   511,    -1,    -1,
     514,   515,   516,    -1,    -1,   519,   520,   521,   522,   523,
      -1,   203,    12,    13,    -1,   529,   208,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,    -1,   540,   219,    -1,    -1,
      -1,    -1,   546,   547,    -1,   549,   550,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,
      -1,   575,   576,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    92,    93,   286,    -1,   288,    97,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,   631,    88,    89,
      -1,    91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,
     130,   131,   132,    -1,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,   665,   187,    95,   668,    -1,   670,   671,    -1,    -1,
     130,   131,   132,   105,    -1,   679,    -1,    -1,   682,   683,
      -1,   113,   114,   115,    95,    -1,    -1,   119,   120,   121,
     122,    -1,   696,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   705,   113,   114,   115,    -1,   196,    -1,   119,   120,
     121,   122,    -1,    95,    -1,    -1,    -1,    -1,   400,    -1,
      -1,    -1,   726,   105,    -1,    -1,    -1,    -1,    -1,   733,
     734,   113,   114,   115,    95,   739,   196,   119,   120,   121,
     122,    12,    13,    -1,   105,    -1,    -1,    -1,   752,    -1,
      -1,   755,   113,   114,   115,    -1,   438,    -1,   119,   120,
     121,   122,    -1,    -1,   196,    -1,    -1,   771,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   780,    -1,   782,    -1,
     784,    -1,   786,    -1,    -1,   196,    -1,   791,    -1,    -1,
     794,    -1,    -1,    -1,    -1,    -1,   800,    -1,   802,   803,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     8,    83,    -1,   196,    -1,    -1,    88,    89,    -1,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
     834,    -1,   514,   515,   516,   196,    -1,    -1,   842,   843,
     844,    -1,   846,    12,    13,    -1,    -1,    -1,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   861,   540,   130,
     131,   132,    -1,    -1,   868,   547,    -1,   871,    -1,   236,
      -1,    -1,   239,    -1,    -1,    -1,    -1,   881,   882,   883,
     884,    -1,     6,    -1,   888,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   576,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    92,    93,   196,    -1,    -1,    97,    -1,
      -1,    -1,    -1,   937,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   947,    -1,   949,    -1,   951,    -1,   953,
       6,    -1,    -1,    -1,    -1,   322,   323,    12,    13,    -1,
      -1,   130,   131,   132,    -1,    -1,    -1,    -1,   335,    -1,
      -1,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   668,    -1,   670,    -1,
     187,    -1,    -1,    -1,    -1,    -1,  1000,    -1,    -1,  1003,
     682,   683,   369,  1007,    -1,  1009,  1010,  1011,     6,    -1,
      -1,    -1,    -1,  1017,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   196,    83,    -1,
    1034,    -1,  1036,    88,    89,    -1,    91,    92,    93,    -1,
       6,    -1,    97,    -1,   726,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,  1070,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,  1082,  1083,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,    -1,   780,    -1,
     782,    -1,   784,    -1,   786,    -1,    -1,    -1,    -1,   791,
      -1,    -1,   794,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,  1138,  1139,  1140,    -1,    -1,    -1,
      -1,   196,    -1,    -1,  1148,    -1,  1150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1161,    -1,    -1,
      -1,    -1,    -1,    -1,   846,  1169,    -1,    -1,    -1,    12,
      13,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,  1195,  1196,  1197,    -1,    -1,    -1,    -1,    -1,   881,
     882,   883,   884,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,  1232,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,  1246,    -1,    -1,    88,    89,  1251,    91,    92,
      93,     6,    -1,    -1,    97,   937,    -1,    -1,    -1,    -1,
    1264,  1265,    -1,    -1,    -1,    -1,    -1,  1271,  1272,    -1,
      -1,    -1,  1276,    -1,    -1,    -1,    95,    -1,   645,    -1,
    1284,    -1,    -1,    -1,    -1,    -1,   105,   130,   131,   132,
    1294,    -1,  1296,    -1,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,  1308,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1320,    -1,    12,    13,
    1324,    -1,    -1,  1327,    -1,    -1,    -1,    -1,  1332,  1333,
    1334,  1335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   706,
      -1,  1345,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,  1355,    -1,   196,    -1,    -1,    -1,   105,   725,     6,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,  1372,  1373,
      -1,   119,   120,   121,   122,    -1,  1380,   196,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,    93,
      -1,    -1,    -1,    97,    -1,     6,    -1,    -1,    -1,    -1,
    1414,    -1,    -1,    -1,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,  1432,    -1,
    1434,    -1,   187,    -1,    -1,    -1,   130,   131,   132,    -1,
      -1,    95,    -1,   810,    -1,  1449,    -1,  1451,   196,   816,
    1454,   105,    -1,    -1,    -1,    -1,    -1,  1461,    -1,   113,
     114,   115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,  1475,    -1,    -1,    -1,    -1,  1480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   852,    -1,  1169,    -1,    -1,
      -1,    -1,  1496,    -1,    -1,    -1,    -1,    -1,    -1,  1503,
      -1,  1505,   196,  1507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1517,    -1,    -1,    -1,  1521,  1522,  1523,
    1524,  1525,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,  1540,  1541,     6,    -1,
     187,  1545,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1555,    -1,    -1,    -1,  1559,   923,   924,    -1,   926,
      -1,   928,   929,    -1,    -1,   932,   933,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,  1589,   187,    -1,    -1,    -1,
    1594,    -1,    -1,    -1,    -1,    -1,    -1,  1601,    -1,    -1,
      -1,    -1,    -1,    -1,  1608,    -1,    -1,  1611,    -1,    -1,
    1614,    -1,    -1,    -1,  1618,    -1,    -1,    -1,  1622,    -1,
    1624,  1625,  1626,  1627,  1628,    -1,    -1,    -1,    -1,    -1,
      -1,  1635,    -1,    -1,  1638,    -1,    -1,    -1,  1320,    -1,
      -1,    -1,  1324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,  1020,  1021,  1022,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1031,    -1,    -1,    -1,    -1,    -1,
      -1,  1675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1690,    -1,  1692,  1693,
    1694,  1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,  1084,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1734,  1735,  1736,  1737,    -1,    -1,  1103,    -1,    -1,    -1,
      -1,    -1,  1109,    -1,    -1,    -1,    -1,    -1,  1115,     6,
    1117,  1118,  1434,    -1,    -1,  1122,  1123,    -1,  1125,    -1,
    1127,    -1,  1129,    -1,  1131,  1132,  1133,    -1,    -1,    -1,
      -1,    -1,  1454,    -1,    -1,    -1,    -1,    -1,    -1,  1461,
      -1,  1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,  1163,    -1,    -1,    -1,
    1167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1496,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,  1517,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,  1245,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,  1258,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1622,    -1,  1624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1322,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,  1339,    -1,   187,    -1,    -1,    -1,    -1,  1346,
      -1,    -1,    -1,  1350,    -1,   144,    -1,  1354,    -1,    -1,
      -1,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,     7,     8,  1374,  1690,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,    -1,    -1,    -1,   183,    -1,    -1,    -1,  1395,   188,
      -1,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,  1429,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,  1479,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,  1495,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,  1512,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,    -1,  1571,    -1,    -1,   158,   159,   160,
     161,   162,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     8,   178,   179,    -1,
     187,    -1,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   196,    -1,    -1,    -1,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,     8,     3,     4,   187,    -1,    -1,
    1637,     9,    10,    11,    -1,  1642,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,  1723,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,     8,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
     178,   179,    -1,   187,    -1,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,   196,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    95,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,    -1,    -1,   110,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   178,   179,    -1,    -1,   187,   183,
     189,    -1,    -1,    -1,   188,   194,     3,     4,     5,   193,
      -1,   195,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    12,    13,    53,    54,    55,    -1,
      -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,    -1,    -1,   110,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,
      -1,   188,    -1,     3,     4,     5,   193,    -1,   195,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,    -1,
      60,    61,    62,    -1,     3,     4,     5,    -1,    68,    69,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
     150,   151,   152,   153,    -1,    -1,    -1,   195,   158,   159,
     160,   161,   162,   163,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   178,   179,
      -1,    -1,   187,   183,    -1,    -1,    -1,    -1,   188,   194,
      -1,   196,    -1,   193,    -1,   195,    -1,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   150,   151,   152,   153,   187,    -1,   189,    -1,   158,
     159,   160,   161,   162,   163,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   178,
     179,    -1,    -1,   187,   183,    -1,    -1,    -1,    -1,   188,
     194,     3,     4,     5,   193,    -1,   195,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    55,    -1,    -1,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   196,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   178,   179,    -1,    -1,
     187,   183,    -1,    -1,    -1,    -1,   188,   194,     3,     4,
       5,   193,    -1,   195,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,    -1,    -1,   110,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,   178,   179,    -1,   187,    -1,   183,    -1,
      -1,    -1,    -1,   188,   195,     3,     4,     5,   193,    -1,
     195,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
      -1,    -1,   110,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
     178,   179,    -1,   187,    -1,   183,    -1,    -1,    -1,    -1,
     188,   195,     3,     4,    -1,   193,    -1,   195,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,    -1,    -1,   110,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   178,   179,    -1,
      -1,   187,   183,    -1,    -1,    -1,    -1,   188,   194,     3,
       4,    -1,   193,    -1,   195,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,    -1,    -1,   110,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   178,   179,    -1,    -1,   187,   183,
      -1,    -1,    -1,    -1,   188,   194,     3,     4,    -1,   193,
      -1,   195,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,    -1,    -1,   110,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,    -1,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   178,   179,    -1,    -1,   187,   183,    -1,    -1,    -1,
      -1,   188,   194,     3,     4,    -1,   193,    -1,   195,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,    -1,    -1,
     110,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,    -1,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   178,   179,
      -1,    -1,   187,   183,    -1,    -1,    -1,    -1,   188,   194,
       3,     4,    -1,   193,    -1,   195,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,    -1,    -1,   110,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   178,   179,    -1,    -1,   187,
     183,    -1,    -1,    -1,    -1,   188,   194,     3,     4,    -1,
     193,    -1,   195,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,     3,     4,     5,
      -1,    -1,    68,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    54,    55,
      -1,    -1,    58,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,   150,    -1,    -1,   153,    -1,    -1,
      -1,   196,   158,   159,   160,   161,   162,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,   178,   179,    -1,   187,    -1,   183,    -1,    -1,
      -1,    -1,   188,    -1,   196,    -1,    -1,   193,    -1,   195,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   150,   151,   152,   153,   187,    -1,
     189,    -1,   158,   159,   160,   161,   162,   163,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   178,   179,    -1,    -1,   187,   183,     3,     4,
      -1,    -1,   188,   194,     9,    10,    11,   193,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,    -1,    -1,   110,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,    -1,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   178,   179,    -1,    -1,   187,   183,     3,
       4,    -1,    -1,   188,   194,     9,    10,    11,   193,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,   150,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,   178,   179,    -1,    -1,    -1,   183,
      -1,    50,    51,    52,   188,    -1,    -1,    56,    57,   193,
      59,    -1,    -1,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    -1,    -1,   116,   117,   118,
       4,    -1,    -1,    -1,    -1,   124,    -1,    -1,    12,    13,
     129,   130,   131,   132,    -1,    -1,   135,    -1,   137,    -1,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    37,    38,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,    50,    51,    52,    -1,
      -1,    -1,    56,    57,    -1,    59,    -1,    -1,    -1,    63,
      64,    -1,    66,    67,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
     124,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
      -1,   135,    -1,   137,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,   189,    -1,   191,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,   191,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,   191,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,   191,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   191,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,   191,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,   191,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,   191,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
     189,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,   189,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,   189,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,   189,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,   189,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
     189,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,   189,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,   189,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,   189,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,   189,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
     189,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,   189,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,   189,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,   189,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,   189,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,   189,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   199,   200,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    56,    57,    59,    63,    64,    66,
      67,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   116,   117,   118,   124,   129,   130,   131,   132,
     135,   137,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   154,   155,   156,   157,   164,   201,   203,
     204,   224,   241,   242,   245,   246,   247,   248,   249,   250,
     251,   252,   273,   274,   275,   276,   294,   295,     3,     4,
       5,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    53,    54,    55,
      58,    60,    61,    62,    68,    69,   144,   150,   151,   152,
     153,   158,   159,   160,   161,   162,   163,   178,   179,   183,
     188,   190,   192,   193,   195,   197,   222,   277,   278,   290,
     291,   294,   295,    13,    78,   188,   188,     6,   195,     6,
       6,     6,     6,   188,     6,     6,   190,   190,   188,   190,
     222,   222,   188,   195,   188,   188,     4,   188,   195,   188,
     188,     4,   195,   188,   188,    82,    78,    78,     6,   195,
      72,    75,    78,    78,    78,    75,    78,    80,    80,    72,
      75,    78,    80,    75,    78,    80,    75,    78,   188,    75,
     135,   148,   149,   195,   178,   179,   188,   195,   280,   281,
     280,   195,    72,    75,    78,   195,   280,     4,    72,    76,
      88,    78,    80,    78,    75,     4,   144,   195,     4,     6,
      72,    75,    78,    75,    78,     4,     4,     4,     4,     5,
      36,    72,    75,    78,    80,    92,   179,   188,   195,   242,
     252,   277,   283,   284,   285,   294,   295,     4,   188,   188,
     188,     4,   195,   287,     4,   188,   188,     6,     6,   190,
       4,   294,   295,     4,     5,   195,     5,   195,     4,   277,
     277,     6,   188,   195,   188,   190,   197,   222,     7,   165,
     166,   167,   168,   185,   186,   220,   221,     4,   188,   190,
     192,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   188,   188,   188,   188,
     188,   188,   222,   188,   222,   222,   222,     7,   188,   188,
     188,   222,   188,   188,   277,   277,   277,   277,   277,     4,
     135,   136,   295,     4,   242,   243,   244,   195,   189,   191,
     195,   223,     6,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   187,   195,     6,
     188,   190,   221,     6,   277,     4,   290,   291,   295,   290,
     277,   290,   293,   226,   229,   291,   295,   277,   179,   277,
     285,   286,   277,   277,   188,   277,   286,   277,   277,   188,
     286,   277,   277,   283,   188,   195,   286,   284,   284,   284,
     188,   188,   284,   284,   284,   188,   188,   188,   188,   188,
     188,   188,   188,   283,   277,     4,   283,   287,   195,   195,
     280,   280,   280,   277,   277,   178,   179,   195,   195,   280,
     195,   195,   195,   178,   179,   188,   244,   280,   195,   188,
     195,   188,   188,   188,   284,   284,   283,   188,     4,     6,
     190,   190,   244,     6,   195,   195,   195,   284,   284,   190,
     190,   190,   188,   190,   192,   222,   190,     5,   138,   195,
       5,   138,     5,   138,     5,   138,    72,    75,    78,    80,
     195,   277,   285,   277,   196,   286,     8,   180,     6,   188,
     190,   222,     6,   277,   277,   277,   192,   277,   195,   138,
     277,   277,   277,     6,     6,   244,     6,   244,   190,     6,
     195,   283,   283,   277,   277,   195,   195,   223,   291,   283,
       6,   190,   277,   277,     4,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   293,   290,   293,
     290,   290,   290,   283,   290,   290,   277,   293,   290,   277,
     291,   277,   290,   290,   290,   290,   295,   291,   189,   191,
       7,   220,   221,   192,     7,   222,   196,    72,    75,    78,
      80,   241,   277,   286,     7,   220,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   205,   277,   277,     6,   190,   192,   189,   194,   189,
     194,   194,   189,   194,   191,   194,   225,   191,   225,   194,
     194,   189,   180,   194,   196,   189,   189,   277,   189,   196,
     189,   189,   277,   196,   189,   189,     7,   277,   277,   196,
       6,     6,     6,   277,   277,     7,     7,   270,   270,   277,
     235,   277,   291,   236,   277,   291,   237,   277,   291,   238,
     277,   291,   277,   277,   277,     7,   195,   189,     6,   195,
     244,   244,   194,   194,   194,   280,   280,   243,   243,   194,
     277,   277,   277,   277,   256,   194,   244,   277,   277,   277,
     277,   277,     7,   271,     6,     7,   277,     6,   277,   277,
     196,   286,   286,   286,     6,     6,   277,   277,   277,   277,
       4,   195,   223,   295,    50,   277,    50,    50,    50,     5,
     195,     5,   195,     5,   195,     5,   195,   286,   189,   196,
     277,   195,   277,   285,   195,   223,   189,   189,   189,   135,
     194,   244,   195,     8,   189,   191,   196,   196,   244,   189,
     194,   196,   189,   191,   277,   286,   220,     6,     6,   277,
     189,   191,   221,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   194,   223,   223,   223,   223,   223,
     223,   223,   194,   194,   194,   223,   194,   223,   223,   189,
     189,   194,   194,   194,   194,   194,   189,   223,   279,   292,
       6,   194,   189,   189,   194,   223,   189,   189,   220,   221,
     192,   220,   221,   291,   277,     6,     4,     4,   195,   288,
     223,   195,   195,   195,   195,   196,   196,   283,     8,     4,
     125,   126,   127,   128,   196,   208,   212,   215,   217,   218,
     189,   191,   277,     4,     6,   175,   202,   286,     6,   286,
     277,     6,   290,     6,   295,     6,   290,   277,   291,     7,
     277,   285,   138,     7,     7,   189,     7,   138,     7,     7,
     189,   138,     7,     7,   277,   189,   196,   195,   189,   189,
     277,   283,     4,   269,     6,   189,   189,   194,   189,   194,
     189,   194,   189,   194,   189,   189,   189,   283,   286,   192,
     244,   196,   196,   280,   277,   277,   196,   196,   277,   280,
     194,   194,   194,    95,   105,   113,   114,   115,   119,   120,
     121,   122,   266,   267,   280,   196,   253,   189,   196,   189,
     189,   189,   277,     6,   277,   189,   191,   191,   196,   196,
     196,   191,   191,   194,   191,   286,   191,   195,   196,   195,
     195,   195,   286,   286,   286,   286,   196,     8,   286,   286,
       7,     7,     7,   192,   277,   196,   277,   277,     7,   192,
     196,   195,   283,     6,   220,   221,   220,   221,   196,   196,
     283,   191,   221,   192,   221,   290,   277,   277,   277,   277,
     286,   290,   283,   290,   290,   291,   231,   233,   277,   290,
     277,     6,     4,   135,   136,   277,     6,     6,     6,     7,
     190,   287,   289,     6,   286,   286,   286,   286,   223,     6,
     277,   209,   188,   188,   195,   219,     6,   221,   221,   191,
     175,   290,   189,   189,   194,     7,   223,   223,   280,    78,
      80,   283,   283,     7,   283,    78,    80,   283,   283,     7,
      80,   283,   283,     6,     7,     7,   286,     7,     7,    95,
     268,     6,     7,   220,   277,   220,   277,   220,   277,   220,
     277,     7,     7,     7,     6,   196,     4,   196,   194,   194,
     194,   196,   196,   280,   280,   280,     4,     6,   195,     6,
     188,     6,   123,     6,   123,     6,   123,     6,   123,   196,
     267,   194,   266,     7,     6,     7,     7,     7,     6,   195,
       6,     6,     6,    78,   277,     6,     6,   277,   192,   196,
     277,   277,   277,   277,   196,   196,   196,   196,   277,   196,
     196,   283,   283,   283,     4,   194,     8,     8,   189,     4,
       4,   283,   196,   277,     6,   277,     6,   223,     6,     6,
       4,     6,   223,   223,   223,   223,   223,   194,   189,   189,
     189,   194,   194,   223,   232,   194,   223,   234,   189,   189,
       6,     7,   220,   221,   192,     7,     6,   287,   277,   194,
     196,   196,   196,   196,   196,   220,   188,   277,   277,   282,
     283,   195,   192,     6,     6,   202,     6,   277,   195,   277,
     291,     6,     6,     6,   195,   195,    88,   240,   240,   283,
       6,   195,   195,     6,     6,   283,   195,     6,     6,     5,
     283,   196,   283,   283,     4,     6,   283,   283,   283,   283,
     283,   283,   283,   283,     7,     6,     7,   277,   277,   277,
     195,   195,   194,   196,   194,   196,   194,   196,   190,   277,
     283,   277,     6,     6,     6,     6,   277,   280,   196,     5,
     195,   283,   195,   195,   195,   283,   286,   195,     6,   191,
       4,   223,   194,   194,   194,   194,   223,     6,     6,   134,
     277,   277,   277,     6,     6,     7,   194,     6,     6,     6,
     220,   221,   290,   291,     4,     4,   147,   291,   277,     6,
       4,   288,     6,   191,   287,     6,     6,     6,     6,   283,
     206,   277,   194,   194,   194,   196,   207,   277,     4,   290,
     194,   283,   291,   277,   277,   280,     6,     6,     6,   277,
     277,     6,   277,     5,     6,   195,     6,   138,   239,   277,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   277,
     277,   291,   196,   189,   194,   196,   243,   243,   280,     6,
     257,   280,     6,   258,   280,     6,   259,   277,   196,   194,
     189,   196,   194,     6,   179,   280,     6,   282,   280,   280,
       6,   196,   277,     6,   277,   277,   277,   277,   283,   194,
     196,     8,   196,   189,   195,   277,   291,   283,   283,   189,
     223,   195,   283,   291,   195,   277,   291,   291,     6,     6,
       7,     6,   192,     6,   189,   194,   277,   277,   283,   195,
     194,   196,     6,   277,   227,   228,   196,   196,   196,   196,
     196,     5,   282,    76,     6,   195,   195,     6,     6,   195,
     277,   196,   196,   194,   195,   194,   195,   194,   195,   191,
       6,   283,     7,   195,   277,   194,   196,   194,   194,     6,
     196,   194,   194,   194,   194,   133,   277,   277,   286,     6,
       6,   196,     6,   230,   277,   293,   287,   136,   210,   277,
     194,   194,   282,   277,     6,   194,   231,   233,     6,     6,
       6,     6,     6,     6,   196,   195,   282,   286,   243,   194,
     196,   277,   280,   266,   277,   280,   266,   277,   280,   266,
       6,   194,   196,   283,   244,   196,   280,     6,   286,   280,
     277,   277,   277,   277,   277,   196,   196,   196,     6,   194,
     196,     7,   196,     6,   195,   277,   277,   196,   277,   196,
     196,   195,   277,   196,   196,   196,   277,   196,   194,   196,
     196,   194,   196,   196,   194,   196,   283,     6,    95,   196,
     254,   195,   194,   196,   194,   194,   194,   194,   194,     6,
       6,   277,   291,   207,   189,   194,     6,   195,   194,   277,
     196,     6,    95,   272,   196,     6,   260,   277,     6,     6,
     261,   277,     6,     6,   262,   277,     6,   196,   277,   266,
     244,   286,     6,   280,   286,   277,   277,   277,   277,     7,
     196,   213,   277,   282,   277,   194,   283,     6,   195,   196,
     195,   196,   195,   196,     6,     6,   196,   196,   255,   196,
     194,   196,   194,   194,   194,   194,   291,     6,   195,   189,
     196,   196,   277,   266,     6,   263,   266,     6,   264,   266,
       6,   265,   266,     6,   286,     6,   277,   277,   277,   277,
     211,   290,   216,   195,     6,   196,   196,   195,   196,   195,
     196,   195,   196,   196,   194,   194,   194,   194,   194,   196,
     195,   282,     6,     6,   266,     6,   266,     6,   266,     6,
     277,   277,   277,   277,   290,     6,   214,   290,   196,   196,
     196,   196,   196,   196,   196,   196,   194,   196,     6,     6,
       6,     6,   290,     6
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
#line 186 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 197 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 198 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 199 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 200 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 201 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 202 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 203 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 210 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 211 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 212 "Gmsh.y"
    { return 1; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 217 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 221 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 228 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 233 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 238 "Gmsh.y"
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
#line 252 "Gmsh.y"
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
#line 265 "Gmsh.y"
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
#line 278 "Gmsh.y"
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
#line 306 "Gmsh.y"
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
#line 320 "Gmsh.y"
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
#line 333 "Gmsh.y"
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
#line 346 "Gmsh.y"
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
#line 364 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 378 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 380 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 385 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 387 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 392 "Gmsh.y"
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
#line 496 "Gmsh.y"
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
#line 506 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 515 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 522 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 532 "Gmsh.y"
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
#line 541 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 550 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 557 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 567 "Gmsh.y"
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
#line 575 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 585 "Gmsh.y"
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
#line 604 "Gmsh.y"
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
#line 623 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 629 "Gmsh.y"
    {
    }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 637 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 638 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 639 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 640 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 644 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 645 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 652 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 652 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 661 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 666 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 672 "Gmsh.y"
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
#line 732 "Gmsh.y"
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
#line 761 "Gmsh.y"
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
#line 790 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 795 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 800 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 805 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 810 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 817 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 824 "Gmsh.y"
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
#line 839 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 844 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 849 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 854 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 859 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 868 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 874 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 883 "Gmsh.y"
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
#line 901 "Gmsh.y"
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
#line 919 "Gmsh.y"
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
#line 928 "Gmsh.y"
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
#line 940 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 945 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 953 "Gmsh.y"
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
#line 973 "Gmsh.y"
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
#line 996 "Gmsh.y"
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
#line 1007 "Gmsh.y"
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
#line 1015 "Gmsh.y"
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
#line 1037 "Gmsh.y"
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
#line 1060 "Gmsh.y"
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
#line 1086 "Gmsh.y"
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
#line 1107 "Gmsh.y"
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
#line 1119 "Gmsh.y"
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
#line 1137 "Gmsh.y"
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
#line 1146 "Gmsh.y"
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
#line 1155 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1157 "Gmsh.y"
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
#line 1173 "Gmsh.y"
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
#line 1182 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1184 "Gmsh.y"
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
#line 1198 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1206 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1212 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1224 "Gmsh.y"
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
#line 1235 "Gmsh.y"
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
#line 1250 "Gmsh.y"
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
#line 1266 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1274 "Gmsh.y"
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
#line 1283 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1291 "Gmsh.y"
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
#line 1309 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1313 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1327 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1331 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1337 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1345 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1349 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1355 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1363 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1367 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1373 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1381 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1385 "Gmsh.y"
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
#line 1397 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1401 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1411 "Gmsh.y"
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
#line 1434 "Gmsh.y"
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
#line 1466 "Gmsh.y"
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
#line 1489 "Gmsh.y"
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
#line 1507 "Gmsh.y"
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
#line 1528 "Gmsh.y"
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
#line 1546 "Gmsh.y"
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
#line 1576 "Gmsh.y"
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
#line 1606 "Gmsh.y"
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
#line 1624 "Gmsh.y"
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
#line 1643 "Gmsh.y"
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
#line 1669 "Gmsh.y"
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
#line 1687 "Gmsh.y"
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
#line 1705 "Gmsh.y"
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
#line 1740 "Gmsh.y"
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
#line 1758 "Gmsh.y"
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
#line 1797 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1803 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1809 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1816 "Gmsh.y"
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
#line 1841 "Gmsh.y"
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
#line 1866 "Gmsh.y"
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
#line 1883 "Gmsh.y"
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
#line 1903 "Gmsh.y"
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
#line 1936 "Gmsh.y"
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
#line 1972 "Gmsh.y"
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
#line 1990 "Gmsh.y"
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
#line 2007 "Gmsh.y"
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
#line 2023 "Gmsh.y"
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
#line 2060 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2065 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2070 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2075 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2080 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 2085 "Gmsh.y"
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
#line 2108 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 2114 "Gmsh.y"
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
#line 2124 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 2125 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 2130 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 2134 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 2138 "Gmsh.y"
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
#line 2161 "Gmsh.y"
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
#line 2184 "Gmsh.y"
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
#line 2207 "Gmsh.y"
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
#line 2235 "Gmsh.y"
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
#line 2256 "Gmsh.y"
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
#line 2283 "Gmsh.y"
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
#line 2304 "Gmsh.y"
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
#line 2325 "Gmsh.y"
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
#line 2345 "Gmsh.y"
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
#line 2457 "Gmsh.y"
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
#line 2476 "Gmsh.y"
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
#line 2515 "Gmsh.y"
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
#line 2623 "Gmsh.y"
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
#line 2632 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2638 "Gmsh.y"
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
#line 2653 "Gmsh.y"
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
#line 2681 "Gmsh.y"
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
#line 2698 "Gmsh.y"
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
#line 2707 "Gmsh.y"
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
#line 2721 "Gmsh.y"
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
#line 2735 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 2741 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2747 "Gmsh.y"
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
#line 2756 "Gmsh.y"
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
#line 2765 "Gmsh.y"
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
#line 2774 "Gmsh.y"
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
#line 2788 "Gmsh.y"
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
#line 2844 "Gmsh.y"
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
#line 2862 "Gmsh.y"
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
#line 2879 "Gmsh.y"
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
#line 2894 "Gmsh.y"
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
#line 2913 "Gmsh.y"
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
#line 2925 "Gmsh.y"
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
#line 2949 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2953 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 2958 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 2965 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 2970 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 2976 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 2981 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 2987 "Gmsh.y"
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
#line 2995 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 2999 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3003 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3009 "Gmsh.y"
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
#line 3063 "Gmsh.y"
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
#line 3076 "Gmsh.y"
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
#line 3093 "Gmsh.y"
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
#line 3110 "Gmsh.y"
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
#line 3132 "Gmsh.y"
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
#line 3154 "Gmsh.y"
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
#line 3189 "Gmsh.y"
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
#line 3197 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3203 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3210 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3214 "Gmsh.y"
    {
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3223 "Gmsh.y"
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
#line 3231 "Gmsh.y"
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
#line 3239 "Gmsh.y"
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
#line 3247 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3253 "Gmsh.y"
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
#line 3261 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3267 "Gmsh.y"
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
#line 3275 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3281 "Gmsh.y"
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
#line 3289 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3295 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3310 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3317 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3324 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3345 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3352 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3366 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3372 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3379 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3385 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3392 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3398 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3411 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3418 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3424 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3431 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3437 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3444 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3450 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3457 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3463 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3470 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3476 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3487 "Gmsh.y"
    {
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3490 "Gmsh.y"
    {
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3496 "Gmsh.y"
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
#line 3508 "Gmsh.y"
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
#line 3528 "Gmsh.y"
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
#line 3552 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3556 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3560 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3564 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3568 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3574 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3580 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3584 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3588 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3592 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3596 "Gmsh.y"
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
#line 3615 "Gmsh.y"
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
#line 3627 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3631 "Gmsh.y"
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
#line 3646 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3650 "Gmsh.y"
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
#line 3666 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3670 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 3675 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 3679 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3685 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 3689 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 3696 "Gmsh.y"
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
#line 3752 "Gmsh.y"
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
#line 3822 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 3827 "Gmsh.y"
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
#line 3894 "Gmsh.y"
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
#line 3930 "Gmsh.y"
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
#line 3938 "Gmsh.y"
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
#line 3981 "Gmsh.y"
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
#line 4020 "Gmsh.y"
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
#line 4040 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(5) - (6)].l)) != List_Nbr((yyvsp[(3) - (6)].l))){
	yymsg(0, "Number of master (%d) different from number of slave (%d) lines",
              List_Nbr((yyvsp[(5) - (6)].l)), List_Nbr((yyvsp[(3) - (6)].l)));
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(5) - (6)].l), i, &d_master);
          List_Read((yyvsp[(3) - (6)].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          Curve *c_slave = FindCurve(abs(j_slave));
          if(c_slave){
	    GModel::current()->getGEOInternals()->periodicEdges[j_slave] = j_master;
          }
          else{
            GEdge *ge = GModel::current()->getEdgeByTag(abs(j_slave));
            if(ge) ge->setMeshMaster(j_master);
            else yymsg(0, "Unknown line %d", j_slave);
          }
        }
      }
      List_Delete((yyvsp[(3) - (6)].l));
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4068 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (13)].l)) != List_Nbr((yyvsp[(10) - (13)].l))){
	yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (13)].l)), List_Nbr((yyvsp[(5) - (13)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (13)].d);
        int j_slave = (int)(yyvsp[(3) - (13)].d);
        Surface *s_slave = FindSurface(abs(j_slave));
	std::vector<double> transfo;
	for(int i = 0; i < List_Nbr((yyvsp[(12) - (13)].l)); i++){
	  double d;
	  List_Read((yyvsp[(12) - (13)].l), i, &d);
	  transfo.push_back(d);
	}
        if(s_slave){
	  GModel::current()->getGEOInternals()->periodicFaces[j_slave] = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (13)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (13)].l), i, &ds);
            List_Read((yyvsp[(10) - (13)].l), i, &dm);
	    GModel::current()->getGEOInternals()->periodicEdges[(int)ds] = (int)dm;
            s_slave->edgeCounterparts[(int)ds] = (int)dm;
            s_slave->affineTransform = transfo;
          }
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(abs(j_slave));
          if(gf){
            gf->setMeshMaster(j_master);
            for (int i = 0; i < List_Nbr((yyvsp[(5) - (13)].l)); i++){
              double dm, ds;
              List_Read((yyvsp[(5) - (13)].l), i, &ds);
              List_Read((yyvsp[(10) - (13)].l), i, &dm);
              gf->edgeCounterparts[(int)ds] = (int)dm;
	      gf->affineTransform = transfo;
	      GEdge *ges = GModel::current()->getEdgeByTag(abs((int)ds));
	      ges->setMeshMaster((int)dm);
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (13)].l));
      List_Delete((yyvsp[(10) - (13)].l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 4116 "Gmsh.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 4144 "Gmsh.y"
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

  case 324:
/* Line 1787 of yacc.c  */
#line 4172 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4176 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4180 "Gmsh.y"
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

  case 327:
/* Line 1787 of yacc.c  */
#line 4208 "Gmsh.y"
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

  case 328:
/* Line 1787 of yacc.c  */
#line 4247 "Gmsh.y"
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

  case 329:
/* Line 1787 of yacc.c  */
#line 4286 "Gmsh.y"
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

  case 330:
/* Line 1787 of yacc.c  */
#line 4307 "Gmsh.y"
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

  case 331:
/* Line 1787 of yacc.c  */
#line 4328 "Gmsh.y"
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

  case 332:
/* Line 1787 of yacc.c  */
#line 4355 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4359 "Gmsh.y"
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

  case 334:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
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

  case 335:
/* Line 1787 of yacc.c  */
#line 4403 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4404 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4405 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4410 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4416 "Gmsh.y"
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

  case 340:
/* Line 1787 of yacc.c  */
#line 4428 "Gmsh.y"
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

  case 341:
/* Line 1787 of yacc.c  */
#line 4446 "Gmsh.y"
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

  case 342:
/* Line 1787 of yacc.c  */
#line 4473 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4474 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4475 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4476 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4477 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4478 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4479 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4480 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4482 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4488 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4489 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4490 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4491 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4492 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4493 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4494 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4495 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4496 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4497 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4498 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4499 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4500 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4501 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4502 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4503 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4504 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4505 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4506 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4507 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4508 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4509 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4510 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4511 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4512 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4513 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4514 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4515 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4516 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4517 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4518 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4519 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4520 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4529 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4530 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4531 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4532 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4533 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4534 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 4535 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 4536 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4537 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4538 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4543 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4545 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 4551 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4556 "Gmsh.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 4573 "Gmsh.y"
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

  case 399:
/* Line 1787 of yacc.c  */
#line 4591 "Gmsh.y"
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

  case 400:
/* Line 1787 of yacc.c  */
#line 4609 "Gmsh.y"
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

  case 401:
/* Line 1787 of yacc.c  */
#line 4627 "Gmsh.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 4645 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4650 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4656 "Gmsh.y"
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

  case 405:
/* Line 1787 of yacc.c  */
#line 4668 "Gmsh.y"
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

  case 406:
/* Line 1787 of yacc.c  */
#line 4685 "Gmsh.y"
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

  case 407:
/* Line 1787 of yacc.c  */
#line 4703 "Gmsh.y"
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

  case 408:
/* Line 1787 of yacc.c  */
#line 4721 "Gmsh.y"
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

  case 409:
/* Line 1787 of yacc.c  */
#line 4739 "Gmsh.y"
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

  case 410:
/* Line 1787 of yacc.c  */
#line 4760 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4765 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4770 "Gmsh.y"
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

  case 413:
/* Line 1787 of yacc.c  */
#line 4780 "Gmsh.y"
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

  case 414:
/* Line 1787 of yacc.c  */
#line 4790 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4795 "Gmsh.y"
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

  case 416:
/* Line 1787 of yacc.c  */
#line 4806 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4815 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4820 "Gmsh.y"
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

  case 419:
/* Line 1787 of yacc.c  */
#line 4847 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4851 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4855 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4859 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4863 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4870 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4874 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4878 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4882 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4889 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4894 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4901 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4906 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4910 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4915 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4919 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 4927 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 4938 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 4942 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 4954 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 4962 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 4970 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 4977 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 4987 "Gmsh.y"
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

  case 443:
/* Line 1787 of yacc.c  */
#line 5016 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 5020 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 5024 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5028 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 5032 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5036 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5040 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5044 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5048 "Gmsh.y"
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

  case 452:
/* Line 1787 of yacc.c  */
#line 5077 "Gmsh.y"
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

  case 453:
/* Line 1787 of yacc.c  */
#line 5106 "Gmsh.y"
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

  case 454:
/* Line 1787 of yacc.c  */
#line 5135 "Gmsh.y"
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

  case 455:
/* Line 1787 of yacc.c  */
#line 5165 "Gmsh.y"
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

  case 456:
/* Line 1787 of yacc.c  */
#line 5178 "Gmsh.y"
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

  case 457:
/* Line 1787 of yacc.c  */
#line 5191 "Gmsh.y"
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

  case 458:
/* Line 1787 of yacc.c  */
#line 5204 "Gmsh.y"
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

  case 459:
/* Line 1787 of yacc.c  */
#line 5216 "Gmsh.y"
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

  case 460:
/* Line 1787 of yacc.c  */
#line 5226 "Gmsh.y"
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

  case 461:
/* Line 1787 of yacc.c  */
#line 5236 "Gmsh.y"
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

  case 462:
/* Line 1787 of yacc.c  */
#line 5248 "Gmsh.y"
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

  case 463:
/* Line 1787 of yacc.c  */
#line 5261 "Gmsh.y"
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

  case 464:
/* Line 1787 of yacc.c  */
#line 5273 "Gmsh.y"
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

  case 465:
/* Line 1787 of yacc.c  */
#line 5291 "Gmsh.y"
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

  case 466:
/* Line 1787 of yacc.c  */
#line 5312 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5317 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5321 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5325 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5337 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5341 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5353 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5360 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5370 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 5374 "Gmsh.y"
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

  case 476:
/* Line 1787 of yacc.c  */
#line 5389 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5394 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5401 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5405 "Gmsh.y"
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

  case 480:
/* Line 1787 of yacc.c  */
#line 5418 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5426 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5437 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5441 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5449 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 485:
/* Line 1787 of yacc.c  */
#line 5455 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 5461 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 5469 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 5477 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 5484 "Gmsh.y"
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

  case 490:
/* Line 1787 of yacc.c  */
#line 5499 "Gmsh.y"
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

  case 491:
/* Line 1787 of yacc.c  */
#line 5513 "Gmsh.y"
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

  case 492:
/* Line 1787 of yacc.c  */
#line 5527 "Gmsh.y"
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

  case 493:
/* Line 1787 of yacc.c  */
#line 5539 "Gmsh.y"
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

  case 494:
/* Line 1787 of yacc.c  */
#line 5555 "Gmsh.y"
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

  case 495:
/* Line 1787 of yacc.c  */
#line 5566 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 5570 "Gmsh.y"
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

  case 497:
/* Line 1787 of yacc.c  */
#line 5589 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 5596 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 5602 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 5604 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 5615 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 5620 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 5626 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 5635 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 5648 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 5651 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11787 "Gmsh.tab.cpp"
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
#line 5655 "Gmsh.y"


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
