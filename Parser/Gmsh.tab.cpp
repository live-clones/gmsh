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
     tCpu = 307,
     tMemory = 308,
     tSyncModel = 309,
     tCreateTopology = 310,
     tCreateTopologyNoHoles = 311,
     tDistanceFunction = 312,
     tDefineConstant = 313,
     tUndefineConstant = 314,
     tPoint = 315,
     tCircle = 316,
     tEllipse = 317,
     tLine = 318,
     tSphere = 319,
     tPolarSphere = 320,
     tSurface = 321,
     tSpline = 322,
     tVolume = 323,
     tCharacteristic = 324,
     tLength = 325,
     tParametric = 326,
     tElliptic = 327,
     tRefineMesh = 328,
     tAdaptMesh = 329,
     tPlane = 330,
     tRuled = 331,
     tTransfinite = 332,
     tComplex = 333,
     tPhysical = 334,
     tCompound = 335,
     tPeriodic = 336,
     tUsing = 337,
     tPlugin = 338,
     tDegenerated = 339,
     tRecursive = 340,
     tRotate = 341,
     tTranslate = 342,
     tSymmetry = 343,
     tDilate = 344,
     tExtrude = 345,
     tLevelset = 346,
     tRecombine = 347,
     tSmoother = 348,
     tSplit = 349,
     tDelete = 350,
     tCoherence = 351,
     tIntersect = 352,
     tMeshAlgorithm = 353,
     tReverse = 354,
     tLayers = 355,
     tScaleLast = 356,
     tHole = 357,
     tAlias = 358,
     tAliasWithOptions = 359,
     tQuadTriAddVerts = 360,
     tQuadTriNoNewVerts = 361,
     tQuadTriSngl = 362,
     tQuadTriDbl = 363,
     tRecombLaterals = 364,
     tTransfQuadTri = 365,
     tText2D = 366,
     tText3D = 367,
     tInterpolationScheme = 368,
     tTime = 369,
     tCombine = 370,
     tBSpline = 371,
     tBezier = 372,
     tNurbs = 373,
     tNurbsOrder = 374,
     tNurbsKnots = 375,
     tColor = 376,
     tColorTable = 377,
     tFor = 378,
     tIn = 379,
     tEndFor = 380,
     tIf = 381,
     tEndIf = 382,
     tExit = 383,
     tAbort = 384,
     tField = 385,
     tReturn = 386,
     tCall = 387,
     tFunction = 388,
     tShow = 389,
     tHide = 390,
     tGetValue = 391,
     tGetEnv = 392,
     tGetString = 393,
     tHomology = 394,
     tCohomology = 395,
     tBetti = 396,
     tSetOrder = 397,
     tGMSH_MAJOR_VERSION = 398,
     tGMSH_MINOR_VERSION = 399,
     tGMSH_PATCH_VERSION = 400,
     tAFFECTDIVIDE = 401,
     tAFFECTTIMES = 402,
     tAFFECTMINUS = 403,
     tAFFECTPLUS = 404,
     tOR = 405,
     tAND = 406,
     tNOTEQUAL = 407,
     tEQUAL = 408,
     tGREATEROREQUAL = 409,
     tLESSOREQUAL = 410,
     UNARYPREC = 411,
     tMINUSMINUS = 412,
     tPLUSPLUS = 413
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
#define tRound 287
#define tFmod 288
#define tModulo 289
#define tHypot 290
#define tList 291
#define tPrintf 292
#define tError 293
#define tStr 294
#define tSprintf 295
#define tStrCat 296
#define tStrPrefix 297
#define tStrRelative 298
#define tStrReplace 299
#define tStrFind 300
#define tStrCmp 301
#define tTextAttributes 302
#define tBoundingBox 303
#define tDraw 304
#define tSetChanged 305
#define tToday 306
#define tCpu 307
#define tMemory 308
#define tSyncModel 309
#define tCreateTopology 310
#define tCreateTopologyNoHoles 311
#define tDistanceFunction 312
#define tDefineConstant 313
#define tUndefineConstant 314
#define tPoint 315
#define tCircle 316
#define tEllipse 317
#define tLine 318
#define tSphere 319
#define tPolarSphere 320
#define tSurface 321
#define tSpline 322
#define tVolume 323
#define tCharacteristic 324
#define tLength 325
#define tParametric 326
#define tElliptic 327
#define tRefineMesh 328
#define tAdaptMesh 329
#define tPlane 330
#define tRuled 331
#define tTransfinite 332
#define tComplex 333
#define tPhysical 334
#define tCompound 335
#define tPeriodic 336
#define tUsing 337
#define tPlugin 338
#define tDegenerated 339
#define tRecursive 340
#define tRotate 341
#define tTranslate 342
#define tSymmetry 343
#define tDilate 344
#define tExtrude 345
#define tLevelset 346
#define tRecombine 347
#define tSmoother 348
#define tSplit 349
#define tDelete 350
#define tCoherence 351
#define tIntersect 352
#define tMeshAlgorithm 353
#define tReverse 354
#define tLayers 355
#define tScaleLast 356
#define tHole 357
#define tAlias 358
#define tAliasWithOptions 359
#define tQuadTriAddVerts 360
#define tQuadTriNoNewVerts 361
#define tQuadTriSngl 362
#define tQuadTriDbl 363
#define tRecombLaterals 364
#define tTransfQuadTri 365
#define tText2D 366
#define tText3D 367
#define tInterpolationScheme 368
#define tTime 369
#define tCombine 370
#define tBSpline 371
#define tBezier 372
#define tNurbs 373
#define tNurbsOrder 374
#define tNurbsKnots 375
#define tColor 376
#define tColorTable 377
#define tFor 378
#define tIn 379
#define tEndFor 380
#define tIf 381
#define tEndIf 382
#define tExit 383
#define tAbort 384
#define tField 385
#define tReturn 386
#define tCall 387
#define tFunction 388
#define tShow 389
#define tHide 390
#define tGetValue 391
#define tGetEnv 392
#define tGetString 393
#define tHomology 394
#define tCohomology 395
#define tBetti 396
#define tSetOrder 397
#define tGMSH_MAJOR_VERSION 398
#define tGMSH_MINOR_VERSION 399
#define tGMSH_PATCH_VERSION 400
#define tAFFECTDIVIDE 401
#define tAFFECTTIMES 402
#define tAFFECTMINUS 403
#define tAFFECTPLUS 404
#define tOR 405
#define tAND 406
#define tNOTEQUAL 407
#define tEQUAL 408
#define tGREATEROREQUAL 409
#define tLESSOREQUAL 410
#define UNARYPREC 411
#define tMINUSMINUS 412
#define tPLUSPLUS 413




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string> gmsh_yystringsymbols;
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
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

