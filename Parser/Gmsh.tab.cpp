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
     tOnelabAction = 311,
     tOnelabRun = 312,
     tCpu = 313,
     tMemory = 314,
     tTotalMemory = 315,
     tCreateTopology = 316,
     tCreateTopologyNoHoles = 317,
     tDistanceFunction = 318,
     tDefineConstant = 319,
     tUndefineConstant = 320,
     tDefineNumber = 321,
     tDefineString = 322,
     tPoint = 323,
     tCircle = 324,
     tEllipse = 325,
     tLine = 326,
     tSphere = 327,
     tPolarSphere = 328,
     tSurface = 329,
     tSpline = 330,
     tVolume = 331,
     tCharacteristic = 332,
     tLength = 333,
     tParametric = 334,
     tElliptic = 335,
     tRefineMesh = 336,
     tAdaptMesh = 337,
     tRelocateMesh = 338,
     tPlane = 339,
     tRuled = 340,
     tTransfinite = 341,
     tComplex = 342,
     tPhysical = 343,
     tCompound = 344,
     tPeriodic = 345,
     tUsing = 346,
     tPlugin = 347,
     tDegenerated = 348,
     tRecursive = 349,
     tRotate = 350,
     tTranslate = 351,
     tSymmetry = 352,
     tDilate = 353,
     tExtrude = 354,
     tLevelset = 355,
     tRecombine = 356,
     tSmoother = 357,
     tSplit = 358,
     tDelete = 359,
     tCoherence = 360,
     tIntersect = 361,
     tMeshAlgorithm = 362,
     tReverse = 363,
     tLayers = 364,
     tScaleLast = 365,
     tHole = 366,
     tAlias = 367,
     tAliasWithOptions = 368,
     tCopyOptions = 369,
     tQuadTriAddVerts = 370,
     tQuadTriNoNewVerts = 371,
     tQuadTriSngl = 372,
     tQuadTriDbl = 373,
     tRecombLaterals = 374,
     tTransfQuadTri = 375,
     tText2D = 376,
     tText3D = 377,
     tInterpolationScheme = 378,
     tTime = 379,
     tCombine = 380,
     tBSpline = 381,
     tBezier = 382,
     tNurbs = 383,
     tNurbsOrder = 384,
     tNurbsKnots = 385,
     tColor = 386,
     tColorTable = 387,
     tFor = 388,
     tIn = 389,
     tEndFor = 390,
     tIf = 391,
     tEndIf = 392,
     tExit = 393,
     tAbort = 394,
     tField = 395,
     tReturn = 396,
     tCall = 397,
     tFunction = 398,
     tShow = 399,
     tHide = 400,
     tGetValue = 401,
     tGetEnv = 402,
     tGetString = 403,
     tHomology = 404,
     tCohomology = 405,
     tBetti = 406,
     tSetOrder = 407,
     tExists = 408,
     tFileExists = 409,
     tGMSH_MAJOR_VERSION = 410,
     tGMSH_MINOR_VERSION = 411,
     tGMSH_PATCH_VERSION = 412,
     tAFFECTDIVIDE = 413,
     tAFFECTTIMES = 414,
     tAFFECTMINUS = 415,
     tAFFECTPLUS = 416,
     tOR = 417,
     tAND = 418,
     tNOTEQUAL = 419,
     tEQUAL = 420,
     tGREATEROREQUAL = 421,
     tLESSOREQUAL = 422,
     UNARYPREC = 423,
     tMINUSMINUS = 424,
     tPLUSPLUS = 425
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
#line 397 "Gmsh.tab.cpp"
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
#line 425 "Gmsh.tab.cpp"

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
#define YYLAST   9474

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  191
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  485
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1715

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   425

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   176,     2,   186,     2,   175,     2,     2,
     181,   182,   173,   171,   187,   172,   185,   174,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     167,     2,   168,   162,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   183,     2,   184,   180,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   188,     2,   189,   190,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   163,   164,   165,
     166,   169,   170,   177,   178,   179
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
    2304,  2309,  2311,  2314,  2317,  2321,  2325,  2337,  2347,  2355,
    2363,  2365,  2369,  2371,  2373,  2376,  2380,  2385,  2391,  2393,
    2395,  2398,  2402,  2406,  2412,  2417,  2420,  2423,  2426,  2429,
    2433,  2437,  2441,  2445,  2451,  2457,  2463,  2469,  2486,  2503,
    2520,  2537,  2539,  2541,  2545,  2549,  2554,  2561,  2568,  2570,
    2572,  2576,  2580,  2590,  2598,  2600,  2606,  2610,  2617,  2619,
    2623,  2625,  2627,  2631,  2638,  2640,  2642,  2644,  2649,  2656,
    2661,  2666,  2671,  2680,  2685,  2694,  2699,  2706,  2711,  2712,
    2719,  2721,  2725,  2731,  2737,  2739
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     192,     0,    -1,   193,    -1,     1,     6,    -1,    -1,   193,
     194,    -1,   197,    -1,   196,    -1,   217,    -1,   234,    -1,
     235,    -1,   239,    -1,   240,    -1,   241,    -1,   244,    -1,
     265,    -1,   266,    -1,   243,    -1,   242,    -1,   238,    -1,
     268,    -1,   168,    -1,   168,   168,    -1,    37,   181,   282,
     182,     6,    -1,    38,   181,   282,   182,     6,    -1,    37,
     181,   282,   182,   195,   282,     6,    -1,    37,   181,   282,
     187,   278,   182,     6,    -1,    38,   181,   282,   187,   278,
     182,     6,    -1,    37,   181,   282,   187,   278,   182,   195,
     282,     6,    -1,     4,   282,   188,   198,   189,     6,    -1,
     112,     4,   183,   269,   184,     6,    -1,   113,     4,   183,
     269,   184,     6,    -1,   114,     4,   183,   269,   187,   269,
     184,     6,    -1,    -1,   198,   201,    -1,   198,   205,    -1,
     198,   208,    -1,   198,   210,    -1,   198,   211,    -1,   269,
      -1,   199,   187,   269,    -1,   269,    -1,   200,   187,   269,
      -1,    -1,    -1,     4,   202,   181,   199,   182,   203,   188,
     200,   189,     6,    -1,   282,    -1,   204,   187,   282,    -1,
      -1,   121,   181,   269,   187,   269,   187,   269,   182,   206,
     188,   204,   189,     6,    -1,   282,    -1,   207,   187,   282,
      -1,    -1,   122,   181,   269,   187,   269,   187,   269,   187,
     269,   182,   209,   188,   207,   189,     6,    -1,   123,   188,
     274,   189,   188,   274,   189,     6,    -1,   123,   188,   274,
     189,   188,   274,   189,   188,   274,   189,   188,   274,   189,
       6,    -1,    -1,   124,   212,   188,   200,   189,     6,    -1,
       7,    -1,   161,    -1,   160,    -1,   159,    -1,   158,    -1,
     179,    -1,   178,    -1,   181,    -1,   183,    -1,   182,    -1,
     184,    -1,    64,   183,   219,   184,     6,    -1,    65,   183,
     222,   184,     6,    -1,   287,   213,   275,     6,    -1,     4,
     183,   184,   213,   275,     6,    -1,   286,   183,   184,   213,
     275,     6,    -1,     4,   183,   269,   184,   213,   269,     6,
      -1,     4,   181,   269,   182,   213,   269,     6,    -1,   286,
     183,   269,   184,   213,   269,     6,    -1,     4,   215,   188,
     278,   189,   216,   213,   275,     6,    -1,   286,   215,   188,
     278,   189,   216,   213,   275,     6,    -1,   287,   214,     6,
      -1,     4,   183,   269,   184,   214,     6,    -1,   286,   183,
     269,   184,   214,     6,    -1,   287,     7,   283,     6,    -1,
       4,   185,     4,     7,   283,     6,    -1,     4,   183,   269,
     184,   185,     4,     7,   283,     6,    -1,     4,   185,     4,
     213,   269,     6,    -1,     4,   183,   269,   184,   185,     4,
     213,   269,     6,    -1,     4,   185,     4,   214,     6,    -1,
       4,   183,   269,   184,   185,     4,   214,     6,    -1,     4,
     185,   131,   185,     4,     7,   279,     6,    -1,     4,   183,
     269,   184,   185,   131,   185,     4,     7,   279,     6,    -1,
       4,   185,   132,     7,   280,     6,    -1,     4,   183,   269,
     184,   185,   132,     7,   280,     6,    -1,     4,   140,     7,
     269,     6,    -1,   140,   183,   269,   184,     7,     4,     6,
      -1,   140,   183,   269,   184,   185,     4,     7,   269,     6,
      -1,   140,   183,   269,   184,   185,     4,     7,   283,     6,
      -1,   140,   183,   269,   184,   185,     4,     7,   188,   278,
     189,     6,    -1,   140,   183,   269,   184,   185,     4,     6,
      -1,    92,   181,     4,   182,   185,     4,     7,   269,     6,
      -1,    92,   181,     4,   182,   185,     4,     7,   283,     6,
      -1,    -1,   187,    -1,    -1,   219,   218,   287,    -1,   219,
     218,   287,     7,   269,    -1,    -1,   219,   218,   287,     7,
     188,   269,   220,   224,   189,    -1,   219,   218,   287,     7,
     283,    -1,    -1,   219,   218,   287,     7,   188,   283,   221,
     226,   189,    -1,    -1,   222,   218,   282,    -1,   269,     7,
     283,    -1,   223,   187,   269,     7,   283,    -1,    -1,   224,
     225,    -1,   187,     4,   275,    -1,   187,     4,   188,   223,
     189,    -1,   187,     4,   283,    -1,    -1,   226,   227,    -1,
     187,     4,   269,    -1,   187,     4,   283,    -1,   187,     4,
     188,   285,   189,    -1,   269,    -1,   283,    -1,   269,    -1,
     283,    -1,   269,    -1,   283,    -1,   269,    -1,   283,    -1,
      -1,   134,    72,   188,   269,   189,    -1,    -1,    84,   272,
      -1,    68,   181,   269,   182,     7,   272,     6,    -1,    88,
      68,   181,   228,   182,   213,   275,     6,    -1,    77,    78,
     275,     7,   269,     6,    -1,    71,   181,   269,   182,     7,
     275,     6,    -1,    93,    71,   275,     6,    -1,    75,   181,
     269,   182,     7,   275,     6,    -1,    69,   181,   269,   182,
       7,   275,   233,     6,    -1,    70,   181,   269,   182,     7,
     275,   233,     6,    -1,   126,   181,   269,   182,     7,   275,
       6,    -1,   127,   181,   269,   182,     7,   275,     6,    -1,
     128,   181,   269,   182,     7,   275,   130,   275,   129,   269,
       6,    -1,    71,     4,   181,   269,   182,     7,   275,     6,
      -1,    89,    71,   181,   269,   182,     7,   275,     6,    -1,
      88,    71,   181,   229,   182,   213,   275,     6,    -1,    84,
      74,   181,   269,   182,     7,   275,     6,    -1,    85,    74,
     181,   269,   182,     7,   275,   232,     6,    -1,    12,    13,
       6,    -1,    13,    74,   269,     6,    -1,    79,    74,   181,
     269,   182,     7,     5,     5,     5,     6,    -1,    72,   181,
     269,   182,     7,   275,     6,    -1,    73,   181,   269,   182,
       7,   275,     6,    -1,    74,     4,   181,   269,   182,     7,
     275,     6,    -1,    89,    74,   181,   269,   182,     7,   275,
       6,    -1,    89,    74,   181,   269,   182,     7,   275,     4,
     188,   274,   189,     6,    -1,    88,    74,   181,   230,   182,
     213,   275,     6,    -1,    87,    76,   181,   269,   182,     7,
     275,     6,    -1,    76,   181,   269,   182,     7,   275,     6,
      -1,    89,    76,   181,   269,   182,     7,   275,     6,    -1,
      88,    76,   181,   231,   182,   213,   275,     6,    -1,    96,
     272,   188,   236,   189,    -1,    95,   188,   272,   187,   272,
     187,   269,   189,   188,   236,   189,    -1,    97,   272,   188,
     236,   189,    -1,    98,   188,   272,   187,   269,   189,   188,
     236,   189,    -1,    98,   188,   272,   187,   272,   189,   188,
     236,   189,    -1,     4,   188,   236,   189,    -1,   106,    71,
     188,   278,   189,    74,   188,   269,   189,    -1,   103,    71,
     181,   269,   182,   188,   278,   189,     6,    -1,   237,    -1,
     235,    -1,    -1,   237,   234,    -1,   237,    68,   188,   278,
     189,     6,    -1,   237,    71,   188,   278,   189,     6,    -1,
     237,    74,   188,   278,   189,     6,    -1,   237,    76,   188,
     278,   189,     6,    -1,   100,    84,   181,   269,   182,     7,
     275,     6,    -1,   100,    68,   181,   269,   182,     7,   188,
     274,   189,     6,    -1,   100,    84,   181,   269,   182,     7,
     188,   272,   187,   272,   187,   278,   189,     6,    -1,   100,
      84,   181,   269,   182,     7,   188,   272,   187,   272,   187,
     272,   187,   278,   189,     6,    -1,   100,    72,   181,   269,
     182,     7,   188,   272,   187,   278,   189,     6,    -1,   100,
       4,   181,   269,   182,     7,   275,     6,    -1,   100,     4,
     181,   269,   182,     7,     5,     6,    -1,   100,     4,   188,
     269,   189,     6,    -1,   100,     4,   181,   269,   182,     7,
     188,   272,   187,   272,   187,   278,   189,     6,    -1,   104,
     188,   237,   189,    -1,   104,   140,   183,   269,   184,     6,
      -1,   104,     4,   183,   269,   184,     6,    -1,   104,     4,
       6,    -1,   104,     4,     4,     6,    -1,   131,   279,   188,
     237,   189,    -1,    94,   131,   279,   188,   237,   189,    -1,
     144,     5,     6,    -1,   145,     5,     6,    -1,   144,   188,
     237,   189,    -1,    94,   144,   188,   237,   189,    -1,   145,
     188,   237,   189,    -1,    94,   145,   188,   237,   189,    -1,
       4,   283,     6,    -1,    57,   181,   285,   182,     6,    -1,
       4,     4,   183,   269,   184,   282,     6,    -1,     4,     4,
       4,   183,   269,   184,     6,    -1,     4,   269,     6,    -1,
      92,   181,     4,   182,   185,     4,     6,    -1,   125,     4,
       6,    -1,   138,     6,    -1,   139,     6,    -1,    55,     6,
      -1,    50,     6,    -1,    50,   188,   269,   187,   269,   187,
     269,   187,   269,   187,   269,   187,   269,   189,     6,    -1,
      51,     6,    -1,    52,     6,    -1,    61,     6,    -1,    62,
       6,    -1,    81,     6,    -1,    82,   188,   278,   189,   188,
     278,   189,   188,   274,   189,   188,   269,   187,   269,   189,
       6,    -1,   152,   269,     6,    -1,   133,   181,   269,     8,
     269,   182,    -1,   133,   181,   269,     8,   269,     8,   269,
     182,    -1,   133,     4,   134,   188,   269,     8,   269,   189,
      -1,   133,     4,   134,   188,   269,     8,   269,     8,   269,
     189,    -1,   135,    -1,   143,     4,    -1,   141,    -1,   142,
     287,     6,    -1,   136,   181,   269,   182,    -1,   137,    -1,
      99,   272,   188,   237,   189,    -1,    99,   188,   272,   187,
     272,   187,   269,   189,   188,   237,   189,    -1,    99,   188,
     272,   187,   272,   187,   272,   187,   269,   189,   188,   237,
     189,    -1,    -1,    99,   272,   188,   237,   245,   258,   189,
      -1,    -1,    99,   188,   272,   187,   272,   187,   269,   189,
     188,   237,   246,   258,   189,    -1,    -1,    99,   188,   272,
     187,   272,   187,   272,   187,   269,   189,   188,   237,   247,
     258,   189,    -1,    -1,    99,   188,   237,   248,   258,   189,
      -1,    99,    68,   188,   269,   187,   272,   189,     6,    -1,
      99,    71,   188,   269,   187,   272,   189,     6,    -1,    99,
      74,   188,   269,   187,   272,   189,     6,    -1,    99,    68,
     188,   269,   187,   272,   187,   272,   187,   269,   189,     6,
      -1,    99,    71,   188,   269,   187,   272,   187,   272,   187,
     269,   189,     6,    -1,    99,    74,   188,   269,   187,   272,
     187,   272,   187,   269,   189,     6,    -1,    99,    68,   188,
     269,   187,   272,   187,   272,   187,   272,   187,   269,   189,
       6,    -1,    99,    71,   188,   269,   187,   272,   187,   272,
     187,   272,   187,   269,   189,     6,    -1,    99,    74,   188,
     269,   187,   272,   187,   272,   187,   272,   187,   269,   189,
       6,    -1,    -1,    99,    68,   188,   269,   187,   272,   189,
     249,   188,   258,   189,     6,    -1,    -1,    99,    71,   188,
     269,   187,   272,   189,   250,   188,   258,   189,     6,    -1,
      -1,    99,    74,   188,   269,   187,   272,   189,   251,   188,
     258,   189,     6,    -1,    -1,    99,    68,   188,   269,   187,
     272,   187,   272,   187,   269,   189,   252,   188,   258,   189,
       6,    -1,    -1,    99,    71,   188,   269,   187,   272,   187,
     272,   187,   269,   189,   253,   188,   258,   189,     6,    -1,
      -1,    99,    74,   188,   269,   187,   272,   187,   272,   187,
     269,   189,   254,   188,   258,   189,     6,    -1,    -1,    99,
      68,   188,   269,   187,   272,   187,   272,   187,   272,   187,
     269,   189,   255,   188,   258,   189,     6,    -1,    -1,    99,
      71,   188,   269,   187,   272,   187,   272,   187,   272,   187,
     269,   189,   256,   188,   258,   189,     6,    -1,    -1,    99,
      74,   188,   269,   187,   272,   187,   272,   187,   272,   187,
     269,   189,   257,   188,   258,   189,     6,    -1,   259,    -1,
     258,   259,    -1,   109,   188,   269,   189,     6,    -1,   109,
     188,   275,   187,   275,   189,     6,    -1,   109,   188,   275,
     187,   275,   187,   275,   189,     6,    -1,   110,     6,    -1,
     101,     6,    -1,   117,     6,    -1,   117,   119,     6,    -1,
     118,     6,    -1,   118,   119,     6,    -1,   115,     6,    -1,
     115,   119,     6,    -1,   116,     6,    -1,   116,   119,     6,
      -1,   111,   181,   269,   182,     7,   275,    91,   269,     6,
      -1,    91,     4,   183,   269,   184,     6,    -1,    -1,    91,
       4,   269,    -1,    -1,     4,    -1,    -1,     7,   275,    -1,
      -1,     7,   269,    -1,    -1,    91,   275,    -1,    86,    71,
     276,     7,   269,   260,     6,    -1,    86,    74,   276,   262,
     261,     6,    -1,    80,    74,   188,   269,   189,     7,   275,
       6,    -1,    86,    76,   276,   262,     6,    -1,   120,   276,
       6,    -1,   107,    74,   188,   278,   189,   269,     6,    -1,
     101,    74,   276,   263,     6,    -1,   101,    76,   276,     6,
      -1,   102,    74,   275,     7,   269,     6,    -1,    90,    71,
     275,     7,   275,     6,    -1,    90,    74,   269,   188,   278,
     189,     7,   269,   188,   278,   189,   264,     6,    -1,    68,
     188,   278,   189,   134,    74,   188,   269,   189,     6,    -1,
      71,   188,   278,   189,   134,    74,   188,   269,   189,     6,
      -1,    68,   188,   278,   189,   134,    76,   188,   269,   189,
       6,    -1,    71,   188,   278,   189,   134,    76,   188,   269,
     189,     6,    -1,    74,   188,   278,   189,   134,    76,   188,
     269,   189,     6,    -1,   108,    74,   276,     6,    -1,   108,
      71,   276,     6,    -1,    83,    68,   276,     6,    -1,    83,
      71,   276,     6,    -1,    83,    74,   276,     6,    -1,   105,
       6,    -1,   105,     4,     6,    -1,   105,    68,   188,   278,
     189,     6,    -1,   149,    -1,   150,    -1,   151,    -1,   267,
       6,    -1,   267,   188,   275,   189,     6,    -1,   267,   188,
     275,   187,   275,   189,     6,    -1,   267,   181,   275,   182,
     188,   275,   187,   275,   189,     6,    -1,   270,    -1,   181,
     269,   182,    -1,   172,   269,    -1,   171,   269,    -1,   176,
     269,    -1,   269,   172,   269,    -1,   269,   171,   269,    -1,
     269,   173,   269,    -1,   269,   174,   269,    -1,   269,   175,
     269,    -1,   269,   180,   269,    -1,   269,   167,   269,    -1,
     269,   168,   269,    -1,   269,   170,   269,    -1,   269,   169,
     269,    -1,   269,   166,   269,    -1,   269,   165,   269,    -1,
     269,   164,   269,    -1,   269,   163,   269,    -1,   269,   162,
     269,     8,   269,    -1,    14,   215,   269,   216,    -1,    15,
     215,   269,   216,    -1,    16,   215,   269,   216,    -1,    17,
     215,   269,   216,    -1,    18,   215,   269,   216,    -1,    19,
     215,   269,   216,    -1,    20,   215,   269,   216,    -1,    21,
     215,   269,   216,    -1,    22,   215,   269,   216,    -1,    24,
     215,   269,   216,    -1,    25,   215,   269,   187,   269,   216,
      -1,    26,   215,   269,   216,    -1,    27,   215,   269,   216,
      -1,    28,   215,   269,   216,    -1,    29,   215,   269,   216,
      -1,    30,   215,   269,   216,    -1,    31,   215,   269,   216,
      -1,    32,   215,   269,   216,    -1,    33,   215,   269,   187,
     269,   216,    -1,    34,   215,   269,   187,   269,   216,    -1,
      35,   215,   269,   187,   269,   216,    -1,    23,   215,   269,
     216,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     155,    -1,   156,    -1,   157,    -1,    58,    -1,    59,    -1,
      60,    -1,    -1,    66,   215,   269,   271,   224,   216,    -1,
     287,    -1,     4,   183,   269,   184,    -1,   286,   183,   269,
     184,    -1,   153,   181,   287,   182,    -1,   154,   181,   283,
     182,    -1,   186,   287,   183,   184,    -1,   287,   214,    -1,
       4,   183,   269,   184,   214,    -1,   286,   183,   269,   184,
     214,    -1,     4,   185,     4,    -1,     4,   183,   269,   184,
     185,     4,    -1,     4,   185,     4,   214,    -1,     4,   183,
     269,   184,   185,     4,   214,    -1,   146,   181,   282,   187,
     269,   182,    -1,    45,   181,   275,   187,   275,   182,    -1,
      46,   181,   282,   187,   282,   182,    -1,    47,   181,   282,
     187,   282,   182,    -1,    49,   181,   285,   182,    -1,   273,
      -1,   172,   272,    -1,   171,   272,    -1,   272,   172,   272,
      -1,   272,   171,   272,    -1,   188,   269,   187,   269,   187,
     269,   187,   269,   187,   269,   189,    -1,   188,   269,   187,
     269,   187,   269,   187,   269,   189,    -1,   188,   269,   187,
     269,   187,   269,   189,    -1,   181,   269,   187,   269,   187,
     269,   182,    -1,   275,    -1,   274,   187,   275,    -1,   269,
      -1,   277,    -1,   188,   189,    -1,   188,   278,   189,    -1,
     172,   188,   278,   189,    -1,   269,   173,   188,   278,   189,
      -1,   275,    -1,     5,    -1,   172,   277,    -1,   269,   173,
     277,    -1,   269,     8,   269,    -1,   269,     8,   269,     8,
     269,    -1,    68,   188,   269,   189,    -1,    68,     5,    -1,
      71,     5,    -1,    74,     5,    -1,    76,     5,    -1,    88,
      68,     5,    -1,    88,    71,     5,    -1,    88,    74,     5,
      -1,    88,    76,     5,    -1,    88,    68,   188,   278,   189,
      -1,    88,    71,   188,   278,   189,    -1,    88,    74,   188,
     278,   189,    -1,    88,    76,   188,   278,   189,    -1,    68,
     134,    50,   188,   269,   187,   269,   187,   269,   187,   269,
     187,   269,   187,   269,   189,    -1,    71,   134,    50,   188,
     269,   187,   269,   187,   269,   187,   269,   187,   269,   187,
     269,   189,    -1,    74,   134,    50,   188,   269,   187,   269,
     187,   269,   187,   269,   187,   269,   187,   269,   189,    -1,
      76,   134,    50,   188,   269,   187,   269,   187,   269,   187,
     269,   187,   269,   187,   269,   189,    -1,   235,    -1,   244,
      -1,     4,   215,   216,    -1,   286,   215,   216,    -1,    36,
     183,   287,   184,    -1,     4,   215,   188,   278,   189,   216,
      -1,   286,   215,   188,   278,   189,   216,    -1,   269,    -1,
     277,    -1,   278,   187,   269,    -1,   278,   187,   277,    -1,
     188,   269,   187,   269,   187,   269,   187,   269,   189,    -1,
     188,   269,   187,   269,   187,   269,   189,    -1,     4,    -1,
       4,   185,   131,   185,     4,    -1,   188,   281,   189,    -1,
       4,   183,   269,   184,   185,   132,    -1,   279,    -1,   281,
     187,   279,    -1,   283,    -1,   287,    -1,     4,   185,     4,
      -1,     4,   183,   269,   184,   185,     4,    -1,     5,    -1,
      53,    -1,    56,    -1,   147,   181,   282,   182,    -1,   148,
     181,   282,   187,   282,   182,    -1,    41,   215,   285,   216,
      -1,    42,   181,   282,   182,    -1,    43,   181,   282,   182,
      -1,    44,   181,   282,   187,   282,   187,   282,   182,    -1,
      39,   215,   285,   216,    -1,    48,   215,   269,   187,   283,
     187,   283,   216,    -1,    40,   215,   282,   216,    -1,    40,
     215,   282,   187,   278,   216,    -1,    54,   215,   282,   216,
      -1,    -1,    67,   215,   283,   284,   226,   216,    -1,   282,
      -1,   285,   187,   282,    -1,     4,   190,   188,   269,   189,
      -1,   286,   190,   188,   269,   189,    -1,     4,    -1,   286,
      -1
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
    1296,  1305,  1309,  1319,  1322,  1335,  1338,  1348,  1371,  1403,
    1426,  1444,  1465,  1483,  1513,  1543,  1561,  1579,  1606,  1624,
    1642,  1677,  1695,  1734,  1740,  1746,  1753,  1778,  1803,  1820,
    1839,  1873,  1909,  1927,  1944,  1960,  1997,  2002,  2007,  2012,
    2017,  2022,  2045,  2051,  2062,  2063,  2068,  2071,  2075,  2098,
    2121,  2144,  2172,  2193,  2219,  2240,  2262,  2282,  2394,  2413,
    2451,  2560,  2569,  2575,  2590,  2618,  2635,  2644,  2658,  2664,
    2670,  2679,  2688,  2697,  2711,  2767,  2785,  2802,  2817,  2836,
    2848,  2872,  2876,  2881,  2888,  2894,  2899,  2905,  2913,  2917,
    2921,  2926,  2981,  2994,  3011,  3028,  3049,  3070,  3105,  3113,
    3119,  3126,  3130,  3139,  3147,  3155,  3164,  3163,  3178,  3177,
    3192,  3191,  3206,  3205,  3219,  3226,  3233,  3240,  3247,  3254,
    3261,  3268,  3275,  3283,  3282,  3296,  3295,  3309,  3308,  3322,
    3321,  3335,  3334,  3348,  3347,  3361,  3360,  3374,  3373,  3387,
    3386,  3403,  3406,  3412,  3424,  3444,  3468,  3472,  3476,  3480,
    3484,  3490,  3496,  3500,  3504,  3508,  3512,  3531,  3544,  3547,
    3563,  3566,  3583,  3586,  3592,  3595,  3602,  3605,  3612,  3668,
    3738,  3743,  3810,  3846,  3854,  3897,  3936,  3956,  3983,  4032,
    4060,  4088,  4092,  4096,  4124,  4163,  4202,  4223,  4244,  4271,
    4275,  4285,  4320,  4321,  4322,  4326,  4332,  4344,  4362,  4390,
    4391,  4392,  4393,  4394,  4395,  4396,  4397,  4398,  4405,  4406,
    4407,  4408,  4409,  4410,  4411,  4412,  4413,  4414,  4415,  4416,
    4417,  4418,  4419,  4420,  4421,  4422,  4423,  4424,  4425,  4426,
    4427,  4428,  4429,  4430,  4431,  4432,  4433,  4434,  4435,  4436,
    4437,  4446,  4447,  4448,  4449,  4450,  4451,  4452,  4453,  4454,
    4455,  4460,  4459,  4467,  4484,  4502,  4520,  4525,  4531,  4543,
    4560,  4578,  4599,  4604,  4609,  4619,  4629,  4634,  4645,  4654,
    4659,  4686,  4690,  4694,  4698,  4702,  4709,  4713,  4717,  4721,
    4728,  4733,  4740,  4745,  4749,  4754,  4758,  4766,  4777,  4781,
    4793,  4801,  4809,  4816,  4826,  4855,  4859,  4863,  4867,  4871,
    4875,  4879,  4883,  4887,  4916,  4945,  4974,  5003,  5016,  5029,
    5042,  5055,  5065,  5075,  5087,  5099,  5111,  5129,  5150,  5155,
    5159,  5163,  5175,  5179,  5191,  5198,  5208,  5212,  5227,  5232,
    5239,  5243,  5256,  5264,  5275,  5279,  5287,  5293,  5301,  5309,
    5324,  5338,  5352,  5364,  5380,  5391,  5395,  5414,  5422,  5421,
    5434,  5439,  5445,  5454,  5467,  5470
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
  "tSetChanged", "tToday", "tFixRelativePath", "tSyncModel",
  "tOnelabAction", "tOnelabRun", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineString",
  "tPoint", "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh",
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
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
     415,   416,    63,   417,   418,   419,   420,    60,    62,   421,
     422,    43,    45,    42,    47,    37,    33,   423,   424,   425,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   191,   192,   192,   193,   193,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   196,   196,   196,   196,   197,
     197,   197,   197,   198,   198,   198,   198,   198,   198,   199,
     199,   200,   200,   202,   203,   201,   204,   204,   206,   205,
     207,   207,   209,   208,   210,   210,   212,   211,   213,   213,
     213,   213,   213,   214,   214,   215,   215,   216,   216,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   218,   218,   219,   219,   219,   220,   219,   219,   221,
     219,   222,   222,   223,   223,   224,   224,   225,   225,   225,
     226,   226,   227,   227,   227,   228,   228,   229,   229,   230,
     230,   231,   231,   232,   232,   233,   233,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   235,   235,   235,   235,
     235,   235,   235,   235,   236,   236,   237,   237,   237,   237,
     237,   237,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   239,   239,   239,   239,   239,   240,   240,   241,   241,
     241,   241,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   244,   244,   244,   245,   244,   246,   244,
     247,   244,   248,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   249,   244,   250,   244,   251,   244,   252,
     244,   253,   244,   254,   244,   255,   244,   256,   244,   257,
     244,   258,   258,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   260,   260,
     261,   261,   262,   262,   263,   263,   264,   264,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   266,
     266,   266,   267,   267,   267,   268,   268,   268,   268,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   272,   272,   272,   272,   272,   273,   273,   273,   273,
     274,   274,   275,   275,   275,   275,   275,   275,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   278,   278,
     278,   278,   279,   279,   279,   279,   280,   280,   281,   281,
     282,   282,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   284,   283,
     285,   285,   286,   286,   287,   287
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
       5,     5,     3,     6,     4,     7,     6,     6,     6,     6,
       4,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     1,
       2,     3,     3,     5,     4,     2,     2,     2,     2,     3,
       3,     3,     3,     5,     5,     5,     5,    16,    16,    16,
      16,     1,     1,     3,     3,     4,     6,     6,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     3,     6,     1,     1,     1,     4,     6,     4,
       4,     4,     8,     4,     8,     4,     6,     4,     0,     6,
       1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   232,     0,     0,     0,   229,     0,     0,     0,     0,
     322,   323,   324,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   485,     0,   371,   484,   464,   372,   373,   374,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   465,     0,   466,   378,   379,   380,     0,     0,
       0,     0,     0,     0,     0,     0,   375,   376,   377,     0,
       0,     0,    65,    66,     0,     0,   176,     0,     0,     0,
     329,     0,   460,   485,   383,     0,     0,     0,     0,   214,
       0,   216,   217,   213,     0,   218,   219,   103,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,   319,     0,     0,     0,
       0,     0,     0,     0,     0,   484,   419,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,   442,   412,   418,
       0,   413,   485,   383,     0,     0,     0,     0,   454,     0,
       0,     0,     0,     0,   211,   212,     0,   484,   485,     0,
     228,     0,   176,     0,   176,   484,     0,   325,     0,     0,
      65,    66,     0,     0,    58,    62,    61,    60,    59,    64,
      63,     0,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
     331,   333,     0,     0,     0,     0,     0,     0,     0,     0,
     175,     0,   174,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,   204,     0,   389,   153,     0,   484,     0,   460,
     461,     0,     0,   480,     0,   101,   101,     0,     0,   448,
     449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   176,
       0,   403,   402,     0,     0,     0,     0,   176,   176,     0,
       0,     0,     0,     0,     0,     0,   242,     0,   176,     0,
       0,     0,     0,     0,   294,     0,     0,     0,     0,   194,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,   425,     0,     0,   426,
       0,   427,     0,   428,     0,     0,     0,     0,     0,     0,
     331,   420,     0,   414,     0,     0,     0,   302,    66,     0,
     210,     0,     0,     0,     0,     0,   176,     0,     0,     0,
       0,   230,   198,     0,   199,     0,     0,   222,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   381,   478,     0,     0,     0,     0,
       0,     0,   330,    58,     0,     0,    58,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,   177,     0,     0,
       0,   347,   346,   345,   344,   340,   341,   343,   342,   335,
     334,   336,   337,   338,   339,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,   317,   318,     0,     0,     0,     0,   290,     0,
       0,     0,   125,   126,     0,   127,   128,     0,   129,   130,
       0,   131,   132,     0,     0,     0,     0,     0,     0,   141,
     176,     0,     0,     0,     0,     0,   405,   404,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,   195,     0,
       0,   191,     0,     0,     0,   315,   314,     0,     0,     0,
       0,   392,    67,    68,     0,   443,     0,     0,     0,     0,
       0,     0,   429,     0,   430,     0,   431,     0,   432,     0,
       0,   330,   415,   422,     0,   336,   421,     0,   444,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,   200,
     202,     0,     0,     0,     0,     0,     0,     0,    82,    71,
       0,   384,   394,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   370,   358,     0,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,   473,     0,   475,   469,   470,
     471,     0,     0,     0,     0,     0,   400,   477,   115,   120,
      93,     0,   467,     0,   386,   387,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,   388,     0,
       0,     0,     0,   482,     0,     0,    43,     0,     0,     0,
      56,     0,    34,    35,    36,    37,    38,   385,     0,   462,
      23,    21,     0,     0,    24,     0,     0,   205,   481,    69,
     104,    70,   112,     0,   450,   451,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   288,   293,   291,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   203,     0,     0,     0,   166,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,   233,     0,     0,     0,     0,
       0,     0,   295,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   384,     0,   445,     0,   424,     0,
       0,     0,     0,     0,     0,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,     0,   326,     0,     0,     0,   483,     0,     0,     0,
     390,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,     0,
       0,     0,    80,    83,    85,     0,     0,   458,     0,    91,
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
       0,     0,   433,   434,   435,   436,   423,   417,     0,     0,
       0,     0,   455,     0,     0,     0,   223,     0,     0,     0,
       0,    73,     0,    81,     0,   207,   393,   206,   359,   367,
     368,   369,   476,     0,   397,   398,   399,     0,     0,   382,
     116,     0,   479,   121,   396,   468,    75,    58,     0,     0,
       0,     0,    74,     0,     0,     0,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,     0,     0,    25,
      26,     0,    27,     0,     0,   105,   108,   137,     0,     0,
       0,     0,     0,     0,   140,     0,     0,   156,   157,     0,
       0,   142,   163,     0,     0,     0,     0,   133,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,     0,     0,   176,   176,     0,   253,     0,   255,
       0,   257,     0,   412,     0,     0,   283,   285,   279,   281,
       0,     0,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,     0,   393,   446,     0,     0,     0,     0,
     447,   145,   146,     0,     0,     0,     0,    94,    98,     0,
       0,   327,    76,     0,   395,     0,     0,     0,     0,     0,
       0,    88,     0,     0,    89,     0,   459,   178,   179,   180,
     181,     0,     0,    39,     0,     0,     0,     0,     0,    41,
     463,     0,     0,   106,   109,     0,     0,   136,   143,   144,
     148,     0,     0,   158,     0,     0,   300,     0,   151,     0,
       0,   289,   162,   138,   150,   161,   165,   149,     0,   159,
     164,     0,     0,     0,     0,   409,     0,   408,     0,     0,
       0,   244,     0,     0,   245,     0,     0,   246,     0,     0,
       0,     0,     0,     0,     0,   188,     0,     0,   187,     0,
       0,     0,   182,     0,     0,    32,     0,     0,     0,     0,
       0,     0,   453,     0,   225,   224,     0,     0,     0,     0,
       0,   472,   474,     0,   117,   119,     0,   122,   123,    84,
      86,     0,    92,     0,    77,    44,     0,     0,     0,   411,
       0,     0,     0,    28,     0,   115,   120,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,    99,   100,
     176,     0,   169,   170,     0,     0,     0,     0,     0,     0,
       0,   273,     0,     0,   176,     0,     0,     0,     0,     0,
     173,   172,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,    78,     0,   448,     0,     0,   457,     0,
      40,     0,     0,     0,    42,    57,     0,     0,     0,   309,
     311,   310,   312,   313,   155,     0,     0,     0,     0,     0,
       0,   407,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,   238,     0,     0,   183,     0,
       0,     0,     0,     0,     0,     0,   452,   226,     0,   328,
       0,   118,     0,   124,    90,     0,     0,     0,     0,     0,
     107,   110,     0,     0,     0,   296,   167,     0,   259,     0,
       0,   261,     0,     0,   263,     0,     0,     0,   274,     0,
     234,     0,   176,     0,     0,     0,     0,     0,     0,     0,
     147,    97,     0,   113,     0,    48,     0,    54,     0,     0,
       0,   134,   160,     0,     0,   406,   247,     0,     0,   254,
     248,     0,     0,   256,   249,     0,     0,   258,     0,     0,
       0,   240,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,   308,     0,
     265,     0,   267,     0,   269,   275,   286,   239,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   114,    45,     0,
      52,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,     0,   190,     0,   184,     0,     0,     0,
       0,     0,    46,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   221,   260,     0,   262,     0,   264,     0,
     185,     0,     0,     0,     0,    47,    49,     0,    50,     0,
       0,     0,     0,   437,   438,   439,   440,     0,     0,    55,
     266,   268,   270,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   872,    85,    86,   635,  1312,  1318,
     862,  1036,  1479,  1661,   863,  1612,  1697,   864,  1663,   865,
     866,  1040,   321,   404,   168,   745,    87,   649,   415,  1425,
    1426,   416,  1474,  1012,  1170,  1013,  1173,   681,   684,   687,
     690,  1340,  1211,   617,   276,   381,   382,    90,    91,    92,
      93,    94,    95,   277,   946,  1561,  1629,   715,  1362,  1365,
    1368,  1587,  1591,  1595,  1646,  1649,  1652,   942,   943,  1072,
     907,   678,   724,  1584,    97,    98,    99,   100,   278,   170,
     828,   462,   236,  1195,   279,   280,   281,   524,   290,   847,
    1028,   413,   409,   829,   414,   173,   283
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1266
static const yytype_int16 yypact[] =
{
    6317,    59,    44,  6434, -1266, -1266,  3274,   119,   -55,   -39,
     -25,    39,   158,   202,   212,    78,   283,   297,   172,   188,
    -148,   197,   221,     2,   240,   243,    14,   250,   253,   315,
     372,   378,   456,   270,   342,   406,   416,    22,   445,   246,
     329,   102,   360,   460,   -54,   361,   123,   123,   400,   338,
      63,    72,   483,   529,    13,    21,   554,   558,   120,   624,
     631,   638,  4042,   655,   484,   507,   514,    26,    56, -1266,
     524, -1266,   646,   678,   528, -1266,   665,   713,    31,    33,
   -1266, -1266, -1266,  6180, -1266, -1266, -1266, -1266, -1266, -1266,
   -1266, -1266, -1266, -1266, -1266, -1266, -1266, -1266, -1266,     5,
   -1266,  -126,    90, -1266,    -1, -1266, -1266, -1266, -1266,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   543,   597,   602,   621,   633,   653,
     -62,   658, -1266,   -62, -1266, -1266, -1266, -1266,   -62,   -62,
     739,   661,   670,   682,   685,   707, -1266, -1266, -1266,  6180,
    6180,  6180,  6180,   995,     8,   665,    62,   694,   770,   163,
   -1266,   771,   790,  -115,   -34,   889,  6180,   550,   550, -1266,
    6180, -1266, -1266, -1266,   550, -1266, -1266, -1266, -1266,  6180,
    5953,  6180,  6180,   721,  6180,  5953,  6180,  6180,   734,  5953,
    6180,  6180,  4821,   801,   788, -1266,  5953,  4042,  4042,  4042,
     816,   819,  4042,  4042,  4042,   826,   827,   850,   851,   852,
     853,   854,   856,  4821,  6180,   805,  4821,    26,   855,   857,
     123,   123,   123,  6180,  6180,   -77, -1266,   127,   123,   858,
     859,   860,  5721,   251,   131,   868,   876,   878,  4042,  4042,
    4821,   879,    52,   880, -1266,  1032, -1266,   877,   881,   882,
    4042,  4042,   885,   896,   897,   570, -1266,   898,    29,    15,
      16,    17,   615,  5001,  6180,  3675, -1266, -1266,  3455, -1266,
    1033, -1266,   -11,   166,  1076,  6180,  6180,  6180,   899,  6180,
     903,   958,  6180,  6180, -1266, -1266,  6180,   905,   906,  1091,
   -1266,  1092, -1266,  1095, -1266,   -98,  1152, -1266,  4821,  4821,
   -1266,  6127,   915,   916,  1478, -1266, -1266, -1266, -1266, -1266,
   -1266,  4821,  1099,   923,  6180,  1103, -1266,  6180,  6180,  6180,
    6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,
    6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,   550,
     550,   550,   550,   550,   550,  4821,   550,   550,  6180,   550,
     550,  6180,  1478,  6180,   550,   550,   550,   665,  1478,   930,
     930,   930,  8580,   237,  8235,   229,   926,  1122,   947,   943,
   -1266,   945,  4246,  6180,  5953, -1266,  6180,  6180,  6180,  6180,
    6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,  6180,
    6180, -1266, -1266,  6180, -1266, -1266,  1301,    -5,   352, -1266,
   -1266,   369,  3314, -1266,   449,   195,   227,  8601,  5953,  3623,
   -1266,   -51,  8622,  8643,  6180,  8664,   272,  8685,  8706,  6180,
     319,  8727,  8748,  1125,  6180,  6180,   333,  1130,  1131,  1132,
    6180,  6180,  1133,  1135,  1135,  6180,  5779,  5779,  5779,  5779,
    6180,  6180,  6180,  1136,  6985,   957,  1138,   959, -1266, -1266,
     -88, -1266, -1266,  7065,  7091,   123,   123,    62,    62,   137,
    6180,  6180,  6180,  5721,  5721,  6180,  4246,   196, -1266,  6180,
    6180,  6180,  6180,  6180,  1139,  1147,  1148,  6180,  1150, -1266,
    6180,  6180,  1352, -1266,  5953,  5953,  5953,  1151,  1153,  6180,
    6180,  6180,  6180,  1141,   434,   665, -1266,  1104,  6180, -1266,
    1111, -1266,  1112, -1266,  1113,    34,    36,    37,    38,  5953,
     930, -1266,  8769, -1266,   391,  6180,  5181, -1266,  6180,   488,
   -1266,  8790,  8811,  8832,  1034,  7117, -1266,   976,  3642,  8853,
    8258, -1266, -1266,  1517, -1266,  1867,  6180, -1266,   986,   452,
     237,  8281,  6180,  5953,  1163,  1164, -1266,  6180,  8304,   213,
    4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,
    4128,  7143,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  7169,
    7195,  7221,   106,   395,   106,   990,   991,   988,   993,   998,
    1002,  7247,   471,    81,  9294, -1266,  1625,  1003,   996,  1004,
    1000,  1013,   237, -1266,  4821,   181,  1478,  6180,  1171,  1193,
      27,  1015, -1266,   135,    19,    28,   177, -1266,  4551,   486,
    3810,   754,  1333,   769,   769,   565,   565,   565,   565,   540,
     540,   930,   930,   930,   930,     6,  8327, -1266,  6180,  1196,
      45,  5953,  1198,  5953,  6180,  1199,   550,  1200, -1266,   665,
    1201,   550,  1195,  5953,  5953,  1074,  1202,  1205,  8874,  1206,
    1080,  1208,  1209,  8895,  1083,  1212,  1213,  6180,  8916,  4610,
    1035, -1266, -1266, -1266,  8937,  8958,  6180,  4821,  1218,  1220,
    8979,  1045,  9294, -1266,  1047,  9294, -1266,  1048,  9294, -1266,
    1050,  9294, -1266,  9000,  9021,  9042,  4821,  5953,  1049, -1266,
   -1266,  2020,  2143,   123,  6180,  6180, -1266, -1266,  1051,  1052,
    5721,  7273,  7299,  7325,  7039,   366,   123,  2344,  9063,  4766,
    9084,  9105,  9126,  6180,  1230, -1266,  6180,  9147, -1266,  8350,
    8373, -1266,   534,   560,   578, -1266, -1266,  8396,  8419,  7351,
    8442,   166, -1266, -1266,  5953, -1266,  1053,  1054,  4946,  1056,
    1057,  1061, -1266,  5953, -1266,  5953, -1266,  5953, -1266,  5953,
     581, -1266, -1266,  3831,  5953,   930, -1266,  5953, -1266,  1228,
    1231,  1247,  1077,  6180,  2513,  6180,  6180, -1266,    43, -1266,
   -1266,  1078,  4821,  1263,  4821,   259,  5126,   584, -1266, -1266,
    8465,  1046, -1266, -1266, -1266, -1266, -1266, -1266, -1266, -1266,
   -1266, -1266, -1266, -1266,  6180, -1266, -1266, -1266, -1266, -1266,
   -1266, -1266,  6180,  6180,  6180, -1266,  5953, -1266, -1266, -1266,
   -1266,   550,  4821,   550,   550,  1478, -1266, -1266, -1266, -1266,
   -1266,  6180, -1266,   550, -1266, -1266,  6180,  1265,   130,  6180,
    1268,  1269,  1664, -1266,  1271,  1093,    26,  1273, -1266,  5953,
    5953,  5953,  5953, -1266,    81,  6180, -1266,  1100,  1101,  1096,
   -1266,  1279, -1266, -1266, -1266, -1266, -1266,   166,  8488, -1266,
   -1266,  1118,   550,   503, -1266,   517,  7377, -1266, -1266, -1266,
    1281, -1266, -1266,   123,  3623, -1266,   700,  4821,  4821,  1282,
    4821,   701,  4821,  4821,  1288,  1225,  4821,  4821,  1896,  1296,
    1299,  5953,  1302,  1303,  2868, -1266, -1266,  1305, -1266,  1321,
     237,   237,   237,   237,  1322,  1326,  1328,  1306,   595,  1298,
    2582, -1266, -1266,   273,  7403,  7429, -1266, -1266,  5306,  -109,
     123,   123,   123,  1304,  1331,  1175,  1360,  1186,    18,    42,
      47,    48,   546, -1266,   300, -1266,   366,  1363,  1368,  1369,
    1372,  1373,  9294, -1266,  1953,  1187,  1376,  1377,  1378,  1311,
    6180,  1381,  1382,  6180,   285,   600, -1266,  6180, -1266,  6180,
    6180,  6180,   603,   604,   608,   612, -1266,  6180,   616,   623,
    4821,  4821,  4821,  1385,  7455, -1266,  3999,   953,  1386,  1387,
    4821,  1203, -1266,  1388,  6180,  1389, -1266,    81,  1391,  1394,
   -1266,  1393,  4128,  4128,  4128,  4128,   423,  1214,  1226,  1227,
    1232,  1215,   547,   575,  9168,  1234,  2144, -1266,   290,  1222,
    1411,  2277, -1266, -1266, -1266,    26,  6180, -1266,   628, -1266,
     635,   636,   639,   640,   237,  9294,  1238,  6180,  6180,  4821,
    1242, -1266, -1266,  1250, -1266,  1426,    75,  1432,  6180,  4222,
      68,  1254,  1255,  1365,  1365,  4821,  1441,  1264,  1266,  1447,
    1451,  4821,  1270,  1454,  1455, -1266,  1457,  4821,   644,  4821,
    4821,  1473,  1479, -1266,  4821,  4821,  4821,  4821,  4821,  4821,
    4821,  4821, -1266,  1480,   726, -1266,  6180,  6180,  6180,  1300,
    1307,  -101,   -46,    84,  1313, -1266,  4821, -1266,  6180, -1266,
    1483, -1266,  1484, -1266,  1504, -1266,  1506, -1266, -1266,  5721,
     591,  4402, -1266,  1327,  1336,  5361, -1266,  5953, -1266, -1266,
   -1266,  1337,  2377, -1266, -1266,  8511,  1482,    81,  7481,  7507,
    7533,  7559, -1266, -1266, -1266, -1266,  9294, -1266,    81,  1508,
    1521,  1398, -1266,  6180,  6180,  6180, -1266,  1527,   901,  1349,
    1531, -1266,  2514, -1266,   237, -1266,   350, -1266, -1266, -1266,
   -1266, -1266, -1266,   550, -1266, -1266, -1266,  1478,  1536, -1266,
   -1266,  1538, -1266, -1266, -1266, -1266, -1266,  1478,  6180,  1537,
    1540,    27, -1266,  1541,  8534,    26, -1266,  1542,  1543,  1545,
    1546,  4821,  6180,  7585,  7611,   648, -1266,  6180,  1549, -1266,
   -1266,   550, -1266,  7637,  5779,  9294, -1266, -1266,  6180,  6180,
     123,  1548,  1550,  1551, -1266,  6180,  6180, -1266, -1266,  1552,
    6180, -1266, -1266,  1556,  1557,  1358,  1558,  1421,  6180, -1266,
    1560,  1561,  1562,  1563,  1564,  1565,   834,  1566,  6180, -1266,
    5779,  5486,  9189,  3228,    62,    62,   123,  1567,   123,  1568,
     123,  1570,  6180,   112,  1390,  9210, -1266, -1266, -1266, -1266,
    5690,   317, -1266,  1572,  3488,  1573,  4821,   123,  3488,  1575,
     663,  6180, -1266,  1576,   166, -1266,  6180,  6180,  6180,  6180,
   -1266, -1266, -1266,  4821,  4178,   396,  9231, -1266, -1266,  4582,
    4821, -1266, -1266,  4821, -1266,  1401,    81,  3862,  4641,  1578,
    2948, -1266,  1588,  1591, -1266,  1413, -1266, -1266, -1266, -1266,
   -1266,  1593,   561,  9294,  6180,  6180,  4821,  1412,   668,  9294,
   -1266,  1597,  6180,  9294, -1266,  5748,  5898,   775, -1266, -1266,
   -1266,  6085,  6425, -1266,  6453,  1602, -1266,  4821, -1266,  1539,
    1603,  9294, -1266, -1266, -1266, -1266, -1266, -1266,  1420, -1266,
   -1266,  7012,  3006,  1607,  1427, -1266,  6180, -1266,  1425,  1429,
     326, -1266,  1428,   340, -1266,  1431,   343, -1266,  1433,  8557,
    1614,  4821,  1615,  1435,  6180, -1266,  5541,   346, -1266,   672,
     353,   412, -1266,  1618,  6481, -1266,  7663,  7689,  7715,  7741,
    1498,  6180, -1266,  6180, -1266, -1266,  5953,  3079,  1623,  1443,
    1624, -1266, -1266,  3675, -1266, -1266,   550,  9294, -1266, -1266,
   -1266,    26, -1266,  1501, -1266, -1266,  6180,  7767,  7793, -1266,
    4821,  6180,  1628, -1266,  7819, -1266, -1266,  1629,  1631,  1633,
    1635,  1636,  1640,   675,  1459, -1266,  4821,  5953, -1266, -1266,
      62,  4347, -1266, -1266,  5721,   366,  5721,   366,  5721,   366,
    1642, -1266,   683,  4821, -1266,  6509,   123,  1643,  5953,   123,
   -1266, -1266,  6180,  6180,  6180,  6180,  6180,  6537,  6565,   684,
   -1266, -1266,  1646, -1266,   687,  3436,   688,  1647, -1266,  1466,
    9294,  6180,  6180,   691,  9294, -1266,  6180,   692,   714, -1266,
   -1266, -1266, -1266, -1266, -1266,  1467,  6180,   727,   746,  1468,
    6180, -1266,  6593,   415,   795,  6621,   437,  1142,  6649,   440,
    1182, -1266,  4821,  1650,  1569,  2789,  1470,   443, -1266,   767,
     462,  7845,  7871,  7897,  7923,  3189, -1266, -1266,  1656, -1266,
    6180, -1266,  1478, -1266, -1266,  6180,  9252,  7949,    46,  7975,
   -1266, -1266,  6180,  6677,  1657,  1574, -1266,  6705,  1661,  6180,
    1662,  1663,  6180,  1665,  1666,  6180,  1667,  1485, -1266,  6180,
   -1266,   366, -1266,  5953,  1669,  5541,  6180,  6180,  6180,  6180,
   -1266, -1266,   800, -1266,   768, -1266,  6180, -1266,  4821,  6180,
    8001, -1266, -1266,  4821,  1671, -1266, -1266,  1491,  6733, -1266,
   -1266,  1492,  6761, -1266, -1266,  1493,  6789, -1266,  1676,  3209,
    1295,  2825,   796, -1266,   473,   799,  8027,  8053,  8079,  8105,
    1478,  1677,  1496,  9273,   802,  6817,  6180, -1266, -1266,   366,
    1679,   366,  1680,   366,  1681, -1266, -1266, -1266, -1266,   366,
    1687,  5953,  1689,  6180,  6180,  6180,  6180, -1266, -1266,   550,
   -1266,  1509,  1690,  6845,  2048, -1266,  1510,  2070, -1266,  1512,
    2083, -1266,  1514,  2237, -1266,   803, -1266,  8131,  8157,  8183,
    8209,   806, -1266,  1515,  4821, -1266,  1701,  1702,   366,  1704,
     366,  1705,   366, -1266,  1706,  6180,  6180,  6180,  6180,   550,
    1707,   550,   807, -1266, -1266,  2286, -1266,  2420, -1266,  2602,
   -1266,  6873,  6901,  6929,  6957, -1266, -1266,   814, -1266,  1708,
    1710,  1711,  1716, -1266, -1266, -1266, -1266,   550,  1725, -1266,
   -1266, -1266, -1266, -1266, -1266
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1266, -1266, -1266, -1266,   690, -1266, -1266, -1266, -1266,   198,
   -1266, -1266, -1266, -1266, -1266, -1266, -1266, -1266, -1266, -1266,
   -1266, -1266,  -338,   -73,  1229,  -460, -1266,  1318, -1266, -1266,
   -1266, -1266, -1266,   312, -1266,   313, -1266, -1266, -1266, -1266,
   -1266, -1266,   686,  1735,    11,  -459,  -226, -1266, -1266, -1266,
   -1266, -1266, -1266,  1739, -1266, -1266, -1266, -1266, -1266, -1266,
   -1266, -1266, -1266, -1266, -1266, -1266, -1266,  -942,  -881, -1266,
   -1266,  1314, -1266, -1266, -1266, -1266, -1266, -1266,  1529, -1266,
   -1266,     0, -1266, -1265,  2159,   287,   997,   101,  -225,   562,
   -1266,    20,     7, -1266,  -344,    -3,    76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -464
static const yytype_int16 yytable[] =
{
     101,  1379,   457,   323,  1110,   582,   193,   584,   708,   709,
     856,   307,   375,   172,    89,   592,   476,   252,   198,   176,
     509,   511,   513,   193,  1099,   255,   171,   256,   492,   322,
     288,   845,   198,   189,   506,   604,   301,   607,   303,   752,
     190,   754,   756,   758,     5,   179,   235,   237,  1101,   243,
     988,   870,  1577,  1103,  1105,   310,   488,   311,   489,   282,
     291,  1108,   465,   466,   312,     4,   379,   244,   403,   768,
     465,   466,  1433,   298,  1207,   312,   543,   227,   545,   102,
    1090,  1200,   174,   465,   466,   546,  1246,   503,  1247,   257,
     228,   229,   167,   212,   465,   466,   213,   314,   214,   703,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   467,   805,   806,   807,   808,   809,   810,   811,   310,
     525,   326,   815,   817,   818,   465,   466,   857,   858,   859,
     860,   245,   175,   827,  1018,   246,   654,  1100,   655,   376,
     377,  1248,   177,  1249,   319,   320,   248,   247,   249,   510,
     512,   514,   299,   253,  -461,  1483,   178,    45,    46,    47,
      48,  1102,   298,   507,   181,    53,  1104,  1106,    56,   385,
     310,  1497,   528,   223,   298,   298,   224,   380,   638,   312,
     639,   298,   324,   194,   325,   167,   308,   282,   603,   167,
     195,   260,   282,   309,   261,   861,   282,   408,   411,   282,
     194,   254,   199,   282,   282,   282,   282,   850,   182,   282,
     282,   282,   784,   871,   289,   846,   851,   508,   183,   302,
     282,   304,   753,   282,   755,   757,   759,   180,   989,  1108,
     460,   461,   701,   702,  1578,   490,   606,   292,   469,   465,
     466,   378,   477,   871,   603,   282,   282,   282,   315,   316,
     317,   318,   717,   410,   410,   465,   466,   282,   282,   184,
     410,  1019,  1020,   742,   836,   743,   603,   839,   319,   320,
     282,  1250,   282,  1251,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   526,   398,   399,   742,   185,
     743,   421,   400,   646,   231,   232,   426,  1177,   465,   466,
     430,  1370,   608,   186,   233,   282,   282,   436,   465,   466,
     774,   234,   479,  1614,   216,   468,   189,   217,   282,   480,
     218,   554,   219,   849,   710,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   315,
     316,   317,   318,   400,   319,   320,   298,   298,   298,   298,
     298,   298,   282,   298,   298,   187,   298,   298,   201,   319,
     320,   298,   298,   298,   298,   852,   838,   465,   466,   595,
     583,   188,   585,   586,   587,   601,   589,   590,   191,   647,
     593,   282,   648,   716,   597,   598,   599,   315,   316,   317,
     318,   319,   320,   202,  1034,   315,   316,   317,   318,  1682,
     220,  -462,   192,   221,  1393,   222,   239,   319,   320,   240,
     207,   650,   241,   208,   648,   282,   209,   315,   316,   317,
     318,   196,   465,   466,   197,   410,   410,   410,   410,   410,
     410,   200,   410,   410,   201,   410,   410,   319,   320,   478,
     410,   410,   410,   600,   465,   466,   203,   994,   315,   316,
     317,   318,   204,   683,   686,   689,   692,   933,   206,   654,
    1086,   660,   205,   319,   320,   706,   707,   934,   319,   320,
    1126,   465,   466,   461,   920,   935,   936,   937,   380,   380,
     210,   938,   939,   940,   941,   619,   792,  1109,   465,   466,
     211,   282,   282,   282,   437,   438,   439,   465,   466,   442,
     443,   444,   298,  1504,  1374,  1507,   654,  1510,   664,   231,
     232,   465,   466,  1444,   465,   466,   282,   465,   466,   233,
     654,   215,   670,   282,   465,   466,   242,  1446,   319,   320,
    1448,   226,   840,  1456,   640,   484,   485,  1154,  -463,   641,
    1458,   225,  1158,  1159,  1160,  1161,  1162,   497,   498,   230,
     282,   642,  1169,  1172,   407,   105,   643,   250,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,  1075,  1076,  1077,  1078,   400,   742,   654,   743,
     762,   746,   816,   465,   466,  1394,   465,   466,   238,   131,
     132,   133,   134,   135,   136,   732,   733,   734,   140,  1459,
     251,   282,  1549,   142,   143,   742,   144,   743,   465,   466,
     654,   465,   466,   841,   465,   466,   742,   149,   743,  1600,
     760,  1027,   744,  1108,  1552,   258,  1108,  1555,   262,  1108,
    1563,   645,   259,   465,   466,   263,   646,   933,   282,   782,
     282,   783,   264,   298,   465,   466,   298,   934,   298,  1565,
     282,   282,   294,   826,   787,   935,   936,   937,   646,   284,
    1631,   938,   939,   940,   941,   285,   878,  1275,   792,   297,
     742,   882,   743,   654,   282,   854,   767,  1644,  1280,  1647,
    1178,  1650,   933,   515,   295,  1046,   516,  1653,   286,   517,
     654,   518,   934,   282,   282,   287,  1191,   152,   153,  1047,
     935,   936,   937,   923,   654,   293,   938,   939,   940,   941,
     929,   296,   995,   397,   398,   399,   944,   300,  1000,  1108,
     400,   654,   410,   958,   352,   880,  1685,   410,  1687,   742,
    1689,   743,  1239,  1240,  1168,  1107,   395,   396,   397,   398,
     399,   282,   873,  1415,   875,   400,   363,   654,  1416,   959,
     282,   310,   282,   502,   282,   503,   282,   742,   166,   743,
     167,   282,  1171,  1108,   282,   654,  1108,   960,   654,  1108,
     976,   654,  1108,   997,  1051,  1057,  1052,  1058,   353,   282,
    1262,   282,   654,   354,  1083,  1358,  1359,   654,   298,  1127,
     654,   654,  1132,  1133,  1042,   654,   402,  1134,   918,   654,
    1183,  1135,   355,   654,  1108,  1137,  1108,  1610,  1108,   455,
     654,  1001,  1138,   282,   356,  1185,  1293,  1186,   298,   282,
     298,   298,   654,   654,  1187,  1188,   654,   654,  1189,  1190,
     298,   654,  1011,  1225,   357,  1316,  1402,  1317,  1348,   359,
    1349,  1007,   364,  1009,  1010,   965,   282,   282,   282,   282,
     654,   365,  1383,  1015,   972,  1421,   973,  1422,   974,  1316,
     975,  1457,  1316,   366,  1495,   978,   367,   410,   979,   298,
    1512,   654,  1513,  1528,  1530,   646,  1531,  1533,  1316,  1168,
    1538,  1540,   383,  1050,   282,   282,   933,   282,   368,   282,
     282,  1000,  1045,   282,   282,   405,   934,   410,   282,   410,
     410,  1171,   424,  1541,   935,   936,   937,  1288,  1289,   410,
     938,   939,   940,   941,  1316,   429,  1544,  1006,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
    1091,  1092,  1093,   654,   400,  1545,   391,   392,   393,   394,
     395,   396,   397,   398,   399,  1179,   465,   466,   410,   400,
    1030,  1031,  1032,  1033,   654,  1421,  1564,  1611,   384,   401,
    1306,  1145,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   435,   282,   282,   282,
     400,  1499,   434,   654,  1550,  1630,   654,   282,  1632,  1316,
     654,  1641,  1674,  1679,  1316,  1680,  1699,   440,   103,   305,
     441,  1707,  1068,  1708,   106,   107,   108,   445,   446,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   447,   448,   449,   450,   451,   282,   452,   493,   527,
     137,   138,   139,   458,   141,   459,   470,   471,   472,   481,
     407,   105,   282,   145,   146,   147,  1206,   482,   282,   483,
     487,   148,  1476,   491,   282,   494,   282,   282,   499,   495,
     496,   282,   282,   282,   282,   282,   282,   282,   282,   500,
     501,   505,   530,  1294,   534,   131,   132,   133,   134,   135,
     136,   536,   537,   282,   140,   167,   312,   541,   542,   142,
     143,   544,   144,   552,   553,   556,   557,   559,   282,  1261,
     400,   609,   282,   149,   282,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   610,
     611,   166,   667,   400,   612,  1146,   671,   672,   673,   698,
     676,   151,   677,   696,   699,   741,   723,   700,   154,   155,
     156,   157,   158,   725,   747,   726,   728,   735,   547,   736,
     298,   749,   750,   751,   775,   772,   159,   160,   781,   788,
     789,   161,   819,   820,  1296,   821,   274,   843,   832,   373,
     822,   165,   834,  1295,  1299,   823,  1477,   420,   282,   824,
     831,   833,   420,   152,   153,   835,   420,   844,   298,   848,
     869,  1294,   883,   420,   874,   877,   879,   881,   886,   887,
    1327,  1324,   888,   890,   891,   892,   893,   895,  1270,   896,
     897,  1321,   906,   901,   319,   320,   908,   910,  1515,   911,
     912,   999,   913,   933,   919,   980,   953,   966,   981,   410,
     926,   927,   967,   934,   969,   970,  1360,  1353,  1363,   971,
    1366,   935,   936,   937,   982,   380,   380,   938,   939,   940,
     941,   282,   983,   282,  1377,   282,   990,  1380,  1381,   992,
     521,  1017,   420,   933,  1022,  1023,  1026,   410,  1025,  1029,
     282,  1037,  1038,   934,  1039,  1041,  1044,   282,  1049,  1055,
     282,   935,   936,   937,   282,  1061,  1398,   938,   939,   940,
     941,  1062,  1084,  1066,  1405,  1408,  1067,   637,  1094,  1069,
    1070,  1073,  1082,   282,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,  1074,  1079,
     313,  1553,   400,  1080,   282,  1081,  1601,  1095,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,  1096,     7,     8,  1097,  1098,   282,   358,
    1111,  1556,   360,   282,  1112,  1117,  1113,   361,   362,  1114,
    1115,   420,  1118,  1119,  1120,  1121,   933,  1123,  1124,  1142,
    1147,  1148,  1150,   282,  1151,  1153,   934,  1155,  1156,  1157,
     282,  1163,  1167,   298,   935,   936,   937,  1180,  1164,  1165,
     938,   939,   940,   941,  1166,   521,  1175,   282,  1181,  1192,
     613,    21,    22,   614,    24,    25,   615,    27,   616,    29,
    1197,    30,  1199,   282,   282,  1198,    35,    36,  1202,    38,
      39,    40,  1208,  1209,  1503,    43,  1506,  1214,  1509,  1210,
     282,   380,  1215,  1217,  1216,   282,  1517,  1218,  1220,  1520,
    1221,  1222,  1223,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,  1228,    64,    65,
      66,   400,   410,   105,  1627,  1229,  1274,  1238,  1244,  1256,
    1257,   420,   420,   420,   504,  1245,  1252,  1469,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   282,
    1258,   529,  1259,   400,  1281,  1266,   420,   131,   132,   133,
     134,   135,   136,   766,  1267,  1271,   140,  1282,  1283,     7,
       8,   142,   143,  1287,   144,   169,  1290,  1291,  1498,  1573,
    1297,   731,  1298,  1301,  1302,   149,  1337,  1304,  1307,  1308,
     420,  1309,  1310,  1320,  1328,  1339,  1329,  1330,  1333,  1519,
     282,  1335,   282,  1336,  1338,  1604,  1342,  1343,  1344,  1345,
    1346,  1347,  1350,  1361,  1364,   282,  1367,  1371,  1375,  1378,
     282,  1382,  1385,  1401,  1409,   613,    21,    22,   614,    24,
      25,   615,    27,   616,    29,  1411,    30,  1412,  1413,  1414,
    1420,    35,    36,  1423,    38,    39,    40,  1432,  1436,  1435,
      43,  1434,   306,  1439,  1442,  1440,  1445,  1637,  1443,  1447,
    1451,  1449,  1453,  1454,  1460,   152,   153,  1466,   282,  1471,
    1473,   830,  1472,  1478,  1485,  1489,   298,  1490,   420,  1491,
     420,  1492,  1493,    64,    65,    66,  1494,  1496,  1511,  1518,
     766,   885,  1529,  1534,  1535,  1542,  1558,  1546,  1562,  1662,
    1559,   282,  1571,  1582,  1602,  1583,  1605,  1586,  1589,  1590,
    1024,  1593,  1594,  1597,  1598,  1603,   298,  1618,   298,  1619,
    1621,  1623,  1625,  1638,  1639,  1645,  1648,  1651,   369,   370,
     371,   372,   374,  1654,   420,  1656,  1665,  1664,  1668,  1695,
    1670,  1698,  1672,  1681,   298,   406,   779,  1683,  1684,   412,
    1686,  1688,  1690,  1696,  1709,   410,  1710,  1711,   417,   419,
     422,   423,  1712,   425,   419,   427,   428,  1713,   419,   431,
     432,  1714,  1655,  1574,   651,   419,  1201,  1487,    88,  1488,
    1212,   420,    96,  1303,     0,     0,     0,     0,     0,     0,
     420,     0,   420,   454,   420,   410,   420,   410,   679,     0,
       0,   420,   463,   464,   420,     0,     0,     0,     0,     0,
       0,   464,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,   520,   522,   419,   400,     0,     0,     0,     0,
       0,     0,     0,   420,   531,   532,   533,     0,   535,     0,
       0,   538,   539,     0,     0,   540,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     551,     0,     0,     0,   400,     0,   420,   420,   420,   420,
       0,     0,     0,   558,     0,     0,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,     0,     7,
       8,     0,     0,     0,     0,     0,     0,   591,     0,     0,
     594,     0,   596,     0,     0,     0,     0,     0,   420,     0,
       0,     0,  1065,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   618,   419,     0,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
       0,     0,   636,     0,     0,   613,    21,    22,   614,    24,
      25,   615,    27,   616,    29,     0,    30,   520,     0,     0,
       0,    35,    36,   658,    38,    39,    40,     0,   663,  1116,
      43,     0,     0,   668,   669,     0,     0,     0,     0,   674,
     675,     0,     0,     0,   680,   682,   685,   688,   691,   693,
     694,   695,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,   711,
     712,   713,   369,   370,   714,     0,     0,     0,   718,   719,
     720,   721,   722,     0,     0,     0,   727,     0,     0,   729,
     730,     0,     0,   419,   419,   419,     0,     0,   737,   738,
     739,   740,     7,     8,     0,     0,     0,   748,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,     0,
       0,     0,     0,     0,   763,   765,   780,   636,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,   740,   400,     0,     0,     0,
       0,   786,   419,     0,     0,     0,   790,     0,   613,    21,
      22,   614,    24,    25,   615,    27,   616,    29,     0,    30,
       0,     0,     0,     0,    35,    36,     0,    38,    39,    40,
       0,     0,     0,    43,   420,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,   842,     0,     0,   933,
       0,     0,     0,     0,     0,     0,    64,    65,    66,   934,
    1176,     0,     0,     0,     0,     7,     8,   935,   936,   937,
       0,   933,     0,   938,   939,   940,   941,   868,     0,     0,
     419,   934,   419,   876,   933,     0,     0,     0,     0,   935,
     936,   937,   765,   884,   934,   938,   939,   940,   941,     0,
       0,     0,   935,   936,   937,     0,   898,     0,   938,   939,
     940,   941,     0,     0,     0,   904,     0,     0,     0,   921,
       0,   613,    21,    22,   614,    24,    25,   615,    27,   616,
      29,     0,    30,     0,     0,     0,   419,    35,    36,     0,
      38,    39,    40,   924,   925,     0,    43,  1667,     0,   928,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   952,     0,     0,   954,     0,     0,     0,  1669,
       0,   420,     0,     0,     0,   420,     0,     0,     0,    64,
      65,    66,  1671,   419,     0,     0,     0,     0,     0,     0,
       0,     0,   419,  1182,   419,     0,   419,     0,   419,     0,
       0,     0,     0,   419,     0,     0,   419,     0,     0,     0,
       0,     0,   984,     0,   986,   987,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,   933,     0,
       0,     0,   922,  1002,     0,     0,     0,     0,   934,     0,
       0,  1003,  1004,  1005,     0,   419,   935,   936,   937,     0,
       0,     0,   938,   939,   940,   941,     7,     8,     0,     0,
    1014,   433,     0,     0,     0,  1016,     0,     0,  1021,     0,
       0,     0,     0,   521,     0,     0,     0,   933,   419,   419,
     419,   419,   453,  1272,  1035,   456,     0,   934,     0,     0,
       0,     0,     0,   420,     0,   935,   936,   937,     0,     0,
     420,   938,   939,   940,   941,     0,     0,     0,     0,   486,
       0,     0,   613,    21,    22,   614,    24,    25,   615,    27,
     616,    29,     0,    30,     0,     0,  1673,     0,    35,    36,
     419,    38,    39,    40,   420,     0,     0,    43,     0,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,   420,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   548,   549,     0,
      64,    65,    66,     0,     0,  1700,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,  1122,
       0,     0,  1125,     0,     0,     0,  1128,     0,  1129,  1130,
    1131,     0,     0,     0,     0,     0,  1136,     0,     0,     0,
       0,   933,     0,     0,   588,     0,     0,     0,     0,     0,
    1292,   934,     0,  1152,     0,     7,     8,     0,     0,   935,
     936,   937,     0,   945,     0,   938,   939,   940,   941,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,  1184,     0,   400,     0,     0,
     420,     0,   420,     0,     0,     0,  1193,  1194,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1203,  1205,     0,
       0,   613,    21,    22,   614,    24,    25,   615,    27,   616,
      29,     0,    30,     0,     7,     8,     0,    35,    36,     0,
      38,    39,    40,     0,     0,     0,    43,     0,     0,  1701,
       0,     0,     0,     0,     0,  1241,  1242,  1243,     0,     0,
       0,     0,     0,     0,     0,  1253,     0,  1255,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1260,    64,
      65,    66,     0,     0,     0,     0,   419,     0,     0,     0,
     613,    21,    22,   614,    24,    25,   615,    27,   616,    29,
       0,    30,     0,     0,     0,     0,    35,    36,     0,    38,
      39,    40,  1284,  1285,  1286,    43,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,   933,   400,     0,     0,     0,     0,     0,
       0,     0,   985,   934,     0,     0,     0,  1300,    64,    65,
      66,   935,   936,   937,     0,     0,     0,   938,   939,   940,
     941,  1313,     0,     0,     0,     0,  1319,     0,     0,     0,
       0,     0,     0,  1323,     0,     0,     0,  1325,  1326,     0,
       0,     0,     0,     0,  1331,  1332,     0,     0,     0,  1334,
       0,     0,     0,     0,     0,     0,     0,  1341,     0,     0,
       0,     0,     0,   837,     0,     0,     0,  1351,     0,  1352,
       0,  1085,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1702,     0,   419,     0,     0,     0,   419,     0,     0,
    1384,     7,     8,     0,     0,  1386,  1387,  1388,  1389,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1397,     0,
       0,     0,     0,     0,     0,     0,     0,  1407,     0,     0,
       0,     0,     0,     0,     0,     0,   905,     7,     8,     0,
       0,     0,     0,  1417,  1418,     0,     0,     0,     0,     0,
       0,  1424,     0,     0,     0,   917,     0,   613,    21,    22,
     614,    24,    25,   615,    27,   616,    29,     0,    30,     0,
       0,     0,     0,    35,    36,     0,    38,    39,    40,     0,
       0,     0,    43,     0,     0,  1441,     0,     0,     0,     0,
       0,     0,     0,   613,    21,    22,   614,    24,    25,   615,
      27,   616,    29,  1455,    30,   520,     0,     0,     0,    35,
      36,     0,    38,    39,    40,    64,    65,    66,    43,     0,
    1467,     0,  1468,     0,     0,   419,     0,     0,     0,     0,
       0,     0,  1475,     0,     0,     0,     0,     0,     0,     0,
       0,   991,     0,   993,     0,  1480,     0,     0,     0,     0,
    1484,    64,    65,    66,  1410,     0,     0,     0,     0,  1071,
       0,     0,     0,     0,     0,     0,   419,     0,     0,     0,
       0,     0,     0,  1502,     0,  1505,     0,  1508,  1560,     0,
       0,  1008,     0,     0,     0,     0,     0,   419,     0,     0,
       0,  1521,  1522,  1523,  1524,  1525,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1536,  1537,  1438,     0,  1628,  1539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1543,     0,     0,     0,  1547,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,  1053,  1054,   400,  1056,
       0,  1059,  1060,     0,     0,  1063,  1064,     0,     0,  1572,
       0,     0,     0,     0,  1319,     0,     0,     0,     0,     0,
       0,  1580,     0,     0,     0,     0,     0,     0,  1588,     0,
       0,  1592,     0,     0,  1596,  1470,     0,     0,  1599,     0,
       0,     0,   419,     0,   419,  1606,  1607,  1608,  1609,     0,
       0,     0,     0,     0,     0,  1613,     0,     0,  1615,     0,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1139,
    1140,  1141,     0,     0,     0,  1643,     0,     0,     0,  1149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     419,     0,  1657,  1658,  1659,  1660,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1570,     0,     0,  1196,     0,
       0,     0,     0,     0,  1691,  1692,  1693,  1694,     0,     0,
       0,     0,     0,     0,  1213,  1626,     0,     0,     0,     0,
    1219,     0,     0,     0,     0,     0,  1224,     0,  1226,  1227,
       0,     0,     0,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,  1254,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1265,     0,     0,     0,  1269,     0,     0,   103,   104,   105,
       0,     0,     0,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,   142,   143,     0,
     144,     0,   145,   146,   147,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
    1311,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,   150,  1356,     0,  1357,     0,     0,
     151,   152,   153,     0,     0,  1196,     0,   154,   155,   156,
     157,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1390,  1532,   525,   159,   160,     0,     0,  1399,
     161,     0,  1400,     0,     0,   162,  1404,   163,     0,   164,
     165,     0,   166,   525,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1419,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,   103,   265,     0,   400,     0,  1196,   106,   107,   108,
       0,   644,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   267,     0,     0,     0,     0,     0,
    1452,     0,     0,   137,   138,   139,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,     0,   148,     0,   268,     0,     0,   269,
       0,     0,   270,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,     0,     0,  1196,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,  1196,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   653,
     398,   399,  1514,     0,     0,     0,   400,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   526,   398,
     399,   525,     0,     0,   151,   400,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,   473,
    1376,     0,     0,     0,   161,     0,     0,     0,     0,   475,
       0,  1557,     0,     0,   165,     0,   234,   523,   103,   265,
       0,     0,     0,     0,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   267,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,  1196,     0,     0,
       0,   148,  1617,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,     0,     0,     0,    53,     0,
       0,    56,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   653,   398,   399,     0,
       0,     0,     0,   400,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   855,     0,
       0,   151,   400,  1196,     0,     0,     0,     0,   154,   155,
     156,   157,   158,     0,     0,     0,     0,     0,     0,   977,
       0,     0,     0,     0,     0,     0,   159,   418,     0,     0,
       0,   161,     0,     0,     0,     0,   274,     0,     0,     0,
       0,   165,     0,     0,   523,   103,   265,   105,     0,     0,
       0,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   267,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   142,   143,     0,   144,     0,
     145,   146,   147,     0,     0,     0,     0,     0,   148,   149,
     268,     0,     0,   269,     0,     0,   270,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,  1144,   151,   152,
     153,   400,     0,     0,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   273,     0,     0,     0,   161,     0,
       0,     0,     0,   274,     0,   103,   265,   266,   165,     0,
    1403,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,     0,   148,     0,
     268,     0,     0,   269,     0,     0,   270,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,   151,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   273,     0,     0,     0,   161,     0,
       0,     0,     0,   274,     0,   103,   305,   105,   165,     0,
     275,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     7,     8,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   142,   143,     0,   144,     0,
     145,   146,   147,     0,     0,     0,     0,     0,   148,   149,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     742,     0,   743,     0,   613,    21,    22,   614,    24,    25,
     615,    27,   616,    29,     0,    30,     0,     0,     0,     0,
      35,    36,     0,    38,    39,    40,     0,     0,     0,    43,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,  1391,     0,  1392,   151,   152,
     153,     0,    64,    65,    66,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,     0,     0,     0,   161,     0,
       0,     0,     0,   274,     0,   103,   265,  1263,   165,     0,
    1204,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,     0,   148,     0,
     268,     0,     0,   269,     0,     0,   270,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1500,     0,  1501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   273,     0,     0,     0,   161,     0,
       0,     0,     0,   274,     0,   103,   305,   105,   165,     0,
    1264,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   142,   143,     0,   144,     0,
     145,   146,   147,     0,   103,   305,   105,     0,   148,   149,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,     0,   142,   143,     0,   144,     0,   145,
     146,   147,     0,     0,     0,     0,     0,   148,   149,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,   151,   152,
     153,   400,     0,     0,     0,   154,   155,   156,   157,   158,
     853,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,     0,     0,     0,   161,     0,
       0,     0,     0,   274,     0,     0,     0,     0,   165,     0,
    1396,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,   151,   152,   153,
     400,     0,     0,     0,   154,   155,   156,   157,   158,   900,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,     0,     0,     0,   161,     0,     0,
       0,     0,   274,     0,   103,   265,     0,   165,     0,  1406,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,   148,     0,   268,
       0,     0,   269,     0,     0,   270,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,   948,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   273,     0,     0,     0,   161,     0,     0,
       0,     0,   274,     0,   103,   265,     0,   165,     0,   275,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,   148,     0,   268,
       0,     0,   269,     0,     0,   270,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,   968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   418,     0,     0,     0,   161,     0,     0,
       0,     0,   274,     0,   103,   265,     0,   165,     0,   519,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,   148,     0,   268,
       0,     0,   269,     0,     0,   270,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,   996,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   418,     0,     0,     0,   161,     0,     0,
       0,     0,   274,     0,   103,   265,     0,   165,     0,   764,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,   148,     0,   268,
       0,     0,   269,     0,     0,   270,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1089,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   273,     0,     0,     0,   161,     0,     0,
       0,     0,   274,     0,   103,   265,     0,   165,     0,  1268,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,   148,     0,   268,
       0,     0,   269,     0,     0,   270,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,  1354,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,  1376,     0,     0,     0,   161,     0,     0,
       0,     0,   475,     0,   103,   305,     0,   165,     0,   234,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,   103,   305,   105,     0,     0,   148,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,   142,   143,     0,   144,     0,   145,   146,   147,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,   151,     0,     0,
     400,     0,     0,     0,   154,   155,   156,   157,   158,  1373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,   474,     0,     0,     0,   161,     0,     0,
       0,     0,   475,     0,     0,     0,     0,   165,     0,   234,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,   151,   152,   153,   400,     0,
       0,     0,   154,   155,   156,   157,   158,  1427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,     0,     0,     0,   161,   103,   265,     0,     0,
     274,     0,   106,   107,   108,   165,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   267,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,     0,   141,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,     0,   148,
       0,   268,     0,     0,   269,     0,     0,   270,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,  1428,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   418,     0,     0,     0,   161,
     103,   305,     0,     0,   274,     0,   106,   107,   108,   165,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,   141,     0,     0,     0,
       0,     0,     0,   103,   305,   145,   146,   147,     0,   106,
     107,   108,     0,   148,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,     0,   148,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,   151,  1429,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
       0,     0,     0,   161,     0,     0,     0,     0,   274,     0,
       0,   550,     0,   165,     0,     0,     0,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,   151,     0,     0,    -4,
      -4,     0,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,     0,    -4,    -4,   161,     0,     0,     0,
       0,   274,     0,     0,     0,     0,   165,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,     0,    14,
       0,    15,     0,     0,     0,    16,    17,     0,    18,    19,
       0,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,    59,    60,    61,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,    63,
      64,    65,    66,     0,     0,    67,     0,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    80,    81,    82,    83,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,  1430,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,  1431,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
    1461,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,  1516,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,  1526,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,  1527,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,  1548,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
    1551,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,  1554,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,  1581,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,  1585,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,  1620,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
    1622,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,  1624,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,  1642,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,  1666,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,  1703,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
    1704,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,  1705,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,  1706,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,   697,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,     0,
    1437,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   761,     0,     0,     0,     0,   704,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,   704,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,   705,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,   773,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
     804,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,   812,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,   813,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,   814,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,   825,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
     930,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,   931,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,   932,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,   963,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1048,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1087,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1088,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1143,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,  1276,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1277,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1278,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1279,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1314,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,  1315,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1322,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1462,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1463,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1464,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,  1465,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1481,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1482,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1486,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1566,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,  1567,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1568,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1569,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1576,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1579,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,  1616,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1633,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1634,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1635,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,  1636,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,  1675,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,  1676,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
    1677,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,  1678,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,   605,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,   778,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,   785,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,   791,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,   867,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,     0,     0,   956,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,     0,     0,   957,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,     0,     0,
     961,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,     0,     0,   962,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,     0,     0,   964,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,     0,     0,   998,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
       0,     0,  1043,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,     0,     0,  1273,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,     0,     0,  1305,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,     0,
       0,  1450,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   602,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   652,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   656,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   657,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   659,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   661,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   662,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   665,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     666,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   761,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   769,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   770,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   771,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   777,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   889,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   894,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   899,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   902,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
     903,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   909,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   914,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   915,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   916,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   947,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   949,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   950,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   951,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   955,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,     0,
    1174,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,  1355,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,  1372,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,  1395,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,  1575,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,  1640,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1266)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,  1266,   227,     4,   946,   349,     4,   351,   467,   468,
       4,     6,     4,     6,     3,   359,   242,     4,     4,    74,
       5,     5,     5,     4,     6,     4,     6,     6,   254,   102,
       4,     4,     4,   181,     5,   373,     5,   375,     5,     5,
     188,     5,     5,     5,     0,     6,    46,    47,     6,    49,
       7,     6,     6,     6,     6,   181,     4,   183,     6,    62,
       4,   942,   171,   172,   190,     6,     4,     4,   183,   529,
     171,   172,  1337,    76,     6,   190,   302,   131,   304,     3,
     189,     6,     6,   171,   172,   183,   187,   185,   189,    68,
     144,   145,   190,    71,   171,   172,    74,     7,    76,   187,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   188,   572,   573,   574,   575,   576,   577,   578,   181,
       8,   183,   582,   583,   584,   171,   172,   121,   122,   123,
     124,    68,    13,   593,     4,    72,   187,   119,   189,   131,
     132,   187,   181,   189,   178,   179,    74,    84,    76,   134,
     134,   134,    76,   140,   188,  1420,   181,    95,    96,    97,
      98,   119,   165,   134,     6,   103,   119,   119,   106,     6,
     181,  1436,   183,    71,   177,   178,    74,   166,   183,   190,
     185,   184,   183,   181,   185,   190,   181,   190,     7,   190,
     188,    71,   195,   188,    74,   189,   199,   177,   178,   202,
     181,   188,   188,   206,   207,   208,   209,   188,     6,   212,
     213,   214,   550,   168,   188,   188,   188,   188,     6,   188,
     223,   188,   188,   226,   188,   188,   188,   188,   185,  1110,
     230,   231,   458,   459,   188,   183,     7,   181,   238,   171,
     172,   165,   242,   168,     7,   248,   249,   250,   158,   159,
     160,   161,   478,   177,   178,   171,   172,   260,   261,   181,
     184,   131,   132,   182,   602,   184,     7,   605,   178,   179,
     273,   187,   275,   189,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   182,     6,
     184,   190,   180,   187,   171,   172,   195,     7,   171,   172,
     199,   189,   375,     6,   181,   308,   309,   206,   171,   172,
     536,   188,   181,  1578,    68,   188,   181,    71,   321,   188,
      74,   314,    76,   188,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   158,
     159,   160,   161,   180,   178,   179,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   183,   359,   360,   181,   178,
     179,   364,   365,   366,   367,   188,   185,   171,   172,   362,
     350,   183,   352,   353,   354,   368,   356,   357,   181,   184,
     360,   384,   187,   187,   364,   365,   366,   158,   159,   160,
     161,   178,   179,    78,   854,   158,   159,   160,   161,  1664,
      71,   188,   181,    74,     8,    76,    68,   178,   179,    71,
      68,   184,    74,    71,   187,   418,    74,   158,   159,   160,
     161,   181,   171,   172,   181,   349,   350,   351,   352,   353,
     354,   181,   356,   357,   181,   359,   360,   178,   179,   188,
     364,   365,   366,   367,   171,   172,    74,   785,   158,   159,
     160,   161,    74,   446,   447,   448,   449,    91,   188,   187,
     187,   189,     6,   178,   179,   465,   466,   101,   178,   179,
     185,   171,   172,   473,   700,   109,   110,   111,   467,   468,
      74,   115,   116,   117,   118,   384,   559,   187,   171,   172,
      74,   494,   495,   496,   207,   208,   209,   171,   172,   212,
     213,   214,   505,  1445,   187,  1447,   187,  1449,   189,   171,
     172,   171,   172,   187,   171,   172,   519,   171,   172,   181,
     187,    76,   189,   526,   171,   172,   188,   187,   178,   179,
     187,    71,   605,   187,   182,   248,   249,   997,   188,   187,
     187,   181,  1002,  1003,  1004,  1005,  1006,   260,   261,   188,
     553,   182,  1012,  1013,     4,     5,   187,    74,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   910,   911,   912,   913,   180,   182,   187,   184,
     189,   505,   187,   171,   172,   189,   171,   172,   188,    39,
      40,    41,    42,    43,    44,   494,   495,   496,    48,   187,
      71,   604,   187,    53,    54,   182,    56,   184,   171,   172,
     187,   171,   172,   606,   171,   172,   182,    67,   184,  1561,
     519,   846,   188,  1504,   187,    71,  1507,   187,     4,  1510,
     187,   182,    74,   171,   172,     4,   187,    91,   641,   187,
     643,   189,     4,   646,   171,   172,   649,   101,   651,   187,
     653,   654,     6,   182,   553,   109,   110,   111,   187,     4,
     187,   115,   116,   117,   118,   181,   646,  1127,   741,     4,
     182,   651,   184,   187,   677,   189,   188,  1619,  1138,  1621,
    1018,  1623,    91,    68,     6,   182,    71,  1629,   181,    74,
     187,    76,   101,   696,   697,   181,  1034,   147,   148,   182,
     109,   110,   111,   703,   187,   181,   115,   116,   117,   118,
     710,   183,   785,   173,   174,   175,   716,     4,   791,  1600,
     180,   187,   646,   189,   181,   649,  1668,   651,  1670,   182,
    1672,   184,     6,     7,   187,   189,   171,   172,   173,   174,
     175,   744,   641,   182,   643,   180,     7,   187,   187,   189,
     753,   181,   755,   183,   757,   185,   759,   182,   188,   184,
     190,   764,   187,  1644,   767,   187,  1647,   189,   187,  1650,
     189,   187,  1653,   189,    74,    74,    76,    76,   181,   782,
     189,   784,   187,   181,   189,  1244,  1245,   187,   791,   189,
     187,   187,   189,   189,   867,   187,     6,   189,   697,   187,
    1025,   189,   181,   187,  1685,   189,  1687,     7,  1689,     4,
     187,   791,   189,   816,   181,   187,  1154,   189,   821,   822,
     823,   824,   187,   187,   189,   189,   187,   187,   189,   189,
     833,   187,   825,   189,   181,   187,  1296,   189,     4,   181,
       6,   821,   181,   823,   824,   744,   849,   850,   851,   852,
     187,   181,   189,   833,   753,   187,   755,   189,   757,   187,
     759,   189,   187,   181,   189,   764,   181,   791,   767,   872,
     187,   187,   189,   189,   187,   187,   189,   189,   187,   187,
     189,   189,   188,   883,   887,   888,    91,   890,   181,   892,
     893,   964,   872,   896,   897,     6,   101,   821,   901,   823,
     824,   187,   181,   189,   109,   110,   111,     6,     7,   833,
     115,   116,   117,   118,   187,   181,   189,   816,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     930,   931,   932,   187,   180,   189,   167,   168,   169,   170,
     171,   172,   173,   174,   175,  1018,   171,   172,   872,   180,
     849,   850,   851,   852,   187,   187,   189,   189,   188,   188,
    1185,     8,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   188,   980,   981,   982,
     180,  1440,   181,   187,   189,   189,   187,   990,   189,   187,
     187,   189,   189,   187,   187,   189,   189,   181,     3,     4,
     181,   187,   901,   189,     9,    10,    11,   181,   181,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,   181,   181,   181,   181,   181,  1039,   181,     6,     6,
      45,    46,    47,   188,    49,   188,   188,   188,   188,   181,
       4,     5,  1055,    58,    59,    60,  1049,   181,  1061,   181,
     181,    66,  1406,   183,  1067,   188,  1069,  1070,   183,   188,
     188,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,   183,
     183,   183,     6,  1156,   185,    39,    40,    41,    42,    43,
      44,   188,   134,  1096,    48,   190,   190,     6,     6,    53,
      54,     6,    56,   188,   188,     6,   183,     4,  1111,  1109,
     180,   185,  1115,    67,  1117,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,     7,
     183,   188,     7,   180,   189,   182,     6,     6,     6,   182,
       7,   146,     7,     7,     6,     4,     7,   188,   153,   154,
     155,   156,   157,     6,    50,     7,     6,     6,     6,     6,
    1163,    50,    50,    50,   188,   131,   171,   172,   182,     6,
       6,   176,   182,   182,  1167,   187,   181,     6,   182,   184,
     187,   186,   182,  1163,  1177,   187,  1411,   190,  1191,   187,
     187,   187,   195,   147,   148,   182,   199,     4,  1201,   184,
       4,  1274,     7,   206,     6,     6,     6,     6,   134,     7,
    1210,  1204,     7,     7,   134,     7,     7,   134,  1117,     7,
       7,  1201,     4,   188,   178,   179,     6,   182,  1454,   182,
     182,   185,   182,    91,   185,     7,     6,   184,     7,  1163,
     189,   189,   188,   101,   188,   188,  1246,  1240,  1248,   188,
    1250,   109,   110,   111,     7,  1244,  1245,   115,   116,   117,
     118,  1264,   185,  1266,  1264,  1268,   188,  1267,  1268,     6,
     273,     6,   275,    91,     6,     6,   183,  1201,     7,     6,
    1283,   181,   181,   101,   188,     6,   168,  1290,     7,     7,
    1293,   109,   110,   111,  1297,     7,  1289,   115,   116,   117,
     118,    76,     4,     7,  1297,  1298,     7,     6,     4,     7,
       7,     6,     6,  1316,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     7,     7,
     101,   189,   180,     7,  1337,     7,  1562,     6,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   188,    12,    13,     6,   181,  1371,   140,
       7,   189,   143,  1376,     6,   188,     7,   148,   149,     7,
       7,   384,     6,     6,     6,    74,    91,     6,     6,     4,
       4,     4,   189,  1396,     6,     6,   101,     6,     4,     6,
    1403,   187,   187,  1406,   109,   110,   111,   185,   182,   182,
     115,   116,   117,   118,   182,   418,   182,  1420,     7,   181,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     188,    79,     6,  1436,  1437,   185,    84,    85,     6,    87,
      88,    89,   188,   188,  1444,    93,  1446,     6,  1448,    84,
    1453,  1440,   188,     6,   188,  1458,  1456,     6,   188,  1459,
       6,     6,     5,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     4,   126,   127,
     128,   180,  1406,     5,   189,     6,     4,     7,   188,     6,
       6,   494,   495,   496,   265,   188,   183,  1396,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,  1512,
       6,   282,     6,   180,     6,   188,   519,    39,    40,    41,
      42,    43,    44,   526,   188,   188,    48,     6,   130,    12,
      13,    53,    54,     6,    56,     6,   187,     6,  1437,  1532,
       4,   189,     4,     6,     4,    67,   188,     6,     6,     6,
     553,     6,     6,     4,     6,   134,     6,     6,     6,  1458,
    1563,     5,  1565,     6,     6,  1565,     6,     6,     6,     6,
       6,     6,     6,     6,     6,  1578,     6,   187,     6,     6,
    1583,     6,     6,   182,     6,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     7,    79,     6,   185,     6,
     188,    84,    85,     6,    87,    88,    89,     5,   188,     6,
      93,    72,    83,     6,   189,   188,   188,  1610,   189,   188,
       6,   188,     7,   188,     6,   147,   148,   129,  1631,     6,
       6,     6,   189,   132,     6,     6,  1639,     6,   641,     6,
     643,     6,     6,   126,   127,   128,     6,   188,     6,     6,
     653,   654,     6,     6,   188,   188,     6,   189,   188,  1639,
      91,  1664,     6,     6,  1563,    91,  1565,     6,     6,     6,
       6,     6,     6,     6,   189,     6,  1679,     6,  1681,   188,
     188,   188,     6,     6,   188,     6,     6,     6,   159,   160,
     161,   162,   163,     6,   697,     6,     6,   188,   188,  1679,
     188,  1681,   188,   188,  1707,   176,   189,     6,     6,   180,
       6,     6,     6,     6,     6,  1639,     6,     6,   189,   190,
     191,   192,     6,   194,   195,   196,   197,  1707,   199,   200,
     201,     6,  1631,  1535,   416,   206,  1046,  1425,     3,  1426,
    1054,   744,     3,  1181,    -1,    -1,    -1,    -1,    -1,    -1,
     753,    -1,   755,   224,   757,  1679,   759,  1681,   444,    -1,
      -1,   764,   233,   234,   767,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1707,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   273,   274,   275,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   816,   285,   286,   287,    -1,   289,    -1,
      -1,   292,   293,    -1,    -1,   296,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     311,    -1,    -1,    -1,   180,    -1,   849,   850,   851,   852,
      -1,    -1,    -1,   324,    -1,    -1,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,
     361,    -1,   363,    -1,    -1,    -1,    -1,    -1,   901,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   383,   384,    -1,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
      -1,    -1,   403,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,   418,    -1,    -1,
      -1,    84,    85,   424,    87,    88,    89,    -1,   429,     6,
      93,    -1,    -1,   434,   435,    -1,    -1,    -1,    -1,   440,
     441,    -1,    -1,    -1,   445,   446,   447,   448,   449,   450,
     451,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,   470,
     471,   472,   473,   474,   475,    -1,    -1,    -1,   479,   480,
     481,   482,   483,    -1,    -1,    -1,   487,    -1,    -1,   490,
     491,    -1,    -1,   494,   495,   496,    -1,    -1,   499,   500,
     501,   502,    12,    13,    -1,    -1,    -1,   508,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,    -1,
      -1,    -1,    -1,    -1,   525,   526,   189,   528,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,   546,   180,    -1,    -1,    -1,
      -1,   552,   553,    -1,    -1,    -1,   557,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      -1,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      -1,    -1,    -1,    93,  1117,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,   607,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   101,
       6,    -1,    -1,    -1,    -1,    12,    13,   109,   110,   111,
      -1,    91,    -1,   115,   116,   117,   118,   638,    -1,    -1,
     641,   101,   643,   644,    91,    -1,    -1,    -1,    -1,   109,
     110,   111,   653,   654,   101,   115,   116,   117,   118,    -1,
      -1,    -1,   109,   110,   111,    -1,   667,    -1,   115,   116,
     117,   118,    -1,    -1,    -1,   676,    -1,    -1,    -1,   189,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    -1,    -1,    -1,   697,    84,    85,    -1,
      87,    88,    89,   704,   705,    -1,    93,   189,    -1,   710,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   723,    -1,    -1,   726,    -1,    -1,    -1,   189,
      -1,  1264,    -1,    -1,    -1,  1268,    -1,    -1,    -1,   126,
     127,   128,   189,   744,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   753,     6,   755,    -1,   757,    -1,   759,    -1,
      -1,    -1,    -1,   764,    -1,    -1,   767,    -1,    -1,    -1,
      -1,    -1,   773,    -1,   775,   776,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    91,    -1,
      -1,    -1,   189,   804,    -1,    -1,    -1,    -1,   101,    -1,
      -1,   812,   813,   814,    -1,   816,   109,   110,   111,    -1,
      -1,    -1,   115,   116,   117,   118,    12,    13,    -1,    -1,
     831,   202,    -1,    -1,    -1,   836,    -1,    -1,   839,    -1,
      -1,    -1,    -1,  1376,    -1,    -1,    -1,    91,   849,   850,
     851,   852,   223,     6,   855,   226,    -1,   101,    -1,    -1,
      -1,    -1,    -1,  1396,    -1,   109,   110,   111,    -1,    -1,
    1403,   115,   116,   117,   118,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    -1,    -1,   189,    -1,    84,    85,
     901,    87,    88,    89,  1437,    -1,    -1,    93,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,  1458,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,   309,    -1,
     126,   127,   128,    -1,    -1,   189,    -1,    -1,    -1,    -1,
     321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   960,
      -1,    -1,   963,    -1,    -1,    -1,   967,    -1,   969,   970,
     971,    -1,    -1,    -1,    -1,    -1,   977,    -1,    -1,    -1,
      -1,    91,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,
       6,   101,    -1,   994,    -1,    12,    13,    -1,    -1,   109,
     110,   111,    -1,   189,    -1,   115,   116,   117,   118,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,  1026,    -1,   180,    -1,    -1,
    1563,    -1,  1565,    -1,    -1,    -1,  1037,  1038,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1048,  1049,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    -1,    12,    13,    -1,    84,    85,    -1,
      87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,   189,
      -1,    -1,    -1,    -1,    -1,  1086,  1087,  1088,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1096,    -1,  1098,  1631,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1109,   126,
     127,   128,    -1,    -1,    -1,    -1,  1117,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,  1143,  1144,  1145,    93,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    91,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   101,    -1,    -1,    -1,  1178,   126,   127,
     128,   109,   110,   111,    -1,    -1,    -1,   115,   116,   117,
     118,  1192,    -1,    -1,    -1,    -1,  1197,    -1,    -1,    -1,
      -1,    -1,    -1,  1204,    -1,    -1,    -1,  1208,  1209,    -1,
      -1,    -1,    -1,    -1,  1215,  1216,    -1,    -1,    -1,  1220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1228,    -1,    -1,
      -1,    -1,    -1,   604,    -1,    -1,    -1,  1238,    -1,  1240,
      -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,  1264,    -1,    -1,    -1,  1268,    -1,    -1,
    1271,    12,    13,    -1,    -1,  1276,  1277,  1278,  1279,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   677,    12,    13,    -1,
      -1,    -1,    -1,  1314,  1315,    -1,    -1,    -1,    -1,    -1,
      -1,  1322,    -1,    -1,    -1,   696,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    79,    -1,
      -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,  1356,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,  1374,    79,  1376,    -1,    -1,    -1,    84,
      85,    -1,    87,    88,    89,   126,   127,   128,    93,    -1,
    1391,    -1,  1393,    -1,    -1,  1396,    -1,    -1,    -1,    -1,
      -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   782,    -1,   784,    -1,  1416,    -1,    -1,    -1,    -1,
    1421,   126,   127,   128,     6,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,  1437,    -1,    -1,    -1,
      -1,    -1,    -1,  1444,    -1,  1446,    -1,  1448,   189,    -1,
      -1,   822,    -1,    -1,    -1,    -1,    -1,  1458,    -1,    -1,
      -1,  1462,  1463,  1464,  1465,  1466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1481,  1482,     6,    -1,   189,  1486,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1496,    -1,    -1,    -1,  1500,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,   887,   888,   180,   890,
      -1,   892,   893,    -1,    -1,   896,   897,    -1,    -1,  1530,
      -1,    -1,    -1,    -1,  1535,    -1,    -1,    -1,    -1,    -1,
      -1,  1542,    -1,    -1,    -1,    -1,    -1,    -1,  1549,    -1,
      -1,  1552,    -1,    -1,  1555,     6,    -1,    -1,  1559,    -1,
      -1,    -1,  1563,    -1,  1565,  1566,  1567,  1568,  1569,    -1,
      -1,    -1,    -1,    -1,    -1,  1576,    -1,    -1,  1579,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   980,
     981,   982,    -1,    -1,    -1,  1616,    -1,    -1,    -1,   990,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1631,    -1,  1633,  1634,  1635,  1636,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  1039,    -1,
      -1,    -1,    -1,    -1,  1675,  1676,  1677,  1678,    -1,    -1,
      -1,    -1,    -1,    -1,  1055,     6,    -1,    -1,    -1,    -1,
    1061,    -1,    -1,    -1,    -1,    -1,  1067,    -1,  1069,  1070,
      -1,    -1,    -1,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,  1096,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1111,    -1,    -1,    -1,  1115,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    54,    -1,
      56,    -1,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1191,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,   140,   187,    -1,   189,    -1,    -1,
     146,   147,   148,    -1,    -1,  1266,    -1,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1283,     7,     8,   171,   172,    -1,    -1,  1290,
     176,    -1,  1293,    -1,    -1,   181,  1297,   183,    -1,   185,
     186,    -1,   188,     8,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1316,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,     3,     4,    -1,   180,    -1,  1337,     9,    10,    11,
      -1,   187,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
    1371,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    -1,    -1,    71,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,  1420,
      -1,    -1,    -1,    95,    96,    97,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,  1436,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,  1453,    -1,    -1,    -1,   180,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     8,    -1,    -1,   146,   180,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,   181,
      -1,  1512,    -1,    -1,   186,    -1,   188,   189,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    -1,  1578,    -1,    -1,
      -1,    66,  1583,    68,    -1,    -1,    71,    -1,    -1,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,    -1,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     8,    -1,
      -1,   146,   180,  1664,    -1,    -1,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,    -1,    -1,
      -1,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,   189,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     8,   146,   147,
     148,   180,    -1,    -1,    -1,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   181,    -1,     3,     4,     5,   186,    -1,
     188,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   181,    -1,     3,     4,     5,   186,    -1,
     188,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    12,    13,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
     182,    -1,   184,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    -1,    -1,    -1,    93,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   146,   147,
     148,    -1,   126,   127,   128,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   181,    -1,     3,     4,     5,   186,    -1,
     188,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   181,    -1,     3,     4,     5,   186,    -1,
     188,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    54,    -1,    56,    -1,
      58,    59,    60,    -1,     3,     4,     5,    -1,    66,    67,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    -1,    56,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   146,   147,
     148,   180,    -1,    -1,    -1,   153,   154,   155,   156,   157,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   146,   147,   148,
     180,    -1,    -1,    -1,   153,   154,   155,   156,   157,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,     3,     4,    -1,   186,    -1,   188,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,     3,     4,    -1,   186,    -1,   188,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,     3,     4,    -1,   186,    -1,   188,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,     3,     4,    -1,   186,    -1,   188,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,     3,     4,    -1,   186,    -1,   188,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,     3,     4,    -1,   186,    -1,   188,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,     3,     4,     5,    -1,    -1,    66,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    54,    -1,    56,    -1,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   146,    -1,    -1,
     180,    -1,    -1,    -1,   153,   154,   155,   156,   157,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   146,   147,   148,   180,    -1,
      -1,    -1,   153,   154,   155,   156,   157,   189,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,    -1,    -1,    -1,   176,     3,     4,    -1,    -1,
     181,    -1,     9,    10,    11,   186,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    68,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,
       3,     4,    -1,    -1,   181,    -1,     9,    10,    11,   186,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    58,    59,    60,    -1,     9,
      10,    11,    -1,    66,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    66,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   189,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,   181,    -1,
      -1,   184,    -1,   186,    -1,    -1,    -1,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,   146,    -1,    -1,    12,
      13,    -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,    -1,    37,    38,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,   186,    50,    51,    52,
      -1,    -1,    55,    -1,    57,    -1,    -1,    -1,    61,    62,
      -1,    64,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,   120,     4,    -1,
      -1,    -1,   125,   126,   127,   128,    12,    13,   131,    -1,
     133,    -1,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    61,    62,    -1,    64,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    -1,    -1,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,   131,    -1,   133,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,   150,   151,   152,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,   182,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,   187,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,   184,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,   184,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,    -1,    -1,   184,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,   184,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
     184,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,   184,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,   184,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,   184,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,   184,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,   182,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,   182,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,   182,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,   182,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
     182,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,   182,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,   182,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,   182,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,   182,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,   182,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
     182,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,   182,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,   182,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,   182,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,   182,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,   182,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
     182,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,   182,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,   182,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,   182,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,   182,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,   182,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   192,   193,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    55,    57,    61,    62,    64,    65,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   112,
     113,   114,   120,   125,   126,   127,   128,   131,   133,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     149,   150,   151,   152,   194,   196,   197,   217,   234,   235,
     238,   239,   240,   241,   242,   243,   244,   265,   266,   267,
     268,   286,   287,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    53,    54,    56,    58,    59,    60,    66,    67,
     140,   146,   147,   148,   153,   154,   155,   156,   157,   171,
     172,   176,   181,   183,   185,   186,   188,   190,   215,   269,
     270,   282,   283,   286,   287,    13,    74,   181,   181,     6,
     188,     6,     6,     6,   181,     6,     6,   183,   183,   181,
     188,   181,   181,     4,   181,   188,   181,   181,     4,   188,
     181,   181,    78,    74,    74,     6,   188,    68,    71,    74,
      74,    74,    71,    74,    76,    76,    68,    71,    74,    76,
      71,    74,    76,    71,    74,   181,    71,   131,   144,   145,
     188,   171,   172,   181,   188,   272,   273,   272,   188,    68,
      71,    74,   188,   272,     4,    68,    72,    84,    74,    76,
      74,    71,     4,   140,   188,     4,     6,    68,    71,    74,
      71,    74,     4,     4,     4,     4,     5,    36,    68,    71,
      74,    76,    88,   172,   181,   188,   235,   244,   269,   275,
     276,   277,   286,   287,     4,   181,   181,   181,     4,   188,
     279,     4,   181,   181,     6,     6,   183,     4,   286,   287,
       4,     5,   188,     5,   188,     4,   269,     6,   181,   188,
     181,   183,   190,   215,     7,   158,   159,   160,   161,   178,
     179,   213,   214,     4,   183,   185,   183,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   181,   181,   181,   181,   181,   181,   215,   181,
     215,   215,   215,     7,   181,   181,   181,   181,   181,   269,
     269,   269,   269,   184,   269,     4,   131,   132,   287,     4,
     235,   236,   237,   188,   188,     6,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     180,   188,     6,   183,   214,     6,   269,     4,   282,   283,
     287,   282,   269,   282,   285,   219,   222,   269,   172,   269,
     277,   278,   269,   269,   181,   269,   278,   269,   269,   181,
     278,   269,   269,   275,   181,   188,   278,   276,   276,   276,
     181,   181,   276,   276,   276,   181,   181,   181,   181,   181,
     181,   181,   181,   275,   269,     4,   275,   279,   188,   188,
     272,   272,   272,   269,   269,   171,   172,   188,   188,   272,
     188,   188,   188,   171,   172,   181,   237,   272,   188,   181,
     188,   181,   181,   181,   276,   276,   275,   181,     4,     6,
     183,   183,   237,     6,   188,   188,   188,   276,   276,   183,
     183,   183,   183,   185,   215,   183,     5,   134,   188,     5,
     134,     5,   134,     5,   134,    68,    71,    74,    76,   188,
     269,   277,   269,   189,   278,     8,   173,     6,   183,   215,
       6,   269,   269,   269,   185,   269,   188,   134,   269,   269,
     269,     6,     6,   237,     6,   237,   183,     6,   275,   275,
     184,   269,   188,   188,   283,   275,     6,   183,   269,     4,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   285,   282,   285,   282,   282,   282,   275,   282,
     282,   269,   285,   282,   269,   283,   269,   282,   282,   282,
     287,   283,   182,     7,   213,   184,     7,   213,   214,   185,
       7,   183,   189,    68,    71,    74,    76,   234,   269,   278,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   198,   269,     6,   183,   185,
     182,   187,   182,   187,   187,   182,   187,   184,   187,   218,
     184,   218,   182,   173,   187,   189,   182,   182,   269,   182,
     189,   182,   182,   269,   189,   182,   182,     7,   269,   269,
     189,     6,     6,     6,   269,   269,     7,     7,   262,   262,
     269,   228,   269,   283,   229,   269,   283,   230,   269,   283,
     231,   269,   283,   269,   269,   269,     7,   188,   182,     6,
     188,   237,   237,   187,   187,   187,   272,   272,   236,   236,
     187,   269,   269,   269,   269,   248,   187,   237,   269,   269,
     269,   269,   269,     7,   263,     6,     7,   269,     6,   269,
     269,   189,   278,   278,   278,     6,     6,   269,   269,   269,
     269,     4,   182,   184,   188,   216,   287,    50,   269,    50,
      50,    50,     5,   188,     5,   188,     5,   188,     5,   188,
     278,   182,   189,   269,   188,   269,   277,   188,   216,   182,
     182,   182,   131,   187,   237,   188,     8,   182,   184,   189,
     189,   182,   187,   189,   213,   184,   269,   278,     6,     6,
     269,   184,   214,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   187,   216,   216,   216,   216,   216,
     216,   216,   187,   187,   187,   216,   187,   216,   216,   182,
     182,   187,   187,   187,   187,   187,   182,   216,   271,   284,
       6,   187,   182,   187,   182,   182,   213,   275,   185,   213,
     214,   283,   269,     6,     4,     4,   188,   280,   184,   188,
     188,   188,   188,   189,   189,     8,     4,   121,   122,   123,
     124,   189,   201,   205,   208,   210,   211,   184,   269,     4,
       6,   168,   195,   278,     6,   278,   269,     6,   282,     6,
     287,     6,   282,     7,   269,   277,   134,     7,     7,   182,
       7,   134,     7,     7,   182,   134,     7,     7,   269,   182,
     189,   188,   182,   182,   269,   275,     4,   261,     6,   182,
     182,   182,   182,   182,   182,   182,   182,   275,   278,   185,
     237,   189,   189,   272,   269,   269,   189,   189,   269,   272,
     187,   187,   187,    91,   101,   109,   110,   111,   115,   116,
     117,   118,   258,   259,   272,   189,   245,   182,   189,   182,
     182,   182,   269,     6,   269,   182,   184,   184,   189,   189,
     189,   184,   184,   187,   184,   278,   184,   188,   189,   188,
     188,   188,   278,   278,   278,   278,   189,     8,   278,   278,
       7,     7,     7,   185,   269,   189,   269,   269,     7,   185,
     188,   275,     6,   275,   213,   214,   189,   189,   184,   185,
     214,   282,   269,   269,   269,   269,   278,   282,   275,   282,
     282,   283,   224,   226,   269,   282,   269,     6,     4,   131,
     132,   269,     6,     6,     6,     7,   183,   279,   281,     6,
     278,   278,   278,   278,   216,   269,   202,   181,   181,   188,
     212,     6,   214,   184,   168,   282,   182,   182,   187,     7,
     272,    74,    76,   275,   275,     7,   275,    74,    76,   275,
     275,     7,    76,   275,   275,     6,     7,     7,   278,     7,
       7,    91,   260,     6,     7,   213,   213,   213,   213,     7,
       7,     7,     6,   189,     4,   189,   187,   187,   187,   189,
     189,   272,   272,   272,     4,     6,   188,     6,   181,     6,
     119,     6,   119,     6,   119,     6,   119,   189,   259,   187,
     258,     7,     6,     7,     7,     7,     6,   188,     6,     6,
       6,    74,   269,     6,     6,   269,   185,   189,   269,   269,
     269,   269,   189,   189,   189,   189,   269,   189,   189,   275,
     275,   275,     4,   187,     8,     8,   182,     4,     4,   275,
     189,     6,   269,     6,   216,     6,     4,     6,   216,   216,
     216,   216,   216,   187,   182,   182,   182,   187,   187,   216,
     225,   187,   216,   227,   182,   182,     6,     7,   213,   214,
     185,     7,     6,   279,   269,   187,   189,   189,   189,   189,
     189,   213,   181,   269,   269,   274,   275,   188,   185,     6,
       6,   195,     6,   269,   188,   269,   283,     6,   188,   188,
      84,   233,   233,   275,     6,   188,   188,     6,     6,   275,
     188,     6,     6,     5,   275,   189,   275,   275,     4,     6,
     275,   275,   275,   275,   275,   275,   275,   275,     7,     6,
       7,   269,   269,   269,   188,   188,   187,   189,   187,   189,
     187,   189,   183,   269,   275,   269,     6,     6,     6,     6,
     269,   272,   189,     5,   188,   275,   188,   188,   188,   275,
     278,   188,     6,   184,     4,   216,   187,   187,   187,   187,
     216,     6,     6,   130,   269,   269,   269,     6,     6,     7,
     187,     6,     6,   213,   214,   282,   283,     4,     4,   283,
     269,     6,     4,   280,     6,   184,   279,     6,     6,     6,
       6,   275,   199,   269,   187,   187,   187,   189,   200,   269,
       4,   282,   187,   269,   283,   269,   269,   272,     6,     6,
       6,   269,   269,     6,   269,     5,     6,   188,     6,   134,
     232,   269,     6,     6,     6,     6,     6,     6,     4,     6,
       6,   269,   269,   283,   189,   182,   187,   189,   236,   236,
     272,     6,   249,   272,     6,   250,   272,     6,   251,   269,
     189,   187,   182,   189,   187,     6,   172,   272,     6,   274,
     272,   272,     6,   189,   269,     6,   269,   269,   269,   269,
     275,   187,   189,     8,   189,   182,   188,   269,   283,   275,
     275,   182,   216,   188,   275,   283,   188,   269,   283,     6,
       6,     7,     6,   185,     6,   182,   187,   269,   269,   275,
     188,   187,   189,     6,   269,   220,   221,   189,   189,   189,
     189,   189,     5,   274,    72,     6,   188,   188,     6,     6,
     188,   269,   189,   189,   187,   188,   187,   188,   187,   188,
     184,     6,   275,     7,   188,   269,   187,   189,   187,   187,
       6,   189,   187,   187,   187,   187,   129,   269,   269,   278,
       6,     6,   189,     6,   223,   269,   285,   279,   132,   203,
     269,   187,   187,   274,   269,     6,   187,   224,   226,     6,
       6,     6,     6,     6,     6,   189,   188,   274,   278,   236,
     187,   189,   269,   272,   258,   269,   272,   258,   269,   272,
     258,     6,   187,   189,   275,   237,   189,   272,     6,   278,
     272,   269,   269,   269,   269,   269,   189,   189,   189,     6,
     187,   189,     7,   189,     6,   188,   269,   269,   189,   269,
     189,   189,   188,   269,   189,   189,   189,   269,   189,   187,
     189,   189,   187,   189,   189,   187,   189,   275,     6,    91,
     189,   246,   188,   187,   189,   187,   187,   187,   187,   187,
       6,     6,   269,   283,   200,   182,   187,     6,   188,   187,
     269,   189,     6,    91,   264,   189,     6,   252,   269,     6,
       6,   253,   269,     6,     6,   254,   269,     6,   189,   269,
     258,   237,   278,     6,   272,   278,   269,   269,   269,   269,
       7,   189,   206,   269,   274,   269,   187,   275,     6,   188,
     189,   188,   189,   188,   189,     6,     6,   189,   189,   247,
     189,   187,   189,   187,   187,   187,   187,   283,     6,   188,
     182,   189,   189,   269,   258,     6,   255,   258,     6,   256,
     258,     6,   257,   258,     6,   278,     6,   269,   269,   269,
     269,   204,   282,   209,   188,     6,   189,   189,   188,   189,
     188,   189,   188,   189,   189,   187,   187,   187,   187,   187,
     189,   188,   274,     6,     6,   258,     6,   258,     6,   258,
       6,   269,   269,   269,   269,   282,     6,   207,   282,   189,
     189,   189,   189,   189,   189,   189,   189,   187,   189,     6,
       6,     6,     6,   282,     6
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

  case 139:
/* Line 1787 of yacc.c  */
#line 1404 "Gmsh.y"
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
#line 1427 "Gmsh.y"
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
#line 1445 "Gmsh.y"
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
#line 1466 "Gmsh.y"
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
#line 1484 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1544 "Gmsh.y"
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
#line 1562 "Gmsh.y"
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
#line 1581 "Gmsh.y"
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
#line 1607 "Gmsh.y"
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
#line 1625 "Gmsh.y"
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
#line 1643 "Gmsh.y"
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

  case 151:
/* Line 1787 of yacc.c  */
#line 1678 "Gmsh.y"
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
#line 1696 "Gmsh.y"
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
#line 1735 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1741 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1747 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1754 "Gmsh.y"
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
#line 1779 "Gmsh.y"
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
#line 1804 "Gmsh.y"
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
#line 1821 "Gmsh.y"
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
#line 1841 "Gmsh.y"
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
#line 1874 "Gmsh.y"
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

  case 162:
/* Line 1787 of yacc.c  */
#line 1910 "Gmsh.y"
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
#line 1928 "Gmsh.y"
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
#line 1945 "Gmsh.y"
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
#line 1961 "Gmsh.y"
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

  case 166:
/* Line 1787 of yacc.c  */
#line 1998 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 2003 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 2008 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 2013 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 2018 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 2023 "Gmsh.y"
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
#line 2046 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 2052 "Gmsh.y"
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
#line 2062 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 2063 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2068 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2072 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2076 "Gmsh.y"
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
#line 2099 "Gmsh.y"
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
#line 2122 "Gmsh.y"
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
#line 2145 "Gmsh.y"
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
#line 2173 "Gmsh.y"
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
#line 2194 "Gmsh.y"
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
#line 2221 "Gmsh.y"
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
#line 2242 "Gmsh.y"
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
#line 2263 "Gmsh.y"
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
#line 2283 "Gmsh.y"
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
#line 2395 "Gmsh.y"
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
#line 2414 "Gmsh.y"
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
#line 2453 "Gmsh.y"
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
#line 2561 "Gmsh.y"
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
#line 2570 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 2576 "Gmsh.y"
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
#line 2591 "Gmsh.y"
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
#line 2619 "Gmsh.y"
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
#line 2636 "Gmsh.y"
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
#line 2645 "Gmsh.y"
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
#line 2659 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2665 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2671 "Gmsh.y"
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
#line 2680 "Gmsh.y"
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
#line 2689 "Gmsh.y"
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
#line 2698 "Gmsh.y"
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
#line 2712 "Gmsh.y"
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
#line 2768 "Gmsh.y"
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
#line 2786 "Gmsh.y"
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
#line 2803 "Gmsh.y"
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
#line 2818 "Gmsh.y"
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
#line 2837 "Gmsh.y"
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
#line 2849 "Gmsh.y"
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
#line 2873 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2877 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 2882 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2889 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2895 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2900 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2906 "Gmsh.y"
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
#line 2914 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2918 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2922 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2928 "Gmsh.y"
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
#line 2982 "Gmsh.y"
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
#line 2995 "Gmsh.y"
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
#line 3012 "Gmsh.y"
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
#line 3029 "Gmsh.y"
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
#line 3050 "Gmsh.y"
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
#line 3071 "Gmsh.y"
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
#line 3106 "Gmsh.y"
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
#line 3114 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 3120 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3127 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3131 "Gmsh.y"
    {
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3140 "Gmsh.y"
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
#line 3148 "Gmsh.y"
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
#line 3156 "Gmsh.y"
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
#line 3164 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3170 "Gmsh.y"
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
#line 3178 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3184 "Gmsh.y"
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
#line 3192 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3198 "Gmsh.y"
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
#line 3206 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3212 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3220 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3227 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3234 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3241 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3248 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3255 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3262 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3269 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3276 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3283 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3289 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
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
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3309 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3322 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3335 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3348 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3361 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3367 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3374 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3380 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3387 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3393 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3404 "Gmsh.y"
    {
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3407 "Gmsh.y"
    {
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3413 "Gmsh.y"
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
#line 3425 "Gmsh.y"
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
#line 3445 "Gmsh.y"
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
#line 3469 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3473 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3477 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3481 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3485 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3491 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3497 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3501 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3505 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3509 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3513 "Gmsh.y"
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
#line 3532 "Gmsh.y"
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
#line 3544 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3548 "Gmsh.y"
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
#line 3563 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3567 "Gmsh.y"
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
#line 3583 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3587 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3592 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3596 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3602 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3606 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3613 "Gmsh.y"
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
#line 3669 "Gmsh.y"
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
#line 3739 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3744 "Gmsh.y"
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
#line 3811 "Gmsh.y"
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
#line 3847 "Gmsh.y"
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
#line 3855 "Gmsh.y"
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
#line 3898 "Gmsh.y"
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
#line 3937 "Gmsh.y"
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
#line 3957 "Gmsh.y"
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
#line 3985 "Gmsh.y"
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
#line 4033 "Gmsh.y"
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
#line 4061 "Gmsh.y"
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
#line 4089 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 4093 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 4097 "Gmsh.y"
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
#line 4125 "Gmsh.y"
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
#line 4164 "Gmsh.y"
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
#line 4203 "Gmsh.y"
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
#line 4224 "Gmsh.y"
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
#line 4245 "Gmsh.y"
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
#line 4272 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 4276 "Gmsh.y"
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
#line 4286 "Gmsh.y"
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
#line 4320 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 4321 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4322 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4327 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
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
#line 4345 "Gmsh.y"
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
#line 4363 "Gmsh.y"
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
#line 4390 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4391 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4392 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4393 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4394 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4395 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4396 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4397 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4399 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4405 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4406 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4407 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4408 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4409 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4410 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4411 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4412 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4413 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4414 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4416 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4417 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4418 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4419 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4420 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4421 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4422 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4423 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4424 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4425 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4426 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4427 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4428 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4429 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4430 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4431 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4432 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4433 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4434 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4435 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4436 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4437 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4446 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4447 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4448 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4449 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4450 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4451 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4452 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4453 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4454 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4455 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4460 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4462 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
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
#line 4485 "Gmsh.y"
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
#line 4503 "Gmsh.y"
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
#line 4521 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4526 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4532 "Gmsh.y"
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
#line 4544 "Gmsh.y"
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
#line 4561 "Gmsh.y"
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
#line 4579 "Gmsh.y"
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
#line 4600 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4605 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4610 "Gmsh.y"
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
#line 4620 "Gmsh.y"
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
#line 4630 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4635 "Gmsh.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 4646 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4655 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4660 "Gmsh.y"
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

  case 401:
/* Line 1787 of yacc.c  */
#line 4687 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4691 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4695 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4699 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4703 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4710 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4714 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4718 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4722 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4729 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4734 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4741 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4746 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4750 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4755 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4759 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4767 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4778 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4782 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4794 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4802 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4810 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4817 "Gmsh.y"
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

  case 424:
/* Line 1787 of yacc.c  */
#line 4827 "Gmsh.y"
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

  case 425:
/* Line 1787 of yacc.c  */
#line 4856 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4860 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4864 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4868 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4872 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4876 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4880 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4884 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4888 "Gmsh.y"
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

  case 434:
/* Line 1787 of yacc.c  */
#line 4917 "Gmsh.y"
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

  case 435:
/* Line 1787 of yacc.c  */
#line 4946 "Gmsh.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 4975 "Gmsh.y"
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

  case 437:
/* Line 1787 of yacc.c  */
#line 5005 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 5018 "Gmsh.y"
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

  case 439:
/* Line 1787 of yacc.c  */
#line 5031 "Gmsh.y"
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

  case 440:
/* Line 1787 of yacc.c  */
#line 5044 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 5056 "Gmsh.y"
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
#line 5066 "Gmsh.y"
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

  case 443:
/* Line 1787 of yacc.c  */
#line 5076 "Gmsh.y"
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
#line 5088 "Gmsh.y"
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

  case 445:
/* Line 1787 of yacc.c  */
#line 5100 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 5112 "Gmsh.y"
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
#line 5130 "Gmsh.y"
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

  case 448:
/* Line 1787 of yacc.c  */
#line 5151 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5156 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5160 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5164 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5176 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5180 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5192 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5199 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5209 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5213 "Gmsh.y"
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

  case 458:
/* Line 1787 of yacc.c  */
#line 5228 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5233 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5240 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5244 "Gmsh.y"
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

  case 462:
/* Line 1787 of yacc.c  */
#line 5257 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5265 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5276 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5280 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5288 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5294 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5302 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5310 "Gmsh.y"
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

  case 470:
/* Line 1787 of yacc.c  */
#line 5325 "Gmsh.y"
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

  case 471:
/* Line 1787 of yacc.c  */
#line 5339 "Gmsh.y"
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

  case 472:
/* Line 1787 of yacc.c  */
#line 5353 "Gmsh.y"
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

  case 473:
/* Line 1787 of yacc.c  */
#line 5365 "Gmsh.y"
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

  case 474:
/* Line 1787 of yacc.c  */
#line 5381 "Gmsh.y"
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

  case 475:
/* Line 1787 of yacc.c  */
#line 5392 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5396 "Gmsh.y"
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

  case 477:
/* Line 1787 of yacc.c  */
#line 5415 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5422 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5424 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5435 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5440 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5446 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5455 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5468 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 485:
/* Line 1787 of yacc.c  */
#line 5471 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11481 "Gmsh.tab.cpp"
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
#line 5475 "Gmsh.y"


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
