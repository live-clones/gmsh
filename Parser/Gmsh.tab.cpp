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
static const char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
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
     tSyncModel = 310,
     tNewModel = 311,
     tOnelabAction = 312,
     tOnelabRun = 313,
     tCpu = 314,
     tMemory = 315,
     tTotalMemory = 316,
     tCreateTopology = 317,
     tCreateTopologyNoHoles = 318,
     tDistanceFunction = 319,
     tDefineConstant = 320,
     tUndefineConstant = 321,
     tDefineNumber = 322,
     tDefineString = 323,
     tSetNumber = 324,
     tSetString = 325,
     tPoint = 326,
     tCircle = 327,
     tEllipse = 328,
     tLine = 329,
     tSphere = 330,
     tPolarSphere = 331,
     tSurface = 332,
     tSpline = 333,
     tVolume = 334,
     tCharacteristic = 335,
     tLength = 336,
     tParametric = 337,
     tElliptic = 338,
     tRefineMesh = 339,
     tAdaptMesh = 340,
     tRelocateMesh = 341,
     tPlane = 342,
     tRuled = 343,
     tTransfinite = 344,
     tComplex = 345,
     tPhysical = 346,
     tCompound = 347,
     tPeriodic = 348,
     tUsing = 349,
     tPlugin = 350,
     tDegenerated = 351,
     tRecursive = 352,
     tRotate = 353,
     tTranslate = 354,
     tSymmetry = 355,
     tDilate = 356,
     tExtrude = 357,
     tLevelset = 358,
     tRecombine = 359,
     tSmoother = 360,
     tSplit = 361,
     tDelete = 362,
     tCoherence = 363,
     tIntersect = 364,
     tMeshAlgorithm = 365,
     tReverse = 366,
     tLayers = 367,
     tScaleLast = 368,
     tHole = 369,
     tAlias = 370,
     tAliasWithOptions = 371,
     tCopyOptions = 372,
     tQuadTriAddVerts = 373,
     tQuadTriNoNewVerts = 374,
     tQuadTriSngl = 375,
     tQuadTriDbl = 376,
     tRecombLaterals = 377,
     tTransfQuadTri = 378,
     tText2D = 379,
     tText3D = 380,
     tInterpolationScheme = 381,
     tTime = 382,
     tCombine = 383,
     tBSpline = 384,
     tBezier = 385,
     tNurbs = 386,
     tNurbsOrder = 387,
     tNurbsKnots = 388,
     tColor = 389,
     tColorTable = 390,
     tFor = 391,
     tIn = 392,
     tEndFor = 393,
     tIf = 394,
     tEndIf = 395,
     tExit = 396,
     tAbort = 397,
     tField = 398,
     tReturn = 399,
     tCall = 400,
     tMacro = 401,
     tShow = 402,
     tHide = 403,
     tGetValue = 404,
     tGetEnv = 405,
     tGetString = 406,
     tGetNumber = 407,
     tHomology = 408,
     tCohomology = 409,
     tBetti = 410,
     tSetOrder = 411,
     tExists = 412,
     tFileExists = 413,
     tGMSH_MAJOR_VERSION = 414,
     tGMSH_MINOR_VERSION = 415,
     tGMSH_PATCH_VERSION = 416,
     tGmshExecutableName = 417,
     tSetPartition = 418,
     tAFFECTDIVIDE = 419,
     tAFFECTTIMES = 420,
     tAFFECTMINUS = 421,
     tAFFECTPLUS = 422,
     tOR = 423,
     tAND = 424,
     tNOTEQUAL = 425,
     tEQUAL = 426,
     tGREATEROREQUAL = 427,
     tLESSOREQUAL = 428,
     UNARYPREC = 429,
     tMINUSMINUS = 430,
     tPLUSPLUS = 431
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
#line 403 "Gmsh.tab.cpp"
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
#line 431 "Gmsh.tab.cpp"

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
#define YYLAST   9360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  493
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1743

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   431

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   182,     2,   192,     2,   181,     2,     2,
     187,   188,   179,   177,   193,   178,   191,   180,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     173,     2,   174,   168,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   189,     2,   190,   186,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   194,     2,   195,   196,     2,     2,     2,
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
     165,   166,   167,   169,   170,   171,   172,   175,   176,   183,
     184,   185
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
     335,   345,   355,   359,   366,   373,   378,   385,   395,   402,
     412,   418,   427,   436,   448,   455,   465,   471,   479,   489,
     499,   511,   519,   529,   539,   540,   542,   543,   547,   553,
     554,   564,   570,   571,   581,   582,   586,   590,   596,   597,
     600,   604,   610,   614,   615,   618,   622,   626,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   649,   655,   656,
     659,   667,   676,   683,   691,   696,   704,   713,   722,   730,
     738,   750,   759,   768,   777,   786,   796,   800,   805,   816,
     824,   832,   841,   850,   863,   872,   881,   889,   898,   907,
     913,   925,   931,   941,   951,   956,   966,   976,   978,   980,
     981,   984,   991,   998,  1005,  1012,  1021,  1032,  1047,  1064,
    1077,  1086,  1095,  1102,  1117,  1122,  1129,  1136,  1140,  1145,
    1151,  1158,  1164,  1168,  1172,  1177,  1183,  1188,  1194,  1198,
    1204,  1212,  1220,  1224,  1232,  1236,  1239,  1242,  1245,  1248,
    1251,  1267,  1270,  1273,  1276,  1279,  1282,  1299,  1303,  1310,
    1319,  1328,  1339,  1341,  1344,  1346,  1350,  1355,  1357,  1363,
    1375,  1389,  1390,  1398,  1399,  1413,  1414,  1430,  1431,  1438,
    1447,  1456,  1465,  1478,  1491,  1504,  1519,  1534,  1549,  1550,
    1563,  1564,  1577,  1578,  1591,  1592,  1609,  1610,  1627,  1628,
    1645,  1646,  1665,  1666,  1685,  1686,  1705,  1707,  1710,  1716,
    1724,  1734,  1737,  1740,  1743,  1747,  1750,  1754,  1757,  1761,
    1764,  1768,  1778,  1785,  1786,  1790,  1791,  1793,  1794,  1797,
    1798,  1801,  1802,  1805,  1813,  1820,  1829,  1835,  1839,  1847,
    1853,  1858,  1865,  1872,  1886,  1897,  1908,  1919,  1930,  1941,
    1946,  1951,  1956,  1961,  1966,  1969,  1973,  1980,  1982,  1984,
    1986,  1989,  1995,  2003,  2014,  2016,  2020,  2023,  2026,  2029,
    2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,  2065,  2069,
    2073,  2077,  2081,  2085,  2091,  2096,  2101,  2106,  2111,  2116,
    2121,  2126,  2131,  2136,  2141,  2148,  2153,  2158,  2163,  2168,
    2173,  2178,  2183,  2190,  2197,  2204,  2209,  2211,  2213,  2215,
    2217,  2219,  2221,  2223,  2225,  2227,  2229,  2230,  2237,  2242,
    2244,  2249,  2254,  2259,  2264,  2269,  2272,  2278,  2284,  2288,
    2295,  2300,  2308,  2315,  2322,  2329,  2336,  2341,  2343,  2346,
    2349,  2353,  2357,  2369,  2379,  2387,  2395,  2397,  2401,  2403,
    2405,  2408,  2412,  2417,  2423,  2425,  2427,  2430,  2434,  2438,
    2444,  2449,  2452,  2455,  2458,  2461,  2465,  2469,  2473,  2477,
    2483,  2489,  2495,  2501,  2518,  2535,  2552,  2569,  2571,  2573,
    2577,  2581,  2586,  2593,  2600,  2602,  2604,  2608,  2612,  2622,
    2630,  2632,  2638,  2642,  2649,  2651,  2655,  2657,  2659,  2663,
    2670,  2672,  2674,  2676,  2678,  2683,  2690,  2695,  2700,  2705,
    2710,  2719,  2724,  2733,  2738,  2745,  2750,  2751,  2758,  2760,
    2764,  2770,  2776,  2778
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     198,     0,    -1,   199,    -1,     1,     6,    -1,    -1,   199,
     200,    -1,   203,    -1,   202,    -1,   223,    -1,   240,    -1,
     241,    -1,   245,    -1,   246,    -1,   247,    -1,   248,    -1,
     251,    -1,   272,    -1,   273,    -1,   250,    -1,   249,    -1,
     244,    -1,   275,    -1,   174,    -1,   174,   174,    -1,    37,
     187,   289,   188,     6,    -1,    38,   187,   289,   188,     6,
      -1,    37,   187,   289,   188,   201,   289,     6,    -1,    37,
     187,   289,   193,   285,   188,     6,    -1,    38,   187,   289,
     193,   285,   188,     6,    -1,    37,   187,   289,   193,   285,
     188,   201,   289,     6,    -1,     4,   289,   194,   204,   195,
       6,    -1,   115,     4,   189,   276,   190,     6,    -1,   116,
       4,   189,   276,   190,     6,    -1,   117,     4,   189,   276,
     193,   276,   190,     6,    -1,    -1,   204,   207,    -1,   204,
     211,    -1,   204,   214,    -1,   204,   216,    -1,   204,   217,
      -1,   276,    -1,   205,   193,   276,    -1,   276,    -1,   206,
     193,   276,    -1,    -1,    -1,     4,   208,   187,   205,   188,
     209,   194,   206,   195,     6,    -1,   289,    -1,   210,   193,
     289,    -1,    -1,   124,   187,   276,   193,   276,   193,   276,
     188,   212,   194,   210,   195,     6,    -1,   289,    -1,   213,
     193,   289,    -1,    -1,   125,   187,   276,   193,   276,   193,
     276,   193,   276,   188,   215,   194,   213,   195,     6,    -1,
     126,   194,   281,   195,   194,   281,   195,     6,    -1,   126,
     194,   281,   195,   194,   281,   195,   194,   281,   195,   194,
     281,   195,     6,    -1,    -1,   127,   218,   194,   206,   195,
       6,    -1,     7,    -1,   167,    -1,   166,    -1,   165,    -1,
     164,    -1,   185,    -1,   184,    -1,   187,    -1,   189,    -1,
     188,    -1,   190,    -1,    65,   189,   225,   190,     6,    -1,
      66,   189,   228,   190,     6,    -1,    69,   221,   290,   193,
     276,   222,     6,    -1,    70,   221,   294,   193,   290,   222,
       6,    -1,   294,   219,   282,     6,    -1,     4,   189,   190,
     219,   282,     6,    -1,   293,   189,   190,   219,   282,     6,
      -1,     4,   189,   276,   190,   219,   276,     6,    -1,     4,
     187,   276,   188,   219,   276,     6,    -1,   293,   189,   276,
     190,   219,   276,     6,    -1,     4,   221,   194,   285,   195,
     222,   219,   282,     6,    -1,   293,   221,   194,   285,   195,
     222,   219,   282,     6,    -1,   294,   220,     6,    -1,     4,
     189,   276,   190,   220,     6,    -1,   293,   189,   276,   190,
     220,     6,    -1,   294,     7,   290,     6,    -1,     4,   191,
       4,     7,   290,     6,    -1,     4,   189,   276,   190,   191,
       4,     7,   290,     6,    -1,     4,   191,     4,   219,   276,
       6,    -1,     4,   189,   276,   190,   191,     4,   219,   276,
       6,    -1,     4,   191,     4,   220,     6,    -1,     4,   189,
     276,   190,   191,     4,   220,     6,    -1,     4,   191,   134,
     191,     4,     7,   286,     6,    -1,     4,   189,   276,   190,
     191,   134,   191,     4,     7,   286,     6,    -1,     4,   191,
     135,     7,   287,     6,    -1,     4,   189,   276,   190,   191,
     135,     7,   287,     6,    -1,     4,   143,     7,   276,     6,
      -1,   143,   189,   276,   190,     7,     4,     6,    -1,   143,
     189,   276,   190,   191,     4,     7,   276,     6,    -1,   143,
     189,   276,   190,   191,     4,     7,   290,     6,    -1,   143,
     189,   276,   190,   191,     4,     7,   194,   285,   195,     6,
      -1,   143,   189,   276,   190,   191,     4,     6,    -1,    95,
     187,     4,   188,   191,     4,     7,   276,     6,    -1,    95,
     187,     4,   188,   191,     4,     7,   290,     6,    -1,    -1,
     193,    -1,    -1,   225,   224,   294,    -1,   225,   224,   294,
       7,   276,    -1,    -1,   225,   224,   294,     7,   194,   276,
     226,   230,   195,    -1,   225,   224,   294,     7,   290,    -1,
      -1,   225,   224,   294,     7,   194,   290,   227,   232,   195,
      -1,    -1,   228,   224,   289,    -1,   276,     7,   290,    -1,
     229,   193,   276,     7,   290,    -1,    -1,   230,   231,    -1,
     193,     4,   282,    -1,   193,     4,   194,   229,   195,    -1,
     193,     4,   290,    -1,    -1,   232,   233,    -1,   193,     4,
     276,    -1,   193,     4,   290,    -1,   193,     4,   194,   292,
     195,    -1,   276,    -1,   290,    -1,   276,    -1,   290,    -1,
     276,    -1,   290,    -1,   276,    -1,   290,    -1,    -1,   137,
      75,   194,   276,   195,    -1,    -1,    87,   279,    -1,    71,
     187,   276,   188,     7,   279,     6,    -1,    91,    71,   187,
     234,   188,   219,   282,     6,    -1,    80,    81,   282,     7,
     276,     6,    -1,    74,   187,   276,   188,     7,   282,     6,
      -1,    96,    74,   282,     6,    -1,    78,   187,   276,   188,
       7,   282,     6,    -1,    72,   187,   276,   188,     7,   282,
     239,     6,    -1,    73,   187,   276,   188,     7,   282,   239,
       6,    -1,   129,   187,   276,   188,     7,   282,     6,    -1,
     130,   187,   276,   188,     7,   282,     6,    -1,   131,   187,
     276,   188,     7,   282,   133,   282,   132,   276,     6,    -1,
      74,     4,   187,   276,   188,     7,   282,     6,    -1,    92,
      74,   187,   276,   188,     7,   282,     6,    -1,    91,    74,
     187,   235,   188,   219,   282,     6,    -1,    87,    77,   187,
     276,   188,     7,   282,     6,    -1,    88,    77,   187,   276,
     188,     7,   282,   238,     6,    -1,    12,    13,     6,    -1,
      13,    77,   276,     6,    -1,    82,    77,   187,   276,   188,
       7,     5,     5,     5,     6,    -1,    75,   187,   276,   188,
       7,   282,     6,    -1,    76,   187,   276,   188,     7,   282,
       6,    -1,    77,     4,   187,   276,   188,     7,   282,     6,
      -1,    92,    77,   187,   276,   188,     7,   282,     6,    -1,
      92,    77,   187,   276,   188,     7,   282,     4,   194,   281,
     195,     6,    -1,    91,    77,   187,   236,   188,   219,   282,
       6,    -1,    90,    79,   187,   276,   188,     7,   282,     6,
      -1,    79,   187,   276,   188,     7,   282,     6,    -1,    92,
      79,   187,   276,   188,     7,   282,     6,    -1,    91,    79,
     187,   237,   188,   219,   282,     6,    -1,    99,   279,   194,
     242,   195,    -1,    98,   194,   279,   193,   279,   193,   276,
     195,   194,   242,   195,    -1,   100,   279,   194,   242,   195,
      -1,   101,   194,   279,   193,   276,   195,   194,   242,   195,
      -1,   101,   194,   279,   193,   279,   195,   194,   242,   195,
      -1,     4,   194,   242,   195,    -1,   109,    74,   194,   285,
     195,    77,   194,   276,   195,    -1,   106,    74,   187,   276,
     188,   194,   285,   195,     6,    -1,   243,    -1,   241,    -1,
      -1,   243,   240,    -1,   243,    71,   194,   285,   195,     6,
      -1,   243,    74,   194,   285,   195,     6,    -1,   243,    77,
     194,   285,   195,     6,    -1,   243,    79,   194,   285,   195,
       6,    -1,   103,    87,   187,   276,   188,     7,   282,     6,
      -1,   103,    71,   187,   276,   188,     7,   194,   281,   195,
       6,    -1,   103,    87,   187,   276,   188,     7,   194,   279,
     193,   279,   193,   285,   195,     6,    -1,   103,    87,   187,
     276,   188,     7,   194,   279,   193,   279,   193,   279,   193,
     285,   195,     6,    -1,   103,    75,   187,   276,   188,     7,
     194,   279,   193,   285,   195,     6,    -1,   103,     4,   187,
     276,   188,     7,   282,     6,    -1,   103,     4,   187,   276,
     188,     7,     5,     6,    -1,   103,     4,   194,   276,   195,
       6,    -1,   103,     4,   187,   276,   188,     7,   194,   279,
     193,   279,   193,   285,   195,     6,    -1,   107,   194,   243,
     195,    -1,   107,   143,   189,   276,   190,     6,    -1,   107,
       4,   189,   276,   190,     6,    -1,   107,     4,     6,    -1,
     107,     4,     4,     6,    -1,   134,   286,   194,   243,   195,
      -1,    97,   134,   286,   194,   243,   195,    -1,   163,   276,
     194,   243,   195,    -1,   147,     5,     6,    -1,   148,     5,
       6,    -1,   147,   194,   243,   195,    -1,    97,   147,   194,
     243,   195,    -1,   148,   194,   243,   195,    -1,    97,   148,
     194,   243,   195,    -1,     4,   290,     6,    -1,    58,   187,
     292,   188,     6,    -1,     4,     4,   189,   276,   190,   289,
       6,    -1,     4,     4,     4,   189,   276,   190,     6,    -1,
       4,   276,     6,    -1,    95,   187,     4,   188,   191,     4,
       6,    -1,   128,     4,     6,    -1,   141,     6,    -1,   142,
       6,    -1,    55,     6,    -1,    56,     6,    -1,    50,     6,
      -1,    50,   194,   276,   193,   276,   193,   276,   193,   276,
     193,   276,   193,   276,   195,     6,    -1,    51,     6,    -1,
      52,     6,    -1,    62,     6,    -1,    63,     6,    -1,    84,
       6,    -1,    85,   194,   285,   195,   194,   285,   195,   194,
     281,   195,   194,   276,   193,   276,   195,     6,    -1,   156,
     276,     6,    -1,   136,   187,   276,     8,   276,   188,    -1,
     136,   187,   276,     8,   276,     8,   276,   188,    -1,   136,
       4,   137,   194,   276,     8,   276,   195,    -1,   136,     4,
     137,   194,   276,     8,   276,     8,   276,   195,    -1,   138,
      -1,   146,     4,    -1,   144,    -1,   145,   294,     6,    -1,
     139,   187,   276,   188,    -1,   140,    -1,   102,   279,   194,
     243,   195,    -1,   102,   194,   279,   193,   279,   193,   276,
     195,   194,   243,   195,    -1,   102,   194,   279,   193,   279,
     193,   279,   193,   276,   195,   194,   243,   195,    -1,    -1,
     102,   279,   194,   243,   252,   265,   195,    -1,    -1,   102,
     194,   279,   193,   279,   193,   276,   195,   194,   243,   253,
     265,   195,    -1,    -1,   102,   194,   279,   193,   279,   193,
     279,   193,   276,   195,   194,   243,   254,   265,   195,    -1,
      -1,   102,   194,   243,   255,   265,   195,    -1,   102,    71,
     194,   276,   193,   279,   195,     6,    -1,   102,    74,   194,
     276,   193,   279,   195,     6,    -1,   102,    77,   194,   276,
     193,   279,   195,     6,    -1,   102,    71,   194,   276,   193,
     279,   193,   279,   193,   276,   195,     6,    -1,   102,    74,
     194,   276,   193,   279,   193,   279,   193,   276,   195,     6,
      -1,   102,    77,   194,   276,   193,   279,   193,   279,   193,
     276,   195,     6,    -1,   102,    71,   194,   276,   193,   279,
     193,   279,   193,   279,   193,   276,   195,     6,    -1,   102,
      74,   194,   276,   193,   279,   193,   279,   193,   279,   193,
     276,   195,     6,    -1,   102,    77,   194,   276,   193,   279,
     193,   279,   193,   279,   193,   276,   195,     6,    -1,    -1,
     102,    71,   194,   276,   193,   279,   195,   256,   194,   265,
     195,     6,    -1,    -1,   102,    74,   194,   276,   193,   279,
     195,   257,   194,   265,   195,     6,    -1,    -1,   102,    77,
     194,   276,   193,   279,   195,   258,   194,   265,   195,     6,
      -1,    -1,   102,    71,   194,   276,   193,   279,   193,   279,
     193,   276,   195,   259,   194,   265,   195,     6,    -1,    -1,
     102,    74,   194,   276,   193,   279,   193,   279,   193,   276,
     195,   260,   194,   265,   195,     6,    -1,    -1,   102,    77,
     194,   276,   193,   279,   193,   279,   193,   276,   195,   261,
     194,   265,   195,     6,    -1,    -1,   102,    71,   194,   276,
     193,   279,   193,   279,   193,   279,   193,   276,   195,   262,
     194,   265,   195,     6,    -1,    -1,   102,    74,   194,   276,
     193,   279,   193,   279,   193,   279,   193,   276,   195,   263,
     194,   265,   195,     6,    -1,    -1,   102,    77,   194,   276,
     193,   279,   193,   279,   193,   279,   193,   276,   195,   264,
     194,   265,   195,     6,    -1,   266,    -1,   265,   266,    -1,
     112,   194,   276,   195,     6,    -1,   112,   194,   282,   193,
     282,   195,     6,    -1,   112,   194,   282,   193,   282,   193,
     282,   195,     6,    -1,   113,     6,    -1,   104,     6,    -1,
     120,     6,    -1,   120,   122,     6,    -1,   121,     6,    -1,
     121,   122,     6,    -1,   118,     6,    -1,   118,   122,     6,
      -1,   119,     6,    -1,   119,   122,     6,    -1,   114,   187,
     276,   188,     7,   282,    94,   276,     6,    -1,    94,     4,
     189,   276,   190,     6,    -1,    -1,    94,     4,   276,    -1,
      -1,     4,    -1,    -1,     7,   282,    -1,    -1,     7,   276,
      -1,    -1,    94,   282,    -1,    89,    74,   283,     7,   276,
     267,     6,    -1,    89,    77,   283,   269,   268,     6,    -1,
      83,    77,   194,   276,   195,     7,   282,     6,    -1,    89,
      79,   283,   269,     6,    -1,   123,   283,     6,    -1,   110,
      77,   194,   285,   195,   276,     6,    -1,   104,    77,   283,
     270,     6,    -1,   104,    79,   283,     6,    -1,   105,    77,
     282,     7,   276,     6,    -1,    93,    74,   282,     7,   282,
       6,    -1,    93,    77,   276,   194,   285,   195,     7,   276,
     194,   285,   195,   271,     6,    -1,    71,   194,   285,   195,
     137,    77,   194,   276,   195,     6,    -1,    74,   194,   285,
     195,   137,    77,   194,   276,   195,     6,    -1,    71,   194,
     285,   195,   137,    79,   194,   276,   195,     6,    -1,    74,
     194,   285,   195,   137,    79,   194,   276,   195,     6,    -1,
      77,   194,   285,   195,   137,    79,   194,   276,   195,     6,
      -1,   111,    77,   283,     6,    -1,   111,    74,   283,     6,
      -1,    86,    71,   283,     6,    -1,    86,    74,   283,     6,
      -1,    86,    77,   283,     6,    -1,   108,     6,    -1,   108,
       4,     6,    -1,   108,    71,   194,   285,   195,     6,    -1,
     153,    -1,   154,    -1,   155,    -1,   274,     6,    -1,   274,
     194,   282,   195,     6,    -1,   274,   194,   282,   193,   282,
     195,     6,    -1,   274,   187,   282,   188,   194,   282,   193,
     282,   195,     6,    -1,   277,    -1,   187,   276,   188,    -1,
     178,   276,    -1,   177,   276,    -1,   182,   276,    -1,   276,
     178,   276,    -1,   276,   177,   276,    -1,   276,   179,   276,
      -1,   276,   180,   276,    -1,   276,   181,   276,    -1,   276,
     186,   276,    -1,   276,   173,   276,    -1,   276,   174,   276,
      -1,   276,   176,   276,    -1,   276,   175,   276,    -1,   276,
     172,   276,    -1,   276,   171,   276,    -1,   276,   170,   276,
      -1,   276,   169,   276,    -1,   276,   168,   276,     8,   276,
      -1,    14,   221,   276,   222,    -1,    15,   221,   276,   222,
      -1,    16,   221,   276,   222,    -1,    17,   221,   276,   222,
      -1,    18,   221,   276,   222,    -1,    19,   221,   276,   222,
      -1,    20,   221,   276,   222,    -1,    21,   221,   276,   222,
      -1,    22,   221,   276,   222,    -1,    24,   221,   276,   222,
      -1,    25,   221,   276,   193,   276,   222,    -1,    26,   221,
     276,   222,    -1,    27,   221,   276,   222,    -1,    28,   221,
     276,   222,    -1,    29,   221,   276,   222,    -1,    30,   221,
     276,   222,    -1,    31,   221,   276,   222,    -1,    32,   221,
     276,   222,    -1,    33,   221,   276,   193,   276,   222,    -1,
      34,   221,   276,   193,   276,   222,    -1,    35,   221,   276,
     193,   276,   222,    -1,    23,   221,   276,   222,    -1,     3,
      -1,     9,    -1,    10,    -1,    11,    -1,   159,    -1,   160,
      -1,   161,    -1,    59,    -1,    60,    -1,    61,    -1,    -1,
      67,   221,   276,   278,   230,   222,    -1,   152,   221,   289,
     222,    -1,   294,    -1,     4,   189,   276,   190,    -1,   293,
     189,   276,   190,    -1,   157,   187,   294,   188,    -1,   158,
     187,   290,   188,    -1,   192,   294,   189,   190,    -1,   294,
     220,    -1,     4,   189,   276,   190,   220,    -1,   293,   189,
     276,   190,   220,    -1,     4,   191,     4,    -1,     4,   189,
     276,   190,   191,     4,    -1,     4,   191,     4,   220,    -1,
       4,   189,   276,   190,   191,     4,   220,    -1,   149,   187,
     289,   193,   276,   188,    -1,    45,   187,   282,   193,   282,
     188,    -1,    46,   187,   289,   193,   289,   188,    -1,    47,
     187,   289,   193,   289,   188,    -1,    49,   187,   292,   188,
      -1,   280,    -1,   178,   279,    -1,   177,   279,    -1,   279,
     178,   279,    -1,   279,   177,   279,    -1,   194,   276,   193,
     276,   193,   276,   193,   276,   193,   276,   195,    -1,   194,
     276,   193,   276,   193,   276,   193,   276,   195,    -1,   194,
     276,   193,   276,   193,   276,   195,    -1,   187,   276,   193,
     276,   193,   276,   188,    -1,   282,    -1,   281,   193,   282,
      -1,   276,    -1,   284,    -1,   194,   195,    -1,   194,   285,
     195,    -1,   178,   194,   285,   195,    -1,   276,   179,   194,
     285,   195,    -1,   282,    -1,     5,    -1,   178,   284,    -1,
     276,   179,   284,    -1,   276,     8,   276,    -1,   276,     8,
     276,     8,   276,    -1,    71,   194,   276,   195,    -1,    71,
       5,    -1,    74,     5,    -1,    77,     5,    -1,    79,     5,
      -1,    91,    71,     5,    -1,    91,    74,     5,    -1,    91,
      77,     5,    -1,    91,    79,     5,    -1,    91,    71,   194,
     285,   195,    -1,    91,    74,   194,   285,   195,    -1,    91,
      77,   194,   285,   195,    -1,    91,    79,   194,   285,   195,
      -1,    71,   137,    50,   194,   276,   193,   276,   193,   276,
     193,   276,   193,   276,   193,   276,   195,    -1,    74,   137,
      50,   194,   276,   193,   276,   193,   276,   193,   276,   193,
     276,   193,   276,   195,    -1,    77,   137,    50,   194,   276,
     193,   276,   193,   276,   193,   276,   193,   276,   193,   276,
     195,    -1,    79,   137,    50,   194,   276,   193,   276,   193,
     276,   193,   276,   193,   276,   193,   276,   195,    -1,   241,
      -1,   251,    -1,     4,   221,   222,    -1,   293,   221,   222,
      -1,    36,   189,   294,   190,    -1,     4,   221,   194,   285,
     195,   222,    -1,   293,   221,   194,   285,   195,   222,    -1,
     276,    -1,   284,    -1,   285,   193,   276,    -1,   285,   193,
     284,    -1,   194,   276,   193,   276,   193,   276,   193,   276,
     195,    -1,   194,   276,   193,   276,   193,   276,   195,    -1,
       4,    -1,     4,   191,   134,   191,     4,    -1,   194,   288,
     195,    -1,     4,   189,   276,   190,   191,   135,    -1,   286,
      -1,   288,   193,   286,    -1,   290,    -1,   294,    -1,     4,
     191,     4,    -1,     4,   189,   276,   190,   191,     4,    -1,
       5,    -1,    53,    -1,   162,    -1,    57,    -1,   150,   187,
     289,   188,    -1,   151,   187,   289,   193,   289,   188,    -1,
     151,   187,   289,   188,    -1,    41,   221,   292,   222,    -1,
      42,   187,   289,   188,    -1,    43,   187,   289,   188,    -1,
      44,   187,   289,   193,   289,   193,   289,   188,    -1,    39,
     221,   292,   222,    -1,    48,   221,   276,   193,   290,   193,
     290,   222,    -1,    40,   221,   289,   222,    -1,    40,   221,
     289,   193,   285,   222,    -1,    54,   221,   289,   222,    -1,
      -1,    68,   221,   290,   291,   232,   222,    -1,   289,    -1,
     292,   193,   289,    -1,     4,   196,   194,   276,   195,    -1,
     293,   196,   194,   276,   195,    -1,     4,    -1,   293,    -1
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
     658,   659,   660,   665,   671,   732,   761,   790,   795,   800,
     805,   812,   819,   834,   839,   844,   853,   859,   868,   886,
     904,   913,   925,   930,   938,   958,   981,   992,  1000,  1022,
    1045,  1071,  1092,  1104,  1118,  1118,  1120,  1122,  1131,  1141,
    1140,  1152,  1162,  1161,  1175,  1177,  1185,  1191,  1198,  1199,
    1203,  1214,  1229,  1239,  1240,  1245,  1253,  1262,  1280,  1284,
    1293,  1297,  1306,  1310,  1319,  1323,  1333,  1336,  1349,  1352,
    1362,  1385,  1417,  1440,  1458,  1479,  1497,  1527,  1557,  1575,
    1593,  1620,  1638,  1656,  1691,  1709,  1748,  1754,  1760,  1767,
    1792,  1817,  1834,  1853,  1887,  1923,  1941,  1958,  1974,  2011,
    2016,  2021,  2026,  2031,  2036,  2059,  2065,  2076,  2077,  2082,
    2085,  2089,  2112,  2135,  2158,  2186,  2207,  2233,  2254,  2276,
    2296,  2408,  2427,  2465,  2574,  2583,  2589,  2604,  2632,  2649,
    2658,  2672,  2686,  2692,  2698,  2707,  2716,  2725,  2739,  2795,
    2813,  2830,  2845,  2864,  2876,  2900,  2904,  2909,  2916,  2921,
    2927,  2932,  2938,  2946,  2950,  2954,  2959,  3014,  3027,  3044,
    3061,  3082,  3103,  3138,  3146,  3152,  3159,  3163,  3172,  3180,
    3188,  3197,  3196,  3211,  3210,  3225,  3224,  3239,  3238,  3252,
    3259,  3266,  3273,  3280,  3287,  3294,  3301,  3308,  3316,  3315,
    3329,  3328,  3342,  3341,  3355,  3354,  3368,  3367,  3381,  3380,
    3394,  3393,  3407,  3406,  3420,  3419,  3436,  3439,  3445,  3457,
    3477,  3501,  3505,  3509,  3513,  3517,  3523,  3529,  3533,  3537,
    3541,  3545,  3564,  3577,  3580,  3596,  3599,  3616,  3619,  3625,
    3628,  3635,  3638,  3645,  3701,  3771,  3776,  3843,  3879,  3887,
    3930,  3969,  3989,  4016,  4065,  4093,  4121,  4125,  4129,  4157,
    4196,  4235,  4256,  4277,  4304,  4308,  4318,  4353,  4354,  4355,
    4359,  4365,  4377,  4395,  4423,  4424,  4425,  4426,  4427,  4428,
    4429,  4430,  4431,  4438,  4439,  4440,  4441,  4442,  4443,  4444,
    4445,  4446,  4447,  4448,  4449,  4450,  4451,  4452,  4453,  4454,
    4455,  4456,  4457,  4458,  4459,  4460,  4461,  4462,  4463,  4464,
    4465,  4466,  4467,  4468,  4469,  4470,  4479,  4480,  4481,  4482,
    4483,  4484,  4485,  4486,  4487,  4488,  4493,  4492,  4500,  4505,
    4522,  4540,  4558,  4563,  4569,  4581,  4598,  4616,  4637,  4642,
    4647,  4657,  4667,  4672,  4683,  4692,  4697,  4724,  4728,  4732,
    4736,  4740,  4747,  4751,  4755,  4759,  4766,  4771,  4778,  4783,
    4787,  4792,  4796,  4804,  4815,  4819,  4831,  4839,  4847,  4854,
    4864,  4893,  4897,  4901,  4905,  4909,  4913,  4917,  4921,  4925,
    4954,  4983,  5012,  5041,  5054,  5067,  5080,  5093,  5103,  5113,
    5125,  5137,  5149,  5167,  5188,  5193,  5197,  5201,  5213,  5217,
    5229,  5236,  5246,  5250,  5265,  5270,  5277,  5281,  5294,  5302,
    5313,  5317,  5325,  5331,  5337,  5345,  5353,  5360,  5375,  5389,
    5403,  5415,  5431,  5442,  5446,  5465,  5473,  5472,  5485,  5490,
    5496,  5505,  5518,  5521
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
  "tSetChanged", "tToday", "tFixRelativePath", "tSyncModel", "tNewModel",
  "tOnelabAction", "tOnelabRun", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineString",
  "tSetNumber", "tSetString", "tPoint", "tCircle", "tEllipse", "tLine",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     415,   416,   417,   418,   419,   420,   421,   422,    63,   423,
     424,   425,   426,    60,    62,   427,   428,    43,    45,    42,
      47,    37,    33,   429,   430,   431,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   197,   198,   198,   199,   199,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   201,   201,   202,   202,   202,   202,   202,   202,
     203,   203,   203,   203,   204,   204,   204,   204,   204,   204,
     205,   205,   206,   206,   208,   209,   207,   210,   210,   212,
     211,   213,   213,   215,   214,   216,   216,   218,   217,   219,
     219,   219,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   225,   225,   225,   226,
     225,   225,   227,   225,   228,   228,   229,   229,   230,   230,
     231,   231,   231,   232,   232,   233,   233,   233,   234,   234,
     235,   235,   236,   236,   237,   237,   238,   238,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   241,
     241,   241,   241,   241,   241,   241,   241,   242,   242,   243,
     243,   243,   243,   243,   243,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   245,   245,   245,   245,   245,   246,
     246,   247,   248,   248,   248,   248,   248,   248,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   251,   251,
     251,   252,   251,   253,   251,   254,   251,   255,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   256,   251,
     257,   251,   258,   251,   259,   251,   260,   251,   261,   251,
     262,   251,   263,   251,   264,   251,   265,   265,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   267,   267,   268,   268,   269,   269,   270,
     270,   271,   271,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   273,   273,   273,   274,   274,   274,
     275,   275,   275,   275,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   278,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   279,   279,   279,
     279,   279,   280,   280,   280,   280,   281,   281,   282,   282,
     282,   282,   282,   282,   283,   283,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   285,   285,   285,   285,   286,   286,
     286,   286,   287,   287,   288,   288,   289,   289,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   291,   290,   292,   292,
     293,   293,   294,   294
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
       9,     9,     3,     6,     6,     4,     6,     9,     6,     9,
       5,     8,     8,    11,     6,     9,     5,     7,     9,     9,
      11,     7,     9,     9,     0,     1,     0,     3,     5,     0,
       9,     5,     0,     9,     0,     3,     3,     5,     0,     2,
       3,     5,     3,     0,     2,     3,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     2,
       7,     8,     6,     7,     4,     7,     8,     8,     7,     7,
      11,     8,     8,     8,     8,     9,     3,     4,    10,     7,
       7,     8,     8,    12,     8,     8,     7,     8,     8,     5,
      11,     5,     9,     9,     4,     9,     9,     1,     1,     0,
       2,     6,     6,     6,     6,     8,    10,    14,    16,    12,
       8,     8,     6,    14,     4,     6,     6,     3,     4,     5,
       6,     5,     3,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     2,     2,    16,     3,     6,     8,
       8,    10,     1,     2,     1,     3,     4,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     2,     3,     2,     3,     2,     3,     2,
       3,     9,     6,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     7,     5,
       4,     6,     6,    13,    10,    10,    10,    10,    10,     4,
       4,     4,     4,     4,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     4,     1,
       4,     4,     4,     4,     4,     2,     5,     5,     3,     6,
       4,     7,     6,     6,     6,     6,     4,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     1,     2,     3,     3,     5,
       4,     2,     2,     2,     2,     3,     3,     3,     3,     5,
       5,     5,     5,    16,    16,    16,    16,     1,     1,     3,
       3,     4,     6,     6,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     3,     6,
       1,     1,     1,     1,     4,     6,     4,     4,     4,     4,
       8,     4,     8,     4,     6,     4,     0,     6,     1,     3,
       5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   492,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,     0,   237,     0,     0,     0,   234,     0,
       0,     0,     0,   327,   328,   329,     0,     0,     5,     7,
       6,     8,     9,    10,    20,    11,    12,    13,    14,    19,
      18,    15,    16,    17,     0,    21,   493,     0,   376,   492,
     470,   377,   378,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   471,     0,   473,
     383,   384,   385,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   381,   382,   472,     0,     0,     0,    66,
      67,     0,     0,   179,     0,     0,     0,   334,     0,   466,
     493,   389,     0,     0,     0,     0,   219,     0,   221,   222,
     217,   218,     0,   223,   224,   106,   114,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   492,   425,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   447,   448,
     418,   424,     0,   419,   493,   389,     0,     0,     0,     0,
     460,     0,     0,     0,     0,     0,   215,   216,     0,   492,
     493,     0,   233,     0,   179,     0,   179,   492,     0,     0,
     330,     0,     0,    67,     0,     0,    59,    63,    62,    61,
      60,    65,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   337,   336,   338,     0,     0,     0,     0,     0,     0,
       0,     0,   178,     0,   177,     0,     0,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,   208,     0,   395,   156,     0,   492,
       0,   466,   467,     0,     0,   488,     0,   104,   104,     0,
       0,     0,     0,   454,   455,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,   297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   179,     0,   409,   408,     0,     0,     0,
       0,   179,   179,     0,     0,     0,     0,     0,     0,     0,
     247,     0,   179,     0,     0,     0,     0,     0,   299,     0,
       0,     0,     0,   197,     0,     0,     0,   325,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
     431,     0,     0,   432,     0,   433,     0,   434,     0,     0,
       0,     0,     0,     0,   336,   426,     0,   420,     0,     0,
       0,   307,    67,     0,   214,     0,     0,     0,     0,     0,
     179,     0,     0,     0,     0,   235,   202,     0,   203,     0,
       0,   227,   179,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   386,
     486,     0,     0,     0,     0,     0,     0,     0,   335,    59,
       0,     0,    59,     0,     0,     0,     0,     0,   174,     0,
       0,     0,     0,   180,     0,     0,     0,   352,   351,   350,
     349,   345,   346,   348,   347,   340,   339,   341,   342,   343,
     344,     0,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
     322,   323,     0,     0,     0,     0,   295,     0,     0,     0,
     128,   129,     0,   130,   131,     0,   132,   133,     0,   134,
     135,     0,     0,     0,     0,     0,     0,   144,   179,     0,
       0,     0,     0,     0,   411,   410,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,     0,
       0,     0,     0,   310,     0,     0,   198,     0,     0,   194,
       0,     0,     0,   320,   319,     0,     0,     0,     0,   398,
      68,    69,     0,   449,     0,     0,     0,     0,     0,     0,
     435,     0,   436,     0,   437,     0,   438,     0,     0,   335,
     421,   428,     0,   341,   427,     0,   450,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,   204,   206,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    74,     0,
     390,   400,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   375,   363,     0,   365,   366,   367,   368,   369,   370,
     371,     0,     0,     0,   481,     0,   483,   477,   478,   479,
       0,     0,     0,     0,     0,   406,   485,   118,   123,    96,
       0,   474,   476,     0,   388,   392,   393,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,   394,
       0,     0,     0,     0,   490,     0,     0,    44,     0,     0,
       0,    57,     0,    35,    36,    37,    38,    39,   391,     0,
     468,    24,    22,     0,     0,    25,     0,     0,   209,   489,
      70,   107,    71,   115,     0,     0,     0,   456,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   298,   296,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   207,     0,     0,     0,   169,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,   238,     0,
       0,     0,     0,     0,     0,   300,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   390,     0,   451,
       0,   430,     0,     0,     0,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,     0,     0,   201,     0,     0,   331,     0,     0,     0,
     491,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,    83,    86,    88,     0,
       0,   464,     0,    94,     0,     0,     0,     0,     0,   353,
       0,     0,     0,     0,     0,    30,   397,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,   312,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,   281,     0,   287,     0,   289,     0,   283,
       0,   285,     0,   248,   277,     0,     0,     0,   192,     0,
       0,     0,   311,     0,   196,   195,   326,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,   439,   440,
     441,   442,   429,   423,     0,     0,     0,     0,   461,     0,
       0,     0,   228,     0,     0,     0,     0,    76,     0,    84,
       0,   211,   399,   210,   364,   372,   373,   374,   484,     0,
     403,   404,   405,     0,     0,   387,   119,     0,   487,   124,
     402,   475,    78,    59,     0,     0,     0,     0,    77,     0,
       0,     0,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   416,     0,     0,    26,    27,     0,    28,     0,
       0,   108,   111,    72,    73,   140,     0,     0,     0,     0,
       0,     0,   143,     0,     0,   159,   160,     0,     0,   145,
     166,     0,     0,     0,     0,   136,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,   179,   179,     0,   258,     0,   260,     0,   262,
       0,   418,     0,     0,   288,   290,   284,   286,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,     0,   399,   452,     0,     0,     0,     0,   453,   148,
     149,     0,     0,     0,     0,    97,   101,     0,     0,   332,
      79,     0,   401,     0,     0,     0,     0,     0,     0,    91,
       0,     0,    92,     0,   465,   181,   182,   183,   184,     0,
       0,    40,     0,     0,     0,     0,     0,    42,   469,     0,
       0,   109,   112,     0,     0,   139,   146,   147,   151,     0,
       0,   161,     0,     0,   305,     0,   154,     0,     0,   294,
     165,   141,   153,   164,   168,   152,     0,   162,   167,     0,
       0,     0,     0,   415,     0,   414,     0,     0,     0,   249,
       0,     0,   250,     0,     0,   251,     0,     0,     0,     0,
       0,     0,     0,   191,     0,     0,   190,     0,     0,     0,
     185,     0,     0,    33,     0,     0,     0,     0,     0,     0,
     459,     0,   230,   229,     0,     0,     0,     0,     0,   480,
     482,     0,   120,   122,     0,   125,   126,    87,    89,     0,
      95,     0,    80,    45,     0,     0,     0,   417,     0,     0,
       0,    29,     0,   118,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   102,   103,   179,     0,
     172,   173,     0,     0,     0,     0,     0,     0,     0,   278,
       0,     0,   179,     0,     0,     0,     0,     0,   176,   175,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,    81,     0,   454,     0,     0,   463,     0,    41,     0,
       0,     0,    43,    58,     0,     0,     0,   314,   316,   315,
     317,   318,   158,     0,     0,     0,     0,     0,     0,   413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,     0,   243,     0,     0,   186,     0,     0,     0,
       0,     0,     0,     0,   458,   231,     0,   333,     0,   121,
       0,   127,    93,     0,     0,     0,     0,     0,   110,   113,
       0,     0,     0,   301,   170,     0,   264,     0,     0,   266,
       0,     0,   268,     0,     0,     0,   279,     0,   239,     0,
     179,     0,     0,     0,     0,     0,     0,     0,   150,   100,
       0,   116,     0,    49,     0,    55,     0,     0,     0,   137,
     163,     0,     0,   412,   252,     0,     0,   259,   253,     0,
       0,   261,   254,     0,     0,   263,     0,     0,     0,   245,
       0,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,   313,     0,   270,     0,
     272,     0,   274,   280,   291,   244,   240,     0,     0,     0,
       0,     0,     0,     0,     0,   117,    46,     0,    53,     0,
       0,     0,     0,   255,     0,     0,   256,     0,     0,   257,
       0,     0,   193,     0,   187,     0,     0,     0,     0,     0,
      47,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   265,     0,   267,     0,   269,     0,   188,     0,
       0,     0,     0,    48,    50,     0,    51,     0,     0,     0,
       0,   443,   444,   445,   446,     0,     0,    56,   271,   273,
     275,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,   893,    89,    90,   651,  1340,  1346,
     883,  1060,  1507,  1689,   884,  1640,  1725,   885,  1691,   886,
     887,  1064,   333,   416,   175,   763,    91,   665,   427,  1453,
    1454,   428,  1502,  1036,  1196,  1037,  1199,   699,   702,   705,
     708,  1368,  1239,   633,   288,   393,   394,    94,    95,    96,
      97,    98,    99,   100,   289,   969,  1589,  1657,   733,  1390,
    1393,  1396,  1615,  1619,  1623,  1674,  1677,  1680,   965,   966,
    1098,   930,   696,   742,  1612,   102,   103,   104,   105,   290,
     177,   847,   476,   248,  1221,   291,   292,   293,   538,   302,
     868,  1052,   425,   421,   848,   426,   180,   295
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1286
static const yytype_int16 yypact[] =
{
    6560,    62,    57,  6674, -1286, -1286,  3177,    86,   -40,  -136,
    -110,    53,   103,   129,   156,   160,   -74,   195,   221,   -66,
      67,   107,   107,  -155,   -35,   120,    20,   194,   204,    34,
     213,   223,   183,   239,   344,   430,   258,   458,   431,   438,
     440,   448,   409,   549,    45,   375,   507,   -37,   401,  -103,
    -103,   437,   548,    27,   238,   557,   581,    18,    46,   593,
     594,   292,   683,   690,   694,  4467,   697,   520,   523,   527,
      36,    63, -1286,   533, -1286,   722,   735,   561, -1286,   751,
     773,     9,    16, -1286, -1286, -1286,  6427,  6427, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286,    59, -1286,   -38,    96, -1286,     4,
   -1286, -1286, -1286, -1286,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   582,
     607,   623,   648,   654,   659,   107,   662, -1286,   107, -1286,
   -1286, -1286, -1286,   107,   107,   864,   666,   670,   678,   107,
     679,   685, -1286, -1286, -1286, -1286,  6427,  6427,  6427,  6427,
    6188,    25,   751,     6,   691,   701,   471, -1286,   702,   882,
    -118,   126,   886,  6427,  2014,  2014, -1286,  6427, -1286, -1286,
   -1286, -1286,  2014, -1286, -1286, -1286, -1286, -1286, -1286,  2852,
     751,  6427,  6008,  6427,  6427,   689,  6427,  6008,  6427,  6427,
     714,  6008,  6427,  6427,  4839,   715,   721, -1286,  6008,  4467,
    4467,  4467,   732,   772,  4467,  4467,  4467,   781,   786,   791,
     792,   798,   802,   826,   860,  4839,  6427,   940,  4839,    36,
     769,   778,  -103,  -103,  -103,  6427,  6427,  -152, -1286,    -6,
    -103,   873,   876,   877,  5769,    77,   146,   869,   881,   887,
    4467,  4467,  4839,   888,    60,   896, -1286,  1070, -1286,   883,
     897,   900,  4467,  4467,   907,   916,   917,   -11, -1286,   928,
      40,    30,    31,    38,   599,  5025,  6427,  3638, -1286, -1286,
    3452, -1286,  1114, -1286,   226,   -41,  1115,  6427,  6427,  6427,
     931,  6427,   935,   988,  6427,  6427, -1286, -1286,  6427,   934,
     941,  1125, -1286,  1127, -1286,  1130, -1286,    83,   647,  4461,
   -1286,  4839,  4839,  6242,   948,   949,  2852, -1286, -1286, -1286,
   -1286, -1286, -1286,  4839,  1138,   957,  6427,  1143,  6427,  6427,
    6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,
    6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,
    2014,  2014,  2014,  2014,  2014,  2014,  4839,  2014,  2014,  6427,
    2014,  2014,  6427,  2852,  6427,  2014,  2014,  2014,  2014,   751,
    2852,   962,   962,   962,  4062,   138,  8136,   266,   961,  1149,
     969,   963, -1286,   975,  4305,  6427,  6008, -1286,  6427,  6427,
    6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,  6427,
    6427,  6427,  6427, -1286, -1286,  6427, -1286, -1286,   849,   253,
    -107, -1286, -1286,    -1,  4090, -1286,   296,   371,   390,   971,
     978,  8481,  6008,  3580, -1286,   281,  8502,  8523,  6427,  8544,
     423,  8565,  8586,  6427,   545,  8607,  8628,  1165,  6427,  6427,
     550,  1167,  1169,  1170,  6427,  6427,  1171,  1175,  1175,  6427,
    5828,  5828,  5828,  5828,  6427,  6427,  6427,  1176,  4647,   989,
    1178,   991, -1286, -1286,   121, -1286, -1286,  4182,  4276,  -103,
    -103,     6,     6,   157,  6427,  6427,  6427,  5769,  5769,  6427,
    4305,   202, -1286,  6427,  6427,  6427,  6427,  6427,  1184,  1186,
    1201,  6427,  1206, -1286,  6427,  6427,   874, -1286,  6008,  6008,
    6008,  1210,  1211,  6427,  6427,  6427,  6427,  1214,   334,   751,
   -1286,  1172,  6427, -1286,  1173, -1286,  1182, -1286,  1183,    48,
      49,    50,    51,  6008,   962, -1286,  8649, -1286,   554,  6427,
    5211, -1286,  6427,   369, -1286,  8670,  8691,  8712,  1100,  5020,
   -1286,  1043,  3632,  8733,  8159, -1286, -1286,  1036, -1286,  1467,
    6427, -1286, -1286,  1047,   567,   138,  8182,  6427,  6008,  1232,
    1233, -1286,  6427,  8205,   128,  6237,  6237,  6237,  6237,  6237,
    6237,  6237,  6237,  6237,  6237,  6237,  5206,  6237,  6237,  6237,
    6237,  6237,  6237,  6237,  5392,  5578,  5823,   274,   343,   274,
    1053,  1054,  1050,  1052,  1056,  1057,  6003,   297,   575,  9174,
   -1286,  1278,  1058,  1059,   503,   575,  1064,  1066,   138, -1286,
    4839,   101,  2852,  6427,  1240,  1252,    37,  1068, -1286,   200,
      42,    44,   251, -1286,  4595,   571,  3669,  1563,  2265,   610,
     610,   165,   165,   165,   165,   408,   408,   962,   962,   962,
     962,    29,  8228, -1286,  6427,  1256,    22,  6008,  1255,  6008,
    6427,  1257,  2014,  1259, -1286,   751,  1260,  2014,  6427,  2852,
    1262,  6008,  6008,  1137,  1270,  1272,  8754,  1273,  1145,  1276,
    1279,  8775,  1148,  1280,  1281,  6427,  8796,  4781,  1096, -1286,
   -1286, -1286,  8817,  8838,  6427,  4839,  1258,  1286,  8859,  1106,
    9174, -1286,  1108,  9174, -1286,  1109,  9174, -1286,  1111,  9174,
   -1286,  8880,  8901,  8922,  4839,  6008,  1104, -1286, -1286,  2023,
    2095,  -103,  6427,  6427, -1286, -1286,  1110,  1119,  5769,  7174,
    7200,  7226,  3844,   235,  -103,  2190,  8943,  4967,  8964,  8985,
    9006,  6427,  1295, -1286,  6427,  9027, -1286,  8251,  8274, -1286,
     583,   602,   613, -1286, -1286,  8297,  8320,  7252,  8343,   -41,
   -1286, -1286,  6008, -1286,  1113,  1112,  5153,  1116,  1122,  1126,
   -1286,  6008, -1286,  6008, -1286,  6008, -1286,  6008,   616, -1286,
   -1286,  3806,  6008,   962, -1286,  6008, -1286,  1297,  1312,  1314,
    1135,  6427,  2272,  6427,  6427, -1286,    11, -1286, -1286,  2422,
    1136,  4839,  1325,  4839,   294,  5339,   649, -1286, -1286,  8366,
     284, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286,  6427, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286,  6427,  6427,  6427, -1286,  6008, -1286, -1286, -1286, -1286,
    2014,  4839,  2014,  2014,  2852, -1286, -1286, -1286, -1286, -1286,
    6427, -1286, -1286,  2014, -1286, -1286, -1286,  6427,  1326,   117,
    6427,  1327,  1332,  1317, -1286,  1333,  1150,    36,  1339, -1286,
    6008,  6008,  6008,  6008, -1286,   575,  6427, -1286,  1159,  1160,
    1163, -1286,  1352, -1286, -1286, -1286, -1286, -1286,   -41,  8389,
   -1286, -1286,  1185,  2014,   516, -1286,   536,  7278, -1286, -1286,
   -1286,  1354, -1286, -1286,  6237,   575,  -103,  3580, -1286,   757,
    4839,  4839,  1356,  4839,   768,  4839,  4839,  1357,  1287,  4839,
    4839,  1403,  1358,  1360,  6008,  1386,  1387,  2470, -1286, -1286,
    1389, -1286,  1390,   138,   138,   138,   138,  1391,  1393,  1397,
    1399,   663,  1406,  2495, -1286, -1286,   248,  7304,  7330, -1286,
   -1286,  5525,  -105,  -103,  -103,  -103,  1407,  1409,  1225,  1414,
    1235,    28,    43,    52,    64,   -25, -1286,   250, -1286,   235,
    1417,  1423,  1425,  1426,  1427,  9174, -1286,  1674,  1236,  1432,
    1433,  1434,  1383,  6427,  1457,  1459,  6427,   186,   667, -1286,
    6427, -1286,  6427,  6427,  6427,   682,   687,   698,   716, -1286,
    6427,   725,   729,  4839,  4839,  4839,  1462,  7356, -1286,  3996,
     370,  1463,  1465, -1286,  4839,  1275, -1286,  1468,  6427,  1471,
   -1286,   575,  1475,  1469, -1286,  1476,  6237,  6237,  6237,  6237,
     445,  1291,  1283,  1311,  1313,  1307,   470,   492,  9048,  1316,
    1715, -1286,   407,  1315,  1495,  2202, -1286, -1286, -1286,    36,
    6427, -1286,   730, -1286,   734,   737,   738,   742,   138,  9174,
    1321,  6427,  6427,  4839,  1322, -1286, -1286,  1319, -1286,  1509,
      24,  1513,  6427,  4035,  1515,  1516,    13,  1329,  1330,  1438,
    1438,  4839,  1520,  1334,  1335,  1521,  1524,  4839,  1338,  1527,
    1528, -1286,  1530,  4839,   743,  4839,  4839,  1532,  1544, -1286,
    4839,  4839,  4839,  4839,  4839,  4839,  4839,  4839, -1286,  1549,
     774, -1286,  6427,  6427,  6427,  1366,  1367,   -77,   100,   113,
    1362, -1286,  4839, -1286,  6427, -1286,  1556, -1286,  1558, -1286,
    1560, -1286,  1561, -1286, -1286,  5769,   785,  4653, -1286,  1374,
    1375,  5397, -1286,  6008, -1286, -1286, -1286,  1392,  2241, -1286,
   -1286,  8412,  1581,   575,  7382,  7408,  7434,  7460, -1286, -1286,
   -1286, -1286,  9174, -1286,   575,  1586,  1587,  1454, -1286,  6427,
    6427,  6427, -1286,  1588,   807,  1402,  1593, -1286,  2300, -1286,
     138, -1286,   272, -1286, -1286, -1286, -1286, -1286, -1286,  2014,
   -1286, -1286, -1286,  2852,  1596, -1286, -1286,  1598, -1286, -1286,
   -1286, -1286, -1286,  2852,  6427,  1599,  1602,    37, -1286,  1601,
    8435,    36, -1286,  1606,  1607,  1613,  1614,  4839,  6427,  7486,
    7512,   747, -1286,  6427,  1617, -1286, -1286,  2014, -1286,  7538,
    5828,  9174, -1286, -1286, -1286, -1286,  6427,  6427,  -103,  1621,
    1631,  1632, -1286,  6427,  6427, -1286, -1286,  1633,  6427, -1286,
   -1286,  1635,  1636,  1447,  1637,  1507,  6427, -1286,  1639,  1640,
    1641,  1644,  1645,  1646,   937,  1648,  6427, -1286,  5828,  5729,
    9069,  4030,     6,     6,  -103,  1649,  -103,  1651,  -103,  1652,
    6427,   323,  1470,  9090, -1286, -1286, -1286, -1286,  5763,   262,
   -1286,  1653,  3398,  1654,  4839,  -103,  3398,  1655,   765,  6427,
   -1286,  1659,   -41, -1286,  6427,  6427,  6427,  6427, -1286, -1286,
   -1286,  4839,  4234,   429,  9111, -1286, -1286,  4095,  4839, -1286,
   -1286,  4839, -1286,  1478,   575,  3849,  4281,  1665,  2661, -1286,
    1669,  1675, -1286,  1491, -1286, -1286, -1286, -1286, -1286,  1677,
     539,  9174,  6427,  6427,  4839,  1492,   776,  9174, -1286,  1679,
    6427,  9174, -1286,  5950,  6143,   652, -1286, -1286, -1286,  6182,
    6327, -1286,  6355,  1682, -1286,  4839, -1286,  1615,  1685,  9174,
   -1286, -1286, -1286, -1286, -1286, -1286,  1499, -1286, -1286,  4833,
    2923,  1688,  1501, -1286,  6427, -1286,  1502,  1503,   270, -1286,
    1506,   333, -1286,  1519,   389, -1286,  1522,  8458,  1690,  4839,
    1694,  1533,  6427, -1286,  5583,   391, -1286,   800,   434,   436,
   -1286,  1697,  6670, -1286,  7564,  7590,  7616,  7642,  1575,  6427,
   -1286,  6427, -1286, -1286,  6008,  2963,  1704,  1534,  1708, -1286,
   -1286,  3638, -1286, -1286,  2014,  9174, -1286, -1286, -1286,    36,
   -1286,  1580, -1286, -1286,  6427,  7668,  7694, -1286,  4839,  6427,
    1716, -1286,  7720, -1286, -1286,  1725,  1739,  1740,  1741,  1748,
    1749,   801,  1564, -1286,  4839,  6008, -1286, -1286,     6,  4409,
   -1286, -1286,  5769,   235,  5769,   235,  5769,   235,  1751, -1286,
     804,  4839, -1286,  6698,  -103,  1753,  6008,  -103, -1286, -1286,
    6427,  6427,  6427,  6427,  6427,  6726,  6754,   813, -1286, -1286,
    1754, -1286,   814,  3350,   817,  1755, -1286,  1568,  9174,  6427,
    6427,   821,  9174, -1286,  6427,   838,   839, -1286, -1286, -1286,
   -1286, -1286, -1286,  1572,  6427,   843,   846,  1573,  6427, -1286,
    6782,   443,   863,  6810,   488,   968,  6838,   497,  1041, -1286,
    4839,  1763,  1678,  2586,  1579,   538, -1286,   847,   541,  7746,
    7772,  7798,  7824,  2982, -1286, -1286,  1769, -1286,  6427, -1286,
    2852, -1286, -1286,  6427,  9132,  7850,    54,  7876, -1286, -1286,
    6427,  6866,  1771,  1684, -1286,  6894,  1773,  6427,  1774,  1775,
    6427,  1776,  1777,  6427,  1779,  1591, -1286,  6427, -1286,   235,
   -1286,  6008,  1781,  5583,  6427,  6427,  6427,  6427, -1286, -1286,
    3428, -1286,   850, -1286,  6427, -1286,  4839,  6427,  7902, -1286,
   -1286,  4839,  1782, -1286, -1286,  1597,  6922, -1286, -1286,  1600,
    6950, -1286, -1286,  1603,  6978, -1286,  1784,  3110,  1075,  2723,
     851, -1286,   544,   858,  7928,  7954,  7980,  8006,  2852,  1786,
    1604,  9153,   859,  7006,  6427, -1286, -1286,   235,  1787,   235,
    1789,   235,  1790, -1286, -1286, -1286, -1286,   235,  1793,  6008,
    1795,  6427,  6427,  6427,  6427, -1286, -1286,  2014, -1286,  1609,
    1820,  7034,  1086, -1286,  1634,  1107, -1286,  1638,  1230, -1286,
    1642,  1323, -1286,   862, -1286,  8032,  8058,  8084,  8110,   866,
   -1286,  1643,  4839, -1286,  1821,  1823,   235,  1824,   235,  1825,
     235, -1286,  1827,  6427,  6427,  6427,  6427,  2014,  1828,  2014,
     870, -1286, -1286,  1497, -1286,  1510, -1286,  1605, -1286,  7062,
    7090,  7118,  7146, -1286, -1286,   871, -1286,  1833,  1835,  1850,
    1851, -1286, -1286, -1286, -1286,  2014,  1852, -1286, -1286, -1286,
   -1286, -1286, -1286
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1286, -1286, -1286, -1286,   789, -1286, -1286, -1286, -1286,   300,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286,  -381,   -87,  1254,  -451, -1286,  1451, -1286, -1286,
   -1286, -1286, -1286,   427, -1286,   428, -1286, -1286, -1286, -1286,
   -1286, -1286,   819,  1894,     0,  -470,  -253, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286,  1897, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,  -952,  -942,
   -1286, -1286,  1444, -1286, -1286, -1286, -1286, -1286, -1286,  1466,
   -1286, -1286,    33, -1286, -1285,  2170,   532,   641,   482,  -237,
     696, -1286,    21,    10, -1286,  -355,    -3,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -470
static const yytype_int16 yytable[] =
{
     106,   490,   471,    93,   620,   597,   623,   599,   335,  1407,
     391,   726,   727,   506,   313,   607,   179,  1136,  1011,  1235,
     334,   315,   264,  1134,   205,   479,   480,   178,   891,   387,
    1226,   256,   201,   877,  1125,   523,   525,   183,   210,   202,
     300,   866,   481,   527,   107,   520,   205,   181,   210,  1127,
     267,   184,   268,   770,   772,   774,   776,     5,  1129,   186,
    1605,   557,   294,   559,   502,   320,   503,   303,     4,   956,
    1131,   415,   479,   480,   243,   244,   310,   185,   324,   957,
    1461,   656,   247,   249,   245,   255,   657,   958,   959,   960,
    1116,   246,   786,   961,   962,   963,   964,   239,   257,   182,
     479,   480,   258,   326,    48,    49,    50,    51,   619,   188,
     240,   241,    56,   192,   259,    59,  1274,   269,  1275,   235,
     311,  1042,   236,   195,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   189,   824,   825,   826,   827,
     828,   829,   830,   331,   332,   619,   834,   836,   837,   197,
    1126,   323,   203,   878,   879,   880,   881,   846,   324,   388,
     389,   265,   190,  1511,   854,  1128,   191,   524,   526,   310,
    1133,   479,   480,   392,  1130,   528,   197,   521,   516,  1525,
     517,   310,   310,   173,   803,   174,  1132,   658,   482,   310,
     479,   480,   659,   336,  1134,   337,   892,   310,   892,   294,
     174,   193,  1012,   314,   294,   420,   423,   206,   294,   429,
     316,   294,   266,   390,   207,   294,   294,   294,   294,   719,
     720,   294,   294,   294,   882,   422,   422,   194,   211,   206,
     301,   867,   294,   422,   522,   294,   871,   857,   872,   735,
     860,   430,   771,   773,   775,   777,   321,   187,  1606,   504,
     304,  1043,  1044,   322,   479,   480,   196,   294,   294,   294,
     327,   328,   329,   330,   214,   327,   328,   329,   330,   294,
     294,   492,   560,   622,   517,   474,   475,   479,   480,   174,
     331,   332,   294,   483,   294,   331,   332,   491,   419,   110,
     479,   480,   859,  1276,   197,  1277,   198,   792,   479,   480,
     624,   619,   327,   328,   329,   330,  1278,   204,  1279,   799,
     331,   332,   331,   332,   721,   260,   215,   261,   294,   294,
    -467,  1642,  -468,   136,   137,   138,   139,   140,   141,   956,
     294,   539,   145,   493,   479,   480,   569,   147,   148,   957,
     494,   149,   407,   408,   409,   410,   411,   958,   959,   960,
     728,   412,   154,   961,   962,   963,   964,   310,   310,   310,
     310,   310,   310,   294,   310,   310,   272,   310,   310,   273,
     331,   332,   310,   310,   310,   310,   310,  1152,  1171,   479,
     480,   208,   598,   610,   600,   601,   602,   201,   604,   605,
     617,   209,   608,   294,   870,   734,   612,   613,   614,   615,
     212,   422,   422,   422,   422,   422,   422,  1710,   422,   422,
     213,   422,   422,   197,  1203,   542,   422,   422,   422,   422,
     616,   216,   324,  1018,  1058,   479,   480,   479,   480,   294,
     327,   328,   329,   330,   157,   158,   217,  1421,   213,   479,
     480,  1112,   654,  1135,   655,   873,   165,   479,   480,   174,
     331,   332,   218,  1074,  1075,  1402,   331,   332,   327,   328,
     329,   330,   760,  1472,   761,   943,  -469,   662,   331,   332,
     701,   704,   707,   710,   672,  1023,   673,   397,   331,   332,
     228,   392,   392,   229,   661,   845,   230,   811,   231,   662,
     662,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   540,   410,   411,   294,   294,   294,   222,   412,
     479,   480,   724,   725,   224,   223,   310,   225,  1398,   226,
     475,  1532,   760,  1535,   761,  1538,  1474,   227,   762,   219,
     294,   760,   220,   761,   861,   221,   835,   294,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,  1101,  1102,  1103,  1104,   412,   760,  1172,   761,
     764,   663,   237,   785,   664,   294,   479,   480,   479,   480,
    1180,   327,   328,   329,   330,  1184,  1185,  1186,  1187,  1188,
     666,   238,  1476,   664,  1484,  1195,  1198,   409,   410,   411,
    1134,   331,   332,  1134,   412,   242,  1134,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   479,   480,   479,   480,   412,   672,   294,   678,   251,
     479,   480,   252,   232,  1422,   253,   233,  1486,   234,  1487,
    1051,   250,   862,   760,   262,   761,  1577,  1628,   672,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   561,   294,   263,   294,   412,   760,   310,
     761,  1204,   310,  1194,   310,   479,   480,   270,   294,   294,
     529,   271,   811,   530,   479,   480,   531,  1217,   532,   905,
     760,  1580,   761,   899,   435,  1197,  1134,   274,   903,   440,
    1583,   852,   294,   444,   275,  1672,   853,  1675,   276,  1678,
     450,   296,  1303,   422,  1070,  1681,   901,   297,   422,   672,
     298,   294,   294,  1308,   299,   479,   480,  1019,   479,   480,
     305,   479,   480,  1024,  1071,   243,   244,  1443,   306,   672,
    1134,  1591,  1444,  1134,  1593,   245,  1134,  1659,   672,  1134,
     682,   307,   254,   672,  1713,   688,  1715,   672,  1717,   780,
     308,   451,   452,   453,   946,   309,   456,   457,   458,   294,
     801,   952,   802,   760,   672,   761,   875,   967,   294,   363,
     294,  1134,   294,  1134,   294,  1134,   672,   312,   981,   294,
    1267,  1268,   294,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   498,   499,   364,   672,   412,   982,   294,  1321,
     294,  1066,  1386,  1387,   511,   512,   672,   310,   983,   672,
     365,   999,  1209,  1316,  1317,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   479,
     480,  1025,   294,   412,  1077,   366,  1078,   310,   294,   310,
     310,   367,   672,   434,  1021,  1083,   368,  1084,   434,   370,
     310,   422,   434,   375,  1035,   653,   672,   376,  1109,   434,
     672,  1031,  1153,  1033,  1034,   377,   379,   294,   294,   294,
     294,   374,   380,  1430,  1039,   672,   438,  1158,   635,   956,
     672,   422,  1159,   422,   422,   395,     7,     8,   414,   957,
     310,   672,   417,  1160,   422,   396,   413,   958,   959,   960,
    1024,   443,   448,   961,   962,   963,   964,   294,   294,   672,
     294,  1161,   294,   294,  1069,   449,   294,   294,   672,   454,
    1163,   294,   672,  1211,  1164,  1212,   535,   672,   434,  1213,
     672,   672,  1214,  1215,   422,   672,   672,  1216,  1253,  1076,
    1344,  1376,  1345,  1377,   469,   629,    24,    25,   630,    27,
      28,   631,    30,   632,    32,  1205,    33,   956,   672,   455,
    1411,    38,    39,   472,    41,    42,    43,   957,   459,  1449,
      46,  1450,   473,   460,  1334,   958,   959,   960,   461,   462,
    1290,   961,   962,   963,   964,   463,  1117,  1118,  1119,   464,
     750,   751,   752,  1344,  1344,  1485,  1523,  1540,  1527,  1541,
     294,   294,   294,    67,    68,    69,   672,  1558,  1556,  1559,
     662,   294,  1561,   465,  1344,   778,  1566,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,  1194,  1197,  1568,  1569,   412,  1344,   434,  1572,   672,
     672,  1573,  1592,  1449,   672,  1639,  1658,   466,     7,     8,
     806,   672,  1344,  1660,  1669,   672,   495,  1702,  1578,  1707,
     294,  1708,   956,  1344,  1735,  1727,  1736,   484,   496,   749,
     485,   486,   957,   535,   497,   501,   507,   508,   294,  1504,
     958,   959,   960,  1232,   294,   505,   961,   962,   963,   964,
     294,   509,   294,   294,   510,  1322,   513,   294,   294,   294,
     294,   294,   294,   294,   294,   514,   515,   629,    24,    25,
     630,    27,    28,   631,    30,   632,    32,   519,    33,   294,
     541,   544,   548,    38,    39,   551,    41,    42,    43,   550,
     174,   555,    46,   556,   294,   956,   558,   324,   294,   894,
     294,   896,   567,   568,   571,   957,   572,   574,   412,   434,
     434,   434,   625,   958,   959,   960,   626,   173,   627,   961,
     962,   963,   964,  1581,   668,    67,    68,    69,  1289,   956,
     628,   669,   685,   689,   434,   690,   691,   716,   694,   957,
     956,   784,   695,   714,   717,   718,   310,   958,   959,   960,
     957,   741,   743,   961,   962,   963,   964,   941,   958,   959,
     960,   956,  1505,  1324,   961,   962,   963,   964,   744,   434,
    1323,   957,   746,  1327,   294,  1322,   753,   754,   759,   958,
     959,   960,   765,   767,   310,   961,   962,   963,   964,  1543,
     422,   797,   768,   769,   790,   800,  1584,   793,   807,   808,
    1352,   838,   839,   840,   988,   841,   864,   851,  1349,   842,
     843,   850,   855,   995,   856,   996,   865,   997,   869,   998,
     890,   895,   929,   898,  1001,   900,   902,  1002,   422,   906,
    1655,  1355,   392,   392,   909,   199,   200,   910,  1381,   911,
     913,  1695,   914,   915,   849,   918,   916,   919,   920,   294,
     924,   294,   931,   294,   933,   942,   934,   935,   434,   936,
     434,   976,  1697,   989,  1003,   949,   990,  1388,   294,  1391,
     992,  1394,   784,   908,   950,   294,   993,  1030,   294,  1004,
     994,  1005,   294,  1048,   956,  1405,  1006,  1426,  1408,  1409,
    1014,  1016,  1041,  1046,   957,  1433,  1436,  1629,  1047,  1050,
    1049,   294,   958,   959,   960,  1053,  1061,  1062,   961,   962,
     963,   964,  1054,  1055,  1056,  1057,   434,  1063,  1065,  1068,
     325,  1073,   294,  1081,  1087,  1092,  1088,  1093,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,  1095,  1096,  1099,   294,  1100,  1105,   369,
    1106,   294,   371,   434,  1107,  1108,  1094,   372,   373,  1091,
    1110,  1120,   434,   378,   434,  1121,   434,   956,   434,  1122,
    1123,   294,  1124,   434,  1137,  1699,   434,   957,   294,  1138,
    1143,   310,  1139,  1140,  1141,   958,   959,   960,  1144,  1145,
    1146,   961,   962,   963,   964,   294,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
    1147,   294,   294,  1149,   412,  1150,  1168,  1173,   392,  1174,
    1176,  1190,   176,  1182,  1177,   422,   434,  1179,   294,     7,
       8,  1181,  1183,   294,  1189,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,  1191,
    1193,  1192,  1207,   412,  1201,  1531,  1206,  1534,  1218,  1537,
    1224,   434,   434,   434,   434,  1225,  1223,  1545,  1701,  1228,
    1548,  1233,  1234,  1236,  1237,  1238,  1242,  1245,  1243,  1244,
    1246,   518,  1248,  1249,  1250,  1251,  1256,   294,   629,    24,
      25,   630,    27,    28,   631,    30,   632,    32,   543,    33,
    1257,  1280,   318,   319,    38,    39,  1266,    41,    42,    43,
    1272,  1273,  1284,    46,  1285,   434,  1286,  1287,  1294,  1295,
    1601,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,  1302,  1299,  1311,   294,   412,
     294,   956,  1309,  1310,  1315,  1318,    67,    68,    69,  1319,
    1325,   957,  1326,   294,   956,  1329,  1330,  1332,   294,   958,
     959,   960,  1335,  1336,   957,   961,   962,   963,   964,  1337,
    1338,  1348,   958,   959,   960,  1298,  1632,  1356,   961,   962,
     963,   964,   381,   382,   383,   384,   386,  1357,  1358,  1361,
    1363,  1365,  1364,  1366,  1367,  1370,  1371,  1372,  1665,   418,
    1373,  1374,  1375,   424,  1378,  1389,   294,  1392,  1395,  1403,
    1406,  1410,   798,  1399,   310,  1413,  1429,   431,   433,   436,
     437,  1437,   439,   433,   441,   442,  1439,   433,   445,   446,
    1142,  1440,  1441,  1442,   433,  1451,  1448,  1460,  1690,   294,
    1462,  1463,  1728,  1464,  1467,  1468,  1479,  1470,  1471,   956,
    1473,  1481,   468,  1488,   310,  1729,   310,  1494,   422,   957,
    1499,   477,   478,  1475,  1501,  1506,  1477,   958,   959,   960,
     478,  1202,  1513,   961,   962,   963,   964,  1482,  1723,  1500,
    1726,  1517,   310,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,  1518,  1519,  1520,   422,   412,
     422,   534,   536,   433,  1521,  1522,  1741,  1539,  1524,  1546,
    1557,  1562,  1563,   545,   546,   547,  1570,   549,  1574,  1586,
     552,   553,  1587,  1590,   554,  1599,   422,  1610,  1611,  1614,
    1617,  1618,  1621,  1622,   434,  1625,  1626,  1631,  1646,   566,
    1653,  1647,  1666,  1673,  1649,  1676,  1679,  1651,  1667,  1682,
    1730,  1684,   573,  1692,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,  1693,  1711,  1696,  1712,
    1714,  1716,  1698,  1718,  1724,   606,  1700,  1709,   609,  1737,
     611,  1738,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,  1739,  1740,  1742,  1227,
     412,   634,   433,  1602,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   667,
    1515,   652,  1516,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,    92,   534,  1240,
     101,   412,   697,  1331,   676,     0,  1497,     0,     0,   681,
       0,     0,     0,     0,   686,   687,     0,     0,     0,     0,
     692,   693,     0,     0,     0,   698,   700,   703,   706,   709,
     711,   712,   713,   434,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1526,     0,     0,
     729,   730,   731,   381,   382,   732,     0,     0,     0,   736,
     737,   738,   739,   740,     0,     0,     0,   745,  1547,     0,
     747,   748,     0,     0,   433,   433,   433,     0,     0,   755,
     756,   757,   758,     0,     0,     0,     0,     0,   766,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,   781,   783,     0,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,   110,
       0,     0,     0,     0,     0,     0,   758,     0,     0,     0,
       0,     0,     0,   805,   433,     7,     8,     0,   809,     0,
       0,     0,     0,     0,     0,   535,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   141,     0,
       0,     0,   145,     0,     0,   434,     0,   147,   148,     0,
       0,   149,   434,  1630,     0,  1633,     0,     0,     0,     0,
       0,     0,   154,     0,     0,     0,     0,     0,     0,   863,
       0,     0,     0,     0,   629,    24,    25,   630,    27,    28,
     631,    30,   632,    32,     0,    33,   434,     7,     8,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
     889,     0,     0,   433,     0,   433,   897,   434,     0,     0,
       0,     0,     0,     0,   904,     0,     0,   783,   907,     0,
       0,  1683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   921,    67,    68,    69,     0,     0,     0,     0,     0,
     927,     0,     0,     0,   157,   158,   629,    24,    25,   630,
      27,    28,   631,    30,   632,    32,   165,    33,     0,     0,
       0,   433,    38,    39,     0,    41,    42,    43,   947,   948,
       0,    46,     0,     0,   951,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,   975,  1208,     0,
     977,     0,     0,     0,     0,     0,     0,     0,   944,     0,
       0,     0,     0,     0,    67,    68,    69,     0,   433,     0,
       0,     0,   434,     0,   434,     0,     0,   433,     0,   433,
       0,   433,     0,   433,     0,     0,     0,  1300,   433,     0,
       0,   433,     0,     0,     0,     0,     0,  1007,     0,  1009,
    1010,   629,    24,    25,   630,    27,    28,   631,    30,   632,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     7,     8,    46,     0,     0,  1026,
     945,     0,     0,     0,     0,     0,     0,  1027,  1028,  1029,
     434,   433,     0,     0,     0,     0,  1320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1038,     0,     0,    67,
      68,    69,     0,  1040,     0,     0,  1045,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,   433,   433,   433,
       0,     0,  1059,   629,    24,    25,   630,    27,    28,   631,
      30,   632,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   447,   968,     0,     0,   412,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,     0,   467,     0,     0,   470,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,     0,
       0,     0,   500,     0,     7,     8,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,  1148,
       0,   412,  1151,     0,     0,     0,  1154,     0,  1155,  1156,
    1157,     0,     0,     0,     0,     0,  1162,  1008,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,  1178,     0,   412,     0,     0,     0,
       0,   563,   564,   629,    24,    25,   630,    27,    28,   631,
      30,   632,    32,   570,    33,     0,     0,     7,     8,    38,
      39,     0,    41,    42,    43,     0,  1210,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,  1219,  1220,     0,
       0,     0,     0,     0,     0,     0,   603,     0,  1229,  1231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1097,     0,   629,    24,    25,   630,
      27,    28,   631,    30,   632,    32,     0,    33,  1269,  1270,
    1271,     0,    38,    39,     0,    41,    42,    43,  1281,     0,
    1283,    46,     0,     0,     0,     0,     0,     0,     7,     8,
       0,  1288,     0,     0,     0,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,     0,  1013,     0,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,  1312,  1313,  1314,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,   629,    24,    25,
     630,    27,    28,   631,    30,   632,    32,  1438,    33,     0,
    1328,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,  1341,     0,     0,     0,     0,  1347,
    1111,     0,     0,     0,     0,     0,  1351,     0,     0,     0,
       0,     0,  1353,  1354,     0,     0,     0,     0,     0,  1359,
    1360,     0,     0,     0,  1362,    67,    68,    69,     0,     0,
       0,     0,  1369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1379,     0,  1380,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1397,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   433,     0,
       0,     0,   433,     0,     0,  1412,     0,     0,     0,     0,
    1414,  1415,  1416,  1417,     0,     0,     0,     0,     0,     0,
       0,  1588,     0,  1425,     0,     0,     0,     0,     0,     0,
     858,     0,  1435,     0,   629,    24,    25,   630,    27,    28,
     631,    30,   632,    32,     0,    33,     0,     0,  1445,  1446,
      38,    39,     0,    41,    42,    43,  1452,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,     0,
    1469,     0,    67,    68,    69,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,   928,     0,     0,  1483,     0,
     534,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   940,  1495,     0,  1496,     0,     0,
     433,   136,   137,   138,   139,   140,   141,  1503,     0,     0,
     145,     0,     0,     0,     0,   147,   148,     0,     0,   149,
    1508,     0,     0,     0,     0,  1512,     0,     0,  1656,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,  1466,
       0,   433,     0,     0,     0,     0,     0,     0,  1530,     0,
    1533,     0,  1536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   433,     0,     0,     0,  1549,  1550,  1551,  1552,
    1553,     0,     0,     0,     0,     0,     0,     0,     0,  1498,
       0,  1015,     0,  1017,     0,  1564,  1565,     0,     0,     0,
    1567,     0,     0,     0,     0,     0,     0,     0,  1598,     0,
    1571,     0,     0,     0,  1575,     0,     0,     0,     0,     0,
       0,     0,   157,   158,     0,     0,     0,     0,     0,     0,
       0,  1032,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1600,     0,     0,     0,     0,  1347,
       0,     0,     0,     0,     0,     0,  1608,     0,     0,     0,
       0,     0,     0,  1616,     0,     0,  1620,     0,     0,  1624,
       0,     0,     0,  1627,     0,     0,     0,   433,     0,   433,
    1634,  1635,  1636,  1637,     0,     0,     0,     0,     0,     0,
    1641,     0,     0,  1643,     0,     0,     0,     0,     0,     0,
    1079,  1080,     0,  1082,     0,  1085,  1086,     0,     0,  1089,
    1090,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
    1671,     0,     0,     0,     0,     0,  1654,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,  1685,  1686,  1687,
    1688,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,  1719,
    1720,  1721,  1722,  1165,  1166,  1167,     0,     0,     0,     0,
     108,   109,   110,     0,  1175,     0,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     147,   148,     0,  1222,   149,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,   154,     0,     0,     0,     0,
       0,  1241,     0,     0,     0,     0,     0,  1247,     0,     0,
       0,     0,     0,  1252,     0,  1254,  1255,     0,     0,     0,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,  1282,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1293,     0,     0,
       0,  1297,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,   156,   157,   158,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,   167,     0,  1560,   539,   168,
       0,     0,     0,     0,   169,     0,   170,     0,   171,   172,
       0,   173,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1339,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   277,     0,     0,     0,     0,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   279,  1638,     0,     0,     0,     0,
       0,     0,     0,   142,   143,   144,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     539,     0,     0,     0,  1222,   153,     0,     0,     0,   280,
       0,     0,   281,     0,     0,   282,     0,   283,     0,     0,
       0,  1418,     0,     0,     0,     0,     0,     0,  1427,   284,
       0,  1428,     0,     0,     0,  1432,    48,    49,    50,    51,
      52,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,     0,  1447,     0,     0,     0,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   671,
     410,   411,     0,     0,     0,  1222,   412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
     159,     0,     0,     0,     0,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1480,
       0,     0,     0,     0,     0,   487,  1404,     0,     0,     0,
     168,     0,     0,     0,     0,   489,     0,     0,   539,     0,
     172,     0,   246,   537,     0,     0,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,  1222,     0,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   540,   410,   411,  1222,     0,     0,     0,   412,     0,
     794,   108,   277,     0,     0,     0,     0,   111,   112,   113,
       0,  1542,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   279,     0,     0,   876,     0,     0,
       0,     0,     0,   142,   143,   144,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
       0,     0,     0,     0,     0,   153,     0,     0,     0,   280,
    1585,     0,   281,     0,     0,   282,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,    56,     0,     0,    59,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   671,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1222,     0,     0,     0,
       0,  1645,     0,     0,     0,     0,     0,   156,     0,     0,
     159,     0,     0,     0,     0,   160,   161,   162,   163,   164,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,  1000,   166,   432,     0,   412,     0,
     168,     0,     0,     0,     0,   286,     0,     0,     0,     0,
     172,     0,     0,   537,     0,     0,     0,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,   108,   277,   110,   412,     0,     0,   111,   112,
     113,     0,  1222,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   279,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,   147,   148,     0,     0,   149,     0,   150,   151,
     152,     0,     0,     0,     0,     0,   153,   154,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,   156,   157,
     158,   159,     0,     0,  1170,     0,   160,   161,   162,   163,
     164,   165,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   166,   285,     0,     0,
     412,   168,   779,     0,     0,     0,   286,   722,   108,   317,
     110,   172,     0,  1431,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   147,   148,
       0,     0,   149,     0,   150,   151,   152,     0,   108,   317,
     110,     0,   153,   154,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   147,   148,
       0,     0,   149,     0,   150,   151,   152,     0,     0,     0,
       0,     0,   153,   154,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,   156,   157,   158,   159,     0,     0,
       0,     0,   160,   161,   162,   163,   164,   165,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   166,   167,     0,     0,   412,   168,     0,     0,
       0,     0,   286,  1384,     0,  1385,     0,   172,     0,  1230,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   156,   157,   158,   159,   412,     0,
     618,     0,   160,   161,   162,   163,   164,   165,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   166,   167,     0,     0,   412,   168,     0,     0,
       0,     0,   286,   660,   108,   317,   110,   172,     0,  1424,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     7,     8,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   147,   148,     0,     0,   149,     0,
     150,   151,   152,     0,     0,     0,     0,     0,   153,   154,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,   722,   629,    24,    25,   630,
      27,    28,   631,    30,   632,    32,     0,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1419,     0,  1420,
     156,   157,   158,   159,    67,    68,    69,     0,   160,   161,
     162,   163,   164,   165,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   166,   167,
       0,     0,   412,   168,     0,     0,     0,     0,   286,   723,
     108,   277,   278,   172,     0,  1434,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   279,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,     0,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,     0,     0,     0,
       0,     0,  1528,     0,  1529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,     0,     0,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,   166,   285,     0,   412,     0,   168,
       0,     0,     0,     0,   286,   562,   108,   277,  1291,   172,
       0,   287,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   279,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   280,     0,     0,   281,     0,     0,
     282,     0,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,    56,
       0,     0,    59,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,     0,     0,     0,     0,     0,     0,     0,
     874,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,   159,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
     166,   285,     0,   412,     0,   168,     0,     0,     0,     0,
     286,   715,   108,   277,     0,   172,     0,  1292,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   279,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,     0,     0,     0,     0,     0,   153,     0,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,    56,     0,     0,    59,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,     0,
       0,     0,     0,     0,     0,     0,   923,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,   159,     0,     0,     0,     0,   160,   161,   162,   163,
     164,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,   166,   285,     0,   412,
       0,   168,     0,     0,     0,     0,   286,  1465,   108,   277,
       0,   172,     0,   287,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   279,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,     0,     0,     0,
       0,     0,   153,     0,     0,     0,   280,     0,     0,   281,
       0,     0,   282,     0,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,    56,     0,     0,    59,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
       0,     0,     0,   412,     0,     0,     0,     0,     0,     0,
       0,     0,   971,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,   159,     0,     0,
       0,     0,   160,   161,   162,   163,   164,     0,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   166,   432,     0,     0,   412,   168,     0,     0,
       0,     0,   286,   791,   108,   277,     0,   172,     0,   533,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   279,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,     0,     0,     0,     0,     0,   153,     0,
       0,     0,   280,     0,     0,   281,     0,     0,   282,     0,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,     0,     0,     0,     0,     0,     0,     0,   991,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,   159,     0,     0,     0,     0,   160,   161,
     162,   163,   164,     0,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   166,   432,
       0,     0,   412,   168,     0,     0,     0,     0,   286,   823,
     108,   277,     0,   172,     0,   782,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   279,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,     0,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,     0,     0,     0,
       0,     0,     0,     0,  1020,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,     0,     0,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,     0,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   166,   285,     0,     0,   412,   168,
       0,     0,     0,     0,   286,   831,   108,   277,     0,   172,
       0,  1296,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   279,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   280,     0,     0,   281,     0,     0,
     282,     0,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,    56,
       0,     0,    59,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,     0,     0,     0,     0,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,   159,     0,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     487,  1404,     0,     0,   412,   168,     0,     0,     0,     0,
     489,   832,   108,   317,     0,   172,     0,   246,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   108,   317,   110,     0,     0,   153,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   147,   148,     0,     0,   149,     0,   150,   151,   152,
       0,     0,     0,     0,     0,   153,   154,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,     0,   156,     0,
       0,   159,     0,     0,  1382,     0,   160,   161,   162,   163,
     164,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,   487,   488,     0,   412,
       0,   168,     0,     0,     0,     0,   489,     0,  1401,     0,
       0,   172,     0,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,   157,   158,
     159,     0,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   166,   167,     0,     0,   412,
     168,   108,   277,     0,     0,   286,   833,   111,   112,   113,
     172,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   279,     0,     0,     0,     0,     0,
       0,     0,     0,   142,   143,   144,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   151,   152,
       0,     0,     0,     0,     0,   153,     0,     0,     0,   280,
       0,     0,   281,     0,     0,   282,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,    56,     0,     0,    59,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,  1455,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
     159,     0,     0,     0,     0,   160,   161,   162,   163,   164,
       0,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   166,   432,     0,     0,   412,
     168,   108,   317,     0,     0,   286,   844,   111,   112,   113,
     172,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,   143,   144,     0,   146,     0,     0,
       0,     0,     0,     0,     0,   108,   317,   150,   151,   152,
       0,   111,   112,   113,     0,   153,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,   152,     0,     0,     0,     0,     0,   153,
       0,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,     0,     0,     0,     0,     0,     0,   156,  1456,     0,
     159,     0,     0,     0,     0,   160,   161,   162,   163,   164,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,   166,   167,     0,   412,     0,
     168,     0,     0,     0,     0,   286,     0,  1457,   385,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,     0,   159,     0,     0,     0,     0,   160,
     161,   162,   163,   164,     0,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   166,
     167,     0,     0,   412,   168,   760,     0,   761,     0,   286,
     108,   317,   565,     0,   172,     0,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
       0,     0,     0,   412,     0,     0,     0,     0,     0,     0,
       0,     0,  1458,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,     0,     0,     0,     0,     0,     0,     0,
    1459,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,   156,     0,     0,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,   166,   167,     0,     0,     0,   168,
      -4,    -4,    -4,     0,   286,    -4,    -4,     0,    -4,   172,
       0,     0,    -4,    -4,     0,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     6,     0,
       0,     0,     0,    -4,     0,     0,     7,     8,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     9,    10,    -4,    -4,    -4,    -4,     0,     0,     0,
       0,     0,     0,    -4,    11,    12,    13,     0,     0,    14,
      15,     0,    16,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,    87,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,  1489,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,     0,     0,  1544,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,     0,
       0,  1554,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,     0,     0,  1555,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,     0,     0,  1576,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,  1579,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,     0,     0,  1582,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,     0,
       0,  1609,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,     0,     0,  1613,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,     0,     0,  1648,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,  1650,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,     0,     0,  1652,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,     0,
       0,  1670,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,     0,     0,  1694,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,     0,     0,  1731,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,  1732,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,     0,     0,  1733,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,     0,
       0,  1734,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,   953,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,   954,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,   955,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,   986,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1072,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1113,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1114,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,  1169,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,  1304,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1305,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1306,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1307,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,  1342,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,  1343,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1350,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1490,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1491,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,  1492,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,  1493,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1509,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1510,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1514,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,  1594,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,  1595,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1596,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1597,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1604,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,  1607,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,  1644,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1661,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1662,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1663,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,  1664,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,  1703,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
       0,  1704,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,  1705,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
       0,     0,     0,  1706,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,   621,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,     0,     0,   796,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,   804,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,     0,     0,   810,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,   888,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,     0,
       0,   979,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,     0,     0,   980,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
       0,     0,     0,   412,     0,     0,     0,   984,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,     0,     0,
     985,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,     0,     0,   987,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,     0,     0,  1022,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,     0,     0,  1067,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
       0,     0,  1301,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,     0,     0,  1333,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,     0,     0,  1478,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,   670,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
     674,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,   675,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,   677,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,   679,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,   680,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
       0,     0,     0,   412,     0,   683,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,   684,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,   779,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,   787,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,   788,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
     789,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,   795,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,   912,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,   917,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,   922,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
       0,     0,     0,   412,     0,   925,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,   926,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,   932,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,   937,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,   938,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
     939,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,   970,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412,     0,   972,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,     0,   973,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,     0,     0,
       0,     0,   412,     0,   974,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,     0,
       0,     0,     0,   412,     0,   978,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,   412,     0,  1200,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,     0,     0,     0,     0,   412,     0,  1383,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,     0,  1400,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,     0,  1423,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,     0,
    1603,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
       0,  1668,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     0,     0,     0,     0,
     412
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1286)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,   254,   239,     3,   385,   360,   387,   362,     4,  1294,
       4,   481,   482,   266,     5,   370,     6,   969,     7,     6,
     107,     5,     4,   965,     4,   177,   178,     6,     6,     4,
       6,     4,   187,     4,     6,     5,     5,    77,     4,   194,
       4,     4,   194,     5,     3,     5,     4,     6,     4,     6,
       4,   187,     6,     5,     5,     5,     5,     0,     6,     6,
       6,   314,    65,   316,     4,     6,     6,     4,     6,    94,
       6,   189,   177,   178,   177,   178,    79,   187,   196,   104,
    1365,   188,    49,    50,   187,    52,   193,   112,   113,   114,
     195,   194,   543,   118,   119,   120,   121,   134,    71,    13,
     177,   178,    75,     7,    98,    99,   100,   101,     7,     6,
     147,   148,   106,   187,    87,   109,   193,    71,   195,    74,
      79,     4,    77,   189,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,     6,   587,   588,   589,   590,
     591,   592,   593,   184,   185,     7,   597,   598,   599,   187,
     122,   189,   187,   124,   125,   126,   127,   608,   196,   134,
     135,   143,     6,  1448,   615,   122,     6,   137,   137,   172,
     195,   177,   178,   173,   122,   137,   187,   137,   189,  1464,
     191,   184,   185,   194,   565,   196,   122,   188,   194,   192,
     177,   178,   193,   189,  1136,   191,   174,   200,   174,   202,
     196,     6,   191,   194,   207,   184,   185,   187,   211,   199,
     194,   214,   194,   172,   194,   218,   219,   220,   221,   472,
     473,   224,   225,   226,   195,   184,   185,     6,   194,   187,
     194,   194,   235,   192,   194,   238,   194,   618,   194,   492,
     621,   200,   194,   194,   194,   194,   187,   194,   194,   189,
     187,   134,   135,   194,   177,   178,   189,   260,   261,   262,
     164,   165,   166,   167,    81,   164,   165,   166,   167,   272,
     273,   194,   189,     7,   191,   242,   243,   177,   178,   196,
     184,   185,   285,   250,   287,   184,   185,   254,     4,     5,
     177,   178,   191,   193,   187,   195,   189,   550,   177,   178,
     387,     7,   164,   165,   166,   167,   193,   187,   195,   562,
     184,   185,   184,   185,   193,    77,    77,    79,   321,   322,
     194,  1606,   194,    39,    40,    41,    42,    43,    44,    94,
     333,     8,    48,   187,   177,   178,   326,    53,    54,   104,
     194,    57,   177,   178,   179,   180,   181,   112,   113,   114,
     193,   186,    68,   118,   119,   120,   121,   360,   361,   362,
     363,   364,   365,   366,   367,   368,    74,   370,   371,    77,
     184,   185,   375,   376,   377,   378,   379,   191,     8,   177,
     178,   187,   361,   373,   363,   364,   365,   187,   367,   368,
     380,   187,   371,   396,   194,   193,   375,   376,   377,   378,
     187,   360,   361,   362,   363,   364,   365,  1692,   367,   368,
     187,   370,   371,   187,     7,   189,   375,   376,   377,   378,
     379,    77,   196,   804,   875,   177,   178,   177,   178,   432,
     164,   165,   166,   167,   150,   151,     6,     8,   187,   177,
     178,   193,   189,   193,   191,   194,   162,   177,   178,   196,
     184,   185,   194,   904,   905,   193,   184,   185,   164,   165,
     166,   167,   188,   193,   190,   718,   194,   193,   184,   185,
     460,   461,   462,   463,   193,   191,   195,     6,   184,   185,
      71,   481,   482,    74,   188,   188,    77,   574,    79,   193,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   508,   509,   510,    77,   186,
     177,   178,   479,   480,    74,    77,   519,    77,   195,    79,
     487,  1473,   188,  1475,   190,  1477,   193,    79,   194,    71,
     533,   188,    74,   190,   621,    77,   193,   540,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   933,   934,   935,   936,   186,   188,   188,   190,
     519,   190,   187,   194,   193,   568,   177,   178,   177,   178,
    1021,   164,   165,   166,   167,  1026,  1027,  1028,  1029,  1030,
     190,    74,   193,   193,   193,  1036,  1037,   179,   180,   181,
    1532,   184,   185,  1535,   186,   194,  1538,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   177,   178,   177,   178,   186,   193,   620,   195,    71,
     177,   178,    74,    74,   195,    77,    77,   193,    79,   193,
     867,   194,   622,   188,    77,   190,   193,  1589,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     6,   657,    74,   659,   186,   188,   662,
     190,  1042,   665,   193,   667,   177,   178,    74,   671,   672,
      71,    77,   759,    74,   177,   178,    77,  1058,    79,   669,
     188,   193,   190,   662,   202,   193,  1628,     4,   667,   207,
     193,   188,   695,   211,     4,  1647,   193,  1649,     4,  1651,
     218,     4,  1153,   662,   188,  1657,   665,   187,   667,   193,
     187,   714,   715,  1164,   187,   177,   178,   804,   177,   178,
     187,   177,   178,   810,   188,   177,   178,   188,     6,   193,
    1672,   193,   193,  1675,   193,   187,  1678,   193,   193,  1681,
     195,     6,   194,   193,  1696,   195,  1698,   193,  1700,   195,
     189,   219,   220,   221,   721,     4,   224,   225,   226,   762,
     193,   728,   195,   188,   193,   190,   195,   734,   771,   187,
     773,  1713,   775,  1715,   777,  1717,   193,     4,   195,   782,
       6,     7,   785,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   260,   261,   187,   193,   186,   195,   801,  1180,
     803,   888,  1272,  1273,   272,   273,   193,   810,   195,   193,
     187,   195,  1049,     6,     7,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   177,
     178,   810,   835,   186,    77,   187,    79,   840,   841,   842,
     843,   187,   193,   202,   195,    77,   187,    79,   207,   187,
     853,   810,   211,   187,   844,     6,   193,   187,   195,   218,
     193,   840,   195,   842,   843,   187,   187,   870,   871,   872,
     873,     7,   187,  1324,   853,   193,   187,   195,   396,    94,
     193,   840,   195,   842,   843,   194,    12,    13,     6,   104,
     893,   193,     6,   195,   853,   194,   194,   112,   113,   114,
     987,   187,   187,   118,   119,   120,   121,   910,   911,   193,
     913,   195,   915,   916,   893,   194,   919,   920,   193,   187,
     195,   924,   193,   193,   195,   195,   285,   193,   287,   195,
     193,   193,   195,   195,   893,   193,   193,   195,   195,   906,
     193,     4,   195,     6,     4,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,  1042,    82,    94,   193,   187,
     195,    87,    88,   194,    90,    91,    92,   104,   187,   193,
      96,   195,   194,   187,  1211,   112,   113,   114,   187,   187,
     195,   118,   119,   120,   121,   187,   953,   954,   955,   187,
     508,   509,   510,   193,   193,   195,   195,   193,  1468,   195,
    1003,  1004,  1005,   129,   130,   131,   193,   193,   195,   195,
     193,  1014,   195,   187,   193,   533,   195,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   193,   193,   195,   195,   186,   193,   396,   195,   193,
     193,   195,   195,   193,   193,   195,   195,   187,    12,    13,
     568,   193,   193,   195,   195,   193,   187,   195,   195,   193,
    1063,   195,    94,   193,   193,   195,   195,   194,   187,   195,
     194,   194,   104,   432,   187,   187,     6,   194,  1081,  1434,
     112,   113,   114,  1073,  1087,   189,   118,   119,   120,   121,
    1093,   194,  1095,  1096,   194,  1182,   189,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,   189,   189,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   189,    82,  1122,
       6,     6,   191,    87,    88,   137,    90,    91,    92,   194,
     196,     6,    96,     6,  1137,    94,     6,   196,  1141,   657,
    1143,   659,   194,   194,     6,   104,   189,     4,   186,   508,
     509,   510,   191,   112,   113,   114,     7,   194,   189,   118,
     119,   120,   121,   195,   193,   129,   130,   131,  1135,    94,
     195,   193,     7,     6,   533,     6,     6,   188,     7,   104,
      94,   540,     7,     7,     6,   194,  1189,   112,   113,   114,
     104,     7,     6,   118,   119,   120,   121,   715,   112,   113,
     114,    94,  1439,  1193,   118,   119,   120,   121,     7,   568,
    1189,   104,     6,  1203,  1217,  1302,     6,     6,     4,   112,
     113,   114,    50,    50,  1227,   118,   119,   120,   121,  1482,
    1189,   195,    50,    50,   134,   188,   195,   194,     6,     6,
    1230,   188,   188,   193,   762,   193,     6,   188,  1227,   193,
     193,   193,   188,   771,   188,   773,     4,   775,   190,   777,
       4,     6,     4,     6,   782,     6,     6,   785,  1227,     7,
     195,  1238,  1272,  1273,   137,    21,    22,     7,  1268,     7,
       7,   195,   137,     7,     6,   137,     7,     7,     7,  1292,
     194,  1294,     6,  1296,   188,   191,   188,   188,   657,   188,
     659,     6,   195,   190,     7,   195,   194,  1274,  1311,  1276,
     194,  1278,   671,   672,   195,  1318,   194,   835,  1321,     7,
     194,     7,  1325,     6,    94,  1292,   191,  1317,  1295,  1296,
     194,     6,     6,     6,   104,  1325,  1326,  1590,     6,   189,
       7,  1344,   112,   113,   114,     6,   187,   187,   118,   119,
     120,   121,   870,   871,   872,   873,   715,   194,     6,   174,
     106,     7,  1365,     7,     7,     7,    79,     7,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     7,     7,     6,  1399,     7,     7,   145,
       7,  1404,   148,   762,     7,     6,   924,   153,   154,     6,
       4,     4,   771,   159,   773,     6,   775,    94,   777,   194,
       6,  1424,   187,   782,     7,   195,   785,   104,  1431,     6,
     194,  1434,     7,     7,     7,   112,   113,   114,     6,     6,
       6,   118,   119,   120,   121,  1448,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      77,  1464,  1465,     6,   186,     6,     4,     4,  1468,     4,
     195,   188,     6,     4,     6,  1434,   835,     6,  1481,    12,
      13,     6,     6,  1486,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   188,
     193,   188,     7,   186,   188,  1472,   191,  1474,   187,  1476,
     191,   870,   871,   872,   873,     6,   194,  1484,   195,     6,
    1487,     6,     6,   194,   194,    87,     6,     6,   194,   194,
       6,   277,   194,     6,     6,     5,     4,  1540,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   294,    82,
       6,   189,    86,    87,    87,    88,     7,    90,    91,    92,
     194,   194,     6,    96,     6,   924,     6,     6,   194,   194,
    1560,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     4,   194,   133,  1591,   186,
    1593,    94,     6,     6,     6,   193,   129,   130,   131,     6,
       4,   104,     4,  1606,    94,     6,     4,     6,  1611,   112,
     113,   114,     6,     6,   104,   118,   119,   120,   121,     6,
       6,     4,   112,   113,   114,  1143,  1593,     6,   118,   119,
     120,   121,   166,   167,   168,   169,   170,     6,     6,     6,
       5,   194,     6,     6,   137,     6,     6,     6,  1638,   183,
       6,     6,     6,   187,     6,     6,  1659,     6,     6,     6,
       6,     6,   195,   193,  1667,     6,   188,   201,   202,   203,
     204,     6,   206,   207,   208,   209,     7,   211,   212,   213,
       6,     6,   191,     6,   218,     6,   194,     5,  1667,  1692,
      75,     6,   195,   194,     6,   194,     6,   195,   195,    94,
     194,     7,   236,     6,  1707,   195,  1709,   132,  1667,   104,
       6,   245,   246,   194,     6,   135,   194,   112,   113,   114,
     254,     6,     6,   118,   119,   120,   121,   194,  1707,   195,
    1709,     6,  1735,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     6,     6,     6,  1707,   186,
    1709,   285,   286,   287,     6,     6,  1735,     6,   194,     6,
       6,     6,   194,   297,   298,   299,   194,   301,   195,     6,
     304,   305,    94,   194,   308,     6,  1735,     6,    94,     6,
       6,     6,     6,     6,  1143,     6,   195,     6,     6,   323,
       6,   194,     6,     6,   194,     6,     6,   194,   194,     6,
     195,     6,   336,   194,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,     6,     6,   194,     6,
       6,     6,   194,     6,     6,   369,   194,   194,   372,     6,
     374,     6,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,     6,     6,     6,  1070,
     186,   395,   396,  1563,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   428,
    1453,   415,  1454,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     3,   432,  1080,
       3,   186,   458,  1207,   438,    -1,  1424,    -1,    -1,   443,
      -1,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,    -1,
     454,   455,    -1,    -1,    -1,   459,   460,   461,   462,   463,
     464,   465,   466,  1292,    -1,    -1,    -1,  1296,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,    -1,    -1,
     484,   485,   486,   487,   488,   489,    -1,    -1,    -1,   493,
     494,   495,   496,   497,    -1,    -1,    -1,   501,  1486,    -1,
     504,   505,    -1,    -1,   508,   509,   510,    -1,    -1,   513,
     514,   515,   516,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,    -1,    -1,   539,   540,    -1,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,
      -1,    -1,    -1,   567,   568,    12,    13,    -1,   572,    -1,
      -1,    -1,    -1,    -1,    -1,  1404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,  1424,    -1,    53,    54,    -1,
      -1,    57,  1431,  1591,    -1,  1593,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,   623,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,  1465,    12,    13,    -1,
      87,    88,    -1,    90,    91,    92,    -1,    -1,    -1,    96,
     654,    -1,    -1,   657,    -1,   659,   660,  1486,    -1,    -1,
      -1,    -1,    -1,    -1,   668,    -1,    -1,   671,   672,    -1,
      -1,  1659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   685,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
     694,    -1,    -1,    -1,   150,   151,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   162,    82,    -1,    -1,
      -1,   715,    87,    88,    -1,    90,    91,    92,   722,   723,
      -1,    96,    -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,   741,     6,    -1,
     744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,    -1,   762,    -1,
      -1,    -1,  1591,    -1,  1593,    -1,    -1,   771,    -1,   773,
      -1,   775,    -1,   777,    -1,    -1,    -1,     6,   782,    -1,
      -1,   785,    -1,    -1,    -1,    -1,    -1,   791,    -1,   793,
     794,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    91,    92,    -1,    12,    13,    96,    -1,    -1,   823,
     195,    -1,    -1,    -1,    -1,    -1,    -1,   831,   832,   833,
    1659,   835,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   850,    -1,    -1,   129,
     130,   131,    -1,   857,    -1,    -1,   860,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   870,   871,   872,   873,
      -1,    -1,   876,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    91,    92,    -1,    -1,    -1,    96,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   214,   195,    -1,    -1,   186,    -1,
     924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,    -1,   235,    -1,    -1,   238,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,   262,    -1,    12,    13,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,   983,
      -1,   186,   986,    -1,    -1,    -1,   990,    -1,   992,   993,
     994,    -1,    -1,    -1,    -1,    -1,  1000,   195,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,  1018,    -1,   186,    -1,    -1,    -1,
      -1,   321,   322,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   333,    82,    -1,    -1,    12,    13,    87,
      88,    -1,    90,    91,    92,    -1,  1050,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1061,  1062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,  1072,  1073,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    82,  1112,  1113,
    1114,    -1,    87,    88,    -1,    90,    91,    92,  1122,    -1,
    1124,    96,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,  1135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1169,  1170,  1171,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     6,    82,    -1,
    1204,    -1,    -1,    87,    88,    -1,    90,    91,    92,    -1,
      -1,    -1,    96,    -1,  1218,    -1,    -1,    -1,    -1,  1223,
     195,    -1,    -1,    -1,    -1,    -1,  1230,    -1,    -1,    -1,
      -1,    -1,  1236,  1237,    -1,    -1,    -1,    -1,    -1,  1243,
    1244,    -1,    -1,    -1,  1248,   129,   130,   131,    -1,    -1,
      -1,    -1,  1256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1266,    -1,  1268,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1280,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1292,    -1,
      -1,    -1,  1296,    -1,    -1,  1299,    -1,    -1,    -1,    -1,
    1304,  1305,  1306,  1307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,  1317,    -1,    -1,    -1,    -1,    -1,    -1,
     620,    -1,  1326,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    -1,    -1,  1342,  1343,
      87,    88,    -1,    90,    91,    92,  1350,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
    1384,    -1,   129,   130,   131,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   695,    -1,    -1,  1402,    -1,
    1404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   714,  1419,    -1,  1421,    -1,    -1,
    1424,    39,    40,    41,    42,    43,    44,  1431,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,
    1444,    -1,    -1,    -1,    -1,  1449,    -1,    -1,   195,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,  1465,    -1,    -1,    -1,    -1,    -1,    -1,  1472,    -1,
    1474,    -1,  1476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1486,    -1,    -1,    -1,  1490,  1491,  1492,  1493,
    1494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,   801,    -1,   803,    -1,  1509,  1510,    -1,    -1,    -1,
    1514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
    1524,    -1,    -1,    -1,  1528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   841,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1558,    -1,    -1,    -1,    -1,  1563,
      -1,    -1,    -1,    -1,    -1,    -1,  1570,    -1,    -1,    -1,
      -1,    -1,    -1,  1577,    -1,    -1,  1580,    -1,    -1,  1583,
      -1,    -1,    -1,  1587,    -1,    -1,    -1,  1591,    -1,  1593,
    1594,  1595,  1596,  1597,    -1,    -1,    -1,    -1,    -1,    -1,
    1604,    -1,    -1,  1607,    -1,    -1,    -1,    -1,    -1,    -1,
     910,   911,    -1,   913,    -1,   915,   916,    -1,    -1,   919,
     920,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
    1644,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1659,    -1,  1661,  1662,  1663,
    1664,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,  1703,
    1704,  1705,  1706,  1003,  1004,  1005,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,  1014,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    -1,  1063,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,  1081,    -1,    -1,    -1,    -1,    -1,  1087,    -1,    -1,
      -1,    -1,    -1,  1093,    -1,  1095,  1096,    -1,    -1,    -1,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,  1122,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,    -1,    -1,
      -1,  1141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,    -1,     7,     8,   182,
      -1,    -1,    -1,    -1,   187,    -1,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
       8,    -1,    -1,    -1,  1294,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,
      -1,  1311,    -1,    -1,    -1,    -1,    -1,    -1,  1318,    91,
      -1,  1321,    -1,    -1,    -1,  1325,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,  1344,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,  1365,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1399,
      -1,    -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    -1,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,     8,    -1,
     192,    -1,   194,   195,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,  1448,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,  1464,    -1,    -1,    -1,   186,    -1,
       8,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,  1481,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
    1540,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,    -1,    -1,   109,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1606,    -1,    -1,    -1,
      -1,  1611,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     8,   177,   178,    -1,   186,    -1,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
     192,    -1,    -1,   195,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,     3,     4,     5,   186,    -1,    -1,     9,    10,
      11,    -1,  1692,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,    -1,    -1,     8,    -1,   157,   158,   159,   160,
     161,   162,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   177,   178,    -1,    -1,
     186,   182,   188,    -1,    -1,    -1,   187,   193,     3,     4,
       5,   192,    -1,   194,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      -1,    -1,    57,    -1,    59,    60,    61,    -1,     3,     4,
       5,    -1,    67,    68,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      -1,    -1,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   177,   178,    -1,    -1,   186,   182,    -1,    -1,
      -1,    -1,   187,   193,    -1,   195,    -1,   192,    -1,   194,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   149,   150,   151,   152,   186,    -1,
     188,    -1,   157,   158,   159,   160,   161,   162,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   177,   178,    -1,    -1,   186,   182,    -1,    -1,
      -1,    -1,   187,   193,     3,     4,     5,   192,    -1,   194,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    12,    13,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    88,    -1,    90,    91,    92,    -1,    -1,
      -1,    96,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     149,   150,   151,   152,   129,   130,   131,    -1,   157,   158,
     159,   160,   161,   162,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   177,   178,
      -1,    -1,   186,   182,    -1,    -1,    -1,    -1,   187,   193,
       3,     4,     5,   192,    -1,   194,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,   109,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,   177,   178,    -1,   186,    -1,   182,
      -1,    -1,    -1,    -1,   187,   194,     3,     4,     5,   192,
      -1,   194,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,   109,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
     177,   178,    -1,   186,    -1,   182,    -1,    -1,    -1,    -1,
     187,   194,     3,     4,    -1,   192,    -1,   194,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,    -1,    -1,   109,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,   177,   178,    -1,   186,
      -1,   182,    -1,    -1,    -1,    -1,   187,   194,     3,     4,
      -1,   192,    -1,   194,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,   109,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   177,   178,    -1,    -1,   186,   182,    -1,    -1,
      -1,    -1,   187,   193,     3,     4,    -1,   192,    -1,   194,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
     109,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   177,   178,
      -1,    -1,   186,   182,    -1,    -1,    -1,    -1,   187,   193,
       3,     4,    -1,   192,    -1,   194,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,   109,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   177,   178,    -1,    -1,   186,   182,
      -1,    -1,    -1,    -1,   187,   193,     3,     4,    -1,   192,
      -1,   194,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,   109,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     177,   178,    -1,    -1,   186,   182,    -1,    -1,    -1,    -1,
     187,   193,     3,     4,    -1,   192,    -1,   194,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,     3,     4,     5,    -1,    -1,    67,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,   149,    -1,
      -1,   152,    -1,    -1,   195,    -1,   157,   158,   159,   160,
     161,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,   177,   178,    -1,   186,
      -1,   182,    -1,    -1,    -1,    -1,   187,    -1,   195,    -1,
      -1,   192,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   177,   178,    -1,    -1,   186,
     182,     3,     4,    -1,    -1,   187,   193,     9,    10,    11,
     192,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,    -1,    -1,   109,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   177,   178,    -1,    -1,   186,
     182,     3,     4,    -1,    -1,   187,   193,     9,    10,    11,
     192,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    59,    60,    61,
      -1,     9,    10,    11,    -1,    67,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   195,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,   177,   178,    -1,   186,    -1,
     182,    -1,    -1,    -1,    -1,   187,    -1,   195,   190,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   177,
     178,    -1,    -1,   186,   182,   188,    -1,   190,    -1,   187,
       3,     4,   190,    -1,   192,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    -1,   182,
      50,    51,    52,    -1,   187,    55,    56,    -1,    58,   192,
      -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,   115,   116,   117,     4,    -1,
      -1,    -1,    -1,   123,    -1,    -1,    12,    13,   128,   129,
     130,   131,    -1,    -1,   134,    -1,   136,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    37,    38,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    50,    51,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,
      66,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,    -1,   134,    -1,
     136,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,   154,   155,
     156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   198,   199,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    55,    56,    58,    62,    63,    65,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   115,   116,   117,   123,   128,   129,   130,   131,
     134,   136,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   153,   154,   155,   156,   163,   200,   202,
     203,   223,   240,   241,   244,   245,   246,   247,   248,   249,
     250,   251,   272,   273,   274,   275,   293,   294,     3,     4,
       5,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    53,    54,    57,
      59,    60,    61,    67,    68,   143,   149,   150,   151,   152,
     157,   158,   159,   160,   161,   162,   177,   178,   182,   187,
     189,   191,   192,   194,   196,   221,   276,   277,   289,   290,
     293,   294,    13,    77,   187,   187,     6,   194,     6,     6,
       6,     6,   187,     6,     6,   189,   189,   187,   189,   221,
     221,   187,   194,   187,   187,     4,   187,   194,   187,   187,
       4,   194,   187,   187,    81,    77,    77,     6,   194,    71,
      74,    77,    77,    77,    74,    77,    79,    79,    71,    74,
      77,    79,    74,    77,    79,    74,    77,   187,    74,   134,
     147,   148,   194,   177,   178,   187,   194,   279,   280,   279,
     194,    71,    74,    77,   194,   279,     4,    71,    75,    87,
      77,    79,    77,    74,     4,   143,   194,     4,     6,    71,
      74,    77,    74,    77,     4,     4,     4,     4,     5,    36,
      71,    74,    77,    79,    91,   178,   187,   194,   241,   251,
     276,   282,   283,   284,   293,   294,     4,   187,   187,   187,
       4,   194,   286,     4,   187,   187,     6,     6,   189,     4,
     293,   294,     4,     5,   194,     5,   194,     4,   276,   276,
       6,   187,   194,   189,   196,   221,     7,   164,   165,   166,
     167,   184,   185,   219,   220,     4,   189,   191,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   187,   187,   187,   187,   187,   187,   221,
     187,   221,   221,   221,     7,   187,   187,   187,   221,   187,
     187,   276,   276,   276,   276,   190,   276,     4,   134,   135,
     294,     4,   241,   242,   243,   194,   194,     6,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   186,   194,     6,   189,   220,     6,   276,     4,
     289,   290,   294,   289,   276,   289,   292,   225,   228,   290,
     294,   276,   178,   276,   284,   285,   276,   276,   187,   276,
     285,   276,   276,   187,   285,   276,   276,   282,   187,   194,
     285,   283,   283,   283,   187,   187,   283,   283,   283,   187,
     187,   187,   187,   187,   187,   187,   187,   282,   276,     4,
     282,   286,   194,   194,   279,   279,   279,   276,   276,   177,
     178,   194,   194,   279,   194,   194,   194,   177,   178,   187,
     243,   279,   194,   187,   194,   187,   187,   187,   283,   283,
     282,   187,     4,     6,   189,   189,   243,     6,   194,   194,
     194,   283,   283,   189,   189,   189,   189,   191,   221,   189,
       5,   137,   194,     5,   137,     5,   137,     5,   137,    71,
      74,    77,    79,   194,   276,   284,   276,   195,   285,     8,
     179,     6,   189,   221,     6,   276,   276,   276,   191,   276,
     194,   137,   276,   276,   276,     6,     6,   243,     6,   243,
     189,     6,   194,   282,   282,   190,   276,   194,   194,   290,
     282,     6,   189,   276,     4,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   292,   289,   292,
     289,   289,   289,   282,   289,   289,   276,   292,   289,   276,
     290,   276,   289,   289,   289,   289,   294,   290,   188,     7,
     219,   190,     7,   219,   220,   191,     7,   189,   195,    71,
      74,    77,    79,   240,   276,   285,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   204,   276,     6,   189,   191,   188,   193,   188,   193,
     193,   188,   193,   190,   193,   224,   190,   224,   193,   193,
     188,   179,   193,   195,   188,   188,   276,   188,   195,   188,
     188,   276,   195,   188,   188,     7,   276,   276,   195,     6,
       6,     6,   276,   276,     7,     7,   269,   269,   276,   234,
     276,   290,   235,   276,   290,   236,   276,   290,   237,   276,
     290,   276,   276,   276,     7,   194,   188,     6,   194,   243,
     243,   193,   193,   193,   279,   279,   242,   242,   193,   276,
     276,   276,   276,   255,   193,   243,   276,   276,   276,   276,
     276,     7,   270,     6,     7,   276,     6,   276,   276,   195,
     285,   285,   285,     6,     6,   276,   276,   276,   276,     4,
     188,   190,   194,   222,   294,    50,   276,    50,    50,    50,
       5,   194,     5,   194,     5,   194,     5,   194,   285,   188,
     195,   276,   194,   276,   284,   194,   222,   188,   188,   188,
     134,   193,   243,   194,     8,   188,   190,   195,   195,   243,
     188,   193,   195,   219,   190,   276,   285,     6,     6,   276,
     190,   220,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   193,   222,   222,   222,   222,   222,   222,
     222,   193,   193,   193,   222,   193,   222,   222,   188,   188,
     193,   193,   193,   193,   193,   188,   222,   278,   291,     6,
     193,   188,   188,   193,   222,   188,   188,   219,   282,   191,
     219,   220,   290,   276,     6,     4,     4,   194,   287,   190,
     194,   194,   194,   194,   195,   195,     8,     4,   124,   125,
     126,   127,   195,   207,   211,   214,   216,   217,   190,   276,
       4,     6,   174,   201,   285,     6,   285,   276,     6,   289,
       6,   294,     6,   289,   276,   290,     7,   276,   284,   137,
       7,     7,   188,     7,   137,     7,     7,   188,   137,     7,
       7,   276,   188,   195,   194,   188,   188,   276,   282,     4,
     268,     6,   188,   188,   188,   188,   188,   188,   188,   188,
     282,   285,   191,   243,   195,   195,   279,   276,   276,   195,
     195,   276,   279,   193,   193,   193,    94,   104,   112,   113,
     114,   118,   119,   120,   121,   265,   266,   279,   195,   252,
     188,   195,   188,   188,   188,   276,     6,   276,   188,   190,
     190,   195,   195,   195,   190,   190,   193,   190,   285,   190,
     194,   195,   194,   194,   194,   285,   285,   285,   285,   195,
       8,   285,   285,     7,     7,     7,   191,   276,   195,   276,
     276,     7,   191,   195,   194,   282,     6,   282,   219,   220,
     195,   195,   190,   191,   220,   289,   276,   276,   276,   276,
     285,   289,   282,   289,   289,   290,   230,   232,   276,   289,
     276,     6,     4,   134,   135,   276,     6,     6,     6,     7,
     189,   286,   288,     6,   285,   285,   285,   285,   222,   276,
     208,   187,   187,   194,   218,     6,   220,   190,   174,   289,
     188,   188,   193,     7,   222,   222,   279,    77,    79,   282,
     282,     7,   282,    77,    79,   282,   282,     7,    79,   282,
     282,     6,     7,     7,   285,     7,     7,    94,   267,     6,
       7,   219,   219,   219,   219,     7,     7,     7,     6,   195,
       4,   195,   193,   193,   193,   195,   195,   279,   279,   279,
       4,     6,   194,     6,   187,     6,   122,     6,   122,     6,
     122,     6,   122,   195,   266,   193,   265,     7,     6,     7,
       7,     7,     6,   194,     6,     6,     6,    77,   276,     6,
       6,   276,   191,   195,   276,   276,   276,   276,   195,   195,
     195,   195,   276,   195,   195,   282,   282,   282,     4,   193,
       8,     8,   188,     4,     4,   282,   195,     6,   276,     6,
     222,     6,     4,     6,   222,   222,   222,   222,   222,   193,
     188,   188,   188,   193,   193,   222,   231,   193,   222,   233,
     188,   188,     6,     7,   219,   220,   191,     7,     6,   286,
     276,   193,   195,   195,   195,   195,   195,   219,   187,   276,
     276,   281,   282,   194,   191,     6,     6,   201,     6,   276,
     194,   276,   290,     6,     6,     6,   194,   194,    87,   239,
     239,   282,     6,   194,   194,     6,     6,   282,   194,     6,
       6,     5,   282,   195,   282,   282,     4,     6,   282,   282,
     282,   282,   282,   282,   282,   282,     7,     6,     7,   276,
     276,   276,   194,   194,   193,   195,   193,   195,   193,   195,
     189,   276,   282,   276,     6,     6,     6,     6,   276,   279,
     195,     5,   194,   282,   194,   194,   194,   282,   285,   194,
       6,   190,     4,   222,   193,   193,   193,   193,   222,     6,
       6,   133,   276,   276,   276,     6,     6,     7,   193,     6,
       6,   219,   220,   289,   290,     4,     4,   290,   276,     6,
       4,   287,     6,   190,   286,     6,     6,     6,     6,   282,
     205,   276,   193,   193,   193,   195,   206,   276,     4,   289,
     193,   276,   290,   276,   276,   279,     6,     6,     6,   276,
     276,     6,   276,     5,     6,   194,     6,   137,   238,   276,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   276,
     276,   290,   195,   188,   193,   195,   242,   242,   279,     6,
     256,   279,     6,   257,   279,     6,   258,   276,   195,   193,
     188,   195,   193,     6,   178,   279,     6,   281,   279,   279,
       6,   195,   276,     6,   276,   276,   276,   276,   282,   193,
     195,     8,   195,   188,   194,   276,   290,   282,   282,   188,
     222,   194,   282,   290,   194,   276,   290,     6,     6,     7,
       6,   191,     6,   188,   193,   276,   276,   282,   194,   193,
     195,     6,   276,   226,   227,   195,   195,   195,   195,   195,
       5,   281,    75,     6,   194,   194,     6,     6,   194,   276,
     195,   195,   193,   194,   193,   194,   193,   194,   190,     6,
     282,     7,   194,   276,   193,   195,   193,   193,     6,   195,
     193,   193,   193,   193,   132,   276,   276,   285,     6,     6,
     195,     6,   229,   276,   292,   286,   135,   209,   276,   193,
     193,   281,   276,     6,   193,   230,   232,     6,     6,     6,
       6,     6,     6,   195,   194,   281,   285,   242,   193,   195,
     276,   279,   265,   276,   279,   265,   276,   279,   265,     6,
     193,   195,   282,   243,   195,   279,     6,   285,   279,   276,
     276,   276,   276,   276,   195,   195,   195,     6,   193,   195,
       7,   195,     6,   194,   276,   276,   195,   276,   195,   195,
     194,   276,   195,   195,   195,   276,   195,   193,   195,   195,
     193,   195,   195,   193,   195,   282,     6,    94,   195,   253,
     194,   193,   195,   193,   193,   193,   193,   193,     6,     6,
     276,   290,   206,   188,   193,     6,   194,   193,   276,   195,
       6,    94,   271,   195,     6,   259,   276,     6,     6,   260,
     276,     6,     6,   261,   276,     6,   195,   276,   265,   243,
     285,     6,   279,   285,   276,   276,   276,   276,     7,   195,
     212,   276,   281,   276,   193,   282,     6,   194,   195,   194,
     195,   194,   195,     6,     6,   195,   195,   254,   195,   193,
     195,   193,   193,   193,   193,   290,     6,   194,   188,   195,
     195,   276,   265,     6,   262,   265,     6,   263,   265,     6,
     264,   265,     6,   285,     6,   276,   276,   276,   276,   210,
     289,   215,   194,     6,   195,   195,   194,   195,   194,   195,
     194,   195,   195,   193,   193,   193,   193,   193,   195,   194,
     281,     6,     6,   265,     6,   265,     6,   265,     6,   276,
     276,   276,   276,   289,     6,   213,   289,   195,   195,   195,
     195,   195,   195,   195,   195,   193,   195,     6,     6,     6,
       6,   289,     6
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
#line 733 "Gmsh.y"
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
#line 762 "Gmsh.y"
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
#line 791 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 796 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 801 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 806 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 813 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 820 "Gmsh.y"
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

  case 83:
/* Line 1787 of yacc.c  */
#line 835 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 840 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 845 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 854 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 860 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 869 "Gmsh.y"
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

  case 89:
/* Line 1787 of yacc.c  */
#line 887 "Gmsh.y"
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

  case 90:
/* Line 1787 of yacc.c  */
#line 905 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 914 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 926 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 931 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 939 "Gmsh.y"
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

  case 95:
/* Line 1787 of yacc.c  */
#line 959 "Gmsh.y"
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

  case 96:
/* Line 1787 of yacc.c  */
#line 982 "Gmsh.y"
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

  case 97:
/* Line 1787 of yacc.c  */
#line 993 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 1001 "Gmsh.y"
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

  case 99:
/* Line 1787 of yacc.c  */
#line 1023 "Gmsh.y"
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

  case 100:
/* Line 1787 of yacc.c  */
#line 1046 "Gmsh.y"
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

  case 101:
/* Line 1787 of yacc.c  */
#line 1072 "Gmsh.y"
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

  case 102:
/* Line 1787 of yacc.c  */
#line 1093 "Gmsh.y"
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

  case 103:
/* Line 1787 of yacc.c  */
#line 1105 "Gmsh.y"
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

  case 107:
/* Line 1787 of yacc.c  */
#line 1123 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 1132 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1141 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1143 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
    }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 1153 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
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
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1178 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1186 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1192 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1204 "Gmsh.y"
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

  case 121:
/* Line 1787 of yacc.c  */
#line 1215 "Gmsh.y"
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

  case 122:
/* Line 1787 of yacc.c  */
#line 1230 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1246 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1254 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1263 "Gmsh.y"
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

  case 128:
/* Line 1787 of yacc.c  */
#line 1281 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1285 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1294 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1298 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1307 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1311 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1320 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1324 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1333 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1337 "Gmsh.y"
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

  case 138:
/* Line 1787 of yacc.c  */
#line 1349 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1353 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1363 "Gmsh.y"
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

  case 141:
/* Line 1787 of yacc.c  */
#line 1386 "Gmsh.y"
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

  case 142:
/* Line 1787 of yacc.c  */
#line 1418 "Gmsh.y"
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

  case 143:
/* Line 1787 of yacc.c  */
#line 1441 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1459 "Gmsh.y"
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

  case 145:
/* Line 1787 of yacc.c  */
#line 1480 "Gmsh.y"
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

  case 146:
/* Line 1787 of yacc.c  */
#line 1498 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1528 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1558 "Gmsh.y"
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

  case 149:
/* Line 1787 of yacc.c  */
#line 1576 "Gmsh.y"
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

  case 150:
/* Line 1787 of yacc.c  */
#line 1595 "Gmsh.y"
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

  case 151:
/* Line 1787 of yacc.c  */
#line 1621 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1639 "Gmsh.y"
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

  case 153:
/* Line 1787 of yacc.c  */
#line 1657 "Gmsh.y"
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

  case 154:
/* Line 1787 of yacc.c  */
#line 1692 "Gmsh.y"
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

  case 155:
/* Line 1787 of yacc.c  */
#line 1710 "Gmsh.y"
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

  case 156:
/* Line 1787 of yacc.c  */
#line 1749 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1755 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1761 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1768 "Gmsh.y"
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

  case 160:
/* Line 1787 of yacc.c  */
#line 1793 "Gmsh.y"
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

  case 161:
/* Line 1787 of yacc.c  */
#line 1818 "Gmsh.y"
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

  case 162:
/* Line 1787 of yacc.c  */
#line 1835 "Gmsh.y"
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1855 "Gmsh.y"
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

  case 164:
/* Line 1787 of yacc.c  */
#line 1888 "Gmsh.y"
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

  case 165:
/* Line 1787 of yacc.c  */
#line 1924 "Gmsh.y"
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

  case 166:
/* Line 1787 of yacc.c  */
#line 1942 "Gmsh.y"
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

  case 167:
/* Line 1787 of yacc.c  */
#line 1959 "Gmsh.y"
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

  case 168:
/* Line 1787 of yacc.c  */
#line 1975 "Gmsh.y"
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

  case 169:
/* Line 1787 of yacc.c  */
#line 2012 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 2017 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 2022 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 2027 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 2032 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 2037 "Gmsh.y"
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

  case 175:
/* Line 1787 of yacc.c  */
#line 2060 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2066 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2076 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2077 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2082 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2086 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2090 "Gmsh.y"
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

  case 182:
/* Line 1787 of yacc.c  */
#line 2113 "Gmsh.y"
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

  case 183:
/* Line 1787 of yacc.c  */
#line 2136 "Gmsh.y"
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

  case 184:
/* Line 1787 of yacc.c  */
#line 2159 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2187 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2208 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2235 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2256 "Gmsh.y"
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

  case 189:
/* Line 1787 of yacc.c  */
#line 2277 "Gmsh.y"
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

  case 190:
/* Line 1787 of yacc.c  */
#line 2297 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2409 "Gmsh.y"
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

  case 192:
/* Line 1787 of yacc.c  */
#line 2428 "Gmsh.y"
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

  case 193:
/* Line 1787 of yacc.c  */
#line 2467 "Gmsh.y"
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

  case 194:
/* Line 1787 of yacc.c  */
#line 2575 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 2584 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 2590 "Gmsh.y"
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

  case 197:
/* Line 1787 of yacc.c  */
#line 2605 "Gmsh.y"
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

  case 198:
/* Line 1787 of yacc.c  */
#line 2633 "Gmsh.y"
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

  case 199:
/* Line 1787 of yacc.c  */
#line 2650 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2659 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2673 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2687 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2693 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2699 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 2708 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 2717 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 2726 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 2740 "Gmsh.y"
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

  case 209:
/* Line 1787 of yacc.c  */
#line 2796 "Gmsh.y"
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

  case 210:
/* Line 1787 of yacc.c  */
#line 2814 "Gmsh.y"
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

  case 211:
/* Line 1787 of yacc.c  */
#line 2831 "Gmsh.y"
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

  case 212:
/* Line 1787 of yacc.c  */
#line 2846 "Gmsh.y"
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

  case 213:
/* Line 1787 of yacc.c  */
#line 2865 "Gmsh.y"
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

  case 214:
/* Line 1787 of yacc.c  */
#line 2877 "Gmsh.y"
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

  case 215:
/* Line 1787 of yacc.c  */
#line 2901 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2905 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2910 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2917 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2922 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2928 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2933 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2939 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2947 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2951 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 2955 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 2961 "Gmsh.y"
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
          if(List_Nbr((yyvsp[(9) - (16)].l)) != f.size()){
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

  case 227:
/* Line 1787 of yacc.c  */
#line 3015 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 3028 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
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

  case 229:
/* Line 1787 of yacc.c  */
#line 3045 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
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

  case 230:
/* Line 1787 of yacc.c  */
#line 3062 "Gmsh.y"
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
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3083 "Gmsh.y"
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
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3104 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
        const char *name = LoopControlVariablesNameTab[ImbricatedLoop - 1];
        if(name){
          if(!gmsh_yysymbols.count(name))
            yymsg(0, "Unknown loop variable '%s'", name);
          else{
            gmsh_yysymbol &s(gmsh_yysymbols[name]);
            if(!s.list && s.value.size()){
              s.value[0] += step;
              LoopControlVariablesTab[ImbricatedLoop - 1][0] = s.value[0];
            }
            else
              yymsg(0, "Bad loop variable %s", name);
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

  case 233:
/* Line 1787 of yacc.c  */
#line 3139 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3147 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3153 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3160 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3164 "Gmsh.y"
    {
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3173 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3189 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3197 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3203 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3211 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3217 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3225 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3231 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3239 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3253 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3260 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3267 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3274 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3281 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3288 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3295 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3309 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3322 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3329 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3335 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3342 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3348 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3355 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3361 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3368 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3374 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3381 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3387 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3394 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3400 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3407 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3413 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3420 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3426 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3437 "Gmsh.y"
    {
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3440 "Gmsh.y"
    {
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3446 "Gmsh.y"
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

  case 279:
/* Line 1787 of yacc.c  */
#line 3458 "Gmsh.y"
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

  case 280:
/* Line 1787 of yacc.c  */
#line 3478 "Gmsh.y"
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

  case 281:
/* Line 1787 of yacc.c  */
#line 3502 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3506 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3510 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3514 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3518 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3524 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3530 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3534 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3538 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3542 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3546 "Gmsh.y"
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

  case 292:
/* Line 1787 of yacc.c  */
#line 3565 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3577 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3581 "Gmsh.y"
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

  case 295:
/* Line 1787 of yacc.c  */
#line 3596 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3600 "Gmsh.y"
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

  case 297:
/* Line 1787 of yacc.c  */
#line 3616 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3620 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3625 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 3629 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3635 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3639 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 3646 "Gmsh.y"
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

  case 304:
/* Line 1787 of yacc.c  */
#line 3702 "Gmsh.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3772 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3777 "Gmsh.y"
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

  case 307:
/* Line 1787 of yacc.c  */
#line 3844 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3880 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3888 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3931 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 3970 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 3990 "Gmsh.y"
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

  case 313:
/* Line 1787 of yacc.c  */
#line 4018 "Gmsh.y"
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

  case 314:
/* Line 1787 of yacc.c  */
#line 4066 "Gmsh.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 4094 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4122 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 4126 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 4130 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4158 "Gmsh.y"
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

  case 320:
/* Line 1787 of yacc.c  */
#line 4197 "Gmsh.y"
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

  case 321:
/* Line 1787 of yacc.c  */
#line 4236 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4257 "Gmsh.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 4278 "Gmsh.y"
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

  case 324:
/* Line 1787 of yacc.c  */
#line 4305 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4309 "Gmsh.y"
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

  case 326:
/* Line 1787 of yacc.c  */
#line 4319 "Gmsh.y"
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

  case 327:
/* Line 1787 of yacc.c  */
#line 4353 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4354 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 4355 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4360 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4366 "Gmsh.y"
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

  case 332:
/* Line 1787 of yacc.c  */
#line 4378 "Gmsh.y"
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

  case 333:
/* Line 1787 of yacc.c  */
#line 4396 "Gmsh.y"
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

  case 334:
/* Line 1787 of yacc.c  */
#line 4423 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4424 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4425 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4426 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4427 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4428 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4429 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4430 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4432 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4438 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4440 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4441 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4442 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4443 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4444 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4445 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4446 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4447 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4448 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4449 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4450 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4451 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4452 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4453 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4454 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4455 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4456 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4457 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4458 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4459 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4460 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4461 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4462 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4463 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4464 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4465 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4466 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4467 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4469 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4470 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4479 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4480 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4481 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4482 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4483 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4484 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4485 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4486 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4487 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4488 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4493 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4495 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4501 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4506 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4523 "Gmsh.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 4541 "Gmsh.y"
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

  case 392:
/* Line 1787 of yacc.c  */
#line 4559 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4564 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4570 "Gmsh.y"
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

  case 395:
/* Line 1787 of yacc.c  */
#line 4582 "Gmsh.y"
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

  case 396:
/* Line 1787 of yacc.c  */
#line 4599 "Gmsh.y"
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

  case 397:
/* Line 1787 of yacc.c  */
#line 4617 "Gmsh.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 4638 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4643 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4648 "Gmsh.y"
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

  case 401:
/* Line 1787 of yacc.c  */
#line 4658 "Gmsh.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 4668 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4673 "Gmsh.y"
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

  case 404:
/* Line 1787 of yacc.c  */
#line 4684 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4693 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4698 "Gmsh.y"
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

  case 407:
/* Line 1787 of yacc.c  */
#line 4725 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4729 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4733 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4737 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4741 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4748 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4756 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4760 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4767 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4772 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4779 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4784 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4788 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4793 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4797 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4805 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4816 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4820 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4832 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4840 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4848 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4855 "Gmsh.y"
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

  case 430:
/* Line 1787 of yacc.c  */
#line 4865 "Gmsh.y"
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

  case 431:
/* Line 1787 of yacc.c  */
#line 4894 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4898 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4902 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4906 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 4910 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 4914 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 4918 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 4922 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 4926 "Gmsh.y"
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

  case 440:
/* Line 1787 of yacc.c  */
#line 4955 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 4984 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 5013 "Gmsh.y"
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

  case 443:
/* Line 1787 of yacc.c  */
#line 5043 "Gmsh.y"
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

  case 444:
/* Line 1787 of yacc.c  */
#line 5056 "Gmsh.y"
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

  case 445:
/* Line 1787 of yacc.c  */
#line 5069 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 5082 "Gmsh.y"
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

  case 447:
/* Line 1787 of yacc.c  */
#line 5094 "Gmsh.y"
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

  case 448:
/* Line 1787 of yacc.c  */
#line 5104 "Gmsh.y"
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

  case 449:
/* Line 1787 of yacc.c  */
#line 5114 "Gmsh.y"
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

  case 450:
/* Line 1787 of yacc.c  */
#line 5126 "Gmsh.y"
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

  case 451:
/* Line 1787 of yacc.c  */
#line 5138 "Gmsh.y"
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

  case 452:
/* Line 1787 of yacc.c  */
#line 5150 "Gmsh.y"
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

  case 453:
/* Line 1787 of yacc.c  */
#line 5168 "Gmsh.y"
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

  case 454:
/* Line 1787 of yacc.c  */
#line 5189 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5194 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5198 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5202 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5214 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5218 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5230 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5237 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5247 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5251 "Gmsh.y"
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

  case 464:
/* Line 1787 of yacc.c  */
#line 5266 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5271 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5278 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5282 "Gmsh.y"
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

  case 468:
/* Line 1787 of yacc.c  */
#line 5295 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5303 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5314 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5318 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5326 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5332 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5338 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 5346 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5354 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5361 "Gmsh.y"
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

  case 478:
/* Line 1787 of yacc.c  */
#line 5376 "Gmsh.y"
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

  case 479:
/* Line 1787 of yacc.c  */
#line 5390 "Gmsh.y"
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

  case 480:
/* Line 1787 of yacc.c  */
#line 5404 "Gmsh.y"
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

  case 481:
/* Line 1787 of yacc.c  */
#line 5416 "Gmsh.y"
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

  case 482:
/* Line 1787 of yacc.c  */
#line 5432 "Gmsh.y"
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

  case 483:
/* Line 1787 of yacc.c  */
#line 5443 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5447 "Gmsh.y"
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

  case 485:
/* Line 1787 of yacc.c  */
#line 5466 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 5473 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 5475 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 5486 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 5491 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 5497 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 5506 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 5519 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 5522 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11559 "Gmsh.tab.cpp"
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
#line 5526 "Gmsh.y"


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
