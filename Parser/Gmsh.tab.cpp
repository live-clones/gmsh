/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse gmsh_yyparse
#define yylex   gmsh_yylex
#define yyerror gmsh_yyerror
#define yylval  gmsh_yylval
#define yychar  gmsh_yychar
#define yydebug gmsh_yydebug
#define yynerrs gmsh_yynerrs


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
     tFmod = 287,
     tModulo = 288,
     tHypot = 289,
     tPrintf = 290,
     tSprintf = 291,
     tStrCat = 292,
     tStrPrefix = 293,
     tStrRelative = 294,
     tBoundingBox = 295,
     tDraw = 296,
     tToday = 297,
     tSyncModel = 298,
     tCreateTopology = 299,
     tDistanceFunction = 300,
     tPoint = 301,
     tCircle = 302,
     tEllipse = 303,
     tLine = 304,
     tSphere = 305,
     tPolarSphere = 306,
     tSurface = 307,
     tSpline = 308,
     tVolume = 309,
     tCharacteristic = 310,
     tLength = 311,
     tParametric = 312,
     tElliptic = 313,
     tPlane = 314,
     tRuled = 315,
     tTransfinite = 316,
     tComplex = 317,
     tPhysical = 318,
     tCompound = 319,
     tPeriodic = 320,
     tUsing = 321,
     tPlugin = 322,
     tDegenerated = 323,
     tRotate = 324,
     tTranslate = 325,
     tSymmetry = 326,
     tDilate = 327,
     tExtrude = 328,
     tLevelset = 329,
     tLoop = 330,
     tRecombine = 331,
     tSmoother = 332,
     tSplit = 333,
     tDelete = 334,
     tCoherence = 335,
     tIntersect = 336,
     tLayers = 337,
     tHole = 338,
     tAlias = 339,
     tAliasWithOptions = 340,
     tText2D = 341,
     tText3D = 342,
     tInterpolationScheme = 343,
     tTime = 344,
     tCombine = 345,
     tBSpline = 346,
     tBezier = 347,
     tNurbs = 348,
     tNurbsOrder = 349,
     tNurbsKnots = 350,
     tColor = 351,
     tColorTable = 352,
     tFor = 353,
     tIn = 354,
     tEndFor = 355,
     tIf = 356,
     tEndIf = 357,
     tExit = 358,
     tField = 359,
     tReturn = 360,
     tCall = 361,
     tFunction = 362,
     tShow = 363,
     tHide = 364,
     tGetValue = 365,
     tGetEnv = 366,
     tGetString = 367,
     tGMSH_MAJOR_VERSION = 368,
     tGMSH_MINOR_VERSION = 369,
     tGMSH_PATCH_VERSION = 370,
     tHomRank = 371,
     tHomGen = 372,
     tHomCut = 373,
     tHomSeq = 374,
     tAFFECTDIVIDE = 375,
     tAFFECTTIMES = 376,
     tAFFECTMINUS = 377,
     tAFFECTPLUS = 378,
     tOR = 379,
     tAND = 380,
     tNOTEQUAL = 381,
     tEQUAL = 382,
     tGREATEROREQUAL = 383,
     tLESSOREQUAL = 384,
     UNARYPREC = 385,
     tMINUSMINUS = 386,
     tPLUSPLUS = 387
   };
#endif
/* Tokens.  */
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tPi 264
#define tMPI_Rank 265
#define tMPI_Size 266
#define tEuclidian 267
#define tCoordinates 268
#define tExp 269
#define tLog 270
#define tLog10 271
#define tSqrt 272
#define tSin 273
#define tAsin 274
#define tCos 275
#define tAcos 276
#define tTan 277
#define tRand 278
#define tAtan 279
#define tAtan2 280
#define tSinh 281
#define tCosh 282
#define tTanh 283
#define tFabs 284
#define tFloor 285
#define tCeil 286
#define tFmod 287
#define tModulo 288
#define tHypot 289
#define tPrintf 290
#define tSprintf 291
#define tStrCat 292
#define tStrPrefix 293
#define tStrRelative 294
#define tBoundingBox 295
#define tDraw 296
#define tToday 297
#define tSyncModel 298
#define tCreateTopology 299
#define tDistanceFunction 300
#define tPoint 301
#define tCircle 302
#define tEllipse 303
#define tLine 304
#define tSphere 305
#define tPolarSphere 306
#define tSurface 307
#define tSpline 308
#define tVolume 309
#define tCharacteristic 310
#define tLength 311
#define tParametric 312
#define tElliptic 313
#define tPlane 314
#define tRuled 315
#define tTransfinite 316
#define tComplex 317
#define tPhysical 318
#define tCompound 319
#define tPeriodic 320
#define tUsing 321
#define tPlugin 322
#define tDegenerated 323
#define tRotate 324
#define tTranslate 325
#define tSymmetry 326
#define tDilate 327
#define tExtrude 328
#define tLevelset 329
#define tLoop 330
#define tRecombine 331
#define tSmoother 332
#define tSplit 333
#define tDelete 334
#define tCoherence 335
#define tIntersect 336
#define tLayers 337
#define tHole 338
#define tAlias 339
#define tAliasWithOptions 340
#define tText2D 341
#define tText3D 342
#define tInterpolationScheme 343
#define tTime 344
#define tCombine 345
#define tBSpline 346
#define tBezier 347
#define tNurbs 348
#define tNurbsOrder 349
#define tNurbsKnots 350
#define tColor 351
#define tColorTable 352
#define tFor 353
#define tIn 354
#define tEndFor 355
#define tIf 356
#define tEndIf 357
#define tExit 358
#define tField 359
#define tReturn 360
#define tCall 361
#define tFunction 362
#define tShow 363
#define tHide 364
#define tGetValue 365
#define tGetEnv 366
#define tGetString 367
#define tGMSH_MAJOR_VERSION 368
#define tGMSH_MINOR_VERSION 369
#define tGMSH_PATCH_VERSION 370
#define tHomRank 371
#define tHomGen 372
#define tHomCut 373
#define tHomSeq 374
#define tAFFECTDIVIDE 375
#define tAFFECTTIMES 376
#define tAFFECTMINUS 377
#define tAFFECTPLUS 378
#define tOR 379
#define tAND 380
#define tNOTEQUAL 381
#define tEQUAL 382
#define tGREATEROREQUAL 383
#define tLESSOREQUAL 384
#define UNARYPREC 385
#define tMINUSMINUS 386
#define tPLUSPLUS 387




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
#include "Colors.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "OS.h"
#include "CreateFile.h"
#include "gmshSurface.h"
#include "gmshLevelset.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#include "BackgroundMesh.h"
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