struct doubleXstring{
  double d;
  char *s;
};



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
#line 93 "Gmsh.y"
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
#line 522 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 535 "Gmsh.tab.cpp"

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
#define YYLAST   8963

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  179
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  473
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1641

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   413

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   164,     2,   174,     2,   163,     2,     2,
     169,   170,   161,   159,   175,   160,   173,   162,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     155,     2,   156,   150,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   171,     2,   172,   168,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   176,     2,   177,   178,     2,     2,     2,
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
     145,   146,   147,   148,   149,   151,   152,   153,   154,   157,
     158,   165,   166,   167
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    59,    67,    75,    83,    93,
     100,   107,   114,   115,   118,   121,   124,   127,   130,   132,
     136,   138,   142,   143,   144,   155,   157,   161,   162,   176,
     178,   182,   183,   199,   208,   223,   224,   231,   233,   235,
     237,   239,   241,   243,   245,   251,   257,   262,   269,   277,
     285,   295,   305,   309,   316,   321,   328,   338,   345,   355,
     361,   370,   379,   391,   398,   408,   414,   422,   432,   442,
     454,   462,   472,   482,   483,   485,   486,   490,   496,   497,
     507,   513,   514,   524,   525,   529,   533,   539,   540,   543,
     547,   553,   557,   558,   561,   565,   569,   575,   577,   579,
     580,   586,   587,   590,   598,   599,   609,   616,   624,   629,
     637,   646,   655,   663,   671,   683,   692,   701,   702,   712,
     721,   731,   735,   740,   751,   759,   767,   776,   785,   798,
     799,   809,   818,   826,   835,   836,   846,   852,   864,   870,
     880,   890,   895,   905,   915,   917,   919,   920,   923,   930,
     937,   944,   951,   960,   971,   986,  1003,  1016,  1025,  1034,
    1041,  1056,  1061,  1068,  1075,  1079,  1084,  1090,  1097,  1101,
    1105,  1110,  1116,  1121,  1127,  1131,  1139,  1147,  1151,  1159,
    1163,  1166,  1169,  1172,  1175,  1191,  1194,  1197,  1200,  1203,
    1206,  1223,  1227,  1234,  1243,  1252,  1263,  1265,  1268,  1270,
    1274,  1279,  1281,  1287,  1299,  1313,  1314,  1322,  1323,  1337,
    1338,  1354,  1355,  1362,  1371,  1380,  1389,  1402,  1415,  1428,
    1443,  1458,  1473,  1474,  1487,  1488,  1501,  1502,  1515,  1516,
    1533,  1534,  1551,  1552,  1569,  1570,  1589,  1590,  1609,  1610,
    1629,  1631,  1634,  1640,  1648,  1658,  1661,  1664,  1667,  1671,
    1674,  1678,  1681,  1685,  1688,  1692,  1702,  1709,  1710,  1714,
    1715,  1717,  1718,  1721,  1722,  1725,  1733,  1740,  1749,  1755,
    1759,  1767,  1773,  1778,  1785,  1792,  1805,  1816,  1827,  1838,
    1849,  1860,  1865,  1870,  1873,  1877,  1884,  1886,  1888,  1890,
    1893,  1899,  1907,  1918,  1920,  1924,  1927,  1930,  1933,  1937,
    1941,  1945,  1949,  1953,  1957,  1961,  1965,  1969,  1973,  1977,
    1981,  1985,  1989,  1995,  2000,  2005,  2010,  2015,  2020,  2025,
    2030,  2035,  2040,  2045,  2052,  2057,  2062,  2067,  2072,  2077,
    2082,  2087,  2094,  2101,  2108,  2113,  2118,  2123,  2128,  2133,
    2138,  2143,  2148,  2153,  2158,  2163,  2170,  2175,  2180,  2185,
    2190,  2195,  2200,  2205,  2212,  2219,  2226,  2231,  2233,  2235,
    2237,  2239,  2241,  2243,  2245,  2247,  2249,  2251,  2256,  2261,
    2264,  2270,  2274,  2281,  2286,  2294,  2301,  2308,  2315,  2320,
    2322,  2325,  2328,  2332,  2336,  2348,  2358,  2366,  2374,  2376,
    2380,  2382,  2384,  2387,  2391,  2396,  2402,  2404,  2406,  2409,
    2413,  2417,  2423,  2428,  2431,  2434,  2437,  2440,  2446,  2452,
    2458,  2464,  2466,  2468,  2472,  2476,  2481,  2488,  2495,  2497,
    2499,  2503,  2507,  2517,  2525,  2527,  2533,  2537,  2544,  2546,
    2550,  2552,  2554,  2558,  2565,  2567,  2569,  2574,  2581,  2588,
    2593,  2598,  2607,  2612,  2617,  2622,  2627,  2634,  2641,  2643,
    2647,  2653,  2659,  2661
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     180,     0,    -1,   181,    -1,     1,     6,    -1,    -1,   181,
     182,    -1,   185,    -1,   184,    -1,   203,    -1,   217,    -1,
     222,    -1,   226,    -1,   227,    -1,   228,    -1,   231,    -1,
     251,    -1,   252,    -1,   230,    -1,   229,    -1,   225,    -1,
     254,    -1,   156,    -1,   156,   156,    -1,    37,   169,   267,
     170,     6,    -1,    38,   169,   267,   170,     6,    -1,    37,
     169,   267,   170,   183,   267,     6,    -1,    37,   169,   267,
     175,   263,   170,     6,    -1,    38,   169,   267,   175,   263,
     170,     6,    -1,    37,   169,   267,   175,   263,   170,   183,
     267,     6,    -1,     4,   267,   176,   186,   177,     6,    -1,
     103,     4,   171,   255,   172,     6,    -1,   104,     4,   171,
     255,   172,     6,    -1,    -1,   186,   189,    -1,   186,   193,
      -1,   186,   196,    -1,   186,   198,    -1,   186,   199,    -1,
     255,    -1,   187,   175,   255,    -1,   255,    -1,   188,   175,
     255,    -1,    -1,    -1,     4,   190,   169,   187,   170,   191,
     176,   188,   177,     6,    -1,   267,    -1,   192,   175,   267,
      -1,    -1,   111,   169,   255,   175,   255,   175,   255,   170,
     194,   176,   192,   177,     6,    -1,   267,    -1,   195,   175,
     267,    -1,    -1,   112,   169,   255,   175,   255,   175,   255,
     175,   255,   170,   197,   176,   195,   177,     6,    -1,   113,
     176,   259,   177,   176,   259,   177,     6,    -1,   113,   176,
     259,   177,   176,   259,   177,   176,   259,   177,   176,   259,
     177,     6,    -1,    -1,   114,   200,   176,   188,   177,     6,
      -1,     7,    -1,   149,    -1,   148,    -1,   147,    -1,   146,
      -1,   167,    -1,   166,    -1,    58,   171,   205,   172,     6,
      -1,    59,   171,   208,   172,     6,    -1,   271,   201,   260,
       6,    -1,     4,   171,   172,   201,   260,     6,    -1,     4,
     171,   255,   172,   201,   255,     6,    -1,     4,   169,   255,
     170,   201,   255,     6,    -1,     4,   171,   176,   263,   177,
     172,   201,   260,     6,    -1,     4,   169,   176,   263,   177,
     170,   201,   260,     6,    -1,   271,   202,     6,    -1,     4,
     171,   255,   172,   202,     6,    -1,   271,     7,   268,     6,
      -1,     4,   173,     4,     7,   268,     6,    -1,     4,   171,
     255,   172,   173,     4,     7,   268,     6,    -1,     4,   173,
       4,   201,   255,     6,    -1,     4,   171,   255,   172,   173,
       4,   201,   255,     6,    -1,     4,   173,     4,   202,     6,
      -1,     4,   171,   255,   172,   173,     4,   202,     6,    -1,
       4,   173,   121,   173,     4,     7,   264,     6,    -1,     4,
     171,   255,   172,   173,   121,   173,     4,     7,   264,     6,
      -1,     4,   173,   122,     7,   265,     6,    -1,     4,   171,
     255,   172,   173,   122,     7,   265,     6,    -1,     4,   130,
       7,   255,     6,    -1,   130,   171,   255,   172,     7,     4,
       6,    -1,   130,   171,   255,   172,   173,     4,     7,   255,
       6,    -1,   130,   171,   255,   172,   173,     4,     7,   268,
       6,    -1,   130,   171,   255,   172,   173,     4,     7,   176,
     263,   177,     6,    -1,   130,   171,   255,   172,   173,     4,
       6,    -1,    83,   169,     4,   170,   173,     4,     7,   255,
       6,    -1,    83,   169,     4,   170,   173,     4,     7,   268,
       6,    -1,    -1,   175,    -1,    -1,   205,   204,   271,    -1,
     205,   204,   271,     7,   255,    -1,    -1,   205,   204,   271,
       7,   176,   255,   206,   210,   177,    -1,   205,   204,   271,
       7,   268,    -1,    -1,   205,   204,   271,     7,   176,   268,
     207,   212,   177,    -1,    -1,   208,   204,   267,    -1,   255,
       7,   268,    -1,   209,   175,   255,     7,   268,    -1,    -1,
     210,   211,    -1,   175,     4,   260,    -1,   175,     4,   176,
     209,   177,    -1,   175,     4,   268,    -1,    -1,   212,   213,
      -1,   175,     4,   255,    -1,   175,     4,   268,    -1,   175,
       4,   176,   269,   177,    -1,   255,    -1,   268,    -1,    -1,
     124,    64,   176,   255,   177,    -1,    -1,    75,   257,    -1,
      60,   169,   255,   170,     7,   257,     6,    -1,    -1,    79,
      60,   218,   169,   214,   170,     7,   260,     6,    -1,    69,
      70,   260,     7,   255,     6,    -1,    63,   169,   255,   170,
       7,   260,     6,    -1,    84,    63,   260,     6,    -1,    67,
     169,   255,   170,     7,   260,     6,    -1,    61,   169,   255,
     170,     7,   260,   216,     6,    -1,    62,   169,   255,   170,
       7,   260,   216,     6,    -1,   116,   169,   255,   170,     7,
     260,     6,    -1,   117,   169,   255,   170,     7,   260,     6,
      -1,   118,   169,   255,   170,     7,   260,   120,   260,   119,
     255,     6,    -1,    63,     4,   169,   255,   170,     7,   260,
       6,    -1,    80,    63,   169,   255,   170,     7,   260,     6,
      -1,    -1,    79,    63,   219,   169,   214,   170,     7,   260,
       6,    -1,    75,    66,   169,   255,   170,     7,   260,     6,
      -1,    76,    66,   169,   255,   170,     7,   260,   215,     6,
      -1,    12,    13,     6,    -1,    13,    66,   255,     6,    -1,
      71,    66,   169,   255,   170,     7,     5,     5,     5,     6,
      -1,    64,   169,   255,   170,     7,   260,     6,    -1,    65,
     169,   255,   170,     7,   260,     6,    -1,    66,     4,   169,
     255,   170,     7,   260,     6,    -1,    80,    66,   169,   255,
     170,     7,   260,     6,    -1,    80,    66,   169,   255,   170,
       7,   260,     4,   176,   259,   177,     6,    -1,    -1,    79,
      66,   220,   169,   214,   170,     7,   260,     6,    -1,    78,
      68,   169,   255,   170,     7,   260,     6,    -1,    68,   169,
     255,   170,     7,   260,     6,    -1,    80,    68,   169,   255,
     170,     7,   260,     6,    -1,    -1,    79,    68,   221,   169,
     214,   170,     7,   260,     6,    -1,    87,   257,   176,   223,
     177,    -1,    86,   176,   257,   175,   257,   175,   255,   177,
     176,   223,   177,    -1,    88,   257,   176,   223,   177,    -1,
      89,   176,   257,   175,   255,   177,   176,   223,   177,    -1,
      89,   176,   257,   175,   257,   177,   176,   223,   177,    -1,
       4,   176,   223,   177,    -1,    97,    63,   176,   263,   177,
      66,   176,   255,   177,    -1,    94,    63,   169,   255,   170,
     176,   263,   177,     6,    -1,   224,    -1,   222,    -1,    -1,
     224,   217,    -1,   224,    60,   176,   263,   177,     6,    -1,
     224,    63,   176,   263,   177,     6,    -1,   224,    66,   176,
     263,   177,     6,    -1,   224,    68,   176,   263,   177,     6,
      -1,    91,    75,   169,   255,   170,     7,   260,     6,    -1,
      91,    60,   169,   255,   170,     7,   176,   259,   177,     6,
      -1,    91,    75,   169,   255,   170,     7,   176,   257,   175,
     257,   175,   263,   177,     6,    -1,    91,    75,   169,   255,
     170,     7,   176,   257,   175,   257,   175,   257,   175,   263,
     177,     6,    -1,    91,    64,   169,   255,   170,     7,   176,
     257,   175,   263,   177,     6,    -1,    91,     4,   169,   255,
     170,     7,   260,     6,    -1,    91,     4,   169,   255,   170,
       7,     5,     6,    -1,    91,     4,   176,   255,   177,     6,
      -1,    91,     4,   169,   255,   170,     7,   176,   257,   175,
     257,   175,   263,   177,     6,    -1,    95,   176,   224,   177,
      -1,    95,   130,   171,   255,   172,     6,    -1,    95,     4,
     171,   255,   172,     6,    -1,    95,     4,     6,    -1,    95,
       4,     4,     6,    -1,   121,   264,   176,   224,   177,    -1,
      85,   121,   264,   176,   224,   177,    -1,   134,     5,     6,
      -1,   135,     5,     6,    -1,   134,   176,   224,   177,    -1,
      85,   134,   176,   224,   177,    -1,   135,   176,   224,   177,
      -1,    85,   135,   176,   224,   177,    -1,     4,   268,     6,
      -1,     4,     4,   171,   255,   172,   267,     6,    -1,     4,
       4,     4,   171,   255,   172,     6,    -1,     4,   255,     6,
      -1,    83,   169,     4,   170,   173,     4,     6,    -1,   115,
       4,     6,    -1,   128,     6,    -1,   129,     6,    -1,    54,
       6,    -1,    48,     6,    -1,    48,   176,   255,   175,   255,
     175,   255,   175,   255,   175,   255,   175,   255,   177,     6,
      -1,    49,     6,    -1,    50,     6,    -1,    55,     6,    -1,
      56,     6,    -1,    73,     6,    -1,    74,   176,   263,   177,
     176,   263,   177,   176,   259,   177,   176,   255,   175,   255,
     177,     6,    -1,   142,   255,     6,    -1,   123,   169,   255,
       8,   255,   170,    -1,   123,   169,   255,     8,   255,     8,
     255,   170,    -1,   123,     4,   124,   176,   255,     8,   255,
     177,    -1,   123,     4,   124,   176,   255,     8,   255,     8,
     255,   177,    -1,   125,    -1,   133,     4,    -1,   131,    -1,
     132,     4,     6,    -1,   126,   169,   255,   170,    -1,   127,
      -1,    90,   257,   176,   224,   177,    -1,    90,   176,   257,
     175,   257,   175,   255,   177,   176,   224,   177,    -1,    90,
     176,   257,   175,   257,   175,   257,   175,   255,   177,   176,
     224,   177,    -1,    -1,    90,   257,   176,   224,   232,   245,
     177,    -1,    -1,    90,   176,   257,   175,   257,   175,   255,
     177,   176,   224,   233,   245,   177,    -1,    -1,    90,   176,
     257,   175,   257,   175,   257,   175,   255,   177,   176,   224,
     234,   245,   177,    -1,    -1,    90,   176,   224,   235,   245,
     177,    -1,    90,    60,   176,   255,   175,   257,   177,     6,
      -1,    90,    63,   176,   255,   175,   257,   177,     6,    -1,
      90,    66,   176,   255,   175,   257,   177,     6,    -1,    90,
      60,   176,   255,   175,   257,   175,   257,   175,   255,   177,
       6,    -1,    90,    63,   176,   255,   175,   257,   175,   257,
     175,   255,   177,     6,    -1,    90,    66,   176,   255,   175,
     257,   175,   257,   175,   255,   177,     6,    -1,    90,    60,
     176,   255,   175,   257,   175,   257,   175,   257,   175,   255,
     177,     6,    -1,    90,    63,   176,   255,   175,   257,   175,
     257,   175,   257,   175,   255,   177,     6,    -1,    90,    66,
     176,   255,   175,   257,   175,   257,   175,   257,   175,   255,
     177,     6,    -1,    -1,    90,    60,   176,   255,   175,   257,
     177,   236,   176,   245,   177,     6,    -1,    -1,    90,    63,
     176,   255,   175,   257,   177,   237,   176,   245,   177,     6,
      -1,    -1,    90,    66,   176,   255,   175,   257,   177,   238,
     176,   245,   177,     6,    -1,    -1,    90,    60,   176,   255,
     175,   257,   175,   257,   175,   255,   177,   239,   176,   245,
     177,     6,    -1,    -1,    90,    63,   176,   255,   175,   257,
     175,   257,   175,   255,   177,   240,   176,   245,   177,     6,
      -1,    -1,    90,    66,   176,   255,   175,   257,   175,   257,
     175,   255,   177,   241,   176,   245,   177,     6,    -1,    -1,
      90,    60,   176,   255,   175,   257,   175,   257,   175,   257,
     175,   255,   177,   242,   176,   245,   177,     6,    -1,    -1,
      90,    63,   176,   255,   175,   257,   175,   257,   175,   257,
     175,   255,   177,   243,   176,   245,   177,     6,    -1,    -1,
      90,    66,   176,   255,   175,   257,   175,   257,   175,   257,
     175,   255,   177,   244,   176,   245,   177,     6,    -1,   246,
      -1,   245,   246,    -1,   100,   176,   255,   177,     6,    -1,
     100,   176,   260,   175,   260,   177,     6,    -1,   100,   176,
     260,   175,   260,   175,   260,   177,     6,    -1,   101,     6,
      -1,    92,     6,    -1,   107,     6,    -1,   107,   109,     6,
      -1,   108,     6,    -1,   108,   109,     6,    -1,   105,     6,
      -1,   105,   109,     6,    -1,   106,     6,    -1,   106,   109,
       6,    -1,   102,   169,   255,   170,     7,   260,    82,   255,
       6,    -1,    82,     4,   171,   255,   172,     6,    -1,    -1,
      82,     4,   255,    -1,    -1,     4,    -1,    -1,     7,   260,
      -1,    -1,     7,   255,    -1,    77,    63,   261,     7,   255,
     247,     6,    -1,    77,    66,   261,   249,   248,     6,    -1,
      72,    66,   176,   255,   177,     7,   260,     6,    -1,    77,
      68,   261,   249,     6,    -1,   110,   261,     6,    -1,    98,
      66,   176,   263,   177,   255,     6,    -1,    92,    66,   261,
     250,     6,    -1,    92,    68,   261,     6,    -1,    93,    66,
     260,     7,   255,     6,    -1,    81,    63,   260,     7,   260,
       6,    -1,    81,    66,   255,   176,   263,   177,     7,   255,
     176,   263,   177,     6,    -1,    60,   176,   263,   177,   124,
      66,   176,   255,   177,     6,    -1,    63,   176,   263,   177,
     124,    66,   176,   255,   177,     6,    -1,    60,   176,   263,
     177,   124,    68,   176,   255,   177,     6,    -1,    63,   176,
     263,   177,   124,    68,   176,   255,   177,     6,    -1,    66,
     176,   263,   177,   124,    68,   176,   255,   177,     6,    -1,
      99,    66,   261,     6,    -1,    99,    63,   261,     6,    -1,
      96,     6,    -1,    96,     4,     6,    -1,    96,    60,   176,
     263,   177,     6,    -1,   139,    -1,   140,    -1,   141,    -1,
     253,     6,    -1,   253,   176,   260,   177,     6,    -1,   253,
     176,   260,   175,   260,   177,     6,    -1,   253,   169,   260,
     170,   176,   260,   175,   260,   177,     6,    -1,   256,    -1,
     169,   255,   170,    -1,   160,   255,    -1,   159,   255,    -1,
     164,   255,    -1,   255,   160,   255,    -1,   255,   159,   255,
      -1,   255,   161,   255,    -1,   255,   162,   255,    -1,   255,
     163,   255,    -1,   255,   168,   255,    -1,   255,   155,   255,
      -1,   255,   156,   255,    -1,   255,   158,   255,    -1,   255,
     157,   255,    -1,   255,   154,   255,    -1,   255,   153,   255,
      -1,   255,   152,   255,    -1,   255,   151,   255,    -1,   255,
     150,   255,     8,   255,    -1,    14,   169,   255,   170,    -1,
      15,   169,   255,   170,    -1,    16,   169,   255,   170,    -1,
      17,   169,   255,   170,    -1,    18,   169,   255,   170,    -1,
      19,   169,   255,   170,    -1,    20,   169,   255,   170,    -1,
      21,   169,   255,   170,    -1,    22,   169,   255,   170,    -1,
      24,   169,   255,   170,    -1,    25,   169,   255,   175,   255,
     170,    -1,    26,   169,   255,   170,    -1,    27,   169,   255,
     170,    -1,    28,   169,   255,   170,    -1,    29,   169,   255,
     170,    -1,    30,   169,   255,   170,    -1,    31,   169,   255,
     170,    -1,    32,   169,   255,   170,    -1,    33,   169,   255,
     175,   255,   170,    -1,    34,   169,   255,   175,   255,   170,
      -1,    35,   169,   255,   175,   255,   170,    -1,    23,   169,
     255,   170,    -1,    14,   171,   255,   172,    -1,    15,   171,
     255,   172,    -1,    16,   171,   255,   172,    -1,    17,   171,
     255,   172,    -1,    18,   171,   255,   172,    -1,    19,   171,
     255,   172,    -1,    20,   171,   255,   172,    -1,    21,   171,
     255,   172,    -1,    22,   171,   255,   172,    -1,    24,   171,
     255,   172,    -1,    25,   171,   255,   175,   255,   172,    -1,
      26,   171,   255,   172,    -1,    27,   171,   255,   172,    -1,
      28,   171,   255,   172,    -1,    29,   171,   255,   172,    -1,
      30,   171,   255,   172,    -1,    31,   171,   255,   172,    -1,
      32,   171,   255,   172,    -1,    33,   171,   255,   175,   255,
     172,    -1,    34,   171,   255,   175,   255,   172,    -1,    35,
     171,   255,   175,   255,   172,    -1,    23,   171,   255,   172,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   143,
      -1,   144,    -1,   145,    -1,    52,    -1,    53,    -1,   271,
      -1,     4,   171,   255,   172,    -1,   174,     4,   171,   172,
      -1,   271,   202,    -1,     4,   171,   255,   172,   202,    -1,
       4,   173,     4,    -1,     4,   171,   255,   172,   173,     4,
      -1,     4,   173,     4,   202,    -1,     4,   171,   255,   172,
     173,     4,   202,    -1,   136,   169,   267,   175,   255,   170,
      -1,    45,   169,   267,   175,   267,   170,    -1,    46,   169,
     267,   175,   267,   170,    -1,    47,   169,   269,   170,    -1,
     258,    -1,   160,   257,    -1,   159,   257,    -1,   257,   160,
     257,    -1,   257,   159,   257,    -1,   176,   255,   175,   255,
     175,   255,   175,   255,   175,   255,   177,    -1,   176,   255,
     175,   255,   175,   255,   175,   255,   177,    -1,   176,   255,
     175,   255,   175,   255,   177,    -1,   169,   255,   175,   255,
     175,   255,   170,    -1,   260,    -1,   259,   175,   260,    -1,
     255,    -1,   262,    -1,   176,   177,    -1,   176,   263,   177,
      -1,   160,   176,   263,   177,    -1,   255,   161,   176,   263,
     177,    -1,   260,    -1,     5,    -1,   160,   262,    -1,   255,
     161,   262,    -1,   255,     8,   255,    -1,   255,     8,   255,
       8,   255,    -1,    60,   176,   255,   177,    -1,    60,     5,
      -1,    63,     5,    -1,    66,     5,    -1,    68,     5,    -1,
      79,    60,   176,   263,   177,    -1,    79,    63,   176,   263,
     177,    -1,    79,    66,   176,   263,   177,    -1,    79,    68,
     176,   263,   177,    -1,   222,    -1,   231,    -1,     4,   171,
     172,    -1,     4,   169,   170,    -1,    36,   171,     4,   172,
      -1,     4,   171,   176,   263,   177,   172,    -1,     4,   169,
     176,   263,   177,   170,    -1,   255,    -1,   262,    -1,   263,
     175,   255,    -1,   263,   175,   262,    -1,   176,   255,   175,
     255,   175,   255,   175,   255,   177,    -1,   176,   255,   175,
     255,   175,   255,   177,    -1,     4,    -1,     4,   173,   121,
     173,     4,    -1,   176,   266,   177,    -1,     4,   171,   255,
     172,   173,   122,    -1,   264,    -1,   266,   175,   264,    -1,
     268,    -1,   271,    -1,     4,   173,     4,    -1,     4,   171,
     255,   172,   173,     4,    -1,     5,    -1,    51,    -1,   137,
     169,   267,   170,    -1,   138,   169,   267,   175,   267,   170,
      -1,    41,   169,   267,   175,   267,   170,    -1,    42,   169,
     267,   170,    -1,    43,   169,   267,   170,    -1,    44,   169,
     267,   175,   267,   175,   267,   170,    -1,    39,   169,   269,
     170,    -1,    39,   171,   269,   172,    -1,    40,   169,   267,
     170,    -1,    40,   171,   267,   172,    -1,    40,   169,   267,
     175,   263,   170,    -1,    40,   171,   267,   175,   263,   172,
      -1,   267,    -1,   269,   175,   267,    -1,     4,   178,   176,
     255,   177,    -1,   270,   178,   176,   255,   177,    -1,     4,
      -1,   270,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   172,   177,   179,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   201,   205,   212,   217,   222,   236,   249,   262,   290,
     304,   315,   330,   335,   336,   337,   338,   339,   343,   345,
     350,   352,   358,   462,   357,   480,   487,   498,   497,   515,
     522,   533,   532,   549,   566,   589,   588,   602,   603,   604,
     605,   606,   610,   611,   617,   619,   621,   683,   713,   748,
     782,   830,   877,   892,   908,   917,   923,   932,   950,   968,
     977,   989,   994,  1002,  1022,  1045,  1056,  1064,  1086,  1109,
    1135,  1156,  1168,  1182,  1182,  1184,  1186,  1197,  1209,  1208,
    1220,  1232,  1231,  1245,  1247,  1255,  1261,  1268,  1269,  1273,
    1284,  1299,  1309,  1310,  1315,  1323,  1332,  1350,  1354,  1365,
    1368,  1381,  1384,  1394,  1418,  1417,  1437,  1459,  1477,  1498,
    1516,  1546,  1576,  1594,  1612,  1638,  1656,  1675,  1674,  1697,
    1715,  1754,  1760,  1766,  1773,  1798,  1823,  1840,  1859,  1894,
    1893,  1917,  1935,  1952,  1969,  1968,  1994,  1999,  2004,  2009,
    2014,  2019,  2042,  2048,  2059,  2060,  2065,  2068,  2072,  2095,
    2118,  2141,  2169,  2190,  2216,  2237,  2259,  2279,  2391,  2410,
    2448,  2557,  2566,  2572,  2587,  2615,  2632,  2641,  2655,  2661,
    2667,  2676,  2685,  2694,  2708,  2753,  2770,  2785,  2804,  2816,
    2840,  2844,  2849,  2856,  2862,  2867,  2873,  2881,  2885,  2889,
    2894,  2949,  2962,  2979,  2996,  3017,  3038,  3073,  3081,  3087,
    3094,  3098,  3107,  3115,  3123,  3132,  3131,  3146,  3145,  3160,
    3159,  3174,  3173,  3187,  3194,  3201,  3208,  3215,  3222,  3229,
    3236,  3243,  3251,  3250,  3264,  3263,  3277,  3276,  3290,  3289,
    3303,  3302,  3316,  3315,  3329,  3328,  3342,  3341,  3355,  3354,
    3371,  3374,  3380,  3392,  3412,  3436,  3441,  3445,  3449,  3453,
    3457,  3461,  3465,  3469,  3473,  3477,  3496,  3509,  3512,  3528,
    3531,  3548,  3551,  3557,  3560,  3567,  3623,  3693,  3698,  3765,
    3801,  3809,  3852,  3891,  3911,  3938,  3978,  4001,  4024,  4028,
    4032,  4055,  4094,  4139,  4143,  4153,  4188,  4189,  4190,  4194,
    4200,  4212,  4230,  4258,  4259,  4260,  4261,  4262,  4263,  4264,
    4265,  4266,  4273,  4274,  4275,  4276,  4277,  4278,  4279,  4280,
    4281,  4282,  4283,  4284,  4285,  4286,  4287,  4288,  4289,  4290,
    4291,  4292,  4293,  4294,  4295,  4296,  4297,  4298,  4299,  4300,
    4301,  4302,  4303,  4304,  4305,  4308,  4309,  4310,  4311,  4312,
    4313,  4314,  4315,  4316,  4317,  4318,  4319,  4320,  4321,  4322,
    4323,  4324,  4325,  4326,  4327,  4328,  4329,  4338,  4339,  4340,
    4341,  4342,  4343,  4344,  4345,  4346,  4350,  4368,  4386,  4398,
    4415,  4436,  4441,  4446,  4456,  4466,  4471,  4480,  4485,  4512,
    4516,  4520,  4524,  4528,  4535,  4539,  4543,  4547,  4554,  4559,
    4566,  4571,  4575,  4580,  4584,  4592,  4603,  4607,  4619,  4627,
    4635,  4642,  4652,  4672,  4676,  4680,  4684,  4688,  4717,  4746,
    4775,  4804,  4814,  4824,  4837,  4849,  4861,  4880,  4901,  4906,
    4910,  4914,  4926,  4930,  4942,  4949,  4959,  4963,  4978,  4983,
    4990,  4994,  5007,  5015,  5026,  5030,  5038,  5046,  5054,  5062,
    5076,  5090,  5102,  5119,  5135,  5140,  5144,  5164,  5186,  5191,
    5197,  5206,  5219,  5222
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
  "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod", "tModulo",
  "tHypot", "tList", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tStrFind", "tStrCmp",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tCpu", "tMemory", "tSyncModel", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRecursive",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast",
  "tHole", "tAlias", "tAliasWithOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tFunction",
  "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString", "tHomology",
  "tCohomology", "tBetti", "tSetOrder", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "Affectation", "Comma",
  "DefineConstants", "@6", "@7", "UndefineConstants", "Enumeration",
  "FloatParameterOptions", "FloatParameterOption", "CharParameterOptions",
  "CharParameterOption", "PhysicalId", "InSphereCenter", "CircleOptions",
  "Shape", "@8", "@9", "@10", "@11", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "@12", "@13", "@14", "@15", "@16", "@17",
  "@18", "@19", "@20", "@21", "@22", "@23", "@24", "ExtrudeParameters",
  "ExtrudeParameter", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "RecursiveListOfStringExprVar", "StringIndex", "String__Index", 0
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
      63,   405,   406,   407,   408,    60,    62,   409,   410,    43,
      45,    42,    47,    37,    33,   411,   412,   413,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   179,   180,   180,   181,   181,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   183,   183,   184,   184,   184,   184,   184,   184,   185,
     185,   185,   186,   186,   186,   186,   186,   186,   187,   187,
     188,   188,   190,   191,   189,   192,   192,   194,   193,   195,
     195,   197,   196,   198,   198,   200,   199,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   204,   204,   205,   205,   205,   206,   205,
     205,   207,   205,   208,   208,   209,   209,   210,   210,   211,
     211,   211,   212,   212,   213,   213,   213,   214,   214,   215,
     215,   216,   216,   217,   218,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   219,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   220,
     217,   217,   217,   217,   221,   217,   222,   222,   222,   222,
     222,   222,   222,   222,   223,   223,   224,   224,   224,   224,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   226,   226,   226,   226,   226,   227,   227,   228,   228,
     228,   228,   228,   228,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   231,   231,   231,   232,   231,   233,   231,   234,
     231,   235,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   236,   231,   237,   231,   238,   231,   239,   231,
     240,   231,   241,   231,   242,   231,   243,   231,   244,   231,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   247,   247,   248,
     248,   249,   249,   250,   250,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   252,   252,   252,   253,   253,   253,   254,
     254,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   257,
     257,   257,   257,   257,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   261,   261,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   263,
     263,   263,   264,   264,   264,   264,   265,   265,   266,   266,
     267,   267,   267,   267,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   269,   269,
     270,   270,   271,   271
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     7,     7,     7,     9,     6,
       6,     6,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     0,     0,    10,     1,     3,     0,    13,     1,
       3,     0,    15,     8,    14,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     6,     7,     7,
       9,     9,     3,     6,     4,     6,     9,     6,     9,     5,
       8,     8,    11,     6,     9,     5,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       5,     0,     9,     0,     3,     3,     5,     0,     2,     3,
       5,     3,     0,     2,     3,     3,     5,     1,     1,     0,
       5,     0,     2,     7,     0,     9,     6,     7,     4,     7,
       8,     8,     7,     7,    11,     8,     8,     0,     9,     8,
       9,     3,     4,    10,     7,     7,     8,     8,    12,     0,
       9,     8,     7,     8,     0,     9,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     6,     3,     3,
       4,     5,     4,     5,     3,     7,     7,     3,     7,     3,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
      16,     3,     6,     8,     8,    10,     1,     2,     1,     3,
       4,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     2,     2,     3,     2,
       3,     2,     3,     2,     3,     9,     6,     0,     3,     0,
       1,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       7,     5,     4,     6,     6,    12,    10,    10,    10,    10,
      10,     4,     4,     2,     3,     6,     1,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     2,
       5,     3,     6,     4,     7,     6,     6,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     5,     5,     5,
       5,     1,     1,     3,     3,     4,     6,     6,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     3,     6,     1,     1,     4,     6,     6,     4,
       4,     8,     4,     4,     4,     4,     6,     6,     1,     3,
       5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,     0,   221,     0,
       0,     0,   218,     0,     0,     0,     0,   306,   307,   308,
       0,     5,     7,     6,     8,     9,    10,    19,    11,    12,
      13,    18,    17,    14,    15,    16,     0,    20,   473,     0,
     377,   472,   454,   378,   379,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,   384,   385,
       0,     0,     0,     0,   381,   382,   383,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,   313,     0,   450,
     386,     0,     0,     0,     0,   203,     0,   205,   206,   202,
     207,   208,    95,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,     0,     0,     0,     0,     0,     0,     0,   124,   137,
     149,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,     0,   303,     0,
       0,     0,     0,     0,     0,     0,   472,   417,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   431,   432,   410,
     416,     0,   411,   386,     0,     0,     0,     0,   444,     0,
       0,     0,     0,     0,   200,   201,     0,     0,   217,     0,
     166,     0,   166,   472,     0,   309,     0,     0,     0,    57,
      61,    60,    59,    58,    63,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,   315,   317,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,   164,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,   194,   389,   141,     0,   472,     0,
     450,   451,     0,     0,    93,    93,     0,     0,   438,   439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,   166,     0,   401,   400,     0,
       0,     0,     0,   166,   166,     0,     0,     0,     0,     0,
       0,     0,   231,     0,   166,     0,     0,     0,     0,     0,
     283,     0,     0,     0,     0,   184,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,   424,   425,   426,     0,     0,     0,     0,
       0,   315,   418,     0,   412,     0,     0,     0,   289,   199,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
     219,   188,     0,   189,     0,     0,   211,     0,     0,     0,
       0,     0,    72,     0,     0,   391,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314,    57,     0,
       0,     0,    57,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,   167,     0,     0,   331,   330,   329,   328,
     324,   325,   327,   326,   319,   318,   320,   321,   322,   323,
       0,   142,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   166,     0,     0,     0,     0,     0,   403,   402,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,   185,
       0,     0,   181,     0,     0,     0,   302,   301,     0,     0,
     434,     0,   433,     0,     0,   391,     0,     0,     0,     0,
       0,     0,     0,   314,   413,   420,     0,   320,   419,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,   190,
     192,     0,     0,     0,     0,    74,    66,     0,   387,   393,
     333,   355,   334,   356,   335,   357,   336,   358,   337,   359,
     338,   360,   339,   361,   340,   362,   341,   363,   354,   376,
     342,   364,     0,     0,   344,   366,   345,   367,   346,   368,
     347,   369,   348,   370,   349,   371,   350,   372,     0,     0,
       0,     0,     0,     0,   462,     0,   463,   464,     0,   465,
       0,     0,   459,   460,     0,     0,     0,   398,    85,     0,
     456,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,   388,     0,     0,     0,
       0,   470,     0,    42,     0,     0,     0,    55,     0,    33,
      34,    35,    36,    37,     0,   452,    23,    21,     0,     0,
      24,     0,     0,    64,   472,    96,    65,   104,     0,   440,
     441,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     282,   280,     0,   288,     0,     0,   117,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   193,
       0,     0,     0,   156,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,   222,     0,     0,     0,     0,     0,     0,   284,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   387,   435,   422,     0,     0,     0,     0,   414,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,     0,   310,   471,     0,     0,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,     0,     0,    73,    75,    77,     0,     0,
     448,     0,    83,     0,     0,     0,     0,   332,     0,     0,
       0,     0,     0,    29,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,   286,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,     0,   265,     0,
     271,     0,   273,     0,   267,     0,   269,     0,   232,   261,
       0,     0,     0,   179,     0,     0,     0,   293,     0,   183,
     182,   305,     0,     0,    30,    31,     0,     0,     0,   427,
     428,   429,   430,   421,   415,     0,     0,     0,   445,     0,
       0,     0,   212,     0,     0,     0,     0,   196,   392,   195,
     343,   365,   351,   373,   352,   374,   353,   375,   466,   467,
     458,     0,   396,   397,   395,   457,     0,    69,     0,    57,
       0,     0,     0,     0,    68,     0,     0,     0,   446,     0,
       0,     0,     0,     0,     0,     0,     0,   408,     0,     0,
      25,    26,     0,    27,     0,     0,    97,   100,   123,     0,
       0,     0,     0,     0,     0,   127,     0,     0,   144,   145,
       0,     0,   129,   152,     0,     0,     0,     0,   119,     0,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,     0,     0,   166,   166,     0,   242,     0,
     244,     0,   246,     0,   410,     0,     0,   272,   274,   268,
     270,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,   437,   436,   392,   132,   133,     0,
       0,     0,     0,    86,    90,     0,     0,   311,   394,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,   449,
     168,   169,   170,   171,     0,    38,     0,     0,     0,     0,
       0,    40,   453,     0,     0,    98,   101,     0,     0,   122,
     130,   131,   135,     0,     0,   146,     0,     0,   287,     0,
     139,     0,     0,   278,   151,     0,     0,     0,     0,   136,
       0,   147,   153,     0,     0,     0,     0,   407,     0,   406,
       0,     0,     0,   233,     0,     0,   234,     0,     0,   235,
       0,     0,     0,     0,     0,     0,     0,   178,     0,     0,
     177,     0,     0,     0,   172,     0,     0,     0,     0,   443,
       0,   214,   213,     0,     0,     0,     0,   461,    71,    70,
      76,    78,     0,    84,     0,    43,     0,     0,     0,   409,
       0,     0,     0,    28,     0,   107,   112,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   125,   138,   150,   155,
       0,     0,    91,    92,   166,     0,   159,   160,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,   166,     0,
       0,     0,     0,     0,   163,   162,     0,     0,     0,     0,
      87,    88,     0,     0,   447,     0,    39,     0,     0,     0,
      41,    56,     0,     0,     0,   296,   298,   297,   299,   300,
     143,     0,     0,     0,     0,     0,     0,   405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,     0,
       0,   227,     0,     0,   173,     0,     0,     0,   442,   215,
       0,   312,    82,     0,     0,     0,     0,     0,     0,    99,
     108,     0,   102,   113,     0,     0,     0,     0,   157,     0,
     248,     0,     0,   250,     0,     0,   252,     0,     0,     0,
     263,     0,   223,     0,   166,     0,     0,     0,   134,    89,
       0,    47,     0,    53,     0,     0,     0,     0,     0,   120,
     148,   295,   404,   236,     0,     0,   243,   237,     0,     0,
     245,   238,     0,     0,   247,     0,     0,     0,   229,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     111,     0,   114,   115,     0,     0,   254,     0,   256,     0,
     258,   264,   275,   228,   224,     0,     0,     0,     0,    44,
       0,    51,     0,     0,     0,   438,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,     0,   180,     0,
     174,     0,    45,     0,     0,   204,     0,   110,     0,   116,
       0,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,     0,     0,     0,   105,   210,   249,     0,   251,     0,
     253,     0,   175,    46,    48,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    54,   106,   255,   257,   259,    50,
      52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    81,   858,    82,    83,   630,  1274,  1280,
     849,  1018,  1425,  1591,   850,  1544,  1625,   851,  1593,   852,
     853,  1022,   296,   395,    84,   641,   404,  1375,  1376,   405,
    1574,  1433,  1480,  1434,  1483,   895,  1302,  1182,   613,   432,
     433,   434,   435,   257,   374,   375,    87,    88,    89,    90,
      91,    92,   258,   933,  1503,  1565,   696,  1324,  1327,  1330,
    1524,  1528,  1532,  1580,  1583,  1586,   929,   930,  1053,   892,
     667,   705,    94,    95,    96,    97,   259,   157,   448,   218,
    1166,   260,   261,   262,   505,   270,   835,  1011,   580,   400,
     581,    98,   263
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1229
static const yytype_int16 yypact[] =
{
    5137,    40,    65,  5244, -1229, -1229,   372,    95,   -30,   -35,
     -25,    34,   186,   216,   224,   239,   293,    -7,   120,  -137,
     184,   205,     0,   253,   286,    19,   298,   324,   248,   266,
     342,   491,   327,   446,   481,   187,   462,   398,   217,    92,
     434,   505,   158,   458,  -100,  -100,   476,    83,   111,   115,
     589,   613,     3,    52,   616,   621,   371,   687,   688,  3037,
     692,   531,   532,   537,    23,    25, -1229,   543, -1229,   707,
     721,   572, -1229,   747,   750,    28,    29, -1229, -1229, -1229,
    4953, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229, -1229, -1229, -1229, -1229, -1229,    15, -1229,   584,   128,
   -1229,     7, -1229, -1229, -1229, -1229,   302,   316,   320,   382,
     427,   457,   466,   480,   554,   557,   570,   581,   590,   607,
     611,   612,   634,   651,   658,   659,   678,   683,   693,   709,
     594,   608,   615,   635,   640,   641,   645, -1229, -1229, -1229,
     812,   654,   679,   684, -1229, -1229, -1229,  4953,  4953,  4953,
    4645,    64,    44,   859,   237,   690,   459, -1229,   691,   866,
      81,   867,  4953,    97,    97, -1229,  4953, -1229, -1229, -1229,
   -1229, -1229, -1229, -1229,  4953,  4858,  4953,  4953,   713,  4953,
    4858,  4953,  4953,   735,  4858,  4953,  4953,  3373,   745,   743,
   -1229,  4858,   771,   789,  3037,  3037,  3037,   790, -1229, -1229,
   -1229, -1229,   819,   820,   835,  3373,  4953,  1006,  3373,    23,
     831,   841,  -100,  -100,  -100,  4953,  4953,    61, -1229,   122,
    -100,   842,   847,   860,  4690,   250,    -6,   921,   924,   928,
    3037,  3037,  3373,   932,    41,   935, -1229,  1077, -1229,   931,
     937,   988,  3037,  3037,   986,   994,   546, -1229,   997,    30,
    1131,  1166,  1186,   840,  3541,  4953,  2605, -1229, -1229,  3496,
   -1229,  1192, -1229,   212,  1201,  4953,  4953,  4953,  1035,  4953,
    1043,  1087,  4953,  4953, -1229, -1229,  4953,  1214, -1229,  1219,
   -1229,  1221, -1229,    78,   638, -1229,  3373,  3373,  1047,   620,
   -1229, -1229, -1229, -1229, -1229, -1229,  3373,  1223,  1059,  4953,
    1227,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,
    4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,
    4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,
    4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,
    4953,  4953,  4953,  4953,  4953,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,  4953,    97,    97,    97,
    1064,  1064,  1064,  4858,  7619,    70,  4858,  6837,   334,  1060,
    1228,  1063,  1061, -1229,  1062,  5332,  4953, -1229,  4953,  4953,
    4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,  4953,
    4953,  4953,  4953, -1229, -1229, -1229, -1229,   682,   149,  -109,
   -1229, -1229,   -70,  6109,   263,   276,  7640,  4858,  3657, -1229,
     365,  7661,  7682,  4953,  7703,   429,  7724,  7745,  4953,   704,
    7766,  7787,  1231,  4953,  4953,   722,  4953,  4953,  1233,  1234,
    1234,  4953,  1075,  1076,  1079,  1080,  4953,  4953,  4953,  1239,
    6029,  1081,  1246,  1078, -1229, -1229,   -56, -1229, -1229,  6135,
    6161,  -100,  -100,   237,   237,   261,  4953,  4953,  4953,  4690,
    4690,  4953,  5332,   268, -1229,  4953,  4953,  4953,  4953,  4953,
    1248,  1247,  1249,  4953,  1252, -1229,  4953,  4953,   669, -1229,
    4858,  4858,  4858,  1253,  1254,  4953,  4953,  -113,  4471,  1258,
    1259, -1229,  4953, -1229, -1229, -1229,  1088,  1090,  1091,  1092,
    4858,  1064, -1229,  7808, -1229,   732,  4953,  3709, -1229, -1229,
    7829,  7850,  7871,  1149,  6187, -1229,  1095,  3679,  7892,  6860,
   -1229, -1229,  1572, -1229,  1641,  4953, -1229,  1117,   748,  4953,
    1282,  1283, -1229,  4953,  6883,   163,  7913,  6906,  7934,  6929,
    7955,  6952,  7976,  6975,  7997,  6998,  8018,  7021,  8039,  7044,
    8060,  7067,  8081,  7090,  8102,  7113,  8123,  7136,  6213,  6239,
    8144,  7159,  8165,  7182,  8186,  7205,  8207,  7228,  8228,  7251,
    8249,  7274,  8270,  7297,  6265,  6291,  6317,  6343,  6369,  6395,
   -1229,     2,   348,    69,   354,  1116,  1124,  1126,  1123,  1125,
    1127,   284,   811,  1128,  1134,  1130,   749,    70, -1229,  3373,
     753,   283,   620,  4953,  1286,  1297,    26,  1135, -1229,    56,
      13,    27,   164, -1229,  5267,  3835,  1841,  2238,   733,   733,
     697,   697,   697,   697,   -11,   -11,  1064,  1064,  1064,  1064,
      16, -1229,  4953,  1302,    31,  4858,  1304,  4858,  4953,  1306,
   -1229,  1309,  1310,    97,  1301,  4858,  4858,  1197,  1319,  1320,
    8291,  1321,  1205,  1323,  1324,  8312,  1208,  1326,  1327,  4953,
    8333,  5301,  1159,  8354,  8375,  4953,  3373,  1332,  1337,  8396,
    5020,  5020,  5020,  5020,  8417,  8438,  8459,  3373,  4858,  1164,
   -1229, -1229,  1711,  1964,  -100,  4953,  4953, -1229, -1229,  1181,
    1182,  4690,  6421,  6447,  6473,  6083,   664,  -100,  2287,  8480,
    5329,  8501,  8522,  8543,  4953,  1355, -1229,  4953,  8564, -1229,
    7320,  7343, -1229,   754,   757,   760, -1229, -1229,  7366,  7389,
   -1229,  4858, -1229,  4858,  7412,   212,  1191,  5357,  4858,  4858,
    4858,  4858,   761, -1229, -1229,  3993,  4858,  1064, -1229,  1357,
    1359,  1360,  1196,  4953,  2487,  4953,  4953, -1229,    42, -1229,
   -1229,  1199,  3373,  1366,  5385, -1229, -1229,  7435,   435, -1229,
   -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229, -1229,  4953,  4953, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229,  4953,  4953,
    4953,  4953,  4953,  4953, -1229,    97, -1229, -1229,  4858, -1229,
    4858,    97, -1229, -1229,    97,    97,    97, -1229, -1229,  4953,
   -1229,    97,  1206,  4953,  1371,  1215,    46,  4953,  1382,  1383,
    1194, -1229,  1384,  1225,    23,  1386, -1229,  4858,  4858,  4858,
    4858, -1229,  4953, -1229,  1229,  1230,  1224, -1229,  1397, -1229,
   -1229, -1229, -1229, -1229,  7458, -1229, -1229,  1241,    97,   363,
   -1229,   369,  6499, -1229,  1212,  1398, -1229, -1229,  -100,  3657,
   -1229,   873,  3373,  3373,  1403,  3373,   877,  3373,  3373,  1404,
    1336,  3373,  3373,  1708,  1405,  1408,  4858,  1409,  1410,  4167,
   -1229, -1229,  1412, -1229,  1417,  1255,  8795, -1229,  1256,  1260,
    1264,  1428,  1434,  1435,  1422,   772,  1440,  2726, -1229, -1229,
     282,  6525,  6551, -1229, -1229,  5413,   -46,  -100,  -100,  -100,
    1441,  1442,  1270,  1443,  1281,    36,    38,    45,    47,   602,
   -1229,   285, -1229,   664,  1444,  1446,  1447,  1449,  1451,  8795,
   -1229,  1907,  1271,  1454,  1455,  1456,  1387,  4953,  1457,  1462,
     773,   780,   -41, -1229, -1229,   800,   801,   805,   806, -1229,
    4953,   809,  3373,  3373,  3373,  1465,  6577, -1229,  4015,   425,
    1466,  1467,  3373,  1298, -1229, -1229,  1471,  1476, -1229,  1478,
    8585,  7481,  8606,  7504,  8627,  7527,  8648,  7550, -1229,   387,
     395,  1315,  1312,  1318,  1325,  8669,  1330,    70,  2104, -1229,
      70,   358,  1317,  1487,  2156, -1229, -1229, -1229,    23,  4953,
   -1229,   810, -1229,   822,   823,   836,   849,  8795,  1333,  4953,
    4953,  3373,  1328, -1229,  1334, -1229,  1495,    32,  1499,  4953,
    4213,    37,  1338,  1339,  1431,  1431,  3373,  1503,  1340,  1341,
    1504,  1514,  3373,  1348,  1519,  1524, -1229,  1526,  3373,   852,
    3373,  3373,  1528,  1527, -1229,  3373,  1533,  1534,  1535,  1536,
    3373,  3373,  3373, -1229,  1538,   593, -1229,  4953,  4953,  4953,
    1373,  1374,  -105,   -53,    54,  1376, -1229,  3373, -1229,  4953,
   -1229,  1545, -1229,  1546, -1229,  1547, -1229,  1548, -1229, -1229,
    4690,   769,  3205, -1229,  1380,  1381,  3877, -1229,  4858, -1229,
   -1229, -1229,  1385,  2262, -1229, -1229,  1388,  1390,  1556, -1229,
   -1229, -1229, -1229,  8795, -1229,  1558,  1559,  1450, -1229,  4953,
    4953,  4953, -1229,  1560,   623,  1394,  1566, -1229,   204, -1229,
   -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229,    97, -1229, -1229, -1229, -1229,  3373, -1229,  3373,   620,
    4953,  1571,  1575,    26, -1229,  1576,  7573,    23, -1229,  1580,
    1581,  1582,  1593,  4953,  6603,  6629,   853, -1229,  4953,  1596,
   -1229, -1229,    97, -1229,  6655,  5020,  8795, -1229, -1229,  4953,
    4953,  -100,  1595,  1597,  1598, -1229,  4953,  4953, -1229, -1229,
    1599,  4953, -1229, -1229,  1602,  1603,  1437,  1608,  1496,  4953,
   -1229,  1618,  3373,  3373,  3373,  3373,  1619,  1027,  1620,  4953,
   -1229,  5020,  5441,  8690,  4375,   237,   237,  -100,  1621,  -100,
    1622,  -100,  1624,  4953,   110,  1469,  8711, -1229, -1229, -1229,
   -1229,  5469,   287, -1229,  1625,  2425,  1639,  3373,  -100,  2425,
    1640,   857,  4953, -1229, -1229, -1229,   212, -1229, -1229,  3373,
    4594,   151,  8732, -1229, -1229,  4258,  3373, -1229, -1229,  1479,
    1649,  1651,  1653,  2374, -1229,  1654,  1656, -1229,  1491, -1229,
   -1229, -1229, -1229, -1229,   399,  8795,  4953,  4953,  3373,  1484,
     907,  8795, -1229,  1659,  4953,  8795, -1229,  5497,  5525,   482,
   -1229, -1229, -1229,  5553,  5581, -1229,  5609,  1663, -1229,  3373,
   -1229,  1605,  1664,  8795, -1229,  1665,  1666,  1667,  1669, -1229,
    1500, -1229, -1229,  6056,  2553,  1671,  1502, -1229,  4953, -1229,
    1505,  1507,   309, -1229,  1509,   336, -1229,  1515,   339, -1229,
    1516,  7596,  1673,  3373,  1674,  1517,  4953, -1229,  4045,   359,
   -1229,   911,   362,   430, -1229,  1680,  5637,  1561,  4953, -1229,
    4953, -1229, -1229,  4858,  2790,  1688,  1518, -1229, -1229, -1229,
   -1229, -1229,    23, -1229,  1577, -1229,  4953,  6681,  6707, -1229,
    3373,  4953,  1691, -1229,  6733, -1229, -1229,  1692,  1694,  1705,
    1707,  1709,  1712,   912,  1550, -1229, -1229, -1229, -1229, -1229,
    3373,  4858, -1229, -1229,   237,  4924, -1229, -1229,  4690,   664,
    4690,   664,  4690,   664,  1716, -1229,   919,  3373, -1229,  5665,
    -100,  1721,  4858,  -100, -1229, -1229,  4953,  5693,  5721,   923,
   -1229, -1229,  1723,  1724, -1229,  1555,  8795,  4953,  4953,   956,
    8795, -1229,  4953,   957,   960, -1229, -1229, -1229, -1229, -1229,
   -1229,  1557,  4953,   964,   965,  1563,  4953, -1229,  5749,   432,
     914,  5777,   464,  1003,  5805,   472,  1217, -1229,  3373,  1728,
    1660,  3082,  1565,   510, -1229,   970,   530,  2867, -1229, -1229,
    1729, -1229, -1229,  4953,  8753,  6759,    35,  6785,  1732, -1229,
   -1229,  1739, -1229, -1229,  4953,  5833,  1738,  1744, -1229,  5861,
    1754,  4953,  1755,  1756,  4953,  1757,  1758,  4953,  1761,  1591,
   -1229,  4953, -1229,   664, -1229,  4858,  1763,  4045, -1229, -1229,
     971, -1229,  4953, -1229,  3373,  4953,  2836,  4426,  6811, -1229,
   -1229, -1229, -1229, -1229,  1594,  5889, -1229, -1229,  1607,  5917,
   -1229, -1229,  1609,  5945, -1229,  1775,  3321,  1278,  3250,   975,
   -1229,   539,   978,  1778,  1612,  8774,   981,  5973,  2605, -1229,
   -1229,    97,  8795, -1229,  4953,   664,  1786,   664,  1787,   664,
    1788, -1229, -1229, -1229, -1229,   664,  1790,  4858,  1791, -1229,
      97, -1229,  1626,  1792,  1000,  1122,  1001,  6001,  1331, -1229,
    1630,  1391, -1229,  1631,  1421, -1229,  1632,  1489, -1229,  1004,
   -1229,  1008, -1229,  1633,  3373, -1229,  4953, -1229,   620, -1229,
    1794,  1795,   664,  1805,   664,  1808,   664, -1229,  1810,    97,
    1811,    97,  1009,  3340, -1229, -1229, -1229,  1510, -1229,  1646,
   -1229,  1730, -1229, -1229, -1229,  1012, -1229,  1813,   620,  1814,
    1815,  1818,    97,  1819, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1229, -1229, -1229, -1229,   813, -1229, -1229, -1229, -1229,   360,
   -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229, -1229,  -343,   -47, -1229,  1436, -1229, -1229, -1229, -1229,
   -1229, -1229, -1229, -1229, -1229,  -112, -1229,   804,  1839, -1229,
   -1229, -1229, -1229,    -1,  -441,  -218, -1229, -1229, -1229, -1229,
   -1229, -1229,  1840, -1229, -1229, -1229, -1229, -1229, -1229, -1229,
   -1229, -1229, -1229, -1229, -1229, -1229,  -909,  -901, -1229, -1229,
    1414, -1229, -1229, -1229, -1229, -1229,   736, -1229,    76, -1229,
   -1228,  1133,   142,  1483,  -165,  -201,   694, -1229,    10,    -5,
    -341, -1229,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -454
static const yytype_int16 yytable[] =
{
      99,   159,    86,   160,   178,   582,   462,   234,   443,  1341,
     410,   298,   689,   690,   591,   415,   158,   178,   478,   419,
     843,   285,   599,   183,  1091,   603,   425,   268,  1089,   271,
     833,   183,   174,   279,   281,   491,   162,   856,  1171,   175,
     165,  1513,  1080,  1178,  1082,   474,     4,   475,   368,   970,
    1001,  1084,   297,  1086,   451,   452,   237,   720,   238,   213,
     214,   634,   522,   721,   524,     5,   635,   100,   283,   215,
    1217,  1383,  1218,   103,   104,   105,   216,   598,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     636,   398,   102,   451,   452,   637,   451,   452,   161,   134,
     135,   136,   239,   451,   452,   226,   138,   139,   506,   684,
     217,   219,  1219,   225,  1220,   294,   295,   844,   845,   846,
     847,  1071,  1108,   235,   163,   289,   128,   129,   130,   131,
     132,   133,  1429,   221,   164,  1081,   222,  1083,   137,   223,
     389,   390,   391,   373,  1085,   205,  1087,   392,   206,  1350,
     401,   401,  1443,   465,   172,   369,   370,  1002,  1003,   179,
     466,   227,   804,   399,   402,   228,   180,   805,   299,   236,
     300,   230,   179,   231,   286,   155,   229,   857,   857,   838,
    1089,   287,   167,   848,   272,   184,   451,   452,   596,   269,
     141,   600,   834,   839,   280,   282,   492,   144,   145,   146,
     166,  1514,   476,   451,   452,   971,   290,   291,   292,   293,
     451,   452,   168,   147,   148,   174,   682,   683,   149,  1221,
     169,  1222,   837,   255,   142,   143,   365,   453,   153,   807,
     366,   372,   213,   214,   808,   170,   698,   294,   295,   525,
     194,   489,   215,   195,   823,   196,   155,  -451,   827,   224,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   507,   390,   391,   290,   291,   292,   293,   392,   209,
     202,   451,   452,   203,   530,   204,  1546,  1332,   446,   447,
     598,   173,   210,   211,   294,   295,   455,   744,   454,   171,
     463,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   713,   714,   715,   187,   392,
     632,   604,   633,    43,    44,    45,    46,   155,  1351,   294,
     295,    51,   188,   186,    54,   732,   428,   429,   430,  -452,
     840,   602,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   176,   401,   401,   401,   583,   584,   585,
     586,   587,   588,   589,   590,  1149,  1612,   593,   594,   595,
     294,   295,   470,   471,   177,   100,   101,   102,   294,   295,
    -453,   103,   104,   105,   483,   484,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   189,   451,
     452,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     451,   452,   181,   137,   138,   139,   464,   451,   452,   290,
     291,   292,   293,  1121,   242,   639,   691,   243,   640,   398,
     102,   451,   452,   697,   451,   452,   451,   452,   642,   294,
     295,   640,   373,   373,   817,   182,   826,  1067,   198,   805,
    1090,   199,  1336,   907,   200,   377,   201,   185,   451,   452,
     859,   301,   861,   302,   128,   129,   130,   131,   132,   133,
     290,   291,   292,   293,  1398,   303,   137,   304,   759,   305,
    1450,   306,  1453,   186,  1456,   451,   452,   190,   451,   452,
     294,   295,   140,   191,   290,   291,   292,   293,   141,   142,
     143,  1400,   192,   905,  1402,   144,   145,   146,   451,   452,
     806,   451,   452,   805,   294,   295,   809,   687,   688,   810,
     197,   147,   148,  1027,  1410,   447,   149,  1412,   646,  1028,
     646,   150,   647,   151,   646,   152,   153,   193,   154,  1089,
     155,   307,  1089,   308,   828,  1089,   950,  1138,   951,   898,
     899,   900,   646,   955,   956,   957,   958,  1139,   208,  1365,
     646,   961,   142,   143,  1366,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   451,
     452,   451,   452,   392,  1537,  1122,   309,   829,   310,  1210,
    1211,   294,   295,   207,   646,  1413,   652,  1491,   977,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   451,   452,   102,   311,   392,   312,  1254,
    1255,   451,   452,  1010,   212,   313,  1089,   314,   865,  1494,
     401,   451,   452,   989,   526,   990,  1578,  1497,  1581,   315,
    1584,   316,   220,   867,  1146,   232,  1587,  1148,  1150,   128,
     129,   130,   131,   132,   133,   897,   897,   897,   897,   451,
     452,   137,  1013,  1014,  1015,  1016,   233,  1089,   759,   240,
    1089,     7,     8,  1089,   920,  1505,  1089,   241,   631,   451,
     452,   244,   245,  1617,   921,  1619,   264,  1621,   451,   452,
     265,   266,   922,   923,   924,  1507,   267,   925,   926,   927,
     928,   978,   273,   274,  1567,   487,  1089,   488,  1089,   489,
    1089,  1049,   154,   317,   155,   318,   319,   275,   320,   609,
      20,    21,   610,    23,    24,   611,    26,   612,    28,   321,
      29,   322,   156,   276,    33,    34,   920,    36,    37,    38,
     323,   277,   324,    41,   278,   401,   921,   142,   143,   325,
     910,   326,   288,   349,   922,   923,   924,   916,   979,   925,
     926,   927,   928,   931,  1320,  1321,   327,   350,   328,  1088,
     329,   331,   330,   332,   351,    61,    62,    63,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   401,   333,   352,   334,   392,  1155,   401,   353,
     354,   401,   401,   401,   355,   988,   284,   818,   401,   356,
     335,   991,   336,   357,   992,   993,   994,   337,   339,   338,
     340,   996,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   712,   341,   358,   342,
     392,   920,   343,   359,   344,   401,   387,   388,   389,   390,
     391,   921,   345,   371,   346,   392,   376,   393,  1026,   922,
     923,   924,   394,   396,   925,   926,   927,   928,   347,   646,
     348,   656,   413,   360,   361,   362,   364,   367,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   646,   397,   662,
     496,   392,   403,   497,   418,   978,   498,   646,   499,   734,
     406,   408,   411,   412,   423,   414,   408,   416,   417,   424,
     408,   420,   421,   752,   646,   753,   822,   408,   646,   646,
     825,   945,   646,  1241,   946,   646,   646,   947,   959,  1032,
     426,  1033,   440,  1038,  1031,  1039,  1233,   646,   646,  1064,
    1106,   449,   450,  1445,  1151,   646,  1269,  1107,   427,   431,
     450,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   646,   646,  1109,  1110,   392,
     646,   646,  1111,  1112,   646,  1157,  1114,  1158,   436,   437,
     501,   503,   408,  1072,  1073,  1074,   920,   646,   646,  1159,
    1160,   510,   511,   512,   438,   514,   921,   444,   517,   518,
     441,   646,   519,  1161,   922,   923,   924,   445,   456,   925,
     926,   927,   928,   457,   646,  1177,  1162,   646,  1278,  1196,
    1279,  1310,   646,  1311,  1345,   534,   458,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,  1258,  1371,   479,  1372,   920,  1278,  1278,  1411,  1441,
     467,  1492,   592,   468,  1458,   921,  1459,   469,   646,   408,
    1470,   473,   408,   922,   923,   924,   477,   480,   925,   926,
     927,   928,   614,   481,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,  1598,
     506,  1278,  1478,  1476,  1479,  1481,   493,  1482,   401,  1278,
     646,  1486,  1487,   501,  1262,   646,  1371,  1506,  1543,   650,
     646,  1259,  1566,   646,   655,  1568,  1278,   485,  1572,   660,
     661,  1423,   663,   664,   482,   486,  1232,   669,   490,   401,
    1286,   494,   674,   675,   676,  1596,   805,  1597,  1599,   646,
    1495,  1608,  1283,  1609,  1278,  1610,  1627,  1632,  1419,  1633,
    1461,   495,   692,   693,   694,   360,   361,   695,   508,  1258,
    1007,   699,   700,   701,   702,   703,  1315,   509,   513,   708,
    1576,   516,   710,   711,   373,   373,   408,   408,   408,   515,
     520,   718,   719,   529,   724,   521,  1444,   523,   727,   532,
     533,   535,   392,   605,   607,   606,   408,   154,   659,   608,
     665,   666,   735,   737,   670,   671,   677,  1465,   672,   673,
    1355,   679,   680,   706,   681,   704,   707,  1289,   709,   716,
     717,   724,   725,   726,   728,   754,   729,   730,   731,   757,
     742,   745,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   645,   390,   391,  1538,   751,   755,   756,
     392,   811,   831,  1322,   812,  1325,   813,  1328,   814,   920,
     815,   832,   816,   819,   820,   821,   855,   836,   868,   921,
     860,  1339,   863,   864,  1342,  1343,   866,   922,   923,   924,
     422,   871,   925,   926,   927,   928,   872,   873,   875,   876,
     877,   878,   880,   881,   882,   886,   891,   906,   439,   830,
    1539,   442,  1542,   893,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   913,   914,
     920,   940,   392,   953,   962,   472,   963,   964,   854,   965,
     921,   408,   974,   408,   862,   972,   997,   999,   922,   923,
     924,   737,   869,   925,   926,   927,   928,  1000,  1005,  1006,
     155,  1008,  1012,   373,  1498,   883,  1009,  1025,  1019,  1020,
    1021,   889,  1589,  1023,  1043,  1030,   896,   896,   896,   896,
    1036,  1042,  1047,   920,   408,  1048,  1050,  1051,  1054,   527,
     528,   911,   912,   921,  1055,  1056,  1057,   915,  1063,   531,
    1058,   922,   923,   924,  1059,  1060,   925,   926,   927,   928,
     939,  1061,  1062,   941,  1065,  1075,  1077,  1098,  1076,  1078,
    1079,  1092,  1093,  1102,  1094,  1563,  1095,   408,  1096,   408,
    1099,  1100,  1101,  1104,   408,   408,   408,   408,  1105,  1118,
    1123,  1124,   408,   920,  1449,  1126,  1452,  1127,  1455,   966,
    1128,   968,   969,   921,  1129,  1140,  1463,  1141,  1142,  1466,
    1152,   922,   923,   924,  1153,  1143,   925,   926,   927,   928,
    1145,  1170,  1163,   920,  1168,  1173,  1181,  1169,  1601,  1185,
    1188,  1550,  1553,   921,  1179,  1180,  1186,  1187,   980,   981,
    1189,   922,   923,   924,  1191,  1192,   925,   926,   927,   928,
    1193,  1194,  1199,  1200,   982,   983,   984,   985,   986,   987,
    1202,  1203,  1204,  1205,   408,  1209,   408,  1223,   401,  1215,
    1216,  1227,  1228,  1229,  1230,   995,  1237,  1238,  1244,   998,
    1246,  1242,  1245,  1004,  1247,  1248,  1253,   401,  1603,  1256,
    1249,   920,  1257,   408,   408,   408,   408,  1264,  1017,  1265,
    1592,   921,  1267,  1541,     7,     8,  1270,  1271,  1272,   922,
     923,   924,   920,  1614,   925,   926,   927,   928,  1605,  1273,
    1282,  1290,   921,  1291,  1292,  1295,   401,  1297,   401,  1298,
     922,   923,   924,  1299,  1300,   925,   926,   927,   928,  1623,
    1301,  1626,   408,  1635,  1304,  1309,  1312,  1323,  1326,   401,
    1329,  1337,   609,    20,    21,   610,    23,    24,   611,    26,
     612,    28,  1639,    29,  1333,  1340,  1344,    33,    34,  1357,
      36,    37,    38,     7,     8,  1358,    41,  1359,   409,  1360,
    1370,  1362,  1363,   409,  1364,  1373,  1607,   409,  1382,  1384,
    1385,  1386,  1387,  1388,   409,  1389,  1390,  1393,  1394,  1405,
    1416,  1407,  1396,  1103,  1397,  1399,  1414,  1629,    61,    62,
      63,  1401,  1403,  1408,  1421,  1422,  1113,  1431,  1435,  1424,
    1436,   609,    20,    21,   610,    23,    24,   611,    26,   612,
      28,  1437,    29,  1438,  1046,  1439,    33,    34,  1440,    36,
      37,    38,  1457,     7,     8,    41,  1442,  1464,   920,  1471,
    1472,  1473,   824,  1484,  1500,  1509,  1516,   502,   921,   409,
    1488,  1504,  1501,  1517,  1520,  1156,   922,   923,   924,   749,
    1521,   925,   926,   927,   928,  1164,  1165,    61,    62,    63,
    1523,  1526,  1527,  1530,  1531,  1174,  1176,  1534,  1535,  1540,
    1555,   609,    20,    21,   610,    23,    24,   611,    26,   612,
      28,  1561,    29,  1557,  1569,  1559,    33,    34,  1570,    36,
      37,    38,  1579,  1582,  1585,    41,  1588,  1590,  1595,   890,
    1615,  1616,  1594,  1212,  1213,  1214,  1602,  1604,  1606,  1611,
     904,  1618,   920,  1224,  1620,  1226,  1622,  1624,   750,  1634,
    1636,  1637,   921,  1630,  1638,  1640,  1231,    61,    62,    63,
     922,   923,   924,  1510,   408,   925,   926,   927,   928,  1183,
    1172,   643,    85,    93,   668,     0,   409,  1266,     0,   409,
       0,     0,     0,     0,     0,  1250,  1251,  1252,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,     0,   973,  1263,     0,   908,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,  1275,
       0,     0,     0,     0,  1281,     0,     0,  1631,     0,     0,
       0,  1285,     0,  1097,     0,  1287,  1288,     0,     0,     0,
       0,     0,  1293,  1294,     0,     0,     0,  1296,     0,     0,
       0,     0,     0,     0,     0,  1303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1313,     0,  1314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1331,
       0,     0,     0,   409,   409,   409,     0,     0,     0,     0,
       0,   408,     0,     0,     0,   408,     7,     8,  1346,     0,
       0,     0,     0,   409,     0,     0,     0,     0,     0,     0,
     738,  1354,     0,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,  1034,  1035,     0,  1037,   392,
    1040,  1041,  1367,  1368,  1044,  1045,     0,     0,     0,     0,
    1374,     0,     0,     0,   609,    20,    21,   610,    23,    24,
     611,    26,   612,    28,     0,    29,     0,     0,     0,    33,
      34,     0,    36,    37,    38,     0,     0,     0,    41,     0,
       0,     0,     0,     0,  1395,     0,     0,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,  1409,     0,   501,   392,     0,     0,     0,     0,
      61,    62,    63,     0,  1417,     0,  1418,     0,     0,   408,
       0,     0,     0,     0,     0,  1115,  1116,  1117,     0,     0,
       0,     0,  1426,     0,     0,  1125,     0,  1430,     0,     0,
    1147,     0,     0,     0,     0,     0,     0,     0,   409,     0,
     409,     0,     0,     0,     0,     0,     0,   408,   738,   870,
       0,     0,     0,     0,  1448,     0,  1451,     0,  1454,     0,
       0,   909,     0,     0,     0,     0,     0,     0,   408,     0,
       0,     0,  1467,     0,  1167,     0,     0,     0,     0,     0,
       0,   409,  1154,  1474,  1475,     0,     0,     0,  1477,  1184,
       0,     0,     0,     0,     0,  1190,     0,     0,  1485,     0,
       0,  1195,  1489,  1197,  1198,     0,     0,     0,  1201,     0,
       0,     0,     0,  1206,  1207,  1208,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,   409,     0,     0,  1281,
    1225,   409,   409,   409,   409,     0,     0,     0,     0,   409,
    1518,     0,     0,     0,     0,  1236,     0,  1525,     0,  1240,
    1529,     0,     0,  1533,     0,     0,     0,  1536,     0,     0,
       0,   408,     0,   408,     0,     0,     0,     0,  1545,     0,
       0,  1547,     0,  1552,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,  1243,     0,
       0,     0,   392,     0,     0,     0,     0,     0,     0,  1260,
       0,  1261,     0,     0,  1575,     0,     0,     0,     0,     0,
    1577,   409,     0,   409,     0,     0,     0,     0,     0,     7,
       8,     0,     0,   408,     0,     0,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     409,   409,   409,   409,   392,     0,     0,     0,     0,     0,
       0,     0,  1613,     0,     0,  1305,  1306,  1307,  1308,     0,
       0,     0,     0,     0,     0,     0,     0,   609,    20,    21,
     610,    23,    24,   611,    26,   612,    28,     0,    29,     0,
       0,     0,    33,    34,     0,    36,    37,    38,     0,   409,
    1167,    41,     0,     0,     0,     0,     0,     0,     0,     0,
    1361,     0,  1347,     0,     0,     0,     0,     0,     0,  1356,
       0,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,    61,    62,    63,   392,     0,     0,     0,
       0,  1369,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,   100,   246,
     392,     0,  1167,     0,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   248,     0,     0,   932,     0,  1406,     0,     0,     0,
     134,   135,   136,     0,     0,     0,     0,   138,   139,     0,
       0,     0,     0,     0,     0,   249,     0,     0,   250,     0,
       0,   251,     0,   252,     0,     0,     0,     0,     0,     7,
       8,     0,     0,  1167,   253,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,     0,     0,     0,    51,
       0,     0,    54,  1167,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
    1460,     0,   392,     0,     0,     0,     0,   609,    20,    21,
     610,    23,    24,   611,    26,   612,    28,     0,    29,  1392,
       0,   141,    33,    34,     0,    36,    37,    38,   144,   145,
     146,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   409,     0,     0,   459,  1338,     0,     0,     0,   149,
       0,  1499,     0,     0,   461,     0,     0,     0,     0,   153,
       0,   216,   504,    61,    62,    63,     0,     0,   100,   246,
       0,     0,     0,     0,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   248,     0,     0,     0,     0,     0,  1167,     0,  1549,
     134,   135,   136,     0,     0,     0,     0,   138,   139,     0,
       0,     0,     0,     0,   967,   249,     0,     0,   250,     0,
       0,   251,     0,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,     0,     0,     0,    51,
       0,     0,    54,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,   409,     0,
       0,   392,   409,     0,     0,     0,     0,  1167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,   141,     0,     0,     0,     0,     0,     0,   144,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   407,     0,     0,     0,   149,
       0,     0,     0,     0,   255,     0,     0,     0,     0,   153,
       0,     0,   504,     0,     0,     0,   609,    20,    21,   610,
      23,    24,   611,    26,   612,    28,  1420,    29,     0,     0,
       0,    33,    34,     0,    36,    37,    38,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   409,     0,     0,   100,
     246,   102,    61,    62,    63,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   248,  1508,   409,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
       0,     0,     0,     0,     0,   409,   249,     0,     0,   250,
       0,     0,   251,  1066,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,     0,     0,     0,
      51,     0,     0,    54,     0,     0,     0,     0,     0,     0,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,     0,     0,     0,     0,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   409,     0,
     409,     0,     0,     0,     0,   147,   254,     0,     0,     0,
     149,     0,     0,     0,     0,   255,     0,     0,     0,     0,
     153,     0,  1548,     0,     0,     0,     0,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   409,     0,     0,     0,   392,     0,     0,     0,     0,
     100,   246,   247,     0,     0,     0,   103,   104,   105,     0,
     409,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   248,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,     0,     0,     0,     0,   138,
     139,     0,     0,     0,     7,     8,     0,   249,     0,     0,
     250,     0,     0,   251,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,     0,     0,
       0,    51,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,   609,    20,    21,   610,    23,    24,   611,    26,
     612,    28,     0,    29,     0,     0,     0,    33,    34,     0,
      36,    37,    38,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
     144,   145,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   254,    61,    62,
      63,   149,     0,     0,     0,     0,   255,     0,   100,   246,
    1234,   153,     0,   256,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   248,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,     0,     0,     0,     0,   138,   139,  1502,
       0,     0,     7,     8,     0,   249,     0,     0,   250,     0,
       0,   251,     0,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,     0,     0,     0,    51,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
     609,    20,    21,   610,    23,    24,   611,    26,   612,    28,
       0,    29,     0,     0,     0,    33,    34,  1562,    36,    37,
      38,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,  1628,   144,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   254,    61,    62,    63,   149,
       0,     0,     0,     0,   255,     0,   100,   246,     0,   153,
       0,  1235,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   248,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,     0,     0,     0,     0,   138,   139,  1564,     0,     0,
       0,     0,     0,   249,     0,     0,   250,     0,     0,   251,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,     0,     0,     0,    51,     0,     0,
      54,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   506,     0,     0,     0,   392,   141,
       0,     0,     0,     0,     0,     0,   144,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   254,     0,     0,     0,   149,     0,     0,
       0,     0,   255,     0,   100,   246,     0,   153,     0,   256,
     103,   104,   105,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   248,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,     0,
       0,     0,     0,   138,   139,     0,     0,     0,     0,     0,
       0,   249,     0,     0,   250,     0,     0,   251,     0,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,    43,    44,    45,
      46,    47,     0,     0,     0,    51,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   507,   390,   391,
       0,     0,     0,     0,   392,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,   144,   145,   146,   746,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   407,     0,     0,     0,   149,     0,     0,     0,     0,
     255,     0,   100,   246,     0,   153,     0,   500,   103,   104,
     105,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   248,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,     0,     0,     0,
       0,   138,   139,     0,     0,     0,     0,     0,     0,   249,
       0,     0,   250,     0,     0,   251,     0,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
       0,     0,     0,    51,     0,     0,    54,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   645,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   842,     0,   141,     0,   392,     0,     0,
       0,     0,   144,   145,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   407,
       0,     0,     0,   149,     0,     0,     0,     0,   255,     0,
     100,   246,     0,   153,     0,   736,   103,   104,   105,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   248,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,     0,     0,     0,     0,   138,
     139,     0,     0,     0,     0,     0,     0,   249,     0,     0,
     250,     0,     0,   251,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,     0,     0,
       0,    51,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,   960,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
     144,   145,   146,  1120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   254,     0,     0,
       0,   149,     0,     0,     0,     0,   255,     0,   100,   246,
       0,   153,     0,  1239,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   248,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,     0,     0,     0,     0,   138,   139,     0,
       0,     0,     0,     0,     0,   249,     0,     0,   250,     0,
       0,   251,     0,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,     0,     0,     0,    51,
       0,     0,    54,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,   141,     0,   392,     0,     0,     0,     0,   144,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,  1338,     0,     0,     0,   149,
       0,     0,     0,     0,   461,     0,   100,   283,   102,   153,
       0,   216,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,  1052,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   100,   283,   102,   137,   138,   139,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,   137,
     138,   139,     0,     0,     0,     0,     0,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,   144,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,     0,     0,     0,   149,     0,     0,
       0,     0,   255,     0,     0,     0,     0,   153,     0,  1175,
       0,     0,     0,     0,   141,   142,   143,     0,     0,     0,
       0,   144,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,     0,
       0,     0,   149,     0,     0,     0,     0,   255,     0,   100,
     283,   102,   153,     0,  1353,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   100,   283,     0,   137,   138,   139,
     103,   104,   105,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,     0,
       0,     0,     0,   138,   139,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
    1318,     0,  1319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,     0,     0,     0,     0,   144,
     145,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,     0,     0,     0,
     149,     0,     0,     0,     0,   255,     0,     0,     0,     0,
     153,     0,  1551,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,   144,   145,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,     0,     0,     0,   149,     0,     0,     0,     0,
     255,     0,     0,   722,     0,   153,     0,   723,   100,   283,
       0,     0,     0,     0,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   100,   283,     0,     0,   138,   139,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   136,     0,     0,
       0,     0,   138,   139,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,     0,     0,     0,     0,     0,  1348,
       0,  1349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,   144,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,     0,     0,     0,   149,
       0,     0,     0,     0,   255,     0,     0,     0,     0,   153,
       0,   363,     0,     0,     0,     0,   141,     0,     0,     0,
       0,     0,     0,   144,   145,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     460,     0,     0,     0,   149,     0,     0,     0,     0,   461,
       0,   100,   246,     0,   153,     0,   216,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   248,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,     0,     0,     0,     0,
     138,   139,     0,     0,     0,     0,     0,     0,   249,     0,
       0,   250,     0,     0,   251,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,     0,
       0,     0,    51,     0,     0,    54,   100,   283,     0,     0,
       0,     0,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,     0,   141,     0,     0,     0,   134,   135,
     136,   144,   145,   146,     0,   138,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   407,     0,
       0,     0,   149,   100,   283,   102,     0,   255,     0,   103,
     104,   105,   153,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   137,   138,   139,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,   141,
       0,     0,   392,     0,     0,     0,   144,   145,   146,  1446,
       0,  1447,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,     0,     0,     0,   149,     0,     0,
       0,     0,   255,     0,     0,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,   141,   142,   143,     0,
       0,     0,     0,   144,   145,   146,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,   147,
     148,     0,     0,     0,   149,    -4,    -4,    -4,     0,   255,
       0,    -4,    -4,    -4,   153,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,     0,     0,     0,     0,     0,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     7,     8,     0,    57,    58,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,    60,
      61,    62,    63,     0,     0,    64,     0,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    77,    78,    79,    80,     0,     0,     0,
       0,     0,   609,    20,    21,   610,    23,    24,   611,    26,
     612,    28,     0,    29,     0,     0,     0,    33,    34,     0,
      36,    37,    38,     0,     0,     0,    41,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,   841,     0,     0,     0,    61,    62,
      63,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,   885,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,   935,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,   954,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,   975,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
    1070,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1316,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,  1335,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,  1377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,  1378,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
    1379,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1380,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,  1381,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,  1415,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,  1462,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
    1468,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1469,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,  1490,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,  1493,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,  1496,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
    1519,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1522,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,  1556,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,  1558,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,  1560,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,     0,
    1573,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1600,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,   678,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,     0,     0,     0,     0,
       0,     0,  1391,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,   733,     0,     0,     0,     0,   685,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,   638,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
     685,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,   686,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,   743,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,   782,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,   783,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
     798,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,   799,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,   800,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,   801,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,   802,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
     803,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,   917,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,   918,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,   919,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,  1029,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
    1068,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,  1069,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,  1119,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,  1276,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,  1277,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
    1284,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,  1427,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,     0,  1428,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,  1432,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,  1512,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
    1515,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,  1554,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,   601,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
       0,     0,   748,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,   758,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,     0,     0,   761,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,   763,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,     0,     0,   765,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,   767,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,     0,     0,
     769,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,   771,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,     0,     0,   773,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,   775,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
       0,     0,   777,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,   779,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,     0,     0,   781,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,   785,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,     0,     0,   787,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,   789,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,     0,     0,
     791,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,   793,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,     0,     0,   795,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,   797,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
       0,     0,   943,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,   944,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,     0,     0,   948,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,     0,
       0,   949,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,     0,     0,   952,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,     0,     0,   976,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,     0,     0,
    1024,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,     0,     0,  1131,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,     0,     0,  1133,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,     0,     0,  1135,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
       0,     0,  1137,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,     0,     0,  1268,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,     0,     0,  1404,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,   597,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
     644,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,   648,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,   649,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,   651,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,   653,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,   654,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,   657,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,   658,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,   733,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,   739,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
     740,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,   741,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,   747,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,   760,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,   762,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,   764,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,   766,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,   768,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,   770,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,   772,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
     774,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,   776,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,   778,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,   780,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,   784,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,   786,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,   788,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,   790,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,   792,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,   794,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
     796,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,   874,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,   879,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,   884,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,   887,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,   888,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,   894,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,   901,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,   902,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,   903,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
     934,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,   936,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,   937,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,   938,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,   942,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392,     0,  1130,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
       0,     0,     0,     0,   392,     0,  1132,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,     0,  1134,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,     0,     0,     0,     0,   392,     0,  1136,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,     0,  1144,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,     0,     0,     0,   392,     0,
    1317,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
       0,  1334,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,     0,  1352,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,     0,  1511,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,     0,  1571,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,     0,
       0,     0,     0,   392
};

static const yytype_int16 yycheck[] =
{
       3,     6,     3,     6,     4,   346,   224,     4,   209,  1237,
     175,     4,   453,   454,   355,   180,     6,     4,   236,   184,
       4,     6,   365,     4,   933,   368,   191,     4,   929,     4,
       4,     4,   169,     5,     5,     5,    66,     6,     6,   176,
       6,     6,     6,     6,     6,     4,     6,     6,     4,     7,
       4,     6,    99,     6,   159,   160,     4,   170,     6,   159,
     160,   170,   280,   176,   282,     0,   175,     3,     4,   169,
     175,  1299,   177,     9,    10,    11,   176,     7,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     170,     4,     5,   159,   160,   175,   159,   160,    13,    45,
      46,    47,    60,   159,   160,     4,    52,    53,     8,   175,
      44,    45,   175,    47,   177,   166,   167,   111,   112,   113,
     114,   177,   173,   130,   169,     7,    39,    40,    41,    42,
      43,    44,  1370,    60,   169,   109,    63,   109,    51,    66,
     161,   162,   163,   154,   109,    63,   109,   168,    66,     8,
     163,   164,  1390,   169,   171,   121,   122,   121,   122,   169,
     176,    60,   170,   163,   164,    64,   176,   175,   171,   176,
     173,    66,   169,    68,   169,   178,    75,   156,   156,   176,
    1091,   176,     6,   177,   169,   176,   159,   160,   363,   176,
     136,   366,   176,   176,   176,   176,   176,   143,   144,   145,
     176,   176,   171,   159,   160,   173,   146,   147,   148,   149,
     159,   160,     6,   159,   160,   169,   444,   445,   164,   175,
       6,   177,   176,   169,   137,   138,   172,   176,   174,   170,
     176,     4,   159,   160,   175,     6,   464,   166,   167,   171,
      63,   173,   169,    66,   597,    68,   178,   176,   601,   176,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   146,   147,   148,   149,   168,   121,
      63,   159,   160,    66,   289,    68,  1514,   177,   212,   213,
       7,   171,   134,   135,   166,   167,   220,   515,   176,     6,
     224,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   480,   481,   482,    70,   168,
     171,   368,   173,    86,    87,    88,    89,   178,   177,   166,
     167,    94,    66,   169,    97,   500,   194,   195,   196,   176,
     176,     7,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   169,   357,   358,   359,   347,   348,   349,
     350,   351,   352,   353,   354,     7,  1594,   357,   358,   359,
     166,   167,   230,   231,   169,     3,     4,     5,   166,   167,
     176,     9,    10,    11,   242,   243,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    66,   159,
     160,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     159,   160,   169,    51,    52,    53,   176,   159,   160,   146,
     147,   148,   149,     8,    63,   172,   175,    66,   175,     4,
       5,   159,   160,   175,   159,   160,   159,   160,   172,   166,
     167,   175,   453,   454,   170,   169,   173,   175,    60,   175,
     175,    63,   175,   681,    66,     6,    68,   169,   159,   160,
     635,   169,   637,   171,    39,    40,    41,    42,    43,    44,
     146,   147,   148,   149,   175,   169,    51,   171,   535,   169,
    1399,   171,  1401,   169,  1403,   159,   160,     6,   159,   160,
     166,   167,   130,   176,   146,   147,   148,   149,   136,   137,
     138,   175,    66,   678,   175,   143,   144,   145,   159,   160,
     172,   159,   160,   175,   166,   167,   172,   451,   452,   175,
      68,   159,   160,   170,   175,   459,   164,   175,   175,   170,
     175,   169,   177,   171,   175,   173,   174,    66,   176,  1450,
     178,   169,  1453,   171,   601,  1456,   721,   170,   723,   671,
     672,   673,   175,   728,   729,   730,   731,   172,    63,   170,
     175,   736,   137,   138,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   159,
     160,   159,   160,   168,  1503,   170,   169,   602,   171,     6,
       7,   166,   167,   169,   175,   175,   177,   175,   173,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   159,   160,     5,   169,   168,   171,     6,
       7,   159,   160,   834,   176,   169,  1537,   171,   641,   175,
     643,   159,   160,   808,     6,   810,  1555,   175,  1557,   169,
    1559,   171,   176,   643,   997,    66,  1565,  1000,  1001,    39,
      40,    41,    42,    43,    44,   670,   671,   672,   673,   159,
     160,    51,   837,   838,   839,   840,    63,  1578,   725,    63,
    1581,    12,    13,  1584,    82,   175,  1587,    66,     6,   159,
     160,     4,     4,  1602,    92,  1604,     4,  1606,   159,   160,
     169,   169,   100,   101,   102,   175,   169,   105,   106,   107,
     108,   758,   169,     6,   175,   169,  1617,   171,  1619,   173,
    1621,   886,   176,   169,   178,   171,   169,     6,   171,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   169,
      71,   171,     6,   171,    75,    76,    82,    78,    79,    80,
     169,     4,   171,    84,     4,   758,    92,   137,   138,   169,
     684,   171,   178,   169,   100,   101,   102,   691,   758,   105,
     106,   107,   108,   697,  1215,  1216,   169,   169,   171,   177,
     169,   169,   171,   171,   169,   116,   117,   118,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   805,   169,   169,   171,   168,  1008,   811,   169,
     169,   814,   815,   816,   169,   805,    80,     6,   821,     7,
     169,   811,   171,   169,   814,   815,   816,   169,   169,   171,
     171,   821,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   177,   169,   169,   171,
     168,    82,   169,   169,   171,   858,   159,   160,   161,   162,
     163,    92,   169,     4,   171,   168,   176,   176,   858,   100,
     101,   102,     6,     6,   105,   106,   107,   108,   169,   175,
     171,   177,   169,   147,   148,   149,   150,   151,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   175,   162,   177,
      60,   168,   166,    63,   169,   952,    66,   175,    68,   177,
     174,   175,   176,   177,   169,   179,   180,   181,   182,   176,
     184,   185,   186,   175,   175,   177,   177,   191,   175,   175,
     177,   177,   175,  1098,   177,   175,   175,   177,   177,    66,
     169,    68,   206,    66,   868,    68,   177,   175,   175,   177,
     177,   215,   216,  1394,  1001,   175,  1157,   177,   169,   169,
     224,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   175,   175,   177,   177,   168,
     175,   175,   177,   177,   175,   175,   177,   177,   169,   169,
     254,   255,   256,   917,   918,   919,    82,   175,   175,   177,
     177,   265,   266,   267,   169,   269,    92,   176,   272,   273,
       4,   175,   276,   177,   100,   101,   102,   176,   176,   105,
     106,   107,   108,   176,   175,  1030,   177,   175,   175,   177,
     177,     4,   175,     6,   177,   299,   176,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,  1128,   175,     6,   177,    82,   175,   175,   177,   177,
     169,   177,   356,   169,   175,    92,   177,   169,   175,   363,
     177,   169,   366,   100,   101,   102,   171,   176,   105,   106,
     107,   108,   376,   176,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,     7,
       8,   175,   175,   177,   177,   175,     5,   177,  1141,   175,
     175,   177,   177,   407,  1149,   175,   175,   177,   177,   413,
     175,  1141,   177,   175,   418,   177,   175,   171,   177,   423,
     424,  1362,   426,   427,   176,   171,  1090,   431,   171,  1172,
    1175,     5,   436,   437,   438,   175,   175,   177,   177,   175,
     177,   177,  1172,   175,   175,   177,   177,   175,  1353,   177,
    1408,     5,   456,   457,   458,   459,   460,   461,     6,  1246,
       6,   465,   466,   467,   468,   469,  1211,     6,   173,   473,
    1551,   124,   476,   477,  1215,  1216,   480,   481,   482,   176,
       6,   485,   486,   176,   488,     6,  1391,     6,   492,     6,
     171,     4,   168,   173,   171,     7,   500,   176,     7,   177,
       7,     7,   506,   507,   169,   169,     7,  1412,   169,   169,
    1255,   170,     6,     6,   176,     7,     7,  1181,     6,     6,
       6,   525,     4,     4,   176,   529,   176,   176,   176,   533,
     121,   176,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,  1504,   170,     6,     6,
     168,   175,     6,  1217,   170,  1219,   170,  1221,   175,    82,
     175,     4,   175,   175,   170,   175,     4,   172,     7,    92,
       6,  1235,     6,     4,  1238,  1239,     6,   100,   101,   102,
     187,   124,   105,   106,   107,   108,     7,     7,     7,   124,
       7,     7,   124,     7,     7,   176,     4,   173,   205,   603,
    1505,   208,  1507,     6,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   177,   177,
      82,     6,   168,   172,     7,   232,     7,     7,   632,   173,
      92,   635,     6,   637,   638,   176,   170,     6,   100,   101,
     102,   645,   646,   105,   106,   107,   108,   172,     6,     6,
     178,     7,     6,  1394,   177,   659,   171,   156,   169,   169,
     176,   665,  1567,     6,    68,     7,   670,   671,   672,   673,
       7,     7,     7,    82,   678,     7,     7,     7,     6,   286,
     287,   685,   686,    92,     7,   170,   170,   691,     6,   296,
     170,   100,   101,   102,   170,     7,   105,   106,   107,   108,
     704,     7,     7,   707,     4,     4,   176,   176,     6,     6,
     169,     7,     6,    66,     7,   177,     7,   721,     7,   723,
       6,     6,     6,     6,   728,   729,   730,   731,     6,     4,
       4,     4,   736,    82,  1398,   177,  1400,     6,  1402,   743,
       4,   745,   746,    92,     6,   170,  1410,   175,   170,  1413,
     173,   100,   101,   102,     7,   170,   105,   106,   107,   108,
     170,     6,   169,    82,   176,     6,    75,   173,   177,     6,
       6,  1516,  1517,    92,   176,   176,   176,   176,   782,   783,
       6,   100,   101,   102,   176,     6,   105,   106,   107,   108,
       6,     5,     4,     6,   798,   799,   800,   801,   802,   803,
       7,     7,     7,     7,   808,     7,   810,   171,  1551,   176,
     176,     6,     6,     6,     6,   819,   176,   176,   170,   823,
       4,   176,   172,   827,     6,     6,     6,  1570,   177,   175,
     120,    82,     6,   837,   838,   839,   840,     6,   842,     4,
    1570,    92,     6,  1507,    12,    13,     6,     6,     6,   100,
     101,   102,    82,  1598,   105,   106,   107,   108,   177,     6,
       4,     6,    92,     6,     6,     6,  1609,     5,  1611,     6,
     100,   101,   102,   176,     6,   105,   106,   107,   108,  1609,
     124,  1611,   886,  1628,     6,     6,     6,     6,     6,  1632,
       6,     6,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,  1632,    71,   175,     6,     6,    75,    76,   170,
      78,    79,    80,    12,    13,     6,    84,     6,   175,     6,
     176,     7,     6,   180,   173,     6,   177,   184,     5,    64,
       6,     6,     6,     6,   191,     6,   176,     6,   176,     6,
     119,     7,   177,   947,   177,   176,     6,   177,   116,   117,
     118,   176,   176,   176,     6,   177,   960,     6,     6,   122,
       6,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     6,    71,     6,     6,     6,    75,    76,     6,    78,
      79,    80,     6,    12,    13,    84,   176,     6,    82,     6,
       6,   176,   599,   176,     6,     6,     4,   254,    92,   256,
     177,   176,    82,     4,     6,  1009,   100,   101,   102,   177,
       6,   105,   106,   107,   108,  1019,  1020,   116,   117,   118,
       6,     6,     6,     6,     6,  1029,  1030,     6,   177,     6,
     176,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     6,    71,   176,     6,   176,    75,    76,   176,    78,
      79,    80,     6,     6,     6,    84,     6,     6,     6,   666,
       6,     6,   176,  1067,  1068,  1069,   176,   176,   176,   176,
     677,     6,    82,  1077,     6,  1079,     6,     6,   177,     6,
       6,     6,    92,   177,     6,     6,  1090,   116,   117,   118,
     100,   101,   102,  1473,  1098,   105,   106,   107,   108,  1035,
    1027,   405,     3,     3,   430,    -1,   363,  1153,    -1,   366,
      -1,    -1,    -1,    -1,    -1,  1119,  1120,  1121,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   752,  1150,    -1,   177,    -1,
     407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,
      -1,    -1,    -1,    -1,  1168,    -1,    -1,   177,    -1,    -1,
      -1,  1175,    -1,     6,    -1,  1179,  1180,    -1,    -1,    -1,
      -1,    -1,  1186,  1187,    -1,    -1,    -1,  1191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1209,    -1,  1211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1223,
      -1,    -1,    -1,   480,   481,   482,    -1,    -1,    -1,    -1,
      -1,  1235,    -1,    -1,    -1,  1239,    12,    13,  1242,    -1,
      -1,    -1,    -1,   500,    -1,    -1,    -1,    -1,    -1,    -1,
     507,  1255,    -1,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   872,   873,    -1,   875,   168,
     877,   878,  1276,  1277,   881,   882,    -1,    -1,    -1,    -1,
    1284,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      76,    -1,    78,    79,    80,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,  1318,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,  1336,    -1,  1338,   168,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,  1348,    -1,  1350,    -1,    -1,  1353,
      -1,    -1,    -1,    -1,    -1,   962,   963,   964,    -1,    -1,
      -1,    -1,  1366,    -1,    -1,   972,    -1,  1371,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,
     637,    -1,    -1,    -1,    -1,    -1,    -1,  1391,   645,   646,
      -1,    -1,    -1,    -1,  1398,    -1,  1400,    -1,  1402,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,  1412,    -1,
      -1,    -1,  1416,    -1,  1021,    -1,    -1,    -1,    -1,    -1,
      -1,   678,     6,  1427,  1428,    -1,    -1,    -1,  1432,  1036,
      -1,    -1,    -1,    -1,    -1,  1042,    -1,    -1,  1442,    -1,
      -1,  1048,  1446,  1050,  1051,    -1,    -1,    -1,  1055,    -1,
      -1,    -1,    -1,  1060,  1061,  1062,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   721,    -1,   723,    -1,    -1,  1473,
    1077,   728,   729,   730,   731,    -1,    -1,    -1,    -1,   736,
    1484,    -1,    -1,    -1,    -1,  1092,    -1,  1491,    -1,  1096,
    1494,    -1,    -1,  1497,    -1,    -1,    -1,  1501,    -1,    -1,
      -1,  1505,    -1,  1507,    -1,    -1,    -1,    -1,  1512,    -1,
      -1,  1515,    -1,  1517,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     6,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,  1146,
      -1,  1148,    -1,    -1,  1548,    -1,    -1,    -1,    -1,    -1,
    1554,   808,    -1,   810,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,  1567,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     837,   838,   839,   840,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1596,    -1,    -1,  1202,  1203,  1204,  1205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    80,    -1,   886,
    1237,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,  1249,    -1,    -1,    -1,    -1,    -1,    -1,  1256,
      -1,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,   116,   117,   118,   168,    -1,    -1,    -1,
      -1,  1278,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,     3,     4,
     168,    -1,  1299,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   177,    -1,  1333,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,  1370,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,  1390,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
    1407,    -1,   168,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,     6,
      -1,   136,    75,    76,    -1,    78,    79,    80,   143,   144,
     145,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1098,    -1,    -1,   159,   160,    -1,    -1,    -1,   164,
      -1,  1458,    -1,    -1,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,   177,   116,   117,   118,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,  1514,    -1,  1516,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,   177,    60,    -1,    -1,    63,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,  1235,    -1,
      -1,   168,  1239,    -1,    -1,    -1,    -1,  1594,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,   174,
      -1,    -1,   177,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     6,    71,    -1,    -1,
      -1,    75,    76,    -1,    78,    79,    80,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1353,    -1,    -1,     3,
       4,     5,   116,   117,   118,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     6,  1391,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,  1412,    60,    -1,    -1,    63,
      -1,    -1,    66,   177,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,  1505,    -1,
    1507,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,  1548,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
    1567,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    12,    13,    -1,    60,    -1,    -1,
      63,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   116,   117,
     118,   164,    -1,    -1,    -1,    -1,   169,    -1,     3,     4,
       5,   174,    -1,   176,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,   177,
      -1,    -1,    12,    13,    -1,    60,    -1,    -1,    63,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    -1,    -1,    -1,    75,    76,     6,    78,    79,
      80,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,     7,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   116,   117,   118,   164,
      -1,    -1,    -1,    -1,   169,    -1,     3,     4,    -1,   174,
      -1,   176,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    52,    53,   177,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     8,    -1,    -1,    -1,   168,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   169,    -1,     3,     4,    -1,   174,    -1,   176,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    -1,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     169,    -1,     3,     4,    -1,   174,    -1,   176,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    63,    -1,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     8,    -1,   136,    -1,   168,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,   169,    -1,
       3,     4,    -1,   174,    -1,   176,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,     8,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   169,    -1,     3,     4,
      -1,   174,    -1,   176,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,   136,    -1,   168,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,   169,    -1,     3,     4,     5,   174,
      -1,   176,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    82,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,     4,     5,    51,    52,    53,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,    -1,   174,    -1,   176,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,   164,    -1,    -1,    -1,    -1,   169,    -1,     3,
       4,     5,   174,    -1,   176,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     3,     4,    -1,    51,    52,    53,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,   172,    -1,   174,    -1,   176,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,     3,     4,    -1,    -1,    52,    53,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,   174,
      -1,   176,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,   169,
      -1,     3,     4,    -1,   174,    -1,   176,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    63,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    45,    46,
      47,   143,   144,   145,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,   164,     3,     4,     5,    -1,   169,    -1,     9,
      10,    11,   174,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    53,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,   136,
      -1,    -1,   168,    -1,    -1,    -1,   143,   144,   145,   175,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,   164,    48,    49,    50,    -1,   169,
      -1,    54,    55,    56,   174,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,   110,     4,    -1,
      -1,    -1,   115,   116,   117,   118,    12,    13,   121,    -1,
     123,    -1,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    12,    13,    -1,   103,   104,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,   115,
     116,   117,   118,    -1,    -1,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    -1,    -1,    -1,    84,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   116,   117,
     118,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,    -1,    -1,    -1,    -1,   175,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,   172,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,   172,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     172,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,   172,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,   172,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,   172,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     172,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,   172,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,   172,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,   172,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     172,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,   172,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   172,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,   170,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,   170,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,   170,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,   170,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,   170,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,   170,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,   170,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,   170,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,   170,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,   170,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,   170,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,   170,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,   170,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   180,   181,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    54,    55,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   103,   104,   110,
     115,   116,   117,   118,   121,   123,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   139,   140,   141,
     142,   182,   184,   185,   203,   217,   222,   225,   226,   227,
     228,   229,   230,   231,   251,   252,   253,   254,   270,   271,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    51,    52,    53,
     130,   136,   137,   138,   143,   144,   145,   159,   160,   164,
     169,   171,   173,   174,   176,   178,   255,   256,   267,   268,
     271,    13,    66,   169,   169,     6,   176,     6,     6,     6,
       6,     6,   171,   171,   169,   176,   169,   169,     4,   169,
     176,   169,   169,     4,   176,   169,   169,    70,    66,    66,
       6,   176,    66,    66,    63,    66,    68,    68,    60,    63,
      66,    68,    63,    66,    68,    63,    66,   169,    63,   121,
     134,   135,   176,   159,   160,   169,   176,   257,   258,   257,
     176,    60,    63,    66,   176,   257,     4,    60,    64,    75,
      66,    68,    66,    63,     4,   130,   176,     4,     6,    60,
      63,    66,    63,    66,     4,     4,     4,     5,    36,    60,
      63,    66,    68,    79,   160,   169,   176,   222,   231,   255,
     260,   261,   262,   271,     4,   169,   169,   169,     4,   176,
     264,     4,   169,   169,     6,     6,   171,     4,     4,     5,
     176,     5,   176,     4,   255,     6,   169,   176,   178,     7,
     146,   147,   148,   149,   166,   167,   201,   202,     4,   171,
     173,   169,   171,   169,   171,   169,   171,   169,   171,   169,
     171,   169,   171,   169,   171,   169,   171,   169,   171,   169,
     171,   169,   171,   169,   171,   169,   171,   169,   171,   169,
     171,   169,   171,   169,   171,   169,   171,   169,   171,   169,
     171,   169,   171,   169,   171,   169,   171,   169,   171,   169,
     169,   169,   169,   169,   169,   169,     7,   169,   169,   169,
     255,   255,   255,   176,   255,   172,   176,   255,     4,   121,
     122,     4,     4,   222,   223,   224,   176,     6,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   168,   176,     6,   202,     6,   255,     4,   267,
     268,   271,   267,   255,   205,   208,   255,   160,   255,   262,
     263,   255,   255,   169,   255,   263,   255,   255,   169,   263,
     255,   255,   260,   169,   176,   263,   169,   169,   261,   261,
     261,   169,   218,   219,   220,   221,   169,   169,   169,   260,
     255,     4,   260,   264,   176,   176,   257,   257,   257,   255,
     255,   159,   160,   176,   176,   257,   176,   176,   176,   159,
     160,   169,   224,   257,   176,   169,   176,   169,   169,   169,
     261,   261,   260,   169,     4,     6,   171,   171,   224,     6,
     176,   176,   176,   261,   261,   171,   171,   169,   171,   173,
     171,     5,   176,     5,     5,     5,    60,    63,    66,    68,
     176,   255,   262,   255,   177,   263,     8,   161,     6,     6,
     255,   255,   255,   173,   255,   176,   124,   255,   255,   255,
       6,     6,   224,     6,   224,   171,     6,   260,   260,   176,
     268,   260,     6,   171,   255,     4,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     267,   269,   269,   267,   267,   267,   267,   267,   267,   267,
     267,   269,   255,   267,   267,   267,   263,   170,     7,   201,
     263,   172,     7,   201,   202,   173,     7,   171,   177,    60,
      63,    66,    68,   217,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     186,     6,   171,   173,   170,   175,   170,   175,   175,   172,
     175,   204,   172,   204,   170,   161,   175,   177,   170,   170,
     255,   170,   177,   170,   170,   255,   177,   170,   170,     7,
     255,   255,   177,   255,   255,     7,     7,   249,   249,   255,
     169,   169,   169,   169,   255,   255,   255,     7,   176,   170,
       6,   176,   224,   224,   175,   175,   175,   257,   257,   223,
     223,   175,   255,   255,   255,   255,   235,   175,   224,   255,
     255,   255,   255,   255,     7,   250,     6,     7,   255,     6,
     255,   255,   177,   263,   263,   263,     6,     6,   255,   255,
     170,   176,   172,   176,   255,     4,     4,   255,   176,   176,
     176,   176,   263,   170,   177,   255,   176,   255,   262,   170,
     170,   170,   121,   175,   224,   176,     8,   170,   172,   177,
     177,   170,   175,   177,   255,     6,     6,   255,   172,   202,
     170,   172,   170,   172,   170,   172,   170,   172,   170,   172,
     170,   172,   170,   172,   170,   172,   170,   172,   170,   172,
     170,   172,   175,   175,   170,   172,   170,   172,   170,   172,
     170,   172,   170,   172,   170,   172,   170,   172,   175,   175,
     175,   175,   175,   175,   170,   175,   172,   170,   175,   172,
     175,   175,   170,   170,   175,   175,   175,   170,     6,   175,
     170,   175,   177,   201,   260,   177,   173,   201,   202,   268,
     255,     6,     4,     4,   176,   265,   172,   176,   176,   176,
     176,   177,     8,     4,   111,   112,   113,   114,   177,   189,
     193,   196,   198,   199,   255,     4,     6,   156,   183,   263,
       6,   263,   255,     6,     4,   271,     6,   267,     7,   255,
     262,   124,     7,     7,   170,     7,   124,     7,     7,   170,
     124,     7,     7,   255,   170,   177,   176,   170,   170,   255,
     260,     4,   248,     6,   170,   214,   255,   268,   214,   214,
     214,   170,   170,   170,   260,   263,   173,   224,   177,   177,
     257,   255,   255,   177,   177,   255,   257,   175,   175,   175,
      82,    92,   100,   101,   102,   105,   106,   107,   108,   245,
     246,   257,   177,   232,   170,   177,   170,   170,   170,   255,
       6,   255,   170,   172,   172,   177,   177,   177,   172,   172,
     263,   263,   172,   172,   177,   263,   263,   263,   263,   177,
       8,   263,     7,     7,     7,   173,   255,   177,   255,   255,
       7,   173,   176,   260,     6,   177,   172,   173,   202,   267,
     255,   255,   255,   255,   255,   255,   255,   255,   267,   263,
     263,   267,   267,   267,   267,   255,   267,   170,   255,     6,
     172,     4,   121,   122,   255,     6,     6,     6,     7,   171,
     264,   266,     6,   263,   263,   263,   263,   255,   190,   169,
     169,   176,   200,     6,   172,   156,   267,   170,   170,   175,
       7,   257,    66,    68,   260,   260,     7,   260,    66,    68,
     260,   260,     7,    68,   260,   260,     6,     7,     7,   263,
       7,     7,    82,   247,     6,     7,   170,   170,   170,   170,
       7,     7,     7,     6,   177,     4,   177,   175,   175,   175,
     177,   177,   257,   257,   257,     4,     6,   176,     6,   169,
       6,   109,     6,   109,     6,   109,     6,   109,   177,   246,
     175,   245,     7,     6,     7,     7,     7,     6,   176,     6,
       6,     6,    66,   255,     6,     6,   177,   177,   173,   177,
     177,   177,   177,   255,   177,   260,   260,   260,     4,   175,
       8,     8,   170,     4,     4,   260,   177,     6,     4,     6,
     170,   172,   170,   172,   170,   172,   170,   172,   170,   172,
     170,   175,   170,   170,   170,   170,   201,     6,   201,     7,
     201,   202,   173,     7,     6,   264,   255,   175,   177,   177,
     177,   177,   177,   169,   255,   255,   259,   260,   176,   173,
       6,     6,   183,     6,   255,   176,   255,   268,     6,   176,
     176,    75,   216,   216,   260,     6,   176,   176,     6,     6,
     260,   176,     6,     6,     5,   260,   177,   260,   260,     4,
       6,   260,     7,     7,     7,     7,   260,   260,   260,     7,
       6,     7,   255,   255,   255,   176,   176,   175,   177,   175,
     177,   175,   177,   171,   255,   260,   255,     6,     6,     6,
       6,   255,   257,   177,     5,   176,   260,   176,   176,   176,
     260,   263,   176,     6,   170,   172,     4,     6,     6,   120,
     255,   255,   255,     6,     6,     7,   175,     6,   202,   267,
     260,   260,   268,   255,     6,     4,   265,     6,   172,   264,
       6,     6,     6,     6,   187,   255,   175,   175,   175,   177,
     188,   255,     4,   267,   175,   255,   268,   255,   255,   257,
       6,     6,     6,   255,   255,     6,   255,     5,     6,   176,
       6,   124,   215,   255,     6,   260,   260,   260,   260,     6,
       4,     6,     6,   255,   255,   268,   177,   170,   175,   177,
     223,   223,   257,     6,   236,   257,     6,   237,   257,     6,
     238,   255,   177,   175,   170,   177,   175,     6,   160,   257,
       6,   259,   257,   257,     6,   177,   255,   260,   175,   177,
       8,   177,   170,   176,   255,   268,   260,   170,     6,     6,
       6,     6,     7,     6,   173,   170,   175,   255,   255,   260,
     176,   175,   177,     6,   255,   206,   207,   177,   177,   177,
     177,   177,     5,   259,    64,     6,     6,     6,     6,     6,
     176,   176,     6,     6,   176,   255,   177,   177,   175,   176,
     175,   176,   175,   176,   172,     6,   260,     7,   176,   255,
     175,   177,   175,   175,     6,   177,   119,   255,   255,   263,
       6,     6,   177,   264,   122,   191,   255,   175,   175,   259,
     255,     6,   175,   210,   212,     6,     6,     6,     6,     6,
       6,   177,   176,   259,   263,   223,   175,   177,   255,   257,
     245,   255,   257,   245,   255,   257,   245,     6,   175,   177,
     260,   224,   177,   257,     6,   263,   257,   255,   177,   177,
     177,     6,     6,   176,   255,   255,   177,   255,   175,   177,
     211,   175,   177,   213,   176,   255,   177,   177,   177,   255,
     177,   175,   177,   177,   175,   177,   177,   175,   177,   260,
       6,    82,   177,   233,   176,   175,   177,   175,     6,     6,
     188,   170,   175,     6,   176,   175,     4,     4,   255,   177,
       6,     6,   177,     6,   239,   255,     6,     6,   240,   255,
       6,     6,   241,   255,     6,   177,   255,   245,   224,   263,
       6,   257,   263,   177,   194,   255,   259,   255,   176,   260,
     268,   176,   255,   268,   175,   176,   177,   176,   177,   176,
     177,     6,     6,   177,   177,   234,   177,   175,   177,     6,
     176,   170,   177,   177,   209,   255,   269,   255,   245,     6,
     242,   245,     6,   243,   245,     6,   244,   245,     6,   263,
       6,   192,   267,   197,   176,     6,   175,   177,     7,   177,
     177,   177,   176,   177,   176,   177,   176,   177,   177,   175,
     177,   176,   259,   255,   268,     6,     6,   245,     6,   245,
       6,   245,     6,   267,     6,   195,   267,   177,     7,   177,
     177,   177,   175,   177,     6,   268,     6,     6,     6,   267,
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
#line 172 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 187 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 191 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 195 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 196 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 197 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 202 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 206 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 213 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 218 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 223 "Gmsh.y"
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
    ;}
    break;

  case 26:
#line 237 "Gmsh.y"
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
    ;}
    break;

  case 27:
#line 250 "Gmsh.y"
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
    ;}
    break;

  case 28:
#line 263 "Gmsh.y"
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
    ;}
    break;

  case 29:
#line 291 "Gmsh.y"
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
#line 305 "Gmsh.y"
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
#line 316 "Gmsh.y"
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
#line 330 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:
#line 344 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:
#line 346 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:
#line 351 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:
#line 353 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:
#line 358 "Gmsh.y"
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
#line 462 "Gmsh.y"
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
#line 472 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:
#line 481 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:
#line 488 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:
#line 498 "Gmsh.y"
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
#line 507 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:
#line 516 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:
#line 523 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:
#line 533 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 52:
#line 541 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:
#line 551 "Gmsh.y"
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
#line 570 "Gmsh.y"
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
#line 589 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:
#line 595 "Gmsh.y"
    {
    ;}
    break;

  case 57:
#line 602 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:
#line 603 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:
#line 604 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:
#line 605 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:
#line 606 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:
#line 610 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:
#line 611 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:
#line 622 "Gmsh.y"
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
    ;}
    break;

  case 67:
#line 684 "Gmsh.y"
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
    ;}
    break;

  case 68:
#line 714 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
          s.list = true;
	  s.value.resize(index + 1, 0.);
	  s.value[index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
        if(s.list){
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch((yyvsp[(5) - (7)].i)){
          case 0 : s.value[index] = (yyvsp[(6) - (7)].d); break;
          case 1 : s.value[index] += (yyvsp[(6) - (7)].d); break;
          case 2 : s.value[index] -= (yyvsp[(6) - (7)].d); break;
          case 3 : s.value[index] *= (yyvsp[(6) - (7)].d); break;
          case 4 :
            if((yyvsp[(6) - (7)].d)) s.value[index] /= (yyvsp[(6) - (7)].d);
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
            break;
          }
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 69:
#line 749 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
          s.list = true;
	  s.value.resize(index + 1, 0.);
	  s.value[index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
        if(s.list){
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch((yyvsp[(5) - (7)].i)){
          case 0 : s.value[index] = (yyvsp[(6) - (7)].d); break;
          case 1 : s.value[index] += (yyvsp[(6) - (7)].d); break;
          case 2 : s.value[index] -= (yyvsp[(6) - (7)].d); break;
          case 3 : s.value[index] *= (yyvsp[(6) - (7)].d); break;
          case 4 :
            if((yyvsp[(6) - (7)].d)) s.value[index] /= (yyvsp[(6) - (7)].d);
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
            break;
          }
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 70:
#line 783 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
            gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
            s.list = true;
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      s.value.resize(index + 1, 0.);
	      s.value[index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
          if(s.list){
            for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
              int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
              double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
              if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
              switch((yyvsp[(7) - (9)].i)){
              case 0 : s.value[index] = d; break;
              case 1 : s.value[index] += d; break;
              case 2 : s.value[index] -= d; break;
              case 3 : s.value[index] *= d; break;
              case 4 :
                if((yyvsp[(8) - (9)].l)) s.value[index] /= d;
                else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
                break;
              }
            }
          }
          else
            yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (9)].c));
        }
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 71:
#line 831 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
            gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
            s.list = true;
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      s.value.resize(index + 1, 0.);
	      s.value[index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
          if(s.list){
            for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
              int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
              double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
              if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
              switch((yyvsp[(7) - (9)].i)){
              case 0 : s.value[index] = d; break;
              case 1 : s.value[index] += d; break;
              case 2 : s.value[index] -= d; break;
              case 3 : s.value[index] *= d; break;
              case 4 :
                if((yyvsp[(8) - (9)].l)) s.value[index] /= d;
                else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
                break;
              }
            }
          }
          else
            yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (9)].c));
        }
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 72:
#line 878 "Gmsh.y"
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
    ;}
    break;

  case 73:
#line 893 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
        if(s.list){
          int index = (int)(yyvsp[(3) - (6)].d);
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          s.value[index] += (yyvsp[(5) - (6)].i);
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (6)].c));
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 74:
#line 909 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 75:
#line 918 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 76:
#line 924 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 77:
#line 933 "Gmsh.y"
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

  case 78:
#line 951 "Gmsh.y"
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

  case 79:
#line 969 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 80:
#line 978 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 81:
#line 990 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 82:
#line 995 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 83:
#line 1003 "Gmsh.y"
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

  case 84:
#line 1023 "Gmsh.y"
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

  case 85:
#line 1046 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[(4) - (5)].d));
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[(4) - (5)].d));
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 86:
#line 1057 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 87:
#line 1065 "Gmsh.y"
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

  case 88:
#line 1087 "Gmsh.y"
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
    ;}
    break;

  case 89:
#line 1110 "Gmsh.y"
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
    ;}
    break;

  case 90:
#line 1136 "Gmsh.y"
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
    ;}
    break;

  case 91:
#line 1157 "Gmsh.y"
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

  case 92:
#line 1169 "Gmsh.y"
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

  case 96:
#line 1187 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 97:
#line 1198 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 98:
#line 1209 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 99:
#line 1211 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
    ;}
    break;

  case 100:
#line 1221 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 101:
#line 1232 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 102:
#line 1234 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 104:
#line 1248 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 105:
#line 1256 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 106:
#line 1262 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 109:
#line 1274 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
        double v;
        List_Read((yyvsp[(3) - (3)].l), i, &v);
        floatOptions[key].push_back(v);
      }
      Free((yyvsp[(2) - (3)].c));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 110:
#line 1285 "Gmsh.y"
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
    ;}
    break;

  case 111:
#line 1300 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 114:
#line 1316 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 115:
#line 1324 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 116:
#line 1333 "Gmsh.y"
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
    ;}
    break;

  case 117:
#line 1351 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 118:
#line 1355 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 119:
#line 1365 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 120:
#line 1369 "Gmsh.y"
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

  case 121:
#line 1381 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 122:
#line 1385 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 123:
#line 1395 "Gmsh.y"
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

  case 124:
#line 1418 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 125:
#line 1422 "Gmsh.y"
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

  case 126:
#line 1438 "Gmsh.y"
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

  case 127:
#line 1460 "Gmsh.y"
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

  case 128:
#line 1478 "Gmsh.y"
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

  case 129:
#line 1499 "Gmsh.y"
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

  case 130:
#line 1517 "Gmsh.y"
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

  case 131:
#line 1547 "Gmsh.y"
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

  case 132:
#line 1577 "Gmsh.y"
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

  case 133:
#line 1595 "Gmsh.y"
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

  case 134:
#line 1613 "Gmsh.y"
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

  case 135:
#line 1639 "Gmsh.y"
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
    ;}
    break;

  case 136:
#line 1657 "Gmsh.y"
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

  case 137:
#line 1675 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 138:
#line 1679 "Gmsh.y"
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

  case 139:
#line 1698 "Gmsh.y"
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

  case 140:
#line 1716 "Gmsh.y"
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

  case 141:
#line 1755 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:
#line 1761 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1767 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 144:
#line 1774 "Gmsh.y"
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

  case 145:
#line 1799 "Gmsh.y"
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

  case 146:
#line 1824 "Gmsh.y"
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
    ;}
    break;

  case 147:
#line 1841 "Gmsh.y"
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
    ;}
    break;

  case 148:
#line 1861 "Gmsh.y"
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
    ;}
    break;

  case 149:
#line 1894 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 150:
#line 1898 "Gmsh.y"
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

  case 151:
#line 1918 "Gmsh.y"
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

  case 152:
#line 1936 "Gmsh.y"
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

  case 153:
#line 1953 "Gmsh.y"
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

  case 154:
#line 1969 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 155:
#line 1973 "Gmsh.y"
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

  case 156:
#line 1995 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:
#line 2000 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 158:
#line 2005 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:
#line 2010 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:
#line 2015 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2020 "Gmsh.y"
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

  case 162:
#line 2043 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 163:
#line 2049 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 164:
#line 2059 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:
#line 2060 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2065 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 167:
#line 2069 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 168:
#line 2073 "Gmsh.y"
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

  case 169:
#line 2096 "Gmsh.y"
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

  case 170:
#line 2119 "Gmsh.y"
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

  case 171:
#line 2142 "Gmsh.y"
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

  case 172:
#line 2170 "Gmsh.y"
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

  case 173:
#line 2191 "Gmsh.y"
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
    ;}
    break;

  case 174:
#line 2218 "Gmsh.y"
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

  case 175:
#line 2239 "Gmsh.y"
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

  case 176:
#line 2260 "Gmsh.y"
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

  case 177:
#line 2280 "Gmsh.y"
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
    ;}
    break;

  case 178:
#line 2392 "Gmsh.y"
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

  case 179:
#line 2411 "Gmsh.y"
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
    ;}
    break;

  case 180:
#line 2450 "Gmsh.y"
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

  case 181:
#line 2558 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 182:
#line 2567 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:
#line 2573 "Gmsh.y"
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

  case 184:
#line 2588 "Gmsh.y"
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

  case 185:
#line 2616 "Gmsh.y"
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

  case 186:
#line 2633 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 187:
#line 2642 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 188:
#line 2656 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:
#line 2662 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2668 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 191:
#line 2677 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 192:
#line 2686 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 193:
#line 2695 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 194:
#line 2709 "Gmsh.y"
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "NonBlockingSystemCall"))
	SystemCall((yyvsp[(2) - (3)].c));
      else if(!strcmp((yyvsp[(1) - (3)].c), "System") || !strcmp((yyvsp[(1) - (3)].c), "SystemCall"))
	SystemCall((yyvsp[(2) - (3)].c), true);
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 195:
#line 2754 "Gmsh.y"
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

  case 196:
#line 2771 "Gmsh.y"
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

  case 197:
#line 2786 "Gmsh.y"
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

  case 198:
#line 2805 "Gmsh.y"
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

  case 199:
#line 2817 "Gmsh.y"
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

  case 200:
#line 2841 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 201:
#line 2845 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 202:
#line 2850 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 203:
#line 2857 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 204:
#line 2863 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 205:
#line 2868 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 206:
#line 2874 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 207:
#line 2882 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 208:
#line 2886 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 209:
#line 2890 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 210:
#line 2896 "Gmsh.y"
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
    ;}
    break;

  case 211:
#line 2950 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 212:
#line 2963 "Gmsh.y"
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

  case 213:
#line 2980 "Gmsh.y"
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

  case 214:
#line 2997 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
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

  case 215:
#line 3018 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
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

  case 216:
#line 3039 "Gmsh.y"
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
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 217:
#line 3074 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 218:
#line 3082 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 219:
#line 3088 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 220:
#line 3095 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 221:
#line 3099 "Gmsh.y"
    {
    ;}
    break;

  case 222:
#line 3108 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 223:
#line 3116 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 224:
#line 3124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 225:
#line 3132 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 226:
#line 3138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 227:
#line 3146 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 228:
#line 3152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 229:
#line 3160 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 230:
#line 3166 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 231:
#line 3174 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 232:
#line 3180 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 233:
#line 3188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 234:
#line 3195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3216 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3237 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3244 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 242:
#line 3251 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 243:
#line 3257 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 244:
#line 3264 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 245:
#line 3270 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 246:
#line 3277 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 247:
#line 3283 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 248:
#line 3290 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 249:
#line 3296 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 250:
#line 3303 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 251:
#line 3309 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 252:
#line 3316 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 253:
#line 3322 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 254:
#line 3329 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 255:
#line 3335 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 256:
#line 3342 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 257:
#line 3348 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 258:
#line 3355 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 259:
#line 3361 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 260:
#line 3372 "Gmsh.y"
    {
    ;}
    break;

  case 261:
#line 3375 "Gmsh.y"
    {
    ;}
    break;

  case 262:
#line 3381 "Gmsh.y"
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
    ;}
    break;

  case 263:
#line 3393 "Gmsh.y"
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

  case 264:
#line 3413 "Gmsh.y"
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

  case 265:
#line 3437 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 266:
#line 3442 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 267:
#line 3446 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 268:
#line 3450 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 269:
#line 3454 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 270:
#line 3458 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 271:
#line 3462 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 272:
#line 3466 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 273:
#line 3470 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 274:
#line 3474 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 275:
#line 3478 "Gmsh.y"
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

  case 276:
#line 3497 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 277:
#line 3509 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 278:
#line 3513 "Gmsh.y"
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

  case 279:
#line 3528 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 280:
#line 3532 "Gmsh.y"
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
    ;}
    break;

  case 281:
#line 3548 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 282:
#line 3552 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 283:
#line 3557 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 284:
#line 3561 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 285:
#line 3568 "Gmsh.y"
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
    ;}
    break;

  case 286:
#line 3624 "Gmsh.y"
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
    ;}
    break;

  case 287:
#line 3694 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 288:
#line 3699 "Gmsh.y"
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
    ;}
    break;

  case 289:
#line 3766 "Gmsh.y"
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
    ;}
    break;

  case 290:
#line 3802 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 291:
#line 3810 "Gmsh.y"
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

  case 292:
#line 3853 "Gmsh.y"
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
    ;}
    break;

  case 293:
#line 3892 "Gmsh.y"
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

  case 294:
#line 3912 "Gmsh.y"
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
    ;}
    break;

  case 295:
#line 3940 "Gmsh.y"
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
    ;}
    break;

  case 296:
#line 3979 "Gmsh.y"
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

  case 297:
#line 4002 "Gmsh.y"
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

  case 298:
#line 4025 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 299:
#line 4029 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 300:
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
    ;}
    break;

  case 301:
#line 4056 "Gmsh.y"
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
    ;}
    break;

  case 302:
#line 4095 "Gmsh.y"
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
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 303:
#line 4140 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 304:
#line 4144 "Gmsh.y"
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

  case 305:
#line 4154 "Gmsh.y"
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
    ;}
    break;

  case 306:
#line 4188 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 307:
#line 4189 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 308:
#line 4190 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 309:
#line 4195 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 310:
#line 4201 "Gmsh.y"
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
    ;}
    break;

  case 311:
#line 4213 "Gmsh.y"
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
    ;}
    break;

  case 312:
#line 4231 "Gmsh.y"
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
    ;}
    break;

  case 313:
#line 4258 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 314:
#line 4259 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 315:
#line 4260 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 316:
#line 4261 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 317:
#line 4262 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 318:
#line 4263 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 319:
#line 4264 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 320:
#line 4265 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 321:
#line 4267 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 322:
#line 4273 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 323:
#line 4274 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 324:
#line 4275 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 325:
#line 4276 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 326:
#line 4277 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 327:
#line 4278 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 328:
#line 4279 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 329:
#line 4280 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 330:
#line 4281 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 331:
#line 4282 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 332:
#line 4283 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 333:
#line 4284 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 334:
#line 4285 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 335:
#line 4286 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 336:
#line 4287 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:
#line 4288 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 338:
#line 4289 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:
#line 4290 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 340:
#line 4291 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:
#line 4292 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:
#line 4293 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:
#line 4294 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 344:
#line 4295 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:
#line 4296 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 346:
#line 4297 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4298 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 348:
#line 4299 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 349:
#line 4300 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:
#line 4301 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 351:
#line 4302 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 352:
#line 4303 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 353:
#line 4304 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 354:
#line 4305 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 355:
#line 4308 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 356:
#line 4309 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 357:
#line 4310 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 358:
#line 4311 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 359:
#line 4312 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 360:
#line 4313 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 361:
#line 4314 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 362:
#line 4315 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 363:
#line 4316 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 364:
#line 4317 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 365:
#line 4318 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 366:
#line 4319 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 367:
#line 4320 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 368:
#line 4321 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 369:
#line 4322 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 370:
#line 4323 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 371:
#line 4324 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 372:
#line 4325 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5);    ;}
    break;

  case 373:
#line 4326 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 374:
#line 4327 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 375:
#line 4328 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 376:
#line 4329 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 377:
#line 4338 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 378:
#line 4339 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 379:
#line 4340 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 380:
#line 4341 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 381:
#line 4342 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 382:
#line 4343 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 383:
#line 4344 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 384:
#line 4345 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 385:
#line 4346 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 386:
#line 4351 "Gmsh.y"
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
    ;}
    break;

  case 387:
#line 4369 "Gmsh.y"
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
    ;}
    break;

  case 388:
#line 4387 "Gmsh.y"
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
    ;}
    break;

  case 389:
#line 4399 "Gmsh.y"
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
    ;}
    break;

  case 390:
#line 4416 "Gmsh.y"
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
    ;}
    break;

  case 391:
#line 4437 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 392:
#line 4442 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 393:
#line 4447 "Gmsh.y"
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

  case 394:
#line 4457 "Gmsh.y"
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

  case 395:
#line 4467 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 396:
#line 4472 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 397:
#line 4481 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 398:
#line 4486 "Gmsh.y"
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
    ;}
    break;

  case 399:
#line 4513 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 400:
#line 4517 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 401:
#line 4521 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 402:
#line 4525 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 403:
#line 4529 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 404:
#line 4536 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 405:
#line 4540 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 406:
#line 4544 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 407:
#line 4548 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 408:
#line 4555 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 409:
#line 4560 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 410:
#line 4567 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 411:
#line 4572 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 412:
#line 4576 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 413:
#line 4581 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 414:
#line 4585 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 415:
#line 4593 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 416:
#line 4604 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 417:
#line 4608 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 418:
#line 4620 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 419:
#line 4628 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 420:
#line 4636 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 421:
#line 4643 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 422:
#line 4653 "Gmsh.y"
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

  case 423:
#line 4673 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 424:
#line 4677 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 425:
#line 4681 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 426:
#line 4685 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 427:
#line 4689 "Gmsh.y"
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
    ;}
    break;

  case 428:
#line 4718 "Gmsh.y"
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
    ;}
    break;

  case 429:
#line 4747 "Gmsh.y"
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
    ;}
    break;

  case 430:
#line 4776 "Gmsh.y"
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
    ;}
    break;

  case 431:
#line 4805 "Gmsh.y"
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

  case 432:
#line 4815 "Gmsh.y"
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

  case 433:
#line 4825 "Gmsh.y"
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
    ;}
    break;

  case 434:
#line 4838 "Gmsh.y"
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
    ;}
    break;

  case 435:
#line 4850 "Gmsh.y"
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
    ;}
    break;

  case 436:
#line 4862 "Gmsh.y"
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
    ;}
    break;

  case 437:
#line 4881 "Gmsh.y"
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
    ;}
    break;

  case 438:
#line 4902 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 439:
#line 4907 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 440:
#line 4911 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 441:
#line 4915 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 442:
#line 4927 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 443:
#line 4931 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 444:
#line 4943 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 445:
#line 4950 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 446:
#line 4960 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 447:
#line 4964 "Gmsh.y"
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

  case 448:
#line 4979 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 449:
#line 4984 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 450:
#line 4991 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 451:
#line 4995 "Gmsh.y"
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

  case 452:
#line 5008 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 453:
#line 5016 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 454:
#line 5027 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 455:
#line 5031 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 456:
#line 5039 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 457:
#line 5047 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 458:
#line 5055 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 459:
#line 5063 "Gmsh.y"
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

  case 460:
#line 5077 "Gmsh.y"
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

  case 461:
#line 5091 "Gmsh.y"
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
    ;}
    break;

  case 462:
#line 5103 "Gmsh.y"
    {
      int size = 0;
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
    ;}
    break;

  case 463:
#line 5120 "Gmsh.y"
    {
      int size = 0;
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
    ;}
    break;

  case 464:
#line 5136 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 465:
#line 5141 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 466:
#line 5145 "Gmsh.y"
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
    ;}
    break;

  case 467:
#line 5165 "Gmsh.y"
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
    ;}
    break;

  case 468:
#line 5187 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 469:
#line 5192 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 470:
#line 5198 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 471:
#line 5207 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 472:
#line 5220 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 473:
#line 5223 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10730 "Gmsh.tab.cpp"
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


#line 5227 "Gmsh.y"


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

