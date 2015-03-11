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
     tStrFind = 300,
     tStrCmp = 301,
     tTextAttributes = 302,
     tBoundingBox = 303,
     tDraw = 304,
     tSetChanged = 305,
     tToday = 306,
     tFixRelativePath = 307,
     tSyncModel = 308,
     tOnelabAction = 309,
     tOnelabRun = 310,
     tCpu = 311,
     tMemory = 312,
     tTotalMemory = 313,
     tCreateTopology = 314,
     tCreateTopologyNoHoles = 315,
     tDistanceFunction = 316,
     tDefineConstant = 317,
     tUndefineConstant = 318,
     tDefineNumber = 319,
     tDefineString = 320,
     tPoint = 321,
     tCircle = 322,
     tEllipse = 323,
     tLine = 324,
     tSphere = 325,
     tPolarSphere = 326,
     tSurface = 327,
     tSpline = 328,
     tVolume = 329,
     tCharacteristic = 330,
     tLength = 331,
     tParametric = 332,
     tElliptic = 333,
     tRefineMesh = 334,
     tAdaptMesh = 335,
     tRelocateMesh = 336,
     tPlane = 337,
     tRuled = 338,
     tTransfinite = 339,
     tComplex = 340,
     tPhysical = 341,
     tCompound = 342,
     tPeriodic = 343,
     tUsing = 344,
     tPlugin = 345,
     tDegenerated = 346,
     tRecursive = 347,
     tRotate = 348,
     tTranslate = 349,
     tSymmetry = 350,
     tDilate = 351,
     tExtrude = 352,
     tLevelset = 353,
     tRecombine = 354,
     tSmoother = 355,
     tSplit = 356,
     tDelete = 357,
     tCoherence = 358,
     tIntersect = 359,
     tMeshAlgorithm = 360,
     tReverse = 361,
     tLayers = 362,
     tScaleLast = 363,
     tHole = 364,
     tAlias = 365,
     tAliasWithOptions = 366,
     tCopyOptions = 367,
     tQuadTriAddVerts = 368,
     tQuadTriNoNewVerts = 369,
     tQuadTriSngl = 370,
     tQuadTriDbl = 371,
     tRecombLaterals = 372,
     tTransfQuadTri = 373,
     tText2D = 374,
     tText3D = 375,
     tInterpolationScheme = 376,
     tTime = 377,
     tCombine = 378,
     tBSpline = 379,
     tBezier = 380,
     tNurbs = 381,
     tNurbsOrder = 382,
     tNurbsKnots = 383,
     tColor = 384,
     tColorTable = 385,
     tFor = 386,
     tIn = 387,
     tEndFor = 388,
     tIf = 389,
     tEndIf = 390,
     tExit = 391,
     tAbort = 392,
     tField = 393,
     tReturn = 394,
     tCall = 395,
     tFunction = 396,
     tShow = 397,
     tHide = 398,
     tGetValue = 399,
     tGetEnv = 400,
     tGetString = 401,
     tHomology = 402,
     tCohomology = 403,
     tBetti = 404,
     tSetOrder = 405,
     tExists = 406,
     tFileExists = 407,
     tGMSH_MAJOR_VERSION = 408,
     tGMSH_MINOR_VERSION = 409,
     tGMSH_PATCH_VERSION = 410,
     tAFFECTDIVIDE = 411,
     tAFFECTTIMES = 412,
     tAFFECTMINUS = 413,
     tAFFECTPLUS = 414,
     tOR = 415,
     tAND = 416,
     tNOTEQUAL = 417,
     tEQUAL = 418,
     tGREATEROREQUAL = 419,
     tLESSOREQUAL = 420,
     UNARYPREC = 421,
     tMINUSMINUS = 422,
     tPLUSPLUS = 423
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
#line 395 "Gmsh.tab.cpp"
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
#line 423 "Gmsh.tab.cpp"

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
#define YYLAST   9382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  483
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1701

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   423

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   174,     2,   184,     2,   173,     2,     2,
     179,   180,   171,   169,   185,   170,   183,   172,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     165,     2,   166,   160,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   181,     2,   182,   178,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   186,     2,   187,   188,     2,     2,     2,
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
     155,   156,   157,   158,   159,   161,   162,   163,   164,   167,
     168,   175,   176,   177
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    59,    67,    75,    83,    93,
     100,   107,   114,   123,   124,   127,   130,   133,   136,   139,
     141,   145,   147,   151,   152,   153,   164,   166,   170,   171,
     185,   187,   191,   192,   208,   217,   232,   233,   240,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     268,   274,   279,   286,   293,   301,   309,   317,   327,   337,
     341,   348,   355,   360,   367,   377,   384,   394,   400,   409,
     418,   430,   437,   447,   453,   461,   471,   481,   493,   501,
     511,   521,   522,   524,   525,   529,   535,   536,   546,   552,
     553,   563,   564,   568,   572,   578,   579,   582,   586,   592,
     596,   597,   600,   604,   608,   614,   616,   618,   620,   622,
     624,   626,   628,   630,   631,   637,   638,   641,   649,   658,
     665,   673,   678,   686,   695,   704,   712,   720,   732,   741,
     750,   759,   768,   778,   782,   787,   798,   806,   814,   823,
     832,   845,   854,   863,   871,   880,   889,   895,   907,   913,
     923,   933,   938,   948,   958,   960,   962,   963,   966,   973,
     980,   987,   994,  1003,  1014,  1029,  1046,  1059,  1068,  1077,
    1084,  1099,  1104,  1111,  1118,  1122,  1127,  1133,  1140,  1144,
    1148,  1153,  1159,  1164,  1170,  1174,  1180,  1188,  1196,  1200,
    1208,  1212,  1215,  1218,  1221,  1224,  1240,  1243,  1246,  1249,
    1252,  1255,  1272,  1276,  1283,  1292,  1301,  1312,  1314,  1317,
    1319,  1323,  1328,  1330,  1336,  1348,  1362,  1363,  1371,  1372,
    1386,  1387,  1403,  1404,  1411,  1420,  1429,  1438,  1451,  1464,
    1477,  1492,  1507,  1522,  1523,  1536,  1537,  1550,  1551,  1564,
    1565,  1582,  1583,  1600,  1601,  1618,  1619,  1638,  1639,  1658,
    1659,  1678,  1680,  1683,  1689,  1697,  1707,  1710,  1713,  1716,
    1720,  1723,  1727,  1730,  1734,  1737,  1741,  1751,  1758,  1759,
    1763,  1764,  1766,  1767,  1770,  1771,  1774,  1775,  1778,  1786,
    1793,  1802,  1808,  1812,  1820,  1826,  1831,  1838,  1845,  1859,
    1870,  1881,  1892,  1903,  1914,  1919,  1924,  1929,  1934,  1939,
    1942,  1946,  1953,  1955,  1957,  1959,  1962,  1968,  1976,  1987,
    1989,  1993,  1996,  1999,  2002,  2006,  2010,  2014,  2018,  2022,
    2026,  2030,  2034,  2038,  2042,  2046,  2050,  2054,  2058,  2064,
    2069,  2074,  2079,  2084,  2089,  2094,  2099,  2104,  2109,  2114,
    2121,  2126,  2131,  2136,  2141,  2146,  2151,  2156,  2163,  2170,
    2177,  2182,  2184,  2186,  2188,  2190,  2192,  2194,  2196,  2198,
    2200,  2202,  2203,  2210,  2212,  2217,  2222,  2227,  2232,  2237,
    2240,  2246,  2252,  2256,  2263,  2268,  2276,  2283,  2290,  2297,
    2302,  2304,  2307,  2310,  2314,  2318,  2330,  2340,  2348,  2356,
    2358,  2362,  2364,  2366,  2369,  2373,  2378,  2384,  2386,  2388,
    2391,  2395,  2399,  2405,  2410,  2413,  2416,  2419,  2422,  2426,
    2430,  2434,  2438,  2444,  2450,  2456,  2462,  2479,  2496,  2513,
    2530,  2532,  2534,  2538,  2542,  2547,  2554,  2561,  2563,  2565,
    2569,  2573,  2583,  2591,  2593,  2599,  2603,  2610,  2612,  2616,
    2618,  2620,  2624,  2631,  2633,  2635,  2637,  2642,  2649,  2654,
    2659,  2664,  2673,  2678,  2683,  2690,  2695,  2696,  2703,  2705,
    2709,  2715,  2721,  2723
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     190,     0,    -1,   191,    -1,     1,     6,    -1,    -1,   191,
     192,    -1,   195,    -1,   194,    -1,   215,    -1,   232,    -1,
     233,    -1,   237,    -1,   238,    -1,   239,    -1,   242,    -1,
     263,    -1,   264,    -1,   241,    -1,   240,    -1,   236,    -1,
     266,    -1,   166,    -1,   166,   166,    -1,    37,   179,   280,
     180,     6,    -1,    38,   179,   280,   180,     6,    -1,    37,
     179,   280,   180,   193,   280,     6,    -1,    37,   179,   280,
     185,   276,   180,     6,    -1,    38,   179,   280,   185,   276,
     180,     6,    -1,    37,   179,   280,   185,   276,   180,   193,
     280,     6,    -1,     4,   280,   186,   196,   187,     6,    -1,
     110,     4,   181,   267,   182,     6,    -1,   111,     4,   181,
     267,   182,     6,    -1,   112,     4,   181,   267,   185,   267,
     182,     6,    -1,    -1,   196,   199,    -1,   196,   203,    -1,
     196,   206,    -1,   196,   208,    -1,   196,   209,    -1,   267,
      -1,   197,   185,   267,    -1,   267,    -1,   198,   185,   267,
      -1,    -1,    -1,     4,   200,   179,   197,   180,   201,   186,
     198,   187,     6,    -1,   280,    -1,   202,   185,   280,    -1,
      -1,   119,   179,   267,   185,   267,   185,   267,   180,   204,
     186,   202,   187,     6,    -1,   280,    -1,   205,   185,   280,
      -1,    -1,   120,   179,   267,   185,   267,   185,   267,   185,
     267,   180,   207,   186,   205,   187,     6,    -1,   121,   186,
     272,   187,   186,   272,   187,     6,    -1,   121,   186,   272,
     187,   186,   272,   187,   186,   272,   187,   186,   272,   187,
       6,    -1,    -1,   122,   210,   186,   198,   187,     6,    -1,
       7,    -1,   159,    -1,   158,    -1,   157,    -1,   156,    -1,
     177,    -1,   176,    -1,   179,    -1,   181,    -1,   180,    -1,
     182,    -1,    62,   181,   217,   182,     6,    -1,    63,   181,
     220,   182,     6,    -1,   285,   211,   273,     6,    -1,     4,
     181,   182,   211,   273,     6,    -1,   284,   181,   182,   211,
     273,     6,    -1,     4,   181,   267,   182,   211,   267,     6,
      -1,     4,   179,   267,   180,   211,   267,     6,    -1,   284,
     181,   267,   182,   211,   267,     6,    -1,     4,   213,   186,
     276,   187,   214,   211,   273,     6,    -1,   284,   213,   186,
     276,   187,   214,   211,   273,     6,    -1,   285,   212,     6,
      -1,     4,   181,   267,   182,   212,     6,    -1,   284,   181,
     267,   182,   212,     6,    -1,   285,     7,   281,     6,    -1,
       4,   183,     4,     7,   281,     6,    -1,     4,   181,   267,
     182,   183,     4,     7,   281,     6,    -1,     4,   183,     4,
     211,   267,     6,    -1,     4,   181,   267,   182,   183,     4,
     211,   267,     6,    -1,     4,   183,     4,   212,     6,    -1,
       4,   181,   267,   182,   183,     4,   212,     6,    -1,     4,
     183,   129,   183,     4,     7,   277,     6,    -1,     4,   181,
     267,   182,   183,   129,   183,     4,     7,   277,     6,    -1,
       4,   183,   130,     7,   278,     6,    -1,     4,   181,   267,
     182,   183,   130,     7,   278,     6,    -1,     4,   138,     7,
     267,     6,    -1,   138,   181,   267,   182,     7,     4,     6,
      -1,   138,   181,   267,   182,   183,     4,     7,   267,     6,
      -1,   138,   181,   267,   182,   183,     4,     7,   281,     6,
      -1,   138,   181,   267,   182,   183,     4,     7,   186,   276,
     187,     6,    -1,   138,   181,   267,   182,   183,     4,     6,
      -1,    90,   179,     4,   180,   183,     4,     7,   267,     6,
      -1,    90,   179,     4,   180,   183,     4,     7,   281,     6,
      -1,    -1,   185,    -1,    -1,   217,   216,   285,    -1,   217,
     216,   285,     7,   267,    -1,    -1,   217,   216,   285,     7,
     186,   267,   218,   222,   187,    -1,   217,   216,   285,     7,
     281,    -1,    -1,   217,   216,   285,     7,   186,   281,   219,
     224,   187,    -1,    -1,   220,   216,   280,    -1,   267,     7,
     281,    -1,   221,   185,   267,     7,   281,    -1,    -1,   222,
     223,    -1,   185,     4,   273,    -1,   185,     4,   186,   221,
     187,    -1,   185,     4,   281,    -1,    -1,   224,   225,    -1,
     185,     4,   267,    -1,   185,     4,   281,    -1,   185,     4,
     186,   283,   187,    -1,   267,    -1,   281,    -1,   267,    -1,
     281,    -1,   267,    -1,   281,    -1,   267,    -1,   281,    -1,
      -1,   132,    70,   186,   267,   187,    -1,    -1,    82,   270,
      -1,    66,   179,   267,   180,     7,   270,     6,    -1,    86,
      66,   179,   226,   180,     7,   273,     6,    -1,    75,    76,
     273,     7,   267,     6,    -1,    69,   179,   267,   180,     7,
     273,     6,    -1,    91,    69,   273,     6,    -1,    73,   179,
     267,   180,     7,   273,     6,    -1,    67,   179,   267,   180,
       7,   273,   231,     6,    -1,    68,   179,   267,   180,     7,
     273,   231,     6,    -1,   124,   179,   267,   180,     7,   273,
       6,    -1,   125,   179,   267,   180,     7,   273,     6,    -1,
     126,   179,   267,   180,     7,   273,   128,   273,   127,   267,
       6,    -1,    69,     4,   179,   267,   180,     7,   273,     6,
      -1,    87,    69,   179,   267,   180,     7,   273,     6,    -1,
      86,    69,   179,   227,   180,     7,   273,     6,    -1,    82,
      72,   179,   267,   180,     7,   273,     6,    -1,    83,    72,
     179,   267,   180,     7,   273,   230,     6,    -1,    12,    13,
       6,    -1,    13,    72,   267,     6,    -1,    77,    72,   179,
     267,   180,     7,     5,     5,     5,     6,    -1,    70,   179,
     267,   180,     7,   273,     6,    -1,    71,   179,   267,   180,
       7,   273,     6,    -1,    72,     4,   179,   267,   180,     7,
     273,     6,    -1,    87,    72,   179,   267,   180,     7,   273,
       6,    -1,    87,    72,   179,   267,   180,     7,   273,     4,
     186,   272,   187,     6,    -1,    86,    72,   179,   228,   180,
       7,   273,     6,    -1,    85,    74,   179,   267,   180,     7,
     273,     6,    -1,    74,   179,   267,   180,     7,   273,     6,
      -1,    87,    74,   179,   267,   180,     7,   273,     6,    -1,
      86,    74,   179,   229,   180,     7,   273,     6,    -1,    94,
     270,   186,   234,   187,    -1,    93,   186,   270,   185,   270,
     185,   267,   187,   186,   234,   187,    -1,    95,   270,   186,
     234,   187,    -1,    96,   186,   270,   185,   267,   187,   186,
     234,   187,    -1,    96,   186,   270,   185,   270,   187,   186,
     234,   187,    -1,     4,   186,   234,   187,    -1,   104,    69,
     186,   276,   187,    72,   186,   267,   187,    -1,   101,    69,
     179,   267,   180,   186,   276,   187,     6,    -1,   235,    -1,
     233,    -1,    -1,   235,   232,    -1,   235,    66,   186,   276,
     187,     6,    -1,   235,    69,   186,   276,   187,     6,    -1,
     235,    72,   186,   276,   187,     6,    -1,   235,    74,   186,
     276,   187,     6,    -1,    98,    82,   179,   267,   180,     7,
     273,     6,    -1,    98,    66,   179,   267,   180,     7,   186,
     272,   187,     6,    -1,    98,    82,   179,   267,   180,     7,
     186,   270,   185,   270,   185,   276,   187,     6,    -1,    98,
      82,   179,   267,   180,     7,   186,   270,   185,   270,   185,
     270,   185,   276,   187,     6,    -1,    98,    70,   179,   267,
     180,     7,   186,   270,   185,   276,   187,     6,    -1,    98,
       4,   179,   267,   180,     7,   273,     6,    -1,    98,     4,
     179,   267,   180,     7,     5,     6,    -1,    98,     4,   186,
     267,   187,     6,    -1,    98,     4,   179,   267,   180,     7,
     186,   270,   185,   270,   185,   276,   187,     6,    -1,   102,
     186,   235,   187,    -1,   102,   138,   181,   267,   182,     6,
      -1,   102,     4,   181,   267,   182,     6,    -1,   102,     4,
       6,    -1,   102,     4,     4,     6,    -1,   129,   277,   186,
     235,   187,    -1,    92,   129,   277,   186,   235,   187,    -1,
     142,     5,     6,    -1,   143,     5,     6,    -1,   142,   186,
     235,   187,    -1,    92,   142,   186,   235,   187,    -1,   143,
     186,   235,   187,    -1,    92,   143,   186,   235,   187,    -1,
       4,   281,     6,    -1,    55,   179,   283,   180,     6,    -1,
       4,     4,   181,   267,   182,   280,     6,    -1,     4,     4,
       4,   181,   267,   182,     6,    -1,     4,   267,     6,    -1,
      90,   179,     4,   180,   183,     4,     6,    -1,   123,     4,
       6,    -1,   136,     6,    -1,   137,     6,    -1,    53,     6,
      -1,    48,     6,    -1,    48,   186,   267,   185,   267,   185,
     267,   185,   267,   185,   267,   185,   267,   187,     6,    -1,
      49,     6,    -1,    50,     6,    -1,    59,     6,    -1,    60,
       6,    -1,    79,     6,    -1,    80,   186,   276,   187,   186,
     276,   187,   186,   272,   187,   186,   267,   185,   267,   187,
       6,    -1,   150,   267,     6,    -1,   131,   179,   267,     8,
     267,   180,    -1,   131,   179,   267,     8,   267,     8,   267,
     180,    -1,   131,     4,   132,   186,   267,     8,   267,   187,
      -1,   131,     4,   132,   186,   267,     8,   267,     8,   267,
     187,    -1,   133,    -1,   141,     4,    -1,   139,    -1,   140,
     285,     6,    -1,   134,   179,   267,   180,    -1,   135,    -1,
      97,   270,   186,   235,   187,    -1,    97,   186,   270,   185,
     270,   185,   267,   187,   186,   235,   187,    -1,    97,   186,
     270,   185,   270,   185,   270,   185,   267,   187,   186,   235,
     187,    -1,    -1,    97,   270,   186,   235,   243,   256,   187,
      -1,    -1,    97,   186,   270,   185,   270,   185,   267,   187,
     186,   235,   244,   256,   187,    -1,    -1,    97,   186,   270,
     185,   270,   185,   270,   185,   267,   187,   186,   235,   245,
     256,   187,    -1,    -1,    97,   186,   235,   246,   256,   187,
      -1,    97,    66,   186,   267,   185,   270,   187,     6,    -1,
      97,    69,   186,   267,   185,   270,   187,     6,    -1,    97,
      72,   186,   267,   185,   270,   187,     6,    -1,    97,    66,
     186,   267,   185,   270,   185,   270,   185,   267,   187,     6,
      -1,    97,    69,   186,   267,   185,   270,   185,   270,   185,
     267,   187,     6,    -1,    97,    72,   186,   267,   185,   270,
     185,   270,   185,   267,   187,     6,    -1,    97,    66,   186,
     267,   185,   270,   185,   270,   185,   270,   185,   267,   187,
       6,    -1,    97,    69,   186,   267,   185,   270,   185,   270,
     185,   270,   185,   267,   187,     6,    -1,    97,    72,   186,
     267,   185,   270,   185,   270,   185,   270,   185,   267,   187,
       6,    -1,    -1,    97,    66,   186,   267,   185,   270,   187,
     247,   186,   256,   187,     6,    -1,    -1,    97,    69,   186,
     267,   185,   270,   187,   248,   186,   256,   187,     6,    -1,
      -1,    97,    72,   186,   267,   185,   270,   187,   249,   186,
     256,   187,     6,    -1,    -1,    97,    66,   186,   267,   185,
     270,   185,   270,   185,   267,   187,   250,   186,   256,   187,
       6,    -1,    -1,    97,    69,   186,   267,   185,   270,   185,
     270,   185,   267,   187,   251,   186,   256,   187,     6,    -1,
      -1,    97,    72,   186,   267,   185,   270,   185,   270,   185,
     267,   187,   252,   186,   256,   187,     6,    -1,    -1,    97,
      66,   186,   267,   185,   270,   185,   270,   185,   270,   185,
     267,   187,   253,   186,   256,   187,     6,    -1,    -1,    97,
      69,   186,   267,   185,   270,   185,   270,   185,   270,   185,
     267,   187,   254,   186,   256,   187,     6,    -1,    -1,    97,
      72,   186,   267,   185,   270,   185,   270,   185,   270,   185,
     267,   187,   255,   186,   256,   187,     6,    -1,   257,    -1,
     256,   257,    -1,   107,   186,   267,   187,     6,    -1,   107,
     186,   273,   185,   273,   187,     6,    -1,   107,   186,   273,
     185,   273,   185,   273,   187,     6,    -1,   108,     6,    -1,
      99,     6,    -1,   115,     6,    -1,   115,   117,     6,    -1,
     116,     6,    -1,   116,   117,     6,    -1,   113,     6,    -1,
     113,   117,     6,    -1,   114,     6,    -1,   114,   117,     6,
      -1,   109,   179,   267,   180,     7,   273,    89,   267,     6,
      -1,    89,     4,   181,   267,   182,     6,    -1,    -1,    89,
       4,   267,    -1,    -1,     4,    -1,    -1,     7,   273,    -1,
      -1,     7,   267,    -1,    -1,    89,   273,    -1,    84,    69,
     274,     7,   267,   258,     6,    -1,    84,    72,   274,   260,
     259,     6,    -1,    78,    72,   186,   267,   187,     7,   273,
       6,    -1,    84,    74,   274,   260,     6,    -1,   118,   274,
       6,    -1,   105,    72,   186,   276,   187,   267,     6,    -1,
      99,    72,   274,   261,     6,    -1,    99,    74,   274,     6,
      -1,   100,    72,   273,     7,   267,     6,    -1,    88,    69,
     273,     7,   273,     6,    -1,    88,    72,   267,   186,   276,
     187,     7,   267,   186,   276,   187,   262,     6,    -1,    66,
     186,   276,   187,   132,    72,   186,   267,   187,     6,    -1,
      69,   186,   276,   187,   132,    72,   186,   267,   187,     6,
      -1,    66,   186,   276,   187,   132,    74,   186,   267,   187,
       6,    -1,    69,   186,   276,   187,   132,    74,   186,   267,
     187,     6,    -1,    72,   186,   276,   187,   132,    74,   186,
     267,   187,     6,    -1,   106,    72,   274,     6,    -1,   106,
      69,   274,     6,    -1,    81,    66,   274,     6,    -1,    81,
      69,   274,     6,    -1,    81,    72,   274,     6,    -1,   103,
       6,    -1,   103,     4,     6,    -1,   103,    66,   186,   276,
     187,     6,    -1,   147,    -1,   148,    -1,   149,    -1,   265,
       6,    -1,   265,   186,   273,   187,     6,    -1,   265,   186,
     273,   185,   273,   187,     6,    -1,   265,   179,   273,   180,
     186,   273,   185,   273,   187,     6,    -1,   268,    -1,   179,
     267,   180,    -1,   170,   267,    -1,   169,   267,    -1,   174,
     267,    -1,   267,   170,   267,    -1,   267,   169,   267,    -1,
     267,   171,   267,    -1,   267,   172,   267,    -1,   267,   173,
     267,    -1,   267,   178,   267,    -1,   267,   165,   267,    -1,
     267,   166,   267,    -1,   267,   168,   267,    -1,   267,   167,
     267,    -1,   267,   164,   267,    -1,   267,   163,   267,    -1,
     267,   162,   267,    -1,   267,   161,   267,    -1,   267,   160,
     267,     8,   267,    -1,    14,   213,   267,   214,    -1,    15,
     213,   267,   214,    -1,    16,   213,   267,   214,    -1,    17,
     213,   267,   214,    -1,    18,   213,   267,   214,    -1,    19,
     213,   267,   214,    -1,    20,   213,   267,   214,    -1,    21,
     213,   267,   214,    -1,    22,   213,   267,   214,    -1,    24,
     213,   267,   214,    -1,    25,   213,   267,   185,   267,   214,
      -1,    26,   213,   267,   214,    -1,    27,   213,   267,   214,
      -1,    28,   213,   267,   214,    -1,    29,   213,   267,   214,
      -1,    30,   213,   267,   214,    -1,    31,   213,   267,   214,
      -1,    32,   213,   267,   214,    -1,    33,   213,   267,   185,
     267,   214,    -1,    34,   213,   267,   185,   267,   214,    -1,
      35,   213,   267,   185,   267,   214,    -1,    23,   213,   267,
     214,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     153,    -1,   154,    -1,   155,    -1,    56,    -1,    57,    -1,
      58,    -1,    -1,    64,   213,   267,   269,   222,   214,    -1,
     285,    -1,     4,   181,   267,   182,    -1,   284,   181,   267,
     182,    -1,   151,   179,   285,   180,    -1,   152,   179,   281,
     180,    -1,   184,   285,   181,   182,    -1,   285,   212,    -1,
       4,   181,   267,   182,   212,    -1,   284,   181,   267,   182,
     212,    -1,     4,   183,     4,    -1,     4,   181,   267,   182,
     183,     4,    -1,     4,   183,     4,   212,    -1,     4,   181,
     267,   182,   183,     4,   212,    -1,   144,   179,   280,   185,
     267,   180,    -1,    45,   179,   280,   185,   280,   180,    -1,
      46,   179,   280,   185,   280,   180,    -1,    47,   179,   283,
     180,    -1,   271,    -1,   170,   270,    -1,   169,   270,    -1,
     270,   170,   270,    -1,   270,   169,   270,    -1,   186,   267,
     185,   267,   185,   267,   185,   267,   185,   267,   187,    -1,
     186,   267,   185,   267,   185,   267,   185,   267,   187,    -1,
     186,   267,   185,   267,   185,   267,   187,    -1,   179,   267,
     185,   267,   185,   267,   180,    -1,   273,    -1,   272,   185,
     273,    -1,   267,    -1,   275,    -1,   186,   187,    -1,   186,
     276,   187,    -1,   170,   186,   276,   187,    -1,   267,   171,
     186,   276,   187,    -1,   273,    -1,     5,    -1,   170,   275,
      -1,   267,   171,   275,    -1,   267,     8,   267,    -1,   267,
       8,   267,     8,   267,    -1,    66,   186,   267,   187,    -1,
      66,     5,    -1,    69,     5,    -1,    72,     5,    -1,    74,
       5,    -1,    86,    66,     5,    -1,    86,    69,     5,    -1,
      86,    72,     5,    -1,    86,    74,     5,    -1,    86,    66,
     186,   276,   187,    -1,    86,    69,   186,   276,   187,    -1,
      86,    72,   186,   276,   187,    -1,    86,    74,   186,   276,
     187,    -1,    66,   132,    48,   186,   267,   185,   267,   185,
     267,   185,   267,   185,   267,   185,   267,   187,    -1,    69,
     132,    48,   186,   267,   185,   267,   185,   267,   185,   267,
     185,   267,   185,   267,   187,    -1,    72,   132,    48,   186,
     267,   185,   267,   185,   267,   185,   267,   185,   267,   185,
     267,   187,    -1,    74,   132,    48,   186,   267,   185,   267,
     185,   267,   185,   267,   185,   267,   185,   267,   187,    -1,
     233,    -1,   242,    -1,     4,   213,   214,    -1,   284,   213,
     214,    -1,    36,   181,   285,   182,    -1,     4,   213,   186,
     276,   187,   214,    -1,   284,   213,   186,   276,   187,   214,
      -1,   267,    -1,   275,    -1,   276,   185,   267,    -1,   276,
     185,   275,    -1,   186,   267,   185,   267,   185,   267,   185,
     267,   187,    -1,   186,   267,   185,   267,   185,   267,   187,
      -1,     4,    -1,     4,   183,   129,   183,     4,    -1,   186,
     279,   187,    -1,     4,   181,   267,   182,   183,   130,    -1,
     277,    -1,   279,   185,   277,    -1,   281,    -1,   285,    -1,
       4,   183,     4,    -1,     4,   181,   267,   182,   183,     4,
      -1,     5,    -1,    51,    -1,    54,    -1,   145,   179,   280,
     180,    -1,   146,   179,   280,   185,   280,   180,    -1,    41,
     213,   283,   214,    -1,    42,   179,   280,   180,    -1,    43,
     179,   280,   180,    -1,    44,   179,   280,   185,   280,   185,
     280,   180,    -1,    39,   213,   283,   214,    -1,    40,   213,
     280,   214,    -1,    40,   213,   280,   185,   276,   214,    -1,
      52,   179,   280,   180,    -1,    -1,    65,   213,   281,   282,
     224,   214,    -1,   280,    -1,   283,   185,   280,    -1,     4,
     188,   186,   267,   187,    -1,   284,   188,   186,   267,   187,
      -1,     4,    -1,   284,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   184,   189,   191,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   213,   217,   224,   229,   234,   248,   261,   274,   302,
     316,   329,   342,   361,   366,   367,   368,   369,   370,   374,
     376,   381,   383,   389,   493,   388,   511,   518,   529,   528,
     546,   553,   564,   563,   580,   597,   620,   619,   633,   634,
     635,   636,   637,   641,   642,   648,   648,   649,   649,   655,
     656,   657,   718,   747,   776,   781,   786,   791,   798,   805,
     820,   825,   830,   839,   845,   854,   872,   890,   899,   911,
     916,   924,   944,   967,   978,   986,  1008,  1031,  1057,  1078,
    1090,  1104,  1104,  1106,  1108,  1117,  1127,  1126,  1138,  1148,
    1147,  1161,  1163,  1171,  1177,  1184,  1185,  1189,  1200,  1215,
    1225,  1226,  1231,  1239,  1248,  1266,  1270,  1279,  1283,  1292,
    1296,  1305,  1309,  1319,  1322,  1335,  1338,  1348,  1371,  1387,
    1410,  1428,  1449,  1467,  1497,  1527,  1545,  1563,  1590,  1608,
    1626,  1645,  1663,  1702,  1708,  1714,  1721,  1746,  1771,  1788,
    1807,  1841,  1861,  1879,  1896,  1912,  1933,  1938,  1943,  1948,
    1953,  1958,  1981,  1987,  1998,  1999,  2004,  2007,  2011,  2034,
    2057,  2080,  2108,  2129,  2155,  2176,  2198,  2218,  2330,  2349,
    2387,  2496,  2505,  2511,  2526,  2554,  2571,  2580,  2594,  2600,
    2606,  2615,  2624,  2633,  2647,  2703,  2721,  2738,  2753,  2772,
    2784,  2808,  2812,  2817,  2824,  2830,  2835,  2841,  2849,  2853,
    2857,  2862,  2917,  2930,  2947,  2964,  2985,  3006,  3041,  3049,
    3055,  3062,  3066,  3075,  3083,  3091,  3100,  3099,  3114,  3113,
    3128,  3127,  3142,  3141,  3155,  3162,  3169,  3176,  3183,  3190,
    3197,  3204,  3211,  3219,  3218,  3232,  3231,  3245,  3244,  3258,
    3257,  3271,  3270,  3284,  3283,  3297,  3296,  3310,  3309,  3323,
    3322,  3339,  3342,  3348,  3360,  3380,  3404,  3408,  3412,  3416,
    3420,  3426,  3432,  3436,  3440,  3444,  3448,  3467,  3480,  3483,
    3499,  3502,  3519,  3522,  3528,  3531,  3538,  3541,  3548,  3604,
    3674,  3679,  3746,  3782,  3790,  3833,  3872,  3892,  3919,  3968,
    3996,  4024,  4028,  4032,  4060,  4099,  4138,  4159,  4180,  4207,
    4211,  4221,  4256,  4257,  4258,  4262,  4268,  4280,  4298,  4326,
    4327,  4328,  4329,  4330,  4331,  4332,  4333,  4334,  4341,  4342,
    4343,  4344,  4345,  4346,  4347,  4348,  4349,  4350,  4351,  4352,
    4353,  4354,  4355,  4356,  4357,  4358,  4359,  4360,  4361,  4362,
    4363,  4364,  4365,  4366,  4367,  4368,  4369,  4370,  4371,  4372,
    4373,  4382,  4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,
    4391,  4396,  4395,  4403,  4420,  4438,  4456,  4461,  4467,  4479,
    4496,  4514,  4535,  4540,  4545,  4555,  4565,  4570,  4579,  4584,
    4611,  4615,  4619,  4623,  4627,  4634,  4638,  4642,  4646,  4653,
    4658,  4665,  4670,  4674,  4679,  4683,  4691,  4702,  4706,  4718,
    4726,  4734,  4741,  4751,  4780,  4784,  4788,  4792,  4796,  4800,
    4804,  4808,  4812,  4841,  4870,  4899,  4928,  4941,  4954,  4967,
    4980,  4990,  5000,  5012,  5024,  5036,  5054,  5075,  5080,  5084,
    5088,  5100,  5104,  5116,  5123,  5133,  5137,  5152,  5157,  5164,
    5168,  5181,  5189,  5200,  5204,  5212,  5218,  5226,  5234,  5249,
    5263,  5277,  5289,  5305,  5309,  5328,  5336,  5335,  5348,  5353,
    5359,  5368,  5381,  5384
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
  "tStrPrefix", "tStrRelative", "tStrReplace", "tStrFind", "tStrCmp",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tSyncModel", "tOnelabAction", "tOnelabRun", "tCpu",
  "tMemory", "tTotalMemory", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineString", "tPoint", "tCircle", "tEllipse",
  "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
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
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
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
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "$@8", "$@9", "$@10", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "$@21", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "$@22",
  "RecursiveListOfStringExprVar", "StringIndex", "String__Index", YY_NULL
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
      63,   415,   416,   417,   418,    60,    62,   419,   420,    43,
      45,    42,    47,    37,    33,   421,   422,   423,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   189,   190,   190,   191,   191,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   193,   193,   194,   194,   194,   194,   194,   194,   195,
     195,   195,   195,   196,   196,   196,   196,   196,   196,   197,
     197,   198,   198,   200,   201,   199,   202,   202,   204,   203,
     205,   205,   207,   206,   208,   208,   210,   209,   211,   211,
     211,   211,   211,   212,   212,   213,   213,   214,   214,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   216,   216,   217,   217,   217,   218,   217,   217,   219,
     217,   220,   220,   221,   221,   222,   222,   223,   223,   223,
     224,   224,   225,   225,   225,   226,   226,   227,   227,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   233,   233,
     233,   233,   233,   233,   234,   234,   235,   235,   235,   235,
     235,   235,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   237,   237,   237,   237,   237,   238,   238,   239,   239,
     239,   239,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   242,   242,   242,   243,   242,   244,   242,
     245,   242,   246,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   247,   242,   248,   242,   249,   242,   250,
     242,   251,   242,   252,   242,   253,   242,   254,   242,   255,
     242,   256,   256,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   258,   258,
     259,   259,   260,   260,   261,   261,   262,   262,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   264,
     264,   264,   265,   265,   265,   266,   266,   266,   266,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   269,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     270,   270,   270,   270,   270,   271,   271,   271,   271,   272,
     272,   273,   273,   273,   273,   273,   273,   274,   274,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   276,   276,   276,
     276,   277,   277,   277,   277,   278,   278,   279,   279,   280,
     280,   280,   280,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   282,   281,   283,   283,
     284,   284,   285,   285
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     7,     7,     7,     9,     6,
       6,     6,     8,     0,     2,     2,     2,     2,     2,     1,
       3,     1,     3,     0,     0,    10,     1,     3,     0,    13,
       1,     3,     0,    15,     8,    14,     0,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     6,     6,     7,     7,     7,     9,     9,     3,
       6,     6,     4,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     9,     9,    11,     7,     9,
       9,     0,     1,     0,     3,     5,     0,     9,     5,     0,
       9,     0,     3,     3,     5,     0,     2,     3,     5,     3,
       0,     2,     3,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     0,     2,     7,     8,     6,
       7,     4,     7,     8,     8,     7,     7,    11,     8,     8,
       8,     8,     9,     3,     4,    10,     7,     7,     8,     8,
      12,     8,     8,     7,     8,     8,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     6,     3,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,    15,     2,     2,     2,     2,
       2,    16,     3,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     2,     3,
       2,     3,     2,     3,     2,     3,     9,     6,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     7,     6,
       8,     5,     3,     7,     5,     4,     6,     6,    13,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     1,     4,     4,     4,     4,     4,     2,
       5,     5,     3,     6,     4,     7,     6,     6,     6,     4,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     1,
       3,     1,     1,     2,     3,     4,     5,     1,     1,     2,
       3,     3,     5,     4,     2,     2,     2,     2,     3,     3,
       3,     3,     5,     5,     5,     5,    16,    16,    16,    16,
       1,     1,     3,     3,     4,     6,     6,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     3,     6,     1,     1,     1,     4,     6,     4,     4,
       4,     8,     4,     4,     6,     4,     0,     6,     1,     3,
       5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   232,     0,     0,     0,   229,     0,     0,     0,     0,
     322,   323,   324,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   483,     0,   371,   482,   463,   372,   373,   374,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,     0,   465,   378,   379,   380,     0,     0,     0,     0,
       0,     0,     0,     0,   375,   376,   377,     0,     0,     0,
      65,    66,     0,     0,   176,     0,     0,     0,   329,     0,
     459,   483,   383,     0,     0,     0,     0,   214,     0,   216,
     217,   213,     0,   218,   219,   103,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,   319,     0,     0,     0,     0,     0,
       0,     0,     0,   482,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   440,   441,   411,   417,     0,   412,
     483,   383,     0,     0,     0,     0,   453,     0,     0,     0,
       0,     0,   211,   212,     0,   482,   483,     0,   228,     0,
     176,     0,   176,   482,     0,   325,     0,     0,    65,    66,
       0,     0,    58,    62,    61,    60,    59,    64,    63,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,   331,   333,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,   174,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,   204,     0,
     389,   153,     0,   482,     0,   459,   460,     0,     0,   478,
       0,   101,   101,     0,     0,   447,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   176,     0,   402,   401,     0,
       0,     0,     0,   176,   176,     0,     0,     0,     0,     0,
       0,     0,   242,     0,   176,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,   194,     0,     0,     0,   320,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,   424,     0,     0,   425,     0,   426,     0,   427,
       0,     0,     0,     0,     0,     0,   331,   419,     0,   413,
       0,     0,     0,   302,    66,     0,   210,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,   230,   198,     0,
     199,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   381,   476,
       0,     0,     0,     0,     0,     0,   330,    58,     0,     0,
      58,     0,     0,     0,     0,     0,   171,     0,     0,     0,
       0,   177,     0,     0,     0,   347,   346,   345,   344,   340,
     341,   343,   342,   335,   334,   336,   337,   338,   339,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   316,   317,   318,     0,     0,
       0,     0,   290,     0,     0,     0,   125,   126,     0,   127,
     128,     0,   129,   130,     0,   131,   132,     0,     0,     0,
       0,     0,     0,   141,   176,     0,     0,     0,     0,     0,
     404,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,     0,     0,     0,     0,   305,
       0,     0,   195,     0,     0,   191,     0,     0,     0,   315,
     314,     0,     0,     0,     0,   392,    67,    68,     0,   442,
       0,     0,     0,     0,     0,     0,   428,     0,   429,     0,
     430,     0,   431,     0,     0,   330,   414,   421,     0,   336,
     420,     0,   443,     0,     0,     0,     0,     0,     0,     0,
       0,   231,     0,   200,   202,     0,     0,     0,     0,     0,
       0,     0,    82,    71,     0,   384,   394,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   370,   358,     0,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,   472,
       0,   473,   468,   469,   470,     0,     0,     0,   399,   475,
     115,   120,    93,     0,   466,     0,   386,   387,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
     388,     0,     0,     0,     0,   480,     0,     0,    43,     0,
       0,     0,    56,     0,    34,    35,    36,    37,    38,   385,
       0,   461,    23,    21,     0,     0,    24,     0,     0,   205,
     479,    69,   104,    70,   112,     0,   449,   450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,   293,   291,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   203,     0,     0,     0,   166,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,   233,     0,     0,
       0,     0,     0,     0,   295,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   384,     0,   444,     0,
     423,     0,     0,     0,     0,     0,     0,     0,   415,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,     0,     0,   326,     0,     0,     0,   481,     0,
       0,     0,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,     0,
       0,     0,    80,    83,    85,     0,     0,   457,     0,    91,
       0,     0,     0,     0,     0,   348,     0,     0,     0,     0,
       0,    29,   391,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,   307,     0,     0,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,   276,     0,   282,
       0,   284,     0,   278,     0,   280,     0,   243,   272,     0,
       0,     0,   189,     0,     0,     0,   306,     0,   193,   192,
     321,     0,     0,    30,    31,     0,     0,     0,     0,     0,
       0,     0,   432,   433,   434,   435,   422,   416,     0,     0,
       0,     0,   454,     0,     0,     0,   223,     0,     0,     0,
       0,    73,     0,    81,     0,   207,   393,   206,   359,   367,
     368,   369,   474,     0,   397,   398,     0,   382,   116,     0,
     477,   121,   396,   467,    75,    58,     0,     0,     0,     0,
      74,     0,     0,     0,   455,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,     0,    25,    26,     0,
      27,     0,     0,   105,   108,   137,     0,     0,     0,     0,
       0,     0,   140,     0,     0,   156,   157,     0,     0,   142,
     163,     0,     0,     0,     0,   133,     0,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,     0,     0,
       0,     0,   176,   176,     0,   253,     0,   255,     0,   257,
       0,   411,     0,     0,   283,   285,   279,   281,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,     0,   393,   445,     0,     0,     0,     0,   446,   145,
     146,     0,     0,     0,     0,    94,    98,     0,     0,   327,
      76,     0,   395,     0,     0,     0,     0,     0,    88,     0,
       0,    89,     0,   458,   178,   179,   180,   181,     0,     0,
      39,     0,     0,     0,     0,     0,    41,   462,     0,     0,
     106,   109,     0,     0,   136,   143,   144,   148,     0,     0,
     158,     0,     0,   300,     0,   151,     0,     0,   289,   162,
     138,   150,   161,   165,   149,     0,   159,   164,     0,     0,
       0,     0,   408,     0,   407,     0,     0,     0,   244,     0,
       0,   245,     0,     0,   246,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,   187,     0,     0,     0,   182,
       0,     0,    32,     0,     0,     0,     0,     0,     0,   452,
       0,   225,   224,     0,     0,     0,     0,     0,   471,     0,
     117,   119,     0,   122,   123,    84,    86,     0,    92,     0,
      77,    44,     0,     0,     0,   410,     0,     0,     0,    28,
       0,   115,   120,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,     0,    99,   100,   176,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,   273,     0,     0,
     176,     0,     0,     0,     0,     0,   173,   172,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,     0,    78,
       0,   447,     0,     0,   456,     0,    40,     0,     0,     0,
      42,    57,     0,     0,     0,   309,   311,   310,   312,   313,
     155,     0,     0,     0,     0,     0,     0,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,     0,     0,
       0,   238,     0,     0,   183,     0,     0,     0,     0,     0,
       0,     0,   451,   226,     0,   328,     0,   118,     0,   124,
      90,     0,     0,     0,     0,     0,   107,   110,     0,     0,
       0,   296,   167,     0,   259,     0,     0,   261,     0,     0,
     263,     0,     0,     0,   274,     0,   234,     0,   176,     0,
       0,     0,     0,     0,     0,     0,   147,    97,     0,   113,
       0,    48,     0,    54,     0,     0,     0,   134,   160,     0,
       0,   405,   247,     0,     0,   254,   248,     0,     0,   256,
     249,     0,     0,   258,     0,     0,     0,   240,     0,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,   308,     0,   265,     0,   267,     0,
     269,   275,   286,   239,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   114,    45,     0,    52,     0,     0,     0,
       0,   250,     0,     0,   251,     0,     0,   252,     0,     0,
     190,     0,   184,     0,     0,     0,     0,     0,    46,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     260,     0,   262,     0,   264,     0,   185,     0,     0,     0,
       0,    47,    49,     0,    50,     0,     0,     0,     0,   436,
     437,   438,   439,     0,     0,    55,   266,   268,   270,    51,
      53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   864,    85,    86,   629,  1299,  1305,
     854,  1026,  1465,  1647,   855,  1598,  1683,   856,  1649,   857,
     858,  1030,   319,   400,   166,   739,    87,   643,   411,  1411,
    1412,   412,  1460,  1002,  1158,  1003,  1161,   675,   678,   681,
     684,  1327,  1199,   611,   274,   377,   378,    90,    91,    92,
      93,    94,    95,   275,   938,  1547,  1615,   709,  1349,  1352,
    1355,  1573,  1577,  1581,  1632,  1635,  1638,   934,   935,  1062,
     899,   672,   718,  1570,    97,    98,    99,   100,   276,   168,
     820,   458,   234,  1183,   277,   278,   279,   520,   288,   839,
    1018,   409,   405,   821,   410,   171,   281
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1185
static const yytype_int16 yypact[] =
{
    5926,    23,    52,  6041, -1185, -1185,  3113,    92,    74,   -60,
     -17,     9,   213,   251,   267,    63,   277,   305,   148,   154,
    -146,   146,   160,    13,   183,   202,    14,   240,   260,   316,
     380,   410,   511,   317,   642,   473,   477,   228,   446,   633,
     569,    55,   379,   508,   -61,   420,  -114,  -114,   438,   307,
      44,   -14,   520,   581,     3,    65,   590,   559,    99,   632,
     661,   666,  3842,   679,   510,   521,   527,    20,     4, -1185,
     530, -1185,   714,   718,   550, -1185,   739,   752,    34,    37,
   -1185, -1185, -1185,  5781, -1185, -1185, -1185, -1185, -1185, -1185,
   -1185, -1185, -1185, -1185, -1185, -1185, -1185, -1185, -1185,    51,
   -1185,  -104,   122, -1185,    -1, -1185, -1185, -1185, -1185,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   592,   598,   601,   602,   621,   652,
   -1185,   653, -1185, -1185, -1185, -1185,   -75,   -75,   804,   657,
     663,   664,   674,   680, -1185, -1185, -1185,  5781,  5781,  5781,
    5781,  5488,   131,   739,   364,   672,   676,   909, -1185,   687,
     861,  -105,  -151,   868,  5781,   362,   362, -1185,  5781, -1185,
   -1185, -1185,   362, -1185, -1185, -1185, -1185,  5781,  5386,  5781,
    5781,   705,  5781,  5386,  5781,  5781,   712,  5386,  5781,  5781,
    4198,   716,   735, -1185,  5386,  3842,  3842,  3842,   721,   746,
    3842,  3842,  3842,   758,   762,   763,   769,   770,   809,   828,
     841,  4198,  5781,   901,  4198,    20,   797,   835,  -114,  -114,
    -114,  5781,  5781,   -90, -1185,   -54,  -114,   836,   837,   838,
    2301,   168,    -5,   846,   848,   849,  3842,  3842,  4198,   850,
      60,   851, -1185,  1024, -1185,   847,   852,   853,  3842,  3842,
     854,   855,   856,   515, -1185,   859,    38,    17,    18,    29,
     660,  4376,  5781,  3479, -1185, -1185,  3990, -1185,  1028, -1185,
     -37,   115,  1035,  5781,  5781,  5781,   860,  5781,   865,   913,
    5781,  5781, -1185, -1185,  5781,   864,   867,  1041, -1185,  1047,
   -1185,  1052, -1185,   229,  1163, -1185,  4198,  4198, -1185,  5730,
     873,   874,   402, -1185, -1185, -1185, -1185, -1185, -1185,  4198,
    1078,   904,  5781,  1082, -1185,  5781,  5781,  5781,  5781,  5781,
    5781,  5781,  5781,  5781,  5781,  5781,  5781,  5781,  5781,  5781,
    5781,  5781,  5781,  5781,  5781,  5781,  5781,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,  5781,   402,  5781,
     362,   362,   362,   739,   402,   910,   910,   910,  8490,   184,
    8145,   129,   906,  1083,   911,   907, -1185,   916,  5247,  5781,
    5386, -1185,  5781,  5781,  5781,  5781,  5781,  5781,  5781,  5781,
    5781,  5781,  5781,  5781,  5781,  5781,  5781, -1185, -1185,  5781,
   -1185, -1185,  1651,   314,    54, -1185, -1185,   185,  6952, -1185,
     331,   179,   236,  8511,  5386,  4157, -1185,   139,  8532,  8553,
    5781,  8574,   253,  8595,  8616,  5781,   285,  8637,  8658,  1087,
    5781,  5781,   286,  1094,  1099,  1101,  5781,  5781,  1105,  1106,
    1106,  5781,  5558,  5558,  5558,  5558,  5781,  5781,  5781,  1107,
    6872,   928,  1113,   935, -1185, -1185,   186, -1185, -1185,  6978,
    7004,  -114,  -114,   364,   364,   224,  5781,  5781,  5781,  2301,
    2301,  5781,  5247,   230, -1185,  5781,  5781,  5781,  5781,  5781,
    1115,  1117,  1132,  5781,  1134, -1185,  5781,  5781,  1507, -1185,
    5386,  5386,  5386,  1135,  1136,  5781,  5781,  5781,  5781,  1140,
     192,   739, -1185,  1097,  5781, -1185,  1098, -1185,  1100, -1185,
    1103,    39,    40,    45,    46,  5386,   910, -1185,  8679, -1185,
     357,  5781,  4554, -1185,  5781,   440, -1185,  8700,  8721,  8742,
    1018,  7030, -1185,   963,  4323,  8763,  8168, -1185, -1185,  1787,
   -1185,  1939,  5781, -1185,   973,   370,   184,  8191,  5781,  5386,
    1165,  1166, -1185,  5781,  8214,   -43,  8122,  8122,  8122,  8122,
    8122,  8122,  8122,  8122,  8122,  8122,  8122,  7056,  8122,  8122,
    8122,  8122,  8122,  8122,  8122,  7082,  7108,  7134,   348,   497,
     348,   997,   998,   994,   996,   999,   371,  1000,  9204, -1185,
    2072,  1005,  1003,  1006,  1007,  1012,   184, -1185,  4198,   118,
     402,  5781,  1176,  1189,    27,  1014, -1185,    -2,    26,    28,
      86, -1185,  5000,   443,  4346,   789,  1205,   618,   618,   491,
     491,   491,   491,   312,   312,   910,   910,   910,   910,     1,
    8237, -1185,  5781,  1190,    10,  5386,  1194,  5386,  5781,  1196,
     362,  1200, -1185,   739,  1201,   362,  1206,  5386,  5386,  1076,
    1207,  1208,  8784,  1210,  1086,  1212,  1213,  8805,  1089,  1220,
    1221,  5781,  8826,  6032,  1044, -1185, -1185, -1185,  8847,  8868,
    5781,  4198,  1227,  1226,  8889,  1055,  9204, -1185,  1057,  9204,
   -1185,  1059,  9204, -1185,  1061,  9204, -1185,  8910,  8931,  8952,
    4198,  5386,  1062, -1185, -1185,  2061,  2357,  -114,  5781,  5781,
   -1185, -1185,  1063,  1067,  2301,  7160,  7186,  7212,  6926,  1309,
    -114,  2496,  8973,  6060,  8994,  9015,  9036,  5781,  1240, -1185,
    5781,  9057, -1185,  8260,  8283, -1185,   486,   555,   562, -1185,
   -1185,  8306,  8329,  7238,  8352,   115, -1185, -1185,  5386, -1185,
    1077,  1072,  6088,  1074,  1084,  1090, -1185,  5386, -1185,  5386,
   -1185,  5386, -1185,  5386,   566, -1185, -1185,  4513,  5386,   910,
   -1185,  5386, -1185,  1255,  1256,  1257,  1102,  5781,  2699,  5781,
    5781, -1185,    67, -1185, -1185,  1091,  4198,  1273,  4198,   151,
    6116,   567, -1185, -1185,  8375,   113, -1185, -1185, -1185, -1185,
   -1185, -1185, -1185, -1185, -1185, -1185, -1185, -1185,  5781, -1185,
   -1185, -1185, -1185, -1185, -1185, -1185,  5781,  5781,  5781, -1185,
    5386, -1185, -1185, -1185, -1185,   362,   362,   362, -1185, -1185,
   -1185, -1185, -1185,  5781, -1185,   362, -1185, -1185,  5781,  1274,
     133,  5781,  1278,  1280,  2217, -1185,  1281,  1110,    20,  1286,
   -1185,  5386,  5386,  5386,  5386, -1185,   580,  5781, -1185,  1114,
    1116,  1108, -1185,  1292, -1185, -1185, -1185, -1185, -1185,   115,
    8398, -1185, -1185,  1133,   362,   406, -1185,   414,  7264, -1185,
   -1185, -1185,  1294, -1185, -1185,  -114,  4157, -1185,   691,  4198,
    4198,  1295,  4198,   694,  4198,  4198,  1297,  1234,  4198,  4198,
    2635,  1303,  1308,  5386,  1310,  1311,  1586, -1185, -1185,  1313,
   -1185,  1315,  1330,  1331,  1332,  1333,  1335,  1337,  1339,  1314,
     582,  1312,  2839, -1185, -1185,   266,  7290,  7316, -1185, -1185,
    6144,   -57,  -114,  -114,  -114,  1343,  1342,  1164,  1347,  1170,
      21,    22,    30,    31,   494, -1185,   309, -1185,  1309,  1352,
    1351,  1354,  1355,  1357,  9204, -1185,  2700,  1179,  1373,  1375,
    1376,  1316,  5781,  1384,  1385,  5781,   254,   585, -1185,  5781,
   -1185,  5781,  5781,  5781,   589,   616,   619,   623, -1185,  5781,
     630,   631,  4198,  4198,  4198,  1388,  7342, -1185,  4760,   995,
    1389,  1390,  4198,  1209, -1185,  1393,  5781,  1394, -1185,   580,
    1395,  1391, -1185,  1396,  8122,  8122,  8122,  8122,   533,  1219,
    1229,  1230,   548,   556,  9078,  1241,  2781, -1185,   156,  1243,
    1421,  3019, -1185, -1185, -1185,    20,  5781, -1185,   636, -1185,
     641,   650,   662,   669,   184,  9204,  1250,  5781,  5781,  4198,
    1245, -1185, -1185,  1252, -1185,  1427,    61,  1432,  5781,  4732,
     153,  1253,  1254,  1362,  1362,  4198,  1444,  1266,  1267,  1448,
    1449,  4198,  1270,  1452,  1478, -1185,  1481,  4198,   681,  4198,
    4198,  1483,  1482, -1185,  4198,  4198,  4198,  4198,  4198,  4198,
    4198,  4198, -1185,  1484,   457, -1185,  5781,  5781,  5781,  1304,
    1306,    84,    97,   149,  1318, -1185,  4198, -1185,  5781, -1185,
    1487, -1185,  1488, -1185,  1494, -1185,  1495, -1185, -1185,  2301,
     540,  4020, -1185,  1317,  1319,  4795, -1185,  5386, -1185, -1185,
   -1185,  1321,  3038, -1185, -1185,  8421,  1485,   580,  7368,  7394,
    7420,  7446, -1185, -1185, -1185, -1185,  9204, -1185,   580,  1496,
    1498,  1380, -1185,  5781,  5781,  5781, -1185,  1504,   485,  1326,
    1506, -1185,  3057, -1185,   184, -1185,   144, -1185, -1185, -1185,
   -1185, -1185, -1185,   362, -1185, -1185,  1509, -1185, -1185,  1511,
   -1185, -1185, -1185, -1185, -1185,   402,  5781,  1512,  1517,    27,
   -1185,  1516,  8444,    20, -1185,  1522,  1523,  1532,  1533,  4198,
    5781,  7472,  7498,   693, -1185,  5781,  1536, -1185, -1185,   362,
   -1185,  7524,  5558,  9204, -1185, -1185,  5781,  5781,  -114,  1539,
    1541,  1543, -1185,  5781,  5781, -1185, -1185,  1544,  5781, -1185,
   -1185,  1547,  1548,  1367,  1549,  1424,  5781, -1185,  1551,  1552,
    1553,  1554,  1556,  1557,   888,  1558,  5781, -1185,  5558,  6172,
    9099,  4936,   364,   364,  -114,  1559,  -114,  1561,  -114,  1562,
    5781,   400,  1386,  9120, -1185, -1185, -1185, -1185,  6200,   311,
   -1185,  1563,  3300,  1564,  4198,  -114,  3300,  1566,   711,  5781,
   -1185,  1577,   115, -1185,  5781,  5781,  5781,  5781, -1185, -1185,
   -1185,  4198,  5513,   965,  9141, -1185, -1185,  4973,  4198, -1185,
   -1185,  4198, -1185,  1405,  3664,  5030,  1580,  3424, -1185,  1581,
    1585, -1185,  1404, -1185, -1185, -1185, -1185, -1185,  1590,   434,
    9204,  5781,  5781,  4198,  1411,   719,  9204, -1185,  1593,  5781,
    9204, -1185,  6228,  6256,   340, -1185, -1185, -1185,  6284,  6312,
   -1185,  6340,  1595, -1185,  4198, -1185,  1535,  1596,  9204, -1185,
   -1185, -1185, -1185, -1185, -1185,  1420, -1185, -1185,  6899,  3443,
    1597,  1430, -1185,  5781, -1185,  1431,  1433,   344, -1185,  1435,
     352, -1185,  1437,   365, -1185,  1438,  8467,  1601,  4198,  1610,
    1440,  5781, -1185,  5208,   369, -1185,   726,   405,   411, -1185,
    1613,  6368, -1185,  7550,  7576,  7602,  7628,  1500,  5781, -1185,
    5781, -1185, -1185,  5386,  3611,  1622,  1447,  1629, -1185,  3479,
   -1185, -1185,   362,  9204, -1185, -1185, -1185,    20, -1185,  1521,
   -1185, -1185,  5781,  7654,  7680, -1185,  4198,  5781,  1630, -1185,
    7706, -1185, -1185,  1631,  1636,  1646,  1647,  1648,  1650,   727,
    1472, -1185,  4198,  5386, -1185, -1185,   364,  5686, -1185, -1185,
    2301,  1309,  2301,  1309,  2301,  1309,  1653, -1185,   741,  4198,
   -1185,  6396,  -114,  1655,  5386,  -114, -1185, -1185,  5781,  5781,
    5781,  5781,  5781,  6424,  6452,   744, -1185, -1185,  1657, -1185,
     747,  2353,   748,  1659, -1185,  1480,  9204,  5781,  5781,   778,
    9204, -1185,  5781,   779,   790, -1185, -1185, -1185, -1185, -1185,
   -1185,  1486,  5781,   791,   795,  1489,  5781, -1185,  6480,   415,
     577,  6508,   419,   756,  6536,   428,   794, -1185,  4198,  1661,
    1579,  2963,  1491,   442, -1185,   799,   448,  7732,  7758,  7784,
    7810,  3633, -1185, -1185,  1663, -1185,  5781, -1185,   402, -1185,
   -1185,  5781,  9162,  7836,    47,  7862, -1185, -1185,  5781,  6564,
    1664,  1582, -1185,  6592,  1668,  5781,  1672,  1673,  5781,  1674,
    1675,  5781,  1678,  1499, -1185,  5781, -1185,  1309, -1185,  5386,
    1679,  5208,  5781,  5781,  5781,  5781, -1185, -1185,  3968, -1185,
     802, -1185,  5781, -1185,  4198,  5781,  7888, -1185, -1185,  4198,
    1681, -1185, -1185,  1502,  6620, -1185, -1185,  1503,  6648, -1185,
   -1185,  1510,  6676, -1185,  1686,  3801,   831,  3340,   806, -1185,
     482,   807,  7914,  7940,  7966,  7992,   402,  1687,  1513,  9183,
     810,  6704,  5781, -1185, -1185,  1309,  1689,  1309,  1692,  1309,
    1695, -1185, -1185, -1185, -1185,  1309,  1697,  5386,  1698,  5781,
    5781,  5781,  5781, -1185, -1185,   362, -1185,  1519,  1700,  6732,
    1002, -1185,  1524,  1096, -1185,  1525,  1158, -1185,  1527,  1198,
   -1185,   813, -1185,  8018,  8044,  8070,  8096,   814, -1185,  1528,
    4198, -1185,  1701,  1702,  1309,  1703,  1309,  1709,  1309, -1185,
    1710,  5781,  5781,  5781,  5781,   362,  1711,   362,   821, -1185,
   -1185,  1298, -1185,  1417, -1185,  1428, -1185,  6760,  6788,  6816,
    6844, -1185, -1185,   832, -1185,  1712,  1713,  1714,  1715, -1185,
   -1185, -1185, -1185,   362,  1719, -1185, -1185, -1185, -1185, -1185,
   -1185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1185, -1185, -1185, -1185,   690, -1185, -1185, -1185, -1185,   206,
   -1185, -1185, -1185, -1185, -1185, -1185, -1185, -1185, -1185, -1185,
   -1185, -1185,  -350,   -40,  1350,  -471, -1185,  1320, -1185, -1185,
   -1185, -1185, -1185,   318, -1185,   319, -1185, -1185, -1185, -1185,
   -1185, -1185,   686,  1730,    11,  -454,  -239, -1185, -1185, -1185,
   -1185, -1185, -1185,  1737, -1185, -1185, -1185, -1185, -1185, -1185,
   -1185, -1185, -1185, -1185, -1185, -1185, -1185,  -810,  -914, -1185,
   -1185,  1322, -1185, -1185, -1185, -1185, -1185, -1185,  1451, -1185,
   -1185,     0, -1185, -1184,   -55,   294,  1851,   605,  -223,   574,
   -1185,    72,     5, -1185,  -343,    -3,    35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -463
static const yytype_int16 yytable[] =
{
     101,   472,   453,   321,   578,   848,   580,   250,   289,   702,
     703,   170,   586,   488,    89,   177,   862,   191,   196,   598,
    1098,   601,   505,   507,   286,   317,   318,  1089,  1091,     4,
     191,   837,   196,   187,   509,  -460,  1093,  1095,   102,   299,
     188,   172,   301,   502,   746,   748,   233,   235,   242,   241,
     750,   752,     5,  1563,   762,   229,   230,   305,   246,   280,
     247,   539,   320,   541,   484,   231,   485,  1188,   225,   253,
    1366,   254,   232,   296,   980,   308,   399,   309,   169,   461,
     462,   226,   227,   310,   310,   787,   788,   789,   790,   791,
     792,   793,   794,   795,   796,   797,   463,   799,   800,   801,
     802,   803,   804,   805,   308,   173,   324,   809,   811,   812,
     243,   297,   461,   462,   244,   461,   462,   403,   105,   175,
     849,   850,   851,   852,   221,   597,   245,   222,  1100,   312,
    1080,   255,   464,   317,   318,   371,   600,  1008,  1090,  1092,
    1419,   251,   308,  -461,   524,   429,   174,  1094,  1096,   506,
     508,   310,   131,   132,   133,   134,   135,   136,   597,  1195,
     296,   510,   176,  1165,   140,   141,   449,   142,   258,   452,
     503,   259,   296,   296,   475,   376,   863,   187,   147,   296,
     322,   476,   323,   290,   841,   280,  1098,   165,   853,   252,
     280,   597,   192,   482,   280,   178,   778,   280,   374,   193,
     197,   280,   280,   280,   280,   192,   287,   280,   280,   280,
     406,   406,   842,   838,   843,   695,   696,   406,   280,   179,
     300,   280,  1469,   302,   504,   747,   749,   863,   456,   457,
     306,   751,   753,  1564,   634,   711,   465,   307,  1483,   635,
     473,   486,   182,   280,   280,   280,   828,   404,   407,   831,
     981,   544,   545,   461,   462,   280,   280,   180,   150,   151,
     372,   373,  1009,  1010,   551,   199,   461,   462,   280,  1234,
     280,  1235,   844,   181,   313,   314,   315,   316,   313,   314,
     315,   316,  1236,   183,  1237,   313,   314,   315,   316,   317,
     318,   317,   318,   768,   317,   318,   991,   210,   317,   318,
     211,   830,   212,   280,   280,   317,   318,   313,   314,   315,
     316,   184,   313,   314,   315,   316,   280,   550,   461,   462,
     317,   318,   461,   462,   648,   189,   649,   317,   318,   185,
    -462,   602,   317,   318,  1238,   186,  1239,   461,   462,   190,
     313,   314,   315,   316,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   474,   461,   462,   296,   296,   296,
     296,   641,   194,   589,   642,   636,   403,   105,   375,   595,
     637,   697,   736,   237,   737,  1024,   238,   280,   738,   239,
    1600,   195,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   200,   461,   462,   406,   406,   406,   594,   461,
     462,   131,   132,   133,   134,   135,   136,   105,   521,   704,
     542,   280,   499,   140,   141,   710,   142,   165,   644,   198,
     579,   642,   581,   582,   583,   584,   585,   147,   587,   986,
     317,   318,   591,   592,   593,   461,   462,  1116,   648,   199,
     654,   131,   132,   133,   134,   135,   136,   677,   680,   683,
     686,  1076,   201,   140,   141,   912,   142,    45,    46,    47,
      48,   700,   701,  1227,  1228,    53,  1668,   147,    56,   457,
     648,   648,   658,   664,   376,   376,   229,   230,   461,   462,
     461,   462,   202,   393,   394,   395,   231,   280,   280,   280,
     396,  1276,  1277,   240,  1099,   632,  1361,   633,   296,   433,
     434,   435,   165,   204,   438,   439,   440,   150,   151,   461,
     462,   639,   280,   461,   462,   786,   640,   203,  1144,   280,
     213,   461,   462,  1148,  1149,  1150,  1151,  1152,   736,  1430,
     737,  1157,  1160,   640,   461,   462,   740,  1432,   461,   462,
     480,   481,   648,   829,   756,   208,   280,   150,   151,   209,
    1434,   818,   493,   494,  1442,   776,   640,   777,   223,   832,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   522,   394,   395,   461,   462,  1098,   224,   396,  1098,
     461,   462,  1098,   925,   461,   462,  1036,  1357,   461,   462,
    1444,   648,   248,   926,  1037,   280,  1445,   461,   462,   648,
    1535,   927,   928,   929,  1538,   833,   228,   930,   931,   932,
     933,   461,   462,  1541,  1401,  1017,   897,   461,   462,  1402,
     736,  1490,   737,  1493,   236,  1496,   761,  1549,   648,   925,
     846,   257,   280,  1551,   280,   909,   260,   296,   218,   926,
     296,   219,   296,   220,   280,   280,  1263,   927,   928,   929,
     249,   461,   462,   930,   931,   932,   933,  1268,  1166,   256,
     391,   392,   393,   394,   395,   261,   925,  1617,   280,   396,
     262,   648,  1098,   950,  1179,   406,   926,   736,   872,   737,
     406,  1097,   810,   282,   927,   928,   929,   280,   280,   283,
     930,   931,   932,   933,   308,   786,   498,   915,   499,   214,
     284,   164,   215,   165,   921,   216,   285,   217,   205,   291,
     936,   206,   870,   736,   207,   737,  1098,   874,   648,  1098,
     292,   983,  1098,   985,   293,  1098,   511,  1250,   736,   512,
     737,   294,   513,  1156,   514,   280,   736,  1586,   737,   987,
     648,  1159,   951,   295,   280,   992,   280,   648,   280,   952,
     280,   648,   648,   968,   989,   280,   298,  1098,   280,  1098,
     736,  1098,   737,  1041,  1536,  1042,  1047,   648,  1048,  1073,
     648,   350,  1117,   280,   648,   280,  1122,   351,  1345,  1346,
     352,   353,   296,   387,   388,   389,   390,   391,   392,   393,
     394,   395,  1171,   417,  1281,  1630,   396,  1633,   422,  1636,
     354,   648,   426,  1123,   648,  1639,  1124,   280,   648,   432,
    1125,   359,   296,   296,   296,   648,   648,  1127,  1128,  1032,
     406,  1173,   296,  1174,  1043,  1044,   648,  1046,  1175,  1049,
    1050,   355,   356,  1053,  1054,   648,   360,  1176,   280,   280,
     280,   280,   361,   362,  1671,   925,  1673,   648,  1675,  1177,
     406,   406,   406,   363,   648,   926,  1178,   993,   379,   364,
     406,   296,   380,   927,   928,   929,   648,   398,  1213,   930,
     931,   932,   933,   397,   401,  1040,   280,   280,  1303,   280,
    1304,   280,   280,   925,   420,   280,   280,   999,  1000,  1001,
     280,   425,  1335,   926,  1336,   430,   648,  1005,  1370,   406,
     436,   927,   928,   929,  1407,   451,  1408,   930,   931,   932,
     933,  1303,  1303,  1443,  1481,   381,   992,  1129,  1130,  1131,
     925,   431,  1081,  1082,  1083,   437,  1498,  1139,  1499,   648,
     926,  1514,  1516,   640,  1517,  1519,  1035,   441,   927,   928,
     929,   442,   443,  1539,   930,   931,   932,   933,   444,   445,
    1293,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,  1303,  1156,  1524,  1526,   396,  1167,   280,
     280,   280,  1485,  1380,  1184,  1159,  1303,  1527,  1530,   280,
     648,  1542,  1531,   454,   648,   613,  1550,  1407,   446,  1597,
    1201,   648,   648,  1616,  1618,  1303,  1207,  1627,   648,  1665,
    1660,  1666,  1212,  1135,  1214,  1215,  1303,   447,  1685,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1225,  1693,  1613,  1694,
     448,   455,   466,   467,   468,   477,   280,   478,   479,   483,
     489,  1242,   487,   490,   523,   495,   496,   497,   491,   492,
     501,   526,   280,   530,  1194,   533,  1253,   537,   280,  1462,
    1257,   532,   165,   538,   280,   310,   280,   280,   540,   548,
     549,   280,   280,   280,   280,   280,   280,   280,   280,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   280,   552,   553,   555,   396,   396,   603,
     604,   925,   605,   164,   661,   726,   727,   728,   280,  1249,
     665,   926,   280,   606,   280,   666,  1282,   667,   692,   927,
     928,   929,   670,   671,   690,   930,   931,   932,   933,   693,
     754,   694,   717,   719,  1298,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   720,
     722,   729,   730,   396,   735,   741,   743,   766,   744,   769,
     296,   745,  1381,   775,   781,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   543,
    1286,   782,   783,   396,  1463,  1136,   280,   813,   814,   815,
     819,   816,   835,   824,   817,   925,   296,   826,   406,  1653,
     823,   825,   827,   836,   861,   926,   840,  1311,  1314,  1184,
     866,  1501,   869,   927,   928,   929,   871,   873,   878,   930,
     931,   932,   933,   875,   879,   880,  1377,   882,   883,   884,
     885,   887,  1282,  1386,   406,  1283,  1387,   888,   889,  1390,
     893,   898,   900,  1340,  1347,   902,  1350,   903,  1353,   904,
     865,   905,   867,   376,   376,   911,   945,   925,  1405,   280,
     918,   280,  1364,   280,   919,  1367,  1368,   926,   959,   958,
     961,  1308,   972,   973,   974,   927,   928,   929,   280,  1184,
     962,   930,   931,   932,   933,   280,   963,   982,   280,   984,
    1007,   280,  1385,  1655,  1012,   975,  1013,   925,  1015,  1391,
    1394,  1016,  1019,  1027,  1029,  1028,   910,   926,  1031,  1034,
     280,  1039,  1045,  1438,  1051,   927,   928,   929,  1052,  1587,
    1056,   930,   931,   932,   933,  1057,  1074,  1059,  1060,  1063,
    1072,   280,  1064,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,  1065,  1066,  1067,
    1068,   396,  1069,   957,  1070,  1657,  1071,  1084,  1085,  1088,
    1086,  1184,   964,  1087,   965,   280,   966,  1102,   967,  1101,
     280,  1103,  1104,   970,  1105,  1107,   971,  1184,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,  1108,
     280,  1109,  1110,   396,  1500,  1659,   280,   925,  1111,   296,
    1113,  1114,  1132,  1137,  1138,  1146,  1140,   926,   925,  1141,
    1143,  1145,  1147,   280,  1153,   927,   928,   929,   926,  1154,
    1155,   930,   931,   932,   933,   998,   927,   928,   929,   280,
     280,  1163,   930,   931,   932,   933,  1168,   406,  1169,  1180,
    1489,  1185,  1492,  1187,  1495,  1186,   280,   376,  1190,  1196,
    1197,   280,  1503,  1543,  1198,  1506,  1020,  1021,  1022,  1023,
    1202,   311,  1203,  1204,  1205,  1206,  1208,   167,  1209,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,  1210,  1686,  1211,  1216,  1217,  1262,
    1232,  1226,  1233,  1244,  1245,   280,   357,   358,  1058,  1240,
    1246,  1247,  1269,  1254,  1270,  1255,   925,  1259,  1271,  1184,
    1275,  1278,  1279,  1284,  1603,  1285,   926,   925,  1288,     7,
       8,  1289,  1291,  1559,   927,   928,   929,   926,  1294,  1295,
     930,   931,   932,   933,   304,   927,   928,   929,  1296,  1297,
    1307,   930,   931,   932,   933,  1315,   280,  1316,   280,  1317,
    1320,  1590,  1322,  1324,  1323,  1325,  1326,  1329,  1330,  1331,
    1332,   280,  1333,  1334,  1337,  1348,   280,  1351,  1354,  1362,
    1365,  1358,  1369,   607,    21,    22,   608,    24,    25,   609,
      27,   610,    29,  1372,    30,  1388,  1395,  1399,  1397,    35,
      36,  1398,    38,    39,    40,  1184,  1400,  1406,    43,  1409,
    1418,  1623,  1421,  1425,  1687,  1420,  1422,  1437,   365,   366,
     367,   368,   370,   500,   280,  1688,  1426,  1439,  1428,  1446,
    1429,  1431,   296,  1433,  1435,   402,  1440,  1452,  1457,   408,
     525,    64,    65,    66,  1458,  1459,  1471,  1475,   413,   415,
     418,   419,  1476,   421,   415,   423,   424,   280,   415,   427,
     428,  1464,  1477,  1478,  1479,   415,  1480,   631,  1482,  1497,
     406,  1504,   296,  1515,   296,  1520,  1521,  1544,  1545,  1557,
    1568,  1569,  1528,   450,  1572,  1061,  1532,  1548,  1575,  1576,
    1579,  1580,   459,   460,  1583,  1589,  1584,  1604,  1605,  1607,
     296,   460,  1611,  1624,   725,  1631,  1609,  1648,  1634,  1625,
     406,  1637,   406,  1640,  1642,  1650,  1651,  1669,  1670,  1672,
    1654,  1656,  1258,  1658,  1667,  1674,  1676,  1682,  1695,  1696,
    1697,  1698,   516,   518,   415,  1700,  1189,  1560,   406,  1473,
    1200,  1474,   645,    88,   527,   528,   529,  1681,   531,  1684,
      96,   534,   535,  1290,     0,   536,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     547,     0,   673,     0,   396,  1699,     0,     0,     0,     0,
       0,     0,     0,   554,     0,     0,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   588,     0,
     590,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
     612,   415,     0,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,     0,     0,
     630,     0,     0,   607,    21,    22,   608,    24,    25,   609,
      27,   610,    29,     0,    30,   516,     0,     0,     0,    35,
      36,   652,    38,    39,    40,     0,   657,     0,    43,     0,
       0,   662,   663,     0,     0,     0,     0,   668,   669,     0,
       0,     0,   674,   676,   679,   682,   685,   687,   688,   689,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,   705,   706,   707,
     365,   366,   708,     0,     0,     0,   712,   713,   714,   715,
     716,     0,     0,     0,   721,     0,     0,   723,   724,     0,
       0,   415,   415,   415,     0,     0,   731,   732,   733,   734,
       0,     7,     8,     0,     0,   742,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   415,     0,     0,     0,
       0,     0,   757,   759,   773,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1455,     0,
       0,     0,     0,   734,     0,     0,     0,     0,     0,   780,
     415,     0,     0,     0,   784,   607,    21,    22,   608,    24,
      25,   609,    27,   610,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,     0,  1484,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,   416,
       0,     0,     0,     0,   416,     0,     0,     0,   416,  1505,
       0,     0,   834,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,   822,     0,
       0,     0,     0,   860,     0,     0,   415,     0,   415,   868,
       0,     0,     0,     0,     0,     0,     0,     0,   759,   876,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   890,     0,     0,     0,     0,     0,     0,     0,
       0,   896,   517,     0,   416,     0,   774,   607,    21,    22,
     608,    24,    25,   609,    27,   610,    29,     0,    30,     0,
       0,     0,   415,    35,    36,     0,    38,    39,    40,   916,
     917,     0,    43,     0,  1588,   920,  1591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   944,     0,
       0,   946,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,     0,   415,
       0,     0,     0,     0,     0,     0,     0,     0,   415,     0,
     415,     0,   415,     0,   415,     0,     0,     0,     0,   415,
       0,     0,   415,     0,     0,     0,     0,     0,   976,     0,
     978,   979,  1641,  1014,     0,     0,     0,     0,     0,     0,
       0,   416,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,   913,   994,
     396,     0,     0,     0,     0,     0,     0,   995,   996,   997,
       0,   415,     0,     0,     0,   517,     0,     0,     0,     0,
       0,     0,     0,     0,  1004,     0,     0,     0,     0,  1006,
       0,     0,  1011,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   415,   415,   415,   415,     0,     0,  1025,     0,
       0,     0,     0,     0,   103,   303,     0,     0,     0,     0,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,   416,   416,   416,   415,     0,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
    1518,   521,     0,     0,     0,   146,   416,     0,     0,     7,
       8,     0,     0,   760,     0,     0,     0,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
     416,     0,     0,  1112,     0,     0,  1115,     0,     0,     0,
    1118,     0,  1119,  1120,  1121,     0,     0,     0,     0,     0,
    1126,     0,     0,   607,    21,    22,   608,    24,    25,   609,
      27,   610,    29,     0,    30,     0,     0,  1142,     0,    35,
      36,     0,    38,    39,    40,   149,     0,     0,    43,     0,
       0,     0,   152,   153,   154,   155,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1172,     0,     0,
     469,   470,     0,     0,     0,   159,     0,     0,  1181,  1182,
     471,    64,    65,    66,     0,   163,   416,   232,   416,  1191,
    1193,     0,     0,     0,     0,     0,     0,     0,   760,   877,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   647,   394,   395,  1229,  1230,  1231,
       0,   396,     0,     0,     0,     0,     0,  1241,     0,  1243,
       0,     0,   416,     0,   914,     0,     0,     0,     0,     0,
    1248,     0,     0,     0,     0,     0,     0,     0,   415,     0,
       0,     0,   607,    21,    22,   608,    24,    25,   609,    27,
     610,    29,     0,    30,     0,     0,     0,     0,    35,    36,
       0,    38,    39,    40,  1272,  1273,  1274,    43,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,   416,     0,
     416,     0,   416,     0,   416,     0,     0,     0,     0,   416,
       0,     0,   416,     0,     0,     0,     0,  1287,     0,     0,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,  1300,     0,     0,     0,     0,  1306,     0,     0,     0,
       0,  1055,     0,  1310,     0,     0,     0,  1312,  1313,     0,
       0,     0,     0,     0,  1318,  1319,     0,     0,     0,  1321,
       0,   416,     0,     0,     0,     0,     0,  1328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1338,     0,  1339,
       0,     0,     0,   937,     0,     0,     0,     0,     0,     0,
       0,  1356,   416,   416,   416,   416,     0,     0,     0,     0,
       0,     0,     0,   415,     0,     0,  1106,   415,     0,     0,
    1371,     7,     8,     0,     0,  1373,  1374,  1375,  1376,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1384,     0,
       0,     0,     0,     0,     0,     0,  1393,     0,     0,     0,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
       0,     0,  1403,  1404,     0,     0,     0,     0,     0,     0,
    1410,     0,     0,     0,     0,   607,    21,    22,   608,    24,
      25,   609,    27,   610,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,  1164,     0,     0,
      43,     0,     0,     0,  1427,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,  1441,   396,   516,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,  1453,
       0,  1454,     0,     0,   415,     0,     0,     0,     0,     0,
    1461,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,  1466,     0,     0,     0,     0,  1470,     0,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   415,     0,     0,     0,   396,     0,
       0,  1488,     0,  1491,     0,  1494,   977,     0,     0,     0,
       0,     0,     0,     0,     0,   415,     0,     0,     0,  1507,
    1508,  1509,  1510,  1511,     0,   607,    21,    22,   608,    24,
      25,   609,    27,   610,    29,     0,    30,     0,  1522,  1523,
       0,    35,    36,  1525,    38,    39,    40,     0,     0,     0,
      43,     0,     0,  1529,     0,     0,     0,  1533,     0,     0,
       0,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,   416,   396,
       0,     0,     0,    64,    65,    66,     0,  1558,     0,     0,
       0,     0,  1306,     0,     0,     7,     8,     0,     0,  1566,
       0,     0,     0,     0,     0,     0,  1574,     0,     0,  1578,
       0,     0,  1582,     0,     0,     0,  1585,     0,     0,     0,
     415,     0,   415,  1592,  1593,  1594,  1595,     0,     0,     0,
       0,     0,     0,  1599,     0,     0,  1601,     0,     0,     0,
       0,     0,     0,     0,     0,  1170,  1075,     0,     0,   607,
      21,    22,   608,    24,    25,   609,    27,   610,    29,     0,
      30,     0,     0,     0,  1260,    35,    36,     0,    38,    39,
      40,     0,     0,  1629,    43,     0,     0,     0,     0,     0,
       0,     0,     0,  1280,     0,     0,     0,     0,   415,     0,
    1643,  1644,  1645,  1646,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   416,     0,     0,     0,   416,     0,     0,
       0,     0,  1677,  1678,  1679,  1680,   103,   104,   105,     0,
       0,     0,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
    1546,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,     0,   140,   141,     0,   142,     0,   143,
     144,   145,     0,     0,     0,     0,     0,   146,   147,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,   517,     0,   396,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,   416,   396,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,   149,   150,   151,
       0,     0,     0,     0,   152,   153,   154,   155,   156,     0,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
       0,     0,   157,   158,     0,     0,     0,   159,     0,     0,
       0,     0,   160,     0,   161,   416,   162,   163,     0,   164,
       0,   165,     0,   103,   263,     0,     0,     0,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,     0,
       0,     0,     7,     8,     0,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,     0,   266,     0,     0,   267,
       0,     0,   268,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
     416,    53,   416,     0,    56,     0,   607,    21,    22,   608,
      24,    25,   609,    27,   610,    29,     0,    30,     0,     0,
       0,     0,    35,    36,     0,    38,    39,    40,     0,     0,
    1396,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,     0,  1424,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,   416,   469,
    1363,     0,     0,     0,   159,     0,     0,     0,     0,   471,
       0,     0,   103,   263,   163,     0,   232,   519,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,  1614,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,     0,     0,
       0,     0,     0,   146,     0,   266,     0,     0,   267,     0,
       0,   268,     0,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,     0,     0,     0,
      53,     0,     0,    56,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,  1456,     0,     0,
       0,   396,     0,   149,     0,     0,     0,     0,     0,     0,
     152,   153,   154,   155,   156,     0,     0,     0,     0,  1556,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   414,
       0,     0,     0,   159,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   163,     0,     0,   519,   103,   263,   105,
       0,     0,     0,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     265,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,   140,   141,     0,   142,     0,
     143,   144,   145,     0,     0,     0,     0,     0,   146,   147,
     266,     0,     0,   267,     0,     0,   268,     0,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,     0,
       0,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,  1612,   149,   150,
     151,   396,     0,     0,     0,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   271,     0,     0,     0,   159,     0,
       0,     0,     0,   272,     0,   103,   263,   264,   163,     0,
    1389,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   265,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,     0,     0,     0,     0,     0,   146,     0,   266,     0,
       0,   267,     0,     0,   268,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
       0,     0,     0,    53,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,  1596,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,   152,   153,   154,   155,   156,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   271,     0,     0,     0,   159,     0,     0,     0,
       0,   272,     0,   103,   263,  1251,   163,     0,   273,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,     0,   266,     0,     0,   267,
       0,     0,   268,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,     0,     0,     0,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   522,   394,   395,   149,   521,     0,     0,   396,     0,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     271,     0,     0,     0,   159,     0,     0,     0,     0,   272,
       0,   103,   263,     0,   163,     0,  1252,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,     0,   146,     0,   266,     0,     0,   267,     0,     0,
     268,     0,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   647,   394,
     395,   770,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,   152,
     153,   154,   155,   156,   847,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   271,     0,
       0,     0,   159,     0,     0,     0,     0,   272,     0,   103,
     263,     0,   163,     0,   273,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   265,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,     0,     0,     0,
     146,     0,   266,     0,     0,   267,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,     0,     0,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     149,   969,     0,     0,   396,     0,     0,   152,   153,   154,
     155,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   414,     0,     0,     0,
     159,     0,     0,     0,     0,   272,     0,   103,   263,     0,
     163,     0,   515,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     265,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   145,     0,     0,     0,     0,     0,   146,     0,
     266,     0,     0,   267,     0,     0,   268,     0,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,   149,     0,
       0,     0,     0,     0,     0,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   414,     0,     0,     0,   159,     0,
       0,     0,     0,   272,     0,   103,   303,   105,   163,     0,
     758,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,  1134,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,   140,   141,     0,   142,     0,   143,   144,
     145,     0,     0,     0,     0,     0,   146,   147,   103,   263,
       0,     0,     0,     0,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,     0,     0,     0,     0,   146,
       0,   266,     0,     0,   267,     0,     0,   268,     0,   269,
       0,     0,     0,     0,     0,     0,   149,   150,   151,     0,
       0,   270,     0,   152,   153,   154,   155,   156,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
       0,   157,   158,     0,     0,     0,   159,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   163,     0,  1192,     0,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,   149,
       0,     0,     0,     0,     0,     0,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   271,     0,     0,     0,   159,
       0,     0,     0,     0,   272,     0,   103,   303,   105,   163,
       0,  1256,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,     0,   140,   141,     0,   142,     0,   143,
     144,   145,     0,   103,   303,   105,     0,   146,   147,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,   141,     0,   142,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,   147,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,   149,   150,   151,
       0,  1343,     0,  1344,   152,   153,   154,   155,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,     0,     0,     0,   159,     0,     0,
       0,     0,   272,     0,     0,     0,     0,   163,     0,  1383,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   149,   150,   151,     0,   396,     0,
       0,   152,   153,   154,   155,   156,     0,   845,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,     0,     0,     0,   159,     0,     0,     0,     0,   272,
       0,   103,   263,     0,   163,     0,  1392,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,     0,     0,     0,     7,
       8,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,     0,   146,     0,   266,     0,     0,   267,     0,     0,
     268,     0,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   607,    21,    22,   608,    24,    25,   609,
      27,   610,    29,     0,    30,     0,     0,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,   469,  1363,     0,
       0,     0,   159,     0,     0,     0,     0,   471,     0,   103,
     263,     0,   163,     0,   232,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   265,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,     0,     0,     0,
     146,     0,   266,     0,     0,   267,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   103,   303,     0,     0,     0,     0,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
     149,     0,     0,   137,   138,   139,     0,   152,   153,   154,
     155,   156,     0,     0,   143,   144,   145,     0,     0,     0,
       0,     0,   146,     0,     0,   157,   414,     0,     0,     0,
     159,   103,   303,   105,     0,   272,     0,   106,   107,   108,
     163,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,   140,
     141,     0,   142,     0,   143,   144,   145,     0,     0,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,     0,
       0,     0,   159,     0,     0,     0,     0,   272,     0,     0,
     369,     0,   163,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1378,     0,
    1379,     0,   149,   150,   151,     0,     0,     0,     0,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,     0,
       0,     0,   159,   103,   303,     0,     0,   272,     0,   106,
     107,   108,   163,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,   103,   303,   143,   144,   145,     0,
     106,   107,   108,     0,   146,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,     0,     0,   146,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1486,     0,  1487,   149,     0,     0,     0,     0,     0,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,     0,     0,     0,   159,     0,     0,     0,     0,   272,
       0,     0,   546,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,    -4,     1,     0,     0,
      -4,     0,   152,   153,   154,   155,   156,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,     0,     0,     0,   159,     0,     0,     0,     0,
     272,     0,     0,    -4,    -4,   163,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,    -4,     6,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,    -4,    -4,     0,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,    14,     0,    15,     0,     0,     0,
      16,    17,     0,    18,    19,     0,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
       0,    59,    60,    61,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,    63,    64,    65,    66,     0,     0,
      67,     0,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    80,    81,
      82,    83,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,   892,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,   940,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,   960,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,   988,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,  1079,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,  1341,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,  1360,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,  1413,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,  1414,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,  1415,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,  1416,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,  1417,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,  1447,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,  1502,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,  1512,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,  1513,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,  1534,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,  1537,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,  1540,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,  1567,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,  1571,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,  1606,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,  1608,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,  1610,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,  1628,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,  1652,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,  1689,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,  1690,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,  1691,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,  1692,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,   691,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,  1423,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   755,     0,     0,     0,
       0,   698,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,   638,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,   698,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,   699,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,   767,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,   798,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,   806,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,   807,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,   808,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,   922,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,   923,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,   924,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,   955,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1038,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1077,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1078,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,  1133,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,  1264,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1265,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1266,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1267,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,  1301,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,  1302,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1309,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1448,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1449,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,  1450,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,  1451,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1467,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1468,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1472,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,  1552,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,  1553,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1554,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1555,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1562,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,  1565,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,  1602,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1619,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1620,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1621,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,  1622,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,  1661,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,  1662,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,  1663,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,  1664,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,   736,     0,   737,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,   599,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
     772,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,   779,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,   785,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,   859,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,   948,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,   949,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,   953,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,   954,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,   956,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,   990,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
    1033,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,  1261,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,  1292,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,  1436,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     596,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,   646,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,   650,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,   651,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,   653,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   655,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   656,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,   659,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,   660,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,   755,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     763,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,   764,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,   765,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,   771,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,   881,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   886,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   891,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,   894,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,   895,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,   901,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     906,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,   907,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,   908,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,   939,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,   941,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   942,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   943,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,   947,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,  1162,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,  1342,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
    1359,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,  1382,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,  1561,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,  1626,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1185)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,   240,   225,     4,   347,     4,   349,     4,     4,   463,
     464,     6,   355,   252,     3,     6,     6,     4,     4,   369,
     934,   371,     5,     5,     4,   176,   177,     6,     6,     6,
       4,     4,     4,   179,     5,   186,     6,     6,     3,     5,
     186,     6,     5,     5,     5,     5,    46,    47,     4,    49,
       5,     5,     0,     6,   525,   169,   170,     6,    72,    62,
      74,   300,   102,   302,     4,   179,     6,     6,   129,     4,
    1254,     6,   186,    76,     7,   179,   181,   181,     6,   169,
     170,   142,   143,   188,   188,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   186,   568,   569,   570,
     571,   572,   573,   574,   179,    13,   181,   578,   579,   580,
      66,    76,   169,   170,    70,   169,   170,     4,     5,   179,
     119,   120,   121,   122,    69,     7,    82,    72,   938,     7,
     187,    66,   186,   176,   177,     4,     7,     4,   117,   117,
    1324,   138,   179,   186,   181,   200,    72,   117,   117,   132,
     132,   188,    39,    40,    41,    42,    43,    44,     7,     6,
     163,   132,   179,     7,    51,    52,   221,    54,    69,   224,
     132,    72,   175,   176,   179,   164,   166,   179,    65,   182,
     181,   186,   183,   179,   186,   188,  1100,   188,   187,   186,
     193,     7,   179,   248,   197,   186,   546,   200,   163,   186,
     186,   204,   205,   206,   207,   179,   186,   210,   211,   212,
     175,   176,   186,   186,   186,   454,   455,   182,   221,     6,
     186,   224,  1406,   186,   186,   186,   186,   166,   228,   229,
     179,   186,   186,   186,   180,   474,   236,   186,  1422,   185,
     240,   181,   179,   246,   247,   248,   596,   175,   176,   599,
     183,   306,   307,   169,   170,   258,   259,     6,   145,   146,
     129,   130,   129,   130,   319,   179,   169,   170,   271,   185,
     273,   187,   186,     6,   156,   157,   158,   159,   156,   157,
     158,   159,   185,     6,   187,   156,   157,   158,   159,   176,
     177,   176,   177,   532,   176,   177,   183,    69,   176,   177,
      72,   183,    74,   306,   307,   176,   177,   156,   157,   158,
     159,     6,   156,   157,   158,   159,   319,   312,   169,   170,
     176,   177,   169,   170,   185,   179,   187,   176,   177,   181,
     186,   371,   176,   177,   185,   181,   187,   169,   170,   179,
     156,   157,   158,   159,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   186,   169,   170,   360,   361,   362,
     363,   182,   179,   358,   185,   180,     4,     5,     4,   364,
     185,   185,   180,    66,   182,   846,    69,   380,   186,    72,
    1564,   179,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,    76,   169,   170,   360,   361,   362,   363,   169,
     170,    39,    40,    41,    42,    43,    44,     5,     8,   185,
     181,   414,   183,    51,    52,   185,    54,   188,   182,   179,
     348,   185,   350,   351,   352,   353,   354,    65,   356,   779,
     176,   177,   360,   361,   362,   169,   170,   183,   185,   179,
     187,    39,    40,    41,    42,    43,    44,   442,   443,   444,
     445,   185,    72,    51,    52,   694,    54,    93,    94,    95,
      96,   461,   462,     6,     7,   101,  1650,    65,   104,   469,
     185,   185,   187,   187,   463,   464,   169,   170,   169,   170,
     169,   170,    72,   171,   172,   173,   179,   490,   491,   492,
     178,     6,     7,   186,   185,   181,   185,   183,   501,   205,
     206,   207,   188,   186,   210,   211,   212,   145,   146,   169,
     170,   180,   515,   169,   170,   555,   185,     6,   989,   522,
      74,   169,   170,   994,   995,   996,   997,   998,   180,   185,
     182,  1002,  1003,   185,   169,   170,   501,   185,   169,   170,
     246,   247,   185,   598,   187,    72,   549,   145,   146,    72,
     185,   180,   258,   259,   185,   185,   185,   187,   179,   599,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   169,   170,  1490,    69,   178,  1493,
     169,   170,  1496,    89,   169,   170,   180,   187,   169,   170,
     185,   185,    72,    99,   180,   598,   185,   169,   170,   185,
     185,   107,   108,   109,   185,   600,   186,   113,   114,   115,
     116,   169,   170,   185,   180,   838,   671,   169,   170,   185,
     180,  1431,   182,  1433,   186,  1435,   186,   185,   185,    89,
     187,    72,   635,   185,   637,   690,     4,   640,    69,    99,
     643,    72,   645,    74,   647,   648,  1117,   107,   108,   109,
      69,   169,   170,   113,   114,   115,   116,  1128,  1008,    69,
     169,   170,   171,   172,   173,     4,    89,   185,   671,   178,
       4,   185,  1586,   187,  1024,   640,    99,   180,   643,   182,
     645,   187,   185,     4,   107,   108,   109,   690,   691,   179,
     113,   114,   115,   116,   179,   735,   181,   697,   183,    66,
     179,   186,    69,   188,   704,    72,   179,    74,    66,   179,
     710,    69,   640,   180,    72,   182,  1630,   645,   185,  1633,
       6,   776,  1636,   778,     6,  1639,    66,   187,   180,    69,
     182,   181,    72,   185,    74,   738,   180,  1547,   182,   779,
     185,   185,   187,     4,   747,   785,   749,   185,   751,   187,
     753,   185,   185,   187,   187,   758,     4,  1671,   761,  1673,
     180,  1675,   182,    72,   187,    74,    72,   185,    74,   187,
     185,   179,   187,   776,   185,   778,   187,   179,  1232,  1233,
     179,   179,   785,   165,   166,   167,   168,   169,   170,   171,
     172,   173,  1015,   188,  1144,  1605,   178,  1607,   193,  1609,
     179,   185,   197,   187,   185,  1615,   187,   810,   185,   204,
     187,     7,   815,   816,   817,   185,   185,   187,   187,   859,
     785,   185,   825,   187,   879,   880,   185,   882,   187,   884,
     885,   179,   179,   888,   889,   185,   179,   187,   841,   842,
     843,   844,   179,   179,  1654,    89,  1656,   185,  1658,   187,
     815,   816,   817,   179,   185,    99,   187,   785,   186,   179,
     825,   864,   186,   107,   108,   109,   185,     6,   187,   113,
     114,   115,   116,   186,     6,   875,   879,   880,   185,   882,
     187,   884,   885,    89,   179,   888,   889,   815,   816,   817,
     893,   179,     4,    99,     6,   179,   185,   825,   187,   864,
     179,   107,   108,   109,   185,     4,   187,   113,   114,   115,
     116,   185,   185,   187,   187,     6,   956,   972,   973,   974,
      89,   186,   922,   923,   924,   179,   185,   982,   187,   185,
      99,   187,   185,   185,   187,   187,   864,   179,   107,   108,
     109,   179,   179,   187,   113,   114,   115,   116,   179,   179,
    1173,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   185,   185,   187,   187,   178,  1008,   972,
     973,   974,  1426,     8,  1029,   185,   185,   187,   187,   982,
     185,   187,   187,   186,   185,   380,   187,   185,   179,   187,
    1045,   185,   185,   187,   187,   185,  1051,   187,   185,   185,
     187,   187,  1057,     8,  1059,  1060,   185,   179,   187,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,   185,   187,   187,
     179,   186,   186,   186,   186,   179,  1029,   179,   179,   179,
       6,  1086,   181,   186,     6,   181,   181,   181,   186,   186,
     181,     6,  1045,   183,  1039,   132,  1101,     6,  1051,  1392,
    1105,   186,   188,     6,  1057,   188,  1059,  1060,     6,   186,
     186,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,  1086,     6,   181,     4,   178,   178,   183,
       7,    89,   181,   186,     7,   490,   491,   492,  1101,  1099,
       6,    99,  1105,   187,  1107,     6,  1146,     6,   180,   107,
     108,   109,     7,     7,     7,   113,   114,   115,   116,     6,
     515,   186,     7,     6,  1179,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     7,
       6,     6,     6,   178,     4,    48,    48,   129,    48,   186,
    1153,    48,   187,   180,   549,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     6,
    1165,     6,     6,   178,  1397,   180,  1179,   180,   180,   185,
     180,   185,     6,   180,   185,    89,  1189,   180,  1153,   187,
     185,   185,   180,     4,     4,    99,   182,  1192,  1198,  1254,
       6,  1440,     6,   107,   108,   109,     6,     6,   132,   113,
     114,   115,   116,     7,     7,     7,  1271,     7,   132,     7,
       7,   132,  1262,  1278,  1189,  1153,  1281,     7,     7,  1284,
     186,     4,     6,  1228,  1234,   180,  1236,   180,  1238,   180,
     635,   180,   637,  1232,  1233,   183,     6,    89,  1303,  1252,
     187,  1254,  1252,  1256,   187,  1255,  1256,    99,   186,   182,
     186,  1189,     7,     7,     7,   107,   108,   109,  1271,  1324,
     186,   113,   114,   115,   116,  1278,   186,   186,  1281,     6,
       6,  1284,  1277,   187,     6,   183,     6,    89,     7,  1284,
    1285,   181,     6,   179,   186,   179,   691,    99,     6,   166,
    1303,     7,     7,  1358,     7,   107,   108,   109,    74,  1548,
       7,   113,   114,   115,   116,     7,     4,     7,     7,     6,
       6,  1324,     7,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     7,     7,     7,
       7,   178,     7,   738,     7,   187,     7,     4,     6,   179,
     186,  1406,   747,     6,   749,  1358,   751,     6,   753,     7,
    1363,     7,     7,   758,     7,   186,   761,  1422,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     6,
    1383,     6,     6,   178,  1439,   187,  1389,    89,    72,  1392,
       6,     6,     4,     4,     4,     4,   187,    99,    89,     6,
       6,     6,     6,  1406,   185,   107,   108,   109,    99,   180,
     180,   113,   114,   115,   116,   810,   107,   108,   109,  1422,
    1423,   180,   113,   114,   115,   116,   183,  1392,     7,   179,
    1430,   186,  1432,     6,  1434,   183,  1439,  1426,     6,   186,
     186,  1444,  1442,  1498,    82,  1445,   841,   842,   843,   844,
       6,   101,   186,   186,     6,     6,   186,     6,     6,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,     6,   187,     5,     4,     6,     4,
     186,     7,   186,     6,     6,  1498,   146,   147,   893,   181,
       6,     6,     6,   186,     6,   186,    89,   186,   128,  1564,
       6,   185,     6,     4,  1569,     4,    99,    89,     6,    12,
      13,     4,     6,  1518,   107,   108,   109,    99,     6,     6,
     113,   114,   115,   116,    83,   107,   108,   109,     6,     6,
       4,   113,   114,   115,   116,     6,  1549,     6,  1551,     6,
       6,  1551,     5,   186,     6,     6,   132,     6,     6,     6,
       6,  1564,     6,     6,     6,     6,  1569,     6,     6,     6,
       6,   185,     6,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     6,    77,   180,     6,   183,     7,    82,
      83,     6,    85,    86,    87,  1650,     6,   186,    91,     6,
       5,  1596,     6,     6,   187,    70,   186,     6,   157,   158,
     159,   160,   161,   263,  1617,   187,   186,     7,   187,     6,
     187,   186,  1625,   186,   186,   174,   186,   127,     6,   178,
     280,   124,   125,   126,   187,     6,     6,     6,   187,   188,
     189,   190,     6,   192,   193,   194,   195,  1650,   197,   198,
     199,   130,     6,     6,     6,   204,     6,     6,   186,     6,
    1625,     6,  1665,     6,  1667,     6,   186,     6,    89,     6,
       6,    89,   186,   222,     6,    89,   187,   186,     6,     6,
       6,     6,   231,   232,     6,     6,   187,     6,   186,   186,
    1693,   240,     6,     6,   187,     6,   186,  1625,     6,   186,
    1665,     6,  1667,     6,     6,   186,     6,     6,     6,     6,
     186,   186,  1107,   186,   186,     6,     6,     6,     6,     6,
       6,     6,   271,   272,   273,     6,  1036,  1521,  1693,  1411,
    1044,  1412,   412,     3,   283,   284,   285,  1665,   287,  1667,
       3,   290,   291,  1169,    -1,   294,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     309,    -1,   440,    -1,   178,  1693,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
     359,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
     379,   380,    -1,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,    -1,    -1,
     399,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,   414,    -1,    -1,    -1,    82,
      83,   420,    85,    86,    87,    -1,   425,    -1,    91,    -1,
      -1,   430,   431,    -1,    -1,    -1,    -1,   436,   437,    -1,
      -1,    -1,   441,   442,   443,   444,   445,   446,   447,   448,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,   475,   476,   477,   478,
     479,    -1,    -1,    -1,   483,    -1,    -1,   486,   487,    -1,
      -1,   490,   491,   492,    -1,    -1,   495,   496,   497,   498,
      -1,    12,    13,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,
      -1,    -1,   521,   522,   187,   524,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,
      -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,   548,
     549,    -1,    -1,    -1,   553,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    -1,  1423,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,  1444,
      -1,    -1,   601,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,   632,    -1,    -1,   635,    -1,   637,   638,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,   648,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   670,   271,    -1,   273,    -1,   187,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,   691,    82,    83,    -1,    85,    86,    87,   698,
     699,    -1,    91,    -1,  1549,   704,  1551,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   717,    -1,
      -1,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,   738,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   747,    -1,
     749,    -1,   751,    -1,   753,    -1,    -1,    -1,    -1,   758,
      -1,    -1,   761,    -1,    -1,    -1,    -1,    -1,   767,    -1,
     769,   770,  1617,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   380,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,   187,   798,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   806,   807,   808,
      -1,   810,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   823,    -1,    -1,    -1,    -1,   828,
      -1,    -1,   831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   841,   842,   843,   844,    -1,    -1,   847,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,   490,   491,   492,   893,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
       7,     8,    -1,    -1,    -1,    64,   515,    -1,    -1,    12,
      13,    -1,    -1,   522,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     549,    -1,    -1,   952,    -1,    -1,   955,    -1,    -1,    -1,
     959,    -1,   961,   962,   963,    -1,    -1,    -1,    -1,    -1,
     969,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    -1,    -1,   986,    -1,    82,
      83,    -1,    85,    86,    87,   144,    -1,    -1,    91,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1016,    -1,    -1,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,  1027,  1028,
     179,   124,   125,   126,    -1,   184,   635,   186,   637,  1038,
    1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,   648,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,  1076,  1077,  1078,
      -1,   178,    -1,    -1,    -1,    -1,    -1,  1086,    -1,  1088,
      -1,    -1,   691,    -1,   187,    -1,    -1,    -1,    -1,    -1,
    1099,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1107,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,    86,    87,  1133,  1134,  1135,    91,    -1,   738,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   747,    -1,
     749,    -1,   751,    -1,   753,    -1,    -1,    -1,    -1,   758,
      -1,    -1,   761,    -1,    -1,    -1,    -1,  1166,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1180,    -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,
      -1,     6,    -1,  1192,    -1,    -1,    -1,  1196,  1197,    -1,
      -1,    -1,    -1,    -1,  1203,  1204,    -1,    -1,    -1,  1208,
      -1,   810,    -1,    -1,    -1,    -1,    -1,  1216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,  1228,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1240,   841,   842,   843,   844,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1252,    -1,    -1,     6,  1256,    -1,    -1,
    1259,    12,    13,    -1,    -1,  1264,  1265,  1266,  1267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   893,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1301,  1302,    -1,    -1,    -1,    -1,    -1,    -1,
    1309,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,     6,    -1,    -1,
      91,    -1,    -1,    -1,  1343,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,  1361,   178,  1363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,  1378,
      -1,  1380,    -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,
    1389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,  1402,    -1,    -1,    -1,    -1,  1407,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,  1423,    -1,    -1,    -1,   178,    -1,
      -1,  1430,    -1,  1432,    -1,  1434,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1444,    -1,    -1,    -1,  1448,
    1449,  1450,  1451,  1452,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,  1467,  1468,
      -1,    82,    83,  1472,    85,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,  1482,    -1,    -1,    -1,  1486,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,  1107,   178,
      -1,    -1,    -1,   124,   125,   126,    -1,  1516,    -1,    -1,
      -1,    -1,  1521,    -1,    -1,    12,    13,    -1,    -1,  1528,
      -1,    -1,    -1,    -1,    -1,    -1,  1535,    -1,    -1,  1538,
      -1,    -1,  1541,    -1,    -1,    -1,  1545,    -1,    -1,    -1,
    1549,    -1,  1551,  1552,  1553,  1554,  1555,    -1,    -1,    -1,
      -1,    -1,    -1,  1562,    -1,    -1,  1565,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   187,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,     6,    82,    83,    -1,    85,    86,
      87,    -1,    -1,  1602,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,  1617,    -1,
    1619,  1620,  1621,  1622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1252,    -1,    -1,    -1,  1256,    -1,    -1,
      -1,    -1,  1661,  1662,  1663,  1664,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
     187,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    -1,    54,    -1,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,  1363,    -1,   178,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,  1383,   178,    -1,    -1,    -1,    -1,
    1389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,  1423,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,   179,    -1,   181,  1444,   183,   184,    -1,   186,
      -1,   188,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,    -1,
    1549,   101,  1551,    -1,   104,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    86,    87,    -1,    -1,
       6,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,     6,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,  1617,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,    -1,     3,     4,   184,    -1,   186,   187,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    -1,    -1,    -1,
     101,    -1,    -1,   104,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     6,    -1,    -1,
      -1,   178,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,   184,    -1,    -1,   187,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    -1,    54,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     6,   144,   145,
     146,   178,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,   179,    -1,     3,     4,     5,   184,    -1,
     186,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      -1,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     7,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,   179,    -1,     3,     4,     5,   184,    -1,   186,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   144,     8,    -1,    -1,   178,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,     3,     4,    -1,   184,    -1,   186,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    -1,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     8,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    -1,     3,
       4,    -1,   184,    -1,   186,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     144,     8,    -1,    -1,   178,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   170,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,   179,    -1,     3,     4,    -1,
     184,    -1,   186,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    -1,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,   179,    -1,     3,     4,     5,   184,    -1,
     186,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     8,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    -1,    54,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    64,    65,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
      -1,    86,    -1,   151,   152,   153,   154,   155,    93,    94,
      95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   170,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,   179,    -1,     3,     4,     5,   184,
      -1,   186,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    -1,    54,    -1,    56,
      57,    58,    -1,     3,     4,     5,    -1,    64,    65,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    54,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    65,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,   144,   145,   146,
      -1,   185,    -1,   187,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,   184,    -1,   186,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   144,   145,   146,    -1,   178,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,     3,     4,    -1,   184,    -1,   186,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    -1,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    -1,     3,
       4,    -1,   184,    -1,   186,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    45,    46,    47,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,   169,   170,    -1,    -1,    -1,
     174,     3,     4,     5,    -1,   179,    -1,     9,    10,    11,
     184,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      52,    -1,    54,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,
     182,    -1,   184,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
     187,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,    -1,
      -1,    -1,   174,     3,     4,    -1,    -1,   179,    -1,     9,
      10,    11,   184,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    56,    57,    58,    -1,
       9,    10,    11,    -1,    64,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,   187,   144,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,     0,     1,    -1,    -1,
       4,    -1,   151,   152,   153,   154,   155,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    37,    38,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,
      -1,    55,    -1,    -1,    -1,    59,    60,    -1,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,   118,     4,    -1,    -1,    -1,   123,
     124,   125,   126,    12,    13,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,   148,   149,   150,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      59,    60,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,    -1,
     129,    -1,   131,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,   148,
     149,   150,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,   180,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,   180,    -1,   182,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   182,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
     182,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   182,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,   182,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,   182,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,   182,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,   182,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,   182,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   182,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
     182,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   182,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,   182,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
     180,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,   180,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,   180,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,   180,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,   180,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
     180,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,   180,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,   180,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,   180,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,   180,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
     180,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,   180,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,   180,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,   180,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,   180,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
     180,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,   180,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,   180,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,   180,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   190,   191,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    53,    55,    59,    60,    62,    63,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   110,
     111,   112,   118,   123,   124,   125,   126,   129,   131,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     147,   148,   149,   150,   192,   194,   195,   215,   232,   233,
     236,   237,   238,   239,   240,   241,   242,   263,   264,   265,
     266,   284,   285,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      51,    52,    54,    56,    57,    58,    64,    65,   138,   144,
     145,   146,   151,   152,   153,   154,   155,   169,   170,   174,
     179,   181,   183,   184,   186,   188,   213,   267,   268,   280,
     281,   284,   285,    13,    72,   179,   179,     6,   186,     6,
       6,     6,   179,     6,     6,   181,   181,   179,   186,   179,
     179,     4,   179,   186,   179,   179,     4,   186,   179,   179,
      76,    72,    72,     6,   186,    66,    69,    72,    72,    72,
      69,    72,    74,    74,    66,    69,    72,    74,    69,    72,
      74,    69,    72,   179,    69,   129,   142,   143,   186,   169,
     170,   179,   186,   270,   271,   270,   186,    66,    69,    72,
     186,   270,     4,    66,    70,    82,    72,    74,    72,    69,
       4,   138,   186,     4,     6,    66,    69,    72,    69,    72,
       4,     4,     4,     4,     5,    36,    66,    69,    72,    74,
      86,   170,   179,   186,   233,   242,   267,   273,   274,   275,
     284,   285,     4,   179,   179,   179,     4,   186,   277,     4,
     179,   179,     6,     6,   181,     4,   284,   285,     4,     5,
     186,     5,   186,     4,   267,     6,   179,   186,   179,   181,
     188,   213,     7,   156,   157,   158,   159,   176,   177,   211,
     212,     4,   181,   183,   181,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     179,   179,   179,   179,   179,   179,   179,   213,   213,     7,
     179,   179,   179,   179,   179,   267,   267,   267,   267,   182,
     267,     4,   129,   130,   285,     4,   233,   234,   235,   186,
     186,     6,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   178,   186,     6,   181,
     212,     6,   267,     4,   280,   281,   285,   280,   267,   280,
     283,   217,   220,   267,   170,   267,   275,   276,   267,   267,
     179,   267,   276,   267,   267,   179,   276,   267,   267,   273,
     179,   186,   276,   274,   274,   274,   179,   179,   274,   274,
     274,   179,   179,   179,   179,   179,   179,   179,   179,   273,
     267,     4,   273,   277,   186,   186,   270,   270,   270,   267,
     267,   169,   170,   186,   186,   270,   186,   186,   186,   169,
     170,   179,   235,   270,   186,   179,   186,   179,   179,   179,
     274,   274,   273,   179,     4,     6,   181,   181,   235,     6,
     186,   186,   186,   274,   274,   181,   181,   181,   181,   183,
     213,   181,     5,   132,   186,     5,   132,     5,   132,     5,
     132,    66,    69,    72,    74,   186,   267,   275,   267,   187,
     276,     8,   171,     6,   181,   213,     6,   267,   267,   267,
     183,   267,   186,   132,   267,   267,   267,     6,     6,   235,
       6,   235,   181,     6,   273,   273,   182,   267,   186,   186,
     281,   273,     6,   181,   267,     4,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   283,   280,
     283,   280,   280,   280,   280,   280,   283,   280,   267,   281,
     267,   280,   280,   280,   285,   281,   180,     7,   211,   182,
       7,   211,   212,   183,     7,   181,   187,    66,    69,    72,
      74,   232,   267,   276,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   196,
     267,     6,   181,   183,   180,   185,   180,   185,   185,   180,
     185,   182,   185,   216,   182,   216,   180,   171,   185,   187,
     180,   180,   267,   180,   187,   180,   180,   267,   187,   180,
     180,     7,   267,   267,   187,     6,     6,     6,   267,   267,
       7,     7,   260,   260,   267,   226,   267,   281,   227,   267,
     281,   228,   267,   281,   229,   267,   281,   267,   267,   267,
       7,   186,   180,     6,   186,   235,   235,   185,   185,   185,
     270,   270,   234,   234,   185,   267,   267,   267,   267,   246,
     185,   235,   267,   267,   267,   267,   267,     7,   261,     6,
       7,   267,     6,   267,   267,   187,   276,   276,   276,     6,
       6,   267,   267,   267,   267,     4,   180,   182,   186,   214,
     285,    48,   267,    48,    48,    48,     5,   186,     5,   186,
       5,   186,     5,   186,   276,   180,   187,   267,   186,   267,
     275,   186,   214,   180,   180,   180,   129,   185,   235,   186,
       8,   180,   182,   187,   187,   180,   185,   187,   211,   182,
     267,   276,     6,     6,   267,   182,   212,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   185,   214,
     214,   214,   214,   214,   214,   214,   185,   185,   185,   214,
     185,   214,   214,   180,   180,   185,   185,   185,   180,   180,
     269,   282,     6,   185,   180,   185,   180,   180,   211,   273,
     183,   211,   212,   281,   267,     6,     4,     4,   186,   278,
     182,   186,   186,   186,   186,   187,   187,     8,     4,   119,
     120,   121,   122,   187,   199,   203,   206,   208,   209,   182,
     267,     4,     6,   166,   193,   276,     6,   276,   267,     6,
     280,     6,   285,     6,   280,     7,   267,   275,   132,     7,
       7,   180,     7,   132,     7,     7,   180,   132,     7,     7,
     267,   180,   187,   186,   180,   180,   267,   273,     4,   259,
       6,   180,   180,   180,   180,   180,   180,   180,   180,   273,
     276,   183,   235,   187,   187,   270,   267,   267,   187,   187,
     267,   270,   185,   185,   185,    89,    99,   107,   108,   109,
     113,   114,   115,   116,   256,   257,   270,   187,   243,   180,
     187,   180,   180,   180,   267,     6,   267,   180,   182,   182,
     187,   187,   187,   182,   182,   185,   182,   276,   182,   186,
     187,   186,   186,   186,   276,   276,   276,   276,   187,     8,
     276,   276,     7,     7,     7,   183,   267,   187,   267,   267,
       7,   183,   186,   273,     6,   273,   211,   212,   187,   187,
     182,   183,   212,   280,   267,   267,   267,   267,   276,   280,
     280,   280,   222,   224,   267,   280,   267,     6,     4,   129,
     130,   267,     6,     6,     6,     7,   181,   277,   279,     6,
     276,   276,   276,   276,   214,   267,   200,   179,   179,   186,
     210,     6,   212,   182,   166,   280,   180,   180,   185,     7,
     270,    72,    74,   273,   273,     7,   273,    72,    74,   273,
     273,     7,    74,   273,   273,     6,     7,     7,   276,     7,
       7,    89,   258,     6,     7,     7,     7,     7,     7,     7,
       7,     7,     6,   187,     4,   187,   185,   185,   185,   187,
     187,   270,   270,   270,     4,     6,   186,     6,   179,     6,
     117,     6,   117,     6,   117,     6,   117,   187,   257,   185,
     256,     7,     6,     7,     7,     7,     6,   186,     6,     6,
       6,    72,   267,     6,     6,   267,   183,   187,   267,   267,
     267,   267,   187,   187,   187,   187,   267,   187,   187,   273,
     273,   273,     4,   185,     8,     8,   180,     4,     4,   273,
     187,     6,   267,     6,   214,     6,     4,     6,   214,   214,
     214,   214,   214,   185,   180,   180,   185,   214,   223,   185,
     214,   225,   180,   180,     6,     7,   211,   212,   183,     7,
       6,   277,   267,   185,   187,   187,   187,   187,   187,   211,
     179,   267,   267,   272,   273,   186,   183,     6,     6,   193,
       6,   267,   186,   267,   281,     6,   186,   186,    82,   231,
     231,   273,     6,   186,   186,     6,     6,   273,   186,     6,
       6,     5,   273,   187,   273,   273,     4,     6,   273,   273,
     273,   273,   273,   273,   273,   273,     7,     6,     7,   267,
     267,   267,   186,   186,   185,   187,   185,   187,   185,   187,
     181,   267,   273,   267,     6,     6,     6,     6,   267,   270,
     187,     5,   186,   273,   186,   186,   186,   273,   276,   186,
       6,   182,     4,   214,   185,   185,   185,   185,   214,     6,
       6,   128,   267,   267,   267,     6,     6,     7,   185,     6,
       6,   211,   212,   280,     4,     4,   281,   267,     6,     4,
     278,     6,   182,   277,     6,     6,     6,     6,   273,   197,
     267,   185,   185,   185,   187,   198,   267,     4,   280,   185,
     267,   281,   267,   267,   270,     6,     6,     6,   267,   267,
       6,   267,     5,     6,   186,     6,   132,   230,   267,     6,
       6,     6,     6,     6,     6,     4,     6,     6,   267,   267,
     281,   187,   180,   185,   187,   234,   234,   270,     6,   247,
     270,     6,   248,   270,     6,   249,   267,   187,   185,   180,
     187,   185,     6,   170,   270,     6,   272,   270,   270,     6,
     187,   267,     6,   267,   267,   267,   267,   273,   185,   187,
       8,   187,   180,   186,   267,   281,   273,   273,   180,   186,
     273,   281,   186,   267,   281,     6,     6,     7,     6,   183,
       6,   180,   185,   267,   267,   273,   186,   185,   187,     6,
     267,   218,   219,   187,   187,   187,   187,   187,     5,   272,
      70,     6,   186,   186,     6,     6,   186,   267,   187,   187,
     185,   186,   185,   186,   185,   186,   182,     6,   273,     7,
     186,   267,   185,   187,   185,   185,     6,   187,   185,   185,
     185,   185,   127,   267,   267,   276,     6,     6,   187,     6,
     221,   267,   283,   277,   130,   201,   267,   185,   185,   272,
     267,     6,   185,   222,   224,     6,     6,     6,     6,     6,
       6,   187,   186,   272,   276,   234,   185,   187,   267,   270,
     256,   267,   270,   256,   267,   270,   256,     6,   185,   187,
     273,   235,   187,   270,     6,   276,   270,   267,   267,   267,
     267,   267,   187,   187,   187,     6,   185,   187,     7,   187,
       6,   186,   267,   267,   187,   267,   187,   187,   186,   267,
     187,   187,   187,   267,   187,   185,   187,   187,   185,   187,
     187,   185,   187,   273,     6,    89,   187,   244,   186,   185,
     187,   185,   185,   185,   185,   185,     6,     6,   267,   281,
     198,   180,   185,     6,   186,   185,   267,   187,     6,    89,
     262,   187,     6,   250,   267,     6,     6,   251,   267,     6,
       6,   252,   267,     6,   187,   267,   256,   235,   276,     6,
     270,   276,   267,   267,   267,   267,     7,   187,   204,   267,
     272,   267,   185,   273,     6,   186,   187,   186,   187,   186,
     187,     6,     6,   187,   187,   245,   187,   185,   187,   185,
     185,   185,   185,   281,     6,   186,   180,   187,   187,   267,
     256,     6,   253,   256,     6,   254,   256,     6,   255,   256,
       6,   276,     6,   267,   267,   267,   267,   202,   280,   207,
     186,     6,   187,   187,   186,   187,   186,   187,   186,   187,
     187,   185,   185,   185,   185,   185,   187,   186,   272,     6,
       6,   256,     6,   256,     6,   256,     6,   267,   267,   267,
     267,   280,     6,   205,   280,   187,   187,   187,   187,   187,
     187,   187,   187,   185,   187,     6,     6,     6,     6,   280,
       6
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
#line 184 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 195 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 196 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 197 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 198 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 199 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 200 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 201 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 202 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 203 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 214 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 218 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 225 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 230 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 235 "Gmsh.y"
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

  case 26:
/* Line 1787 of yacc.c  */
#line 249 "Gmsh.y"
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

  case 27:
/* Line 1787 of yacc.c  */
#line 262 "Gmsh.y"
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

  case 28:
/* Line 1787 of yacc.c  */
#line 275 "Gmsh.y"
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

  case 29:
/* Line 1787 of yacc.c  */
#line 303 "Gmsh.y"
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

  case 30:
/* Line 1787 of yacc.c  */
#line 317 "Gmsh.y"
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

  case 31:
/* Line 1787 of yacc.c  */
#line 330 "Gmsh.y"
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

  case 32:
/* Line 1787 of yacc.c  */
#line 343 "Gmsh.y"
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

  case 33:
/* Line 1787 of yacc.c  */
#line 361 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 375 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 377 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 382 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 384 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 389 "Gmsh.y"
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

  case 44:
/* Line 1787 of yacc.c  */
#line 493 "Gmsh.y"
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

  case 45:
/* Line 1787 of yacc.c  */
#line 503 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 519 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 529 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 538 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 547 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 554 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 564 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 572 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 582 "Gmsh.y"
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

  case 55:
/* Line 1787 of yacc.c  */
#line 601 "Gmsh.y"
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

  case 56:
/* Line 1787 of yacc.c  */
#line 620 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 626 "Gmsh.y"
    {
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 633 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 634 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 635 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 637 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 641 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 642 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 648 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 648 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 649 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 649 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 658 "Gmsh.y"
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

  case 72:
/* Line 1787 of yacc.c  */
#line 719 "Gmsh.y"
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

  case 73:
/* Line 1787 of yacc.c  */
#line 748 "Gmsh.y"
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

  case 74:
/* Line 1787 of yacc.c  */
#line 777 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 782 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 787 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 792 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 799 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 806 "Gmsh.y"
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

  case 80:
/* Line 1787 of yacc.c  */
#line 821 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 826 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 831 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 840 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 846 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 855 "Gmsh.y"
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

  case 86:
/* Line 1787 of yacc.c  */
#line 873 "Gmsh.y"
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

  case 87:
/* Line 1787 of yacc.c  */
#line 891 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 900 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 912 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 917 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 925 "Gmsh.y"
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

  case 92:
/* Line 1787 of yacc.c  */
#line 945 "Gmsh.y"
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

  case 93:
/* Line 1787 of yacc.c  */
#line 968 "Gmsh.y"
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

  case 94:
/* Line 1787 of yacc.c  */
#line 979 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 987 "Gmsh.y"
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

  case 96:
/* Line 1787 of yacc.c  */
#line 1009 "Gmsh.y"
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

  case 97:
/* Line 1787 of yacc.c  */
#line 1032 "Gmsh.y"
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

  case 98:
/* Line 1787 of yacc.c  */
#line 1058 "Gmsh.y"
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

  case 99:
/* Line 1787 of yacc.c  */
#line 1079 "Gmsh.y"
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

  case 100:
/* Line 1787 of yacc.c  */
#line 1091 "Gmsh.y"
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

  case 104:
/* Line 1787 of yacc.c  */
#line 1109 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 1118 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 1127 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 1129 "Gmsh.y"
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

  case 108:
/* Line 1787 of yacc.c  */
#line 1139 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1148 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1150 "Gmsh.y"
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

  case 112:
/* Line 1787 of yacc.c  */
#line 1164 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1172 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1178 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1190 "Gmsh.y"
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

  case 118:
/* Line 1787 of yacc.c  */
#line 1201 "Gmsh.y"
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

  case 119:
/* Line 1787 of yacc.c  */
#line 1216 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 1232 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1240 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 1249 "Gmsh.y"
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

  case 125:
/* Line 1787 of yacc.c  */
#line 1267 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1271 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1280 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1284 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1293 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1297 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1306 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1310 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1323 "Gmsh.y"
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

  case 135:
/* Line 1787 of yacc.c  */
#line 1335 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1339 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1349 "Gmsh.y"
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

  case 138:
/* Line 1787 of yacc.c  */
#line 1372 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1388 "Gmsh.y"
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

  case 140:
/* Line 1787 of yacc.c  */
#line 1411 "Gmsh.y"
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

  case 141:
/* Line 1787 of yacc.c  */
#line 1429 "Gmsh.y"
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

  case 142:
/* Line 1787 of yacc.c  */
#line 1450 "Gmsh.y"
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

  case 143:
/* Line 1787 of yacc.c  */
#line 1468 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1498 "Gmsh.y"
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

  case 145:
/* Line 1787 of yacc.c  */
#line 1528 "Gmsh.y"
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

  case 146:
/* Line 1787 of yacc.c  */
#line 1546 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1565 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1591 "Gmsh.y"
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

  case 149:
/* Line 1787 of yacc.c  */
#line 1609 "Gmsh.y"
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

  case 150:
/* Line 1787 of yacc.c  */
#line 1627 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1646 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1664 "Gmsh.y"
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

  case 153:
/* Line 1787 of yacc.c  */
#line 1703 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1709 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1715 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1722 "Gmsh.y"
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

  case 157:
/* Line 1787 of yacc.c  */
#line 1747 "Gmsh.y"
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

  case 158:
/* Line 1787 of yacc.c  */
#line 1772 "Gmsh.y"
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

  case 159:
/* Line 1787 of yacc.c  */
#line 1789 "Gmsh.y"
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

  case 160:
/* Line 1787 of yacc.c  */
#line 1809 "Gmsh.y"
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

  case 161:
/* Line 1787 of yacc.c  */
#line 1842 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1862 "Gmsh.y"
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1880 "Gmsh.y"
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

  case 164:
/* Line 1787 of yacc.c  */
#line 1897 "Gmsh.y"
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

  case 165:
/* Line 1787 of yacc.c  */
#line 1913 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1934 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1939 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1944 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1949 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1954 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1959 "Gmsh.y"
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

  case 172:
/* Line 1787 of yacc.c  */
#line 1982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1988 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1998 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1999 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2004 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2008 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2012 "Gmsh.y"
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

  case 179:
/* Line 1787 of yacc.c  */
#line 2035 "Gmsh.y"
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

  case 180:
/* Line 1787 of yacc.c  */
#line 2058 "Gmsh.y"
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

  case 181:
/* Line 1787 of yacc.c  */
#line 2081 "Gmsh.y"
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

  case 182:
/* Line 1787 of yacc.c  */
#line 2109 "Gmsh.y"
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

  case 183:
/* Line 1787 of yacc.c  */
#line 2130 "Gmsh.y"
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

  case 184:
/* Line 1787 of yacc.c  */
#line 2157 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2178 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2199 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2219 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2331 "Gmsh.y"
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

  case 189:
/* Line 1787 of yacc.c  */
#line 2350 "Gmsh.y"
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

  case 190:
/* Line 1787 of yacc.c  */
#line 2389 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2497 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 2506 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 2512 "Gmsh.y"
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

  case 194:
/* Line 1787 of yacc.c  */
#line 2527 "Gmsh.y"
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

  case 195:
/* Line 1787 of yacc.c  */
#line 2555 "Gmsh.y"
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

  case 196:
/* Line 1787 of yacc.c  */
#line 2572 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 2581 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 2595 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2601 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2607 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2616 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2625 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2634 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2648 "Gmsh.y"
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

  case 205:
/* Line 1787 of yacc.c  */
#line 2704 "Gmsh.y"
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

  case 206:
/* Line 1787 of yacc.c  */
#line 2722 "Gmsh.y"
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

  case 207:
/* Line 1787 of yacc.c  */
#line 2739 "Gmsh.y"
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

  case 208:
/* Line 1787 of yacc.c  */
#line 2754 "Gmsh.y"
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

  case 209:
/* Line 1787 of yacc.c  */
#line 2773 "Gmsh.y"
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

  case 210:
/* Line 1787 of yacc.c  */
#line 2785 "Gmsh.y"
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

  case 211:
/* Line 1787 of yacc.c  */
#line 2809 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2813 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 2818 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2825 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2831 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2836 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2842 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2850 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2854 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2858 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2864 "Gmsh.y"
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

  case 222:
/* Line 1787 of yacc.c  */
#line 2918 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2931 "Gmsh.y"
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

  case 224:
/* Line 1787 of yacc.c  */
#line 2948 "Gmsh.y"
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

  case 225:
/* Line 1787 of yacc.c  */
#line 2965 "Gmsh.y"
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

  case 226:
/* Line 1787 of yacc.c  */
#line 2986 "Gmsh.y"
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

  case 227:
/* Line 1787 of yacc.c  */
#line 3007 "Gmsh.y"
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

  case 228:
/* Line 1787 of yacc.c  */
#line 3042 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 3050 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 3056 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3063 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3067 "Gmsh.y"
    {
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3076 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3092 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3100 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3106 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3114 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3128 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3134 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3142 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3148 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3156 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3170 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3177 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3184 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3191 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3205 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3212 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3219 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3225 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3232 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3238 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3258 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3271 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3277 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3284 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3290 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3297 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3310 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3323 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3329 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3340 "Gmsh.y"
    {
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3343 "Gmsh.y"
    {
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3349 "Gmsh.y"
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

  case 274:
/* Line 1787 of yacc.c  */
#line 3361 "Gmsh.y"
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

  case 275:
/* Line 1787 of yacc.c  */
#line 3381 "Gmsh.y"
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

  case 276:
/* Line 1787 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3409 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3413 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3417 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3421 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3427 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3433 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3437 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3441 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3445 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3449 "Gmsh.y"
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

  case 287:
/* Line 1787 of yacc.c  */
#line 3468 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3480 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3484 "Gmsh.y"
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

  case 290:
/* Line 1787 of yacc.c  */
#line 3499 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3503 "Gmsh.y"
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

  case 292:
/* Line 1787 of yacc.c  */
#line 3519 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3523 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3528 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3532 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3538 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3542 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3549 "Gmsh.y"
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

  case 299:
/* Line 1787 of yacc.c  */
#line 3605 "Gmsh.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 3675 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3680 "Gmsh.y"
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

  case 302:
/* Line 1787 of yacc.c  */
#line 3747 "Gmsh.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 3783 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3791 "Gmsh.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3834 "Gmsh.y"
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

  case 306:
/* Line 1787 of yacc.c  */
#line 3873 "Gmsh.y"
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

  case 307:
/* Line 1787 of yacc.c  */
#line 3893 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3921 "Gmsh.y"
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

  case 309:
/* Line 1787 of yacc.c  */
#line 3969 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3997 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4025 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 4029 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 4033 "Gmsh.y"
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

  case 314:
/* Line 1787 of yacc.c  */
#line 4061 "Gmsh.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 4100 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4139 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4160 "Gmsh.y"
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

  case 318:
/* Line 1787 of yacc.c  */
#line 4181 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4208 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 4212 "Gmsh.y"
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

  case 321:
/* Line 1787 of yacc.c  */
#line 4222 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4256 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 4257 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4258 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4263 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4269 "Gmsh.y"
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

  case 327:
/* Line 1787 of yacc.c  */
#line 4281 "Gmsh.y"
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

  case 328:
/* Line 1787 of yacc.c  */
#line 4299 "Gmsh.y"
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

  case 329:
/* Line 1787 of yacc.c  */
#line 4326 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4327 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4328 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4329 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4330 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4331 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4332 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4335 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4341 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4342 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4344 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4346 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4347 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4348 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4350 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4351 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4352 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4353 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4354 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4355 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4356 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4357 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4358 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4359 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4360 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4361 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4362 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4363 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4364 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4365 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4366 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4367 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4368 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4370 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4371 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4372 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4373 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4382 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4383 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4384 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4385 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4386 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4387 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4388 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4389 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4390 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4391 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4396 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4398 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4404 "Gmsh.y"
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

  case 384:
/* Line 1787 of yacc.c  */
#line 4421 "Gmsh.y"
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

  case 385:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
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

  case 386:
/* Line 1787 of yacc.c  */
#line 4457 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4462 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
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

  case 389:
/* Line 1787 of yacc.c  */
#line 4480 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4497 "Gmsh.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 4515 "Gmsh.y"
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

  case 392:
/* Line 1787 of yacc.c  */
#line 4536 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4541 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4546 "Gmsh.y"
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

  case 395:
/* Line 1787 of yacc.c  */
#line 4556 "Gmsh.y"
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

  case 396:
/* Line 1787 of yacc.c  */
#line 4566 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4571 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4580 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4585 "Gmsh.y"
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

  case 400:
/* Line 1787 of yacc.c  */
#line 4612 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4616 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4624 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4635 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4639 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4643 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4647 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4654 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4659 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4666 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4671 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4675 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4680 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4692 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4703 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4707 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4719 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4727 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4735 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4742 "Gmsh.y"
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

  case 423:
/* Line 1787 of yacc.c  */
#line 4752 "Gmsh.y"
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

  case 424:
/* Line 1787 of yacc.c  */
#line 4781 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4785 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4789 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4793 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4797 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4801 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4805 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4809 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4813 "Gmsh.y"
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

  case 433:
/* Line 1787 of yacc.c  */
#line 4842 "Gmsh.y"
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

  case 434:
/* Line 1787 of yacc.c  */
#line 4871 "Gmsh.y"
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

  case 435:
/* Line 1787 of yacc.c  */
#line 4900 "Gmsh.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 4930 "Gmsh.y"
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

  case 437:
/* Line 1787 of yacc.c  */
#line 4943 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 4956 "Gmsh.y"
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

  case 439:
/* Line 1787 of yacc.c  */
#line 4969 "Gmsh.y"
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

  case 440:
/* Line 1787 of yacc.c  */
#line 4981 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 4991 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 5001 "Gmsh.y"
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

  case 443:
/* Line 1787 of yacc.c  */
#line 5013 "Gmsh.y"
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

  case 444:
/* Line 1787 of yacc.c  */
#line 5025 "Gmsh.y"
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

  case 445:
/* Line 1787 of yacc.c  */
#line 5037 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 5055 "Gmsh.y"
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

  case 447:
/* Line 1787 of yacc.c  */
#line 5076 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5081 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5085 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5089 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5101 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5105 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5117 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5124 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5134 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5138 "Gmsh.y"
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

  case 457:
/* Line 1787 of yacc.c  */
#line 5153 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5158 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5165 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5169 "Gmsh.y"
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

  case 461:
/* Line 1787 of yacc.c  */
#line 5182 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5190 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5201 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5205 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5213 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5219 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5227 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5235 "Gmsh.y"
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

  case 469:
/* Line 1787 of yacc.c  */
#line 5250 "Gmsh.y"
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

  case 470:
/* Line 1787 of yacc.c  */
#line 5264 "Gmsh.y"
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

  case 471:
/* Line 1787 of yacc.c  */
#line 5278 "Gmsh.y"
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

  case 472:
/* Line 1787 of yacc.c  */
#line 5290 "Gmsh.y"
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

  case 473:
/* Line 1787 of yacc.c  */
#line 5306 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5310 "Gmsh.y"
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

  case 475:
/* Line 1787 of yacc.c  */
#line 5329 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5336 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5338 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5349 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5354 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5360 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5369 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5382 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5385 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11360 "Gmsh.tab.cpp"
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
#line 5389 "Gmsh.y"


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
