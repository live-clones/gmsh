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
static int curPhysDim = 0;
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
#line 174 "Gmsh.tab.cpp"

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
#line 100 "Gmsh.y"

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
#define YYLAST   8086

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  188
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1616

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
     268,   274,   279,   286,   294,   302,   310,   320,   330,   334,
     341,   348,   353,   360,   370,   377,   387,   393,   402,   411,
     423,   430,   440,   446,   454,   464,   474,   486,   494,   504,
     514,   515,   517,   518,   522,   528,   529,   539,   545,   546,
     556,   557,   561,   565,   571,   572,   575,   579,   585,   589,
     590,   593,   597,   601,   607,   609,   611,   612,   618,   619,
     622,   630,   631,   641,   648,   656,   661,   669,   678,   687,
     695,   703,   715,   724,   733,   734,   744,   753,   763,   767,
     772,   783,   791,   799,   808,   817,   830,   831,   841,   850,
     858,   867,   868,   878,   884,   896,   902,   912,   922,   927,
     937,   947,   949,   951,   952,   955,   962,   969,   976,   983,
     992,  1003,  1018,  1035,  1048,  1057,  1066,  1073,  1088,  1093,
    1100,  1107,  1111,  1116,  1122,  1129,  1133,  1137,  1142,  1148,
    1153,  1159,  1163,  1169,  1177,  1185,  1189,  1197,  1201,  1204,
    1207,  1210,  1213,  1229,  1232,  1235,  1238,  1241,  1244,  1261,
    1265,  1272,  1281,  1290,  1301,  1303,  1306,  1308,  1312,  1317,
    1319,  1325,  1337,  1351,  1352,  1360,  1361,  1375,  1376,  1392,
    1393,  1400,  1409,  1418,  1427,  1440,  1453,  1466,  1481,  1496,
    1511,  1512,  1525,  1526,  1539,  1540,  1553,  1554,  1571,  1572,
    1589,  1590,  1607,  1608,  1627,  1628,  1647,  1648,  1667,  1669,
    1672,  1678,  1686,  1696,  1699,  1702,  1705,  1709,  1712,  1716,
    1719,  1723,  1726,  1730,  1740,  1747,  1748,  1752,  1753,  1755,
    1756,  1759,  1760,  1763,  1771,  1778,  1787,  1793,  1797,  1805,
    1811,  1816,  1823,  1830,  1843,  1854,  1865,  1876,  1887,  1898,
    1903,  1908,  1913,  1918,  1923,  1926,  1930,  1937,  1939,  1941,
    1943,  1946,  1952,  1960,  1971,  1973,  1977,  1980,  1983,  1986,
    1990,  1994,  1998,  2002,  2006,  2010,  2014,  2018,  2022,  2026,
    2030,  2034,  2038,  2042,  2048,  2053,  2058,  2063,  2068,  2073,
    2078,  2083,  2088,  2093,  2098,  2105,  2110,  2115,  2120,  2125,
    2130,  2135,  2140,  2147,  2154,  2161,  2166,  2168,  2170,  2172,
    2174,  2176,  2178,  2180,  2182,  2184,  2186,  2187,  2194,  2196,
    2201,  2206,  2211,  2216,  2221,  2224,  2230,  2236,  2240,  2247,
    2252,  2260,  2267,  2274,  2281,  2286,  2288,  2291,  2294,  2298,
    2302,  2314,  2324,  2332,  2340,  2342,  2346,  2348,  2350,  2353,
    2357,  2362,  2368,  2370,  2372,  2375,  2379,  2383,  2389,  2394,
    2397,  2400,  2403,  2406,  2412,  2418,  2424,  2430,  2432,  2434,
    2438,  2443,  2450,  2452,  2454,  2458,  2462,  2472,  2480,  2482,
    2488,  2492,  2499,  2501,  2505,  2507,  2509,  2513,  2520,  2522,
    2524,  2526,  2531,  2538,  2543,  2548,  2553,  2562,  2567,  2572,
    2579,  2580,  2587,  2589,  2593,  2599,  2605,  2607
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     189,     0,    -1,   190,    -1,     1,     6,    -1,    -1,   190,
     191,    -1,   194,    -1,   193,    -1,   214,    -1,   228,    -1,
     233,    -1,   237,    -1,   238,    -1,   239,    -1,   242,    -1,
     262,    -1,   263,    -1,   241,    -1,   240,    -1,   236,    -1,
     265,    -1,   165,    -1,   165,   165,    -1,    37,   178,   279,
     179,     6,    -1,    38,   178,   279,   179,     6,    -1,    37,
     178,   279,   179,   192,   279,     6,    -1,    37,   178,   279,
     184,   275,   179,     6,    -1,    38,   178,   279,   184,   275,
     179,     6,    -1,    37,   178,   279,   184,   275,   179,   192,
     279,     6,    -1,     4,   279,   185,   195,   186,     6,    -1,
     109,     4,   180,   266,   181,     6,    -1,   110,     4,   180,
     266,   181,     6,    -1,   111,     4,   180,   266,   184,   266,
     181,     6,    -1,    -1,   195,   198,    -1,   195,   202,    -1,
     195,   205,    -1,   195,   207,    -1,   195,   208,    -1,   266,
      -1,   196,   184,   266,    -1,   266,    -1,   197,   184,   266,
      -1,    -1,    -1,     4,   199,   178,   196,   179,   200,   185,
     197,   186,     6,    -1,   279,    -1,   201,   184,   279,    -1,
      -1,   118,   178,   266,   184,   266,   184,   266,   179,   203,
     185,   201,   186,     6,    -1,   279,    -1,   204,   184,   279,
      -1,    -1,   119,   178,   266,   184,   266,   184,   266,   184,
     266,   179,   206,   185,   204,   186,     6,    -1,   120,   185,
     271,   186,   185,   271,   186,     6,    -1,   120,   185,   271,
     186,   185,   271,   186,   185,   271,   186,   185,   271,   186,
       6,    -1,    -1,   121,   209,   185,   197,   186,     6,    -1,
       7,    -1,   158,    -1,   157,    -1,   156,    -1,   155,    -1,
     176,    -1,   175,    -1,   178,    -1,   180,    -1,   179,    -1,
     181,    -1,    61,   180,   216,   181,     6,    -1,    62,   180,
     219,   181,     6,    -1,   284,   210,   272,     6,    -1,     4,
     180,   181,   210,   272,     6,    -1,     4,   180,   266,   181,
     210,   266,     6,    -1,     4,   178,   266,   179,   210,   266,
       6,    -1,   283,   180,   266,   181,   210,   266,     6,    -1,
       4,   212,   185,   275,   186,   213,   210,   272,     6,    -1,
     283,   178,   185,   275,   186,   179,   210,   272,     6,    -1,
     284,   211,     6,    -1,     4,   180,   266,   181,   211,     6,
      -1,   283,   180,   266,   181,   211,     6,    -1,   284,     7,
     280,     6,    -1,     4,   182,     4,     7,   280,     6,    -1,
       4,   180,   266,   181,   182,     4,     7,   280,     6,    -1,
       4,   182,     4,   210,   266,     6,    -1,     4,   180,   266,
     181,   182,     4,   210,   266,     6,    -1,     4,   182,     4,
     211,     6,    -1,     4,   180,   266,   181,   182,     4,   211,
       6,    -1,     4,   182,   128,   182,     4,     7,   276,     6,
      -1,     4,   180,   266,   181,   182,   128,   182,     4,     7,
     276,     6,    -1,     4,   182,   129,     7,   277,     6,    -1,
       4,   180,   266,   181,   182,   129,     7,   277,     6,    -1,
       4,   137,     7,   266,     6,    -1,   137,   180,   266,   181,
       7,     4,     6,    -1,   137,   180,   266,   181,   182,     4,
       7,   266,     6,    -1,   137,   180,   266,   181,   182,     4,
       7,   280,     6,    -1,   137,   180,   266,   181,   182,     4,
       7,   185,   275,   186,     6,    -1,   137,   180,   266,   181,
     182,     4,     6,    -1,    89,   178,     4,   179,   182,     4,
       7,   266,     6,    -1,    89,   178,     4,   179,   182,     4,
       7,   280,     6,    -1,    -1,   184,    -1,    -1,   216,   215,
     284,    -1,   216,   215,   284,     7,   266,    -1,    -1,   216,
     215,   284,     7,   185,   266,   217,   221,   186,    -1,   216,
     215,   284,     7,   280,    -1,    -1,   216,   215,   284,     7,
     185,   280,   218,   223,   186,    -1,    -1,   219,   215,   279,
      -1,   266,     7,   280,    -1,   220,   184,   266,     7,   280,
      -1,    -1,   221,   222,    -1,   184,     4,   272,    -1,   184,
       4,   185,   220,   186,    -1,   184,     4,   280,    -1,    -1,
     223,   224,    -1,   184,     4,   266,    -1,   184,     4,   280,
      -1,   184,     4,   185,   282,   186,    -1,   266,    -1,   280,
      -1,    -1,   131,    69,   185,   266,   186,    -1,    -1,    81,
     269,    -1,    65,   178,   266,   179,     7,   269,     6,    -1,
      -1,    85,    65,   229,   178,   225,   179,     7,   272,     6,
      -1,    74,    75,   272,     7,   266,     6,    -1,    68,   178,
     266,   179,     7,   272,     6,    -1,    90,    68,   272,     6,
      -1,    72,   178,   266,   179,     7,   272,     6,    -1,    66,
     178,   266,   179,     7,   272,   227,     6,    -1,    67,   178,
     266,   179,     7,   272,   227,     6,    -1,   123,   178,   266,
     179,     7,   272,     6,    -1,   124,   178,   266,   179,     7,
     272,     6,    -1,   125,   178,   266,   179,     7,   272,   127,
     272,   126,   266,     6,    -1,    68,     4,   178,   266,   179,
       7,   272,     6,    -1,    86,    68,   178,   266,   179,     7,
     272,     6,    -1,    -1,    85,    68,   230,   178,   225,   179,
       7,   272,     6,    -1,    81,    71,   178,   266,   179,     7,
     272,     6,    -1,    82,    71,   178,   266,   179,     7,   272,
     226,     6,    -1,    12,    13,     6,    -1,    13,    71,   266,
       6,    -1,    76,    71,   178,   266,   179,     7,     5,     5,
       5,     6,    -1,    69,   178,   266,   179,     7,   272,     6,
      -1,    70,   178,   266,   179,     7,   272,     6,    -1,    71,
       4,   178,   266,   179,     7,   272,     6,    -1,    86,    71,
     178,   266,   179,     7,   272,     6,    -1,    86,    71,   178,
     266,   179,     7,   272,     4,   185,   271,   186,     6,    -1,
      -1,    85,    71,   231,   178,   225,   179,     7,   272,     6,
      -1,    84,    73,   178,   266,   179,     7,   272,     6,    -1,
      73,   178,   266,   179,     7,   272,     6,    -1,    86,    73,
     178,   266,   179,     7,   272,     6,    -1,    -1,    85,    73,
     232,   178,   225,   179,     7,   272,     6,    -1,    93,   269,
     185,   234,   186,    -1,    92,   185,   269,   184,   269,   184,
     266,   186,   185,   234,   186,    -1,    94,   269,   185,   234,
     186,    -1,    95,   185,   269,   184,   266,   186,   185,   234,
     186,    -1,    95,   185,   269,   184,   269,   186,   185,   234,
     186,    -1,     4,   185,   234,   186,    -1,   103,    68,   185,
     275,   186,    71,   185,   266,   186,    -1,   100,    68,   178,
     266,   179,   185,   275,   186,     6,    -1,   235,    -1,   233,
      -1,    -1,   235,   228,    -1,   235,    65,   185,   275,   186,
       6,    -1,   235,    68,   185,   275,   186,     6,    -1,   235,
      71,   185,   275,   186,     6,    -1,   235,    73,   185,   275,
     186,     6,    -1,    97,    81,   178,   266,   179,     7,   272,
       6,    -1,    97,    65,   178,   266,   179,     7,   185,   271,
     186,     6,    -1,    97,    81,   178,   266,   179,     7,   185,
     269,   184,   269,   184,   275,   186,     6,    -1,    97,    81,
     178,   266,   179,     7,   185,   269,   184,   269,   184,   269,
     184,   275,   186,     6,    -1,    97,    69,   178,   266,   179,
       7,   185,   269,   184,   275,   186,     6,    -1,    97,     4,
     178,   266,   179,     7,   272,     6,    -1,    97,     4,   178,
     266,   179,     7,     5,     6,    -1,    97,     4,   185,   266,
     186,     6,    -1,    97,     4,   178,   266,   179,     7,   185,
     269,   184,   269,   184,   275,   186,     6,    -1,   101,   185,
     235,   186,    -1,   101,   137,   180,   266,   181,     6,    -1,
     101,     4,   180,   266,   181,     6,    -1,   101,     4,     6,
      -1,   101,     4,     4,     6,    -1,   128,   276,   185,   235,
     186,    -1,    91,   128,   276,   185,   235,   186,    -1,   141,
       5,     6,    -1,   142,     5,     6,    -1,   141,   185,   235,
     186,    -1,    91,   141,   185,   235,   186,    -1,   142,   185,
     235,   186,    -1,    91,   142,   185,   235,   186,    -1,     4,
     280,     6,    -1,    54,   178,   282,   179,     6,    -1,     4,
       4,   180,   266,   181,   279,     6,    -1,     4,     4,     4,
     180,   266,   181,     6,    -1,     4,   266,     6,    -1,    89,
     178,     4,   179,   182,     4,     6,    -1,   122,     4,     6,
      -1,   135,     6,    -1,   136,     6,    -1,    52,     6,    -1,
      48,     6,    -1,    48,   185,   266,   184,   266,   184,   266,
     184,   266,   184,   266,   184,   266,   186,     6,    -1,    49,
       6,    -1,    50,     6,    -1,    58,     6,    -1,    59,     6,
      -1,    78,     6,    -1,    79,   185,   275,   186,   185,   275,
     186,   185,   271,   186,   185,   266,   184,   266,   186,     6,
      -1,   149,   266,     6,    -1,   130,   178,   266,     8,   266,
     179,    -1,   130,   178,   266,     8,   266,     8,   266,   179,
      -1,   130,     4,   131,   185,   266,     8,   266,   186,    -1,
     130,     4,   131,   185,   266,     8,   266,     8,   266,   186,
      -1,   132,    -1,   140,     4,    -1,   138,    -1,   139,     4,
       6,    -1,   133,   178,   266,   179,    -1,   134,    -1,    96,
     269,   185,   235,   186,    -1,    96,   185,   269,   184,   269,
     184,   266,   186,   185,   235,   186,    -1,    96,   185,   269,
     184,   269,   184,   269,   184,   266,   186,   185,   235,   186,
      -1,    -1,    96,   269,   185,   235,   243,   256,   186,    -1,
      -1,    96,   185,   269,   184,   269,   184,   266,   186,   185,
     235,   244,   256,   186,    -1,    -1,    96,   185,   269,   184,
     269,   184,   269,   184,   266,   186,   185,   235,   245,   256,
     186,    -1,    -1,    96,   185,   235,   246,   256,   186,    -1,
      96,    65,   185,   266,   184,   269,   186,     6,    -1,    96,
      68,   185,   266,   184,   269,   186,     6,    -1,    96,    71,
     185,   266,   184,   269,   186,     6,    -1,    96,    65,   185,
     266,   184,   269,   184,   269,   184,   266,   186,     6,    -1,
      96,    68,   185,   266,   184,   269,   184,   269,   184,   266,
     186,     6,    -1,    96,    71,   185,   266,   184,   269,   184,
     269,   184,   266,   186,     6,    -1,    96,    65,   185,   266,
     184,   269,   184,   269,   184,   269,   184,   266,   186,     6,
      -1,    96,    68,   185,   266,   184,   269,   184,   269,   184,
     269,   184,   266,   186,     6,    -1,    96,    71,   185,   266,
     184,   269,   184,   269,   184,   269,   184,   266,   186,     6,
      -1,    -1,    96,    65,   185,   266,   184,   269,   186,   247,
     185,   256,   186,     6,    -1,    -1,    96,    68,   185,   266,
     184,   269,   186,   248,   185,   256,   186,     6,    -1,    -1,
      96,    71,   185,   266,   184,   269,   186,   249,   185,   256,
     186,     6,    -1,    -1,    96,    65,   185,   266,   184,   269,
     184,   269,   184,   266,   186,   250,   185,   256,   186,     6,
      -1,    -1,    96,    68,   185,   266,   184,   269,   184,   269,
     184,   266,   186,   251,   185,   256,   186,     6,    -1,    -1,
      96,    71,   185,   266,   184,   269,   184,   269,   184,   266,
     186,   252,   185,   256,   186,     6,    -1,    -1,    96,    65,
     185,   266,   184,   269,   184,   269,   184,   269,   184,   266,
     186,   253,   185,   256,   186,     6,    -1,    -1,    96,    68,
     185,   266,   184,   269,   184,   269,   184,   269,   184,   266,
     186,   254,   185,   256,   186,     6,    -1,    -1,    96,    71,
     185,   266,   184,   269,   184,   269,   184,   269,   184,   266,
     186,   255,   185,   256,   186,     6,    -1,   257,    -1,   256,
     257,    -1,   106,   185,   266,   186,     6,    -1,   106,   185,
     272,   184,   272,   186,     6,    -1,   106,   185,   272,   184,
     272,   184,   272,   186,     6,    -1,   107,     6,    -1,    98,
       6,    -1,   114,     6,    -1,   114,   116,     6,    -1,   115,
       6,    -1,   115,   116,     6,    -1,   112,     6,    -1,   112,
     116,     6,    -1,   113,     6,    -1,   113,   116,     6,    -1,
     108,   178,   266,   179,     7,   272,    88,   266,     6,    -1,
      88,     4,   180,   266,   181,     6,    -1,    -1,    88,     4,
     266,    -1,    -1,     4,    -1,    -1,     7,   272,    -1,    -1,
       7,   266,    -1,    83,    68,   273,     7,   266,   258,     6,
      -1,    83,    71,   273,   260,   259,     6,    -1,    77,    71,
     185,   266,   186,     7,   272,     6,    -1,    83,    73,   273,
     260,     6,    -1,   117,   273,     6,    -1,   104,    71,   185,
     275,   186,   266,     6,    -1,    98,    71,   273,   261,     6,
      -1,    98,    73,   273,     6,    -1,    99,    71,   272,     7,
     266,     6,    -1,    87,    68,   272,     7,   272,     6,    -1,
      87,    71,   266,   185,   275,   186,     7,   266,   185,   275,
     186,     6,    -1,    65,   185,   275,   186,   131,    71,   185,
     266,   186,     6,    -1,    68,   185,   275,   186,   131,    71,
     185,   266,   186,     6,    -1,    65,   185,   275,   186,   131,
      73,   185,   266,   186,     6,    -1,    68,   185,   275,   186,
     131,    73,   185,   266,   186,     6,    -1,    71,   185,   275,
     186,   131,    73,   185,   266,   186,     6,    -1,   105,    71,
     273,     6,    -1,   105,    68,   273,     6,    -1,    80,    65,
     273,     6,    -1,    80,    68,   273,     6,    -1,    80,    71,
     273,     6,    -1,   102,     6,    -1,   102,     4,     6,    -1,
     102,    65,   185,   275,   186,     6,    -1,   146,    -1,   147,
      -1,   148,    -1,   264,     6,    -1,   264,   185,   272,   186,
       6,    -1,   264,   185,   272,   184,   272,   186,     6,    -1,
     264,   178,   272,   179,   185,   272,   184,   272,   186,     6,
      -1,   267,    -1,   178,   266,   179,    -1,   169,   266,    -1,
     168,   266,    -1,   173,   266,    -1,   266,   169,   266,    -1,
     266,   168,   266,    -1,   266,   170,   266,    -1,   266,   171,
     266,    -1,   266,   172,   266,    -1,   266,   177,   266,    -1,
     266,   164,   266,    -1,   266,   165,   266,    -1,   266,   167,
     266,    -1,   266,   166,   266,    -1,   266,   163,   266,    -1,
     266,   162,   266,    -1,   266,   161,   266,    -1,   266,   160,
     266,    -1,   266,   159,   266,     8,   266,    -1,    14,   212,
     266,   213,    -1,    15,   212,   266,   213,    -1,    16,   212,
     266,   213,    -1,    17,   212,   266,   213,    -1,    18,   212,
     266,   213,    -1,    19,   212,   266,   213,    -1,    20,   212,
     266,   213,    -1,    21,   212,   266,   213,    -1,    22,   212,
     266,   213,    -1,    24,   212,   266,   213,    -1,    25,   212,
     266,   184,   266,   213,    -1,    26,   212,   266,   213,    -1,
      27,   212,   266,   213,    -1,    28,   212,   266,   213,    -1,
      29,   212,   266,   213,    -1,    30,   212,   266,   213,    -1,
      31,   212,   266,   213,    -1,    32,   212,   266,   213,    -1,
      33,   212,   266,   184,   266,   213,    -1,    34,   212,   266,
     184,   266,   213,    -1,    35,   212,   266,   184,   266,   213,
      -1,    23,   212,   266,   213,    -1,     3,    -1,     9,    -1,
      10,    -1,    11,    -1,   152,    -1,   153,    -1,   154,    -1,
      55,    -1,    56,    -1,    57,    -1,    -1,    63,   212,   266,
     268,   221,   213,    -1,   284,    -1,     4,   180,   266,   181,
      -1,   283,   180,   266,   181,    -1,   150,   178,   284,   179,
      -1,   151,   178,   280,   179,    -1,   183,   284,   180,   181,
      -1,   284,   211,    -1,     4,   180,   266,   181,   211,    -1,
     283,   180,   266,   181,   211,    -1,     4,   182,     4,    -1,
       4,   180,   266,   181,   182,     4,    -1,     4,   182,     4,
     211,    -1,     4,   180,   266,   181,   182,     4,   211,    -1,
     143,   178,   279,   184,   266,   179,    -1,    45,   178,   279,
     184,   279,   179,    -1,    46,   178,   279,   184,   279,   179,
      -1,    47,   178,   282,   179,    -1,   270,    -1,   169,   269,
      -1,   168,   269,    -1,   269,   169,   269,    -1,   269,   168,
     269,    -1,   185,   266,   184,   266,   184,   266,   184,   266,
     184,   266,   186,    -1,   185,   266,   184,   266,   184,   266,
     184,   266,   186,    -1,   185,   266,   184,   266,   184,   266,
     186,    -1,   178,   266,   184,   266,   184,   266,   179,    -1,
     272,    -1,   271,   184,   272,    -1,   266,    -1,   274,    -1,
     185,   186,    -1,   185,   275,   186,    -1,   169,   185,   275,
     186,    -1,   266,   170,   185,   275,   186,    -1,   272,    -1,
       5,    -1,   169,   274,    -1,   266,   170,   274,    -1,   266,
       8,   266,    -1,   266,     8,   266,     8,   266,    -1,    65,
     185,   266,   186,    -1,    65,     5,    -1,    68,     5,    -1,
      71,     5,    -1,    73,     5,    -1,    85,    65,   185,   275,
     186,    -1,    85,    68,   185,   275,   186,    -1,    85,    71,
     185,   275,   186,    -1,    85,    73,   185,   275,   186,    -1,
     233,    -1,   242,    -1,     4,   212,   213,    -1,    36,   180,
       4,   181,    -1,     4,   212,   185,   275,   186,   213,    -1,
     266,    -1,   274,    -1,   275,   184,   266,    -1,   275,   184,
     274,    -1,   185,   266,   184,   266,   184,   266,   184,   266,
     186,    -1,   185,   266,   184,   266,   184,   266,   186,    -1,
       4,    -1,     4,   182,   128,   182,     4,    -1,   185,   278,
     186,    -1,     4,   180,   266,   181,   182,   129,    -1,   276,
      -1,   278,   184,   276,    -1,   280,    -1,   284,    -1,     4,
     182,     4,    -1,     4,   180,   266,   181,   182,     4,    -1,
       5,    -1,    51,    -1,    53,    -1,   144,   178,   279,   179,
      -1,   145,   178,   279,   184,   279,   179,    -1,    41,   212,
     282,   213,    -1,    42,   178,   279,   179,    -1,    43,   178,
     279,   179,    -1,    44,   178,   279,   184,   279,   184,   279,
     179,    -1,    39,   212,   282,   213,    -1,    40,   212,   279,
     213,    -1,    40,   212,   279,   184,   275,   213,    -1,    -1,
      64,   212,   280,   281,   223,   213,    -1,   279,    -1,   282,
     184,   279,    -1,     4,   187,   185,   266,   186,    -1,   283,
     187,   185,   266,   186,    -1,     4,    -1,   283,    -1
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
     656,   657,   718,   747,   752,   757,   762,   769,   776,   791,
     796,   801,   810,   816,   825,   843,   861,   870,   882,   887,
     895,   915,   938,   949,   957,   979,  1002,  1028,  1049,  1061,
    1075,  1075,  1077,  1079,  1088,  1098,  1097,  1109,  1119,  1118,
    1132,  1134,  1142,  1148,  1155,  1156,  1160,  1171,  1186,  1196,
    1197,  1202,  1210,  1219,  1237,  1241,  1252,  1255,  1268,  1271,
    1281,  1305,  1304,  1324,  1346,  1364,  1385,  1403,  1433,  1463,
    1481,  1499,  1526,  1544,  1563,  1562,  1585,  1603,  1642,  1648,
    1654,  1661,  1686,  1711,  1728,  1747,  1782,  1781,  1805,  1823,
    1840,  1857,  1856,  1882,  1887,  1892,  1897,  1902,  1907,  1930,
    1936,  1947,  1948,  1953,  1956,  1960,  1983,  2006,  2029,  2057,
    2078,  2104,  2125,  2147,  2167,  2279,  2298,  2336,  2445,  2454,
    2460,  2475,  2503,  2520,  2529,  2543,  2549,  2555,  2564,  2573,
    2582,  2596,  2652,  2677,  2694,  2709,  2728,  2740,  2764,  2768,
    2773,  2780,  2786,  2791,  2797,  2805,  2809,  2813,  2818,  2873,
    2886,  2903,  2920,  2941,  2962,  2997,  3005,  3011,  3018,  3022,
    3031,  3039,  3047,  3056,  3055,  3070,  3069,  3084,  3083,  3098,
    3097,  3111,  3118,  3125,  3132,  3139,  3146,  3153,  3160,  3167,
    3175,  3174,  3188,  3187,  3201,  3200,  3214,  3213,  3227,  3226,
    3240,  3239,  3253,  3252,  3266,  3265,  3279,  3278,  3295,  3298,
    3304,  3316,  3336,  3360,  3364,  3368,  3372,  3376,  3382,  3388,
    3392,  3396,  3400,  3404,  3423,  3436,  3439,  3455,  3458,  3475,
    3478,  3484,  3487,  3494,  3550,  3620,  3625,  3692,  3728,  3736,
    3779,  3818,  3838,  3865,  3905,  3928,  3951,  3955,  3959,  3982,
    4021,  4060,  4081,  4102,  4129,  4133,  4143,  4178,  4179,  4180,
    4184,  4190,  4202,  4220,  4248,  4249,  4250,  4251,  4252,  4253,
    4254,  4255,  4256,  4263,  4264,  4265,  4266,  4267,  4268,  4269,
    4270,  4271,  4272,  4273,  4274,  4275,  4276,  4277,  4278,  4279,
    4280,  4281,  4282,  4283,  4284,  4285,  4286,  4287,  4288,  4289,
    4290,  4291,  4292,  4293,  4294,  4295,  4304,  4305,  4306,  4307,
    4308,  4309,  4310,  4311,  4312,  4313,  4318,  4317,  4325,  4342,
    4360,  4378,  4383,  4389,  4401,  4418,  4436,  4457,  4462,  4467,
    4477,  4487,  4492,  4501,  4506,  4533,  4537,  4541,  4545,  4549,
    4556,  4560,  4564,  4568,  4575,  4580,  4587,  4592,  4596,  4601,
    4605,  4613,  4624,  4628,  4640,  4648,  4656,  4663,  4673,  4693,
    4697,  4701,  4705,  4709,  4738,  4767,  4796,  4825,  4835,  4845,
    4857,  4869,  4890,  4895,  4899,  4903,  4915,  4919,  4931,  4938,
    4948,  4952,  4967,  4972,  4979,  4983,  4996,  5004,  5015,  5019,
    5027,  5033,  5041,  5049,  5064,  5078,  5092,  5104,  5120,  5124,
    5144,  5143,  5156,  5161,  5167,  5176,  5189,  5192
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
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "$@8", "$@9",
  "$@10", "$@11", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "ExtrudeParameters", "ExtrudeParameter",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "$@25", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "$@26",
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
     215,   215,   216,   216,   216,   217,   216,   216,   218,   216,
     219,   219,   220,   220,   221,   221,   222,   222,   222,   223,
     223,   224,   224,   224,   225,   225,   226,   226,   227,   227,
     228,   229,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   230,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   231,   228,   228,   228,
     228,   232,   228,   233,   233,   233,   233,   233,   233,   233,
     233,   234,   234,   235,   235,   235,   235,   235,   235,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   237,   237,
     237,   237,   237,   238,   238,   239,   239,   239,   239,   239,
     239,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     242,   242,   242,   243,   242,   244,   242,   245,   242,   246,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     247,   242,   248,   242,   249,   242,   250,   242,   251,   242,
     252,   242,   253,   242,   254,   242,   255,   242,   256,   256,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   258,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   263,   263,   263,   264,   264,   264,
     265,   265,   265,   265,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   268,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   269,   269,   269,   269,   269,
     270,   270,   270,   270,   271,   271,   272,   272,   272,   272,
     272,   272,   273,   273,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   275,   275,   275,   275,   276,   276,   276,   276,
     277,   277,   278,   278,   279,   279,   279,   279,   280,   280,
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
       5,     4,     6,     7,     7,     7,     9,     9,     3,     6,
       6,     4,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     5,     7,     9,     9,    11,     7,     9,     9,
       0,     1,     0,     3,     5,     0,     9,     5,     0,     9,
       0,     3,     3,     5,     0,     2,     3,     5,     3,     0,
       2,     3,     3,     5,     1,     1,     0,     5,     0,     2,
       7,     0,     9,     6,     7,     4,     7,     8,     8,     7,
       7,    11,     8,     8,     0,     9,     8,     9,     3,     4,
      10,     7,     7,     8,     8,    12,     0,     9,     8,     7,
       8,     0,     9,     5,    11,     5,     9,     9,     4,     9,
       9,     1,     1,     0,     2,     6,     6,     6,     6,     8,
      10,    14,    16,    12,     8,     8,     6,    14,     4,     6,
       6,     3,     4,     5,     6,     3,     3,     4,     5,     4,
       5,     3,     5,     7,     7,     3,     7,     3,     2,     2,
       2,     2,    15,     2,     2,     2,     2,     2,    16,     3,
       6,     8,     8,    10,     1,     2,     1,     3,     4,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     8,     8,     8,    12,    12,    12,    14,    14,    14,
       0,    12,     0,    12,     0,    12,     0,    16,     0,    16,
       0,    16,     0,    18,     0,    18,     0,    18,     1,     2,
       5,     7,     9,     2,     2,     2,     3,     2,     3,     2,
       3,     2,     3,     9,     6,     0,     3,     0,     1,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     7,     5,
       4,     6,     6,    12,    10,    10,    10,    10,    10,     4,
       4,     4,     4,     4,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     1,     4,
       4,     4,     4,     4,     2,     5,     5,     3,     6,     4,
       7,     6,     6,     6,     4,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     5,     5,     5,     5,     1,     1,     3,
       4,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       1,     4,     6,     4,     4,     4,     8,     4,     4,     6,
       0,     6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
       0,   229,     0,     0,     0,   226,     0,     0,     0,     0,
     317,   318,   319,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   467,     0,   366,   466,   448,   367,   368,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   450,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,   370,   371,   372,     0,     0,     0,    65,
      66,     0,     0,   173,     0,     0,     0,   324,     0,   444,
     467,   378,     0,     0,     0,     0,   211,     0,   213,   214,
     210,     0,   215,   216,   102,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   144,   156,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   395,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,   314,     0,     0,     0,     0,     0,     0,
       0,     0,   466,   413,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   427,   428,   406,   412,     0,   407,   378,
       0,     0,     0,     0,   438,     0,     0,     0,     0,     0,
     208,   209,     0,     0,   225,     0,   173,     0,   173,   466,
       0,   320,     0,     0,     0,     0,     0,    58,    62,    61,
      60,    59,    64,    63,     0,     0,     0,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,   326,   328,     0,     0,     0,     0,     0,     0,   466,
     467,     0,     0,   172,     0,   171,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,   201,     0,   384,   148,     0,
     466,     0,   444,   445,     0,     0,   462,     0,   100,   100,
       0,     0,   432,   433,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   289,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   173,     0,   397,   396,     0,     0,     0,     0,
     173,   173,     0,     0,     0,     0,     0,     0,     0,   239,
       0,   173,     0,     0,     0,     0,     0,   291,     0,     0,
       0,     0,   191,     0,     0,     0,   315,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,   419,
       0,   420,   421,   422,     0,     0,     0,     0,     0,   326,
     414,     0,   408,     0,     0,     0,   297,   207,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,   227,   195,
       0,   196,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,   387,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   460,     0,
       0,     0,     0,     0,     0,   325,    58,     0,     0,    58,
       0,     0,     0,     0,     0,   168,     0,     0,     0,     0,
     174,     0,     0,     0,   342,   341,   340,   339,   335,   336,
     338,   337,   330,   329,   331,   332,   333,   334,     0,     0,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,   312,   313,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   173,     0,     0,     0,     0,
       0,   399,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
     300,     0,     0,   192,     0,     0,   188,     0,     0,     0,
     310,   309,     0,     0,     0,     0,   387,    67,    68,     0,
     429,     0,     0,     0,     0,     0,     0,     0,   325,   409,
     416,     0,   331,   415,     0,     0,     0,     0,     0,     0,
       0,     0,   228,     0,   197,   199,     0,     0,     0,     0,
       0,     0,    81,    71,     0,   379,   389,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   365,   353,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,   457,
       0,   458,   453,   454,   455,     0,     0,     0,   394,   114,
     119,    92,     0,   451,     0,   381,   382,     0,     0,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,   383,
       0,     0,     0,     0,   464,     0,     0,    43,     0,     0,
       0,    56,     0,    34,    35,    36,    37,    38,   380,     0,
     446,    23,    21,     0,     0,    24,     0,     0,   202,   463,
      69,   103,    70,   111,     0,   434,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   290,   288,     0,   296,
       0,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,   200,     0,     0,     0,   163,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,   230,     0,
       0,     0,     0,     0,     0,   292,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   379,     0,   430,
     418,     0,     0,     0,     0,   410,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,     0,     0,     0,     0,
     321,     0,     0,     0,   465,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,    79,    82,    84,
       0,     0,   442,     0,    90,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,    29,   386,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,   302,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,   273,     0,   279,     0,   281,     0,   275,     0,
     277,     0,   240,   269,     0,     0,     0,   186,     0,     0,
       0,   301,     0,   190,   189,   316,     0,     0,    30,    31,
       0,     0,     0,   423,   424,   425,   426,   417,   411,     0,
       0,     0,   439,     0,     0,     0,   220,     0,     0,     0,
       0,     0,     0,    80,   204,   388,   203,   354,   362,   363,
     364,   459,     0,   392,   393,     0,   377,   115,     0,   461,
     120,   391,   452,    74,    58,     0,     0,     0,     0,    73,
       0,     0,     0,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,     0,     0,    25,    26,     0,    27,
       0,     0,   104,   107,   130,     0,     0,     0,     0,     0,
       0,   134,     0,     0,   151,   152,     0,     0,   136,   159,
       0,     0,     0,     0,   126,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,     0,     0,
       0,   173,   173,     0,   250,     0,   252,     0,   254,     0,
     406,     0,     0,   280,   282,   276,   278,     0,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   298,
       0,   388,   431,   139,   140,     0,     0,     0,     0,    93,
      97,     0,     0,   322,     0,    75,   390,     0,     0,     0,
       0,     0,    87,     0,     0,    88,     0,   443,   175,   176,
     177,   178,     0,     0,    39,     0,     0,     0,     0,     0,
      41,   447,     0,     0,   105,   108,     0,     0,   129,   137,
     138,   142,     0,     0,   153,     0,     0,   295,     0,   146,
       0,     0,   286,   158,     0,     0,     0,     0,   143,     0,
     154,   160,     0,     0,     0,     0,   403,     0,   402,     0,
       0,     0,   241,     0,     0,   242,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,   185,     0,     0,   184,
       0,     0,     0,   179,     0,     0,    32,     0,     0,   437,
       0,   222,   221,     0,     0,     0,     0,     0,   456,     0,
     116,   118,     0,   121,   122,    83,    85,     0,    91,     0,
      76,    44,     0,     0,     0,   405,     0,     0,     0,    28,
       0,   114,   119,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   132,   145,   157,   162,     0,     0,    98,    99,
     173,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,   270,     0,     0,   173,     0,     0,     0,     0,     0,
     170,   169,     0,     0,     0,     0,    94,    95,     0,    77,
       0,   432,     0,     0,   441,     0,    40,     0,     0,     0,
      42,    57,     0,     0,     0,   304,   306,   305,   307,   308,
     150,     0,     0,     0,     0,     0,     0,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,   235,     0,     0,   180,     0,     0,     0,   436,   223,
       0,   323,     0,   117,     0,   123,    89,     0,     0,     0,
       0,     0,   106,   109,     0,     0,     0,     0,   164,     0,
     256,     0,     0,   258,     0,     0,   260,     0,     0,     0,
     271,     0,   231,     0,   173,     0,     0,     0,   141,    96,
       0,   112,     0,    48,     0,    54,     0,     0,     0,   127,
     155,   303,   400,   244,     0,     0,   251,   245,     0,     0,
     253,   246,     0,     0,   255,     0,     0,     0,   237,     0,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,   264,     0,   266,   272,   283,   236,   232,
       0,     0,     0,     0,   113,    45,     0,    52,     0,     0,
       0,     0,   247,     0,     0,   248,     0,     0,   249,     0,
       0,   187,     0,   181,     0,    46,     0,     0,   212,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
       0,     0,   218,   257,     0,   259,     0,   261,     0,   182,
      47,    49,     0,    50,     0,     0,     0,     0,     0,     0,
      55,   263,   265,   267,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   833,    85,    86,   618,  1253,  1259,
     823,   991,  1415,  1574,   824,  1535,  1602,   825,  1576,   826,
     827,   995,   314,   397,   165,   720,    87,   632,   408,  1361,
    1362,   409,  1410,   967,  1117,   968,  1120,   871,  1281,  1158,
     600,   439,   440,   441,   442,   273,   374,   375,    90,    91,
      92,    93,    94,    95,   274,   909,  1493,  1550,   690,  1303,
    1306,  1309,  1514,  1518,  1522,  1563,  1566,  1569,   905,   906,
    1027,   868,   661,   699,    97,    98,    99,   100,   275,   167,
     789,   455,   233,  1142,   276,   277,   278,   513,   286,   808,
     983,   406,   402,   790,   407,   170,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1212
