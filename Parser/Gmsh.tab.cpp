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
#define YYLAST   8865

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  188
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  473
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1682

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
     590,   593,   597,   601,   607,   609,   611,   613,   615,   617,
     619,   621,   623,   624,   630,   631,   634,   642,   651,   673,
     680,   688,   693,   701,   710,   719,   727,   735,   747,   756,
     765,   774,   796,   805,   815,   819,   824,   835,   843,   851,
     860,   869,   882,   891,   913,   922,   930,   939,   948,   970,
     976,   988,   994,  1004,  1014,  1019,  1029,  1039,  1041,  1043,
    1044,  1047,  1054,  1061,  1068,  1075,  1084,  1095,  1110,  1127,
    1140,  1149,  1158,  1165,  1180,  1185,  1192,  1199,  1203,  1208,
    1214,  1221,  1225,  1229,  1234,  1240,  1245,  1251,  1255,  1261,
    1269,  1277,  1281,  1289,  1293,  1296,  1299,  1302,  1305,  1321,
    1324,  1327,  1330,  1333,  1336,  1353,  1357,  1364,  1373,  1382,
    1393,  1395,  1398,  1400,  1404,  1409,  1411,  1417,  1429,  1443,
    1444,  1452,  1453,  1467,  1468,  1484,  1485,  1492,  1501,  1510,
    1519,  1532,  1545,  1558,  1573,  1588,  1603,  1604,  1617,  1618,
    1631,  1632,  1645,  1646,  1663,  1664,  1681,  1682,  1699,  1700,
    1719,  1720,  1739,  1740,  1759,  1761,  1764,  1770,  1778,  1788,
    1791,  1794,  1797,  1801,  1804,  1808,  1811,  1815,  1818,  1822,
    1832,  1839,  1840,  1844,  1845,  1847,  1848,  1851,  1852,  1855,
    1863,  1870,  1879,  1885,  1889,  1897,  1903,  1908,  1915,  1922,
    1935,  1946,  1957,  1968,  1979,  1990,  1995,  2000,  2005,  2010,
    2015,  2018,  2022,  2029,  2031,  2033,  2035,  2038,  2044,  2052,
    2063,  2065,  2069,  2072,  2075,  2078,  2082,  2086,  2090,  2094,
    2098,  2102,  2106,  2110,  2114,  2118,  2122,  2126,  2130,  2134,
    2140,  2145,  2150,  2155,  2160,  2165,  2170,  2175,  2180,  2185,
    2190,  2197,  2202,  2207,  2212,  2217,  2222,  2227,  2232,  2239,
    2246,  2253,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2272,
    2274,  2276,  2278,  2279,  2286,  2288,  2293,  2298,  2303,  2308,
    2313,  2316,  2322,  2328,  2332,  2339,  2344,  2352,  2359,  2366,
    2373,  2378,  2380,  2383,  2386,  2390,  2394,  2406,  2416,  2424,
    2432,  2434,  2438,  2440,  2442,  2445,  2449,  2454,  2460,  2462,
    2464,  2467,  2471,  2475,  2481,  2486,  2489,  2492,  2495,  2498,
    2504,  2510,  2516,  2522,  2524,  2526,  2530,  2535,  2542,  2544,
    2546,  2550,  2554,  2564,  2572,  2574,  2580,  2584,  2591,  2593,
    2597,  2599,  2601,  2605,  2612,  2614,  2616,  2618,  2623,  2630,
    2635,  2640,  2645,  2654,  2659,  2664,  2671,  2672,  2679,  2681,
    2685,  2691,  2697,  2699
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
     180,   181,   210,   271,     6,    -1,     4,   180,   265,   181,
     210,   265,     6,    -1,     4,   178,   265,   179,   210,   265,
       6,    -1,   282,   180,   265,   181,   210,   265,     6,    -1,
       4,   212,   185,   274,   186,   213,   210,   271,     6,    -1,
     282,   178,   185,   274,   186,   179,   210,   271,     6,    -1,
     283,   211,     6,    -1,     4,   180,   265,   181,   211,     6,
      -1,   282,   180,   265,   181,   211,     6,    -1,   283,     7,
     279,     6,    -1,     4,   182,     4,     7,   279,     6,    -1,
       4,   180,   265,   181,   182,     4,     7,   279,     6,    -1,
       4,   182,     4,   210,   265,     6,    -1,     4,   180,   265,
     181,   182,     4,   210,   265,     6,    -1,     4,   182,     4,
     211,     6,    -1,     4,   180,   265,   181,   182,     4,   211,
       6,    -1,     4,   182,   128,   182,     4,     7,   275,     6,
      -1,     4,   180,   265,   181,   182,   128,   182,     4,     7,
     275,     6,    -1,     4,   182,   129,     7,   276,     6,    -1,
       4,   180,   265,   181,   182,   129,     7,   276,     6,    -1,
       4,   137,     7,   265,     6,    -1,   137,   180,   265,   181,
       7,     4,     6,    -1,   137,   180,   265,   181,   182,     4,
       7,   265,     6,    -1,   137,   180,   265,   181,   182,     4,
       7,   279,     6,    -1,   137,   180,   265,   181,   182,     4,
       7,   185,   274,   186,     6,    -1,   137,   180,   265,   181,
     182,     4,     6,    -1,    89,   178,     4,   179,   182,     4,
       7,   265,     6,    -1,    89,   178,     4,   179,   182,     4,
       7,   279,     6,    -1,    -1,   184,    -1,    -1,   216,   215,
     283,    -1,   216,   215,   283,     7,   265,    -1,    -1,   216,
     215,   283,     7,   185,   265,   217,   221,   186,    -1,   216,
     215,   283,     7,   279,    -1,    -1,   216,   215,   283,     7,
     185,   279,   218,   223,   186,    -1,    -1,   219,   215,   278,
      -1,   265,     7,   279,    -1,   220,   184,   265,     7,   279,
      -1,    -1,   221,   222,    -1,   184,     4,   271,    -1,   184,
       4,   185,   220,   186,    -1,   184,     4,   279,    -1,    -1,
     223,   224,    -1,   184,     4,   265,    -1,   184,     4,   279,
      -1,   184,     4,   185,   281,   186,    -1,   265,    -1,   279,
      -1,   265,    -1,   279,    -1,   265,    -1,   279,    -1,   265,
      -1,   279,    -1,    -1,   131,    69,   185,   265,   186,    -1,
      -1,    81,   268,    -1,    65,   178,   265,   179,     7,   268,
       6,    -1,    85,    65,   178,   225,   179,     7,   271,     6,
      -1,    85,    65,   178,   225,   179,   131,    48,   185,   265,
     184,   265,   184,   265,   184,   265,   184,   265,   184,   265,
     186,     6,    -1,    74,    75,   271,     7,   265,     6,    -1,
      68,   178,   265,   179,     7,   271,     6,    -1,    90,    68,
     271,     6,    -1,    72,   178,   265,   179,     7,   271,     6,
      -1,    66,   178,   265,   179,     7,   271,   230,     6,    -1,
      67,   178,   265,   179,     7,   271,   230,     6,    -1,   123,
     178,   265,   179,     7,   271,     6,    -1,   124,   178,   265,
     179,     7,   271,     6,    -1,   125,   178,   265,   179,     7,
     271,   127,   271,   126,   265,     6,    -1,    68,     4,   178,
     265,   179,     7,   271,     6,    -1,    86,    68,   178,   265,
     179,     7,   271,     6,    -1,    85,    68,   178,   226,   179,
       7,   271,     6,    -1,    85,    68,   178,   226,   179,   131,
      48,   185,   265,   184,   265,   184,   265,   184,   265,   184,
     265,   184,   265,   186,     6,    -1,    81,    71,   178,   265,
     179,     7,   271,     6,    -1,    82,    71,   178,   265,   179,
       7,   271,   229,     6,    -1,    12,    13,     6,    -1,    13,
      71,   265,     6,    -1,    76,    71,   178,   265,   179,     7,
       5,     5,     5,     6,    -1,    69,   178,   265,   179,     7,
     271,     6,    -1,    70,   178,   265,   179,     7,   271,     6,
      -1,    71,     4,   178,   265,   179,     7,   271,     6,    -1,
      86,    71,   178,   265,   179,     7,   271,     6,    -1,    86,
      71,   178,   265,   179,     7,   271,     4,   185,   270,   186,
       6,    -1,    85,    71,   178,   227,   179,     7,   271,     6,
      -1,    85,    71,   178,   227,   179,   131,    48,   185,   265,
     184,   265,   184,   265,   184,   265,   184,   265,   184,   265,
     186,     6,    -1,    84,    73,   178,   265,   179,     7,   271,
       6,    -1,    73,   178,   265,   179,     7,   271,     6,    -1,
      86,    73,   178,   265,   179,     7,   271,     6,    -1,    85,
      73,   178,   228,   179,     7,   271,     6,    -1,    85,    73,
     178,   228,   179,   131,    48,   185,   265,   184,   265,   184,
     265,   184,   265,   184,   265,   184,   265,   186,     6,    -1,
      93,   268,   185,   233,   186,    -1,    92,   185,   268,   184,
     268,   184,   265,   186,   185,   233,   186,    -1,    94,   268,
     185,   233,   186,    -1,    95,   185,   268,   184,   265,   186,
     185,   233,   186,    -1,    95,   185,   268,   184,   268,   186,
     185,   233,   186,    -1,     4,   185,   233,   186,    -1,   103,
      68,   185,   274,   186,    71,   185,   265,   186,    -1,   100,
      68,   178,   265,   179,   185,   274,   186,     6,    -1,   234,
      -1,   232,    -1,    -1,   234,   231,    -1,   234,    65,   185,
     274,   186,     6,    -1,   234,    68,   185,   274,   186,     6,
      -1,   234,    71,   185,   274,   186,     6,    -1,   234,    73,
     185,   274,   186,     6,    -1,    97,    81,   178,   265,   179,
       7,   271,     6,    -1,    97,    65,   178,   265,   179,     7,
     185,   270,   186,     6,    -1,    97,    81,   178,   265,   179,
       7,   185,   268,   184,   268,   184,   274,   186,     6,    -1,
      97,    81,   178,   265,   179,     7,   185,   268,   184,   268,
     184,   268,   184,   274,   186,     6,    -1,    97,    69,   178,
     265,   179,     7,   185,   268,   184,   274,   186,     6,    -1,
      97,     4,   178,   265,   179,     7,   271,     6,    -1,    97,
       4,   178,   265,   179,     7,     5,     6,    -1,    97,     4,
     185,   265,   186,     6,    -1,    97,     4,   178,   265,   179,
       7,   185,   268,   184,   268,   184,   274,   186,     6,    -1,
     101,   185,   234,   186,    -1,   101,   137,   180,   265,   181,
       6,    -1,   101,     4,   180,   265,   181,     6,    -1,   101,
       4,     6,    -1,   101,     4,     4,     6,    -1,   128,   275,
     185,   234,   186,    -1,    91,   128,   275,   185,   234,   186,
      -1,   141,     5,     6,    -1,   142,     5,     6,    -1,   141,
     185,   234,   186,    -1,    91,   141,   185,   234,   186,    -1,
     142,   185,   234,   186,    -1,    91,   142,   185,   234,   186,
      -1,     4,   279,     6,    -1,    54,   178,   281,   179,     6,
      -1,     4,     4,   180,   265,   181,   278,     6,    -1,     4,
       4,     4,   180,   265,   181,     6,    -1,     4,   265,     6,
      -1,    89,   178,     4,   179,   182,     4,     6,    -1,   122,
       4,     6,    -1,   135,     6,    -1,   136,     6,    -1,    52,
       6,    -1,    48,     6,    -1,    48,   185,   265,   184,   265,
     184,   265,   184,   265,   184,   265,   184,   265,   186,     6,
      -1,    49,     6,    -1,    50,     6,    -1,    58,     6,    -1,
      59,     6,    -1,    78,     6,    -1,    79,   185,   274,   186,
     185,   274,   186,   185,   270,   186,   185,   265,   184,   265,
     186,     6,    -1,   149,   265,     6,    -1,   130,   178,   265,
       8,   265,   179,    -1,   130,   178,   265,     8,   265,     8,
     265,   179,    -1,   130,     4,   131,   185,   265,     8,   265,
     186,    -1,   130,     4,   131,   185,   265,     8,   265,     8,
     265,   186,    -1,   132,    -1,   140,     4,    -1,   138,    -1,
     139,     4,     6,    -1,   133,   178,   265,   179,    -1,   134,
      -1,    96,   268,   185,   234,   186,    -1,    96,   185,   268,
     184,   268,   184,   265,   186,   185,   234,   186,    -1,    96,
     185,   268,   184,   268,   184,   268,   184,   265,   186,   185,
     234,   186,    -1,    -1,    96,   268,   185,   234,   242,   255,
     186,    -1,    -1,    96,   185,   268,   184,   268,   184,   265,
     186,   185,   234,   243,   255,   186,    -1,    -1,    96,   185,
     268,   184,   268,   184,   268,   184,   265,   186,   185,   234,
     244,   255,   186,    -1,    -1,    96,   185,   234,   245,   255,
     186,    -1,    96,    65,   185,   265,   184,   268,   186,     6,
      -1,    96,    68,   185,   265,   184,   268,   186,     6,    -1,
      96,    71,   185,   265,   184,   268,   186,     6,    -1,    96,
      65,   185,   265,   184,   268,   184,   268,   184,   265,   186,
       6,    -1,    96,    68,   185,   265,   184,   268,   184,   268,
     184,   265,   186,     6,    -1,    96,    71,   185,   265,   184,
     268,   184,   268,   184,   265,   186,     6,    -1,    96,    65,
     185,   265,   184,   268,   184,   268,   184,   268,   184,   265,
     186,     6,    -1,    96,    68,   185,   265,   184,   268,   184,
     268,   184,   268,   184,   265,   186,     6,    -1,    96,    71,
     185,   265,   184,   268,   184,   268,   184,   268,   184,   265,
     186,     6,    -1,    -1,    96,    65,   185,   265,   184,   268,
     186,   246,   185,   255,   186,     6,    -1,    -1,    96,    68,
     185,   265,   184,   268,   186,   247,   185,   255,   186,     6,
      -1,    -1,    96,    71,   185,   265,   184,   268,   186,   248,
     185,   255,   186,     6,    -1,    -1,    96,    65,   185,   265,
     184,   268,   184,   268,   184,   265,   186,   249,   185,   255,
     186,     6,    -1,    -1,    96,    68,   185,   265,   184,   268,
     184,   268,   184,   265,   186,   250,   185,   255,   186,     6,
      -1,    -1,    96,    71,   185,   265,   184,   268,   184,   268,
     184,   265,   186,   251,   185,   255,   186,     6,    -1,    -1,
      96,    65,   185,   265,   184,   268,   184,   268,   184,   268,
     184,   265,   186,   252,   185,   255,   186,     6,    -1,    -1,
      96,    68,   185,   265,   184,   268,   184,   268,   184,   268,
     184,   265,   186,   253,   185,   255,   186,     6,    -1,    -1,
      96,    71,   185,   265,   184,   268,   184,   268,   184,   268,
     184,   265,   186,   254,   185,   255,   186,     6,    -1,   256,
      -1,   255,   256,    -1,   106,   185,   265,   186,     6,    -1,
     106,   185,   271,   184,   271,   186,     6,    -1,   106,   185,
     271,   184,   271,   184,   271,   186,     6,    -1,   107,     6,
      -1,    98,     6,    -1,   114,     6,    -1,   114,   116,     6,
      -1,   115,     6,    -1,   115,   116,     6,    -1,   112,     6,
      -1,   112,   116,     6,    -1,   113,     6,    -1,   113,   116,
       6,    -1,   108,   178,   265,   179,     7,   271,    88,   265,
       6,    -1,    88,     4,   180,   265,   181,     6,    -1,    -1,
      88,     4,   265,    -1,    -1,     4,    -1,    -1,     7,   271,
      -1,    -1,     7,   265,    -1,    83,    68,   272,     7,   265,
     257,     6,    -1,    83,    71,   272,   259,   258,     6,    -1,
      77,    71,   185,   265,   186,     7,   271,     6,    -1,    83,
      73,   272,   259,     6,    -1,   117,   272,     6,    -1,   104,
      71,   185,   274,   186,   265,     6,    -1,    98,    71,   272,
     260,     6,    -1,    98,    73,   272,     6,    -1,    99,    71,
     271,     7,   265,     6,    -1,    87,    68,   271,     7,   271,
       6,    -1,    87,    71,   265,   185,   274,   186,     7,   265,
     185,   274,   186,     6,    -1,    65,   185,   274,   186,   131,
      71,   185,   265,   186,     6,    -1,    68,   185,   274,   186,
     131,    71,   185,   265,   186,     6,    -1,    65,   185,   274,
     186,   131,    73,   185,   265,   186,     6,    -1,    68,   185,
     274,   186,   131,    73,   185,   265,   186,     6,    -1,    71,
     185,   274,   186,   131,    73,   185,   265,   186,     6,    -1,
     105,    71,   272,     6,    -1,   105,    68,   272,     6,    -1,
      80,    65,   272,     6,    -1,    80,    68,   272,     6,    -1,
      80,    71,   272,     6,    -1,   102,     6,    -1,   102,     4,
       6,    -1,   102,    65,   185,   274,   186,     6,    -1,   146,
      -1,   147,    -1,   148,    -1,   263,     6,    -1,   263,   185,
     271,   186,     6,    -1,   263,   185,   271,   184,   271,   186,
       6,    -1,   263,   178,   271,   179,   185,   271,   184,   271,
     186,     6,    -1,   266,    -1,   178,   265,   179,    -1,   169,
     265,    -1,   168,   265,    -1,   173,   265,    -1,   265,   169,
     265,    -1,   265,   168,   265,    -1,   265,   170,   265,    -1,
     265,   171,   265,    -1,   265,   172,   265,    -1,   265,   177,
     265,    -1,   265,   164,   265,    -1,   265,   165,   265,    -1,
     265,   167,   265,    -1,   265,   166,   265,    -1,   265,   163,
     265,    -1,   265,   162,   265,    -1,   265,   161,   265,    -1,
     265,   160,   265,    -1,   265,   159,   265,     8,   265,    -1,
      14,   212,   265,   213,    -1,    15,   212,   265,   213,    -1,
      16,   212,   265,   213,    -1,    17,   212,   265,   213,    -1,
      18,   212,   265,   213,    -1,    19,   212,   265,   213,    -1,
      20,   212,   265,   213,    -1,    21,   212,   265,   213,    -1,
      22,   212,   265,   213,    -1,    24,   212,   265,   213,    -1,
      25,   212,   265,   184,   265,   213,    -1,    26,   212,   265,
     213,    -1,    27,   212,   265,   213,    -1,    28,   212,   265,
     213,    -1,    29,   212,   265,   213,    -1,    30,   212,   265,
     213,    -1,    31,   212,   265,   213,    -1,    32,   212,   265,
     213,    -1,    33,   212,   265,   184,   265,   213,    -1,    34,
     212,   265,   184,   265,   213,    -1,    35,   212,   265,   184,
     265,   213,    -1,    23,   212,   265,   213,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   152,    -1,   153,    -1,
     154,    -1,    55,    -1,    56,    -1,    57,    -1,    -1,    63,
     212,   265,   267,   221,   213,    -1,   283,    -1,     4,   180,
     265,   181,    -1,   282,   180,   265,   181,    -1,   150,   178,
     283,   179,    -1,   151,   178,   279,   179,    -1,   183,   283,
     180,   181,    -1,   283,   211,    -1,     4,   180,   265,   181,
     211,    -1,   282,   180,   265,   181,   211,    -1,     4,   182,
       4,    -1,     4,   180,   265,   181,   182,     4,    -1,     4,
     182,     4,   211,    -1,     4,   180,   265,   181,   182,     4,
     211,    -1,   143,   178,   278,   184,   265,   179,    -1,    45,
     178,   278,   184,   278,   179,    -1,    46,   178,   278,   184,
     278,   179,    -1,    47,   178,   281,   179,    -1,   269,    -1,
     169,   268,    -1,   168,   268,    -1,   268,   169,   268,    -1,
     268,   168,   268,    -1,   185,   265,   184,   265,   184,   265,
     184,   265,   184,   265,   186,    -1,   185,   265,   184,   265,
     184,   265,   184,   265,   186,    -1,   185,   265,   184,   265,
     184,   265,   186,    -1,   178,   265,   184,   265,   184,   265,
     179,    -1,   271,    -1,   270,   184,   271,    -1,   265,    -1,
     273,    -1,   185,   186,    -1,   185,   274,   186,    -1,   169,
     185,   274,   186,    -1,   265,   170,   185,   274,   186,    -1,
     271,    -1,     5,    -1,   169,   273,    -1,   265,   170,   273,
      -1,   265,     8,   265,    -1,   265,     8,   265,     8,   265,
      -1,    65,   185,   265,   186,    -1,    65,     5,    -1,    68,
       5,    -1,    71,     5,    -1,    73,     5,    -1,    85,    65,
     185,   274,   186,    -1,    85,    68,   185,   274,   186,    -1,
      85,    71,   185,   274,   186,    -1,    85,    73,   185,   274,
     186,    -1,   232,    -1,   241,    -1,     4,   212,   213,    -1,
      36,   180,     4,   181,    -1,     4,   212,   185,   274,   186,
     213,    -1,   265,    -1,   273,    -1,   274,   184,   265,    -1,
     274,   184,   273,    -1,   185,   265,   184,   265,   184,   265,
     184,   265,   186,    -1,   185,   265,   184,   265,   184,   265,
     186,    -1,     4,    -1,     4,   182,   128,   182,     4,    -1,
     185,   277,   186,    -1,     4,   180,   265,   181,   182,   129,
      -1,   275,    -1,   277,   184,   275,    -1,   279,    -1,   283,
      -1,     4,   182,     4,    -1,     4,   180,   265,   181,   182,
       4,    -1,     5,    -1,    51,    -1,    53,    -1,   144,   178,
     278,   179,    -1,   145,   178,   278,   184,   278,   179,    -1,
      41,   212,   281,   213,    -1,    42,   178,   278,   179,    -1,
      43,   178,   278,   179,    -1,    44,   178,   278,   184,   278,
     184,   278,   179,    -1,    39,   212,   281,   213,    -1,    40,
     212,   278,   213,    -1,    40,   212,   278,   184,   274,   213,
      -1,    -1,    64,   212,   279,   280,   223,   213,    -1,   278,
      -1,   281,   184,   278,    -1,     4,   187,   185,   265,   186,
      -1,   282,   187,   185,   265,   186,    -1,     4,    -1,   282,
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
     656,   657,   718,   747,   752,   757,   762,   769,   776,   791,
     796,   801,   810,   816,   825,   843,   861,   870,   882,   887,
     895,   915,   938,   949,   957,   979,  1002,  1028,  1049,  1061,
    1075,  1075,  1077,  1079,  1088,  1098,  1097,  1109,  1119,  1118,
    1132,  1134,  1142,  1148,  1155,  1156,  1160,  1171,  1186,  1196,
    1197,  1202,  1210,  1219,  1237,  1241,  1250,  1254,  1263,  1267,
    1276,  1280,  1290,  1293,  1306,  1309,  1319,  1342,  1358,  1373,
    1395,  1413,  1434,  1452,  1482,  1512,  1530,  1548,  1575,  1593,
    1611,  1627,  1645,  1663,  1702,  1708,  1714,  1721,  1746,  1771,
    1788,  1807,  1841,  1857,  1876,  1894,  1911,  1927,  1943,  1964,
    1969,  1974,  1979,  1984,  1989,  2012,  2018,  2029,  2030,  2035,
    2038,  2042,  2065,  2088,  2111,  2139,  2160,  2186,  2207,  2229,
    2249,  2361,  2380,  2418,  2527,  2536,  2542,  2557,  2585,  2602,
    2611,  2625,  2631,  2637,  2646,  2655,  2664,  2678,  2734,  2759,
    2776,  2791,  2810,  2822,  2846,  2850,  2855,  2862,  2868,  2873,
    2879,  2887,  2891,  2895,  2900,  2955,  2968,  2985,  3002,  3023,
    3044,  3079,  3087,  3093,  3100,  3104,  3113,  3121,  3129,  3138,
    3137,  3152,  3151,  3166,  3165,  3180,  3179,  3193,  3200,  3207,
    3214,  3221,  3228,  3235,  3242,  3249,  3257,  3256,  3270,  3269,
    3283,  3282,  3296,  3295,  3309,  3308,  3322,  3321,  3335,  3334,
    3348,  3347,  3361,  3360,  3377,  3380,  3386,  3398,  3418,  3442,
    3446,  3450,  3454,  3458,  3464,  3470,  3474,  3478,  3482,  3486,
    3505,  3518,  3521,  3537,  3540,  3557,  3560,  3566,  3569,  3576,
    3632,  3702,  3707,  3774,  3810,  3818,  3861,  3900,  3920,  3947,
    3987,  4010,  4033,  4037,  4041,  4064,  4103,  4142,  4163,  4184,
    4211,  4215,  4225,  4260,  4261,  4262,  4266,  4272,  4284,  4302,
    4330,  4331,  4332,  4333,  4334,  4335,  4336,  4337,  4338,  4345,
    4346,  4347,  4348,  4349,  4350,  4351,  4352,  4353,  4354,  4355,
    4356,  4357,  4358,  4359,  4360,  4361,  4362,  4363,  4364,  4365,
    4366,  4367,  4368,  4369,  4370,  4371,  4372,  4373,  4374,  4375,
    4376,  4377,  4386,  4387,  4388,  4389,  4390,  4391,  4392,  4393,
    4394,  4395,  4400,  4399,  4407,  4424,  4442,  4460,  4465,  4471,
    4483,  4500,  4518,  4539,  4544,  4549,  4559,  4569,  4574,  4583,
    4588,  4615,  4619,  4623,  4627,  4631,  4638,  4642,  4646,  4650,
    4657,  4662,  4669,  4674,  4678,  4683,  4687,  4695,  4706,  4710,
    4722,  4730,  4738,  4745,  4755,  4784,  4788,  4792,  4796,  4800,
    4829,  4858,  4887,  4916,  4926,  4936,  4948,  4960,  4981,  4986,
    4990,  4994,  5006,  5010,  5022,  5029,  5039,  5043,  5058,  5063,
    5070,  5074,  5087,  5095,  5106,  5110,  5118,  5124,  5132,  5140,
    5155,  5169,  5183,  5195,  5211,  5215,  5235,  5234,  5247,  5252,
    5258,  5267,  5280,  5283
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
     215,   215,   216,   216,   216,   217,   216,   216,   218,   216,
     219,   219,   220,   220,   221,   221,   222,   222,   222,   223,
     223,   224,   224,   224,   225,   225,   226,   226,   227,   227,
     228,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   233,   234,
     234,   234,   234,   234,   234,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   236,   236,   236,   236,   236,   237,
     237,   238,   238,   238,   238,   238,   238,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   241,   241,   241,   242,
     241,   243,   241,   244,   241,   245,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   246,   241,   247,   241,
     248,   241,   249,   241,   250,   241,   251,   241,   252,   241,
     253,   241,   254,   241,   255,   255,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   257,   257,   258,   258,   259,   259,   260,   260,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     262,   262,   262,   263,   263,   263,   264,   264,   264,   264,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   267,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   268,   268,   268,   268,   268,   269,   269,   269,   269,
     270,   270,   271,   271,   271,   271,   271,   271,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   274,   274,
     274,   274,   275,   275,   275,   275,   276,   276,   277,   277,
     278,   278,   278,   278,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   280,   279,   281,   281,
     282,   282,   283,   283
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
       2,     3,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     0,     2,     7,     8,    21,     6,
       7,     4,     7,     8,     8,     7,     7,    11,     8,     8,
       8,    21,     8,     9,     3,     4,    10,     7,     7,     8,
       8,    12,     8,    21,     8,     7,     8,     8,    21,     5,
      11,     5,     9,     9,     4,     9,     9,     1,     1,     0,
       2,     6,     6,     6,     6,     8,    10,    14,    16,    12,
       8,     8,     6,    14,     4,     6,     6,     3,     4,     5,
       6,     3,     3,     4,     5,     4,     5,     3,     5,     7,
       7,     3,     7,     3,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,     3,     6,     8,     8,    10,
       1,     2,     1,     3,     4,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     2,     3,     2,     3,     2,     3,     2,     3,     9,
       6,     0,     3,     0,     1,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     7,     5,     4,     6,     6,    12,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     4,     4,     4,     4,
       2,     5,     5,     3,     6,     4,     7,     6,     6,     6,
       4,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     1,
       2,     3,     3,     5,     4,     2,     2,     2,     2,     5,
       5,     5,     5,     1,     1,     3,     4,     6,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     3,     6,     1,     1,     1,     4,     6,     4,
       4,     4,     8,     4,     4,     6,     0,     6,     1,     3,
       5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,   235,     0,     0,     0,   232,     0,     0,     0,     0,
     323,   324,   325,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   473,     0,   372,   472,   454,   373,   374,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     455,   456,   379,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,     0,     0,     0,    65,
      66,     0,     0,   179,     0,     0,     0,   330,     0,   450,
     473,   384,     0,     0,     0,     0,   217,     0,   219,   220,
     216,     0,   221,   222,   102,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   401,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,   472,   419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,   434,   412,   418,     0,   413,   384,
       0,     0,     0,     0,   444,     0,     0,     0,     0,     0,
     214,   215,     0,     0,   231,     0,   179,     0,   179,   472,
       0,   326,     0,     0,     0,     0,     0,    58,    62,    61,
      60,    59,    64,    63,     0,     0,     0,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     333,   332,   334,     0,     0,     0,     0,     0,     0,   472,
     473,     0,     0,   178,     0,   177,     0,     0,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,   207,     0,   390,   154,     0,
     472,     0,   450,   451,     0,     0,   468,     0,   100,   100,
       0,     0,   438,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   179,     0,   403,   402,     0,     0,     0,     0,
     179,   179,     0,     0,     0,     0,     0,     0,     0,   245,
       0,   179,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   197,     0,     0,     0,   321,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,   425,
       0,   426,   427,   428,     0,     0,     0,     0,     0,   332,
     420,     0,   414,     0,     0,     0,   303,   213,     0,     0,
       0,     0,     0,   179,     0,     0,     0,     0,   233,   201,
       0,   202,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   466,     0,
       0,     0,     0,     0,     0,   331,    58,     0,     0,    58,
       0,     0,     0,     0,     0,   174,     0,     0,     0,     0,
     180,     0,     0,     0,   348,   347,   346,   345,   341,   342,
     344,   343,   336,   335,   337,   338,   339,   340,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,   318,   319,     0,     0,     0,
       0,   293,     0,     0,     0,   124,   125,     0,   126,   127,
       0,   128,   129,     0,   130,   131,     0,     0,     0,     0,
       0,     0,   141,   179,     0,     0,     0,     0,     0,   405,
     404,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,     0,     0,     0,     0,     0,     0,     0,   306,     0,
       0,   198,     0,     0,   194,     0,     0,     0,   316,   315,
       0,     0,     0,     0,   393,    67,    68,     0,   435,     0,
       0,     0,     0,     0,     0,     0,   331,   415,   422,     0,
     337,   421,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,   203,   205,     0,     0,     0,     0,     0,     0,
      81,    71,     0,   385,   395,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   371,   359,     0,   361,   362,   363,
     364,   365,   366,   367,     0,     0,     0,   463,     0,   464,
     459,   460,   461,     0,     0,     0,   400,   114,   119,    92,
       0,   457,     0,   387,   388,     0,     0,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,   389,     0,     0,
       0,     0,   470,     0,     0,    43,     0,     0,     0,    56,
       0,    34,    35,    36,    37,    38,   386,     0,   452,    23,
      21,     0,     0,    24,     0,     0,   208,   469,    69,   103,
      70,   111,     0,   440,   441,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   296,   294,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,   206,     0,     0,     0,   169,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,   236,     0,     0,     0,     0,     0,
       0,   298,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,   436,   424,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,   327,     0,     0,     0,
     471,     0,     0,   391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,    79,    82,    84,     0,     0,   448,     0,
      90,     0,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,    29,   392,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,     0,   279,     0,   285,     0,   287,     0,   281,     0,
     283,     0,   246,   275,     0,     0,     0,   192,     0,     0,
       0,   307,     0,   196,   195,   322,     0,     0,    30,    31,
       0,     0,     0,   429,   430,   431,   432,   423,   417,     0,
       0,     0,   445,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,    80,   210,   394,   209,   360,   368,   369,
     370,   465,     0,   398,   399,     0,   383,   115,     0,   467,
     120,   397,   458,    74,    58,     0,     0,     0,     0,    73,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,     0,     0,    25,    26,     0,    27,
       0,     0,   104,   107,   136,     0,     0,     0,     0,     0,
       0,   140,     0,     0,   157,   158,     0,     0,   142,   165,
       0,     0,     0,     0,   132,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     212,     0,     0,     0,     0,   179,   179,     0,   256,     0,
     258,     0,   260,     0,   412,     0,     0,   286,   288,   282,
     284,     0,     0,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,   394,   437,   145,   146,     0,
       0,     0,     0,    93,    97,     0,     0,   328,     0,    75,
     396,     0,     0,     0,     0,     0,    87,     0,     0,    88,
       0,   449,   181,   182,   183,   184,     0,     0,    39,     0,
       0,     0,     0,     0,    41,   453,     0,     0,   105,   108,
       0,     0,   135,   143,   144,   148,     0,     0,   159,     0,
       0,   301,     0,   152,     0,     0,   292,   164,   137,     0,
     150,     0,   162,     0,   167,     0,   149,     0,   160,   166,
       0,     0,     0,     0,   409,     0,   408,     0,     0,     0,
     247,     0,     0,   248,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,   191,     0,     0,   190,     0,     0,
       0,   185,     0,     0,    32,     0,     0,   443,     0,   228,
     227,     0,     0,     0,     0,     0,   462,     0,   116,   118,
       0,   121,   122,    83,    85,     0,    91,     0,    76,    44,
       0,     0,     0,   411,     0,     0,     0,    28,     0,   114,
     119,     0,     0,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,    98,    99,   179,     0,
     172,   173,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,   179,     0,     0,     0,     0,     0,   176,   175,
       0,     0,     0,     0,    94,    95,     0,    77,     0,   438,
       0,     0,   447,     0,    40,     0,     0,     0,    42,    57,
       0,     0,     0,   310,   312,   311,   313,   314,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,     0,   241,     0,     0,   186,     0,     0,     0,
     442,   229,     0,   329,     0,   117,     0,   123,    89,     0,
       0,     0,     0,     0,   106,   109,     0,     0,     0,     0,
       0,     0,     0,     0,   170,     0,   262,     0,     0,   264,
       0,     0,   266,     0,     0,     0,   277,     0,   237,     0,
     179,     0,     0,     0,   147,    96,     0,   112,     0,    48,
       0,    54,     0,     0,     0,   133,     0,     0,     0,     0,
     161,   309,   406,   250,     0,     0,   257,   251,     0,     0,
     259,   252,     0,     0,   261,     0,     0,     0,   243,     0,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,     0,   270,     0,   272,
     278,   289,   242,   238,     0,     0,     0,     0,   113,    45,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,   254,     0,     0,   255,     0,     0,   193,
       0,   187,     0,    46,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,   224,     0,     0,     0,     0,   263,
       0,   265,     0,   267,     0,   188,    47,    49,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,   269,   271,   273,    51,    53,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   151,
     163,   168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   841,    85,    86,   618,  1267,  1273,
     831,   997,  1433,  1612,   832,  1565,  1648,   833,  1614,   834,
     835,  1001,   314,   397,   165,   728,    87,   632,   408,  1379,
    1380,   409,  1428,   973,  1127,   974,  1130,   664,   667,   670,
     673,  1295,  1168,   600,   273,   374,   375,    90,    91,    92,
      93,    94,    95,   274,   915,  1519,  1584,   698,  1321,  1324,
    1327,  1544,  1548,  1552,  1601,  1604,  1607,   911,   912,  1033,
     876,   661,   707,    97,    98,    99,   100,   275,   167,   797,
     455,   233,  1152,   276,   277,   278,   513,   286,   816,   989,
     406,   402,   798,   407,   170,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1176