#if defined(HAVE_KBIPACK)
#include "Homology.h"
#endif

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, std::vector<double> > gmsh_yysymbols;

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string > gmsh_yystringsymbols;
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
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static const char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 88 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
}
/* Line 193 of yacc.c.  */
#line 465 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 478 "Gmsh.tab.cpp"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6954

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  388
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1400

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   387

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   138,     2,   148,     2,   137,     2,     2,
     143,   144,   135,   133,   149,   134,   147,   136,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     129,     2,   130,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   145,     2,   146,   142,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   150,     2,   151,   152,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   125,
     126,   127,   128,   131,   132,   139,   140,   141
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    51,    57,    65,    73,    83,
      90,    97,   104,   105,   108,   111,   114,   117,   120,   122,
     126,   128,   132,   133,   134,   145,   147,   151,   152,   166,
     168,   172,   173,   189,   198,   213,   214,   221,   223,   225,
     227,   229,   231,   233,   235,   240,   248,   258,   265,   272,
     276,   283,   288,   295,   305,   312,   322,   328,   337,   346,
     358,   365,   375,   381,   389,   399,   409,   421,   431,   441,
     443,   445,   446,   452,   453,   456,   464,   465,   475,   482,
     490,   495,   503,   512,   521,   529,   537,   549,   558,   567,
     568,   578,   587,   597,   601,   606,   617,   625,   633,   642,
     651,   664,   665,   675,   684,   692,   701,   702,   712,   718,
     730,   736,   746,   751,   761,   771,   773,   775,   776,   779,
     786,   793,   800,   807,   816,   831,   848,   861,   870,   879,
     886,   901,   906,   913,   920,   924,   929,   935,   939,   943,
     948,   953,   957,   965,   973,   977,   985,   989,   992,   995,
     998,  1014,  1017,  1020,  1027,  1036,  1045,  1056,  1058,  1061,
    1063,  1067,  1072,  1074,  1080,  1092,  1106,  1107,  1115,  1116,
    1130,  1131,  1147,  1148,  1155,  1164,  1173,  1182,  1195,  1208,
    1221,  1236,  1251,  1266,  1267,  1280,  1281,  1294,  1295,  1308,
    1309,  1326,  1327,  1344,  1345,  1362,  1363,  1382,  1383,  1402,
    1403,  1422,  1424,  1427,  1433,  1441,  1451,  1454,  1464,  1471,
    1472,  1476,  1477,  1479,  1480,  1483,  1484,  1487,  1495,  1502,
    1511,  1517,  1523,  1530,  1537,  1550,  1561,  1572,  1583,  1594,
    1597,  1601,  1608,  1620,  1632,  1644,  1656,  1658,  1662,  1665,
    1668,  1671,  1675,  1679,  1683,  1687,  1691,  1695,  1699,  1703,
    1707,  1711,  1715,  1719,  1723,  1727,  1733,  1738,  1743,  1748,
    1753,  1758,  1763,  1768,  1773,  1778,  1783,  1790,  1795,  1800,
    1805,  1810,  1815,  1820,  1827,  1834,  1841,  1846,  1851,  1856,
    1861,  1866,  1871,  1876,  1881,  1886,  1891,  1896,  1903,  1908,
    1913,  1918,  1923,  1928,  1933,  1940,  1947,  1954,  1959,  1961,
    1963,  1965,  1967,  1969,  1971,  1973,  1975,  1981,  1986,  1991,
    1994,  2000,  2004,  2011,  2016,  2024,  2031,  2033,  2036,  2039,
    2043,  2047,  2059,  2069,  2077,  2085,  2087,  2091,  2093,  2095,
    2098,  2102,  2107,  2113,  2115,  2117,  2120,  2124,  2128,  2134,
    2139,  2141,  2143,  2147,  2154,  2156,  2158,  2162,  2166,  2176,
    2184,  2186,  2192,  2196,  2203,  2205,  2209,  2211,  2213,  2217,
    2224,  2226,  2228,  2233,  2240,  2247,  2252,  2257,  2262
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     154,     0,    -1,   155,    -1,     1,     6,    -1,    -1,   155,
     156,    -1,   159,    -1,   158,    -1,   177,    -1,   181,    -1,
     186,    -1,   190,    -1,   191,    -1,   192,    -1,   195,    -1,
     215,    -1,   216,    -1,   217,    -1,   218,    -1,   194,    -1,
     193,    -1,   189,    -1,   219,    -1,   130,    -1,   130,   130,
      -1,    35,   143,     5,   144,     6,    -1,    35,   143,     5,
     144,   157,   232,     6,    -1,    35,   143,     5,   149,   228,
     144,     6,    -1,    35,   143,     5,   149,   228,   144,   157,
     232,     6,    -1,     4,     5,   150,   160,   151,     6,    -1,
      84,     4,   145,   220,   146,     6,    -1,    85,     4,   145,
     220,   146,     6,    -1,    -1,   160,   163,    -1,   160,   167,
      -1,   160,   170,    -1,   160,   172,    -1,   160,   173,    -1,
     220,    -1,   161,   149,   220,    -1,   220,    -1,   162,   149,
     220,    -1,    -1,    -1,     4,   164,   143,   161,   144,   165,
     150,   162,   151,     6,    -1,   232,    -1,   166,   149,   232,
      -1,    -1,    86,   143,   220,   149,   220,   149,   220,   144,
     168,   150,   166,   151,     6,    -1,   232,    -1,   169,   149,
     232,    -1,    -1,    87,   143,   220,   149,   220,   149,   220,
     149,   220,   144,   171,   150,   169,   151,     6,    -1,    88,
     150,   224,   151,   150,   224,   151,     6,    -1,    88,   150,
     224,   151,   150,   224,   151,   150,   224,   151,   150,   224,
     151,     6,    -1,    -1,    89,   174,   150,   162,   151,     6,
      -1,     7,    -1,   123,    -1,   122,    -1,   121,    -1,   120,
      -1,   141,    -1,   140,    -1,     4,   175,   220,     6,    -1,
       4,   145,   220,   146,   175,   220,     6,    -1,     4,   145,
     150,   228,   151,   146,   175,   225,     6,    -1,     4,   145,
     146,     7,   225,     6,    -1,     4,   145,   146,   123,   225,
       6,    -1,     4,   176,     6,    -1,     4,   145,   220,   146,
     176,     6,    -1,     4,     7,   233,     6,    -1,     4,   147,
       4,     7,   233,     6,    -1,     4,   145,   220,   146,   147,
       4,     7,   233,     6,    -1,     4,   147,     4,   175,   220,
       6,    -1,     4,   145,   220,   146,   147,     4,   175,   220,
       6,    -1,     4,   147,     4,   176,     6,    -1,     4,   145,
     220,   146,   147,     4,   176,     6,    -1,     4,   147,    96,
     147,     4,     7,   229,     6,    -1,     4,   145,   220,   146,
     147,    96,   147,     4,     7,   229,     6,    -1,     4,   147,
      97,     7,   230,     6,    -1,     4,   145,   220,   146,   147,
      97,     7,   230,     6,    -1,     4,   104,     7,   220,     6,
      -1,   104,   145,   220,   146,     7,     4,     6,    -1,   104,
     145,   220,   146,   147,     4,     7,   220,     6,    -1,   104,
     145,   220,   146,   147,     4,     7,   233,     6,    -1,   104,
     145,   220,   146,   147,     4,     7,   150,   228,   151,     6,
      -1,    67,   143,     4,   144,   147,     4,     7,   220,     6,
      -1,    67,   143,     4,   144,   147,     4,     7,   233,     6,
      -1,   220,    -1,   233,    -1,    -1,    99,    50,   150,   220,
     151,    -1,    -1,    59,   222,    -1,    46,   143,   220,   144,
       7,   222,     6,    -1,    -1,    63,    46,   182,   143,   178,
     144,     7,   225,     6,    -1,    55,    56,   225,     7,   220,
       6,    -1,    49,   143,   220,   144,     7,   225,     6,    -1,
      68,    49,   225,     6,    -1,    53,   143,   220,   144,     7,
     225,     6,    -1,    47,   143,   220,   144,     7,   225,   180,
       6,    -1,    48,   143,   220,   144,     7,   225,   180,     6,
      -1,    91,   143,   220,   144,     7,   225,     6,    -1,    92,
     143,   220,   144,     7,   225,     6,    -1,    93,   143,   220,
     144,     7,   225,    95,   225,    94,   220,     6,    -1,    49,
      75,   143,   220,   144,     7,   225,     6,    -1,    64,    49,
     143,   220,   144,     7,   225,     6,    -1,    -1,    63,    49,
     183,   143,   178,   144,     7,   225,     6,    -1,    59,    52,
     143,   220,   144,     7,   225,     6,    -1,    60,    52,   143,
     220,   144,     7,   225,   179,     6,    -1,    12,    13,     6,
      -1,    13,    52,   220,     6,    -1,    57,    52,   143,   220,
     144,     7,     5,     5,     5,     6,    -1,    50,   143,   220,
     144,     7,   225,     6,    -1,    51,   143,   220,   144,     7,
     225,     6,    -1,    52,    75,   143,   220,   144,     7,   225,
       6,    -1,    64,    52,   143,   220,   144,     7,   225,     6,
      -1,    64,    52,   143,   220,   144,     7,   225,     4,   150,
     224,   151,     6,    -1,    -1,    63,    52,   184,   143,   178,
     144,     7,   225,     6,    -1,    62,    54,   143,   220,   144,
       7,   225,     6,    -1,    54,   143,   220,   144,     7,   225,
       6,    -1,    64,    54,   143,   220,   144,     7,   225,     6,
      -1,    -1,    63,    54,   185,   143,   178,   144,     7,   225,
       6,    -1,    70,   222,   150,   187,   151,    -1,    69,   150,
     222,   149,   222,   149,   220,   151,   150,   187,   151,    -1,
      71,   222,   150,   187,   151,    -1,    72,   150,   222,   149,
     220,   151,   150,   187,   151,    -1,     4,   150,   187,   151,
      -1,    81,    49,   150,   228,   151,    52,   150,   220,   151,
      -1,    78,    49,   143,   220,   144,   150,   228,   151,     6,
      -1,   188,    -1,   186,    -1,    -1,   188,   181,    -1,   188,
      46,   150,   228,   151,     6,    -1,   188,    49,   150,   228,
     151,     6,    -1,   188,    52,   150,   228,   151,     6,    -1,
     188,    54,   150,   228,   151,     6,    -1,    74,    59,   143,
     220,   144,     7,   225,     6,    -1,    74,    59,   143,   220,
     144,     7,   150,   222,   149,   222,   149,   228,   151,     6,
      -1,    74,    59,   143,   220,   144,     7,   150,   222,   149,
     222,   149,   222,   149,   228,   151,     6,    -1,    74,    50,
     143,   220,   144,     7,   150,   222,   149,   228,   151,     6,
      -1,    74,     4,   143,   220,   144,     7,   225,     6,    -1,
      74,     4,   143,   220,   144,     7,     5,     6,    -1,    74,
       4,   150,   220,   151,     6,    -1,    74,     4,   143,   220,
     144,     7,   150,   222,   149,   222,   149,   228,   151,     6,
      -1,    79,   150,   188,   151,    -1,    79,   104,   145,   220,
     146,     6,    -1,    79,     4,   145,   220,   146,     6,    -1,
      79,     4,     6,    -1,    79,     4,     4,     6,    -1,    96,
     229,   150,   188,   151,    -1,   108,     5,     6,    -1,   109,
       5,     6,    -1,   108,   150,   188,   151,    -1,   109,   150,
     188,   151,    -1,     4,   233,     6,    -1,     4,     4,   145,
     220,   146,   232,     6,    -1,     4,     4,     4,   145,   220,
     146,     6,    -1,     4,   220,     6,    -1,    67,   143,     4,
     144,   147,     4,     6,    -1,    90,     4,     6,    -1,   103,
       6,    -1,    43,     6,    -1,    40,     6,    -1,    40,   150,
     220,   149,   220,   149,   220,   149,   220,   149,   220,   149,
     220,   151,     6,    -1,    41,     6,    -1,    44,     6,    -1,
      98,   143,   220,     8,   220,   144,    -1,    98,   143,   220,
       8,   220,     8,   220,   144,    -1,    98,     4,    99,   150,
     220,     8,   220,   151,    -1,    98,     4,    99,   150,   220,
       8,   220,     8,   220,   151,    -1,   100,    -1,   107,     4,
      -1,   105,    -1,   106,     4,     6,    -1,   101,   143,   220,
     144,    -1,   102,    -1,    73,   222,   150,   188,   151,    -1,
      73,   150,   222,   149,   222,   149,   220,   151,   150,   188,
     151,    -1,    73,   150,   222,   149,   222,   149,   222,   149,
     220,   151,   150,   188,   151,    -1,    -1,    73,   222,   150,
     188,   196,   209,   151,    -1,    -1,    73,   150,   222,   149,
     222,   149,   220,   151,   150,   188,   197,   209,   151,    -1,
      -1,    73,   150,   222,   149,   222,   149,   222,   149,   220,
     151,   150,   188,   198,   209,   151,    -1,    -1,    73,   150,
     188,   199,   209,   151,    -1,    73,    46,   150,   220,   149,
     222,   151,     6,    -1,    73,    49,   150,   220,   149,   222,
     151,     6,    -1,    73,    52,   150,   220,   149,   222,   151,
       6,    -1,    73,    46,   150,   220,   149,   222,   149,   222,
     149,   220,   151,     6,    -1,    73,    49,   150,   220,   149,
     222,   149,   222,   149,   220,   151,     6,    -1,    73,    52,
     150,   220,   149,   222,   149,   222,   149,   220,   151,     6,
      -1,    73,    46,   150,   220,   149,   222,   149,   222,   149,
     222,   149,   220,   151,     6,    -1,    73,    49,   150,   220,
     149,   222,   149,   222,   149,   222,   149,   220,   151,     6,
      -1,    73,    52,   150,   220,   149,   222,   149,   222,   149,
     222,   149,   220,   151,     6,    -1,    -1,    73,    46,   150,
     220,   149,   222,   151,   200,   150,   209,   151,     6,    -1,
      -1,    73,    49,   150,   220,   149,   222,   151,   201,   150,
     209,   151,     6,    -1,    -1,    73,    52,   150,   220,   149,
     222,   151,   202,   150,   209,   151,     6,    -1,    -1,    73,
      46,   150,   220,   149,   222,   149,   222,   149,   220,   151,
     203,   150,   209,   151,     6,    -1,    -1,    73,    49,   150,
     220,   149,   222,   149,   222,   149,   220,   151,   204,   150,
     209,   151,     6,    -1,    -1,    73,    52,   150,   220,   149,
     222,   149,   222,   149,   220,   151,   205,   150,   209,   151,
       6,    -1,    -1,    73,    46,   150,   220,   149,   222,   149,
     222,   149,   222,   149,   220,   151,   206,   150,   209,   151,
       6,    -1,    -1,    73,    49,   150,   220,   149,   222,   149,
     222,   149,   222,   149,   220,   151,   207,   150,   209,   151,
       6,    -1,    -1,    73,    52,   150,   220,   149,   222,   149,
     222,   149,   222,   149,   220,   151,   208,   150,   209,   151,
       6,    -1,   210,    -1,   209,   210,    -1,    82,   150,   220,
     151,     6,    -1,    82,   150,   225,   149,   225,   151,     6,
      -1,    82,   150,   225,   149,   225,   149,   225,   151,     6,
      -1,    76,     6,    -1,    83,   143,   220,   144,     7,   225,
      66,   220,     6,    -1,    66,     4,   145,   220,   146,     6,
      -1,    -1,    66,     4,   220,    -1,    -1,     4,    -1,    -1,
       7,   225,    -1,    -1,     7,   220,    -1,    61,    49,   226,
       7,   220,   211,     6,    -1,    61,    52,   226,   213,   212,
       6,    -1,    58,    52,   150,   220,   151,     7,   225,     6,
      -1,    61,    54,   226,   213,     6,    -1,    76,    52,   226,
     214,     6,    -1,    77,    52,   225,     7,   220,     6,    -1,
      65,    49,   225,     7,   225,     6,    -1,    65,    52,   220,
     150,   228,   151,     7,   220,   150,   228,   151,     6,    -1,
      46,   150,   228,   151,    99,    52,   150,   220,   151,     6,
      -1,    49,   150,   228,   151,    99,    52,   150,   220,   151,
       6,    -1,    49,   150,   228,   151,    99,    54,   150,   220,
     151,     6,    -1,    52,   150,   228,   151,    99,    54,   150,
     220,   151,     6,    -1,    80,     6,    -1,    80,     4,     6,
      -1,    80,    46,   150,   228,   151,     6,    -1,   116,   143,
     232,   144,     7,   150,   225,   149,   225,   151,     6,    -1,
     117,   143,   232,   144,     7,   150,   225,   149,   225,   151,
       6,    -1,   118,   143,   232,   144,     7,   150,   225,   149,
     225,   151,     6,    -1,   119,   143,   232,   144,     7,   150,
     225,   149,   225,   151,     6,    -1,   221,    -1,   143,   220,
     144,    -1,   134,   220,    -1,   133,   220,    -1,   138,   220,
      -1,   220,   134,   220,    -1,   220,   133,   220,    -1,   220,
     135,   220,    -1,   220,   136,   220,    -1,   220,   137,   220,
      -1,   220,   142,   220,    -1,   220,   129,   220,    -1,   220,
     130,   220,    -1,   220,   132,   220,    -1,   220,   131,   220,
      -1,   220,   128,   220,    -1,   220,   127,   220,    -1,   220,
     126,   220,    -1,   220,   125,   220,    -1,   220,   124,   220,
       8,   220,    -1,    14,   143,   220,   144,    -1,    15,   143,
     220,   144,    -1,    16,   143,   220,   144,    -1,    17,   143,
     220,   144,    -1,    18,   143,   220,   144,    -1,    19,   143,
     220,   144,    -1,    20,   143,   220,   144,    -1,    21,   143,
     220,   144,    -1,    22,   143,   220,   144,    -1,    24,   143,
     220,   144,    -1,    25,   143,   220,   149,   220,   144,    -1,
      26,   143,   220,   144,    -1,    27,   143,   220,   144,    -1,
      28,   143,   220,   144,    -1,    29,   143,   220,   144,    -1,
      30,   143,   220,   144,    -1,    31,   143,   220,   144,    -1,
      32,   143,   220,   149,   220,   144,    -1,    33,   143,   220,
     149,   220,   144,    -1,    34,   143,   220,   149,   220,   144,
      -1,    23,   143,   220,   144,    -1,    14,   145,   220,   146,
      -1,    15,   145,   220,   146,    -1,    16,   145,   220,   146,
      -1,    17,   145,   220,   146,    -1,    18,   145,   220,   146,
      -1,    19,   145,   220,   146,    -1,    20,   145,   220,   146,
      -1,    21,   145,   220,   146,    -1,    22,   145,   220,   146,
      -1,    24,   145,   220,   146,    -1,    25,   145,   220,   149,
     220,   146,    -1,    26,   145,   220,   146,    -1,    27,   145,
     220,   146,    -1,    28,   145,   220,   146,    -1,    29,   145,
     220,   146,    -1,    30,   145,   220,   146,    -1,    31,   145,
     220,   146,    -1,    32,   145,   220,   149,   220,   146,    -1,
      33,   145,   220,   149,   220,   146,    -1,    34,   145,   220,
     149,   220,   146,    -1,    23,   145,   220,   146,    -1,     3,
      -1,     9,    -1,    10,    -1,    11,    -1,   113,    -1,   114,
      -1,   115,    -1,     4,    -1,     4,   152,   150,   220,   151,
      -1,     4,   145,   220,   146,    -1,   148,     4,   145,   146,
      -1,     4,   176,    -1,     4,   145,   220,   146,   176,    -1,
       4,   147,     4,    -1,     4,   145,   220,   146,   147,     4,
      -1,     4,   147,     4,   176,    -1,     4,   145,   220,   146,
     147,     4,   176,    -1,   110,   143,   232,   149,   220,   144,
      -1,   223,    -1,   134,   222,    -1,   133,   222,    -1,   222,
     134,   222,    -1,   222,   133,   222,    -1,   150,   220,   149,
     220,   149,   220,   149,   220,   149,   220,   151,    -1,   150,
     220,   149,   220,   149,   220,   149,   220,   151,    -1,   150,
     220,   149,   220,   149,   220,   151,    -1,   143,   220,   149,
     220,   149,   220,   144,    -1,   225,    -1,   224,   149,   225,
      -1,   220,    -1,   227,    -1,   150,   151,    -1,   150,   228,
     151,    -1,   134,   150,   228,   151,    -1,   220,   135,   150,
     228,   151,    -1,   225,    -1,     5,    -1,   134,   227,    -1,
     220,   135,   227,    -1,   220,     8,   220,    -1,   220,     8,
     220,     8,   220,    -1,    46,   150,   220,   151,    -1,   186,
      -1,   195,    -1,     4,   145,   146,    -1,     4,   145,   150,
     228,   151,   146,    -1,   220,    -1,   227,    -1,   228,   149,
     220,    -1,   228,   149,   227,    -1,   150,   220,   149,   220,
     149,   220,   149,   220,   151,    -1,   150,   220,   149,   220,
     149,   220,   151,    -1,     4,    -1,     4,   147,    96,   147,
       4,    -1,   150,   231,   151,    -1,     4,   145,   220,   146,
     147,    97,    -1,   229,    -1,   231,   149,   229,    -1,   233,
      -1,     4,    -1,     4,   147,     4,    -1,     4,   145,   220,
     146,   147,     4,    -1,     5,    -1,    42,    -1,   111,   143,
     232,   144,    -1,   112,   143,   232,   149,   232,   144,    -1,
      37,   143,   232,   149,   232,   144,    -1,    38,   143,   232,
     144,    -1,    39,   143,   232,   144,    -1,    36,   143,   232,
     144,    -1,    36,   143,   232,   149,   228,   144,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   159,   164,   166,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   190,   194,   201,   206,   220,   233,   261,
     275,   286,   301,   306,   307,   308,   309,   310,   314,   316,
     321,   323,   329,   433,   328,   451,   458,   469,   468,   486,
     493,   504,   503,   520,   537,   560,   559,   573,   574,   575,
     576,   577,   581,   582,   589,   615,   642,   682,   692,   700,
     712,   724,   733,   739,   748,   766,   784,   793,   805,   810,
     818,   838,   861,   870,   878,   900,   923,   951,   963,   980,
     984,   995,   998,  1011,  1014,  1024,  1048,  1047,  1067,  1089,
    1107,  1128,  1146,  1176,  1206,  1224,  1242,  1268,  1285,  1304,
    1303,  1326,  1344,  1383,  1389,  1395,  1402,  1427,  1452,  1468,
    1485,  1517,  1516,  1540,  1558,  1575,  1592,  1591,  1617,  1622,
    1627,  1632,  1637,  1660,  1666,  1677,  1678,  1683,  1686,  1690,
    1713,  1736,  1759,  1787,  1808,  1829,  1851,  1871,  1983,  2002,
    2022,  2131,  2140,  2146,  2161,  2189,  2206,  2220,  2226,  2232,
    2241,  2255,  2297,  2314,  2329,  2348,  2360,  2384,  2388,  2395,
    2401,  2406,  2412,  2422,  2439,  2456,  2475,  2494,  2524,  2532,
    2538,  2545,  2549,  2558,  2566,  2574,  2583,  2582,  2595,  2594,
    2607,  2606,  2619,  2618,  2630,  2637,  2644,  2651,  2658,  2665,
    2672,  2679,  2686,  2694,  2693,  2705,  2704,  2716,  2715,  2727,
    2726,  2738,  2737,  2749,  2748,  2760,  2759,  2771,  2770,  2782,
    2781,  2796,  2799,  2805,  2814,  2834,  2857,  2861,  2880,  2893,
    2896,  2912,  2915,  2928,  2931,  2937,  2940,  2947,  3003,  3073,
    3078,  3145,  3188,  3213,  3240,  3284,  3307,  3330,  3333,  3342,
    3346,  3356,  3390,  3427,  3463,  3498,  3538,  3539,  3540,  3541,
    3542,  3543,  3544,  3545,  3546,  3553,  3554,  3555,  3556,  3557,
    3558,  3559,  3560,  3561,  3562,  3563,  3564,  3565,  3566,  3567,
    3568,  3569,  3570,  3571,  3572,  3573,  3574,  3575,  3576,  3577,
    3578,  3579,  3580,  3581,  3582,  3583,  3584,  3586,  3587,  3588,
    3589,  3590,  3591,  3592,  3593,  3594,  3595,  3596,  3597,  3598,
    3599,  3600,  3601,  3602,  3603,  3604,  3605,  3606,  3615,  3616,
    3617,  3618,  3619,  3620,  3621,  3625,  3644,  3662,  3677,  3687,
    3703,  3721,  3726,  3731,  3741,  3751,  3759,  3763,  3767,  3771,
    3775,  3782,  3786,  3790,  3794,  3801,  3806,  3813,  3818,  3822,
    3827,  3831,  3839,  3850,  3854,  3866,  3874,  3882,  3889,  3900,
    3920,  3930,  3940,  3950,  3970,  3975,  3979,  3983,  3995,  3999,
    4011,  4018,  4028,  4032,  4047,  4052,  4059,  4063,  4076,  4084,
    4095,  4099,  4107,  4115,  4123,  4131,  4145,  4159,  4163
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tExp", "tLog", "tLog10", "tSqrt", "tSin", "tAsin",
  "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh", "tCosh",
  "tTanh", "tFabs", "tFloor", "tCeil", "tFmod", "tModulo", "tHypot",
  "tPrintf", "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative",
  "tBoundingBox", "tDraw", "tToday", "tSyncModel", "tCreateTopology",
  "tDistanceFunction", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tLoop", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tField", "tReturn", "tCall",
  "tFunction", "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tHomRank", "tHomGen", "tHomCut", "tHomSeq", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "Affectation", "PhysicalId",
  "InSphereCenter", "CircleOptions", "Shape", "@6", "@7", "@8", "@9",
  "Transform", "MultipleShape", "ListOfShapes", "LevelSet", "Delete",
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "@10", "@11",
  "@12", "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21",
  "@22", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "Transfinite", "Periodic", "Embedding", "Coherence", "Homology", "FExpr",
  "FExpr_Single", "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble",
  "ListOfDouble", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", 0
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
     375,   376,   377,   378,    63,   379,   380,   381,   382,    60,
      62,   383,   384,    43,    45,    42,    47,    37,    33,   385,
     386,   387,    94,    40,    41,    91,    93,    46,    35,    44,
     123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   153,   154,   154,   155,   155,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   157,   157,   158,   158,   158,   158,   159,
     159,   159,   160,   160,   160,   160,   160,   160,   161,   161,
     162,   162,   164,   165,   163,   166,   166,   168,   167,   169,
     169,   171,   170,   172,   172,   174,   173,   175,   175,   175,
     175,   175,   176,   176,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   182,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   183,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   184,   181,   181,   181,   181,   185,   181,   186,   186,
     186,   186,   186,   186,   186,   187,   187,   188,   188,   188,
     188,   188,   188,   189,   189,   189,   189,   189,   189,   189,
     189,   190,   190,   190,   190,   190,   191,   192,   192,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   195,   195,   195,   196,   195,   197,   195,
     198,   195,   199,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   200,   195,   201,   195,   202,   195,   203,
     195,   204,   195,   205,   195,   206,   195,   207,   195,   208,
     195,   209,   209,   210,   210,   210,   210,   210,   210,   211,
     211,   212,   212,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   217,   217,   218,
     218,   218,   219,   219,   219,   219,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   222,   222,   222,   222,
     222,   223,   223,   223,   223,   224,   224,   225,   225,   225,
     225,   225,   225,   226,   226,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   228,   228,   228,   228,   229,   229,
     229,   229,   230,   230,   231,   231,   232,   232,   232,   232,
     233,   233,   233,   233,   233,   233,   233,   233,   233
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     7,     7,     9,     6,
       6,     6,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     0,     0,    10,     1,     3,     0,    13,     1,
       3,     0,    15,     8,    14,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     4,     7,     9,     6,     6,     3,
       6,     4,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     5,     7,     9,     9,    11,     9,     9,     1,
       1,     0,     5,     0,     2,     7,     0,     9,     6,     7,
       4,     7,     8,     8,     7,     7,    11,     8,     8,     0,
       9,     8,     9,     3,     4,    10,     7,     7,     8,     8,
      12,     0,     9,     8,     7,     8,     0,     9,     5,    11,
       5,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     8,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     3,     3,     4,
       4,     3,     7,     7,     3,     7,     3,     2,     2,     2,
      15,     2,     2,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     9,     6,     0,
       3,     0,     1,     0,     2,     0,     2,     7,     6,     8,
       5,     5,     6,     6,    12,    10,    10,    10,    10,     2,
       3,     6,    11,    11,    11,    11,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     4,     2,
       5,     3,     6,     4,     7,     6,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       1,     1,     3,     6,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     3,     6,
       1,     1,     4,     6,     6,     4,     4,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,     0,   182,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    21,    11,    12,    13,    20,
      19,    14,    15,    16,    17,    18,    22,   318,   325,   380,
      57,   319,   320,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   381,
       0,     0,     0,     0,   322,   323,   324,    61,    60,    59,
      58,     0,     0,     0,    63,    62,     0,     0,     0,     0,
     137,     0,     0,     0,   256,     0,     0,     0,     0,   169,
       0,   171,   168,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,   109,   121,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,     0,     0,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     370,     0,     0,     0,     0,     0,   167,     0,     0,   178,
       0,   137,     0,   137,     0,     0,     0,     0,     0,     0,
       0,     0,   329,    32,   380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   259,   258,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,   135,     0,    69,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   113,     0,     0,     0,     0,   325,     0,     0,   360,
     361,   364,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,     0,   348,
       0,     0,     0,     0,   354,   353,     0,   233,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   338,   337,     0,     0,     0,     0,   137,   137,
       0,     0,     0,     0,     0,     0,     0,   192,     0,   137,
       0,     0,     0,     0,   235,     0,     0,     0,   154,     0,
       0,     0,   250,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,   137,     0,     0,     0,     0,   180,   157,
       0,   158,     0,   377,     0,   376,     0,     0,     0,     0,
       0,   331,     0,     0,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,   132,     0,     0,
       0,     0,   138,    64,     0,   274,   273,   272,   271,   267,
     268,   270,   269,   262,   261,   263,   264,   265,   266,   114,
       0,     0,     0,     0,     0,     0,   258,   355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,     0,
       0,   340,   339,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,     0,     0,     0,     0,
       0,   155,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,     0,   159,
     160,     0,     0,     0,     0,     0,     0,     0,   327,   333,
       0,    42,     0,     0,     0,    55,     0,    33,    34,    35,
      36,    37,   276,   297,   277,   298,   278,   299,   279,   300,
     280,   301,   281,   302,   282,   303,   283,   304,   284,   305,
     296,   317,   285,   306,     0,     0,   287,   308,   288,   309,
     289,   310,   290,   311,   291,   312,   292,   313,     0,     0,
       0,     0,     0,     0,   387,     0,     0,   385,   386,    82,
       0,   382,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,   328,     0,
       0,     0,     0,     0,    25,    23,     0,     0,     0,     0,
     362,     0,     0,   357,   263,   356,   366,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   350,     0,     0,     0,     0,     0,     0,   229,   234,
     232,     0,   240,     0,     0,    89,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,   183,     0,     0,     0,     0,     0,   236,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,   378,
       0,     0,     0,     0,     0,     0,   330,     0,   326,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,    67,    68,
       0,     0,     0,     0,     0,    70,    72,    74,     0,     0,
     374,     0,    80,     0,     0,     0,     0,   275,    24,     0,
       0,     0,     0,     0,   359,     0,     0,    93,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   351,
       0,    98,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,   193,   222,     0,     0,     0,   149,     0,     0,   242,
       0,   153,   152,   251,     0,    30,    31,     0,     0,     0,
     371,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,   163,   332,   162,     0,     0,     0,     0,   345,
       0,   286,   307,   293,   314,   294,   315,   295,   316,   388,
     384,   335,   383,     0,    57,     0,     0,     0,     0,    65,
       0,     0,     0,   372,     0,     0,     0,     0,    26,    27,
       0,     0,    95,     0,   358,     0,     0,     0,     0,     0,
      99,     0,     0,   116,   117,     0,     0,   101,   124,   352,
       0,     0,     0,    91,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
     137,     0,   203,     0,   205,     0,   207,     0,   347,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,   334,     0,    38,     0,     0,
       0,     0,     0,    40,     0,     0,     0,    77,     0,     0,
      78,     0,   375,   139,   140,   141,   142,     0,     0,   363,
       0,    94,   102,   103,   107,     0,     0,   118,     0,     0,
     239,   111,     0,     0,   230,   123,     0,     0,     0,     0,
     108,     0,   119,   125,     0,     0,     0,     0,   344,     0,
     343,     0,     0,   194,     0,     0,   195,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
     147,     0,     0,   143,     0,     0,     0,     0,   369,     0,
     175,   174,     0,     0,     0,   379,     0,     0,     0,     0,
      43,     0,     0,     0,   346,     0,     0,     0,    66,    73,
      75,     0,    81,     0,    28,     0,     0,     0,     0,     0,
       0,     0,   112,    97,   110,   122,   127,     0,     0,    87,
      88,   137,     0,   131,     0,     0,     0,     0,     0,     0,
       0,   223,     0,     0,   137,     0,     0,     0,     0,   134,
     133,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    41,    56,     0,   373,
       0,   245,   246,   247,   248,   115,     0,     0,     0,     0,
       0,   342,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,     0,     0,     0,   188,     0,     0,     0,     0,
       0,   368,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,   129,     0,   209,
       0,     0,   211,     0,     0,   213,     0,     0,     0,   224,
       0,   184,     0,   137,     0,     0,     0,   106,    86,   252,
     253,   254,   255,     0,    47,     0,    53,     0,     0,    92,
     120,   244,   341,   197,     0,     0,   204,   198,     0,     0,
     206,   199,     0,     0,   208,     0,     0,     0,   190,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,   215,
       0,   217,     0,   219,   225,   227,   189,   185,     0,     0,
       0,     0,    44,     0,    51,     0,     0,     0,   200,     0,
       0,   201,     0,     0,   202,     0,     0,   150,     0,   144,
       0,    45,     0,     0,   170,     0,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,   210,     0,   212,
       0,   214,     0,   145,    46,    48,     0,    49,     0,     0,
       0,     0,     0,     0,    54,   216,   218,   220,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    69,   716,    70,    71,   443,  1056,  1062,
     637,   819,  1211,  1360,   638,  1324,  1386,   639,  1362,   640,
     641,   823,   141,   242,    72,   754,  1093,   987,   512,   370,
     371,   372,   373,   339,   310,   311,    75,    76,    77,    78,
      79,    80,   340,   783,  1282,  1338,   590,  1114,  1117,  1120,
    1304,  1308,  1312,  1349,  1352,  1355,   779,   780,   887,   751,
     564,   598,    82,    83,    84,    85,    86,   357,   144,   383,
     193,   948,   949,   366,   359,   555,   222,   707,   851,   434,
     435
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1141
static const yytype_int16 yypact[] =
{
    3354,    74,     9,  3462, -1141, -1141,  1728,    17,    57,    -9,
      15,   197,   218,   276,   -36,   192,   200,   -62,   204,   208,
     -53,   216,   224,   292,   319,   324,   329,   330,   540,   339,
     185,   698,    46,   255,   356,   249,   150,   150,   265,   285,
      24,   368,   374,   380,    16,    47,   381,   430,   435,   436,
     300,   301,   321,    21,    25, -1141,   342, -1141,   486,   352,
   -1141,   496,   509,     2,    29,   367,   373,   377,   384, -1141,
   -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,    22,   388,
     336, -1141, -1141, -1141,   -95,   -26,    27,    93,   215,   282,
     363,   392,   452,   477,   506,   544,   566,   589,   600,   613,
     616,   623,   630,   644,   653,   400,   406,   411,   415, -1141,
     510,   423,   432,   437, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141,  3238,  3238,  3238, -1141, -1141,  3238,  2801,     7,   519,
     710,  3238,   596,  1581, -1141,   599,   610,  3238,   618, -1141,
    3238, -1141, -1141, -1141,  3238,  3065,  3238,  3238,   487,  3238,
    3065,  3238,  3238,   488,  3065,  3238,  3238,  2160,   492,   497,
     499,   505,  1876,  1876,  1876,   512, -1141, -1141, -1141, -1141,
     518,   525,   528,  2160,  3238,   676,  2160,   150,   150,   150,
    3238,  3238,   -68, -1141,   -56,   150,   558,   562,   583,  3018,
      64,    59,   543,   603,  1876,  2160,   617,    35,   538, -1141,
     745, -1141,   615,   619,   629,   632,   777,  3238,  3238,  3238,
     631,  3238,   634,   704,  3238,  3238, -1141,  3238,   784, -1141,
     789, -1141,   802, -1141,   433,   433,   433,   433,   664,  3238,
     849,   707, -1141, -1141, -1141,   872,  3238,  3238,  3238,  3238,
    3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,
    3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,
    3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,
    3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,   433,   433,
     433,   433,  3238,   433,   433,   433,   665,   716,   716,   716,
    5699,     5,  3065,  4940,   184,   746,   894,   796,   752, -1141,
     754,  3232,  1655, -1141, -1141,  3238,  3238,  3238,  3238,  3238,
    3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,  3238,
   -1141, -1141,  1802,   -77,  4238,  5720,   652,   763,  3065, -1141,
   -1141,  2722, -1141,   662,  5741,  5762,  3238,  5783,   667,  5804,
    5825,  3238,   685,  5846,  5867,  2302,  1539,  2794,   938, -1141,
    3238,  3238,  3238,  3238, -1141, -1141,   939,   954,   954,  3238,
     821,   826,   834,   837,  3238,  3238,  3238,   977,  4158,   844,
     986,    61, -1141, -1141,  4264,  4290,   150,   150,   710,   710,
      67,  3238,  3238,  3238,  3018,  3018,  3238,  3232,   231, -1141,
    3238,  3238,  3238,  3238,   990,  1012,  3238,  1025, -1141,  3238,
    3238,   903, -1141,  3065,  3065,  3238,  3238, -1141,  5888,  5909,
    5930,   937,  4316, -1141,   886,  2828,  5951,  4963, -1141, -1141,
    1583, -1141,  1765,   692,   893, -1141,   895,   896,   897,  3238,
    4986,   -82,  3238,    13, -1141,  5972,  5009,  5993,  5032,  6014,
    5055,  6035,  5078,  6056,  5101,  6077,  5124,  6098,  5147,  6119,
    5170,  6140,  5193,  6161,  5216,  6182,  5239,  4342,  4368,  6203,
    5262,  6224,  5285,  6245,  5308,  6266,  5331,  6287,  5354,  6308,
    5377,  4394,  4420,  4446,  4472,  4498,  4524,   -11,   889,   898,
     900,  1944,   899,   901,   902,  3238, -1141,  2160,  2160,   691,
      85,   336,  3238,  1040,  1043,    23,   904, -1141,    77,   -32,
     -40,    79, -1141, -1141,  2864,   734,   801,   965,   965,   714,
     714,   714,   714,   155,   155,   716,   716,   716,   716, -1141,
      10,  3065,  3238,  1042,  2870,  3238,   716, -1141,  3238,  3065,
    3065,   956,  1049,  1051,  6329,  1052,   961,  1054,  1055,  6350,
     966,  1057,  1061,  3065, -1141,   695,  2444,  3238,  6371,  2988,
    6392,  6413,  3238,  2160,  1065,  1064,  6434,  3201,  3201,  3201,
    3201,  6455,  6476,  6497,  2160,  3065,   924, -1141,   150,  3238,
    3238, -1141, -1141,   922,   923,  3238,  4550,  4576,  4602,  4212,
     -14,   150,  1912,  6518,  3353,  6539,  6560,  3238,  1069,  3238,
    6581, -1141,  5400,  5423, -1141,   703,   726,  5446,  5469,  1070,
    1073,  1074,   929,  3238,  2054,  3238,  3238, -1141,    -2, -1141,
   -1141,  3238,  1078,  1076,  1077,  1080,  1082,  5492,   660, -1141,
    3542, -1141,   942,   947,   941, -1141,  1086, -1141, -1141, -1141,
   -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141, -1141, -1141, -1141,  3238,  3238, -1141, -1141, -1141, -1141,
   -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,  3238,  3238,
    3238,  3238,  3238,  3238, -1141,  3065,   433, -1141, -1141, -1141,
    3238, -1141,   433,  5515,  1098,  1099,   960, -1141,    19,  3238,
    1102,  1103,  2086, -1141,  1104,   968,    21,  1108, -1141,  3065,
    3065,  3065,  3065,  3238, -1141,   980,   433,    38,  4628,   150,
   -1141,  3065,  3570,  2929,   716, -1141,  2722, -1141,  1063,  2160,
    2160,  1109,  2160,   846,  2160,  2160,  1110,  1072,  2160,  2160,
     757, -1141,  3065,  2228,  1111,  1112,  1117,  1120,   696, -1141,
   -1141,  1122, -1141,  1123,   985,  6812, -1141,   988,   996,   997,
    1127,  1135,  1136,  1140,   760,  1143,   268,  4654,  4680, -1141,
   -1141,  3598,   150,   150,   150,  1144,  1145,   999,  1009,   -22,
   -1141,   332, -1141,   -14,  1146,  1148,  1150,  1151,  6812, -1141,
    2370,  1010,  1153,  1155,  1156,  1113,  1157,  1158,  2160,  2160,
    2160,  1162,  4706, -1141,  3059,   755,  1163,  1164,  5538, -1141,
    1023,  1024,  1026,  1027,  1169,  1175, -1141,  1177, -1141,  1038,
    3238,  3238,  2160,  1035, -1141,  6602,  5561,  6623,  5584,  6644,
    5607,  6665,  5630,    86,  1045,  6686,  1046,    49, -1141, -1141,
       1,   291,  1039,  1180,  2402, -1141, -1141, -1141,    21,  3238,
   -1141,   761, -1141,   768,   769,   772,   773,  6812, -1141,  1186,
      12,  3238,    43,   791, -1141,  3238,  1044,  1134,  1134,  2160,
    1190,  1047,  1048,  1194,  1196,  2160,  1053,  1198,  1199, -1141,
     819, -1141,  1204,  2160,  2160,  2160,  1206,  1205, -1141,  2160,
    1211,  1240,  1246,  1249,  2160,  2160,  2160, -1141,  1250,   140,
    3238,  3238,  3238,  1062,   -78,   193,   228,  1068, -1141,  2160,
    3238, -1141, -1141,  3018,   -19,  2018, -1141,  1115,  2586, -1141,
    3065, -1141, -1141, -1141,  1116, -1141, -1141,  1213,  1252,  1165,
   -1141,  3238,  3238,  3238, -1141,  1253,  1254,  1121,  2160,  2160,
    2160,  2160, -1141,   -82, -1141,  3238,  4732,  4758,   823, -1141,
    3238, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141, -1141, -1141,  2160,   336,  3238,  1256,  1259,    23, -1141,
    1263,  5653,    21, -1141,  1265,  1266,  1267,  1269, -1141, -1141,
     433,  4784, -1141,  1130,  6812,  3238,   150,  1271,  1273,  1275,
   -1141,  3238,  3238, -1141, -1141,  1276,  3238, -1141, -1141, -1141,
    1278,  1279,  1281,  1191,  3238, -1141,  1285,  2160,  2160,  2160,
    2160,  1287,   969,  1288,  3238, -1141,  3201,  3626,  6707,  3458,
     710,   150,  1289,   150,  1291,   150,  1293,  3238,   325,  1152,
    6728,  3654,   344, -1141,  1294,  1390,  1296,   150,  1390,  1297,
     827,  3238, -1141, -1141,  2160,  3486,   593,  6749, -1141,  1212,
    1300,  1159,  1160,  1168,  1172, -1141,   145,  6812,  3238,  3238,
    2160,  1178,   832,  6812,  1299,  1301,  2437, -1141,  1311,  1323,
   -1141,  1183, -1141, -1141, -1141, -1141, -1141,  1325,  3238, -1141,
    3682,   205, -1141, -1141, -1141,  3710,  3738, -1141,  3766,  1327,
   -1141, -1141,  1283,  1329,  6812, -1141,  1330,  1331,  1332,  1333,
   -1141,  1192, -1141, -1141,  4185,  2512,  1334,  1193, -1141,  3238,
   -1141,  1197,   350, -1141,  1201,   369, -1141,  1202,   408, -1141,
    1203,  5676,  1335,  2160,  1337,  1207,  3238, -1141,  2728,   449,
   -1141,   485,   495, -1141,  1341,  3794,  1255,  3238, -1141,  3238,
   -1141, -1141,  3065,  2544,  1348, -1141,  2160,  2160,  2160,  2160,
   -1141,  3238,  4810,  4836, -1141,  2160,  3238,  1350, -1141, -1141,
   -1141,    21, -1141,  1209, -1141,  4862,  1352,  1353,  1355,  1357,
    1358,  1215, -1141, -1141, -1141, -1141, -1141,  2160,  3065, -1141,
   -1141,   710,  3514, -1141,  3018,   -14,  3018,   -14,  3018,   -14,
    1360, -1141,   838,  2160, -1141,  3822,   150,  3065,   150, -1141,
   -1141,  3238,  3850,  3878,   842, -1141, -1141,  1216,  1218,  1219,
    1220,  1222,  6812,  3238,  3238,   851,  6812, -1141,  1367, -1141,
    3238, -1141, -1141, -1141, -1141, -1141,  3238,   852,   855,  1223,
    3238, -1141,  3906,   504,    30,  3934,   533,   270,  3962,   536,
     340, -1141,  2160,  1369,  1310,  2196,  1227,   561,   856,   567,
    2579, -1141, -1141,  1372,  1376,  1377,  1378,  1379,  3238,  6770,
    4888,    36, -1141,  4914,  3990,  1381,  1382, -1141,  4018,  1383,
    3238,  1384,  1385,  3238,  1386,  1389,  3238,  1391,  1245, -1141,
    3238, -1141,   -14, -1141,  3065,  1392,  2728, -1141, -1141, -1141,
   -1141, -1141, -1141,   860, -1141,  3238, -1141,  2160,  3238, -1141,
   -1141, -1141, -1141, -1141,  1277,  4046, -1141, -1141,  1280,  4074,
   -1141, -1141,  1282,  4102, -1141,  1396,  2654,   397,  2338,   863,
   -1141,   608,   866,  1397,  1284,  6791,   867,  4130,   -14,  1419,
     -14,  1420,   -14,  1422, -1141, -1141, -1141, -1141,   -14,  1423,
    3065,  1425, -1141,   433, -1141,  1290,  1427,   439, -1141,  1292,
     448, -1141,  1295,   470, -1141,  1298,   489, -1141,   871, -1141,
     875, -1141,  1302,  2160, -1141,  1429,   -14,  1431,   -14,  1432,
     -14, -1141,  1433,   433,  1435,   433,   876, -1141,   494, -1141,
     530, -1141,   580, -1141, -1141, -1141,   879, -1141,  1437,  1438,
    1440,  1441,   433,  1443, -1141, -1141, -1141, -1141, -1141, -1141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1141, -1141, -1141, -1141,   591, -1141, -1141, -1141, -1141,   195,
   -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141, -1141,  -301,     4, -1141,  -267, -1141,   586,  1452, -1141,
   -1141, -1141, -1141,     3,  -387,  -195, -1141, -1141, -1141, -1141,
   -1141, -1141,  1454, -1141, -1141, -1141, -1141, -1141, -1141, -1141,
   -1141, -1141, -1141, -1141, -1141, -1141,  -678,  -739, -1141, -1141,
    1090, -1141, -1141, -1141, -1141, -1141, -1141,    -6, -1141,   100,
   -1141, -1140,   581,  -128,    28,   -85,  -687,   501, -1141,  -204,
      18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     143,   583,   584,   502,   397,   806,    74,   230,   697,     5,
     142,   304,   497,   158,   411,  1215,   714,   631,   979,   850,
     207,   149,   163,   841,   145,   220,   238,   705,   201,   223,
     146,   436,   437,   438,   232,   163,   430,  1227,   432,   407,
     912,   408,  1296,   158,   775,   367,   368,   775,   246,   982,
     247,   210,   775,   211,   776,   386,   387,   776,   134,   135,
     777,   778,   776,   777,   778,   386,   387,   530,   777,   778,
     343,  1021,   531,  1022,   202,   348,   404,   386,   387,   352,
       4,   159,   388,   203,   487,   488,   489,   490,   160,   492,
     493,   494,   697,   212,   389,   183,   775,   164,   184,   632,
     633,   634,   635,   305,   306,   914,   776,   154,   245,   147,
     711,   159,   777,   778,   155,   842,   843,   248,   710,   249,
     208,   127,   128,   129,   130,   297,   298,   299,   498,   911,
     300,   303,  1033,   684,   148,   312,   192,   194,   685,   200,
     715,   332,   715,   309,   334,   807,  1015,  1016,   335,   341,
     344,   345,   231,   347,   341,   349,   350,  1326,   341,   353,
     354,   970,   134,   135,   636,   150,   209,   239,   224,   240,
     250,   221,   251,   706,   241,   912,   386,   387,   378,   233,
     409,  1271,   860,   342,   384,   385,  1297,   540,   342,   134,
     135,   501,   342,   385,   386,   387,   815,   386,   387,   699,
     386,   387,   400,   151,   592,   127,   128,   129,   130,   401,
     578,   418,   419,   420,   399,   422,   585,   499,   425,   426,
     154,   427,   166,  1376,   152,   134,   135,   709,   614,   712,
     959,   176,   698,   440,   177,   540,   252,   178,   253,   179,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   153,   188,   189,  1072,   491,   381,   382,  1150,
     326,   327,   328,   190,  1151,   390,   341,   329,   964,   398,
     191,   757,   758,   759,   127,   128,   129,   130,   503,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   134,   135,   386,   387,   605,   606,
     342,   196,   536,   538,   197,   156,   775,   198,   386,   387,
     544,   244,  1023,   157,  1024,   549,   776,   161,   167,   536,
     341,   162,   777,   778,   558,   559,   560,   561,   254,   165,
     255,   386,   387,   566,   386,   387,   537,   166,   571,   572,
     573,   168,   115,   116,   117,   118,   169,  1025,   119,  1026,
     591,   170,   171,   537,   342,   586,   587,   588,   297,   298,
     589,   309,   309,   175,   593,   594,   595,   596,   185,   187,
     600,   386,   387,   602,   603,   186,   775,   341,   341,   607,
     608,   127,   128,   129,   130,   195,   776,   900,   188,   189,
     204,  1274,   777,   778,   817,   256,   205,   257,   190,   206,
     213,   134,   135,   627,   214,   199,   630,   433,   244,   215,
     216,   342,   342,   217,   218,   629,   717,   122,   123,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     556,   327,   328,   775,   219,   386,   387,   329,   740,   115,
     116,   117,   118,   776,  1218,   119,  1122,   386,   387,   777,
     778,   913,   834,   386,   387,   225,   581,   582,   836,   693,
     764,  1277,   226,  1126,   382,   912,   702,   227,   912,  1184,
     228,   912,   386,   387,   700,   775,   258,  1234,   259,  1237,
     234,  1240,   859,   229,   775,   776,   235,   292,  1186,   701,
     236,   777,   778,   307,   776,   341,   718,   237,   693,   722,
     777,   778,   723,   724,   726,   260,   775,   261,   243,   963,
     965,   386,   387,   288,   122,   123,   776,   341,  1336,   289,
     724,   743,   777,   778,   290,   775,   748,  1188,   291,   342,
     775,   755,   755,   755,   755,   776,   293,   725,   727,   341,
     776,   777,   778,   767,   768,   294,   777,   778,   912,   771,
     295,   342,   386,   387,   725,   756,   756,   756,   756,   172,
    1365,   788,   173,   790,   174,   262,   775,   263,  1196,  1367,
     833,  1139,   313,   342,  1317,   330,   776,   802,   912,   804,
     805,   912,   777,   778,   912,   808,   331,   912,   386,   387,
     264,  1369,   265,   333,   853,   854,   855,   856,   386,   387,
     346,   351,   816,  1111,  1197,   360,   863,   386,   387,   912,
    1371,   912,   362,   912,  1198,  1389,   775,   361,   363,   266,
    1347,   267,  1350,  1270,  1353,   369,   776,   880,   825,   826,
    1356,   374,   777,   778,   433,   244,   386,   387,   375,   386,
     387,   376,   827,   828,   829,   830,   831,   832,   766,   341,
     379,  1390,  1273,   410,   835,  1276,   402,   268,  1378,   269,
    1380,   781,  1382,   844,   386,   387,   115,   116,   117,   118,
     386,   387,   119,   341,   341,   341,   341,   857,   391,   270,
    1284,   271,   392,   342,   308,   341,  1286,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,  1391,   272,   393,   273,   329,   341,   342,   342,   342,
     342,   386,   387,   274,  1140,   275,   403,   180,   358,   342,
     181,   412,   182,   365,   365,   365,   276,  1340,   277,   278,
     406,   279,   886,   933,   377,   413,   280,   380,   281,   414,
     342,   122,   123,   282,   415,   283,  1077,   416,   421,    35,
      36,    37,    38,   417,   423,   365,   405,   284,    43,   285,
     428,    46,   134,   135,  1229,   429,   286,   534,   287,   240,
     134,   135,   140,   424,   241,   134,   135,   815,   431,   439,
     495,   540,   240,   541,   946,   947,   540,   241,   546,   862,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   540,  1040,   550,   621,   329,   622,
     540,   816,   696,   971,   540,   966,   741,   324,   325,   326,
     327,   328,   540,   441,   794,   981,   329,   442,   329,   984,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   904,   905,   906,   540,   329,   795,   444,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   504,  1017,  1018,  1019,   329,   871,   934,
     872,   505,   140,  1028,  1030,   507,   540,  1031,   879,   540,
     972,   898,   973,   535,   341,     7,     8,   540,   540,   974,
     975,   540,   540,   976,   977,  1045,  1046,  1047,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,  1057,
     540,   506,   983,   329,  1063,   557,   562,  1055,   342,   508,
      15,    16,   509,    18,    19,   510,    21,   511,    23,  1066,
      24,   563,    26,    27,   567,    29,    30,    31,   540,   568,
     999,    34,  1060,  1101,  1061,  1102,   540,   569,  1134,  1080,
     570,  1156,  1065,  1157,   574,  1085,  1086,  1242,   576,  1243,
    1088,   540,   577,  1253,    50,    51,    52,   597,  1094,  1245,
    1060,  1060,  1261,  1265,   540,   540,  1266,  1285,  1104,  1156,
    1105,  1323,   540,  1032,  1339,   540,  1060,  1341,  1345,   599,
     540,  1121,  1372,   309,  1373,  1060,  1374,  1388,  1392,   341,
    1393,   601,   341,   612,  1106,  1135,   615,   623,   686,   624,
     625,   626,   687,  1143,   688,   691,   703,   704,   690,   719,
     708,   692,  1152,  1153,   604,   728,   729,  1204,   730,   732,
     733,   734,   735,   342,   738,   737,   342,  1144,   739,   750,
     752,   765,  1165,   769,   770,   789,   801,   798,   694,   695,
     799,   800,   809,   810,   811,   820,  1081,   812,  1318,   813,
     821,   822,   824,  1228,   320,   321,   322,   323,   324,   325,
     326,   327,   328,  1182,   838,   839,   840,   329,   845,   846,
     858,   848,  1248,   849,   852,   866,   869,   875,   882,   883,
    1195,  1112,   536,  1115,   884,  1118,   876,   885,   888,   890,
     889,  1202,   891,  1203,   894,  1129,   341,  1131,  1132,  1361,
     892,   893,   895,   896,   749,  1212,   897,   899,   907,   909,
    1216,   908,   910,   915,   916,   763,   537,   917,   918,   921,
     920,   922,   923,   925,   926,   924,   930,   935,   936,  1384,
     342,  1387,   341,   938,   939,   942,   940,   941,  1232,   943,
    1235,   945,  1238,   944,   309,   950,   967,   968,  1398,   960,
     962,   341,   978,   986,   985,  1250,   990,   991,   992,  1319,
     993,  1322,   994,   996,   997,   998,   342,  1259,  1260,  1000,
    1004,  1005,  1020,  1027,  1263,    87,   296,   244,  1007,  1042,
    1264,    91,    92,    93,  1268,   342,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,  1008,   115,   116,
     117,   118,  1063,  1009,   119,  1358,  1010,  1014,  1043,  1048,
    1044,  1049,  1067,  1068,  1305,  1037,  1041,  1309,  1050,  1070,
    1313,  1073,  1074,  1075,  1316,  1076,  1079,  1082,   341,  1083,
     341,  1084,  1087,  1089,  1233,  1090,  1236,  1091,  1239,  1325,
    1092,  1095,  1327,  1100,  1103,  1113,  1247,  1116,  1249,  1119,
    1127,  1123,  1130,  1133,  1145,  1158,  1219,  1159,  1146,  1147,
     867,   868,   342,   870,   342,   873,   874,  1148,  1161,   877,
     878,  1149,   121,   122,   123,   124,   125,   126,  1155,  1162,
    1163,  1164,  1170,  1171,   341,  1172,  1173,  1174,  1175,  1176,
    1180,  1191,  1177,  1181,  1193,   131,   132,  1199,  1183,  1201,
     133,  1185,  1187,  1189,  1206,   136,  1217,  1194,  1221,  1222,
     139,  1223,  1142,  1224,  1225,  1226,  1241,  1254,   342,  1255,
    1256,  1257,  1258,  1262,  1267,  1279,  1280,  1283,  1288,   927,
     928,   929,  1289,  1290,  1291,  1292,  1321,  1300,  1301,  1303,
    1306,  1307,  1310,    87,   336,  1311,  1315,  1314,  1320,    91,
      92,    93,  1334,  1342,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,  1348,  1351,  1328,  1354,  1357,
    1330,  1359,  1332,  1364,  1343,  1377,   337,  1379,  1381,  1383,
    1363,  1385,  1366,  1394,  1395,  1368,  1396,  1397,  1370,  1399,
     989,   980,  1375,  1293,   988,    73,   995,    81,   565,    35,
      36,    37,    38,    39,  1001,  1002,  1003,     0,    43,  1069,
    1006,    46,     0,     0,     0,  1011,  1012,  1013,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1029,     0,     0,     0,     0,     0,  1036,     0,     0,  1039,
     121,     0,     0,   124,   125,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1051,
    1052,  1053,  1054,   394,  1128,     0,     0,     0,   133,     0,
       0,     0,     0,   396,     0,     0,     0,     0,   139,     0,
     191,   554,    87,   336,  1064,     0,     0,     0,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,     0,   314,  1096,  1097,
    1098,  1099,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    36,
      37,    38,    39,     0,     0,     0,     0,    43,     0,     0,
      46,     0,     0,     0,     0,  1136,     0,     0,     0,   508,
      15,    16,   509,    18,    19,   510,    21,   511,    23,     0,
      24,  1154,    26,    27,     0,    29,    30,    31,     0,   121,
       0,    34,   124,   125,   126,     0,     0,     0,     0,     0,
       0,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   338,    50,    51,    52,   133,     0,     0,
       0,     0,   136,     0,     0,     0,     0,   139,     0,     0,
     554,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1192,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,     0,     0,  1207,  1208,  1209,
    1210,    87,    88,    89,   619,    90,     0,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,   115,   116,   117,   118,     0,     0,
     119,     0,     0,     0,  1244,     0,     0,     7,     8,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,   508,    15,    16,   509,    18,    19,   510,    21,   511,
      23,     0,    24,  1278,    26,    27,     0,    29,    30,    31,
       0,     0,   120,    34,     0,     0,     0,     0,   121,   122,
     123,   124,   125,   126,     0,     0,     0,     0,   127,   128,
     129,   130,     0,     0,     0,     0,    50,    51,    52,     0,
       0,   131,   132,     0,     0,     0,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,     0,   140,    87,
     336,   364,     0,     0,     0,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,   337,     0,     7,     8,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,    35,    36,    37,    38,    39,
     689,     0,     0,     0,    43,     0,     0,    46,   508,    15,
      16,   509,    18,    19,   510,    21,   511,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,     0,
      34,     0,     0,     0,     0,     0,   121,     0,     0,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,     0,     0,   131,
     355,     0,     0,     0,   133,     0,     0,     0,     0,   136,
       0,    87,   336,  1034,   139,     0,   356,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   782,   337,     0,     7,     8,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,    35,    36,    37,
      38,    39,   847,     0,     0,     0,    43,     0,     0,    46,
     508,    15,    16,   509,    18,    19,   510,    21,   511,    23,
       0,    24,     0,    26,    27,     0,    29,    30,    31,     0,
       0,     0,    34,     0,     0,     0,     0,     0,   121,     0,
       0,   124,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,     0,     0,
       0,   131,   355,     0,     0,     0,   133,     0,     0,     0,
       0,   136,     0,    87,   336,     0,   139,     0,  1035,    91,
      92,    93,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   803,   337,     0,     7,     8,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,    35,
      36,    37,    38,    39,   881,     0,     0,     0,    43,     0,
       0,    46,   508,    15,    16,   509,    18,    19,   510,    21,
     511,    23,     0,    24,     0,    26,    27,     0,    29,    30,
      31,     0,     0,     0,    34,     0,     0,     0,     0,     0,
     121,     0,     0,   124,   125,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
       0,     0,     0,   131,   355,     0,     0,     0,   133,     0,
       0,     0,     0,   136,     0,    87,   336,     0,   139,     0,
     356,    91,    92,    93,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1281,   337,     0,
       7,     8,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,    35,    36,    37,    38,    39,   919,     0,     0,     0,
      43,     0,     0,    46,   508,    15,    16,   509,    18,    19,
     510,    21,   511,    23,     0,    24,     0,    26,    27,     0,
      29,    30,    31,     0,     0,     0,    34,     0,   969,     0,
       0,     0,   121,     0,     0,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,     0,     0,     0,   131,   338,     0,     0,     0,
     133,     0,     0,  1160,     0,   136,     0,    87,   336,     0,
     139,     0,   553,    91,    92,    93,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1337,
     337,     0,     0,     0,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,    35,    36,    37,    38,    39,  1179,     0,
       0,     0,    43,     0,     0,    46,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
    1205,     0,     0,     0,   121,     0,     0,   124,   125,   126,
       0,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,   131,   338,   329,
       0,     0,   133,     0,     0,  1287,     0,   136,     0,    87,
     336,     0,   139,     0,   742,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,     0,     0,     0,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,    35,    36,    37,    38,    39,
    1335,     0,     0,     0,    43,     0,     0,    46,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,   124,
     125,   126,     0,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,   131,
     355,   329,     0,     0,   133,     0,     0,     0,     0,   136,
     538,    87,   336,     0,   139,     0,  1038,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   337,     0,     0,     0,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,    35,    36,    37,
      38,    39,   538,     0,    87,   296,    43,     0,     0,    46,
      91,    92,    93,     0,     0,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   616,     0,   121,     0,
       0,   124,   125,   126,     0,     0,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   539,   327,   328,
       0,   394,  1128,     0,   329,     0,   133,     0,     0,     0,
       0,   396,   713,    87,   296,     0,   139,     0,   191,    91,
      92,    93,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,   121,     0,     0,   124,   125,   126,     0,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   556,
     327,   328,     0,     0,   131,   132,   329,   865,     0,   133,
       0,     0,     0,     0,   136,     0,     0,   301,     0,   139,
       0,   302,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,   124,   125,   126,     0,     0,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,   131,   132,     0,   329,     0,   133,     0,
       0,     0,     0,   136,     0,     0,   720,     0,   139,     0,
     721,    87,   296,     0,     0,     0,     0,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   932,    87,   336,
       0,   329,     0,     0,    91,    92,    93,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   337,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,   121,     0,
     329,   124,   125,   126,    35,    36,    37,    38,    39,   745,
       0,     0,     0,    43,     0,     0,    46,     0,     0,     0,
       0,   394,   395,     0,     0,     0,   133,     0,     0,     0,
       0,   396,     0,     0,     0,     0,   139,     0,   191,     0,
       0,     0,     0,     0,     0,   121,     0,     0,   124,   125,
     126,     0,     0,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,   131,   338,
       0,   329,     0,   133,    87,   296,   244,     0,   136,     0,
      91,    92,    93,   139,     0,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,   115,   116,   117,
     118,    87,   296,   119,     7,     8,     0,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,   508,    15,
      16,   509,    18,    19,   510,    21,   511,    23,     0,    24,
       0,    26,    27,     0,    29,    30,    31,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,     0,     0,     0,   133,
       0,     0,     0,     0,   136,     0,     0,     0,   121,   139,
       0,   124,   125,   126,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,   131,   132,     0,     0,     0,   133,     0,     0,     0,
       0,   136,     0,     0,     0,     0,   139,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     6,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,     0,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,     9,     0,     0,
       0,     0,    10,    11,   785,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,    51,    52,     0,     0,    53,     0,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,  1109,     0,  1110,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,  1137,     0,  1138,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,  1230,     0,  1231,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,     0,     0,   818,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,     0,
       0,   864,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,   903,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,     0,     0,  1125,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,     0,     0,  1166,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,     0,
       0,  1167,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,  1168,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,  1169,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,     0,     0,  1200,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,     0,     0,  1246,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,     0,
       0,  1251,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,  1252,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,  1269,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,     0,     0,  1272,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,     0,     0,  1275,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,     0,
       0,  1299,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,  1302,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,  1329,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,     0,     0,  1331,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,     0,     0,  1333,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,     0,
       0,  1346,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,   575,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,     0,
       0,     0,     0,     0,     0,  1178,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,   496,     0,     0,     0,
       0,   579,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,   532,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,   579,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,   580,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,   613,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,   664,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,   665,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,   678,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,   679,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,   680,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,   681,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,   682,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,   683,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,   772,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,   773,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,   774,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,   861,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,   901,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,   902,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,   931,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,  1058,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,  1059,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,  1078,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,     0,     0,     0,  1213,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,  1214,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,     0,     0,
       0,  1220,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,  1295,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
       0,     0,     0,  1298,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,   500,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,     0,     0,   618,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,   628,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,     0,     0,   643,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,   645,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,     0,
       0,   647,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,   649,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,     0,     0,   651,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
     653,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,     0,     0,   655,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,   657,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,     0,     0,   659,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,   661,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,     0,     0,   663,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,   667,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,     0,
       0,   669,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,   671,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,     0,     0,   673,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
     675,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,     0,     0,   677,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,   792,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,     0,     0,   793,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,   796,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,     0,     0,   797,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,     0,     0,   814,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,     0,
       0,   837,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,     0,     0,   937,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,     0,     0,   952,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,     0,     0,
     954,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,     0,     0,   956,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,     0,     0,   958,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,     0,     0,  1071,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
       0,     0,  1190,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,   496,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,   533,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,   542,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,   543,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,   545,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,   547,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,   548,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
     551,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,   552,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,   609,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,   610,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,   611,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,   617,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,   642,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,   644,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,   646,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,   648,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
     650,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,   652,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,   654,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,   656,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,   658,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,   660,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,   662,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,   666,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,   668,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,   670,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
     672,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,   674,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,   676,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,   731,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,   736,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,   744,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,   746,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,   747,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,   753,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,   760,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
     761,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,   762,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,   784,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,   786,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,   787,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,   791,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329,     0,   951,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,     0,     0,   329,     0,   953,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,     0,     0,   329,     0,   955,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,     0,     0,   329,     0,   957,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,     0,     0,   329,     0,
     961,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,     0,     0,   329,
       0,  1108,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,     0,     0,
     329,     0,  1124,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,     0,
       0,   329,     0,  1141,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,     0,   329,     0,  1294,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,     0,     0,   329,     0,  1344,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,     0,     0,   329
};