static const yytype_int16 yypact[] =
{
    5192,    57,    33,  5306, -1212, -1212,  2277,    56,    31,   -45,
      14,    24,   194,   210,   219,    61,   237,   286,   124,   171,
    -105,   160,   243,     4,   299,   310,    16,   327,   331,   360,
     413,   474,   550,   364,   439,   512,   524,   507,   469,   167,
     548,    78,   462,   581,   -63,   468,    59,    59,   476,   -12,
      67,   180,   596,   612,     1,    54,   615,   620,    87,   710,
     717,   724,  3092,   735,   499,   529,   566,    18,    20, -1212,
     570, -1212,   743,   752,   592, -1212,   769,   777,    12,    26,
   -1212, -1212, -1212,  5030, -1212, -1212, -1212, -1212, -1212, -1212,
   -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212,    17,
   -1212,   -43,   235, -1212,     3, -1212, -1212, -1212, -1212,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   600,   618,   619,   623,   624,   627,
   -1212, -1212, -1212, -1212, -1212,   195,   195,   803,   636,   644,
     647,   648,   674, -1212, -1212, -1212,  5030,  5030,  5030,  5030,
    4854,    35,   825,    47,   656,   657,   774, -1212,   675,   862,
     138,   233,   870,  5030,  1766,  1766, -1212,  5030, -1212, -1212,
   -1212,  1766, -1212, -1212, -1212, -1212,  5030,  4627,  5030,  5030,
     705,  5030,  4627,  5030,  5030,   714,  4627,  5030,  5030,  3446,
     750,   747, -1212,  4627,  3092,  3092,  3092,   770,   789,  3092,
    3092,  3092,   793, -1212, -1212, -1212, -1212,   794,   815,   826,
    3446,  5030,   884,  3446,    18,   762,   820,    59,    59,    59,
    5030,  5030,   -42, -1212,   -15,    59,   834,   845,   846,   251,
       8,     6,   831,   836,   854,  3092,  3092,  3446,   856,    37,
     844, -1212,  1029, -1212,   857,   858,   859,  3092,  3092,   871,
     874,   878,   411, -1212,   883,    27,  1045,  1059,  1065,   565,
    3623,  5030,  2710, -1212, -1212,  2860, -1212,  1068, -1212,     5,
    1069,  5030,  5030,  5030,   889,  5030,   891,   949,  5030,  5030,
   -1212, -1212,  5030,  1083, -1212,  1087, -1212,  1088, -1212,   -65,
     967, -1212,  3446,  3446,   910,  5030,   916,   683, -1212, -1212,
   -1212, -1212, -1212, -1212,  3446,  1096,   923,  5030,  1100, -1212,
   -1212,  5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,
    5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,
    5030,  5030,  5030,  1766,  1766,  1766,  1766,  1766,  1766,  1766,
    1766,  1766,  5030,   683,  5030,  1766,  1766,  1766,   825,   683,
     928,   928,   928,  7195,   101,  6850,   241,   925,  1101,   924,
     926,   934,   930, -1212,   931,  5400,  5030,  4627, -1212,  5030,
    5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,  5030,
    5030,  5030,  5030,  5030, -1212, -1212,  5030, -1212, -1212,  1116,
      49,   -59, -1212, -1212,   131,  6177, -1212,   188,   110,   352,
    7216,  4627,  2879, -1212,   197,  7237,  7258,  5030,  7279,   258,
    7300,  7321,  5030,   322,  7342,  7363,  1111,  5030,  5030,   408,
    1113,  1114,  1115,  5030,  5030,  1117,  1133,  1133,  5030,   945,
     965,   968,   969,  5030,  5030,  5030,  1142,  6123,   972,  1144,
     970, -1212, -1212,   -92, -1212, -1212,  6203,  6229,    59,    59,
      47,    47,    65,  5030,  5030,  5030,   251,   251,  5030,  5400,
     119, -1212,  5030,  5030,  5030,  5030,  5030,  1145,  1148,  1149,
    5030,  1152, -1212,  5030,  5030,   500, -1212,  4627,  4627,  4627,
    1153,  1154,  5030,  5030,  5030,  5030,  1161,   458,  1162, -1212,
    5030, -1212, -1212, -1212,   982,   986,   987,   988,  4627,   928,
   -1212,  7384, -1212,   448,  5030,  3800, -1212, -1212,  7405,  7426,
    7447,  1041,  6255, -1212,   989,  4293,  7468,  6873, -1212, -1212,
    1334, -1212,  2078,  5030, -1212,   996,   482,  4627,  6896,  5030,
    1170,  1171, -1212,  5030,  6919,   271,  6827,  6827,  6827,  6827,
    6827,  6827,  6827,  6827,  6827,  6827,  6827,  6281,  6827,  6827,
    6827,  6827,  6827,  6827,  6827,  6307,  6333,  6359,   471,   481,
     471,  1000,  1002,   998,   999,  1001,   205,  7909, -1212,  1156,
    1003,  1012,  1008,  1016,  1017,   101, -1212,  3446,   144,   683,
    5030,  1192,  1197,    23,  1023, -1212,   270,    21,    25,   298,
   -1212,  4823,   506,  4592,  1427,  2309,   810,   810,   502,   502,
     502,   502,   158,   158,   928,   928,   928,   928,    10,  6942,
   -1212,  5030,  1203,     9,  4627,  1202,  4627,  5030,  1208,  1766,
    1209, -1212,   825,  1215,  1766,  1217,  4627,  4627,  1091,  1218,
    1219,  7489,  1220,  1097,  1222,  1223,  7510,  1102,  1224,  1227,
    5030,  7531,  5395,  1050, -1212, -1212, -1212,  7552,  7573,  5030,
    3446,  1232,  1235,  7594,  4798,  4798,  4798,  4798,  7615,  7636,
    7657,  3446,  4627,  1060, -1212, -1212,  3131,  3308,    59,  5030,
    5030, -1212, -1212,  1057,  1058,   251,  6385,  6411,  6437,  5055,
     725,    59,  3485,  7678,  5423,  7699,  7720,  7741,  5030,  1240,
   -1212,  5030,  7762, -1212,  6965,  6988, -1212,   519,   551,   554,
   -1212, -1212,  7011,  7034,  6463,  7057,     5, -1212, -1212,  4627,
   -1212,  1066,  5451,  4627,  4627,  4627,  4627,   559, -1212, -1212,
    4759,  4627,   928, -1212,  1241,  1242,  1243,  1072,  5030,  3662,
    5030,  5030, -1212,    38, -1212, -1212,  1071,  3446,  1245,   567,
     324,  5479, -1212, -1212,  7080,    70, -1212, -1212, -1212, -1212,
   -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212,  5030, -1212,
   -1212, -1212, -1212, -1212, -1212, -1212,  5030,  5030,  5030, -1212,
    4627, -1212, -1212, -1212, -1212,  1766,  1766,  1766, -1212, -1212,
   -1212, -1212,  5030, -1212,  1766, -1212, -1212,  5030,  1249,    40,
    5030,  1253,  1255,  1302, -1212,  1256,  1085,    18,  1263, -1212,
    4627,  4627,  4627,  4627, -1212,   575,  5030, -1212,  1092,  1094,
    1104, -1212,  1284, -1212, -1212, -1212, -1212, -1212,     5,  7103,
   -1212, -1212,  1129,  1766,   216, -1212,   379,  6489, -1212, -1212,
   -1212,  1288, -1212, -1212,    59,  2879, -1212,   684,  3446,  3446,
    1293,  3446,   706,  3446,  3446,  1294,  1229,  3446,  3446,  1370,
    1296,  1298,  4627,  1299,  1300,  2107, -1212, -1212,  1303, -1212,
    1305,  1131,  7909, -1212,  1150,  1151,  1155,  1324,  1325,  1328,
    1330,   602,  1333,  3839, -1212, -1212,   121,  6515,  6541, -1212,
   -1212,  5507,   -62,    59,    59,    59,  1336,  1332,  1158,  1339,
    1166,    36,    44,    46,    51,   325, -1212,   143, -1212,   725,
    1341,  1348,  1349,  1350,  1351,  7909, -1212,  1492,  1174,  1357,
    1358,  1365,  1301,  5030,  1374,  1375,  5030,   362,   603, -1212,
   -1212,   606,   609,   622,   625, -1212,  5030,   634,  3446,  3446,
    3446,  1378,  6567, -1212,  4936,   443,  1384,  1387,  3446,  1206,
   -1212,  1214,  5030,  1388, -1212,  1390,  1393, -1212,  1403,  6827,
    6827,  6827,  6827,   525,  1228,  1234,  1238,   532,   536,  7783,
    1244,  1511, -1212,   543,  1239,  1404,  1774, -1212, -1212, -1212,
      18,  5030, -1212,   635, -1212,   650,   663,   664,   667,   101,
    7909,  1236,  5030,  5030,  3446,  1246, -1212, -1212,  1247, -1212,
    1419,    42,  1421,  5030,  4331,    55,  1248,  1252,  1347,  1347,
    3446,  1424,  1257,  1258,  1426,  1428,  3446,  1264,  1432,  1433,
   -1212,  1436,  3446,   673,  3446,  3446,  1444,  1448, -1212,  3446,
    1449,  1453,  1468,  1469,  3446,  3446,  3446, -1212,  1473,   621,
   -1212,  5030,  5030,  5030,  1270,  1297,  -122,  -114,   -68,  1304,
   -1212,  3446, -1212,  5030, -1212,  1475, -1212,  1477, -1212,  1479,
   -1212,  1480, -1212, -1212,   251,   914,  3269, -1212,  1306,  1307,
    3977, -1212,  4627, -1212, -1212, -1212,  1309,  1817, -1212, -1212,
    7126,  1483,   575, -1212, -1212, -1212, -1212,  7909, -1212,  1484,
    1489,  1373, -1212,  5030,  5030,  5030, -1212,  1491,   651,  1317,
    1496,   101,  2053, -1212, -1212,   356, -1212, -1212, -1212, -1212,
   -1212, -1212,  1766, -1212, -1212,  1499, -1212, -1212,  1500, -1212,
   -1212, -1212, -1212, -1212,   683,  5030,  1501,  1502,    23, -1212,
    1504,  7149,    18, -1212,  1505,  1506,  1507,  1508,  3446,  5030,
    6593,  6619,   680, -1212,  5030,  1512, -1212, -1212,  1766, -1212,
    6645,  4798,  7909, -1212, -1212,  5030,  5030,    59,  1509,  1513,
    1515, -1212,  5030,  5030, -1212, -1212,  1516,  5030, -1212, -1212,
    1503,  1517,  1320,  1520,  1396,  5030, -1212,  1522,  3446,  3446,
    3446,  3446,  1537,   863,  1538,  5030, -1212,  4798,  5535,  7804,
    4993,    47,    47,    59,  1539,    59,  1540,    59,  1542,  5030,
     301,  1366,  7825, -1212, -1212, -1212, -1212,  5563,   148, -1212,
    1543,  2481,  1545,  3446,    59,  2481,  1546,   686,  5030, -1212,
    1549,     5, -1212, -1212, -1212,  3446,  5332,   357,  7846, -1212,
   -1212,  4387,  3446, -1212,  3446, -1212, -1212,  1377,  2915,  4564,
    1554,  2088, -1212,  1557,  1555, -1212,  1385, -1212, -1212, -1212,
   -1212, -1212,  1564,   380,  7909,  5030,  5030,  3446,  1386,   687,
    7909, -1212,  1567,  5030,  7909, -1212,  5591,  5619,    95, -1212,
   -1212, -1212,  5647,  5675, -1212,  5703,  1569, -1212,  3446, -1212,
    1514,  1574,  7909, -1212,  1575,  1576,  1578,  1594, -1212,  1417,
   -1212, -1212,  6150,  2199,  1600,  1423, -1212,  5030, -1212,  1389,
    1425,   153, -1212,  1437,   155, -1212,  1438,   165, -1212,  1440,
    7172,  1604,  3446,  1605,  1445,  5030, -1212,  4154,   238, -1212,
     691,   246,   257, -1212,  1607,  5731, -1212,  1392,  5030, -1212,
    5030, -1212, -1212,  4627,  2433,  1611,  1446,  1625, -1212,  2710,
   -1212, -1212,  1766,  7909, -1212, -1212, -1212,    18, -1212,  1510,
   -1212, -1212,  5030,  6671,  6697, -1212,  3446,  5030,  1634, -1212,
    6723, -1212, -1212,  1635,  1636,  1637,  1638,  1641,  1643,   695,
    1465, -1212, -1212, -1212, -1212, -1212,  3446,  4627, -1212, -1212,
      47,  5367, -1212, -1212,   251,   725,   251,   725,   251,   725,
    1659, -1212,   696,  3446, -1212,  5759,    59,  1678,  4627,    59,
   -1212, -1212,  5030,  5787,  5815,   703, -1212, -1212,  1679, -1212,
     707,  2675,   732,  1680, -1212,  1518,  7909,  5030,  5030,   733,
    7909, -1212,  5030,   737,   738, -1212, -1212, -1212, -1212, -1212,
   -1212,  1519,  5030,   745,   784,  1523,  5030, -1212,  5843,   259,
     971,  5871,   306,   984,  5899,   317,  1105, -1212,  3446,  1681,
    1601,  4016,  1525,   346, -1212,   799,   371,  2535, -1212, -1212,
    1684, -1212,  5030, -1212,   683, -1212, -1212,  5030,  7867,  6749,
      28,  6775, -1212, -1212,  5030,  5927,  1685,  1686, -1212,  5955,
    1687,  5030,  1689,  1691,  5030,  1693,  1694,  5030,  1695,  1527,
   -1212,  5030, -1212,   725, -1212,  4627,  1696,  4154, -1212, -1212,
    2740, -1212,   802, -1212,  5030, -1212,  3446,  5030,  6801, -1212,
   -1212, -1212, -1212, -1212,  1526,  5983, -1212, -1212,  1529,  6011,
   -1212, -1212,  1530,  6039, -1212,  1699,  2655,  1254,  4193,   805,
   -1212,   393,   808,   683,  1700,  1531,  7888,   812,  6067,  5030,
     725,  1702,   725,  1712,   725,  1713, -1212, -1212, -1212, -1212,
     725,  1714,  4627,  1715, -1212, -1212,  1766, -1212,  1541,  1716,
    6095,  1338, -1212,  1547,  1521, -1212,  1548,  1661, -1212,  1552,
    1745, -1212,   813, -1212,   824, -1212,  1553,  3446, -1212,  1717,
    1719,   725,  1721,   725,  1724,   725, -1212,  1725,  1766,  1728,
    1766,   829, -1212, -1212,  2020, -1212,  2237, -1212,  2284, -1212,
   -1212, -1212,   839, -1212,  1733,  1735,  1737,  1738,  1766,  1739,
   -1212, -1212, -1212, -1212, -1212, -1212
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1212, -1212, -1212, -1212,   746, -1212, -1212, -1212, -1212,   279,
   -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212,
   -1212, -1212,  -338,   -53,  5005,  -465, -1212,  1342, -1212, -1212,
   -1212, -1212, -1212,   389, -1212,   390, -1212,  -213, -1212,   748,
    1751, -1212, -1212, -1212, -1212,    -2,  -450,  -230, -1212, -1212,
   -1212, -1212, -1212, -1212,  1752, -1212, -1212, -1212, -1212, -1212,
   -1212, -1212, -1212, -1212, -1212, -1212, -1212, -1212,  -896,  -886,
   -1212, -1212,  1319, -1212, -1212, -1212, -1212, -1212,   573, -1212,
   -1212,    -9, -1212, -1211,  1175,   342,  1376,  1070,  -206,   633,
   -1212,    30,    29, -1212,  -339,    13,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -448
static const yytype_int16 yytable[] =
{
     102,    89,  1320,   171,   568,   249,   570,   316,   190,   469,
     683,   684,   576,  1065,   817,   831,   101,   295,   450,  1063,
     195,   485,   284,   301,   287,   190,   587,   806,   590,   195,
     176,   297,   499,     5,  1505,   169,   168,   232,   234,   366,
     240,   481,  1054,   482,   973,   946,   458,   459,  1147,   315,
    1056,   372,  1058,   236,   458,   459,   237,  1060,   252,   238,
     253,  1154,  1193,     4,  1194,   224,   530,  1369,   532,   172,
    1195,   241,  1196,   186,   400,   105,   458,   459,   225,   226,
     187,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,   678,   769,   770,   771,   772,   773,   774,   775,
     458,   459,   173,   779,   781,   782,   458,   459,   586,   131,
     132,   133,   134,   135,   136,   533,  1197,   496,  1198,   254,
     623,   140,   164,   141,  1045,   624,   458,   459,   818,   819,
     820,   821,   242,   174,   146,   304,   243,   305,   250,    45,
      46,    47,    48,   460,   306,  1419,   220,    53,   244,   221,
      56,   586,  1055,   458,   459,   257,   228,   229,   258,   371,
    1057,   373,  1059,   367,   368,  1433,   230,  1061,   974,   975,
     461,   403,   403,   239,   832,   370,   458,   459,   403,  1063,
     312,   313,   191,   317,   472,   318,   251,   370,   370,   192,
     164,   473,   175,   471,   370,   302,   822,   296,   288,   191,
     178,   196,   303,   285,   401,   404,   811,   832,   807,   177,
     812,   298,   500,  1506,   149,   150,   179,   483,   453,   454,
     947,   676,   677,   458,   459,   180,   462,   228,   229,   621,
     470,   622,   213,   458,   459,   214,   164,   230,   215,   181,
     216,   692,   307,   182,   231,   312,   313,   797,   589,   685,
     800,   245,   956,   246,   103,   299,   308,   309,   310,   311,
     106,   107,   108,   458,   459,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   458,   459,   458,
     459,   630,   183,   739,   631,  1537,   137,   138,   139,   308,
     309,   310,   311,   691,   184,  1041,   142,   143,   144,   514,
     625,   458,   459,   591,   145,   626,   458,   459,   396,   312,
     313,   458,   459,   458,   459,   306,   799,  1064,   390,   391,
     392,   586,  1315,   458,   459,   393,   540,  1384,   188,  1386,
     403,   403,   403,   403,   403,   403,   403,   403,   403,  1388,
     989,   185,   403,   403,   403,   583,   370,   370,   370,   370,
     370,   370,   370,   370,   370,  1330,  1591,   628,   370,   370,
     370,   370,   629,   319,   569,   320,   571,   572,   573,   574,
     575,   637,   578,   638,   788,   580,   581,   582,   584,   629,
     308,   309,   310,   311,   148,  1001,   308,   309,   310,   311,
     637,   151,   152,   153,   154,   155,   458,   459,   312,   313,
     312,   313,   952,   896,   458,   459,   312,   313,  -445,   466,
     467,   189,  1396,   897,   158,   458,   459,   458,   459,   468,
    1398,   898,   899,   900,   162,   199,   231,   901,   902,   903,
     904,  1399,   637,  1481,   643,   883,   312,   313,   186,   681,
     682,  1095,   874,   875,   876,   810,  -446,   454,   373,   373,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   515,   391,   392,   458,   459,   198,   193,   393,   308,
     309,   310,   311,   813,   200,   458,   459,  1311,   194,  1440,
    1484,  1443,   756,  1446,  1107,  1108,  1109,  1110,  1111,   312,
     313,  1487,  1116,  1119,   204,   197,   637,   205,   647,   198,
     206,  1062,     7,     8,   458,   459,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
    1495,   312,   313,   633,   393,   801,   631,   312,   313,   458,
     459,  -447,   212,  1331,  1081,   201,   430,   431,   432,   203,
    1124,   435,   436,   437,  1063,  1497,   202,  1063,  1002,  1351,
    1063,   458,   459,   637,  1352,   596,    21,    22,   597,    24,
      25,   598,    27,   599,    29,   209,    30,  1552,   210,   166,
     211,    35,    36,   207,    38,    39,    40,   477,   478,   319,
      43,   495,   637,   496,   653,   208,   163,  1527,   164,   490,
     491,   982,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   217,  1222,   802,   218,
     393,   219,  1096,    64,    65,    66,   403,  1186,  1187,   841,
     504,   403,   637,   505,   729,  1125,   506,   717,   507,   718,
     222,  1063,   370,   719,  1561,   370,  1564,   370,  1567,   223,
     717,  1138,   718,   227,  1570,   629,   300,  1230,  1231,   839,
     717,   235,   718,   756,   843,   780,   747,   247,   748,   886,
     388,   389,   390,   391,   392,  1063,   892,   281,  1063,   393,
     248,  1063,   907,   255,  1063,  1594,   706,  1596,   105,  1598,
     637,   256,   815,   873,   873,   873,   873,   953,   308,   309,
     310,   311,   957,   637,   717,   921,   718,   282,  1063,   637,
    1063,   717,  1063,   718,   259,   717,  1115,   718,   312,   313,
    1118,   260,   131,   132,   133,   134,   135,   136,   261,   360,
     361,   362,   363,   365,   140,   637,   141,   922,   637,   280,
     923,  1299,  1300,   637,   283,   935,   399,   146,   289,   290,
     405,   637,   403,   951,   717,  1006,   718,  1007,   291,   410,
     412,   415,   416,  1234,   418,   412,   420,   421,   370,   412,
     424,   425,   292,   293,  1130,   997,   412,  1012,   346,  1013,
     378,   294,   403,   403,   403,   958,   637,   637,  1038,  1082,
     637,   403,  1083,   637,   447,  1084,   347,   348,   370,   370,
     370,   349,   350,   456,   457,   351,   637,   370,  1085,   637,
     354,  1086,   457,   896,   355,   964,   965,   966,   637,  1132,
    1088,  1133,   356,   897,   970,   357,   358,   149,   150,   369,
     403,   898,   899,   900,   637,  1005,  1134,   901,   902,   903,
     904,   376,   377,   509,   511,   412,   370,   637,   637,  1135,
    1136,   637,   359,  1137,   518,   519,   520,   637,   522,  1172,
     394,   525,   526,  1000,  1257,   527,  1258,  1289,   395,  1290,
     637,  1357,  1324,  1358,   957,  1257,   398,  1397,   538,  1257,
    1448,  1431,  1449,   417,  1046,  1047,  1048,   637,   448,  1460,
     544,  1462,   422,  1463,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   629,  1257,  1465,  1470,
    1126,  1115,  1118,  1472,  1473,   577,  1247,   579,   427,  1257,
    1435,  1476,   428,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   451,   433,   601,
     412,   393,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   434,   637,   619,
    1477,   438,   443,   534,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   637,   509,  1496,  1357,   393,  1534,   637,
     641,  1551,   637,   444,  1553,   646,  1257,   637,  1558,  1587,
     651,   652,   896,  1412,   445,   452,   657,   658,  1588,   474,
    1589,   663,   897,  1257,   475,  1604,   668,   669,   670,   463,
     898,   899,   900,  1608,   484,  1609,   901,   902,   903,   904,
     464,   465,   476,  1153,   480,   486,   686,   687,   688,   360,
     361,   689,   487,   488,   489,   693,   694,   695,   696,   697,
     501,   492,  1236,   702,   493,  1208,   704,   705,   494,   896,
     412,   412,   412,   498,   502,   712,   713,   714,   715,   897,
     503,   521,   896,   722,   516,   517,   523,   898,   899,   900,
     524,   412,   897,   901,   902,   903,   904,   730,   732,   528,
     898,   899,   900,   529,   531,   537,   901,   902,   903,   904,
    1209,   539,   542,   543,   545,   393,   715,   592,   593,   403,
     412,   164,   751,   306,   594,   163,   754,   595,   650,   654,
     655,   656,   620,   664,   659,   370,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     660,  1413,  1237,   665,   393,   403,   666,   667,  1268,   671,
     674,   673,   698,  1240,   700,   675,   701,  1482,   703,   710,
     711,   370,   791,   803,  1451,   716,   721,   723,  1236,   737,
    1485,   724,   725,   726,   740,   746,   752,   753,  1262,   783,
    1265,   784,   785,   786,  1301,   787,  1304,   792,  1307,   373,
     373,   793,   794,   896,   829,   795,   796,   412,   804,   412,
     837,   805,  1318,   897,   809,  1321,  1322,   830,   835,   732,
     845,   898,   899,   900,   838,   840,  1294,   901,   902,   903,
     904,   842,   847,   859,   844,   848,   849,   851,   852,   853,
     854,   857,   865,   856,   858,   862,   867,   872,   872,   872,
     872,   869,   882,   889,   890,   412,   916,   929,   938,   939,
     940,   950,   887,   888,   941,   972,   948,   414,   891,   977,
    1335,   978,   419,   980,  1528,   981,   423,  1341,  1344,   984,
     992,   915,   993,   429,   917,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   994,
     996,  1488,   412,   393,   999,  1004,   412,   412,   412,   412,
    1010,  1016,  1017,  1021,   412,  1022,  1024,  1025,   979,  1028,
    1030,   942,  1029,   944,   945,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,  1031,
    1032,  1034,  1035,   393,  1033,  1036,  1037,  1039,  1050,   403,
    1049,   959,   896,  1051,  1053,  1052,     7,     8,  1066,   960,
     961,   962,   897,   412,  1067,   370,  1068,  1069,  1070,  1072,
     898,   899,   900,  1073,  1074,   969,   901,   902,   903,   904,
     971,  1075,  1076,   976,   426,  1439,  1020,  1442,   373,  1445,
    1078,  1079,  1092,   412,   412,   412,   412,  1453,  1097,   990,
    1456,  1098,  1100,  1101,  1103,   446,  1104,  1105,   449,   596,
      21,    22,   597,    24,    25,   598,    27,   599,    29,  1106,
      30,  1128,  1112,  1113,  1139,    35,    36,  1114,    38,    39,
      40,  1127,   479,  1122,    43,  1146,   896,  1149,  1157,  1145,
    1161,  1144,  1164,  1155,  1165,   412,   897,  1156,  1168,  1169,
    1548,  1170,  1162,  1163,   898,   899,   900,   602,  1175,  1167,
     901,   902,   903,   904,  1176,  1191,  1178,    64,    65,    66,
    1179,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,  1180,  1181,   535,   536,   393,
    1185,  1203,  1192,  1204,  1199,  1205,  1206,  1221,  1531,   541,
    1223,  1213,  1214,  1501,  1218,  1224,  1077,  1229,  1071,  1080,
    1225,  1232,  1233,  1238,  1239,  1278,  1243,  1242,  1276,  1087,
    1245,  1248,  1249,  1250,  1251,  1269,  1261,  1123,  1402,  1270,
     744,  1271,  1274,  1277,  1580,  1102,  1279,  1280,  1283,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,  1288,  1291,  1302,  1305,   393,  1308,  1316,
    1312,  1319,  1323,   403,  1131,  1326,  1338,   707,   708,   709,
    1345,  1348,  1554,   413,  1347,  1140,  1141,  1349,   413,   370,
    1350,  1356,   413,  1359,  1368,  1382,  1150,  1152,   727,   413,
    1371,  1372,  1373,  1370,  1374,   403,  1575,   403,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
    1375,   370,  1376,   370,   393,   403,  1379,   749,  1380,   896,
    1391,  1383,  1393,  1400,  1188,  1189,  1190,  1407,  1600,   897,
    1603,   370,  1385,  1387,  1200,  1389,  1202,   898,   899,   900,
    1394,  1409,  1408,   901,   902,   903,   904,  1207,  1614,  1414,
    1421,  1425,  1426,  1427,  1428,   412,   510,  1429,   413,  1430,
    1432,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,  1447,  1226,  1227,  1228,   393,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,  1454,  1461,  1466,  1490,   393,  1491,
    1499,  1510,  1511,  1513,   834,  1516,   836,  1517,  1241,  1520,
    1521,  1524,  1530,  1467,  1474,  1546,  1555,  1582,  1562,  1478,
    1494,  1540,  1254,  1525,  1542,  1544,  1556,  1260,  1565,  1568,
    1571,  1573,  1578,  1592,  1264,  1593,  1577,  1595,  1266,  1267,
    1597,  1599,  1581,  1583,  1601,  1272,  1273,  1585,  1590,  1610,
    1275,  1611,   881,  1612,  1613,  1615,  1502,  1148,  1282,   896,
    1423,   634,  1424,   413,    88,    96,   662,  1159,  1292,   897,
    1293,  1244,   798,     0,     0,     0,     0,   898,   899,   900,
     400,   105,  1310,   901,   902,   903,   904,     0,     0,     0,
    1129,     0,     0,     0,   412,     0,     0,   510,   412,   928,
       0,  1325,     0,   931,   932,   933,   934,     0,     0,     0,
       0,   937,     0,     0,  1334,   131,   132,   133,   134,   135,
     136,     0,  1343,     0,     0,     0,     0,   140,     0,   141,
       0,     0,     0,  1219,     0,     0,     0,     0,  1353,  1354,
     146,     0,     0,   896,     0,   866,  1360,     0,     0,     0,
       0,     0,     0,   897,     0,     0,   880,  1584,     0,     0,
     963,   898,   899,   900,     0,     0,     0,   901,   902,   903,
     904,     0,     0,   413,   413,   413,     0,     0,     0,     0,
    1381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     985,   986,   987,   988,   413,     0,     0,     0,  1395,     0,
     509,   733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1403,     0,  1404,     0,     0,   412,     0,     0,     0,
     149,   150,  1411,   413,     0,     0,     0,     0,     0,     0,
       0,     0,   949,     0,     0,  1416,     0,     0,     0,     0,
    1420,  1586,  1023,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
     412,   393,     0,     0,     0,     0,     0,  1438,     0,  1441,
       0,  1444,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,     0,     0,  1457,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
    1468,  1469,     0,     0,   393,  1471,     0,     0,     0,     0,
     413,     0,   413,     0,     0,  1475,     0,     0,     0,  1479,
       0,     0,   733,   846,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1008,  1009,     0,  1011,     0,  1014,  1015,
       0,     0,  1018,  1019,     0,  1500,     0,     0,     0,     0,
    1260,     0,     0,     0,     0,     0,     0,  1508,   413,     0,
       0,     0,     0,     0,  1515,     0,     0,  1519,     0,  1235,
    1523,     0,     0,     0,  1526,     0,     0,     0,   412,     0,
     412,     0,     0,     0,     0,     0,     0,  1536,     0,     0,
    1538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,  1346,   413,     0,     0,     0,   413,
     413,   413,   413,     0,     0,     0,     0,   413,   896,     0,
       0,     0,  1560,  1089,  1090,  1091,     0,     0,   897,     0,
       0,     0,     0,  1099,     0,   412,   898,   899,   900,     0,
       0,     0,   901,   902,   903,   904,     0,     0,     0,     0,
       0,     0,  1217,   596,    21,    22,   597,    24,    25,   598,
      27,   599,    29,     0,    30,     0,   413,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,  1143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1160,   413,   413,   413,   413,
       0,  1166,     0,     0,     0,  1026,     0,  1171,     0,  1173,
    1174,    64,    65,    66,  1177,  1378,  1605,     0,     0,  1182,
    1183,  1184,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,  1201,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,   413,     0,
       0,  1212,     0,     0,     0,  1216,     0,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,   745,   393,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     103,   104,   105,     0,   393,     0,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,  1252,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   896,     0,     0,   140,     0,
     141,     0,   142,   143,   144,   897,     0,     0,     0,     0,
     145,   146,     0,   898,   899,   900,     0,     0,     0,   901,
     902,   903,   904,  1284,  1285,  1286,  1287,     0,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   896,     0,     0,     0,   393,     0,     0,     0,
       0,     0,   897,     0,     0,     0,     0,     0,  1143,     0,
     898,   899,   900,     0,     0,     0,   901,   902,   903,   904,
    1327,     0,     0,  1405,     0,     0,     0,  1336,     0,  1337,
       0,     0,     0,  1340,   147,     0,     0,     0,     0,     0,
     148,   149,   150,  1606,     0,     0,     0,   151,   152,   153,
     154,   155,  1355,     0,     0,     0,     0,     0,     0,  1406,
       0,     0,     0,     0,     0,   156,   157,  1434,   413,     0,
     158,     0,     0,  1143,     0,   159,     0,   160,     0,   161,
     162,     0,   163,     0,   164,     0,     0,     0,  1455,     0,
    1607,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,   103,   262,   393,  1392,     0,     0,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,     0,
       0,  1143,     0,     0,     0,     0,   142,   143,   144,     0,
       0,  1498,     0,     0,   145,     0,   265,     0,     0,   266,
       0,  1143,   267,     0,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1529,   269,  1532,  1450,     0,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,     0,     0,   413,     0,     0,
       0,   413,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1572,  1489,   148,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
    1317,     0,     0,     0,   158,     0,     0,     0,     0,   468,
       0,  1547,     0,     0,   162,     0,   231,   512,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1143,  1464,   514,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   510,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,   413,
       0,     0,   393,   103,   262,   413,     0,     0,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   264,  1533,     0,     0,
       0,     0,  1143,   413,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,     0,
       0,     0,     0,   145,   413,   265,     0,     0,   266,     0,
       0,   267,     0,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,     0,     0,     0,
      53,     0,     0,    56,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   636,   391,   392,     0,     0,
       0,     0,   393,   148,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,   514,     0,
       0,   413,     0,   413,     0,     0,     0,     0,   156,   411,
       0,     0,     0,   158,     0,     0,     0,   514,   271,     0,
       0,     0,     0,   162,     0,     0,   512,     0,     0,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,   103,   262,
     105,     0,     0,     0,   106,   107,   108,     0,   413,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   264,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,     0,   140,     0,   141,     0,
     142,   143,   144,     0,     0,     0,     0,     0,   145,   146,
     265,     0,     0,   266,     0,     0,   267,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     515,   391,   392,     0,     0,     0,     0,   393,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   636,
     391,   392,     0,     0,     0,     0,   393,     0,   148,   149,
     150,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,   270,     0,     0,     0,   158,     0,
       0,     0,     0,   271,     0,   103,   262,   263,   162,     0,
    1339,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
       0,     0,     0,     7,     8,     0,     0,   142,   143,   144,
       0,     0,     0,     0,     0,   145,     0,   265,     0,     0,
     266,     0,     0,   267,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,     0,
       0,     0,    53,     0,     0,    56,   596,    21,    22,   597,
      24,    25,   598,    27,   599,    29,     0,    30,     0,     0,
       0,     0,    35,    36,     0,    38,    39,    40,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,     0,
     156,   270,     0,     0,     0,   158,     0,     0,     0,     0,
     271,     0,   103,   262,  1210,   162,     0,   272,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   884,     0,     0,
       7,     8,     0,     0,   142,   143,   144,     0,     0,     0,
       0,     0,   145,     0,   265,     0,     0,   266,     0,     0,
     267,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   596,    21,    22,   597,    24,    25,   598,
      27,   599,    29,     0,    30,     0,     0,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,   156,   270,     0,
       0,     0,   158,     0,     0,     0,     0,   271,     0,   103,
     262,     0,   162,     0,  1211,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,   885,     0,     0,     7,     8,     0,
       0,   142,   143,   144,     0,     0,     0,     0,     0,   145,
       0,   265,     0,     0,   266,     0,     0,   267,     0,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     596,    21,    22,   597,    24,    25,   598,    27,   599,    29,
       0,    30,     0,     0,     0,     0,    35,    36,     0,    38,
      39,    40,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   151,   152,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     0,     0,   156,   270,     0,     0,     0,   158,
       0,     0,     0,     0,   271,     0,   103,   262,     0,   162,
       0,   272,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   908,     0,     0,     7,     8,     0,     0,   142,   143,
     144,     0,     0,     0,     0,     0,   145,     0,   265,     0,
       0,   266,     0,     0,   267,     0,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
       0,     0,     0,    53,     0,     0,    56,   596,    21,    22,
     597,    24,    25,   598,    27,   599,    29,     0,    30,     0,
       0,     0,     0,    35,    36,     0,    38,    39,    40,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,     0,     0,
       0,   156,   411,     0,     0,     0,   158,     0,     0,     0,
       0,   271,     0,   103,   262,     0,   162,     0,   508,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,   943,     0,
       0,     7,     8,     0,     0,   142,   143,   144,     0,     0,
       0,     0,     0,   145,     0,   265,     0,     0,   266,     0,
       0,   267,     0,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,     0,     0,     0,
      53,     0,     0,    56,   596,    21,    22,   597,    24,    25,
     598,    27,   599,    29,     0,    30,     0,     0,     0,     0,
      35,    36,     0,    38,    39,    40,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,     0,     0,   156,   411,
       0,     0,     0,   158,     0,     0,     0,     0,   271,     0,
     103,   262,     0,   162,     0,   731,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,  1040,     0,     0,     7,     8,
       0,     0,   142,   143,   144,     0,     0,     0,     0,     0,
     145,     0,   265,     0,     0,   266,     0,     0,   267,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   596,    21,    22,   597,    24,    25,   598,    27,   599,
      29,     0,    30,     0,     0,     0,     0,    35,    36,     0,
      38,    39,    40,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     0,   156,   270,     0,     0,     0,
     158,     0,     0,     0,     0,   271,     0,   103,   262,     0,
     162,     0,  1215,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,   139,  1492,     0,     0,     7,     8,     0,     0,   142,
     143,   144,     0,     0,     0,     0,     0,   145,     0,   265,
       0,     0,   266,     0,     0,   267,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   596,    21,
      22,   597,    24,    25,   598,    27,   599,    29,     0,    30,
       0,     0,     0,     0,    35,    36,     0,    38,    39,    40,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,   741,     0,     0,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,     0,
       0,     0,   466,  1317,     0,     0,     0,   158,     0,     0,
       0,     0,   468,     0,   103,   299,   105,   162,     0,   231,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,  1549,
       0,     0,   140,     0,   141,     0,   142,   143,   144,     0,
     103,   299,   105,     0,   145,   146,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,   140,     0,
     141,     0,   142,   143,   144,     0,     0,     0,     0,     0,
     145,   146,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,   148,   149,   150,     0,     0,     0,
       0,   151,   152,   153,   154,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
     157,     0,     0,     0,   158,     0,     0,     0,     0,   271,
       0,     0,     0,     0,   162,     0,  1151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,     0,     0,     0,
     158,     0,     0,     0,     0,   271,     0,   103,   299,   105,
     162,     0,  1333,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     816,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,   140,     0,   141,     0,   142,
     143,   144,     0,     0,     0,     0,     0,   145,   146,     0,
     103,   262,     0,     0,     0,     0,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,     0,     0,     0,     0,
     145,     0,   265,     0,     0,   266,     0,     0,   267,     0,
     268,     0,     0,     0,     0,     0,     0,   148,   149,   150,
       0,     0,   269,     0,   151,   152,   153,   154,   155,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,     0,   156,   157,     0,     0,     0,   158,     0,     0,
       0,     0,   271,     0,     0,     0,     0,   162,     0,  1342,
       0,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,   936,     0,   393,
     148,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   411,     0,     0,     0,
     158,   103,   299,   105,     0,   271,     0,   106,   107,   108,
     162,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,   140,
       0,   141,     0,   142,   143,   144,     0,   103,   299,     0,
       0,   145,   146,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,     0,     0,     0,     0,     0,   145,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,   148,   149,   150,  1094,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,     0,     0,
       0,   158,     0,     0,     0,     0,   271,     0,     0,     0,
       0,   162,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,   148,     0,     0,
     393,     0,     0,     0,   151,   152,   153,   154,   155,   814,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,     0,     0,   158,     0,     0,
       0,     0,   271,   103,   299,   364,     0,   162,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,     0,
       0,     0,     0,   145,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352,   353,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,   148,     0,     0,     0,  1297,     0,  1298,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,   156,   157,
       0,     0,     0,   158,    -4,    -4,     0,     0,   271,     0,
       0,     0,     0,   162,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,    -4,
      -4,     0,   393,     0,   728,     0,     0,     0,     0,   679,
      -4,    -4,    -4,     0,    -4,     0,    -4,     0,     0,     0,
      -4,    -4,     0,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,   497,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,    -4,
       6,     0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,    -4,     0,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,    14,     0,
      15,     0,     0,     0,    16,    17,     0,    18,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     7,     8,     0,    59,    60,    61,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    63,    64,
      65,    66,     0,     0,    67,     0,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   596,    21,    22,   597,    24,
      25,   598,    27,   599,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,     0,     0,     0,
      43,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1328,     0,  1329,     0,
       0,     0,     0,    64,    65,    66,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1436,     0,  1437,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,   861,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,   911,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,     0,     0,   930,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,   954,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,  1044,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,  1295,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,  1314,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,     0,     0,  1363,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,  1364,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,  1365,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,  1366,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,  1367,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,     0,     0,  1401,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,  1452,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,  1458,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,  1459,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,  1480,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,     0,     0,  1483,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,  1486,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,  1509,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,  1512,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,  1541,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,     0,     0,  1543,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,  1545,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,  1559,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,  1579,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,   672,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,  1377,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,   627,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,   679,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,   680,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,   738,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,   768,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,   776,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,   777,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,   778,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,   893,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,   894,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,   895,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,   926,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1003,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1042,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1043,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1093,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1255,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1256,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1263,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1417,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
       0,  1418,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,  1422,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
       0,     0,     0,  1504,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1507,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,  1539,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   717,     0,   718,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,   588,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,   743,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,   750,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
     755,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,   828,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,   919,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,   920,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,   924,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,   925,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,   927,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,   955,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,   998,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,  1220,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
    1246,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,  1390,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   585,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   635,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   639,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   640,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   642,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   644,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     645,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   648,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   649,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   728,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   734,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   735,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   736,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   742,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   850,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   855,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     860,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   863,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   864,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   870,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   877,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   878,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   879,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   910,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   912,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   913,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     914,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   918,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,  1121,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,  1296,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,  1313,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,  1332,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,  1503,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,  1557,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1212)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,  1213,     6,   343,     4,   345,     4,     4,   239,
     460,   461,   351,   909,     4,     6,     3,     5,   224,   905,
       4,   251,     4,     6,     4,     4,   364,     4,   366,     4,
       6,     5,     5,     0,     6,     6,     6,    46,    47,     4,
      49,     4,     6,     6,     4,     7,   168,   169,     6,   102,
       6,     4,     6,    65,   168,   169,    68,     6,     4,    71,
       6,     6,   184,     6,   186,   128,   296,  1278,   298,    13,
     184,     4,   186,   178,     4,     5,   168,   169,   141,   142,
     185,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   184,   558,   559,   560,   561,   562,   563,   564,
     168,   169,    71,   568,   569,   570,   168,   169,     7,    39,
      40,    41,    42,    43,    44,   180,   184,   182,   186,    65,
     179,    51,   187,    53,   186,   184,   168,   169,   118,   119,
     120,   121,    65,   178,    64,   178,    69,   180,   137,    92,
      93,    94,    95,   185,   187,  1356,    68,   100,    81,    71,
     103,     7,   116,   168,   169,    68,   168,   169,    71,   162,
     116,   163,   116,   128,   129,  1376,   178,   116,   128,   129,
     185,   174,   175,   185,   165,   162,   168,   169,   181,  1065,
     175,   176,   178,   180,   178,   182,   185,   174,   175,   185,
     187,   185,   178,   185,   181,   178,   186,   185,   178,   178,
       6,   185,   185,   185,   174,   175,   185,   165,   185,   185,
     185,   185,   185,   185,   144,   145,     6,   180,   227,   228,
     182,   451,   452,   168,   169,     6,   235,   168,   169,   180,
     239,   182,    65,   168,   169,    68,   187,   178,    71,   178,
      73,   471,     7,     6,   185,   175,   176,   585,     7,   184,
     588,    71,   182,    73,     3,     4,   155,   156,   157,   158,
       9,    10,    11,   168,   169,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   168,   169,   168,
     169,   181,     6,   523,   184,  1506,    45,    46,    47,   155,
     156,   157,   158,   184,   180,   184,    55,    56,    57,     8,
     179,   168,   169,   366,    63,   184,   168,   169,   180,   175,
     176,   168,   169,   168,   169,   187,   182,   184,   170,   171,
     172,     7,   184,   168,   169,   177,   307,   184,   178,   184,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   184,
     815,   180,   355,   356,   357,   358,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     8,  1577,   179,   355,   356,
     357,   358,   184,   178,   344,   180,   346,   347,   348,   349,
     350,   184,   353,   186,   179,   355,   356,   357,   359,   184,
     155,   156,   157,   158,   143,   179,   155,   156,   157,   158,
     184,   150,   151,   152,   153,   154,   168,   169,   175,   176,
     175,   176,   750,    88,   168,   169,   175,   176,   185,   168,
     169,   178,   184,    98,   173,   168,   169,   168,   169,   178,
     184,   106,   107,   108,   183,    75,   185,   112,   113,   114,
     115,   184,   184,   184,   186,   675,   175,   176,   178,   458,
     459,     8,   665,   666,   667,   185,   185,   466,   460,   461,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   168,   169,   178,   178,   177,   155,
     156,   157,   158,   185,    71,   168,   169,   186,   178,  1385,
     184,  1387,   545,  1389,   959,   960,   961,   962,   963,   175,
     176,   184,   967,   968,    65,   178,   184,    68,   186,   178,
      71,   186,    12,    13,   168,   169,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     184,   175,   176,   181,   177,   588,   184,   175,   176,   168,
     169,   185,    73,   186,   182,    71,   204,   205,   206,   185,
       7,   209,   210,   211,  1440,   184,     6,  1443,   179,   179,
    1446,   168,   169,   184,   184,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    68,    76,   184,    71,     6,
      73,    81,    82,    71,    84,    85,    86,   245,   246,   178,
      90,   180,   184,   182,   186,    71,   185,  1493,   187,   257,
     258,   807,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    68,  1082,   589,    71,
     177,    73,   179,   123,   124,   125,   629,     6,     7,   632,
      65,   634,   184,    68,   186,   973,    71,   179,    73,   181,
     178,  1527,   629,   185,  1540,   632,  1542,   634,  1544,    68,
     179,   989,   181,   185,  1550,   184,    83,     6,     7,   629,
     179,   185,   181,   716,   634,   184,   184,    71,   186,   678,
     168,   169,   170,   171,   172,  1561,   685,   178,  1564,   177,
      68,  1567,   691,    68,  1570,  1581,   186,  1583,     5,  1585,
     184,    71,   186,   664,   665,   666,   667,   750,   155,   156,
     157,   158,   755,   184,   179,   186,   181,   178,  1594,   184,
    1596,   179,  1598,   181,     4,   179,   184,   181,   175,   176,
     184,     4,    39,    40,    41,    42,    43,    44,     4,   156,
     157,   158,   159,   160,    51,   184,    53,   186,   184,     4,
     186,  1191,  1192,   184,   178,   186,   173,    64,   178,     6,
     177,   184,   755,   186,   179,    71,   181,    73,     6,   186,
     187,   188,   189,  1101,   191,   192,   193,   194,   755,   196,
     197,   198,   180,     4,   980,   828,   203,    71,   178,    73,
       6,     4,   785,   786,   787,   755,   184,   184,   186,   186,
     184,   794,   186,   184,   221,   186,   178,   178,   785,   786,
     787,   178,   178,   230,   231,   178,   184,   794,   186,   184,
       7,   186,   239,    88,   178,   785,   786,   787,   184,   184,
     186,   186,   178,    98,   794,   178,   178,   144,   145,     4,
     833,   106,   107,   108,   184,   844,   186,   112,   113,   114,
     115,   185,   185,   270,   271,   272,   833,   184,   184,   186,
     186,   184,   178,   186,   281,   282,   283,   184,   285,   186,
     185,   288,   289,   833,   184,   292,   186,     4,     6,     6,
     184,   184,   186,   186,   927,   184,     6,   186,   305,   184,
     184,   186,   186,   178,   893,   894,   895,   184,     4,   186,
     317,   184,   178,   186,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   184,   184,   186,   186,
     973,   184,   184,   186,   186,   352,  1132,   354,   178,   184,
    1380,   186,   185,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   185,   178,   376,
     377,   177,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   178,   184,   396,
     186,   178,   178,     6,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   184,   411,   186,   184,   177,   186,   184,
     417,   186,   184,   178,   186,   422,   184,   184,   186,   186,
     427,   428,    88,  1342,   178,   185,   433,   434,   184,   178,
     186,   438,    98,   184,   178,   186,   443,   444,   445,   185,
     106,   107,   108,   184,   180,   186,   112,   113,   114,   115,
     185,   185,   178,  1004,   178,     6,   463,   464,   465,   466,
     467,   468,   185,   185,   185,   472,   473,   474,   475,   476,
       5,   180,  1105,   480,   180,  1064,   483,   484,   180,    88,
     487,   488,   489,   180,     5,   492,   493,   494,   495,    98,
       5,   182,    88,   500,     6,     6,   185,   106,   107,   108,
     131,   508,    98,   112,   113,   114,   115,   514,   515,     6,
     106,   107,   108,     6,     6,   185,   112,   113,   114,   115,
     186,   185,     6,   180,     4,   177,   533,   182,     7,  1112,
     537,   187,   539,   187,   180,   185,   543,   186,     7,     6,
       6,     6,     6,   178,     7,  1112,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       7,  1347,  1112,   178,   177,  1148,   178,   178,  1157,     7,
       6,   179,     7,  1124,     6,   185,     7,   186,     6,     6,
       6,  1148,     6,   590,  1394,     4,     4,   185,  1221,   128,
     186,   185,   185,   185,   185,   179,     6,     6,  1148,   179,
    1151,   179,   184,   184,  1193,   184,  1195,   184,  1197,  1191,
    1192,   179,   184,    88,   621,   179,   179,   624,     6,   626,
     627,     4,  1211,    98,   181,  1214,  1215,     4,     6,   636,
     637,   106,   107,   108,     6,     6,  1187,   112,   113,   114,
     115,     6,   131,   650,     7,     7,     7,     7,   131,     7,
       7,     7,   659,   131,     7,   185,     4,   664,   665,   666,
     667,     6,   182,   186,   186,   672,     6,   181,     7,     7,
       7,     6,   679,   680,   182,     6,   185,   187,   685,     6,
    1231,     6,   192,     7,  1494,   180,   196,  1238,  1239,     6,
     178,   698,   178,   203,   701,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   185,
       6,   186,   719,   177,   165,     7,   723,   724,   725,   726,
       7,     7,    73,     7,   731,     7,     7,     7,     6,     6,
     179,   738,     7,   740,   741,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   179,
     179,     7,     7,   177,   179,     7,     6,     4,     6,  1342,
       4,   768,    88,   185,   178,     6,    12,    13,     7,   776,
     777,   778,    98,   780,     6,  1342,     7,     7,     7,   185,
     106,   107,   108,     6,     6,   792,   112,   113,   114,   115,
     797,     6,    71,   800,   199,  1384,     6,  1386,  1380,  1388,
       6,     6,     4,   810,   811,   812,   813,  1396,     4,   816,
    1399,     4,   186,   179,     6,   220,     6,     4,   223,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     6,
      76,     7,   184,   179,   178,    81,    82,   179,    84,    85,
      86,   182,   247,   179,    90,     6,    88,     6,    81,   182,
       6,   185,     6,   185,     6,   862,    98,   185,     6,     6,
     186,     5,   185,   185,   106,   107,   108,   377,     4,   185,
     112,   113,   114,   115,     6,   185,     7,   123,   124,   125,
       7,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     7,     7,   302,   303,   177,
       7,     6,   185,     6,   180,     6,     6,     4,  1497,   314,
       6,   185,   185,  1464,   185,     6,   923,     6,     6,   926,
     127,   184,     6,     4,     4,   185,     4,     6,     5,   936,
       6,     6,     6,     6,     6,     6,     4,     6,   126,     6,
     186,     6,     6,     6,   186,   952,     6,   131,     6,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     6,     6,     6,     6,   177,     6,     6,
     184,     6,     6,  1556,   981,     6,   179,   487,   488,   489,
       6,     6,  1533,   187,     7,   992,   993,   182,   192,  1556,
       6,   185,   196,     6,     5,   186,  1003,  1004,   508,   203,
       6,     6,     6,    69,     6,  1588,  1556,  1590,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       6,  1588,   185,  1590,   177,  1608,     6,   537,   185,    88,
       6,   186,     7,     6,  1041,  1042,  1043,     6,  1588,    98,
    1590,  1608,   185,   185,  1051,   185,  1053,   106,   107,   108,
     185,     6,   186,   112,   113,   114,   115,  1064,  1608,   129,
       6,     6,     6,     6,     6,  1072,   270,     6,   272,     6,
     185,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     6,  1093,  1094,  1095,   177,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     6,     6,     6,     6,   177,    88,
       6,     6,     6,     6,   624,     6,   626,     6,  1125,     6,
       6,     6,     6,   185,   185,     6,     6,   186,     6,   186,
     185,   185,  1139,   186,   185,   185,   185,  1144,     6,     6,
       6,     6,     6,     6,  1151,     6,   185,     6,  1155,  1156,
       6,     6,   185,   185,     6,  1162,  1163,   185,   185,     6,
    1167,     6,   672,     6,     6,     6,  1467,  1001,  1175,    88,
    1361,   409,  1362,   377,     3,     3,   437,  1009,  1185,    98,
    1187,  1128,   587,    -1,    -1,    -1,    -1,   106,   107,   108,
       4,     5,  1199,   112,   113,   114,   115,    -1,    -1,    -1,
       6,    -1,    -1,    -1,  1211,    -1,    -1,   411,  1215,   719,
      -1,  1218,    -1,   723,   724,   725,   726,    -1,    -1,    -1,
      -1,   731,    -1,    -1,  1231,    39,    40,    41,    42,    43,
      44,    -1,  1239,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,  1255,  1256,
      64,    -1,    -1,    88,    -1,   660,  1263,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   671,   186,    -1,    -1,
     780,   106,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,   487,   488,   489,    -1,    -1,    -1,    -1,
    1297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     810,   811,   812,   813,   508,    -1,    -1,    -1,  1315,    -1,
    1317,   515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1328,    -1,  1330,    -1,    -1,  1333,    -1,    -1,    -1,
     144,   145,  1339,   537,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   747,    -1,    -1,  1352,    -1,    -1,    -1,    -1,
    1357,   186,   862,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
    1377,   177,    -1,    -1,    -1,    -1,    -1,  1384,    -1,  1386,
      -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1398,    -1,    -1,    -1,  1402,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
    1417,  1418,    -1,    -1,   177,  1422,    -1,    -1,    -1,    -1,
     624,    -1,   626,    -1,    -1,  1432,    -1,    -1,    -1,  1436,
      -1,    -1,   636,   637,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   848,   849,    -1,   851,    -1,   853,   854,
      -1,    -1,   857,   858,    -1,  1462,    -1,    -1,    -1,    -1,
    1467,    -1,    -1,    -1,    -1,    -1,    -1,  1474,   672,    -1,
      -1,    -1,    -1,    -1,  1481,    -1,    -1,  1484,    -1,     6,
    1487,    -1,    -1,    -1,  1491,    -1,    -1,    -1,  1495,    -1,
    1497,    -1,    -1,    -1,    -1,    -1,    -1,  1504,    -1,    -1,
    1507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,     6,   719,    -1,    -1,    -1,   723,
     724,   725,   726,    -1,    -1,    -1,    -1,   731,    88,    -1,
      -1,    -1,  1539,   938,   939,   940,    -1,    -1,    98,    -1,
      -1,    -1,    -1,   948,    -1,  1552,   106,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,  1072,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    -1,   780,    -1,    -1,    81,
      82,    -1,    84,    85,    86,    -1,    -1,    -1,    90,   994,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1010,   810,   811,   812,   813,
      -1,  1016,    -1,    -1,    -1,    88,    -1,  1022,    -1,  1024,
    1025,   123,   124,   125,  1029,     6,   186,    -1,    -1,  1034,
    1035,  1036,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,  1051,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   862,    -1,
      -1,  1066,    -1,    -1,    -1,  1070,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,   186,   177,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       3,     4,     5,    -1,   177,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,  1138,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    88,    -1,    -1,    51,    -1,
      53,    -1,    55,    56,    57,    98,    -1,    -1,    -1,    -1,
      63,    64,    -1,   106,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,  1178,  1179,  1180,  1181,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    88,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,  1213,    -1,
     106,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
    1225,    -1,    -1,  1333,    -1,    -1,    -1,  1232,    -1,  1234,
      -1,    -1,    -1,  1238,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   186,    -1,    -1,    -1,   150,   151,   152,
     153,   154,  1257,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,   168,   169,  1377,  1072,    -1,
     173,    -1,    -1,  1278,    -1,   178,    -1,   180,    -1,   182,
     183,    -1,   185,    -1,   187,    -1,    -1,    -1,  1398,    -1,
     186,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,     3,     4,   177,  1312,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,  1356,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,
      -1,     6,    -1,    -1,    63,    -1,    65,    -1,    -1,    68,
      -1,  1376,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1495,    85,  1497,  1393,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,  1211,    -1,    -1,
      -1,  1215,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1552,  1448,   143,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,
      -1,     6,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1506,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1317,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,  1333,
      -1,    -1,   177,     3,     4,  1339,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     7,    -1,    -1,
      -1,    -1,  1577,  1377,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,  1398,    65,    -1,    -1,    68,    -1,
      -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,   143,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,     8,    -1,
      -1,  1495,    -1,  1497,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,     8,   178,    -1,
      -1,    -1,    -1,   183,    -1,    -1,   186,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,  1552,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    -1,    53,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,    -1,    68,    -1,    -1,    71,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   178,    -1,     3,     4,     5,   183,    -1,
     185,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    12,    13,    -1,    -1,    55,    56,    57,
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
     178,    -1,     3,     4,     5,   183,    -1,   185,     9,    10,
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
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,   178,    -1,     3,     4,    -1,   183,
      -1,   185,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,   186,    -1,    -1,    12,    13,    -1,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,
      -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,   178,    -1,     3,     4,    -1,   183,    -1,   185,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,   186,    -1,
      -1,    12,    13,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,
       3,     4,    -1,   183,    -1,   185,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,   186,    -1,    -1,    12,    13,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    71,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,   178,    -1,     3,     4,    -1,
     183,    -1,   185,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,   186,    -1,    -1,    12,    13,    -1,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    71,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,   103,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,     8,    -1,    -1,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,
      -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   178,    -1,     3,     4,     5,   183,    -1,   185,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   186,
      -1,    -1,    51,    -1,    53,    -1,    55,    56,    57,    -1,
       3,     4,     5,    -1,    63,    64,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    64,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,   183,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,   178,    -1,     3,     4,     5,
     183,    -1,   185,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       8,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    -1,    53,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    71,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
      -1,    -1,    85,    -1,   150,   151,   152,   153,   154,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   183,    -1,   185,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,     8,    -1,   177,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,     3,     4,     5,    -1,   178,    -1,     9,    10,    11,
     183,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      -1,    53,    -1,    55,    56,    57,    -1,     3,     4,    -1,
      -1,    63,    64,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,   143,   144,   145,     8,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   183,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   143,    -1,    -1,
     177,    -1,    -1,    -1,   150,   151,   152,   153,   154,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   178,     3,     4,   181,    -1,   183,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,   143,    -1,    -1,    -1,   184,    -1,   186,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,   168,   169,
      -1,    -1,    -1,   173,    12,    13,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   183,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    37,
      38,    -1,   177,    -1,   179,    -1,    -1,    -1,    -1,   184,
      48,    49,    50,    -1,    52,    -1,    54,    -1,    -1,    -1,
      58,    59,    -1,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   262,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,   117,
       4,    -1,    -1,    -1,   122,   123,   124,   125,    12,    13,
     128,    -1,   130,    -1,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,   149,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    52,    -1,
      54,    -1,    -1,    -1,    58,    59,    -1,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    12,    13,    -1,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,    -1,    -1,   128,    -1,   130,    -1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    85,    86,    -1,    -1,    -1,
      90,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
      -1,    -1,    -1,   123,   124,   125,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   159,   160,   161,   162,
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
     146,   147,   148,   149,   191,   193,   194,   214,   228,   233,
     236,   237,   238,   239,   240,   241,   242,   262,   263,   264,
     265,   283,   284,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      51,    53,    55,    56,    57,    63,    64,   137,   143,   144,
     145,   150,   151,   152,   153,   154,   168,   169,   173,   178,
     180,   182,   183,   185,   187,   212,   266,   267,   279,   280,
     283,   284,    13,    71,   178,   178,     6,   185,     6,     6,
       6,   178,     6,     6,   180,   180,   178,   185,   178,   178,
       4,   178,   185,   178,   178,     4,   185,   178,   178,    75,
      71,    71,     6,   185,    65,    68,    71,    71,    71,    68,
      71,    73,    73,    65,    68,    71,    73,    68,    71,    73,
      68,    71,   178,    68,   128,   141,   142,   185,   168,   169,
     178,   185,   269,   270,   269,   185,    65,    68,    71,   185,
     269,     4,    65,    69,    81,    71,    73,    71,    68,     4,
     137,   185,     4,     6,    65,    68,    71,    68,    71,     4,
       4,     4,     4,     5,    36,    65,    68,    71,    73,    85,
     169,   178,   185,   233,   242,   266,   272,   273,   274,   284,
       4,   178,   178,   178,     4,   185,   276,     4,   178,   178,
       6,     6,   180,     4,     4,     5,   185,     5,   185,     4,
     266,     6,   178,   185,   178,   180,   187,     7,   155,   156,
     157,   158,   175,   176,   210,   211,     4,   180,   182,   178,
     180,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   178,   178,   178,   178,
     178,   178,   212,   212,     7,   178,   178,   178,   178,   178,
     266,   266,   266,   266,   181,   266,     4,   128,   129,     4,
     283,   284,     4,   233,   234,   235,   185,   185,     6,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   177,   185,     6,   180,   211,     6,   266,
       4,   279,   280,   284,   279,   266,   279,   282,   216,   219,
     266,   169,   266,   274,   275,   266,   266,   178,   266,   275,
     266,   266,   178,   275,   266,   266,   272,   178,   185,   275,
     273,   273,   273,   178,   178,   273,   273,   273,   178,   229,
     230,   231,   232,   178,   178,   178,   272,   266,     4,   272,
     276,   185,   185,   269,   269,   269,   266,   266,   168,   169,
     185,   185,   269,   185,   185,   185,   168,   169,   178,   235,
     269,   185,   178,   185,   178,   178,   178,   273,   273,   272,
     178,     4,     6,   180,   180,   235,     6,   185,   185,   185,
     273,   273,   180,   180,   180,   180,   182,   212,   180,     5,
     185,     5,     5,     5,    65,    68,    71,    73,   185,   266,
     274,   266,   186,   275,     8,   170,     6,     6,   266,   266,
     266,   182,   266,   185,   131,   266,   266,   266,     6,     6,
     235,     6,   235,   180,     6,   272,   272,   185,   266,   185,
     280,   272,     6,   180,   266,     4,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   282,   279,
     282,   279,   279,   279,   279,   279,   282,   266,   280,   266,
     279,   279,   279,   284,   280,   179,     7,   210,   181,     7,
     210,   211,   182,     7,   180,   186,    65,    68,    71,    73,
     228,   266,   275,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   195,   266,
       6,   180,   182,   179,   184,   179,   184,   184,   179,   184,
     181,   184,   215,   181,   215,   179,   170,   184,   186,   179,
     179,   266,   179,   186,   179,   179,   266,   186,   179,   179,
       7,   266,   266,   186,     6,     6,     6,   266,   266,     7,
       7,   260,   260,   266,   178,   178,   178,   178,   266,   266,
     266,     7,   185,   179,     6,   185,   235,   235,   184,   184,
     184,   269,   269,   234,   234,   184,   266,   266,   266,   266,
     246,   184,   235,   266,   266,   266,   266,   266,     7,   261,
       6,     7,   266,     6,   266,   266,   186,   275,   275,   275,
       6,     6,   266,   266,   266,   266,     4,   179,   181,   185,
     213,     4,   266,   185,   185,   185,   185,   275,   179,   186,
     266,   185,   266,   274,   179,   179,   179,   128,   184,   235,
     185,     8,   179,   181,   186,   186,   179,   184,   186,   275,
     181,   266,     6,     6,   266,   181,   211,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   184,   213,
     213,   213,   213,   213,   213,   213,   184,   184,   184,   213,
     184,   213,   213,   179,   179,   184,   184,   184,   179,   268,
     281,     6,   184,   179,   184,   179,   179,   210,   272,   182,
     210,   211,   280,   266,     6,     4,     4,   185,   277,   181,
     185,   185,   185,   185,   186,   186,     8,     4,   118,   119,
     120,   121,   186,   198,   202,   205,   207,   208,   181,   266,
       4,     6,   165,   192,   275,     6,   275,   266,     6,   279,
       6,   284,     6,   279,     7,   266,   274,   131,     7,     7,
     179,     7,   131,     7,     7,   179,   131,     7,     7,   266,
     179,   186,   185,   179,   179,   266,   272,     4,   259,     6,
     179,   225,   266,   280,   225,   225,   225,   179,   179,   179,
     272,   275,   182,   235,   186,   186,   269,   266,   266,   186,
     186,   266,   269,   184,   184,   184,    88,    98,   106,   107,
     108,   112,   113,   114,   115,   256,   257,   269,   186,   243,
     179,   186,   179,   179,   179,   266,     6,   266,   179,   181,
     181,   186,   186,   186,   181,   181,   184,   181,   275,   181,
     186,   275,   275,   275,   275,   186,     8,   275,     7,     7,
       7,   182,   266,   186,   266,   266,     7,   182,   185,   272,
       6,   186,   210,   211,   186,   181,   182,   211,   279,   266,
     266,   266,   266,   275,   279,   279,   279,   221,   223,   266,
     279,   266,     6,     4,   128,   129,   266,     6,     6,     6,
       7,   180,   276,   278,     6,   275,   275,   275,   275,   213,
     266,   199,   178,   178,   185,   209,     6,   211,   181,   165,
     279,   179,   179,   184,     7,   269,    71,    73,   272,   272,
       7,   272,    71,    73,   272,   272,     7,    73,   272,   272,
       6,     7,     7,   275,     7,     7,    88,   258,     6,     7,
     179,   179,   179,   179,     7,     7,     7,     6,   186,     4,
     186,   184,   184,   184,   186,   186,   269,   269,   269,     4,
       6,   185,     6,   178,     6,   116,     6,   116,     6,   116,
       6,   116,   186,   257,   184,   256,     7,     6,     7,     7,
       7,     6,   185,     6,     6,     6,    71,   266,     6,     6,
     266,   182,   186,   186,   186,   186,   186,   266,   186,   272,
     272,   272,     4,   184,     8,     8,   179,     4,     4,   272,
     186,   179,   266,     6,     6,     4,     6,   213,   213,   213,
     213,   213,   184,   179,   179,   184,   213,   222,   184,   213,
     224,   179,   179,     6,     7,   210,   211,   182,     7,     6,
     276,   266,   184,   186,   186,   186,   186,   186,   210,   178,
     266,   266,   271,   272,   185,   182,     6,     6,   192,     6,
     266,   185,   266,   280,     6,   185,   185,    81,   227,   227,
     272,     6,   185,   185,     6,     6,   272,   185,     6,     6,
       5,   272,   186,   272,   272,     4,     6,   272,     7,     7,
       7,     7,   272,   272,   272,     7,     6,     7,   266,   266,
     266,   185,   185,   184,   186,   184,   186,   184,   186,   180,
     266,   272,   266,     6,     6,     6,     6,   266,   269,   186,
       5,   185,   272,   185,   185,   185,   272,   275,   185,     6,
     181,     4,   213,     6,     6,   127,   266,   266,   266,     6,
       6,     7,   184,     6,   210,     6,   211,   279,     4,     4,
     280,   266,     6,     4,   277,     6,   181,   276,     6,     6,
       6,     6,   272,   196,   266,   184,   184,   184,   186,   197,
     266,     4,   279,   184,   266,   280,   266,   266,   269,     6,
       6,     6,   266,   266,     6,   266,     5,     6,   185,     6,
     131,   226,   266,     6,   272,   272,   272,   272,     6,     4,
       6,     6,   266,   266,   280,   186,   179,   184,   186,   234,
     234,   269,     6,   247,   269,     6,   248,   269,     6,   249,
     266,   186,   184,   179,   186,   184,     6,   169,   269,     6,
     271,   269,   269,     6,   186,   266,     6,   272,   184,   186,
       8,   186,   179,   185,   266,   280,   272,   272,   179,   185,
     272,   280,   185,   266,   280,     6,     6,     7,     6,   182,
       6,   179,   184,   266,   266,   272,   185,   184,   186,     6,
     266,   217,   218,   186,   186,   186,   186,   186,     5,   271,
      69,     6,     6,     6,     6,     6,   185,   185,     6,     6,
     185,   266,   186,   186,   184,   185,   184,   185,   184,   185,
     181,     6,   272,     7,   185,   266,   184,   186,   184,   184,
       6,   186,   126,   266,   266,   275,     6,     6,   186,     6,
     220,   266,   282,   276,   129,   200,   266,   184,   184,   271,
     266,     6,   184,   221,   223,     6,     6,     6,     6,     6,
       6,   186,   185,   271,   275,   234,   184,   186,   266,   269,
     256,   266,   269,   256,   266,   269,   256,     6,   184,   186,
     272,   235,   186,   269,     6,   275,   269,   266,   186,   186,
     186,     6,   184,   186,     7,   186,     6,   185,   266,   266,
     186,   266,   186,   186,   185,   266,   186,   186,   186,   266,
     186,   184,   186,   186,   184,   186,   186,   184,   186,   272,
       6,    88,   186,   244,   185,   184,   186,   184,     6,     6,
     266,   280,   197,   179,   184,     6,   185,   184,   266,   186,
       6,     6,   186,     6,   250,   266,     6,     6,   251,   266,
       6,     6,   252,   266,     6,   186,   266,   256,   235,   275,
       6,   269,   275,     7,   186,   203,   266,   271,   266,   184,
     185,   186,   185,   186,   185,   186,     6,     6,   186,   186,
     245,   186,   184,   186,   280,     6,   185,   179,   186,   186,
     266,   256,     6,   253,   256,     6,   254,   256,     6,   255,
     256,     6,   275,     6,   201,   279,   206,   185,     6,   186,
     186,   185,   186,   185,   186,   185,   186,   186,   184,   186,
     185,   271,     6,     6,   256,     6,   256,     6,   256,     6,
     279,     6,   204,   279,   186,   186,   186,   186,   184,   186,
       6,     6,     6,     6,   279,     6
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
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 753 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 758 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 763 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 770 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 777 "Gmsh.y"
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

  case 79:
/* Line 1787 of yacc.c  */
#line 792 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 797 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 802 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 811 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 817 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 826 "Gmsh.y"
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

  case 85:
/* Line 1787 of yacc.c  */
#line 844 "Gmsh.y"
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

  case 86:
/* Line 1787 of yacc.c  */
#line 862 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 871 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 883 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 888 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 896 "Gmsh.y"
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

  case 91:
/* Line 1787 of yacc.c  */
#line 916 "Gmsh.y"
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

  case 92:
/* Line 1787 of yacc.c  */
#line 939 "Gmsh.y"
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

  case 93:
/* Line 1787 of yacc.c  */
#line 950 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 958 "Gmsh.y"
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

  case 95:
/* Line 1787 of yacc.c  */
#line 980 "Gmsh.y"
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

  case 96:
/* Line 1787 of yacc.c  */
#line 1003 "Gmsh.y"
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

  case 97:
/* Line 1787 of yacc.c  */
#line 1029 "Gmsh.y"
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

  case 98:
/* Line 1787 of yacc.c  */
#line 1050 "Gmsh.y"
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

  case 99:
/* Line 1787 of yacc.c  */
#line 1062 "Gmsh.y"
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

  case 103:
/* Line 1787 of yacc.c  */
#line 1080 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 1089 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 1098 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 1100 "Gmsh.y"
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

  case 107:
/* Line 1787 of yacc.c  */
#line 1110 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 1119 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1121 "Gmsh.y"
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

  case 111:
/* Line 1787 of yacc.c  */
#line 1135 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1143 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1149 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1161 "Gmsh.y"
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

  case 117:
/* Line 1787 of yacc.c  */
#line 1172 "Gmsh.y"
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

  case 118:
/* Line 1787 of yacc.c  */
#line 1187 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 1203 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 1211 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1220 "Gmsh.y"
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

  case 124:
/* Line 1787 of yacc.c  */
#line 1238 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1242 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1252 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1256 "Gmsh.y"
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

  case 128:
/* Line 1787 of yacc.c  */
#line 1268 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1272 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1282 "Gmsh.y"
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

  case 131:
/* Line 1787 of yacc.c  */
#line 1305 "Gmsh.y"
    {
      curPhysDim = 0;
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1309 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1325 "Gmsh.y"
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

  case 134:
/* Line 1787 of yacc.c  */
#line 1347 "Gmsh.y"
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

  case 135:
/* Line 1787 of yacc.c  */
#line 1365 "Gmsh.y"
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

  case 136:
/* Line 1787 of yacc.c  */
#line 1386 "Gmsh.y"
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

  case 137:
/* Line 1787 of yacc.c  */
#line 1404 "Gmsh.y"
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

  case 138:
/* Line 1787 of yacc.c  */
#line 1434 "Gmsh.y"
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

  case 139:
/* Line 1787 of yacc.c  */
#line 1464 "Gmsh.y"
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

  case 140:
/* Line 1787 of yacc.c  */
#line 1482 "Gmsh.y"
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

  case 141:
/* Line 1787 of yacc.c  */
#line 1501 "Gmsh.y"
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

  case 142:
/* Line 1787 of yacc.c  */
#line 1527 "Gmsh.y"
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

  case 143:
/* Line 1787 of yacc.c  */
#line 1545 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1563 "Gmsh.y"
    {
      curPhysDim = 1;
    }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1567 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1586 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1604 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1643 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1649 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1655 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1662 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1687 "Gmsh.y"
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

  case 153:
/* Line 1787 of yacc.c  */
#line 1712 "Gmsh.y"
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

  case 154:
/* Line 1787 of yacc.c  */
#line 1729 "Gmsh.y"
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

  case 155:
/* Line 1787 of yacc.c  */
#line 1749 "Gmsh.y"
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

  case 156:
/* Line 1787 of yacc.c  */
#line 1782 "Gmsh.y"
    {
      curPhysDim = 2;
    }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1786 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1806 "Gmsh.y"
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

  case 159:
/* Line 1787 of yacc.c  */
#line 1824 "Gmsh.y"
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

  case 160:
/* Line 1787 of yacc.c  */
#line 1841 "Gmsh.y"
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

  case 161:
/* Line 1787 of yacc.c  */
#line 1857 "Gmsh.y"
    {
      curPhysDim = 3;
    }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1861 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1883 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1888 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1893 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1898 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1903 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1908 "Gmsh.y"
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

  case 169:
/* Line 1787 of yacc.c  */
#line 1931 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1937 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1947 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1948 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1953 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1957 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1961 "Gmsh.y"
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

  case 176:
/* Line 1787 of yacc.c  */
#line 1984 "Gmsh.y"
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

  case 177:
/* Line 1787 of yacc.c  */
#line 2007 "Gmsh.y"
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

  case 178:
/* Line 1787 of yacc.c  */
#line 2030 "Gmsh.y"
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

  case 179:
/* Line 1787 of yacc.c  */
#line 2058 "Gmsh.y"
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

  case 180:
/* Line 1787 of yacc.c  */
#line 2079 "Gmsh.y"
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

  case 181:
/* Line 1787 of yacc.c  */
#line 2106 "Gmsh.y"
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

  case 182:
/* Line 1787 of yacc.c  */
#line 2127 "Gmsh.y"
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

  case 183:
/* Line 1787 of yacc.c  */
#line 2148 "Gmsh.y"
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

  case 184:
/* Line 1787 of yacc.c  */
#line 2168 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2280 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2299 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2338 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2446 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 2455 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 2461 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2476 "Gmsh.y"
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

  case 192:
/* Line 1787 of yacc.c  */
#line 2504 "Gmsh.y"
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

  case 193:
/* Line 1787 of yacc.c  */
#line 2521 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 2530 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 2544 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 2550 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 2556 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 2565 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2574 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2583 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2597 "Gmsh.y"
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

  case 202:
/* Line 1787 of yacc.c  */
#line 2653 "Gmsh.y"
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

  case 203:
/* Line 1787 of yacc.c  */
#line 2678 "Gmsh.y"
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

  case 204:
/* Line 1787 of yacc.c  */
#line 2695 "Gmsh.y"
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

  case 205:
/* Line 1787 of yacc.c  */
#line 2710 "Gmsh.y"
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

  case 206:
/* Line 1787 of yacc.c  */
#line 2729 "Gmsh.y"
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

  case 207:
/* Line 1787 of yacc.c  */
#line 2741 "Gmsh.y"
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

  case 208:
/* Line 1787 of yacc.c  */
#line 2765 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 2769 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 2774 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 2781 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2787 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 2792 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2798 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2806 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2810 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2814 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2820 "Gmsh.y"
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

  case 219:
/* Line 1787 of yacc.c  */
#line 2874 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2887 "Gmsh.y"
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

  case 221:
/* Line 1787 of yacc.c  */
#line 2904 "Gmsh.y"
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

  case 222:
/* Line 1787 of yacc.c  */
#line 2921 "Gmsh.y"
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

  case 223:
/* Line 1787 of yacc.c  */
#line 2942 "Gmsh.y"
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

  case 224:
/* Line 1787 of yacc.c  */
#line 2963 "Gmsh.y"
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

  case 225:
/* Line 1787 of yacc.c  */
#line 2998 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 3006 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 3012 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 3019 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 3023 "Gmsh.y"
    {
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 3032 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3040 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3048 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3056 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3062 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3070 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3076 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3084 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3090 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3098 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3104 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3119 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3126 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3133 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3140 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3147 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3154 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3161 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3168 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3175 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3188 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3194 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3201 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3207 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3214 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3220 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3227 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3233 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3240 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3246 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3253 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3266 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3272 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3279 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3285 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3296 "Gmsh.y"
    {
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3299 "Gmsh.y"
    {
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3305 "Gmsh.y"
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

  case 271:
/* Line 1787 of yacc.c  */
#line 3317 "Gmsh.y"
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

  case 272:
/* Line 1787 of yacc.c  */
#line 3337 "Gmsh.y"
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

  case 273:
/* Line 1787 of yacc.c  */
#line 3361 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3365 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3369 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3373 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3377 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3383 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3389 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3393 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3397 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3401 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3405 "Gmsh.y"
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

  case 284:
/* Line 1787 of yacc.c  */
#line 3424 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3436 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3440 "Gmsh.y"
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

  case 287:
/* Line 1787 of yacc.c  */
#line 3455 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3459 "Gmsh.y"
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

  case 289:
/* Line 1787 of yacc.c  */
#line 3475 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3479 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3484 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3488 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3495 "Gmsh.y"
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

  case 294:
/* Line 1787 of yacc.c  */
#line 3551 "Gmsh.y"
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

  case 295:
/* Line 1787 of yacc.c  */
#line 3621 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3626 "Gmsh.y"
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

  case 297:
/* Line 1787 of yacc.c  */
#line 3693 "Gmsh.y"
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
              yymsg(1, "Unknown region %d", (int)d);
          }
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3729 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3737 "Gmsh.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 3780 "Gmsh.y"
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

  case 301:
/* Line 1787 of yacc.c  */
#line 3819 "Gmsh.y"
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

  case 302:
/* Line 1787 of yacc.c  */
#line 3839 "Gmsh.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 3867 "Gmsh.y"
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

  case 304:
/* Line 1787 of yacc.c  */
#line 3906 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iPoint;
            List_Read((yyvsp[(3) - (10)].l), i, &iPoint);
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3929 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iCurve;
            List_Read((yyvsp[(3) - (10)].l), i, &iCurve);
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
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

  case 306:
/* Line 1787 of yacc.c  */
#line 3952 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 3956 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 3960 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedSurfaces(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iSurface;
            List_Read((yyvsp[(3) - (10)].l), i, &iSurface);
            GFace *gf = GModel::current()->getFaceByTag(iSurface);
            if(gf)
              gr->addEmbeddedFace(gf);
            else
              yymsg(0, "Unknown surface %d", iSurface);
          }
        }
        else
          yymsg(0, "Unknown region %d", (int)(yyvsp[(8) - (10)].d));
      }
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3983 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 4022 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4061 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 4082 "Gmsh.y"
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

  case 313:
/* Line 1787 of yacc.c  */
#line 4103 "Gmsh.y"
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

  case 314:
/* Line 1787 of yacc.c  */
#line 4130 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 4134 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4144 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4178 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 4179 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 4180 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 4185 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4191 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4203 "Gmsh.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 4221 "Gmsh.y"
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

  case 324:
/* Line 1787 of yacc.c  */
#line 4248 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4249 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4250 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4251 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4252 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 4253 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4254 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4255 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4257 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4263 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4264 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4265 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4266 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4267 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4268 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4269 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4270 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4271 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4272 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4273 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4274 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4275 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4276 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4277 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4278 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4279 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4280 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4281 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4282 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4283 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4284 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4285 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4286 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4287 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4288 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4289 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4290 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4291 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4292 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4293 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4294 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4295 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4304 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4305 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4306 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4307 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4308 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4309 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4310 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4311 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4312 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4313 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4318 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4320 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4326 "Gmsh.y"
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

  case 379:
/* Line 1787 of yacc.c  */
#line 4343 "Gmsh.y"
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

  case 380:
/* Line 1787 of yacc.c  */
#line 4361 "Gmsh.y"
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

  case 381:
/* Line 1787 of yacc.c  */
#line 4379 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4384 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4390 "Gmsh.y"
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

  case 384:
/* Line 1787 of yacc.c  */
#line 4402 "Gmsh.y"
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

  case 385:
/* Line 1787 of yacc.c  */
#line 4419 "Gmsh.y"
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

  case 386:
/* Line 1787 of yacc.c  */
#line 4437 "Gmsh.y"
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

  case 387:
/* Line 1787 of yacc.c  */
#line 4458 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4463 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4478 "Gmsh.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 4488 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4493 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4502 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4507 "Gmsh.y"
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

  case 395:
/* Line 1787 of yacc.c  */
#line 4534 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 4538 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4542 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4546 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4550 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4557 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4561 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4565 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4569 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4576 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4581 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4588 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4593 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4597 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4602 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4606 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4614 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4625 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4629 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4641 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4649 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4657 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4664 "Gmsh.y"
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

  case 418:
/* Line 1787 of yacc.c  */
#line 4674 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
	yymsg(0, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
	double d = 0.0;
	List_Add((yyval.l), &d);
	List_Add((yyval.l), &d);
	List_Add((yyval.l), &d);
      }
      else{
	List_Add((yyval.l), &v->Pos.X);
	List_Add((yyval.l), &v->Pos.Y);
	List_Add((yyval.l), &v->Pos.Z);
      }
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4694 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4698 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4702 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4706 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4710 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[0].find((int)num);
          if(it != groups[0].end()){
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

  case 424:
/* Line 1787 of yacc.c  */
#line 4739 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[1].find((int)num);
          if(it != groups[1].end()){
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

  case 425:
/* Line 1787 of yacc.c  */
#line 4768 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[2].find((int)num);
          if(it != groups[2].end()){
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

  case 426:
/* Line 1787 of yacc.c  */
#line 4797 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[3].find((int)num);
          if(it != groups[3].end()){
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
#line 4826 "Gmsh.y"
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

  case 428:
/* Line 1787 of yacc.c  */
#line 4836 "Gmsh.y"
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

  case 429:
/* Line 1787 of yacc.c  */
#line 4846 "Gmsh.y"
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

  case 430:
/* Line 1787 of yacc.c  */
#line 4858 "Gmsh.y"
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

  case 431:
/* Line 1787 of yacc.c  */
#line 4870 "Gmsh.y"
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

  case 432:
/* Line 1787 of yacc.c  */
#line 4891 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4896 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4900 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 4904 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 4916 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 4920 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 4932 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 4939 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 4949 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 4953 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 4968 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 4973 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 4980 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 4984 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 4997 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 5005 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5016 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5020 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5028 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5034 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5042 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5050 "Gmsh.y"
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

  case 454:
/* Line 1787 of yacc.c  */
#line 5065 "Gmsh.y"
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

  case 455:
/* Line 1787 of yacc.c  */
#line 5079 "Gmsh.y"
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

  case 456:
/* Line 1787 of yacc.c  */
#line 5093 "Gmsh.y"
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

  case 457:
/* Line 1787 of yacc.c  */
#line 5105 "Gmsh.y"
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

  case 458:
/* Line 1787 of yacc.c  */
#line 5121 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5125 "Gmsh.y"
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

  case 460:
/* Line 1787 of yacc.c  */
#line 5144 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5146 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5157 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5162 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5168 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5177 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5190 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5193 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 10810 "Gmsh.tab.cpp"
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
#line 5197 "Gmsh.y"


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