static const yytype_int16 yypact[] =
{
    5260,    90,    19,  5399, -1176, -1176,  2212,    70,    48,     6,
      31,    37,   125,   223,   250,    84,   264,   361,   226,   249,
      89,   277,   295,    18,   322,   329,    16,   340,   343,   381,
     458,   461,   530,   367,   355,   490,   512,   567,   513,   592,
     604,    34,   430,   531,   168,   457,   239,   239,   465,   -12,
     216,   272,   546,   558,     4,    81,   566,   580,    91,   675,
     698,   707,  2955,   708,   523,   527,   538,    41,    40, -1176,
     559, -1176,   717,   718,   561, -1176,   740,   744,    49,    50,
   -1176, -1176, -1176,  4769, -1176, -1176, -1176, -1176, -1176, -1176,
   -1176, -1176, -1176, -1176, -1176, -1176, -1176, -1176, -1176,    29,
   -1176,  -120,   137, -1176,    13, -1176, -1176, -1176, -1176,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   571,   582,   597,   605,   606,   617,
   -1176, -1176, -1176, -1176, -1176,  -107,  -107,   738,   622,   656,
     662,   663,   671, -1176, -1176, -1176,  4769,  4769,  4769,  4769,
    4528,    14,   848,   269,   670,   674,  1639, -1176,   680,   854,
     111,   278,   860,  4769,    94,    94, -1176,  4769, -1176, -1176,
   -1176,    94, -1176, -1176, -1176, -1176,  4769,  4427,  4769,  4769,
     710,  4769,  4427,  4769,  4769,   743,  4427,  4769,  4769,  3309,
     765,   686, -1176,  4427,  2955,  2955,  2955,   766,   770,  2955,
    2955,  2955,   773,   785,   788,   794,   801,   806,   817,   824,
    3309,  4769,   910,  3309,    41,   826,   827,   239,   239,   239,
    4769,  4769,   -74, -1176,   -45,   239,   833,   834,   836,  1949,
      42,   102,   828,   844,   845,  2955,  2955,  3309,   846,    64,
     754, -1176,  1019, -1176,   841,   842,   843,  2955,  2955,   850,
     855,   858,   506, -1176,   863,    52,   911,  1035,  1037,   596,
    3486,  4769,  2594, -1176, -1176,  4936, -1176,  1038, -1176,   213,
    1043,  4769,  4769,  4769,   868,  4769,   866,   921,  4769,  4769,
   -1176, -1176,  4769,  1047, -1176,  1050, -1176,  1054, -1176,  -101,
    1738, -1176,  3309,  3309,   877,  4769,   878,   514, -1176, -1176,
   -1176, -1176, -1176, -1176,  3309,  1059,   886,  4769,  1063, -1176,
   -1176,  4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,
    4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,
    4769,  4769,  4769,    94,    94,    94,    94,    94,    94,    94,
      94,    94,  4769,   514,  4769,    94,    94,    94,   848,   514,
     892,   892,   892,  7974,   103,  7629,   335,   888,  1064,   890,
     896,   895,   899, -1176,   900,  5493,  4769,  4427, -1176,  4769,
    4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,  4769,
    4769,  4769,  4769,  4769, -1176, -1176,  4769, -1176, -1176,  1770,
     -90,   -64, -1176, -1176,   246,  6436, -1176,   384,   122,   184,
    7995,  4427,  4966, -1176,   -54,  8016,  8037,  4769,  8058,   228,
    8079,  8100,  4769,   441,  8121,  8142,  1078,  4769,  4769,   487,
    1081,  1085,  1087,  4769,  4769,  1088,  1096,  1096,  4769,  4598,
    4598,  4598,  4598,  4769,  4769,  4769,  1097,  6356,   915,  1099,
     926, -1176, -1176,    44, -1176, -1176,  6462,  6488,   239,   239,
     269,   269,   100,  4769,  4769,  4769,  1949,  1949,  4769,  5493,
     121, -1176,  4769,  4769,  4769,  4769,  4769,  1105,  1112,  1113,
    4769,  1115, -1176,  4769,  4769,  1647, -1176,  4427,  4427,  4427,
    1116,  1117,  4769,  4769,  4769,  4769,  1123,   123,  1126, -1176,
    4769, -1176, -1176, -1176,   934,   941,   946,   950,  4427,   892,
   -1176,  8163, -1176,   499,  4769,  3663, -1176, -1176,  8184,  8205,
    8226,  1009,  6514, -1176,   957,  4986,  8247,  7652, -1176, -1176,
    2641, -1176,  2994,  4769, -1176,   965,   536,  4427,  7675,  4769,
    1139,  1140, -1176,  4769,  7698,   300,  7606,  7606,  7606,  7606,
    7606,  7606,  7606,  7606,  7606,  7606,  7606,  6540,  7606,  7606,
    7606,  7606,  7606,  7606,  7606,  6566,  6592,  6618,   317,   421,
     317,   968,   970,   969,   972,   973,   406,  8688, -1176,  1855,
     974,   971,   978,   975,   984,   103, -1176,  3309,    96,   514,
    4769,  1163,  1169,    46,   995, -1176,   129,    45,    47,   159,
   -1176,  5488,   545,  5009,  1584,  1880,  1657,  1657,   477,   477,
     477,   477,    -7,    -7,   892,   892,   892,   892,     8,  7721,
   -1176,  4769,  1171,     7,  4427,  1175,  4427,  4769,  1179,    94,
    1180, -1176,   848,  1181,    94,  1185,  4427,  4427,  1065,  1187,
    1190,  8268,  1191,  1068,  1196,  1197,  8289,  1074,  1199,  1201,
    4769,  8310,  5516,  1028, -1176, -1176, -1176,  8331,  8352,  4769,
    3309,  1207,  1208,  8373,  1036,  8688, -1176,  1039,  8688, -1176,
    1042,  8688, -1176,  1045,  8688, -1176,  8394,  8415,  8436,  3309,
    4427,  1040, -1176, -1176,  3171,  3348,   239,  4769,  4769, -1176,
   -1176,  1041,  1046,  1949,  6644,  6670,  6696,  6410,   432,   239,
    3525,  8457,  5544,  8478,  8499,  8520,  4769,  1219, -1176,  4769,
    8541, -1176,  7744,  7767, -1176,   552,   575,   583, -1176, -1176,
    7790,  7813,  6722,  7836,   213, -1176, -1176,  4427, -1176,  1052,
    5572,  4427,  4427,  4427,  4427,   587, -1176, -1176,  5029,  4427,
     892, -1176,  1224,  1231,  1233,  1060,  4769,  3702,  4769,  4769,
   -1176,    65, -1176, -1176,  1056,  3309,  1237,   590,   348,  5600,
   -1176, -1176,  7859,   914, -1176, -1176, -1176, -1176, -1176, -1176,
   -1176, -1176, -1176, -1176, -1176, -1176,  4769, -1176, -1176, -1176,
   -1176, -1176, -1176, -1176,  4769,  4769,  4769, -1176,  4427, -1176,
   -1176, -1176, -1176,    94,    94,    94, -1176, -1176, -1176, -1176,
    4769, -1176,    94, -1176, -1176,  4769,  1240,    76,  4769,  1243,
    1245,  2361, -1176,  1248,  1072,    41,  1247, -1176,  4427,  4427,
    4427,  4427, -1176,   610,  4769, -1176,  1079,  1080,  1071, -1176,
    1253, -1176, -1176, -1176, -1176, -1176,   213,  7882, -1176, -1176,
    1095,    94,   449, -1176,   510,  6748, -1176, -1176, -1176,  1258,
   -1176, -1176,   239,  4966, -1176,   719,  3309,  3309,  1259,  3309,
     730,  3309,  3309,  1261,  1200,  3309,  3309,  2380,  1262,  1263,
    4427,  1265,  1270,  5115, -1176, -1176,  1272, -1176,  1273,    67,
      71,    75,    77,  1274,  1275,  1277,  1281,   620,  1285,  3879,
   -1176, -1176,   170,  6774,  6800, -1176, -1176,  5628,   -47,   239,
     239,   239,  1286,  1288,  1094,  1292,  1114,     9,    59,    60,
      63,   755, -1176,   172, -1176,   432,  1284,  1294,  1295,  1296,
    1300,  8688, -1176,  2723,  1129,  1310,  1311,  1312,  1230,  4769,
    1313,  1314,  4769,    73,   623, -1176, -1176,   624,   633,   636,
     637, -1176,  4769,   649,  3309,  3309,  3309,  1317,  6826, -1176,
    5056,  1445,  1319,  1320,  3309,  1146, -1176,  1136,  4769,  1327,
   -1176,  1329,  1321, -1176,  1330,  7606,  7606,  7606,  7606,   511,
    1142,  1158,  1159,   529,   551,  8562,  1160,  2743, -1176,   359,
    1161,  1334,  4156, -1176, -1176, -1176,    41,  4769, -1176,   661,
   -1176,   664,   672,   692,   693,   103,  8688,  1168,  4769,  4769,
    3309,  1162, -1176, -1176,  1166, -1176,  1343,    56,  1344,  4769,
    2150,     0,  1170,  1172,  1282,  1282,  3309,  1350,  1177,  1182,
    1359,  1360,  3309,  1183,  1364,  1365, -1176,  1367,  3309,   696,
    3309,  3309,  1369,  1368, -1176,  3309,  3309,  1328,  3309,  1333,
    3309,  1335,  3309,  1337,  3309,  3309,  3309, -1176,  1370,   473,
   -1176,  4769,  4769,  4769,  1202,  1203,   -93,   -80,   -68,  1195,
   -1176,  3309, -1176,  4769, -1176,  1376, -1176,  1380, -1176,  1384,
   -1176,  1386, -1176, -1176,  1949,   862,  3132, -1176,  1209,  1210,
    3840, -1176,  4427, -1176, -1176, -1176,  1214,  4558, -1176, -1176,
    7905,  1389,   610, -1176, -1176, -1176, -1176,  8688, -1176,  1396,
    1397,  1279, -1176,  4769,  4769,  4769, -1176,  1398,   542,  1227,
    1402,   103,  4677, -1176, -1176,   337, -1176, -1176, -1176, -1176,
   -1176, -1176,    94, -1176, -1176,  1408, -1176, -1176,  1409, -1176,
   -1176, -1176, -1176, -1176,   514,  4769,  1413,  1416,    46, -1176,
    1419,  7928,    41, -1176,  1420,  1421,  1422,  1425,  3309,  4769,
    6852,  6878,   697, -1176,  4769,  1429, -1176, -1176,    94, -1176,
    6904,  4598,  8688, -1176, -1176,  4769,  4769,   239,  1430,  1431,
    1432, -1176,  4769,  4769, -1176, -1176,  1433,  4769, -1176, -1176,
    1435,  1436,  1269,  1437,  1324,  4769, -1176,  1444,  1450,  1278,
    1451,  1290,  1458,  1291,  1465,  1299,  1467,   880,  1471,  4769,
   -1176,  4598,  5656,  8583,  5254,   269,   269,   239,  1473,   239,
    1479,   239,  1485,  4769,   232,  1308,  8604, -1176, -1176, -1176,
   -1176,  5684,   281, -1176,  1488,  2416,  1490,  3309,   239,  2416,
    1491,   701,  4769, -1176,  1492,   213, -1176, -1176, -1176,  3309,
    5425,   731,  8625, -1176, -1176,  4194,  3309, -1176,  3309, -1176,
   -1176,  1326,  2778,  4250,  1493,  4725, -1176,  1496,  1494, -1176,
    1331, -1176, -1176, -1176, -1176, -1176,  1500,   525,  8688,  4769,
    4769,  3309,  1323,   720,  8688, -1176,  1506,  4769,  8688, -1176,
    5712,  5740,   273, -1176, -1176, -1176,  5768,  5796, -1176,  5824,
    1509, -1176,  3309, -1176,  1447,  1512,  8688, -1176, -1176,  4769,
   -1176,  4769, -1176,  4769, -1176,  4769, -1176,  1336, -1176, -1176,
    6383,  4801,  1513,  1338, -1176,  4769, -1176,  1339,  1340,   382,
   -1176,  1349,   391, -1176,  1351,   403, -1176,  1352,  7951,  1514,
    3309,  1515,  1355,  4769, -1176,  4017,   405, -1176,   721,   408,
     411, -1176,  1522,  5852, -1176,  1412,  4769, -1176,  4769, -1176,
   -1176,  4427,  4821,  1529,  1356,  1535, -1176,  2594, -1176, -1176,
      94,  8688, -1176, -1176, -1176,    41, -1176,  1414, -1176, -1176,
    4769,  6930,  6956, -1176,  3309,  4769,  1538, -1176,  6982, -1176,
   -1176,  1542,  1543,  1544,  1545,  1546,  1548,   725,  1371, -1176,
    7008,  7034,  7060,  7086,  3309,  4427, -1176, -1176,   269,  5460,
   -1176, -1176,  1949,   432,  1949,   432,  1949,   432,  1549, -1176,
     726,  3309, -1176,  5880,   239,  1551,  4427,   239, -1176, -1176,
    4769,  5908,  5936,   729, -1176, -1176,  1552, -1176,   736,  4891,
     741,  1553, -1176,  1377,  8688,  4769,  4769,   745,  8688, -1176,
    4769,   746,   749, -1176, -1176, -1176, -1176, -1176, -1176,  1379,
    4769,  4769,  4769,  4769,  4769,   756,   763,  1375,  4769, -1176,
    5964,   425,   902,  5992,   428,   966,  6020,   435,   994, -1176,
    3309,  1561,  1480,  4056,  1385,   438, -1176,   775,   445,  4844,
   -1176, -1176,  1565, -1176,  4769, -1176,   514, -1176, -1176,  4769,
    8646,  7112,    58,  7138, -1176, -1176,  4769,  6048,  7164,  7190,
    7216,  7242,  1566,  1568, -1176,  6076,  1570,  4769,  1572,  1573,
    4769,  1575,  1576,  4769,  1577,  1399, -1176,  4769, -1176,   432,
   -1176,  4427,  1578,  4017, -1176, -1176,  4917, -1176,   778, -1176,
    4769, -1176,  3309,  4769,  7268, -1176,  4769,  4769,  4769,  4769,
   -1176, -1176, -1176, -1176,  1401,  6104, -1176, -1176,  1403,  6132,
   -1176, -1176,  1411,  6160, -1176,  1581,  4864,  1026,  4793,   787,
   -1176,   455,   796,   514,  1588,  1415,  8667,   799,  6188,  4769,
    7294,  7320,  7346,  7372,   432,  1591,   432,  1592,   432,  1593,
   -1176, -1176, -1176, -1176,   432,  1595,  4427,  1596, -1176, -1176,
      94, -1176,  1434,  1612,  6216,  4769,  4769,  4769,  4769,  1076,
   -1176,  1438,  1122, -1176,  1440,  1198, -1176,  1441,  1246, -1176,
     803, -1176,   812, -1176,  1442,  3309, -1176,  1614,  7398,  7424,
    7450,  7476,  1615,   432,  1622,   432,  1628,   432, -1176,  1630,
      94,  1631,    94,   815, -1176,  4769,  4769,  4769,  4769, -1176,
    1309, -1176,  1353, -1176,  1374, -1176, -1176, -1176,   821, -1176,
    1632,  7502,  7528,  7554,  7580,  1635,  1636,  1637,    94,  1638,
   -1176,  4769,  4769,  4769,  4769, -1176, -1176, -1176, -1176, -1176,
    6244,  6272,  6300,  6328,  1641,  1642,  1643,  1644, -1176, -1176,
   -1176, -1176
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1176, -1176, -1176, -1176,   644, -1176, -1176, -1176, -1176,   163,
   -1176, -1176, -1176, -1176, -1176, -1176, -1176, -1176, -1176, -1176,
   -1176, -1176,  -343,    53,  5125,  -522, -1176,  1244, -1176, -1176,
   -1176, -1176, -1176,   275, -1176,   282, -1176, -1176, -1176, -1176,
   -1176, -1176,   648,  1661,    11,  -459,  -235, -1176, -1176, -1176,
   -1176, -1176, -1176,  1662, -1176, -1176, -1176, -1176, -1176, -1176,
   -1176, -1176, -1176, -1176, -1176, -1176, -1176,  -908,  -611, -1176,
   -1176,  1229, -1176, -1176, -1176, -1176, -1176,    -6, -1176, -1176,
     479, -1176, -1175,   814,   -97,  1058,    54,  -214,   534, -1176,
       3,   257, -1176,  -340,   481,   407
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -454
static const yytype_int16 yytable[] =
{
     166,   691,   692,   568,   469,   570,  1164,  1075,   249,   168,
     450,   576,   825,   839,    89,  1064,   485,   316,   366,     5,
     195,   587,   190,   590,   765,   766,   767,   768,   769,   770,
     771,   772,   773,   774,   775,   301,   777,   778,   779,   780,
     781,   782,   783,   176,   287,   284,   787,   789,   790,   190,
     814,   195,  1338,   236,   295,   297,   237,   499,   304,   238,
     305,   530,  1157,   532,  1531,  1066,  1068,   306,   481,  1070,
     482,   319,   952,   320,  1036,   458,   459,   300,  1038,   533,
     979,   496,  1040,   172,  1042,   252,   164,   253,   458,   459,
     621,  1207,   622,  1208,   458,   459,     4,   164,   400,   105,
     458,   459,   220,   586,  1209,   221,  1210,   430,   431,   432,
     586,   460,   435,   436,   437,   623,  1211,  1387,  1212,   173,
     624,   458,   459,   458,   459,  1065,   826,   827,   828,   829,
     637,   178,   638,   131,   132,   133,   134,   135,   136,  1055,
     461,   250,   367,   368,   307,   140,   254,   141,   477,   478,
     360,   361,   362,   363,   365,   315,   228,   229,   146,   257,
     490,   491,   258,   390,   391,   392,   230,   399,   458,   459,
     393,   405,   840,   239,   373,  1067,  1069,   401,   404,  1071,
     410,   412,   415,   416,   174,   418,   412,   420,   421,   251,
     412,   424,   425,   317,   830,   318,   191,   412,  1037,  1437,
     164,   196,  1039,   192,   980,   981,  1041,   302,  1043,   175,
     458,   459,   458,   459,   303,   447,   684,   685,   288,  1455,
     241,   840,   177,   191,   456,   457,   285,   471,   686,   179,
     819,   815,   820,   457,   296,   298,   700,   500,   149,   150,
     514,   414,   805,  1532,   483,   808,   419,   953,   312,   313,
     423,   308,   309,   310,   311,  1091,   180,   429,   308,   309,
     310,   311,   181,   169,   509,   511,   412,   186,   458,   459,
     182,   312,   313,   372,   187,   518,   519,   520,   807,   522,
     472,   242,   525,   526,   693,   243,   527,   473,   747,   458,
     459,   396,   308,   309,   310,   311,   224,   244,   306,   538,
    1073,   995,   725,   630,   726,   699,   631,   186,   727,   225,
     226,   544,   312,   313,   818,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   198,   458,   459,
     458,   459,   589,   245,   821,   246,   577,   569,   579,   571,
     572,   573,   574,   575,  1051,   586,  1074,  1567,   580,   581,
     582,    45,    46,    47,    48,   633,  1134,   183,   631,    53,
     601,   412,    56,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   312,   313,
     619,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   515,   391,   392,   509,   184,   228,   229,   393,
     102,   641,   637,   171,   643,   958,   646,   230,  1329,   591,
     204,   651,   652,   205,   231,   625,   206,   657,   658,   185,
     626,   602,   663,   665,   668,   671,   674,   676,   677,   678,
    1633,   458,   459,  1117,  1118,  1119,  1120,  1121,   889,   458,
     459,  1126,  1129,   312,   313,   188,   199,   694,   695,   696,
     360,   361,   697,  -451,  1073,  1333,   701,   702,   703,   704,
     705,   373,   373,   189,   710,   312,   313,   712,   713,  1200,
    1201,   412,   412,   412,   101,  -452,   720,   721,   722,   723,
     308,   309,   310,   311,   730,  1462,   725,  1465,   726,  1468,
     193,   629,   412,   308,   309,   310,   311,   194,   738,   740,
     312,   313,   312,   313,   308,   309,   310,   311,   197,   105,
     902,   198,  -453,   312,   313,   232,   234,   723,   240,   200,
     903,   412,   201,   759,   312,   313,   202,   762,   904,   905,
     906,   715,   716,   717,   907,   908,   909,   910,  1244,  1245,
     458,   459,   203,   131,   132,   133,   134,   135,   136,   458,
     459,   207,   735,   628,   540,   140,  1402,   141,   629,   371,
    1236,   458,   459,   458,   459,  1404,   458,   459,   146,   458,
     459,   403,   403,   208,   811,   796,   212,  1406,   403,  1414,
     629,   757,  1416,   458,   459,  1417,   458,   459,   764,   223,
     725,   988,   726,   458,   459,   788,   458,   459,   222,  1507,
     578,  1557,  1510,   458,   459,   837,   584,   247,   412,  1513,
     412,   845,  1521,   458,   459,   637,   248,   647,  1007,  1523,
     740,   853,   847,   637,   255,   209,  1135,   851,   210,  1586,
     211,   809,   227,   370,   867,   388,   389,   390,   391,   392,
     235,   256,  1148,   873,   393,   370,   370,   213,   149,   150,
     214,   504,   370,   215,   505,   216,  1599,   506,  1602,   507,
    1605,   637,   217,   653,   412,   218,  1608,   219,   842,   259,
     844,   893,   894,   637,   319,   737,   495,   897,   496,  1008,
     725,   163,   726,   164,   637,   637,   666,   669,   672,   675,
     921,   281,   260,   923,  1369,   282,   453,   454,   725,  1370,
     726,   261,   280,  1125,   462,  1640,   283,  1642,   470,  1644,
     755,   412,   756,   290,   291,   412,   412,   412,   412,   637,
     725,   823,   726,   412,   887,  1128,   637,   289,   927,  1348,
     948,   292,   950,   951,   293,   354,  1317,  1318,   294,   346,
     403,   403,   403,   403,   403,   403,   403,   403,   403,   637,
     347,   928,   403,   403,   403,   583,   964,   637,  1248,   929,
     965,   637,  1140,   941,   637,   348,   957,   764,   966,   967,
     968,   934,   412,   349,   350,   937,   938,   939,   940,   725,
    1012,   726,  1013,   943,   975,   351,   970,   971,   972,   977,
     355,  1018,   982,  1019,   637,   976,  1048,   637,   637,  1092,
    1093,   959,   412,   412,   412,   412,   963,   637,   996,  1094,
     637,   637,  1095,  1096,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   637,   356,  1098,   370,   370,   370,   370,
     357,   358,   969,   902,  1006,  1142,   810,  1143,   637,   359,
    1144,  1073,   369,   903,  1073,   376,   637,  1073,  1145,   377,
     395,   904,   905,   906,   412,   394,   398,   907,   908,   909,
     910,   428,   991,   992,   993,   994,   637,   637,  1146,  1147,
     637,  1271,  1182,  1272,  1307,   637,  1308,  1342,   417,  1003,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,  1375,  1271,  1376,  1415,   393,  1271,
    1470,  1449,  1471,   637,   448,  1482,   501,  1349,   400,   105,
    1484,   422,  1485,  1087,  1029,   629,  1090,  1487,  1261,  1271,
    1125,  1492,  1494,  1128,   484,  1495,  1097,   689,   690,  1457,
    1271,  1072,  1502,   427,   433,   454,  1073,   637,   434,  1503,
     902,   438,  1112,   131,   132,   133,   134,   135,   136,   637,
     903,  1522,  1375,   439,  1564,   140,   440,   141,   904,   905,
     906,   637,   441,  1585,   907,   908,   909,   910,   146,   442,
     637,  1141,  1587,  1271,   443,  1592,   963,   637,  1073,  1629,
     902,  1073,  1150,  1151,  1073,   444,  1630,  1073,  1631,  1271,
     903,  1650,   445,  1160,  1162,  1658,   474,  1659,   904,   905,
     906,   451,   452,   426,   907,   908,   909,   910,   463,   464,
    1430,   465,   475,   476,   480,   486,   487,   488,   489,  1073,
     492,  1073,  1136,  1073,   446,   493,   403,   449,   494,   849,
     502,   403,   503,   498,   516,  1202,  1203,  1204,  1223,   517,
     521,   523,   524,   528,   902,  1214,   529,  1216,   149,   150,
     531,   479,   537,   539,   903,   542,   543,   545,  1221,   393,
     592,   593,   904,   905,   906,   594,   412,   164,   907,   908,
     909,   910,   902,   306,   163,   650,   595,   654,  1508,   312,
     313,   655,   903,   656,   681,   659,   962,  1240,  1241,  1242,
     904,   905,   906,   660,   679,   682,   907,   908,   909,   910,
     370,   683,   706,   370,   902,   370,   535,   536,   708,   731,
     709,   711,   718,   719,   903,  1251,   732,   724,   541,  1255,
     729,   733,   904,   905,   906,   734,  1231,   745,   907,   908,
     909,   910,   748,  1268,   754,   760,   761,   791,  1274,   792,
     801,  1431,  1511,   793,   803,  1278,   794,   795,   800,  1280,
    1281,  1276,   802,   804,   902,   892,  1286,  1287,  1250,   812,
     403,  1289,   898,   813,   903,   838,   817,  1473,   913,  1296,
    1514,   843,   904,   905,   906,   846,   848,   850,   907,   908,
     909,   910,   852,  1310,   856,  1311,   855,   857,   859,   860,
     403,   403,   403,   861,   862,   864,   865,  1328,   866,   403,
     902,   875,  1582,   870,   877,   879,   373,   373,   880,   412,
     903,   881,   888,   412,   882,   922,  1343,   895,   904,   905,
     906,   944,   896,   935,   907,   908,   909,   910,   945,  1352,
     946,   954,   947,   956,   370,   413,   978,  1361,   403,   983,
     413,   984,   987,   990,   413,   986,  1000,   998,   999,  1002,
    1005,   413,  1622,  1371,  1372,  1010,  1016,  1163,  1022,  1027,
    1028,  1378,  1030,  1023,   370,   370,   370,  1031,  1034,  1061,
    1035,  1044,  1045,   370,  1046,  1558,   902,  1047,  1250,  1049,
    1059,  1076,  1063,  1390,  1060,  1391,   903,  1392,  1062,  1393,
    1077,  1086,  1078,  1079,   904,   905,   906,  1080,  1624,  1399,
     907,   908,   909,   910,  1082,  1111,  1083,  1084,  1085,  1088,
    1089,  1102,   370,  1107,  1108,  1115,  1122,  1413,   510,   509,
     413,  1011,  1110,  1113,   902,  1114,  1116,  1123,  1124,  1132,
    1421,  1138,  1422,  1137,   903,   412,  1149,  1154,  1155,  1156,
    1159,  1429,   904,   905,   906,  1165,  1171,  1166,   907,   908,
     909,   910,  1172,  1167,  1434,  1174,  1175,  1173,  1177,  1438,
    1178,  1179,  1180,  1185,  1186,  1213,  1189,  1199,  1056,  1057,
    1058,  1191,  1217,  1193,  1626,  1195,  1218,  1205,  1206,   412,
    1219,  1254,  1220,  1235,  1227,  1228,  1460,   902,  1463,  1232,
    1466,   806,  1237,  1238,  1243,  1423,  1239,   903,  1247,   373,
     412,  1246,  1252,  1253,  1479,   904,   905,   906,  1279,  1256,
    1257,   907,   908,   909,   910,  1259,  1262,  1263,  1264,  1490,
    1491,  1265,  1628,  1275,  1493,   413,  1283,  1284,  1285,  1288,
    1290,   902,  1291,  1293,  1497,  1498,  1499,  1500,  1501,  1456,
    1297,   903,  1505,  1105,  1292,  1294,  1298,  1300,  1312,   904,
     905,   906,   902,  1299,  1302,   907,   908,   909,   910,   510,
    1477,  1304,   903,  1306,   874,  1301,  1303,  1309,  1526,  1320,
     904,   905,   906,  1274,  1305,  1323,   907,   908,   909,   910,
    1534,  1326,  1330,   886,  1334,  1655,  1337,  1341,  1344,  1363,
    1366,  1545,  1353,  1365,  1549,  1356,  1368,  1553,  1374,  1359,
    1362,  1556,  1377,  1367,  1386,   412,  1388,   412,  1389,  1397,
    1409,  1394,  1411,  1398,  1566,  1400,  1401,  1568,  1418,   403,
    1570,  1571,  1572,  1573,  1403,  1425,  1405,  1407,  1420,  1656,
    1412,  1427,  1426,  1432,  1439,   413,   413,   413,  1443,  1444,
    1445,  1446,  1447,  1222,  1448,  1469,  1450,  1476,  1483,  1488,
    1657,  1504,  1489,  1594,  1496,   403,   413,  1516,  1517,   955,
    1520,  1525,  1540,   741,  1541,  1559,  1543,  1562,  1546,  1547,
     412,  1550,  1551,  1554,  1560,  1555,  1574,  1580,  1576,  1618,
    1619,  1620,  1621,  1613,  1589,   413,  1578,  1600,  1603,  1606,
    1590,  1609,  1611,   370,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,  1616,  1615,
    1634,  1639,   393,  1623,  1106,  1625,  1627,  1632,  1641,  1651,
    1652,  1653,  1654,  1646,  1643,  1649,  1645,  1647,  1660,   370,
    1610,  1665,  1666,  1667,  1669,   378,  1282,  1678,  1679,  1680,
    1681,  1158,  1528,   634,  1441,  1670,  1671,  1672,  1673,     7,
       8,  1668,  1442,  1169,    88,    96,   662,     0,     0,     0,
    1014,  1015,  1258,  1017,     0,  1020,  1021,     0,     0,  1024,
    1025,     0,   413,     0,   413,     0,  1319,     0,  1322,     0,
    1325,     0,     0,     0,   741,   854,     0,     0,     0,     0,
       0,     0,     0,     0,  1336,     0,     0,  1339,  1340,     0,
       0,     0,   596,    21,    22,   597,    24,    25,   598,    27,
     599,    29,     0,    30,     0,     0,     0,     0,    35,    36,
       0,    38,    39,    40,     0,     0,     0,    43,   413,     0,
       0,     0,     0,  1527,   534,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,  1099,  1100,
    1101,   393,     0,     0,     0,     0,     0,   403,  1109,     0,
      64,    65,    66,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,   413,     0,     0,     0,   413,
     413,   413,   413,     0,     0,     0,     0,   413,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,  1153,     0,   393,     0,     0,     0,
    1588,   384,   385,   386,   387,   388,   389,   390,   391,   392,
    1170,     0,     0,   714,   393,     0,  1176,     0,     0,     0,
       0,   370,  1181,     0,  1183,  1184,   413,     0,     0,  1187,
    1188,     0,  1190,     0,  1192,     0,  1194,     0,  1196,  1197,
    1198,   799,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1215,   413,   413,   413,   413,
       0,  1461,     0,  1464,     0,  1467,     0,     0,     0,     0,
    1226,     0,     0,  1475,  1230,     0,  1478,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   413,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,   103,   299,     0,     0,     0,     0,   106,   107,
     108,     0,  1266,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   403,     0,     0,
       0,     0,  1561,     0,   142,   143,   144,     0,     0,     0,
       0,     0,   145,     0,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,   403,     0,   403,
       0,  1153,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,  1345,     0,     0,     0,   393,     0,     0,
    1354,     0,  1355,     0,     0,   403,  1358,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1373,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,     0,     0,  1153,     0,     0,     0,
       0,   370,     0,   370,     0,     0,     0,   466,   467,     0,
       0,     0,   158,     0,     0,     0,     0,   468,     0,     0,
       0,     0,   162,     0,   231,     0,     0,     0,     0,   370,
     413,     0,     0,     0,  1410,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   299,   105,     0,     0,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,  1153,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,     0,   141,     0,   142,   143,   144,  1153,     0,
       0,     0,     0,   145,   146,   103,   104,   105,     0,     0,
       0,   106,   107,   108,     0,  1472,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,   140,     0,   141,     0,   142,   143,   144,
       0,     0,     0,     0,     0,   145,   146,     0,     0,     0,
       0,     0,     0,   413,  1515,     0,     0,   413,     0,     0,
       0,     0,     0,   148,   149,   150,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
       0,     0,     0,   158,     0,     0,     0,     0,   271,     0,
       0,     0,     0,   162,     0,  1161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1153,     0,     0,   147,
       0,     0,     0,     0,     0,   148,   149,   150,     0,     0,
       0,     0,   151,   152,   153,   154,   155,   985,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,     0,     0,   158,  1026,     0,     0,     0,
     159,     0,   160,   510,   161,   162,     0,   163,     0,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   413,
       0,     0,     0,     0,     0,   413,     0,     0,     0,   103,
     262,     0,     0,     0,     0,   106,   107,   108,     0,  1153,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   264,   413,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,   413,     0,     0,     0,     0,   145,
       0,   265,     0,     0,   266,     0,     0,   267,     0,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   148,
       0,     0,     0,     0,     0,     0,   151,   152,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,     0,   413,
       0,   413,     0,     0,   466,  1335,     0,     0,     0,   158,
       0,     0,     0,     0,   468,     0,     0,   103,   262,   162,
       0,   231,   512,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,   139,     0,     0,   413,     0,     0,     0,     0,   142,
     143,   144,     0,     7,     8,     0,     0,   145,     0,   265,
       0,     0,   266,     0,     0,   267,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,   596,    21,    22,   597,
      24,    25,   598,    27,   599,    29,     0,    30,     0,     0,
       0,     0,    35,    36,     0,    38,    39,    40,     0,  1081,
       0,    43,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   154,   155,  1133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   411,    64,    65,    66,   158,     0,     0,
       0,     0,   271,     0,     0,     0,     0,   162,     0,     0,
     512,   103,   262,   105,     0,     0,     0,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   264,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   752,     0,   140,
       0,   141,     0,   142,   143,   144,     0,     0,     0,     0,
       0,   145,   146,   265,     0,     0,   266,     0,     0,   267,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,     0,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,     0,     0,     0,    53,     0,
       0,    56,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,   148,   149,   150,     0,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   270,     0,     0,
       0,   158,     0,     0,     0,     0,   271,     0,   103,   262,
     263,   162,     0,  1357,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,     0,     0,     0,     7,     8,     0,     0,
     142,   143,   144,     0,     0,     0,     0,     0,   145,     0,
     265,     0,     0,   266,     0,     0,   267,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,     0,     0,    53,     0,     0,    56,   596,
      21,    22,   597,    24,    25,   598,    27,   599,    29,     0,
      30,     0,     0,     0,     0,    35,    36,     0,    38,    39,
      40,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     0,     0,   156,   270,     0,     0,     0,   158,     0,
       0,     0,     0,   271,     0,   103,   262,  1224,   162,     0,
     272,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   139,
     753,     0,     0,     7,     8,     0,     0,   142,   143,   144,
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
     271,     0,   103,   262,     0,   162,     0,  1225,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   890,     0,     0,
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
     262,     0,   162,     0,   272,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,   891,     0,     0,     7,     8,     0,
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
      66,     0,     0,     0,   156,   411,     0,     0,     0,   158,
       0,     0,     0,     0,   271,     0,   103,   262,     0,   162,
       0,   508,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   914,     0,     0,     7,     8,     0,     0,   142,   143,
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
       0,   271,     0,   103,   262,     0,   162,     0,   739,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   139,   949,     0,
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
       0,     0,    64,    65,    66,     0,     0,     0,   156,   270,
       0,     0,     0,   158,     0,     0,     0,     0,   271,     0,
     103,   262,     0,   162,     0,  1229,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,  1050,     0,     0,     7,     8,
       0,     0,   142,   143,   144,     0,     0,     0,     0,     0,
     145,     0,   265,     0,     0,   266,     0,     0,   267,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   596,    21,    22,   597,    24,    25,   598,    27,   599,
      29,     0,    30,     0,     0,     0,     0,    35,    36,     0,
      38,    39,    40,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,  1139,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     0,   466,  1335,     0,     0,     0,
     158,     0,     0,     0,     0,   468,     0,   103,   299,   105,
     162,     0,   231,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,  1518,     0,     0,   140,     0,   141,     0,   142,
     143,   144,     0,   103,   299,   105,     0,   145,   146,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,     0,   141,     0,   142,   143,   144,     0,     0,
       0,     0,     0,   145,   146,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,   148,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,     0,     0,   158,     0,     0,
       0,     0,   271,     0,     0,     0,     0,   162,     0,  1351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   157,
       0,     0,     0,   158,     0,     0,     0,     0,   271,     0,
     103,   262,     0,   162,     0,  1360,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,     0,     0,     0,     0,
     145,     0,   265,     0,     0,   266,     0,     0,   267,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   103,   299,     0,     0,     0,     0,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,  1233,     0,     0,     0,     0,     0,
     148,     0,     0,   137,   138,   139,     0,   151,   152,   153,
     154,   155,     0,   142,   143,   144,     0,     0,     0,     0,
       0,   145,     0,     0,     0,   156,   411,     0,     0,     0,
     158,   103,   299,   105,     0,   271,     0,   106,   107,   108,
     162,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,   140,
       0,   141,     0,   142,   143,   144,     0,     0,     0,     0,
       0,   145,   146,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,  1249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,     0,     0,
       0,   158,     0,     0,     0,     0,   271,     0,     0,   364,
       0,   162,     0,     0,     0,     0,     0,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,  1364,     0,     0,     0,   393,     0,     0,     0,     0,
       0,   148,   149,   150,     0,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,     0,     0,
       0,   158,   103,   299,     0,     0,   271,     0,   106,   107,
     108,   162,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     7,     8,  1396,     0,     0,
       0,     0,     0,     0,   137,   138,   139,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,  1424,     0,     0,
       0,     0,   145,     0,     0,     0,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
    1524,     0,     0,     0,   393,     0,     0,     0,   596,    21,
      22,   597,    24,    25,   598,    27,   599,    29,     0,    30,
    1581,     0,     0,     0,    35,    36,     0,    38,    39,    40,
       0,     0,     0,    43,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,  1486,   514,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,    64,    65,    66,   151,
     152,   153,   154,   155,  1563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,   157,     0,
       0,     0,   158,     0,   514,     0,     0,   271,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   514,     0,     0,     0,   393,  1583,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   749,     0,     0,     0,   393,     0,
       0,     0,     0,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   824,     0,     0,
       0,   393,     0,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   942,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   636,   391,   392,  1104,     0,     0,     0,   393,     0,
       0,     0,     0,     0,     0,     0,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   515,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   636,   391,   392,     0,
       0,     0,     0,   393,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,  1032,     0,     0,   393,     0,     0,     0,
       0,     0,     0,     0,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
     352,   353,    -4,    -4,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,    -4,     0,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     0,   497,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     6,     0,     0,    -4,    -4,    -4,    -4,
       0,     7,     8,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     9,    10,  1315,     0,
    1316,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,    14,     0,    15,     0,     0,     0,    16,    17,     0,
      18,    19,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     7,     8,     0,    59,    60,
      61,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,    63,    64,    65,    66,     0,     0,    67,     0,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   596,    21,
      22,   597,    24,    25,   598,    27,   599,    29,     0,    30,
       0,     0,     0,     0,    35,    36,     0,    38,    39,    40,
       0,     0,     0,    43,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,  1346,
       0,  1347,     0,     0,     0,     0,    64,    65,    66,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1458,     0,  1459,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,   822,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,   869,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
     917,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,   936,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,   960,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1054,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1313,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1332,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1381,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1382,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1383,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1384,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1385,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1419,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1474,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1480,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1481,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1506,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1509,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1512,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1535,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1542,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1575,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1577,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1579,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1593,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,  1617,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
    1674,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,  1675,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1676,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,  1677,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,   680,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,  1395,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   736,
       0,     0,     0,     0,   687,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
     627,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,   687,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,   688,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,   746,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,   776,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
     784,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,   785,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,   786,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,   899,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,   900,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
     901,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,   932,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1009,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1052,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1053,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
    1103,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1269,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1270,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1277,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1435,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
    1436,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1440,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1451,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1452,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1453,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
    1454,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1530,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1533,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1536,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1537,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
    1538,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1539,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1569,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1595,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1596,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
    1597,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1598,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1635,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1636,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1637,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
    1638,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,  1661,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,     0,
       0,     0,  1662,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,     0,  1663,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,  1664,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   725,     0,   726,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
     588,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,   751,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,   758,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,   763,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,   836,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,     0,     0,   925,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,     0,     0,   926,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,     0,
       0,   930,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,     0,     0,   931,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,     0,     0,   933,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,     0,     0,
     961,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,     0,     0,  1004,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,     0,     0,  1234,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,     0,     0,  1260,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
       0,     0,  1408,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   585,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   635,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   639,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   640,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   642,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   644,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   645,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     648,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   649,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   736,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   742,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   743,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   744,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   750,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   858,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   863,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   868,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     871,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,   872,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   878,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   883,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   884,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   885,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   916,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   918,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   919,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   920,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     924,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,   393,
       0,  1131,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
     393,     0,  1314,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   393,     0,  1331,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,   393,     0,  1350,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,   393,     0,  1529,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
       0,     0,     0,     0,   393,     0,  1591,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   393
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1176)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,   460,   461,   343,   239,   345,     6,   915,     4,     6,
     224,   351,     4,     6,     3,     6,   251,     4,     4,     0,
       4,   364,     4,   366,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,     6,   558,   559,   560,   561,
     562,   563,   564,     6,     4,     4,   568,   569,   570,     4,
       4,     4,  1227,    65,     5,     5,    68,     5,   178,    71,
     180,   296,     6,   298,     6,     6,     6,   187,     4,     6,
       6,   178,     7,   180,     7,   168,   169,    83,     7,   180,
       4,   182,     7,    13,     7,     4,   187,     6,   168,   169,
     180,   184,   182,   186,   168,   169,     6,   187,     4,     5,
     168,   169,    68,     7,   184,    71,   186,   204,   205,   206,
       7,   185,   209,   210,   211,   179,   184,  1292,   186,    71,
     184,   168,   169,   168,   169,   116,   118,   119,   120,   121,
     184,     6,   186,    39,    40,    41,    42,    43,    44,   186,
     185,   137,   128,   129,     7,    51,    65,    53,   245,   246,
     156,   157,   158,   159,   160,   102,   168,   169,    64,    68,
     257,   258,    71,   170,   171,   172,   178,   173,   168,   169,
     177,   177,   165,   185,   163,   116,   116,   174,   175,   116,
     186,   187,   188,   189,   178,   191,   192,   193,   194,   185,
     196,   197,   198,   180,   186,   182,   178,   203,   131,  1374,
     187,   185,   131,   185,   128,   129,   131,   178,   131,   178,
     168,   169,   168,   169,   185,   221,   451,   452,   178,  1394,
       4,   165,   185,   178,   230,   231,   185,   185,   184,     6,
     185,   185,   185,   239,   185,   185,   471,   185,   144,   145,
       8,   187,   585,   185,   180,   588,   192,   182,   175,   176,
     196,   155,   156,   157,   158,   182,     6,   203,   155,   156,
     157,   158,   178,     6,   270,   271,   272,   178,   168,   169,
       6,   175,   176,     4,   185,   281,   282,   283,   182,   285,
     178,    65,   288,   289,   184,    69,   292,   185,   523,   168,
     169,   180,   155,   156,   157,   158,   128,    81,   187,   305,
     911,   823,   179,   181,   181,   184,   184,   178,   185,   141,
     142,   317,   175,   176,   185,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   178,   168,   169,
     168,   169,     7,    71,   185,    73,   352,   344,   354,   346,
     347,   348,   349,   350,   184,     7,   184,  1532,   355,   356,
     357,    92,    93,    94,    95,   181,     7,     6,   184,   100,
     376,   377,   103,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   175,   176,
     396,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   411,   180,   168,   169,   177,
       3,   417,   184,     6,   186,   758,   422,   178,   186,   366,
      65,   427,   428,    68,   185,   179,    71,   433,   434,   180,
     184,   377,   438,   439,   440,   441,   442,   443,   444,   445,
    1615,   168,   169,   965,   966,   967,   968,   969,   683,   168,
     169,   973,   974,   175,   176,   178,    75,   463,   464,   465,
     466,   467,   468,   185,  1075,   184,   472,   473,   474,   475,
     476,   460,   461,   178,   480,   175,   176,   483,   484,     6,
       7,   487,   488,   489,     3,   185,   492,   493,   494,   495,
     155,   156,   157,   158,   500,  1403,   179,  1405,   181,  1407,
     178,   184,   508,   155,   156,   157,   158,   178,   514,   515,
     175,   176,   175,   176,   155,   156,   157,   158,   178,     5,
      88,   178,   185,   175,   176,    46,    47,   533,    49,    71,
      98,   537,    71,   539,   175,   176,     6,   543,   106,   107,
     108,   487,   488,   489,   112,   113,   114,   115,     6,     7,
     168,   169,   185,    39,    40,    41,    42,    43,    44,   168,
     169,    71,   508,   179,   307,    51,   184,    53,   184,   162,
    1092,   168,   169,   168,   169,   184,   168,   169,    64,   168,
     169,   174,   175,    71,   590,   179,    73,   184,   181,   184,
     184,   537,   184,   168,   169,   184,   168,   169,   545,    68,
     179,   815,   181,   168,   169,   184,   168,   169,   178,   184,
     353,  1519,   184,   168,   169,   621,   359,    71,   624,   184,
     626,   627,   184,   168,   169,   184,    68,   186,   179,   184,
     636,   637,   629,   184,    68,    68,   979,   634,    71,   184,
      73,   588,   185,   162,   650,   168,   169,   170,   171,   172,
     185,    71,   995,   659,   177,   174,   175,    65,   144,   145,
      68,    65,   181,    71,    68,    73,  1574,    71,  1576,    73,
    1578,   184,    68,   186,   680,    71,  1584,    73,   624,     4,
     626,   687,   688,   184,   178,   186,   180,   693,   182,   179,
     179,   185,   181,   187,   184,   184,   439,   440,   441,   442,
     706,   178,     4,   709,   179,   178,   227,   228,   179,   184,
     181,     4,     4,   184,   235,  1623,   178,  1625,   239,  1627,
     184,   727,   186,     6,     6,   731,   732,   733,   734,   184,
     179,   186,   181,   739,   680,   184,   184,   178,   186,     8,
     746,   180,   748,   749,     4,     7,  1205,  1206,     4,   178,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   184,
     178,   186,   355,   356,   357,   358,   763,   184,  1111,   186,
     776,   184,   986,   186,   184,   178,   186,   724,   784,   785,
     786,   727,   788,   178,   178,   731,   732,   733,   734,   179,
      71,   181,    73,   739,   800,   178,   793,   794,   795,   805,
     178,    71,   808,    73,   184,   802,   186,   184,   184,   186,
     186,   758,   818,   819,   820,   821,   763,   184,   824,   186,
     184,   184,   186,   186,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   184,   178,   186,   355,   356,   357,   358,
     178,   178,   788,    88,   841,   184,   589,   186,   184,   178,
     186,  1462,     4,    98,  1465,   185,   184,  1468,   186,   185,
       6,   106,   107,   108,   870,   185,     6,   112,   113,   114,
     115,   185,   818,   819,   820,   821,   184,   184,   186,   186,
     184,   184,   186,   186,     4,   184,     6,   186,   178,   836,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   184,   184,   186,   186,   177,   184,
     184,   186,   186,   184,     4,   186,     5,   186,     4,     5,
     184,   178,   186,   929,   870,   184,   932,   186,  1142,   184,
     184,   186,   186,   184,   180,   186,   942,   458,   459,  1398,
     184,   186,   186,   178,   178,   466,  1557,   184,   178,   186,
      88,   178,   958,    39,    40,    41,    42,    43,    44,   184,
      98,   186,   184,   178,   186,    51,   178,    53,   106,   107,
     108,   184,   178,   186,   112,   113,   114,   115,    64,   178,
     184,   987,   186,   184,   178,   186,   933,   184,  1599,   186,
      88,  1602,   998,   999,  1605,   178,   184,  1608,   186,   184,
      98,   186,   178,  1009,  1010,   184,   178,   186,   106,   107,
     108,   185,   185,   199,   112,   113,   114,   115,   185,   185,
    1360,   185,   178,   178,   178,     6,   185,   185,   185,  1640,
     180,  1642,   979,  1644,   220,   180,   629,   223,   180,   632,
       5,   634,     5,   180,     6,  1051,  1052,  1053,   186,     6,
     182,   185,   131,     6,    88,  1061,     6,  1063,   144,   145,
       6,   247,   185,   185,    98,     6,   180,     4,  1074,   177,
     182,     7,   106,   107,   108,   180,  1082,   187,   112,   113,
     114,   115,    88,   187,   185,     7,   186,     6,   186,   175,
     176,     6,    98,     6,   179,     7,   182,  1103,  1104,  1105,
     106,   107,   108,     7,     7,     6,   112,   113,   114,   115,
     629,   185,     7,   632,    88,   634,   302,   303,     6,   185,
       7,     6,     6,     6,    98,  1122,   185,     4,   314,  1135,
       4,   185,   106,   107,   108,   185,  1082,   128,   112,   113,
     114,   115,   185,  1149,   179,     6,     6,   179,  1154,   179,
     179,  1365,   186,   184,   179,  1161,   184,   184,   184,  1165,
    1166,  1158,   184,   179,    88,   686,  1172,  1173,  1115,     6,
     763,  1177,   693,     4,    98,     4,   181,  1412,   699,  1185,
     186,     6,   106,   107,   108,     6,     6,     6,   112,   113,
     114,   115,     7,  1199,     7,  1201,   131,     7,     7,   131,
     793,   794,   795,     7,     7,   131,     7,  1213,     7,   802,
      88,     4,   186,   185,     6,   179,  1205,  1206,   179,  1225,
      98,   179,   182,  1229,   179,     6,  1232,   186,   106,   107,
     108,     7,   186,   181,   112,   113,   114,   115,     7,  1245,
       7,   185,   182,     6,   763,   187,     6,  1253,   841,     6,
     192,     6,   180,     6,   196,     7,   185,   178,   178,     6,
     165,   203,   186,  1269,  1270,     7,     7,  1010,     7,     7,
       7,  1277,     7,    73,   793,   794,   795,     7,     6,   185,
       7,     7,     7,   802,     7,  1520,    88,     6,  1235,     4,
       4,     7,   178,  1299,     6,  1301,    98,  1303,     6,  1305,
       6,    71,     7,     7,   106,   107,   108,     7,   186,  1315,
     112,   113,   114,   115,   185,   179,     6,     6,     6,     6,
       6,     4,   841,     4,     4,     4,   184,  1333,   270,  1335,
     272,   852,   186,     6,    88,     6,     6,   179,   179,   179,
    1346,     7,  1348,   182,    98,  1351,   178,   185,   182,     6,
       6,  1357,   106,   107,   108,   185,     6,   185,   112,   113,
     114,   115,   185,    81,  1370,     6,     6,   185,   185,  1375,
       6,     6,     5,     4,     6,   180,    48,     7,   899,   900,
     901,    48,     6,    48,   186,    48,     6,   185,   185,  1395,
       6,  1134,     6,     4,   185,   185,  1402,    88,  1404,   185,
    1406,   587,     6,     6,     6,  1351,   127,    98,     6,  1398,
    1416,   184,     4,     4,  1420,   106,   107,   108,  1161,     6,
       4,   112,   113,   114,   115,     6,     6,     6,     6,  1435,
    1436,     6,   186,     4,  1440,   377,     6,     6,     6,     6,
       5,    88,     6,     6,  1450,  1451,  1452,  1453,  1454,  1395,
       6,    98,  1458,     8,   185,   131,     6,     6,  1201,   106,
     107,   108,    88,   185,     6,   112,   113,   114,   115,   411,
    1416,     6,    98,     6,   660,   185,   185,     6,  1484,     6,
     106,   107,   108,  1489,   185,     6,   112,   113,   114,   115,
    1496,     6,   184,   679,     6,   186,     6,     6,     6,     6,
       6,  1507,  1245,     7,  1510,   179,     6,  1513,   185,  1252,
    1253,  1517,     6,   182,     5,  1521,    69,  1523,     6,     6,
       6,   185,     7,   185,  1530,   186,   186,  1533,     6,  1122,
    1536,  1537,  1538,  1539,   185,     6,   185,   185,   126,   186,
     185,     6,   186,   129,     6,   487,   488,   489,     6,     6,
       6,     6,     6,  1074,     6,     6,   185,     6,     6,     6,
     186,   186,   185,  1569,   185,  1158,   508,     6,    88,   755,
     185,     6,     6,   515,     6,  1521,     6,  1523,     6,     6,
    1586,     6,     6,     6,     6,   186,   185,     6,   185,  1595,
    1596,  1597,  1598,  1590,     6,   537,   185,     6,     6,     6,
     185,     6,     6,  1122,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     6,   185,
       6,     6,   177,   185,   179,   185,   185,   185,     6,  1635,
    1636,  1637,  1638,  1630,     6,  1632,     6,     6,     6,  1158,
    1586,     6,     6,     6,     6,     6,  1167,     6,     6,     6,
       6,  1007,  1489,   409,  1379,  1661,  1662,  1663,  1664,    12,
      13,  1658,  1380,  1015,     3,     3,   437,    -1,    -1,    -1,
     856,   857,  1138,   859,    -1,   861,   862,    -1,    -1,   865,
     866,    -1,   624,    -1,   626,    -1,  1207,    -1,  1209,    -1,
    1211,    -1,    -1,    -1,   636,   637,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1225,    -1,    -1,  1228,  1229,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    85,    86,    -1,    -1,    -1,    90,   680,    -1,
      -1,    -1,    -1,  1486,     6,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   944,   945,
     946,   177,    -1,    -1,    -1,    -1,    -1,  1360,   954,    -1,
     123,   124,   125,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,   731,
     732,   733,   734,    -1,    -1,    -1,    -1,   739,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,  1000,    -1,   177,    -1,    -1,    -1,
    1563,   164,   165,   166,   167,   168,   169,   170,   171,   172,
    1016,    -1,    -1,   186,   177,    -1,  1022,    -1,    -1,    -1,
      -1,  1360,  1028,    -1,  1030,  1031,   788,    -1,    -1,  1035,
    1036,    -1,  1038,    -1,  1040,    -1,  1042,    -1,  1044,  1045,
    1046,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1061,   818,   819,   820,   821,
      -1,  1402,    -1,  1404,    -1,  1406,    -1,    -1,    -1,    -1,
    1076,    -1,    -1,  1414,  1080,    -1,  1417,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   870,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,  1148,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,  1590,    -1,    -1,
      -1,    -1,  1523,    -1,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,  1630,    -1,  1632,
      -1,  1227,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,  1239,    -1,    -1,    -1,   177,    -1,    -1,
    1246,    -1,  1248,    -1,    -1,  1658,  1252,    -1,    -1,    -1,
      -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,    -1,    -1,  1292,    -1,    -1,    -1,
      -1,  1630,    -1,  1632,    -1,    -1,    -1,   168,   169,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   183,    -1,   185,    -1,    -1,    -1,    -1,  1658,
    1082,    -1,    -1,    -1,  1330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,  1374,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    -1,    53,    -1,    55,    56,    57,  1394,    -1,
      -1,    -1,    -1,    63,    64,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,  1411,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    -1,    53,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,  1225,  1470,    -1,    -1,  1229,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   183,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1532,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,    -1,    -1,    -1,   173,     6,    -1,    -1,    -1,
     178,    -1,   180,  1335,   182,   183,    -1,   185,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1351,
      -1,    -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,  1615,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,  1395,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,  1416,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    71,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,
      -1,  1523,    -1,    -1,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,     3,     4,   183,
      -1,   185,   186,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,  1586,    -1,    -1,    -1,    -1,    55,
      56,    57,    -1,    12,    13,    -1,    -1,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    71,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    85,    86,    -1,     6,
      -1,    90,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,   123,   124,   125,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,
     186,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,   186,    -1,    51,
      -1,    53,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,
      -1,   103,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   178,    -1,     3,     4,
       5,   183,    -1,   185,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    12,    13,    -1,    -1,
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
      -1,    -1,    -1,   178,    -1,     3,     4,     5,   183,    -1,
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
     143,    -1,     6,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,   178,    -1,     3,     4,     5,
     183,    -1,   185,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   186,    -1,    -1,    51,    -1,    53,    -1,    55,
      56,    57,    -1,     3,     4,     5,    -1,    63,    64,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    -1,    53,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    64,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   183,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,
       3,     4,    -1,   183,    -1,   185,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    71,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     6,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    45,    46,    47,    -1,   150,   151,   152,
     153,   154,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
     173,     3,     4,     5,    -1,   178,    -1,     9,    10,    11,
     183,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      -1,    53,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,   181,
      -1,   183,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     6,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,
      -1,   173,     3,     4,    -1,    -1,   178,    -1,     9,    10,
      11,   183,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    12,    13,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,     6,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       6,    -1,    -1,    -1,   177,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
       6,    -1,    -1,    -1,    81,    82,    -1,    84,    85,    86,
      -1,    -1,    -1,    90,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     7,     8,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,   123,   124,   125,   150,
     151,   152,   153,   154,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,
      -1,    -1,   173,    -1,     8,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     8,    -1,    -1,    -1,   177,   186,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     8,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     8,    -1,    -1,
      -1,   177,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     8,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     8,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    88,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
     145,   146,    12,    13,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    52,    -1,    54,    -1,    -1,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    -1,   262,   128,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     4,    -1,    -1,   146,   147,   148,   149,
      -1,    12,    13,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    37,    38,   184,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    52,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    12,    13,    -1,   109,   110,
     111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,    -1,   128,    -1,   130,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,    86,
      -1,    -1,    -1,    90,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,   186,    -1,    -1,    -1,    -1,   123,   124,   125,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,   159,   160,   161,
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
      -1,   185,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,   179,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,   177,    -1,   179,    -1,   181,   159,   160,
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
      -1,    -1,   177,    -1,    -1,    -1,   181,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   181,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,   181,   159,   160,   161,   162,   163,   164,   165,
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
     172,    -1,    -1,    -1,    -1,   177
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
     234,     6,   234,   180,     6,   271,   271,   185,   265,   185,
     279,   271,     6,   180,   265,     4,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   281,   278,
     281,   278,   278,   278,   278,   278,   281,   265,   279,   265,
     278,   278,   278,   283,   279,   179,     7,   210,   181,     7,
     210,   211,   182,     7,   180,   186,    65,    68,    71,    73,
     231,   265,   274,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   195,   265,
       6,   180,   182,   179,   184,   179,   184,   184,   179,   184,
     181,   184,   215,   181,   215,   179,   170,   184,   186,   179,
     179,   265,   179,   186,   179,   179,   265,   186,   179,   179,
       7,   265,   265,   186,     6,     6,     6,   265,   265,     7,
       7,   259,   259,   265,   225,   265,   279,   226,   265,   279,
     227,   265,   279,   228,   265,   279,   265,   265,   265,     7,
     185,   179,     6,   185,   234,   234,   184,   184,   184,   268,
     268,   233,   233,   184,   265,   265,   265,   265,   245,   184,
     234,   265,   265,   265,   265,   265,     7,   260,     6,     7,
     265,     6,   265,   265,   186,   274,   274,   274,     6,     6,
     265,   265,   265,   265,     4,   179,   181,   185,   213,     4,
     265,   185,   185,   185,   185,   274,   179,   186,   265,   185,
     265,   273,   179,   179,   179,   128,   184,   234,   185,     8,
     179,   181,   186,   186,   179,   184,   186,   274,   181,   265,
       6,     6,   265,   181,   211,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   184,   213,   213,   213,
     213,   213,   213,   213,   184,   184,   184,   213,   184,   213,
     213,   179,   179,   184,   184,   184,   179,   267,   280,     6,
     184,   179,   184,   179,   179,   210,   271,   182,   210,   211,
     279,   265,     6,     4,     4,   185,   276,   181,   185,   185,
     185,   185,   186,   186,     8,     4,   118,   119,   120,   121,
     186,   198,   202,   205,   207,   208,   181,   265,     4,     6,
     165,   192,   274,     6,   274,   265,     6,   278,     6,   283,
       6,   278,     7,   265,   273,   131,     7,     7,   179,     7,
     131,     7,     7,   179,   131,     7,     7,   265,   179,   186,
     185,   179,   179,   265,   271,     4,   258,     6,   179,   179,
     179,   179,   179,   179,   179,   179,   271,   274,   182,   234,
     186,   186,   268,   265,   265,   186,   186,   265,   268,   184,
     184,   184,    88,    98,   106,   107,   108,   112,   113,   114,
     115,   255,   256,   268,   186,   242,   179,   186,   179,   179,
     179,   265,     6,   265,   179,   181,   181,   186,   186,   186,
     181,   181,   184,   181,   274,   181,   186,   274,   274,   274,
     274,   186,     8,   274,     7,     7,     7,   182,   265,   186,
     265,   265,     7,   182,   185,   271,     6,   186,   210,   211,
     186,   181,   182,   211,   278,   265,   265,   265,   265,   274,
     278,   278,   278,   221,   223,   265,   278,   265,     6,     4,
     128,   129,   265,     6,     6,     6,     7,   180,   275,   277,
       6,   274,   274,   274,   274,   213,   265,   199,   178,   178,
     185,   209,     6,   211,   181,   165,   278,   179,   179,   184,
       7,   268,    71,    73,   271,   271,     7,   271,    71,    73,
     271,   271,     7,    73,   271,   271,     6,     7,     7,   274,
       7,     7,    88,   257,     6,     7,     7,   131,     7,   131,
       7,   131,     7,   131,     7,     7,     7,     6,   186,     4,
     186,   184,   184,   184,   186,   186,   268,   268,   268,     4,
       6,   185,     6,   178,     6,   116,     6,   116,     6,   116,
       6,   116,   186,   256,   184,   255,     7,     6,     7,     7,
       7,     6,   185,     6,     6,     6,    71,   265,     6,     6,
     265,   182,   186,   186,   186,   186,   186,   265,   186,   271,
     271,   271,     4,   184,     8,     8,   179,     4,     4,   271,
     186,   179,   265,     6,     6,     4,     6,   213,   213,   213,
     213,   213,   184,   179,   179,   184,   213,   222,   184,   213,
     224,   179,   179,     6,     7,   210,   211,   182,     7,     6,
     275,   265,   184,   186,   186,   186,   186,   186,   210,   178,
     265,   265,   270,   271,   185,   182,     6,     6,   192,     6,
     265,   185,   265,   279,     6,   185,   185,    81,   230,   230,
     271,     6,   185,   185,     6,     6,   271,   185,     6,     6,
       5,   271,   186,   271,   271,     4,     6,   271,   271,    48,
     271,    48,   271,    48,   271,    48,   271,   271,   271,     7,
       6,     7,   265,   265,   265,   185,   185,   184,   186,   184,
     186,   184,   186,   180,   265,   271,   265,     6,     6,     6,
       6,   265,   268,   186,     5,   185,   271,   185,   185,   185,
     271,   274,   185,     6,   181,     4,   213,     6,     6,   127,
     265,   265,   265,     6,     6,     7,   184,     6,   210,     6,
     211,   278,     4,     4,   279,   265,     6,     4,   276,     6,
     181,   275,     6,     6,     6,     6,   271,   196,   265,   184,
     184,   184,   186,   197,   265,     4,   278,   184,   265,   279,
     265,   265,   268,     6,     6,     6,   265,   265,     6,   265,
       5,     6,   185,     6,   131,   229,   265,     6,     6,   185,
       6,   185,     6,   185,     6,   185,     6,     4,     6,     6,
     265,   265,   279,   186,   179,   184,   186,   233,   233,   268,
       6,   246,   268,     6,   247,   268,     6,   248,   265,   186,
     184,   179,   186,   184,     6,   169,   268,     6,   270,   268,
     268,     6,   186,   265,     6,   271,   184,   186,     8,   186,
     179,   185,   265,   279,   271,   271,   179,   185,   271,   279,
     185,   265,   279,     6,     6,     7,     6,   182,     6,   179,
     184,   265,   265,   271,   185,   184,   186,     6,   265,   217,
     218,   186,   186,   186,   186,   186,     5,   270,    69,     6,
     265,   265,   265,   265,   185,   185,     6,     6,   185,   265,
     186,   186,   184,   185,   184,   185,   184,   185,   181,     6,
     271,     7,   185,   265,   184,   186,   184,   184,     6,   186,
     126,   265,   265,   274,     6,     6,   186,     6,   220,   265,
     281,   275,   129,   200,   265,   184,   184,   270,   265,     6,
     184,   221,   223,     6,     6,     6,     6,     6,     6,   186,
     185,   184,   184,   184,   184,   270,   274,   233,   184,   186,
     265,   268,   255,   265,   268,   255,   265,   268,   255,     6,
     184,   186,   271,   234,   186,   268,     6,   274,   268,   265,
     186,   186,   186,     6,   184,   186,     7,   186,     6,   185,
     265,   265,   186,   265,   186,   186,   185,   265,   265,   265,
     265,   265,   186,   186,   186,   265,   186,   184,   186,   186,
     184,   186,   186,   184,   186,   271,     6,    88,   186,   243,
     185,   184,   186,   184,     6,     6,   265,   279,   197,   179,
     184,     6,   185,   184,   265,   186,   184,   184,   184,   184,
       6,     6,   186,     6,   249,   265,     6,     6,   250,   265,
       6,     6,   251,   265,     6,   186,   265,   255,   234,   274,
       6,   268,   274,     7,   186,   203,   265,   270,   265,   184,
     265,   265,   265,   265,   185,   186,   185,   186,   185,   186,
       6,     6,   186,   186,   244,   186,   184,   186,   279,     6,
     185,   179,   186,   186,   265,   184,   184,   184,   184,   255,
       6,   252,   255,     6,   253,   255,     6,   254,   255,     6,
     274,     6,   201,   278,   206,   185,     6,   186,   265,   265,
     265,   265,   186,   185,   186,   185,   186,   185,   186,   186,
     184,   186,   185,   270,     6,   184,   184,   184,   184,     6,
     255,     6,   255,     6,   255,     6,   278,     6,   204,   278,
     186,   265,   265,   265,   265,   186,   186,   186,   184,   186,
       6,   184,   184,   184,   184,     6,     6,     6,   278,     6,
     265,   265,   265,   265,   186,   186,   186,   186,     6,     6,
       6,     6
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
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1251 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1255 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1264 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1268 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1277 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1281 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1290 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1294 "Gmsh.y"
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

  case 134:
/* Line 1787 of yacc.c  */
#line 1306 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1310 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1320 "Gmsh.y"
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

  case 137:
/* Line 1787 of yacc.c  */
#line 1343 "Gmsh.y"
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

  case 138:
/* Line 1787 of yacc.c  */
#line 1360 "Gmsh.y"
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

  case 139:
/* Line 1787 of yacc.c  */
#line 1374 "Gmsh.y"
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

  case 140:
/* Line 1787 of yacc.c  */
#line 1396 "Gmsh.y"
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
#line 1414 "Gmsh.y"
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
#line 1435 "Gmsh.y"
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
#line 1453 "Gmsh.y"
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
#line 1483 "Gmsh.y"
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
#line 1513 "Gmsh.y"
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
#line 1531 "Gmsh.y"
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
#line 1550 "Gmsh.y"
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
#line 1576 "Gmsh.y"
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
#line 1594 "Gmsh.y"
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
#line 1612 "Gmsh.y"
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
#line 1629 "Gmsh.y"
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

  case 152:
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

  case 153:
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

  case 154:
/* Line 1787 of yacc.c  */
#line 1703 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1709 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1715 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 157:
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

  case 158:
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

  case 159:
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

  case 160:
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

  case 161:
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

  case 162:
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1859 "Gmsh.y"
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

  case 164:
/* Line 1787 of yacc.c  */
#line 1877 "Gmsh.y"
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

  case 165:
/* Line 1787 of yacc.c  */
#line 1895 "Gmsh.y"
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

  case 166:
/* Line 1787 of yacc.c  */
#line 1912 "Gmsh.y"
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

  case 167:
/* Line 1787 of yacc.c  */
#line 1928 "Gmsh.y"
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

  case 168:
/* Line 1787 of yacc.c  */
#line 1945 "Gmsh.y"
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

  case 169:
/* Line 1787 of yacc.c  */
#line 1965 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1970 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1975 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1980 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1985 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1990 "Gmsh.y"
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
#line 2013 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2019 "Gmsh.y"
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
#line 2029 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2030 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2035 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2039 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2043 "Gmsh.y"
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
#line 2066 "Gmsh.y"
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
#line 2089 "Gmsh.y"
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
#line 2112 "Gmsh.y"
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
#line 2140 "Gmsh.y"
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
#line 2161 "Gmsh.y"
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
#line 2188 "Gmsh.y"
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
#line 2209 "Gmsh.y"
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
#line 2230 "Gmsh.y"
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
#line 2250 "Gmsh.y"
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
#line 2362 "Gmsh.y"
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
#line 2381 "Gmsh.y"
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
#line 2420 "Gmsh.y"
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
#line 2528 "Gmsh.y"
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
#line 2537 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 2543 "Gmsh.y"
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
#line 2558 "Gmsh.y"
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
#line 2586 "Gmsh.y"
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
#line 2603 "Gmsh.y"
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
#line 2612 "Gmsh.y"
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
#line 2626 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2632 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2638 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2647 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 2656 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 2665 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 2679 "Gmsh.y"
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

  case 208:
/* Line 1787 of yacc.c  */
#line 2735 "Gmsh.y"
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

  case 209:
/* Line 1787 of yacc.c  */
#line 2760 "Gmsh.y"
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

  case 210:
/* Line 1787 of yacc.c  */
#line 2777 "Gmsh.y"
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

  case 211:
/* Line 1787 of yacc.c  */
#line 2792 "Gmsh.y"
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

  case 212:
/* Line 1787 of yacc.c  */
#line 2811 "Gmsh.y"
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

  case 213:
/* Line 1787 of yacc.c  */
#line 2823 "Gmsh.y"
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

  case 214:
/* Line 1787 of yacc.c  */
#line 2847 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2851 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2856 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2863 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2869 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2874 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2880 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2888 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2892 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2896 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2902 "Gmsh.y"
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

  case 225:
/* Line 1787 of yacc.c  */
#line 2956 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 2969 "Gmsh.y"
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

  case 227:
/* Line 1787 of yacc.c  */
#line 2986 "Gmsh.y"
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

  case 228:
/* Line 1787 of yacc.c  */
#line 3003 "Gmsh.y"
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

  case 229:
/* Line 1787 of yacc.c  */
#line 3024 "Gmsh.y"
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

  case 230:
/* Line 1787 of yacc.c  */
#line 3045 "Gmsh.y"
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

  case 231:
/* Line 1787 of yacc.c  */
#line 3080 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3088 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3094 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3101 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3105 "Gmsh.y"
    {
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3114 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3122 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3130 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3144 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3152 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3158 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3166 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3172 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3180 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3186 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3194 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3201 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3208 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3215 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3222 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3229 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3236 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3243 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3250 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3257 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3263 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3270 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3276 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3283 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3289 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3296 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3309 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3322 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3335 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3348 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3361 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3367 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3378 "Gmsh.y"
    {
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3381 "Gmsh.y"
    {
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3387 "Gmsh.y"
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

  case 277:
/* Line 1787 of yacc.c  */
#line 3399 "Gmsh.y"
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

  case 278:
/* Line 1787 of yacc.c  */
#line 3419 "Gmsh.y"
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

  case 279:
/* Line 1787 of yacc.c  */
#line 3443 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3447 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3451 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3455 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3459 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3465 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3471 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3475 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3479 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3483 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3487 "Gmsh.y"
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

  case 290:
/* Line 1787 of yacc.c  */
#line 3506 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3518 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3522 "Gmsh.y"
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

  case 293:
/* Line 1787 of yacc.c  */
#line 3537 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3541 "Gmsh.y"
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

  case 295:
/* Line 1787 of yacc.c  */
#line 3557 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3561 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3566 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3570 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3577 "Gmsh.y"
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
#line 3633 "Gmsh.y"
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
#line 3703 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3708 "Gmsh.y"
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
#line 3775 "Gmsh.y"
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

  case 304:
/* Line 1787 of yacc.c  */
#line 3811 "Gmsh.y"
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
#line 3819 "Gmsh.y"
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
#line 3862 "Gmsh.y"
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
#line 3901 "Gmsh.y"
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
#line 3921 "Gmsh.y"
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
#line 3949 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3988 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4011 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 4034 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 4038 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 4042 "Gmsh.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 4065 "Gmsh.y"
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
#line 4104 "Gmsh.y"
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
#line 4143 "Gmsh.y"
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
#line 4164 "Gmsh.y"
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
#line 4185 "Gmsh.y"
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
#line 4212 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4216 "Gmsh.y"
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
#line 4226 "Gmsh.y"
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
#line 4260 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4261 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4262 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4267 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4273 "Gmsh.y"
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
#line 4285 "Gmsh.y"
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
#line 4303 "Gmsh.y"
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
#line 4330 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4331 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4332 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4334 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4335 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4336 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4337 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4339 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4345 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4346 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4347 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4348 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4350 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4351 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4352 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4353 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4354 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4355 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4356 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4357 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4358 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4359 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4360 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4361 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4362 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4363 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4364 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4365 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4366 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4367 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4368 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4370 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4371 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4372 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4373 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4374 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4375 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4376 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4377 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4386 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4387 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4388 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4389 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4390 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4391 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4392 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4393 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4394 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4395 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4400 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4402 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4408 "Gmsh.y"
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
#line 4425 "Gmsh.y"
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
#line 4443 "Gmsh.y"
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
#line 4461 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4466 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4472 "Gmsh.y"
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
#line 4484 "Gmsh.y"
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
#line 4501 "Gmsh.y"
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
#line 4519 "Gmsh.y"
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
#line 4540 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4545 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 4550 "Gmsh.y"
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
#line 4560 "Gmsh.y"
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
#line 4570 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4575 "Gmsh.y"
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
#line 4584 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4589 "Gmsh.y"
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
#line 4616 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4624 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4632 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4639 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4643 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
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
#line 4651 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4658 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4663 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4670 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4675 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4679 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4688 "Gmsh.y"
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
#line 4696 "Gmsh.y"
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
#line 4707 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4711 "Gmsh.y"
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
#line 4723 "Gmsh.y"
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
#line 4731 "Gmsh.y"
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
#line 4739 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4746 "Gmsh.y"
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
#line 4756 "Gmsh.y"
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
#line 4785 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4789 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4793 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4797 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4801 "Gmsh.y"
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

  case 430:
/* Line 1787 of yacc.c  */
#line 4830 "Gmsh.y"
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

  case 431:
/* Line 1787 of yacc.c  */
#line 4859 "Gmsh.y"
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

  case 432:
/* Line 1787 of yacc.c  */
#line 4888 "Gmsh.y"
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

  case 433:
/* Line 1787 of yacc.c  */
#line 4917 "Gmsh.y"
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

  case 434:
/* Line 1787 of yacc.c  */
#line 4927 "Gmsh.y"
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
#line 4937 "Gmsh.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 4949 "Gmsh.y"
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

  case 437:
/* Line 1787 of yacc.c  */
#line 4961 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 4982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 4987 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 4991 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 4995 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 5007 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 5011 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 5023 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 5030 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5040 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 5044 "Gmsh.y"
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

  case 448:
/* Line 1787 of yacc.c  */
#line 5059 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5064 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5071 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5075 "Gmsh.y"
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

  case 452:
/* Line 1787 of yacc.c  */
#line 5088 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5096 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5107 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5111 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5119 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5125 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5133 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5141 "Gmsh.y"
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

  case 460:
/* Line 1787 of yacc.c  */
#line 5156 "Gmsh.y"
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

  case 461:
/* Line 1787 of yacc.c  */
#line 5170 "Gmsh.y"
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

  case 462:
/* Line 1787 of yacc.c  */
#line 5184 "Gmsh.y"
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

  case 463:
/* Line 1787 of yacc.c  */
#line 5196 "Gmsh.y"
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

  case 464:
/* Line 1787 of yacc.c  */
#line 5212 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5216 "Gmsh.y"
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

  case 466:
/* Line 1787 of yacc.c  */
#line 5235 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5237 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5248 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5253 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5259 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5268 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5281 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5284 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11103 "Gmsh.tab.cpp"
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
#line 5288 "Gmsh.y"


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
