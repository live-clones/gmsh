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
     tPoint = 324,
     tCircle = 325,
     tEllipse = 326,
     tLine = 327,
     tSphere = 328,
     tPolarSphere = 329,
     tSurface = 330,
     tSpline = 331,
     tVolume = 332,
     tCharacteristic = 333,
     tLength = 334,
     tParametric = 335,
     tElliptic = 336,
     tRefineMesh = 337,
     tAdaptMesh = 338,
     tRelocateMesh = 339,
     tPlane = 340,
     tRuled = 341,
     tTransfinite = 342,
     tComplex = 343,
     tPhysical = 344,
     tCompound = 345,
     tPeriodic = 346,
     tUsing = 347,
     tPlugin = 348,
     tDegenerated = 349,
     tRecursive = 350,
     tRotate = 351,
     tTranslate = 352,
     tSymmetry = 353,
     tDilate = 354,
     tExtrude = 355,
     tLevelset = 356,
     tRecombine = 357,
     tSmoother = 358,
     tSplit = 359,
     tDelete = 360,
     tCoherence = 361,
     tIntersect = 362,
     tMeshAlgorithm = 363,
     tReverse = 364,
     tLayers = 365,
     tScaleLast = 366,
     tHole = 367,
     tAlias = 368,
     tAliasWithOptions = 369,
     tCopyOptions = 370,
     tQuadTriAddVerts = 371,
     tQuadTriNoNewVerts = 372,
     tQuadTriSngl = 373,
     tQuadTriDbl = 374,
     tRecombLaterals = 375,
     tTransfQuadTri = 376,
     tText2D = 377,
     tText3D = 378,
     tInterpolationScheme = 379,
     tTime = 380,
     tCombine = 381,
     tBSpline = 382,
     tBezier = 383,
     tNurbs = 384,
     tNurbsOrder = 385,
     tNurbsKnots = 386,
     tColor = 387,
     tColorTable = 388,
     tFor = 389,
     tIn = 390,
     tEndFor = 391,
     tIf = 392,
     tEndIf = 393,
     tExit = 394,
     tAbort = 395,
     tField = 396,
     tReturn = 397,
     tCall = 398,
     tFunction = 399,
     tShow = 400,
     tHide = 401,
     tGetValue = 402,
     tGetEnv = 403,
     tGetString = 404,
     tHomology = 405,
     tCohomology = 406,
     tBetti = 407,
     tSetOrder = 408,
     tExists = 409,
     tFileExists = 410,
     tGMSH_MAJOR_VERSION = 411,
     tGMSH_MINOR_VERSION = 412,
     tGMSH_PATCH_VERSION = 413,
     tAFFECTDIVIDE = 414,
     tAFFECTTIMES = 415,
     tAFFECTMINUS = 416,
     tAFFECTPLUS = 417,
     tOR = 418,
     tAND = 419,
     tNOTEQUAL = 420,
     tEQUAL = 421,
     tGREATEROREQUAL = 422,
     tLESSOREQUAL = 423,
     UNARYPREC = 424,
     tMINUSMINUS = 425,
     tPLUSPLUS = 426
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
#line 398 "Gmsh.tab.cpp"
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
#line 426 "Gmsh.tab.cpp"

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
#define YYLAST   9436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  192
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  486
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1717

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   426

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   177,     2,   187,     2,   176,     2,     2,
     182,   183,   174,   172,   188,   173,   186,   175,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     168,     2,   169,   163,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   184,     2,   185,   181,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   189,     2,   190,   191,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   164,   165,
     166,   167,   170,   171,   178,   179,   180
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
    1208,  1212,  1215,  1218,  1221,  1224,  1227,  1243,  1246,  1249,
    1252,  1255,  1258,  1275,  1279,  1286,  1295,  1304,  1315,  1317,
    1320,  1322,  1326,  1331,  1333,  1339,  1351,  1365,  1366,  1374,
    1375,  1389,  1390,  1406,  1407,  1414,  1423,  1432,  1441,  1454,
    1467,  1480,  1495,  1510,  1525,  1526,  1539,  1540,  1553,  1554,
    1567,  1568,  1585,  1586,  1603,  1604,  1621,  1622,  1641,  1642,
    1661,  1662,  1681,  1683,  1686,  1692,  1700,  1710,  1713,  1716,
    1719,  1723,  1726,  1730,  1733,  1737,  1740,  1744,  1754,  1761,
    1762,  1766,  1767,  1769,  1770,  1773,  1774,  1777,  1778,  1781,
    1789,  1796,  1805,  1811,  1815,  1823,  1829,  1834,  1841,  1848,
    1862,  1873,  1884,  1895,  1906,  1917,  1922,  1927,  1932,  1937,
    1942,  1945,  1949,  1956,  1958,  1960,  1962,  1965,  1971,  1979,
    1990,  1992,  1996,  1999,  2002,  2005,  2009,  2013,  2017,  2021,
    2025,  2029,  2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,
    2067,  2072,  2077,  2082,  2087,  2092,  2097,  2102,  2107,  2112,
    2117,  2124,  2129,  2134,  2139,  2144,  2149,  2154,  2159,  2166,
    2173,  2180,  2185,  2187,  2189,  2191,  2193,  2195,  2197,  2199,
    2201,  2203,  2205,  2206,  2213,  2215,  2220,  2225,  2230,  2235,
    2240,  2243,  2249,  2255,  2259,  2266,  2271,  2279,  2286,  2293,
    2300,  2307,  2312,  2314,  2317,  2320,  2324,  2328,  2340,  2350,
    2358,  2366,  2368,  2372,  2374,  2376,  2379,  2383,  2388,  2394,
    2396,  2398,  2401,  2405,  2409,  2415,  2420,  2423,  2426,  2429,
    2432,  2436,  2440,  2444,  2448,  2454,  2460,  2466,  2472,  2489,
    2506,  2523,  2540,  2542,  2544,  2548,  2552,  2557,  2564,  2571,
    2573,  2575,  2579,  2583,  2593,  2601,  2603,  2609,  2613,  2620,
    2622,  2626,  2628,  2630,  2634,  2641,  2643,  2645,  2647,  2652,
    2659,  2664,  2669,  2674,  2683,  2688,  2697,  2702,  2709,  2714,
    2715,  2722,  2724,  2728,  2734,  2740,  2742
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     193,     0,    -1,   194,    -1,     1,     6,    -1,    -1,   194,
     195,    -1,   198,    -1,   197,    -1,   218,    -1,   235,    -1,
     236,    -1,   240,    -1,   241,    -1,   242,    -1,   245,    -1,
     266,    -1,   267,    -1,   244,    -1,   243,    -1,   239,    -1,
     269,    -1,   169,    -1,   169,   169,    -1,    37,   182,   283,
     183,     6,    -1,    38,   182,   283,   183,     6,    -1,    37,
     182,   283,   183,   196,   283,     6,    -1,    37,   182,   283,
     188,   279,   183,     6,    -1,    38,   182,   283,   188,   279,
     183,     6,    -1,    37,   182,   283,   188,   279,   183,   196,
     283,     6,    -1,     4,   283,   189,   199,   190,     6,    -1,
     113,     4,   184,   270,   185,     6,    -1,   114,     4,   184,
     270,   185,     6,    -1,   115,     4,   184,   270,   188,   270,
     185,     6,    -1,    -1,   199,   202,    -1,   199,   206,    -1,
     199,   209,    -1,   199,   211,    -1,   199,   212,    -1,   270,
      -1,   200,   188,   270,    -1,   270,    -1,   201,   188,   270,
      -1,    -1,    -1,     4,   203,   182,   200,   183,   204,   189,
     201,   190,     6,    -1,   283,    -1,   205,   188,   283,    -1,
      -1,   122,   182,   270,   188,   270,   188,   270,   183,   207,
     189,   205,   190,     6,    -1,   283,    -1,   208,   188,   283,
      -1,    -1,   123,   182,   270,   188,   270,   188,   270,   188,
     270,   183,   210,   189,   208,   190,     6,    -1,   124,   189,
     275,   190,   189,   275,   190,     6,    -1,   124,   189,   275,
     190,   189,   275,   190,   189,   275,   190,   189,   275,   190,
       6,    -1,    -1,   125,   213,   189,   201,   190,     6,    -1,
       7,    -1,   162,    -1,   161,    -1,   160,    -1,   159,    -1,
     180,    -1,   179,    -1,   182,    -1,   184,    -1,   183,    -1,
     185,    -1,    65,   184,   220,   185,     6,    -1,    66,   184,
     223,   185,     6,    -1,   288,   214,   276,     6,    -1,     4,
     184,   185,   214,   276,     6,    -1,   287,   184,   185,   214,
     276,     6,    -1,     4,   184,   270,   185,   214,   270,     6,
      -1,     4,   182,   270,   183,   214,   270,     6,    -1,   287,
     184,   270,   185,   214,   270,     6,    -1,     4,   216,   189,
     279,   190,   217,   214,   276,     6,    -1,   287,   216,   189,
     279,   190,   217,   214,   276,     6,    -1,   288,   215,     6,
      -1,     4,   184,   270,   185,   215,     6,    -1,   287,   184,
     270,   185,   215,     6,    -1,   288,     7,   284,     6,    -1,
       4,   186,     4,     7,   284,     6,    -1,     4,   184,   270,
     185,   186,     4,     7,   284,     6,    -1,     4,   186,     4,
     214,   270,     6,    -1,     4,   184,   270,   185,   186,     4,
     214,   270,     6,    -1,     4,   186,     4,   215,     6,    -1,
       4,   184,   270,   185,   186,     4,   215,     6,    -1,     4,
     186,   132,   186,     4,     7,   280,     6,    -1,     4,   184,
     270,   185,   186,   132,   186,     4,     7,   280,     6,    -1,
       4,   186,   133,     7,   281,     6,    -1,     4,   184,   270,
     185,   186,   133,     7,   281,     6,    -1,     4,   141,     7,
     270,     6,    -1,   141,   184,   270,   185,     7,     4,     6,
      -1,   141,   184,   270,   185,   186,     4,     7,   270,     6,
      -1,   141,   184,   270,   185,   186,     4,     7,   284,     6,
      -1,   141,   184,   270,   185,   186,     4,     7,   189,   279,
     190,     6,    -1,   141,   184,   270,   185,   186,     4,     6,
      -1,    93,   182,     4,   183,   186,     4,     7,   270,     6,
      -1,    93,   182,     4,   183,   186,     4,     7,   284,     6,
      -1,    -1,   188,    -1,    -1,   220,   219,   288,    -1,   220,
     219,   288,     7,   270,    -1,    -1,   220,   219,   288,     7,
     189,   270,   221,   225,   190,    -1,   220,   219,   288,     7,
     284,    -1,    -1,   220,   219,   288,     7,   189,   284,   222,
     227,   190,    -1,    -1,   223,   219,   283,    -1,   270,     7,
     284,    -1,   224,   188,   270,     7,   284,    -1,    -1,   225,
     226,    -1,   188,     4,   276,    -1,   188,     4,   189,   224,
     190,    -1,   188,     4,   284,    -1,    -1,   227,   228,    -1,
     188,     4,   270,    -1,   188,     4,   284,    -1,   188,     4,
     189,   286,   190,    -1,   270,    -1,   284,    -1,   270,    -1,
     284,    -1,   270,    -1,   284,    -1,   270,    -1,   284,    -1,
      -1,   135,    73,   189,   270,   190,    -1,    -1,    85,   273,
      -1,    69,   182,   270,   183,     7,   273,     6,    -1,    89,
      69,   182,   229,   183,   214,   276,     6,    -1,    78,    79,
     276,     7,   270,     6,    -1,    72,   182,   270,   183,     7,
     276,     6,    -1,    94,    72,   276,     6,    -1,    76,   182,
     270,   183,     7,   276,     6,    -1,    70,   182,   270,   183,
       7,   276,   234,     6,    -1,    71,   182,   270,   183,     7,
     276,   234,     6,    -1,   127,   182,   270,   183,     7,   276,
       6,    -1,   128,   182,   270,   183,     7,   276,     6,    -1,
     129,   182,   270,   183,     7,   276,   131,   276,   130,   270,
       6,    -1,    72,     4,   182,   270,   183,     7,   276,     6,
      -1,    90,    72,   182,   270,   183,     7,   276,     6,    -1,
      89,    72,   182,   230,   183,   214,   276,     6,    -1,    85,
      75,   182,   270,   183,     7,   276,     6,    -1,    86,    75,
     182,   270,   183,     7,   276,   233,     6,    -1,    12,    13,
       6,    -1,    13,    75,   270,     6,    -1,    80,    75,   182,
     270,   183,     7,     5,     5,     5,     6,    -1,    73,   182,
     270,   183,     7,   276,     6,    -1,    74,   182,   270,   183,
       7,   276,     6,    -1,    75,     4,   182,   270,   183,     7,
     276,     6,    -1,    90,    75,   182,   270,   183,     7,   276,
       6,    -1,    90,    75,   182,   270,   183,     7,   276,     4,
     189,   275,   190,     6,    -1,    89,    75,   182,   231,   183,
     214,   276,     6,    -1,    88,    77,   182,   270,   183,     7,
     276,     6,    -1,    77,   182,   270,   183,     7,   276,     6,
      -1,    90,    77,   182,   270,   183,     7,   276,     6,    -1,
      89,    77,   182,   232,   183,   214,   276,     6,    -1,    97,
     273,   189,   237,   190,    -1,    96,   189,   273,   188,   273,
     188,   270,   190,   189,   237,   190,    -1,    98,   273,   189,
     237,   190,    -1,    99,   189,   273,   188,   270,   190,   189,
     237,   190,    -1,    99,   189,   273,   188,   273,   190,   189,
     237,   190,    -1,     4,   189,   237,   190,    -1,   107,    72,
     189,   279,   190,    75,   189,   270,   190,    -1,   104,    72,
     182,   270,   183,   189,   279,   190,     6,    -1,   238,    -1,
     236,    -1,    -1,   238,   235,    -1,   238,    69,   189,   279,
     190,     6,    -1,   238,    72,   189,   279,   190,     6,    -1,
     238,    75,   189,   279,   190,     6,    -1,   238,    77,   189,
     279,   190,     6,    -1,   101,    85,   182,   270,   183,     7,
     276,     6,    -1,   101,    69,   182,   270,   183,     7,   189,
     275,   190,     6,    -1,   101,    85,   182,   270,   183,     7,
     189,   273,   188,   273,   188,   279,   190,     6,    -1,   101,
      85,   182,   270,   183,     7,   189,   273,   188,   273,   188,
     273,   188,   279,   190,     6,    -1,   101,    73,   182,   270,
     183,     7,   189,   273,   188,   279,   190,     6,    -1,   101,
       4,   182,   270,   183,     7,   276,     6,    -1,   101,     4,
     182,   270,   183,     7,     5,     6,    -1,   101,     4,   189,
     270,   190,     6,    -1,   101,     4,   182,   270,   183,     7,
     189,   273,   188,   273,   188,   279,   190,     6,    -1,   105,
     189,   238,   190,    -1,   105,   141,   184,   270,   185,     6,
      -1,   105,     4,   184,   270,   185,     6,    -1,   105,     4,
       6,    -1,   105,     4,     4,     6,    -1,   132,   280,   189,
     238,   190,    -1,    95,   132,   280,   189,   238,   190,    -1,
     145,     5,     6,    -1,   146,     5,     6,    -1,   145,   189,
     238,   190,    -1,    95,   145,   189,   238,   190,    -1,   146,
     189,   238,   190,    -1,    95,   146,   189,   238,   190,    -1,
       4,   284,     6,    -1,    58,   182,   286,   183,     6,    -1,
       4,     4,   184,   270,   185,   283,     6,    -1,     4,     4,
       4,   184,   270,   185,     6,    -1,     4,   270,     6,    -1,
      93,   182,     4,   183,   186,     4,     6,    -1,   126,     4,
       6,    -1,   139,     6,    -1,   140,     6,    -1,    55,     6,
      -1,    56,     6,    -1,    50,     6,    -1,    50,   189,   270,
     188,   270,   188,   270,   188,   270,   188,   270,   188,   270,
     190,     6,    -1,    51,     6,    -1,    52,     6,    -1,    62,
       6,    -1,    63,     6,    -1,    82,     6,    -1,    83,   189,
     279,   190,   189,   279,   190,   189,   275,   190,   189,   270,
     188,   270,   190,     6,    -1,   153,   270,     6,    -1,   134,
     182,   270,     8,   270,   183,    -1,   134,   182,   270,     8,
     270,     8,   270,   183,    -1,   134,     4,   135,   189,   270,
       8,   270,   190,    -1,   134,     4,   135,   189,   270,     8,
     270,     8,   270,   190,    -1,   136,    -1,   144,     4,    -1,
     142,    -1,   143,   288,     6,    -1,   137,   182,   270,   183,
      -1,   138,    -1,   100,   273,   189,   238,   190,    -1,   100,
     189,   273,   188,   273,   188,   270,   190,   189,   238,   190,
      -1,   100,   189,   273,   188,   273,   188,   273,   188,   270,
     190,   189,   238,   190,    -1,    -1,   100,   273,   189,   238,
     246,   259,   190,    -1,    -1,   100,   189,   273,   188,   273,
     188,   270,   190,   189,   238,   247,   259,   190,    -1,    -1,
     100,   189,   273,   188,   273,   188,   273,   188,   270,   190,
     189,   238,   248,   259,   190,    -1,    -1,   100,   189,   238,
     249,   259,   190,    -1,   100,    69,   189,   270,   188,   273,
     190,     6,    -1,   100,    72,   189,   270,   188,   273,   190,
       6,    -1,   100,    75,   189,   270,   188,   273,   190,     6,
      -1,   100,    69,   189,   270,   188,   273,   188,   273,   188,
     270,   190,     6,    -1,   100,    72,   189,   270,   188,   273,
     188,   273,   188,   270,   190,     6,    -1,   100,    75,   189,
     270,   188,   273,   188,   273,   188,   270,   190,     6,    -1,
     100,    69,   189,   270,   188,   273,   188,   273,   188,   273,
     188,   270,   190,     6,    -1,   100,    72,   189,   270,   188,
     273,   188,   273,   188,   273,   188,   270,   190,     6,    -1,
     100,    75,   189,   270,   188,   273,   188,   273,   188,   273,
     188,   270,   190,     6,    -1,    -1,   100,    69,   189,   270,
     188,   273,   190,   250,   189,   259,   190,     6,    -1,    -1,
     100,    72,   189,   270,   188,   273,   190,   251,   189,   259,
     190,     6,    -1,    -1,   100,    75,   189,   270,   188,   273,
     190,   252,   189,   259,   190,     6,    -1,    -1,   100,    69,
     189,   270,   188,   273,   188,   273,   188,   270,   190,   253,
     189,   259,   190,     6,    -1,    -1,   100,    72,   189,   270,
     188,   273,   188,   273,   188,   270,   190,   254,   189,   259,
     190,     6,    -1,    -1,   100,    75,   189,   270,   188,   273,
     188,   273,   188,   270,   190,   255,   189,   259,   190,     6,
      -1,    -1,   100,    69,   189,   270,   188,   273,   188,   273,
     188,   273,   188,   270,   190,   256,   189,   259,   190,     6,
      -1,    -1,   100,    72,   189,   270,   188,   273,   188,   273,
     188,   273,   188,   270,   190,   257,   189,   259,   190,     6,
      -1,    -1,   100,    75,   189,   270,   188,   273,   188,   273,
     188,   273,   188,   270,   190,   258,   189,   259,   190,     6,
      -1,   260,    -1,   259,   260,    -1,   110,   189,   270,   190,
       6,    -1,   110,   189,   276,   188,   276,   190,     6,    -1,
     110,   189,   276,   188,   276,   188,   276,   190,     6,    -1,
     111,     6,    -1,   102,     6,    -1,   118,     6,    -1,   118,
     120,     6,    -1,   119,     6,    -1,   119,   120,     6,    -1,
     116,     6,    -1,   116,   120,     6,    -1,   117,     6,    -1,
     117,   120,     6,    -1,   112,   182,   270,   183,     7,   276,
      92,   270,     6,    -1,    92,     4,   184,   270,   185,     6,
      -1,    -1,    92,     4,   270,    -1,    -1,     4,    -1,    -1,
       7,   276,    -1,    -1,     7,   270,    -1,    -1,    92,   276,
      -1,    87,    72,   277,     7,   270,   261,     6,    -1,    87,
      75,   277,   263,   262,     6,    -1,    81,    75,   189,   270,
     190,     7,   276,     6,    -1,    87,    77,   277,   263,     6,
      -1,   121,   277,     6,    -1,   108,    75,   189,   279,   190,
     270,     6,    -1,   102,    75,   277,   264,     6,    -1,   102,
      77,   277,     6,    -1,   103,    75,   276,     7,   270,     6,
      -1,    91,    72,   276,     7,   276,     6,    -1,    91,    75,
     270,   189,   279,   190,     7,   270,   189,   279,   190,   265,
       6,    -1,    69,   189,   279,   190,   135,    75,   189,   270,
     190,     6,    -1,    72,   189,   279,   190,   135,    75,   189,
     270,   190,     6,    -1,    69,   189,   279,   190,   135,    77,
     189,   270,   190,     6,    -1,    72,   189,   279,   190,   135,
      77,   189,   270,   190,     6,    -1,    75,   189,   279,   190,
     135,    77,   189,   270,   190,     6,    -1,   109,    75,   277,
       6,    -1,   109,    72,   277,     6,    -1,    84,    69,   277,
       6,    -1,    84,    72,   277,     6,    -1,    84,    75,   277,
       6,    -1,   106,     6,    -1,   106,     4,     6,    -1,   106,
      69,   189,   279,   190,     6,    -1,   150,    -1,   151,    -1,
     152,    -1,   268,     6,    -1,   268,   189,   276,   190,     6,
      -1,   268,   189,   276,   188,   276,   190,     6,    -1,   268,
     182,   276,   183,   189,   276,   188,   276,   190,     6,    -1,
     271,    -1,   182,   270,   183,    -1,   173,   270,    -1,   172,
     270,    -1,   177,   270,    -1,   270,   173,   270,    -1,   270,
     172,   270,    -1,   270,   174,   270,    -1,   270,   175,   270,
      -1,   270,   176,   270,    -1,   270,   181,   270,    -1,   270,
     168,   270,    -1,   270,   169,   270,    -1,   270,   171,   270,
      -1,   270,   170,   270,    -1,   270,   167,   270,    -1,   270,
     166,   270,    -1,   270,   165,   270,    -1,   270,   164,   270,
      -1,   270,   163,   270,     8,   270,    -1,    14,   216,   270,
     217,    -1,    15,   216,   270,   217,    -1,    16,   216,   270,
     217,    -1,    17,   216,   270,   217,    -1,    18,   216,   270,
     217,    -1,    19,   216,   270,   217,    -1,    20,   216,   270,
     217,    -1,    21,   216,   270,   217,    -1,    22,   216,   270,
     217,    -1,    24,   216,   270,   217,    -1,    25,   216,   270,
     188,   270,   217,    -1,    26,   216,   270,   217,    -1,    27,
     216,   270,   217,    -1,    28,   216,   270,   217,    -1,    29,
     216,   270,   217,    -1,    30,   216,   270,   217,    -1,    31,
     216,   270,   217,    -1,    32,   216,   270,   217,    -1,    33,
     216,   270,   188,   270,   217,    -1,    34,   216,   270,   188,
     270,   217,    -1,    35,   216,   270,   188,   270,   217,    -1,
      23,   216,   270,   217,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   156,    -1,   157,    -1,   158,    -1,    59,
      -1,    60,    -1,    61,    -1,    -1,    67,   216,   270,   272,
     225,   217,    -1,   288,    -1,     4,   184,   270,   185,    -1,
     287,   184,   270,   185,    -1,   154,   182,   288,   183,    -1,
     155,   182,   284,   183,    -1,   187,   288,   184,   185,    -1,
     288,   215,    -1,     4,   184,   270,   185,   215,    -1,   287,
     184,   270,   185,   215,    -1,     4,   186,     4,    -1,     4,
     184,   270,   185,   186,     4,    -1,     4,   186,     4,   215,
      -1,     4,   184,   270,   185,   186,     4,   215,    -1,   147,
     182,   283,   188,   270,   183,    -1,    45,   182,   276,   188,
     276,   183,    -1,    46,   182,   283,   188,   283,   183,    -1,
      47,   182,   283,   188,   283,   183,    -1,    49,   182,   286,
     183,    -1,   274,    -1,   173,   273,    -1,   172,   273,    -1,
     273,   173,   273,    -1,   273,   172,   273,    -1,   189,   270,
     188,   270,   188,   270,   188,   270,   188,   270,   190,    -1,
     189,   270,   188,   270,   188,   270,   188,   270,   190,    -1,
     189,   270,   188,   270,   188,   270,   190,    -1,   182,   270,
     188,   270,   188,   270,   183,    -1,   276,    -1,   275,   188,
     276,    -1,   270,    -1,   278,    -1,   189,   190,    -1,   189,
     279,   190,    -1,   173,   189,   279,   190,    -1,   270,   174,
     189,   279,   190,    -1,   276,    -1,     5,    -1,   173,   278,
      -1,   270,   174,   278,    -1,   270,     8,   270,    -1,   270,
       8,   270,     8,   270,    -1,    69,   189,   270,   190,    -1,
      69,     5,    -1,    72,     5,    -1,    75,     5,    -1,    77,
       5,    -1,    89,    69,     5,    -1,    89,    72,     5,    -1,
      89,    75,     5,    -1,    89,    77,     5,    -1,    89,    69,
     189,   279,   190,    -1,    89,    72,   189,   279,   190,    -1,
      89,    75,   189,   279,   190,    -1,    89,    77,   189,   279,
     190,    -1,    69,   135,    50,   189,   270,   188,   270,   188,
     270,   188,   270,   188,   270,   188,   270,   190,    -1,    72,
     135,    50,   189,   270,   188,   270,   188,   270,   188,   270,
     188,   270,   188,   270,   190,    -1,    75,   135,    50,   189,
     270,   188,   270,   188,   270,   188,   270,   188,   270,   188,
     270,   190,    -1,    77,   135,    50,   189,   270,   188,   270,
     188,   270,   188,   270,   188,   270,   188,   270,   190,    -1,
     236,    -1,   245,    -1,     4,   216,   217,    -1,   287,   216,
     217,    -1,    36,   184,   288,   185,    -1,     4,   216,   189,
     279,   190,   217,    -1,   287,   216,   189,   279,   190,   217,
      -1,   270,    -1,   278,    -1,   279,   188,   270,    -1,   279,
     188,   278,    -1,   189,   270,   188,   270,   188,   270,   188,
     270,   190,    -1,   189,   270,   188,   270,   188,   270,   190,
      -1,     4,    -1,     4,   186,   132,   186,     4,    -1,   189,
     282,   190,    -1,     4,   184,   270,   185,   186,   133,    -1,
     280,    -1,   282,   188,   280,    -1,   284,    -1,   288,    -1,
       4,   186,     4,    -1,     4,   184,   270,   185,   186,     4,
      -1,     5,    -1,    53,    -1,    57,    -1,   148,   182,   283,
     183,    -1,   149,   182,   283,   188,   283,   183,    -1,    41,
     216,   286,   217,    -1,    42,   182,   283,   183,    -1,    43,
     182,   283,   183,    -1,    44,   182,   283,   188,   283,   188,
     283,   183,    -1,    39,   216,   286,   217,    -1,    48,   216,
     270,   188,   284,   188,   284,   217,    -1,    40,   216,   283,
     217,    -1,    40,   216,   283,   188,   279,   217,    -1,    54,
     216,   283,   217,    -1,    -1,    68,   216,   284,   285,   227,
     217,    -1,   283,    -1,   286,   188,   283,    -1,     4,   191,
     189,   270,   190,    -1,   287,   191,   189,   270,   190,    -1,
       4,    -1,   287,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   185,   190,   192,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   214,   218,   225,   230,   235,   249,   262,   275,   303,
     317,   330,   343,   362,   367,   368,   369,   370,   371,   375,
     377,   382,   384,   390,   494,   389,   512,   519,   530,   529,
     547,   554,   565,   564,   581,   598,   621,   620,   634,   635,
     636,   637,   638,   642,   643,   649,   649,   650,   650,   656,
     657,   658,   719,   748,   777,   782,   787,   792,   799,   806,
     821,   826,   831,   840,   846,   855,   873,   891,   900,   912,
     917,   925,   945,   968,   979,   987,  1009,  1032,  1058,  1079,
    1091,  1105,  1105,  1107,  1109,  1118,  1128,  1127,  1139,  1149,
    1148,  1162,  1164,  1172,  1178,  1185,  1186,  1190,  1201,  1216,
    1226,  1227,  1232,  1240,  1249,  1267,  1271,  1280,  1284,  1293,
    1297,  1306,  1310,  1320,  1323,  1336,  1339,  1349,  1372,  1404,
    1427,  1445,  1466,  1484,  1514,  1544,  1562,  1580,  1607,  1625,
    1643,  1678,  1696,  1735,  1741,  1747,  1754,  1779,  1804,  1821,
    1840,  1874,  1910,  1928,  1945,  1961,  1998,  2003,  2008,  2013,
    2018,  2023,  2046,  2052,  2063,  2064,  2069,  2072,  2076,  2099,
    2122,  2145,  2173,  2194,  2220,  2241,  2263,  2283,  2395,  2414,
    2452,  2561,  2570,  2576,  2591,  2619,  2636,  2645,  2659,  2665,
    2671,  2680,  2689,  2698,  2712,  2768,  2786,  2803,  2818,  2837,
    2849,  2873,  2877,  2882,  2889,  2894,  2900,  2905,  2911,  2919,
    2923,  2927,  2932,  2987,  3000,  3017,  3034,  3055,  3076,  3111,
    3119,  3125,  3132,  3136,  3145,  3153,  3161,  3170,  3169,  3184,
    3183,  3198,  3197,  3212,  3211,  3225,  3232,  3239,  3246,  3253,
    3260,  3267,  3274,  3281,  3289,  3288,  3302,  3301,  3315,  3314,
    3328,  3327,  3341,  3340,  3354,  3353,  3367,  3366,  3380,  3379,
    3393,  3392,  3409,  3412,  3418,  3430,  3450,  3474,  3478,  3482,
    3486,  3490,  3496,  3502,  3506,  3510,  3514,  3518,  3537,  3550,
    3553,  3569,  3572,  3589,  3592,  3598,  3601,  3608,  3611,  3618,
    3674,  3744,  3749,  3816,  3852,  3860,  3903,  3942,  3962,  3989,
    4038,  4066,  4094,  4098,  4102,  4130,  4169,  4208,  4229,  4250,
    4277,  4281,  4291,  4326,  4327,  4328,  4332,  4338,  4350,  4368,
    4396,  4397,  4398,  4399,  4400,  4401,  4402,  4403,  4404,  4411,
    4412,  4413,  4414,  4415,  4416,  4417,  4418,  4419,  4420,  4421,
    4422,  4423,  4424,  4425,  4426,  4427,  4428,  4429,  4430,  4431,
    4432,  4433,  4434,  4435,  4436,  4437,  4438,  4439,  4440,  4441,
    4442,  4443,  4452,  4453,  4454,  4455,  4456,  4457,  4458,  4459,
    4460,  4461,  4466,  4465,  4473,  4490,  4508,  4526,  4531,  4537,
    4549,  4566,  4584,  4605,  4610,  4615,  4625,  4635,  4640,  4651,
    4660,  4665,  4692,  4696,  4700,  4704,  4708,  4715,  4719,  4723,
    4727,  4734,  4739,  4746,  4751,  4755,  4760,  4764,  4772,  4783,
    4787,  4799,  4807,  4815,  4822,  4832,  4861,  4865,  4869,  4873,
    4877,  4881,  4885,  4889,  4893,  4922,  4951,  4980,  5009,  5022,
    5035,  5048,  5061,  5071,  5081,  5093,  5105,  5117,  5135,  5156,
    5161,  5165,  5169,  5181,  5185,  5197,  5204,  5214,  5218,  5233,
    5238,  5245,  5249,  5262,  5270,  5281,  5285,  5293,  5299,  5307,
    5315,  5330,  5344,  5358,  5370,  5386,  5397,  5401,  5420,  5428,
    5427,  5440,  5445,  5451,  5460,  5473,  5476
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
     415,   416,   417,    63,   418,   419,   420,   421,    60,    62,
     422,   423,    43,    45,    42,    47,    37,    33,   424,   425,
     426,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   192,   193,   193,   194,   194,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   196,   196,   197,   197,   197,   197,   197,   197,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   199,   200,
     200,   201,   201,   203,   204,   202,   205,   205,   207,   206,
     208,   208,   210,   209,   211,   211,   213,   212,   214,   214,
     214,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   219,   219,   220,   220,   220,   221,   220,   220,   222,
     220,   223,   223,   224,   224,   225,   225,   226,   226,   226,
     227,   227,   228,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   236,   236,   236,   236,
     236,   236,   236,   236,   237,   237,   238,   238,   238,   238,
     238,   238,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   240,   240,   240,   240,   240,   241,   241,   242,   242,
     242,   242,   242,   242,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   245,   245,   245,   246,   245,   247,
     245,   248,   245,   249,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   250,   245,   251,   245,   252,   245,
     253,   245,   254,   245,   255,   245,   256,   245,   257,   245,
     258,   245,   259,   259,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     261,   262,   262,   263,   263,   264,   264,   265,   265,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     267,   267,   267,   268,   268,   268,   269,   269,   269,   269,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   272,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   273,   273,   273,   273,   273,   274,   274,   274,
     274,   275,   275,   276,   276,   276,   276,   276,   276,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   279,
     279,   279,   279,   280,   280,   280,   280,   281,   281,   282,
     282,   283,   283,   283,   283,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   285,
     284,   286,   286,   287,   287,   288,   288
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
       3,     2,     2,     2,     2,     2,    15,     2,     2,     2,
       2,     2,    16,     3,     6,     8,     8,    10,     1,     2,
       1,     3,     4,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     0,     6,     8,     8,     8,    12,    12,
      12,    14,    14,    14,     0,    12,     0,    12,     0,    12,
       0,    16,     0,    16,     0,    16,     0,    18,     0,    18,
       0,    18,     1,     2,     5,     7,     9,     2,     2,     2,
       3,     2,     3,     2,     3,     2,     3,     9,     6,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     7,     5,     4,     6,     6,    13,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     4,     4,     4,     4,
       2,     5,     5,     3,     6,     4,     7,     6,     6,     6,
       6,     4,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       1,     2,     3,     3,     5,     4,     2,     2,     2,     2,
       3,     3,     3,     3,     5,     5,     5,     5,    16,    16,
      16,    16,     1,     1,     3,     3,     4,     6,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     3,     6,     1,     1,     1,     4,     6,
       4,     4,     4,     8,     4,     8,     4,     6,     4,     0,
       6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,   233,     0,     0,     0,   230,     0,     0,     0,
       0,   323,   324,   325,     0,     5,     7,     6,     8,     9,
      10,    19,    11,    12,    13,    18,    17,    14,    15,    16,
       0,    20,   486,     0,   372,   485,   465,   373,   374,   375,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   466,     0,   467,   379,   380,   381,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   377,   378,
       0,     0,     0,    65,    66,     0,     0,   176,     0,     0,
       0,   330,     0,   461,   486,   384,     0,     0,     0,     0,
     215,     0,   217,   218,   213,   214,     0,   219,   220,   103,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   402,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,     0,   320,     0,
       0,     0,     0,     0,     0,     0,     0,   485,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   442,   443,
     413,   419,     0,   414,   486,   384,     0,     0,     0,     0,
     455,     0,     0,     0,     0,     0,   211,   212,     0,   485,
     486,     0,   229,     0,   176,     0,   176,   485,     0,   326,
       0,     0,    65,    66,     0,     0,    58,    62,    61,    60,
      59,    64,    63,     0,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   333,   332,   334,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,   174,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,   204,     0,   390,   153,     0,   485,
       0,   461,   462,     0,     0,   481,     0,   101,   101,     0,
       0,   449,   450,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   176,     0,   404,   403,     0,     0,     0,     0,   176,
     176,     0,     0,     0,     0,     0,     0,     0,   243,     0,
     176,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,   194,     0,     0,     0,   321,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,   426,     0,
       0,   427,     0,   428,     0,   429,     0,     0,     0,     0,
       0,     0,   332,   421,     0,   415,     0,     0,     0,   303,
      66,     0,   210,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,   231,   198,     0,   199,     0,     0,   223,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   479,     0,     0,
       0,     0,     0,     0,   331,    58,     0,     0,    58,     0,
       0,     0,     0,     0,   171,     0,     0,     0,     0,   177,
       0,     0,     0,   348,   347,   346,   345,   341,   342,   344,
     343,   336,   335,   337,   338,   339,   340,     0,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   318,   319,     0,     0,     0,     0,
     291,     0,     0,     0,   125,   126,     0,   127,   128,     0,
     129,   130,     0,   131,   132,     0,     0,     0,     0,     0,
       0,   141,   176,     0,     0,     0,     0,     0,   406,   405,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,   306,     0,     0,
     195,     0,     0,   191,     0,     0,     0,   316,   315,     0,
       0,     0,     0,   393,    67,    68,     0,   444,     0,     0,
       0,     0,     0,     0,   430,     0,   431,     0,   432,     0,
     433,     0,     0,   331,   416,   423,     0,   337,   422,     0,
     445,     0,     0,     0,     0,     0,     0,     0,     0,   232,
       0,   200,   202,     0,     0,     0,     0,     0,     0,     0,
      82,    71,     0,   385,   395,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   371,   359,     0,   361,   362,   363,
     364,   365,   366,   367,     0,     0,     0,   474,     0,   476,
     470,   471,   472,     0,     0,     0,     0,     0,   401,   478,
     115,   120,    93,     0,   468,     0,   387,   388,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
     389,     0,     0,     0,     0,   483,     0,     0,    43,     0,
       0,     0,    56,     0,    34,    35,    36,    37,    38,   386,
       0,   463,    23,    21,     0,     0,    24,     0,     0,   205,
     482,    69,   104,    70,   112,     0,   451,   452,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   289,   294,   292,     0,
     302,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   203,     0,     0,     0,   166,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,   234,     0,     0,
       0,     0,     0,     0,   296,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   385,     0,   446,     0,
     425,     0,     0,     0,     0,     0,     0,     0,   417,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,   484,     0,
       0,     0,   391,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,    80,    83,    85,     0,     0,   459,
       0,    91,     0,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,    29,   392,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,   308,     0,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,   277,
       0,   283,     0,   285,     0,   279,     0,   281,     0,   244,
     273,     0,     0,     0,   189,     0,     0,     0,   307,     0,
     193,   192,   322,     0,     0,    30,    31,     0,     0,     0,
       0,     0,     0,     0,   434,   435,   436,   437,   424,   418,
       0,     0,     0,     0,   456,     0,     0,     0,   224,     0,
       0,     0,     0,    73,     0,    81,     0,   207,   394,   206,
     360,   368,   369,   370,   477,     0,   398,   399,   400,     0,
       0,   383,   116,     0,   480,   121,   397,   469,    75,    58,
       0,     0,     0,     0,    74,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   411,     0,
       0,    25,    26,     0,    27,     0,     0,   105,   108,   137,
       0,     0,     0,     0,     0,     0,   140,     0,     0,   156,
     157,     0,     0,   142,   163,     0,     0,     0,     0,   133,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,     0,     0,   176,   176,     0,   254,
       0,   256,     0,   258,     0,   413,     0,     0,   284,   286,
     280,   282,     0,     0,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,   394,   447,     0,     0,
       0,     0,   448,   145,   146,     0,     0,     0,     0,    94,
      98,     0,     0,   328,    76,     0,   396,     0,     0,     0,
       0,     0,     0,    88,     0,     0,    89,     0,   460,   178,
     179,   180,   181,     0,     0,    39,     0,     0,     0,     0,
       0,    41,   464,     0,     0,   106,   109,     0,     0,   136,
     143,   144,   148,     0,     0,   158,     0,     0,   301,     0,
     151,     0,     0,   290,   162,   138,   150,   161,   165,   149,
       0,   159,   164,     0,     0,     0,     0,   410,     0,   409,
       0,     0,     0,   245,     0,     0,   246,     0,     0,   247,
       0,     0,     0,     0,     0,     0,     0,   188,     0,     0,
     187,     0,     0,     0,   182,     0,     0,    32,     0,     0,
       0,     0,     0,     0,   454,     0,   226,   225,     0,     0,
       0,     0,     0,   473,   475,     0,   117,   119,     0,   122,
     123,    84,    86,     0,    92,     0,    77,    44,     0,     0,
       0,   412,     0,     0,     0,    28,     0,   115,   120,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
      99,   100,   176,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,   274,     0,     0,   176,     0,     0,     0,
       0,     0,   173,   172,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,    78,     0,   449,     0,     0,
     458,     0,    40,     0,     0,     0,    42,    57,     0,     0,
       0,   310,   312,   311,   313,   314,   155,     0,     0,     0,
       0,     0,     0,   408,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   288,     0,     0,     0,   239,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,   453,   227,
       0,   329,     0,   118,     0,   124,    90,     0,     0,     0,
       0,     0,   107,   110,     0,     0,     0,   297,   167,     0,
     260,     0,     0,   262,     0,     0,   264,     0,     0,     0,
     275,     0,   235,     0,   176,     0,     0,     0,     0,     0,
       0,     0,   147,    97,     0,   113,     0,    48,     0,    54,
       0,     0,     0,   134,   160,     0,     0,   407,   248,     0,
       0,   255,   249,     0,     0,   257,   250,     0,     0,   259,
       0,     0,     0,   241,     0,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   298,
     309,     0,   266,     0,   268,     0,   270,   276,   287,   240,
     236,     0,     0,     0,     0,     0,     0,     0,     0,   114,
      45,     0,    52,     0,     0,     0,     0,   251,     0,     0,
     252,     0,     0,   253,     0,     0,   190,     0,   184,     0,
       0,     0,     0,     0,    46,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   261,     0,   263,     0,
     265,     0,   185,     0,     0,     0,     0,    47,    49,     0,
      50,     0,     0,     0,     0,   438,   439,   440,   441,     0,
       0,    55,   267,   269,   271,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    85,   874,    86,    87,   637,  1314,  1320,
     864,  1038,  1481,  1663,   865,  1614,  1699,   866,  1665,   867,
     868,  1042,   323,   406,   169,   747,    88,   651,   417,  1427,
    1428,   418,  1476,  1014,  1172,  1015,  1175,   683,   686,   689,
     692,  1342,  1213,   619,   278,   383,   384,    91,    92,    93,
      94,    95,    96,   279,   948,  1563,  1631,   717,  1364,  1367,
    1370,  1589,  1593,  1597,  1648,  1651,  1654,   944,   945,  1074,
     909,   680,   726,  1586,    98,    99,   100,   101,   280,   171,
     830,   464,   238,  1197,   281,   282,   283,   526,   292,   849,
    1030,   415,   411,   831,   416,   174,   285
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1259
static const yytype_int16 yypact[] =
{
    6023,    45,    62,  6141, -1259, -1259,  2039,    71,   -35,  -114,
     -89,    47,    91,   134,   145,   156,   -51,   160,   221,    56,
      85,   -68,   117,   175,     8,   179,   220,    29,   231,   240,
     224,   242,   352,   440,   274,   495,   399,   403,   561,   119,
     481,   569,   268,   309,   425,   120,   354,   -56,   -56,   379,
     307,    39,     1,   448,   509,    26,    33,   512,   516,   295,
     607,   616,   639,  3875,   643,   469,   479,   480,    30,    27,
   -1259,   500, -1259,   672,   707,   470, -1259,   718,   731,     6,
      21, -1259, -1259, -1259,  5885, -1259, -1259, -1259, -1259, -1259,
   -1259, -1259, -1259, -1259, -1259, -1259, -1259, -1259, -1259, -1259,
      46, -1259,  -118,   121, -1259,     2, -1259, -1259, -1259, -1259,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   536,   556,   563,   590,   610,
     622,   -81,   634, -1259,   -81, -1259, -1259, -1259, -1259,   -81,
     -81,   735,   647,   663,   664,   677,   686, -1259, -1259, -1259,
    5885,  5885,  5885,  5885,  2814,    23,   718,   410,   680,   699,
     758, -1259,   704,   869,   -10,   239,   888,  5885,  1593,  1593,
   -1259,  5885, -1259, -1259, -1259, -1259,  1593, -1259, -1259, -1259,
   -1259,  5885,  5656,  5885,  5885,   716,  5885,  5656,  5885,  5885,
     725,  5656,  5885,  5885,  4659,   728,   708, -1259,  5656,  3875,
    3875,  3875,   769,   777,  3875,  3875,  3875,   781,   795,   800,
     801,   803,   806,   809,   813,  4659,  5885,   992,  4659,    30,
     819,   820,   -56,   -56,   -56,  5885,  5885,  -101, -1259,   -50,
     -56,   821,   826,   827,  2382,   -43,   -41,   846,   855,   860,
    3875,  3875,  4659,   861,    55,   818, -1259,  1030, -1259,   856,
     857,   858,  3875,  3875,   864,   865,   867,   -37, -1259,   868,
       3,    15,    18,    42,   541,  4840,  5885,  3487, -1259, -1259,
    3519, -1259,  1047, -1259,   128,   -60,  1049,  5885,  5885,  5885,
     870,  5885,   872,   922,  5885,  5885, -1259, -1259,  5885,   873,
     874,  1053, -1259,  1057, -1259,  1061, -1259,   443,   955, -1259,
    4659,  4659, -1259,  5831,   881,   893,  2124, -1259, -1259, -1259,
   -1259, -1259, -1259,  4659,  1065,   900,  5885,  1082, -1259,  5885,
    5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,
    5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,
    5885,  1593,  1593,  1593,  1593,  1593,  1593,  4659,  1593,  1593,
    5885,  1593,  1593,  5885,  2124,  5885,  1593,  1593,  1593,   718,
    2124,   907,   907,   907,  8560,   135,  8215,   125,   903,  1083,
     908,   904, -1259,   906,  5060,  5885,  5656, -1259,  5885,  5885,
    5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,  5885,
    5885,  5885,  5885, -1259, -1259,  5885, -1259, -1259,   984,   446,
      -4, -1259, -1259,    67,  6996, -1259,    90,   210,   276,  8581,
    5656,  3962, -1259,    68,  8602,  8623,  5885,  8644,   151,  8665,
    8686,  5885,   190,  8707,  8728,  1087,  5885,  5885,   300,  1091,
    1092,  1096,  5885,  5885,  1097,  1102,  1102,  5885,  5564,  5564,
    5564,  5564,  5885,  5885,  5885,  1104,  6916,   920,  1106,   924,
   -1259, -1259,   -29, -1259, -1259,  7022,  7048,   -56,   -56,   410,
     410,   -15,  5885,  5885,  5885,  2382,  2382,  5885,  5060,   104,
   -1259,  5885,  5885,  5885,  5885,  5885,  1108,  1111,  1125,  5885,
    1127, -1259,  5885,  5885,  1459, -1259,  5656,  5656,  5656,  1131,
    1132,  5885,  5885,  5885,  5885,  1135,   316,   718, -1259,  1090,
    5885, -1259,  1093, -1259,  1094, -1259,  1095,    37,    40,    41,
      43,  5656,   907, -1259,  8749, -1259,   325,  5885,  5021, -1259,
    5885,   388, -1259,  8770,  8791,  8812,  1010,  7074, -1259,   972,
    4388,  8833,  8238, -1259, -1259,  1831, -1259,  2422,  5885, -1259,
     980,   334,   135,  8261,  5885,  5656,  1158,  1160, -1259,  5885,
    8284,   368,  8192,  8192,  8192,  8192,  8192,  8192,  8192,  8192,
    8192,  8192,  8192,  7100,  8192,  8192,  8192,  8192,  8192,  8192,
    8192,  7126,  7152,  7178,   133,   366,   133,   985,   994,   979,
     987,   993,   997,  7204,   397,   429,  3981, -1259,  1258,  1001,
     999,  1003,  1011,  1013,   135, -1259,  4659,    84,  2124,  5885,
    1174,  1189,    31,  1012, -1259,   258,    32,    34,   270, -1259,
    4809,   436,  4447,  3481,  3159,   709,   709,   613,   613,   613,
     613,   345,   345,   907,   907,   907,   907,    12,  8307, -1259,
    5885,  1195,    13,  5656,  1198,  5656,  5885,  1199,  1593,  1200,
   -1259,   718,  1201,  1593,  1194,  5656,  5656,  1073,  1202,  1207,
    8854,  1214,  1088,  1217,  1218,  8875,  1098,  1219,  1220,  5885,
    8896,  5601,  1039, -1259, -1259, -1259,  8917,  8938,  5885,  4659,
    1226,  1225,  8959,  1051,  3981, -1259,  1052,  3981, -1259,  1054,
    3981, -1259,  1055,  3981, -1259,  8980,  9001,  9022,  4659,  5656,
    1046, -1259, -1259,  2555,  3006,   -56,  5885,  5885, -1259, -1259,
    1050,  1056,  2382,  7230,  7256,  7282,  6970,   477,   -56,  3298,
    9043,  5790,  9064,  9085,  9106,  5885,  1230, -1259,  5885,  9127,
   -1259,  8330,  8353, -1259,   485,   504,   524, -1259, -1259,  8376,
    8399,  7308,  8422,   -60, -1259, -1259,  5656, -1259,  1058,  1062,
    6132,  1063,  1064,  1066, -1259,  5656, -1259,  5656, -1259,  5656,
   -1259,  5656,   529, -1259, -1259,  4616,  5656,   907, -1259,  5656,
   -1259,  1232,  1235,  1243,  1068,  5885,  3733,  5885,  5885, -1259,
      14, -1259, -1259,  1069,  4659,  1251,  4659,   250,  6160,   535,
   -1259, -1259,  8445,  1130, -1259, -1259, -1259, -1259, -1259, -1259,
   -1259, -1259, -1259, -1259, -1259, -1259,  5885, -1259, -1259, -1259,
   -1259, -1259, -1259, -1259,  5885,  5885,  5885, -1259,  5656, -1259,
   -1259, -1259, -1259,  1593,  4659,  1593,  1593,  2124, -1259, -1259,
   -1259, -1259, -1259,  5885, -1259,  1593, -1259, -1259,  5885,  1254,
      28,  5885,  1255,  1256,  1441, -1259,  1259,  1084,    30,  1263,
   -1259,  5656,  5656,  5656,  5656, -1259,   429,  5885, -1259,  1089,
    1099,  1081, -1259,  1266, -1259, -1259, -1259, -1259, -1259,   -60,
    8468, -1259, -1259,  1105,  1593,   472, -1259,   505,  7334, -1259,
   -1259, -1259,  1268, -1259, -1259,   -56,  3962, -1259,   110,  4659,
    4659,  1269,  4659,   652,  4659,  4659,  1273,  1196,  4659,  4659,
    1695,  1277,  1281,  5656,  1284,  1286,  1860, -1259, -1259,  1288,
   -1259,  1290,   135,   135,   135,   135,  1292,  1293,  1301,  1289,
     540,  1299,  3916, -1259, -1259,   118,  7360,  7386, -1259, -1259,
    6188,  -103,   -56,   -56,   -56,  1309,  1308,  1128,  1312,  1137,
      48,    50,    51,    52,   -12, -1259,   174, -1259,   477,  1316,
    1318,  1324,  1325,  1326,  3981, -1259,  1945,  1136,  1328,  1329,
    1357,  1291,  5885,  1358,  1359,  5885,   195,   544, -1259,  5885,
   -1259,  5885,  5885,  5885,   551,   560,   567,   571, -1259,  5885,
     572,   579,  4659,  4659,  4659,  1363,  7412, -1259,  4785,   161,
    1364,  1367,  4659,  1183, -1259,  1368,  5885,  1370, -1259,   429,
    1373,  1376, -1259,  1375,  8192,  8192,  8192,  8192,   489,  1197,
    1203,  1204,  1206,  1205,   496,   502,  9148,  1208,  2116, -1259,
     264,  1211,  1383,  2148, -1259, -1259, -1259,    30,  5885, -1259,
     585, -1259,   594,   608,   609,   617,   135,  3981,  1212,  5885,
    5885,  4659,  1215, -1259, -1259,  1213, -1259,  1377,    22,  1386,
    5885,  4056,    69,  1221,  1222,  1311,  1311,  4659,  1395,  1227,
    1229,  1397,  1403,  4659,  1231,  1411,  1431, -1259,  1433,  4659,
     621,  4659,  4659,  1437,  1436, -1259,  4659,  4659,  4659,  4659,
    4659,  4659,  4659,  4659, -1259,  1438,   282, -1259,  5885,  5885,
    5885,  1260,  1262,  -123,   -77,   -63,  1264, -1259,  4659, -1259,
    5885, -1259,  1447, -1259,  1449, -1259,  1450, -1259,  1452, -1259,
   -1259,  2382,   490,  4237, -1259,  1275,  1276,  5202, -1259,  5656,
   -1259, -1259, -1259,  1278,  2194, -1259, -1259,  8491,  1439,   429,
    7438,  7464,  7490,  7516, -1259, -1259, -1259, -1259,  3981, -1259,
     429,  1460,  1462,  1313, -1259,  5885,  5885,  5885, -1259,  1467,
     598,  1287,  1468, -1259,  2495, -1259,   135, -1259,   386, -1259,
   -1259, -1259, -1259, -1259, -1259,  1593, -1259, -1259, -1259,  2124,
    1472, -1259, -1259,  1473, -1259, -1259, -1259, -1259, -1259,  2124,
    5885,  1474,  1475,    31, -1259,  1478,  8514,    30, -1259,  1481,
    1482,  1483,  1484,  4659,  5885,  7542,  7568,   636, -1259,  5885,
    1487, -1259, -1259,  1593, -1259,  7594,  5564,  3981, -1259, -1259,
    5885,  5885,   -56,  1488,  1491,  1497, -1259,  5885,  5885, -1259,
   -1259,  1498,  5885, -1259, -1259,  1500,  1504,  1327,  1507,  1343,
    5885, -1259,  1508,  1509,  1511,  1512,  1513,  1514,   745,  1515,
    5885, -1259,  5564,  6216,  9169,  5147,   410,   410,   -56,  1516,
     -56,  1517,   -56,  1518,  5885,   365,  1337,  9190, -1259, -1259,
   -1259, -1259,  6244,   196, -1259,  1520,  3247,  1521,  4659,   -56,
    3247,  1532,   637,  5885, -1259,  1536,   -60, -1259,  5885,  5885,
    5885,  5885, -1259, -1259, -1259,  4659,  5328,   534,  9211, -1259,
   -1259,  4418,  4659, -1259, -1259,  4659, -1259,  1360,   429,  3694,
    4478,  1540,  2753, -1259,  1543,  1545, -1259,  1366, -1259, -1259,
   -1259, -1259, -1259,  1548,   528,  3981,  5885,  5885,  4659,  1369,
     640,  3981, -1259,  1549,  5885,  3981, -1259,  6272,  6300,   605,
   -1259, -1259, -1259,  6328,  6356, -1259,  6384,  1551, -1259,  4659,
   -1259,  1486,  1554,  3981, -1259, -1259, -1259, -1259, -1259, -1259,
    1374, -1259, -1259,  6943,  2973,  1559,  1378, -1259,  5885, -1259,
    1379,  1380,   213, -1259,  1382,   215, -1259,  1384,   243, -1259,
    1385,  8537,  1560,  4659,  1550,  1389,  5885, -1259,  5383,   248,
   -1259,   645,   260,   281, -1259,  1562,  6412, -1259,  7620,  7646,
    7672,  7698,  1442,  5885, -1259,  5885, -1259, -1259,  5656,  3278,
    1569,  1391,  1573, -1259, -1259,  3487, -1259, -1259,  1593,  3981,
   -1259, -1259, -1259,    30, -1259,  1456, -1259, -1259,  5885,  7724,
    7750, -1259,  4659,  5885,  1577, -1259,  7776, -1259, -1259,  1579,
    1584,  1585,  1586,  1587,  1588,   648,  1407, -1259,  4659,  5656,
   -1259, -1259,   410,  5473, -1259, -1259,  2382,   477,  2382,   477,
    2382,   477,  1594, -1259,   649,  4659, -1259,  6440,   -56,  1595,
    5656,   -56, -1259, -1259,  5885,  5885,  5885,  5885,  5885,  6468,
    6496,   653, -1259, -1259,  1597, -1259,   667,  3043,   684,  1612,
   -1259,  1410,  3981,  5885,  5885,   711,  3981, -1259,  5885,   714,
     715, -1259, -1259, -1259, -1259, -1259, -1259,  1432,  5885,   723,
     726,  1430,  5885, -1259,  6524,   293,   547,  6552,   298,   854,
    6580,   304,   882, -1259,  4659,  1617,  1533,  4095,  1435,   310,
   -1259,   727,   312,  7802,  7828,  7854,  7880,  3299, -1259, -1259,
    1620, -1259,  5885, -1259,  2124, -1259, -1259,  5885,  9232,  7906,
      49,  7932, -1259, -1259,  5885,  6608,  1622,  1535, -1259,  6636,
    1623,  5885,  1625,  1633,  5885,  1634,  1636,  5885,  1637,  1454,
   -1259,  5885, -1259,   477, -1259,  5656,  1639,  5383,  5885,  5885,
    5885,  5885, -1259, -1259,  3451, -1259,   747, -1259,  5885, -1259,
    4659,  5885,  7958, -1259, -1259,  4659,  1642, -1259, -1259,  1469,
    6664, -1259, -1259,  1470,  6692, -1259, -1259,  1471,  6720, -1259,
    1645,  3432,   895,  4278,   750, -1259,   339,   753,  7984,  8010,
    8036,  8062,  2124,  1651,  1476,  9253,   754,  6748,  5885, -1259,
   -1259,   477,  1656,   477,  1658,   477,  1661, -1259, -1259, -1259,
   -1259,   477,  1664,  5656,  1665,  5885,  5885,  5885,  5885, -1259,
   -1259,  1593, -1259,  1485,  1666,  6776,   989, -1259,  1493,  1100,
   -1259,  1503,  1210, -1259,  1510,  1296, -1259,   757, -1259,  8088,
    8114,  8140,  8166,   760, -1259,  1519,  4659, -1259,  1669,  1670,
     477,  1671,   477,  1675,   477, -1259,  1681,  5885,  5885,  5885,
    5885,  1593,  1690,  1593,   770, -1259, -1259,  1390, -1259,  1621,
   -1259,  1683, -1259,  6804,  6832,  6860,  6888, -1259, -1259,   788,
   -1259,  1691,  1692,  1696,  1697, -1259, -1259, -1259, -1259,  1593,
    1698, -1259, -1259, -1259, -1259, -1259, -1259
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1259, -1259, -1259, -1259,   657, -1259, -1259, -1259, -1259,   170,
   -1259, -1259, -1259, -1259, -1259, -1259, -1259, -1259, -1259, -1259,
   -1259, -1259,  -353,   -17,  1228,   455, -1259,  1294, -1259, -1259,
   -1259, -1259, -1259,   283, -1259,   286, -1259, -1259, -1259, -1259,
   -1259, -1259,   655,  1706,    -2,  -467,  -227, -1259, -1259, -1259,
   -1259, -1259, -1259,  1712, -1259, -1259, -1259, -1259, -1259, -1259,
   -1259, -1259, -1259, -1259, -1259, -1259, -1259,  -830,  -881, -1259,
   -1259,  1270, -1259, -1259, -1259, -1259, -1259, -1259,  1492, -1259,
   -1259,    35, -1259, -1258,  2122,   603,  -183,   101,  -225,   537,
   -1259,    83,     7, -1259,  -346,    -3,    38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -465
static const yytype_int16 yytable[] =
{
     102,    90,   710,   711,   459,   584,   325,   586,   508,   422,
    1381,   303,   195,   173,   422,   594,   858,   478,   422,   872,
     511,   990,   606,   513,   609,   422,   305,   377,  1202,   494,
     254,   293,  1020,   200,   290,   847,   195,   257,   200,   258,
     177,   103,   754,   246,   175,   756,   758,   515,   760,   467,
     468,     4,   309,   180,  1101,  1579,  1103,  1105,  1107,   490,
     284,   491,     5,  1110,   312,  1248,   313,  1249,   178,   467,
     468,   467,   468,   314,   300,  1209,   250,   545,   251,   547,
     935,  1435,   237,   239,   176,   245,   324,  1092,   469,   172,
     936,   605,   523,   179,   422,   467,   468,   182,   937,   938,
     939,   312,   259,   328,   940,   941,   942,   943,   247,   467,
     468,  1250,   248,  1251,   191,   301,   233,   234,  1112,   321,
     322,   192,   467,   468,   249,  1252,   235,  1253,   316,   467,
     468,   186,   608,   236,   859,   860,   861,   862,   509,   470,
     183,   481,   605,   467,   468,   312,   480,   504,   482,   505,
     512,   184,   167,   514,   168,   378,   379,   467,   468,   705,
    1021,  1022,   185,   300,  1485,   382,   187,   255,  1102,  1147,
    1104,  1106,  1108,   712,   405,   300,   300,   516,  1109,   642,
    1499,   314,   873,   300,   643,  1053,   326,  1054,   327,   284,
     196,   873,   510,   168,   284,   304,   217,   197,   284,   786,
     991,   284,   863,   422,   380,   284,   284,   284,   284,   294,
     306,   284,   284,   284,   196,   256,   412,   412,   201,   291,
     848,   852,   284,   853,   412,   284,   755,   188,   310,   757,
     759,  1110,   761,   703,   704,   311,   181,   523,  1580,   492,
     189,   467,   468,   317,   318,   319,   320,   284,   284,   284,
     644,   838,   229,   719,   841,   645,   656,   605,   657,   284,
     284,   410,   413,   321,   322,   230,   231,   462,   463,   190,
     840,  1179,   284,   647,   284,   471,   467,   468,   648,   479,
     317,   318,   319,   320,   317,   318,   319,   320,  1241,  1242,
     467,   468,   718,   423,   317,   318,   319,   320,   428,   193,
     321,   322,   432,   204,   321,   322,  1088,   284,   284,   438,
     312,   776,   530,   422,   422,   422,   744,   205,   745,   314,
     284,   648,  1616,   556,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   422,   656,
     225,   662,   402,   226,  1148,   768,   467,   468,   300,   300,
     300,   300,   300,   300,   284,   300,   300,   194,   300,   300,
     610,   198,  1111,   300,   300,   300,   300,   262,   467,   468,
     263,   597,   422,   527,   321,   322,   241,   603,   656,   242,
     666,  1128,   243,   284,  1376,   467,   468,   467,   468,   412,
     412,   412,   412,   412,   412,   649,   412,   412,   650,   412,
     412,  1446,   199,  1448,   412,   412,   412,   602,  1684,   317,
     318,   319,   320,   202,   381,   467,   468,   284,   321,   322,
     467,   468,   203,   317,   318,   319,   320,   206,  -462,   321,
     322,  1450,   467,   468,   996,   585,  1458,   587,   588,   589,
     191,   591,   592,   321,   322,   595,   207,   851,  1460,   599,
     600,   601,   203,   467,   468,   685,   688,   691,   694,   854,
     422,   652,   422,   208,   650,   467,   468,   382,   382,  1461,
     467,   468,   768,   887,   212,   922,   467,   468,   213,   233,
     234,  1551,   467,   468,   467,   468,  1554,   621,   656,   235,
     672,   227,  1557,   284,   284,   284,   244,   228,  1565,   744,
    1567,   745,   708,   709,   300,   746,    46,    47,    48,    49,
     463,   467,   468,   656,    54,   764,   422,    57,   284,   399,
     400,   401,   784,   252,   785,   284,   402,  1633,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   528,
     400,   401,  1395,   232,   794,   748,   402,   321,   322,   744,
     218,   745,   284,   219,   818,  1372,   220,  -463,   221,  1077,
    1078,  1079,  1080,   422,   209,   321,   322,   210,   240,   935,
     211,   744,   422,   745,   422,  -464,   422,   769,   422,   936,
     828,   253,   935,   422,   260,   648,   422,   937,   938,   939,
     842,   261,   936,   940,   941,   942,   943,   734,   735,   736,
     937,   938,   939,   284,  1290,  1291,   940,   941,   942,   943,
     517,   264,   744,   518,   745,   843,   519,  1506,   520,  1509,
     265,  1512,   762,  1029,   656,  1110,   856,   548,  1110,   505,
     640,  1110,   641,   214,   168,   422,   215,   168,   216,   935,
     284,   222,   284,   266,   223,   300,   224,   286,   300,   936,
     300,   287,   284,   284,   298,  1048,   789,   937,   938,   939,
     656,   288,   289,   940,   941,   942,   943,  1180,   422,   422,
     422,   422,   744,   656,   745,   960,   284,   656,   296,   744,
    1264,   745,   295,  1193,  1170,   744,   412,   745,  1049,   882,
    1173,   412,   656,   656,   961,   284,   284,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,  1417,   656,   297,   962,   402,  1418,   656,   354,   978,
     422,  1110,   299,   656,  1396,   999,   794,  1059,   656,  1060,
    1085,   880,   656,  1602,  1129,   302,   884,  1552,   355,   656,
     925,  1134,   365,   284,   875,   356,   877,   931,   656,  1350,
    1135,  1351,   284,   946,   284,   656,   284,  1136,   284,   656,
     656,  1137,  1139,   284,   387,  1110,   284,   656,  1110,  1140,
     997,  1110,   357,  1187,  1110,  1188,  1002,   467,   468,  1360,
    1361,   284,   656,   284,  1189,   397,   398,   399,   400,   401,
     300,  1646,   358,  1649,   402,  1652,   656,   656,  1190,  1191,
     920,  1655,  1185,  1295,   359,   656,  1110,  1192,  1110,   656,
    1110,  1227,   439,   440,   441,   284,   361,   444,   445,   446,
     300,   284,   300,   300,  1318,   656,  1319,  1385,  1423,   366,
    1424,   412,   300,  1318,  1013,  1459,  1318,  1514,  1497,  1515,
    1687,   656,  1689,  1530,  1691,   367,   368,   967,   284,   284,
     284,   284,  1044,   486,   487,  1532,   974,  1533,   975,   369,
     976,   412,   977,   412,   412,   499,   500,   980,   370,   385,
     981,   300,   648,   412,  1535,   404,  1003,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   284,   284,   386,   284,
     402,   284,   284,   403,   407,   284,   284,   437,   426,  1318,
     284,  1540,  1170,  1173,  1542,  1543,  1009,   431,  1011,  1012,
     436,  1318,   412,  1546,   656,   656,  1547,  1566,  1017,  1008,
    1052,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,  1423,   422,  1613,   656,   402,
    1632,   656,  1318,  1634,  1643,   656,   935,  1676,  1681,  1002,
    1682,   442,  1032,  1033,  1034,  1035,   936,  1047,  1318,   443,
    1701,   549,  1308,   447,   937,   938,   939,  1093,  1094,  1095,
     940,   941,   942,   943,   935,  1501,  1709,   448,  1710,   284,
     284,   284,   449,   450,   936,   451,   770,   935,   452,   284,
     639,   453,   937,   938,   939,   454,   457,   936,   940,   941,
     942,   943,   493,  1181,  1070,   937,   938,   939,   460,   461,
     472,   940,   941,   942,   943,   473,   474,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   483,   807,
     808,   809,   810,   811,   812,   813,   495,   484,   284,   817,
     819,   820,   485,   489,  1555,   496,   497,   498,   501,   502,
     829,   503,   507,   529,   284,   532,   536,   539,  1208,   543,
     284,   538,  1478,   544,   168,   314,   284,   546,   284,   284,
     554,   558,  1558,   284,   284,   284,   284,   284,   284,   284,
     284,   935,   555,   422,   559,  1629,   561,   422,   402,   611,
     612,   936,   613,   167,   669,   284,   614,   673,   674,   937,
     938,   939,   675,   700,   678,   940,   941,   942,   943,   679,
     284,   698,   701,   702,   284,   725,   284,   727,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   728,   730,   409,   106,   402,   737,   738,   743,
     749,  1296,   774,   751,   752,   753,  1263,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   777,   300,   783,   790,   402,   791,   823,   821,   132,
     133,   134,   135,   136,   137,   824,  1298,   822,   141,  1669,
     845,   825,   834,   143,   144,   826,  1301,   145,  1479,   833,
     284,   835,   935,   846,   836,   523,   837,   850,   150,   871,
     300,   885,   936,   412,   876,   879,   881,   883,   888,   889,
     937,   938,   939,  1326,   890,   422,   940,   941,   942,   943,
    1272,   892,   422,   893,   894,   895,   898,   899,   903,  1517,
     908,   910,   921,   897,   912,   913,   955,   914,   915,   982,
     928,   412,   983,   968,   382,   382,   929,  1329,  1297,  1355,
     984,   969,   971,   972,   985,   973,   422,   994,   992,  1296,
    1019,  1024,  1025,   284,   832,   284,  1027,   284,  1028,  1031,
    1041,  1039,  1043,  1064,  1046,  1051,  1057,   422,   153,   154,
    1063,  1040,   284,  1362,  1068,  1365,  1323,  1368,  1069,   284,
    1671,  1071,   284,  1072,  1075,  1084,   284,  1076,  1400,  1081,
    1082,  1379,   935,  1086,  1382,  1383,  1407,  1410,  1083,   321,
     322,  1036,   936,  1096,  1097,   284,  1001,  1098,  1099,  1100,
     937,   938,   939,  1113,  1114,  1119,   940,   941,   942,   943,
     315,  1115,  1116,  1117,  1120,  1121,   284,  1603,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,  1122,  1125,  1126,  1123,  1144,  1149,   360,
     284,  1150,   362,  1152,  1153,   284,  1155,   363,   364,  1157,
    1158,  1159,   422,  1201,   422,  1165,  1166,  1167,   935,  1168,
    1183,  1177,  1204,  1169,  1194,   284,  1212,  1182,   936,  1200,
    1673,  1216,   284,  1219,  1199,   300,   937,   938,   939,  1220,
    1210,  1211,   940,   941,   942,   943,  1217,  1223,  1218,   284,
    1222,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   284,   284,  1224,  1225,   402,
     382,  1230,  1231,  1276,  1285,  1240,   412,  1026,  1254,  1246,
     422,  1247,   284,  1258,  1156,  1259,  1260,   284,  1261,  1160,
    1161,  1162,  1163,  1164,  1268,  1269,  1283,  1273,  1284,  1171,
    1174,     7,     8,  1289,  1293,  1292,  1299,  1300,  1341,  1304,
    1303,  1505,   935,  1508,  1306,  1511,  1675,  1309,  1310,  1311,
    1312,  1322,   936,  1519,  1330,   506,  1522,  1331,   170,  1471,
     937,   938,   939,  1332,  1335,  1337,   940,   941,   942,   943,
    1338,   284,   531,  1340,  1344,  1345,  1339,  1346,  1347,  1348,
    1349,  1352,  1363,  1366,  1369,  1373,  1377,  1380,   615,    22,
      23,   616,    25,    26,   617,    28,   618,    30,  1384,    31,
    1500,  1575,  1387,  1403,    36,    37,  1411,    39,    40,    41,
    1413,  1414,  1415,    44,  1416,  1425,  1434,  1455,  1422,  1436,
    1437,  1521,   284,  1438,   284,  1441,  1453,  1442,  1462,  1444,
    1445,  1447,  1468,  1449,  1451,  1473,   308,   284,  1456,  1475,
    1702,  1474,   284,  1487,  1277,  1491,    65,    66,    67,  1480,
    1492,  1493,  1494,  1495,  1496,  1282,  1498,   409,   106,  1537,
    1513,  1520,  1606,  1531,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,  1536,  1639,
    1548,  1544,   402,  1560,  1564,  1561,  1573,  1585,  1584,  1588,
     284,  1591,   132,   133,   134,   135,   136,   137,   300,  1592,
    1595,   141,  1596,  1599,  1600,  1605,   143,   144,  1620,   733,
     145,  1627,   371,   372,   373,   374,   376,  1640,  1621,  1623,
    1625,   150,  1647,   284,  1650,  1641,  1604,  1653,  1607,   408,
    1656,  1658,  1667,   414,  1666,  1685,  1686,  1688,   300,   412,
     300,  1690,  1670,   419,   421,   424,   425,  1692,   427,   421,
     429,   430,  1672,   421,   433,   434,  1698,  1711,  1712,  1674,
     421,  1067,  1713,  1714,  1716,  1203,   300,  1576,  1683,    89,
    1489,  1214,   653,   935,  1490,    97,   681,     0,   456,   412,
    1305,   412,     0,   936,  1664,     0,     0,   465,   466,     0,
       0,   937,   938,   939,  1657,     0,   466,   940,   941,   942,
     943,   153,   154,     0,     0,     0,     0,   412,     0,     0,
       0,     0,     0,  1404,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1697,     0,  1700,   522,   524,   421,
       0,     0,     0,     0,     0,   935,     0,     0,     0,   533,
     534,   535,     0,   537,     0,   936,   540,   541,     0,     0,
     542,     0,  1715,   937,   938,   939,     0,     0,     0,   940,
     941,   942,   943,     0,     0,   553,     0,     0,     0,     0,
       0,  1703,     0,     0,     0,     0,     0,     0,   560,     0,
       0,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   593,     0,     0,   596,     0,   598,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,  1704,     0,     0,   402,   620,   421,     0,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,     0,     0,   638,     0,     0,
     615,    22,    23,   616,    25,    26,   617,    28,   618,    30,
       0,    31,   522,     0,     0,     0,    36,    37,   660,    39,
      40,    41,     0,   665,     0,    44,     0,     0,   670,   671,
       0,     0,     0,     0,   676,   677,     0,     0,     0,   682,
     684,   687,   690,   693,   695,   696,   697,     0,     0,     0,
       0,  1118,  1073,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,   713,   714,   715,   371,   372,   716,
       0,     0,     0,   720,   721,   722,   723,   724,     0,     0,
       0,   729,     0,     0,   731,   732,     0,     0,   421,   421,
     421,     0,     0,   739,   740,   741,   742,     0,     0,     0,
       0,     0,   750,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,     0,     0,     0,     0,     0,   765,
     767,   781,   638,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
     742,   402,   104,   105,   106,     0,   788,   421,   107,   108,
     109,   792,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,     0,   143,   144,     0,     0,   145,     0,   146,   147,
     148,   844,     0,     0,     0,     0,   149,   150,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,  1178,     0,     0,     0,   402,     0,     0,   106,
       0,     0,   870,     0,     0,   421,     0,   421,   878,     0,
       0,     0,     0,     0,     0,     0,     0,   767,   886,     0,
       0,     0,     0,     0,  1184,     0,     0,     0,     0,     0,
       0,   900,     0,   132,   133,   134,   135,   136,   137,     0,
     906,     0,   141,     0,     0,     0,     0,   143,   144,     0,
     151,   145,     0,     0,     0,     0,   152,   153,   154,     0,
       0,   421,   150,   155,   156,   157,   158,   159,   926,   927,
    1274,     0,     0,     0,   930,     0,     0,     0,     0,     0,
       0,   160,   161,     0,     0,     0,   162,   954,     0,     0,
     956,   163,     0,   164,     0,   165,   166,     0,   167,     0,
     168,     0,     0,     0,     0,     0,     0,     0,   421,     0,
       0,     0,     0,     0,     0,     0,     0,   421,     0,   421,
       0,   421,     0,   421,     0,     0,     0,     0,   421,     0,
       0,   421,     0,     0,     0,     0,     0,   986,     0,   988,
     989,     0,   153,   154,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,  1004,     0,
       0,     0,     0,     0,     0,     0,  1005,  1006,  1007,     0,
     421,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,  1016,   435,     0,     0,   402,
    1018,     0,     0,  1023,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,   421,   421,   421,   455,     0,  1037,
     458,     0,     0,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,   488,   402,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   307,     0,     0,     0,
       0,   107,   108,   109,     0,   421,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
       0,   142,   550,   551,     7,     8,     0,     0,     0,     0,
       0,   146,   147,   148,     0,   557,     0,     0,     0,   149,
       0,     0,     0,     0,  1124,     0,     0,  1127,     0,     0,
       0,  1130,     0,  1131,  1132,  1133,     0,     0,     0,     0,
       0,  1138,     0,     0,     0,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,  1154,     0,
       0,   615,    22,    23,   616,    25,    26,   617,    28,   618,
      30,  1294,    31,     0,     0,     0,     0,    36,    37,     0,
      39,    40,    41,     0,     0,     0,    44,     0,     0,     0,
    1186,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,  1195,  1196,     0,     0,     0,   155,   156,   157,   158,
     159,     0,  1205,  1207,     0,     0,     0,     0,     0,    65,
      66,    67,     0,     0,   475,   476,     0,     0,     0,   162,
       0,     0,     0,     0,   477,     0,     0,     7,     8,   166,
       0,   236,     0,     0,     0,     0,     0,     0,     0,     0,
    1243,  1244,  1245,     0,     0,     0,     0,     0,     0,     0,
    1255,     0,  1257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1262,     0,     0,     0,     0,     0,     0,
       0,   421,   782,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,    22,    23,   616,    25,    26,
     617,    28,   618,    30,     0,    31,     0,  1286,  1287,  1288,
      36,    37,     0,    39,    40,    41,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,  1302,     0,     0,     0,   402,     0,     0,     0,
       0,     0,    65,    66,    67,     0,  1315,     0,     0,     0,
       0,  1321,     0,     0,     0,     0,     0,     0,  1325,     0,
       0,     0,  1327,  1328,     0,     0,     0,     0,     0,  1333,
    1334,     0,     0,     0,  1336,     0,     0,     0,     0,     0,
       0,     0,  1343,     0,     0,     0,     0,     0,   839,     0,
       0,     0,  1353,     0,  1354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   923,  1371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,  1412,
       0,     0,   421,     0,     0,  1386,     0,     0,     0,     0,
    1388,  1389,  1390,  1391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1399,     0,     0,     0,     0,     0,     0,
       0,     0,  1409,     0,     0,     0,     0,     0,     0,     0,
       0,   907,     0,     0,     0,     0,     0,     0,  1419,  1420,
       0,     0,     0,     0,     0,     0,  1426,   104,   307,     0,
     919,     0,     0,   107,   108,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
    1443,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   140,     0,   142,     0,     0,     0,     0,  1457,     0,
     522,     0,     0,   146,   147,   148,     0,     0,     0,     0,
       0,   149,     0,     0,     0,  1469,     0,  1470,     0,     0,
     421,     0,     0,     0,     0,     0,     0,  1477,     0,     0,
       0,     0,     0,     0,     0,     0,   993,     0,   995,     0,
    1482,     0,     0,     0,     0,  1486,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,   421,     0,     0,   402,     0,     0,     0,  1504,     0,
    1507,     0,  1510,     0,     0,     0,  1010,     0,     0,     0,
       0,     0,   421,     0,     0,     0,  1523,  1524,  1525,  1526,
    1527,   152,     0,     0,     0,     0,     0,     0,   155,   156,
     157,   158,   159,     0,     0,  1538,  1539,     0,     0,  1440,
    1541,     0,     0,     0,     0,     0,   160,   161,     0,     0,
    1545,   162,     0,     0,  1549,     0,   276,     0,     0,   375,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1055,  1056,     0,  1058,     0,  1061,  1062,     7,     8,
    1065,  1066,     0,     0,  1574,     0,     0,     0,     0,  1321,
       0,     0,     0,     0,     0,     0,  1582,     0,     0,     0,
       0,     0,     0,  1590,     0,     0,  1594,     0,     0,  1598,
    1534,   527,     0,  1601,     0,     0,     0,   421,     0,   421,
    1608,  1609,  1610,  1611,     0,     0,     0,     0,     0,     0,
    1615,     0,     0,  1617,     0,   615,    22,    23,   616,    25,
      26,   617,    28,   618,    30,     0,    31,     0,     0,     0,
       0,    36,    37,     0,    39,    40,    41,     0,     0,     0,
      44,     0,     0,     0,  1141,  1142,  1143,     0,     0,     0,
    1645,     0,     0,     0,  1151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   421,     0,  1659,  1660,  1661,
    1662,     0,     0,    65,    66,    67,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,     0,     0,     0,     0,
       0,     0,     0,  1198,     0,     0,     0,     0,     0,  1693,
    1694,  1695,  1696,     0,     0,     0,     0,     0,     0,  1215,
       0,     0,     0,     0,     0,  1221,     0,     0,     0,     0,
       0,  1226,     0,  1228,  1229,     0,   924,     0,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   655,   400,   401,
    1256,     0,     0,     0,   402,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1267,     0,     0,     0,  1271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   267,     0,     0,     0,     0,   107,   108,   109,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   269,  1472,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,  1572,   146,   147,   148,     0,
       7,     8,     0,     0,   149,  1313,   270,     0,     0,   271,
       0,     0,   272,     0,   273,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   274,     0,     0,     0,
     402,     0,     0,    46,    47,    48,    49,    50,     0,     0,
       0,    54,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   615,    22,    23,
     616,    25,    26,   617,    28,   618,    30,     0,    31,     0,
       0,     0,     0,    36,    37,     0,    39,    40,    41,     0,
    1198,     0,    44,     0,   152,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   159,     0,  1392,     0,     0,
       0,     0,     0,     0,  1401,     0,     0,  1402,     0,   475,
    1378,  1406,     0,     0,   162,    65,    66,    67,     0,   477,
       0,     0,     0,     0,   166,     0,   236,   525,  1628,     0,
    1421,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,  1612,   402,
       0,  1198,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,     0,     0,     0,     0,     0,     0,   947,     0,
     104,   267,     0,     0,     0,  1454,   107,   108,   109,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   269,     0,     0,     0,   527,     0,     0,
       0,     0,   138,   139,   140,     0,   142,     0,     0,     0,
       0,     0,     0,     0,  1198,     0,   146,   147,   148,     0,
       0,     0,     0,     0,   149,     0,   270,     0,     0,   271,
    1198,     0,   272,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,  1516,     0,     0,
       0,     0,     0,    46,    47,    48,    49,    50,     0,     0,
       0,    54,     0,     0,    57,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   152,     0,  1559,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   160,
     420,     0,   402,     0,   162,     0,     0,     0,     0,   276,
       0,     0,     0,     0,   166,     0,     0,   525,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   528,   400,   401,     0,   104,   267,   106,
     402,     0,  1198,   107,   108,   109,     0,  1619,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     269,     0,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     7,     8,   143,   144,     0,
       0,   145,     0,   146,   147,   148,     0,     0,     0,     0,
       0,   149,   150,   270,     0,     0,   271,     0,     0,   272,
       0,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,  1198,     0,
      46,    47,    48,    49,    50,     0,     0,     0,    54,     0,
       0,    57,   615,    22,    23,   616,    25,    26,   617,    28,
     618,    30,     0,    31,     0,     0,     0,     0,    36,    37,
       0,    39,    40,    41,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   153,   154,     0,     0,     0,     0,   155,   156,
     157,   158,   159,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,     0,     0,     0,   160,   275,     0,     0,
       0,   162,     0,     0,     0,     0,   276,     0,   104,   267,
     268,   166,     0,  1405,   107,   108,   109,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   269,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,   987,   142,     0,     0,     0,     7,     8,
       0,     0,     0,     0,   146,   147,   148,     0,     0,     0,
       0,     0,   149,     0,   270,     0,     0,   271,     0,     0,
     272,     0,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,     0,     0,     0,
     527,    46,    47,    48,    49,    50,     0,     0,     0,    54,
       0,     0,    57,     0,     0,   615,    22,    23,   616,    25,
      26,   617,    28,   618,    30,     0,    31,     0,     0,     0,
       0,    36,    37,     0,    39,    40,    41,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,   155,
     156,   157,   158,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,     0,   160,   275,     0,
       0,     0,   162,     0,     0,     0,     0,   276,     0,   104,
     307,   106,   166,     0,   277,   107,   108,   109,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,  1087,     7,     8,   143,
     144,     0,     0,   145,     0,   146,   147,   148,     0,     0,
       0,     0,     0,   149,   150,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   655,   400,   401,     0,
       0,     0,     0,   402,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   615,    22,    23,   616,    25,    26,
     617,    28,   618,    30,     0,    31,     0,     0,     0,     0,
      36,    37,     0,    39,    40,    41,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   153,   154,     0,     0,     0,     0,
     155,   156,   157,   158,   159,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,     0,     0,     0,   160,   161,
       0,     0,     0,   162,     0,     0,     0,     0,   276,     0,
     104,   267,  1265,   166,     0,  1206,   107,   108,   109,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   269,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,  1562,   142,     0,     0,     0,
       7,     8,     0,     0,     0,     0,   146,   147,   148,     0,
       0,     0,     0,     0,   149,     0,   270,     0,     0,   271,
       0,     0,   272,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,     0,
       0,     0,     0,    46,    47,    48,    49,    50,     0,     0,
       0,    54,     0,     0,    57,     0,     0,   615,    22,    23,
     616,    25,    26,   617,    28,   618,    30,     0,    31,     0,
       0,     0,     0,    36,    37,     0,    39,    40,    41,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   778,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,     0,   160,
     275,     0,     0,     0,   162,     0,     0,     0,     0,   276,
       0,   104,   307,   106,   166,     0,  1266,   107,   108,   109,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,   857,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,  1630,     0,
       0,   143,   144,     0,     0,   145,     0,   146,   147,   148,
       0,   104,   307,   106,     0,   149,   150,   107,   108,   109,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   143,   144,     0,     0,   145,     0,   146,   147,   148,
       0,     0,     0,     0,     0,   149,   150,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   152,   153,   154,     0,   402,
       0,     0,   155,   156,   157,   158,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,   162,     0,     0,     0,     0,
     276,     0,     0,     0,     0,   166,     0,  1398,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   979,   152,   153,   154,   402,     0,
       0,     0,   155,   156,   157,   158,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,   162,     0,     0,     0,     0,
     276,     0,   104,   267,     0,   166,     0,  1408,   107,   108,
     109,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   269,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   140,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,     0,     0,     0,     0,     0,   149,     0,   270,     0,
       0,   271,     0,     0,   272,     0,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,     0,     0,     0,     0,    46,    47,    48,    49,    50,
       0,     0,     0,    54,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,  1146,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   160,   275,     0,     0,     0,   162,     0,     0,     0,
       0,   276,     0,   104,   267,     0,   166,     0,   277,   107,
     108,   109,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   269,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,   148,     0,     0,     0,     0,     0,   149,     0,   270,
       0,     0,   271,     0,     0,   272,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   274,
       0,     0,     0,     0,     0,     0,    46,    47,    48,    49,
      50,     0,     0,     0,    54,     0,     0,    57,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,   152,     0,     0,
     402,     0,     0,     0,   155,   156,   157,   158,   159,   855,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   420,     0,     0,     0,   162,     0,     0,
       0,     0,   276,     0,   104,   267,     0,   166,     0,   521,
     107,   108,   109,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   269,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   140,     0,
     142,     0,     7,     8,     0,     0,     0,     0,     0,     0,
     146,   147,   148,     0,     0,     0,     0,     0,   149,     0,
     270,     0,     0,   271,     0,     0,   272,     0,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,     0,     0,     0,    54,     0,     0,    57,   615,
      22,    23,   616,    25,    26,   617,    28,   618,    30,     0,
      31,     0,     0,     0,     0,    36,    37,     0,    39,    40,
      41,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   159,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
       0,     0,     0,   160,   420,     0,     0,     0,   162,     0,
       0,     0,     0,   276,     0,   104,   267,     0,   166,     0,
     766,   107,   108,   109,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   269,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
       0,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,     0,     0,     0,     0,     0,   149,
       0,   270,     0,     0,   271,     0,     0,   272,     0,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,     0,     0,     0,     0,     0,     0,    46,    47,
      48,    49,    50,     0,     0,     0,    54,     0,     0,    57,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
       0,     0,     0,     0,     0,  1358,     0,  1359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,   155,   156,   157,   158,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   275,     0,     0,     0,   162,
       0,     0,     0,     0,   276,     0,   104,   267,     0,   166,
       0,  1270,   107,   108,   109,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   269,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,     0,
     149,     0,   270,     0,     0,   271,     0,     0,   272,     0,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,     0,     0,     0,     0,     0,    46,
      47,    48,    49,    50,     0,     0,     0,    54,     0,     0,
      57,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1393,     0,  1394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,  1378,     0,     0,     0,
     162,     0,     0,     0,     0,   477,     0,   104,   307,   106,
     166,     0,   236,   107,   108,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,     0,   143,   144,     0,
       0,   145,     0,   146,   147,   148,     0,     0,     0,     0,
       0,   149,   150,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,     0,     0,     0,   104,
     267,  1502,     0,  1503,     0,   107,   108,   109,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   269,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   140,     0,   142,     0,     0,     0,     0,
       0,   152,   153,   154,     0,   146,   147,   148,   155,   156,
     157,   158,   159,   149,     0,   270,     0,     0,   271,     0,
       0,   272,     0,   273,     0,     0,   160,   161,     0,     0,
       0,   162,     0,     0,     0,   274,   276,     0,     0,     0,
       0,   166,    46,    47,    48,    49,    50,     0,     0,     0,
      54,     0,     0,    57,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,     0,     0,     0,     0,     0,     0,
       0,   902,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
     155,   156,   157,   158,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   420,
       0,     0,     0,   162,   104,   307,     0,     0,   276,     0,
     107,   108,   109,   166,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   140,     0,
     142,     0,     0,     0,     0,     0,     0,     0,   104,   307,
     146,   147,   148,     0,   107,   108,   109,     0,   149,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,     0,   142,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,     0,     0,     0,
       0,     0,   149,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,   152,     0,
     950,     0,     0,     0,     0,   155,   156,   157,   158,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   160,   161,     0,     0,     0,   162,     0,
       0,     0,     0,   276,     0,     0,   552,     0,   166,     0,
       0,     0,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,   152,     0,     0,    -4,    -4,     0,     0,   155,
     156,   157,   158,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   161,     0,
      -4,    -4,   162,     0,     0,     0,     0,   276,     0,     0,
       0,     0,   166,    -4,    -4,    -4,     0,     0,    -4,    -4,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,    18,     0,    19,    20,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,    60,    61,    62,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,    64,    65,    66,
      67,     0,     0,    68,     0,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    81,    82,    83,    84,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
       0,     0,   970,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
     998,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,  1091,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,  1356,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,     0,     0,  1375,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
       0,     0,  1429,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
    1430,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,  1431,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,  1432,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,     0,     0,  1433,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
       0,     0,  1463,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
    1518,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,  1528,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,  1529,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,     0,     0,  1550,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
       0,     0,  1553,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
    1556,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,  1583,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,  1587,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,     0,     0,  1622,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
       0,     0,  1624,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
    1626,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,  1644,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,  1668,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,     0,     0,  1705,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
       0,     0,  1706,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
    1707,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,  1708,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     0,   699,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,     0,     0,     0,     0,
       0,     0,  1439,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,   763,     0,     0,     0,     0,   706,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,   646,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
     706,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,   707,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,   775,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,   806,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,   814,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
     815,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,   816,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,   827,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,   932,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,   933,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
     934,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,   965,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1050,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1089,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1090,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
    1145,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1278,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1279,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1280,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1281,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
    1316,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1317,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1324,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1464,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1465,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
    1466,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1467,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1483,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1484,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1488,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
    1568,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1569,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1570,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1571,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1578,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
    1581,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1618,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1635,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1636,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1637,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,     0,
    1638,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,  1677,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,  1678,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,  1679,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,  1680,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   744,     0,   745,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,     0,     0,
     607,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,   780,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,     0,     0,   787,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,   793,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
       0,     0,   869,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,     0,     0,   958,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,     0,     0,   959,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,     0,
       0,   963,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,     0,     0,   964,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,     0,     0,   966,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,     0,     0,
    1000,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,     0,     0,  1045,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,     0,     0,  1275,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,     0,     0,  1307,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
       0,     0,  1452,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,   604,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   654,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   658,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   659,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   661,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,   663,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,   664,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
     667,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,   668,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,   763,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,   771,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   772,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   773,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   779,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   891,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,   896,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,   901,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
     904,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,   905,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,   911,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,   916,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   917,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   918,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   949,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   951,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,   952,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,   953,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
     957,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,  1176,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,  1357,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,  1374,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,  1397,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,  1577,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,  1642
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1259)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,   469,   470,   229,   351,     4,   353,     5,   192,
    1268,     5,     4,     6,   197,   361,     4,   244,   201,     6,
       5,     7,   375,     5,   377,   208,     5,     4,     6,   256,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
      75,     3,     5,     4,     6,     5,     5,     5,     5,   172,
     173,     6,     6,     6,     6,     6,     6,     6,     6,     4,
      63,     6,     0,   944,   182,   188,   184,   190,   182,   172,
     173,   172,   173,   191,    77,     6,    75,   304,    77,   306,
      92,  1339,    47,    48,    13,    50,   103,   190,   189,     6,
     102,     7,   275,   182,   277,   172,   173,     6,   110,   111,
     112,   182,    69,   184,   116,   117,   118,   119,    69,   172,
     173,   188,    73,   190,   182,    77,   172,   173,   948,   179,
     180,   189,   172,   173,    85,   188,   182,   190,     7,   172,
     173,   182,     7,   189,   122,   123,   124,   125,   135,   189,
       6,   182,     7,   172,   173,   182,   189,   184,   189,   186,
     135,     6,   189,   135,   191,   132,   133,   172,   173,   188,
     132,   133,     6,   166,  1422,   167,     6,   141,   120,     8,
     120,   120,   120,   188,   184,   178,   179,   135,   190,   183,
    1438,   191,   169,   186,   188,    75,   184,    77,   186,   192,
     182,   169,   189,   191,   197,   189,    77,   189,   201,   552,
     186,   204,   190,   386,   166,   208,   209,   210,   211,   182,
     189,   214,   215,   216,   182,   189,   178,   179,   189,   189,
     189,   189,   225,   189,   186,   228,   189,     6,   182,   189,
     189,  1112,   189,   460,   461,   189,   189,   420,   189,   184,
     184,   172,   173,   159,   160,   161,   162,   250,   251,   252,
     183,   604,   132,   480,   607,   188,   188,     7,   190,   262,
     263,   178,   179,   179,   180,   145,   146,   232,   233,   184,
     186,     7,   275,   183,   277,   240,   172,   173,   188,   244,
     159,   160,   161,   162,   159,   160,   161,   162,     6,     7,
     172,   173,   188,   192,   159,   160,   161,   162,   197,   182,
     179,   180,   201,    79,   179,   180,   188,   310,   311,   208,
     182,   538,   184,   496,   497,   498,   183,    75,   185,   191,
     323,   188,  1580,   316,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   521,   188,
      72,   190,   181,    75,   183,   528,   172,   173,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   182,   361,   362,
     377,   182,   188,   366,   367,   368,   369,    72,   172,   173,
      75,   364,   555,     8,   179,   180,    69,   370,   188,    72,
     190,   186,    75,   386,   188,   172,   173,   172,   173,   351,
     352,   353,   354,   355,   356,   185,   358,   359,   188,   361,
     362,   188,   182,   188,   366,   367,   368,   369,  1666,   159,
     160,   161,   162,   182,     4,   172,   173,   420,   179,   180,
     172,   173,   182,   159,   160,   161,   162,    75,   189,   179,
     180,   188,   172,   173,   787,   352,   188,   354,   355,   356,
     182,   358,   359,   179,   180,   362,     6,   189,   188,   366,
     367,   368,   182,   172,   173,   448,   449,   450,   451,   189,
     643,   185,   645,   189,   188,   172,   173,   469,   470,   188,
     172,   173,   655,   656,    75,   702,   172,   173,    75,   172,
     173,   188,   172,   173,   172,   173,   188,   386,   188,   182,
     190,   182,   188,   496,   497,   498,   189,    72,   188,   183,
     188,   185,   467,   468,   507,   189,    96,    97,    98,    99,
     475,   172,   173,   188,   104,   190,   699,   107,   521,   174,
     175,   176,   188,    75,   190,   528,   181,   188,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     8,   189,   561,   507,   181,   179,   180,   183,
      69,   185,   555,    72,   188,   190,    75,   189,    77,   912,
     913,   914,   915,   746,    69,   179,   180,    72,   189,    92,
      75,   183,   755,   185,   757,   189,   759,   189,   761,   102,
     183,    72,    92,   766,    72,   188,   769,   110,   111,   112,
     607,    75,   102,   116,   117,   118,   119,   496,   497,   498,
     110,   111,   112,   606,     6,     7,   116,   117,   118,   119,
      69,     4,   183,    72,   185,   608,    75,  1447,    77,  1449,
       4,  1451,   521,   848,   188,  1506,   190,   184,  1509,   186,
     184,  1512,   186,    72,   191,   818,    75,   191,    77,    92,
     643,    72,   645,     4,    75,   648,    77,     4,   651,   102,
     653,   182,   655,   656,   184,   183,   555,   110,   111,   112,
     188,   182,   182,   116,   117,   118,   119,  1020,   851,   852,
     853,   854,   183,   188,   185,   190,   679,   188,     6,   183,
     190,   185,   182,  1036,   188,   183,   648,   185,   183,   651,
     188,   653,   188,   188,   190,   698,   699,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   183,   188,     6,   190,   181,   188,   188,   182,   190,
     903,  1602,     4,   188,   190,   190,   743,    75,   188,    77,
     190,   648,   188,  1563,   190,     4,   653,   190,   182,   188,
     705,   190,     7,   746,   643,   182,   645,   712,   188,     4,
     190,     6,   755,   718,   757,   188,   759,   190,   761,   188,
     188,   190,   190,   766,     6,  1646,   769,   188,  1649,   190,
     787,  1652,   182,   188,  1655,   190,   793,   172,   173,  1246,
    1247,   784,   188,   786,   190,   172,   173,   174,   175,   176,
     793,  1621,   182,  1623,   181,  1625,   188,   188,   190,   190,
     699,  1631,  1027,  1156,   182,   188,  1687,   190,  1689,   188,
    1691,   190,   209,   210,   211,   818,   182,   214,   215,   216,
     823,   824,   825,   826,   188,   188,   190,   190,   188,   182,
     190,   793,   835,   188,   827,   190,   188,   188,   190,   190,
    1670,   188,  1672,   190,  1674,   182,   182,   746,   851,   852,
     853,   854,   869,   250,   251,   188,   755,   190,   757,   182,
     759,   823,   761,   825,   826,   262,   263,   766,   182,   189,
     769,   874,   188,   835,   190,     6,   793,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   889,   890,   189,   892,
     181,   894,   895,   189,     6,   898,   899,   189,   182,   188,
     903,   190,   188,   188,   190,   190,   823,   182,   825,   826,
     182,   188,   874,   190,   188,   188,   190,   190,   835,   818,
     885,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   188,  1119,   190,   188,   181,
     190,   188,   188,   190,   190,   188,    92,   190,   188,   966,
     190,   182,   851,   852,   853,   854,   102,   874,   188,   182,
     190,     6,  1187,   182,   110,   111,   112,   932,   933,   934,
     116,   117,   118,   119,    92,  1442,   188,   182,   190,   982,
     983,   984,   182,   182,   102,   182,   531,    92,   182,   992,
       6,   182,   110,   111,   112,   182,     4,   102,   116,   117,
     118,   119,   184,  1020,   903,   110,   111,   112,   189,   189,
     189,   116,   117,   118,   119,   189,   189,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   182,   574,
     575,   576,   577,   578,   579,   580,     6,   182,  1041,   584,
     585,   586,   182,   182,   190,   189,   189,   189,   184,   184,
     595,   184,   184,     6,  1057,     6,   186,   135,  1051,     6,
    1063,   189,  1408,     6,   191,   191,  1069,     6,  1071,  1072,
     189,     6,   190,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,    92,   189,  1266,   184,   190,     4,  1270,   181,   186,
       7,   102,   184,   189,     7,  1098,   190,     6,     6,   110,
     111,   112,     6,   183,     7,   116,   117,   118,   119,     7,
    1113,     7,     6,   189,  1117,     7,  1119,     6,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     7,     6,     4,     5,   181,     6,     6,     4,
      50,  1158,   132,    50,    50,    50,  1111,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   189,  1165,   183,     6,   181,     6,   188,   183,    39,
      40,    41,    42,    43,    44,   188,  1169,   183,    48,   190,
       6,   188,   183,    53,    54,   188,  1179,    57,  1413,   188,
    1193,   188,    92,     4,   183,  1378,   183,   185,    68,     4,
    1203,     7,   102,  1165,     6,     6,     6,     6,   135,     7,
     110,   111,   112,  1206,     7,  1398,   116,   117,   118,   119,
    1119,     7,  1405,   135,     7,     7,     7,     7,   189,  1456,
       4,     6,   186,   135,   183,   183,     6,   183,   183,     7,
     190,  1203,     7,   185,  1246,  1247,   190,  1212,  1165,  1242,
       7,   189,   189,   189,   186,   189,  1439,     6,   189,  1276,
       6,     6,     6,  1266,     6,  1268,     7,  1270,   184,     6,
     189,   182,     6,    77,   169,     7,     7,  1460,   148,   149,
       7,   182,  1285,  1248,     7,  1250,  1203,  1252,     7,  1292,
     190,     7,  1295,     7,     6,     6,  1299,     7,  1291,     7,
       7,  1266,    92,     4,  1269,  1270,  1299,  1300,     7,   179,
     180,   856,   102,     4,     6,  1318,   186,   189,     6,   182,
     110,   111,   112,     7,     6,   189,   116,   117,   118,   119,
     102,     7,     7,     7,     6,     6,  1339,  1564,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     6,     6,     6,    75,     4,     4,   141,
    1373,     4,   144,   190,     6,  1378,     6,   149,   150,     6,
       4,     6,  1565,     6,  1567,   188,   183,   183,    92,   183,
       7,   183,     6,   188,   182,  1398,    85,   186,   102,   186,
     190,     6,  1405,     6,   189,  1408,   110,   111,   112,     6,
     189,   189,   116,   117,   118,   119,   189,     6,   189,  1422,
     189,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,  1438,  1439,     6,     5,   181,
    1442,     4,     6,     4,   131,     7,  1408,     6,   184,   189,
    1633,   189,  1455,     6,   999,     6,     6,  1460,     6,  1004,
    1005,  1006,  1007,  1008,   189,   189,     6,   189,     6,  1014,
    1015,    12,    13,     6,     6,   188,     4,     4,   135,     4,
       6,  1446,    92,  1448,     6,  1450,   190,     6,     6,     6,
       6,     4,   102,  1458,     6,   267,  1461,     6,     6,  1398,
     110,   111,   112,     6,     6,     5,   116,   117,   118,   119,
       6,  1514,   284,     6,     6,     6,   189,     6,     6,     6,
       6,     6,     6,     6,     6,   188,     6,     6,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     6,    80,
    1439,  1534,     6,   183,    85,    86,     6,    88,    89,    90,
       7,     6,   186,    94,     6,     6,     5,     7,   189,    73,
       6,  1460,  1565,   189,  1567,     6,     6,   189,     6,   190,
     190,   189,   130,   189,   189,     6,    84,  1580,   189,     6,
     190,   190,  1585,     6,  1129,     6,   127,   128,   129,   133,
       6,     6,     6,     6,     6,  1140,   189,     4,     5,   189,
       6,     6,  1567,     6,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     6,  1612,
     190,   189,   181,     6,   189,    92,     6,    92,     6,     6,
    1633,     6,    39,    40,    41,    42,    43,    44,  1641,     6,
       6,    48,     6,     6,   190,     6,    53,    54,     6,   190,
      57,     6,   160,   161,   162,   163,   164,     6,   189,   189,
     189,    68,     6,  1666,     6,   189,  1565,     6,  1567,   177,
       6,     6,     6,   181,   189,     6,     6,     6,  1681,  1641,
    1683,     6,   189,   191,   192,   193,   194,     6,   196,   197,
     198,   199,   189,   201,   202,   203,     6,     6,     6,   189,
     208,     6,     6,     6,     6,  1048,  1709,  1537,   189,     3,
    1427,  1056,   418,    92,  1428,     3,   446,    -1,   226,  1681,
    1183,  1683,    -1,   102,  1641,    -1,    -1,   235,   236,    -1,
      -1,   110,   111,   112,  1633,    -1,   244,   116,   117,   118,
     119,   148,   149,    -1,    -1,    -1,    -1,  1709,    -1,    -1,
      -1,    -1,    -1,  1298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1681,    -1,  1683,   275,   276,   277,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,   287,
     288,   289,    -1,   291,    -1,   102,   294,   295,    -1,    -1,
     298,    -1,  1709,   110,   111,   112,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,    -1,   313,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   326,    -1,
      -1,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,    -1,    -1,   363,    -1,   365,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,   190,    -1,    -1,   181,   385,   386,    -1,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,    -1,    -1,   405,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,   420,    -1,    -1,    -1,    85,    86,   426,    88,
      89,    90,    -1,   431,    -1,    94,    -1,    -1,   436,   437,
      -1,    -1,    -1,    -1,   442,   443,    -1,    -1,    -1,   447,
     448,   449,   450,   451,   452,   453,   454,    -1,    -1,    -1,
      -1,     6,    92,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,    -1,    -1,    -1,   472,   473,   474,   475,   476,   477,
      -1,    -1,    -1,   481,   482,   483,   484,   485,    -1,    -1,
      -1,   489,    -1,    -1,   492,   493,    -1,    -1,   496,   497,
     498,    -1,    -1,   501,   502,   503,   504,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,    -1,   527,
     528,   190,   530,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
     548,   181,     3,     4,     5,    -1,   554,   555,     9,    10,
      11,   559,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,   609,    -1,    -1,    -1,    -1,    67,    68,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     6,    -1,    -1,    -1,   181,    -1,    -1,     5,
      -1,    -1,   640,    -1,    -1,   643,    -1,   645,   646,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,   656,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,   669,    -1,    39,    40,    41,    42,    43,    44,    -1,
     678,    -1,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,
     141,    57,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,
      -1,   699,    68,   154,   155,   156,   157,   158,   706,   707,
       6,    -1,    -1,    -1,   712,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,    -1,    -1,    -1,   177,   725,    -1,    -1,
     728,   182,    -1,   184,    -1,   186,   187,    -1,   189,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   755,    -1,   757,
      -1,   759,    -1,   761,    -1,    -1,    -1,    -1,   766,    -1,
      -1,   769,    -1,    -1,    -1,    -1,    -1,   775,    -1,   777,
     778,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,   806,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   814,   815,   816,    -1,
     818,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   833,   204,    -1,    -1,   181,
     838,    -1,    -1,   841,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   851,   852,   853,   854,   225,    -1,   857,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,   252,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,   903,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,   310,   311,    12,    13,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,   323,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,   962,    -1,    -1,   965,    -1,    -1,
      -1,   969,    -1,   971,   972,   973,    -1,    -1,    -1,    -1,
      -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   996,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     6,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
    1028,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,  1039,  1040,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,  1050,  1051,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,   182,    -1,    -1,    12,    13,   187,
      -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1088,  1089,  1090,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1098,    -1,  1100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1119,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    -1,  1145,  1146,  1147,
      85,    86,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,  1180,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,    -1,  1194,    -1,    -1,    -1,
      -1,  1199,    -1,    -1,    -1,    -1,    -1,    -1,  1206,    -1,
      -1,    -1,  1210,  1211,    -1,    -1,    -1,    -1,    -1,  1217,
    1218,    -1,    -1,    -1,  1222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1230,    -1,    -1,    -1,    -1,    -1,   606,    -1,
      -1,    -1,  1240,    -1,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,  1254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1266,     6,
      -1,    -1,  1270,    -1,    -1,  1273,    -1,    -1,    -1,    -1,
    1278,  1279,  1280,  1281,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1291,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,  1316,  1317,
      -1,    -1,    -1,    -1,    -1,    -1,  1324,     3,     4,    -1,
     698,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    1358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,  1376,    -1,
    1378,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,  1393,    -1,  1395,    -1,    -1,
    1398,    -1,    -1,    -1,    -1,    -1,    -1,  1405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   784,    -1,   786,    -1,
    1418,    -1,    -1,    -1,    -1,  1423,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,  1439,    -1,    -1,   181,    -1,    -1,    -1,  1446,    -1,
    1448,    -1,  1450,    -1,    -1,    -1,   824,    -1,    -1,    -1,
      -1,    -1,  1460,    -1,    -1,    -1,  1464,  1465,  1466,  1467,
    1468,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,    -1,  1483,  1484,    -1,    -1,     6,
    1488,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,    -1,
    1498,   177,    -1,    -1,  1502,    -1,   182,    -1,    -1,   185,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   889,   890,    -1,   892,    -1,   894,   895,    12,    13,
     898,   899,    -1,    -1,  1532,    -1,    -1,    -1,    -1,  1537,
      -1,    -1,    -1,    -1,    -1,    -1,  1544,    -1,    -1,    -1,
      -1,    -1,    -1,  1551,    -1,    -1,  1554,    -1,    -1,  1557,
       7,     8,    -1,  1561,    -1,    -1,    -1,  1565,    -1,  1567,
    1568,  1569,  1570,  1571,    -1,    -1,    -1,    -1,    -1,    -1,
    1578,    -1,    -1,  1581,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,   982,   983,   984,    -1,    -1,    -1,
    1618,    -1,    -1,    -1,   992,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1633,    -1,  1635,  1636,  1637,
    1638,    -1,    -1,   127,   128,   129,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1041,    -1,    -1,    -1,    -1,    -1,  1677,
    1678,  1679,  1680,    -1,    -1,    -1,    -1,    -1,    -1,  1057,
      -1,    -1,    -1,    -1,    -1,  1063,    -1,    -1,    -1,    -1,
      -1,  1069,    -1,  1071,  1072,    -1,   190,    -1,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
    1098,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1113,    -1,    -1,    -1,  1117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    59,    60,    61,    -1,
      12,    13,    -1,    -1,    67,  1193,    69,    -1,    -1,    72,
      -1,    -1,    75,    -1,    77,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    89,    -1,    -1,    -1,
     181,    -1,    -1,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    89,    90,    -1,
    1268,    -1,    94,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,    -1,  1285,    -1,    -1,
      -1,    -1,    -1,    -1,  1292,    -1,    -1,  1295,    -1,   172,
     173,  1299,    -1,    -1,   177,   127,   128,   129,    -1,   182,
      -1,    -1,    -1,    -1,   187,    -1,   189,   190,     6,    -1,
    1318,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,     7,   181,
      -1,  1339,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
       3,     4,    -1,    -1,    -1,  1373,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1422,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    72,
    1438,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,  1455,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   104,    -1,    -1,   107,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,   147,    -1,  1514,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,   172,
     173,    -1,   181,    -1,   177,    -1,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,     3,     4,     5,
     181,    -1,  1580,     9,    10,    11,    -1,  1585,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    12,    13,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,  1666,    -1,
      96,    97,    98,    99,   100,    -1,    -1,    -1,   104,    -1,
      -1,   107,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,    -1,    -1,    -1,   172,   173,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,   182,    -1,     3,     4,
       5,   187,    -1,   189,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,   190,    49,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    -1,    72,    -1,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
       8,    96,    97,    98,    99,   100,    -1,    -1,    -1,   104,
      -1,    -1,   107,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,    -1,   172,   173,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,   182,    -1,     3,
       4,     5,   187,    -1,   189,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   190,    12,    13,    53,
      54,    -1,    -1,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,    -1,    -1,    -1,   172,   173,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,   182,    -1,
       3,     4,     5,   187,    -1,   189,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,   190,    49,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    72,
      -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   104,    -1,    -1,   107,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,   172,
     173,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,   182,
      -1,     3,     4,     5,   187,    -1,   189,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,     8,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   190,    -1,
      -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      -1,     3,     4,     5,    -1,    67,    68,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   147,   148,   149,    -1,   181,
      -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,    -1,   187,    -1,   189,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     8,   147,   148,   149,   181,    -1,
      -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
     182,    -1,     3,     4,    -1,   187,    -1,   189,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      -1,    72,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,
      -1,    -1,    -1,   104,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     8,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,   182,    -1,     3,     4,    -1,   187,    -1,   189,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      -1,    -1,    72,    -1,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,    -1,    -1,   107,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,   147,    -1,    -1,
     181,    -1,    -1,    -1,   154,   155,   156,   157,   158,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,   182,    -1,     3,     4,    -1,   187,    -1,   189,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    -1,    72,    -1,    -1,    75,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,   100,    -1,    -1,    -1,   104,    -1,    -1,   107,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   182,    -1,     3,     4,    -1,   187,    -1,
     189,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    -1,    -1,    72,    -1,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,   107,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,   182,    -1,     3,     4,    -1,   187,
      -1,   189,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    -1,    72,    -1,    -1,    75,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,
     107,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   182,    -1,     3,     4,     5,
     187,    -1,   189,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,     3,
       4,   188,    -1,   190,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,    59,    60,    61,   154,   155,
     156,   157,   158,    67,    -1,    69,    -1,    -1,    72,    -1,
      -1,    75,    -1,    77,    -1,    -1,   172,   173,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    89,   182,    -1,    -1,    -1,
      -1,   187,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     104,    -1,    -1,   107,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,    -1,    -1,   177,     3,     4,    -1,    -1,   182,    -1,
       9,    10,    11,   187,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      59,    60,    61,    -1,     9,    10,    11,    -1,    67,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
     190,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   182,    -1,    -1,   185,    -1,   187,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    12,    13,    -1,    -1,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,
      37,    38,   177,    -1,    -1,    -1,    -1,   182,    -1,    -1,
      -1,    -1,   187,    50,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,   121,     4,    -1,    -1,    -1,   126,
     127,   128,   129,    12,    13,   132,    -1,   134,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,   150,   151,   152,   153,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,    -1,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,   183,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,   183,    -1,   185,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
     185,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,   185,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,   185,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
      -1,    -1,   185,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,   185,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
      -1,   185,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,   185,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,   185,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
     185,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,   185,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,   185,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
      -1,    -1,   185,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,   183,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,   183,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,   183,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,   183,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,   183,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
     183,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,   183,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,   183,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,   183,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,   183,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,   183,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,   183,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,   183,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
     183,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,   183,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,   183,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,   183,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,   183,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,   183,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,   183,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,   183,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
     183,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,   183,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,   183,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,   183,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,   183,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,   183,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,    -1,    -1,   181,    -1,   183
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   193,   194,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    55,    56,    58,    62,    63,    65,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     113,   114,   115,   121,   126,   127,   128,   129,   132,   134,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   150,   151,   152,   153,   195,   197,   198,   218,   235,
     236,   239,   240,   241,   242,   243,   244,   245,   266,   267,
     268,   269,   287,   288,     3,     4,     5,     9,    10,    11,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    53,    54,    57,    59,    60,    61,    67,
      68,   141,   147,   148,   149,   154,   155,   156,   157,   158,
     172,   173,   177,   182,   184,   186,   187,   189,   191,   216,
     270,   271,   283,   284,   287,   288,    13,    75,   182,   182,
       6,   189,     6,     6,     6,     6,   182,     6,     6,   184,
     184,   182,   189,   182,   182,     4,   182,   189,   182,   182,
       4,   189,   182,   182,    79,    75,    75,     6,   189,    69,
      72,    75,    75,    75,    72,    75,    77,    77,    69,    72,
      75,    77,    72,    75,    77,    72,    75,   182,    72,   132,
     145,   146,   189,   172,   173,   182,   189,   273,   274,   273,
     189,    69,    72,    75,   189,   273,     4,    69,    73,    85,
      75,    77,    75,    72,     4,   141,   189,     4,     6,    69,
      72,    75,    72,    75,     4,     4,     4,     4,     5,    36,
      69,    72,    75,    77,    89,   173,   182,   189,   236,   245,
     270,   276,   277,   278,   287,   288,     4,   182,   182,   182,
       4,   189,   280,     4,   182,   182,     6,     6,   184,     4,
     287,   288,     4,     5,   189,     5,   189,     4,   270,     6,
     182,   189,   182,   184,   191,   216,     7,   159,   160,   161,
     162,   179,   180,   214,   215,     4,   184,   186,   184,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   182,   182,   182,   182,   182,   182,
     216,   182,   216,   216,   216,     7,   182,   182,   182,   182,
     182,   270,   270,   270,   270,   185,   270,     4,   132,   133,
     288,     4,   236,   237,   238,   189,   189,     6,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   181,   189,     6,   184,   215,     6,   270,     4,
     283,   284,   288,   283,   270,   283,   286,   220,   223,   270,
     173,   270,   278,   279,   270,   270,   182,   270,   279,   270,
     270,   182,   279,   270,   270,   276,   182,   189,   279,   277,
     277,   277,   182,   182,   277,   277,   277,   182,   182,   182,
     182,   182,   182,   182,   182,   276,   270,     4,   276,   280,
     189,   189,   273,   273,   273,   270,   270,   172,   173,   189,
     189,   273,   189,   189,   189,   172,   173,   182,   238,   273,
     189,   182,   189,   182,   182,   182,   277,   277,   276,   182,
       4,     6,   184,   184,   238,     6,   189,   189,   189,   277,
     277,   184,   184,   184,   184,   186,   216,   184,     5,   135,
     189,     5,   135,     5,   135,     5,   135,    69,    72,    75,
      77,   189,   270,   278,   270,   190,   279,     8,   174,     6,
     184,   216,     6,   270,   270,   270,   186,   270,   189,   135,
     270,   270,   270,     6,     6,   238,     6,   238,   184,     6,
     276,   276,   185,   270,   189,   189,   284,   276,     6,   184,
     270,     4,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   286,   283,   286,   283,   283,   283,
     276,   283,   283,   270,   286,   283,   270,   284,   270,   283,
     283,   283,   288,   284,   183,     7,   214,   185,     7,   214,
     215,   186,     7,   184,   190,    69,    72,    75,    77,   235,
     270,   279,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   199,   270,     6,
     184,   186,   183,   188,   183,   188,   188,   183,   188,   185,
     188,   219,   185,   219,   183,   174,   188,   190,   183,   183,
     270,   183,   190,   183,   183,   270,   190,   183,   183,     7,
     270,   270,   190,     6,     6,     6,   270,   270,     7,     7,
     263,   263,   270,   229,   270,   284,   230,   270,   284,   231,
     270,   284,   232,   270,   284,   270,   270,   270,     7,   189,
     183,     6,   189,   238,   238,   188,   188,   188,   273,   273,
     237,   237,   188,   270,   270,   270,   270,   249,   188,   238,
     270,   270,   270,   270,   270,     7,   264,     6,     7,   270,
       6,   270,   270,   190,   279,   279,   279,     6,     6,   270,
     270,   270,   270,     4,   183,   185,   189,   217,   288,    50,
     270,    50,    50,    50,     5,   189,     5,   189,     5,   189,
       5,   189,   279,   183,   190,   270,   189,   270,   278,   189,
     217,   183,   183,   183,   132,   188,   238,   189,     8,   183,
     185,   190,   190,   183,   188,   190,   214,   185,   270,   279,
       6,     6,   270,   185,   215,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   188,   217,   217,   217,
     217,   217,   217,   217,   188,   188,   188,   217,   188,   217,
     217,   183,   183,   188,   188,   188,   188,   188,   183,   217,
     272,   285,     6,   188,   183,   188,   183,   183,   214,   276,
     186,   214,   215,   284,   270,     6,     4,     4,   189,   281,
     185,   189,   189,   189,   189,   190,   190,     8,     4,   122,
     123,   124,   125,   190,   202,   206,   209,   211,   212,   185,
     270,     4,     6,   169,   196,   279,     6,   279,   270,     6,
     283,     6,   288,     6,   283,     7,   270,   278,   135,     7,
       7,   183,     7,   135,     7,     7,   183,   135,     7,     7,
     270,   183,   190,   189,   183,   183,   270,   276,     4,   262,
       6,   183,   183,   183,   183,   183,   183,   183,   183,   276,
     279,   186,   238,   190,   190,   273,   270,   270,   190,   190,
     270,   273,   188,   188,   188,    92,   102,   110,   111,   112,
     116,   117,   118,   119,   259,   260,   273,   190,   246,   183,
     190,   183,   183,   183,   270,     6,   270,   183,   185,   185,
     190,   190,   190,   185,   185,   188,   185,   279,   185,   189,
     190,   189,   189,   189,   279,   279,   279,   279,   190,     8,
     279,   279,     7,     7,     7,   186,   270,   190,   270,   270,
       7,   186,   189,   276,     6,   276,   214,   215,   190,   190,
     185,   186,   215,   283,   270,   270,   270,   270,   279,   283,
     276,   283,   283,   284,   225,   227,   270,   283,   270,     6,
       4,   132,   133,   270,     6,     6,     6,     7,   184,   280,
     282,     6,   279,   279,   279,   279,   217,   270,   203,   182,
     182,   189,   213,     6,   215,   185,   169,   283,   183,   183,
     188,     7,   273,    75,    77,   276,   276,     7,   276,    75,
      77,   276,   276,     7,    77,   276,   276,     6,     7,     7,
     279,     7,     7,    92,   261,     6,     7,   214,   214,   214,
     214,     7,     7,     7,     6,   190,     4,   190,   188,   188,
     188,   190,   190,   273,   273,   273,     4,     6,   189,     6,
     182,     6,   120,     6,   120,     6,   120,     6,   120,   190,
     260,   188,   259,     7,     6,     7,     7,     7,     6,   189,
       6,     6,     6,    75,   270,     6,     6,   270,   186,   190,
     270,   270,   270,   270,   190,   190,   190,   190,   270,   190,
     190,   276,   276,   276,     4,   188,     8,     8,   183,     4,
       4,   276,   190,     6,   270,     6,   217,     6,     4,     6,
     217,   217,   217,   217,   217,   188,   183,   183,   183,   188,
     188,   217,   226,   188,   217,   228,   183,   183,     6,     7,
     214,   215,   186,     7,     6,   280,   270,   188,   190,   190,
     190,   190,   190,   214,   182,   270,   270,   275,   276,   189,
     186,     6,     6,   196,     6,   270,   189,   270,   284,     6,
     189,   189,    85,   234,   234,   276,     6,   189,   189,     6,
       6,   276,   189,     6,     6,     5,   276,   190,   276,   276,
       4,     6,   276,   276,   276,   276,   276,   276,   276,   276,
       7,     6,     7,   270,   270,   270,   189,   189,   188,   190,
     188,   190,   188,   190,   184,   270,   276,   270,     6,     6,
       6,     6,   270,   273,   190,     5,   189,   276,   189,   189,
     189,   276,   279,   189,     6,   185,     4,   217,   188,   188,
     188,   188,   217,     6,     6,   131,   270,   270,   270,     6,
       6,     7,   188,     6,     6,   214,   215,   283,   284,     4,
       4,   284,   270,     6,     4,   281,     6,   185,   280,     6,
       6,     6,     6,   276,   200,   270,   188,   188,   188,   190,
     201,   270,     4,   283,   188,   270,   284,   270,   270,   273,
       6,     6,     6,   270,   270,     6,   270,     5,     6,   189,
       6,   135,   233,   270,     6,     6,     6,     6,     6,     6,
       4,     6,     6,   270,   270,   284,   190,   183,   188,   190,
     237,   237,   273,     6,   250,   273,     6,   251,   273,     6,
     252,   270,   190,   188,   183,   190,   188,     6,   173,   273,
       6,   275,   273,   273,     6,   190,   270,     6,   270,   270,
     270,   270,   276,   188,   190,     8,   190,   183,   189,   270,
     284,   276,   276,   183,   217,   189,   276,   284,   189,   270,
     284,     6,     6,     7,     6,   186,     6,   183,   188,   270,
     270,   276,   189,   188,   190,     6,   270,   221,   222,   190,
     190,   190,   190,   190,     5,   275,    73,     6,   189,   189,
       6,     6,   189,   270,   190,   190,   188,   189,   188,   189,
     188,   189,   185,     6,   276,     7,   189,   270,   188,   190,
     188,   188,     6,   190,   188,   188,   188,   188,   130,   270,
     270,   279,     6,     6,   190,     6,   224,   270,   286,   280,
     133,   204,   270,   188,   188,   275,   270,     6,   188,   225,
     227,     6,     6,     6,     6,     6,     6,   190,   189,   275,
     279,   237,   188,   190,   270,   273,   259,   270,   273,   259,
     270,   273,   259,     6,   188,   190,   276,   238,   190,   273,
       6,   279,   273,   270,   270,   270,   270,   270,   190,   190,
     190,     6,   188,   190,     7,   190,     6,   189,   270,   270,
     190,   270,   190,   190,   189,   270,   190,   190,   190,   270,
     190,   188,   190,   190,   188,   190,   190,   188,   190,   276,
       6,    92,   190,   247,   189,   188,   190,   188,   188,   188,
     188,   188,     6,     6,   270,   284,   201,   183,   188,     6,
     189,   188,   270,   190,     6,    92,   265,   190,     6,   253,
     270,     6,     6,   254,   270,     6,     6,   255,   270,     6,
     190,   270,   259,   238,   279,     6,   273,   279,   270,   270,
     270,   270,     7,   190,   207,   270,   275,   270,   188,   276,
       6,   189,   190,   189,   190,   189,   190,     6,     6,   190,
     190,   248,   190,   188,   190,   188,   188,   188,   188,   284,
       6,   189,   183,   190,   190,   270,   259,     6,   256,   259,
       6,   257,   259,     6,   258,   259,     6,   279,     6,   270,
     270,   270,   270,   205,   283,   210,   189,     6,   190,   190,
     189,   190,   189,   190,   189,   190,   190,   188,   188,   188,
     188,   188,   190,   189,   275,     6,     6,   259,     6,   259,
       6,   259,     6,   270,   270,   270,   270,   283,     6,   208,
     283,   190,   190,   190,   190,   190,   190,   190,   190,   188,
     190,     6,     6,     6,     6,   283,     6
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
#line 185 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 196 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 197 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 198 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 199 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 200 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 201 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 202 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 203 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 210 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 215 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 219 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 226 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 231 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 236 "Gmsh.y"
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
#line 250 "Gmsh.y"
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
#line 263 "Gmsh.y"
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
#line 276 "Gmsh.y"
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
#line 304 "Gmsh.y"
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
#line 318 "Gmsh.y"
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
#line 331 "Gmsh.y"
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
#line 344 "Gmsh.y"
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
#line 362 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 376 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 378 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 383 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 385 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 390 "Gmsh.y"
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
#line 494 "Gmsh.y"
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
#line 504 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 513 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 520 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 530 "Gmsh.y"
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
#line 539 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 548 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 555 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 565 "Gmsh.y"
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
#line 573 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 583 "Gmsh.y"
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
#line 602 "Gmsh.y"
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
#line 621 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 627 "Gmsh.y"
    {
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 634 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 635 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 637 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 638 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 642 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 643 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 649 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 649 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 650 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 650 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 659 "Gmsh.y"
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
#line 720 "Gmsh.y"
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
#line 749 "Gmsh.y"
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
#line 778 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 783 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 788 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 793 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 800 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 807 "Gmsh.y"
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
#line 822 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 827 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 832 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 841 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 847 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 856 "Gmsh.y"
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
#line 874 "Gmsh.y"
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
#line 892 "Gmsh.y"
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
#line 901 "Gmsh.y"
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
#line 913 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 918 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 926 "Gmsh.y"
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
#line 946 "Gmsh.y"
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
#line 969 "Gmsh.y"
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
#line 980 "Gmsh.y"
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
#line 988 "Gmsh.y"
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
#line 1010 "Gmsh.y"
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
#line 1033 "Gmsh.y"
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
#line 1059 "Gmsh.y"
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
#line 1080 "Gmsh.y"
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
#line 1092 "Gmsh.y"
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
#line 1110 "Gmsh.y"
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
#line 1119 "Gmsh.y"
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
#line 1128 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 1130 "Gmsh.y"
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
#line 1140 "Gmsh.y"
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
#line 1149 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1151 "Gmsh.y"
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
#line 1165 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1173 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1179 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1191 "Gmsh.y"
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
#line 1202 "Gmsh.y"
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
#line 1217 "Gmsh.y"
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
#line 1233 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1241 "Gmsh.y"
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
#line 1250 "Gmsh.y"
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
#line 1268 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1272 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1281 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1285 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1294 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1298 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1307 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1311 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1320 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1324 "Gmsh.y"
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
#line 1336 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1340 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1350 "Gmsh.y"
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
#line 1373 "Gmsh.y"
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
#line 1405 "Gmsh.y"
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
#line 1428 "Gmsh.y"
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
#line 1446 "Gmsh.y"
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
#line 1467 "Gmsh.y"
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
#line 1485 "Gmsh.y"
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
#line 1515 "Gmsh.y"
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
#line 1545 "Gmsh.y"
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
#line 1563 "Gmsh.y"
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
#line 1582 "Gmsh.y"
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
#line 1608 "Gmsh.y"
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
#line 1626 "Gmsh.y"
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
#line 1644 "Gmsh.y"
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
#line 1679 "Gmsh.y"
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
#line 1697 "Gmsh.y"
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
#line 1736 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1742 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1748 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1755 "Gmsh.y"
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
#line 1780 "Gmsh.y"
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
#line 1805 "Gmsh.y"
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
#line 1822 "Gmsh.y"
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
#line 1842 "Gmsh.y"
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
#line 1875 "Gmsh.y"
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
#line 1911 "Gmsh.y"
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
#line 1929 "Gmsh.y"
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
#line 1946 "Gmsh.y"
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
#line 1962 "Gmsh.y"
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
#line 1999 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 2004 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 2009 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 2014 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 2019 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 2024 "Gmsh.y"
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
#line 2047 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 2053 "Gmsh.y"
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
#line 2063 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 2064 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2069 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2073 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2077 "Gmsh.y"
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
#line 2100 "Gmsh.y"
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
#line 2123 "Gmsh.y"
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
#line 2146 "Gmsh.y"
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
#line 2174 "Gmsh.y"
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
#line 2195 "Gmsh.y"
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
#line 2222 "Gmsh.y"
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
#line 2243 "Gmsh.y"
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
#line 2264 "Gmsh.y"
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
#line 2284 "Gmsh.y"
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
#line 2396 "Gmsh.y"
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
#line 2415 "Gmsh.y"
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
#line 2454 "Gmsh.y"
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
#line 2562 "Gmsh.y"
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
#line 2571 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 2577 "Gmsh.y"
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
#line 2592 "Gmsh.y"
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
#line 2620 "Gmsh.y"
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
#line 2637 "Gmsh.y"
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
#line 2646 "Gmsh.y"
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
#line 2660 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2666 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2672 "Gmsh.y"
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
#line 2681 "Gmsh.y"
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
#line 2690 "Gmsh.y"
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
#line 2699 "Gmsh.y"
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
#line 2713 "Gmsh.y"
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
#line 2769 "Gmsh.y"
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
#line 2787 "Gmsh.y"
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
#line 2804 "Gmsh.y"
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
#line 2819 "Gmsh.y"
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
#line 2838 "Gmsh.y"
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
#line 2850 "Gmsh.y"
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
#line 2874 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2878 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 2883 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2890 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2895 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2901 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2906 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2912 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2920 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2924 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2928 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2934 "Gmsh.y"
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

  case 223:
/* Line 1787 of yacc.c  */
#line 2988 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 3001 "Gmsh.y"
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

  case 225:
/* Line 1787 of yacc.c  */
#line 3018 "Gmsh.y"
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

  case 226:
/* Line 1787 of yacc.c  */
#line 3035 "Gmsh.y"
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

  case 227:
/* Line 1787 of yacc.c  */
#line 3056 "Gmsh.y"
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

  case 228:
/* Line 1787 of yacc.c  */
#line 3077 "Gmsh.y"
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

  case 229:
/* Line 1787 of yacc.c  */
#line 3112 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 3120 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3126 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3133 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3137 "Gmsh.y"
    {
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3146 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3154 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3162 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3170 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3184 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3190 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3204 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3212 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3218 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3226 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3233 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3240 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3247 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3261 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3268 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3275 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3282 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3289 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3295 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3302 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3315 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3321 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3328 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3334 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3341 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3347 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3354 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3360 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3367 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3373 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3380 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3386 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3393 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3399 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3410 "Gmsh.y"
    {
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3413 "Gmsh.y"
    {
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3419 "Gmsh.y"
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

  case 275:
/* Line 1787 of yacc.c  */
#line 3431 "Gmsh.y"
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

  case 276:
/* Line 1787 of yacc.c  */
#line 3451 "Gmsh.y"
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

  case 277:
/* Line 1787 of yacc.c  */
#line 3475 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3479 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3483 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3487 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
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
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3503 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3507 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3511 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3515 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3519 "Gmsh.y"
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

  case 288:
/* Line 1787 of yacc.c  */
#line 3538 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3550 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3554 "Gmsh.y"
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

  case 291:
/* Line 1787 of yacc.c  */
#line 3569 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3573 "Gmsh.y"
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

  case 293:
/* Line 1787 of yacc.c  */
#line 3589 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3593 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3598 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3602 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3608 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3612 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3619 "Gmsh.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 3675 "Gmsh.y"
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

  case 301:
/* Line 1787 of yacc.c  */
#line 3745 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3750 "Gmsh.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 3817 "Gmsh.y"
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

  case 304:
/* Line 1787 of yacc.c  */
#line 3853 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 3861 "Gmsh.y"
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

  case 306:
/* Line 1787 of yacc.c  */
#line 3904 "Gmsh.y"
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

  case 307:
/* Line 1787 of yacc.c  */
#line 3943 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3963 "Gmsh.y"
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

  case 309:
/* Line 1787 of yacc.c  */
#line 3991 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 4039 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4067 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 4095 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 4099 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 4103 "Gmsh.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 4131 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4170 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4209 "Gmsh.y"
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

  case 318:
/* Line 1787 of yacc.c  */
#line 4230 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4251 "Gmsh.y"
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

  case 320:
/* Line 1787 of yacc.c  */
#line 4278 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4282 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4292 "Gmsh.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 4326 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4327 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4328 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4339 "Gmsh.y"
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

  case 328:
/* Line 1787 of yacc.c  */
#line 4351 "Gmsh.y"
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

  case 329:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
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

  case 330:
/* Line 1787 of yacc.c  */
#line 4396 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4397 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4398 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4399 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4400 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4401 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4402 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4403 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4405 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4411 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4412 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4413 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4414 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4416 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4417 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4418 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4419 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4420 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4421 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4422 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4423 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4424 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4425 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4426 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4427 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4428 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4429 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4430 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4431 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4432 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4433 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4434 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4435 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4436 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4437 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4438 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4440 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4441 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4442 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4443 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4452 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4453 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4454 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4455 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4456 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4457 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4458 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4459 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4460 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4461 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4466 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4474 "Gmsh.y"
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

  case 385:
/* Line 1787 of yacc.c  */
#line 4491 "Gmsh.y"
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
#line 4509 "Gmsh.y"
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

  case 387:
/* Line 1787 of yacc.c  */
#line 4527 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4532 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4538 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4550 "Gmsh.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 4567 "Gmsh.y"
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
#line 4585 "Gmsh.y"
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

  case 393:
/* Line 1787 of yacc.c  */
#line 4606 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4611 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4616 "Gmsh.y"
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

  case 396:
/* Line 1787 of yacc.c  */
#line 4626 "Gmsh.y"
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

  case 397:
/* Line 1787 of yacc.c  */
#line 4636 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4641 "Gmsh.y"
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

  case 399:
/* Line 1787 of yacc.c  */
#line 4652 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4661 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4666 "Gmsh.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 4693 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4697 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4701 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4705 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4709 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4716 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4720 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4724 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4728 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4735 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4740 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4747 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4756 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4761 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4765 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4773 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
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
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4800 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4808 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4816 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4823 "Gmsh.y"
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

  case 425:
/* Line 1787 of yacc.c  */
#line 4833 "Gmsh.y"
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

  case 426:
/* Line 1787 of yacc.c  */
#line 4862 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4866 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4870 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4874 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4878 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4882 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4886 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4890 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4894 "Gmsh.y"
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

  case 435:
/* Line 1787 of yacc.c  */
#line 4923 "Gmsh.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 4952 "Gmsh.y"
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

  case 437:
/* Line 1787 of yacc.c  */
#line 4981 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 5011 "Gmsh.y"
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

  case 439:
/* Line 1787 of yacc.c  */
#line 5024 "Gmsh.y"
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

  case 440:
/* Line 1787 of yacc.c  */
#line 5037 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 5050 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 5062 "Gmsh.y"
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
#line 5072 "Gmsh.y"
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

  case 444:
/* Line 1787 of yacc.c  */
#line 5082 "Gmsh.y"
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
#line 5094 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 5106 "Gmsh.y"
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

  case 447:
/* Line 1787 of yacc.c  */
#line 5118 "Gmsh.y"
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
#line 5136 "Gmsh.y"
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

  case 449:
/* Line 1787 of yacc.c  */
#line 5157 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5162 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5166 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5170 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5182 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5186 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5198 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5205 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5215 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5219 "Gmsh.y"
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

  case 459:
/* Line 1787 of yacc.c  */
#line 5234 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5239 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5246 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5250 "Gmsh.y"
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

  case 463:
/* Line 1787 of yacc.c  */
#line 5263 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5271 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5282 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5286 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5294 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5300 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5308 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5316 "Gmsh.y"
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

  case 471:
/* Line 1787 of yacc.c  */
#line 5331 "Gmsh.y"
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

  case 472:
/* Line 1787 of yacc.c  */
#line 5345 "Gmsh.y"
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

  case 473:
/* Line 1787 of yacc.c  */
#line 5359 "Gmsh.y"
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

  case 474:
/* Line 1787 of yacc.c  */
#line 5371 "Gmsh.y"
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

  case 475:
/* Line 1787 of yacc.c  */
#line 5387 "Gmsh.y"
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

  case 476:
/* Line 1787 of yacc.c  */
#line 5398 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5402 "Gmsh.y"
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

  case 478:
/* Line 1787 of yacc.c  */
#line 5421 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5428 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5430 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5441 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5446 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5452 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5461 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 485:
/* Line 1787 of yacc.c  */
#line 5474 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 5477 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11483 "Gmsh.tab.cpp"
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
#line 5481 "Gmsh.y"


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