static const yytype_int16 yycheck[] =
{
       6,   388,   389,   304,   199,     7,     3,     5,     7,     0,
       6,     4,     7,    75,   209,  1155,     6,     4,     6,   706,
       4,     6,    75,     4,     6,     4,     4,     4,     4,     4,
      13,   235,   236,   237,     5,    75,   231,  1177,   233,     4,
     779,     6,     6,    75,    66,   173,   174,    66,   143,     6,
     145,     4,    66,     6,    76,   133,   134,    76,   140,   141,
      82,    83,    76,    82,    83,   133,   134,   144,    82,    83,
     155,   149,   149,   151,    50,   160,   204,   133,   134,   164,
       6,   143,   150,    59,   288,   289,   290,   291,   150,   293,
     294,   295,     7,    46,   150,    49,    66,   150,    52,    86,
      87,    88,    89,    96,    97,   783,    76,   143,    90,    52,
     150,   143,    82,    83,   150,    96,    97,   143,   150,   145,
     104,   120,   121,   122,   123,   131,   132,   133,   123,   151,
     136,   137,   151,   144,   143,   141,    36,    37,   149,    39,
     130,   147,   130,   140,   150,   147,     6,     7,   154,   155,
     156,   157,   150,   159,   160,   161,   162,  1297,   164,   165,
     166,   848,   140,   141,   151,   150,   150,   145,   143,   147,
     143,   150,   145,   150,   152,   914,   133,   134,   184,   150,
     145,   151,   144,   155,   190,   191,   150,   149,   160,   140,
     141,     7,   164,   199,   133,   134,   147,   133,   134,   500,
     133,   134,   143,     6,   399,   120,   121,   122,   123,   150,
     149,   217,   218,   219,   150,   221,   149,   302,   224,   225,
     143,   227,   143,  1363,     6,   140,   141,   150,   423,   150,
     144,    46,   147,   239,    49,   149,   143,    52,   145,    54,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,     6,   133,   134,   972,   292,   187,   188,   144,
     135,   136,   137,   143,   149,   195,   302,   142,     7,   199,
     150,   568,   569,   570,   120,   121,   122,   123,   304,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   140,   141,   133,   134,   413,   414,
     302,    46,   338,     8,    49,   143,    66,    52,   133,   134,
     346,     5,   149,   143,   151,   351,    76,   143,    56,   355,
     356,   143,    82,    83,   360,   361,   362,   363,   143,   143,
     145,   133,   134,   369,   133,   134,   338,   143,   374,   375,
     376,    52,    36,    37,    38,    39,    52,   149,    42,   151,
     149,    52,    52,   355,   356,   391,   392,   393,   394,   395,
     396,   388,   389,    54,   400,   401,   402,   403,   143,   150,
     406,   133,   134,   409,   410,    49,    66,   413,   414,   415,
     416,   120,   121,   122,   123,   150,    76,   149,   133,   134,
      52,   151,    82,    83,   628,   143,    52,   145,   143,    49,
      49,   140,   141,   439,     4,   150,   442,     4,     5,     4,
       4,   413,   414,   143,   143,   441,   531,   111,   112,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    66,   143,   133,   134,   142,   553,    36,
      37,    38,    39,    76,  1161,    42,   151,   133,   134,    82,
      83,   149,   686,   133,   134,   143,   386,   387,   692,   495,
     575,   151,     6,   149,   394,  1234,   502,   145,  1237,   149,
       4,  1240,   133,   134,   500,    66,   143,  1185,   145,  1187,
     143,  1189,   716,     4,    66,    76,   143,     7,   149,   501,
     143,    82,    83,     4,    76,   531,   532,   143,   534,   535,
      82,    83,   538,   539,   540,   143,    66,   145,   150,   840,
     841,   133,   134,   143,   111,   112,    76,   553,   151,   143,
     556,   557,    82,    83,   143,    66,   562,   149,   143,   531,
      66,   567,   568,   569,   570,    76,   143,   539,   540,   575,
      76,    82,    83,   579,   580,   143,    82,    83,  1317,   585,
     143,   553,   133,   134,   556,   567,   568,   569,   570,    49,
     151,   597,    52,   599,    54,   143,    66,   145,   149,   151,
     685,     8,     6,   575,  1282,     6,    76,   613,  1347,   615,
     616,  1350,    82,    83,  1353,   621,     6,  1356,   133,   134,
     143,   151,   145,     5,   709,   710,   711,   712,   133,   134,
     143,   143,   628,  1020,   149,   143,   721,   133,   134,  1378,
     151,  1380,   143,  1382,   149,   151,    66,   150,   143,   143,
    1328,   145,  1330,   149,  1332,   143,    76,   742,   664,   665,
    1338,   143,    82,    83,     4,     5,   133,   134,   143,   133,
     134,   143,   678,   679,   680,   681,   682,   683,   578,   685,
       4,   151,   149,   145,   690,   149,   143,   143,  1366,   145,
    1368,   591,  1370,   699,   133,   134,    36,    37,    38,    39,
     133,   134,    42,   709,   710,   711,   712,   713,   150,   143,
     149,   145,   150,   685,     4,   721,   149,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   151,   143,   150,   145,   142,   742,   709,   710,   711,
     712,   133,   134,   143,   151,   145,   143,    49,   167,   721,
      52,     6,    54,   172,   173,   174,   143,   149,   145,   143,
     143,   145,    66,     8,   183,   150,   143,   186,   145,   150,
     742,   111,   112,   143,   145,   145,   980,   145,   147,    69,
      70,    71,    72,     6,   150,   204,   205,   143,    78,   145,
       6,    81,   140,   141,  1181,     6,   143,   145,   145,   147,
     140,   141,   150,    99,   152,   140,   141,   147,     6,   145,
     145,   149,   147,   151,   820,   821,   149,   152,   151,   719,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   149,   920,   151,   145,   142,   147,
     149,   837,   151,   849,   149,   841,   151,   133,   134,   135,
     136,   137,   149,     4,   151,   861,   142,   150,   142,   865,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   772,   773,   774,   149,   142,   151,     6,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   147,   900,   901,   902,   142,    52,   144,
      54,     7,   150,   909,   910,   151,   149,   913,   151,   149,
     149,   151,   151,   150,   920,    12,    13,   149,   149,   151,
     151,   149,   149,   151,   151,   931,   932,   933,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   945,
     149,   145,   151,   142,   950,     7,     7,   943,   920,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   965,
      57,     7,    59,    60,   143,    62,    63,    64,   149,   143,
     151,    68,   149,     4,   151,     6,   149,   143,   151,   985,
     143,   149,   964,   151,     7,   991,   992,   149,   144,   151,
     996,   149,     6,   151,    91,    92,    93,     7,  1004,  1194,
     149,   149,   151,   151,   149,   149,   151,   151,  1014,   149,
    1016,   151,   149,   913,   151,   149,   149,   151,   151,     7,
     149,  1027,   151,  1020,   149,   149,   151,   151,   149,  1035,
     151,     6,  1038,    96,  1016,  1041,   150,   144,   149,   144,
     144,   144,   144,  1049,   144,   144,     6,     4,   149,     7,
     146,   149,  1058,  1059,   151,    99,     7,  1142,     7,     7,
      99,     7,     7,  1035,     7,    99,  1038,  1049,     7,     4,
       6,   147,  1078,   151,   151,     6,   147,     7,   497,   498,
       7,     7,     4,     7,     7,   143,   986,     7,  1283,     7,
     143,   150,     6,  1178,   129,   130,   131,   132,   133,   134,
     135,   136,   137,  1109,     6,     6,   146,   142,     6,     6,
     130,     7,  1197,   145,     6,    52,     7,     7,     7,     7,
    1126,  1021,  1128,  1023,     7,  1025,    54,     7,     6,   144,
       7,  1137,   144,  1139,     7,  1035,  1142,  1037,  1038,  1343,
     144,   144,     7,     7,   563,  1151,     6,     4,     4,   150,
    1156,     6,   143,     7,     6,   574,  1128,     7,     7,     6,
     150,     6,     6,     6,     6,    52,     4,     4,     4,  1373,
    1142,  1375,  1178,   150,   150,     6,   150,   150,  1184,     4,
    1186,   143,  1188,     6,  1181,   150,   147,     7,  1392,   144,
     144,  1197,     6,    59,   150,  1201,     6,   150,   150,  1284,
       6,  1286,     6,   150,     6,     6,  1178,  1213,  1214,     5,
       4,     6,   150,   145,  1220,     3,     4,     5,     7,     6,
    1226,     9,    10,    11,  1230,  1197,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     7,    36,    37,
      38,    39,  1258,     7,    42,  1340,     7,     7,     6,     6,
      95,     7,     6,     4,  1270,   150,   150,  1273,   147,     6,
    1276,     6,     6,     6,  1280,     6,   146,     6,  1284,     6,
    1286,     6,     6,     5,  1184,     6,  1186,     6,  1188,  1295,
      99,     6,  1298,     6,     6,     6,  1196,     6,  1198,     6,
       6,   149,     6,     6,     4,     6,    97,     6,   149,   149,
     729,   730,  1284,   732,  1286,   734,   735,   149,     7,   738,
     739,   149,   110,   111,   112,   113,   114,   115,   150,     6,
     147,     6,     5,    50,  1340,     6,     6,     6,     6,     6,
       6,     6,   150,   150,     7,   133,   134,     6,   151,    94,
     138,   150,   150,   150,     6,   143,     6,   150,     6,     6,
     148,     6,   150,     6,     6,   150,     6,   151,  1340,   151,
     151,   151,   150,     6,   151,     6,    66,   150,     6,   798,
     799,   800,     6,     6,     6,     6,  1286,     6,     6,     6,
       6,     6,     6,     3,     4,     6,   151,     6,     6,     9,
      10,    11,     6,     6,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     6,     6,   150,     6,     6,
     150,     6,   150,     6,   150,     6,    46,     6,     6,     6,
     150,     6,   150,     6,     6,   150,     6,     6,   150,     6,
     869,   860,   150,  1258,   868,     3,   875,     3,   368,    69,
      70,    71,    72,    73,   883,   884,   885,    -1,    78,   968,
     889,    81,    -1,    -1,    -1,   894,   895,   896,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     909,    -1,    -1,    -1,    -1,    -1,   915,    -1,    -1,   918,
     110,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   938,
     939,   940,   941,   133,   134,    -1,    -1,    -1,   138,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   151,     3,     4,   963,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,     6,  1007,  1008,
    1009,  1010,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    -1,    -1,  1044,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,  1060,    59,    60,    -1,    62,    63,    64,    -1,   110,
      -1,    68,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,    91,    92,    93,   138,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,  1146,  1147,  1148,
    1149,     3,     4,     5,   151,     7,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,  1193,    -1,    -1,    12,    13,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,  1242,    59,    60,    -1,    62,    63,    64,
      -1,    -1,   104,    68,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,
      -1,   133,   134,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,   147,   148,    -1,   150,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    12,    13,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    69,    70,    71,    72,    73,
       6,    -1,    -1,    -1,    78,    -1,    -1,    81,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,    -1,    -1,   133,
     134,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,   143,
      -1,     3,     4,     5,   148,    -1,   150,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    46,    -1,    12,    13,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    69,    70,    71,
      72,    73,     6,    -1,    -1,    -1,    78,    -1,    -1,    81,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,    -1,
      -1,   133,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,   143,    -1,     3,     4,    -1,   148,    -1,   150,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    46,    -1,    12,    13,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    69,
      70,    71,    72,    73,     6,    -1,    -1,    -1,    78,    -1,
      -1,    81,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      -1,    -1,    -1,   133,   134,    -1,    -1,    -1,   138,    -1,
      -1,    -1,    -1,   143,    -1,     3,     4,    -1,   148,    -1,
     150,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    46,    -1,
      12,    13,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    69,    70,    71,    72,    73,     6,    -1,    -1,    -1,
      78,    -1,    -1,    81,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    -1,    -1,    68,    -1,     6,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    -1,    -1,    -1,   133,   134,    -1,    -1,    -1,
     138,    -1,    -1,     6,    -1,   143,    -1,     3,     4,    -1,
     148,    -1,   150,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      46,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    69,    70,    71,    72,    73,     6,    -1,
      -1,    -1,    78,    -1,    -1,    81,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,   115,
      -1,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,   133,   134,   142,
      -1,    -1,   138,    -1,    -1,     6,    -1,   143,    -1,     3,
       4,    -1,   148,    -1,   150,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    69,    70,    71,    72,    73,
       6,    -1,    -1,    -1,    78,    -1,    -1,    81,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
     114,   115,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,   133,
     134,   142,    -1,    -1,   138,    -1,    -1,    -1,    -1,   143,
       8,     3,     4,    -1,   148,    -1,   150,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    69,    70,    71,
      72,    73,     8,    -1,     3,     4,    78,    -1,    -1,    81,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     8,    -1,   110,    -1,
      -1,   113,   114,   115,    -1,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,   133,   134,    -1,   142,    -1,   138,    -1,    -1,    -1,
      -1,   143,     8,     3,     4,    -1,   148,    -1,   150,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,   113,   114,   115,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,   133,   134,   142,     8,    -1,   138,
      -1,    -1,    -1,    -1,   143,    -1,    -1,   146,    -1,   148,
      -1,   150,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,   113,   114,   115,    -1,    -1,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,   133,   134,    -1,   142,    -1,   138,    -1,
      -1,    -1,    -1,   143,    -1,    -1,   146,    -1,   148,    -1,
     150,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     8,     3,     4,
      -1,   142,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,   110,    -1,
     142,   113,   114,   115,    69,    70,    71,    72,    73,   151,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,
      -1,   133,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,
     115,    -1,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,   133,   134,
      -1,   142,    -1,   138,     3,     4,     5,    -1,   143,    -1,
       9,    10,    11,   148,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,     3,     4,    42,    12,    13,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,   110,   148,
      -1,   113,   114,   115,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,   133,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,
      96,    -1,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,     4,    -1,    -1,    -1,
     116,   117,   118,   119,    12,    13,    -1,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,   151,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,   151,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,   151,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,   151,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,   144,    -1,    -1,    -1,
      -1,   149,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,   146,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,   146,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,   146,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
     146,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,   146,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,   146,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,   146,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,   146,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
     146,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,   146,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,   146,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,   146,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,   146,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
     146,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,   146,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   146,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,   146,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,   146,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,   144,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,   144,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
     144,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,   144,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,   144,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,   144,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,   144,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
     144,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,   144,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,   144,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,   144,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,   144,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
     144,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,   144,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,   144,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,   144,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,   144,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
     144,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,   144,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,   144,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,   144,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,   144,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,   144,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,    -1,
     144,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,   142,
      -1,   144,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
     142,    -1,   144,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,   142,    -1,   144,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,   142,    -1,   144,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,   142,    -1,   144,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   154,   155,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    84,    85,    90,
      91,    92,    93,    96,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   116,   117,   118,   119,   156,
     158,   159,   177,   181,   186,   189,   190,   191,   192,   193,
     194,   195,   215,   216,   217,   218,   219,     3,     4,     5,
       7,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    42,
     104,   110,   111,   112,   113,   114,   115,   120,   121,   122,
     123,   133,   134,   138,   140,   141,   143,   145,   147,   148,
     150,   175,   176,   220,   221,   233,    13,    52,   143,     6,
     150,     6,     6,     6,   143,   150,   143,   143,    75,   143,
     150,   143,   143,    75,   150,   143,   143,    56,    52,    52,
      52,    52,    49,    52,    54,    54,    46,    49,    52,    54,
      49,    52,    54,    49,    52,   143,    49,   150,   133,   134,
     143,   150,   222,   223,   222,   150,    46,    49,    52,   150,
     222,     4,    50,    59,    52,    52,    49,     4,   104,   150,
       4,     6,    46,    49,     4,     4,     4,   143,   143,   143,
       4,   150,   229,     4,   143,   143,     6,   145,     4,     4,
       5,   150,     5,   150,   143,   143,   143,   143,     4,   145,
     147,   152,   176,   150,     5,   233,   143,   145,   143,   145,
     143,   145,   143,   145,   143,   145,   143,   145,   143,   145,
     143,   145,   143,   145,   143,   145,   143,   145,   143,   145,
     143,   145,   143,   145,   143,   145,   143,   145,   143,   145,
     143,   145,   143,   145,   143,   145,   143,   145,   143,   143,
     143,   143,     7,   143,   143,   143,     4,   220,   220,   220,
     220,   146,   150,   220,     4,    96,    97,     4,     4,   186,
     187,   188,   220,     6,     6,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   142,
       6,     6,   220,     5,   220,   220,     4,    46,   134,   186,
     195,   220,   227,   228,   220,   220,   143,   220,   228,   220,
     220,   143,   228,   220,   220,   134,   150,   220,   225,   227,
     143,   150,   143,   143,     5,   225,   226,   226,   226,   143,
     182,   183,   184,   185,   143,   143,   143,   225,   220,     4,
     225,   222,   222,   222,   220,   220,   133,   134,   150,   150,
     222,   150,   150,   150,   133,   134,   143,   188,   222,   150,
     143,   150,   143,   143,   226,   225,   143,     4,     6,   145,
     145,   188,     6,   150,   150,   145,   145,     6,   220,   220,
     220,   147,   220,   150,    99,   220,   220,   220,     6,     6,
     188,     6,   188,     4,   232,   233,   232,   232,   232,   145,
     220,     4,   150,   160,     6,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   232,   232,   232,
     232,   220,   232,   232,   232,   145,   144,     7,   123,   228,
     146,     7,   175,   176,   147,     7,   145,   151,    46,    49,
      52,    54,   181,     6,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,     6,
     144,   149,   149,   144,   145,   150,   220,   227,     8,   135,
     149,   151,   144,   144,   220,   144,   151,   144,   144,   220,
     151,   144,   144,   150,   151,   228,   135,     7,   220,   220,
     220,   220,     7,     7,   213,   213,   220,   143,   143,   143,
     143,   220,   220,   220,     7,   150,   144,     6,   149,   149,
     149,   222,   222,   187,   187,   149,   220,   220,   220,   220,
     199,   149,   188,   220,   220,   220,   220,     7,   214,     7,
     220,     6,   220,   220,   151,   228,   228,   220,   220,   144,
     144,   144,    96,   149,   188,   150,     8,   144,   146,   151,
     151,   145,   147,   144,   144,   144,   144,   220,   146,   176,
     220,     4,    86,    87,    88,    89,   151,   163,   167,   170,
     172,   173,   144,   146,   144,   146,   144,   146,   144,   146,
     144,   146,   144,   146,   144,   146,   144,   146,   144,   146,
     144,   146,   144,   146,   149,   149,   144,   146,   144,   146,
     144,   146,   144,   146,   144,   146,   144,   146,   149,   149,
     149,   149,   149,   149,   144,   149,   149,   144,   144,     6,
     149,   144,   149,   220,   225,   225,   151,     7,   147,   175,
     176,   233,   220,     6,     4,     4,   150,   230,   146,   150,
     150,   150,   150,     8,     6,   130,   157,   228,   220,     7,
     146,   150,   220,   220,   220,   227,   220,   227,    99,     7,
       7,   144,     7,    99,     7,     7,   144,    99,     7,     7,
     228,   151,   150,   220,   144,   151,   144,   144,   220,   225,
       4,   212,     6,   144,   178,   220,   233,   178,   178,   178,
     144,   144,   144,   225,   228,   147,   222,   220,   220,   151,
     151,   220,   149,   149,   149,    66,    76,    82,    83,   209,
     210,   222,   151,   196,   144,   151,   144,   144,   220,     6,
     220,   144,   146,   146,   151,   151,   146,   146,     7,     7,
       7,   147,   220,   151,   220,   220,     7,   147,   220,     4,
       7,     7,     7,     7,   146,   147,   176,   232,   151,   164,
     143,   143,   150,   174,     6,   220,   220,   220,   220,   220,
     220,   220,   220,   228,   232,   220,   232,   146,     6,     6,
     146,     4,    96,    97,   220,     6,     6,     6,     7,   145,
     229,   231,     6,   228,   228,   228,   228,   220,   130,   232,
     144,   149,   222,   228,   151,     8,    52,   225,   225,     7,
     225,    52,    54,   225,   225,     7,    54,   225,   225,   151,
     228,     6,     7,     7,     7,     7,    66,   211,     6,     7,
     144,   144,   144,   144,     7,     7,     7,     6,   151,     4,
     149,   149,   149,   151,   222,   222,   222,     4,     6,   150,
     143,   151,   210,   149,   209,     7,     6,     7,     7,     6,
     150,     6,     6,     6,    52,     6,     6,   225,   225,   225,
       4,   149,     8,     8,   144,     4,     4,   146,   150,   150,
     150,   150,     6,     4,     6,   143,   220,   220,   224,   225,
     150,   144,   146,   144,   146,   144,   146,   144,   146,   144,
     144,   144,   144,   175,     7,   175,   176,   147,     7,     6,
     229,   220,   149,   151,   151,   151,   151,   151,     6,     6,
     157,   220,     6,   151,   220,   150,    59,   180,   180,   225,
       6,   150,   150,     6,     6,   225,   150,     6,     6,   151,
       5,   225,   225,   225,     4,     6,   225,     7,     7,     7,
       7,   225,   225,   225,     7,     6,     7,   220,   220,   220,
     150,   149,   151,   149,   151,   149,   151,   145,   220,   225,
     220,   220,   222,   151,     5,   150,   225,   150,   150,   225,
     228,   150,     6,     6,    95,   220,   220,   220,     6,     7,
     147,   225,   225,   225,   225,   176,   161,   220,   149,   149,
     149,   151,   162,   220,   225,   233,   220,     6,     4,   230,
       6,   146,   229,     6,     6,     6,     6,   232,   149,   146,
     220,   222,     6,     6,     6,   220,   220,     6,   220,     5,
       6,     6,    99,   179,   220,     6,   225,   225,   225,   225,
       6,     4,     6,     6,   220,   220,   233,   151,   144,   149,
     151,   187,   222,     6,   200,   222,     6,   201,   222,     6,
     202,   220,   151,   149,   144,   151,   149,     6,   134,   222,
       6,   222,   222,     6,   151,   220,   225,   149,   151,     8,
     151,   144,   150,   220,   233,     4,   149,   149,   149,   149,
     144,   149,   220,   220,   225,   150,   149,   151,     6,     6,
       6,     7,     6,   147,     6,   220,   151,   151,   151,   151,
       5,    50,     6,     6,     6,     6,     6,   150,   150,     6,
       6,   150,   220,   151,   149,   150,   149,   150,   149,   150,
     146,     6,   225,     7,   150,   220,   149,   149,   149,     6,
     151,    94,   220,   220,   228,     6,     6,   225,   225,   225,
     225,   165,   220,   149,   149,   224,   220,     6,   229,    97,
     149,     6,     6,     6,     6,     6,   150,   224,   228,   187,
     149,   151,   220,   222,   209,   220,   222,   209,   220,   222,
     209,     6,   149,   151,   225,   188,   151,   222,   228,   222,
     220,   151,   151,   151,   151,   151,   151,   151,   150,   220,
     220,   151,     6,   220,   220,   151,   151,   151,   220,   151,
     149,   151,   151,   149,   151,   151,   149,   151,   225,     6,
      66,   151,   197,   150,   149,   151,   149,     6,     6,     6,
       6,     6,     6,   162,   144,   149,     6,   150,   149,   151,
       6,     6,   151,     6,   203,   220,     6,     6,   204,   220,
       6,     6,   205,   220,     6,   151,   220,   209,   188,   228,
       6,   222,   228,   151,   168,   220,   224,   220,   150,   151,
     150,   151,   150,   151,     6,     6,   151,   151,   198,   151,
     149,   151,     6,   150,   144,   151,   151,   209,     6,   206,
     209,     6,   207,   209,     6,   208,   209,     6,   228,     6,
     166,   232,   171,   150,     6,   151,   150,   151,   150,   151,
     150,   151,   151,   149,   151,   150,   224,     6,   209,     6,
     209,     6,   209,     6,   232,     6,   169,   232,   151,   151,
     151,   151,   149,   151,     6,     6,     6,     6,   232,     6
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 159 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 170 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 171 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 172 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 173 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 174 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 175 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 176 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 178 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 191 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:
#line 195 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:
#line 202 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:
#line 207 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
      FILE *fp = fopen(tmp.c_str(), (yyvsp[(5) - (7)].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[(3) - (7)].c));
	fclose(fp);
      }
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 27:
#line 221 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0) 
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 28:
#line 234 "Gmsh.y"
    {
      char tmpstring[1024];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0) 
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(8) - (9)].c));
	FILE *fp = fopen(tmp.c_str(), (yyvsp[(7) - (9)].c));
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
    ;}
    break;

  case 29:
#line 262 "Gmsh.y"
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
    ;}
    break;

  case 30:
#line 276 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 31:
#line 287 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 32:
#line 301 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList(); 
#endif
    ;}
    break;

  case 38:
#line 315 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 317 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 322 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 324 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 329 "Gmsh.y"
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
    ;}
    break;

  case 43:
#line 433 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++) 
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 44:
#line 443 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:
#line 452 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:
#line 459 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:
#line 469 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d)); 
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d)); 
      ViewData->T2D.push_back(ViewData->T2C.size()); 
#endif
    ;}
    break;

  case 48:
#line 478 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:
#line 487 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 494 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 504 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size()); 
#endif
    ;}
    break;

  case 52:
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:
#line 522 "Gmsh.y"
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
    ;}
    break;

  case 54:
#line 541 "Gmsh.y"
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
    ;}
    break;

  case 55:
#line 560 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:
#line 566 "Gmsh.y"
    {
    ;}
    break;

  case 57:
#line 573 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:
#line 574 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:
#line 575 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:
#line 576 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:
#line 577 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:
#line 581 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 582 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 64:
#line 590 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	if(!(yyvsp[(2) - (4)].i))
	  gmsh_yysymbols[(yyvsp[(1) - (4)].c)].push_back((yyvsp[(3) - (4)].d));
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (4)].c)].empty()){
          if((yyvsp[(2) - (4)].i)) yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (4)].c));
          gmsh_yysymbols[(yyvsp[(1) - (4)].c)].resize(1, 0.);
        }
	switch((yyvsp[(2) - (4)].i)){
	case 0 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] = (yyvsp[(3) - (4)].d); break;
	case 1 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] += (yyvsp[(3) - (4)].d); break;
	case 2 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] -= (yyvsp[(3) - (4)].d); break;
	case 3 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] *= (yyvsp[(3) - (4)].d); break;
	case 4 : 
	  if((yyvsp[(3) - (4)].d)) gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] /= (yyvsp[(3) - (4)].d); 
	  else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), (yyvsp[(3) - (4)].d));
	  break;
	}
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 65:
#line 616 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)].resize(index + 1, 0.);
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
	if((int)gmsh_yysymbols[(yyvsp[(1) - (7)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)].resize(index + 1, 0.);
	switch((yyvsp[(5) - (7)].i)){
	case 0 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] = (yyvsp[(6) - (7)].d); break;
	case 1 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] += (yyvsp[(6) - (7)].d); break;
	case 2 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] -= (yyvsp[(6) - (7)].d); break;
	case 3 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] *= (yyvsp[(6) - (7)].d); break;
	case 4 : 
	  if((yyvsp[(6) - (7)].d)) gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] /= (yyvsp[(6) - (7)].d); 
	  else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
	  break;
	}
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 66:
#line 643 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)].resize(index + 1, 0.);
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
	  for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	    int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	    double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    if((int)gmsh_yysymbols[(yyvsp[(1) - (9)].c)].size() < index + 1)
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)].resize(index + 1, 0.);
	    switch((yyvsp[(7) - (9)].i)){
	    case 0 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] = d; break;
	    case 1 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] += d; break;
	    case 2 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] -= d; break;
	    case 3 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] *= d; break;
	    case 4 : 
	      if((yyvsp[(8) - (9)].l)) gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] /= d; 
	      else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
	      break;
	    }
	  }
	}
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 67:
#line 683 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].clear();
      gmsh_yysymbols[(yyvsp[(1) - (6)].c)] = std::vector<double>();
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
        gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 68:
#line 693 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 69:
#line 701 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (3)].c)].empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (3)].c));
        else
          gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 70:
#line 713 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c)); 
      else{
	int index = (int)(yyvsp[(3) - (6)].d);
	if((int)gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (6)].c)].resize(index + 1, 0.);
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index] += (yyvsp[(5) - (6)].i);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 71:
#line 725 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 72:
#line 734 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 73:
#line 740 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 74:
#line 749 "Gmsh.y"
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
    ;}
    break;

  case 75:
#line 767 "Gmsh.y"
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
    ;}
    break;

  case 76:
#line 785 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 77:
#line 794 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 78:
#line 806 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 79:
#line 811 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 80:
#line 819 "Gmsh.y"
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
    ;}
    break;

  case 81:
#line 839 "Gmsh.y"
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
    ;}
    break;

  case 82:
#line 862 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 83:
#line 871 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 84:
#line 879 "Gmsh.y"
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
    ;}
    break;

  case 85:
#line 901 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string() = (yyvsp[(8) - (9)].c); }
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
    ;}
    break;

  case 86:
#line 924 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  std::list<int> &vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	    double id;
	    List_Read((yyvsp[(9) - (11)].l), i, &id);
	    vl.push_back((int)id);
	  }
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
    ;}
    break;

  case 87:
#line 952 "Gmsh.y"
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
    ;}
    break;

  case 88:
#line 964 "Gmsh.y"
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
    ;}
    break;

  case 89:
#line 981 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 90:
#line 985 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 91:
#line 995 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 92:
#line 999 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[(4) - (5)].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[(4) - (5)].d));
      else{
	List_Add((yyval.l), &v);
      }
    ;}
    break;

  case 93:
#line 1011 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 94:
#line 1015 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 95:
#line 1025 "Gmsh.y"
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
    ;}
    break;

  case 96:
#line 1048 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 97:
#line 1052 "Gmsh.y"
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
    ;}
    break;

  case 98:
#line 1068 "Gmsh.y"
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
    ;}
    break;

  case 99:
#line 1090 "Gmsh.y"
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
    ;}
    break;

  case 100:
#line 1108 "Gmsh.y"
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
    ;}
    break;

  case 101:
#line 1129 "Gmsh.y"
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
    ;}
    break;

  case 102:
#line 1147 "Gmsh.y"
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
    ;}
    break;

  case 103:
#line 1177 "Gmsh.y"
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
    ;}
    break;

  case 104:
#line 1207 "Gmsh.y"
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
    ;}
    break;

  case 105:
#line 1225 "Gmsh.y"
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
    ;}
    break;

  case 106:
#line 1243 "Gmsh.y"
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
    ;}
    break;

  case 107:
#line 1269 "Gmsh.y"
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
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 108:
#line 1286 "Gmsh.y"
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
    ;}
    break;

  case 109:
#line 1304 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 110:
#line 1308 "Gmsh.y"
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
    ;}
    break;

  case 111:
#line 1327 "Gmsh.y"
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
    ;}
    break;

  case 112:
#line 1345 "Gmsh.y"
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
    ;}
    break;

  case 113:
#line 1384 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 114:
#line 1390 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 115:
#line 1396 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 116:
#line 1403 "Gmsh.y"
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
    ;}
    break;

  case 117:
#line 1428 "Gmsh.y"
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
    ;}
    break;

  case 118:
#line 1453 "Gmsh.y"
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
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 119:
#line 1469 "Gmsh.y"
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
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 120:
#line 1487 "Gmsh.y"
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
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (12)].l));
      for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
      List_Delete((yyvsp[(10) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 121:
#line 1517 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 122:
#line 1521 "Gmsh.y"
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
    ;}
    break;

  case 123:
#line 1541 "Gmsh.y"
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
    ;}
    break;

  case 124:
#line 1559 "Gmsh.y"
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
    ;}
    break;

  case 125:
#line 1576 "Gmsh.y"
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
    ;}
    break;

  case 126:
#line 1592 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 127:
#line 1596 "Gmsh.y"
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
    ;}
    break;

  case 128:
#line 1618 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 129:
#line 1623 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 130:
#line 1628 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 131:
#line 1633 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 132:
#line 1638 "Gmsh.y"
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
    ;}
    break;

  case 133:
#line 1661 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 134:
#line 1667 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 135:
#line 1677 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 136:
#line 1678 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 137:
#line 1683 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 138:
#line 1687 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 139:
#line 1691 "Gmsh.y"
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
    ;}
    break;

  case 140:
#line 1714 "Gmsh.y"
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
    ;}
    break;

  case 141:
#line 1737 "Gmsh.y"
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
    ;}
    break;

  case 142:
#line 1760 "Gmsh.y"
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
    ;}
    break;

  case 143:
#line 1788 "Gmsh.y"
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
    ;}
    break;

  case 144:
#line 1810 "Gmsh.y"
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
    ;}
    break;

  case 145:
#line 1831 "Gmsh.y"
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
    ;}
    break;

  case 146:
#line 1852 "Gmsh.y"
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
    ;}
    break;

  case 147:
#line 1872 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl);
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
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl);
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
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl);
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
          std::vector<const gLevelset *> vl;
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
    ;}
    break;

  case 148:
#line 1984 "Gmsh.y"
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
    ;}
    break;

  case 149:
#line 2003 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls);
        GM->setVisibility(0);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls, false);
        GM->setVisibility(0);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (6)].c));
#endif
    ;}
    break;

  case 150:
#line 2024 "Gmsh.y"
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
    ;}
    break;

  case 151:
#line 2132 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 152:
#line 2141 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 153:
#line 2147 "Gmsh.y"
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
    ;}
    break;

  case 154:
#line 2162 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy();
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
    ;}
    break;

  case 155:
#line 2190 "Gmsh.y"
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
    ;}
    break;

  case 156:
#line 2207 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 157:
#line 2221 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 158:
#line 2227 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 159:
#line 2233 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 160:
#line 2242 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 161:
#line 2256 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	// Warning: we *don't* close included files (to allow user
	// functions in these files). If you need to include many many
	// files and don't have functions in the files, use "Merge"
	// instead: some OSes limit the number of files a process can
	// open simultaneously. The right solution would be of course
	// to modify FunctionManager to reopen the files instead of
	// using the FILE pointer, but hey, I'm lazy...
	Msg::StatusBar(2, true, "Reading '%s'...", tmp.c_str());
	ParseFile(tmp, false, true);
	SetBoundingBox();
	Msg::StatusBar(2, true, "Done reading '%s'", tmp.c_str());
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "System"))
	SystemCall((yyvsp[(2) - (3)].c));
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 162:
#line 2298 "Gmsh.y"
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
    ;}
    break;

  case 163:
#line 2315 "Gmsh.y"
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
    ;}
    break;

  case 164:
#line 2330 "Gmsh.y"
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
    ;}
    break;

  case 165:
#line 2349 "Gmsh.y"
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
     ;}
    break;

  case 166:
#line 2361 "Gmsh.y"
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
    ;}
    break;

  case 167:
#line 2385 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 168:
#line 2389 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 169:
#line 2396 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 170:
#line 2402 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 171:
#line 2407 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 172:
#line 2413 "Gmsh.y"
    {
       GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 173:
#line 2423 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 174:
#line 2440 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 175:
#line 2457 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbols[(yyvsp[(2) - (8)].c)].resize(1);
      gmsh_yysymbols[(yyvsp[(2) - (8)].c)][0] = (yyvsp[(5) - (8)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d)) 
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 176:
#line 2476 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbols[(yyvsp[(2) - (10)].c)].resize(1);
      gmsh_yysymbols[(yyvsp[(2) - (10)].c)][0] = (yyvsp[(5) - (10)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 177:
#line 2495 "Gmsh.y"
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
            yymsg(0, "Unknown loop variable");
          else{
            gmsh_yysymbols[name][0] += step;
            LoopControlVariablesTab[ImbricatedLoop - 1][0] = gmsh_yysymbols[name][0];
          }
        }
        else{
          LoopControlVariablesTab[ImbricatedLoop - 1][0] += step;
        }
	double x0 = LoopControlVariablesTab[ImbricatedLoop - 1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop - 1][1];
        if((step > 0. && x0 <= x1) || (step < 0. && x0 >= x1)){
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 178:
#line 2525 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 179:
#line 2533 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 180:
#line 2539 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 181:
#line 2546 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 182:
#line 2550 "Gmsh.y"
    {
    ;}
    break;

  case 183:
#line 2559 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 184:
#line 2567 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 185:
#line 2575 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 186:
#line 2583 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 187:
#line 2587 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 188:
#line 2595 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 189:
#line 2599 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 190:
#line 2607 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 191:
#line 2611 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 192:
#line 2619 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 193:
#line 2623 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 194:
#line 2631 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 195:
#line 2638 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 196:
#line 2645 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 197:
#line 2652 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 198:
#line 2659 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 199:
#line 2666 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 200:
#line 2673 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 201:
#line 2680 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 202:
#line 2687 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 203:
#line 2694 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 204:
#line 2698 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 205:
#line 2705 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 206:
#line 2709 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 207:
#line 2716 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 208:
#line 2720 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 209:
#line 2727 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 210:
#line 2731 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 211:
#line 2738 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 212:
#line 2742 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 213:
#line 2749 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 214:
#line 2753 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 215:
#line 2760 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 216:
#line 2764 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 217:
#line 2771 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 218:
#line 2775 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 219:
#line 2782 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
    ;}
    break;

  case 220:
#line 2786 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 221:
#line 2797 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 2800 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 2806 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 224:
#line 2815 "Gmsh.y"
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
    ;}
    break;

  case 225:
#line 2835 "Gmsh.y"
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
    ;}
    break;

  case 226:
#line 2858 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 227:
#line 2862 "Gmsh.y"
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
    ;}
    break;

  case 228:
#line 2881 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 229:
#line 2893 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 230:
#line 2897 "Gmsh.y"
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
    ;}
    break;

  case 231:
#line 2912 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 232:
#line 2916 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
        (yyval.i) = -1;
      else // alternated
        (yyval.i) = 0;
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 233:
#line 2928 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 234:
#line 2932 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 235:
#line 2937 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 236:
#line 2941 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 237:
#line 2948 "Gmsh.y"
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
            (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                ge->meshAttributes.Method = MESH_TRANSFINITE;
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
    ;}
    break;

  case 238:
#line 3004 "Gmsh.y"
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
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                gf->meshAttributes.Method = MESH_TRANSFINITE;
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
    ;}
    break;

  case 239:
#line 3074 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 240:
#line 3079 "Gmsh.y"
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
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                gr->meshAttributes.Method = MESH_TRANSFINITE;
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
    ;}
    break;

  case 241:
#line 3146 "Gmsh.y"
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
    ;}
    break;

  case 242:
#line 3189 "Gmsh.y"
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
    ;}
    break;

  case 243:
#line 3214 "Gmsh.y"
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
            c_slave->meshMaster = j_master;	  
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
    ;}
    break;

  case 244:
#line 3242 "Gmsh.y"
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
          s_slave->meshMaster = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (12)].l), i, &ds);
            List_Read((yyvsp[(10) - (12)].l), i, &dm);	  
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
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 245:
#line 3285 "Gmsh.y"
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
    ;}
    break;

  case 246:
#line 3308 "Gmsh.y"
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
    ;}
    break;

  case 247:
#line 3331 "Gmsh.y"
    {
    ;}
    break;

  case 248:
#line 3334 "Gmsh.y"
    {
    ;}
    break;

  case 249:
#line 3343 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 250:
#line 3347 "Gmsh.y"
    { 
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 251:
#line 3357 "Gmsh.y"
    { 
      if(List_Nbr((yyvsp[(4) - (6)].l)) >= 2){
        double d;
        List_Read((yyvsp[(4) - (6)].l), 0, &d);
        Vertex *target = FindPoint((int)d);
        if(!target) yymsg(0, "Could not find Point %d", (int)d);
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
      else
        yymsg(0, "Need at least two points to merge");
      ReplaceAllDuplicates();
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 252:
#line 3391 "Gmsh.y"
    {
    
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->computeRanks();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 253:
#line 3428 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findGenerators();  
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 254:
#line 3464 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findDualGenerators();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 255:
#line 3499 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findHomSequence();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 256:
#line 3538 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 257:
#line 3539 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 258:
#line 3540 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 259:
#line 3541 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 260:
#line 3542 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 261:
#line 3543 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 262:
#line 3544 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 263:
#line 3545 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 264:
#line 3547 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 265:
#line 3553 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 266:
#line 3554 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 267:
#line 3555 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 268:
#line 3556 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 269:
#line 3557 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 270:
#line 3558 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 271:
#line 3559 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 272:
#line 3560 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 273:
#line 3561 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 274:
#line 3562 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 275:
#line 3563 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 276:
#line 3564 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 277:
#line 3565 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 278:
#line 3566 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 279:
#line 3567 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 280:
#line 3568 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 281:
#line 3569 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 282:
#line 3570 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 283:
#line 3571 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 284:
#line 3572 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 285:
#line 3573 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 286:
#line 3574 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 287:
#line 3575 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 288:
#line 3576 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 289:
#line 3577 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 290:
#line 3578 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 291:
#line 3579 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 292:
#line 3580 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 293:
#line 3581 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 294:
#line 3582 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 295:
#line 3583 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 296:
#line 3584 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 297:
#line 3586 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 298:
#line 3587 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 299:
#line 3588 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 300:
#line 3589 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 301:
#line 3590 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 302:
#line 3591 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 303:
#line 3592 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 304:
#line 3593 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 305:
#line 3594 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 306:
#line 3595 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 307:
#line 3596 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 308:
#line 3597 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:
#line 3598 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:
#line 3599 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:
#line 3600 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 312:
#line 3601 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 313:
#line 3602 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 314:
#line 3603 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 315:
#line 3604 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 316:
#line 3605 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 317:
#line 3606 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 318:
#line 3615 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 319:
#line 3616 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 320:
#line 3617 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 321:
#line 3618 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 322:
#line 3619 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 323:
#line 3620 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 324:
#line 3621 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 325:
#line 3626 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (1)].c)].empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (1)].c)][0];
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 326:
#line 3645 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[tmpstring].empty()){
          yymsg(0, "Uninitialized variable '%s'", tmpstring);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = gmsh_yysymbols[tmpstring][0];
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 327:
#line 3663 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else if((int)gmsh_yysymbols[(yyvsp[(1) - (4)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (4)].c)][index];
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 328:
#line 3678 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(2) - (4)].c)].size();
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 329:
#line 3688 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (2)].c)].empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (2)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (2)].c)][0] += (yyvsp[(2) - (2)].i));
      }
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 330:
#line 3704 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else if((int)gmsh_yysymbols[(yyvsp[(1) - (5)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (5)].c)][index] += (yyvsp[(5) - (5)].i));
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 331:
#line 3722 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 332:
#line 3727 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 333:
#line 3732 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d)){
	d += (yyvsp[(4) - (4)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 334:
#line 3742 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d)){
	d += (yyvsp[(7) - (7)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 335:
#line 3752 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 336:
#line 3760 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 337:
#line 3764 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 338:
#line 3768 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 339:
#line 3772 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 340:
#line 3776 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 341:
#line 3783 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 342:
#line 3787 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 343:
#line 3791 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 344:
#line 3795 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 345:
#line 3802 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 346:
#line 3807 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 347:
#line 3814 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 348:
#line 3819 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 349:
#line 3823 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 350:
#line 3828 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 351:
#line 3832 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 352:
#line 3840 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 353:
#line 3851 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 354:
#line 3855 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 355:
#line 3867 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 356:
#line 3875 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 357:
#line 3883 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 358:
#line 3890 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      if(!(yyvsp[(5) - (5)].d) || ((yyvsp[(1) - (5)].d) < (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) < 0) || ((yyvsp[(1) - (5)].d) > (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) > 0)){
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
	List_Add((yyval.l), &((yyvsp[(1) - (5)].d)));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 359:
#line 3901 "Gmsh.y"
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
    ;}
    break;

  case 360:
#line 3921 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    ;}
    break;

  case 361:
#line 3931 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    ;}
    break;

  case 362:
#line 3941 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else
	for(unsigned int i = 0; i < gmsh_yysymbols[(yyvsp[(1) - (3)].c)].size(); i++)
	  List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (3)].c)][i]);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 363:
#line 3951 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 364:
#line 3971 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 365:
#line 3976 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 366:
#line 3980 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 367:
#line 3984 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 368:
#line 3996 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 369:
#line 4000 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 370:
#line 4012 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 371:
#line 4019 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 372:
#line 4029 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 373:
#line 4033 "Gmsh.y"
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
    ;}
    break;

  case 374:
#line 4048 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 375:
#line 4053 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 376:
#line 4060 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 377:
#line 4064 "Gmsh.y"
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
    ;}
    break;

  case 378:
#line 4077 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 379:
#line 4085 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 380:
#line 4096 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 381:
#line 4100 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 382:
#line 4108 "Gmsh.y"
    { 
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 383:
#line 4116 "Gmsh.y"
    { 
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 384:
#line 4124 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 385:
#line 4132 "Gmsh.y"
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
    ;}
    break;

  case 386:
#line 4146 "Gmsh.y"
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
    ;}
    break;

  case 387:
#line 4160 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 388:
#line 4164 "Gmsh.y"
    {
      char tmpstring[1024];
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
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 8894 "Gmsh.tab.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 4184 "Gmsh.y"


int PrintListOfDouble(char *format, List_T *list, char *buffer)
{
  int j, k;
  char tmp1[256], tmp2[256];

  j = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j); 
  buffer[j]='\0'; 
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
      return List_Nbr(list)-i;
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
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

