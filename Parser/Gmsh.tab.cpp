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
     tRelocateMesh = 330,
     tPlane = 331,
     tRuled = 332,
     tTransfinite = 333,
     tComplex = 334,
     tPhysical = 335,
     tCompound = 336,
     tPeriodic = 337,
     tUsing = 338,
     tPlugin = 339,
     tDegenerated = 340,
     tRecursive = 341,
     tRotate = 342,
     tTranslate = 343,
     tSymmetry = 344,
     tDilate = 345,
     tExtrude = 346,
     tLevelset = 347,
     tRecombine = 348,
     tSmoother = 349,
     tSplit = 350,
     tDelete = 351,
     tCoherence = 352,
     tIntersect = 353,
     tMeshAlgorithm = 354,
     tReverse = 355,
     tLayers = 356,
     tScaleLast = 357,
     tHole = 358,
     tAlias = 359,
     tAliasWithOptions = 360,
     tCopyOptions = 361,
     tQuadTriAddVerts = 362,
     tQuadTriNoNewVerts = 363,
     tQuadTriSngl = 364,
     tQuadTriDbl = 365,
     tRecombLaterals = 366,
     tTransfQuadTri = 367,
     tText2D = 368,
     tText3D = 369,
     tInterpolationScheme = 370,
     tTime = 371,
     tCombine = 372,
     tBSpline = 373,
     tBezier = 374,
     tNurbs = 375,
     tNurbsOrder = 376,
     tNurbsKnots = 377,
     tColor = 378,
     tColorTable = 379,
     tFor = 380,
     tIn = 381,
     tEndFor = 382,
     tIf = 383,
     tEndIf = 384,
     tExit = 385,
     tAbort = 386,
     tField = 387,
     tReturn = 388,
     tCall = 389,
     tFunction = 390,
     tShow = 391,
     tHide = 392,
     tGetValue = 393,
     tGetEnv = 394,
     tGetString = 395,
     tHomology = 396,
     tCohomology = 397,
     tBetti = 398,
     tSetOrder = 399,
     tGMSH_MAJOR_VERSION = 400,
     tGMSH_MINOR_VERSION = 401,
     tGMSH_PATCH_VERSION = 402,
     tAFFECTDIVIDE = 403,
     tAFFECTTIMES = 404,
     tAFFECTMINUS = 405,
     tAFFECTPLUS = 406,
     tOR = 407,
     tAND = 408,
     tNOTEQUAL = 409,
     tEQUAL = 410,
     tGREATEROREQUAL = 411,
     tLESSOREQUAL = 412,
     UNARYPREC = 413,
     tMINUSMINUS = 414,
     tPLUSPLUS = 415
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
#define tRelocateMesh 330
#define tPlane 331
#define tRuled 332
#define tTransfinite 333
#define tComplex 334
#define tPhysical 335
#define tCompound 336
#define tPeriodic 337
#define tUsing 338
#define tPlugin 339
#define tDegenerated 340
#define tRecursive 341
#define tRotate 342
#define tTranslate 343
#define tSymmetry 344
#define tDilate 345
#define tExtrude 346
#define tLevelset 347
#define tRecombine 348
#define tSmoother 349
#define tSplit 350
#define tDelete 351
#define tCoherence 352
#define tIntersect 353
#define tMeshAlgorithm 354
#define tReverse 355
#define tLayers 356
#define tScaleLast 357
#define tHole 358
#define tAlias 359
#define tAliasWithOptions 360
#define tCopyOptions 361
#define tQuadTriAddVerts 362
#define tQuadTriNoNewVerts 363
#define tQuadTriSngl 364
#define tQuadTriDbl 365
#define tRecombLaterals 366
#define tTransfQuadTri 367
#define tText2D 368
#define tText3D 369
#define tInterpolationScheme 370
#define tTime 371
#define tCombine 372
#define tBSpline 373
#define tBezier 374
#define tNurbs 375
#define tNurbsOrder 376
#define tNurbsKnots 377
#define tColor 378
#define tColorTable 379
#define tFor 380
#define tIn 381
#define tEndFor 382
#define tIf 383
#define tEndIf 384
#define tExit 385
#define tAbort 386
#define tField 387
#define tReturn 388
#define tCall 389
#define tFunction 390
#define tShow 391
#define tHide 392
#define tGetValue 393
#define tGetEnv 394
#define tGetString 395
#define tHomology 396
#define tCohomology 397
#define tBetti 398
#define tSetOrder 399
#define tGMSH_MAJOR_VERSION 400
#define tGMSH_MINOR_VERSION 401
#define tGMSH_PATCH_VERSION 402
#define tAFFECTDIVIDE 403
#define tAFFECTTIMES 404
#define tAFFECTMINUS 405
#define tAFFECTPLUS 406
#define tOR 407
#define tAND 408
#define tNOTEQUAL 409
#define tEQUAL 410
#define tGREATEROREQUAL 411
#define tLESSOREQUAL 412
#define UNARYPREC 413
#define tMINUSMINUS 414
#define tPLUSPLUS 415




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
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
#line 526 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 539 "Gmsh.tab.cpp"

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
#define YYLAST   8664

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  181
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  478
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1664

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   415

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   166,     2,   176,     2,   165,     2,     2,
     171,   172,   163,   161,   177,   162,   175,   164,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     157,     2,   158,   152,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   173,     2,   174,   170,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   178,     2,   179,   180,     2,     2,     2,
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
     145,   146,   147,   148,   149,   150,   151,   153,   154,   155,
     156,   159,   160,   167,   168,   169
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
    1847,  1858,  1869,  1874,  1879,  1884,  1889,  1894,  1897,  1901,
    1908,  1910,  1912,  1914,  1917,  1923,  1931,  1942,  1944,  1948,
    1951,  1954,  1957,  1961,  1965,  1969,  1973,  1977,  1981,  1985,
    1989,  1993,  1997,  2001,  2005,  2009,  2013,  2019,  2024,  2029,
    2034,  2039,  2044,  2049,  2054,  2059,  2064,  2069,  2076,  2081,
    2086,  2091,  2096,  2101,  2106,  2111,  2118,  2125,  2132,  2137,
    2142,  2147,  2152,  2157,  2162,  2167,  2172,  2177,  2182,  2187,
    2194,  2199,  2204,  2209,  2214,  2219,  2224,  2229,  2236,  2243,
    2250,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,
    2273,  2275,  2280,  2285,  2288,  2294,  2298,  2305,  2310,  2318,
    2325,  2332,  2339,  2344,  2346,  2349,  2352,  2356,  2360,  2372,
    2382,  2390,  2398,  2400,  2404,  2406,  2408,  2411,  2415,  2420,
    2426,  2428,  2430,  2433,  2437,  2441,  2447,  2452,  2455,  2458,
    2461,  2464,  2470,  2476,  2482,  2488,  2490,  2492,  2496,  2500,
    2505,  2512,  2519,  2521,  2523,  2527,  2531,  2541,  2549,  2551,
    2557,  2561,  2568,  2570,  2574,  2576,  2578,  2582,  2589,  2591,
    2593,  2598,  2605,  2612,  2619,  2624,  2629,  2638,  2643,  2648,
    2653,  2658,  2665,  2672,  2674,  2678,  2684,  2690,  2692
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     182,     0,    -1,   183,    -1,     1,     6,    -1,    -1,   183,
     184,    -1,   187,    -1,   186,    -1,   205,    -1,   219,    -1,
     224,    -1,   228,    -1,   229,    -1,   230,    -1,   233,    -1,
     253,    -1,   254,    -1,   232,    -1,   231,    -1,   227,    -1,
     256,    -1,   158,    -1,   158,   158,    -1,    37,   171,   269,
     172,     6,    -1,    38,   171,   269,   172,     6,    -1,    37,
     171,   269,   172,   185,   269,     6,    -1,    37,   171,   269,
     177,   265,   172,     6,    -1,    38,   171,   269,   177,   265,
     172,     6,    -1,    37,   171,   269,   177,   265,   172,   185,
     269,     6,    -1,     4,   269,   178,   188,   179,     6,    -1,
     104,     4,   173,   257,   174,     6,    -1,   105,     4,   173,
     257,   174,     6,    -1,   106,     4,   173,   257,   177,   257,
     174,     6,    -1,    -1,   188,   191,    -1,   188,   195,    -1,
     188,   198,    -1,   188,   200,    -1,   188,   201,    -1,   257,
      -1,   189,   177,   257,    -1,   257,    -1,   190,   177,   257,
      -1,    -1,    -1,     4,   192,   171,   189,   172,   193,   178,
     190,   179,     6,    -1,   269,    -1,   194,   177,   269,    -1,
      -1,   113,   171,   257,   177,   257,   177,   257,   172,   196,
     178,   194,   179,     6,    -1,   269,    -1,   197,   177,   269,
      -1,    -1,   114,   171,   257,   177,   257,   177,   257,   177,
     257,   172,   199,   178,   197,   179,     6,    -1,   115,   178,
     261,   179,   178,   261,   179,     6,    -1,   115,   178,   261,
     179,   178,   261,   179,   178,   261,   179,   178,   261,   179,
       6,    -1,    -1,   116,   202,   178,   190,   179,     6,    -1,
       7,    -1,   151,    -1,   150,    -1,   149,    -1,   148,    -1,
     169,    -1,   168,    -1,    58,   173,   207,   174,     6,    -1,
      59,   173,   210,   174,     6,    -1,   273,   203,   262,     6,
      -1,     4,   173,   174,   203,   262,     6,    -1,     4,   173,
     257,   174,   203,   257,     6,    -1,     4,   171,   257,   172,
     203,   257,     6,    -1,     4,   173,   178,   265,   179,   174,
     203,   262,     6,    -1,     4,   171,   178,   265,   179,   172,
     203,   262,     6,    -1,   273,   204,     6,    -1,     4,   173,
     257,   174,   204,     6,    -1,   273,     7,   270,     6,    -1,
       4,   175,     4,     7,   270,     6,    -1,     4,   173,   257,
     174,   175,     4,     7,   270,     6,    -1,     4,   175,     4,
     203,   257,     6,    -1,     4,   173,   257,   174,   175,     4,
     203,   257,     6,    -1,     4,   175,     4,   204,     6,    -1,
       4,   173,   257,   174,   175,     4,   204,     6,    -1,     4,
     175,   123,   175,     4,     7,   266,     6,    -1,     4,   173,
     257,   174,   175,   123,   175,     4,     7,   266,     6,    -1,
       4,   175,   124,     7,   267,     6,    -1,     4,   173,   257,
     174,   175,   124,     7,   267,     6,    -1,     4,   132,     7,
     257,     6,    -1,   132,   173,   257,   174,     7,     4,     6,
      -1,   132,   173,   257,   174,   175,     4,     7,   257,     6,
      -1,   132,   173,   257,   174,   175,     4,     7,   270,     6,
      -1,   132,   173,   257,   174,   175,     4,     7,   178,   265,
     179,     6,    -1,   132,   173,   257,   174,   175,     4,     6,
      -1,    84,   171,     4,   172,   175,     4,     7,   257,     6,
      -1,    84,   171,     4,   172,   175,     4,     7,   270,     6,
      -1,    -1,   177,    -1,    -1,   207,   206,   273,    -1,   207,
     206,   273,     7,   257,    -1,    -1,   207,   206,   273,     7,
     178,   257,   208,   212,   179,    -1,   207,   206,   273,     7,
     270,    -1,    -1,   207,   206,   273,     7,   178,   270,   209,
     214,   179,    -1,    -1,   210,   206,   269,    -1,   257,     7,
     270,    -1,   211,   177,   257,     7,   270,    -1,    -1,   212,
     213,    -1,   177,     4,   262,    -1,   177,     4,   178,   211,
     179,    -1,   177,     4,   270,    -1,    -1,   214,   215,    -1,
     177,     4,   257,    -1,   177,     4,   270,    -1,   177,     4,
     178,   271,   179,    -1,   257,    -1,   270,    -1,    -1,   126,
      64,   178,   257,   179,    -1,    -1,    76,   259,    -1,    60,
     171,   257,   172,     7,   259,     6,    -1,    -1,    80,    60,
     220,   171,   216,   172,     7,   262,     6,    -1,    69,    70,
     262,     7,   257,     6,    -1,    63,   171,   257,   172,     7,
     262,     6,    -1,    85,    63,   262,     6,    -1,    67,   171,
     257,   172,     7,   262,     6,    -1,    61,   171,   257,   172,
       7,   262,   218,     6,    -1,    62,   171,   257,   172,     7,
     262,   218,     6,    -1,   118,   171,   257,   172,     7,   262,
       6,    -1,   119,   171,   257,   172,     7,   262,     6,    -1,
     120,   171,   257,   172,     7,   262,   122,   262,   121,   257,
       6,    -1,    63,     4,   171,   257,   172,     7,   262,     6,
      -1,    81,    63,   171,   257,   172,     7,   262,     6,    -1,
      -1,    80,    63,   221,   171,   216,   172,     7,   262,     6,
      -1,    76,    66,   171,   257,   172,     7,   262,     6,    -1,
      77,    66,   171,   257,   172,     7,   262,   217,     6,    -1,
      12,    13,     6,    -1,    13,    66,   257,     6,    -1,    71,
      66,   171,   257,   172,     7,     5,     5,     5,     6,    -1,
      64,   171,   257,   172,     7,   262,     6,    -1,    65,   171,
     257,   172,     7,   262,     6,    -1,    66,     4,   171,   257,
     172,     7,   262,     6,    -1,    81,    66,   171,   257,   172,
       7,   262,     6,    -1,    81,    66,   171,   257,   172,     7,
     262,     4,   178,   261,   179,     6,    -1,    -1,    80,    66,
     222,   171,   216,   172,     7,   262,     6,    -1,    79,    68,
     171,   257,   172,     7,   262,     6,    -1,    68,   171,   257,
     172,     7,   262,     6,    -1,    81,    68,   171,   257,   172,
       7,   262,     6,    -1,    -1,    80,    68,   223,   171,   216,
     172,     7,   262,     6,    -1,    88,   259,   178,   225,   179,
      -1,    87,   178,   259,   177,   259,   177,   257,   179,   178,
     225,   179,    -1,    89,   259,   178,   225,   179,    -1,    90,
     178,   259,   177,   257,   179,   178,   225,   179,    -1,    90,
     178,   259,   177,   259,   179,   178,   225,   179,    -1,     4,
     178,   225,   179,    -1,    98,    63,   178,   265,   179,    66,
     178,   257,   179,    -1,    95,    63,   171,   257,   172,   178,
     265,   179,     6,    -1,   226,    -1,   224,    -1,    -1,   226,
     219,    -1,   226,    60,   178,   265,   179,     6,    -1,   226,
      63,   178,   265,   179,     6,    -1,   226,    66,   178,   265,
     179,     6,    -1,   226,    68,   178,   265,   179,     6,    -1,
      92,    76,   171,   257,   172,     7,   262,     6,    -1,    92,
      60,   171,   257,   172,     7,   178,   261,   179,     6,    -1,
      92,    76,   171,   257,   172,     7,   178,   259,   177,   259,
     177,   265,   179,     6,    -1,    92,    76,   171,   257,   172,
       7,   178,   259,   177,   259,   177,   259,   177,   265,   179,
       6,    -1,    92,    64,   171,   257,   172,     7,   178,   259,
     177,   265,   179,     6,    -1,    92,     4,   171,   257,   172,
       7,   262,     6,    -1,    92,     4,   171,   257,   172,     7,
       5,     6,    -1,    92,     4,   178,   257,   179,     6,    -1,
      92,     4,   171,   257,   172,     7,   178,   259,   177,   259,
     177,   265,   179,     6,    -1,    96,   178,   226,   179,    -1,
      96,   132,   173,   257,   174,     6,    -1,    96,     4,   173,
     257,   174,     6,    -1,    96,     4,     6,    -1,    96,     4,
       4,     6,    -1,   123,   266,   178,   226,   179,    -1,    86,
     123,   266,   178,   226,   179,    -1,   136,     5,     6,    -1,
     137,     5,     6,    -1,   136,   178,   226,   179,    -1,    86,
     136,   178,   226,   179,    -1,   137,   178,   226,   179,    -1,
      86,   137,   178,   226,   179,    -1,     4,   270,     6,    -1,
       4,     4,   173,   257,   174,   269,     6,    -1,     4,     4,
       4,   173,   257,   174,     6,    -1,     4,   257,     6,    -1,
      84,   171,     4,   172,   175,     4,     6,    -1,   117,     4,
       6,    -1,   130,     6,    -1,   131,     6,    -1,    54,     6,
      -1,    48,     6,    -1,    48,   178,   257,   177,   257,   177,
     257,   177,   257,   177,   257,   177,   257,   179,     6,    -1,
      49,     6,    -1,    50,     6,    -1,    55,     6,    -1,    56,
       6,    -1,    73,     6,    -1,    74,   178,   265,   179,   178,
     265,   179,   178,   261,   179,   178,   257,   177,   257,   179,
       6,    -1,   144,   257,     6,    -1,   125,   171,   257,     8,
     257,   172,    -1,   125,   171,   257,     8,   257,     8,   257,
     172,    -1,   125,     4,   126,   178,   257,     8,   257,   179,
      -1,   125,     4,   126,   178,   257,     8,   257,     8,   257,
     179,    -1,   127,    -1,   135,     4,    -1,   133,    -1,   134,
       4,     6,    -1,   128,   171,   257,   172,    -1,   129,    -1,
      91,   259,   178,   226,   179,    -1,    91,   178,   259,   177,
     259,   177,   257,   179,   178,   226,   179,    -1,    91,   178,
     259,   177,   259,   177,   259,   177,   257,   179,   178,   226,
     179,    -1,    -1,    91,   259,   178,   226,   234,   247,   179,
      -1,    -1,    91,   178,   259,   177,   259,   177,   257,   179,
     178,   226,   235,   247,   179,    -1,    -1,    91,   178,   259,
     177,   259,   177,   259,   177,   257,   179,   178,   226,   236,
     247,   179,    -1,    -1,    91,   178,   226,   237,   247,   179,
      -1,    91,    60,   178,   257,   177,   259,   179,     6,    -1,
      91,    63,   178,   257,   177,   259,   179,     6,    -1,    91,
      66,   178,   257,   177,   259,   179,     6,    -1,    91,    60,
     178,   257,   177,   259,   177,   259,   177,   257,   179,     6,
      -1,    91,    63,   178,   257,   177,   259,   177,   259,   177,
     257,   179,     6,    -1,    91,    66,   178,   257,   177,   259,
     177,   259,   177,   257,   179,     6,    -1,    91,    60,   178,
     257,   177,   259,   177,   259,   177,   259,   177,   257,   179,
       6,    -1,    91,    63,   178,   257,   177,   259,   177,   259,
     177,   259,   177,   257,   179,     6,    -1,    91,    66,   178,
     257,   177,   259,   177,   259,   177,   259,   177,   257,   179,
       6,    -1,    -1,    91,    60,   178,   257,   177,   259,   179,
     238,   178,   247,   179,     6,    -1,    -1,    91,    63,   178,
     257,   177,   259,   179,   239,   178,   247,   179,     6,    -1,
      -1,    91,    66,   178,   257,   177,   259,   179,   240,   178,
     247,   179,     6,    -1,    -1,    91,    60,   178,   257,   177,
     259,   177,   259,   177,   257,   179,   241,   178,   247,   179,
       6,    -1,    -1,    91,    63,   178,   257,   177,   259,   177,
     259,   177,   257,   179,   242,   178,   247,   179,     6,    -1,
      -1,    91,    66,   178,   257,   177,   259,   177,   259,   177,
     257,   179,   243,   178,   247,   179,     6,    -1,    -1,    91,
      60,   178,   257,   177,   259,   177,   259,   177,   259,   177,
     257,   179,   244,   178,   247,   179,     6,    -1,    -1,    91,
      63,   178,   257,   177,   259,   177,   259,   177,   259,   177,
     257,   179,   245,   178,   247,   179,     6,    -1,    -1,    91,
      66,   178,   257,   177,   259,   177,   259,   177,   259,   177,
     257,   179,   246,   178,   247,   179,     6,    -1,   248,    -1,
     247,   248,    -1,   101,   178,   257,   179,     6,    -1,   101,
     178,   262,   177,   262,   179,     6,    -1,   101,   178,   262,
     177,   262,   177,   262,   179,     6,    -1,   102,     6,    -1,
      93,     6,    -1,   109,     6,    -1,   109,   111,     6,    -1,
     110,     6,    -1,   110,   111,     6,    -1,   107,     6,    -1,
     107,   111,     6,    -1,   108,     6,    -1,   108,   111,     6,
      -1,   103,   171,   257,   172,     7,   262,    83,   257,     6,
      -1,    83,     4,   173,   257,   174,     6,    -1,    -1,    83,
       4,   257,    -1,    -1,     4,    -1,    -1,     7,   262,    -1,
      -1,     7,   257,    -1,    78,    63,   263,     7,   257,   249,
       6,    -1,    78,    66,   263,   251,   250,     6,    -1,    72,
      66,   178,   257,   179,     7,   262,     6,    -1,    78,    68,
     263,   251,     6,    -1,   112,   263,     6,    -1,    99,    66,
     178,   265,   179,   257,     6,    -1,    93,    66,   263,   252,
       6,    -1,    93,    68,   263,     6,    -1,    94,    66,   262,
       7,   257,     6,    -1,    82,    63,   262,     7,   262,     6,
      -1,    82,    66,   257,   178,   265,   179,     7,   257,   178,
     265,   179,     6,    -1,    60,   178,   265,   179,   126,    66,
     178,   257,   179,     6,    -1,    63,   178,   265,   179,   126,
      66,   178,   257,   179,     6,    -1,    60,   178,   265,   179,
     126,    68,   178,   257,   179,     6,    -1,    63,   178,   265,
     179,   126,    68,   178,   257,   179,     6,    -1,    66,   178,
     265,   179,   126,    68,   178,   257,   179,     6,    -1,   100,
      66,   263,     6,    -1,   100,    63,   263,     6,    -1,    75,
      60,   263,     6,    -1,    75,    63,   263,     6,    -1,    75,
      66,   263,     6,    -1,    97,     6,    -1,    97,     4,     6,
      -1,    97,    60,   178,   265,   179,     6,    -1,   141,    -1,
     142,    -1,   143,    -1,   255,     6,    -1,   255,   178,   262,
     179,     6,    -1,   255,   178,   262,   177,   262,   179,     6,
      -1,   255,   171,   262,   172,   178,   262,   177,   262,   179,
       6,    -1,   258,    -1,   171,   257,   172,    -1,   162,   257,
      -1,   161,   257,    -1,   166,   257,    -1,   257,   162,   257,
      -1,   257,   161,   257,    -1,   257,   163,   257,    -1,   257,
     164,   257,    -1,   257,   165,   257,    -1,   257,   170,   257,
      -1,   257,   157,   257,    -1,   257,   158,   257,    -1,   257,
     160,   257,    -1,   257,   159,   257,    -1,   257,   156,   257,
      -1,   257,   155,   257,    -1,   257,   154,   257,    -1,   257,
     153,   257,    -1,   257,   152,   257,     8,   257,    -1,    14,
     171,   257,   172,    -1,    15,   171,   257,   172,    -1,    16,
     171,   257,   172,    -1,    17,   171,   257,   172,    -1,    18,
     171,   257,   172,    -1,    19,   171,   257,   172,    -1,    20,
     171,   257,   172,    -1,    21,   171,   257,   172,    -1,    22,
     171,   257,   172,    -1,    24,   171,   257,   172,    -1,    25,
     171,   257,   177,   257,   172,    -1,    26,   171,   257,   172,
      -1,    27,   171,   257,   172,    -1,    28,   171,   257,   172,
      -1,    29,   171,   257,   172,    -1,    30,   171,   257,   172,
      -1,    31,   171,   257,   172,    -1,    32,   171,   257,   172,
      -1,    33,   171,   257,   177,   257,   172,    -1,    34,   171,
     257,   177,   257,   172,    -1,    35,   171,   257,   177,   257,
     172,    -1,    23,   171,   257,   172,    -1,    14,   173,   257,
     174,    -1,    15,   173,   257,   174,    -1,    16,   173,   257,
     174,    -1,    17,   173,   257,   174,    -1,    18,   173,   257,
     174,    -1,    19,   173,   257,   174,    -1,    20,   173,   257,
     174,    -1,    21,   173,   257,   174,    -1,    22,   173,   257,
     174,    -1,    24,   173,   257,   174,    -1,    25,   173,   257,
     177,   257,   174,    -1,    26,   173,   257,   174,    -1,    27,
     173,   257,   174,    -1,    28,   173,   257,   174,    -1,    29,
     173,   257,   174,    -1,    30,   173,   257,   174,    -1,    31,
     173,   257,   174,    -1,    32,   173,   257,   174,    -1,    33,
     173,   257,   177,   257,   174,    -1,    34,   173,   257,   177,
     257,   174,    -1,    35,   173,   257,   177,   257,   174,    -1,
      23,   173,   257,   174,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   145,    -1,   146,    -1,   147,    -1,    52,
      -1,    53,    -1,   273,    -1,     4,   173,   257,   174,    -1,
     176,     4,   173,   174,    -1,   273,   204,    -1,     4,   173,
     257,   174,   204,    -1,     4,   175,     4,    -1,     4,   173,
     257,   174,   175,     4,    -1,     4,   175,     4,   204,    -1,
       4,   173,   257,   174,   175,     4,   204,    -1,   138,   171,
     269,   177,   257,   172,    -1,    45,   171,   269,   177,   269,
     172,    -1,    46,   171,   269,   177,   269,   172,    -1,    47,
     171,   271,   172,    -1,   260,    -1,   162,   259,    -1,   161,
     259,    -1,   259,   162,   259,    -1,   259,   161,   259,    -1,
     178,   257,   177,   257,   177,   257,   177,   257,   177,   257,
     179,    -1,   178,   257,   177,   257,   177,   257,   177,   257,
     179,    -1,   178,   257,   177,   257,   177,   257,   179,    -1,
     171,   257,   177,   257,   177,   257,   172,    -1,   262,    -1,
     261,   177,   262,    -1,   257,    -1,   264,    -1,   178,   179,
      -1,   178,   265,   179,    -1,   162,   178,   265,   179,    -1,
     257,   163,   178,   265,   179,    -1,   262,    -1,     5,    -1,
     162,   264,    -1,   257,   163,   264,    -1,   257,     8,   257,
      -1,   257,     8,   257,     8,   257,    -1,    60,   178,   257,
     179,    -1,    60,     5,    -1,    63,     5,    -1,    66,     5,
      -1,    68,     5,    -1,    80,    60,   178,   265,   179,    -1,
      80,    63,   178,   265,   179,    -1,    80,    66,   178,   265,
     179,    -1,    80,    68,   178,   265,   179,    -1,   224,    -1,
     233,    -1,     4,   173,   174,    -1,     4,   171,   172,    -1,
      36,   173,     4,   174,    -1,     4,   173,   178,   265,   179,
     174,    -1,     4,   171,   178,   265,   179,   172,    -1,   257,
      -1,   264,    -1,   265,   177,   257,    -1,   265,   177,   264,
      -1,   178,   257,   177,   257,   177,   257,   177,   257,   179,
      -1,   178,   257,   177,   257,   177,   257,   179,    -1,     4,
      -1,     4,   175,   123,   175,     4,    -1,   178,   268,   179,
      -1,     4,   173,   257,   174,   175,   124,    -1,   266,    -1,
     268,   177,   266,    -1,   270,    -1,   273,    -1,     4,   175,
       4,    -1,     4,   173,   257,   174,   175,     4,    -1,     5,
      -1,    51,    -1,   139,   171,   269,   172,    -1,   140,   171,
     269,   177,   269,   172,    -1,    41,   171,   269,   177,   269,
     172,    -1,    41,   173,   269,   177,   269,   174,    -1,    42,
     171,   269,   172,    -1,    43,   171,   269,   172,    -1,    44,
     171,   269,   177,   269,   177,   269,   172,    -1,    39,   171,
     271,   172,    -1,    39,   173,   271,   174,    -1,    40,   171,
     269,   172,    -1,    40,   173,   269,   174,    -1,    40,   171,
     269,   177,   265,   172,    -1,    40,   173,   269,   177,   265,
     174,    -1,   269,    -1,   271,   177,   269,    -1,     4,   180,
     178,   257,   179,    -1,   272,   180,   178,   257,   179,    -1,
       4,    -1,   272,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   173,   178,   180,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   202,   206,   213,   218,   223,   237,   250,   263,   291,
     305,   318,   331,   350,   355,   356,   357,   358,   359,   363,
     365,   370,   372,   378,   482,   377,   500,   507,   518,   517,
     535,   542,   553,   552,   569,   586,   609,   608,   622,   623,
     624,   625,   626,   630,   631,   637,   639,   641,   703,   733,
     768,   802,   850,   897,   912,   928,   937,   943,   952,   970,
     988,   997,  1009,  1014,  1022,  1042,  1065,  1076,  1084,  1106,
    1129,  1155,  1176,  1188,  1202,  1202,  1204,  1206,  1215,  1225,
    1224,  1236,  1246,  1245,  1259,  1261,  1269,  1275,  1282,  1283,
    1287,  1298,  1313,  1323,  1324,  1329,  1337,  1346,  1364,  1368,
    1379,  1382,  1395,  1398,  1408,  1432,  1431,  1451,  1473,  1491,
    1512,  1530,  1560,  1590,  1608,  1626,  1652,  1670,  1689,  1688,
    1711,  1729,  1768,  1774,  1780,  1787,  1812,  1837,  1854,  1873,
    1908,  1907,  1931,  1949,  1966,  1983,  1982,  2008,  2013,  2018,
    2023,  2028,  2033,  2056,  2062,  2073,  2074,  2079,  2082,  2086,
    2109,  2132,  2155,  2183,  2204,  2230,  2251,  2273,  2293,  2405,
    2424,  2462,  2571,  2580,  2586,  2601,  2629,  2646,  2655,  2669,
    2675,  2681,  2690,  2699,  2708,  2722,  2774,  2791,  2806,  2825,
    2837,  2861,  2865,  2870,  2877,  2883,  2888,  2894,  2902,  2906,
    2910,  2915,  2970,  2983,  3000,  3017,  3038,  3059,  3094,  3102,
    3108,  3115,  3119,  3128,  3136,  3144,  3153,  3152,  3167,  3166,
    3181,  3180,  3195,  3194,  3208,  3215,  3222,  3229,  3236,  3243,
    3250,  3257,  3264,  3272,  3271,  3285,  3284,  3298,  3297,  3311,
    3310,  3324,  3323,  3337,  3336,  3350,  3349,  3363,  3362,  3376,
    3375,  3392,  3395,  3401,  3413,  3433,  3457,  3462,  3466,  3470,
    3474,  3478,  3482,  3486,  3490,  3494,  3498,  3517,  3530,  3533,
    3549,  3552,  3569,  3572,  3578,  3581,  3588,  3644,  3714,  3719,
    3786,  3822,  3830,  3873,  3912,  3932,  3959,  3999,  4022,  4045,
    4049,  4053,  4076,  4115,  4154,  4175,  4196,  4223,  4227,  4237,
    4272,  4273,  4274,  4278,  4284,  4296,  4314,  4342,  4343,  4344,
    4345,  4346,  4347,  4348,  4349,  4350,  4357,  4358,  4359,  4360,
    4361,  4362,  4363,  4364,  4365,  4366,  4367,  4368,  4369,  4370,
    4371,  4372,  4373,  4374,  4375,  4376,  4377,  4378,  4379,  4380,
    4381,  4382,  4383,  4384,  4385,  4386,  4387,  4388,  4389,  4392,
    4393,  4394,  4395,  4396,  4397,  4398,  4399,  4400,  4401,  4402,
    4403,  4404,  4405,  4406,  4407,  4408,  4409,  4410,  4411,  4412,
    4413,  4422,  4423,  4424,  4425,  4426,  4427,  4428,  4429,  4430,
    4434,  4452,  4470,  4482,  4499,  4520,  4525,  4530,  4540,  4550,
    4555,  4564,  4569,  4596,  4600,  4604,  4608,  4612,  4619,  4623,
    4627,  4631,  4638,  4643,  4650,  4655,  4659,  4664,  4668,  4676,
    4687,  4691,  4703,  4711,  4719,  4726,  4736,  4756,  4760,  4764,
    4768,  4772,  4801,  4830,  4859,  4888,  4898,  4908,  4921,  4933,
    4945,  4964,  4985,  4990,  4994,  4998,  5010,  5014,  5026,  5033,
    5043,  5047,  5062,  5067,  5074,  5078,  5091,  5099,  5110,  5114,
    5122,  5130,  5138,  5147,  5155,  5169,  5183,  5195,  5212,  5228,
    5233,  5237,  5257,  5279,  5284,  5290,  5299,  5312,  5315
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
  "tRelocateMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     405,   406,    63,   407,   408,   409,   410,    60,    62,   411,
     412,    43,    45,    42,    47,    37,    33,   413,   414,   415,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   181,   182,   182,   183,   183,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   185,   185,   186,   186,   186,   186,   186,   186,   187,
     187,   187,   187,   188,   188,   188,   188,   188,   188,   189,
     189,   190,   190,   192,   193,   191,   194,   194,   196,   195,
     197,   197,   199,   198,   200,   200,   202,   201,   203,   203,
     203,   203,   203,   204,   204,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   206,   206,   207,   207,   207,   208,
     207,   207,   209,   207,   210,   210,   211,   211,   212,   212,
     213,   213,   213,   214,   214,   215,   215,   215,   216,   216,
     217,   217,   218,   218,   219,   220,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   221,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     222,   219,   219,   219,   219,   223,   219,   224,   224,   224,
     224,   224,   224,   224,   224,   225,   225,   226,   226,   226,
     226,   226,   226,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   228,   228,   228,   228,   228,   229,   229,   230,
     230,   230,   230,   230,   230,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   233,   233,   233,   234,   233,   235,   233,
     236,   233,   237,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   238,   233,   239,   233,   240,   233,   241,
     233,   242,   233,   243,   233,   244,   233,   245,   233,   246,
     233,   247,   247,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   254,   254,   254,
     255,   255,   255,   256,   256,   256,   256,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   259,   259,   259,   259,   259,   260,   260,
     260,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     263,   263,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   265,   265,   265,   265,   266,   266,   266,   266,
     267,   267,   268,   268,   269,   269,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   271,   271,   272,   272,   273,   273
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
      10,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     5,     3,     6,     4,     7,     6,
       6,     6,     4,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     1,     2,     3,     3,     5,     4,     2,     2,     2,
       2,     5,     5,     5,     5,     1,     1,     3,     3,     4,
       6,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       4,     6,     6,     6,     4,     4,     8,     4,     4,     4,
       4,     6,     6,     1,     3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
     222,     0,     0,     0,   219,     0,     0,     0,     0,   310,
     311,   312,     0,     5,     7,     6,     8,     9,    10,    19,
      11,    12,    13,    18,    17,    14,    15,    16,     0,    20,
     478,     0,   381,   477,   458,   382,   383,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     388,   389,     0,     0,     0,     0,   385,   386,   387,     0,
       0,     0,     0,     0,     0,     0,   167,     0,     0,   317,
       0,   454,   390,     0,     0,     0,     0,   204,     0,   206,
     207,   203,   208,   209,    96,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   138,   150,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,     0,     0,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,     0,   307,     0,     0,     0,     0,     0,     0,
       0,     0,   477,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,   436,   414,   420,     0,   415,   390,
       0,     0,     0,     0,   448,     0,     0,     0,     0,     0,
     201,   202,     0,     0,   218,     0,   167,     0,   167,   477,
       0,   313,     0,     0,     0,    58,    62,    61,    60,    59,
      64,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,   319,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,   165,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,   195,   393,   142,     0,   477,     0,   454,   455,     0,
       0,    94,    94,     0,     0,   442,   443,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
     282,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   167,     0,   405,   404,     0,
       0,     0,     0,   167,   167,     0,     0,     0,     0,     0,
       0,     0,   232,     0,   167,     0,     0,     0,     0,     0,
     284,     0,     0,     0,     0,   185,     0,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   427,     0,   428,   429,   430,     0,     0,     0,
       0,     0,   319,   422,     0,   416,     0,     0,     0,   290,
     200,     0,     0,     0,     0,     0,   167,     0,     0,     0,
       0,   220,   189,     0,   190,     0,     0,   212,     0,     0,
       0,     0,     0,    73,     0,     0,   395,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   318,
      58,     0,     0,     0,    58,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,   168,     0,     0,   335,   334,
     333,   332,   328,   329,   331,   330,   323,   322,   324,   325,
     326,   327,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   305,   306,     0,     0,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   167,     0,     0,     0,
       0,     0,   407,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,   293,     0,     0,   186,     0,     0,   182,     0,     0,
       0,   303,   302,     0,     0,     0,   438,     0,   437,     0,
       0,   395,     0,     0,     0,     0,     0,     0,     0,   318,
     417,   424,     0,   324,   423,     0,     0,     0,     0,     0,
       0,     0,     0,   221,     0,   191,   193,     0,     0,     0,
       0,    75,    67,     0,   391,   397,   337,   359,   338,   360,
     339,   361,   340,   362,   341,   363,   342,   364,   343,   365,
     344,   366,   345,   367,   358,   380,   346,   368,     0,     0,
     348,   370,   349,   371,   350,   372,   351,   373,   352,   374,
     353,   375,   354,   376,     0,     0,     0,     0,     0,     0,
     467,     0,   468,   469,     0,   470,     0,     0,     0,   464,
     465,     0,     0,     0,   402,    86,     0,   460,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,   392,     0,     0,     0,     0,   475,     0,
      43,     0,     0,     0,    56,     0,    34,    35,    36,    37,
      38,     0,   456,    23,    21,     0,     0,    24,     0,     0,
      65,   477,    97,    66,   105,     0,   444,   445,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,   283,   281,     0,
     289,     0,     0,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   194,     0,     0,     0,
     157,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,   223,
       0,     0,     0,     0,     0,     0,   285,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,   439,   426,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,   314,   476,     0,     0,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,    74,    76,    78,     0,     0,   452,
       0,    84,     0,     0,     0,     0,   336,     0,     0,     0,
       0,     0,    29,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,   122,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,     0,   266,     0,   272,
       0,   274,     0,   268,     0,   270,     0,   233,   262,     0,
       0,     0,   180,     0,     0,     0,   294,     0,   184,   183,
     309,     0,     0,    30,    31,     0,     0,     0,     0,   431,
     432,   433,   434,   425,   419,     0,     0,     0,   449,     0,
       0,     0,   213,     0,     0,     0,     0,   197,   396,   196,
     347,   369,   355,   377,   356,   378,   357,   379,   471,   472,
     462,   463,     0,   400,   401,   399,   461,     0,    70,     0,
      58,     0,     0,     0,     0,    69,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,   412,     0,
       0,    25,    26,     0,    27,     0,     0,    98,   101,   124,
       0,     0,     0,     0,     0,     0,   128,     0,     0,   145,
     146,     0,     0,   130,   153,     0,     0,     0,     0,   120,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,     0,     0,   167,   167,     0,   243,
       0,   245,     0,   247,     0,   414,     0,     0,   273,   275,
     269,   271,     0,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,   441,   440,   396,   133,
     134,     0,     0,     0,     0,    87,    91,     0,     0,   315,
     398,     0,     0,     0,     0,     0,    81,     0,     0,    82,
       0,   453,   169,   170,   171,   172,     0,    39,     0,     0,
       0,     0,     0,    41,   457,     0,     0,    99,   102,     0,
       0,   123,   131,   132,   136,     0,     0,   147,     0,     0,
     288,     0,   140,     0,     0,   279,   152,     0,     0,     0,
       0,   137,     0,   148,   154,     0,     0,     0,     0,   411,
       0,   410,     0,     0,     0,   234,     0,     0,   235,     0,
       0,   236,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,   178,     0,     0,     0,   173,     0,     0,    32,
       0,     0,   447,     0,   215,   214,     0,     0,     0,     0,
     466,    72,    71,    77,    79,     0,    85,     0,    44,     0,
       0,     0,   413,     0,     0,     0,    28,     0,   108,   113,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   126,
     139,   151,   156,     0,     0,    92,    93,   167,     0,   160,
     161,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,   167,     0,     0,     0,     0,     0,   164,   163,     0,
       0,     0,     0,    88,    89,     0,     0,   451,     0,    40,
       0,     0,     0,    42,    57,     0,     0,     0,   297,   299,
     298,   300,   301,   144,     0,     0,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,   228,     0,     0,   174,     0,     0,
       0,   446,   216,     0,   316,    83,     0,     0,     0,     0,
       0,     0,   100,   109,     0,   103,   114,     0,     0,     0,
       0,   158,     0,   249,     0,     0,   251,     0,     0,   253,
       0,     0,     0,   264,     0,   224,     0,   167,     0,     0,
       0,   135,    90,     0,    48,     0,    54,     0,     0,     0,
       0,     0,   121,   149,   296,   408,   237,     0,     0,   244,
     238,     0,     0,   246,   239,     0,     0,   248,     0,     0,
       0,   230,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   112,     0,   115,   116,     0,     0,   255,
       0,   257,     0,   259,   265,   276,   229,   225,     0,     0,
       0,     0,    45,     0,    52,     0,     0,     0,   442,     0,
       0,     0,   240,     0,     0,   241,     0,     0,   242,     0,
       0,   181,     0,   175,     0,    46,     0,     0,   205,     0,
     111,     0,   117,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,   106,   211,   250,
       0,   252,     0,   254,     0,   176,    47,    49,     0,    50,
       0,     0,     0,     0,     0,     0,     0,    55,   107,   256,
     258,   260,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    83,   875,    84,    85,   642,  1296,  1302,
     866,  1037,  1448,  1614,   867,  1567,  1648,   868,  1616,   869,
     870,  1041,   302,   402,    86,   653,   411,  1398,  1399,   412,
    1597,  1456,  1503,  1457,  1506,   912,  1324,  1203,   625,   442,
     443,   444,   445,   263,   381,   382,    89,    90,    91,    92,
      93,    94,   264,   950,  1526,  1588,   711,  1346,  1349,  1352,
    1547,  1551,  1555,  1603,  1606,  1609,   946,   947,  1072,   909,
     682,   720,    96,    97,    98,    99,   265,   159,   458,   223,
    1187,   266,   267,   268,   516,   276,   852,  1030,   591,   407,
     592,   100,   269
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1244
static const yytype_int16 yypact[] =
{
    4700,    52,   108,  4809, -1244, -1244,   101,   138,   -55,     0,
      12,    26,   185,   212,   217,   316,   332,    79,   109,  -140,
     224,   233,    16,   290,   296,    18,   304,   340,   448,   466,
     485,   610,   454,   563,   582,   592,   347,   606,   609,   408,
      37,   520,   636,   -67,   543,    88,    88,   554,   162,   265,
     -16,   670,   666,     6,    47,   674,   675,   276,   729,   738,
     742,  2755,   749,   586,   596,   601,    19,    22, -1244,   602,
   -1244,   757,   772,   613, -1244,   775,   778,    23,    24, -1244,
   -1244, -1244,  4072, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,    29, -1244,
     603,    87, -1244,     5, -1244, -1244, -1244, -1244,   -94,   -34,
      56,   100,   321,   360,   379,   437,   536,   537,   549,   557,
     583,   591,   616,   635,   638,   660,   663,   679,   693,   697,
     700,   704,   707,   619,   623,   639,   643,   648,   649, -1244,
   -1244, -1244,   830,   655,   669,   676, -1244, -1244, -1244,  4072,
    4072,  4072,  3767,  1945,    44,   837,   209,   689,   859, -1244,
     696,   878,  -102,   887,  4072,   818,   818, -1244,  4072, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244,  4072,  3982,  4072,  4072,
     723,  4072,  3982,  4072,  4072,   746,  3982,  4072,  4072,  2949,
     759,   764, -1244,  3982,  2755,  2755,  2755,   776,   788,  2755,
    2755,  2755,   797, -1244, -1244, -1244, -1244,   805,   806,   834,
    2949,  4072,   896,  2949,    19,   768,   811,    88,    88,    88,
    4072,  4072,    -6, -1244,   122,    88,   812,   847,   864,  3812,
     124,   -98,   877,   881,   902,  2755,  2755,  2949,   906,    39,
     835, -1244,  1037, -1244,   900,   923,   963,  2755,  2755,   880,
     909,   913,   322, -1244,   925,    25,  1085,  1116,  1132,   785,
    3046,  4072,  2313, -1244, -1244,   384, -1244,  1140, -1244,   137,
    1143,  4072,  4072,  4072,   982,  4072,   994,  1053,  4072,  4072,
   -1244, -1244,  4072,  1182, -1244,  1186, -1244,  1188, -1244,    46,
    1403, -1244,  2949,  2949,  1017,   940, -1244, -1244, -1244, -1244,
   -1244, -1244,  2949,  1190,  1024,  4072,  1195,  4072,  4072,  4072,
    4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,
    4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,
    4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,
    4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,
    4072,   818,   818,   818,   818,   818,   818,   818,   818,   818,
     818,   818,   818,  4072,   818,   818,   818,  1028,  1028,  1028,
    3982,  7318,    94,  3982,  6513,   294,  1025,  1196,  1029,  1023,
   -1244,  1026,  4898,  4072, -1244,  4072,  4072,  4072,  4072,  4072,
    4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,  4072,
   -1244, -1244, -1244, -1244,  1781,    95,   234, -1244, -1244,   256,
    5759,   -86,   240,  7339,  3982,  4451, -1244,    81,  7360,  7381,
    4072,  7402,   702,  7423,  7444,  4072,   706,  7465,  7486,  1202,
    4072,  4072,   722,  1204,  1205,  1207,  4072,  4072,  1209,  1210,
    1210,  4072,  1043,  1047,  1048,  1049,  4072,  4072,  4072,  1214,
    5679,  1050,  1217,  1052, -1244, -1244,   -63, -1244, -1244,  5785,
    5811,    88,    88,   209,   209,    53,  4072,  4072,  4072,  3812,
    3812,  4072,  4898,   103, -1244,  4072,  4072,  4072,  4072,  4072,
    1218,  1226,  1221,  4072,  1228, -1244,  4072,  4072,   736, -1244,
    3982,  3982,  3982,  1229,  1230,  4072,  4072,  4072,  -110,  2539,
    1235,  1236, -1244,  4072, -1244, -1244, -1244,  1066,  1070,  1071,
    1074,  3982,  1028, -1244,  7507, -1244,   733,  4072,  3143, -1244,
   -1244,  7528,  7549,  7570,  1118,  5837, -1244,  1075,  4470,  7591,
    6536, -1244, -1244,  1063, -1244,  1194,  4072, -1244,  1073,   734,
    4072,  1237,  1258, -1244,  4072,  6559,   168,  7612,  6582,  7633,
    6605,  7654,  6628,  7675,  6651,  7696,  6674,  7717,  6697,  7738,
    6720,  7759,  6743,  7780,  6766,  7801,  6789,  7822,  6812,  5863,
    5889,  7843,  6835,  7864,  6858,  7885,  6881,  7906,  6904,  7927,
    6927,  7948,  6950,  7969,  6973,  5915,  5941,  5967,  5993,  6019,
    6045, -1244,   352,   451,   477,   493,  1089,  1090,  1096,  1097,
    1100,  1101,  1103,   484,  1869,  1104,  1110,  1106,   737,    94,
   -1244,  2949,   741,   271,   940,  4072,  1278,  1281,    20,  1114,
   -1244,   -69,    17,    21,     8, -1244,  4923,  4489,  1689,  1761,
     875,   875,   726,   726,   726,   726,   449,   449,  1028,  1028,
    1028,  1028,    45, -1244,  4072,  1285,    34,  3982,  1284,  3982,
    4072,  1286, -1244,  1287,  1288,   818,  1291,  3982,  3982,  1167,
    1292,  1293,  7990,  1294,  1169,  1295,  1296,  8011,  1180,  1300,
    1301,  4072,  8032,  4951,  1131, -1244, -1244, -1244,  8053,  8074,
    4072,  2949,  1306,  1305,  8095,  4146,  4146,  4146,  4146,  8116,
    8137,  8158,  2949,  3982,  1141, -1244, -1244,  1315,  2401,    88,
    4072,  4072, -1244, -1244,  1138,  1139,  3812,  6071,  6097,  6123,
    5733,   948,    88,  3386,  8179,  4979,  8200,  8221,  8242,  4072,
    1313, -1244,  4072,  8263, -1244,  6996,  7019, -1244,   744,   745,
     752, -1244, -1244,  7042,  7065,  6149, -1244,  3982, -1244,  3982,
    7088,   137,  1146,  5007,  3982,  3982,  3982,  3982,   760, -1244,
   -1244,  4514,  3982,  1028, -1244,  1314,  1319,  1326,  1147,  4072,
    4191,  4072,  4072, -1244,    -2, -1244, -1244,  1159,  2949,  1332,
    5035, -1244, -1244,  7111,    42, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,  4072,  4072,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244,  4072,  4072,  4072,  4072,  4072,  4072,
   -1244,   818, -1244, -1244,  3982, -1244,  3982,   818,   818, -1244,
   -1244,   818,   818,   818, -1244, -1244,  4072, -1244,   818,  1171,
    4072,  1333,  1173,    51,  4072,  1335,  1342,  1893, -1244,  1343,
    1178,    19,  1347, -1244,  3982,  3982,  3982,  3982, -1244,  4072,
   -1244,  1183,  1192,  1181, -1244,  1358, -1244, -1244, -1244, -1244,
   -1244,  7134, -1244, -1244,  1212,   818,   499, -1244,   515,  6175,
   -1244,  1191,  1365, -1244, -1244,    88,  4451, -1244,   872,  2949,
    2949,  1367,  2949,   884,  2949,  2949,  1378,  1322,  2949,  2949,
    2079,  1386,  1390,  3982,  1391,  1392,  4833, -1244, -1244,  1396,
   -1244,  1397,  1231,  8494, -1244,  1233,  1234,  1238,  1400,  1401,
    1404,  1407,   774,  1411,  4265, -1244, -1244,   166,  6201,  6227,
   -1244, -1244,  5063,   -66,    88,    88,    88,  1413,  1414,  1243,
    1416,  1255,    38,    54,    55,    58,   667, -1244,   170, -1244,
     948,  1422,  1424,  1429,  1432,  1433,  8494, -1244,  2098,  1253,
    1435,  1436,  1437,  1379,  4072,  1440,  1444,  4072,   783,   786,
     120, -1244, -1244,   787,   792,   795,   796, -1244,  4072,   809,
    2949,  2949,  2949,  1447,  6253, -1244,  4533,   326,  1448,  1449,
    2949,  1275, -1244, -1244,  1452,  1455, -1244,  1456,  8284,  7157,
    8305,  7180,  8326,  7203,  8347,  7226, -1244,   516,   524,  1289,
    1290,  1302,  1297,  1298,  8368,  1309,    94,  2283, -1244,    94,
     366,  1307,  1476,  2344, -1244, -1244, -1244,    19,  4072, -1244,
     819, -1244,   820,   824,   825,   849,  8494,  1316,  4072,  4072,
    2949,  1308, -1244,  1310, -1244,  1457,    48,  1478,  4072,  3507,
      28,  1311,  1312,  1412,  1412,  2949,  1485,  1317,  1321,  1487,
    1494,  2949,  1323,  1496,  1497, -1244,  1492,  2949,   882,  2949,
    2949,  1501,  1500, -1244,  2949,  1503,  1505,  1506,  1507,  2949,
    2949,  2949, -1244,  1508,   442, -1244,  4072,  4072,  4072,  1329,
    1338,  -120,   -90,   -87,  1344, -1244,  2949, -1244,  4072, -1244,
    1512, -1244,  1513, -1244,  1514, -1244,  1516, -1244, -1244,  3812,
    1067,  2852, -1244,  1345,  1346,  3240, -1244,  3982, -1244, -1244,
   -1244,  1348,  3714, -1244, -1244,  7249,  1355,  1354,  1525, -1244,
   -1244, -1244, -1244,  8494, -1244,  1524,  1526,  1409, -1244,  4072,
    4072,  4072, -1244,  1531,   498,  1361,  1533, -1244,   269, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244,   818, -1244, -1244, -1244, -1244,  2949, -1244,  2949,
     940,  4072,  1534,  1537,    20, -1244,  1536,  7272,    19, -1244,
    1538,  1539,  1542,  1543,  4072,  6279,  6305,   891, -1244,  4072,
    1546, -1244, -1244,   818, -1244,  6331,  4146,  8494, -1244, -1244,
    4072,  4072,    88,  1545,  1547,  1563, -1244,  4072,  4072, -1244,
   -1244,  1564,  4072, -1244, -1244,  1567,  1569,  1374,  1570,  1453,
    4072, -1244,  1572,  2949,  2949,  2949,  2949,  1574,  1065,  1575,
    4072, -1244,  4146,  5091,  8389,  4562,   209,   209,    88,  1576,
      88,  1577,    88,  1580,  4072,   156,  1410,  8410, -1244, -1244,
   -1244, -1244,  5119,   183, -1244,  1583,  2131,  1585,  2949,    88,
    2131,  1589,   904,  4072, -1244,  1590, -1244, -1244,   137, -1244,
   -1244,  2949,  4867,   226,  8431, -1244, -1244,  3552,  2949, -1244,
   -1244,  1425,  1596,  1597,  1599,  3733, -1244,  1600,  1603, -1244,
    1438, -1244, -1244, -1244, -1244, -1244,   528,  8494,  4072,  4072,
    2949,  1434,   908,  8494, -1244,  1604,  4072,  8494, -1244,  5147,
    5175,   551, -1244, -1244, -1244,  5203,  5231, -1244,  5259,  1606,
   -1244,  2949, -1244,  1550,  1609,  8494, -1244,  1611,  1612,  1614,
    1616, -1244,  1445, -1244, -1244,  5706,  4234,  1619,  1450, -1244,
    4072, -1244,  1451,  1454,   232, -1244,  1458,   241, -1244,  1460,
     246, -1244,  1461,  7295,  1620,  2949,  1628,  1462,  4072, -1244,
    3337,   289, -1244,   912,   293,   295, -1244,  1621,  5287, -1244,
    1520,  4072, -1244,  4072, -1244, -1244,  3982,  4293,  1638,  1468,
   -1244, -1244, -1244, -1244, -1244,    19, -1244,  1527, -1244,  4072,
    6357,  6383, -1244,  2949,  4072,  1642, -1244,  6409, -1244, -1244,
    1643,  1644,  1651,  1652,  1653,  1654,   916,  1483, -1244, -1244,
   -1244, -1244, -1244,  2949,  3982, -1244, -1244,   209,  4895, -1244,
   -1244,  3812,   948,  3812,   948,  3812,   948,  1657, -1244,   917,
    2949, -1244,  5315,    88,  1658,  3982,    88, -1244, -1244,  4072,
    5343,  5371,   920, -1244, -1244,  1659,  1661, -1244,  1490,  8494,
    4072,  4072,   929,  8494, -1244,  4072,   934,   935, -1244, -1244,
   -1244, -1244, -1244, -1244,  1498,  4072,   938,   939,  1477,  4072,
   -1244,  5399,   345,  1222,  5427,   351,  1259,  5455,   438,  1364,
   -1244,  2949,  1666,  1592,  4292,  1499,   440, -1244,   943,   443,
    4329, -1244, -1244,  1673, -1244, -1244,  4072,  8452,  6435,    27,
    6461,  1676, -1244, -1244,  1678, -1244, -1244,  4072,  5483,  1679,
    1680, -1244,  5511,  1682,  4072,  1683,  1684,  4072,  1685,  1686,
    4072,  1687,  1515, -1244,  4072, -1244,   948, -1244,  3982,  1690,
    3337, -1244, -1244,   956, -1244,  4072, -1244,  2949,  4072,  2585,
    3597,  6487, -1244, -1244, -1244, -1244, -1244,  1517,  5539, -1244,
   -1244,  1519,  5567, -1244, -1244,  1522,  5595, -1244,  1695,  4356,
    1491,  4354,   959, -1244,   445,   968,  1696,  1530,  8473,   975,
    5623,  2313, -1244, -1244,   818,  8494, -1244,  4072,   948,  1698,
     948,  1699,   948,  1704, -1244, -1244, -1244, -1244,   948,  1708,
    3982,  1712, -1244,   818, -1244,  1541,  1714,   976,  4393,   979,
    5651,  1650, -1244,  1548,  1725, -1244,  1549,  1900, -1244,  1556,
    2105, -1244,   984, -1244,   987, -1244,  1557,  2949, -1244,  4072,
   -1244,   940, -1244,  1715,  1717,   948,  1719,   948,  1722,   948,
   -1244,  1730,   818,  1732,   818,  1007,  4417, -1244, -1244, -1244,
    2211, -1244,  2559, -1244,  2619, -1244, -1244, -1244,  1010, -1244,
    1733,   940,  1734,  1735,  1736,   818,  1739, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1244, -1244, -1244, -1244,   701, -1244, -1244, -1244, -1244,   188,
   -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244,  -356,   -88, -1244,  1334, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244,  -395, -1244,   694,  1746, -1244,
   -1244, -1244, -1244,     1,  -456,  -223, -1244, -1244, -1244, -1244,
   -1244, -1244,  1747, -1244, -1244, -1244, -1244, -1244, -1244, -1244,
   -1244, -1244, -1244, -1244, -1244, -1244,  -923,  -849, -1244, -1244,
    1324, -1244, -1244, -1244, -1244, -1244,   248, -1244,    -9, -1244,
   -1243,   817,   708,  1163,   985,  -200,   580, -1244,    11,    -5,
    -350, -1244,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -458
static const yytype_int16 yytable[] =
{
     101,   161,   593,   162,    88,   988,   472,   704,   705,   304,
     239,   164,   603,   303,   453,  1363,   611,   160,   488,   615,
     180,   180,   185,   274,   850,   185,   277,  1110,   285,   287,
     502,   176,   167,  1536,  1199,   291,   222,   224,   177,   230,
     873,   461,   462,   484,  1099,   485,   405,   104,   375,   860,
     235,   242,   236,   243,  1192,  1020,   214,  1238,     4,  1239,
    1101,  1103,   736,   533,  1105,   535,   300,   301,   737,   215,
     216,   461,   462,   475,   461,   462,  -455,   307,  1406,   308,
     476,   130,   131,   132,   133,   134,   135,  1240,   651,  1241,
    1242,   652,  1243,   139,   295,   461,   462,  1108,   461,   462,
     210,   610,   176,   211,   102,   103,   104,   244,     5,   854,
     105,   106,   107,  1090,   699,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   309,   240,   310,
     130,   131,   132,   133,   134,   135,   136,   137,   138,  1100,
    1452,   163,   139,   140,   141,   461,   462,   380,   861,   862,
     863,   864,   408,   408,   517,  1102,  1104,   376,   377,  1106,
    1466,   165,   463,   989,  1021,  1022,   406,   409,   305,   188,
     306,   144,   145,   166,   241,   157,   857,   181,   181,   461,
     462,   169,   874,   278,   182,   855,   186,   275,   851,   856,
     292,   286,   288,   503,   168,  1537,   874,   293,   456,   457,
     300,   301,   486,   379,   461,   462,   465,   995,   170,   536,
     473,   500,   226,   171,   865,   227,   157,   311,   228,   312,
     706,   697,   698,   142,  1373,   296,   297,   298,   299,   143,
     144,   145,   296,   297,   298,   299,   146,   147,   148,   218,
     219,   713,   174,   840,   158,   300,   301,   844,   658,   220,
     659,  1108,   149,   150,   461,   462,   221,   151,   644,   231,
     645,   313,   152,   314,   153,   157,   154,   155,   610,   156,
     712,   157,   175,   461,   462,   461,   462,   616,   300,   301,
     541,   915,   916,   917,  1569,  1128,    44,    45,    46,    47,
     464,   614,   474,   760,    52,   300,   301,    55,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   518,
     397,   398,   172,   218,   219,   232,   399,   461,   462,   233,
     290,   461,   462,   220,  1141,  1354,   300,   301,   173,   247,
     229,   234,   248,  1086,   461,   462,  -456,  1109,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
    1358,   408,   408,   408,   594,   595,   596,   597,   598,   599,
     600,   601,   602,  1170,  1635,   605,   606,   607,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   517,   461,   462,   178,   399,   367,   368,   369,
     371,   374,   461,   462,   179,  1374,   646,   461,   462,  1421,
     199,   647,   404,   200,   654,   201,   410,   652,  1423,   296,
     297,   298,   299,  1425,   413,   415,   418,   419,   648,   421,
     415,   423,   424,   649,   415,   427,   428,   300,   301,   300,
     301,   415,   296,   297,   298,   299,   843,  -457,  1231,  1232,
     461,   462,   702,   703,   461,   462,   461,   462,   775,   450,
     457,   183,   300,   301,   380,   380,  1433,   184,   459,   460,
    1435,   207,  1436,   924,   208,   187,   209,   460,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   315,   498,   316,   499,   399,   500,  1142,  1473,
     156,  1476,   157,  1479,  1276,  1277,   461,   462,   512,   514,
     415,   188,   461,   462,   296,   297,   298,   299,   189,   521,
     522,   523,  1514,   525,   820,   845,   528,   529,  1517,   821,
     530,   317,   190,   318,   300,   301,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   518,   397,   398,
     319,   191,   320,   545,   399,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   461,
     462,   461,   462,  1560,   461,   462,   461,   462,   321,   846,
     322,   604,   396,   397,   398,  1520,   192,  1528,   415,   399,
    1530,   415,  1590,   194,  1108,   822,   195,  1108,   821,   196,
    1108,   626,   193,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   197,   823,
     882,  1029,   408,   775,   824,  1601,   834,  1604,   198,  1607,
    1167,   821,   512,  1169,  1171,  1610,   884,   825,   662,   203,
     826,  1046,   204,   667,   202,   205,   658,   206,   672,   673,
     914,   914,   914,   914,   678,   679,   996,  1047,  1158,   684,
     927,   212,   658,   658,   689,   690,   691,   933,  1159,   213,
    1388,   658,  1640,   948,  1642,  1389,  1644,   323,   325,   324,
     326,  1108,   461,   462,   707,   708,   709,   367,   368,   710,
     327,   217,   328,   714,   715,   716,   717,   718,   329,   238,
     330,   723,   225,   249,   725,   726,   237,   245,   415,   415,
     415,   246,   250,   733,   734,   735,   251,   740,     7,     8,
     937,   743,  1108,   270,   331,  1108,   332,   271,  1108,   415,
     938,  1108,   333,   280,   334,   751,   753,   272,   939,   940,
     941,   408,   273,   279,   942,   943,   944,   945,   281,   283,
    1342,  1343,   284,   294,   740,   997,   282,   335,   770,   336,
     357,  1108,   773,  1108,   358,  1108,   621,    20,    21,   622,
      23,    24,   623,    26,   624,    28,   337,    29,   338,   339,
     359,   340,    34,    35,   360,    37,    38,    39,   408,   361,
     362,    42,   405,   104,   408,   408,   364,  1176,   408,   408,
     408,   341,  1006,   342,   343,   408,   344,   363,  1009,  1010,
     365,   378,  1011,  1012,  1013,   507,  1107,   366,   508,  1015,
     345,   509,   346,   510,    63,    64,    65,   130,   131,   132,
     133,   134,   135,   847,   347,   384,   348,   383,   349,   139,
     350,   351,   408,   352,   400,   353,  1050,   354,   355,   658,
     356,   664,   996,   658,   401,   668,  1045,   394,   395,   396,
     397,   398,   871,   403,   420,   415,   399,   415,   879,   658,
     451,   674,   433,   434,   435,   753,   886,   438,   439,   440,
     658,   768,   750,   769,   658,   727,   839,   425,   658,   900,
     842,   658,   658,   962,   963,  1091,  1092,  1093,   906,   658,
     430,   964,  1172,   913,   913,   913,   913,   658,  1051,   977,
    1052,   415,   431,   480,   481,   104,   454,   436,   928,   929,
    1057,   658,  1058,  1083,   932,   493,   494,   144,   145,   437,
     658,  1468,  1126,   658,   658,  1127,  1129,   956,   441,   658,
     958,  1130,   658,   658,  1131,  1132,   446,   447,  1291,   130,
     131,   132,   133,   134,   135,   415,   658,   415,  1134,   455,
     466,   139,   415,   415,   415,   415,  1178,   658,  1179,  1180,
     415,   658,   658,  1181,  1182,   448,   429,   984,   487,   986,
     987,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   467,   658,   449,  1183,   399,
     452,   937,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   938,   468,   489,  1198,   399,   998,   999,   477,   939,
     940,   941,   478,   495,   482,   942,   943,   944,   945,   658,
    1280,  1217,  1000,  1001,  1002,  1003,  1004,  1005,  1300,  1332,
    1301,  1333,   415,   479,   415,     7,     8,   483,   490,   144,
     145,   658,   496,  1367,  1014,  1394,   497,  1395,  1017,  1300,
     504,  1434,  1023,  1300,  1481,  1464,  1482,   658,   501,  1493,
    1253,   491,   415,   415,   415,   415,  1300,  1036,  1499,   538,
     539,  1501,  1504,  1502,  1505,  1300,   658,  1509,  1510,   542,
     658,   505,  1529,   621,    20,    21,   622,    23,    24,   623,
      26,   624,    28,  1394,    29,  1566,   658,   506,  1589,    34,
      35,   492,    37,    38,    39,   658,   519,  1591,    42,   520,
     937,   415,  1300,  1619,  1595,  1620,   821,   524,  1622,   408,
     938,   658,   417,  1631,  1632,  1284,  1633,   422,   939,   940,
     941,   426,   526,  1281,   942,   943,   944,   945,   432,   527,
    1280,    63,    64,    65,  1300,  1446,  1650,  1655,   531,  1656,
     408,  1308,   532,  1311,   534,   540,   543,   544,   399,   546,
     617,   156,   619,   618,  1305,   620,     7,     8,  1484,   671,
     675,   676,  1122,   677,   685,  1125,   680,   681,   686,   687,
     688,   692,   694,   695,  1599,   719,  1133,  1337,   722,  1344,
     696,  1347,   721,  1350,   724,   731,   732,   380,   380,   741,
     742,   758,   765,   771,   744,   767,  1254,  1361,   745,   746,
    1364,  1365,   747,   761,   621,    20,    21,   622,    23,    24,
     623,    26,   624,    28,   772,    29,   827,   828,   829,   830,
      34,    35,  1378,    37,    38,    39,  1177,   831,   832,    42,
     833,   836,   837,   838,   848,   849,  1185,  1186,   853,   872,
     877,   881,   880,   888,   883,   893,  1195,  1197,   885,   889,
     890,   892,   894,   895,  1561,   937,   897,   898,   899,   903,
     908,   910,    63,    64,    65,   938,   923,   930,   931,   957,
     971,   980,   983,   939,   940,   941,   981,     7,     8,   942,
     943,   944,   945,   982,  1233,  1234,  1235,   990,   992,  1018,
     416,  1024,   937,  1016,  1245,   416,  1247,  1019,  1025,   416,
    1027,  1028,   938,  1031,  1038,   608,   416,  1252,   612,  1040,
     939,   940,   941,  1039,  1042,   415,   942,   943,   944,   945,
    1044,   157,  1049,   766,  1055,   621,    20,    21,   622,    23,
      24,   623,    26,   624,    28,  1061,    29,  1272,  1273,  1274,
    1062,    34,    35,  1066,    37,    38,    39,  1067,  1069,  1070,
      42,  1515,  1073,  1075,  1074,  1076,  1077,  1079,  1080,   537,
    1078,  1081,  1472,  1082,  1475,  1084,  1478,  1094,   380,  1285,
    1095,  1096,  1097,   513,  1486,   416,  1098,  1489,   841,  1111,
    1112,  1117,  1297,    63,    64,    65,  1113,  1303,  1518,  1114,
    1115,  1118,  1119,  1120,  1307,  1121,  1123,   937,  1309,  1310,
    1124,  1138,  1143,  1144,  1146,  1315,  1316,   938,  1147,  1148,
    1318,  1160,  1149,  1191,  1161,   939,   940,   941,  1325,  1163,
    1164,   942,   943,   944,   945,   728,   729,   730,  1335,  1162,
    1336,  1166,  1173,  1174,  1194,  1190,  1189,  1184,  1202,  1200,
    1201,  1206,  1353,  1209,   925,  1207,   748,  1215,   907,  1208,
    1210,  1212,  1213,  1214,   415,  1220,  1221,  1236,   415,   921,
    1223,  1368,  1224,  1225,  1226,  1230,  1237,  1244,  1248,  1249,
    1250,  1564,  1251,  1258,  1259,  1377,  1263,  1266,  1267,  1268,
    1269,  1271,  1270,   416,  1573,  1576,   416,  1275,  1278,  1279,
    1286,  1287,  1289,  1521,  1292,  1293,  1390,  1391,  1294,  1295,
    1304,  1312,  1321,  1313,  1397,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,  1314,
    1317,   408,  1319,   399,   937,  1320,  1322,   513,  1326,  1323,
    1331,  1334,  1345,  1348,   938,   991,  1351,  1355,  1418,  1359,
     408,  1362,   939,   940,   941,  1366,  1369,  1380,   942,   943,
     944,   945,  1381,  1382,  1615,  1383,  1432,  1385,   512,  1386,
    1396,  1405,  1393,  1387,  1407,  1408,  1637,  1409,  1410,  1440,
    1411,  1441,  1412,  1413,   415,  1416,  1428,  1437,  1417,   408,
    1419,   408,   876,  1420,   878,  1430,  1422,  1449,  1424,  1426,
    1431,  1439,  1453,  1646,  1444,  1649,  1658,  1445,  1454,  1458,
    1459,  1447,   408,   416,   416,   416,  1511,  1460,  1461,  1462,
    1463,  1465,   415,  1480,  1487,  1494,  1662,  1495,  1496,  1471,
    1586,  1474,  1523,  1477,   416,  1524,  1507,  1527,   922,  1532,
    1539,   754,  1540,   415,  1533,  1543,  1544,  1490,  1546,  1549,
    1550,  1553,  1554,  1557,  1558,  1578,  1563,  1580,  1497,  1498,
    1582,  1584,  1592,  1500,  1602,  1605,  1053,  1054,  1593,  1056,
    1608,  1059,  1060,  1508,  1611,  1063,  1064,  1512,  1613,  1617,
    1618,  1638,   968,  1639,   969,  1641,  1625,  1627,  1643,   973,
     974,   975,   976,   937,  1629,  1634,  1645,   979,  1647,  1657,
    1659,  1660,  1661,   938,  1303,  1663,   655,  1193,  1204,    87,
      95,   939,   940,   941,  1288,  1541,     0,   942,   943,   944,
     945,     0,  1548,     0,   683,  1552,     0,     0,  1556,     0,
       0,     0,  1559,     0,     0,     0,   415,     0,   415,     0,
       0,     0,     0,  1568,     0,     0,  1570,   643,  1575,     0,
       0,     0,     0,     0,     0,     0,     0,  1135,  1136,  1137,
       0,     0,     0,     0,     0,     0,     0,  1145,   937,  1007,
     416,  1008,   416,     0,     0,     0,     0,     0,   938,  1598,
     754,   887,     0,     0,     0,  1600,   939,   940,   941,  1624,
       0,     0,   942,   943,   944,   945,     0,     0,   415,  1032,
    1033,  1034,  1035,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,   416,  1188,     0,   399,
       0,     0,     0,     0,     0,     0,     0,  1636,     0,     0,
       0,     0,  1205,     0,     0,   835,     0,     0,  1211,     0,
       0,     0,     0,     0,  1216,     0,  1218,  1219,  1068,     0,
       0,  1222,     0,     0,     0,     0,  1227,  1228,  1229,  1026,
     416,     0,   416,     0,  1626,     0,     0,   416,   416,   416,
     416,     0,     0,  1246,     0,   416,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,  1257,     0,
       0,   399,  1261,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,   102,   289,
       0,   399,     0,     0,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,   937,  1282,     0,  1283,   416,     0,   416,
     136,   137,   138,   938,     0,     0,     0,   140,   141,     0,
       0,   939,   940,   941,     0,     0,     0,   942,   943,   944,
     945,     0,     0,     0,     0,     0,     0,   416,   416,   416,
     416,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
    1327,  1328,  1329,  1330,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,  1188,     0,     0,     0,  1628,
       0,     0,     0,   143,     0,  1065,     0,     0,  1370,     0,
     146,   147,   148,     0,     0,  1379,     0,     0,     0,     0,
       0,     0,  1262,     0,  1116,     0,   149,   150,     0,     0,
       0,   151,     0,     0,     0,     0,   261,  1392,     0,   372,
       0,   155,     0,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   252,     0,     0,  1188,     0,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   254,     0,     0,
       0,     0,  1429,     0,     0,     0,   136,   137,   138,     0,
       0,     0,     0,   140,   141,     0,     0,     0,   937,     0,
       0,   255,     0,     0,   256,     0,     0,   257,   938,   258,
       0,     0,     0,     0,     0,     0,   939,   940,   941,     0,
    1188,   259,   942,   943,   944,   945,     0,     0,    44,    45,
      46,    47,    48,     0,     0,     0,    52,     0,     0,    55,
    1188,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,  1483,     0,   399,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,   143,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
     416,     0,     0,     0,  1630,     0,     0,     0,     0,  1168,
       0,     0,   469,  1360,   937,     0,     0,   151,  1522,     0,
       0,     0,   471,     0,   938,     0,     0,   155,     0,   221,
     515,     0,   939,   940,   941,     0,   102,   252,   942,   943,
     944,   945,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   254,
    1175,     0,     0,     0,  1188,     0,  1572,     0,   136,   137,
     138,  1442,     0,     0,     0,   140,   141,     0,     0,     0,
       0,     0,     0,   255,     0,     0,   256,     0,     0,   257,
       0,   258,     0,     0,     0,     0,     0,     0,     0,     0,
    1652,     0,     0,   259,     0,     0,     0,     0,     0,  1467,
      44,    45,    46,    47,    48,     0,     0,     0,    52,     0,
       0,    55,     0,     7,     8,     0,     0,     0,     0,   416,
    1488,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1188,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,   143,     0,   399,     0,     0,     0,     0,   146,   147,
     148,   621,    20,    21,   622,    23,    24,   623,    26,   624,
      28,     0,    29,     0,   149,   414,     0,    34,    35,   151,
      37,    38,    39,     0,   261,     0,    42,     0,     0,   155,
       0,     0,   515,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,  1562,   399,  1565,     0,     0,     0,    63,
      64,    65,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   416,
       0,     0,   102,   289,     0,     0,     0,     0,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,  1612,     0,   416,     0,     0,
     926,     0,     0,     0,   136,   137,   138,     0,   102,   252,
     104,   140,   141,     0,   105,   106,   107,     0,   416,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   254,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,   139,   140,   141,     0,
       0,     0,   937,     0,     0,   255,     0,     0,   256,     0,
       0,   257,   938,   258,     0,     0,     0,     0,     0,     0,
     939,   940,   941,     0,     0,   259,   942,   943,   944,   945,
       0,     0,    44,    45,    46,    47,    48,   143,     0,     0,
      52,     0,     0,    55,   146,   147,   148,     0,     0,     0,
       0,   416,     0,   416,     0,     0,     0,     0,     0,     0,
     149,   150,   937,     0,     0,   151,     0,     0,     0,     0,
     261,     0,   938,   738,     0,   155,     0,   739,     0,     0,
     939,   940,   941,   143,   144,   145,   942,   943,   944,   945,
     146,   147,   148,     0,   416,     0,     0,     0,  1653,     0,
       0,     0,     0,     0,     0,     0,   149,   260,     0,     0,
       0,   151,     0,   416,     0,     0,   261,     0,   102,   252,
     253,   155,     0,  1571,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   254,     0,     0,     0,     0,     0,     0,  1654,     0,
     136,   137,   138,     0,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,   255,     0,     0,   256,     0,
       0,   257,     0,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,    44,    45,    46,    47,    48,     0,     0,     0,
      52,     0,     0,    55,     0,   102,   252,  1255,     0,     0,
       0,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   254,     0,
       0,     0,     0,   143,     0,     0,     0,   136,   137,   138,
     146,   147,   148,     0,   140,   141,     0,     0,     0,     0,
       0,     0,   255,     0,     0,   256,   149,   260,   257,     0,
     258,   151,     0,     0,     0,     0,   261,     0,     0,     0,
       0,   155,   259,   262,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,    52,     0,     0,
      55,     0,   102,   252,     0,     0,     0,     0,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   254,     0,     0,     0,     0,
     143,     0,     0,     0,   136,   137,   138,   146,   147,   148,
       0,   140,   141,     0,     0,     0,     0,     0,     0,   255,
       0,     0,   256,   149,   260,   257,     0,   258,   151,     0,
       0,     0,     0,   261,     0,     0,     0,     0,   155,   259,
    1256,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,     0,     0,     0,    52,     0,     0,    55,     0,   102,
     252,     0,     0,     0,     0,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   254,     0,     0,     0,     0,   143,     0,     0,
       0,   136,   137,   138,   146,   147,   148,     0,   140,   141,
       0,     0,     0,     0,     0,     0,   255,     0,     0,   256,
     149,   260,   257,     0,   258,   151,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   155,   259,   262,     0,     0,
       0,     0,     0,    44,    45,    46,    47,    48,     0,     0,
       0,    52,     0,     0,    55,     0,   102,   252,     0,     0,
       0,     0,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   254,
       0,     0,     0,     0,   143,     0,     0,     0,   136,   137,
     138,   146,   147,   148,     0,   140,   141,     0,     0,     0,
       0,     0,     0,   255,     0,     0,   256,   149,   414,   257,
       0,   258,   151,     0,     0,     0,     0,   261,     0,     0,
       0,     0,   155,   259,   511,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,     0,     0,     0,    52,     0,
       0,    55,     0,   102,   252,     0,     0,     0,     0,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   254,     0,     0,     0,
       0,   143,     0,     0,     0,   136,   137,   138,   146,   147,
     148,     0,   140,   141,     0,     0,     0,     0,     0,     0,
     255,     0,     0,   256,   149,   414,   257,     0,   258,   151,
       0,     0,     0,     0,   261,     0,     0,     0,     0,   155,
     259,   752,     0,     0,     0,     0,     0,    44,    45,    46,
      47,    48,     0,     0,     0,    52,     0,     0,    55,     0,
     102,   252,     0,     0,     0,     0,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   254,     0,     0,     0,     0,   143,     0,
       0,     0,   136,   137,   138,   146,   147,   148,     0,   140,
     141,     0,     0,     0,     0,     0,     0,   255,     7,     8,
     256,   149,   260,   257,     0,   258,   151,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   155,   259,  1260,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
       0,     0,    52,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   621,    20,    21,   622,
      23,    24,   623,    26,   624,    28,     0,    29,     0,     0,
       0,     0,    34,    35,     0,    37,    38,    39,     0,     0,
       0,    42,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,  1360,
       0,     0,     0,   151,    63,    64,    65,     0,   471,     0,
     102,   289,   104,   155,     0,   221,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   102,   289,   104,   139,   140,
     141,   105,   106,   107,     0,   949,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     102,   289,   104,   139,   140,   141,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   143,   144,   145,   139,   140,
     141,     0,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,   151,     0,     0,     0,     0,   261,     0,
       0,     0,     0,   155,     0,  1196,     0,     0,     0,     0,
     143,   144,   145,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   150,     0,     0,     0,   151,     0,
    1264,     0,     0,   261,     0,     0,     0,     0,   155,     0,
    1376,     0,     0,     0,     0,   143,   144,   145,     0,  1384,
       0,     0,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,   151,     0,     0,     0,     0,   261,     0,
     102,   289,     0,   155,     0,  1574,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   102,   289,     0,     0,   140,
     141,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
       0,     0,     0,     0,   140,   141,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   143,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,   151,     0,     0,     0,     0,   261,     0,
       0,     0,     0,   155,     0,   370,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,   470,     0,     0,     0,   151,     0,
       0,     0,     0,   471,     0,   102,   252,     0,   155,     0,
     221,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   254,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
       0,     0,     0,     0,   140,   141,     0,     0,     0,     0,
       0,     0,   255,     0,     0,   256,     0,     0,   257,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,     0,   102,   289,    52,     0,     0,
      55,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     143,     0,     0,     0,   140,   141,     0,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   414,     0,     0,     0,   151,   102,
     289,   104,     0,   261,     0,   105,   106,   107,   155,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,   141,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   150,     0,     0,     0,   151,     0,
    1415,     0,     0,   261,     0,     0,     0,     0,   155,     0,
       0,   621,    20,    21,   622,    23,    24,   623,    26,   624,
      28,     0,    29,     0,     0,     0,     0,    34,    35,     0,
      37,    38,    39,     0,     0,     0,    42,     7,     8,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,   146,   147,   148,     0,     0,     0,     0,     0,  1443,
       0,     0,     0,     0,     7,     8,     0,   149,   150,    63,
      64,    65,   151,     0,     0,     0,     0,   261,     0,     0,
       0,     0,   155,     0,     0,   621,    20,    21,   622,    23,
      24,   623,    26,   624,    28,  1531,    29,     0,     0,     0,
       0,    34,    35,     0,    37,    38,    39,     0,     0,     0,
      42,     0,   621,    20,    21,   622,    23,    24,   623,    26,
     624,    28,  1585,    29,     0,     0,     7,     8,    34,    35,
     985,    37,    38,    39,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    63,    64,    65,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
    1621,   517,     0,     0,   399,     0,     0,     0,     0,     0,
      63,    64,    65,     0,   621,    20,    21,   622,    23,    24,
     623,    26,   624,    28,  1651,    29,     0,     0,     0,     0,
      34,    35,     0,    37,    38,    39,     0,     0,     0,    42,
       0,     0,     0,     0,  1085,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   517,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,  1525,    63,    64,    65,     0,     0,     0,   762,     0,
       0,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,   859,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   978,     0,     0,     0,   399,     0,     0,     0,
       0,     0,     0,  1587,     0,     0,     0,     0,     0,     0,
       0,  1140,     0,     0,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   657,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   657,   397,   398,     0,     0,     0,
       0,   399,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
      -4,     1,     0,   399,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,     0,     0,     0,    -4,    -4,  1340,
       0,  1341,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
       0,     0,    -4,     6,     0,     0,     0,    -4,    -4,    -4,
      -4,     7,     8,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,    -4,     0,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,    14,    15,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       7,     8,     0,    58,    59,    60,  1071,     0,     0,     0,
       0,    61,     0,     0,     0,     0,    62,    63,    64,    65,
       0,     0,    66,     0,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      79,    80,    81,    82,     0,     0,     0,     0,   621,    20,
      21,   622,    23,    24,   623,    26,   624,    28,     0,    29,
       0,     0,     0,     0,    34,    35,     0,    37,    38,    39,
       0,     0,     0,    42,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,  1371,     0,  1372,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,  1469,     0,  1470,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,   858,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
     902,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,   952,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,     0,     0,   972,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,   993,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,  1089,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
    1338,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,  1357,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,     0,     0,  1400,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,  1401,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,  1402,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
    1403,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,  1404,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,     0,     0,  1438,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,  1485,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,  1491,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
    1492,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,  1513,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,     0,     0,  1516,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,  1519,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,  1542,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
    1545,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,  1579,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,     0,     0,  1581,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,  1583,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,  1596,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
    1623,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,   693,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,  1414,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   749,     0,     0,     0,     0,
     700,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,   650,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,   700,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,   701,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,   759,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
     798,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,   799,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,   814,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,   815,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,   816,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
     817,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,   818,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,   819,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,   934,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,   935,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
     936,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,   967,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,  1048,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,  1087,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,  1088,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
    1139,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,  1298,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,  1299,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,  1306,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,  1450,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
    1451,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,  1455,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,  1535,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,     0,     0,     0,  1538,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,     0,     0,     0,  1577,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,   613,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,     0,     0,
     764,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,   774,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,     0,     0,   777,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,   779,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
       0,     0,   781,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,   783,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,     0,     0,   785,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,   787,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,     0,     0,   789,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,   791,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,     0,     0,
     793,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,   795,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,     0,     0,   797,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,   801,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
       0,     0,   803,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,   805,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,     0,     0,   807,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,   809,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,     0,     0,   811,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,   813,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,     0,     0,
     960,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,   961,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,     0,     0,   965,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,   966,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
       0,     0,   970,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,     0,     0,   994,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,     0,     0,  1043,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,     0,
       0,  1151,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,     0,     0,  1153,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,  1155,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,     0,     0,
    1157,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,     0,     0,  1265,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,     0,     0,  1290,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,     0,     0,  1427,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
     609,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,   656,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,   660,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,   661,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,   663,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   665,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,   666,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,   669,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   670,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,   749,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
     755,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,   756,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,   757,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,   763,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,   776,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   778,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,   780,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,   782,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   784,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,   786,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
     788,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,   790,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,   792,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,   794,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,   796,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   800,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,   802,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,   804,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   806,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,   808,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
     810,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,   812,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,   891,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,   896,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,   901,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   904,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,   905,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,   911,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   918,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,   919,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
     920,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,   951,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,   953,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,   954,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,   955,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   959,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,  1150,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   399,     0,  1152,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   399,     0,  1154,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,     0,     0,     0,   399,     0,  1156,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,     0,
    1165,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,     0,     0,     0,     0,   399,
       0,  1339,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,     0,     0,
     399,     0,  1356,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,     0,  1375,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     0,     0,
       0,     0,   399,     0,  1534,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,  1594,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399
};

static const yytype_int16 yycheck[] =
{
       3,     6,   352,     6,     3,     7,   229,   463,   464,     4,
       4,    66,   362,   101,   214,  1258,   372,     6,   241,   375,
       4,     4,     4,     4,     4,     4,     4,   950,     5,     5,
       5,   171,     6,     6,     6,     6,    45,    46,   178,    48,
       6,   161,   162,     4,     6,     6,     4,     5,     4,     4,
      66,     4,    68,     6,     6,     4,   123,   177,     6,   179,
       6,     6,   172,   286,     6,   288,   168,   169,   178,   136,
     137,   161,   162,   171,   161,   162,   178,   171,  1321,   173,
     178,    39,    40,    41,    42,    43,    44,   177,   174,   179,
     177,   177,   179,    51,     7,   161,   162,   946,   161,   162,
      63,     7,   171,    66,     3,     4,     5,    60,     0,   178,
       9,    10,    11,   179,   177,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   171,   132,   173,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   111,
    1393,    13,    51,    52,    53,   161,   162,   156,   113,   114,
     115,   116,   165,   166,     8,   111,   111,   123,   124,   111,
    1413,   171,   178,   175,   123,   124,   165,   166,   173,   171,
     175,   139,   140,   171,   178,   180,   178,   171,   171,   161,
     162,     6,   158,   171,   178,   178,   178,   178,   178,   178,
     171,   178,   178,   178,   178,   178,   158,   178,   217,   218,
     168,   169,   173,     4,   161,   162,   225,   175,     6,   173,
     229,   175,    60,     6,   179,    63,   180,   171,    66,   173,
     177,   454,   455,   132,     8,   148,   149,   150,   151,   138,
     139,   140,   148,   149,   150,   151,   145,   146,   147,   161,
     162,   474,   173,   609,     6,   168,   169,   613,   177,   171,
     179,  1110,   161,   162,   161,   162,   178,   166,   173,     4,
     175,   171,   171,   173,   173,   180,   175,   176,     7,   178,
     177,   180,   173,   161,   162,   161,   162,   375,   168,   169,
     295,   686,   687,   688,  1537,   175,    87,    88,    89,    90,
     178,     7,   178,   526,    95,   168,   169,    98,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     6,   161,   162,    60,   170,   161,   162,    64,
      82,   161,   162,   171,     8,   179,   168,   169,     6,    63,
     178,    76,    66,   177,   161,   162,   178,   177,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     177,   364,   365,   366,   353,   354,   355,   356,   357,   358,
     359,   360,   361,     7,  1617,   364,   365,   366,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     8,   161,   162,   171,   170,   149,   150,   151,
     152,   153,   161,   162,   171,   179,   172,   161,   162,   177,
      63,   177,   164,    66,   174,    68,   168,   177,   177,   148,
     149,   150,   151,   177,   176,   177,   178,   179,   172,   181,
     182,   183,   184,   177,   186,   187,   188,   168,   169,   168,
     169,   193,   148,   149,   150,   151,   175,   178,     6,     7,
     161,   162,   461,   462,   161,   162,   161,   162,   546,   211,
     469,   171,   168,   169,   463,   464,   177,   171,   220,   221,
     177,    63,   177,   696,    66,   171,    68,   229,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   171,   171,   173,   173,   170,   175,   172,  1422,
     178,  1424,   180,  1426,     6,     7,   161,   162,   260,   261,
     262,   171,   161,   162,   148,   149,   150,   151,    70,   271,
     272,   273,   177,   275,   172,   613,   278,   279,   177,   177,
     282,   171,    66,   173,   168,   169,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     171,    66,   173,   305,   170,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   161,
     162,   161,   162,  1526,   161,   162,   161,   162,   171,   614,
     173,   363,   163,   164,   165,   177,     6,   177,   370,   170,
     177,   373,   177,    60,  1473,   174,    63,  1476,   177,    66,
    1479,   383,   178,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,    66,   172,
     653,   851,   655,   741,   177,  1578,   172,  1580,    66,  1582,
    1016,   177,   414,  1019,  1020,  1588,   655,   174,   420,    60,
     177,   172,    63,   425,    68,    66,   177,    68,   430,   431,
     685,   686,   687,   688,   436,   437,   774,   172,   172,   441,
     699,   171,   177,   177,   446,   447,   448,   706,   174,    63,
     172,   177,  1625,   712,  1627,   177,  1629,   171,   171,   173,
     173,  1560,   161,   162,   466,   467,   468,   469,   470,   471,
     171,   178,   173,   475,   476,   477,   478,   479,   171,    63,
     173,   483,   178,     4,   486,   487,    66,    63,   490,   491,
     492,    66,     4,   495,   496,   497,     4,   499,    12,    13,
      83,   503,  1601,     4,   171,  1604,   173,   171,  1607,   511,
      93,  1610,   171,     6,   173,   517,   518,   171,   101,   102,
     103,   774,   171,   171,   107,   108,   109,   110,     6,     4,
    1236,  1237,     4,   180,   536,   774,   173,   171,   540,   173,
     171,  1640,   544,  1642,   171,  1644,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,   171,    71,   173,   171,
     171,   173,    76,    77,   171,    79,    80,    81,   821,   171,
     171,    85,     4,     5,   827,   828,   171,  1027,   831,   832,
     833,   171,   821,   173,   171,   838,   173,     7,   827,   828,
     171,     4,   831,   832,   833,    60,   179,   171,    63,   838,
     171,    66,   173,    68,   118,   119,   120,    39,    40,    41,
      42,    43,    44,   615,   171,     6,   173,   178,   171,    51,
     173,   171,   875,   173,   178,   171,   885,   173,   171,   177,
     173,   179,   970,   177,     6,   179,   875,   161,   162,   163,
     164,   165,   644,     6,   171,   647,   170,   649,   650,   177,
       4,   179,   194,   195,   196,   657,   658,   199,   200,   201,
     177,   177,   179,   179,   177,   179,   179,   171,   177,   671,
     179,   177,   177,   179,   179,   934,   935,   936,   680,   177,
     171,   179,  1020,   685,   686,   687,   688,   177,    66,   179,
      68,   693,   178,   235,   236,     5,   178,   171,   700,   701,
      66,   177,    68,   179,   706,   247,   248,   139,   140,   171,
     177,  1417,   179,   177,   177,   179,   179,   719,   171,   177,
     722,   179,   177,   177,   179,   179,   171,   171,  1178,    39,
      40,    41,    42,    43,    44,   737,   177,   739,   179,   178,
     178,    51,   744,   745,   746,   747,   177,   177,   179,   179,
     752,   177,   177,   179,   179,   171,   189,   759,   173,   761,
     762,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   178,   177,   210,   179,   170,
     213,    83,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    93,   178,     6,  1049,   170,   798,   799,   171,   101,
     102,   103,   171,   173,   237,   107,   108,   109,   110,   177,
    1148,   179,   814,   815,   816,   817,   818,   819,   177,     4,
     179,     6,   824,   171,   826,    12,    13,   171,   178,   139,
     140,   177,   173,   179,   836,   177,   173,   179,   840,   177,
       5,   179,   844,   177,   177,   179,   179,   177,   173,   179,
    1109,   178,   854,   855,   856,   857,   177,   859,   179,   292,
     293,   177,   177,   179,   179,   177,   177,   179,   179,   302,
     177,     5,   179,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,   177,    71,   179,   177,     5,   179,    76,
      77,   178,    79,    80,    81,   177,     6,   179,    85,     6,
      83,   903,   177,   177,   179,   179,   177,   175,   179,  1162,
      93,   177,   177,   179,   177,  1170,   179,   182,   101,   102,
     103,   186,   178,  1162,   107,   108,   109,   110,   193,   126,
    1268,   118,   119,   120,   177,  1385,   179,   177,     6,   179,
    1193,  1196,     6,  1202,     6,   178,     6,   173,   170,     4,
     175,   178,   173,     7,  1193,   179,    12,    13,  1431,     7,
       6,     6,   964,     6,   171,   967,     7,     7,   171,   171,
     171,     7,   172,     6,  1574,     7,   978,  1232,     7,  1238,
     178,  1240,     6,  1242,     6,     6,     6,  1236,  1237,     4,
       4,   123,   179,     6,   178,   172,   179,  1256,   178,   178,
    1259,  1260,   178,   178,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     6,    71,   177,   177,   172,   172,
      76,    77,  1277,    79,    80,    81,  1028,   177,   177,    85,
     177,   177,   172,   177,     6,     4,  1038,  1039,   174,     4,
       6,     4,     6,   126,     6,   126,  1048,  1049,     7,     7,
       7,     7,     7,     7,  1527,    83,   126,     7,     7,   178,
       4,     6,   118,   119,   120,    93,   175,   179,   179,     6,
     174,     7,   175,   101,   102,   103,     7,    12,    13,   107,
     108,   109,   110,     7,  1086,  1087,  1088,   178,     6,     6,
     177,     6,    83,   172,  1096,   182,  1098,   174,     6,   186,
       7,   173,    93,     6,   171,   370,   193,  1109,   373,   178,
     101,   102,   103,   171,     6,  1117,   107,   108,   109,   110,
     158,   180,     7,   179,     7,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     7,    71,  1139,  1140,  1141,
      68,    76,    77,     7,    79,    80,    81,     7,     7,     7,
      85,   179,     6,   172,     7,   172,   172,     7,     7,     6,
     172,     7,  1421,     6,  1423,     4,  1425,     4,  1417,  1171,
       6,   178,     6,   260,  1433,   262,   171,  1436,   611,     7,
       6,   178,  1184,   118,   119,   120,     7,  1189,   179,     7,
       7,     6,     6,     6,  1196,    66,     6,    83,  1200,  1201,
       6,     4,     4,     4,   179,  1207,  1208,    93,     6,     4,
    1212,   172,     6,     6,   174,   101,   102,   103,  1220,   172,
     172,   107,   108,   109,   110,   490,   491,   492,  1230,   177,
    1232,   172,   175,     7,     6,   175,   178,   171,    76,   178,
     178,     6,  1244,     6,   179,   178,   511,     5,   681,   178,
       6,   178,     6,     6,  1256,     4,     6,   178,  1260,   692,
       7,  1263,     7,     7,     7,     7,   178,   173,     6,     6,
       6,  1530,     6,   178,   178,  1277,   178,   172,   174,     4,
       6,   122,     6,   370,  1539,  1540,   373,     6,   177,     6,
       6,     4,     6,   179,     6,     6,  1298,  1299,     6,     6,
       4,     6,   178,     6,  1306,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     6,
       6,  1574,     5,   170,    83,     6,     6,   414,     6,   126,
       6,     6,     6,     6,    93,   768,     6,   177,  1340,     6,
    1593,     6,   101,   102,   103,     6,     6,   172,   107,   108,
     109,   110,     6,     6,  1593,     6,  1358,     7,  1360,     6,
       6,     5,   178,   175,    64,     6,  1621,     6,     6,  1371,
       6,  1373,     6,   178,  1376,     6,     6,     6,   178,  1632,
     179,  1634,   647,   179,   649,     7,   178,  1389,   178,   178,
     178,   121,  1394,  1632,     6,  1634,  1651,   179,     6,     6,
       6,   124,  1655,   490,   491,   492,   179,     6,     6,     6,
       6,   178,  1414,     6,     6,     6,  1655,     6,   178,  1421,
     179,  1423,     6,  1425,   511,    83,   178,   178,   693,     6,
       4,   518,     4,  1435,  1496,     6,     6,  1439,     6,     6,
       6,     6,     6,     6,   179,   178,     6,   178,  1450,  1451,
     178,     6,     6,  1455,     6,     6,   889,   890,   178,   892,
       6,   894,   895,  1465,     6,   898,   899,  1469,     6,   178,
       6,     6,   737,     6,   739,     6,   178,   178,     6,   744,
     745,   746,   747,    83,   178,   178,     6,   752,     6,     6,
       6,     6,     6,    93,  1496,     6,   412,  1046,  1054,     3,
       3,   101,   102,   103,  1174,  1507,    -1,   107,   108,   109,
     110,    -1,  1514,    -1,   440,  1517,    -1,    -1,  1520,    -1,
      -1,    -1,  1524,    -1,    -1,    -1,  1528,    -1,  1530,    -1,
      -1,    -1,    -1,  1535,    -1,    -1,  1538,     6,  1540,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   980,   981,   982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   990,    83,   824,
     647,   826,   649,    -1,    -1,    -1,    -1,    -1,    93,  1571,
     657,   658,    -1,    -1,    -1,  1577,   101,   102,   103,   179,
      -1,    -1,   107,   108,   109,   110,    -1,    -1,  1590,   854,
     855,   856,   857,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   693,  1040,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1619,    -1,    -1,
      -1,    -1,  1055,    -1,    -1,     6,    -1,    -1,  1061,    -1,
      -1,    -1,    -1,    -1,  1067,    -1,  1069,  1070,   903,    -1,
      -1,  1074,    -1,    -1,    -1,    -1,  1079,  1080,  1081,     6,
     737,    -1,   739,    -1,   179,    -1,    -1,   744,   745,   746,
     747,    -1,    -1,  1096,    -1,   752,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,  1111,    -1,
      -1,   170,  1115,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,     3,     4,
      -1,   170,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    83,  1167,    -1,  1169,   824,    -1,   826,
      45,    46,    47,    93,    -1,    -1,    -1,    52,    53,    -1,
      -1,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   854,   855,   856,
     857,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
    1223,  1224,  1225,  1226,    -1,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   903,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,   179,
      -1,    -1,    -1,   138,    -1,     6,    -1,    -1,  1271,    -1,
     145,   146,   147,    -1,    -1,  1278,    -1,    -1,    -1,    -1,
      -1,    -1,  1117,    -1,     6,    -1,   161,   162,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,   171,  1300,    -1,   174,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,  1321,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,  1355,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    83,    -1,
      -1,    60,    -1,    -1,    63,    -1,    -1,    66,    93,    68,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,
    1393,    80,   107,   108,   109,   110,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
    1413,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,  1430,    -1,   170,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
    1117,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,     6,
      -1,    -1,   161,   162,    83,    -1,    -1,   166,  1481,    -1,
      -1,    -1,   171,    -1,    93,    -1,    -1,   176,    -1,   178,
     179,    -1,   101,   102,   103,    -1,     3,     4,   107,   108,
     109,   110,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       6,    -1,    -1,    -1,  1537,    -1,  1539,    -1,    45,    46,
      47,  1376,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,  1414,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    12,    13,    -1,    -1,    -1,    -1,  1256,
    1435,    -1,    -1,  1260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1617,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,   138,    -1,   170,    -1,    -1,    -1,    -1,   145,   146,
     147,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,   161,   162,    -1,    76,    77,   166,
      79,    80,    81,    -1,   171,    -1,    85,    -1,    -1,   176,
      -1,    -1,   179,    -1,    -1,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,  1528,   170,  1530,    -1,    -1,    -1,   118,
     119,   120,    -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,  1590,    -1,  1414,    -1,    -1,
     179,    -1,    -1,    -1,    45,    46,    47,    -1,     3,     4,
       5,    52,    53,    -1,     9,    10,    11,    -1,  1435,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    83,    -1,    -1,    60,    -1,    -1,    63,    -1,
      -1,    66,    93,    68,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,    -1,    -1,    80,   107,   108,   109,   110,
      -1,    -1,    87,    88,    89,    90,    91,   138,    -1,    -1,
      95,    -1,    -1,    98,   145,   146,   147,    -1,    -1,    -1,
      -1,  1528,    -1,  1530,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    83,    -1,    -1,   166,    -1,    -1,    -1,    -1,
     171,    -1,    93,   174,    -1,   176,    -1,   178,    -1,    -1,
     101,   102,   103,   138,   139,   140,   107,   108,   109,   110,
     145,   146,   147,    -1,  1571,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,    -1,  1590,    -1,    -1,   171,    -1,     3,     4,
       5,   176,    -1,   178,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    45,    46,    47,
     145,   146,   147,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    63,   161,   162,    66,    -1,
      68,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   176,    80,   178,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    45,    46,    47,   145,   146,   147,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    63,   161,   162,    66,    -1,    68,   166,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    80,
     178,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    45,    46,    47,   145,   146,   147,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,
     161,   162,    66,    -1,    68,   166,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,   176,    80,   178,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    45,    46,
      47,   145,   146,   147,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,   161,   162,    66,
      -1,    68,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,    -1,   176,    80,   178,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    45,    46,    47,   145,   146,
     147,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    63,   161,   162,    66,    -1,    68,   166,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,
      80,   178,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    -1,    45,    46,    47,   145,   146,   147,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    12,    13,
      63,   161,   162,    66,    -1,    68,   166,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,    -1,   176,    80,   178,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    77,    -1,    79,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   118,   119,   120,    -1,   171,    -1,
       3,     4,     5,   176,    -1,   178,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,     4,     5,    51,    52,
      53,     9,    10,    11,    -1,   179,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,     4,     5,    51,    52,    53,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   138,   139,   140,    51,    52,
      53,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,    -1,
       6,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,     6,
      -1,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,    -1,
       3,     4,    -1,   176,    -1,   178,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,     3,     4,    -1,    -1,    52,
      53,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,   171,    -1,     3,     4,    -1,   176,    -1,
     178,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    63,    -1,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    -1,     3,     4,    95,    -1,    -1,
      98,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
     138,    -1,    -1,    -1,    52,    53,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,     3,
       4,     5,    -1,   171,    -1,     9,    10,    11,   176,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,    -1,
       6,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,
      79,    80,    81,    -1,    -1,    -1,    85,    12,    13,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    12,    13,    -1,   161,   162,   118,
     119,   120,   166,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     6,    71,    -1,    -1,    -1,
      -1,    76,    77,    -1,    79,    80,    81,    -1,    -1,    -1,
      85,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     6,    71,    -1,    -1,    12,    13,    76,    77,
     179,    79,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       7,     8,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     7,    71,    -1,    -1,    -1,    -1,
      76,    77,    -1,    79,    80,    81,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     8,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   118,   119,   120,    -1,    -1,    -1,     8,    -1,
      -1,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,     8,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     8,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
       0,     1,    -1,   170,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,    -1,    37,    38,   177,
      -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,   112,     4,    -1,    -1,    -1,   117,   118,   119,
     120,    12,    13,   123,    -1,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,    -1,
      -1,   141,   142,   143,   144,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      12,    13,    -1,   104,   105,   106,    83,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,    -1,   123,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      -1,    -1,    -1,    -1,    76,    77,    -1,    79,    80,    81,
      -1,    -1,    -1,    85,    -1,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,   179,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,    -1,    -1,    -1,    -1,
     177,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   177,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   177,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   177,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   177,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   177,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   177,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
     172,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,   172,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,   172,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,   172,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,   172,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
     172,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,   172,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,   172,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,   172,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,   172,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
     172,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,   172,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,   172,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,   172,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,   172,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
     172,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,   172,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,   172,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,   172,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,   172,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
     172,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,   172,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,   172,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,   172,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,   172,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,   172,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,
     172,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,   172,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,   172,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    -1,   172,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,   172,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,   172,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   182,   183,     6,     0,     4,    12,    13,    37,
      38,    48,    49,    50,    54,    55,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   104,   105,
     106,   112,   117,   118,   119,   120,   123,   125,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   141,
     142,   143,   144,   184,   186,   187,   205,   219,   224,   227,
     228,   229,   230,   231,   232,   233,   253,   254,   255,   256,
     272,   273,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    51,
      52,    53,   132,   138,   139,   140,   145,   146,   147,   161,
     162,   166,   171,   173,   175,   176,   178,   180,   257,   258,
     269,   270,   273,    13,    66,   171,   171,     6,   178,     6,
       6,     6,     6,     6,   173,   173,   171,   178,   171,   171,
       4,   171,   178,   171,   171,     4,   178,   171,   171,    70,
      66,    66,     6,   178,    60,    63,    66,    66,    66,    63,
      66,    68,    68,    60,    63,    66,    68,    63,    66,    68,
      63,    66,   171,    63,   123,   136,   137,   178,   161,   162,
     171,   178,   259,   260,   259,   178,    60,    63,    66,   178,
     259,     4,    60,    64,    76,    66,    68,    66,    63,     4,
     132,   178,     4,     6,    60,    63,    66,    63,    66,     4,
       4,     4,     4,     5,    36,    60,    63,    66,    68,    80,
     162,   171,   178,   224,   233,   257,   262,   263,   264,   273,
       4,   171,   171,   171,     4,   178,   266,     4,   171,   171,
       6,     6,   173,     4,     4,     5,   178,     5,   178,     4,
     257,     6,   171,   178,   180,     7,   148,   149,   150,   151,
     168,   169,   203,   204,     4,   173,   175,   171,   173,   171,
     173,   171,   173,   171,   173,   171,   173,   171,   173,   171,
     173,   171,   173,   171,   173,   171,   173,   171,   173,   171,
     173,   171,   173,   171,   173,   171,   173,   171,   173,   171,
     173,   171,   173,   171,   173,   171,   173,   171,   173,   171,
     173,   171,   173,   171,   173,   171,   173,   171,   171,   171,
     171,   171,   171,     7,   171,   171,   171,   257,   257,   257,
     178,   257,   174,   178,   257,     4,   123,   124,     4,     4,
     224,   225,   226,   178,     6,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   170,
     178,     6,   204,     6,   257,     4,   269,   270,   273,   269,
     257,   207,   210,   257,   162,   257,   264,   265,   257,   257,
     171,   257,   265,   257,   257,   171,   265,   257,   257,   262,
     171,   178,   265,   263,   263,   263,   171,   171,   263,   263,
     263,   171,   220,   221,   222,   223,   171,   171,   171,   262,
     257,     4,   262,   266,   178,   178,   259,   259,   259,   257,
     257,   161,   162,   178,   178,   259,   178,   178,   178,   161,
     162,   171,   226,   259,   178,   171,   178,   171,   171,   171,
     263,   263,   262,   171,     4,     6,   173,   173,   226,     6,
     178,   178,   178,   263,   263,   173,   173,   173,   171,   173,
     175,   173,     5,   178,     5,     5,     5,    60,    63,    66,
      68,   178,   257,   264,   257,   179,   265,     8,   163,     6,
       6,   257,   257,   257,   175,   257,   178,   126,   257,   257,
     257,     6,     6,   226,     6,   226,   173,     6,   262,   262,
     178,   270,   262,     6,   173,   257,     4,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   269,   271,   271,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   271,   257,   269,   269,   269,   265,   172,
       7,   203,   265,   174,     7,   203,   204,   175,     7,   173,
     179,    60,    63,    66,    68,   219,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   188,     6,   173,   175,   172,   177,   172,   177,
     177,   174,   177,   206,   174,   206,   172,   163,   177,   179,
     172,   172,   257,   172,   179,   172,   172,   257,   179,   172,
     172,     7,   257,   257,   179,     6,     6,     6,   257,   257,
       7,     7,   251,   251,   257,   171,   171,   171,   171,   257,
     257,   257,     7,   178,   172,     6,   178,   226,   226,   177,
     177,   177,   259,   259,   225,   225,   177,   257,   257,   257,
     257,   237,   177,   226,   257,   257,   257,   257,   257,     7,
     252,     6,     7,   257,     6,   257,   257,   179,   265,   265,
     265,     6,     6,   257,   257,   257,   172,   178,   174,   178,
     257,     4,     4,   257,   178,   178,   178,   178,   265,   172,
     179,   257,   178,   257,   264,   172,   172,   172,   123,   177,
     226,   178,     8,   172,   174,   179,   179,   172,   177,   179,
     257,     6,     6,   257,   174,   204,   172,   174,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   172,   174,   172,   174,   172,   174,   177,   177,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   172,   174,   177,   177,   177,   177,   177,   177,
     172,   177,   174,   172,   177,   174,   177,   177,   177,   172,
     172,   177,   177,   177,   172,     6,   177,   172,   177,   179,
     203,   262,   179,   175,   203,   204,   270,   257,     6,     4,
       4,   178,   267,   174,   178,   178,   178,   178,   179,     8,
       4,   113,   114,   115,   116,   179,   191,   195,   198,   200,
     201,   257,     4,     6,   158,   185,   265,     6,   265,   257,
       6,     4,   273,     6,   269,     7,   257,   264,   126,     7,
       7,   172,     7,   126,     7,     7,   172,   126,     7,     7,
     257,   172,   179,   178,   172,   172,   257,   262,     4,   250,
       6,   172,   216,   257,   270,   216,   216,   216,   172,   172,
     172,   262,   265,   175,   226,   179,   179,   259,   257,   257,
     179,   179,   257,   259,   177,   177,   177,    83,    93,   101,
     102,   103,   107,   108,   109,   110,   247,   248,   259,   179,
     234,   172,   179,   172,   172,   172,   257,     6,   257,   172,
     174,   174,   179,   179,   179,   174,   174,   177,   265,   265,
     174,   174,   179,   265,   265,   265,   265,   179,     8,   265,
       7,     7,     7,   175,   257,   179,   257,   257,     7,   175,
     178,   262,     6,   179,   174,   175,   204,   269,   257,   257,
     257,   257,   257,   257,   257,   257,   269,   265,   265,   269,
     269,   269,   269,   269,   257,   269,   172,   257,     6,   174,
       4,   123,   124,   257,     6,     6,     6,     7,   173,   266,
     268,     6,   265,   265,   265,   265,   257,   192,   171,   171,
     178,   202,     6,   174,   158,   269,   172,   172,   177,     7,
     259,    66,    68,   262,   262,     7,   262,    66,    68,   262,
     262,     7,    68,   262,   262,     6,     7,     7,   265,     7,
       7,    83,   249,     6,     7,   172,   172,   172,   172,     7,
       7,     7,     6,   179,     4,   179,   177,   177,   177,   179,
     179,   259,   259,   259,     4,     6,   178,     6,   171,     6,
     111,     6,   111,     6,   111,     6,   111,   179,   248,   177,
     247,     7,     6,     7,     7,     7,     6,   178,     6,     6,
       6,    66,   257,     6,     6,   257,   179,   179,   175,   179,
     179,   179,   179,   257,   179,   262,   262,   262,     4,   177,
       8,     8,   172,     4,     4,   262,   179,     6,     4,     6,
     172,   174,   172,   174,   172,   174,   172,   174,   172,   174,
     172,   174,   177,   172,   172,   172,   172,   203,     6,   203,
       7,   203,   204,   175,     7,     6,   266,   257,   177,   179,
     179,   179,   179,   179,   171,   257,   257,   261,   262,   178,
     175,     6,     6,   185,     6,   257,   178,   257,   270,     6,
     178,   178,    76,   218,   218,   262,     6,   178,   178,     6,
       6,   262,   178,     6,     6,     5,   262,   179,   262,   262,
       4,     6,   262,     7,     7,     7,     7,   262,   262,   262,
       7,     6,     7,   257,   257,   257,   178,   178,   177,   179,
     177,   179,   177,   179,   173,   257,   262,   257,     6,     6,
       6,     6,   257,   259,   179,     5,   178,   262,   178,   178,
     178,   262,   265,   178,     6,   174,   172,   174,     4,     6,
       6,   122,   257,   257,   257,     6,     6,     7,   177,     6,
     204,   269,   262,   262,   270,   257,     6,     4,   267,     6,
     174,   266,     6,     6,     6,     6,   189,   257,   177,   177,
     177,   179,   190,   257,     4,   269,   177,   257,   270,   257,
     257,   259,     6,     6,     6,   257,   257,     6,   257,     5,
       6,   178,     6,   126,   217,   257,     6,   262,   262,   262,
     262,     6,     4,     6,     6,   257,   257,   270,   179,   172,
     177,   179,   225,   225,   259,     6,   238,   259,     6,   239,
     259,     6,   240,   257,   179,   177,   172,   179,   177,     6,
     162,   259,     6,   261,   259,   259,     6,   179,   257,     6,
     262,   177,   179,     8,   179,   172,   178,   257,   270,   262,
     172,     6,     6,     6,     6,     7,     6,   175,   172,   177,
     257,   257,   262,   178,   177,   179,     6,   257,   208,   209,
     179,   179,   179,   179,   179,     5,   261,    64,     6,     6,
       6,     6,     6,   178,   178,     6,     6,   178,   257,   179,
     179,   177,   178,   177,   178,   177,   178,   174,     6,   262,
       7,   178,   257,   177,   179,   177,   177,     6,   179,   121,
     257,   257,   265,     6,     6,   179,   266,   124,   193,   257,
     177,   177,   261,   257,     6,   177,   212,   214,     6,     6,
       6,     6,     6,     6,   179,   178,   261,   265,   225,   177,
     179,   257,   259,   247,   257,   259,   247,   257,   259,   247,
       6,   177,   179,   262,   226,   179,   259,     6,   265,   259,
     257,   179,   179,   179,     6,     6,   178,   257,   257,   179,
     257,   177,   179,   213,   177,   179,   215,   178,   257,   179,
     179,   179,   257,   179,   177,   179,   179,   177,   179,   179,
     177,   179,   262,     6,    83,   179,   235,   178,   177,   179,
     177,     6,     6,   190,   172,   177,     6,   178,   177,     4,
       4,   257,   179,     6,     6,   179,     6,   241,   257,     6,
       6,   242,   257,     6,     6,   243,   257,     6,   179,   257,
     247,   226,   265,     6,   259,   265,   179,   196,   257,   261,
     257,   178,   262,   270,   178,   257,   270,   177,   178,   179,
     178,   179,   178,   179,     6,     6,   179,   179,   236,   179,
     177,   179,     6,   178,   172,   179,   179,   211,   257,   271,
     257,   247,     6,   244,   247,     6,   245,   247,     6,   246,
     247,     6,   265,     6,   194,   269,   199,   178,     6,   177,
     179,     7,   179,   179,   179,   178,   179,   178,   179,   178,
     179,   179,   177,   179,   178,   261,   257,   270,     6,     6,
     247,     6,   247,     6,   247,     6,   269,     6,   197,   269,
     179,     7,   179,   179,   179,   177,   179,     6,   270,     6,
       6,     6,   269,     6
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
#line 173 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 188 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 192 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 195 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 196 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 197 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 198 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 203 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:
#line 207 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:
#line 214 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:
#line 219 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:
#line 224 "Gmsh.y"
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
#line 238 "Gmsh.y"
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
#line 251 "Gmsh.y"
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
#line 264 "Gmsh.y"
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
#line 292 "Gmsh.y"
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
#line 306 "Gmsh.y"
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
#line 319 "Gmsh.y"
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
#line 332 "Gmsh.y"
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
#line 350 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 39:
#line 364 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 40:
#line 366 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 41:
#line 371 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 42:
#line 373 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 43:
#line 378 "Gmsh.y"
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
#line 482 "Gmsh.y"
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
#line 492 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 46:
#line 501 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 47:
#line 508 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 48:
#line 518 "Gmsh.y"
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
#line 527 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 50:
#line 536 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 543 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 553 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 53:
#line 561 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 54:
#line 571 "Gmsh.y"
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
#line 590 "Gmsh.y"
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
#line 609 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 57:
#line 615 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 622 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 59:
#line 623 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 60:
#line 624 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 61:
#line 625 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 62:
#line 626 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 63:
#line 630 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 631 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:
#line 642 "Gmsh.y"
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
#line 704 "Gmsh.y"
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
#line 734 "Gmsh.y"
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
#line 769 "Gmsh.y"
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
#line 803 "Gmsh.y"
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
#line 851 "Gmsh.y"
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
#line 898 "Gmsh.y"
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
#line 913 "Gmsh.y"
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
#line 929 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:
#line 938 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:
#line 944 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 78:
#line 953 "Gmsh.y"
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
#line 971 "Gmsh.y"
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
#line 989 "Gmsh.y"
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
#line 998 "Gmsh.y"
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
#line 1010 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:
#line 1015 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:
#line 1023 "Gmsh.y"
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
#line 1043 "Gmsh.y"
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
#line 1066 "Gmsh.y"
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
#line 1077 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 88:
#line 1085 "Gmsh.y"
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
#line 1107 "Gmsh.y"
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
#line 1130 "Gmsh.y"
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
#line 1156 "Gmsh.y"
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
#line 1177 "Gmsh.y"
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
#line 1189 "Gmsh.y"
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
#line 1207 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 98:
#line 1216 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 99:
#line 1225 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:
#line 1227 "Gmsh.y"
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
#line 1237 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 102:
#line 1246 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:
#line 1248 "Gmsh.y"
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
#line 1262 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 106:
#line 1270 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 107:
#line 1276 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 110:
#line 1288 "Gmsh.y"
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
#line 1299 "Gmsh.y"
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
#line 1314 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 115:
#line 1330 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 116:
#line 1338 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 117:
#line 1347 "Gmsh.y"
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
#line 1365 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 119:
#line 1369 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 120:
#line 1379 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 121:
#line 1383 "Gmsh.y"
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
#line 1395 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 123:
#line 1399 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 124:
#line 1409 "Gmsh.y"
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
#line 1432 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 126:
#line 1436 "Gmsh.y"
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
#line 1452 "Gmsh.y"
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
#line 1474 "Gmsh.y"
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
#line 1492 "Gmsh.y"
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
#line 1513 "Gmsh.y"
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
#line 1531 "Gmsh.y"
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
#line 1561 "Gmsh.y"
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
#line 1591 "Gmsh.y"
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
#line 1609 "Gmsh.y"
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
#line 1627 "Gmsh.y"
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
#line 1653 "Gmsh.y"
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
#line 1671 "Gmsh.y"
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
#line 1689 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 139:
#line 1693 "Gmsh.y"
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
#line 1712 "Gmsh.y"
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
#line 1730 "Gmsh.y"
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
#line 1769 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:
#line 1775 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 144:
#line 1781 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 145:
#line 1788 "Gmsh.y"
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
#line 1813 "Gmsh.y"
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
#line 1838 "Gmsh.y"
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
#line 1855 "Gmsh.y"
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
#line 1875 "Gmsh.y"
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
#line 1908 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 151:
#line 1912 "Gmsh.y"
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
#line 1932 "Gmsh.y"
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
#line 1950 "Gmsh.y"
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
#line 1967 "Gmsh.y"
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
#line 1983 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 156:
#line 1987 "Gmsh.y"
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
#line 2009 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:
#line 2014 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 159:
#line 2019 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 160:
#line 2024 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:
#line 2029 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 162:
#line 2034 "Gmsh.y"
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
#line 2057 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 164:
#line 2063 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 165:
#line 2073 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:
#line 2074 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 167:
#line 2079 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 168:
#line 2083 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 169:
#line 2087 "Gmsh.y"
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
#line 2110 "Gmsh.y"
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
#line 2133 "Gmsh.y"
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
#line 2156 "Gmsh.y"
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
#line 2184 "Gmsh.y"
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
#line 2205 "Gmsh.y"
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
#line 2232 "Gmsh.y"
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
#line 2253 "Gmsh.y"
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
#line 2274 "Gmsh.y"
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
#line 2294 "Gmsh.y"
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
#line 2406 "Gmsh.y"
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
#line 2425 "Gmsh.y"
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
#line 2464 "Gmsh.y"
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
#line 2572 "Gmsh.y"
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
#line 2581 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 184:
#line 2587 "Gmsh.y"
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
#line 2602 "Gmsh.y"
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
#line 2630 "Gmsh.y"
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
#line 2647 "Gmsh.y"
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
#line 2656 "Gmsh.y"
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
#line 2670 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 190:
#line 2676 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 191:
#line 2682 "Gmsh.y"
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
#line 2691 "Gmsh.y"
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
#line 2700 "Gmsh.y"
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
#line 2709 "Gmsh.y"
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
#line 2723 "Gmsh.y"
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
	CreateSingleDir(std::string((yyvsp[(2) - (3)].c)));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 196:
#line 2775 "Gmsh.y"
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
#line 2792 "Gmsh.y"
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
#line 2807 "Gmsh.y"
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
#line 2826 "Gmsh.y"
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
#line 2838 "Gmsh.y"
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
#line 2862 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 202:
#line 2866 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 203:
#line 2871 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 204:
#line 2878 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 205:
#line 2884 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 206:
#line 2889 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 207:
#line 2895 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 208:
#line 2903 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 209:
#line 2907 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 210:
#line 2911 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 211:
#line 2917 "Gmsh.y"
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
#line 2971 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    ;}
    break;

  case 213:
#line 2984 "Gmsh.y"
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
#line 3001 "Gmsh.y"
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
#line 3018 "Gmsh.y"
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
#line 3039 "Gmsh.y"
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
#line 3060 "Gmsh.y"
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
#line 3095 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 219:
#line 3103 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 220:
#line 3109 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 221:
#line 3116 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 222:
#line 3120 "Gmsh.y"
    {
    ;}
    break;

  case 223:
#line 3129 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 224:
#line 3137 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 225:
#line 3145 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 226:
#line 3153 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 227:
#line 3159 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 228:
#line 3167 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 229:
#line 3173 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 230:
#line 3181 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 231:
#line 3187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 232:
#line 3195 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 233:
#line 3201 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 234:
#line 3209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 235:
#line 3216 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 236:
#line 3223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 237:
#line 3230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 238:
#line 3237 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 239:
#line 3244 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 240:
#line 3251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 241:
#line 3258 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 242:
#line 3265 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 243:
#line 3272 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 244:
#line 3278 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 245:
#line 3285 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 246:
#line 3291 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 247:
#line 3298 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 248:
#line 3304 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 249:
#line 3311 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 250:
#line 3317 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:
#line 3324 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 252:
#line 3330 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:
#line 3337 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 254:
#line 3343 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:
#line 3350 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 256:
#line 3356 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 257:
#line 3363 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 258:
#line 3369 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 259:
#line 3376 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 260:
#line 3382 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 261:
#line 3393 "Gmsh.y"
    {
    ;}
    break;

  case 262:
#line 3396 "Gmsh.y"
    {
    ;}
    break;

  case 263:
#line 3402 "Gmsh.y"
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
#line 3414 "Gmsh.y"
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
#line 3434 "Gmsh.y"
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
#line 3458 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 267:
#line 3463 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 268:
#line 3467 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 269:
#line 3471 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 270:
#line 3475 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 271:
#line 3479 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, which has no requirement for the number of extrusion layers and meshes with body-centered vertices.");
    ;}
    break;

  case 272:
#line 3483 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 273:
#line 3487 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 274:
#line 3491 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 275:
#line 3495 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 276:
#line 3499 "Gmsh.y"
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
#line 3518 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 278:
#line 3530 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 279:
#line 3534 "Gmsh.y"
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
#line 3549 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 281:
#line 3553 "Gmsh.y"
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
#line 3569 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 283:
#line 3573 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 284:
#line 3578 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 285:
#line 3582 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 286:
#line 3589 "Gmsh.y"
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
#line 3645 "Gmsh.y"
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
#line 3715 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 289:
#line 3720 "Gmsh.y"
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
#line 3787 "Gmsh.y"
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
#line 3823 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 292:
#line 3831 "Gmsh.y"
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
#line 3874 "Gmsh.y"
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
#line 3913 "Gmsh.y"
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
#line 3933 "Gmsh.y"
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
#line 3961 "Gmsh.y"
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
#line 4000 "Gmsh.y"
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
#line 4023 "Gmsh.y"
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
#line 4046 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    ;}
    break;

  case 300:
#line 4050 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 301:
#line 4054 "Gmsh.y"
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
#line 4077 "Gmsh.y"
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
#line 4116 "Gmsh.y"
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
    ;}
    break;

  case 304:
#line 4155 "Gmsh.y"
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
    ;}
    break;

  case 305:
#line 4176 "Gmsh.y"
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
    ;}
    break;

  case 306:
#line 4197 "Gmsh.y"
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
    ;}
    break;

  case 307:
#line 4224 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 308:
#line 4228 "Gmsh.y"
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

  case 309:
#line 4238 "Gmsh.y"
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

  case 310:
#line 4272 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 311:
#line 4273 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 312:
#line 4274 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 313:
#line 4279 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 314:
#line 4285 "Gmsh.y"
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

  case 315:
#line 4297 "Gmsh.y"
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

  case 316:
#line 4315 "Gmsh.y"
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

  case 317:
#line 4342 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 318:
#line 4343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 319:
#line 4344 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 320:
#line 4345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 321:
#line 4346 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 322:
#line 4347 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 323:
#line 4348 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 324:
#line 4349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 325:
#line 4351 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 326:
#line 4357 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 327:
#line 4358 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 328:
#line 4359 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 329:
#line 4360 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 330:
#line 4361 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 331:
#line 4362 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 332:
#line 4363 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 333:
#line 4364 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 334:
#line 4365 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 335:
#line 4366 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 336:
#line 4367 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 337:
#line 4368 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 338:
#line 4369 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 339:
#line 4370 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 340:
#line 4371 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:
#line 4372 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:
#line 4373 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:
#line 4374 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:
#line 4375 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:
#line 4376 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:
#line 4377 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:
#line 4378 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 348:
#line 4379 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:
#line 4380 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:
#line 4381 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:
#line 4382 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:
#line 4383 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 353:
#line 4384 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:
#line 4385 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 355:
#line 4386 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 356:
#line 4387 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 357:
#line 4388 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 358:
#line 4389 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 359:
#line 4392 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 360:
#line 4393 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 361:
#line 4394 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 362:
#line 4395 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 363:
#line 4396 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 364:
#line 4397 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 365:
#line 4398 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 366:
#line 4399 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 367:
#line 4400 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 368:
#line 4401 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 369:
#line 4402 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 370:
#line 4403 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 371:
#line 4404 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 372:
#line 4405 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 373:
#line 4406 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 374:
#line 4407 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 375:
#line 4408 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 376:
#line 4409 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5);    ;}
    break;

  case 377:
#line 4410 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 378:
#line 4411 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 379:
#line 4412 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 380:
#line 4413 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 381:
#line 4422 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 382:
#line 4423 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 383:
#line 4424 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 384:
#line 4425 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 385:
#line 4426 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 386:
#line 4427 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 387:
#line 4428 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 388:
#line 4429 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 389:
#line 4430 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 390:
#line 4435 "Gmsh.y"
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

  case 391:
#line 4453 "Gmsh.y"
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

  case 392:
#line 4471 "Gmsh.y"
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

  case 393:
#line 4483 "Gmsh.y"
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

  case 394:
#line 4500 "Gmsh.y"
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

  case 395:
#line 4521 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 396:
#line 4526 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 397:
#line 4531 "Gmsh.y"
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

  case 398:
#line 4541 "Gmsh.y"
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

  case 399:
#line 4551 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 400:
#line 4556 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 401:
#line 4565 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 402:
#line 4570 "Gmsh.y"
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

  case 403:
#line 4597 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 404:
#line 4601 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 405:
#line 4605 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 406:
#line 4609 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 407:
#line 4613 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 408:
#line 4620 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 409:
#line 4624 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 410:
#line 4628 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 411:
#line 4632 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 412:
#line 4639 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 413:
#line 4644 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 414:
#line 4651 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 415:
#line 4656 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 416:
#line 4660 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 417:
#line 4665 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 418:
#line 4669 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 419:
#line 4677 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 420:
#line 4688 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 421:
#line 4692 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 422:
#line 4704 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 423:
#line 4712 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 424:
#line 4720 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 425:
#line 4727 "Gmsh.y"
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

  case 426:
#line 4737 "Gmsh.y"
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

  case 427:
#line 4757 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 428:
#line 4761 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 429:
#line 4765 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 430:
#line 4769 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 431:
#line 4773 "Gmsh.y"
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

  case 432:
#line 4802 "Gmsh.y"
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

  case 433:
#line 4831 "Gmsh.y"
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

  case 434:
#line 4860 "Gmsh.y"
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

  case 435:
#line 4889 "Gmsh.y"
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

  case 436:
#line 4899 "Gmsh.y"
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

  case 437:
#line 4909 "Gmsh.y"
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

  case 438:
#line 4922 "Gmsh.y"
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

  case 439:
#line 4934 "Gmsh.y"
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

  case 440:
#line 4946 "Gmsh.y"
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

  case 441:
#line 4965 "Gmsh.y"
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

  case 442:
#line 4986 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 443:
#line 4991 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 444:
#line 4995 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 445:
#line 4999 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 446:
#line 5011 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 447:
#line 5015 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 448:
#line 5027 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 449:
#line 5034 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 450:
#line 5044 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 451:
#line 5048 "Gmsh.y"
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

  case 452:
#line 5063 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 453:
#line 5068 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 454:
#line 5075 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 455:
#line 5079 "Gmsh.y"
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

  case 456:
#line 5092 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 457:
#line 5100 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 458:
#line 5111 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 459:
#line 5115 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 460:
#line 5123 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 461:
#line 5131 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 462:
#line 5139 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 463:
#line 5148 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 464:
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
    ;}
    break;

  case 465:
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
    ;}
    break;

  case 466:
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
    ;}
    break;

  case 467:
#line 5196 "Gmsh.y"
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

  case 468:
#line 5213 "Gmsh.y"
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

  case 469:
#line 5229 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 470:
#line 5234 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 471:
#line 5238 "Gmsh.y"
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

  case 472:
#line 5258 "Gmsh.y"
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

  case 473:
#line 5280 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 474:
#line 5285 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 475:
#line 5291 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 476:
#line 5300 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 477:
#line 5313 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 478:
#line 5316 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 10791 "Gmsh.tab.cpp"
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


#line 5320 "Gmsh.y"


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

