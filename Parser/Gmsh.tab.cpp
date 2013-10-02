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
     tCopyOptions = 360,
     tQuadTriAddVerts = 361,
     tQuadTriNoNewVerts = 362,
     tQuadTriSngl = 363,
     tQuadTriDbl = 364,
     tRecombLaterals = 365,
     tTransfQuadTri = 366,
     tText2D = 367,
     tText3D = 368,
     tInterpolationScheme = 369,
     tTime = 370,
     tCombine = 371,
     tBSpline = 372,
     tBezier = 373,
     tNurbs = 374,
     tNurbsOrder = 375,
     tNurbsKnots = 376,
     tColor = 377,
     tColorTable = 378,
     tFor = 379,
     tIn = 380,
     tEndFor = 381,
     tIf = 382,
     tEndIf = 383,
     tExit = 384,
     tAbort = 385,
     tField = 386,
     tReturn = 387,
     tCall = 388,
     tFunction = 389,
     tShow = 390,
     tHide = 391,
     tGetValue = 392,
     tGetEnv = 393,
     tGetString = 394,
     tHomology = 395,
     tCohomology = 396,
     tBetti = 397,
     tSetOrder = 398,
     tGMSH_MAJOR_VERSION = 399,
     tGMSH_MINOR_VERSION = 400,
     tGMSH_PATCH_VERSION = 401,
     tAFFECTDIVIDE = 402,
     tAFFECTTIMES = 403,
     tAFFECTMINUS = 404,
     tAFFECTPLUS = 405,
     tOR = 406,
     tAND = 407,
     tNOTEQUAL = 408,
     tEQUAL = 409,
     tGREATEROREQUAL = 410,
     tLESSOREQUAL = 411,
     UNARYPREC = 412,
     tMINUSMINUS = 413,
     tPLUSPLUS = 414
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
#define tCopyOptions 360
#define tQuadTriAddVerts 361
#define tQuadTriNoNewVerts 362
#define tQuadTriSngl 363
#define tQuadTriDbl 364
#define tRecombLaterals 365
#define tTransfQuadTri 366
#define tText2D 367
#define tText3D 368
#define tInterpolationScheme 369
#define tTime 370
#define tCombine 371
#define tBSpline 372
#define tBezier 373
#define tNurbs 374
#define tNurbsOrder 375
#define tNurbsKnots 376
#define tColor 377
#define tColorTable 378
#define tFor 379
#define tIn 380
#define tEndFor 381
#define tIf 382
#define tEndIf 383
#define tExit 384
#define tAbort 385
#define tField 386
#define tReturn 387
#define tCall 388
#define tFunction 389
#define tShow 390
#define tHide 391
#define tGetValue 392
#define tGetEnv 393
#define tGetString 394
#define tHomology 395
#define tCohomology 396
#define tBetti 397
#define tSetOrder 398
#define tGMSH_MAJOR_VERSION 399
#define tGMSH_MINOR_VERSION 400
#define tGMSH_PATCH_VERSION 401
#define tAFFECTDIVIDE 402
#define tAFFECTTIMES 403
#define tAFFECTMINUS 404
#define tAFFECTPLUS 405
#define tOR 406
#define tAND 407
#define tNOTEQUAL 408
#define tEQUAL 409
#define tGREATEROREQUAL 410
#define tLESSOREQUAL 411
#define UNARYPREC 412
#define tMINUSMINUS 413
#define tPLUSPLUS 414




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
#line 524 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 537 "Gmsh.tab.cpp"

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
#define YYLAST   8862

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  180
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  474
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1649

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   414

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   165,     2,   175,     2,   164,     2,     2,
     170,   171,   162,   160,   176,   161,   174,   163,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     156,     2,   157,   151,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   172,     2,   173,   169,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   177,     2,   178,   179,     2,     2,     2,
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
     145,   146,   147,   148,   149,   150,   152,   153,   154,   155,
     158,   159,   166,   167,   168
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
     244,   246,   248,   250,   252,   254,   260,   266,   271,   278,
     286,   294,   304,   314,   318,   325,   330,   337,   347,   354,
     364,   370,   379,   388,   400,   407,   417,   423,   431,   441,
     451,   463,   471,   481,   491,   492,   494,   495,   499,   505,
     506,   516,   522,   523,   533,   534,   538,   542,   548,   549,
     552,   556,   562,   566,   567,   570,   574,   578,   584,   586,
     588,   589,   595,   596,   599,   607,   608,   618,   625,   633,
     638,   646,   655,   664,   672,   680,   692,   701,   710,   711,
     721,   730,   740,   744,   749,   760,   768,   776,   785,   794,
     807,   808,   818,   827,   835,   844,   845,   855,   861,   873,
     879,   889,   899,   904,   914,   924,   926,   928,   929,   932,
     939,   946,   953,   960,   969,   980,   995,  1012,  1025,  1034,
    1043,  1050,  1065,  1070,  1077,  1084,  1088,  1093,  1099,  1106,
    1110,  1114,  1119,  1125,  1130,  1136,  1140,  1148,  1156,  1160,
    1168,  1172,  1175,  1178,  1181,  1184,  1200,  1203,  1206,  1209,
    1212,  1215,  1232,  1236,  1243,  1252,  1261,  1272,  1274,  1277,
    1279,  1283,  1288,  1290,  1296,  1308,  1322,  1323,  1331,  1332,
    1346,  1347,  1363,  1364,  1371,  1380,  1389,  1398,  1411,  1424,
    1437,  1452,  1467,  1482,  1483,  1496,  1497,  1510,  1511,  1524,
    1525,  1542,  1543,  1560,  1561,  1578,  1579,  1598,  1599,  1618,
    1619,  1638,  1640,  1643,  1649,  1657,  1667,  1670,  1673,  1676,
    1680,  1683,  1687,  1690,  1694,  1697,  1701,  1711,  1718,  1719,
    1723,  1724,  1726,  1727,  1730,  1731,  1734,  1742,  1749,  1758,
    1764,  1768,  1776,  1782,  1787,  1794,  1801,  1814,  1825,  1836,
    1847,  1858,  1869,  1874,  1879,  1882,  1886,  1893,  1895,  1897,
    1899,  1902,  1908,  1916,  1927,  1929,  1933,  1936,  1939,  1942,
    1946,  1950,  1954,  1958,  1962,  1966,  1970,  1974,  1978,  1982,
    1986,  1990,  1994,  1998,  2004,  2009,  2014,  2019,  2024,  2029,
    2034,  2039,  2044,  2049,  2054,  2061,  2066,  2071,  2076,  2081,
    2086,  2091,  2096,  2103,  2110,  2117,  2122,  2127,  2132,  2137,
    2142,  2147,  2152,  2157,  2162,  2167,  2172,  2179,  2184,  2189,
    2194,  2199,  2204,  2209,  2214,  2221,  2228,  2235,  2240,  2242,
    2244,  2246,  2248,  2250,  2252,  2254,  2256,  2258,  2260,  2265,
    2270,  2273,  2279,  2283,  2290,  2295,  2303,  2310,  2317,  2324,
    2329,  2331,  2334,  2337,  2341,  2345,  2357,  2367,  2375,  2383,
    2385,  2389,  2391,  2393,  2396,  2400,  2405,  2411,  2413,  2415,
    2418,  2422,  2426,  2432,  2437,  2440,  2443,  2446,  2449,  2455,
    2461,  2467,  2473,  2475,  2477,  2481,  2485,  2490,  2497,  2504,
    2506,  2508,  2512,  2516,  2526,  2534,  2536,  2542,  2546,  2553,
    2555,  2559,  2561,  2563,  2567,  2574,  2576,  2578,  2583,  2590,
    2597,  2602,  2607,  2616,  2621,  2626,  2631,  2636,  2643,  2650,
    2652,  2656,  2662,  2668,  2670
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     181,     0,    -1,   182,    -1,     1,     6,    -1,    -1,   182,
     183,    -1,   186,    -1,   185,    -1,   204,    -1,   218,    -1,
     223,    -1,   227,    -1,   228,    -1,   229,    -1,   232,    -1,
     252,    -1,   253,    -1,   231,    -1,   230,    -1,   226,    -1,
     255,    -1,   157,    -1,   157,   157,    -1,    37,   170,   268,
     171,     6,    -1,    38,   170,   268,   171,     6,    -1,    37,
     170,   268,   171,   184,   268,     6,    -1,    37,   170,   268,
     176,   264,   171,     6,    -1,    38,   170,   268,   176,   264,
     171,     6,    -1,    37,   170,   268,   176,   264,   171,   184,
     268,     6,    -1,     4,   268,   177,   187,   178,     6,    -1,
     103,     4,   172,   256,   173,     6,    -1,   104,     4,   172,
     256,   173,     6,    -1,   105,     4,   172,   256,   176,   256,
     173,     6,    -1,    -1,   187,   190,    -1,   187,   194,    -1,
     187,   197,    -1,   187,   199,    -1,   187,   200,    -1,   256,
      -1,   188,   176,   256,    -1,   256,    -1,   189,   176,   256,
      -1,    -1,    -1,     4,   191,   170,   188,   171,   192,   177,
     189,   178,     6,    -1,   268,    -1,   193,   176,   268,    -1,
      -1,   112,   170,   256,   176,   256,   176,   256,   171,   195,
     177,   193,   178,     6,    -1,   268,    -1,   196,   176,   268,
      -1,    -1,   113,   170,   256,   176,   256,   176,   256,   176,
     256,   171,   198,   177,   196,   178,     6,    -1,   114,   177,
     260,   178,   177,   260,   178,     6,    -1,   114,   177,   260,
     178,   177,   260,   178,   177,   260,   178,   177,   260,   178,
       6,    -1,    -1,   115,   201,   177,   189,   178,     6,    -1,
       7,    -1,   150,    -1,   149,    -1,   148,    -1,   147,    -1,
     168,    -1,   167,    -1,    58,   172,   206,   173,     6,    -1,
      59,   172,   209,   173,     6,    -1,   272,   202,   261,     6,
      -1,     4,   172,   173,   202,   261,     6,    -1,     4,   172,
     256,   173,   202,   256,     6,    -1,     4,   170,   256,   171,
     202,   256,     6,    -1,     4,   172,   177,   264,   178,   173,
     202,   261,     6,    -1,     4,   170,   177,   264,   178,   171,
     202,   261,     6,    -1,   272,   203,     6,    -1,     4,   172,
     256,   173,   203,     6,    -1,   272,     7,   269,     6,    -1,
       4,   174,     4,     7,   269,     6,    -1,     4,   172,   256,
     173,   174,     4,     7,   269,     6,    -1,     4,   174,     4,
     202,   256,     6,    -1,     4,   172,   256,   173,   174,     4,
     202,   256,     6,    -1,     4,   174,     4,   203,     6,    -1,
       4,   172,   256,   173,   174,     4,   203,     6,    -1,     4,
     174,   122,   174,     4,     7,   265,     6,    -1,     4,   172,
     256,   173,   174,   122,   174,     4,     7,   265,     6,    -1,
       4,   174,   123,     7,   266,     6,    -1,     4,   172,   256,
     173,   174,   123,     7,   266,     6,    -1,     4,   131,     7,
     256,     6,    -1,   131,   172,   256,   173,     7,     4,     6,
      -1,   131,   172,   256,   173,   174,     4,     7,   256,     6,
      -1,   131,   172,   256,   173,   174,     4,     7,   269,     6,
      -1,   131,   172,   256,   173,   174,     4,     7,   177,   264,
     178,     6,    -1,   131,   172,   256,   173,   174,     4,     6,
      -1,    83,   170,     4,   171,   174,     4,     7,   256,     6,
      -1,    83,   170,     4,   171,   174,     4,     7,   269,     6,
      -1,    -1,   176,    -1,    -1,   206,   205,   272,    -1,   206,
     205,   272,     7,   256,    -1,    -1,   206,   205,   272,     7,
     177,   256,   207,   211,   178,    -1,   206,   205,   272,     7,
     269,    -1,    -1,   206,   205,   272,     7,   177,   269,   208,
     213,   178,    -1,    -1,   209,   205,   268,    -1,   256,     7,
     269,    -1,   210,   176,   256,     7,   269,    -1,    -1,   211,
     212,    -1,   176,     4,   261,    -1,   176,     4,   177,   210,
     178,    -1,   176,     4,   269,    -1,    -1,   213,   214,    -1,
     176,     4,   256,    -1,   176,     4,   269,    -1,   176,     4,
     177,   270,   178,    -1,   256,    -1,   269,    -1,    -1,   125,
      64,   177,   256,   178,    -1,    -1,    75,   258,    -1,    60,
     170,   256,   171,     7,   258,     6,    -1,    -1,    79,    60,
     219,   170,   215,   171,     7,   261,     6,    -1,    69,    70,
     261,     7,   256,     6,    -1,    63,   170,   256,   171,     7,
     261,     6,    -1,    84,    63,   261,     6,    -1,    67,   170,
     256,   171,     7,   261,     6,    -1,    61,   170,   256,   171,
       7,   261,   217,     6,    -1,    62,   170,   256,   171,     7,
     261,   217,     6,    -1,   117,   170,   256,   171,     7,   261,
       6,    -1,   118,   170,   256,   171,     7,   261,     6,    -1,
     119,   170,   256,   171,     7,   261,   121,   261,   120,   256,
       6,    -1,    63,     4,   170,   256,   171,     7,   261,     6,
      -1,    80,    63,   170,   256,   171,     7,   261,     6,    -1,
      -1,    79,    63,   220,   170,   215,   171,     7,   261,     6,
      -1,    75,    66,   170,   256,   171,     7,   261,     6,    -1,
      76,    66,   170,   256,   171,     7,   261,   216,     6,    -1,
      12,    13,     6,    -1,    13,    66,   256,     6,    -1,    71,
      66,   170,   256,   171,     7,     5,     5,     5,     6,    -1,
      64,   170,   256,   171,     7,   261,     6,    -1,    65,   170,
     256,   171,     7,   261,     6,    -1,    66,     4,   170,   256,
     171,     7,   261,     6,    -1,    80,    66,   170,   256,   171,
       7,   261,     6,    -1,    80,    66,   170,   256,   171,     7,
     261,     4,   177,   260,   178,     6,    -1,    -1,    79,    66,
     221,   170,   215,   171,     7,   261,     6,    -1,    78,    68,
     170,   256,   171,     7,   261,     6,    -1,    68,   170,   256,
     171,     7,   261,     6,    -1,    80,    68,   170,   256,   171,
       7,   261,     6,    -1,    -1,    79,    68,   222,   170,   215,
     171,     7,   261,     6,    -1,    87,   258,   177,   224,   178,
      -1,    86,   177,   258,   176,   258,   176,   256,   178,   177,
     224,   178,    -1,    88,   258,   177,   224,   178,    -1,    89,
     177,   258,   176,   256,   178,   177,   224,   178,    -1,    89,
     177,   258,   176,   258,   178,   177,   224,   178,    -1,     4,
     177,   224,   178,    -1,    97,    63,   177,   264,   178,    66,
     177,   256,   178,    -1,    94,    63,   170,   256,   171,   177,
     264,   178,     6,    -1,   225,    -1,   223,    -1,    -1,   225,
     218,    -1,   225,    60,   177,   264,   178,     6,    -1,   225,
      63,   177,   264,   178,     6,    -1,   225,    66,   177,   264,
     178,     6,    -1,   225,    68,   177,   264,   178,     6,    -1,
      91,    75,   170,   256,   171,     7,   261,     6,    -1,    91,
      60,   170,   256,   171,     7,   177,   260,   178,     6,    -1,
      91,    75,   170,   256,   171,     7,   177,   258,   176,   258,
     176,   264,   178,     6,    -1,    91,    75,   170,   256,   171,
       7,   177,   258,   176,   258,   176,   258,   176,   264,   178,
       6,    -1,    91,    64,   170,   256,   171,     7,   177,   258,
     176,   264,   178,     6,    -1,    91,     4,   170,   256,   171,
       7,   261,     6,    -1,    91,     4,   170,   256,   171,     7,
       5,     6,    -1,    91,     4,   177,   256,   178,     6,    -1,
      91,     4,   170,   256,   171,     7,   177,   258,   176,   258,
     176,   264,   178,     6,    -1,    95,   177,   225,   178,    -1,
      95,   131,   172,   256,   173,     6,    -1,    95,     4,   172,
     256,   173,     6,    -1,    95,     4,     6,    -1,    95,     4,
       4,     6,    -1,   122,   265,   177,   225,   178,    -1,    85,
     122,   265,   177,   225,   178,    -1,   135,     5,     6,    -1,
     136,     5,     6,    -1,   135,   177,   225,   178,    -1,    85,
     135,   177,   225,   178,    -1,   136,   177,   225,   178,    -1,
      85,   136,   177,   225,   178,    -1,     4,   269,     6,    -1,
       4,     4,   172,   256,   173,   268,     6,    -1,     4,     4,
       4,   172,   256,   173,     6,    -1,     4,   256,     6,    -1,
      83,   170,     4,   171,   174,     4,     6,    -1,   116,     4,
       6,    -1,   129,     6,    -1,   130,     6,    -1,    54,     6,
      -1,    48,     6,    -1,    48,   177,   256,   176,   256,   176,
     256,   176,   256,   176,   256,   176,   256,   178,     6,    -1,
      49,     6,    -1,    50,     6,    -1,    55,     6,    -1,    56,
       6,    -1,    73,     6,    -1,    74,   177,   264,   178,   177,
     264,   178,   177,   260,   178,   177,   256,   176,   256,   178,
       6,    -1,   143,   256,     6,    -1,   124,   170,   256,     8,
     256,   171,    -1,   124,   170,   256,     8,   256,     8,   256,
     171,    -1,   124,     4,   125,   177,   256,     8,   256,   178,
      -1,   124,     4,   125,   177,   256,     8,   256,     8,   256,
     178,    -1,   126,    -1,   134,     4,    -1,   132,    -1,   133,
       4,     6,    -1,   127,   170,   256,   171,    -1,   128,    -1,
      90,   258,   177,   225,   178,    -1,    90,   177,   258,   176,
     258,   176,   256,   178,   177,   225,   178,    -1,    90,   177,
     258,   176,   258,   176,   258,   176,   256,   178,   177,   225,
     178,    -1,    -1,    90,   258,   177,   225,   233,   246,   178,
      -1,    -1,    90,   177,   258,   176,   258,   176,   256,   178,
     177,   225,   234,   246,   178,    -1,    -1,    90,   177,   258,
     176,   258,   176,   258,   176,   256,   178,   177,   225,   235,
     246,   178,    -1,    -1,    90,   177,   225,   236,   246,   178,
      -1,    90,    60,   177,   256,   176,   258,   178,     6,    -1,
      90,    63,   177,   256,   176,   258,   178,     6,    -1,    90,
      66,   177,   256,   176,   258,   178,     6,    -1,    90,    60,
     177,   256,   176,   258,   176,   258,   176,   256,   178,     6,
      -1,    90,    63,   177,   256,   176,   258,   176,   258,   176,
     256,   178,     6,    -1,    90,    66,   177,   256,   176,   258,
     176,   258,   176,   256,   178,     6,    -1,    90,    60,   177,
     256,   176,   258,   176,   258,   176,   258,   176,   256,   178,
       6,    -1,    90,    63,   177,   256,   176,   258,   176,   258,
     176,   258,   176,   256,   178,     6,    -1,    90,    66,   177,
     256,   176,   258,   176,   258,   176,   258,   176,   256,   178,
       6,    -1,    -1,    90,    60,   177,   256,   176,   258,   178,
     237,   177,   246,   178,     6,    -1,    -1,    90,    63,   177,
     256,   176,   258,   178,   238,   177,   246,   178,     6,    -1,
      -1,    90,    66,   177,   256,   176,   258,   178,   239,   177,
     246,   178,     6,    -1,    -1,    90,    60,   177,   256,   176,
     258,   176,   258,   176,   256,   178,   240,   177,   246,   178,
       6,    -1,    -1,    90,    63,   177,   256,   176,   258,   176,
     258,   176,   256,   178,   241,   177,   246,   178,     6,    -1,
      -1,    90,    66,   177,   256,   176,   258,   176,   258,   176,
     256,   178,   242,   177,   246,   178,     6,    -1,    -1,    90,
      60,   177,   256,   176,   258,   176,   258,   176,   258,   176,
     256,   178,   243,   177,   246,   178,     6,    -1,    -1,    90,
      63,   177,   256,   176,   258,   176,   258,   176,   258,   176,
     256,   178,   244,   177,   246,   178,     6,    -1,    -1,    90,
      66,   177,   256,   176,   258,   176,   258,   176,   258,   176,
     256,   178,   245,   177,   246,   178,     6,    -1,   247,    -1,
     246,   247,    -1,   100,   177,   256,   178,     6,    -1,   100,
     177,   261,   176,   261,   178,     6,    -1,   100,   177,   261,
     176,   261,   176,   261,   178,     6,    -1,   101,     6,    -1,
      92,     6,    -1,   108,     6,    -1,   108,   110,     6,    -1,
     109,     6,    -1,   109,   110,     6,    -1,   106,     6,    -1,
     106,   110,     6,    -1,   107,     6,    -1,   107,   110,     6,
      -1,   102,   170,   256,   171,     7,   261,    82,   256,     6,
      -1,    82,     4,   172,   256,   173,     6,    -1,    -1,    82,
       4,   256,    -1,    -1,     4,    -1,    -1,     7,   261,    -1,
      -1,     7,   256,    -1,    77,    63,   262,     7,   256,   248,
       6,    -1,    77,    66,   262,   250,   249,     6,    -1,    72,
      66,   177,   256,   178,     7,   261,     6,    -1,    77,    68,
     262,   250,     6,    -1,   111,   262,     6,    -1,    98,    66,
     177,   264,   178,   256,     6,    -1,    92,    66,   262,   251,
       6,    -1,    92,    68,   262,     6,    -1,    93,    66,   261,
       7,   256,     6,    -1,    81,    63,   261,     7,   261,     6,
      -1,    81,    66,   256,   177,   264,   178,     7,   256,   177,
     264,   178,     6,    -1,    60,   177,   264,   178,   125,    66,
     177,   256,   178,     6,    -1,    63,   177,   264,   178,   125,
      66,   177,   256,   178,     6,    -1,    60,   177,   264,   178,
     125,    68,   177,   256,   178,     6,    -1,    63,   177,   264,
     178,   125,    68,   177,   256,   178,     6,    -1,    66,   177,
     264,   178,   125,    68,   177,   256,   178,     6,    -1,    99,
      66,   262,     6,    -1,    99,    63,   262,     6,    -1,    96,
       6,    -1,    96,     4,     6,    -1,    96,    60,   177,   264,
     178,     6,    -1,   140,    -1,   141,    -1,   142,    -1,   254,
       6,    -1,   254,   177,   261,   178,     6,    -1,   254,   177,
     261,   176,   261,   178,     6,    -1,   254,   170,   261,   171,
     177,   261,   176,   261,   178,     6,    -1,   257,    -1,   170,
     256,   171,    -1,   161,   256,    -1,   160,   256,    -1,   165,
     256,    -1,   256,   161,   256,    -1,   256,   160,   256,    -1,
     256,   162,   256,    -1,   256,   163,   256,    -1,   256,   164,
     256,    -1,   256,   169,   256,    -1,   256,   156,   256,    -1,
     256,   157,   256,    -1,   256,   159,   256,    -1,   256,   158,
     256,    -1,   256,   155,   256,    -1,   256,   154,   256,    -1,
     256,   153,   256,    -1,   256,   152,   256,    -1,   256,   151,
     256,     8,   256,    -1,    14,   170,   256,   171,    -1,    15,
     170,   256,   171,    -1,    16,   170,   256,   171,    -1,    17,
     170,   256,   171,    -1,    18,   170,   256,   171,    -1,    19,
     170,   256,   171,    -1,    20,   170,   256,   171,    -1,    21,
     170,   256,   171,    -1,    22,   170,   256,   171,    -1,    24,
     170,   256,   171,    -1,    25,   170,   256,   176,   256,   171,
      -1,    26,   170,   256,   171,    -1,    27,   170,   256,   171,
      -1,    28,   170,   256,   171,    -1,    29,   170,   256,   171,
      -1,    30,   170,   256,   171,    -1,    31,   170,   256,   171,
      -1,    32,   170,   256,   171,    -1,    33,   170,   256,   176,
     256,   171,    -1,    34,   170,   256,   176,   256,   171,    -1,
      35,   170,   256,   176,   256,   171,    -1,    23,   170,   256,
     171,    -1,    14,   172,   256,   173,    -1,    15,   172,   256,
     173,    -1,    16,   172,   256,   173,    -1,    17,   172,   256,
     173,    -1,    18,   172,   256,   173,    -1,    19,   172,   256,
     173,    -1,    20,   172,   256,   173,    -1,    21,   172,   256,
     173,    -1,    22,   172,   256,   173,    -1,    24,   172,   256,
     173,    -1,    25,   172,   256,   176,   256,   173,    -1,    26,
     172,   256,   173,    -1,    27,   172,   256,   173,    -1,    28,
     172,   256,   173,    -1,    29,   172,   256,   173,    -1,    30,
     172,   256,   173,    -1,    31,   172,   256,   173,    -1,    32,
     172,   256,   173,    -1,    33,   172,   256,   176,   256,   173,
      -1,    34,   172,   256,   176,   256,   173,    -1,    35,   172,
     256,   176,   256,   173,    -1,    23,   172,   256,   173,    -1,
       3,    -1,     9,    -1,    10,    -1,    11,    -1,   144,    -1,
     145,    -1,   146,    -1,    52,    -1,    53,    -1,   272,    -1,
       4,   172,   256,   173,    -1,   175,     4,   172,   173,    -1,
     272,   203,    -1,     4,   172,   256,   173,   203,    -1,     4,
     174,     4,    -1,     4,   172,   256,   173,   174,     4,    -1,
       4,   174,     4,   203,    -1,     4,   172,   256,   173,   174,
       4,   203,    -1,   137,   170,   268,   176,   256,   171,    -1,
      45,   170,   268,   176,   268,   171,    -1,    46,   170,   268,
     176,   268,   171,    -1,    47,   170,   270,   171,    -1,   259,
      -1,   161,   258,    -1,   160,   258,    -1,   258,   161,   258,
      -1,   258,   160,   258,    -1,   177,   256,   176,   256,   176,
     256,   176,   256,   176,   256,   178,    -1,   177,   256,   176,
     256,   176,   256,   176,   256,   178,    -1,   177,   256,   176,
     256,   176,   256,   178,    -1,   170,   256,   176,   256,   176,
     256,   171,    -1,   261,    -1,   260,   176,   261,    -1,   256,
      -1,   263,    -1,   177,   178,    -1,   177,   264,   178,    -1,
     161,   177,   264,   178,    -1,   256,   162,   177,   264,   178,
      -1,   261,    -1,     5,    -1,   161,   263,    -1,   256,   162,
     263,    -1,   256,     8,   256,    -1,   256,     8,   256,     8,
     256,    -1,    60,   177,   256,   178,    -1,    60,     5,    -1,
      63,     5,    -1,    66,     5,    -1,    68,     5,    -1,    79,
      60,   177,   264,   178,    -1,    79,    63,   177,   264,   178,
      -1,    79,    66,   177,   264,   178,    -1,    79,    68,   177,
     264,   178,    -1,   223,    -1,   232,    -1,     4,   172,   173,
      -1,     4,   170,   171,    -1,    36,   172,     4,   173,    -1,
       4,   172,   177,   264,   178,   173,    -1,     4,   170,   177,
     264,   178,   171,    -1,   256,    -1,   263,    -1,   264,   176,
     256,    -1,   264,   176,   263,    -1,   177,   256,   176,   256,
     176,   256,   176,   256,   178,    -1,   177,   256,   176,   256,
     176,   256,   178,    -1,     4,    -1,     4,   174,   122,   174,
       4,    -1,   177,   267,   178,    -1,     4,   172,   256,   173,
     174,   123,    -1,   265,    -1,   267,   176,   265,    -1,   269,
      -1,   272,    -1,     4,   174,     4,    -1,     4,   172,   256,
     173,   174,     4,    -1,     5,    -1,    51,    -1,   138,   170,
     268,   171,    -1,   139,   170,   268,   176,   268,   171,    -1,
      41,   170,   268,   176,   268,   171,    -1,    42,   170,   268,
     171,    -1,    43,   170,   268,   171,    -1,    44,   170,   268,
     176,   268,   176,   268,   171,    -1,    39,   170,   270,   171,
      -1,    39,   172,   270,   173,    -1,    40,   170,   268,   171,
      -1,    40,   172,   268,   173,    -1,    40,   170,   268,   176,
     264,   171,    -1,    40,   172,   268,   176,   264,   173,    -1,
     268,    -1,   270,   176,   268,    -1,     4,   179,   177,   256,
     178,    -1,   271,   179,   177,   256,   178,    -1,     4,    -1,
     271,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   172,   177,   179,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   201,   205,   212,   217,   222,   236,   249,   262,   290,
     304,   317,   330,   349,   354,   355,   356,   357,   358,   362,
     364,   369,   371,   377,   481,   376,   499,   506,   517,   516,
     534,   541,   552,   551,   568,   585,   608,   607,   621,   622,
     623,   624,   625,   629,   630,   636,   638,   640,   702,   732,
     767,   801,   849,   896,   911,   927,   936,   942,   951,   969,
     987,   996,  1008,  1013,  1021,  1041,  1064,  1075,  1083,  1105,
    1128,  1154,  1175,  1187,  1201,  1201,  1203,  1205,  1216,  1228,
    1227,  1239,  1251,  1250,  1264,  1266,  1274,  1280,  1287,  1288,
    1292,  1303,  1318,  1328,  1329,  1334,  1342,  1351,  1369,  1373,
    1384,  1387,  1400,  1403,  1413,  1437,  1436,  1456,  1478,  1496,
    1517,  1535,  1565,  1595,  1613,  1631,  1657,  1675,  1694,  1693,
    1716,  1734,  1773,  1779,  1785,  1792,  1817,  1842,  1859,  1878,
    1913,  1912,  1936,  1954,  1971,  1988,  1987,  2013,  2018,  2023,
    2028,  2033,  2038,  2061,  2067,  2078,  2079,  2084,  2087,  2091,
    2114,  2137,  2160,  2188,  2209,  2235,  2256,  2278,  2298,  2410,
    2429,  2467,  2576,  2585,  2591,  2606,  2634,  2651,  2660,  2674,
    2680,  2686,  2695,  2704,  2713,  2727,  2772,  2789,  2804,  2823,
    2835,  2859,  2863,  2868,  2875,  2881,  2886,  2892,  2900,  2904,
    2908,  2913,  2968,  2981,  2998,  3015,  3036,  3057,  3092,  3100,
    3106,  3113,  3117,  3126,  3134,  3142,  3151,  3150,  3165,  3164,
    3179,  3178,  3193,  3192,  3206,  3213,  3220,  3227,  3234,  3241,
    3248,  3255,  3262,  3270,  3269,  3283,  3282,  3296,  3295,  3309,
    3308,  3322,  3321,  3335,  3334,  3348,  3347,  3361,  3360,  3374,
    3373,  3390,  3393,  3399,  3411,  3431,  3455,  3460,  3464,  3468,
    3472,  3476,  3480,  3484,  3488,  3492,  3496,  3515,  3528,  3531,
    3547,  3550,  3567,  3570,  3576,  3579,  3586,  3642,  3712,  3717,
    3784,  3820,  3828,  3871,  3910,  3930,  3957,  3997,  4020,  4043,
    4047,  4051,  4074,  4113,  4158,  4162,  4172,  4207,  4208,  4209,
    4213,  4219,  4231,  4249,  4277,  4278,  4279,  4280,  4281,  4282,
    4283,  4284,  4285,  4292,  4293,  4294,  4295,  4296,  4297,  4298,
    4299,  4300,  4301,  4302,  4303,  4304,  4305,  4306,  4307,  4308,
    4309,  4310,  4311,  4312,  4313,  4314,  4315,  4316,  4317,  4318,
    4319,  4320,  4321,  4322,  4323,  4324,  4327,  4328,  4329,  4330,
    4331,  4332,  4333,  4334,  4335,  4336,  4337,  4338,  4339,  4340,
    4341,  4342,  4343,  4344,  4345,  4346,  4347,  4348,  4357,  4358,
    4359,  4360,  4361,  4362,  4363,  4364,  4365,  4369,  4387,  4405,
    4417,  4434,  4455,  4460,  4465,  4475,  4485,  4490,  4499,  4504,
    4531,  4535,  4539,  4543,  4547,  4554,  4558,  4562,  4566,  4573,
    4578,  4585,  4590,  4594,  4599,  4603,  4611,  4622,  4626,  4638,
    4646,  4654,  4661,  4671,  4691,  4695,  4699,  4703,  4707,  4736,
    4765,  4794,  4823,  4833,  4843,  4856,  4868,  4880,  4899,  4920,
    4925,  4929,  4933,  4945,  4949,  4961,  4968,  4978,  4982,  4997,
    5002,  5009,  5013,  5026,  5034,  5045,  5049,  5057,  5065,  5073,
    5081,  5095,  5109,  5121,  5138,  5154,  5159,  5163,  5183,  5205,
    5210,  5216,  5225,  5238,  5241
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
  "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "@1", "@2",
  "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D", "@4",
  "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "Comma", "DefineConstants", "@6",
  "@7", "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "@8", "@9",
  "@10", "@11", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "@12",
  "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "@23", "@24", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble",
  "ListOfDouble", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr",
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
     405,    63,   406,   407,   408,   409,    60,    62,   410,   411,
      43,    45,    42,    47,    37,    33,   412,   413,   414,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   180,   181,   181,   182,   182,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   184,   184,   185,   185,   185,   185,   185,   185,   186,
     186,   186,   186,   187,   187,   187,   187,   187,   187,   188,
     188,   189,   189,   191,   192,   190,   193,   193,   195,   194,
     196,   196,   198,   197,   199,   199,   201,   200,   202,   202,
     202,   202,   202,   203,   203,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   205,   205,   206,   206,   206,   207,
     206,   206,   208,   206,   209,   209,   210,   210,   211,   211,
     212,   212,   212,   213,   213,   214,   214,   214,   215,   215,
     216,   216,   217,   217,   218,   219,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   220,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     221,   218,   218,   218,   218,   222,   218,   223,   223,   223,
     223,   223,   223,   223,   223,   224,   224,   225,   225,   225,
     225,   225,   225,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   227,   228,   228,   229,
     229,   229,   229,   229,   229,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   232,   232,   232,   233,   232,   234,   232,
     235,   232,   236,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   237,   232,   238,   232,   239,   232,   240,
     232,   241,   232,   242,   232,   243,   232,   244,   232,   245,
     232,   246,   246,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   248,   248,
     249,   249,   250,   250,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   253,   253,   253,   254,   254,   254,
     255,   255,   255,   255,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     258,   258,   258,   258,   258,   259,   259,   259,   259,   260,
     260,   261,   261,   261,   261,   261,   261,   262,   262,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   264,
     264,   264,   264,   265,   265,   265,   265,   266,   266,   267,
     267,   268,   268,   268,   268,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   270,
     270,   271,   271,   272,   272
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
       1,     1,     1,     1,     1,     5,     5,     4,     6,     7,
       7,     9,     9,     3,     6,     4,     6,     9,     6,     9,
       5,     8,     8,    11,     6,     9,     5,     7,     9,     9,
      11,     7,     9,     9,     0,     1,     0,     3,     5,     0,
       9,     5,     0,     9,     0,     3,     3,     5,     0,     2,
       3,     5,     3,     0,     2,     3,     3,     5,     1,     1,
       0,     5,     0,     2,     7,     0,     9,     6,     7,     4,
       7,     8,     8,     7,     7,    11,     8,     8,     0,     9,
       8,     9,     3,     4,    10,     7,     7,     8,     8,    12,
       0,     9,     8,     7,     8,     0,     9,     5,    11,     5,
       9,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     8,    10,    14,    16,    12,     8,     8,
       6,    14,     4,     6,     6,     3,     4,     5,     6,     3,
       3,     4,     5,     4,     5,     3,     7,     7,     3,     7,
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
      10,    10,     4,     4,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       2,     5,     3,     6,     4,     7,     6,     6,     6,     4,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     1,
       3,     1,     1,     2,     3,     4,     5,     1,     1,     2,
       3,     3,     5,     4,     2,     2,     2,     2,     5,     5,
       5,     5,     1,     1,     3,     3,     4,     6,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     3,     6,     1,     1,     4,     6,     6,
       4,     4,     8,     4,     4,     4,     4,     6,     6,     1,
       3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,     0,   222,
       0,     0,     0,   219,     0,     0,     0,     0,   307,   308,
     309,     0,     5,     7,     6,     8,     9,    10,    19,    11,
      12,    13,    18,    17,    14,    15,    16,     0,    20,   474,
       0,   378,   473,   455,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,   385,
     386,     0,     0,     0,     0,   382,   383,   384,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,   314,     0,
     451,   387,     0,     0,     0,     0,   204,     0,   206,   207,
     203,   208,   209,    96,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,   125,
     138,   150,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,   473,   418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   411,   417,     0,   412,   387,     0,     0,     0,     0,
     445,     0,     0,     0,     0,     0,   201,   202,     0,     0,
     218,     0,   167,     0,   167,   473,     0,   310,     0,     0,
       0,    58,    62,    61,    60,    59,    64,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,   316,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,     0,   165,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,   195,   390,   142,     0,
     473,     0,   451,   452,     0,     0,    94,    94,     0,     0,
     439,   440,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,   282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   167,     0,   402,
     401,     0,     0,     0,     0,   167,   167,     0,     0,     0,
       0,     0,     0,     0,   232,     0,   167,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,   185,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   424,     0,   425,   426,   427,     0,
       0,     0,     0,     0,   316,   419,     0,   413,     0,     0,
       0,   290,   200,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,   220,   189,     0,   190,     0,     0,   212,
       0,     0,     0,     0,     0,    73,     0,     0,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,    58,     0,     0,     0,    58,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,   168,     0,     0,   332,
     331,   330,   329,   325,   326,   328,   327,   320,   319,   321,
     322,   323,   324,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   167,     0,     0,     0,     0,     0,
     404,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,   186,     0,     0,   182,     0,     0,     0,   303,
     302,     0,     0,     0,   435,     0,   434,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,   315,   414,   421,
       0,   321,   420,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,   191,   193,     0,     0,     0,     0,    75,
      67,     0,   388,   394,   334,   356,   335,   357,   336,   358,
     337,   359,   338,   360,   339,   361,   340,   362,   341,   363,
     342,   364,   355,   377,   343,   365,     0,     0,   345,   367,
     346,   368,   347,   369,   348,   370,   349,   371,   350,   372,
     351,   373,     0,     0,     0,     0,     0,     0,   463,     0,
     464,   465,     0,   466,     0,     0,   460,   461,     0,     0,
       0,   399,    86,     0,   457,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
     389,     0,     0,     0,     0,   471,     0,    43,     0,     0,
       0,    56,     0,    34,    35,    36,    37,    38,     0,   453,
      23,    21,     0,     0,    24,     0,     0,    65,   473,    97,
      66,   105,     0,   441,   442,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   283,   281,     0,   289,     0,     0,
     118,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   194,     0,     0,     0,   157,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,   223,     0,     0,     0,
       0,     0,     0,   285,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   388,   436,   423,
       0,     0,     0,     0,   415,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,   311,
     472,     0,     0,   391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   470,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,     0,     0,
      74,    76,    78,     0,     0,   449,     0,    84,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,    29,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,     0,   266,     0,   272,     0,   274,     0,   268,
       0,   270,     0,   233,   262,     0,     0,     0,   180,     0,
       0,     0,   294,     0,   184,   183,   306,     0,     0,    30,
      31,     0,     0,     0,     0,   428,   429,   430,   431,   422,
     416,     0,     0,     0,   446,     0,     0,     0,   213,     0,
       0,     0,     0,   197,   393,   196,   344,   366,   352,   374,
     353,   375,   354,   376,   467,   468,   459,     0,   397,   398,
     396,   458,     0,    70,     0,    58,     0,     0,     0,     0,
      69,     0,     0,     0,   447,     0,     0,     0,     0,     0,
       0,     0,     0,   409,     0,     0,    25,    26,     0,    27,
       0,     0,    98,   101,   124,     0,     0,     0,     0,     0,
       0,   128,     0,     0,   145,   146,     0,     0,   130,   153,
       0,     0,     0,     0,   120,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,     0,
       0,   167,   167,     0,   243,     0,   245,     0,   247,     0,
     411,     0,     0,   273,   275,   269,   271,     0,     0,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,   438,   437,   393,   133,   134,     0,     0,     0,     0,
      87,    91,     0,     0,   312,   395,     0,     0,     0,     0,
       0,    81,     0,     0,    82,     0,   450,   169,   170,   171,
     172,     0,    39,     0,     0,     0,     0,     0,    41,   454,
       0,     0,    99,   102,     0,     0,   123,   131,   132,   136,
       0,     0,   147,     0,     0,   288,     0,   140,     0,     0,
     279,   152,     0,     0,     0,     0,   137,     0,   148,   154,
       0,     0,     0,     0,   408,     0,   407,     0,     0,     0,
     234,     0,     0,   235,     0,     0,   236,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,   178,     0,     0,
       0,   173,     0,     0,    32,     0,     0,   444,     0,   215,
     214,     0,     0,     0,     0,   462,    72,    71,    77,    79,
       0,    85,     0,    44,     0,     0,     0,   410,     0,     0,
       0,    28,     0,   108,   113,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   126,   139,   151,   156,     0,     0,
      92,    93,   167,     0,   160,   161,     0,     0,     0,     0,
       0,     0,     0,   263,     0,     0,   167,     0,     0,     0,
       0,     0,   164,   163,     0,     0,     0,     0,    88,    89,
       0,     0,   448,     0,    40,     0,     0,     0,    42,    57,
       0,     0,     0,   297,   299,   298,   300,   301,   144,     0,
       0,     0,     0,     0,     0,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,   228,
       0,     0,   174,     0,     0,     0,   443,   216,     0,   313,
      83,     0,     0,     0,     0,     0,     0,   100,   109,     0,
     103,   114,     0,     0,     0,     0,   158,     0,   249,     0,
       0,   251,     0,     0,   253,     0,     0,     0,   264,     0,
     224,     0,   167,     0,     0,     0,   135,    90,     0,    48,
       0,    54,     0,     0,     0,     0,     0,   121,   149,   296,
     405,   237,     0,     0,   244,   238,     0,     0,   246,   239,
       0,     0,   248,     0,     0,     0,   230,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   112,     0,
     115,   116,     0,     0,   255,     0,   257,     0,   259,   265,
     276,   229,   225,     0,     0,     0,     0,    45,     0,    52,
       0,     0,     0,   439,     0,     0,     0,   240,     0,     0,
     241,     0,     0,   242,     0,     0,   181,     0,   175,     0,
      46,     0,     0,   205,     0,   111,     0,   117,     0,     0,
       0,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     0,   106,   211,   250,     0,   252,     0,   254,     0,
     176,    47,    49,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    55,   107,   256,   258,   260,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    82,   862,    83,    84,   633,  1281,  1287,
     853,  1023,  1433,  1599,   854,  1552,  1633,   855,  1601,   856,
     857,  1027,   298,   397,    85,   644,   406,  1383,  1384,   407,
    1582,  1441,  1488,  1442,  1491,   899,  1309,  1188,   616,   434,
     435,   436,   437,   259,   376,   377,    88,    89,    90,    91,
      92,    93,   260,   937,  1511,  1573,   699,  1331,  1334,  1337,
    1532,  1536,  1540,  1588,  1591,  1594,   933,   934,  1058,   896,
     670,   708,    95,    96,    97,    98,   261,   158,   450,   219,
    1172,   262,   263,   264,   508,   272,   839,  1016,   583,   402,
     584,    99,   265
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1231
static const yytype_int16 yypact[] =
{
    4983,    21,    50,  5091, -1231, -1231,   379,   112,    77,    44,
     119,    33,   174,   178,   184,   260,   279,   152,   171,   -40,
     185,   221,     8,   257,   286,    16,   311,   322,   426,   301,
     441,   528,   361,   481,   498,   552,   523,   673,   596,    78,
     436,   546,   -87,   442,   165,   165,   450,   402,    53,   313,
     564,   570,    14,    52,   576,   588,   168,   651,   654,   657,
    2762,   669,   495,   510,   514,    18,    43, -1231,   518, -1231,
     685,   686,   538, -1231,   712,   725,    27,    28, -1231, -1231,
   -1231,  4677, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,    19, -1231,   547,
     114, -1231,     7, -1231, -1231, -1231, -1231,   307,   350,   401,
     502,   515,   525,   529,   532,   555,   565,   572,   594,   601,
     606,   621,   630,   641,   662,   684,   690,   691,   694,   697,
     698,   568,   577,   581,   590,   595,   607,   622, -1231, -1231,
   -1231,   727,   626,   635,   638, -1231, -1231, -1231,  4677,  4677,
    4677,  4255,  2547,    42,   810,   489,   646,   688, -1231,   647,
     821,  -108,   847,  4677,   290,   290, -1231,  4677, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,  4677,  4469,  4677,  4677,   701,
    4677,  4469,  4677,  4677,   735,  4469,  4677,  4677,  3100,   749,
     681, -1231,  4469,   754,   775,  2762,  2762,  2762,   779, -1231,
   -1231, -1231, -1231,   784,   836,   846,  3100,  4677,   873,  3100,
      18,   710,   751,   165,   165,   165,  4677,  4677,   -41, -1231,
     -22,   165,   781,   926,   942,  4424,   289,   -14,   862,   977,
     981,  2762,  2762,  3100,   991,    25,   841, -1231,  1011, -1231,
     985,   986,   987,  2762,  2762,   999,  1000,  1002,   371, -1231,
    1005,    29,  1165,  1176,  1177,   741,  3269,  4677,  2363, -1231,
   -1231,  2201, -1231,  1178, -1231,   -97,  1179,  4677,  4677,  4677,
    1009,  4677,  1010,  1061,  4677,  4677, -1231, -1231,  4677,  1183,
   -1231,  1184, -1231,  1185, -1231,  -111,  1153, -1231,  3100,  3100,
    1015,   458, -1231, -1231, -1231, -1231, -1231, -1231,  3100,  1188,
    1021,  4677,  1193,  4677,  4677,  4677,  4677,  4677,  4677,  4677,
    4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,
    4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,
    4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,
    4677,  4677,  4677,  4677,  4677,  4677,  4677,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,  4677,   290,
     290,   290,  1035,  1035,  1035,  4469,  7517,   120,  4469,  6712,
     445,  1031,  1206,  1042,  1039, -1231,  1048,  5179,  4677, -1231,
    4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,  4677,
    4677,  4677,  4677,  4677,  4677, -1231, -1231, -1231, -1231,  1722,
     206,   151, -1231, -1231,   197,  5958,   -62,    -7,  7538,  4469,
    4737, -1231,   293,  7559,  7580,  4677,  7601,   471,  7622,  7643,
    4677,   642,  7664,  7685,  1210,  4677,  4677,   655,  4677,  4677,
    1223,  1225,  1225,  4677,  1064,  1066,  1067,  1068,  4677,  4677,
    4677,  1232,  5904,  1069,  1235,  1070, -1231, -1231,    69, -1231,
   -1231,  5984,  6010,   165,   165,   489,   489,   139,  4677,  4677,
    4677,  4424,  4424,  4677,  5179,   160, -1231,  4677,  4677,  4677,
    4677,  4677,  1237,  1236,  1239,  4677,  1242, -1231,  4677,  4677,
     719, -1231,  4469,  4469,  4469,  1246,  1249,  4677,  4677,  4677,
    -133,  4204,  1254,  1255, -1231,  4677, -1231, -1231, -1231,  1084,
    1085,  1086,  1087,  4469,  1035, -1231,  7706, -1231,   700,  4677,
    3438, -1231, -1231,  7727,  7748,  7769,  1143,  6036, -1231,  1089,
    4760,  7790,  6735, -1231, -1231,  1432, -1231,  1580,  4677, -1231,
    1099,   707,  4677,  1267,  1269, -1231,  4677,  6758,     5,  7811,
    6781,  7832,  6804,  7853,  6827,  7874,  6850,  7895,  6873,  7916,
    6896,  7937,  6919,  7958,  6942,  7979,  6965,  8000,  6988,  8021,
    7011,  6062,  6088,  8042,  7034,  8063,  7057,  8084,  7080,  8105,
    7103,  8126,  7126,  8147,  7149,  8168,  7172,  6114,  6140,  6166,
    6192,  6218,  6244, -1231,   319,   294,   332,   411,  1101,  1107,
    1109,  1106,  1108,  1110,   357,  2044,  1114,  1120,  1121,   708,
     120, -1231,  3100,   717,    68,   458,  4677,  1294,  1297,    24,
    1145, -1231,    55,    17,    26,   103, -1231,  1857,  4779,  2358,
     865,   932,   932,   545,   545,   545,   545,   559,   559,  1035,
    1035,  1035,  1035,    20, -1231,  4677,  1315,    31,  4469,  1314,
    4469,  4677,  1317, -1231,  1320,  1319,   290,  1321,  4469,  4469,
    1196,  1322,  1323,  8189,  1325,  1201,  1327,  1328,  8210,  1202,
    1329,  1330,  4677,  8231,  5176,  1161,  8252,  8273,  4677,  3100,
    1335,  1334,  8294,  4632,  4632,  4632,  4632,  8315,  8336,  8357,
    3100,  4469,  1167, -1231, -1231,  1608,  1784,   165,  4677,  4677,
   -1231, -1231,  1166,  1170,  4424,  6270,  6296,  6322,  2330,   661,
     165,  1911,  8378,  5204,  8399,  8420,  8441,  4677,  1337, -1231,
    4677,  8462, -1231,  7195,  7218, -1231,   718,   722,   723, -1231,
   -1231,  7241,  7264,  6348, -1231,  4469, -1231,  4469,  7287,   -97,
    1172,  5232,  4469,  4469,  4469,  4469,   726, -1231, -1231,  4798,
    4469,  1035, -1231,  1343,  1344,  1348,  1182,  4677,  1991,  4677,
    4677, -1231,    38, -1231, -1231,  1180,  3100,  1352,  5260, -1231,
   -1231,  7310,   443, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231,  4677,  4677, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231,  4677,  4677,  4677,  4677,  4677,  4677, -1231,   290,
   -1231, -1231,  4469, -1231,  4469,   290, -1231, -1231,   290,   290,
     290, -1231, -1231,  4677, -1231,   290,  1199,  4677,  1353,  1191,
      48,  4677,  1365,  1366,  2128, -1231,  1367,  1204,    18,  1371,
   -1231,  4469,  4469,  4469,  4469, -1231,  4677, -1231,  1209,  1212,
    1207, -1231,  1379, -1231, -1231, -1231, -1231, -1231,  7333, -1231,
   -1231,  1229,   290,   384, -1231,   394,  6374, -1231,  1208,  1383,
   -1231, -1231,   165,  4737, -1231,   840,  3100,  3100,  1387,  3100,
     843,  3100,  3100,  1388,  1336,  3100,  3100,  2178,  1389,  1396,
    4469,  1398,  1399,   831, -1231, -1231,  1401, -1231,  1403,  1240,
    8693, -1231,  1241,  1247,  1248,  1410,  1413,  1415,  1417,   736,
    1420,  2807, -1231, -1231,   216,  6400,  6426, -1231, -1231,  5288,
     -60,   165,   165,   165,  1421,  1424,  1250,  1425,  1256,    30,
      36,    37,    49,   611, -1231,   297, -1231,   661,  1426,  1429,
    1430,  1434,  1435,  8693, -1231,  3216,  1262,  1442,  1443,  1445,
    1386,  4677,  1447,  1451,  4677,   753,   757,     9, -1231, -1231,
     758,   762,   763,   766, -1231,  4677,   770,  3100,  3100,  3100,
    1428,  6452, -1231,  4817,   282,  1454,  1455,  3100,  1292, -1231,
   -1231,  1465,  1473, -1231,  1472,  8483,  7356,  8504,  7379,  8525,
    7402,  8546,  7425, -1231,   455,   412,  1310,  1306,  1312,  1331,
    8567,  1338,   120,  3235, -1231,   120,   454,  1311,  1479,  3394,
   -1231, -1231, -1231,    18,  4677, -1231,   774, -1231,   788,   795,
     796,   799,  8693,  1318,  4677,  4677,  3100,  1340, -1231,  1332,
   -1231,  1485,    35,  1499,  4677,  3945,    59,  1341,  1356,  1438,
    1438,  3100,  1509,  1357,  1358,  1515,  1519,  3100,  1359,  1531,
    1532, -1231,  1534,  3100,   800,  3100,  3100,  1536,  1535, -1231,
    3100,  1541,  1546,  1548,  1553,  3100,  3100,  3100, -1231,  1554,
     237, -1231,  4677,  4677,  4677,  1385,  1391,   -54,    61,   115,
    1392, -1231,  3100, -1231,  4677, -1231,  1559, -1231,  1560, -1231,
    1563, -1231,  1564, -1231, -1231,  4424,   648,  2931, -1231,  1395,
    1397,  3607, -1231,  4469, -1231, -1231, -1231,  1400,  3554, -1231,
   -1231,  7448,  1405,  1406,  1576, -1231, -1231, -1231, -1231,  8693,
   -1231,  1581,  1583,  1469, -1231,  4677,  4677,  4677, -1231,  1585,
     507,  1418,  1589, -1231,   110, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,   290, -1231, -1231,
   -1231, -1231,  3100, -1231,  3100,   458,  4677,  1590,  1593,    24,
   -1231,  1592,  7471,    18, -1231,  1596,  1597,  1598,  1599,  4677,
    6478,  6504,   823, -1231,  4677,  1602, -1231, -1231,   290, -1231,
    6530,  4632,  8693, -1231, -1231,  4677,  4677,   165,  1601,  1605,
    1606, -1231,  4677,  4677, -1231, -1231,  1607,  4677, -1231, -1231,
    1603,  1609,  1456,  1616,  1503,  4677, -1231,  1626,  3100,  3100,
    3100,  3100,  1628,   998,  1629,  4677, -1231,  4632,  5316,  8588,
    4846,   489,   489,   165,  1630,   165,  1632,   165,  1633,  4677,
      96,  1476,  8609, -1231, -1231, -1231, -1231,  5344,   299, -1231,
    1647,    63,  1648,  3100,   165,    63,  1651,   827,  4677, -1231,
    1655, -1231, -1231,   -97, -1231, -1231,  3100,  5113,   150,  8630,
   -1231, -1231,  3990,  3100, -1231, -1231,  1491,  1657,  1659,  1660,
    3573, -1231,  1671,  1674, -1231,  1507, -1231, -1231, -1231, -1231,
   -1231,   474,  8693,  4677,  4677,  3100,  1505,   834,  8693, -1231,
    1679,  4677,  8693, -1231,  5372,  5400,   136, -1231, -1231, -1231,
    5428,  5456, -1231,  5484,  1684, -1231,  3100, -1231,  1636,  1687,
    8693, -1231,  1690,  1695,  1696,  1697, -1231,  1513, -1231, -1231,
    5931,  3732,  1698,  1529, -1231,  4677, -1231,  1530,  1533,   328,
   -1231,  1537,   345, -1231,  1539,   366, -1231,  1540,  7494,  1701,
    3100,  1702,  1542,  4677, -1231,  3776,   370, -1231,   855,   376,
     429, -1231,  1704,  5512, -1231,  1600,  4677, -1231,  4677, -1231,
   -1231,  4469,  3893,  1706,  1543, -1231, -1231, -1231, -1231, -1231,
      18, -1231,  1595, -1231,  4677,  6556,  6582, -1231,  3100,  4677,
    1723, -1231,  6608, -1231, -1231,  1724,  1725,  1727,  1729,  1730,
    1731,   859,  1561, -1231, -1231, -1231, -1231, -1231,  3100,  4469,
   -1231, -1231,   489,  5148, -1231, -1231,  4424,   661,  4424,   661,
    4424,   661,  1733, -1231,   860,  3100, -1231,  5540,   165,  1738,
    4469,   165, -1231, -1231,  4677,  5568,  5596,   864, -1231, -1231,
    1744,  1745, -1231,  1575,  8693,  4677,  4677,   921,  8693, -1231,
    4677,   924,   928, -1231, -1231, -1231, -1231, -1231, -1231,  1578,
    4677,   931,   934,  1579,  4677, -1231,  5624,   438,   773,  5652,
     447,   861,  5680,   464,  1187, -1231,  3100,  1753,  1678,  2976,
    1594,   468, -1231,   935,   477,  3912, -1231, -1231,  1760, -1231,
   -1231,  4677,  8651,  6634,    34,  6660,  1768, -1231, -1231,  1769,
   -1231, -1231,  4677,  5708,  1770,  1771, -1231,  5736,  1772,  4677,
    1773,  1774,  4677,  1775,  1776,  4677,  1777,  1610, -1231,  4677,
   -1231,   661, -1231,  4469,  1778,  3776, -1231, -1231,   938, -1231,
    4677, -1231,  3100,  4677,  2593,  4159,  6686, -1231, -1231, -1231,
   -1231, -1231,  1612,  5764, -1231, -1231,  1613,  5792, -1231, -1231,
    1614,  5820, -1231,  1779,  4580,  1260,  3145,   939, -1231,   491,
     959,  1781,  1615,  8672,   960,  5848,  2363, -1231, -1231,   290,
    8693, -1231,  4677,   661,  1787,   661,  1788,   661,  1789, -1231,
   -1231, -1231, -1231,   661,  1792,  4469,  1793, -1231,   290, -1231,
    1624,  1797,   963,  4603,   964,  5876,  1291, -1231,  1627,  1354,
   -1231,  1634,  1422, -1231,  1639,  1517, -1231,   967, -1231,   970,
   -1231,  1642,  3100, -1231,  4677, -1231,   458, -1231,  1799,  1800,
     661,  1811,   661,  1814,   661, -1231,  1817,   290,  1819,   290,
     976,  4706, -1231, -1231, -1231,  1640, -1231,  1661, -1231,  2332,
   -1231, -1231, -1231,   980, -1231,  1820,   458,  1821,  1822,  1823,
     290,  1824, -1231, -1231, -1231, -1231, -1231, -1231, -1231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1231, -1231, -1231, -1231,   801, -1231, -1231, -1231, -1231,   351,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231,  -316,   -47, -1231,  1427, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,  -259, -1231,   791,  1833, -1231,
   -1231, -1231, -1231,    -1,  -447,  -220, -1231, -1231, -1231, -1231,
   -1231, -1231,  1834, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231,  -931,  -929, -1231, -1231,
    1408, -1231, -1231, -1231, -1231, -1231,   740, -1231,    58, -1231,
   -1230,  1065,   143,  1075,  -166,  -203,   679, -1231,    10,    -5,
    -334, -1231,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -455
static const yytype_int16 yytable[] =
{
     100,   160,    87,   161,  1094,   464,  1096,   445,   692,   693,
     412,   300,   179,  1348,   585,   417,   159,   480,   235,   421,
     184,   179,   270,   594,   847,   287,   427,     4,   837,   476,
     184,   477,   281,   283,   494,   210,  1085,   860,   724,   166,
    1521,  1177,  1087,  1089,   725,   975,   370,   273,   211,   212,
       5,   602,  1006,   299,   606,  1091,   238,   227,   239,   296,
     297,   528,   525,   492,   527,  1184,   101,   248,   156,  -452,
     296,   297,   104,   105,   106,   601,  1391,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   250,
     453,   454,   218,   220,   509,   226,   453,   454,   135,   136,
     137,   642,   240,   228,   643,   139,   140,   229,  1076,   453,
     454,   291,  1223,   251,  1224,   162,   252,   601,   230,   253,
     175,   254,   848,   849,   850,   851,   455,   176,   453,   454,
    1086,   206,   255,   163,   207,   236,  1088,  1090,  1437,    43,
      44,    45,    46,    47,   375,   456,   467,    51,  1358,  1092,
      54,   403,   403,   468,   371,   372,   645,  1094,  1451,   643,
    1007,  1008,   296,   297,   401,   404,   296,   297,   180,   301,
     168,   302,  -453,  1114,   169,   181,   156,   180,   861,   288,
     170,   237,   861,   185,   842,   271,   289,   478,   852,   599,
     142,   838,   603,   843,   282,   284,   495,   145,   146,   147,
     167,  1522,   976,   274,   164,   292,   293,   294,   295,   453,
     454,   453,   454,   461,  1345,   175,   685,   686,   150,   453,
     454,   243,   841,   463,   244,   296,   297,  1225,   154,  1226,
     217,   507,   830,  1216,  1217,   687,   701,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   510,   392,
     393,   292,   293,   294,   295,   394,   171,   292,   293,   294,
     295,   448,   449,   187,  1339,   453,   454,   296,   297,   457,
     844,   296,   297,   465,   827,   172,   533,  -454,   831,   165,
    1127,  1227,  1554,  1228,   400,   103,   453,   454,   748,   453,
     454,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   694,   716,   717,   718,   394,
     453,   454,   637,   607,   173,   214,   215,   638,  1359,   129,
     130,   131,   132,   133,   134,   216,   700,   736,   430,   431,
     432,   138,   217,   174,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   403,   177,   403,   403,   403,   586,
     587,   588,   589,   590,   591,   592,   593,   189,   639,   596,
     597,   598,  1620,   640,   472,   473,   453,   454,   635,   231,
     636,   232,   101,   102,   103,   156,   485,   486,   104,   105,
     106,   178,  1072,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   902,   903,   904,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   182,   143,   144,
     138,   139,   140,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   400,   103,   453,
     454,   394,   605,  1128,   375,   375,   183,   453,   454,   453,
     454,  1155,   222,   103,   911,   223,   466,   810,   224,   649,
     809,   650,   863,  1095,   865,  1343,  1458,   303,  1461,   304,
    1464,   186,   129,   130,   131,   132,   133,   134,   453,   454,
     808,   763,   187,   374,   138,   809,   188,   129,   130,   131,
     132,   133,   134,   811,  1406,   453,   454,   190,   812,   138,
     141,   690,   691,  1261,  1262,   909,   142,   143,   144,   449,
     305,  1408,   306,   145,   146,   147,   453,   454,   821,  1094,
     453,   454,  1094,   809,   191,  1094,   453,   454,   192,   148,
     149,   490,  1410,   491,   150,   492,  1418,   193,   155,   151,
     156,   152,  1420,   153,   154,  1032,   155,   832,   156,   955,
     649,   956,   214,   215,   194,  1033,   960,   961,   962,   963,
     649,   307,   216,   308,   966,    43,    44,    45,    46,   225,
    1545,   143,   144,    51,   813,  1145,    54,   814,   649,   453,
     454,   198,   292,   293,   294,   295,   143,   144,   453,   454,
     833,   292,   293,   294,   295,  1421,   208,   453,   454,   209,
     296,   297,   296,   297,  1499,   195,  1094,   982,   196,   213,
     197,   296,   297,  1502,   453,   454,  1144,   221,   453,   454,
     233,   649,  1586,   234,  1589,  1015,  1592,   453,   454,   241,
    1505,   869,  1595,   403,  1513,  1373,   994,   649,   995,   655,
    1374,   453,   454,  1515,   242,   245,   871,  1094,   246,   203,
    1094,   247,   204,  1094,   205,   267,  1094,  1575,   901,   901,
     901,   901,   309,   266,   310,  1018,  1019,  1020,  1021,  1625,
     268,  1627,   763,  1629,   269,   311,  1152,   312,   275,  1154,
    1156,   276,   277,   924,   379,   313,  1094,   314,  1094,   315,
    1094,   316,   317,   925,   318,   389,   390,   391,   392,   393,
     278,   926,   927,   928,   394,   983,   279,   929,   930,   931,
     932,   391,   392,   393,  1054,   319,   290,   320,   394,   280,
     924,     7,     8,   199,   358,   321,   200,   322,   351,   201,
     925,   202,   323,   924,   324,   914,   157,   352,   926,   927,
     928,   353,   920,   925,   929,   930,   931,   932,   935,   403,
     354,   926,   927,   928,   325,   355,   326,   929,   930,   931,
     932,   327,   984,   328,  1327,  1328,   329,   356,   330,   612,
      20,    21,   613,    23,    24,   614,    26,   615,    28,  1093,
      29,   331,   357,   332,    33,    34,   359,    36,    37,    38,
     333,   499,   334,    41,   500,   360,   403,   501,   361,   502,
    1161,   335,   403,   336,   373,   403,   403,   403,   649,   993,
     659,   286,   403,   378,   395,   996,  1239,   396,   997,   998,
     999,   649,   337,   665,   338,  1001,    62,    63,    64,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   398,   339,   924,   340,   394,   426,   403,
     341,   343,   342,   344,   345,   925,   346,   347,   349,   348,
     350,   415,  1031,   926,   927,   928,   649,   443,   738,   929,
     930,   931,   932,   756,   649,   757,   826,   446,   362,   363,
     364,   366,   369,   649,   649,   829,   949,   715,   649,   649,
     950,   951,   649,   399,   964,   420,  1037,   405,  1038,  1043,
     983,  1044,   649,  1057,  1069,   408,   410,   413,   414,   425,
     416,   410,   418,   419,   428,   410,   422,   423,   447,   649,
    1036,  1112,   410,   649,   649,  1113,  1115,  1247,   649,   649,
    1116,  1117,   649,   924,  1118,   429,   649,   442,  1120,   433,
    1163,  1500,  1164,   925,   438,  1453,   451,   452,   458,  1157,
    1276,   926,   927,   928,   649,   452,  1165,   929,   930,   931,
     932,   649,   649,  1166,  1167,   649,   649,  1168,  1202,  1077,
    1078,  1079,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   504,   506,   410,  1285,
     394,  1286,  1317,   649,  1318,  1352,   439,   513,   514,   515,
    1379,   517,  1380,   479,   520,   521,   440,   481,   522,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
    1183,  1285,   469,  1419,   394,  1285,  1466,  1449,  1467,  1503,
     649,   537,  1478,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,  1265,   385,   386,
     387,   388,   389,   390,   391,   392,   393,  1285,   595,  1484,
    1486,   394,  1487,   459,  1489,   410,  1490,  1285,   410,  1494,
     649,   649,  1495,  1514,  1379,   649,  1551,  1574,   617,   460,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   649,  1285,  1576,  1580,  1604,
     809,  1605,  1607,   649,   403,  1616,  1617,   470,  1618,   504,
    1269,   471,  1285,  1238,  1635,   653,  1640,  1266,  1641,   529,
     658,   475,   482,   483,   484,   663,   664,  1431,   666,   667,
     496,   487,   488,   672,   489,   403,  1293,   493,   677,   678,
     679,   497,   498,   516,   511,   512,   519,   518,  1290,   523,
     524,   526,   532,   536,   535,  1427,  1469,   538,   695,   696,
     697,   362,   363,   698,   394,   608,  1265,   702,   703,   704,
     705,   706,  1322,   609,   610,   711,   155,   662,   713,   714,
     375,   375,   410,   410,   410,  1584,   611,   721,   722,   723,
     668,   728,   669,  1452,   673,   731,   674,   675,   676,   680,
     682,   683,   709,   410,   707,  1296,   710,   684,   712,   739,
     741,   411,   719,   424,  1473,   720,   411,  1363,   729,   730,
     411,   732,   733,   734,   735,   746,   749,   411,   728,   924,
     755,   441,   758,   759,   444,   760,   761,   815,   816,   925,
     817,  1329,   818,  1332,   819,  1335,   820,   926,   927,   928,
     823,   824,  1546,   929,   930,   931,   932,   825,   474,  1346,
     835,   836,  1349,  1350,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   840,   859,
     864,   875,   394,   867,   868,   870,   880,   884,   872,   876,
     877,   505,   879,   411,   881,   882,   885,   886,   890,   895,
     897,   910,   924,   944,   917,   958,   834,  1547,   918,  1550,
     967,   968,   925,   530,   531,   969,   970,   977,   979,  1004,
     926,   927,   928,   534,  1005,  1506,   929,   930,   931,   932,
    1002,  1010,  1011,   924,  1013,   858,  1014,  1017,   410,  1024,
     410,   866,  1025,   925,  1026,  1028,  1030,   156,   741,   873,
    1035,   926,   927,   928,  1041,  1047,  1052,   929,   930,   931,
     932,   375,   887,  1053,  1048,  1055,  1056,  1059,   893,  1597,
    1060,  1061,  1062,   900,   900,   900,   900,  1065,  1063,  1064,
    1066,   410,  1067,  1068,  1070,  1080,  1084,  1082,   915,   916,
    1081,  1083,  1124,  1097,   919,  1098,   924,  1099,  1571,  1103,
     411,  1100,  1101,   411,     7,     8,   925,   943,  1104,  1105,
     945,  1106,  1107,  1109,   926,   927,   928,  1110,  1129,  1130,
     929,   930,   931,   932,  1457,   410,  1460,   410,  1463,  1609,
    1132,  1133,   410,   410,   410,   410,  1471,  1134,  1135,  1474,
     410,  1146,  1147,  1148,   505,  1158,  1159,   971,  1169,   973,
     974,  1176,   612,    20,    21,   613,    23,    24,   614,    26,
     615,    28,  1149,    29,   924,  1179,  1175,    33,    34,  1151,
      36,    37,    38,  1187,   925,  1191,    41,  1174,  1185,  1558,
    1561,  1194,   926,   927,   928,  1195,   985,   986,   929,   930,
     931,   932,  1611,  1186,  1192,  1193,  1197,  1198,  1199,  1200,
    1205,  1206,   987,   988,   989,   990,   991,   992,  1208,    62,
      63,    64,   410,  1209,   410,  1210,   403,   411,   411,   411,
    1211,  1215,  1221,  1000,  1229,  1233,  1234,  1003,  1222,  1235,
    1236,  1009,  1243,  1549,  1244,   403,  1251,  1248,   411,  1252,
    1253,   410,   410,   410,   410,   742,  1022,  1254,  1600,  1255,
    1256,  1260,     7,     8,  1263,  1264,  1271,  1272,  1274,   924,
    1613,  1622,  1277,  1278,  1279,  1280,  1289,  1297,  1304,   925,
     753,  1298,  1299,  1302,   403,  1305,   403,   926,   927,   928,
       7,     8,  1307,   929,   930,   931,   932,  1631,  1308,  1634,
     410,  1643,  1311,  1306,  1316,  1319,  1330,   403,  1333,  1336,
     612,    20,    21,   613,    23,    24,   614,    26,   615,    28,
    1647,    29,  1340,  1344,  1347,    33,    34,  1351,    36,    37,
      38,  1354,  1365,  1366,    41,  1367,  1368,   828,   612,    20,
      21,   613,    23,    24,   614,    26,   615,    28,  1370,    29,
    1371,  1372,  1378,    33,    34,  1381,    36,    37,    38,  1390,
    1398,  1108,    41,  1393,  1111,  1615,  1394,    62,    63,    64,
    1392,  1395,  1396,  1397,  1401,  1119,  1402,  1413,  1404,  1415,
    1422,  1405,  1429,   411,  1407,   411,  1409,  1411,  1432,  1416,
    1424,  1430,   924,   742,   874,    62,    63,    64,   634,  1439,
    1443,  1444,   925,  1445,   894,  1446,  1447,  1448,  1450,  1465,
     926,   927,   928,   924,  1472,   908,   929,   930,   931,   932,
    1479,  1480,  1481,   925,  1162,  1492,   411,  1496,   754,  1508,
    1509,   926,   927,   928,  1170,  1171,  1517,   929,   930,   931,
     932,  1512,  1524,  1525,  1180,  1182,  1528,  1529,  1531,  1534,
    1535,  1538,  1539,  1542,  1548,  1569,   912,  1577,  1543,  1563,
    1565,  1567,  1578,  1587,  1590,  1593,     7,     8,  1596,  1598,
     411,  1602,   411,  1603,  1610,  1623,  1624,   411,   411,   411,
     411,  1612,  1218,  1219,  1220,   411,  1614,  1626,  1637,  1619,
    1628,   978,  1230,  1630,  1232,  1632,  1642,  1644,  1645,  1646,
    1648,  1189,  1518,  1178,   646,  1237,    86,    94,  1273,  1638,
     671,     0,     0,   410,   612,    20,    21,   613,    23,    24,
     614,    26,   615,    28,     0,    29,     0,     0,     0,    33,
      34,     0,    36,    37,    38,  1257,  1258,  1259,    41,     0,
       0,     0,     0,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   411,     0,   411,
       0,   394,     0,     0,     0,     0,  1270,     0,     0,     0,
       0,    62,    63,    64,     0,     0,     0,     0,     0,  1282,
       0,     0,     0,     0,  1288,     0,   411,   411,   411,   411,
       0,  1292,     0,     7,     8,  1294,  1295,     0,     0,     0,
       0,     0,  1300,  1301,     0,     0,     0,  1303,     0,     0,
       0,  1039,  1040,     0,  1042,  1310,  1045,  1046,     0,     0,
    1049,  1050,     0,     0,     0,  1320,     0,  1321,     0,     0,
       0,     0,   913,     0,     0,   411,     0,     0,     0,  1338,
       0,   612,    20,    21,   613,    23,    24,   614,    26,   615,
      28,   410,    29,     0,     0,   410,    33,    34,  1353,    36,
      37,    38,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,  1362,     7,     8,     0,     0,     0,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,  1375,  1376,     0,   394,     0,    62,    63,
      64,  1382,  1121,  1122,  1123,   845,     0,     0,     0,     0,
       0,     0,  1131,     0,     0,     0,     0,     0,     0,     0,
     822,   612,    20,    21,   613,    23,    24,   614,    26,   615,
      28,     0,    29,     0,     0,  1403,    33,    34,     0,    36,
      37,    38,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,  1417,     0,   504,     0,     0,     0,   936,
       0,  1173,     0,     0,     0,     0,  1425,     0,  1426,     0,
       0,   410,     0,     0,     0,     0,  1190,     0,    62,    63,
      64,     0,  1196,     0,  1434,     0,     0,     0,  1201,  1438,
    1203,  1204,     0,     0,     0,  1207,     0,     0,     0,     0,
    1212,  1213,  1214,     0,  1012,     0,     0,     0,     0,   410,
       0,     0,     0,     0,     0,     0,  1456,  1231,  1459,     0,
    1462,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,     0,  1242,     0,  1475,     0,  1246,     0,     0,   972,
       0,     0,     0,     0,     0,  1482,  1483,     0,   411,     0,
    1485,     0,     0,     0,  1051,     0,     0,     0,     0,     0,
    1493,     0,     0,     0,  1497,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   509,
       0,     0,     0,   394,     0,     0,     0,  1267,     0,  1268,
       0,  1288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1526,     0,     0,     0,     0,     0,     0,  1533,
       0,     0,  1537,     0,     0,  1541,     0,     0,     0,  1544,
       0,     0,     0,   410,     0,   410,     0,     0,     0,     0,
    1553,     0,     0,  1555,     0,  1560,     0,     0,     0,     0,
       0,     0,     0,  1312,  1313,  1314,  1315,     0,     0,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,  1583,   394,     0,     0,
       0,     0,  1585,     0,     0,     0,     0,     0,  1173,     0,
       0,     0,     0,     0,     0,   410,   411,     0,     0,     0,
     411,  1355,     0,     0,     0,     0,     0,     0,  1364,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,  1621,     0,     0,   394,     0,     0,
    1377,     0,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   510,   392,   393,   101,   248,     0,     0,
     394,  1173,   104,   105,   106,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   250,
       0,     0,     0,     0,     0,  1414,     0,     0,   135,   136,
     137,     0,     0,     0,   924,   139,   140,     0,     0,     0,
     505,     0,     0,   251,   925,     0,   252,     0,     0,   253,
       0,   254,   926,   927,   928,     0,   411,     0,   929,   930,
     931,   932,   255,  1173,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,     0,     0,     0,    51,     0,     0,
      54,     0,     0,  1173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,     0,     0,     0,     0,     0,
    1468,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   411,     0,     0,     0,   394,
     142,   737,     0,     0,     0,     0,   688,   145,   146,   147,
    1639,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   148,   409,     0,     0,   394,   150,     0,
       0,  1507,     0,   257,     0,     0,     0,     0,   154,     0,
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   285,     0,     0,     0,     0,   104,   105,   106,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     0,     0,     0,     0,  1173,   411,  1557,
     411,     0,   135,   136,   137,     0,   101,   248,   103,   139,
     140,     0,   104,   105,   106,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   250,
       0,   411,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   138,   139,   140,     0,     0,     0,
     411,     0,     0,   251,     0,     0,   252,     0,     0,   253,
       0,   254,     0,     0,     0,     0,     0,  1173,     0,     0,
       0,     0,   255,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,   142,     0,     0,    51,     0,     0,
      54,   145,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   149,     0,
       0,     0,   150,     0,     0,     0,     0,   257,     0,     0,
     367,     0,   154,     0,   368,     0,     0,     0,     0,     0,
     142,   143,   144,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   256,     0,     0,     0,   150,     0,
       0,     0,     0,   257,     0,   101,   248,   249,   154,     0,
    1556,   104,   105,   106,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   136,   137,
       0,     0,     0,     0,   139,   140,     0,     0,     0,     7,
       8,     0,   251,     0,     0,   252,     0,     0,   253,     0,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,     0,     0,     0,    43,    44,
      45,    46,    47,     0,     0,     0,    51,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,   612,    20,    21,
     613,    23,    24,   614,    26,   615,    28,     0,    29,     0,
       0,     0,    33,    34,     0,    36,    37,    38,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   256,    62,    63,    64,   150,     0,     0,
       0,     0,   257,     0,   101,   248,  1240,   154,     0,   258,
     104,   105,   106,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   136,   137,     0,
       0,     0,     0,   139,   140,  1071,     0,     0,     7,     8,
       0,   251,     0,     0,   252,     0,     0,   253,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,     0,    43,    44,    45,
      46,    47,     0,     0,     0,    51,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,   612,    20,    21,   613,
      23,    24,   614,    26,   615,    28,     0,    29,     0,     0,
       0,    33,    34,     0,    36,    37,    38,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   256,    62,    63,    64,   150,     0,     0,     0,
       0,   257,     0,   101,   248,     0,   154,     0,  1241,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   136,   137,     0,     0,
       0,     0,   139,   140,  1510,     0,     0,     7,     8,     0,
     251,     0,     0,   252,     0,     0,   253,     0,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      47,     0,     0,     0,    51,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,   612,    20,    21,   613,    23,
      24,   614,    26,   615,    28,     0,    29,     0,     0,     0,
      33,    34,  1102,    36,    37,    38,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,  1153,     0,     0,   145,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   256,    62,    63,    64,   150,     0,     0,     0,     0,
     257,     0,   101,   248,     0,   154,     0,   258,   104,   105,
     106,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,     0,     0,     0,
       0,   139,   140,  1572,     0,     0,     0,     0,     0,   251,
       0,     0,   252,     0,     0,   253,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
       0,     0,     0,    51,     0,     0,    54,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
    1160,     0,     0,     0,   394,     0,   142,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     409,     0,     0,     0,   150,     0,     0,     0,     0,   257,
       0,   101,   248,     0,   154,     0,   503,   104,   105,   106,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   136,   137,     0,     0,     0,     0,
     139,   140,     0,     0,     0,     0,     0,     0,   251,     0,
       0,   252,     0,     0,   253,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,     0,
       0,     0,    51,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
    1249,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,  1369,
       0,     0,   145,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   409,
       0,     0,     0,   150,     0,     0,     0,     0,   257,     0,
     101,   248,     0,   154,     0,   740,   104,   105,   106,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,     0,     0,     0,     0,   139,
     140,     0,     0,     0,     0,     0,     0,   251,     0,     0,
     252,     0,     0,   253,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,     0,     0,
       0,    51,     0,     0,    54,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,  1400,     0,
       0,     0,   394,     0,   142,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   256,     0,
       0,     0,   150,     0,     0,     0,     0,   257,     0,   101,
     248,     0,   154,     0,  1245,   104,   105,   106,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   136,   137,     0,     0,     0,     0,   139,   140,
       0,     0,     0,     0,     0,     0,   251,     0,     0,   252,
       0,     0,   253,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,     0,     0,     0,
      51,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,  1428,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,  1516,     0,
     145,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   461,  1345,     0,     0,
       0,   150,     0,     0,     0,     0,   463,     0,   101,   285,
     103,   154,     0,   217,   104,   105,   106,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   101,   285,   103,   138,   139,   140,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,   142,   143,   144,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,     0,     0,     0,
     154,     0,  1181,     0,     0,     0,     0,   142,   143,   144,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,   150,     0,     0,     0,     0,
     257,     0,   101,   285,   103,   154,     0,  1361,   104,   105,
     106,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   101,   285,     0,
     138,   139,   140,   104,   105,   106,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,     0,     0,     0,     0,   139,   140,   101,   285,
       0,     0,     0,     0,   104,   105,   106,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     135,   136,   137,   145,   146,   147,     0,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,     0,   150,     0,     0,     0,     0,   257,
       0,     0,     0,     0,   154,     0,  1559,     0,     0,     0,
       0,   142,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,     0,     0,     0,   150,
       0,     0,     0,     0,   257,     0,     0,   726,     0,   154,
       0,   727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   257,     0,   101,   285,     0,
     154,     0,   365,   104,   105,   106,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   101,   248,     0,     0,   139,   140,   104,   105,
     106,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,     0,     0,     0,
       0,   139,   140,     0,     0,     0,     0,     0,     0,   251,
       0,     0,   252,     0,     0,   253,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
       0,   142,     0,    51,     0,     0,    54,     0,   145,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   461,   462,  1570,     0,     0,   150,
       0,     0,     0,     0,   463,     0,     0,     0,     0,   154,
       0,   217,     0,     0,     0,     0,   142,     0,     0,     0,
    1606,   509,     0,   145,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     409,     0,     0,     0,   150,   101,   285,   103,     0,   257,
       0,   104,   105,   106,   154,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,     0,
       0,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     101,   285,     0,   138,   139,   140,   104,   105,   106,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,  1636,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,     0,     0,     0,     0,   139,
     140,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   509,     0,     0,     0,   394,
       0,     0,     0,     0,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   648,   392,   393,   750,   142,
     143,   144,   394,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   846,     0,     0,
       0,     0,   148,   149,     0,     0,     0,   150,     0,     0,
       0,     0,   257,     0,     0,     0,   965,   154,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,  1126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   149,     0,
       0,     0,   150,     0,     0,     0,     0,   257,     0,     0,
       0,     0,   154,     0,     0,     0,     0,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   648,
     392,   393,     0,     0,     0,     0,   394,     0,     0,     0,
       0,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,    -4,     1,     0,   394,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
      -4,    -4,  1325,     0,  1326,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,    -4,     6,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,    -4,    -4,     0,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,    14,    15,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     7,     8,     0,    57,    58,    59,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,    61,    62,    63,
      64,     0,     0,    65,     0,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
       0,    78,    79,    80,    81,     0,     0,     0,     0,   612,
      20,    21,   613,    23,    24,   614,    26,   615,    28,     0,
      29,     0,     0,     0,    33,    34,     0,    36,    37,    38,
       0,     0,     0,    41,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,     0,     0,     0,     0,     0,  1356,
       0,  1357,     0,     0,     0,     0,    62,    63,    64,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,  1454,     0,  1455,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,   889,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,   939,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
     959,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,     0,     0,   980,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,  1075,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,  1323,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,  1342,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
    1385,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,     0,     0,  1386,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,  1387,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,  1388,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,  1389,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
    1423,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,     0,     0,  1470,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,  1476,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,  1477,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,  1498,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
    1501,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,     0,     0,  1504,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,  1527,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,  1530,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,     0,  1564,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
    1566,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,     0,     0,  1568,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,  1581,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,  1608,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,   681,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,     0,     0,     0,     0,     0,     0,  1399,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,   641,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
     688,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,   689,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,   747,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,   786,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,   787,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
     802,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,   803,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,   804,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,   805,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,   806,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
     807,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,   921,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,   922,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,   923,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,   954,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
    1034,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,  1073,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,  1074,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,  1125,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,  1283,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
    1284,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,  1291,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,  1435,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,  1436,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,     0,     0,     0,  1440,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
    1520,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,  1523,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,     0,  1562,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,   604,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,     0,     0,   752,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,   762,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,     0,     0,   765,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,   767,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,     0,     0,
     769,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,   771,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,     0,     0,   773,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,   775,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
       0,     0,   777,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,   779,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,     0,     0,   781,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,   783,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,     0,     0,   785,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,   789,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,     0,     0,
     791,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,   793,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,     0,     0,   795,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,   797,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
       0,     0,   799,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,   801,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,     0,     0,   947,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,   948,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,     0,     0,   952,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,   953,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,     0,     0,
     957,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,     0,     0,   981,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,     0,     0,  1029,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,     0,     0,  1137,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
       0,     0,  1139,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,     0,     0,  1141,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,     0,     0,  1143,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,     0,
       0,  1250,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,     0,     0,  1275,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,     0,     0,  1412,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,   600,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,   647,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
     651,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,   652,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,   654,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,   656,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,   657,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,   660,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,   661,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,   737,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,   743,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,   744,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
     745,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,   751,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,   764,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,   766,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,   768,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,   770,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,   772,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,   774,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,   776,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,   778,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
     780,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,   782,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,   784,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,   788,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,   790,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,   792,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,   794,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,   796,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,   798,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,   800,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
     878,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,   883,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,   888,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,   891,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,   892,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,   898,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,   905,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,   906,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,   907,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,   938,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
     940,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,   941,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,   942,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,   946,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394,     0,  1136,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   394,     0,  1138,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   394,     0,  1140,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,     0,  1142,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,     0,  1150,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,     0,  1324,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   394,     0,
    1341,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
       0,  1360,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,     0,  1519,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,     0,  1579,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   394
};

static const yytype_int16 yycheck[] =
{
       3,     6,     3,     6,   933,   225,   937,   210,   455,   456,
     176,     4,     4,  1243,   348,   181,     6,   237,     4,   185,
       4,     4,     4,   357,     4,     6,   192,     6,     4,     4,
       4,     6,     5,     5,     5,   122,     6,     6,   171,     6,
       6,     6,     6,     6,   177,     7,     4,     4,   135,   136,
       0,   367,     4,   100,   370,     6,     4,     4,     6,   167,
     168,   172,   282,   174,   284,     6,     3,     4,   179,   177,
     167,   168,     9,    10,    11,     7,  1306,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     160,   161,    44,    45,     8,    47,   160,   161,    45,    46,
      47,   173,    60,    60,   176,    52,    53,    64,   178,   160,
     161,     7,   176,    60,   178,    13,    63,     7,    75,    66,
     170,    68,   112,   113,   114,   115,   177,   177,   160,   161,
     110,    63,    79,    66,    66,   131,   110,   110,  1378,    86,
      87,    88,    89,    90,   155,   177,   170,    94,     8,   110,
      97,   164,   165,   177,   122,   123,   173,  1096,  1398,   176,
     122,   123,   167,   168,   164,   165,   167,   168,   170,   172,
       6,   174,   177,   174,     6,   177,   179,   170,   157,   170,
       6,   177,   157,   177,   177,   177,   177,   172,   178,   365,
     137,   177,   368,   177,   177,   177,   177,   144,   145,   146,
     177,   177,   174,   170,   170,   147,   148,   149,   150,   160,
     161,   160,   161,   160,   161,   170,   446,   447,   165,   160,
     161,    63,   177,   170,    66,   167,   168,   176,   175,   178,
     177,   178,   174,     6,     7,   176,   466,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   147,   148,   149,   150,   169,     6,   147,   148,   149,
     150,   213,   214,   170,   178,   160,   161,   167,   168,   221,
     177,   167,   168,   225,   600,     6,   291,   177,   604,   170,
       8,   176,  1522,   178,     4,     5,   160,   161,   518,   160,
     161,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   176,   482,   483,   484,   169,
     160,   161,   171,   370,   172,   160,   161,   176,   178,    39,
      40,    41,    42,    43,    44,   170,   176,   503,   195,   196,
     197,    51,   177,   172,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   170,   359,   360,   361,   349,
     350,   351,   352,   353,   354,   355,   356,    66,   171,   359,
     360,   361,  1602,   176,   231,   232,   160,   161,   172,    66,
     174,    68,     3,     4,     5,   179,   243,   244,     9,    10,
      11,   170,   176,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   674,   675,   676,    39,    40,
      41,    42,    43,    44,    45,    46,    47,   170,   138,   139,
      51,    52,    53,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     4,     5,   160,
     161,   169,     7,   171,   455,   456,   170,   160,   161,   160,
     161,     7,    60,     5,   684,    63,   177,   173,    66,   176,
     176,   178,   638,   176,   640,   176,  1407,   170,  1409,   172,
    1411,   170,    39,    40,    41,    42,    43,    44,   160,   161,
     171,   538,   170,     4,    51,   176,    70,    39,    40,    41,
      42,    43,    44,   171,   176,   160,   161,    66,   176,    51,
     131,   453,   454,     6,     7,   681,   137,   138,   139,   461,
     170,   176,   172,   144,   145,   146,   160,   161,   171,  1458,
     160,   161,  1461,   176,     6,  1464,   160,   161,   177,   160,
     161,   170,   176,   172,   165,   174,   176,    66,   177,   170,
     179,   172,   176,   174,   175,   171,   177,   604,   179,   725,
     176,   727,   160,   161,    66,   171,   732,   733,   734,   735,
     176,   170,   170,   172,   740,    86,    87,    88,    89,   177,
    1511,   138,   139,    94,   173,   173,    97,   176,   176,   160,
     161,    68,   147,   148,   149,   150,   138,   139,   160,   161,
     605,   147,   148,   149,   150,   176,   170,   160,   161,    63,
     167,   168,   167,   168,   176,    63,  1545,   174,    66,   177,
      68,   167,   168,   176,   160,   161,   171,   177,   160,   161,
      66,   176,  1563,    63,  1565,   838,  1567,   160,   161,    63,
     176,   644,  1573,   646,   176,   171,   812,   176,   814,   178,
     176,   160,   161,   176,    66,     4,   646,  1586,     4,    63,
    1589,     4,    66,  1592,    68,   170,  1595,   176,   673,   674,
     675,   676,   170,     4,   172,   841,   842,   843,   844,  1610,
     170,  1612,   729,  1614,   170,   170,  1002,   172,   170,  1005,
    1006,     6,     6,    82,     6,   170,  1625,   172,  1627,   170,
    1629,   172,   170,    92,   172,   160,   161,   162,   163,   164,
     172,   100,   101,   102,   169,   762,     4,   106,   107,   108,
     109,   162,   163,   164,   890,   170,   179,   172,   169,     4,
      82,    12,    13,    60,     7,   170,    63,   172,   170,    66,
      92,    68,   170,    82,   172,   687,     6,   170,   100,   101,
     102,   170,   694,    92,   106,   107,   108,   109,   700,   762,
     170,   100,   101,   102,   170,   170,   172,   106,   107,   108,
     109,   170,   762,   172,  1221,  1222,   170,   170,   172,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   178,
      71,   170,   170,   172,    75,    76,   170,    78,    79,    80,
     170,    60,   172,    84,    63,   170,   809,    66,   170,    68,
    1013,   170,   815,   172,     4,   818,   819,   820,   176,   809,
     178,    81,   825,   177,   177,   815,   178,     6,   818,   819,
     820,   176,   170,   178,   172,   825,   117,   118,   119,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     6,   170,    82,   172,   169,   177,   862,
     170,   170,   172,   172,   170,    92,   172,   170,   170,   172,
     172,   170,   862,   100,   101,   102,   176,     4,   178,   106,
     107,   108,   109,   176,   176,   178,   178,   177,   148,   149,
     150,   151,   152,   176,   176,   178,   178,   178,   176,   176,
     178,   178,   176,   163,   178,   170,    66,   167,    68,    66,
     957,    68,   176,    82,   178,   175,   176,   177,   178,   170,
     180,   181,   182,   183,   170,   185,   186,   187,   177,   176,
     872,   178,   192,   176,   176,   178,   178,  1103,   176,   176,
     178,   178,   176,    82,   178,   170,   176,   207,   178,   170,
     176,   178,   178,    92,   170,  1402,   216,   217,   177,  1006,
    1163,   100,   101,   102,   176,   225,   178,   106,   107,   108,
     109,   176,   176,   178,   178,   176,   176,   178,   178,   921,
     922,   923,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   256,   257,   258,   176,
     169,   178,     4,   176,     6,   178,   170,   267,   268,   269,
     176,   271,   178,   172,   274,   275,   170,     6,   278,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
    1035,   176,   170,   178,   169,   176,   176,   178,   178,   178,
     176,   301,   178,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,  1134,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   176,   358,   178,
     176,   169,   178,   177,   176,   365,   178,   176,   368,   178,
     176,   176,   178,   178,   176,   176,   178,   178,   378,   177,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   176,   176,   178,   178,   176,
     176,   178,   178,   176,  1147,   178,   176,   170,   178,   409,
    1155,   170,   176,  1095,   178,   415,   176,  1147,   178,     6,
     420,   170,   177,   177,   177,   425,   426,  1370,   428,   429,
       5,   172,   172,   433,   172,  1178,  1181,   172,   438,   439,
     440,     5,     5,   174,     6,     6,   125,   177,  1178,     6,
       6,     6,   177,   172,     6,  1361,  1416,     4,   458,   459,
     460,   461,   462,   463,   169,   174,  1253,   467,   468,   469,
     470,   471,  1217,     7,   172,   475,   177,     7,   478,   479,
    1221,  1222,   482,   483,   484,  1559,   178,   487,   488,   489,
       7,   491,     7,  1399,   170,   495,   170,   170,   170,     7,
     171,     6,     6,   503,     7,  1187,     7,   177,     6,   509,
     510,   176,     6,   188,  1420,     6,   181,  1262,     4,     4,
     185,   177,   177,   177,   177,   122,   177,   192,   528,    82,
     171,   206,   532,     6,   209,     6,   536,   176,   171,    92,
     171,  1223,   176,  1225,   176,  1227,   176,   100,   101,   102,
     176,   171,  1512,   106,   107,   108,   109,   176,   233,  1241,
       6,     4,  1244,  1245,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   173,     4,
       6,   125,   169,     6,     4,     6,   125,   125,     7,     7,
       7,   256,     7,   258,     7,     7,     7,     7,   177,     4,
       6,   174,    82,     6,   178,   173,   606,  1513,   178,  1515,
       7,     7,    92,   288,   289,     7,   174,   177,     6,     6,
     100,   101,   102,   298,   173,   178,   106,   107,   108,   109,
     171,     6,     6,    82,     7,   635,   172,     6,   638,   170,
     640,   641,   170,    92,   177,     6,   157,   179,   648,   649,
       7,   100,   101,   102,     7,     7,     7,   106,   107,   108,
     109,  1402,   662,     7,    68,     7,     7,     6,   668,  1575,
       7,   171,   171,   673,   674,   675,   676,     7,   171,   171,
       7,   681,     7,     6,     4,     4,   170,   177,   688,   689,
       6,     6,     4,     7,   694,     6,    82,     7,   178,   177,
     365,     7,     7,   368,    12,    13,    92,   707,     6,     6,
     710,     6,    66,     6,   100,   101,   102,     6,     4,     4,
     106,   107,   108,   109,  1406,   725,  1408,   727,  1410,   178,
     178,     6,   732,   733,   734,   735,  1418,     4,     6,  1421,
     740,   171,   176,   171,   409,   174,     7,   747,   170,   749,
     750,     6,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   171,    71,    82,     6,   174,    75,    76,   171,
      78,    79,    80,    75,    92,     6,    84,   177,   177,  1524,
    1525,     6,   100,   101,   102,     6,   786,   787,   106,   107,
     108,   109,   178,   177,   177,   177,   177,     6,     6,     5,
       4,     6,   802,   803,   804,   805,   806,   807,     7,   117,
     118,   119,   812,     7,   814,     7,  1559,   482,   483,   484,
       7,     7,   177,   823,   172,     6,     6,   827,   177,     6,
       6,   831,   177,  1515,   177,  1578,   171,   177,   503,   173,
       4,   841,   842,   843,   844,   510,   846,     6,  1578,     6,
     121,     6,    12,    13,   176,     6,     6,     4,     6,    82,
     178,  1606,     6,     6,     6,     6,     4,     6,     5,    92,
     178,     6,     6,     6,  1617,     6,  1619,   100,   101,   102,
      12,    13,     6,   106,   107,   108,   109,  1617,   125,  1619,
     890,  1636,     6,   177,     6,     6,     6,  1640,     6,     6,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    1640,    71,   176,     6,     6,    75,    76,     6,    78,    79,
      80,     6,   171,     6,    84,     6,     6,   602,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     7,    71,
       6,   174,   177,    75,    76,     6,    78,    79,    80,     5,
     177,   951,    84,     6,   954,   178,     6,   117,   118,   119,
      64,     6,     6,     6,     6,   965,   177,     6,   178,     7,
       6,   178,     6,   638,   177,   640,   177,   177,   123,   177,
     120,   178,    82,   648,   649,   117,   118,   119,     6,     6,
       6,     6,    92,     6,   669,     6,     6,     6,   177,     6,
     100,   101,   102,    82,     6,   680,   106,   107,   108,   109,
       6,     6,   177,    92,  1014,   177,   681,   178,   178,     6,
      82,   100,   101,   102,  1024,  1025,     6,   106,   107,   108,
     109,   177,     4,     4,  1034,  1035,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,   178,     6,   178,   177,
     177,   177,   177,     6,     6,     6,    12,    13,     6,     6,
     725,   177,   727,     6,   177,     6,     6,   732,   733,   734,
     735,   177,  1072,  1073,  1074,   740,   177,     6,   178,   177,
       6,   756,  1082,     6,  1084,     6,     6,     6,     6,     6,
       6,  1040,  1481,  1032,   407,  1095,     3,     3,  1159,   178,
     432,    -1,    -1,  1103,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      76,    -1,    78,    79,    80,  1125,  1126,  1127,    84,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   812,    -1,   814,
      -1,   169,    -1,    -1,    -1,    -1,  1156,    -1,    -1,    -1,
      -1,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,  1169,
      -1,    -1,    -1,    -1,  1174,    -1,   841,   842,   843,   844,
      -1,  1181,    -1,    12,    13,  1185,  1186,    -1,    -1,    -1,
      -1,    -1,  1192,  1193,    -1,    -1,    -1,  1197,    -1,    -1,
      -1,   876,   877,    -1,   879,  1205,   881,   882,    -1,    -1,
     885,   886,    -1,    -1,    -1,  1215,    -1,  1217,    -1,    -1,
      -1,    -1,   178,    -1,    -1,   890,    -1,    -1,    -1,  1229,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,  1241,    71,    -1,    -1,  1245,    75,    76,  1248,    78,
      79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,  1262,    12,    13,    -1,    -1,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,  1283,  1284,    -1,   169,    -1,   117,   118,
     119,  1291,   967,   968,   969,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   977,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    -1,  1325,    75,    76,    -1,    78,
      79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1343,    -1,  1345,    -1,    -1,    -1,   178,
      -1,  1026,    -1,    -1,    -1,    -1,  1356,    -1,  1358,    -1,
      -1,  1361,    -1,    -1,    -1,    -1,  1041,    -1,   117,   118,
     119,    -1,  1047,    -1,  1374,    -1,    -1,    -1,  1053,  1379,
    1055,  1056,    -1,    -1,    -1,  1060,    -1,    -1,    -1,    -1,
    1065,  1066,  1067,    -1,     6,    -1,    -1,    -1,    -1,  1399,
      -1,    -1,    -1,    -1,    -1,    -1,  1406,  1082,  1408,    -1,
    1410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1420,    -1,  1097,    -1,  1424,    -1,  1101,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,  1435,  1436,    -1,  1103,    -1,
    1440,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
    1450,    -1,    -1,    -1,  1454,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     8,
      -1,    -1,    -1,   169,    -1,    -1,    -1,  1152,    -1,  1154,
      -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1492,    -1,    -1,    -1,    -1,    -1,    -1,  1499,
      -1,    -1,  1502,    -1,    -1,  1505,    -1,    -1,    -1,  1509,
      -1,    -1,    -1,  1513,    -1,  1515,    -1,    -1,    -1,    -1,
    1520,    -1,    -1,  1523,    -1,  1525,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1208,  1209,  1210,  1211,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,  1556,   169,    -1,    -1,
      -1,    -1,  1562,    -1,    -1,    -1,    -1,    -1,  1243,    -1,
      -1,    -1,    -1,    -1,    -1,  1575,  1241,    -1,    -1,    -1,
    1245,  1256,    -1,    -1,    -1,    -1,    -1,    -1,  1263,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,  1604,    -1,    -1,   169,    -1,    -1,
    1285,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     3,     4,    -1,    -1,
     169,  1306,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,  1340,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    82,    52,    53,    -1,    -1,    -1,
    1345,    -1,    -1,    60,    92,    -1,    63,    -1,    -1,    66,
      -1,    68,   100,   101,   102,    -1,  1361,    -1,   106,   107,
     108,   109,    79,  1378,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,  1398,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1399,    -1,    -1,    -1,    -1,    -1,
    1415,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,  1420,    -1,    -1,    -1,   169,
     137,   171,    -1,    -1,    -1,    -1,   176,   144,   145,   146,
     178,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   160,   161,    -1,    -1,   169,   165,    -1,
      -1,  1466,    -1,   170,    -1,    -1,    -1,    -1,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,  1522,  1513,  1524,
    1515,    -1,    45,    46,    47,    -1,     3,     4,     5,    52,
      53,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,  1556,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
    1575,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    -1,  1602,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,   137,    -1,    -1,    94,    -1,    -1,
      97,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
     173,    -1,   175,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,    -1,
      -1,    -1,    -1,   170,    -1,     3,     4,     5,   175,    -1,
     177,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    12,
      13,    -1,    60,    -1,    -1,    63,    -1,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    80,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   117,   118,   119,   165,    -1,    -1,
      -1,    -1,   170,    -1,     3,     4,     5,   175,    -1,   177,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,   178,    -1,    -1,    12,    13,
      -1,    60,    -1,    -1,    63,    -1,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    -1,    -1,
      -1,    75,    76,    -1,    78,    79,    80,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   117,   118,   119,   165,    -1,    -1,    -1,
      -1,   170,    -1,     3,     4,    -1,   175,    -1,   177,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,   178,    -1,    -1,    12,    13,    -1,
      60,    -1,    -1,    63,    -1,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,
      75,    76,     6,    78,    79,    80,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,     6,    -1,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   117,   118,   119,   165,    -1,    -1,    -1,    -1,
     170,    -1,     3,     4,    -1,   175,    -1,   177,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    53,   178,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    63,    -1,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       6,    -1,    -1,    -1,   169,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,   170,
      -1,     3,     4,    -1,   175,    -1,   177,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    63,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
       6,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,     6,
      -1,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,   170,    -1,
       3,     4,    -1,   175,    -1,   177,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    97,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     6,    -1,
      -1,    -1,   169,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,    -1,    -1,    -1,    -1,   170,    -1,     3,
       4,    -1,   175,    -1,   177,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,
      -1,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,     6,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,     6,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,   170,    -1,     3,     4,
       5,   175,    -1,   177,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     3,     4,     5,    51,    52,    53,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    53,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,   137,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
     175,    -1,   177,    -1,    -1,    -1,    -1,   137,   138,   139,
      -1,    -1,    -1,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
     170,    -1,     3,     4,     5,   175,    -1,   177,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,     4,    -1,
      51,    52,    53,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    52,    53,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
      45,    46,    47,   144,   145,   146,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,   175,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,   170,    -1,     3,     4,    -1,
     175,    -1,   177,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,     3,     4,    -1,    -1,    52,    53,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    63,    -1,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      -1,   137,    -1,    94,    -1,    -1,    97,    -1,   144,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,     6,    -1,    -1,   165,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,   175,
      -1,   177,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
       7,     8,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,     3,     4,     5,    -1,   170,
      -1,     9,    10,    11,   175,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,     4,    -1,    51,    52,    53,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     8,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     8,   137,
     138,   139,   169,    -1,    -1,    -1,   144,   145,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,     8,   175,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,     0,     1,    -1,   169,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      37,    38,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,    -1,    -1,    -1,   111,     4,    -1,    -1,    -1,   116,
     117,   118,   119,    12,    13,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      -1,    -1,    -1,   140,   141,   142,   143,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    12,    13,    -1,   103,   104,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,    -1,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,   141,   142,   143,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    -1,    -1,    -1,    75,    76,    -1,    78,    79,    80,
      -1,    -1,    -1,    84,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,   178,    -1,    -1,    -1,    -1,   117,   118,   119,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,   176,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,   171,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,   171,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,   171,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,   171,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,   171,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,   171,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,   171,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,   171,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,   171,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,   171,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,   171,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,   171,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,   171,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,   171,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,   171,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,   171,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,
     171,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,   171,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,   171,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,   171,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   181,   182,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    54,    55,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   103,   104,   105,
     111,   116,   117,   118,   119,   122,   124,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   140,   141,
     142,   143,   183,   185,   186,   204,   218,   223,   226,   227,
     228,   229,   230,   231,   232,   252,   253,   254,   255,   271,
     272,     3,     4,     5,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    51,    52,
      53,   131,   137,   138,   139,   144,   145,   146,   160,   161,
     165,   170,   172,   174,   175,   177,   179,   256,   257,   268,
     269,   272,    13,    66,   170,   170,     6,   177,     6,     6,
       6,     6,     6,   172,   172,   170,   177,   170,   170,     4,
     170,   177,   170,   170,     4,   177,   170,   170,    70,    66,
      66,     6,   177,    66,    66,    63,    66,    68,    68,    60,
      63,    66,    68,    63,    66,    68,    63,    66,   170,    63,
     122,   135,   136,   177,   160,   161,   170,   177,   258,   259,
     258,   177,    60,    63,    66,   177,   258,     4,    60,    64,
      75,    66,    68,    66,    63,     4,   131,   177,     4,     6,
      60,    63,    66,    63,    66,     4,     4,     4,     4,     5,
      36,    60,    63,    66,    68,    79,   161,   170,   177,   223,
     232,   256,   261,   262,   263,   272,     4,   170,   170,   170,
       4,   177,   265,     4,   170,   170,     6,     6,   172,     4,
       4,     5,   177,     5,   177,     4,   256,     6,   170,   177,
     179,     7,   147,   148,   149,   150,   167,   168,   202,   203,
       4,   172,   174,   170,   172,   170,   172,   170,   172,   170,
     172,   170,   172,   170,   172,   170,   172,   170,   172,   170,
     172,   170,   172,   170,   172,   170,   172,   170,   172,   170,
     172,   170,   172,   170,   172,   170,   172,   170,   172,   170,
     172,   170,   172,   170,   172,   170,   172,   170,   172,   170,
     172,   170,   170,   170,   170,   170,   170,   170,     7,   170,
     170,   170,   256,   256,   256,   177,   256,   173,   177,   256,
       4,   122,   123,     4,     4,   223,   224,   225,   177,     6,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   169,   177,     6,   203,     6,   256,
       4,   268,   269,   272,   268,   256,   206,   209,   256,   161,
     256,   263,   264,   256,   256,   170,   256,   264,   256,   256,
     170,   264,   256,   256,   261,   170,   177,   264,   170,   170,
     262,   262,   262,   170,   219,   220,   221,   222,   170,   170,
     170,   261,   256,     4,   261,   265,   177,   177,   258,   258,
     258,   256,   256,   160,   161,   177,   177,   258,   177,   177,
     177,   160,   161,   170,   225,   258,   177,   170,   177,   170,
     170,   170,   262,   262,   261,   170,     4,     6,   172,   172,
     225,     6,   177,   177,   177,   262,   262,   172,   172,   172,
     170,   172,   174,   172,     5,   177,     5,     5,     5,    60,
      63,    66,    68,   177,   256,   263,   256,   178,   264,     8,
     162,     6,     6,   256,   256,   256,   174,   256,   177,   125,
     256,   256,   256,     6,     6,   225,     6,   225,   172,     6,
     261,   261,   177,   269,   261,     6,   172,   256,     4,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   268,   270,   270,   268,   268,   268,   268,
     268,   268,   268,   268,   270,   256,   268,   268,   268,   264,
     171,     7,   202,   264,   173,     7,   202,   203,   174,     7,
     172,   178,    60,    63,    66,    68,   218,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   187,     6,   172,   174,   171,   176,   171,
     176,   176,   173,   176,   205,   173,   205,   171,   162,   176,
     178,   171,   171,   256,   171,   178,   171,   171,   256,   178,
     171,   171,     7,   256,   256,   178,   256,   256,     7,     7,
     250,   250,   256,   170,   170,   170,   170,   256,   256,   256,
       7,   177,   171,     6,   177,   225,   225,   176,   176,   176,
     258,   258,   224,   224,   176,   256,   256,   256,   256,   236,
     176,   225,   256,   256,   256,   256,   256,     7,   251,     6,
       7,   256,     6,   256,   256,   178,   264,   264,   264,     6,
       6,   256,   256,   256,   171,   177,   173,   177,   256,     4,
       4,   256,   177,   177,   177,   177,   264,   171,   178,   256,
     177,   256,   263,   171,   171,   171,   122,   176,   225,   177,
       8,   171,   173,   178,   178,   171,   176,   178,   256,     6,
       6,   256,   173,   203,   171,   173,   171,   173,   171,   173,
     171,   173,   171,   173,   171,   173,   171,   173,   171,   173,
     171,   173,   171,   173,   171,   173,   176,   176,   171,   173,
     171,   173,   171,   173,   171,   173,   171,   173,   171,   173,
     171,   173,   176,   176,   176,   176,   176,   176,   171,   176,
     173,   171,   176,   173,   176,   176,   171,   171,   176,   176,
     176,   171,     6,   176,   171,   176,   178,   202,   261,   178,
     174,   202,   203,   269,   256,     6,     4,     4,   177,   266,
     173,   177,   177,   177,   177,   178,     8,     4,   112,   113,
     114,   115,   178,   190,   194,   197,   199,   200,   256,     4,
       6,   157,   184,   264,     6,   264,   256,     6,     4,   272,
       6,   268,     7,   256,   263,   125,     7,     7,   171,     7,
     125,     7,     7,   171,   125,     7,     7,   256,   171,   178,
     177,   171,   171,   256,   261,     4,   249,     6,   171,   215,
     256,   269,   215,   215,   215,   171,   171,   171,   261,   264,
     174,   225,   178,   178,   258,   256,   256,   178,   178,   256,
     258,   176,   176,   176,    82,    92,   100,   101,   102,   106,
     107,   108,   109,   246,   247,   258,   178,   233,   171,   178,
     171,   171,   171,   256,     6,   256,   171,   173,   173,   178,
     178,   178,   173,   173,   176,   264,   264,   173,   173,   178,
     264,   264,   264,   264,   178,     8,   264,     7,     7,     7,
     174,   256,   178,   256,   256,     7,   174,   177,   261,     6,
     178,   173,   174,   203,   268,   256,   256,   256,   256,   256,
     256,   256,   256,   268,   264,   264,   268,   268,   268,   268,
     256,   268,   171,   256,     6,   173,     4,   122,   123,   256,
       6,     6,     6,     7,   172,   265,   267,     6,   264,   264,
     264,   264,   256,   191,   170,   170,   177,   201,     6,   173,
     157,   268,   171,   171,   176,     7,   258,    66,    68,   261,
     261,     7,   261,    66,    68,   261,   261,     7,    68,   261,
     261,     6,     7,     7,   264,     7,     7,    82,   248,     6,
       7,   171,   171,   171,   171,     7,     7,     7,     6,   178,
       4,   178,   176,   176,   176,   178,   178,   258,   258,   258,
       4,     6,   177,     6,   170,     6,   110,     6,   110,     6,
     110,     6,   110,   178,   247,   176,   246,     7,     6,     7,
       7,     7,     6,   177,     6,     6,     6,    66,   256,     6,
       6,   256,   178,   178,   174,   178,   178,   178,   178,   256,
     178,   261,   261,   261,     4,   176,     8,     8,   171,     4,
       4,   261,   178,     6,     4,     6,   171,   173,   171,   173,
     171,   173,   171,   173,   171,   173,   171,   176,   171,   171,
     171,   171,   202,     6,   202,     7,   202,   203,   174,     7,
       6,   265,   256,   176,   178,   178,   178,   178,   178,   170,
     256,   256,   260,   261,   177,   174,     6,     6,   184,     6,
     256,   177,   256,   269,     6,   177,   177,    75,   217,   217,
     261,     6,   177,   177,     6,     6,   261,   177,     6,     6,
       5,   261,   178,   261,   261,     4,     6,   261,     7,     7,
       7,     7,   261,   261,   261,     7,     6,     7,   256,   256,
     256,   177,   177,   176,   178,   176,   178,   176,   178,   172,
     256,   261,   256,     6,     6,     6,     6,   256,   258,   178,
       5,   177,   261,   177,   177,   177,   261,   264,   177,     6,
     173,   171,   173,     4,     6,     6,   121,   256,   256,   256,
       6,     6,     7,   176,     6,   203,   268,   261,   261,   269,
     256,     6,     4,   266,     6,   173,   265,     6,     6,     6,
       6,   188,   256,   176,   176,   176,   178,   189,   256,     4,
     268,   176,   256,   269,   256,   256,   258,     6,     6,     6,
     256,   256,     6,   256,     5,     6,   177,     6,   125,   216,
     256,     6,   261,   261,   261,   261,     6,     4,     6,     6,
     256,   256,   269,   178,   171,   176,   178,   224,   224,   258,
       6,   237,   258,     6,   238,   258,     6,   239,   256,   178,
     176,   171,   178,   176,     6,   161,   258,     6,   260,   258,
     258,     6,   178,   256,     6,   261,   176,   178,     8,   178,
     171,   177,   256,   269,   261,   171,     6,     6,     6,     6,
       7,     6,   174,   171,   176,   256,   256,   261,   177,   176,
     178,     6,   256,   207,   208,   178,   178,   178,   178,   178,
       5,   260,    64,     6,     6,     6,     6,     6,   177,   177,
       6,     6,   177,   256,   178,   178,   176,   177,   176,   177,
     176,   177,   173,     6,   261,     7,   177,   256,   176,   178,
     176,   176,     6,   178,   120,   256,   256,   264,     6,     6,
     178,   265,   123,   192,   256,   176,   176,   260,   256,     6,
     176,   211,   213,     6,     6,     6,     6,     6,     6,   178,
     177,   260,   264,   224,   176,   178,   256,   258,   246,   256,
     258,   246,   256,   258,   246,     6,   176,   178,   261,   225,
     178,   258,     6,   264,   258,   256,   178,   178,   178,     6,
       6,   177,   256,   256,   178,   256,   176,   178,   212,   176,
     178,   214,   177,   256,   178,   178,   178,   256,   178,   176,
     178,   178,   176,   178,   178,   176,   178,   261,     6,    82,
     178,   234,   177,   176,   178,   176,     6,     6,   189,   171,
     176,     6,   177,   176,     4,     4,   256,   178,     6,     6,
     178,     6,   240,   256,     6,     6,   241,   256,     6,     6,
     242,   256,     6,   178,   256,   246,   225,   264,     6,   258,
     264,   178,   195,   256,   260,   256,   177,   261,   269,   177,
     256,   269,   176,   177,   178,   177,   178,   177,   178,     6,
       6,   178,   178,   235,   178,   176,   178,     6,   177,   171,
     178,   178,   210,   256,   270,   256,   246,     6,   243,   246,
       6,   244,   246,     6,   245,   246,     6,   264,     6,   193,
     268,   198,   177,     6,   176,   178,     7,   178,   178,   178,
     177,   178,   177,   178,   177,   178,   178,   176,   178,   177,
     260,   256,   269,     6,     6,   246,     6,   246,     6,   246,
       6,   268,     6,   196,   268,   178,     7,   178,   178,   178,
     176,   178,     6,   269,     6,     6,     6,   268,     6
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
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 31:
#line 318 "Gmsh.y"
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
    ;}
    break;

  case 32:
#line 331 "Gmsh.y"
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
    ;}
    break;

  case 33:
#line 349 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 39:
#line 363 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 40:
#line 365 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 41:
#line 370 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 42:
#line 372 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 43:
#line 377 "Gmsh.y"
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

  case 44:
#line 481 "Gmsh.y"
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

  case 45:
#line 491 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 46:
#line 500 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 507 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 517 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 49:
#line 526 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 50:
#line 535 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 542 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 552 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 53:
#line 560 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
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
	(ViewData->NbSY || ViewData->NbVY) ? TYPE_PYR :
	(ViewData->NbSI || ViewData->NbVI) ? TYPE_PRI :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (8)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (8)].l)));
#endif
    ;}
    break;

  case 55:
#line 589 "Gmsh.y"
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

  case 56:
#line 608 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 57:
#line 614 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 621 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 59:
#line 622 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 623 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 61:
#line 624 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 62:
#line 625 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 63:
#line 629 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 630 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:
#line 641 "Gmsh.y"
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

  case 68:
#line 703 "Gmsh.y"
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

  case 69:
#line 733 "Gmsh.y"
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
#line 768 "Gmsh.y"
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

  case 71:
#line 802 "Gmsh.y"
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
#line 850 "Gmsh.y"
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

  case 73:
#line 897 "Gmsh.y"
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

  case 74:
#line 912 "Gmsh.y"
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

  case 75:
#line 928 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:
#line 937 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:
#line 943 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 78:
#line 952 "Gmsh.y"
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

  case 79:
#line 970 "Gmsh.y"
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

  case 80:
#line 988 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 81:
#line 997 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 82:
#line 1009 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:
#line 1014 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:
#line 1022 "Gmsh.y"
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

  case 85:
#line 1042 "Gmsh.y"
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

  case 86:
#line 1065 "Gmsh.y"
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

  case 87:
#line 1076 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 88:
#line 1084 "Gmsh.y"
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

  case 89:
#line 1106 "Gmsh.y"
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

  case 90:
#line 1129 "Gmsh.y"
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

  case 91:
#line 1155 "Gmsh.y"
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

  case 92:
#line 1176 "Gmsh.y"
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

  case 93:
#line 1188 "Gmsh.y"
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

  case 97:
#line 1206 "Gmsh.y"
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

  case 98:
#line 1217 "Gmsh.y"
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

  case 99:
#line 1228 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:
#line 1230 "Gmsh.y"
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

  case 101:
#line 1240 "Gmsh.y"
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

  case 102:
#line 1251 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:
#line 1253 "Gmsh.y"
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

  case 105:
#line 1267 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 106:
#line 1275 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 107:
#line 1281 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 110:
#line 1293 "Gmsh.y"
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

  case 111:
