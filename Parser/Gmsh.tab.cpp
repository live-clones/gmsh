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
#define YYLAST   9125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  477
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1694

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
    1763,  1764,  1766,  1767,  1770,  1771,  1774,  1782,  1789,  1798,
    1804,  1808,  1816,  1822,  1827,  1834,  1841,  1854,  1865,  1876,
    1887,  1898,  1909,  1914,  1919,  1924,  1929,  1934,  1937,  1941,
    1948,  1950,  1952,  1954,  1957,  1963,  1971,  1982,  1984,  1988,
    1991,  1994,  1997,  2001,  2005,  2009,  2013,  2017,  2021,  2025,
    2029,  2033,  2037,  2041,  2045,  2049,  2053,  2059,  2064,  2069,
    2074,  2079,  2084,  2089,  2094,  2099,  2104,  2109,  2116,  2121,
    2126,  2131,  2136,  2141,  2146,  2151,  2158,  2165,  2172,  2177,
    2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,  2195,  2197,
    2198,  2205,  2207,  2212,  2217,  2222,  2227,  2232,  2235,  2241,
    2247,  2251,  2258,  2263,  2271,  2278,  2285,  2292,  2297,  2299,
    2302,  2305,  2309,  2313,  2325,  2335,  2343,  2351,  2353,  2357,
    2359,  2361,  2364,  2368,  2373,  2379,  2381,  2383,  2386,  2390,
    2394,  2400,  2405,  2408,  2411,  2414,  2417,  2423,  2429,  2435,
    2441,  2458,  2475,  2492,  2509,  2511,  2513,  2517,  2521,  2526,
    2533,  2540,  2542,  2544,  2548,  2552,  2562,  2570,  2572,  2578,
    2582,  2589,  2591,  2595,  2597,  2599,  2603,  2610,  2612,  2614,
    2616,  2621,  2628,  2633,  2638,  2643,  2652,  2657,  2662,  2669,
    2674,  2675,  2682,  2684,  2688,  2694,  2700,  2702
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     190,     0,    -1,   191,    -1,     1,     6,    -1,    -1,   191,
     192,    -1,   195,    -1,   194,    -1,   215,    -1,   232,    -1,
     233,    -1,   237,    -1,   238,    -1,   239,    -1,   242,    -1,
     262,    -1,   263,    -1,   241,    -1,   240,    -1,   236,    -1,
     265,    -1,   166,    -1,   166,   166,    -1,    37,   179,   279,
     180,     6,    -1,    38,   179,   279,   180,     6,    -1,    37,
     179,   279,   180,   193,   279,     6,    -1,    37,   179,   279,
     185,   275,   180,     6,    -1,    38,   179,   279,   185,   275,
     180,     6,    -1,    37,   179,   279,   185,   275,   180,   193,
     279,     6,    -1,     4,   279,   186,   196,   187,     6,    -1,
     110,     4,   181,   266,   182,     6,    -1,   111,     4,   181,
     266,   182,     6,    -1,   112,     4,   181,   266,   185,   266,
     182,     6,    -1,    -1,   196,   199,    -1,   196,   203,    -1,
     196,   206,    -1,   196,   208,    -1,   196,   209,    -1,   266,
      -1,   197,   185,   266,    -1,   266,    -1,   198,   185,   266,
      -1,    -1,    -1,     4,   200,   179,   197,   180,   201,   186,
     198,   187,     6,    -1,   279,    -1,   202,   185,   279,    -1,
      -1,   119,   179,   266,   185,   266,   185,   266,   180,   204,
     186,   202,   187,     6,    -1,   279,    -1,   205,   185,   279,
      -1,    -1,   120,   179,   266,   185,   266,   185,   266,   185,
     266,   180,   207,   186,   205,   187,     6,    -1,   121,   186,
     271,   187,   186,   271,   187,     6,    -1,   121,   186,   271,
     187,   186,   271,   187,   186,   271,   187,   186,   271,   187,
       6,    -1,    -1,   122,   210,   186,   198,   187,     6,    -1,
       7,    -1,   159,    -1,   158,    -1,   157,    -1,   156,    -1,
     177,    -1,   176,    -1,   179,    -1,   181,    -1,   180,    -1,
     182,    -1,    62,   181,   217,   182,     6,    -1,    63,   181,
     220,   182,     6,    -1,   284,   211,   272,     6,    -1,     4,
     181,   182,   211,   272,     6,    -1,   283,   181,   182,   211,
     272,     6,    -1,     4,   181,   266,   182,   211,   266,     6,
      -1,     4,   179,   266,   180,   211,   266,     6,    -1,   283,
     181,   266,   182,   211,   266,     6,    -1,     4,   213,   186,
     275,   187,   214,   211,   272,     6,    -1,   283,   213,   186,
     275,   187,   214,   211,   272,     6,    -1,   284,   212,     6,
      -1,     4,   181,   266,   182,   212,     6,    -1,   283,   181,
     266,   182,   212,     6,    -1,   284,     7,   280,     6,    -1,
       4,   183,     4,     7,   280,     6,    -1,     4,   181,   266,
     182,   183,     4,     7,   280,     6,    -1,     4,   183,     4,
     211,   266,     6,    -1,     4,   181,   266,   182,   183,     4,
     211,   266,     6,    -1,     4,   183,     4,   212,     6,    -1,
       4,   181,   266,   182,   183,     4,   212,     6,    -1,     4,
     183,   129,   183,     4,     7,   276,     6,    -1,     4,   181,
     266,   182,   183,   129,   183,     4,     7,   276,     6,    -1,
       4,   183,   130,     7,   277,     6,    -1,     4,   181,   266,
     182,   183,   130,     7,   277,     6,    -1,     4,   138,     7,
     266,     6,    -1,   138,   181,   266,   182,     7,     4,     6,
      -1,   138,   181,   266,   182,   183,     4,     7,   266,     6,
      -1,   138,   181,   266,   182,   183,     4,     7,   280,     6,
      -1,   138,   181,   266,   182,   183,     4,     7,   186,   275,
     187,     6,    -1,   138,   181,   266,   182,   183,     4,     6,
      -1,    90,   179,     4,   180,   183,     4,     7,   266,     6,
      -1,    90,   179,     4,   180,   183,     4,     7,   280,     6,
      -1,    -1,   185,    -1,    -1,   217,   216,   284,    -1,   217,
     216,   284,     7,   266,    -1,    -1,   217,   216,   284,     7,
     186,   266,   218,   222,   187,    -1,   217,   216,   284,     7,
     280,    -1,    -1,   217,   216,   284,     7,   186,   280,   219,
     224,   187,    -1,    -1,   220,   216,   279,    -1,   266,     7,
     280,    -1,   221,   185,   266,     7,   280,    -1,    -1,   222,
     223,    -1,   185,     4,   272,    -1,   185,     4,   186,   221,
     187,    -1,   185,     4,   280,    -1,    -1,   224,   225,    -1,
     185,     4,   266,    -1,   185,     4,   280,    -1,   185,     4,
     186,   282,   187,    -1,   266,    -1,   280,    -1,   266,    -1,
     280,    -1,   266,    -1,   280,    -1,   266,    -1,   280,    -1,
      -1,   132,    70,   186,   266,   187,    -1,    -1,    82,   269,
      -1,    66,   179,   266,   180,     7,   269,     6,    -1,    86,
      66,   179,   226,   180,     7,   272,     6,    -1,    75,    76,
     272,     7,   266,     6,    -1,    69,   179,   266,   180,     7,
     272,     6,    -1,    91,    69,   272,     6,    -1,    73,   179,
     266,   180,     7,   272,     6,    -1,    67,   179,   266,   180,
       7,   272,   231,     6,    -1,    68,   179,   266,   180,     7,
     272,   231,     6,    -1,   124,   179,   266,   180,     7,   272,
       6,    -1,   125,   179,   266,   180,     7,   272,     6,    -1,
     126,   179,   266,   180,     7,   272,   128,   272,   127,   266,
       6,    -1,    69,     4,   179,   266,   180,     7,   272,     6,
      -1,    87,    69,   179,   266,   180,     7,   272,     6,    -1,
      86,    69,   179,   227,   180,     7,   272,     6,    -1,    82,
      72,   179,   266,   180,     7,   272,     6,    -1,    83,    72,
     179,   266,   180,     7,   272,   230,     6,    -1,    12,    13,
       6,    -1,    13,    72,   266,     6,    -1,    77,    72,   179,
     266,   180,     7,     5,     5,     5,     6,    -1,    70,   179,
     266,   180,     7,   272,     6,    -1,    71,   179,   266,   180,
       7,   272,     6,    -1,    72,     4,   179,   266,   180,     7,
     272,     6,    -1,    87,    72,   179,   266,   180,     7,   272,
       6,    -1,    87,    72,   179,   266,   180,     7,   272,     4,
     186,   271,   187,     6,    -1,    86,    72,   179,   228,   180,
       7,   272,     6,    -1,    85,    74,   179,   266,   180,     7,
     272,     6,    -1,    74,   179,   266,   180,     7,   272,     6,
      -1,    87,    74,   179,   266,   180,     7,   272,     6,    -1,
      86,    74,   179,   229,   180,     7,   272,     6,    -1,    94,
     269,   186,   234,   187,    -1,    93,   186,   269,   185,   269,
     185,   266,   187,   186,   234,   187,    -1,    95,   269,   186,
     234,   187,    -1,    96,   186,   269,   185,   266,   187,   186,
     234,   187,    -1,    96,   186,   269,   185,   269,   187,   186,
     234,   187,    -1,     4,   186,   234,   187,    -1,   104,    69,
     186,   275,   187,    72,   186,   266,   187,    -1,   101,    69,
     179,   266,   180,   186,   275,   187,     6,    -1,   235,    -1,
     233,    -1,    -1,   235,   232,    -1,   235,    66,   186,   275,
     187,     6,    -1,   235,    69,   186,   275,   187,     6,    -1,
     235,    72,   186,   275,   187,     6,    -1,   235,    74,   186,
     275,   187,     6,    -1,    98,    82,   179,   266,   180,     7,
     272,     6,    -1,    98,    66,   179,   266,   180,     7,   186,
     271,   187,     6,    -1,    98,    82,   179,   266,   180,     7,
     186,   269,   185,   269,   185,   275,   187,     6,    -1,    98,
      82,   179,   266,   180,     7,   186,   269,   185,   269,   185,
     269,   185,   275,   187,     6,    -1,    98,    70,   179,   266,
     180,     7,   186,   269,   185,   275,   187,     6,    -1,    98,
       4,   179,   266,   180,     7,   272,     6,    -1,    98,     4,
     179,   266,   180,     7,     5,     6,    -1,    98,     4,   186,
     266,   187,     6,    -1,    98,     4,   179,   266,   180,     7,
     186,   269,   185,   269,   185,   275,   187,     6,    -1,   102,
     186,   235,   187,    -1,   102,   138,   181,   266,   182,     6,
      -1,   102,     4,   181,   266,   182,     6,    -1,   102,     4,
       6,    -1,   102,     4,     4,     6,    -1,   129,   276,   186,
     235,   187,    -1,    92,   129,   276,   186,   235,   187,    -1,
     142,     5,     6,    -1,   143,     5,     6,    -1,   142,   186,
     235,   187,    -1,    92,   142,   186,   235,   187,    -1,   143,
     186,   235,   187,    -1,    92,   143,   186,   235,   187,    -1,
       4,   280,     6,    -1,    55,   179,   282,   180,     6,    -1,
       4,     4,   181,   266,   182,   279,     6,    -1,     4,     4,
       4,   181,   266,   182,     6,    -1,     4,   266,     6,    -1,
      90,   179,     4,   180,   183,     4,     6,    -1,   123,     4,
       6,    -1,   136,     6,    -1,   137,     6,    -1,    53,     6,
      -1,    48,     6,    -1,    48,   186,   266,   185,   266,   185,
     266,   185,   266,   185,   266,   185,   266,   187,     6,    -1,
      49,     6,    -1,    50,     6,    -1,    59,     6,    -1,    60,
       6,    -1,    79,     6,    -1,    80,   186,   275,   187,   186,
     275,   187,   186,   271,   187,   186,   266,   185,   266,   187,
       6,    -1,   150,   266,     6,    -1,   131,   179,   266,     8,
     266,   180,    -1,   131,   179,   266,     8,   266,     8,   266,
     180,    -1,   131,     4,   132,   186,   266,     8,   266,   187,
      -1,   131,     4,   132,   186,   266,     8,   266,     8,   266,
     187,    -1,   133,    -1,   141,     4,    -1,   139,    -1,   140,
     284,     6,    -1,   134,   179,   266,   180,    -1,   135,    -1,
      97,   269,   186,   235,   187,    -1,    97,   186,   269,   185,
     269,   185,   266,   187,   186,   235,   187,    -1,    97,   186,
     269,   185,   269,   185,   269,   185,   266,   187,   186,   235,
     187,    -1,    -1,    97,   269,   186,   235,   243,   256,   187,
      -1,    -1,    97,   186,   269,   185,   269,   185,   266,   187,
     186,   235,   244,   256,   187,    -1,    -1,    97,   186,   269,
     185,   269,   185,   269,   185,   266,   187,   186,   235,   245,
     256,   187,    -1,    -1,    97,   186,   235,   246,   256,   187,
      -1,    97,    66,   186,   266,   185,   269,   187,     6,    -1,
      97,    69,   186,   266,   185,   269,   187,     6,    -1,    97,
      72,   186,   266,   185,   269,   187,     6,    -1,    97,    66,
     186,   266,   185,   269,   185,   269,   185,   266,   187,     6,
      -1,    97,    69,   186,   266,   185,   269,   185,   269,   185,
     266,   187,     6,    -1,    97,    72,   186,   266,   185,   269,
     185,   269,   185,   266,   187,     6,    -1,    97,    66,   186,
     266,   185,   269,   185,   269,   185,   269,   185,   266,   187,
       6,    -1,    97,    69,   186,   266,   185,   269,   185,   269,
     185,   269,   185,   266,   187,     6,    -1,    97,    72,   186,
     266,   185,   269,   185,   269,   185,   269,   185,   266,   187,
       6,    -1,    -1,    97,    66,   186,   266,   185,   269,   187,
     247,   186,   256,   187,     6,    -1,    -1,    97,    69,   186,
     266,   185,   269,   187,   248,   186,   256,   187,     6,    -1,
      -1,    97,    72,   186,   266,   185,   269,   187,   249,   186,
     256,   187,     6,    -1,    -1,    97,    66,   186,   266,   185,
     269,   185,   269,   185,   266,   187,   250,   186,   256,   187,
       6,    -1,    -1,    97,    69,   186,   266,   185,   269,   185,
     269,   185,   266,   187,   251,   186,   256,   187,     6,    -1,
      -1,    97,    72,   186,   266,   185,   269,   185,   269,   185,
     266,   187,   252,   186,   256,   187,     6,    -1,    -1,    97,
      66,   186,   266,   185,   269,   185,   269,   185,   269,   185,
     266,   187,   253,   186,   256,   187,     6,    -1,    -1,    97,
      69,   186,   266,   185,   269,   185,   269,   185,   269,   185,
     266,   187,   254,   186,   256,   187,     6,    -1,    -1,    97,
      72,   186,   266,   185,   269,   185,   269,   185,   269,   185,
     266,   187,   255,   186,   256,   187,     6,    -1,   257,    -1,
     256,   257,    -1,   107,   186,   266,   187,     6,    -1,   107,
     186,   272,   185,   272,   187,     6,    -1,   107,   186,   272,
     185,   272,   185,   272,   187,     6,    -1,   108,     6,    -1,
      99,     6,    -1,   115,     6,    -1,   115,   117,     6,    -1,
     116,     6,    -1,   116,   117,     6,    -1,   113,     6,    -1,
     113,   117,     6,    -1,   114,     6,    -1,   114,   117,     6,
      -1,   109,   179,   266,   180,     7,   272,    89,   266,     6,
      -1,    89,     4,   181,   266,   182,     6,    -1,    -1,    89,
       4,   266,    -1,    -1,     4,    -1,    -1,     7,   272,    -1,
      -1,     7,   266,    -1,    84,    69,   273,     7,   266,   258,
       6,    -1,    84,    72,   273,   260,   259,     6,    -1,    78,
      72,   186,   266,   187,     7,   272,     6,    -1,    84,    74,
     273,   260,     6,    -1,   118,   273,     6,    -1,   105,    72,
     186,   275,   187,   266,     6,    -1,    99,    72,   273,   261,
       6,    -1,    99,    74,   273,     6,    -1,   100,    72,   272,
       7,   266,     6,    -1,    88,    69,   272,     7,   272,     6,
      -1,    88,    72,   266,   186,   275,   187,     7,   266,   186,
     275,   187,     6,    -1,    66,   186,   275,   187,   132,    72,
     186,   266,   187,     6,    -1,    69,   186,   275,   187,   132,
      72,   186,   266,   187,     6,    -1,    66,   186,   275,   187,
     132,    74,   186,   266,   187,     6,    -1,    69,   186,   275,
     187,   132,    74,   186,   266,   187,     6,    -1,    72,   186,
     275,   187,   132,    74,   186,   266,   187,     6,    -1,   106,
      72,   273,     6,    -1,   106,    69,   273,     6,    -1,    81,
      66,   273,     6,    -1,    81,    69,   273,     6,    -1,    81,
      72,   273,     6,    -1,   103,     6,    -1,   103,     4,     6,
      -1,   103,    66,   186,   275,   187,     6,    -1,   147,    -1,
     148,    -1,   149,    -1,   264,     6,    -1,   264,   186,   272,
     187,     6,    -1,   264,   186,   272,   185,   272,   187,     6,
      -1,   264,   179,   272,   180,   186,   272,   185,   272,   187,
       6,    -1,   267,    -1,   179,   266,   180,    -1,   170,   266,
      -1,   169,   266,    -1,   174,   266,    -1,   266,   170,   266,
      -1,   266,   169,   266,    -1,   266,   171,   266,    -1,   266,
     172,   266,    -1,   266,   173,   266,    -1,   266,   178,   266,
      -1,   266,   165,   266,    -1,   266,   166,   266,    -1,   266,
     168,   266,    -1,   266,   167,   266,    -1,   266,   164,   266,
      -1,   266,   163,   266,    -1,   266,   162,   266,    -1,   266,
     161,   266,    -1,   266,   160,   266,     8,   266,    -1,    14,
     213,   266,   214,    -1,    15,   213,   266,   214,    -1,    16,
     213,   266,   214,    -1,    17,   213,   266,   214,    -1,    18,
     213,   266,   214,    -1,    19,   213,   266,   214,    -1,    20,
     213,   266,   214,    -1,    21,   213,   266,   214,    -1,    22,
     213,   266,   214,    -1,    24,   213,   266,   214,    -1,    25,
     213,   266,   185,   266,   214,    -1,    26,   213,   266,   214,
      -1,    27,   213,   266,   214,    -1,    28,   213,   266,   214,
      -1,    29,   213,   266,   214,    -1,    30,   213,   266,   214,
      -1,    31,   213,   266,   214,    -1,    32,   213,   266,   214,
      -1,    33,   213,   266,   185,   266,   214,    -1,    34,   213,
     266,   185,   266,   214,    -1,    35,   213,   266,   185,   266,
     214,    -1,    23,   213,   266,   214,    -1,     3,    -1,     9,
      -1,    10,    -1,    11,    -1,   153,    -1,   154,    -1,   155,
      -1,    56,    -1,    57,    -1,    58,    -1,    -1,    64,   213,
     266,   268,   222,   214,    -1,   284,    -1,     4,   181,   266,
     182,    -1,   283,   181,   266,   182,    -1,   151,   179,   284,
     180,    -1,   152,   179,   280,   180,    -1,   184,   284,   181,
     182,    -1,   284,   212,    -1,     4,   181,   266,   182,   212,
      -1,   283,   181,   266,   182,   212,    -1,     4,   183,     4,
      -1,     4,   181,   266,   182,   183,     4,    -1,     4,   183,
       4,   212,    -1,     4,   181,   266,   182,   183,     4,   212,
      -1,   144,   179,   279,   185,   266,   180,    -1,    45,   179,
     279,   185,   279,   180,    -1,    46,   179,   279,   185,   279,
     180,    -1,    47,   179,   282,   180,    -1,   270,    -1,   170,
     269,    -1,   169,   269,    -1,   269,   170,   269,    -1,   269,
     169,   269,    -1,   186,   266,   185,   266,   185,   266,   185,
     266,   185,   266,   187,    -1,   186,   266,   185,   266,   185,
     266,   185,   266,   187,    -1,   186,   266,   185,   266,   185,
     266,   187,    -1,   179,   266,   185,   266,   185,   266,   180,
      -1,   272,    -1,   271,   185,   272,    -1,   266,    -1,   274,
      -1,   186,   187,    -1,   186,   275,   187,    -1,   170,   186,
     275,   187,    -1,   266,   171,   186,   275,   187,    -1,   272,
      -1,     5,    -1,   170,   274,    -1,   266,   171,   274,    -1,
     266,     8,   266,    -1,   266,     8,   266,     8,   266,    -1,
      66,   186,   266,   187,    -1,    66,     5,    -1,    69,     5,
      -1,    72,     5,    -1,    74,     5,    -1,    86,    66,   186,
     275,   187,    -1,    86,    69,   186,   275,   187,    -1,    86,
      72,   186,   275,   187,    -1,    86,    74,   186,   275,   187,
      -1,    66,   132,    48,   186,   266,   185,   266,   185,   266,
     185,   266,   185,   266,   185,   266,   187,    -1,    69,   132,
      48,   186,   266,   185,   266,   185,   266,   185,   266,   185,
     266,   185,   266,   187,    -1,    72,   132,    48,   186,   266,
     185,   266,   185,   266,   185,   266,   185,   266,   185,   266,
     187,    -1,    74,   132,    48,   186,   266,   185,   266,   185,
     266,   185,   266,   185,   266,   185,   266,   187,    -1,   233,
      -1,   242,    -1,     4,   213,   214,    -1,   283,   213,   214,
      -1,    36,   181,   284,   182,    -1,     4,   213,   186,   275,
     187,   214,    -1,   283,   213,   186,   275,   187,   214,    -1,
     266,    -1,   274,    -1,   275,   185,   266,    -1,   275,   185,
     274,    -1,   186,   266,   185,   266,   185,   266,   185,   266,
     187,    -1,   186,   266,   185,   266,   185,   266,   187,    -1,
       4,    -1,     4,   183,   129,   183,     4,    -1,   186,   278,
     187,    -1,     4,   181,   266,   182,   183,   130,    -1,   276,
      -1,   278,   185,   276,    -1,   280,    -1,   284,    -1,     4,
     183,     4,    -1,     4,   181,   266,   182,   183,     4,    -1,
       5,    -1,    51,    -1,    54,    -1,   145,   179,   279,   180,
      -1,   146,   179,   279,   185,   279,   180,    -1,    41,   213,
     282,   214,    -1,    42,   179,   279,   180,    -1,    43,   179,
     279,   180,    -1,    44,   179,   279,   185,   279,   185,   279,
     180,    -1,    39,   213,   282,   214,    -1,    40,   213,   279,
     214,    -1,    40,   213,   279,   185,   275,   214,    -1,    52,
     179,   279,   180,    -1,    -1,    65,   213,   280,   281,   224,
     214,    -1,   279,    -1,   282,   185,   279,    -1,     4,   188,
     186,   266,   187,    -1,   283,   188,   186,   266,   187,    -1,
       4,    -1,   283,    -1
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
    3499,  3502,  3519,  3522,  3528,  3531,  3538,  3594,  3664,  3669,
    3736,  3772,  3780,  3823,  3862,  3882,  3909,  3949,  3977,  4005,
    4009,  4013,  4041,  4080,  4119,  4140,  4161,  4188,  4192,  4202,
    4237,  4238,  4239,  4243,  4249,  4261,  4279,  4307,  4308,  4309,
    4310,  4311,  4312,  4313,  4314,  4315,  4322,  4323,  4324,  4325,
    4326,  4327,  4328,  4329,  4330,  4331,  4332,  4333,  4334,  4335,
    4336,  4337,  4338,  4339,  4340,  4341,  4342,  4343,  4344,  4345,
    4346,  4347,  4348,  4349,  4350,  4351,  4352,  4353,  4354,  4363,
    4364,  4365,  4366,  4367,  4368,  4369,  4370,  4371,  4372,  4377,
    4376,  4384,  4401,  4419,  4437,  4442,  4448,  4460,  4477,  4495,
    4516,  4521,  4526,  4536,  4546,  4551,  4560,  4565,  4592,  4596,
    4600,  4604,  4608,  4615,  4619,  4623,  4627,  4634,  4639,  4646,
    4651,  4655,  4660,  4664,  4672,  4683,  4687,  4699,  4707,  4715,
    4722,  4732,  4761,  4765,  4769,  4773,  4777,  4806,  4835,  4864,
    4893,  4906,  4919,  4932,  4945,  4955,  4965,  4977,  4989,  5001,
    5019,  5040,  5045,  5049,  5053,  5065,  5069,  5081,  5088,  5098,
    5102,  5117,  5122,  5129,  5133,  5146,  5154,  5165,  5169,  5177,
    5183,  5191,  5199,  5214,  5228,  5242,  5254,  5270,  5274,  5293,
    5301,  5300,  5313,  5318,  5324,  5333,  5346,  5349
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
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "$@21", "VExpr", "VExpr_Single",
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
     259,   259,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   263,   263,
     264,   264,   264,   265,   265,   265,   265,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   268,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   269,   269,
     269,   269,   269,   270,   270,   270,   270,   271,   271,   272,
     272,   272,   272,   272,   272,   273,   273,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   275,   275,   275,   275,   276,   276,   276,   276,   277,
     277,   278,   278,   279,   279,   279,   279,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     281,   280,   282,   282,   283,   283,   284,   284
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
       0,     1,     0,     2,     0,     2,     7,     6,     8,     5,
       3,     7,     5,     4,     6,     6,    12,    10,    10,    10,
      10,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     1,     4,     4,     4,     4,     4,     2,     5,     5,
       3,     6,     4,     7,     6,     6,     6,     4,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     5,     5,     5,     5,
      16,    16,    16,    16,     1,     1,     3,     3,     4,     6,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     3,     6,     1,     1,     1,
       4,     6,     4,     4,     4,     8,     4,     4,     6,     4,
       0,     6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   232,     0,     0,     0,   229,     0,     0,     0,     0,
     320,   321,   322,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   477,     0,   369,   476,   457,   370,   371,   372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,     0,   459,   376,   377,   378,     0,     0,     0,     0,
       0,     0,     0,     0,   373,   374,   375,     0,     0,     0,
      65,    66,     0,     0,   176,     0,     0,     0,   327,     0,
     453,   477,   381,     0,     0,     0,     0,   214,     0,   216,
     217,   213,     0,   218,   219,   103,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,   317,     0,     0,     0,     0,     0,
       0,     0,     0,   476,   416,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,   435,   409,   415,     0,   410,
     477,   381,     0,     0,     0,     0,   447,     0,     0,     0,
       0,     0,   211,   212,     0,   476,   477,     0,   228,     0,
     176,     0,   176,   476,     0,   323,     0,     0,    65,    66,
       0,     0,    58,    62,    61,    60,    59,    64,    63,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   330,   329,   331,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,   174,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,   204,     0,
     387,   153,     0,   476,     0,   453,   454,     0,     0,   472,
       0,   101,   101,     0,     0,   441,   442,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   176,     0,   400,   399,     0,
       0,     0,     0,   176,   176,     0,     0,     0,     0,     0,
       0,     0,   242,     0,   176,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,   194,     0,     0,     0,   318,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,   422,     0,     0,   423,     0,   424,     0,   425,
       0,     0,     0,     0,     0,     0,   329,   417,     0,   411,
       0,     0,     0,   300,    66,     0,   210,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,   230,   198,     0,
     199,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,   470,
       0,     0,     0,     0,     0,     0,   328,    58,     0,     0,
      58,     0,     0,     0,     0,     0,   171,     0,     0,     0,
       0,   177,     0,     0,     0,   345,   344,   343,   342,   338,
     339,   341,   340,   333,   332,   334,   335,   336,   337,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,   315,   316,     0,     0,
       0,     0,   290,     0,     0,     0,   125,   126,     0,   127,
     128,     0,   129,   130,     0,   131,   132,     0,     0,     0,
       0,     0,     0,   141,   176,     0,     0,     0,     0,     0,
     402,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,     0,     0,     0,     0,   303,
       0,     0,   195,     0,     0,   191,     0,     0,     0,   313,
     312,     0,     0,     0,     0,   390,    67,    68,     0,   436,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,   412,   419,     0,   334,   418,     0,   437,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,   200,
     202,     0,     0,     0,     0,     0,     0,     0,    82,    71,
       0,   382,   392,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   368,   356,     0,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,   466,     0,   467,   462,   463,
     464,     0,     0,     0,   397,   469,   115,   120,    93,     0,
     460,     0,   384,   385,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,   386,     0,     0,     0,
       0,   474,     0,     0,    43,     0,     0,     0,    56,     0,
      34,    35,    36,    37,    38,   383,     0,   455,    23,    21,
       0,     0,    24,     0,     0,   205,   473,    69,   104,    70,
     112,     0,   443,   444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   288,   293,   291,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     203,     0,     0,     0,   166,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,   233,     0,     0,     0,     0,     0,     0,
     295,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   382,     0,   438,     0,   421,     0,     0,     0,
       0,     0,     0,     0,   413,     0,     0,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,     0,
     324,     0,     0,     0,   475,     0,     0,     0,   388,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,    80,    83,
      85,     0,     0,   451,     0,    91,     0,     0,     0,     0,
       0,   346,     0,     0,     0,     0,     0,    29,   389,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,     0,     0,   305,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,   276,     0,   282,     0,   284,     0,   278,
       0,   280,     0,   243,   272,     0,     0,     0,   189,     0,
       0,     0,   304,     0,   193,   192,   319,     0,     0,    30,
      31,     0,     0,     0,     0,     0,     0,     0,   426,   427,
     428,   429,   420,   414,     0,     0,     0,     0,   448,     0,
       0,     0,   223,     0,     0,     0,     0,    73,     0,    81,
       0,   207,   391,   206,   357,   365,   366,   367,   468,     0,
     395,   396,     0,   380,   116,     0,   471,   121,   394,   461,
      75,    58,     0,     0,     0,     0,    74,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     407,     0,     0,    25,    26,     0,    27,     0,     0,   105,
     108,   137,     0,     0,     0,     0,     0,     0,   140,     0,
       0,   156,   157,     0,     0,   142,   163,     0,     0,     0,
       0,   133,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,   176,   176,
       0,   253,     0,   255,     0,   257,     0,   409,     0,     0,
     283,   285,   279,   281,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   301,     0,   391,   439,
       0,     0,     0,     0,   440,   145,   146,     0,     0,     0,
       0,    94,    98,     0,     0,   325,    76,     0,   393,     0,
       0,     0,     0,     0,    88,     0,     0,    89,     0,   452,
     178,   179,   180,   181,     0,     0,    39,     0,     0,     0,
       0,     0,    41,   456,     0,     0,   106,   109,     0,     0,
     136,   143,   144,   148,     0,     0,   158,     0,     0,   298,
       0,   151,     0,     0,   289,   162,   138,   150,   161,   165,
     149,     0,   159,   164,     0,     0,     0,     0,   406,     0,
     405,     0,     0,     0,   244,     0,     0,   245,     0,     0,
     246,     0,     0,     0,     0,     0,     0,     0,   188,     0,
       0,   187,     0,     0,     0,   182,     0,     0,    32,     0,
       0,     0,     0,     0,     0,   446,     0,   225,   224,     0,
       0,     0,     0,     0,   465,     0,   117,   119,     0,   122,
     123,    84,    86,     0,    92,     0,    77,    44,     0,     0,
       0,   408,     0,     0,     0,    28,     0,   115,   120,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
      99,   100,   176,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,   273,     0,     0,   176,     0,     0,     0,
       0,     0,   173,   172,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,    78,     0,   441,     0,     0,
     450,     0,    40,     0,     0,     0,    42,    57,     0,     0,
       0,   307,   309,   308,   310,   311,   155,     0,     0,     0,
       0,     0,     0,   404,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,   238,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,   445,   226,
       0,   326,     0,   118,     0,   124,    90,     0,     0,     0,
       0,     0,   107,   110,     0,     0,     0,     0,   167,     0,
     259,     0,     0,   261,     0,     0,   263,     0,     0,     0,
     274,     0,   234,     0,   176,     0,     0,     0,     0,     0,
       0,     0,   147,    97,     0,   113,     0,    48,     0,    54,
       0,     0,     0,   134,   160,   306,   403,   247,     0,     0,
     254,   248,     0,     0,   256,   249,     0,     0,   258,     0,
       0,     0,   240,     0,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,   267,     0,   269,   275,   286,   239,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   114,    45,     0,    52,
       0,     0,     0,     0,   250,     0,     0,   251,     0,     0,
     252,     0,     0,   190,     0,   184,     0,     0,     0,     0,
       0,    46,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   260,     0,   262,     0,   264,     0,   185,
       0,     0,     0,     0,    47,    49,     0,    50,     0,     0,
       0,     0,   430,   431,   432,   433,     0,     0,    55,   266,
     268,   270,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   860,    85,    86,   629,  1295,  1301,
     850,  1022,  1461,  1640,   851,  1593,  1676,   852,  1642,   853,
     854,  1026,   319,   400,   166,   739,    87,   643,   411,  1407,
    1408,   412,  1456,   998,  1154,   999,  1157,   675,   678,   681,
     684,  1323,  1195,   611,   274,   377,   378,    90,    91,    92,
      93,    94,    95,   275,   934,  1543,  1608,   709,  1345,  1348,
    1351,  1568,  1572,  1576,  1625,  1628,  1631,   930,   931,  1058,
     895,   672,   718,    97,    98,    99,   100,   276,   168,   816,
     458,   234,  1179,   277,   278,   279,   520,   288,   835,  1014,
     409,   405,   817,   410,   171,   281
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1232
static const yytype_int16 yypact[] =
{
    5725,    71,   128,  5840, -1232, -1232,  2320,   146,   -45,   -29,
     -14,    46,   168,   174,   217,    62,   251,   257,    92,   115,
      -9,   129,   152,    27,   175,   196,    38,   231,   252,   245,
     358,   370,   471,   299,     2,   431,   443,   256,   465,   335,
     500,   422,   372,   483,   271,   378,   -65,   -65,   389,   192,
      18,   385,   486,   558,    28,    51,   561,   564,   545,   639,
     646,   657,  3714,   681,   485,   514,   520,    39,    -1, -1232,
     527, -1232,   697,   722,   566, -1232,   729,   749,    34,    45,
   -1232, -1232, -1232,  5602, -1232, -1232, -1232, -1232, -1232, -1232,
   -1232, -1232, -1232, -1232, -1232, -1232, -1232, -1232, -1232,    60,
   -1232,   382,   118, -1232,     1, -1232, -1232, -1232, -1232,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   569,   577,   582,   588,   594,   597,
   -1232,   610, -1232, -1232, -1232, -1232,   -69,   -69,   753,   633,
     640,   675,   676,   679, -1232, -1232, -1232,  5602,  5602,  5602,
    5602,  2001,    32,   729,   377,   653,   663,   660, -1232,   683,
     857,    98,    83,   864,  5602,   884,   884, -1232,  5602, -1232,
   -1232, -1232,   884, -1232, -1232, -1232, -1232,  5602,  5258,  5602,
    5602,   700,  5602,  5258,  5602,  5602,   701,  5258,  5602,  5602,
    4070,   708,   716, -1232,  5258,  3714,  3714,  3714,   738,   751,
    3714,  3714,  3714,   754,   758,   765,   772,   773,   811,   812,
     847,  4070,  5602,   887,  4070,    39,   748,   841,   -65,   -65,
     -65,  5602,  5602,   -63, -1232,   -50,   -65,   845,   851,   855,
     978,   -32,   106,   853,   854,   866,  3714,  3714,  4070,   867,
      14,   862, -1232,  1042, -1232,   863,   865,   868,  3714,  3714,
     874,   875,   885,   -85, -1232,   888,    19,    20,    21,    25,
     557,  4248,  5602,  3331, -1232, -1232,  3360, -1232,  1059, -1232,
     415,   -35,  1062,  5602,  5602,  5602,   897,  5602,   895,   938,
    5602,  5602, -1232, -1232,  5602,   894,   896,  1077, -1232,  1081,
   -1232,  1083, -1232,  -123,  1240, -1232,  4070,  4070, -1232,  5360,
     904,   906,  1034, -1232, -1232, -1232, -1232, -1232, -1232,  4070,
    1087,   915,  5602,  1093, -1232,  5602,  5602,  5602,  5602,  5602,
    5602,  5602,  5602,  5602,  5602,  5602,  5602,  5602,  5602,  5602,
    5602,  5602,  5602,  5602,  5602,  5602,  5602,   884,   884,   884,
     884,   884,   884,   884,   884,   884,   884,  5602,  1034,  5602,
     884,   884,   884,   729,  1034,   923,   923,   923,  8233,   132,
    7888,   142,   919,  1107,   942,   963, -1232,   937,  5119,  5602,
    5258, -1232,  5602,  5602,  5602,  5602,  5602,  5602,  5602,  5602,
    5602,  5602,  5602,  5602,  5602,  5602,  5602, -1232, -1232,  5602,
   -1232, -1232,  1408,   277,    11, -1232, -1232,    57,  6695, -1232,
     117,   -99,   158,  8254,  5258,  3481, -1232,   434,  8275,  8296,
    5602,  8317,   448,  8338,  8359,  5602,   454,  8380,  8401,  1121,
    5602,  5602,   464,  1145,  1147,  1148,  5602,  5602,  1149,  1151,
    1151,  5602,  5430,  5430,  5430,  5430,  5602,  5602,  5602,  1152,
    6615,   975,  1154,   977, -1232, -1232,   -54, -1232, -1232,  6721,
    6747,   -65,   -65,   377,   377,    97,  5602,  5602,  5602,   978,
     978,  5602,  5119,   137, -1232,  5602,  5602,  5602,  5602,  5602,
    1158,  1155,  1160,  5602,  1162, -1232,  5602,  5602,  1255, -1232,
    5258,  5258,  5258,  1163,  1165,  5602,  5602,  5602,  5602,  1169,
     -56,   729, -1232,  1126,  5602, -1232,  1127, -1232,  1128, -1232,
    1129,   995,   997,   999,  1000,  5258,   923, -1232,  8422, -1232,
     482,  5602,  4426, -1232,  5602,   300, -1232,  8443,  8464,  8485,
    1058,  6773, -1232,  1002,  3500,  8506,  7911, -1232, -1232,  1674,
   -1232,  1780,  5602, -1232,  1009,   496,   132,  7934,  5602,  5258,
    1185,  1186, -1232,  5602,  7957,   190,  7865,  7865,  7865,  7865,
    7865,  7865,  7865,  7865,  7865,  7865,  7865,  6799,  7865,  7865,
    7865,  7865,  7865,  7865,  7865,  6825,  6851,  6877,   336,   428,
     336,  1015,  1016,  1014,  1017,  1018,   214,  1021,  8947, -1232,
    1644,  1020,  1026,  1027,  1031,  1033,   132, -1232,  4070,    95,
    1034,  5602,  1212,  1215,    41,  1040, -1232,   311,    40,    44,
     334, -1232,  4872,   505,  4371,   972,   791,  1141,  1141,   429,
     429,   429,   429,   201,   201,   923,   923,   923,   923,    13,
    7980, -1232,  5602,  1219,    15,  5258,  1218,  5258,  5602,  1220,
     884,  1221, -1232,   729,  1222,   884,  1224,  5258,  5258,  1103,
    1226,  1229,  8527,  1230,  1110,  1232,  1236,  8548,  1112,  1243,
    1247,  5602,  8569,  5507,  1039, -1232, -1232, -1232,  8590,  8611,
    5602,  4070,  1249,  1250,  8632,  1075,  8947, -1232,  1078,  8947,
   -1232,  1080,  8947, -1232,  1082,  8947, -1232,  8653,  8674,  8695,
    4070,  5258,  1086, -1232, -1232,  2485,  2707,   -65,  5602,  5602,
   -1232, -1232,  1074,  1076,   978,  6903,  6929,  6955,  6669,   606,
     -65,  3156,  8716,  5535,  8737,  8758,  8779,  5602,  1259, -1232,
    5602,  8800, -1232,  8003,  8026, -1232,   515,   524,   531, -1232,
   -1232,  8049,  8072,  6981,  8095,   -35, -1232, -1232,  5258, -1232,
    1084,  1089,  5831,  1090,  1094,  1095,  5258,  5258,  5258,  5258,
     538, -1232, -1232,  4390,  5258,   923, -1232,  5258, -1232,  1263,
    1265,  1266,  1096,  5602,  3753,  5602,  5602, -1232,    55, -1232,
   -1232,  1097,  4070,  1276,  4070,   156,  5859,   542, -1232, -1232,
    8118,   104, -1232, -1232, -1232, -1232, -1232, -1232, -1232, -1232,
   -1232, -1232, -1232, -1232,  5602, -1232, -1232, -1232, -1232, -1232,
   -1232, -1232,  5602,  5602,  5602, -1232,  5258, -1232, -1232, -1232,
   -1232,   884,   884,   884, -1232, -1232, -1232, -1232, -1232,  5602,
   -1232,   884, -1232, -1232,  5602,  1278,    63,  5602,  1281,  1283,
    1812, -1232,  1284,  1109,    39,  1286, -1232,  5258,  5258,  5258,
    5258, -1232,   552,  5602, -1232,  1114,  1115,  1111, -1232,  1289,
   -1232, -1232, -1232, -1232, -1232,   -35,  8141, -1232, -1232,  1132,
     884,   329, -1232,   365,  7007, -1232, -1232, -1232,  1293, -1232,
   -1232,   -65,  3481, -1232,   665,  4070,  4070,  1294,  4070,   666,
    4070,  4070,  1295,  1241,  4070,  4070,  1955,  1296,  1309,  5258,
    1311,  1313,  2768, -1232, -1232,  1325, -1232,  1326,  1327,  1329,
    1332,  1336,  1340,  1341,  1342,  1344,   572,  1348,  3931, -1232,
   -1232,   154,  7033,  7059, -1232, -1232,  5887,   -88,   -65,   -65,
     -65,  1353,  1352,  1177,  1361,  1190,    23,    47,    58,    66,
     330, -1232,   157, -1232,   606,  1363,  1365,  1366,  1367,  1368,
    8947, -1232,  2055,  1191,  1377,  1378,  1384,  1300,  5602,  1385,
    1390,  5602,  -143,   581, -1232,  5602, -1232,  5602,  5602,  5602,
     585,   592,   595,   596, -1232,  5602,   599,   600,  4070,  4070,
    4070,  1393,  7085, -1232,  4632,  1291,  1394,  1413,  4070,  1233,
   -1232,  1415,  5602,  1416, -1232,   552,  1418,  1421, -1232,  1425,
    7865,  7865,  7865,  7865,   480,  1234,  1256,  1260,   509,   516,
    8821,  1264,  2144, -1232,   179,  1244,  1428,  2250, -1232, -1232,
   -1232,    39,  5602, -1232,   611, -1232,   612,   615,   620,   626,
     132,  8947,  1267,  5602,  5602,  4070,  1253, -1232, -1232,  1262,
   -1232,  1437,    22,  1441,  5602,  4604,    -2,  1282,  1287,  1392,
    1392,  4070,  1442,  1290,  1292,  1443,  1459,  4070,  1297,  1461,
    1469, -1232,  1472,  4070,   630,  4070,  4070,  1475,  1474, -1232,
    4070,  4070,  4070,  4070,  4070,  4070,  4070,  4070, -1232,  1478,
     670, -1232,  5602,  5602,  5602,  1301,  1302,  -100,   -94,   -90,
    1305, -1232,  4070, -1232,  5602, -1232,  1476, -1232,  1483, -1232,
    1484, -1232,  1511, -1232, -1232,   978,   539,  3892, -1232,  1334,
    1335,  4667, -1232,  5258, -1232, -1232, -1232,  1337,  2269, -1232,
   -1232,  8164,  1477,   552,  7111,  7137,  7163,  7189, -1232, -1232,
   -1232, -1232,  8947, -1232,   552,  1512,  1516,  1396, -1232,  5602,
    5602,  5602, -1232,  1519,   735,  1343,  1520, -1232,  2644, -1232,
     132, -1232,   361, -1232, -1232, -1232, -1232, -1232, -1232,   884,
   -1232, -1232,  1527, -1232, -1232,  1529, -1232, -1232, -1232, -1232,
   -1232,  1034,  5602,  1528,  1532,    41, -1232,  1537,  8187,    39,
   -1232,  1544,  1545,  1546,  1547,  4070,  5602,  7215,  7241,   658,
   -1232,  5602,  1550, -1232, -1232,   884, -1232,  7267,  5430,  8947,
   -1232, -1232,  5602,  5602,   -65,  1549,  1552,  1553, -1232,  5602,
    5602, -1232, -1232,  1554,  5602, -1232, -1232,  1551,  1555,  1376,
    1557,  1432,  5602, -1232,  1559,  1560,  1561,  1576,  1577,  1578,
     846,  1579,  5602, -1232,  5430,  5915,  8842,  2566,   377,   377,
     -65,  1581,   -65,  1582,   -65,  1583,  5602,   362,  1405,  8863,
   -1232, -1232, -1232, -1232,  5943,   195, -1232,  1585,  3115,  1586,
    4070,   -65,  3115,  1587,   677,  5602, -1232,  1588,   -35, -1232,
    5602,  5602,  5602,  5602, -1232, -1232, -1232,  4070,  4808,   419,
    8884, -1232, -1232,  4845,  4070, -1232, -1232,  4070, -1232,  1417,
    3536,  4902,  1589,  2850, -1232,  1591,  1593, -1232,  1423, -1232,
   -1232, -1232, -1232, -1232,  1594,   424,  8947,  5602,  5602,  4070,
    1422,   689,  8947, -1232,  1603,  5602,  8947, -1232,  5971,  5999,
     114, -1232, -1232, -1232,  6027,  6055, -1232,  6083,  1605, -1232,
    4070, -1232,  1542,  1607,  8947, -1232, -1232, -1232, -1232, -1232,
   -1232,  1430, -1232, -1232,  6642,  2942,  1608,  1431, -1232,  5602,
   -1232,  1424,  1433,   223, -1232,  1435,   233, -1232,  1438,   236,
   -1232,  1439,  8210,  1613,  4070,  1616,  1440,  5602, -1232,  5080,
     266, -1232,   705,   283,   294, -1232,  1621,  6111, -1232,  7293,
    7319,  7345,  7371,  1501,  5602, -1232,  5602, -1232, -1232,  5258,
    3146,  1623,  1448,  1624, -1232,  3331, -1232, -1232,   884,  8947,
   -1232, -1232, -1232,    39, -1232,  1514, -1232, -1232,  5602,  7397,
    7423, -1232,  4070,  5602,  1639, -1232,  7449, -1232, -1232,  1641,
    1643,  1645,  1646,  1650,  1652,   709,  1473, -1232,  4070,  5258,
   -1232, -1232,   377,  5385, -1232, -1232,   978,   606,   978,   606,
     978,   606,  1655, -1232,   712,  4070, -1232,  6139,   -65,  1656,
    5258,   -65, -1232, -1232,  5602,  5602,  5602,  5602,  5602,  6167,
    6195,   713, -1232, -1232,  1659, -1232,   744,  1541,   755,  1661,
   -1232,  1482,  8947,  5602,  5602,   756,  8947, -1232,  5602,   760,
     763, -1232, -1232, -1232, -1232, -1232, -1232,  1491,  5602,   785,
     786,  1495,  5602, -1232,  6223,   314,   752,  6251,   323,  1101,
    6279,   326,  1246, -1232,  4070,  1663,  1596,  4109,  1502,   374,
   -1232,   789,   386,  7475,  7501,  7527,  7553,  3280, -1232, -1232,
    1664, -1232,  5602, -1232,  1034, -1232, -1232,  5602,  8905,  7579,
      48,  7605, -1232, -1232,  5602,  6307,  1683,  1685, -1232,  6335,
    1686,  5602,  1688,  1690,  5602,  1691,  1692,  5602,  1693,  1513,
   -1232,  5602, -1232,   606, -1232,  5258,  1712,  5080,  5602,  5602,
    5602,  5602, -1232, -1232,   743, -1232,   792, -1232,  5602, -1232,
    4070,  5602,  7631, -1232, -1232, -1232, -1232, -1232,  1534,  6363,
   -1232, -1232,  1536,  6391, -1232, -1232,  1538,  6419, -1232,  1717,
    3299,  1279,  4287,   793, -1232,   408,   798,  7657,  7683,  7709,
    7735,  1034,  1719,  1540,  8926,   799,  6447,  5602,   606,  1727,
     606,  1730,   606,  1731, -1232, -1232, -1232, -1232,   606,  1733,
    5258,  1744,  5602,  5602,  5602,  5602, -1232, -1232,   884, -1232,
    1568,  1749,  6475,  1565, -1232,  1609,  1981, -1232,  1610,  1994,
   -1232,  1611,  2145, -1232,   829, -1232,  7761,  7787,  7813,  7839,
     830, -1232,  1633,  4070, -1232,  1756,  1757,   606,  1758,   606,
    1761,   606, -1232,  1762,  5602,  5602,  5602,  5602,   884,  1785,
     884,   833, -1232, -1232,  2406, -1232,  2488, -1232,  2570, -1232,
    6503,  6531,  6559,  6587, -1232, -1232,   834, -1232,  1788,  1796,
    1814,  1815, -1232, -1232, -1232, -1232,   884,  1819, -1232, -1232,
   -1232, -1232, -1232, -1232
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1232, -1232, -1232, -1232,   809, -1232, -1232, -1232, -1232,   325,
   -1232, -1232, -1232, -1232, -1232, -1232, -1232, -1232, -1232, -1232,
   -1232, -1232,  -334,   -51,  1383,   547, -1232,  1447, -1232, -1232,
   -1232, -1232, -1232,   437, -1232,   452, -1232, -1232, -1232, -1232,
   -1232, -1232,   805,  1853,    12,  -454,  -239, -1232, -1232, -1232,
   -1232, -1232, -1232,  1865, -1232, -1232, -1232, -1232, -1232, -1232,
   -1232, -1232, -1232, -1232, -1232, -1232, -1232,  -807,  -874, -1232,
   -1232,  1436, -1232, -1232, -1232, -1232, -1232,  1444, -1232, -1232,
       0, -1232, -1231,  1984,   295,  -181,   -75,  -223,   707, -1232,
      72,     5, -1232,  -341,    -3,    35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -457
static const yytype_int16 yytable[] =
{
     101,   472,   453,   289,  1191,   321,   578,   416,   580,   702,
     703,   170,   416,   488,   586,    89,   416,   844,   484,  1362,
     485,   858,   242,   416,   502,   505,   507,   174,  1184,  1085,
     509,   191,   250,   317,   318,   598,   371,   601,   102,   299,
    1112,   172,   196,   286,   191,   833,   233,   235,   196,   241,
     301,   320,   177,  1087,  1559,   253,  1094,   254,   542,   280,
     499,   539,   976,   541,  1089,   165,   305,  1004,   205,   461,
     462,   206,  1091,   296,   207,   461,   462,     4,   169,   461,
     462,   461,   462,   641,   243,  1230,   642,  1231,   244,  1415,
     517,  1232,   416,  1233,   308,  1234,   498,  1235,   499,  1076,
     245,   164,   597,   165,   229,   230,   461,   462,   403,   105,
     308,   297,   324,   417,   231,   461,   462,   255,   422,   461,
     462,   232,   426,   463,   736,   312,   737,  1096,     5,   432,
     738,   697,   845,   846,   847,   848,   464,   461,   462,   597,
    1086,   317,   318,   131,   132,   133,   134,   135,   136,   600,
     175,   503,   506,   508,   474,   140,   141,   510,   142,   173,
     296,   372,   373,   597,  1088,   176,   251,   461,   462,   147,
     187,  1465,   296,   296,   179,  1090,   376,   188,   290,   296,
     180,   859,   322,  1092,   323,   280,  1161,  1479,   859,   165,
     280,   634,  1005,  1006,   280,   486,   635,   280,   374,   416,
     849,   280,   280,   280,   280,   504,   192,   280,   280,   280,
     406,   406,   774,   193,   252,   695,   696,   406,   280,   192,
     300,   280,  1094,   181,   197,   287,   838,   834,   456,   457,
     839,   302,   178,   517,  1560,   711,   465,   636,   977,   306,
     473,   182,   637,   280,   280,   280,   307,   404,   407,   150,
     151,   313,   314,   315,   316,   280,   280,   183,   237,   317,
     318,   238,   824,   184,   239,   827,   461,   462,   280,  -454,
     280,   317,   318,   185,   313,   314,   315,   316,   826,   399,
     317,   318,   704,   461,   462,   475,   310,   987,   313,   314,
     315,   316,   476,   764,   317,   318,   186,   639,   313,   314,
     315,   316,   640,   280,   280,   613,   461,   462,   189,   416,
     416,   416,   313,   314,   315,   316,   280,   550,   317,   318,
     602,   200,   710,   461,   462,   210,   461,   462,   211,  1595,
     212,   190,   317,   318,   416,   313,   314,   315,   316,  1072,
     644,   756,  1095,   642,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   194,   317,   318,   296,   296,   296,
     296,   229,   230,   589,   461,   462,   317,   318,   416,   595,
     521,   231,   393,   394,   395,   195,  -455,   280,   240,   396,
    1357,   375,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   461,   462,   814,   406,   406,   406,   594,   640,
     225,   214,   461,   462,   215,   461,   462,   216,  1426,   217,
     198,   280,  1661,   226,   227,   726,   727,   728,  1428,   921,
     579,  1430,   581,   582,   583,   584,   585,  1376,   587,   922,
     201,   199,   591,   592,   593,   461,   462,   923,   924,   925,
     750,   982,   202,   926,   927,   928,   929,   677,   680,   683,
     686,  1438,   461,   462,   416,   908,   416,   246,   632,   247,
     633,   700,   701,   461,   462,   165,   756,   873,  1440,   457,
      45,    46,    47,    48,   777,   376,   376,   203,    53,  1441,
     736,    56,   737,   461,   462,   204,   757,   280,   280,   280,
     187,   221,   461,   462,   222,   461,   462,   837,   296,  1531,
     433,   434,   435,   208,   782,   438,   439,   440,  1534,  1032,
     416,  1537,   280,   199,   648,   209,   736,  1093,   737,   280,
     840,   640,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   522,   394,   395,   740,   317,   318,   213,
     396,   480,   481,   461,   462,  1033,   280,  -456,   828,  1353,
     648,   223,   224,   493,   494,   461,   462,   416,   248,  1545,
     861,   308,   863,   309,   228,   416,   416,   416,   416,   218,
     310,  1547,   219,   416,   220,   236,   416,   461,   462,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,  1610,   308,   280,   524,   396,   391,   392,
     393,   394,   395,   310,  1397,   829,  1377,   396,   736,  1398,
     737,  1013,  1094,   806,   258,  1094,   906,   259,  1094,   648,
    1486,   649,  1489,   511,  1492,   416,   512,   249,   921,   513,
     256,   514,   280,   648,   280,   654,   257,   296,   922,   648,
     296,   658,   296,   260,   280,   280,   923,   924,   925,   648,
     261,   664,   926,   927,   928,   929,   416,   416,   416,   416,
     736,   262,   737,   953,   283,   648,   381,   648,   280,   752,
    1162,   960,   961,   962,   963,   406,  1223,  1224,   868,   966,
     406,   772,   967,   773,   782,   282,  1175,   280,   280,   736,
     648,   737,   842,   284,  1152,   921,   736,   911,   737,   285,
     648,  1155,   946,   292,   917,   922,   291,  1094,   416,   648,
     932,   947,   866,   923,   924,   925,   648,   870,   948,   926,
     927,   928,   929,   648,   983,   964,  1246,   648,   293,   985,
     988,   994,   736,   295,   737,   280,  1581,  1037,  1043,  1038,
    1044,  1272,  1273,   280,   280,   280,   280,   294,   350,  1094,
    1591,   280,  1094,   298,   280,  1094,   351,   648,  1094,  1069,
     359,   352,  1016,  1017,  1018,  1019,   648,   353,  1113,   280,
     648,   280,  1118,   354,  1341,  1342,   355,   648,   296,  1119,
     648,   648,  1120,  1121,   648,   648,  1123,  1124,  1167,   356,
    1094,  1623,  1094,  1626,  1094,  1629,  1169,   648,  1170,  1171,
     648,  1632,  1172,   280,  1028,   648,  1277,  1173,   296,   296,
     296,   648,   360,  1174,  1054,   648,   406,  1209,   296,   361,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   280,   280,   280,   280,   396,   379,
    1664,   921,  1666,  1299,  1668,  1300,   406,   406,   406,   380,
    1331,   922,  1332,   989,   362,   363,   406,   296,   364,   923,
     924,   925,   648,   398,  1366,   926,   927,   928,   929,   397,
     401,  1036,   280,   280,  1403,   280,  1404,   280,   280,   420,
     425,   280,   280,   995,   996,   997,   280,   430,   403,   105,
    1299,   451,  1439,  1001,  1299,   406,  1477,  1494,   648,  1495,
    1510,   988,   431,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   436,  1077,  1078,
    1079,   396,   416,   131,   132,   133,   134,   135,   136,  1512,
     437,  1513,  1031,   441,   454,   140,   141,   442,   142,  1532,
     640,  1299,  1515,  1520,   443,  1152,  1289,  1522,  1155,   147,
    1523,   444,   445,  1163,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   280,   280,   280,  1481,   396,
    1299,   648,  1526,  1527,   648,   280,  1546,  1403,   648,  1592,
    1609,   103,   303,   648,  1299,  1611,  1620,   106,   107,   108,
     446,   447,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   648,  1658,  1653,  1659,  1299,  1686,
    1678,  1687,   280,   137,   138,   139,   448,   455,  1254,   150,
     151,   466,   477,   478,   143,   144,   145,   467,   280,   105,
    1190,   468,   146,   487,   280,   479,   483,  1458,   489,   490,
     280,   491,   280,   280,   492,   495,   496,   280,   280,   280,
     280,   280,   280,   280,   280,   523,   497,   416,   526,   501,
     533,   416,   758,   131,   132,   133,   134,   135,   136,   280,
     530,   532,   165,   537,   310,   140,   141,   538,   142,   540,
     548,  1278,   549,   552,   280,  1245,   553,   555,   280,   147,
     280,   396,   603,   783,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   604,   795,   796,   797,   798,   799,
     800,   801,   149,   605,   606,   805,   807,   808,   661,   152,
     153,   154,   155,   156,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   296,   469,   470,   164,
     396,   665,   159,   666,   667,   692,   670,   471,   671,   690,
     693,   719,   163,   694,   232,   717,  1282,   720,   722,   729,
    1459,   730,   280,   735,   741,   743,   744,   745,   517,   150,
     151,   746,   296,   747,   406,   748,   749,   762,   765,   771,
     921,   778,   779,  1307,  1310,   809,   810,  1497,   416,   811,
     922,   815,   812,   813,   416,   819,   820,  1278,   923,   924,
     925,   822,   821,   823,   926,   927,   928,   929,   831,   832,
     406,  1279,   836,   857,   862,   889,   865,   867,   869,  1336,
    1343,   871,  1346,   875,  1349,   874,   876,   878,   416,   880,
     376,   376,   879,   881,   883,   280,   543,   280,  1360,   280,
     884,  1363,  1364,   894,   885,   898,   896,  1304,   899,   416,
     900,   914,   901,   915,   280,   941,   954,     7,     8,   907,
     968,   280,   969,   970,   280,   955,   957,   280,  1381,   971,
     958,   959,   980,   978,  1003,  1387,  1390,  1008,  1535,  1009,
    1012,  1011,  1015,  1023,  1024,  1027,   280,  1025,  1030,  1131,
    1035,  1041,  1047,  1052,  1451,  1582,   387,   388,   389,   390,
     391,   392,   393,   394,   395,  1048,  1053,   280,  1055,   396,
    1056,   607,    21,    22,   608,    24,    25,   609,    27,   610,
      29,  1059,    30,  1060,  1061,   921,  1062,    35,    36,  1063,
      38,    39,    40,  1064,  1480,   922,    43,  1065,  1066,  1067,
    1068,   280,  1070,   923,   924,   925,   280,  1080,  1081,   926,
     927,   928,   929,  1082,   416,  1501,   416,  1083,   921,  1084,
    1097,  1098,  1107,  1099,  1100,  1101,   280,  1103,   922,    64,
      65,    66,   280,  1104,  1105,   296,   923,   924,   925,  1020,
    1106,  1109,   926,   927,   928,   929,  1110,  1128,  1133,   280,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   631,   280,   280,  1134,   396,  1149,
    1136,  1137,  1139,   406,  1141,  1142,  1485,  1164,  1488,   416,
    1491,  1143,   280,  1538,   376,  1165,  1150,   280,  1499,  1181,
    1151,  1502,   725,  1183,  1159,  1182,  1176,  1186,  1198,  1201,
     167,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,  1202,  1606,  1205,  1192,   396,
    1583,  1132,  1586,  1193,  1194,  1206,  1199,  1207,  1200,  1212,
    1213,  1258,  1240,  1204,   311,  1222,  1236,  1228,  1229,  1241,
    1242,   280,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,  1243,  1265,  1555,
    1250,  1251,  1266,  1255,  1267,  1271,  1275,   304,  1274,   357,
     358,  1280,  1140,  1281,  1284,  1634,  1285,  1144,  1145,  1146,
    1147,  1148,   280,  1287,   280,  1153,  1156,  1585,  1514,   521,
    1290,  1291,  1292,  1293,  1303,  1311,  1318,   280,  1312,  1313,
    1316,  1319,  1320,  1321,  1322,  1325,  1326,  1327,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,  1328,  1329,  1330,  1333,   396,  1344,  1347,  1350,
    1354,  1358,  1361,  1365,  1368,  1391,  1616,  1384,  1393,  1394,
    1396,   365,   366,   367,   368,   370,  1395,   280,  1402,  1405,
    1414,  1424,  1416,  1417,  1421,   296,  1418,  1422,   402,  1433,
    1425,  1427,   408,  1435,  1429,  1431,  1436,  1442,  1448,  1453,
    1455,   413,   415,   418,   419,  1454,   421,   415,   423,   424,
     280,   415,   427,   428,  1460,  1467,   500,  1471,   415,  1472,
     818,  1473,  1474,   406,   921,   296,  1475,   296,  1476,  1478,
    1259,  1493,  1500,   525,   922,  1511,   450,  1516,  1517,  1540,
    1553,  1264,   923,   924,   925,   459,   460,  1524,   926,   927,
     928,   929,  1528,   296,   460,  1541,     7,     8,  1544,  1564,
    1641,  1565,  1567,   406,  1570,   406,  1571,  1574,  1575,  1578,
    1579,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   647,   394,   395,   516,   518,   415,  1584,   396,
    1598,   406,  1600,  1604,  1602,  1617,  1618,   527,   528,   529,
    1674,   531,  1677,  1624,   534,   535,  1627,  1630,   536,  1633,
     607,    21,    22,   608,    24,    25,   609,    27,   610,    29,
    1635,    30,  1646,   547,  1643,  1644,    35,    36,  1692,    38,
      39,    40,  1662,  1663,  1665,    43,   554,  1667,  1669,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,  1675,     7,     8,  1688,  1647,  1649,  1651,    64,    65,
      66,   588,  1689,   590,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,  1010,  1660,
    1690,  1691,   396,   612,   415,  1693,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,  1185,  1556,   630,  1469,  1196,   607,    21,    22,   608,
      24,    25,   609,    27,   610,    29,    88,    30,   516,   645,
    1470,   769,    35,    36,   652,    38,    39,    40,    96,   657,
       0,    43,  1286,     0,   662,   663,   673,     0,     0,     0,
     668,   669,     0,     0,     0,   674,   676,   679,   682,   685,
     687,   688,   689,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,     0,
     705,   706,   707,   365,   366,   708,     0,     0,     0,   712,
     713,   714,   715,   716,     0,     0,     0,   721,     0,     0,
     723,   724,     0,     0,   415,   415,   415,     0,     0,   731,
     732,   733,   734,     0,     0,     0,     0,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   415,
       0,  1051,     0,     0,     0,   753,   755,   770,   630,     0,
       0,     0,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   734,     0,     0,     0,
     396,     0,   776,   415,     0,     0,     0,   780,     0,     0,
       0,     0,     0,     0,   103,   303,     0,     0,     0,     0,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,   830,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
       0,  1102,     0,     0,     0,   146,     0,     0,     0,     0,
     921,     0,     0,     0,     0,     0,   856,     0,     0,   415,
     922,   415,   864,   921,     0,     0,     0,     0,   923,   924,
     925,   755,   872,   922,   926,   927,   928,   929,     0,     0,
       0,   923,   924,   925,     0,   886,     0,   926,   927,   928,
     929,     0,     0,     0,   892,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   415,     0,     0,     0,     0,
       0,     0,   912,   913,     0,   149,     0,     0,   916,     0,
    1160,     0,   152,   153,   154,   155,   156,     0,     0,     0,
       0,   940,     0,     0,   942,     0,     0,     0,  1648,     0,
     157,   158,     0,     0,     0,   159,     0,     0,     0,     0,
     272,  1650,   415,   369,   429,   163,     0,     0,     0,     0,
     415,   415,   415,   415,     0,     0,     0,     0,   415,     0,
       0,   415,     0,     0,     0,   449,     0,   972,   452,   974,
     975,     0,     0,     0,     0,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,   482,   396,   921,     0,     0,     0,   990,     0,
       0,     0,     0,     0,   922,     0,   991,   992,   993,     0,
     415,     0,   923,   924,   925,     0,  1166,     0,   926,   927,
     928,   929,     0,  1000,     0,     0,     0,     0,  1002,     0,
       0,  1007,     0,     0,     0,  1256,     0,     0,     0,     0,
       0,   415,   415,   415,   415,     0,     0,  1021,     0,     0,
     544,   545,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   551,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,   103,   104,   105,     0,     0,     0,   106,
     107,   108,  1652,   415,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,   141,     0,   142,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,  1111,     0,     0,     0,  1114,
       0,  1115,  1116,  1117,     0,     0,     0,     0,     0,  1122,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,  1138,     0,   396,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,  1168,     0,   148,     0,
       0,     0,     0,     0,   149,   150,   151,  1177,  1178,     0,
       0,   152,   153,   154,   155,   156,     0,     0,  1187,  1189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,     0,     0,     0,   159,   921,     0,     7,     8,   160,
       0,   161,     0,   162,   163,   922,   164,     0,   165,     0,
       0,     0,     0,   923,   924,   925,  1225,  1226,  1227,   926,
     927,   928,   929,     0,     0,     0,  1237,     0,  1239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1244,
       0,     0,     0,     0,     0,     0,     0,   415,     0,     0,
       0,   607,    21,    22,   608,    24,    25,   609,    27,   610,
      29,     0,    30,     0,     0,     0,     0,    35,    36,     0,
      38,    39,    40,  1268,  1269,  1270,    43,   921,     0,     0,
       0,     0,   825,     0,     0,     0,     0,   922,     0,     0,
       0,     0,     0,  1679,     0,   923,   924,   925,     0,     0,
       0,   926,   927,   928,   929,     0,  1283,     0,     0,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
    1296,     0,     0,     0,     0,  1302,     0,     0,     0,     0,
       0,     0,  1306,     0,     0,     0,  1308,  1309,     0,     0,
       0,     0,     0,  1314,  1315,     0,     0,     0,  1317,     0,
    1276,     0,     0,     0,     0,   893,  1324,     0,     0,   921,
       0,     0,     0,     0,     0,     0,  1334,     0,  1335,   922,
       0,     0,   909,     0,   905,  1680,     0,   923,   924,   925,
    1352,     0,     0,   926,   927,   928,   929,     0,     0,     0,
       0,     0,   415,     0,     0,     0,   415,     0,     0,  1367,
       0,     0,     0,     0,  1369,  1370,  1371,  1372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1380,     0,     7,
       8,     0,     0,     0,     0,  1389,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,  1399,  1400,     0,   396,     0,     0,     0,     0,  1406,
       0,  1339,     0,  1340,     0,     0,   979,  1681,   981,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,    21,    22,   608,    24,    25,   609,
      27,   610,    29,  1423,    30,     0,     0,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,     0,
       0,  1437,     0,   516,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,  1449,     0,
    1450,     0,   396,   415,     0,     0,     0,     0,     0,  1457,
       0,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,  1462,     0,     0,     0,     0,  1466,     0,     0,
       0,     0,     0,     0,     0,     0,  1392,  1057,     0,  1039,
    1040,     0,  1042,   415,  1045,  1046,     0,     0,  1049,  1050,
    1484,     0,  1487,     0,  1490,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   415,     0,     0,     0,  1503,  1504,
    1505,  1506,  1507,     0,   910,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1518,  1519,     0,
       0,     0,  1521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1525,     0,     0,     0,  1529,     0,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,  1420,     0,
       0,     0,  1125,  1126,  1127,     0,  1554,     0,     0,     0,
       0,  1302,  1135,     0,     0,     0,     0,     0,  1562,     0,
       0,     0,     0,     0,     0,  1569,     0,     0,  1573,     0,
       0,  1577,     0,     0,     0,  1580,     0,     0,     0,   415,
       0,   415,  1587,  1588,  1589,  1590,     0,     0,     0,     0,
       0,     0,  1594,     0,     0,  1596,     0,     0,     0,  1180,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,  1197,     0,     0,   396,     0,
       0,  1203,     0,     0,     0,     0,     0,  1208,     0,  1210,
    1211,  1622,     0,     0,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,     0,     0,   415,     0,  1636,  1637,  1638,  1639,
       0,     0,     0,     0,     0,     0,  1238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1249,     0,     0,     0,  1253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1670,  1671,
    1672,  1673,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,   103,   263,
     396,     0,     0,     0,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   265,  1452,     0,     0,     0,     0,     0,     0,  1294,
     137,   138,   139,     0,     0,     0,     0,     0,     7,     8,
       0,   143,   144,   145,     0,     0,     0,     0,     0,   146,
       0,   266,     0,     0,   267,     0,     0,   268,     0,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
       0,     0,   607,    21,    22,   608,    24,    25,   609,    27,
     610,    29,     0,    30,  1180,     0,     0,     0,    35,    36,
       0,    38,    39,    40,     0,     0,     0,    43,     0,     0,
       0,  1373,     0,     0,     0,     0,     0,     0,  1382,   149,
       0,  1383,     0,     0,  1386,     0,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,  1401,   469,  1359,  1552,     0,     0,   159,
       0,     0,     0,     0,   471,     0,     0,     0,     0,   163,
       0,   232,   519,     0,  1180,  1605,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   263,     0,     0,  1434,     0,
     106,   107,   108,   933,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   265,   521,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,  1180,   143,   144,   145,
       0,     0,     0,     0,     0,   146,     0,   266,     0,     0,
     267,     0,  1180,   268,     0,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,  1496,
       0,     0,     0,     0,    45,    46,    47,    48,    49,     0,
       0,     0,    53,     0,     0,    56,     0,     0,     0,     0,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,   149,     0,   396,  1539,     0,
       0,     0,   152,   153,   154,   155,   156,     0,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   414,     0,     0,     0,   159,     0,     0,   766,     0,
     272,     0,     0,     0,     0,   163,     0,     0,   519,     0,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   522,   394,   395,     0,     0,     0,     0,   396,   103,
     263,   105,     0,     0,  1180,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   265,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,   140,   141,     0,
     142,     0,   143,   144,   145,     0,     0,     0,     0,     0,
     146,   147,   266,     0,     0,   267,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,  1180,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   647,   394,   395,     0,     0,     0,     0,   396,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     149,   150,   151,     0,     0,     0,     0,   152,   153,   154,
     155,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   271,     0,     0,     0,
     159,     0,     0,     0,     0,   272,     0,   103,   263,   264,
     163,     0,  1385,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     265,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,   139,     0,     0,     0,     7,     8,     0,     0,     0,
     143,   144,   145,     0,     0,     0,     0,     0,   146,     0,
     266,     0,     0,   267,     0,     0,   268,     0,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,   607,
      21,    22,   608,    24,    25,   609,    27,   610,    29,     0,
      30,     0,     0,     0,     0,    35,    36,     0,    38,    39,
      40,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,     0,
       0,     0,     0,     0,     0,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     0,     0,   157,   271,     0,     0,     0,   159,     0,
       0,     0,     0,   272,     0,   103,   263,  1247,   163,     0,
     273,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   265,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
     973,     0,     0,     7,     8,     0,     0,     0,   143,   144,
     145,     0,     0,     0,     0,     0,   146,     0,   266,     0,
       0,   267,     0,     0,   268,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
       0,     0,     0,    53,     0,     0,    56,   607,    21,    22,
     608,    24,    25,   609,    27,   610,    29,     0,    30,     0,
       0,     0,     0,    35,    36,     0,    38,    39,    40,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,   152,   153,   154,   155,   156,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,     0,     0,
       0,   157,   271,     0,     0,     0,   159,     0,     0,     0,
       0,   272,     0,   103,   263,     0,   163,     0,  1248,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,  1071,     0,
       0,     7,     8,     0,     0,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,     0,   266,     0,     0,   267,
       0,     0,   268,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,   607,    21,    22,   608,    24,
      25,   609,    27,   610,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,   157,
     271,     0,     0,     0,   159,     0,     0,     0,     0,   272,
       0,   103,   263,     0,   163,     0,   273,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,  1542,     0,     0,     7,
       8,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,     0,   146,     0,   266,     0,     0,   267,     0,     0,
     268,     0,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   607,    21,    22,   608,    24,    25,   609,
      27,   610,    29,     0,    30,     0,     0,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,   843,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,   965,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,   157,   414,     0,
       0,     0,   159,     0,     0,     0,     0,   272,     0,   103,
     263,     0,   163,     0,   515,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   265,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,  1607,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,     0,     0,     0,
     146,     0,   266,     0,     0,   267,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     149,     0,     0,     0,     0,     0,     0,   152,   153,   154,
     155,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   414,     0,     0,     0,
     159,     0,     0,     0,     0,   272,     0,   103,   303,   105,
     163,     0,   754,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
    1130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,   140,   141,     0,   142,     0,
     143,   144,   145,     0,     0,     0,     0,     0,   146,   147,
     103,   263,     0,     0,     0,     0,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,     0,     0,     0,     0,
       0,   146,     0,   266,     0,     0,   267,     0,     0,   268,
       0,   269,     0,     0,     0,     0,     0,     0,   149,   150,
     151,     0,     0,   270,     0,   152,   153,   154,   155,   156,
      45,    46,    47,    48,    49,     0,     0,     0,    53,     0,
       0,    56,     0,   157,   158,     0,     0,     0,   159,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   163,     0,
    1188,     0,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,   149,     0,     0,     0,     0,     0,     0,   152,   153,
     154,   155,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   271,     0,     0,
       0,   159,     0,     0,     0,     0,   272,     0,   103,   303,
     105,   163,     0,  1252,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,     0,   140,   141,     0,   142,
       0,   143,   144,   145,     0,   103,   303,   105,     0,   146,
     147,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,   140,   141,     0,   142,     0,   143,   144,
     145,     0,     0,     0,     0,     0,   146,   147,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,   149,
     150,   151,     0,  1374,     0,  1375,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,     0,     0,     0,   159,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   163,
       0,  1379,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   149,   150,   151,     0,
     396,     0,     0,   152,   153,   154,   155,   156,     0,   841,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,     0,     0,     0,   159,     0,     0,     0,
       0,   272,     0,   103,   263,     0,   163,     0,  1388,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,     0,
       0,     7,     8,     0,     0,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,     0,   266,     0,     0,   267,
       0,     0,   268,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,   607,    21,    22,   608,    24,
      25,   609,    27,   610,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,   469,
    1359,     0,     0,     0,   159,     0,     0,     0,     0,   471,
       0,   103,   263,     0,   163,     0,   232,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,     0,   146,     0,   266,     0,     0,   267,     0,     0,
     268,     0,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   103,   303,     0,     0,     0,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,   149,     0,     0,   137,   138,   139,     0,   152,
     153,   154,   155,   156,     0,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,     0,     0,   157,   414,     0,
       0,     0,   159,   103,   303,   105,     0,   272,     0,   106,
     107,   108,   163,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,   141,     0,   142,     0,   143,   144,   145,     0,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,     0,     0,     0,   159,     0,     0,     0,     0,   272,
       0,     0,   546,     0,   163,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1482,     0,  1483,     0,   149,   150,   151,     0,     0,     0,
       0,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,     0,     0,     0,   159,   103,   303,     0,     0,   272,
       0,   106,   107,   108,   163,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,     0,     0,     0,     0,     0,   146,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,   888,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,   936,     0,     0,    -4,     1,     0,     0,    -4,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,   152,   153,   154,   155,   156,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,   157,   158,    -4,    -4,    -4,   159,     0,    -4,     0,
      -4,   272,     0,     0,    -4,    -4,   163,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,     0,     0,    -4,     6,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,    -4,     0,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,     0,     0,    14,     0,    15,     0,     0,     0,    16,
      17,     0,    18,    19,     0,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
      59,    60,    61,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,    63,    64,    65,    66,     0,     0,    67,
       0,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    80,    81,    82,
      83,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,   956,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,   984,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,  1075,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,  1337,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
    1356,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,  1409,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,  1410,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,  1411,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,  1412,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
    1413,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,  1443,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,  1498,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,  1508,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,  1509,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
    1530,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,  1533,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,  1536,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,  1563,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,  1566,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
    1599,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,  1601,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,  1603,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,  1621,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,     0,  1645,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
    1682,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,  1683,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,  1684,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,  1685,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,   691,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,  1419,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,   751,
       0,     0,     0,     0,   698,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
     638,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,   698,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,   699,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,   763,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,   794,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
     802,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,   803,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,   804,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,   918,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,   919,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
     920,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,   951,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1034,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1073,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1074,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1129,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,  1260,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1261,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1262,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1263,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1297,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,  1298,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1305,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1444,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1445,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1446,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,  1447,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1463,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1464,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1468,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1548,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,  1549,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1550,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1551,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1558,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1561,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,  1597,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1612,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1613,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1614,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
    1615,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,  1654,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,  1655,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,  1656,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,  1657,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   736,     0,   737,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
     599,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,   768,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,   775,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,   781,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,   855,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,     0,     0,   944,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,     0,     0,   945,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,     0,
       0,   949,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,     0,     0,   950,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,     0,     0,   952,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
     986,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,     0,     0,  1029,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,     0,     0,  1257,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,     0,     0,  1288,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
       0,     0,  1432,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,   596,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,   646,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   650,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   651,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,   653,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,   655,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,   656,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     659,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,   660,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,   751,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,   759,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,   760,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   761,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   767,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,   877,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,   882,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,   887,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     890,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,   891,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,   897,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,   902,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,   903,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,   904,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,   935,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396,     0,   937,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,   938,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,     0,     0,     0,     0,   396,     0,   939,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,     0,     0,     0,     0,   396,     0,
     943,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,     0,     0,     0,     0,   396,
       0,  1158,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     0,     0,     0,     0,
     396,     0,  1338,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,     0,  1355,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,     0,  1378,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,     0,
       0,     0,     0,   396,     0,  1557,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       0,     0,     0,     0,   396,     0,  1619,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,     0,     0,     0,     0,   396
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1232)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,   240,   225,     4,     6,     4,   347,   188,   349,   463,
     464,     6,   193,   252,   355,     3,   197,     4,     4,  1250,
       6,     6,     4,   204,     5,     5,     5,    72,     6,     6,
       5,     4,     4,   176,   177,   369,     4,   371,     3,     5,
     183,     6,     4,     4,     4,     4,    46,    47,     4,    49,
       5,   102,     6,     6,     6,     4,   930,     6,   181,    62,
     183,   300,     7,   302,     6,   188,     6,     4,    66,   169,
     170,    69,     6,    76,    72,   169,   170,     6,     6,   169,
     170,   169,   170,   182,    66,   185,   185,   187,    70,  1320,
     271,   185,   273,   187,   179,   185,   181,   187,   183,   187,
      82,   186,     7,   188,   169,   170,   169,   170,     4,     5,
     179,    76,   181,   188,   179,   169,   170,    66,   193,   169,
     170,   186,   197,   186,   180,     7,   182,   934,     0,   204,
     186,   185,   119,   120,   121,   122,   186,   169,   170,     7,
     117,   176,   177,    39,    40,    41,    42,    43,    44,     7,
     179,   132,   132,   132,   186,    51,    52,   132,    54,    13,
     163,   129,   130,     7,   117,   179,   138,   169,   170,    65,
     179,  1402,   175,   176,     6,   117,   164,   186,   179,   182,
       6,   166,   181,   117,   183,   188,     7,  1418,   166,   188,
     193,   180,   129,   130,   197,   181,   185,   200,   163,   380,
     187,   204,   205,   206,   207,   186,   179,   210,   211,   212,
     175,   176,   546,   186,   186,   454,   455,   182,   221,   179,
     186,   224,  1096,     6,   186,   186,   186,   186,   228,   229,
     186,   186,   186,   414,   186,   474,   236,   180,   183,   179,
     240,   179,   185,   246,   247,   248,   186,   175,   176,   145,
     146,   156,   157,   158,   159,   258,   259,     6,    66,   176,
     177,    69,   596,     6,    72,   599,   169,   170,   271,   186,
     273,   176,   177,   181,   156,   157,   158,   159,   183,   181,
     176,   177,   185,   169,   170,   179,   188,   183,   156,   157,
     158,   159,   186,   532,   176,   177,   181,   180,   156,   157,
     158,   159,   185,   306,   307,   380,   169,   170,   179,   490,
     491,   492,   156,   157,   158,   159,   319,   312,   176,   177,
     371,    76,   185,   169,   170,    69,   169,   170,    72,  1560,
      74,   179,   176,   177,   515,   156,   157,   158,   159,   185,
     182,   522,   185,   185,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   179,   176,   177,   360,   361,   362,
     363,   169,   170,   358,   169,   170,   176,   177,   549,   364,
       8,   179,   171,   172,   173,   179,   186,   380,   186,   178,
     185,     4,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   169,   170,   180,   360,   361,   362,   363,   185,
     129,    66,   169,   170,    69,   169,   170,    72,   185,    74,
     179,   414,  1643,   142,   143,   490,   491,   492,   185,    89,
     348,   185,   350,   351,   352,   353,   354,     8,   356,    99,
      72,   179,   360,   361,   362,   169,   170,   107,   108,   109,
     515,   775,    72,   113,   114,   115,   116,   442,   443,   444,
     445,   185,   169,   170,   635,   694,   637,    72,   181,    74,
     183,   461,   462,   169,   170,   188,   647,   648,   185,   469,
      93,    94,    95,    96,   549,   463,   464,     6,   101,   185,
     180,   104,   182,   169,   170,   186,   186,   490,   491,   492,
     179,    69,   169,   170,    72,   169,   170,   186,   501,   185,
     205,   206,   207,    72,   555,   210,   211,   212,   185,   180,
     691,   185,   515,   179,   185,    72,   180,   187,   182,   522,
     186,   185,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   501,   176,   177,    74,
     178,   246,   247,   169,   170,   180,   549,   186,   599,   187,
     185,   179,    69,   258,   259,   169,   170,   738,    72,   185,
     635,   179,   637,   181,   186,   746,   747,   748,   749,    69,
     188,   185,    72,   754,    74,   186,   757,   169,   170,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   185,   179,   598,   181,   178,   169,   170,
     171,   172,   173,   188,   180,   600,   187,   178,   180,   185,
     182,   834,  1486,   185,    69,  1489,   691,    72,  1492,   185,
    1427,   187,  1429,    66,  1431,   806,    69,    69,    89,    72,
      69,    74,   635,   185,   637,   187,    72,   640,    99,   185,
     643,   187,   645,     4,   647,   648,   107,   108,   109,   185,
       4,   187,   113,   114,   115,   116,   837,   838,   839,   840,
     180,     4,   182,   738,   179,   185,     6,   185,   671,   187,
    1004,   746,   747,   748,   749,   640,     6,     7,   643,   754,
     645,   185,   757,   187,   735,     4,  1020,   690,   691,   180,
     185,   182,   187,   179,   185,    89,   180,   697,   182,   179,
     185,   185,   187,     6,   704,    99,   179,  1581,   889,   185,
     710,   187,   640,   107,   108,   109,   185,   645,   187,   113,
     114,   115,   116,   185,   775,   187,   187,   185,     6,   187,
     781,   806,   180,     4,   182,   738,  1543,    72,    72,    74,
      74,     6,     7,   746,   747,   748,   749,   181,   179,  1623,
       7,   754,  1626,     4,   757,  1629,   179,   185,  1632,   187,
       7,   179,   837,   838,   839,   840,   185,   179,   187,   772,
     185,   774,   187,   179,  1228,  1229,   179,   185,   781,   187,
     185,   185,   187,   187,   185,   185,   187,   187,  1011,   179,
    1664,  1598,  1666,  1600,  1668,  1602,   185,   185,   187,   187,
     185,  1608,   187,   806,   855,   185,  1140,   187,   811,   812,
     813,   185,   179,   187,   889,   185,   781,   187,   821,   179,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   837,   838,   839,   840,   178,   186,
    1647,    89,  1649,   185,  1651,   187,   811,   812,   813,   186,
       4,    99,     6,   781,   179,   179,   821,   860,   179,   107,
     108,   109,   185,     6,   187,   113,   114,   115,   116,   186,
       6,   871,   875,   876,   185,   878,   187,   880,   881,   179,
     179,   884,   885,   811,   812,   813,   889,   179,     4,     5,
     185,     4,   187,   821,   185,   860,   187,   185,   185,   187,
     187,   952,   186,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   179,   918,   919,
     920,   178,  1103,    39,    40,    41,    42,    43,    44,   185,
     179,   187,   860,   179,   186,    51,    52,   179,    54,   187,
     185,   185,   187,   187,   179,   185,  1169,   187,   185,    65,
     187,   179,   179,  1004,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   968,   969,   970,  1422,   178,
     185,   185,   187,   187,   185,   978,   187,   185,   185,   187,
     187,     3,     4,   185,   185,   187,   187,     9,    10,    11,
     179,   179,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   185,   185,   187,   187,   185,   185,
     187,   187,  1025,    45,    46,    47,   179,   186,  1103,   145,
     146,   186,   179,   179,    56,    57,    58,   186,  1041,     5,
    1035,   186,    64,   181,  1047,   179,   179,  1388,     6,   186,
    1053,   186,  1055,  1056,   186,   181,   181,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,     6,   181,  1248,     6,   181,
     132,  1252,   525,    39,    40,    41,    42,    43,    44,  1082,
     183,   186,   188,     6,   188,    51,    52,     6,    54,     6,
     186,  1142,   186,     6,  1097,  1095,   181,     4,  1101,    65,
    1103,   178,   183,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,     7,   568,   569,   570,   571,   572,
     573,   574,   144,   181,   187,   578,   579,   580,     7,   151,
     152,   153,   154,   155,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,  1149,   169,   170,   186,
     178,     6,   174,     6,     6,   180,     7,   179,     7,     7,
       6,     6,   184,   186,   186,     7,  1161,     7,     6,     6,
    1393,     6,  1175,     4,    48,    48,    48,    48,  1359,   145,
     146,   186,  1185,   186,  1149,   186,   186,   129,   186,   180,
      89,     6,     6,  1188,  1194,   180,   180,  1436,  1379,   185,
      99,   180,   185,   185,  1385,   185,   180,  1258,   107,   108,
     109,   180,   185,   180,   113,   114,   115,   116,     6,     4,
    1185,  1149,   182,     4,     6,   186,     6,     6,     6,  1224,
    1230,     7,  1232,     7,  1234,   132,     7,     7,  1419,     7,
    1228,  1229,   132,     7,   132,  1248,     6,  1250,  1248,  1252,
       7,  1251,  1252,     4,     7,   180,     6,  1185,   180,  1440,
     180,   187,   180,   187,  1267,     6,   182,    12,    13,   183,
       7,  1274,     7,     7,  1277,   186,   186,  1280,  1273,   183,
     186,   186,     6,   186,     6,  1280,  1281,     6,   187,     6,
     181,     7,     6,   179,   179,     6,  1299,   186,   166,     8,
       7,     7,     7,     7,  1379,  1544,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    74,     7,  1320,     7,   178,
       7,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     6,    77,     7,     7,    89,     7,    82,    83,     7,
      85,    86,    87,     7,  1419,    99,    91,     7,     7,     7,
       6,  1354,     4,   107,   108,   109,  1359,     4,     6,   113,
     114,   115,   116,   186,  1545,  1440,  1547,     6,    89,   179,
       7,     6,    72,     7,     7,     7,  1379,   186,    99,   124,
     125,   126,  1385,     6,     6,  1388,   107,   108,   109,   842,
       6,     6,   113,   114,   115,   116,     6,     4,     4,  1402,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     6,  1418,  1419,     4,   178,   185,
     187,     6,     6,  1388,     6,     4,  1426,   183,  1428,  1610,
    1430,     6,  1435,   187,  1422,     7,   180,  1440,  1438,   186,
     180,  1441,   187,     6,   180,   183,   179,     6,     6,     6,
       6,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     6,   187,     6,   186,   178,
    1545,   180,  1547,   186,    82,     6,   186,     5,   186,     4,
       6,     4,     6,   186,   101,     7,   181,   186,   186,     6,
       6,  1494,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     6,     6,  1514,
     186,   186,     6,   186,   128,     6,     6,    83,   185,   146,
     147,     4,   985,     4,     6,  1610,     4,   990,   991,   992,
     993,   994,  1545,     6,  1547,   998,   999,  1547,     7,     8,
       6,     6,     6,     6,     4,     6,     5,  1560,     6,     6,
       6,     6,   186,     6,   132,     6,     6,     6,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     6,     6,     6,     6,   178,     6,     6,     6,
     185,     6,     6,     6,     6,     6,  1591,   180,     7,     6,
       6,   157,   158,   159,   160,   161,   183,  1610,   186,     6,
       5,   187,    70,     6,     6,  1618,   186,   186,   174,     6,
     187,   186,   178,     7,   186,   186,   186,     6,   127,     6,
       6,   187,   188,   189,   190,   187,   192,   193,   194,   195,
    1643,   197,   198,   199,   130,     6,   263,     6,   204,     6,
       6,     6,     6,  1618,    89,  1658,     6,  1660,     6,   186,
    1113,     6,     6,   280,    99,     6,   222,     6,   186,     6,
       6,  1124,   107,   108,   109,   231,   232,   186,   113,   114,
     115,   116,   187,  1686,   240,    89,    12,    13,   186,     6,
    1618,     6,     6,  1658,     6,  1660,     6,     6,     6,     6,
     187,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   271,   272,   273,     6,   178,
     186,  1686,   186,     6,   186,     6,   186,   283,   284,   285,
    1658,   287,  1660,     6,   290,   291,     6,     6,   294,     6,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       6,    77,   187,   309,   186,     6,    82,    83,  1686,    85,
      86,    87,     6,     6,     6,    91,   322,     6,     6,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,     6,    12,    13,     6,   186,   186,   186,   124,   125,
     126,   357,     6,   359,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     6,   186,
       6,     6,   178,   379,   380,     6,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,  1032,  1517,   399,  1407,  1040,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     3,    77,   414,   412,
    1408,   187,    82,    83,   420,    85,    86,    87,     3,   425,
      -1,    91,  1165,    -1,   430,   431,   440,    -1,    -1,    -1,
     436,   437,    -1,    -1,    -1,   441,   442,   443,   444,   445,
     446,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
     466,   467,   468,   469,   470,   471,    -1,    -1,    -1,   475,
     476,   477,   478,   479,    -1,    -1,    -1,   483,    -1,    -1,
     486,   487,    -1,    -1,   490,   491,   492,    -1,    -1,   495,
     496,   497,   498,    -1,    -1,    -1,    -1,    -1,   504,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,
      -1,     6,    -1,    -1,    -1,   521,   522,   187,   524,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   542,    -1,    -1,    -1,
     178,    -1,   548,   549,    -1,    -1,    -1,   553,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   601,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,     6,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,   632,    -1,    -1,   635,
      99,   637,   638,    89,    -1,    -1,    -1,    -1,   107,   108,
     109,   647,   648,    99,   113,   114,   115,   116,    -1,    -1,
      -1,   107,   108,   109,    -1,   661,    -1,   113,   114,   115,
     116,    -1,    -1,    -1,   670,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,   691,    -1,    -1,    -1,    -1,
      -1,    -1,   698,   699,    -1,   144,    -1,    -1,   704,    -1,
       6,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   717,    -1,    -1,   720,    -1,    -1,    -1,   187,    -1,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
     179,   187,   738,   182,   200,   184,    -1,    -1,    -1,    -1,
     746,   747,   748,   749,    -1,    -1,    -1,    -1,   754,    -1,
      -1,   757,    -1,    -1,    -1,   221,    -1,   763,   224,   765,
     766,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,   248,   178,    89,    -1,    -1,    -1,   794,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   802,   803,   804,    -1,
     806,    -1,   107,   108,   109,    -1,     6,    -1,   113,   114,
     115,   116,    -1,   819,    -1,    -1,    -1,    -1,   824,    -1,
      -1,   827,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,   837,   838,   839,   840,    -1,    -1,   843,    -1,    -1,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   319,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,   187,   889,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    54,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,   948,    -1,    -1,   951,    -1,    -1,    -1,   955,
      -1,   957,   958,   959,    -1,    -1,    -1,    -1,    -1,   965,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,   982,    -1,   178,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1012,    -1,   138,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,  1023,  1024,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,  1034,  1035,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,    89,    -1,    12,    13,   179,
      -1,   181,    -1,   183,   184,    99,   186,    -1,   188,    -1,
      -1,    -1,    -1,   107,   108,   109,  1072,  1073,  1074,   113,
     114,   115,   116,    -1,    -1,    -1,  1082,    -1,  1084,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1095,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1103,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    86,    87,  1129,  1130,  1131,    91,    89,    -1,    -1,
      -1,    -1,   598,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   187,    -1,   107,   108,   109,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,  1162,    -1,    -1,   124,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1176,    -1,    -1,    -1,    -1,  1181,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,    -1,  1192,  1193,    -1,    -1,
      -1,    -1,    -1,  1199,  1200,    -1,    -1,    -1,  1204,    -1,
       6,    -1,    -1,    -1,    -1,   671,  1212,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,  1222,    -1,  1224,    99,
      -1,    -1,   187,    -1,   690,   187,    -1,   107,   108,   109,
    1236,    -1,    -1,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,  1248,    -1,    -1,    -1,  1252,    -1,    -1,  1255,
      -1,    -1,    -1,    -1,  1260,  1261,  1262,  1263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1273,    -1,    12,
      13,    -1,    -1,    -1,    -1,  1281,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,  1297,  1298,    -1,   178,    -1,    -1,    -1,    -1,  1305,
      -1,   185,    -1,   187,    -1,    -1,   772,   187,   774,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,  1339,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
      -1,  1357,    -1,  1359,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,  1374,    -1,
    1376,    -1,   178,  1379,    -1,    -1,    -1,    -1,    -1,  1385,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1398,    -1,    -1,    -1,    -1,  1403,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    89,    -1,   875,
     876,    -1,   878,  1419,   880,   881,    -1,    -1,   884,   885,
    1426,    -1,  1428,    -1,  1430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1440,    -1,    -1,    -1,  1444,  1445,
    1446,  1447,  1448,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1463,  1464,    -1,
      -1,    -1,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1478,    -1,    -1,    -1,  1482,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,     6,    -1,
      -1,    -1,   968,   969,   970,    -1,  1512,    -1,    -1,    -1,
      -1,  1517,   978,    -1,    -1,    -1,    -1,    -1,  1524,    -1,
      -1,    -1,    -1,    -1,    -1,  1531,    -1,    -1,  1534,    -1,
      -1,  1537,    -1,    -1,    -1,  1541,    -1,    -1,    -1,  1545,
      -1,  1547,  1548,  1549,  1550,  1551,    -1,    -1,    -1,    -1,
      -1,    -1,  1558,    -1,    -1,  1561,    -1,    -1,    -1,  1025,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,  1041,    -1,    -1,   178,    -1,
      -1,  1047,    -1,    -1,    -1,    -1,    -1,  1053,    -1,  1055,
    1056,  1597,    -1,    -1,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,    -1,    -1,  1610,    -1,  1612,  1613,  1614,  1615,
      -1,    -1,    -1,    -1,    -1,    -1,  1082,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1097,    -1,    -1,    -1,  1101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1654,  1655,
    1656,  1657,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,     3,     4,
     178,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1175,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,  1250,    -1,    -1,    -1,    82,    83,
      -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,    -1,
      -1,  1267,    -1,    -1,    -1,    -1,    -1,    -1,  1274,   144,
      -1,  1277,    -1,    -1,  1280,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,  1299,   169,   170,     6,    -1,    -1,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,  1320,     6,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,  1354,    -1,
       9,    10,    11,   187,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1402,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,
      69,    -1,  1418,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,  1435,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,   144,    -1,   178,  1494,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,     8,    -1,
     179,    -1,    -1,    -1,    -1,   184,    -1,    -1,   187,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,     3,
       4,     5,    -1,    -1,  1560,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    51,    52,    -1,
      54,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,  1643,    -1,    93,
      94,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   170,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,   179,    -1,     3,     4,     5,
     184,    -1,   186,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    -1,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,    86,
      87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,   179,    -1,     3,     4,     5,   184,    -1,
     186,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
     187,    -1,    -1,    12,    13,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      -1,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,   104,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,    86,    87,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
      -1,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,   179,    -1,     3,     4,    -1,   184,    -1,   186,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,   187,    -1,
      -1,    12,    13,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,   104,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,     3,     4,    -1,   184,    -1,   186,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,   187,    -1,    -1,    12,
      13,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    -1,    69,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,     8,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,   169,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   179,    -1,     3,
       4,    -1,   184,    -1,   186,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   170,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,   179,    -1,     3,     4,     5,
     184,    -1,   186,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       8,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    -1,    54,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    -1,    69,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,    -1,    -1,    86,    -1,   151,   152,   153,   154,   155,
      93,    94,    95,    96,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,    -1,
     186,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   170,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,   179,    -1,     3,     4,
       5,   184,    -1,   186,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    52,    -1,    54,
      -1,    56,    57,    58,    -1,     3,     4,     5,    -1,    64,
      65,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    -1,    54,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    64,    65,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,   144,
     145,   146,    -1,   185,    -1,   187,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   170,    -1,    -1,    -1,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,
      -1,   186,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   144,   145,   146,    -1,
     178,    -1,    -1,   151,   152,   153,   154,   155,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,   179,    -1,     3,     4,    -1,   184,    -1,   186,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,   104,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,   169,
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
      -1,    -1,   104,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    45,    46,    47,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,   169,   170,    -1,
      -1,    -1,   174,     3,     4,     5,    -1,   179,    -1,     9,
      10,    11,   184,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    -1,    54,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,   179,
      -1,    -1,   182,    -1,   184,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,   187,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,    -1,   174,     3,     4,    -1,    -1,   179,
      -1,     9,    10,    11,   184,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    64,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,    -1,     0,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,   170,    48,    49,    50,   174,    -1,    53,    -1,
      55,   179,    -1,    -1,    59,    60,   184,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,   118,     4,    -1,    -1,    -1,   123,   124,
     125,   126,    12,    13,   129,    -1,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    59,
      60,    -1,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,    -1,   129,
      -1,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,   148,   149,
     150,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,   180,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,   180,    -1,   182,   160,   161,
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
      -1,    -1,   182,   160,   161,   162,   163,   164,   165,   166,
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
      -1,    -1,   178,    -1,   180,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,   180,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178
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
     236,   237,   238,   239,   240,   241,   242,   262,   263,   264,
     265,   283,   284,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      51,    52,    54,    56,    57,    58,    64,    65,   138,   144,
     145,   146,   151,   152,   153,   154,   155,   169,   170,   174,
     179,   181,   183,   184,   186,   188,   213,   266,   267,   279,
     280,   283,   284,    13,    72,   179,   179,     6,   186,     6,
       6,     6,   179,     6,     6,   181,   181,   179,   186,   179,
     179,     4,   179,   186,   179,   179,     4,   186,   179,   179,
      76,    72,    72,     6,   186,    66,    69,    72,    72,    72,
      69,    72,    74,    74,    66,    69,    72,    74,    69,    72,
      74,    69,    72,   179,    69,   129,   142,   143,   186,   169,
     170,   179,   186,   269,   270,   269,   186,    66,    69,    72,
     186,   269,     4,    66,    70,    82,    72,    74,    72,    69,
       4,   138,   186,     4,     6,    66,    69,    72,    69,    72,
       4,     4,     4,     4,     5,    36,    66,    69,    72,    74,
      86,   170,   179,   186,   233,   242,   266,   272,   273,   274,
     283,   284,     4,   179,   179,   179,     4,   186,   276,     4,
     179,   179,     6,     6,   181,     4,   283,   284,     4,     5,
     186,     5,   186,     4,   266,     6,   179,   186,   179,   181,
     188,   213,     7,   156,   157,   158,   159,   176,   177,   211,
     212,     4,   181,   183,   181,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     179,   179,   179,   179,   179,   179,   179,   213,   213,     7,
     179,   179,   179,   179,   179,   266,   266,   266,   266,   182,
     266,     4,   129,   130,   284,     4,   233,   234,   235,   186,
     186,     6,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   178,   186,     6,   181,
     212,     6,   266,     4,   279,   280,   284,   279,   266,   279,
     282,   217,   220,   266,   170,   266,   274,   275,   266,   266,
     179,   266,   275,   266,   266,   179,   275,   266,   266,   272,
     179,   186,   275,   273,   273,   273,   179,   179,   273,   273,
     273,   179,   179,   179,   179,   179,   179,   179,   179,   272,
     266,     4,   272,   276,   186,   186,   269,   269,   269,   266,
     266,   169,   170,   186,   186,   269,   186,   186,   186,   169,
     170,   179,   235,   269,   186,   179,   186,   179,   179,   179,
     273,   273,   272,   179,     4,     6,   181,   181,   235,     6,
     186,   186,   186,   273,   273,   181,   181,   181,   181,   183,
     213,   181,     5,   132,   186,     5,   132,     5,   132,     5,
     132,    66,    69,    72,    74,   186,   266,   274,   266,   187,
     275,     8,   171,     6,   181,   213,     6,   266,   266,   266,
     183,   266,   186,   132,   266,   266,   266,     6,     6,   235,
       6,   235,   181,     6,   272,   272,   182,   266,   186,   186,
     280,   272,     6,   181,   266,     4,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   282,   279,
     282,   279,   279,   279,   279,   279,   282,   279,   266,   280,
     266,   279,   279,   279,   284,   280,   180,     7,   211,   182,
       7,   211,   212,   183,     7,   181,   187,    66,    69,    72,
      74,   232,   266,   275,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   196,
     266,     6,   181,   183,   180,   185,   180,   185,   185,   180,
     185,   182,   185,   216,   182,   216,   180,   171,   185,   187,
     180,   180,   266,   180,   187,   180,   180,   266,   187,   180,
     180,     7,   266,   266,   187,     6,     6,     6,   266,   266,
       7,     7,   260,   260,   266,   226,   266,   280,   227,   266,
     280,   228,   266,   280,   229,   266,   280,   266,   266,   266,
       7,   186,   180,     6,   186,   235,   235,   185,   185,   185,
     269,   269,   234,   234,   185,   266,   266,   266,   266,   246,
     185,   235,   266,   266,   266,   266,   266,     7,   261,     6,
       7,   266,     6,   266,   266,   187,   275,   275,   275,     6,
       6,   266,   266,   266,   266,     4,   180,   182,   186,   214,
     284,    48,   266,    48,    48,    48,   186,   186,   186,   186,
     275,   180,   187,   266,   186,   266,   274,   186,   214,   180,
     180,   180,   129,   185,   235,   186,     8,   180,   182,   187,
     187,   180,   185,   187,   211,   182,   266,   275,     6,     6,
     266,   182,   212,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   185,   214,   214,   214,   214,   214,
     214,   214,   185,   185,   185,   214,   185,   214,   214,   180,
     180,   185,   185,   185,   180,   180,   268,   281,     6,   185,
     180,   185,   180,   180,   211,   272,   183,   211,   212,   280,
     266,     6,     4,     4,   186,   277,   182,   186,   186,   186,
     186,   187,   187,     8,     4,   119,   120,   121,   122,   187,
     199,   203,   206,   208,   209,   182,   266,     4,     6,   166,
     193,   275,     6,   275,   266,     6,   279,     6,   284,     6,
     279,     7,   266,   274,   132,     7,     7,   180,     7,   132,
       7,     7,   180,   132,     7,     7,   266,   180,   187,   186,
     180,   180,   266,   272,     4,   259,     6,   180,   180,   180,
     180,   180,   180,   180,   180,   272,   275,   183,   235,   187,
     187,   269,   266,   266,   187,   187,   266,   269,   185,   185,
     185,    89,    99,   107,   108,   109,   113,   114,   115,   116,
     256,   257,   269,   187,   243,   180,   187,   180,   180,   180,
     266,     6,   266,   180,   182,   182,   187,   187,   187,   182,
     182,   185,   182,   275,   182,   186,   187,   186,   186,   186,
     275,   275,   275,   275,   187,     8,   275,   275,     7,     7,
       7,   183,   266,   187,   266,   266,     7,   183,   186,   272,
       6,   272,   211,   212,   187,   187,   182,   183,   212,   279,
     266,   266,   266,   266,   275,   279,   279,   279,   222,   224,
     266,   279,   266,     6,     4,   129,   130,   266,     6,     6,
       6,     7,   181,   276,   278,     6,   275,   275,   275,   275,
     214,   266,   200,   179,   179,   186,   210,     6,   212,   182,
     166,   279,   180,   180,   185,     7,   269,    72,    74,   272,
     272,     7,   272,    72,    74,   272,   272,     7,    74,   272,
     272,     6,     7,     7,   275,     7,     7,    89,   258,     6,
       7,     7,     7,     7,     7,     7,     7,     7,     6,   187,
       4,   187,   185,   185,   185,   187,   187,   269,   269,   269,
       4,     6,   186,     6,   179,     6,   117,     6,   117,     6,
     117,     6,   117,   187,   257,   185,   256,     7,     6,     7,
       7,     7,     6,   186,     6,     6,     6,    72,   266,     6,
       6,   266,   183,   187,   266,   266,   266,   266,   187,   187,
     187,   187,   266,   187,   187,   272,   272,   272,     4,   185,
       8,     8,   180,     4,     4,   272,   187,     6,   266,     6,
     214,     6,     4,     6,   214,   214,   214,   214,   214,   185,
     180,   180,   185,   214,   223,   185,   214,   225,   180,   180,
       6,     7,   211,   212,   183,     7,     6,   276,   266,   185,
     187,   187,   187,   187,   187,   211,   179,   266,   266,   271,
     272,   186,   183,     6,     6,   193,     6,   266,   186,   266,
     280,     6,   186,   186,    82,   231,   231,   272,     6,   186,
     186,     6,     6,   272,   186,     6,     6,     5,   272,   187,
     272,   272,     4,     6,   272,   272,   272,   272,   272,   272,
     272,   272,     7,     6,     7,   266,   266,   266,   186,   186,
     185,   187,   185,   187,   185,   187,   181,   266,   272,   266,
       6,     6,     6,     6,   266,   269,   187,     5,   186,   272,
     186,   186,   186,   272,   275,   186,     6,   182,     4,   214,
     185,   185,   185,   185,   214,     6,     6,   128,   266,   266,
     266,     6,     6,     7,   185,     6,     6,   211,   212,   279,
       4,     4,   280,   266,     6,     4,   277,     6,   182,   276,
       6,     6,     6,     6,   272,   197,   266,   185,   185,   185,
     187,   198,   266,     4,   279,   185,   266,   280,   266,   266,
     269,     6,     6,     6,   266,   266,     6,   266,     5,     6,
     186,     6,   132,   230,   266,     6,     6,     6,     6,     6,
       6,     4,     6,     6,   266,   266,   280,   187,   180,   185,
     187,   234,   234,   269,     6,   247,   269,     6,   248,   269,
       6,   249,   266,   187,   185,   180,   187,   185,     6,   170,
     269,     6,   271,   269,   269,     6,   187,   266,     6,   266,
     266,   266,   266,   272,   185,   187,     8,   187,   180,   186,
     266,   280,   272,   272,   180,   186,   272,   280,   186,   266,
     280,     6,     6,     7,     6,   183,     6,   180,   185,   266,
     266,   272,   186,   185,   187,     6,   266,   218,   219,   187,
     187,   187,   187,   187,     5,   271,    70,     6,   186,   186,
       6,     6,   186,   266,   187,   187,   185,   186,   185,   186,
     185,   186,   182,     6,   272,     7,   186,   266,   185,   187,
     185,   185,     6,   187,   185,   185,   185,   185,   127,   266,
     266,   275,     6,     6,   187,     6,   221,   266,   282,   276,
     130,   201,   266,   185,   185,   271,   266,     6,   185,   222,
     224,     6,     6,     6,     6,     6,     6,   187,   186,   271,
     275,   234,   185,   187,   266,   269,   256,   266,   269,   256,
     266,   269,   256,     6,   185,   187,   272,   235,   187,   269,
       6,   275,   269,   266,   266,   266,   266,   266,   187,   187,
     187,     6,   185,   187,     7,   187,     6,   186,   266,   266,
     187,   266,   187,   187,   186,   266,   187,   187,   187,   266,
     187,   185,   187,   187,   185,   187,   187,   185,   187,   272,
       6,    89,   187,   244,   186,   185,   187,   185,   185,   185,
     185,   185,     6,     6,   266,   280,   198,   180,   185,     6,
     186,   185,   266,   187,     6,     6,   187,     6,   250,   266,
       6,     6,   251,   266,     6,     6,   252,   266,     6,   187,
     266,   256,   235,   275,     6,   269,   275,   266,   266,   266,
     266,     7,   187,   204,   266,   271,   266,   185,   186,   187,
     186,   187,   186,   187,     6,     6,   187,   187,   245,   187,
     185,   187,   185,   185,   185,   185,   280,     6,   186,   180,
     187,   187,   266,   256,     6,   253,   256,     6,   254,   256,
       6,   255,   256,     6,   275,     6,   266,   266,   266,   266,
     202,   279,   207,   186,     6,   187,   187,   186,   187,   186,
     187,   186,   187,   187,   185,   185,   185,   185,   185,   187,
     186,   271,     6,     6,   256,     6,   256,     6,   256,     6,
     266,   266,   266,   266,   279,     6,   205,   279,   187,   187,
     187,   187,   187,   187,   187,   187,   185,   187,     6,     6,
       6,     6,   279,     6
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
#line 3539 "Gmsh.y"
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

  case 297:
/* Line 1787 of yacc.c  */
#line 3595 "Gmsh.y"
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

  case 298:
/* Line 1787 of yacc.c  */
#line 3665 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3670 "Gmsh.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 3737 "Gmsh.y"
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

  case 301:
/* Line 1787 of yacc.c  */
#line 3773 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3781 "Gmsh.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 3824 "Gmsh.y"
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

  case 304:
/* Line 1787 of yacc.c  */
#line 3863 "Gmsh.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3883 "Gmsh.y"
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

  case 306:
/* Line 1787 of yacc.c  */
#line 3911 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
	yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        Surface *s_slave = FindSurface(abs(j_slave));
        if(s_slave){
	  GModel::current()->getGEOInternals()->periodicFaces[j_slave] = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (12)].l), i, &ds);
            List_Read((yyvsp[(10) - (12)].l), i, &dm);
	    GModel::current()->getGEOInternals()->periodicEdges[(int)ds] = (int)dm;
            s_slave->edgeCounterparts[(int)ds] = (int)dm;
          }
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(abs(j_slave));
          if(gf){
            gf->setMeshMaster(j_master);
            for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
              double dm, ds;
              List_Read((yyvsp[(5) - (12)].l), i, &ds);
              List_Read((yyvsp[(10) - (12)].l), i, &dm);
              gf->edgeCounterparts[(int)ds] = (int)dm;
	      GEdge *ges = GModel::current()->getEdgeByTag(abs((int)ds));
	      ges->setMeshMaster((int)dm);
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 3950 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3978 "Gmsh.y"
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

  case 309:
/* Line 1787 of yacc.c  */
#line 4006 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 4010 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 4014 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 4042 "Gmsh.y"
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

  case 313:
/* Line 1787 of yacc.c  */
#line 4081 "Gmsh.y"
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

  case 314:
/* Line 1787 of yacc.c  */
#line 4120 "Gmsh.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 4141 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4162 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4189 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 4193 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4203 "Gmsh.y"
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

  case 320:
/* Line 1787 of yacc.c  */
#line 4237 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4238 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 4239 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 4244 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4250 "Gmsh.y"
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

  case 325:
/* Line 1787 of yacc.c  */
#line 4262 "Gmsh.y"
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

  case 326:
/* Line 1787 of yacc.c  */
#line 4280 "Gmsh.y"
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

  case 327:
/* Line 1787 of yacc.c  */
#line 4307 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4308 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 4309 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4310 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4311 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4312 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4313 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4314 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4316 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4322 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4323 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4324 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4325 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4326 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4327 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4328 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4329 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4330 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4331 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4332 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4334 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4335 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4336 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4337 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4338 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4339 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4340 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4341 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4342 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4343 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4344 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4345 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4346 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4347 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4348 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4349 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4350 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4351 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4352 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4353 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4354 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4363 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4364 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4365 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4366 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4367 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4368 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4370 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4371 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4372 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4377 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4379 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4385 "Gmsh.y"
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

  case 382:
/* Line 1787 of yacc.c  */
#line 4402 "Gmsh.y"
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

  case 383:
/* Line 1787 of yacc.c  */
#line 4420 "Gmsh.y"
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

  case 384:
/* Line 1787 of yacc.c  */
#line 4438 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4443 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4449 "Gmsh.y"
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

  case 387:
/* Line 1787 of yacc.c  */
#line 4461 "Gmsh.y"
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

  case 388:
/* Line 1787 of yacc.c  */
#line 4478 "Gmsh.y"
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

  case 389:
/* Line 1787 of yacc.c  */
#line 4496 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4517 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 4522 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4527 "Gmsh.y"
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

  case 393:
/* Line 1787 of yacc.c  */
#line 4537 "Gmsh.y"
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

  case 394:
/* Line 1787 of yacc.c  */
#line 4547 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4552 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 4561 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4566 "Gmsh.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 4593 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4597 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4601 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4605 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4609 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4616 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4624 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4635 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4640 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4647 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4652 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4656 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4661 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4665 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4673 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4688 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4700 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4708 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4716 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4723 "Gmsh.y"
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

  case 421:
/* Line 1787 of yacc.c  */
#line 4733 "Gmsh.y"
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

  case 422:
/* Line 1787 of yacc.c  */
#line 4762 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4766 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4770 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4774 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4778 "Gmsh.y"
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

  case 427:
/* Line 1787 of yacc.c  */
#line 4807 "Gmsh.y"
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

  case 428:
/* Line 1787 of yacc.c  */
#line 4836 "Gmsh.y"
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

  case 429:
/* Line 1787 of yacc.c  */
#line 4865 "Gmsh.y"
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

  case 430:
/* Line 1787 of yacc.c  */
#line 4895 "Gmsh.y"
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

  case 431:
/* Line 1787 of yacc.c  */
#line 4908 "Gmsh.y"
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

  case 432:
/* Line 1787 of yacc.c  */
#line 4921 "Gmsh.y"
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

  case 433:
/* Line 1787 of yacc.c  */
#line 4934 "Gmsh.y"
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

  case 434:
/* Line 1787 of yacc.c  */
#line 4946 "Gmsh.y"
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

  case 435:
/* Line 1787 of yacc.c  */
#line 4956 "Gmsh.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 4966 "Gmsh.y"
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

  case 437:
/* Line 1787 of yacc.c  */
#line 4978 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 4990 "Gmsh.y"
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

  case 439:
/* Line 1787 of yacc.c  */
#line 5002 "Gmsh.y"
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

  case 440:
/* Line 1787 of yacc.c  */
#line 5020 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 5041 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 5046 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 5050 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 5054 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 5066 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5070 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 5082 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5089 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5099 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5103 "Gmsh.y"
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

  case 451:
/* Line 1787 of yacc.c  */
#line 5118 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5123 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5130 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5134 "Gmsh.y"
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

  case 455:
/* Line 1787 of yacc.c  */
#line 5147 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5155 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5166 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5170 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5178 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5184 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5192 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5200 "Gmsh.y"
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

  case 463:
/* Line 1787 of yacc.c  */
#line 5215 "Gmsh.y"
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

  case 464:
/* Line 1787 of yacc.c  */
#line 5229 "Gmsh.y"
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

  case 465:
/* Line 1787 of yacc.c  */
#line 5243 "Gmsh.y"
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

  case 466:
/* Line 1787 of yacc.c  */
#line 5255 "Gmsh.y"
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

  case 467:
/* Line 1787 of yacc.c  */
#line 5271 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5275 "Gmsh.y"
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

  case 469:
/* Line 1787 of yacc.c  */
#line 5294 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5301 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5303 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5314 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5319 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5325 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 5334 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5347 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5350 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11242 "Gmsh.tab.cpp"
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
#line 5354 "Gmsh.y"


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
