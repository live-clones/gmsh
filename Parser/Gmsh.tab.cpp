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

// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
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
     tSyncModel = 307,
     tOnelabAction = 308,
     tOnelabRun = 309,
     tCpu = 310,
     tMemory = 311,
     tTotalMemory = 312,
     tCreateTopology = 313,
     tCreateTopologyNoHoles = 314,
     tDistanceFunction = 315,
     tDefineConstant = 316,
     tUndefineConstant = 317,
     tDefineNumber = 318,
     tDefineString = 319,
     tPoint = 320,
     tCircle = 321,
     tEllipse = 322,
     tLine = 323,
     tSphere = 324,
     tPolarSphere = 325,
     tSurface = 326,
     tSpline = 327,
     tVolume = 328,
     tCharacteristic = 329,
     tLength = 330,
     tParametric = 331,
     tElliptic = 332,
     tRefineMesh = 333,
     tAdaptMesh = 334,
     tRelocateMesh = 335,
     tPlane = 336,
     tRuled = 337,
     tTransfinite = 338,
     tComplex = 339,
     tPhysical = 340,
     tCompound = 341,
     tPeriodic = 342,
     tUsing = 343,
     tPlugin = 344,
     tDegenerated = 345,
     tRecursive = 346,
     tRotate = 347,
     tTranslate = 348,
     tSymmetry = 349,
     tDilate = 350,
     tExtrude = 351,
     tLevelset = 352,
     tRecombine = 353,
     tSmoother = 354,
     tSplit = 355,
     tDelete = 356,
     tCoherence = 357,
     tIntersect = 358,
     tMeshAlgorithm = 359,
     tReverse = 360,
     tLayers = 361,
     tScaleLast = 362,
     tHole = 363,
     tAlias = 364,
     tAliasWithOptions = 365,
     tCopyOptions = 366,
     tQuadTriAddVerts = 367,
     tQuadTriNoNewVerts = 368,
     tQuadTriSngl = 369,
     tQuadTriDbl = 370,
     tRecombLaterals = 371,
     tTransfQuadTri = 372,
     tText2D = 373,
     tText3D = 374,
     tInterpolationScheme = 375,
     tTime = 376,
     tCombine = 377,
     tBSpline = 378,
     tBezier = 379,
     tNurbs = 380,
     tNurbsOrder = 381,
     tNurbsKnots = 382,
     tColor = 383,
     tColorTable = 384,
     tFor = 385,
     tIn = 386,
     tEndFor = 387,
     tIf = 388,
     tEndIf = 389,
     tExit = 390,
     tAbort = 391,
     tField = 392,
     tReturn = 393,
     tCall = 394,
     tFunction = 395,
     tShow = 396,
     tHide = 397,
     tGetValue = 398,
     tGetEnv = 399,
     tGetString = 400,
     tHomology = 401,
     tCohomology = 402,
     tBetti = 403,
     tSetOrder = 404,
     tExists = 405,
     tFileExists = 406,
     tGMSH_MAJOR_VERSION = 407,
     tGMSH_MINOR_VERSION = 408,
     tGMSH_PATCH_VERSION = 409,
     tAFFECTDIVIDE = 410,
     tAFFECTTIMES = 411,
     tAFFECTMINUS = 412,
     tAFFECTPLUS = 413,
     tOR = 414,
     tAND = 415,
     tNOTEQUAL = 416,
     tEQUAL = 417,
     tGREATEROREQUAL = 418,
     tLESSOREQUAL = 419,
     UNARYPREC = 420,
     tMINUSMINUS = 421,
     tPLUSPLUS = 422
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
#line 394 "Gmsh.tab.cpp"
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
#line 422 "Gmsh.tab.cpp"

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
#define YYLAST   8756

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  188
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  474
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1686

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   422

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   173,     2,   183,     2,   172,     2,     2,
     178,   179,   170,   168,   184,   169,   182,   171,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     164,     2,   165,   159,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   180,     2,   181,   177,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   185,     2,   186,   187,     2,     2,     2,
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
     155,   156,   157,   158,   160,   161,   162,   163,   166,   167,
     174,   175,   176
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
     680,   687,   695,   700,   708,   717,   726,   734,   742,   754,
     763,   772,   781,   803,   812,   822,   826,   831,   842,   850,
     858,   867,   876,   889,   898,   920,   929,   937,   946,   955,
     977,   983,   995,  1001,  1011,  1021,  1026,  1036,  1046,  1048,
    1050,  1051,  1054,  1061,  1068,  1075,  1082,  1091,  1102,  1117,
    1134,  1147,  1156,  1165,  1172,  1187,  1192,  1199,  1206,  1210,
    1215,  1221,  1228,  1232,  1236,  1241,  1247,  1252,  1258,  1262,
    1268,  1276,  1284,  1288,  1296,  1300,  1303,  1306,  1309,  1312,
    1328,  1331,  1334,  1337,  1340,  1343,  1360,  1364,  1371,  1380,
    1389,  1400,  1402,  1405,  1407,  1411,  1416,  1418,  1424,  1436,
    1450,  1451,  1459,  1460,  1474,  1475,  1491,  1492,  1499,  1508,
    1517,  1526,  1539,  1552,  1565,  1580,  1595,  1610,  1611,  1624,
    1625,  1638,  1639,  1652,  1653,  1670,  1671,  1688,  1689,  1706,
    1707,  1726,  1727,  1746,  1747,  1766,  1768,  1771,  1777,  1785,
    1795,  1798,  1801,  1804,  1808,  1811,  1815,  1818,  1822,  1825,
    1829,  1839,  1846,  1847,  1851,  1852,  1854,  1855,  1858,  1859,
    1862,  1870,  1877,  1886,  1892,  1896,  1904,  1910,  1915,  1922,
    1929,  1942,  1953,  1964,  1975,  1986,  1997,  2002,  2007,  2012,
    2017,  2022,  2025,  2029,  2036,  2038,  2040,  2042,  2045,  2051,
    2059,  2070,  2072,  2076,  2079,  2082,  2085,  2089,  2093,  2097,
    2101,  2105,  2109,  2113,  2117,  2121,  2125,  2129,  2133,  2137,
    2141,  2147,  2152,  2157,  2162,  2167,  2172,  2177,  2182,  2187,
    2192,  2197,  2204,  2209,  2214,  2219,  2224,  2229,  2234,  2239,
    2246,  2253,  2260,  2265,  2267,  2269,  2271,  2273,  2275,  2277,
    2279,  2281,  2283,  2285,  2286,  2293,  2295,  2300,  2305,  2310,
    2315,  2320,  2323,  2329,  2335,  2339,  2346,  2351,  2359,  2366,
    2373,  2380,  2385,  2387,  2390,  2393,  2397,  2401,  2413,  2423,
    2431,  2439,  2441,  2445,  2447,  2449,  2452,  2456,  2461,  2467,
    2469,  2471,  2474,  2478,  2482,  2488,  2493,  2496,  2499,  2502,
    2505,  2511,  2517,  2523,  2529,  2531,  2533,  2537,  2542,  2549,
    2551,  2553,  2557,  2561,  2571,  2579,  2581,  2587,  2591,  2598,
    2600,  2604,  2606,  2608,  2612,  2619,  2621,  2623,  2625,  2630,
    2637,  2642,  2647,  2652,  2661,  2666,  2671,  2678,  2679,  2686,
    2688,  2692,  2698,  2704,  2706
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     189,     0,    -1,   190,    -1,     1,     6,    -1,    -1,   190,
     191,    -1,   194,    -1,   193,    -1,   214,    -1,   231,    -1,
     232,    -1,   236,    -1,   237,    -1,   238,    -1,   241,    -1,
     261,    -1,   262,    -1,   240,    -1,   239,    -1,   235,    -1,
     264,    -1,   165,    -1,   165,   165,    -1,    37,   178,   278,
     179,     6,    -1,    38,   178,   278,   179,     6,    -1,    37,
     178,   278,   179,   192,   278,     6,    -1,    37,   178,   278,
     184,   274,   179,     6,    -1,    38,   178,   278,   184,   274,
     179,     6,    -1,    37,   178,   278,   184,   274,   179,   192,
     278,     6,    -1,     4,   278,   185,   195,   186,     6,    -1,
     109,     4,   180,   265,   181,     6,    -1,   110,     4,   180,
     265,   181,     6,    -1,   111,     4,   180,   265,   184,   265,
     181,     6,    -1,    -1,   195,   198,    -1,   195,   202,    -1,
     195,   205,    -1,   195,   207,    -1,   195,   208,    -1,   265,
      -1,   196,   184,   265,    -1,   265,    -1,   197,   184,   265,
      -1,    -1,    -1,     4,   199,   178,   196,   179,   200,   185,
     197,   186,     6,    -1,   278,    -1,   201,   184,   278,    -1,
      -1,   118,   178,   265,   184,   265,   184,   265,   179,   203,
     185,   201,   186,     6,    -1,   278,    -1,   204,   184,   278,
      -1,    -1,   119,   178,   265,   184,   265,   184,   265,   184,
     265,   179,   206,   185,   204,   186,     6,    -1,   120,   185,
     270,   186,   185,   270,   186,     6,    -1,   120,   185,   270,
     186,   185,   270,   186,   185,   270,   186,   185,   270,   186,
       6,    -1,    -1,   121,   209,   185,   197,   186,     6,    -1,
       7,    -1,   158,    -1,   157,    -1,   156,    -1,   155,    -1,
     176,    -1,   175,    -1,   178,    -1,   180,    -1,   179,    -1,
     181,    -1,    61,   180,   216,   181,     6,    -1,    62,   180,
     219,   181,     6,    -1,   283,   210,   271,     6,    -1,     4,
     180,   181,   210,   271,     6,    -1,   282,   180,   181,   210,
     271,     6,    -1,     4,   180,   265,   181,   210,   265,     6,
      -1,     4,   178,   265,   179,   210,   265,     6,    -1,   282,
     180,   265,   181,   210,   265,     6,    -1,     4,   212,   185,
     274,   186,   213,   210,   271,     6,    -1,   282,   178,   185,
     274,   186,   179,   210,   271,     6,    -1,   283,   211,     6,
      -1,     4,   180,   265,   181,   211,     6,    -1,   282,   180,
     265,   181,   211,     6,    -1,   283,     7,   279,     6,    -1,
       4,   182,     4,     7,   279,     6,    -1,     4,   180,   265,
     181,   182,     4,     7,   279,     6,    -1,     4,   182,     4,
     210,   265,     6,    -1,     4,   180,   265,   181,   182,     4,
     210,   265,     6,    -1,     4,   182,     4,   211,     6,    -1,
       4,   180,   265,   181,   182,     4,   211,     6,    -1,     4,
     182,   128,   182,     4,     7,   275,     6,    -1,     4,   180,
     265,   181,   182,   128,   182,     4,     7,   275,     6,    -1,
       4,   182,   129,     7,   276,     6,    -1,     4,   180,   265,
     181,   182,   129,     7,   276,     6,    -1,     4,   137,     7,
     265,     6,    -1,   137,   180,   265,   181,     7,     4,     6,
      -1,   137,   180,   265,   181,   182,     4,     7,   265,     6,
      -1,   137,   180,   265,   181,   182,     4,     7,   279,     6,
      -1,   137,   180,   265,   181,   182,     4,     7,   185,   274,
     186,     6,    -1,   137,   180,   265,   181,   182,     4,     6,
      -1,    89,   178,     4,   179,   182,     4,     7,   265,     6,
      -1,    89,   178,     4,   179,   182,     4,     7,   279,     6,
      -1,    -1,   184,    -1,    -1,   216,   215,   283,    -1,   216,
     215,   283,     7,   265,    -1,    -1,   216,   215,   283,     7,
     185,   265,   217,   221,   186,    -1,   216,   215,   283,     7,
     279,    -1,    -1,   216,   215,   283,     7,   185,   279,   218,
     223,   186,    -1,    -1,   219,   215,   278,    -1,   265,     7,
     279,    -1,   220,   184,   265,     7,   279,    -1,    -1,   221,
     222,    -1,   184,     4,   271,    -1,   184,     4,   185,   220,
     186,    -1,   184,     4,   279,    -1,    -1,   223,   224,    -1,
     184,     4,   265,    -1,   184,     4,   279,    -1,   184,     4,
     185,   281,   186,    -1,   265,    -1,   279,    -1,   265,    -1,
     279,    -1,   265,    -1,   279,    -1,   265,    -1,   279,    -1,
      -1,   131,    69,   185,   265,   186,    -1,    -1,    81,   268,
      -1,    65,   178,   265,   179,     7,   268,     6,    -1,    85,
      65,   178,   225,   179,     7,   271,     6,    -1,    85,    65,
     178,   225,   179,   131,    48,   185,   265,   184,   265,   184,
     265,   184,   265,   184,   265,   184,   265,   186,     6,    -1,
      74,    75,   271,     7,   265,     6,    -1,    68,   178,   265,
     179,     7,   271,     6,    -1,    90,    68,   271,     6,    -1,
      72,   178,   265,   179,     7,   271,     6,    -1,    66,   178,
     265,   179,     7,   271,   230,     6,    -1,    67,   178,   265,
     179,     7,   271,   230,     6,    -1,   123,   178,   265,   179,
       7,   271,     6,    -1,   124,   178,   265,   179,     7,   271,
       6,    -1,   125,   178,   265,   179,     7,   271,   127,   271,
     126,   265,     6,    -1,    68,     4,   178,   265,   179,     7,
     271,     6,    -1,    86,    68,   178,   265,   179,     7,   271,
       6,    -1,    85,    68,   178,   226,   179,     7,   271,     6,
      -1,    85,    68,   178,   226,   179,   131,    48,   185,   265,
     184,   265,   184,   265,   184,   265,   184,   265,   184,   265,
     186,     6,    -1,    81,    71,   178,   265,   179,     7,   271,
       6,    -1,    82,    71,   178,   265,   179,     7,   271,   229,
       6,    -1,    12,    13,     6,    -1,    13,    71,   265,     6,
      -1,    76,    71,   178,   265,   179,     7,     5,     5,     5,
       6,    -1,    69,   178,   265,   179,     7,   271,     6,    -1,
      70,   178,   265,   179,     7,   271,     6,    -1,    71,     4,
     178,   265,   179,     7,   271,     6,    -1,    86,    71,   178,
     265,   179,     7,   271,     6,    -1,    86,    71,   178,   265,
     179,     7,   271,     4,   185,   270,   186,     6,    -1,    85,
      71,   178,   227,   179,     7,   271,     6,    -1,    85,    71,
     178,   227,   179,   131,    48,   185,   265,   184,   265,   184,
     265,   184,   265,   184,   265,   184,   265,   186,     6,    -1,
      84,    73,   178,   265,   179,     7,   271,     6,    -1,    73,
     178,   265,   179,     7,   271,     6,    -1,    86,    73,   178,
     265,   179,     7,   271,     6,    -1,    85,    73,   178,   228,
     179,     7,   271,     6,    -1,    85,    73,   178,   228,   179,
     131,    48,   185,   265,   184,   265,   184,   265,   184,   265,
     184,   265,   184,   265,   186,     6,    -1,    93,   268,   185,
     233,   186,    -1,    92,   185,   268,   184,   268,   184,   265,
     186,   185,   233,   186,    -1,    94,   268,   185,   233,   186,
      -1,    95,   185,   268,   184,   265,   186,   185,   233,   186,
      -1,    95,   185,   268,   184,   268,   186,   185,   233,   186,
      -1,     4,   185,   233,   186,    -1,   103,    68,   185,   274,
     186,    71,   185,   265,   186,    -1,   100,    68,   178,   265,
     179,   185,   274,   186,     6,    -1,   234,    -1,   232,    -1,
      -1,   234,   231,    -1,   234,    65,   185,   274,   186,     6,
      -1,   234,    68,   185,   274,   186,     6,    -1,   234,    71,
     185,   274,   186,     6,    -1,   234,    73,   185,   274,   186,
       6,    -1,    97,    81,   178,   265,   179,     7,   271,     6,
      -1,    97,    65,   178,   265,   179,     7,   185,   270,   186,
       6,    -1,    97,    81,   178,   265,   179,     7,   185,   268,
     184,   268,   184,   274,   186,     6,    -1,    97,    81,   178,
     265,   179,     7,   185,   268,   184,   268,   184,   268,   184,
     274,   186,     6,    -1,    97,    69,   178,   265,   179,     7,
     185,   268,   184,   274,   186,     6,    -1,    97,     4,   178,
     265,   179,     7,   271,     6,    -1,    97,     4,   178,   265,
     179,     7,     5,     6,    -1,    97,     4,   185,   265,   186,
       6,    -1,    97,     4,   178,   265,   179,     7,   185,   268,
     184,   268,   184,   274,   186,     6,    -1,   101,   185,   234,
     186,    -1,   101,   137,   180,   265,   181,     6,    -1,   101,
       4,   180,   265,   181,     6,    -1,   101,     4,     6,    -1,
     101,     4,     4,     6,    -1,   128,   275,   185,   234,   186,
      -1,    91,   128,   275,   185,   234,   186,    -1,   141,     5,
       6,    -1,   142,     5,     6,    -1,   141,   185,   234,   186,
      -1,    91,   141,   185,   234,   186,    -1,   142,   185,   234,
     186,    -1,    91,   142,   185,   234,   186,    -1,     4,   279,
       6,    -1,    54,   178,   281,   179,     6,    -1,     4,     4,
     180,   265,   181,   278,     6,    -1,     4,     4,     4,   180,
     265,   181,     6,    -1,     4,   265,     6,    -1,    89,   178,
       4,   179,   182,     4,     6,    -1,   122,     4,     6,    -1,
     135,     6,    -1,   136,     6,    -1,    52,     6,    -1,    48,
       6,    -1,    48,   185,   265,   184,   265,   184,   265,   184,
     265,   184,   265,   184,   265,   186,     6,    -1,    49,     6,
      -1,    50,     6,    -1,    58,     6,    -1,    59,     6,    -1,
      78,     6,    -1,    79,   185,   274,   186,   185,   274,   186,
     185,   270,   186,   185,   265,   184,   265,   186,     6,    -1,
     149,   265,     6,    -1,   130,   178,   265,     8,   265,   179,
      -1,   130,   178,   265,     8,   265,     8,   265,   179,    -1,
     130,     4,   131,   185,   265,     8,   265,   186,    -1,   130,
       4,   131,   185,   265,     8,   265,     8,   265,   186,    -1,
     132,    -1,   140,     4,    -1,   138,    -1,   139,     4,     6,
      -1,   133,   178,   265,   179,    -1,   134,    -1,    96,   268,
     185,   234,   186,    -1,    96,   185,   268,   184,   268,   184,
     265,   186,   185,   234,   186,    -1,    96,   185,   268,   184,
     268,   184,   268,   184,   265,   186,   185,   234,   186,    -1,
      -1,    96,   268,   185,   234,   242,   255,   186,    -1,    -1,
      96,   185,   268,   184,   268,   184,   265,   186,   185,   234,
     243,   255,   186,    -1,    -1,    96,   185,   268,   184,   268,
     184,   268,   184,   265,   186,   185,   234,   244,   255,   186,
      -1,    -1,    96,   185,   234,   245,   255,   186,    -1,    96,
      65,   185,   265,   184,   268,   186,     6,    -1,    96,    68,
     185,   265,   184,   268,   186,     6,    -1,    96,    71,   185,
     265,   184,   268,   186,     6,    -1,    96,    65,   185,   265,
     184,   268,   184,   268,   184,   265,   186,     6,    -1,    96,
      68,   185,   265,   184,   268,   184,   268,   184,   265,   186,
       6,    -1,    96,    71,   185,   265,   184,   268,   184,   268,
     184,   265,   186,     6,    -1,    96,    65,   185,   265,   184,
     268,   184,   268,   184,   268,   184,   265,   186,     6,    -1,
      96,    68,   185,   265,   184,   268,   184,   268,   184,   268,
     184,   265,   186,     6,    -1,    96,    71,   185,   265,   184,
     268,   184,   268,   184,   268,   184,   265,   186,     6,    -1,
      -1,    96,    65,   185,   265,   184,   268,   186,   246,   185,
     255,   186,     6,    -1,    -1,    96,    68,   185,   265,   184,
     268,   186,   247,   185,   255,   186,     6,    -1,    -1,    96,
      71,   185,   265,   184,   268,   186,   248,   185,   255,   186,
       6,    -1,    -1,    96,    65,   185,   265,   184,   268,   184,
     268,   184,   265,   186,   249,   185,   255,   186,     6,    -1,
      -1,    96,    68,   185,   265,   184,   268,   184,   268,   184,
     265,   186,   250,   185,   255,   186,     6,    -1,    -1,    96,
      71,   185,   265,   184,   268,   184,   268,   184,   265,   186,
     251,   185,   255,   186,     6,    -1,    -1,    96,    65,   185,
     265,   184,   268,   184,   268,   184,   268,   184,   265,   186,
     252,   185,   255,   186,     6,    -1,    -1,    96,    68,   185,
     265,   184,   268,   184,   268,   184,   268,   184,   265,   186,
     253,   185,   255,   186,     6,    -1,    -1,    96,    71,   185,
     265,   184,   268,   184,   268,   184,   268,   184,   265,   186,
     254,   185,   255,   186,     6,    -1,   256,    -1,   255,   256,
      -1,   106,   185,   265,   186,     6,    -1,   106,   185,   271,
     184,   271,   186,     6,    -1,   106,   185,   271,   184,   271,
     184,   271,   186,     6,    -1,   107,     6,    -1,    98,     6,
      -1,   114,     6,    -1,   114,   116,     6,    -1,   115,     6,
      -1,   115,   116,     6,    -1,   112,     6,    -1,   112,   116,
       6,    -1,   113,     6,    -1,   113,   116,     6,    -1,   108,
     178,   265,   179,     7,   271,    88,   265,     6,    -1,    88,
       4,   180,   265,   181,     6,    -1,    -1,    88,     4,   265,
      -1,    -1,     4,    -1,    -1,     7,   271,    -1,    -1,     7,
     265,    -1,    83,    68,   272,     7,   265,   257,     6,    -1,
      83,    71,   272,   259,   258,     6,    -1,    77,    71,   185,
     265,   186,     7,   271,     6,    -1,    83,    73,   272,   259,
       6,    -1,   117,   272,     6,    -1,   104,    71,   185,   274,
     186,   265,     6,    -1,    98,    71,   272,   260,     6,    -1,
      98,    73,   272,     6,    -1,    99,    71,   271,     7,   265,
       6,    -1,    87,    68,   271,     7,   271,     6,    -1,    87,
      71,   265,   185,   274,   186,     7,   265,   185,   274,   186,
       6,    -1,    65,   185,   274,   186,   131,    71,   185,   265,
     186,     6,    -1,    68,   185,   274,   186,   131,    71,   185,
     265,   186,     6,    -1,    65,   185,   274,   186,   131,    73,
     185,   265,   186,     6,    -1,    68,   185,   274,   186,   131,
      73,   185,   265,   186,     6,    -1,    71,   185,   274,   186,
     131,    73,   185,   265,   186,     6,    -1,   105,    71,   272,
       6,    -1,   105,    68,   272,     6,    -1,    80,    65,   272,
       6,    -1,    80,    68,   272,     6,    -1,    80,    71,   272,
       6,    -1,   102,     6,    -1,   102,     4,     6,    -1,   102,
      65,   185,   274,   186,     6,    -1,   146,    -1,   147,    -1,
     148,    -1,   263,     6,    -1,   263,   185,   271,   186,     6,
      -1,   263,   185,   271,   184,   271,   186,     6,    -1,   263,
     178,   271,   179,   185,   271,   184,   271,   186,     6,    -1,
     266,    -1,   178,   265,   179,    -1,   169,   265,    -1,   168,
     265,    -1,   173,   265,    -1,   265,   169,   265,    -1,   265,
     168,   265,    -1,   265,   170,   265,    -1,   265,   171,   265,
      -1,   265,   172,   265,    -1,   265,   177,   265,    -1,   265,
     164,   265,    -1,   265,   165,   265,    -1,   265,   167,   265,
      -1,   265,   166,   265,    -1,   265,   163,   265,    -1,   265,
     162,   265,    -1,   265,   161,   265,    -1,   265,   160,   265,
      -1,   265,   159,   265,     8,   265,    -1,    14,   212,   265,
     213,    -1,    15,   212,   265,   213,    -1,    16,   212,   265,
     213,    -1,    17,   212,   265,   213,    -1,    18,   212,   265,
     213,    -1,    19,   212,   265,   213,    -1,    20,   212,   265,
     213,    -1,    21,   212,   265,   213,    -1,    22,   212,   265,
     213,    -1,    24,   212,   265,   213,    -1,    25,   212,   265,
     184,   265,   213,    -1,    26,   212,   265,   213,    -1,    27,
     212,   265,   213,    -1,    28,   212,   265,   213,    -1,    29,
     212,   265,   213,    -1,    30,   212,   265,   213,    -1,    31,
     212,   265,   213,    -1,    32,   212,   265,   213,    -1,    33,
     212,   265,   184,   265,   213,    -1,    34,   212,   265,   184,
     265,   213,    -1,    35,   212,   265,   184,   265,   213,    -1,
      23,   212,   265,   213,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   152,    -1,   153,    -1,   154,    -1,    55,
      -1,    56,    -1,    57,    -1,    -1,    63,   212,   265,   267,
     221,   213,    -1,   283,    -1,     4,   180,   265,   181,    -1,
     282,   180,   265,   181,    -1,   150,   178,   283,   179,    -1,
     151,   178,   279,   179,    -1,   183,   283,   180,   181,    -1,
     283,   211,    -1,     4,   180,   265,   181,   211,    -1,   282,
     180,   265,   181,   211,    -1,     4,   182,     4,    -1,     4,
     180,   265,   181,   182,     4,    -1,     4,   182,     4,   211,
      -1,     4,   180,   265,   181,   182,     4,   211,    -1,   143,
     178,   278,   184,   265,   179,    -1,    45,   178,   278,   184,
     278,   179,    -1,    46,   178,   278,   184,   278,   179,    -1,
      47,   178,   281,   179,    -1,   269,    -1,   169,   268,    -1,
     168,   268,    -1,   268,   169,   268,    -1,   268,   168,   268,
      -1,   185,   265,   184,   265,   184,   265,   184,   265,   184,
     265,   186,    -1,   185,   265,   184,   265,   184,   265,   184,
     265,   186,    -1,   185,   265,   184,   265,   184,   265,   186,
      -1,   178,   265,   184,   265,   184,   265,   179,    -1,   271,
      -1,   270,   184,   271,    -1,   265,    -1,   273,    -1,   185,
     186,    -1,   185,   274,   186,    -1,   169,   185,   274,   186,
      -1,   265,   170,   185,   274,   186,    -1,   271,    -1,     5,
      -1,   169,   273,    -1,   265,   170,   273,    -1,   265,     8,
     265,    -1,   265,     8,   265,     8,   265,    -1,    65,   185,
     265,   186,    -1,    65,     5,    -1,    68,     5,    -1,    71,
       5,    -1,    73,     5,    -1,    85,    65,   185,   274,   186,
      -1,    85,    68,   185,   274,   186,    -1,    85,    71,   185,
     274,   186,    -1,    85,    73,   185,   274,   186,    -1,   232,
      -1,   241,    -1,     4,   212,   213,    -1,    36,   180,     4,
     181,    -1,     4,   212,   185,   274,   186,   213,    -1,   265,
      -1,   273,    -1,   274,   184,   265,    -1,   274,   184,   273,
      -1,   185,   265,   184,   265,   184,   265,   184,   265,   186,
      -1,   185,   265,   184,   265,   184,   265,   186,    -1,     4,
      -1,     4,   182,   128,   182,     4,    -1,   185,   277,   186,
      -1,     4,   180,   265,   181,   182,   129,    -1,   275,    -1,
     277,   184,   275,    -1,   279,    -1,   283,    -1,     4,   182,
       4,    -1,     4,   180,   265,   181,   182,     4,    -1,     5,
      -1,    51,    -1,    53,    -1,   144,   178,   278,   179,    -1,
     145,   178,   278,   184,   278,   179,    -1,    41,   212,   281,
     213,    -1,    42,   178,   278,   179,    -1,    43,   178,   278,
     179,    -1,    44,   178,   278,   184,   278,   184,   278,   179,
      -1,    39,   212,   281,   213,    -1,    40,   212,   278,   213,
      -1,    40,   212,   278,   184,   274,   213,    -1,    -1,    64,
     212,   279,   280,   223,   213,    -1,   278,    -1,   281,   184,
     278,    -1,     4,   187,   185,   265,   186,    -1,   282,   187,
     185,   265,   186,    -1,     4,    -1,   282,    -1
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
    1402,  1424,  1442,  1463,  1481,  1511,  1541,  1559,  1577,  1604,
    1622,  1640,  1656,  1674,  1692,  1731,  1737,  1743,  1750,  1775,
    1800,  1817,  1836,  1870,  1886,  1905,  1923,  1940,  1956,  1972,
    1993,  1998,  2003,  2008,  2013,  2018,  2041,  2047,  2058,  2059,
    2064,  2067,  2071,  2094,  2117,  2140,  2168,  2189,  2215,  2236,
    2258,  2278,  2390,  2409,  2447,  2556,  2565,  2571,  2586,  2614,
    2631,  2640,  2654,  2660,  2666,  2675,  2684,  2693,  2707,  2763,
    2788,  2805,  2820,  2839,  2851,  2875,  2879,  2884,  2891,  2897,
    2902,  2908,  2916,  2920,  2924,  2929,  2984,  2997,  3014,  3031,
    3052,  3073,  3108,  3116,  3122,  3129,  3133,  3142,  3150,  3158,
    3167,  3166,  3181,  3180,  3195,  3194,  3209,  3208,  3222,  3229,
    3236,  3243,  3250,  3257,  3264,  3271,  3278,  3286,  3285,  3299,
    3298,  3312,  3311,  3325,  3324,  3338,  3337,  3351,  3350,  3364,
    3363,  3377,  3376,  3390,  3389,  3406,  3409,  3415,  3427,  3447,
    3471,  3475,  3479,  3483,  3487,  3493,  3499,  3503,  3507,  3511,
    3515,  3534,  3547,  3550,  3566,  3569,  3586,  3589,  3595,  3598,
    3605,  3661,  3731,  3736,  3803,  3839,  3847,  3890,  3929,  3949,
    3976,  4016,  4044,  4072,  4076,  4080,  4108,  4147,  4186,  4207,
    4228,  4255,  4259,  4269,  4304,  4305,  4306,  4310,  4316,  4328,
    4346,  4374,  4375,  4376,  4377,  4378,  4379,  4380,  4381,  4382,
    4389,  4390,  4391,  4392,  4393,  4394,  4395,  4396,  4397,  4398,
    4399,  4400,  4401,  4402,  4403,  4404,  4405,  4406,  4407,  4408,
    4409,  4410,  4411,  4412,  4413,  4414,  4415,  4416,  4417,  4418,
    4419,  4420,  4421,  4430,  4431,  4432,  4433,  4434,  4435,  4436,
    4437,  4438,  4439,  4444,  4443,  4451,  4468,  4486,  4504,  4509,
    4515,  4527,  4544,  4562,  4583,  4588,  4593,  4603,  4613,  4618,
    4627,  4632,  4659,  4663,  4667,  4671,  4675,  4682,  4686,  4690,
    4694,  4701,  4706,  4713,  4718,  4722,  4727,  4731,  4739,  4750,
    4754,  4766,  4774,  4782,  4789,  4799,  4828,  4832,  4836,  4840,
    4844,  4873,  4902,  4931,  4960,  4970,  4980,  4992,  5004,  5025,
    5030,  5034,  5038,  5050,  5054,  5066,  5073,  5083,  5087,  5102,
    5107,  5114,  5118,  5131,  5139,  5150,  5154,  5162,  5168,  5176,
    5184,  5199,  5213,  5227,  5239,  5255,  5259,  5279,  5278,  5291,
    5296,  5302,  5311,  5324,  5327
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
  "tSyncModel", "tOnelabAction", "tOnelabRun", "tCpu", "tMemory",
  "tTotalMemory", "tCreateTopology", "tCreateTopologyNoHoles",
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,    63,
     414,   415,   416,   417,    60,    62,   418,   419,    43,    45,
      42,    47,    37,    33,   420,   421,   422,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   188,   189,   189,   190,   190,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   192,   193,   193,   193,   193,   193,   193,   194,
     194,   194,   194,   195,   195,   195,   195,   195,   195,   196,
     196,   197,   197,   199,   200,   198,   201,   201,   203,   202,
     204,   204,   206,   205,   207,   207,   209,   208,   210,   210,
     210,   210,   210,   211,   211,   212,   212,   213,   213,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   216,   216,   216,   217,   216,   216,   218,
     216,   219,   219,   220,   220,   221,   221,   222,   222,   222,
     223,   223,   224,   224,   224,   225,   225,   226,   226,   227,
     227,   228,   228,   229,   229,   230,   230,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     232,   232,   232,   232,   232,   232,   232,   232,   233,   233,
     234,   234,   234,   234,   234,   234,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   236,   236,   236,   236,   236,
     237,   237,   238,   238,   238,   238,   238,   238,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   241,   241,   241,
     242,   241,   243,   241,   244,   241,   245,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   246,   241,   247,
     241,   248,   241,   249,   241,   250,   241,   251,   241,   252,
     241,   253,   241,   254,   241,   255,   255,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   257,   257,   258,   258,   259,   259,   260,   260,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   262,   262,   262,   263,   263,   263,   264,   264,   264,
     264,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   267,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   268,   268,   268,   268,   268,   269,   269,   269,
     269,   270,   270,   271,   271,   271,   271,   271,   271,   272,
     272,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   274,
     274,   274,   274,   275,   275,   275,   275,   276,   276,   277,
     277,   278,   278,   278,   278,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   280,   279,   281,
     281,   282,   282,   283,   283
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
       1,     1,     1,     0,     5,     0,     2,     7,     8,    21,
       6,     7,     4,     7,     8,     8,     7,     7,    11,     8,
       8,     8,    21,     8,     9,     3,     4,    10,     7,     7,
       8,     8,    12,     8,    21,     8,     7,     8,     8,    21,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,     8,     8,     6,    14,     4,     6,     6,     3,     4,
       5,     6,     3,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,    15,
       2,     2,     2,     2,     2,    16,     3,     6,     8,     8,
      10,     1,     2,     1,     3,     4,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     5,     7,     9,
       2,     2,     2,     3,     2,     3,     2,     3,     2,     3,
       9,     6,     0,     3,     0,     1,     0,     2,     0,     2,
       7,     6,     8,     5,     3,     7,     5,     4,     6,     6,
      12,    10,    10,    10,    10,    10,     4,     4,     4,     4,
       4,     2,     3,     6,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     1,     4,     4,     4,     4,
       4,     2,     5,     5,     3,     6,     4,     7,     6,     6,
       6,     4,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       1,     2,     3,     3,     5,     4,     2,     2,     2,     2,
       5,     5,     5,     5,     1,     1,     3,     4,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     3,     6,     1,     1,     1,     4,     6,
       4,     4,     4,     8,     4,     4,     6,     0,     6,     1,
       3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
       0,   236,     0,     0,     0,   233,     0,     0,     0,     0,
     324,   325,   326,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   474,     0,   373,   473,   455,   374,   375,   376,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     456,   457,   380,   381,   382,     0,     0,     0,     0,     0,
       0,     0,     0,   377,   378,   379,     0,     0,     0,    65,
      66,     0,     0,   180,     0,     0,     0,   331,     0,   451,
     474,   385,     0,     0,     0,     0,   218,     0,   220,   221,
     217,     0,   222,   223,   103,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   402,     0,     0,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,   321,     0,     0,     0,     0,     0,     0,
       0,     0,   473,   420,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   434,   435,   413,   419,     0,   414,   385,
       0,     0,     0,     0,   445,     0,     0,     0,     0,     0,
     215,   216,     0,     0,   232,     0,   180,     0,   180,   473,
       0,   327,     0,     0,     0,     0,     0,    58,    62,    61,
      60,    59,    64,    63,     0,     0,     0,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     334,   333,   335,     0,     0,     0,     0,     0,     0,   473,
     474,     0,     0,   179,     0,   178,     0,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,   208,     0,   391,   155,     0,
     473,     0,   451,   452,     0,     0,   469,     0,   101,   101,
       0,     0,   439,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   296,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   180,     0,   404,   403,     0,     0,     0,     0,
     180,   180,     0,     0,     0,     0,     0,     0,     0,   246,
       0,   180,     0,     0,     0,     0,     0,   298,     0,     0,
       0,     0,   198,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,   426,
       0,   427,   428,   429,     0,     0,     0,     0,     0,   333,
     421,     0,   415,     0,     0,     0,   304,   214,     0,     0,
       0,     0,     0,   180,     0,     0,     0,     0,   234,   202,
       0,   203,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   383,   467,
       0,     0,     0,     0,     0,     0,   332,    58,     0,     0,
      58,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,   181,     0,     0,     0,   349,   348,   347,   346,   342,
     343,   345,   344,   337,   336,   338,   339,   340,   341,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,   319,   320,     0,     0,
       0,     0,   294,     0,     0,     0,   125,   126,     0,   127,
     128,     0,   129,   130,     0,   131,   132,     0,     0,     0,
       0,     0,     0,   142,   180,     0,     0,     0,     0,     0,
     406,   405,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,     0,   307,
       0,     0,   199,     0,     0,   195,     0,     0,     0,   317,
     316,     0,     0,     0,     0,   394,    67,    68,     0,   436,
       0,     0,     0,     0,     0,     0,     0,   332,   416,   423,
       0,   338,   422,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,   204,   206,     0,     0,     0,     0,     0,
       0,     0,    82,    71,     0,   386,   396,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   372,   360,     0,   362,
     363,   364,   365,   366,   367,   368,     0,     0,     0,   464,
       0,   465,   460,   461,   462,     0,     0,     0,   401,   115,
     120,    93,     0,   458,     0,   388,   389,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,   390,
       0,     0,     0,     0,   471,     0,     0,    43,     0,     0,
       0,    56,     0,    34,    35,    36,    37,    38,   387,     0,
     453,    23,    21,     0,     0,    24,     0,     0,   209,   470,
      69,   104,    70,   112,     0,   441,   442,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   292,   297,   295,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   207,     0,     0,     0,   170,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,   237,     0,     0,     0,
       0,     0,     0,   299,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,     0,   437,   425,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,     0,     0,   328,     0,
       0,     0,     0,   472,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,    80,    83,    85,     0,
       0,   449,     0,    91,     0,     0,     0,     0,     0,   350,
       0,     0,     0,     0,     0,    29,   393,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,     0,   280,     0,   286,     0,   288,
       0,   282,     0,   284,     0,   247,   276,     0,     0,     0,
     193,     0,     0,     0,   308,     0,   197,   196,   323,     0,
       0,    30,    31,     0,     0,     0,   430,   431,   432,   433,
     424,   418,     0,     0,     0,   446,     0,     0,     0,   227,
       0,     0,     0,     0,     0,    73,     0,    81,   211,   395,
     210,   361,   369,   370,   371,   466,     0,   399,   400,     0,
     384,   116,     0,   468,   121,   398,   459,    75,    58,     0,
       0,     0,     0,    74,     0,     0,     0,   447,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,     0,
      25,    26,     0,    27,     0,     0,   105,   108,   137,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   158,   159,
       0,     0,   143,   166,     0,     0,     0,     0,   133,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,   180,
     180,     0,   257,     0,   259,     0,   261,     0,   413,     0,
       0,   287,   289,   283,   285,     0,     0,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   305,     0,   395,
     438,   146,   147,     0,     0,     0,     0,    94,    98,     0,
       0,   329,     0,    76,   397,     0,     0,     0,     0,     0,
      88,     0,     0,    89,     0,   450,   182,   183,   184,   185,
       0,     0,    39,     0,     0,     0,     0,     0,    41,   454,
       0,     0,   106,   109,     0,     0,   136,   144,   145,   149,
       0,     0,   160,     0,     0,   302,     0,   153,     0,     0,
     293,   165,   138,     0,   151,     0,   163,     0,   168,     0,
     150,     0,   161,   167,     0,     0,     0,     0,   410,     0,
     409,     0,     0,     0,   248,     0,     0,   249,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,   191,     0,     0,     0,   186,     0,     0,    32,     0,
       0,   444,     0,   229,   228,     0,     0,     0,     0,     0,
     463,     0,   117,   119,     0,   122,   123,    84,    86,     0,
      92,     0,    77,    44,     0,     0,     0,   412,     0,     0,
       0,    28,     0,   115,   120,     0,     0,     0,     0,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
      99,   100,   180,     0,   173,   174,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,   180,     0,     0,     0,
       0,     0,   177,   176,     0,     0,     0,     0,    95,    96,
       0,    78,     0,   439,     0,     0,   448,     0,    40,     0,
       0,     0,    42,    57,     0,     0,     0,   311,   313,   312,
     314,   315,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   408,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,     0,     0,     0,   242,     0,     0,
     187,     0,     0,     0,   443,   230,     0,   330,     0,   118,
       0,   124,    90,     0,     0,     0,     0,     0,   107,   110,
       0,     0,     0,     0,     0,     0,     0,     0,   171,     0,
     263,     0,     0,   265,     0,     0,   267,     0,     0,     0,
     278,     0,   238,     0,   180,     0,     0,     0,   148,    97,
       0,   113,     0,    48,     0,    54,     0,     0,     0,   134,
       0,     0,     0,     0,   162,   310,   407,   251,     0,     0,
     258,   252,     0,     0,   260,   253,     0,     0,   262,     0,
       0,     0,   244,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,   271,     0,   273,   279,   290,   243,   239,     0,     0,
       0,     0,   114,    45,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,   254,     0,     0,   255,     0,     0,
     256,     0,     0,   194,     0,   188,     0,    46,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,   264,     0,   266,     0,   268,     0,   189,
      47,    49,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,   270,
     272,   274,    51,    53,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   152,   164,   169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   843,    85,    86,   619,  1271,  1277,
     833,  1000,  1437,  1616,   834,  1569,  1652,   835,  1618,   836,
     837,  1004,   314,   397,   165,   729,    87,   633,   408,  1383,
    1384,   409,  1432,   976,  1131,   977,  1134,   665,   668,   671,
     674,  1299,  1172,   601,   273,   374,   375,    90,    91,    92,
      93,    94,    95,   274,   917,  1523,  1588,   699,  1325,  1328,
    1331,  1548,  1552,  1556,  1605,  1608,  1611,   913,   914,  1036,
     878,   662,   708,    97,    98,    99,   100,   275,   167,   799,
     455,   233,  1156,   276,   277,   278,   513,   286,   818,   992,
     406,   402,   800,   407,   170,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1190