#line 1304 "Gmsh.y"
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

  case 112:
#line 1319 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 115:
#line 1335 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 116:
#line 1343 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 117:
#line 1352 "Gmsh.y"
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

  case 118:
#line 1370 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 119:
#line 1374 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 120:
#line 1384 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 121:
#line 1388 "Gmsh.y"
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

  case 122:
#line 1400 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 123:
#line 1404 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 124:
#line 1414 "Gmsh.y"
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

  case 125:
#line 1437 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 126:
#line 1441 "Gmsh.y"
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

  case 127:
#line 1457 "Gmsh.y"
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

  case 128:
#line 1479 "Gmsh.y"
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

  case 129:
#line 1497 "Gmsh.y"
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

  case 130:
#line 1518 "Gmsh.y"
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

  case 131:
#line 1536 "Gmsh.y"
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

  case 132:
#line 1566 "Gmsh.y"
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

  case 133:
#line 1596 "Gmsh.y"
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

  case 134:
#line 1614 "Gmsh.y"
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

  case 135:
#line 1632 "Gmsh.y"
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

  case 136:
#line 1658 "Gmsh.y"
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

  case 137:
#line 1676 "Gmsh.y"
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

  case 138:
#line 1694 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 139:
#line 1698 "Gmsh.y"
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

  case 140:
#line 1717 "Gmsh.y"
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

  case 141:
#line 1735 "Gmsh.y"
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

  case 142:
#line 1774 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1780 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 144:
#line 1786 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 145:
#line 1793 "Gmsh.y"
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

  case 146:
#line 1818 "Gmsh.y"
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

  case 147:
#line 1843 "Gmsh.y"
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

  case 148:
#line 1860 "Gmsh.y"
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

  case 149:
#line 1880 "Gmsh.y"
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

  case 150:
#line 1913 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 151:
#line 1917 "Gmsh.y"
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

  case 152:
#line 1937 "Gmsh.y"
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

  case 153:
#line 1955 "Gmsh.y"
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

  case 154:
#line 1972 "Gmsh.y"
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

  case 155:
#line 1988 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 156:
#line 1992 "Gmsh.y"
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

  case 157:
#line 2014 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:
#line 2019 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 159:
#line 2024 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 160:
#line 2029 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2034 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 162:
#line 2039 "Gmsh.y"
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

  case 163:
#line 2062 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 164:
#line 2068 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 165:
#line 2078 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2079 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 167:
#line 2084 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 168:
#line 2088 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 169:
#line 2092 "Gmsh.y"
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

  case 170:
#line 2115 "Gmsh.y"
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

  case 171:
#line 2138 "Gmsh.y"
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

  case 172:
#line 2161 "Gmsh.y"
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

  case 173:
#line 2189 "Gmsh.y"
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

  case 174:
#line 2210 "Gmsh.y"
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

  case 175:
#line 2237 "Gmsh.y"
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

  case 176:
#line 2258 "Gmsh.y"
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

  case 177:
#line 2279 "Gmsh.y"
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

  case 178:
#line 2299 "Gmsh.y"
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

  case 179:
#line 2411 "Gmsh.y"
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

  case 180:
#line 2430 "Gmsh.y"
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

  case 181:
#line 2469 "Gmsh.y"
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

  case 182:
#line 2577 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 183:
#line 2586 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 184:
#line 2592 "Gmsh.y"
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

  case 185:
#line 2607 "Gmsh.y"
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

  case 186:
#line 2635 "Gmsh.y"
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

  case 187:
#line 2652 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 188:
#line 2661 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 189:
#line 2675 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2681 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 191:
#line 2687 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 192:
#line 2696 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 193:
#line 2705 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 194:
#line 2714 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 195:
#line 2728 "Gmsh.y"
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

  case 196:
#line 2773 "Gmsh.y"
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

  case 197:
#line 2790 "Gmsh.y"
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

  case 198:
#line 2805 "Gmsh.y"
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

  case 199:
#line 2824 "Gmsh.y"
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

  case 200:
#line 2836 "Gmsh.y"
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

  case 201:
#line 2860 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 202:
#line 2864 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 203:
#line 2869 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 204:
#line 2876 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 205:
#line 2882 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 206:
#line 2887 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 207:
#line 2893 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 208:
#line 2901 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 209:
#line 2905 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 210:
#line 2909 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 211:
#line 2915 "Gmsh.y"
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

  case 212:
#line 2969 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 213:
#line 2982 "Gmsh.y"
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

  case 214:
#line 2999 "Gmsh.y"
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

  case 215:
#line 3016 "Gmsh.y"
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

  case 216:
#line 3037 "Gmsh.y"
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

  case 217:
#line 3058 "Gmsh.y"
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

  case 218:
#line 3093 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 219:
#line 3101 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 220:
#line 3107 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 221:
#line 3114 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 222:
#line 3118 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 3127 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 224:
#line 3135 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 225:
#line 3143 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 226:
#line 3151 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 227:
#line 3157 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 228:
#line 3165 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 229:
#line 3171 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 230:
#line 3179 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 231:
#line 3185 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 232:
#line 3193 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 233:
#line 3199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 234:
#line 3207 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3214 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3221 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3228 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3235 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3249 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3256 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 242:
#line 3263 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 243:
#line 3270 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 244:
#line 3276 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3283 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 246:
#line 3289 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3296 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 248:
#line 3302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3309 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 250:
#line 3315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3322 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 252:
#line 3328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3335 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3348 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 257:
#line 3361 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3367 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 259:
#line 3374 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 260:
#line 3380 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 261:
#line 3391 "Gmsh.y"
    {
    ;}
    break;

  case 262:
#line 3394 "Gmsh.y"
    {
    ;}
    break;

  case 263:
#line 3400 "Gmsh.y"
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

  case 264:
#line 3412 "Gmsh.y"
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

  case 265:
#line 3432 "Gmsh.y"
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

  case 266:
#line 3456 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 267:
#line 3461 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 268:
#line 3465 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 269:
#line 3469 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 270:
#line 3473 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 271:
#line 3477 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 272:
#line 3481 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 273:
#line 3485 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 274:
#line 3489 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 275:
#line 3493 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 276:
#line 3497 "Gmsh.y"
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

  case 277:
#line 3516 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 278:
#line 3528 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 279:
#line 3532 "Gmsh.y"
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

  case 280:
#line 3547 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 281:
#line 3551 "Gmsh.y"
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

  case 282:
#line 3567 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 283:
#line 3571 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 284:
#line 3576 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 285:
#line 3580 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 286:
#line 3587 "Gmsh.y"
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

  case 287:
#line 3643 "Gmsh.y"
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

  case 288:
#line 3713 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 289:
#line 3718 "Gmsh.y"
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

  case 290:
#line 3785 "Gmsh.y"
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

  case 291:
#line 3821 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 292:
#line 3829 "Gmsh.y"
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

  case 293:
#line 3872 "Gmsh.y"
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

  case 294:
#line 3911 "Gmsh.y"
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

  case 295:
#line 3931 "Gmsh.y"
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

  case 296:
#line 3959 "Gmsh.y"
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

  case 297:
#line 3998 "Gmsh.y"
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

  case 298:
#line 4021 "Gmsh.y"
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

  case 299:
#line 4044 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 300:
#line 4048 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 301:
#line 4052 "Gmsh.y"
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

  case 302:
#line 4075 "Gmsh.y"
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

  case 303:
#line 4114 "Gmsh.y"
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

  case 304:
#line 4159 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 305:
#line 4163 "Gmsh.y"
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

  case 306:
#line 4173 "Gmsh.y"
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

  case 307:
#line 4207 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 308:
#line 4208 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 309:
#line 4209 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 310:
#line 4214 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 311:
#line 4220 "Gmsh.y"
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

  case 312:
#line 4232 "Gmsh.y"
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

  case 313:
#line 4250 "Gmsh.y"
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

  case 314:
#line 4277 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 315:
#line 4278 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 316:
#line 4279 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 317:
#line 4280 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 318:
#line 4281 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 319:
#line 4282 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 320:
#line 4283 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 321:
#line 4284 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 322:
#line 4286 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 323:
#line 4292 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 324:
#line 4293 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 325:
#line 4294 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 326:
#line 4295 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 327:
#line 4296 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 328:
#line 4297 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 329:
#line 4298 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 330:
#line 4299 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 331:
#line 4300 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 332:
#line 4301 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 333:
#line 4302 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 334:
#line 4303 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 335:
#line 4304 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 336:
#line 4305 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 337:
#line 4306 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 338:
#line 4307 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 339:
#line 4308 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 340:
#line 4309 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 341:
#line 4310 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 342:
#line 4311 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 343:
#line 4312 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 344:
#line 4313 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 345:
#line 4314 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 346:
#line 4315 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4316 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 348:
#line 4317 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4318 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 350:
#line 4319 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:
#line 4320 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 352:
#line 4321 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 353:
#line 4322 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 354:
#line 4323 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 355:
#line 4324 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 356:
#line 4327 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 357:
#line 4328 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 358:
#line 4329 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 359:
#line 4330 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 360:
#line 4331 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 361:
#line 4332 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 362:
#line 4333 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 363:
#line 4334 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 364:
#line 4335 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 365:
#line 4336 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 366:
#line 4337 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 367:
#line 4338 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 368:
#line 4339 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 369:
#line 4340 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 370:
#line 4341 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 371:
#line 4342 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 372:
#line 4343 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 373:
#line 4344 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5);    ;}
    break;

  case 374:
#line 4345 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 375:
#line 4346 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 376:
#line 4347 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 377:
#line 4348 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 378:
#line 4357 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 379:
#line 4358 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 380:
#line 4359 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 381:
#line 4360 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 382:
#line 4361 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 383:
#line 4362 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 384:
#line 4363 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 385:
#line 4364 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 386:
#line 4365 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 387:
#line 4370 "Gmsh.y"
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

  case 388:
#line 4388 "Gmsh.y"
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

  case 389:
#line 4406 "Gmsh.y"
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

  case 390:
#line 4418 "Gmsh.y"
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

  case 391:
#line 4435 "Gmsh.y"
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

  case 392:
#line 4456 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 393:
#line 4461 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 394:
#line 4466 "Gmsh.y"
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

  case 395:
#line 4476 "Gmsh.y"
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

  case 396:
#line 4486 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 397:
#line 4491 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 398:
#line 4500 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 399:
#line 4505 "Gmsh.y"
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

  case 400:
#line 4532 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 401:
#line 4536 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 402:
#line 4540 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 403:
#line 4544 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 404:
#line 4548 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 405:
#line 4555 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 406:
#line 4559 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 407:
#line 4563 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 408:
#line 4567 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 409:
#line 4574 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 410:
#line 4579 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 411:
#line 4586 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 412:
#line 4591 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 413:
#line 4595 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 414:
#line 4600 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 415:
#line 4604 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 416:
#line 4612 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 417:
#line 4623 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 418:
#line 4627 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 419:
#line 4639 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 420:
#line 4647 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 421:
#line 4655 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 422:
#line 4662 "Gmsh.y"
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

  case 423:
#line 4672 "Gmsh.y"
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

  case 424:
#line 4692 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 425:
#line 4696 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 426:
#line 4700 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 427:
#line 4704 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 428:
#line 4708 "Gmsh.y"
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

  case 429:
#line 4737 "Gmsh.y"
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

  case 430:
#line 4766 "Gmsh.y"
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

  case 431:
#line 4795 "Gmsh.y"
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

  case 432:
#line 4824 "Gmsh.y"
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
#line 4834 "Gmsh.y"
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

  case 434:
#line 4844 "Gmsh.y"
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
#line 4857 "Gmsh.y"
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

  case 436:
#line 4869 "Gmsh.y"
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
#line 4900 "Gmsh.y"
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

  case 439:
#line 4921 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 440:
#line 4926 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 441:
#line 4930 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 442:
#line 4934 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 443:
#line 4946 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 444:
#line 4950 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 445:
#line 4962 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 446:
#line 4969 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 447:
#line 4979 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 448:
#line 4983 "Gmsh.y"
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

  case 449:
#line 4998 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 450:
#line 5003 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 451:
#line 5010 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 452:
#line 5014 "Gmsh.y"
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

  case 453:
#line 5027 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 454:
#line 5035 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 455:
#line 5046 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 456:
#line 5050 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 457:
#line 5058 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 458:
#line 5066 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 459:
#line 5074 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 460:
#line 5082 "Gmsh.y"
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

  case 461:
#line 5096 "Gmsh.y"
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

  case 462:
#line 5110 "Gmsh.y"
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

  case 463:
#line 5122 "Gmsh.y"
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
#line 5139 "Gmsh.y"
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

  case 465:
#line 5155 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 466:
#line 5160 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 467:
#line 5164 "Gmsh.y"
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
#line 5184 "Gmsh.y"
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

  case 469:
#line 5206 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 470:
#line 5211 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 471:
#line 5217 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 472:
#line 5226 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 473:
#line 5239 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 474:
#line 5242 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10736 "Gmsh.tab.cpp"
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


#line 5246 "Gmsh.y"


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