static const yytype_int16 yypact[] =
{
    5199,    11,    55,  5313, -1190, -1190,  2101,   144,   -27,  -138,
     -41,    29,   281,   343,   347,   228,   389,   404,    43,   234,
    -148,   287,   293,    20,   302,   323,    18,   359,   380,   450,
     478,   508,   580,   424,   298,   518,   533,   448,   494,   178,
     488,    -1,   445,   552,   -76,   461,  -109,  -109,   513,   235,
     224,   241,   572,   584,    10,    44,   605,   610,   159,   699,
     716,   726,  2858,   747,   524,   547,   559,    19,    -2, -1190,
     589, -1190,   762,   770,   599, -1190,   782,   798,    15,    27,
   -1190, -1190, -1190,  4955, -1190, -1190, -1190, -1190, -1190, -1190,
   -1190, -1190, -1190, -1190, -1190, -1190, -1190, -1190, -1190,    41,
   -1190,  -116,   348, -1190,    14, -1190, -1190, -1190, -1190,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   629,   640,   641,   656,   682,   717,
   -1190, -1190, -1190, -1190, -1190,   160,   160,   842,   742,   752,
     765,   792,   793, -1190, -1190, -1190,  4955,  4955,  4955,  4955,
    4664,    30,   874,   145,   719,   723,   945, -1190,   759,   972,
      -8,   -37,   973,  4955,   828,   828, -1190,  4955, -1190, -1190,
   -1190,   828, -1190, -1190, -1190, -1190,  4955,  4563,  4955,  4955,
     811,  4955,  4563,  4955,  4955,   815,  4563,  4955,  4955,  3212,
     816,   817, -1190,  4563,  2858,  2858,  2858,   820,   827,  2858,
    2858,  2858,   835,   840,   854,   860,   864,   895,   896,   897,
    3212,  4955,  1015,  3212,    19,   867,   871,  -109,  -109,  -109,
    4955,  4955,    86, -1190,   105,  -109,   891,   892,   893,  4386,
     116,  -110,   902,   905,   906,  2858,  2858,  3212,   907,     4,
     846, -1190,  1080, -1190,   903,   909,   910,  2858,  2858,   911,
     912,   916,   568, -1190,   917,    28,  1082,  1093,  1094,   619,
    3389,  4955,  2497, -1190, -1190,  1923, -1190,  1097, -1190,   -59,
    1113,  4955,  4955,  4955,   941,  4955,   940,   995,  4955,  4955,
   -1190, -1190,  4955,  1121, -1190,  1122, -1190,  1123, -1190,   -77,
    1260, -1190,  3212,  3212,   946,  4905,   947,   859, -1190, -1190,
   -1190, -1190, -1190, -1190,  3212,  1124,   955,  4955,  1132, -1190,
   -1190,  4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,
    4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,
    4955,  4955,  4955,   828,   828,   828,   828,   828,   828,   828,
     828,   828,  4955,   859,  4955,   828,   828,   828,   874,   859,
     960,   960,   960,  7865,   289,  7520,   357,   956,  1133,   954,
     958,   966,   968, -1190,   969,  4995,  4955,  4563, -1190,  4955,
    4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,  4955,
    4955,  4955,  4955,  4955, -1190, -1190,  4955, -1190, -1190,  1438,
     -74,    63, -1190, -1190,    88,  6327, -1190,   210,   245,   326,
    7886,  4563,  4692, -1190,   181,  7907,  7928,  4955,  7949,   264,
    7970,  7991,  4955,   371,  8012,  8033,  1149,  4955,  4955,   382,
    1152,  1154,  1155,  4955,  4955,  1158,  1161,  1161,  4955,  4734,
    4734,  4734,  4734,  4955,  4955,  4955,  1162,  5304,   983,  1166,
     988, -1190, -1190,   123, -1190, -1190,  6353,  6379,  -109,  -109,
     145,   145,   126,  4955,  4955,  4955,  4386,  4386,  4955,  4995,
     129, -1190,  4955,  4955,  4955,  4955,  4955,  1167,  1170,  1171,
    4955,  1173, -1190,  4955,  4955,  1685, -1190,  4563,  4563,  4563,
    1174,  1176,  4955,  4955,  4955,  4955,  1180,   238,  1184, -1190,
    4955, -1190, -1190, -1190,  1004,  1005,  1010,  1011,  4563,   960,
   -1190,  8054, -1190,   406,  4955,  3566, -1190, -1190,  8075,  8096,
    8117,  1070,  6405, -1190,  1016,  4860,  8138,  7543, -1190, -1190,
    1854, -1190,  1984,  4955, -1190,  1021,   443,  4563,   289,  7566,
    4955,  1196,  1197, -1190,  4955,  7589,   183,  7497,  7497,  7497,
    7497,  7497,  7497,  7497,  7497,  7497,  7497,  7497,  6431,  7497,
    7497,  7497,  7497,  7497,  7497,  7497,  6457,  6483,  6509,   516,
     540,   516,  1025,  1026,  1023,  1024,  1031,   218,  8579, -1190,
    1514,  1032,  1030,  1033,  1039,  1040,   289, -1190,  3212,   297,
     859,  4955,  1214,  1217,    22,  1045, -1190,   124,    21,    23,
     213, -1190,  5406,   458,  4983,  2095,   659,   676,   676,   705,
     705,   705,   705,   358,   358,   960,   960,   960,   960,    25,
    7612, -1190,  4955,  1224,    37,  4563,  1223,  4563,  4955,  1225,
     828,  1229, -1190,   874,  1231,   828,  1235,  4563,  4563,  1114,
    1237,  1240,  8159,  1241,  1118,  1245,  1246,  8180,  1138,  1257,
    1263,  4955,  8201,  5434,  1087, -1190, -1190, -1190,  8222,  8243,
    4955,  3212,  1269,  1268,  8264,  1098,  8579, -1190,  1099,  8579,
   -1190,  1100,  8579, -1190,  1102,  8579, -1190,  8285,  8306,  8327,
    3212,  4563,  1101, -1190, -1190,  2224,  2350,  -109,  4955,  4955,
   -1190, -1190,  1096,  1104,  4386,  6535,  6561,  6587,  6301,   651,
    -109,  2897,  8348,  5462,  8369,  8390,  8411,  4955,  1278, -1190,
    4955,  8432, -1190,  7635,  7658, -1190,   490,   549,   561, -1190,
   -1190,  7681,  7704,  6613,  7727,   -59, -1190, -1190,  4563, -1190,
    1107,  5490,  4563,  4563,  4563,  4563,   570, -1190, -1190,  5005,
    4563,   960, -1190,  1285,  1286,  1287,  1103,  4955,  3074,  4955,
    4955, -1190,    38, -1190, -1190,  1106,  3212,  1289,   603,  3212,
     483,  5518, -1190, -1190,  7750,   217, -1190, -1190, -1190, -1190,
   -1190, -1190, -1190, -1190, -1190, -1190, -1190, -1190,  4955, -1190,
   -1190, -1190, -1190, -1190, -1190, -1190,  4955,  4955,  4955, -1190,
    4563, -1190, -1190, -1190, -1190,   828,   828,   828, -1190, -1190,
   -1190, -1190,  4955, -1190,   828, -1190, -1190,  4955,  1290,    32,
    4955,  1292,  1294,  1798, -1190,  1295,  1125,    19,  1298, -1190,
    4563,  4563,  4563,  4563, -1190,   627,  4955, -1190,  1128,  1129,
    1130, -1190,  1302, -1190, -1190, -1190, -1190, -1190,   -59,  7773,
   -1190, -1190,  1144,   828,   272, -1190,   313,  6639, -1190, -1190,
   -1190,  1304, -1190, -1190,  -109,  4692, -1190,   739,  3212,  3212,
    1307,  3212,   740,  3212,  3212,  1309,  1247,  3212,  3212,  1821,
    1311,  1312,  4563,  1314,  1315,  5331, -1190, -1190,  1318, -1190,
    1319,    24,    31,    34,    42,  1320,  1321,  1322,  1324,   668,
    1328,  3251, -1190, -1190,   188,  6665,  6691, -1190, -1190,  5546,
     -57,  -109,  -109,  -109,  1334,  1333,  1140,  1335,  1164,    40,
      47,    48,    52,   438, -1190,   307, -1190,   651,  1336,  1339,
    1340,  1341,  1343,  8579, -1190,  1840,  1168,  1345,  1348,  1351,
    1291,  4955,  1352,  1354,  4955,   595,   671, -1190, -1190,   679,
     700,   703,   704, -1190,  4955,   707,  3212,  3212,  3212,  1357,
    6717, -1190,  5025,  1381,  1360,  1361,  3212,  1181, -1190,  1187,
    1363,  4955,  1364, -1190,  1365,  1370, -1190,  1369,  7497,  7497,
    7497,  7497,   594,  1156,  1198,  1200,   604,   614,  8453,  1201,
    2014, -1190,   492,  1199,  1376,  2053, -1190, -1190, -1190,    19,
    4955, -1190,   710, -1190,   721,   725,   729,   730,   289,  8579,
    1206,  4955,  4955,  3212,  1202, -1190, -1190,  1204, -1190,  1388,
      45,  1389,  4955,  4097,     9,  1216,  1218,  1325,  1325,  3212,
    1401,  1226,  1228,  1402,  1403,  3212,  1230,  1404,  1410, -1190,
    1412,  3212,   733,  3212,  3212,  1431,  1430, -1190,  3212,  3212,
    1391,  3212,  1392,  3212,  1393,  3212,  1394,  3212,  3212,  3212,
   -1190,  1436,   168, -1190,  4955,  4955,  4955,  1261,  1262,  -112,
      66,    94,  1265, -1190,  3212, -1190,  4955, -1190,  1447, -1190,
    1449, -1190,  1452, -1190,  1453, -1190, -1190,  4386,   834,  3035,
   -1190,  1275,  1277,  3743, -1190,  4563, -1190, -1190, -1190,  1279,
    2458, -1190, -1190,  7796,  1459,   627, -1190, -1190, -1190, -1190,
    8579, -1190,  1460,  1461,  1338, -1190,  4955,  4955,  4955, -1190,
    1462,   608,  1288,  1463,   289, -1190,  2626, -1190, -1190,   233,
   -1190, -1190, -1190, -1190, -1190, -1190,   828, -1190, -1190,  1467,
   -1190, -1190,  1470, -1190, -1190, -1190, -1190, -1190,   859,  4955,
    1472,  1475,    22, -1190,  1474,  7819,    19, -1190,  1477,  1478,
    1482,  1483,  3212,  4955,  6743,  6769,   743, -1190,  4955,  1486,
   -1190, -1190,   828, -1190,  6795,  4734,  8579, -1190, -1190,  4955,
    4955,  -109,  1487,  1489,  1490, -1190,  4955,  4955, -1190, -1190,
    1491,  4955, -1190, -1190,  1471,  1492,  1296,  1493,  1371,  4955,
   -1190,  1494,  1495,  1327,  1497,  1329,  1498,  1331,  1500,  1332,
    1501,   920,  1503,  4955, -1190,  4734,  5574,  8474,  5054,   145,
     145,  -109,  1504,  -109,  1507,  -109,  1512,  4955,   546,  1308,
    8495, -1190, -1190, -1190, -1190,  5602,   316, -1190,  1516,  2309,
    1517,  3212,  -109,  2309,  1521,   749,  4955, -1190,  1524,   -59,
   -1190, -1190, -1190,  3212,  5350,   797,  8516, -1190, -1190,  4153,
    3212, -1190,  3212, -1190, -1190,  1353,  2681,  4330,  1527,  2646,
   -1190,  1531,  1533, -1190,  1372, -1190, -1190, -1190, -1190, -1190,
    1549,   314,  8579,  4955,  4955,  3212,  1378,   750,  8579, -1190,
    1558,  4955,  8579, -1190,  5630,  5658,   517, -1190, -1190, -1190,
    5686,  5714, -1190,  5742,  1564, -1190,  3212, -1190,  1505,  1569,
    8579, -1190, -1190,  4955, -1190,  4955, -1190,  4955, -1190,  4955,
   -1190,  1385, -1190, -1190,  6274,  3688,  1571,  1400, -1190,  4955,
   -1190,  1405,  1425,   327, -1190,  1427,   394, -1190,  1428,   396,
   -1190,  1432,  7842,  1572,  3212,  1579,  1433,  4955, -1190,  3920,
     419, -1190,   753,   442,   444, -1190,  1573,  5770, -1190,  1496,
    4955, -1190,  4955, -1190, -1190,  4563,  3707,  1581,  1434,  1610,
   -1190,  2497, -1190, -1190,   828,  8579, -1190, -1190, -1190,    19,
   -1190,  1499, -1190, -1190,  4955,  6821,  6847, -1190,  3212,  4955,
    1613, -1190,  6873, -1190, -1190,  1617,  1618,  1619,  1620,  1621,
    1624,   766,  1454, -1190,  6899,  6925,  6951,  6977,  3212,  4563,
   -1190, -1190,   145,  5378, -1190, -1190,  4386,   651,  4386,   651,
    4386,   651,  1626, -1190,   801,  3212, -1190,  5798,  -109,  1631,
    4563,  -109, -1190, -1190,  4955,  5826,  5854,   802, -1190, -1190,
    1634, -1190,   806,  4292,   813,  1635, -1190,  1457,  8579,  4955,
    4955,   824,  8579, -1190,  4955,   825,   841, -1190, -1190, -1190,
   -1190, -1190, -1190,  1458,  4955,  4955,  4955,  4955,  4955,   847,
     850,  1464,  4955, -1190,  5882,   449,  1036,  5910,   467,  1079,
    5938,   487,  1126, -1190,  3212,  1641,  1560,  3428,  1466,   493,
   -1190,   853,   496,  3874, -1190, -1190,  1643, -1190,  4955, -1190,
     859, -1190, -1190,  4955,  8537,  7003,    33,  7029, -1190, -1190,
    4955,  5966,  7055,  7081,  7107,  7133,  1646,  1647, -1190,  5994,
    1649,  4955,  1650,  1652,  4955,  1657,  1658,  4955,  1659,  1480,
   -1190,  4955, -1190,   651, -1190,  4563,  1661,  3920, -1190, -1190,
    1731, -1190,   857, -1190,  4955, -1190,  3212,  4955,  7159, -1190,
    4955,  4955,  4955,  4955, -1190, -1190, -1190, -1190,  1502,  6022,
   -1190, -1190,  1508,  6050, -1190, -1190,  1509,  6078, -1190,  1666,
    4059,  1148,  3605,   869, -1190,   510,   873,   859,  1682,  1510,
    8558,   877,  6106,  4955,  7185,  7211,  7237,  7263,   651,  1683,
     651,  1686,   651,  1690, -1190, -1190, -1190, -1190,   651,  1693,
    4563,  1696, -1190, -1190,   828, -1190,  1518,  1698,  6134,  4955,
    4955,  4955,  4955,  1284, -1190,  1520,  1684, -1190,  1522,  2283,
   -1190,  1523,  2471, -1190,   878, -1190,   881, -1190,  1525,  3212,
   -1190,  1700,  7289,  7315,  7341,  7367,  1706,   651,  1707,   651,
    1708,   651, -1190,  1709,   828,  1710,   828,   882, -1190,  4955,
    4955,  4955,  4955, -1190,  2655, -1190,  2731, -1190,  2832, -1190,
   -1190, -1190,   886, -1190,  1712,  7393,  7419,  7445,  7471,  1713,
    1715,  1716,   828,  1718, -1190,  4955,  4955,  4955,  4955, -1190,
   -1190, -1190, -1190, -1190,  6162,  6190,  6218,  6246,  1719,  1720,
    1721,  1722, -1190, -1190, -1190, -1190
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1190, -1190, -1190, -1190,   680, -1190, -1190, -1190, -1190,   237,
   -1190, -1190, -1190, -1190, -1190, -1190, -1190, -1190, -1190, -1190,
   -1190, -1190,  -345,   -29,   -31,  -429, -1190,  1326, -1190, -1190,
   -1190, -1190, -1190,   350, -1190,   356, -1190, -1190, -1190, -1190,
   -1190, -1190,   724,  1741,     3,  -448,  -235, -1190, -1190, -1190,
   -1190, -1190, -1190,  1745, -1190, -1190, -1190, -1190, -1190, -1190,
   -1190, -1190, -1190, -1190, -1190, -1190, -1190,  -889,  -809, -1190,
   -1190,  1297, -1190, -1190, -1190, -1190, -1190,    -6, -1190, -1190,
     623, -1190, -1189,   698,   771,   848,  1084,  -215,   607, -1190,
      -5,     1, -1190,  -340,   250,   226
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -455
static const yytype_int16 yytable[] =
{
     166,   168,   287,   569,   469,   571,    89,   169,   481,   450,
     482,   577,   692,   693,   249,  1168,   485,     4,   316,   588,
     295,   591,   195,   284,   190,   190,   816,   195,  1078,   827,
     186,  1039,   297,   499,   366,   176,   982,   187,  1041,  1535,
     174,  1043,  1342,   841,   173,   954,  1067,   301,   252,  1045,
     253,  1161,   224,  1069,  1071,     5,   458,   459,  1073,   228,
     229,   530,   304,   532,   305,   225,   226,   220,   472,   230,
     221,   306,  1211,   315,  1212,   473,   231,   300,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   533,  1076,   496,   622,  1391,   623,   254,
     164,   458,   459,   164,   352,   353,   312,   313,   767,   768,
     769,   770,   771,   772,   773,   774,   775,   776,   777,  1058,
     779,   780,   781,   782,   783,   784,   785,   175,   312,   313,
     789,   791,   792,   828,   829,   830,   831,   250,  -452,   372,
     360,   361,   362,   363,   365,  1040,  1068,   172,   367,   368,
     983,   984,  1042,  1070,  1072,  1044,   373,   399,  1074,   401,
     404,   405,   396,  1046,  1204,  1205,   288,   458,   459,   306,
     410,   412,   415,   416,   483,   418,   412,   420,   421,  1441,
     412,   424,   425,   759,   317,   251,   318,   412,   191,   191,
     296,   164,   842,   196,   285,   192,   821,   817,   822,  1459,
     842,   832,   298,   500,   177,   447,   685,   686,  1536,   302,
     955,   400,   105,   184,   456,   457,   303,   257,   241,   102,
     258,   497,   171,   457,   458,   459,   701,    45,    46,    47,
      48,   807,   624,   213,   810,    53,   214,   625,    56,   215,
    1213,   216,  1214,   101,   458,   459,   131,   132,   133,   134,
     135,   136,   458,   459,   509,   511,   412,   626,   140,  1076,
     141,   460,   627,   458,   459,   518,   519,   520,  1215,   522,
    1216,   146,   525,   526,   458,   459,   527,   178,   748,   242,
     461,   458,   459,   243,   458,   459,   587,   458,   459,   539,
     236,   471,   186,   237,   587,   244,   238,   687,   541,   820,
     694,   545,   245,   700,   246,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   592,   319,   570,
     320,   572,   573,   574,   575,   576,   578,  1571,   580,   179,
     581,   582,   583,   180,   579,   307,   458,   459,   312,   313,
     585,   149,   150,   204,   590,   638,   205,   639,  -453,   206,
     602,   412,  1054,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   371,   629,
     620,   198,   312,   313,   630,   182,   998,   798,   823,   965,
     403,   403,   630,   228,   229,   509,   181,   403,   312,   313,
     183,   642,   370,   230,   185,   961,   647,   726,  -454,   727,
     239,   652,   653,   728,   370,   370,   631,   658,   659,   632,
    1637,   370,   664,   666,   669,   672,   675,   677,   678,   679,
     667,   670,   673,   676,   308,   309,   310,   311,   638,   891,
     644,  1010,   308,   309,   310,   311,   638,   695,   696,   697,
     360,   361,   698,   373,   373,   188,   702,   703,   704,   705,
     706,   189,   312,   313,   711,   458,   459,   713,   714,   809,
     193,   412,   412,   412,   458,   459,   721,   722,   723,   724,
     587,  1077,  1011,  1373,   731,   458,   459,   638,  1374,  1138,
    1337,   194,   412,   308,   309,   310,   311,   634,   739,   741,
     632,  1406,   308,   309,   310,   311,   209,   766,  1466,   210,
    1469,   211,  1472,   312,   313,   199,   904,   724,   390,   391,
     392,   412,   312,   313,   761,   393,   905,   197,   764,  1121,
    1122,  1123,  1124,  1125,   906,   907,   908,  1130,  1133,   200,
     909,   910,   911,   912,   514,   638,   217,   648,   198,   218,
     811,   219,   458,   459,   458,   459,   638,   212,   654,   403,
     403,   403,   403,   403,   403,   403,   403,   403,  1408,   201,
    1410,   403,   403,   403,   584,   813,   202,   458,   459,   207,
     638,   812,   738,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   991,  1418,   208,   370,   370,   370,   370,   203,
     458,   459,   458,   459,  1248,  1249,   839,   458,   459,   412,
     223,   412,   847,   222,  1075,   849,  1420,   756,  1421,   757,
     853,   741,   855,  1511,  1561,   458,   459,  1139,   308,   309,
     310,   311,   638,   247,   825,   869,   227,   308,   309,   310,
     311,  1514,   248,  1152,   875,   458,   459,  1076,   312,   313,
    1076,   458,   459,  1076,   458,   459,  1240,   312,   313,   232,
     234,  1517,   240,   255,   638,   412,   929,  1525,   458,   459,
    1527,   256,   895,   896,   504,   458,   459,   505,   899,  1603,
     506,  1606,   507,  1609,  1590,   726,   766,   727,   235,  1612,
     630,   923,   281,   259,   925,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   515,   391,   392,   726,
     260,   727,   412,   393,   790,   282,   412,   412,   412,   412,
     261,   962,  1333,   638,   412,   930,   966,   283,  1644,   904,
    1646,   950,  1648,   952,   953,   638,   319,   931,   495,   905,
     496,   280,  1076,   163,   638,   164,   943,   906,   907,   908,
     967,  1321,  1322,   909,   910,   911,   912,   289,   290,  1252,
     312,   313,   968,   726,  1144,   727,   291,  1094,   638,   292,
     969,   970,   971,   726,   412,   727,   293,   638,  1129,   959,
     973,   974,   975,   726,  1076,   727,   978,  1076,  1132,   979,
    1076,   980,   294,  1076,   985,  1352,   726,   346,   727,  1006,
    1015,  1021,  1016,  1022,   412,   412,   412,   412,   347,   348,
     999,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   400,   105,   349,  1076,   393,  1076,  1009,  1076,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   354,
     453,   454,   638,   393,  1051,   638,   403,  1095,   462,   851,
     350,   403,   470,   638,   105,  1096,   412,   131,   132,   133,
     134,   135,   136,   388,   389,   390,   391,   392,   369,   140,
     370,   141,   393,   370,   638,   370,  1097,   638,   638,  1098,
    1099,   638,   146,  1101,  1146,   351,  1147,   426,   131,   132,
     133,   134,   135,   136,   376,   638,   966,  1148,   377,   638,
     140,  1149,   141,   638,   638,  1150,  1151,   638,   446,  1186,
     355,   449,   904,   146,  1311,  1090,  1312,  1275,  1093,  1276,
     356,  1265,   905,   638,  1379,  1346,  1380,  1275,  1100,  1419,
     906,   907,   908,   357,   394,   479,   909,   910,   911,   912,
    1275,   378,  1453,  1140,  1461,  1116,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     358,   359,   149,   150,   393,   430,   431,   432,   395,   398,
     435,   436,   437,  1353,  1145,  1474,   638,  1475,  1486,   417,
    1488,   403,  1489,   422,   427,  1154,  1155,   630,   433,  1491,
     535,   536,   428,   149,   150,   434,  1164,  1166,  1275,  1129,
    1496,  1498,   542,   438,  1167,   370,   477,   478,   439,   448,
    1227,   403,   403,   403,  1434,  1132,   484,  1499,   490,   491,
     403,  1275,   440,  1506,   638,   413,  1507,   638,   441,  1526,
     413,  1379,   442,  1568,   413,   370,   370,   370,  1206,  1207,
    1208,   413,   451,   638,   370,  1589,   452,   638,  1218,  1591,
    1220,  1275,   638,  1596,  1633,  1634,  1275,  1635,  1654,   403,
    1662,  1225,  1663,   443,   444,   445,   463,   464,   465,   412,
     474,   690,   691,   475,   476,   480,   486,   501,   487,   454,
    1254,   492,   493,   370,   488,   489,   494,   498,   502,   503,
    1244,  1245,  1246,   516,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   510,   517,
     413,  1255,   393,   521,   904,   523,   524,   528,   529,   531,
     543,   537,   540,  1259,   905,   544,   546,   393,   593,  1258,
     594,   164,   906,   907,   908,   306,   595,  1272,   909,   910,
     911,   912,  1278,   163,  1435,   596,   651,  1280,   655,  1282,
     656,   657,   682,  1284,  1285,   660,  1283,   904,   661,   680,
    1290,  1291,   683,   684,   707,  1293,   709,   905,   710,   712,
     719,  1477,   720,  1300,   725,   906,   907,   908,   730,   732,
     733,   909,   910,   911,   912,   734,   735,  1314,   746,  1315,
     755,   749,   762,   763,   793,   794,  1316,   795,   796,   803,
    1254,  1332,   373,   373,   904,   797,   802,   804,   805,   806,
     814,   815,  1512,   412,   905,   413,   819,   412,   840,   845,
    1347,   848,   906,   907,   908,   850,   904,   852,   909,   910,
     911,   912,   854,  1356,   858,   857,   905,   859,   861,   862,
    1357,  1365,   863,   864,   906,   907,   908,  1363,  1366,   510,
     909,   910,   911,   912,   867,  1515,   534,  1375,  1376,   866,
     868,   414,   872,   877,   879,  1382,   419,   881,   882,   883,
     423,   884,   897,   890,   924,   949,   808,   429,   937,  1562,
     898,   956,   946,   947,   948,   958,   981,  1394,   986,  1395,
     987,  1396,   989,  1397,   993,   990,  1001,  1002,  1005,  1008,
     894,  1013,  1518,  1403,  1019,  1003,  1025,   900,  1030,  1031,
    1026,  1033,  1034,   915,  1037,  1064,  1038,  1047,  1048,  1049,
    1050,  1417,  1052,   509,  1586,   413,   413,   413,  1062,  1063,
    1126,  1065,  1066,  1079,  1425,  1080,  1426,  1081,  1082,   412,
    1083,  1086,   403,  1085,  1087,  1433,   413,  1088,  1091,   876,
    1092,  1105,  1089,   742,  1110,  1111,  1114,  1113,  1438,  1115,
    1117,  1118,   904,  1442,  1119,  1120,   370,  1127,   888,  1128,
    1136,  1141,   905,  1142,  1153,   413,  1159,  1158,   403,  1108,
     906,   907,   908,   412,  1160,  1163,   909,   910,   911,   912,
    1464,  1169,  1467,  1170,  1470,   373,  1171,  1175,  1178,  1179,
    1182,  1176,   370,  1177,   412,  1181,  1183,  1184,  1483,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,  1494,  1495,  1189,  1190,   393,  1497,  1193,
    1195,  1197,  1199,  1203,   621,  1217,  1209,  1210,  1501,  1502,
    1503,  1504,  1505,  1221,   957,  1222,  1509,   960,  1223,  1224,
    1231,   603,  1232,  1239,  1236,  1243,  1241,  1242,  1247,  1251,
    1626,  1256,  1250,   413,  1257,   413,  1294,  1014,  1260,  1261,
    1263,  1296,  1530,  1266,  1267,   742,   856,  1278,  1268,  1269,
    1279,  1531,  1334,  1287,  1538,  1288,  1289,  1292,  1295,  1297,
    1301,  1302,  1298,  1304,  1306,  1549,  1308,  1310,  1553,  1313,
    1324,  1557,  1303,  1327,  1305,  1560,  1307,  1309,  1330,   412,
     801,   412,  1338,  1341,  1059,  1060,  1061,  1345,  1570,   413,
    1348,  1572,  1360,  1367,  1574,  1575,  1576,  1577,  1369,  1370,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,  1371,  1372,  1017,  1018,   393,  1020,
    1109,  1023,  1024,  1378,  1381,  1027,  1028,  1598,  1592,  1390,
    1398,   716,   717,   718,  1392,  1393,   413,  1401,  1413,  1422,
     413,   413,   413,   413,   412,  1402,  1415,  1429,   413,  1617,
     403,  1404,   736,  1622,  1623,  1624,  1625,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,  1405,  1407,  1409,   370,   393,  1431,  1411,  1416,  1443,
    1430,   758,  1424,  1447,  1448,  1449,  1450,  1451,  1436,  1650,
    1452,  1653,  1473,  1655,  1656,  1657,  1658,  1480,   413,  1454,
    1487,  1492,  1493,  1500,  1102,  1103,  1104,  1520,  1521,  1529,
    1508,  1524,  1544,  1545,  1112,  1547,  1550,  1672,  1551,  1674,
    1675,  1676,  1677,  1554,  1555,  1558,  1559,  1564,   413,   413,
     413,   413,  1584,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,  1578,  1593,  1604,
    1162,   393,  1607,  1580,  1582,  1594,  1610,     7,     8,  1613,
    1226,  1157,  1615,  1619,  1620,  1627,  1638,  1629,  1631,   844,
    1636,   846,  1643,  1645,  1647,  1649,  1651,  1174,  1664,  1669,
     413,  1670,  1671,  1180,  1673,  1682,  1683,  1684,  1685,  1185,
    1532,  1187,  1188,  1445,   663,   635,  1191,  1192,  1567,  1194,
    1446,  1196,  1173,  1198,    88,  1200,  1201,  1202,    96,  1262,
     597,    21,    22,   598,    24,    25,   599,    27,   600,    29,
       0,    30,  1219,     0,     0,   889,    35,    36,     0,    38,
      39,    40,   904,     0,     0,    43,     0,  1230,     0,     0,
       0,  1234,   905,     0,     0,     0,     0,     0,     0,     0,
     906,   907,   908,     0,  1286,     0,   909,   910,   911,   912,
       0,     0,     0,     0,   988,     0,     0,     0,    64,    65,
      66,     0,   936,     0,     0,     0,   939,   940,   941,   942,
     403,     0,     0,     0,   945,     0,     0,  1029,     0,     0,
       0,     0,     0,     0,  1323,     0,  1326,     0,  1329,     0,
       0,     0,     0,     0,   370,     0,  1084,     0,     0,     0,
    1270,     0,  1340,     0,     0,  1343,  1344,     0,     0,     0,
     403,     0,   403,     0,     0,     0,     7,     8,     0,     0,
    1628,   715,     0,     0,   972,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,     0,   370,     0,   403,     0,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   994,   995,   996,   997,   393,     0,
       0,     0,   370,     0,     0,     0,     0,     0,     0,   597,
      21,    22,   598,    24,    25,   599,    27,   600,    29,  1157,
      30,   514,     0,   413,     0,    35,    36,     0,    38,    39,
      40,  1349,     0,     0,    43,     0,     0,     0,  1358,     0,
    1359,     0,     0,     0,  1362,     0,  1032,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,  1377,     0,   393,     0,    64,    65,    66,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,  1157,     0,     7,     8,   393,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
    1137,     0,     0,     0,     0,     0,     0,     0,     0,  1465,
       0,  1468,  1414,  1471,     0,     0,     0,     0,     0,     0,
     753,  1479,     0,     0,  1482,     0,     0,     0,     0,   597,
      21,    22,   598,    24,    25,   599,    27,   600,    29,  1143,
      30,     0,     0,     0,     0,    35,    36,     0,    38,    39,
      40,     0,     0,     0,    43,     0,  1157,   413,     0,     0,
       0,   413,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   515,   391,   392,  1157,     0,     0,     0,
     393,     0,     0,     0,   103,   104,   105,    64,    65,    66,
     106,   107,   108,  1476,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
    1565,     0,   140,     0,   141,     0,   142,   143,   144,     0,
       0,     0,     0,     0,   145,   146,     0,     0,     0,  1235,
     754,     0,  1519,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   510,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,     0,     0,     0,     0,     0,   413,
       0,     0,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,  1157,     0,     7,     8,   147,     0,
       0,     0,     0,     0,   148,   149,   150,   413,     0,     0,
       0,   151,   152,   153,   154,   155,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   413,   156,
     157,     0,   393,     0,   158,     0,     0,     0,     0,   159,
       0,   160,     0,   161,   162,     0,   163,     0,   164,   597,
      21,    22,   598,    24,    25,   599,    27,   600,    29,     0,
      30,     0,     0,     0,     0,    35,    36,     0,    38,    39,
      40,     0,   103,   262,    43,     0,     0,  1157,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   264,     0,    64,    65,    66,
       0,     0,     0,     0,   137,   138,   139,     0,     0,     0,
       0,     0,     7,     8,   142,   143,   144,     0,     0,     0,
       0,   904,   145,   413,   265,   413,     0,   266,     0,     0,
     267,   905,   268,     0,     0,     0,     0,     0,     0,   906,
     907,   908,     0,     0,   269,   909,   910,   911,   912,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
     892,     0,    56,     0,     0,   597,    21,    22,   598,    24,
      25,   599,    27,   600,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,     0,   413,  1427,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,  1237,     0,     0,     0,     0,  1630,
       0,     0,     0,    64,    65,    66,     0,   466,  1339,     0,
       0,     0,   158,  1460,     0,     0,     0,   468,     0,     0,
       0,     0,   162,     0,   231,   512,     0,     0,     0,     0,
     103,   262,     0,     0,  1481,     0,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   264,     0,     0,   893,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,     0,     0,     0,   904,
     145,     0,   265,     0,     0,   266,     0,     0,   267,   905,
     268,     0,     0,     0,     0,     0,     0,   906,   907,   908,
       0,     0,   269,   909,   910,   911,   912,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,  1563,
       0,  1566,     0,     0,     0,     0,     0,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,  1253,     0,     0,   393,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,  1368,     0,     0,     0,     0,  1632,     0,     0,
       0,     0,     0,     0,     0,   156,   411,     0,     0,     0,
     158,     0,     0,     0,  1614,   271,     0,     0,     0,     0,
     162,     0,     0,   512,   103,   262,   105,     0,     0,     0,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   264,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,     0,   140,     0,   141,     0,   142,   143,   144,     0,
       0,     0,     0,   904,   145,   146,   265,     0,     0,   266,
       0,     0,   267,   905,   268,     0,     0,     0,     0,     0,
       0,   906,   907,   908,     0,     0,   269,   909,   910,   911,
     912,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   904,
       0,     0,     0,   393,   148,   149,   150,     0,     0,   905,
       0,   151,   152,   153,   154,   155,     0,   906,   907,   908,
       0,  1659,     0,   909,   910,   911,   912,     0,     0,   156,
     270,     0,     0,     0,   158,     0,     0,     0,     0,   271,
       0,   103,   262,   263,   162,     0,  1361,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,   139,     0,     0,     0,     7,
       8,     0,     0,   142,   143,   144,     0,  1660,     0,     0,
     904,   145,     0,   265,     0,     0,   266,     0,     0,   267,
     905,   268,     0,     0,     0,     0,     0,     0,   906,   907,
     908,     0,     0,   269,   909,   910,   911,   912,     0,     0,
      45,    46,    47,    48,    49,     0,     0,     0,    53,     0,
       0,    56,   597,    21,    22,   598,    24,    25,   599,    27,
     600,    29,     0,    30,     0,     0,     0,     0,    35,    36,
       0,    38,    39,    40,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,  1661,     0,
      64,    65,    66,     0,     0,     0,   156,   270,     0,     0,
       0,   158,     0,     0,     0,     0,   271,     0,   103,   262,
    1228,   162,     0,   272,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   916,     0,     0,     7,     8,     0,     0,
     142,   143,   144,     0,     0,     0,     0,     0,   145,     0,
     265,     0,     0,   266,     0,     0,   267,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,   597,
      21,    22,   598,    24,    25,   599,    27,   600,    29,     0,
      30,     0,     0,     0,     0,    35,    36,     0,    38,    39,
      40,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     0,     0,   156,   270,     0,     0,     0,   158,     0,
       0,     0,     0,   271,     0,   103,   262,     0,   162,     0,
    1229,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
     951,     0,     0,     7,     8,     0,     0,   142,   143,   144,
       0,     0,     0,     0,     0,   145,     0,   265,     0,     0,
     266,     0,     0,   267,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,     0,
       0,     0,    53,     0,     0,    56,   597,    21,    22,   598,
      24,    25,   599,    27,   600,    29,     0,    30,     0,     0,
       0,     0,    35,    36,     0,    38,    39,    40,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,     0,
     156,   270,     0,     0,     0,   158,     0,     0,     0,     0,
     271,     0,   103,   262,     0,   162,     0,   272,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,  1053,     0,     0,
       7,     8,     0,     0,   142,   143,   144,     0,     0,     0,
       0,     0,   145,     0,   265,     0,     0,   266,     0,     0,
     267,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   597,    21,    22,   598,    24,    25,   599,
      27,   600,    29,     0,    30,     0,     0,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,   156,   411,     0,
       0,     0,   158,     0,     0,     0,     0,   271,     0,   103,
     262,     0,   162,     0,   508,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,  1522,     0,     0,     7,     8,     0,
       0,   142,   143,   144,     0,     0,     0,     0,     0,   145,
       0,   265,     0,     0,   266,     0,     0,   267,     0,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     597,    21,    22,   598,    24,    25,   599,    27,   600,    29,
       0,    30,     0,     0,     0,     0,    35,    36,     0,    38,
      39,    40,     0,     0,  1400,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,  1428,     0,     0,   151,   152,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     0,     0,   156,   411,     0,     0,     0,   158,
       0,     0,     0,     0,   271,     0,   103,   262,     0,   162,
       0,   740,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,  1587,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,     0,     0,     0,     0,   145,     0,   265,     0,
       0,   266,     0,     0,   267,     0,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
       0,     0,     0,    53,     0,     0,    56,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
    1528,     0,     0,     0,   393,     0,   148,     0,     0,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   270,     0,     0,     0,   158,     0,     0,     0,
       0,   271,     0,   103,   262,     0,   162,     0,  1233,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,     0,
       0,     0,     0,   145,     0,   265,     0,     0,   266,     0,
       0,   267,     0,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,     0,     0,     0,
      53,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,  1585,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,  1339,
       0,     0,     0,   158,     0,     0,     0,     0,   468,     0,
     103,   299,   105,   162,     0,   231,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,   140,     0,
     141,     0,   142,   143,   144,     0,   103,   299,   105,     0,
     145,   146,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,     0,   140,     0,   141,     0,   142,   143,
     144,     0,     0,     0,     0,     0,   145,   146,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,     0,     0,     0,
     158,     0,     0,     0,     0,   271,     0,     0,     0,     0,
     162,     0,  1165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,  1490,
     514,     0,     0,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   157,     0,     0,     0,   158,     0,     0,     0,
       0,   271,     0,   103,   299,   105,   162,     0,  1355,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,     0,   141,     0,   142,   143,   144,     0,   103,
     299,     0,     0,   145,   146,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,     0,     0,     0,     0,   145,
       0,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   637,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,   148,   149,   150,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
       0,     0,     0,   158,     0,     0,     0,     0,   271,     0,
       0,     0,     0,   162,     0,  1364,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   151,   152,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   466,   467,     0,     0,     0,   158,
       0,     0,     0,     0,   468,     0,   103,   262,     0,   162,
       0,   231,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,     0,     0,     0,     0,   145,     0,   265,     0,
       0,   266,     0,     0,   267,     0,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
       0,     0,     0,    53,     0,     0,    56,   103,   299,     0,
       0,     0,     0,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     514,     0,     0,     0,     0,     0,   148,     0,     0,   137,
     138,   139,     0,   151,   152,   153,   154,   155,     0,   142,
     143,   144,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   156,   411,     0,     0,     0,   158,   103,   299,   105,
       0,   271,     0,   106,   107,   108,   162,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,   140,     0,   141,     0,   142,
     143,   144,     0,     0,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,     0,     0,   158,     0,     0,
       0,     0,   271,     0,     0,   364,     0,   162,     0,     0,
       0,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   637,   391,   392,     0,     0,     0,   750,   393,
       0,     0,     0,     0,     0,     0,     0,   148,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,     0,     0,   158,   103,   299,
       0,     0,   271,     0,   106,   107,   108,   162,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,     0,     0,     0,     0,     0,   103,   299,
     142,   143,   144,     0,   106,   107,   108,     0,   145,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   826,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,     0,     0,     0,     0,     7,     8,     0,
     142,   143,   144,   944,     0,     0,     0,     0,   145,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,  1107,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     597,    21,    22,   598,    24,    25,   599,    27,   600,    29,
       0,    30,     0,   156,   157,     0,    35,    36,   158,    38,
      39,    40,     0,   271,     0,    43,   538,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     0,   156,   157,     0,     0,     0,   158,     0,
       0,     0,     0,   271,     0,     0,     0,     0,   162,     0,
       0,     0,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,    -4,
       1,     0,   393,    -4,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,    -4,    -4,  1319,     0,
    1320,     0,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,    -4,     0,    -4,     0,     0,     0,    -4,    -4,     0,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,     0,    -4,     6,     0,     0,
       0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,     0,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,     0,    14,     0,    15,     0,     0,
       0,    16,    17,     0,    18,    19,     0,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,  1035,
       0,     0,    59,    60,    61,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,    63,    64,    65,    66,     0,
       0,    67,     0,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    80,
      81,    82,    83,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,   681,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1350,     0,  1351,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1462,     0,  1463,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,   824,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
     871,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,   919,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,   938,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,   963,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1057,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1317,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1336,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1385,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1386,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1387,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1388,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1389,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1423,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1478,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1484,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1485,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1510,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1513,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1516,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1539,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1546,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1579,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1581,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1583,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1597,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1621,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1678,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1679,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1680,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1681,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,  1399,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     737,     0,     0,     0,     0,   688,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,   628,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,   688,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,   689,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,   747,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,   778,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,   786,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,   787,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,   788,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,   901,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,   902,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,   903,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,   934,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1012,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1055,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1056,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1106,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1273,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1274,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1281,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1439,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1440,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1444,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1455,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1456,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1457,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1458,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1534,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1537,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1540,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1541,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1542,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1543,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1573,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1599,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1600,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1601,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1602,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1639,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1640,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1641,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1642,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1665,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1666,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1667,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1668,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   726,     0,   727,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,   589,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,   752,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,   760,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
     765,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,   838,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,   927,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,   928,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,   932,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,   933,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,   935,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,   964,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,  1007,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,  1238,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
    1264,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,  1412,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   586,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   636,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   640,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   641,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   643,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   645,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     646,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   649,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   650,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   737,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   743,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   744,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   745,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   751,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   860,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   865,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     870,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   873,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   874,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   880,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   885,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   886,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   887,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   918,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   920,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   921,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     922,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   926,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,  1135,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,  1318,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,  1335,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,  1354,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,  1533,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,  1595,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1190)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,     6,     4,   343,   239,   345,     3,     6,     4,   224,
       6,   351,   460,   461,     4,     6,   251,     6,     4,   364,
       5,   366,     4,     4,     4,     4,     4,     4,   917,     4,
     178,     7,     5,     5,     4,     6,     4,   185,     7,     6,
     178,     7,  1231,     6,    71,     7,     6,     6,     4,     7,
       6,     6,   128,     6,     6,     0,   168,   169,     6,   168,
     169,   296,   178,   298,   180,   141,   142,    68,   178,   178,
      71,   187,   184,   102,   186,   185,   185,    83,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   180,   913,   182,   180,  1296,   182,    65,
     187,   168,   169,   187,   145,   146,   175,   176,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   186,
     559,   560,   561,   562,   563,   564,   565,   178,   175,   176,
     569,   570,   571,   118,   119,   120,   121,   137,   185,     4,
     156,   157,   158,   159,   160,   131,   116,    13,   128,   129,
     128,   129,   131,   116,   116,   131,   163,   173,   116,   174,
     175,   177,   180,   131,     6,     7,   178,   168,   169,   187,
     186,   187,   188,   189,   180,   191,   192,   193,   194,  1378,
     196,   197,   198,   538,   180,   185,   182,   203,   178,   178,
     185,   187,   165,   185,   185,   185,   185,   185,   185,  1398,
     165,   186,   185,   185,   185,   221,   451,   452,   185,   178,
     182,     4,     5,   180,   230,   231,   185,    68,     4,     3,
      71,   262,     6,   239,   168,   169,   471,    92,    93,    94,
      95,   586,   179,    65,   589,   100,    68,   184,   103,    71,
     184,    73,   186,     3,   168,   169,    39,    40,    41,    42,
      43,    44,   168,   169,   270,   271,   272,   179,    51,  1078,
      53,   185,   184,   168,   169,   281,   282,   283,   184,   285,
     186,    64,   288,   289,   168,   169,   292,     6,   523,    65,
     185,   168,   169,    69,   168,   169,     7,   168,   169,   305,
      65,   185,   178,    68,     7,    81,    71,   184,   307,   185,
     184,   317,    71,   184,    73,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   366,   178,   344,
     180,   346,   347,   348,   349,   350,   352,  1536,   354,     6,
     355,   356,   357,     6,   353,     7,   168,   169,   175,   176,
     359,   144,   145,    65,     7,   184,    68,   186,   185,    71,
     376,   377,   184,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   162,   179,
     396,   178,   175,   176,   184,     6,   825,   179,   185,   182,
     174,   175,   184,   168,   169,   411,   178,   181,   175,   176,
       6,   417,   162,   178,   180,   760,   422,   179,   185,   181,
     185,   427,   428,   185,   174,   175,   181,   433,   434,   184,
    1619,   181,   438,   439,   440,   441,   442,   443,   444,   445,
     439,   440,   441,   442,   155,   156,   157,   158,   184,   684,
     186,   179,   155,   156,   157,   158,   184,   463,   464,   465,
     466,   467,   468,   460,   461,   178,   472,   473,   474,   475,
     476,   178,   175,   176,   480,   168,   169,   483,   484,   182,
     178,   487,   488,   489,   168,   169,   492,   493,   494,   495,
       7,   184,   179,   179,   500,   168,   169,   184,   184,     7,
     184,   178,   508,   155,   156,   157,   158,   181,   514,   515,
     184,   184,   155,   156,   157,   158,    68,   546,  1407,    71,
    1409,    73,  1411,   175,   176,    75,    88,   533,   170,   171,
     172,   537,   175,   176,   540,   177,    98,   178,   544,   968,
     969,   970,   971,   972,   106,   107,   108,   976,   977,    71,
     112,   113,   114,   115,     8,   184,    68,   186,   178,    71,
     589,    73,   168,   169,   168,   169,   184,    73,   186,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   184,    71,
     184,   355,   356,   357,   358,   591,     6,   168,   169,    71,
     184,   590,   186,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   817,   184,    71,   355,   356,   357,   358,   185,
     168,   169,   168,   169,     6,     7,   622,   168,   169,   625,
      68,   627,   628,   178,   186,   630,   184,   184,   184,   186,
     635,   637,   638,   184,  1523,   168,   169,   982,   155,   156,
     157,   158,   184,    71,   186,   651,   185,   155,   156,   157,
     158,   184,    68,   998,   660,   168,   169,  1466,   175,   176,
    1469,   168,   169,  1472,   168,   169,  1095,   175,   176,    46,
      47,   184,    49,    68,   184,   681,   186,   184,   168,   169,
     184,    71,   688,   689,    65,   168,   169,    68,   694,  1578,
      71,  1580,    73,  1582,   184,   179,   725,   181,   185,  1588,
     184,   707,   178,     4,   710,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   179,
       4,   181,   728,   177,   184,   178,   732,   733,   734,   735,
       4,   760,   186,   184,   740,   186,   765,   178,  1627,    88,
    1629,   747,  1631,   749,   750,   184,   178,   186,   180,    98,
     182,     4,  1561,   185,   184,   187,   186,   106,   107,   108,
     765,  1209,  1210,   112,   113,   114,   115,   178,     6,  1114,
     175,   176,   778,   179,   989,   181,     6,   182,   184,   180,
     786,   787,   788,   179,   790,   181,     4,   184,   184,   186,
     795,   796,   797,   179,  1603,   181,   802,  1606,   184,   804,
    1609,   807,     4,  1612,   810,     8,   179,   178,   181,   838,
      71,    71,    73,    73,   820,   821,   822,   823,   178,   178,
     826,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     4,     5,   178,  1644,   177,  1646,   843,  1648,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     7,
     227,   228,   184,   177,   186,   184,   630,   186,   235,   633,
     178,   635,   239,   184,     5,   186,   872,    39,    40,    41,
      42,    43,    44,   168,   169,   170,   171,   172,     4,    51,
     630,    53,   177,   633,   184,   635,   186,   184,   184,   186,
     186,   184,    64,   186,   184,   178,   186,   199,    39,    40,
      41,    42,    43,    44,   185,   184,   935,   186,   185,   184,
      51,   186,    53,   184,   184,   186,   186,   184,   220,   186,
     178,   223,    88,    64,     4,   931,     6,   184,   934,   186,
     178,  1146,    98,   184,   184,   186,   186,   184,   944,   186,
     106,   107,   108,   178,   185,   247,   112,   113,   114,   115,
     184,     6,   186,   982,  1402,   961,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     178,   178,   144,   145,   177,   204,   205,   206,     6,     6,
     209,   210,   211,   186,   990,   184,   184,   186,   186,   178,
     184,   765,   186,   178,   178,  1001,  1002,   184,   178,   186,
     302,   303,   185,   144,   145,   178,  1012,  1013,   184,   184,
     186,   186,   314,   178,  1013,   765,   245,   246,   178,     4,
     186,   795,   796,   797,  1364,   184,   180,   186,   257,   258,
     804,   184,   178,   186,   184,   187,   186,   184,   178,   186,
     192,   184,   178,   186,   196,   795,   796,   797,  1054,  1055,
    1056,   203,   185,   184,   804,   186,   185,   184,  1064,   186,
    1066,   184,   184,   186,   186,   184,   184,   186,   186,   843,
     184,  1077,   186,   178,   178,   178,   185,   185,   185,  1085,
     178,   458,   459,   178,   178,   178,     6,     5,   185,   466,
    1119,   180,   180,   843,   185,   185,   180,   180,     5,     5,
    1106,  1107,  1108,     6,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   270,     6,
     272,  1126,   177,   182,    88,   185,   131,     6,     6,     6,
       6,   185,   185,  1139,    98,   180,     4,   177,   182,  1138,
       7,   187,   106,   107,   108,   187,   180,  1153,   112,   113,
     114,   115,  1158,   185,  1369,   186,     7,  1162,     6,  1165,
       6,     6,   179,  1169,  1170,     7,  1165,    88,     7,     7,
    1176,  1177,     6,   185,     7,  1181,     6,    98,     7,     6,
       6,  1416,     6,  1189,     4,   106,   107,   108,     4,   185,
     185,   112,   113,   114,   115,   185,   185,  1203,   128,  1205,
     179,   185,     6,     6,   179,   179,  1205,   184,   184,   179,
    1239,  1217,  1209,  1210,    88,   184,   184,   184,   179,   179,
       6,     4,   186,  1229,    98,   377,   181,  1233,     4,     6,
    1236,     6,   106,   107,   108,     6,    88,     6,   112,   113,
     114,   115,     7,  1249,     7,   131,    98,     7,     7,   131,
    1249,  1257,     7,     7,   106,   107,   108,  1256,  1257,   411,
     112,   113,   114,   115,     7,   186,     6,  1273,  1274,   131,
       7,   187,   185,     4,     6,  1281,   192,   179,   179,   179,
     196,   179,   186,   182,     6,   182,   588,   203,   181,  1524,
     186,   185,     7,     7,     7,     6,     6,  1303,     6,  1305,
       6,  1307,     7,  1309,     6,   180,   178,   178,     6,   165,
     687,     7,   186,  1319,     7,   185,     7,   694,     7,     7,
      73,     7,     7,   700,     6,   185,     7,     7,     7,     7,
       6,  1337,     4,  1339,   186,   487,   488,   489,     4,     6,
     184,     6,   178,     7,  1350,     6,  1352,     7,     7,  1355,
       7,     6,  1126,   185,     6,  1361,   508,     6,     6,   661,
       6,     4,    71,   515,     4,     4,   179,   186,  1374,     6,
       6,     6,    88,  1379,     4,     6,  1126,   179,   680,   179,
     179,   182,    98,     7,   178,   537,   182,   185,  1162,     8,
     106,   107,   108,  1399,     6,     6,   112,   113,   114,   115,
    1406,   185,  1408,   185,  1410,  1402,    81,     6,     6,     6,
       6,   185,  1162,   185,  1420,   185,     6,     5,  1424,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,  1439,  1440,     4,     6,   177,  1444,    48,
      48,    48,    48,     7,     6,   180,   185,   185,  1454,  1455,
    1456,  1457,  1458,     6,   756,     6,  1462,   759,     6,     6,
     185,   377,   185,     4,   185,   127,     6,     6,     6,     6,
     186,     4,   184,   625,     4,   627,     5,   854,     6,     4,
       6,   185,  1488,     6,     6,   637,   638,  1493,     6,     6,
       4,  1490,   184,     6,  1500,     6,     6,     6,     6,     6,
       6,     6,   131,     6,     6,  1511,     6,     6,  1514,     6,
       6,  1517,   185,     6,   185,  1521,   185,   185,     6,  1525,
       6,  1527,     6,     6,   901,   902,   903,     6,  1534,   681,
       6,  1537,   179,     6,  1540,  1541,  1542,  1543,     7,     6,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   182,     6,   858,   859,   177,   861,
     179,   863,   864,   185,     6,   867,   868,  1573,  1567,     5,
     185,   487,   488,   489,    69,     6,   728,     6,     6,     6,
     732,   733,   734,   735,  1590,   185,     7,     6,   740,  1594,
    1364,   186,   508,  1599,  1600,  1601,  1602,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   186,   185,   185,  1364,   177,     6,   185,   185,     6,
     186,   537,   126,     6,     6,     6,     6,     6,   129,  1634,
       6,  1636,     6,  1639,  1640,  1641,  1642,     6,   790,   185,
       6,     6,   185,   185,   946,   947,   948,     6,    88,     6,
     186,   185,     6,     6,   956,     6,     6,  1662,     6,  1665,
    1666,  1667,  1668,     6,     6,     6,   186,     6,   820,   821,
     822,   823,     6,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   185,     6,     6,
    1010,   177,     6,   185,   185,   185,     6,    12,    13,     6,
    1077,  1003,     6,   185,     6,   185,     6,   185,   185,   625,
     185,   627,     6,     6,     6,     6,     6,  1019,     6,     6,
     872,     6,     6,  1025,     6,     6,     6,     6,     6,  1031,
    1493,  1033,  1034,  1383,   437,   409,  1038,  1039,     7,  1041,
    1384,  1043,  1018,  1045,     3,  1047,  1048,  1049,     3,  1142,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,  1064,    -1,    -1,   681,    81,    82,    -1,    84,
      85,    86,    88,    -1,    -1,    90,    -1,  1079,    -1,    -1,
      -1,  1083,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,    -1,  1171,    -1,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   123,   124,
     125,    -1,   728,    -1,    -1,    -1,   732,   733,   734,   735,
    1594,    -1,    -1,    -1,   740,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,  1211,    -1,  1213,    -1,  1215,    -1,
      -1,    -1,    -1,    -1,  1594,    -1,     6,    -1,    -1,    -1,
    1152,    -1,  1229,    -1,    -1,  1232,  1233,    -1,    -1,    -1,
    1634,    -1,  1636,    -1,    -1,    -1,    12,    13,    -1,    -1,
     186,   186,    -1,    -1,   790,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1634,    -1,  1636,    -1,  1662,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   820,   821,   822,   823,   177,    -1,
      -1,    -1,  1662,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,  1231,
      76,     8,    -1,  1085,    -1,    81,    82,    -1,    84,    85,
      86,  1243,    -1,    -1,    90,    -1,    -1,    -1,  1250,    -1,
    1252,    -1,    -1,    -1,  1256,    -1,   872,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,  1275,    -1,   177,    -1,   123,   124,   125,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,  1296,    -1,    12,    13,   177,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1406,
      -1,  1408,  1334,  1410,    -1,    -1,    -1,    -1,    -1,    -1,
     186,  1418,    -1,    -1,  1421,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     6,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,  1378,  1229,    -1,    -1,
      -1,  1233,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,  1398,    -1,    -1,    -1,
     177,    -1,    -1,    -1,     3,     4,     5,   123,   124,   125,
       9,    10,    11,  1415,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
    1527,    -1,    51,    -1,    53,    -1,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,  1085,
     186,    -1,  1474,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,  1339,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1355,    -1,    -1,    -1,    -1,    -1,  1361,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,  1536,    -1,    12,    13,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,  1399,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,  1420,   168,
     169,    -1,   177,    -1,   173,    -1,    -1,    -1,    -1,   178,
      -1,   180,    -1,   182,   183,    -1,   185,    -1,   187,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,
      86,    -1,     3,     4,    90,    -1,    -1,  1619,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,   123,   124,   125,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    12,    13,    55,    56,    57,    -1,    -1,    -1,
      -1,    88,    63,  1525,    65,  1527,    -1,    68,    -1,    -1,
      71,    98,    73,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,    -1,    -1,    85,   112,   113,   114,   115,    -1,
      -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     186,    -1,   103,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    85,    86,    -1,  1590,  1355,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,     6,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   123,   124,   125,    -1,   168,   169,    -1,
      -1,    -1,   173,  1399,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,  1420,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    88,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    71,    98,
      73,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    85,   112,   113,   114,   115,    -1,    -1,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1525,
      -1,  1527,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,     6,    -1,    -1,   177,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,     6,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,  1590,   178,    -1,    -1,    -1,    -1,
     183,    -1,    -1,   186,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    53,    -1,    55,    56,    57,    -1,
      -1,    -1,    -1,    88,    63,    64,    65,    -1,    -1,    68,
      -1,    -1,    71,    98,    73,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,    -1,    -1,    85,   112,   113,   114,
     115,    -1,    -1,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    88,
      -1,    -1,    -1,   177,   143,   144,   145,    -1,    -1,    98,
      -1,   150,   151,   152,   153,   154,    -1,   106,   107,   108,
      -1,   186,    -1,   112,   113,   114,   115,    -1,    -1,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,
      -1,     3,     4,     5,   183,    -1,   185,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    12,
      13,    -1,    -1,    55,    56,    57,    -1,   186,    -1,    -1,
      88,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    71,
      98,    73,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,    85,   112,   113,   114,   115,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,
      -1,   103,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,   186,    -1,
     123,   124,   125,    -1,    -1,    -1,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   178,    -1,     3,     4,
       5,   183,    -1,   185,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,   186,    -1,    -1,    12,    13,    -1,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    71,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
      -1,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   178,    -1,     3,     4,    -1,   183,    -1,
     185,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
     186,    -1,    -1,    12,    13,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
     178,    -1,     3,     4,    -1,   183,    -1,   185,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,   186,    -1,    -1,
      12,    13,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,    -1,    -1,    -1,   168,   169,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,     3,
       4,    -1,   183,    -1,   185,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,   186,    -1,    -1,    12,    13,    -1,
      -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    71,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,
      85,    86,    -1,    -1,     6,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,     6,    -1,    -1,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,   178,    -1,     3,     4,    -1,   183,
      -1,   185,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,   186,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       6,    -1,    -1,    -1,   177,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,   178,    -1,     3,     4,    -1,   183,    -1,   185,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,     6,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,
       3,     4,     5,   183,    -1,   185,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      53,    -1,    55,    56,    57,    -1,     3,     4,     5,    -1,
      63,    64,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    -1,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    64,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     183,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,     7,
       8,    -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,   178,    -1,     3,     4,     5,   183,    -1,   185,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    -1,    53,    -1,    55,    56,    57,    -1,     3,
       4,    -1,    -1,    63,    64,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   183,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,   178,    -1,     3,     4,    -1,   183,
      -1,   185,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       8,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    45,
      46,    47,    -1,   150,   151,   152,   153,   154,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,   168,   169,    -1,    -1,    -1,   173,     3,     4,     5,
      -1,   178,    -1,     9,    10,    11,   183,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    -1,    53,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,   181,    -1,   183,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,     8,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,    -1,    -1,    -1,   173,     3,     4,
      -1,    -1,   178,    -1,     9,    10,    11,   183,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,     3,     4,
      55,    56,    57,    -1,     9,    10,    11,    -1,    63,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    12,    13,    -1,
      55,    56,    57,     8,    -1,    -1,    -1,    -1,    63,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     8,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    -1,   168,   169,    -1,    81,    82,   173,    84,
      85,    86,    -1,   178,    -1,    90,   181,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,     0,
       1,    -1,   177,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    37,    38,   184,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    52,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,    -1,    -1,    -1,   117,     4,    -1,    -1,
      -1,   122,   123,   124,   125,    12,    13,   128,    -1,   130,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,   149,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    52,    -1,    54,    -1,    -1,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    88,
      -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
      -1,   128,    -1,   130,    -1,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
     147,   148,   149,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
     179,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,   181,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,   181,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
     181,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,   181,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,   181,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   181,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,   181,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,   181,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   181,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,   181,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,   181,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,   181,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
     181,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,   181,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,   179,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
     179,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,   179,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,   179,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,   179,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,   179,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
     179,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,   179,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,   179,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,   179,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,   179,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
     179,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,   179,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,   179,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,   179,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,   179,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,   179,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   189,   190,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    52,    54,    58,    59,    61,    62,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   109,
     110,   111,   117,   122,   123,   124,   125,   128,   130,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     146,   147,   148,   149,   191,   193,   194,   214,   231,   232,
     235,   236,   237,   238,   239,   240,   241,   261,   262,   263,
     264,   282,   283,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      51,    53,    55,    56,    57,    63,    64,   137,   143,   144,
     145,   150,   151,   152,   153,   154,   168,   169,   173,   178,
     180,   182,   183,   185,   187,   212,   265,   266,   278,   279,
     282,   283,    13,    71,   178,   178,     6,   185,     6,     6,
       6,   178,     6,     6,   180,   180,   178,   185,   178,   178,
       4,   178,   185,   178,   178,     4,   185,   178,   178,    75,
      71,    71,     6,   185,    65,    68,    71,    71,    71,    68,
      71,    73,    73,    65,    68,    71,    73,    68,    71,    73,
      68,    71,   178,    68,   128,   141,   142,   185,   168,   169,
     178,   185,   268,   269,   268,   185,    65,    68,    71,   185,
     268,     4,    65,    69,    81,    71,    73,    71,    68,     4,
     137,   185,     4,     6,    65,    68,    71,    68,    71,     4,
       4,     4,     4,     5,    36,    65,    68,    71,    73,    85,
     169,   178,   185,   232,   241,   265,   271,   272,   273,   283,
       4,   178,   178,   178,     4,   185,   275,     4,   178,   178,
       6,     6,   180,     4,     4,     5,   185,     5,   185,     4,
     265,     6,   178,   185,   178,   180,   187,     7,   155,   156,
     157,   158,   175,   176,   210,   211,     4,   180,   182,   178,
     180,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   178,   178,   178,   178,
     178,   178,   212,   212,     7,   178,   178,   178,   178,   178,
     265,   265,   265,   265,   181,   265,     4,   128,   129,     4,
     282,   283,     4,   232,   233,   234,   185,   185,     6,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   177,   185,     6,   180,   211,     6,   265,
       4,   278,   279,   283,   278,   265,   278,   281,   216,   219,
     265,   169,   265,   273,   274,   265,   265,   178,   265,   274,
     265,   265,   178,   274,   265,   265,   271,   178,   185,   274,
     272,   272,   272,   178,   178,   272,   272,   272,   178,   178,
     178,   178,   178,   178,   178,   178,   271,   265,     4,   271,
     275,   185,   185,   268,   268,   268,   265,   265,   168,   169,
     185,   185,   268,   185,   185,   185,   168,   169,   178,   234,
     268,   185,   178,   185,   178,   178,   178,   272,   272,   271,
     178,     4,     6,   180,   180,   234,     6,   185,   185,   185,
     272,   272,   180,   180,   180,   180,   182,   212,   180,     5,
     185,     5,     5,     5,    65,    68,    71,    73,   185,   265,
     273,   265,   186,   274,     8,   170,     6,     6,   265,   265,
     265,   182,   265,   185,   131,   265,   265,   265,     6,     6,
     234,     6,   234,   180,     6,   271,   271,   185,   181,   265,
     185,   279,   271,     6,   180,   265,     4,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   281,
     278,   281,   278,   278,   278,   278,   278,   281,   265,   279,
     265,   278,   278,   278,   283,   279,   179,     7,   210,   181,
       7,   210,   211,   182,     7,   180,   186,    65,    68,    71,
      73,   231,   265,   274,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   195,
     265,     6,   180,   182,   179,   184,   179,   184,   184,   179,
     184,   181,   184,   215,   181,   215,   179,   170,   184,   186,
     179,   179,   265,   179,   186,   179,   179,   265,   186,   179,
     179,     7,   265,   265,   186,     6,     6,     6,   265,   265,
       7,     7,   259,   259,   265,   225,   265,   279,   226,   265,
     279,   227,   265,   279,   228,   265,   279,   265,   265,   265,
       7,   185,   179,     6,   185,   234,   234,   184,   184,   184,
     268,   268,   233,   233,   184,   265,   265,   265,   265,   245,
     184,   234,   265,   265,   265,   265,   265,     7,   260,     6,
       7,   265,     6,   265,   265,   186,   274,   274,   274,     6,
       6,   265,   265,   265,   265,     4,   179,   181,   185,   213,
       4,   265,   185,   185,   185,   185,   274,   179,   186,   265,
     185,   265,   273,   179,   179,   179,   128,   184,   234,   185,
       8,   179,   181,   186,   186,   179,   184,   186,   274,   210,
     181,   265,     6,     6,   265,   181,   211,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   184,   213,
     213,   213,   213,   213,   213,   213,   184,   184,   184,   213,
     184,   213,   213,   179,   179,   184,   184,   184,   179,   267,
     280,     6,   184,   179,   184,   179,   179,   210,   271,   182,
     210,   211,   279,   265,     6,     4,     4,   185,   276,   181,
     185,   185,   185,   185,   186,   186,     8,     4,   118,   119,
     120,   121,   186,   198,   202,   205,   207,   208,   181,   265,
       4,     6,   165,   192,   274,     6,   274,   265,     6,   278,
       6,   283,     6,   278,     7,   265,   273,   131,     7,     7,
     179,     7,   131,     7,     7,   179,   131,     7,     7,   265,
     179,   186,   185,   179,   179,   265,   271,     4,   258,     6,
     179,   179,   179,   179,   179,   179,   179,   179,   271,   274,
     182,   234,   186,   186,   268,   265,   265,   186,   186,   265,
     268,   184,   184,   184,    88,    98,   106,   107,   108,   112,
     113,   114,   115,   255,   256,   268,   186,   242,   179,   186,
     179,   179,   179,   265,     6,   265,   179,   181,   181,   186,
     186,   186,   181,   181,   184,   181,   274,   181,   186,   274,
     274,   274,   274,   186,     8,   274,     7,     7,     7,   182,
     265,   186,   265,   265,     7,   182,   185,   271,     6,   186,
     271,   210,   211,   186,   181,   182,   211,   278,   265,   265,
     265,   265,   274,   278,   278,   278,   221,   223,   265,   278,
     265,     6,     4,   128,   129,   265,     6,     6,     6,     7,
     180,   275,   277,     6,   274,   274,   274,   274,   213,   265,
     199,   178,   178,   185,   209,     6,   211,   181,   165,   278,
     179,   179,   184,     7,   268,    71,    73,   271,   271,     7,
     271,    71,    73,   271,   271,     7,    73,   271,   271,     6,
       7,     7,   274,     7,     7,    88,   257,     6,     7,     7,
     131,     7,   131,     7,   131,     7,   131,     7,     7,     7,
       6,   186,     4,   186,   184,   184,   184,   186,   186,   268,
     268,   268,     4,     6,   185,     6,   178,     6,   116,     6,
     116,     6,   116,     6,   116,   186,   256,   184,   255,     7,
       6,     7,     7,     7,     6,   185,     6,     6,     6,    71,
     265,     6,     6,   265,   182,   186,   186,   186,   186,   186,
     265,   186,   271,   271,   271,     4,   184,     8,     8,   179,
       4,     4,   271,   186,   179,     6,   265,     6,     6,     4,
       6,   213,   213,   213,   213,   213,   184,   179,   179,   184,
     213,   222,   184,   213,   224,   179,   179,     6,     7,   210,
     211,   182,     7,     6,   275,   265,   184,   186,   186,   186,
     186,   186,   210,   178,   265,   265,   270,   271,   185,   182,
       6,     6,   192,     6,   265,   185,   265,   279,     6,   185,
     185,    81,   230,   230,   271,     6,   185,   185,     6,     6,
     271,   185,     6,     6,     5,   271,   186,   271,   271,     4,
       6,   271,   271,    48,   271,    48,   271,    48,   271,    48,
     271,   271,   271,     7,     6,     7,   265,   265,   265,   185,
     185,   184,   186,   184,   186,   184,   186,   180,   265,   271,
     265,     6,     6,     6,     6,   265,   268,   186,     5,   185,
     271,   185,   185,   185,   271,   274,   185,     6,   181,     4,
     213,     6,     6,   127,   265,   265,   265,     6,     6,     7,
     184,     6,   210,     6,   211,   278,     4,     4,   279,   265,
       6,     4,   276,     6,   181,   275,     6,     6,     6,     6,
     271,   196,   265,   184,   184,   184,   186,   197,   265,     4,
     278,   184,   265,   279,   265,   265,   268,     6,     6,     6,
     265,   265,     6,   265,     5,     6,   185,     6,   131,   229,
     265,     6,     6,   185,     6,   185,     6,   185,     6,   185,
       6,     4,     6,     6,   265,   265,   279,   186,   179,   184,
     186,   233,   233,   268,     6,   246,   268,     6,   247,   268,
       6,   248,   265,   186,   184,   179,   186,   184,     6,   169,
     268,     6,   270,   268,   268,     6,   186,   265,     6,   271,
     184,   186,     8,   186,   179,   185,   265,   279,   271,   271,
     179,   185,   271,   279,   185,   265,   279,     6,     6,     7,
       6,   182,     6,   179,   184,   265,   265,   271,   185,   184,
     186,     6,   265,   217,   218,   186,   186,   186,   186,   186,
       5,   270,    69,     6,   265,   265,   265,   265,   185,   185,
       6,     6,   185,   265,   186,   186,   184,   185,   184,   185,
     184,   185,   181,     6,   271,     7,   185,   265,   184,   186,
     184,   184,     6,   186,   126,   265,   265,   274,     6,     6,
     186,     6,   220,   265,   281,   275,   129,   200,   265,   184,
     184,   270,   265,     6,   184,   221,   223,     6,     6,     6,
       6,     6,     6,   186,   185,   184,   184,   184,   184,   270,
     274,   233,   184,   186,   265,   268,   255,   265,   268,   255,
     265,   268,   255,     6,   184,   186,   271,   234,   186,   268,
       6,   274,   268,   265,   186,   186,   186,     6,   184,   186,
       7,   186,     6,   185,   265,   265,   186,   265,   186,   186,
     185,   265,   265,   265,   265,   265,   186,   186,   186,   265,
     186,   184,   186,   186,   184,   186,   186,   184,   186,   271,
       6,    88,   186,   243,   185,   184,   186,   184,     6,     6,
     265,   279,   197,   179,   184,     6,   185,   184,   265,   186,
     184,   184,   184,   184,     6,     6,   186,     6,   249,   265,
       6,     6,   250,   265,     6,     6,   251,   265,     6,   186,
     265,   255,   234,   274,     6,   268,   274,     7,   186,   203,
     265,   270,   265,   184,   265,   265,   265,   265,   185,   186,
     185,   186,   185,   186,     6,     6,   186,   186,   244,   186,
     184,   186,   279,     6,   185,   179,   186,   186,   265,   184,
     184,   184,   184,   255,     6,   252,   255,     6,   253,   255,
       6,   254,   255,     6,   274,     6,   201,   278,   206,   185,
       6,   186,   265,   265,   265,   265,   186,   185,   186,   185,
     186,   185,   186,   186,   184,   186,   185,   270,     6,   184,
     184,   184,   184,     6,   255,     6,   255,     6,   255,     6,
     278,     6,   204,   278,   186,   265,   265,   265,   265,   186,
     186,   186,   184,   186,     6,   184,   184,   184,   184,     6,
       6,     6,   278,     6,   265,   265,   265,   265,   186,   186,
     186,   186,     6,     6,     6,     6
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
#line 1389 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (21)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
        GModel::current()->importGEOInternals();
        SBoundingBox3d bbox((yyvsp[(9) - (21)].d), (yyvsp[(11) - (21)].d), (yyvsp[(13) - (21)].d), (yyvsp[(15) - (21)].d), (yyvsp[(17) - (21)].d), (yyvsp[(19) - (21)].d));
        GModel::current()->setPhysicalNumToEntitiesInBox(0, num, bbox);
      }
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1403 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v)
	  v->lc = (yyvsp[(5) - (6)].d);
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

  case 141:
/* Line 1787 of yacc.c  */
#line 1425 "Gmsh.y"
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

  case 142:
/* Line 1787 of yacc.c  */
#line 1443 "Gmsh.y"
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

  case 143:
/* Line 1787 of yacc.c  */
#line 1464 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1482 "Gmsh.y"
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

  case 145:
/* Line 1787 of yacc.c  */
#line 1512 "Gmsh.y"
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

  case 146:
/* Line 1787 of yacc.c  */
#line 1542 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1560 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1579 "Gmsh.y"
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

  case 149:
/* Line 1787 of yacc.c  */
#line 1605 "Gmsh.y"
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

  case 150:
/* Line 1787 of yacc.c  */
#line 1623 "Gmsh.y"
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

  case 151:
/* Line 1787 of yacc.c  */
#line 1641 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1658 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (21)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
        GModel::current()->importGEOInternals();
        SBoundingBox3d bbox((yyvsp[(9) - (21)].d), (yyvsp[(11) - (21)].d), (yyvsp[(13) - (21)].d), (yyvsp[(15) - (21)].d), (yyvsp[(17) - (21)].d), (yyvsp[(19) - (21)].d));
        GModel::current()->setPhysicalNumToEntitiesInBox(1, num, bbox);
      }
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1675 "Gmsh.y"
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

  case 154:
/* Line 1787 of yacc.c  */
#line 1693 "Gmsh.y"
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

  case 155:
/* Line 1787 of yacc.c  */
#line 1732 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1738 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1744 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1751 "Gmsh.y"
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

  case 159:
/* Line 1787 of yacc.c  */
#line 1776 "Gmsh.y"
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

  case 160:
/* Line 1787 of yacc.c  */
#line 1801 "Gmsh.y"
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

  case 161:
/* Line 1787 of yacc.c  */
#line 1818 "Gmsh.y"
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

  case 162:
/* Line 1787 of yacc.c  */
#line 1838 "Gmsh.y"
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1871 "Gmsh.y"
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

  case 164:
/* Line 1787 of yacc.c  */
#line 1888 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (21)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
        GModel::current()->importGEOInternals();
        SBoundingBox3d bbox((yyvsp[(9) - (21)].d), (yyvsp[(11) - (21)].d), (yyvsp[(13) - (21)].d), (yyvsp[(15) - (21)].d), (yyvsp[(17) - (21)].d), (yyvsp[(19) - (21)].d));
        GModel::current()->setPhysicalNumToEntitiesInBox(2, num, bbox);
      }
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1906 "Gmsh.y"
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
#line 1924 "Gmsh.y"
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
#line 1941 "Gmsh.y"
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
#line 1957 "Gmsh.y"
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

  case 169:
/* Line 1787 of yacc.c  */
#line 1974 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (21)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
        GModel::current()->importGEOInternals();
        SBoundingBox3d bbox((yyvsp[(9) - (21)].d), (yyvsp[(11) - (21)].d), (yyvsp[(13) - (21)].d), (yyvsp[(15) - (21)].d), (yyvsp[(17) - (21)].d), (yyvsp[(19) - (21)].d));
        GModel::current()->setPhysicalNumToEntitiesInBox(3, num, bbox);
      }
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1994 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1999 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 2004 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 2009 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 2014 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 2019 "Gmsh.y"
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

  case 176:
/* Line 1787 of yacc.c  */
#line 2042 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2048 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2058 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2059 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2064 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2068 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 2072 "Gmsh.y"
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

  case 183:
/* Line 1787 of yacc.c  */
#line 2095 "Gmsh.y"
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

  case 184:
/* Line 1787 of yacc.c  */
#line 2118 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2141 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2169 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2190 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2217 "Gmsh.y"
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

  case 189:
/* Line 1787 of yacc.c  */
#line 2238 "Gmsh.y"
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

  case 190:
/* Line 1787 of yacc.c  */
#line 2259 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2279 "Gmsh.y"
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

  case 192:
/* Line 1787 of yacc.c  */
#line 2391 "Gmsh.y"
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

  case 193:
/* Line 1787 of yacc.c  */
#line 2410 "Gmsh.y"
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

  case 194:
/* Line 1787 of yacc.c  */
#line 2449 "Gmsh.y"
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

  case 195:
/* Line 1787 of yacc.c  */
#line 2557 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 2566 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 2572 "Gmsh.y"
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

  case 198:
/* Line 1787 of yacc.c  */
#line 2587 "Gmsh.y"
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

  case 199:
/* Line 1787 of yacc.c  */
#line 2615 "Gmsh.y"
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

  case 200:
/* Line 1787 of yacc.c  */
#line 2632 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2641 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2655 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2661 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2667 "Gmsh.y"
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
#line 2676 "Gmsh.y"
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
#line 2685 "Gmsh.y"
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
#line 2694 "Gmsh.y"
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
#line 2708 "Gmsh.y"
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
#line 2764 "Gmsh.y"
    {
      int n = List_Nbr((yyvsp[(3) - (5)].l));
      if(n != 1 && n != 2){
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      else{
        char *s0;
        List_Read((yyvsp[(3) - (5)].l), 0, &s0);
        if(n == 2){
          char *s1;
          List_Read((yyvsp[(3) - (5)].l), 1, &s1);
          Msg::RunOnelabClient(s0, s1);
        }
        else{
          Msg::RunOnelabClient(s0);
        }
      }
      for(int i = 0; i < n; i++){
        char *s;
        List_Read((yyvsp[(3) - (5)].l), i, &s);
        Free(s);
      }
      List_Delete((yyvsp[(3) - (5)].l));
    }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 2789 "Gmsh.y"
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
#line 2806 "Gmsh.y"
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
#line 2821 "Gmsh.y"
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
#line 2840 "Gmsh.y"
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
#line 2852 "Gmsh.y"
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
#line 2876 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2880 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2885 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2892 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2898 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2903 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2909 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2917 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2921 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2925 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 2931 "Gmsh.y"
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

  case 226:
/* Line 1787 of yacc.c  */
#line 2985 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 2998 "Gmsh.y"
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

  case 228:
/* Line 1787 of yacc.c  */
#line 3015 "Gmsh.y"
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

  case 229:
/* Line 1787 of yacc.c  */
#line 3032 "Gmsh.y"
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

  case 230:
/* Line 1787 of yacc.c  */
#line 3053 "Gmsh.y"
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

  case 231:
/* Line 1787 of yacc.c  */
#line 3074 "Gmsh.y"
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

  case 232:
/* Line 1787 of yacc.c  */
#line 3109 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3117 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3123 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3130 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3134 "Gmsh.y"
    {
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3143 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3151 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3159 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3167 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3173 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3181 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3195 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3201 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3209 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3215 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3237 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3244 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3258 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3265 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3272 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3279 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3286 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3292 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3299 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3305 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3312 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3318 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3325 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3338 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3344 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3351 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3357 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3364 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3370 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3377 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3383 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3390 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3396 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3407 "Gmsh.y"
    {
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3410 "Gmsh.y"
    {
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3416 "Gmsh.y"
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

  case 278:
/* Line 1787 of yacc.c  */
#line 3428 "Gmsh.y"
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

  case 279:
/* Line 1787 of yacc.c  */
#line 3448 "Gmsh.y"
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

  case 280:
/* Line 1787 of yacc.c  */
#line 3472 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3476 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3480 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3484 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3488 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3494 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3500 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3504 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3508 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3512 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3516 "Gmsh.y"
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

  case 291:
/* Line 1787 of yacc.c  */
#line 3535 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3547 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3551 "Gmsh.y"
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

  case 294:
/* Line 1787 of yacc.c  */
#line 3566 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3570 "Gmsh.y"
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

  case 296:
/* Line 1787 of yacc.c  */
#line 3586 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3590 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3595 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3599 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 3606 "Gmsh.y"
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

  case 301:
/* Line 1787 of yacc.c  */
#line 3662 "Gmsh.y"
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

  case 302:
/* Line 1787 of yacc.c  */
#line 3732 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 3737 "Gmsh.y"
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

  case 304:
/* Line 1787 of yacc.c  */
#line 3804 "Gmsh.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3840 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3848 "Gmsh.y"
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

  case 307:
/* Line 1787 of yacc.c  */
#line 3891 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3930 "Gmsh.y"
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

  case 309:
/* Line 1787 of yacc.c  */
#line 3950 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3978 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4017 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 4045 "Gmsh.y"
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

  case 313:
/* Line 1787 of yacc.c  */
#line 4073 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 4077 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 4081 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4109 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4148 "Gmsh.y"
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

  case 318:
/* Line 1787 of yacc.c  */
#line 4187 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4208 "Gmsh.y"
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

  case 320:
/* Line 1787 of yacc.c  */
#line 4229 "Gmsh.y"
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

  case 321:
/* Line 1787 of yacc.c  */
#line 4256 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 4260 "Gmsh.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 4270 "Gmsh.y"
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

  case 324:
/* Line 1787 of yacc.c  */
#line 4304 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4305 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4306 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4311 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4317 "Gmsh.y"
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

  case 329:
/* Line 1787 of yacc.c  */
#line 4329 "Gmsh.y"
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

  case 330:
/* Line 1787 of yacc.c  */
#line 4347 "Gmsh.y"
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

  case 331:
/* Line 1787 of yacc.c  */
#line 4374 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4375 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4376 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4377 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4378 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4379 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4380 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4381 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4383 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4389 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4390 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4391 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4392 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4393 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4394 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4395 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4396 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4397 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4398 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4399 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4400 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4401 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4402 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4403 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4404 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4405 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4406 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4407 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4408 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4409 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4410 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4411 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4412 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4413 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4414 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4415 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4416 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4417 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4418 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4419 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4420 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4421 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4430 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4431 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4432 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4433 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4434 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4435 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4436 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4437 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4438 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4444 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4446 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4452 "Gmsh.y"
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

  case 386:
/* Line 1787 of yacc.c  */
#line 4469 "Gmsh.y"
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
#line 4487 "Gmsh.y"
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

  case 388:
/* Line 1787 of yacc.c  */
#line 4505 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4510 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 4516 "Gmsh.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 4528 "Gmsh.y"
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

  case 392:
/* Line 1787 of yacc.c  */
#line 4545 "Gmsh.y"
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
#line 4563 "Gmsh.y"
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

  case 394:
/* Line 1787 of yacc.c  */
#line 4584 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4589 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 4594 "Gmsh.y"
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

  case 397:
/* Line 1787 of yacc.c  */
#line 4604 "Gmsh.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 4614 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4619 "Gmsh.y"
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
#line 4628 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4633 "Gmsh.y"
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
#line 4660 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4664 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4668 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4672 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4676 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4683 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4687 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4691 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4695 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4702 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4707 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4714 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4719 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4723 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4728 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4732 "Gmsh.y"
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
#line 4740 "Gmsh.y"
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
#line 4751 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4755 "Gmsh.y"
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
#line 4767 "Gmsh.y"
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
#line 4775 "Gmsh.y"
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
#line 4783 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4790 "Gmsh.y"
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
#line 4800 "Gmsh.y"
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
#line 4829 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4833 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4837 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4841 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4845 "Gmsh.y"
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

  case 431:
/* Line 1787 of yacc.c  */
#line 4874 "Gmsh.y"
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

  case 432:
/* Line 1787 of yacc.c  */
#line 4903 "Gmsh.y"
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

  case 433:
/* Line 1787 of yacc.c  */
#line 4932 "Gmsh.y"
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

  case 434:
/* Line 1787 of yacc.c  */
#line 4961 "Gmsh.y"
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
#line 4971 "Gmsh.y"
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
#line 4981 "Gmsh.y"
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
#line 4993 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 5005 "Gmsh.y"
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

  case 439:
/* Line 1787 of yacc.c  */
#line 5026 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 5031 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 5035 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 5039 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 5051 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 5055 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 5067 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5074 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 5084 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5088 "Gmsh.y"
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

  case 449:
/* Line 1787 of yacc.c  */
#line 5103 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5108 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5115 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5119 "Gmsh.y"
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

  case 453:
/* Line 1787 of yacc.c  */
#line 5132 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5140 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5151 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5155 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5163 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5169 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5177 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5185 "Gmsh.y"
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

  case 461:
/* Line 1787 of yacc.c  */
#line 5200 "Gmsh.y"
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

  case 462:
/* Line 1787 of yacc.c  */
#line 5214 "Gmsh.y"
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

  case 463:
/* Line 1787 of yacc.c  */
#line 5228 "Gmsh.y"
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

  case 464:
/* Line 1787 of yacc.c  */
#line 5240 "Gmsh.y"
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

  case 465:
/* Line 1787 of yacc.c  */
#line 5256 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5260 "Gmsh.y"
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

  case 467:
/* Line 1787 of yacc.c  */
#line 5279 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5281 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5292 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5297 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5303 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5312 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5325 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5328 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11129 "Gmsh.tab.cpp"
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
#line 5332 "Gmsh.y"


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
  else
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);

}
