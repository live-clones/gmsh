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
     tTestLevel = 269,
     tExp = 270,
     tLog = 271,
     tLog10 = 272,
     tSqrt = 273,
     tSin = 274,
     tAsin = 275,
     tCos = 276,
     tAcos = 277,
     tTan = 278,
     tRand = 279,
     tAtan = 280,
     tAtan2 = 281,
     tSinh = 282,
     tCosh = 283,
     tTanh = 284,
     tFabs = 285,
     tFloor = 286,
     tCeil = 287,
     tRound = 288,
     tFmod = 289,
     tModulo = 290,
     tHypot = 291,
     tList = 292,
     tLinSpace = 293,
     tLogSpace = 294,
     tListFromFile = 295,
     tCatenary = 296,
     tPrintf = 297,
     tError = 298,
     tStr = 299,
     tSprintf = 300,
     tStrCat = 301,
     tStrPrefix = 302,
     tStrRelative = 303,
     tStrReplace = 304,
     tAbsolutePath = 305,
     tDirName = 306,
     tStrSub = 307,
     tStrLen = 308,
     tFind = 309,
     tStrFind = 310,
     tStrCmp = 311,
     tStrChoice = 312,
     tUpperCase = 313,
     tLowerCase = 314,
     tLowerCaseIn = 315,
     tTextAttributes = 316,
     tBoundingBox = 317,
     tDraw = 318,
     tSetChanged = 319,
     tToday = 320,
     tFixRelativePath = 321,
     tCurrentDirectory = 322,
     tSyncModel = 323,
     tNewModel = 324,
     tOnelabAction = 325,
     tOnelabRun = 326,
     tCpu = 327,
     tMemory = 328,
     tTotalMemory = 329,
     tCreateTopology = 330,
     tCreateTopologyNoHoles = 331,
     tDistanceFunction = 332,
     tDefineConstant = 333,
     tUndefineConstant = 334,
     tDefineNumber = 335,
     tDefineString = 336,
     tSetNumber = 337,
     tSetString = 338,
     tPoint = 339,
     tCircle = 340,
     tEllipse = 341,
     tLine = 342,
     tSphere = 343,
     tPolarSphere = 344,
     tSurface = 345,
     tSpline = 346,
     tVolume = 347,
     tBlock = 348,
     tCylinder = 349,
     tCone = 350,
     tEllipsoid = 351,
     tQuadric = 352,
     tCharacteristic = 353,
     tLength = 354,
     tParametric = 355,
     tElliptic = 356,
     tRefineMesh = 357,
     tAdaptMesh = 358,
     tRelocateMesh = 359,
     tSetFactory = 360,
     tThruSections = 361,
     tPlane = 362,
     tRuled = 363,
     tTransfinite = 364,
     tComplex = 365,
     tPhysical = 366,
     tCompound = 367,
     tPeriodic = 368,
     tUsing = 369,
     tPlugin = 370,
     tDegenerated = 371,
     tRecursive = 372,
     tRotate = 373,
     tTranslate = 374,
     tSymmetry = 375,
     tDilate = 376,
     tExtrude = 377,
     tLevelset = 378,
     tAffine = 379,
     tBooleanUnion = 380,
     tBooleanIntersection = 381,
     tBooleanDifference = 382,
     tBooleanSection = 383,
     tBooleanFragments = 384,
     tRecombine = 385,
     tSmoother = 386,
     tSplit = 387,
     tDelete = 388,
     tCoherence = 389,
     tIntersect = 390,
     tMeshAlgorithm = 391,
     tReverse = 392,
     tLayers = 393,
     tScaleLast = 394,
     tHole = 395,
     tAlias = 396,
     tAliasWithOptions = 397,
     tCopyOptions = 398,
     tQuadTriAddVerts = 399,
     tQuadTriNoNewVerts = 400,
     tQuadTriSngl = 401,
     tQuadTriDbl = 402,
     tRecombLaterals = 403,
     tTransfQuadTri = 404,
     tText2D = 405,
     tText3D = 406,
     tInterpolationScheme = 407,
     tTime = 408,
     tCombine = 409,
     tBSpline = 410,
     tBezier = 411,
     tNurbs = 412,
     tNurbsOrder = 413,
     tNurbsKnots = 414,
     tColor = 415,
     tColorTable = 416,
     tFor = 417,
     tIn = 418,
     tEndFor = 419,
     tIf = 420,
     tElseIf = 421,
     tElse = 422,
     tEndIf = 423,
     tExit = 424,
     tAbort = 425,
     tField = 426,
     tReturn = 427,
     tCall = 428,
     tSlide = 429,
     tMacro = 430,
     tShow = 431,
     tHide = 432,
     tGetValue = 433,
     tGetStringValue = 434,
     tGetEnv = 435,
     tGetString = 436,
     tGetNumber = 437,
     tHomology = 438,
     tCohomology = 439,
     tBetti = 440,
     tExists = 441,
     tFileExists = 442,
     tGMSH_MAJOR_VERSION = 443,
     tGMSH_MINOR_VERSION = 444,
     tGMSH_PATCH_VERSION = 445,
     tGmshExecutableName = 446,
     tSetPartition = 447,
     tNameToString = 448,
     tStringToName = 449,
     tAFFECTDIVIDE = 450,
     tAFFECTTIMES = 451,
     tAFFECTMINUS = 452,
     tAFFECTPLUS = 453,
     tOR = 454,
     tAND = 455,
     tNOTEQUAL = 456,
     tEQUAL = 457,
     tGREATEROREQUAL = 458,
     tLESSOREQUAL = 459,
     UNARYPREC = 460,
     tMINUSMINUS = 461,
     tPLUSPLUS = 462
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
#define tTestLevel 269
#define tExp 270
#define tLog 271
#define tLog10 272
#define tSqrt 273
#define tSin 274
#define tAsin 275
#define tCos 276
#define tAcos 277
#define tTan 278
#define tRand 279
#define tAtan 280
#define tAtan2 281
#define tSinh 282
#define tCosh 283
#define tTanh 284
#define tFabs 285
#define tFloor 286
#define tCeil 287
#define tRound 288
#define tFmod 289
#define tModulo 290
#define tHypot 291
#define tList 292
#define tLinSpace 293
#define tLogSpace 294
#define tListFromFile 295
#define tCatenary 296
#define tPrintf 297
#define tError 298
#define tStr 299
#define tSprintf 300
#define tStrCat 301
#define tStrPrefix 302
#define tStrRelative 303
#define tStrReplace 304
#define tAbsolutePath 305
#define tDirName 306
#define tStrSub 307
#define tStrLen 308
#define tFind 309
#define tStrFind 310
#define tStrCmp 311
#define tStrChoice 312
#define tUpperCase 313
#define tLowerCase 314
#define tLowerCaseIn 315
#define tTextAttributes 316
#define tBoundingBox 317
#define tDraw 318
#define tSetChanged 319
#define tToday 320
#define tFixRelativePath 321
#define tCurrentDirectory 322
#define tSyncModel 323
#define tNewModel 324
#define tOnelabAction 325
#define tOnelabRun 326
#define tCpu 327
#define tMemory 328
#define tTotalMemory 329
#define tCreateTopology 330
#define tCreateTopologyNoHoles 331
#define tDistanceFunction 332
#define tDefineConstant 333
#define tUndefineConstant 334
#define tDefineNumber 335
#define tDefineString 336
#define tSetNumber 337
#define tSetString 338
#define tPoint 339
#define tCircle 340
#define tEllipse 341
#define tLine 342
#define tSphere 343
#define tPolarSphere 344
#define tSurface 345
#define tSpline 346
#define tVolume 347
#define tBlock 348
#define tCylinder 349
#define tCone 350
#define tEllipsoid 351
#define tQuadric 352
#define tCharacteristic 353
#define tLength 354
#define tParametric 355
#define tElliptic 356
#define tRefineMesh 357
#define tAdaptMesh 358
#define tRelocateMesh 359
#define tSetFactory 360
#define tThruSections 361
#define tPlane 362
#define tRuled 363
#define tTransfinite 364
#define tComplex 365
#define tPhysical 366
#define tCompound 367
#define tPeriodic 368
#define tUsing 369
#define tPlugin 370
#define tDegenerated 371
#define tRecursive 372
#define tRotate 373
#define tTranslate 374
#define tSymmetry 375
#define tDilate 376
#define tExtrude 377
#define tLevelset 378
#define tAffine 379
#define tBooleanUnion 380
#define tBooleanIntersection 381
#define tBooleanDifference 382
#define tBooleanSection 383
#define tBooleanFragments 384
#define tRecombine 385
#define tSmoother 386
#define tSplit 387
#define tDelete 388
#define tCoherence 389
#define tIntersect 390
#define tMeshAlgorithm 391
#define tReverse 392
#define tLayers 393
#define tScaleLast 394
#define tHole 395
#define tAlias 396
#define tAliasWithOptions 397
#define tCopyOptions 398
#define tQuadTriAddVerts 399
#define tQuadTriNoNewVerts 400
#define tQuadTriSngl 401
#define tQuadTriDbl 402
#define tRecombLaterals 403
#define tTransfQuadTri 404
#define tText2D 405
#define tText3D 406
#define tInterpolationScheme 407
#define tTime 408
#define tCombine 409
#define tBSpline 410
#define tBezier 411
#define tNurbs 412
#define tNurbsOrder 413
#define tNurbsKnots 414
#define tColor 415
#define tColorTable 416
#define tFor 417
#define tIn 418
#define tEndFor 419
#define tIf 420
#define tElseIf 421
#define tElse 422
#define tEndIf 423
#define tExit 424
#define tAbort 425
#define tField 426
#define tReturn 427
#define tCall 428
#define tSlide 429
#define tMacro 430
#define tShow 431
#define tHide 432
#define tGetValue 433
#define tGetStringValue 434
#define tGetEnv 435
#define tGetString 436
#define tGetNumber 437
#define tHomology 438
#define tCohomology 439
#define tBetti 440
#define tExists 441
#define tFileExists 442
#define tGMSH_MAJOR_VERSION 443
#define tGMSH_MINOR_VERSION 444
#define tGMSH_PATCH_VERSION 445
#define tGmshExecutableName 446
#define tSetPartition 447
#define tNameToString 448
#define tStringToName 449
#define tAFFECTDIVIDE 450
#define tAFFECTTIMES 451
#define tAFFECTMINUS 452
#define tAFFECTPLUS 453
#define tOR 454
#define tAND 455
#define tNOTEQUAL 456
#define tEQUAL 457
#define tGREATEROREQUAL 458
#define tLESSOREQUAL 459
#define UNARYPREC 460
#define tMINUSMINUS 461
#define tPLUSPLUS 462




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include <map>
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
#include "GModelIO_OCC.h"
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

#if defined(HAVE_POPPLER)
#include "gmshPopplerWrapper.h"
#endif


// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

// Static parser variables (accessible only in this file)
#if defined(HAVE_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_TESTS 100
static int statusImbricatedTests[MAX_RECUR_TESTS];
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0, ImbricatedTest = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static std::string factory;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void skip_until_test(const char *skip, const char *until,
                     const char *until2, int l_until2_sub, int *type_until2);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int,int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&, std::vector<double>&);
char  *strsave(char *ptr);

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
#line 117 "Gmsh.y"
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
#line 644 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 657 "Gmsh.tab.cpp"

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
#define YYLAST   13332

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  584
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   462

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   213,     2,   223,     2,   212,     2,     2,
     218,   219,   210,   208,   224,   209,   222,   211,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     204,     2,   205,   199,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   220,     2,   221,   217,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   225,     2,   226,   227,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   200,   201,   202,   203,   206,   207,
     214,   215,   216
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    50,    52,    55,    61,    67,
      75,    83,    91,   101,   108,   115,   122,   131,   132,   135,
     138,   141,   144,   147,   149,   153,   155,   159,   160,   161,
     172,   174,   178,   179,   193,   195,   199,   200,   216,   225,
     240,   241,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   266,   268,   270,   276,   282,   290,   298,   303,   307,
     314,   321,   329,   337,   344,   351,   361,   371,   378,   385,
     393,   401,   408,   415,   420,   429,   438,   448,   458,   468,
     478,   487,   496,   506,   516,   526,   536,   543,   553,   560,
     570,   576,   585,   594,   606,   613,   623,   629,   637,   647,
     657,   669,   677,   687,   697,   698,   700,   701,   705,   711,
     712,   722,   723,   735,   736,   748,   754,   755,   765,   766,
     770,   774,   780,   786,   787,   790,   794,   800,   804,   805,
     808,   812,   816,   820,   826,   828,   830,   834,   836,   838,
     842,   844,   846,   850,   852,   854,   858,   859,   865,   866,
     869,   875,   883,   892,   899,   907,   912,   920,   929,   938,
     946,   954,   966,   975,   980,   989,   998,  1007,  1017,  1021,
    1026,  1037,  1045,  1053,  1061,  1069,  1078,  1083,  1092,  1105,
    1114,  1123,  1131,  1141,  1146,  1155,  1164,  1170,  1182,  1188,
    1198,  1208,  1213,  1223,  1233,  1235,  1237,  1238,  1241,  1248,
    1255,  1262,  1269,  1278,  1289,  1304,  1321,  1334,  1349,  1364,
    1379,  1394,  1403,  1412,  1419,  1424,  1431,  1438,  1442,  1447,
    1453,  1460,  1466,  1470,  1474,  1479,  1485,  1490,  1496,  1500,
    1506,  1514,  1522,  1526,  1534,  1538,  1541,  1544,  1547,  1550,
    1553,  1569,  1572,  1575,  1578,  1581,  1584,  1601,  1613,  1620,
    1629,  1638,  1649,  1651,  1654,  1657,  1659,  1663,  1667,  1672,
    1677,  1679,  1681,  1687,  1699,  1713,  1714,  1722,  1723,  1737,
    1738,  1754,  1755,  1762,  1771,  1780,  1789,  1802,  1815,  1828,
    1843,  1858,  1873,  1874,  1887,  1888,  1901,  1902,  1915,  1916,
    1933,  1934,  1951,  1952,  1969,  1970,  1989,  1990,  2009,  2010,
    2029,  2031,  2034,  2040,  2048,  2058,  2061,  2064,  2068,  2071,
    2075,  2078,  2082,  2085,  2089,  2092,  2096,  2106,  2113,  2115,
    2117,  2119,  2121,  2123,  2124,  2127,  2131,  2141,  2156,  2157,
    2161,  2162,  2164,  2165,  2168,  2169,  2172,  2173,  2176,  2184,
    2191,  2200,  2206,  2210,  2219,  2225,  2230,  2237,  2249,  2261,
    2280,  2299,  2312,  2325,  2338,  2349,  2360,  2371,  2382,  2393,
    2398,  2403,  2408,  2413,  2418,  2421,  2425,  2432,  2434,  2436,
    2438,  2441,  2447,  2455,  2466,  2468,  2472,  2475,  2478,  2481,
    2485,  2489,  2493,  2497,  2501,  2505,  2509,  2513,  2517,  2521,
    2525,  2529,  2533,  2537,  2543,  2548,  2553,  2558,  2563,  2568,
    2573,  2578,  2583,  2588,  2593,  2600,  2605,  2610,  2615,  2620,
    2625,  2630,  2635,  2642,  2649,  2656,  2661,  2663,  2665,  2667,
    2669,  2671,  2673,  2675,  2677,  2679,  2681,  2683,  2684,  2691,
    2696,  2703,  2705,  2710,  2715,  2720,  2725,  2730,  2735,  2740,
    2743,  2749,  2755,  2761,  2767,  2771,  2778,  2783,  2791,  2798,
    2805,  2812,  2817,  2824,  2829,  2831,  2834,  2837,  2841,  2845,
    2857,  2867,  2875,  2883,  2885,  2889,  2891,  2893,  2896,  2900,
    2905,  2911,  2913,  2915,  2918,  2922,  2926,  2932,  2937,  2940,
    2943,  2946,  2949,  2953,  2957,  2961,  2965,  2971,  2977,  2983,
    2989,  3006,  3023,  3040,  3057,  3059,  3061,  3063,  3067,  3071,
    3076,  3081,  3086,  3093,  3100,  3107,  3114,  3123,  3132,  3137,
    3152,  3154,  3156,  3160,  3164,  3174,  3182,  3184,  3190,  3194,
    3201,  3203,  3207,  3209,  3211,  3216,  3221,  3226,  3231,  3235,
    3242,  3244,  3249,  3251,  3253,  3255,  3260,  3267,  3272,  3279,
    3284,  3289,  3294,  3303,  3308,  3313,  3318,  3323,  3332,  3341,
    3348,  3353,  3360,  3365,  3367,  3372,  3377,  3378,  3385,  3387,
    3391,  3397,  3403,  3405,  3407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     229,     0,    -1,   230,    -1,     1,     6,    -1,    -1,   230,
     231,    -1,   234,    -1,   233,    -1,   254,    -1,   273,    -1,
     274,    -1,   278,    -1,   279,    -1,   280,    -1,   281,    -1,
     285,    -1,   303,    -1,   304,    -1,   310,    -1,   311,    -1,
     284,    -1,   283,    -1,   282,    -1,   277,    -1,   313,    -1,
     205,    -1,   205,   205,    -1,    42,   218,   327,   219,     6,
      -1,    43,   218,   327,   219,     6,    -1,    42,   218,   327,
     219,   232,   327,     6,    -1,    42,   218,   327,   224,   323,
     219,     6,    -1,    43,   218,   327,   224,   323,   219,     6,
      -1,    42,   218,   327,   224,   323,   219,   232,   327,     6,
      -1,     4,   327,   225,   235,   226,     6,    -1,   141,     4,
     220,   314,   221,     6,    -1,   142,     4,   220,   314,   221,
       6,    -1,   143,     4,   220,   314,   224,   314,   221,     6,
      -1,    -1,   235,   238,    -1,   235,   242,    -1,   235,   245,
      -1,   235,   247,    -1,   235,   248,    -1,   314,    -1,   236,
     224,   314,    -1,   314,    -1,   237,   224,   314,    -1,    -1,
      -1,     4,   239,   218,   236,   219,   240,   225,   237,   226,
       6,    -1,   327,    -1,   241,   224,   327,    -1,    -1,   150,
     218,   314,   224,   314,   224,   314,   219,   243,   225,   241,
     226,     6,    -1,   327,    -1,   244,   224,   327,    -1,    -1,
     151,   218,   314,   224,   314,   224,   314,   224,   314,   219,
     246,   225,   244,   226,     6,    -1,   152,   225,   319,   226,
     225,   319,   226,     6,    -1,   152,   225,   319,   226,   225,
     319,   226,   225,   319,   226,   225,   319,   226,     6,    -1,
      -1,   153,   249,   225,   237,   226,     6,    -1,     7,    -1,
     198,    -1,   197,    -1,   196,    -1,   195,    -1,   216,    -1,
     215,    -1,   218,    -1,   220,    -1,   219,    -1,   221,    -1,
      78,   220,   256,   221,     6,    -1,    79,   220,   261,   221,
       6,    -1,    82,   252,   328,   224,   314,   253,     6,    -1,
      83,   252,   332,   224,   328,   253,     6,    -1,   332,   250,
     320,     6,    -1,   332,   251,     6,    -1,     4,   220,   221,
     250,   320,     6,    -1,   331,   220,   221,   250,   320,     6,
      -1,     4,   220,   314,   221,   250,   314,     6,    -1,   331,
     220,   314,   221,   250,   314,     6,    -1,     4,   220,   314,
     221,   251,     6,    -1,   331,   220,   314,   221,   251,     6,
      -1,     4,   252,   225,   323,   226,   253,   250,   320,     6,
      -1,   331,   252,   225,   323,   226,   253,   250,   320,     6,
      -1,     4,   218,   219,   250,   320,     6,    -1,   331,   218,
     219,   250,   320,     6,    -1,     4,   218,   314,   219,   250,
     314,     6,    -1,   331,   218,   314,   219,   250,   314,     6,
      -1,     4,   218,   314,   219,   251,     6,    -1,   331,   218,
     314,   219,   251,     6,    -1,   332,     7,   328,     6,    -1,
       4,   220,   221,     7,    44,   252,   253,     6,    -1,   331,
     220,   221,     7,    44,   252,   253,     6,    -1,     4,   220,
     221,     7,    44,   252,   330,   253,     6,    -1,   331,   220,
     221,     7,    44,   252,   330,   253,     6,    -1,     4,   220,
     221,   198,    44,   252,   330,   253,     6,    -1,   331,   220,
     221,   198,    44,   252,   330,   253,     6,    -1,     4,   218,
     219,     7,    44,   252,   253,     6,    -1,   331,   218,   219,
       7,    44,   252,   253,     6,    -1,     4,   218,   219,     7,
      44,   252,   330,   253,     6,    -1,   331,   218,   219,     7,
      44,   252,   330,   253,     6,    -1,     4,   218,   219,   198,
      44,   252,   330,   253,     6,    -1,   331,   218,   219,   198,
      44,   252,   330,   253,     6,    -1,     4,   222,     4,     7,
     328,     6,    -1,     4,   220,   314,   221,   222,     4,     7,
     328,     6,    -1,     4,   222,     4,   250,   314,     6,    -1,
       4,   220,   314,   221,   222,     4,   250,   314,     6,    -1,
       4,   222,     4,   251,     6,    -1,     4,   220,   314,   221,
     222,     4,   251,     6,    -1,     4,   222,   160,   222,     4,
       7,   324,     6,    -1,     4,   220,   314,   221,   222,   160,
     222,     4,     7,   324,     6,    -1,     4,   222,   161,     7,
     325,     6,    -1,     4,   220,   314,   221,   222,   161,     7,
     325,     6,    -1,     4,   171,     7,   314,     6,    -1,   171,
     220,   314,   221,     7,     4,     6,    -1,   171,   220,   314,
     221,   222,     4,     7,   314,     6,    -1,   171,   220,   314,
     221,   222,     4,     7,   328,     6,    -1,   171,   220,   314,
     221,   222,     4,     7,   225,   323,   226,     6,    -1,   171,
     220,   314,   221,   222,     4,     6,    -1,   115,   218,     4,
     219,   222,     4,     7,   314,     6,    -1,   115,   218,     4,
     219,   222,     4,     7,   328,     6,    -1,    -1,   224,    -1,
      -1,   256,   255,   332,    -1,   256,   255,   332,     7,   314,
      -1,    -1,   256,   255,   332,     7,   225,   320,   257,   263,
     226,    -1,    -1,   256,   255,   332,   220,   221,     7,   225,
     320,   258,   263,   226,    -1,    -1,   256,   255,   332,   218,
     219,     7,   225,   320,   259,   263,   226,    -1,   256,   255,
     332,     7,   328,    -1,    -1,   256,   255,   332,     7,   225,
     328,   260,   265,   226,    -1,    -1,   261,   255,   327,    -1,
     314,     7,   328,    -1,   262,   224,   314,     7,   328,    -1,
     322,     7,   332,   218,   219,    -1,    -1,   263,   264,    -1,
     224,     4,   320,    -1,   224,     4,   225,   262,   226,    -1,
     224,     4,   328,    -1,    -1,   265,   266,    -1,   224,     4,
     314,    -1,   224,     4,   328,    -1,   224,   175,   328,    -1,
     224,     4,   225,   330,   226,    -1,   314,    -1,   328,    -1,
     328,   224,   314,    -1,   314,    -1,   328,    -1,   328,   224,
     314,    -1,   314,    -1,   328,    -1,   328,   224,   314,    -1,
     314,    -1,   328,    -1,   328,   224,   314,    -1,    -1,   163,
      88,   225,   314,   226,    -1,    -1,   107,   317,    -1,   105,
     218,   327,   219,     6,    -1,    84,   218,   314,   219,     7,
     317,     6,    -1,   111,    84,   218,   267,   219,   250,   320,
       6,    -1,    98,    99,   320,     7,   314,     6,    -1,    87,
     218,   314,   219,     7,   320,     6,    -1,   116,    87,   320,
       6,    -1,    91,   218,   314,   219,     7,   320,     6,    -1,
      85,   218,   314,   219,     7,   320,   272,     6,    -1,    86,
     218,   314,   219,     7,   320,   272,     6,    -1,   155,   218,
     314,   219,     7,   320,     6,    -1,   156,   218,   314,   219,
       7,   320,     6,    -1,   157,   218,   314,   219,     7,   320,
     159,   320,   158,   314,     6,    -1,    87,     4,   218,   314,
     219,     7,   320,     6,    -1,   112,    87,   320,     6,    -1,
     112,    87,   218,   314,   219,     7,   320,     6,    -1,   111,
      87,   218,   268,   219,   250,   320,     6,    -1,   107,    90,
     218,   314,   219,     7,   320,     6,    -1,   108,    90,   218,
     314,   219,     7,   320,   271,     6,    -1,    12,    13,     6,
      -1,    13,    90,   314,     6,    -1,   100,    90,   218,   314,
     219,     7,     5,     5,     5,     6,    -1,    88,   218,   314,
     219,     7,   320,     6,    -1,    89,   218,   314,   219,     7,
     320,     6,    -1,    93,   218,   314,   219,     7,   320,     6,
      -1,    94,   218,   314,   219,     7,   320,     6,    -1,    90,
       4,   218,   314,   219,     7,   320,     6,    -1,   112,    90,
     320,     6,    -1,   112,    90,   218,   314,   219,     7,   320,
       6,    -1,   112,    90,   218,   314,   219,     7,   320,     4,
     225,   319,   226,     6,    -1,   111,    90,   218,   269,   219,
     250,   320,     6,    -1,   110,    92,   218,   314,   219,     7,
     320,     6,    -1,    92,   218,   314,   219,     7,   320,     6,
      -1,   106,   218,   314,   219,     7,   225,   319,   226,     6,
      -1,   112,    92,   320,     6,    -1,   112,    92,   218,   314,
     219,     7,   320,     6,    -1,   111,    92,   218,   270,   219,
     250,   320,     6,    -1,   119,   317,   225,   275,   226,    -1,
     118,   225,   317,   224,   317,   224,   314,   226,   225,   275,
     226,    -1,   120,   317,   225,   275,   226,    -1,   121,   225,
     317,   224,   314,   226,   225,   275,   226,    -1,   121,   225,
     317,   224,   317,   226,   225,   275,   226,    -1,     4,   225,
     275,   226,    -1,   135,    87,   225,   323,   226,    90,   225,
     314,   226,    -1,   132,    87,   218,   314,   219,   225,   323,
     226,     6,    -1,   276,    -1,   274,    -1,    -1,   276,   273,
      -1,   276,    84,   225,   323,   226,     6,    -1,   276,    87,
     225,   323,   226,     6,    -1,   276,    90,   225,   323,   226,
       6,    -1,   276,    92,   225,   323,   226,     6,    -1,   123,
     107,   218,   314,   219,     7,   320,     6,    -1,   123,    84,
     218,   314,   219,     7,   225,   319,   226,     6,    -1,   123,
     107,   218,   314,   219,     7,   225,   317,   224,   317,   224,
     323,   226,     6,    -1,   123,   107,   218,   314,   219,     7,
     225,   317,   224,   317,   224,   317,   224,   323,   226,     6,
      -1,   123,    88,   218,   314,   219,     7,   225,   317,   224,
     323,   226,     6,    -1,   123,    94,   218,   314,   219,     7,
     225,   317,   224,   317,   224,   323,   226,     6,    -1,   123,
      95,   218,   314,   219,     7,   225,   317,   224,   317,   224,
     323,   226,     6,    -1,   123,    96,   218,   314,   219,     7,
     225,   317,   224,   317,   224,   323,   226,     6,    -1,   123,
      97,   218,   314,   219,     7,   225,   317,   224,   317,   224,
     323,   226,     6,    -1,   123,     4,   218,   314,   219,     7,
     320,     6,    -1,   123,     4,   218,   314,   219,     7,     5,
       6,    -1,   123,     4,   225,   314,   226,     6,    -1,   133,
     225,   276,   226,    -1,   133,   171,   220,   314,   221,     6,
      -1,   133,     4,   220,   314,   221,     6,    -1,   133,   332,
       6,    -1,   133,     4,     4,     6,    -1,   160,   324,   225,
     276,   226,    -1,   117,   160,   324,   225,   276,   226,    -1,
     192,   314,   225,   276,   226,    -1,   176,     5,     6,    -1,
     177,     5,     6,    -1,   176,   225,   276,   226,    -1,   117,
     176,   225,   276,   226,    -1,   177,   225,   276,   226,    -1,
     117,   177,   225,   276,   226,    -1,     4,   328,     6,    -1,
      71,   218,   330,   219,     6,    -1,     4,     4,   220,   314,
     221,   327,     6,    -1,     4,     4,     4,   220,   314,   221,
       6,    -1,     4,   314,     6,    -1,   115,   218,     4,   219,
     222,     4,     6,    -1,   154,     4,     6,    -1,   169,     6,
      -1,   170,     6,    -1,    68,     6,    -1,    69,     6,    -1,
      62,     6,    -1,    62,   225,   314,   224,   314,   224,   314,
     224,   314,   224,   314,   224,   314,   226,     6,    -1,    63,
       6,    -1,    64,     6,    -1,    75,     6,    -1,    76,     6,
      -1,   102,     6,    -1,   103,   225,   323,   226,   225,   323,
     226,   225,   319,   226,   225,   314,   224,   314,   226,     6,
      -1,   174,   218,   225,   323,   226,   224,   328,   224,   328,
     219,     6,    -1,   162,   218,   314,     8,   314,   219,    -1,
     162,   218,   314,     8,   314,     8,   314,   219,    -1,   162,
       4,   163,   225,   314,     8,   314,   226,    -1,   162,     4,
     163,   225,   314,     8,   314,     8,   314,   226,    -1,   164,
      -1,   175,     4,    -1,   175,   328,    -1,   172,    -1,   173,
     332,     6,    -1,   173,   328,     6,    -1,   165,   218,   314,
     219,    -1,   166,   218,   314,   219,    -1,   167,    -1,   168,
      -1,   122,   317,   225,   276,   226,    -1,   122,   225,   317,
     224,   317,   224,   314,   226,   225,   276,   226,    -1,   122,
     225,   317,   224,   317,   224,   317,   224,   314,   226,   225,
     276,   226,    -1,    -1,   122,   317,   225,   276,   286,   299,
     226,    -1,    -1,   122,   225,   317,   224,   317,   224,   314,
     226,   225,   276,   287,   299,   226,    -1,    -1,   122,   225,
     317,   224,   317,   224,   317,   224,   314,   226,   225,   276,
     288,   299,   226,    -1,    -1,   122,   225,   276,   289,   299,
     226,    -1,   122,    84,   225,   314,   224,   317,   226,     6,
      -1,   122,    87,   225,   314,   224,   317,   226,     6,    -1,
     122,    90,   225,   314,   224,   317,   226,     6,    -1,   122,
      84,   225,   314,   224,   317,   224,   317,   224,   314,   226,
       6,    -1,   122,    87,   225,   314,   224,   317,   224,   317,
     224,   314,   226,     6,    -1,   122,    90,   225,   314,   224,
     317,   224,   317,   224,   314,   226,     6,    -1,   122,    84,
     225,   314,   224,   317,   224,   317,   224,   317,   224,   314,
     226,     6,    -1,   122,    87,   225,   314,   224,   317,   224,
     317,   224,   317,   224,   314,   226,     6,    -1,   122,    90,
     225,   314,   224,   317,   224,   317,   224,   317,   224,   314,
     226,     6,    -1,    -1,   122,    84,   225,   314,   224,   317,
     226,   290,   225,   299,   226,     6,    -1,    -1,   122,    87,
     225,   314,   224,   317,   226,   291,   225,   299,   226,     6,
      -1,    -1,   122,    90,   225,   314,   224,   317,   226,   292,
     225,   299,   226,     6,    -1,    -1,   122,    84,   225,   314,
     224,   317,   224,   317,   224,   314,   226,   293,   225,   299,
     226,     6,    -1,    -1,   122,    87,   225,   314,   224,   317,
     224,   317,   224,   314,   226,   294,   225,   299,   226,     6,
      -1,    -1,   122,    90,   225,   314,   224,   317,   224,   317,
     224,   314,   226,   295,   225,   299,   226,     6,    -1,    -1,
     122,    84,   225,   314,   224,   317,   224,   317,   224,   317,
     224,   314,   226,   296,   225,   299,   226,     6,    -1,    -1,
     122,    87,   225,   314,   224,   317,   224,   317,   224,   317,
     224,   314,   226,   297,   225,   299,   226,     6,    -1,    -1,
     122,    90,   225,   314,   224,   317,   224,   317,   224,   317,
     224,   314,   226,   298,   225,   299,   226,     6,    -1,   300,
      -1,   299,   300,    -1,   138,   225,   314,   226,     6,    -1,
     138,   225,   320,   224,   320,   226,     6,    -1,   138,   225,
     320,   224,   320,   224,   320,   226,     6,    -1,   139,     6,
      -1,   130,     6,    -1,   130,   314,     6,    -1,   146,     6,
      -1,   146,   148,     6,    -1,   147,     6,    -1,   147,   148,
       6,    -1,   144,     6,    -1,   144,   148,     6,    -1,   145,
       6,    -1,   145,   148,     6,    -1,   140,   218,   314,   219,
       7,   320,   114,   314,     6,    -1,   114,     4,   220,   314,
     221,     6,    -1,   125,    -1,   126,    -1,   127,    -1,   128,
      -1,   129,    -1,    -1,   133,     6,    -1,   133,   314,     6,
      -1,   301,   225,   276,   302,   226,   225,   276,   302,   226,
      -1,   301,   218,   314,   219,     7,   225,   276,   302,   226,
     225,   276,   302,   226,     6,    -1,    -1,   114,     4,   314,
      -1,    -1,     4,    -1,    -1,     7,   320,    -1,    -1,     7,
     314,    -1,    -1,   124,   320,    -1,   109,    87,   321,     7,
     314,   305,     6,    -1,   109,    90,   321,   307,   306,     6,
      -1,   101,    90,   225,   314,   226,     7,   320,     6,    -1,
     109,    92,   321,   307,     6,    -1,   149,   321,     6,    -1,
     136,    90,   225,   323,   226,     7,   314,     6,    -1,   130,
      90,   321,   308,     6,    -1,   130,    92,   321,     6,    -1,
     131,    90,   320,     7,   314,     6,    -1,   113,    87,   225,
     323,   226,     7,   225,   323,   226,   309,     6,    -1,   113,
      90,   225,   323,   226,     7,   225,   323,   226,   309,     6,
      -1,   113,    87,   225,   323,   226,     7,   225,   323,   226,
     118,   225,   317,   224,   317,   224,   314,   226,     6,    -1,
     113,    90,   225,   323,   226,     7,   225,   323,   226,   118,
     225,   317,   224,   317,   224,   314,   226,     6,    -1,   113,
      87,   225,   323,   226,     7,   225,   323,   226,   119,   317,
       6,    -1,   113,    90,   225,   323,   226,     7,   225,   323,
     226,   119,   317,     6,    -1,   113,    90,   314,   225,   323,
     226,     7,   314,   225,   323,   226,     6,    -1,    84,   225,
     323,   226,   163,    90,   225,   314,   226,     6,    -1,    87,
     225,   323,   226,   163,    90,   225,   314,   226,     6,    -1,
      84,   225,   323,   226,   163,    92,   225,   314,   226,     6,
      -1,    87,   225,   323,   226,   163,    92,   225,   314,   226,
       6,    -1,    90,   225,   323,   226,   163,    92,   225,   314,
     226,     6,    -1,   137,    90,   321,     6,    -1,   137,    87,
     321,     6,    -1,   104,    84,   321,     6,    -1,   104,    87,
     321,     6,    -1,   104,    90,   321,     6,    -1,   134,     6,
      -1,   134,     4,     6,    -1,   134,    84,   225,   323,   226,
       6,    -1,   183,    -1,   184,    -1,   185,    -1,   312,     6,
      -1,   312,   225,   320,   226,     6,    -1,   312,   225,   320,
     224,   320,   226,     6,    -1,   312,   218,   320,   219,   225,
     320,   224,   320,   226,     6,    -1,   315,    -1,   218,   314,
     219,    -1,   209,   314,    -1,   208,   314,    -1,   213,   314,
      -1,   314,   209,   314,    -1,   314,   208,   314,    -1,   314,
     210,   314,    -1,   314,   211,   314,    -1,   314,   212,   314,
      -1,   314,   217,   314,    -1,   314,   204,   314,    -1,   314,
     205,   314,    -1,   314,   207,   314,    -1,   314,   206,   314,
      -1,   314,   203,   314,    -1,   314,   202,   314,    -1,   314,
     201,   314,    -1,   314,   200,   314,    -1,   314,   199,   314,
       8,   314,    -1,    15,   252,   314,   253,    -1,    16,   252,
     314,   253,    -1,    17,   252,   314,   253,    -1,    18,   252,
     314,   253,    -1,    19,   252,   314,   253,    -1,    20,   252,
     314,   253,    -1,    21,   252,   314,   253,    -1,    22,   252,
     314,   253,    -1,    23,   252,   314,   253,    -1,    25,   252,
     314,   253,    -1,    26,   252,   314,   224,   314,   253,    -1,
      27,   252,   314,   253,    -1,    28,   252,   314,   253,    -1,
      29,   252,   314,   253,    -1,    30,   252,   314,   253,    -1,
      31,   252,   314,   253,    -1,    32,   252,   314,   253,    -1,
      33,   252,   314,   253,    -1,    34,   252,   314,   224,   314,
     253,    -1,    35,   252,   314,   224,   314,   253,    -1,    36,
     252,   314,   224,   314,   253,    -1,    24,   252,   314,   253,
      -1,     3,    -1,     9,    -1,    14,    -1,    10,    -1,    11,
      -1,   188,    -1,   189,    -1,   190,    -1,    72,    -1,    73,
      -1,    74,    -1,    -1,    80,   252,   314,   316,   263,   253,
      -1,   182,   252,   327,   253,    -1,   182,   252,   327,   224,
     314,   253,    -1,   332,    -1,     4,   220,   314,   221,    -1,
       4,   218,   314,   219,    -1,   331,   220,   314,   221,    -1,
     331,   218,   314,   219,    -1,   186,   218,   332,   219,    -1,
     187,   218,   328,   219,    -1,   223,   332,   252,   253,    -1,
     332,   251,    -1,     4,   220,   314,   221,   251,    -1,     4,
     218,   314,   219,   251,    -1,   331,   220,   314,   221,   251,
      -1,   331,   218,   314,   219,   251,    -1,     4,   222,     4,
      -1,     4,   220,   314,   221,   222,     4,    -1,     4,   222,
       4,   251,    -1,     4,   220,   314,   221,   222,     4,   251,
      -1,   178,   218,   327,   224,   314,   219,    -1,    54,   218,
     320,   224,   320,   219,    -1,    55,   252,   327,   224,   327,
     253,    -1,    53,   252,   327,   253,    -1,    56,   252,   327,
     224,   327,   253,    -1,    61,   218,   330,   219,    -1,   318,
      -1,   209,   317,    -1,   208,   317,    -1,   317,   209,   317,
      -1,   317,   208,   317,    -1,   225,   314,   224,   314,   224,
     314,   224,   314,   224,   314,   226,    -1,   225,   314,   224,
     314,   224,   314,   224,   314,   226,    -1,   225,   314,   224,
     314,   224,   314,   226,    -1,   218,   314,   224,   314,   224,
     314,   219,    -1,   320,    -1,   319,   224,   320,    -1,   314,
      -1,   322,    -1,   225,   226,    -1,   225,   323,   226,    -1,
     209,   225,   323,   226,    -1,   314,   210,   225,   323,   226,
      -1,   320,    -1,     5,    -1,   209,   322,    -1,   314,   210,
     322,    -1,   314,     8,   314,    -1,   314,     8,   314,     8,
     314,    -1,    84,   225,   314,   226,    -1,    84,     5,    -1,
      87,     5,    -1,    90,     5,    -1,    92,     5,    -1,   111,
      84,     5,    -1,   111,    87,     5,    -1,   111,    90,     5,
      -1,   111,    92,     5,    -1,   111,    84,   225,   323,   226,
      -1,   111,    87,   225,   323,   226,    -1,   111,    90,   225,
     323,   226,    -1,   111,    92,   225,   323,   226,    -1,    84,
     163,    62,   225,   314,   224,   314,   224,   314,   224,   314,
     224,   314,   224,   314,   226,    -1,    87,   163,    62,   225,
     314,   224,   314,   224,   314,   224,   314,   224,   314,   224,
     314,   226,    -1,    90,   163,    62,   225,   314,   224,   314,
     224,   314,   224,   314,   224,   314,   224,   314,   226,    -1,
      92,   163,    62,   225,   314,   224,   314,   224,   314,   224,
     314,   224,   314,   224,   314,   226,    -1,   274,    -1,   285,
      -1,   303,    -1,     4,   252,   253,    -1,   331,   252,   253,
      -1,    37,   220,   332,   221,    -1,    37,   220,   322,   221,
      -1,    37,   218,   322,   219,    -1,    37,   220,   225,   323,
     226,   221,    -1,    37,   218,   225,   323,   226,   219,    -1,
       4,   252,   225,   323,   226,   253,    -1,   331,   252,   225,
     323,   226,   253,    -1,    38,   252,   314,   224,   314,   224,
     314,   253,    -1,    39,   252,   314,   224,   314,   224,   314,
     253,    -1,    40,   252,   327,   253,    -1,    41,   252,   314,
     224,   314,   224,   314,   224,   314,   224,   314,   224,   314,
     253,    -1,   314,    -1,   322,    -1,   323,   224,   314,    -1,
     323,   224,   322,    -1,   225,   314,   224,   314,   224,   314,
     224,   314,   226,    -1,   225,   314,   224,   314,   224,   314,
     226,    -1,   332,    -1,     4,   222,   160,   222,     4,    -1,
     225,   326,   226,    -1,     4,   220,   314,   221,   222,   161,
      -1,   324,    -1,   326,   224,   324,    -1,   328,    -1,   332,
      -1,     4,   220,   314,   221,    -1,   331,   220,   314,   221,
      -1,     4,   218,   314,   219,    -1,   331,   218,   314,   219,
      -1,     4,   222,     4,    -1,     4,   220,   314,   221,   222,
       4,    -1,     5,    -1,   193,   220,   332,   221,    -1,    65,
      -1,   191,    -1,    70,    -1,   180,   218,   327,   219,    -1,
     179,   218,   327,   224,   327,   219,    -1,   181,   252,   327,
     253,    -1,   181,   252,   327,   224,   327,   253,    -1,    46,
     252,   330,   253,    -1,    47,   218,   327,   219,    -1,    48,
     218,   327,   219,    -1,    49,   218,   327,   224,   327,   224,
     327,   219,    -1,    44,   252,   330,   253,    -1,    58,   252,
     327,   253,    -1,    59,   252,   327,   253,    -1,    60,   252,
     327,   253,    -1,    57,   252,   314,   224,   327,   224,   327,
     253,    -1,    52,   252,   327,   224,   314,   224,   314,   253,
      -1,    52,   252,   327,   224,   314,   253,    -1,    45,   252,
     327,   253,    -1,    45,   252,   327,   224,   323,   253,    -1,
      66,   252,   327,   253,    -1,    67,    -1,    51,   252,   327,
     253,    -1,    50,   252,   327,   253,    -1,    -1,    81,   252,
     328,   329,   265,   253,    -1,   327,    -1,   330,   224,   327,
      -1,     4,   227,   225,   314,   226,    -1,   331,   227,   225,
     314,   226,    -1,     4,    -1,   331,    -1,   194,   220,   327,
     221,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   209,   209,   210,   215,   217,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   243,   247,   254,   259,   264,
     278,   291,   304,   332,   346,   359,   372,   391,   396,   397,
     398,   399,   400,   404,   406,   411,   413,   419,   523,   418,
     541,   548,   559,   558,   576,   583,   594,   593,   610,   627,
     650,   649,   663,   664,   665,   666,   667,   671,   672,   678,
     678,   679,   679,   685,   686,   687,   692,   698,   760,   777,
     806,   835,   840,   845,   850,   855,   862,   872,   901,   930,
     935,   940,   945,   953,   962,   968,   974,   987,  1000,  1015,
    1032,  1038,  1044,  1057,  1070,  1085,  1102,  1108,  1117,  1135,
    1153,  1162,  1174,  1179,  1187,  1207,  1230,  1241,  1249,  1271,
    1294,  1332,  1353,  1365,  1379,  1379,  1381,  1383,  1392,  1402,
    1401,  1422,  1421,  1440,  1439,  1457,  1467,  1466,  1480,  1482,
    1490,  1496,  1501,  1527,  1528,  1532,  1543,  1558,  1568,  1569,
    1574,  1582,  1591,  1599,  1617,  1621,  1627,  1635,  1639,  1645,
    1653,  1657,  1663,  1671,  1675,  1681,  1690,  1693,  1706,  1709,
    1717,  1727,  1755,  1798,  1821,  1850,  1871,  1889,  1929,  1959,
    1977,  1995,  2022,  2041,  2046,  2064,  2110,  2128,  2167,  2173,
    2179,  2186,  2227,  2253,  2277,  2302,  2319,  2323,  2342,  2376,
    2423,  2441,  2458,  2487,  2491,  2507,  2555,  2565,  2575,  2585,
    2595,  2605,  2652,  2663,  2679,  2680,  2685,  2688,  2692,  2721,
    2750,  2779,  2813,  2835,  2861,  2883,  2906,  2927,  2983,  3007,
    3032,  3058,  3171,  3190,  3233,  3247,  3253,  3268,  3296,  3313,
    3322,  3336,  3350,  3356,  3362,  3371,  3380,  3389,  3403,  3465,
    3483,  3500,  3515,  3544,  3556,  3580,  3584,  3589,  3597,  3602,
    3608,  3613,  3619,  3627,  3631,  3635,  3640,  3700,  3716,  3733,
    3750,  3772,  3794,  3829,  3837,  3845,  3851,  3858,  3865,  3885,
    3911,  3923,  3935,  3943,  3951,  3960,  3959,  3974,  3973,  3988,
    3987,  4002,  4001,  4015,  4022,  4029,  4036,  4043,  4050,  4057,
    4064,  4071,  4079,  4078,  4092,  4091,  4105,  4104,  4118,  4117,
    4131,  4130,  4144,  4143,  4157,  4156,  4170,  4169,  4183,  4182,
    4199,  4202,  4208,  4220,  4240,  4264,  4268,  4272,  4276,  4280,
    4284,  4290,  4296,  4300,  4304,  4308,  4312,  4331,  4344,  4345,
    4346,  4347,  4348,  4352,  4353,  4354,  4357,  4385,  4407,  4410,
    4426,  4429,  4446,  4449,  4455,  4458,  4465,  4468,  4475,  4531,
    4601,  4606,  4673,  4709,  4717,  4760,  4799,  4819,  4851,  4878,
    4904,  4930,  4956,  4982,  5004,  5032,  5060,  5088,  5116,  5144,
    5183,  5222,  5243,  5264,  5291,  5295,  5305,  5340,  5341,  5342,
    5346,  5352,  5364,  5382,  5410,  5411,  5412,  5413,  5414,  5415,
    5416,  5417,  5418,  5425,  5426,  5427,  5428,  5429,  5430,  5431,
    5432,  5433,  5434,  5435,  5436,  5437,  5438,  5439,  5440,  5441,
    5442,  5443,  5444,  5445,  5446,  5447,  5448,  5449,  5450,  5451,
    5452,  5453,  5454,  5455,  5456,  5457,  5466,  5467,  5468,  5469,
    5470,  5471,  5472,  5473,  5474,  5475,  5476,  5481,  5480,  5488,
    5493,  5498,  5515,  5533,  5551,  5569,  5587,  5592,  5598,  5613,
    5632,  5652,  5672,  5692,  5715,  5720,  5725,  5735,  5745,  5750,
    5761,  5770,  5775,  5780,  5807,  5811,  5815,  5819,  5823,  5830,
    5834,  5838,  5842,  5849,  5854,  5861,  5866,  5870,  5875,  5879,
    5887,  5898,  5902,  5914,  5922,  5930,  5937,  5947,  5976,  5980,
    5984,  5988,  5992,  5996,  6000,  6004,  6008,  6037,  6066,  6095,
    6124,  6137,  6150,  6163,  6176,  6186,  6196,  6206,  6218,  6231,
    6243,  6247,  6251,  6255,  6259,  6277,  6295,  6303,  6311,  6340,
    6353,  6358,  6362,  6366,  6378,  6382,  6394,  6411,  6421,  6425,
    6440,  6445,  6452,  6456,  6469,  6483,  6497,  6511,  6525,  6533,
    6544,  6548,  6552,  6560,  6566,  6572,  6580,  6588,  6595,  6603,
    6618,  6632,  6646,  6658,  6674,  6683,  6692,  6702,  6713,  6721,
    6729,  6733,  6752,  6759,  6765,  6772,  6780,  6779,  6792,  6797,
    6803,  6812,  6825,  6828,  6832
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tTestLevel", "tExp", "tLog", "tLog10", "tSqrt", "tSin",
  "tAsin", "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh",
  "tCosh", "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod",
  "tModulo", "tHypot", "tList", "tLinSpace", "tLogSpace", "tListFromFile",
  "tCatenary", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tAbsolutePath", "tDirName",
  "tStrSub", "tStrLen", "tFind", "tStrFind", "tStrCmp", "tStrChoice",
  "tUpperCase", "tLowerCase", "tLowerCaseIn", "tTextAttributes",
  "tBoundingBox", "tDraw", "tSetChanged", "tToday", "tFixRelativePath",
  "tCurrentDirectory", "tSyncModel", "tNewModel", "tOnelabAction",
  "tOnelabRun", "tCpu", "tMemory", "tTotalMemory", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tDefineNumber", "tDefineString", "tSetNumber",
  "tSetString", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBlock", "tCylinder",
  "tCone", "tEllipsoid", "tQuadric", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh",
  "tSetFactory", "tThruSections", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanDifference", "tBooleanSection",
  "tBooleanFragments", "tRecombine", "tSmoother", "tSplit", "tDelete",
  "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers",
  "tScaleLast", "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tSlide", "tMacro", "tShow", "tHide",
  "tGetValue", "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber",
  "tHomology", "tCohomology", "tBetti", "tExists", "tFileExists",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tGmshExecutableName", "tSetPartition", "tNameToString", "tStringToName",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC",
  "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'",
  "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems",
  "GeoFormatItem", "SendToFile", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "@1", "@2", "Text2DValues",
  "Text2D", "@3", "Text3DValues", "Text3D", "@4", "InterpolationMatrix",
  "Time", "@5", "NumericAffectation", "NumericIncrement", "LP", "RP",
  "Affectation", "Comma", "DefineConstants", "@6", "@7", "@8", "@9",
  "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId0", "PhysicalId1", "PhysicalId2", "PhysicalId3",
  "InSphereCenter", "CircleOptions", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "SetPartition",
  "Visibility", "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12",
  "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "BooleanShape", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@23", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@24",
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,    63,
     454,   455,   456,   457,    60,    62,   458,   459,    43,    45,
      42,    47,    37,    33,   460,   461,   462,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   232,   232,   233,   233,   233,
     233,   233,   233,   234,   234,   234,   234,   235,   235,   235,
     235,   235,   235,   236,   236,   237,   237,   239,   240,   238,
     241,   241,   243,   242,   244,   244,   246,   245,   247,   247,
     249,   248,   250,   250,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   255,   255,   256,   256,   256,   257,
     256,   258,   256,   259,   256,   256,   260,   256,   261,   261,
     262,   262,   262,   263,   263,   264,   264,   264,   265,   265,
     266,   266,   266,   266,   267,   267,   267,   268,   268,   268,
     269,   269,   269,   270,   270,   270,   271,   271,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   275,   275,   276,   276,   276,   276,
     276,   276,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   278,   278,   278,   278,   278,   279,
     279,   280,   281,   281,   281,   281,   281,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   283,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   285,   285,   285,   286,   285,   287,   285,   288,
     285,   289,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   290,   285,   291,   285,   292,   285,   293,   285,
     294,   285,   295,   285,   296,   285,   297,   285,   298,   285,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   301,   301,
     301,   301,   301,   302,   302,   302,   303,   304,   305,   305,
     306,   306,   307,   307,   308,   308,   309,   309,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   311,   311,   311,   312,   312,   312,
     313,   313,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   316,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   317,   317,   317,   317,   317,   318,
     318,   318,   318,   319,   319,   320,   320,   320,   320,   320,
     320,   321,   321,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     323,   323,   323,   323,   324,   324,   324,   324,   325,   325,
     326,   326,   327,   327,   327,   327,   327,   327,   327,   327,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   329,   328,   330,   330,
     331,   331,   332,   332,   332
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     5,     7,
       7,     7,     9,     6,     6,     6,     8,     0,     2,     2,
       2,     2,     2,     1,     3,     1,     3,     0,     0,    10,
       1,     3,     0,    13,     1,     3,     0,    15,     8,    14,
       0,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     7,     7,     4,     3,     6,
       6,     7,     7,     6,     6,     9,     9,     6,     6,     7,
       7,     6,     6,     4,     8,     8,     9,     9,     9,     9,
       8,     8,     9,     9,     9,     9,     6,     9,     6,     9,
       5,     8,     8,    11,     6,     9,     5,     7,     9,     9,
      11,     7,     9,     9,     0,     1,     0,     3,     5,     0,
       9,     0,    11,     0,    11,     5,     0,     9,     0,     3,
       3,     5,     5,     0,     2,     3,     5,     3,     0,     2,
       3,     3,     3,     5,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     0,     5,     0,     2,
       5,     7,     8,     6,     7,     4,     7,     8,     8,     7,
       7,    11,     8,     4,     8,     8,     8,     9,     3,     4,
      10,     7,     7,     7,     7,     8,     4,     8,    12,     8,
       8,     7,     9,     4,     8,     8,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,    14,    14,    14,
      14,     8,     8,     6,     4,     6,     6,     3,     4,     5,
       6,     5,     3,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     2,     2,    16,    11,     6,     8,
       8,    10,     1,     2,     2,     1,     3,     3,     4,     4,
       1,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     9,     6,     1,     1,
       1,     1,     1,     0,     2,     3,     9,    14,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     7,     6,
       8,     5,     3,     8,     5,     4,     6,    11,    11,    18,
      18,    12,    12,    12,    10,    10,    10,    10,    10,     4,
       4,     4,     4,     4,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     4,
       6,     1,     4,     4,     4,     4,     4,     4,     4,     2,
       5,     5,     5,     5,     3,     6,     4,     7,     6,     6,
       6,     4,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     5,     5,     5,     5,
      16,    16,    16,    16,     1,     1,     1,     3,     3,     4,
       4,     4,     6,     6,     6,     6,     8,     8,     4,    14,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     4,     4,     3,     6,
       1,     4,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     1,     3,
       5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   582,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,   339,
     340,   341,   342,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     0,   280,   281,     0,     0,     0,   275,
       0,     0,     0,     0,     0,   387,   388,   389,     0,     0,
       5,     7,     6,     8,     9,    10,    23,    11,    12,    13,
      14,    22,    21,    20,    15,     0,    16,    17,    18,    19,
       0,    24,   583,     0,   436,   582,   550,   437,   439,   440,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,     0,   573,   554,   444,   445,   446,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   441,   442,
     443,   553,     0,     0,     0,     0,    69,    70,     0,     0,
     216,     0,     0,     0,   394,     0,   542,   583,   451,     0,
       0,     0,     0,   259,     0,   261,   262,   257,   258,     0,
     263,   264,   126,   138,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   582,
       0,   216,   583,     0,     0,   384,     0,     0,     0,     0,
       0,     0,     0,     0,   582,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   514,
     515,     0,   516,   485,   491,     0,   486,   583,   451,     0,
       0,     0,     0,   582,     0,     0,   536,     0,     0,     0,
       0,   255,   256,     0,   582,     0,     0,     0,   273,   274,
       0,   216,     0,   216,   582,     0,   583,     0,     0,   216,
     390,     0,     0,    69,    70,     0,     0,    62,    66,    65,
      64,    63,    68,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   397,   396,   398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   215,     0,   214,     0,     0,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   248,     0,     0,   459,
     188,     0,   582,     0,   542,   583,   543,     0,     0,   578,
       0,   124,   124,     0,     0,     0,     0,   530,   531,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   352,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,   216,     0,   476,   475,     0,
       0,     0,     0,   216,   216,     0,     0,     0,     0,     0,
       0,     0,   291,     0,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   354,     0,     0,     0,     0,     0,
       0,     0,   237,   385,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   498,     0,     0,   499,     0,   500,     0,   501,
       0,     0,     0,     0,     0,     0,   396,   493,     0,   487,
       0,     0,     0,   362,    69,    70,     0,   254,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,   277,
     276,     0,   242,     0,   243,     0,     0,     0,   216,     0,
       0,     0,     0,   343,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,   464,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,   395,    62,    63,     0,     0,    62,
       0,     0,     0,     0,     0,   211,     0,     0,     0,     0,
     217,     0,     0,     0,   412,   411,   410,   409,   405,   406,
     408,   407,   400,   399,   401,   402,   403,   404,     0,     0,
       0,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,   382,   383,     0,     0,     0,     0,     0,
       0,   350,     0,     0,     0,   154,   155,     0,   157,   158,
       0,   160,   161,     0,   163,   164,     0,   183,     0,   196,
       0,   203,     0,     0,     0,     0,   175,   216,     0,     0,
       0,     0,     0,   478,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   365,     0,     0,   238,
       0,     0,   234,     0,     0,     0,   380,   379,     0,     0,
       0,     0,     0,   464,    71,    72,     0,   517,     0,     0,
       0,     0,     0,   451,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   502,     0,   503,     0,   504,     0,   505,
       0,     0,   395,   488,   495,     0,   401,   494,     0,     0,
       0,   518,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   279,     0,     0,   244,   246,     0,   584,     0,     0,
       0,     0,     0,     0,    62,    63,     0,     0,    62,    63,
       0,     0,     0,     0,    93,    77,     0,   453,   452,   466,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   435,
     423,     0,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,   563,     0,   570,   559,   560,   561,     0,   575,
     574,     0,   471,     0,     0,     0,     0,   564,   565,   566,
     473,   572,   143,   148,   116,     0,     0,   555,     0,   557,
       0,   449,   456,   457,   551,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,   458,     0,     0,     0,     0,   580,
       0,     0,    47,     0,     0,     0,    60,     0,    38,    39,
      40,    41,    42,   455,   454,     0,     0,   548,    27,    25,
       0,     0,     0,     0,    28,     0,     0,   249,   579,    73,
     127,    74,   139,     0,     0,     0,   532,   533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
     348,   353,   351,     0,   361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,   395,   395,     0,     0,     0,
       0,     0,   245,   247,     0,     0,     0,   206,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,   282,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
     452,     0,     0,   521,     0,   520,   519,     0,     0,   528,
       0,     0,   497,     0,     0,     0,     0,     0,     0,     0,
     489,     0,     0,   455,   454,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,   241,     0,   344,
       0,     0,     0,     0,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   581,     0,     0,   461,     0,
     460,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    91,     0,     0,    79,     0,     0,     0,
       0,    83,   106,   108,     0,     0,   540,     0,   114,     0,
       0,     0,     0,     0,   413,     0,     0,     0,     0,     0,
      33,   463,   462,   546,   544,    26,     0,     0,   547,   545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,   359,     0,     0,   156,     0,   159,     0,
     162,     0,   165,     0,     0,     0,     0,     0,     0,     0,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,     0,     0,   325,     0,   332,     0,   334,     0,   328,
       0,   330,     0,   292,   321,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,   366,     0,   236,   235,
     386,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,   507,   508,
     509,   496,   490,     0,     0,     0,     0,   537,     0,     0,
       0,   268,     0,     0,     0,   216,   345,   216,     0,     0,
       0,     0,    88,     0,    92,     0,     0,    80,     0,    84,
       0,   251,   465,   250,   424,   432,   433,   434,   571,     0,
       0,   569,   469,   470,   472,     0,     0,   448,   144,     0,
     577,   149,   468,   556,   558,   450,     0,     0,     0,    89,
       0,     0,     0,    62,     0,     0,     0,     0,    81,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   483,     0,     0,    29,    30,     0,    31,     0,
       0,   128,   135,     0,     0,    75,    76,   171,     0,     0,
       0,     0,     0,     0,   174,     0,     0,   191,   192,     0,
       0,   176,   201,   193,   194,     0,     0,     0,     0,     0,
     166,     0,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,   216,
     216,     0,   302,     0,   304,     0,   306,     0,   327,   485,
       0,     0,   333,   335,   329,   331,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,   524,   523,   522,     0,     0,     0,
       0,     0,     0,     0,   525,   179,   180,     0,     0,     0,
       0,   117,   121,     0,     0,   343,   343,     0,   392,     0,
       0,     0,    90,     0,     0,     0,    82,     0,   467,     0,
       0,     0,     0,     0,     0,   100,     0,     0,    94,     0,
       0,     0,     0,   111,     0,     0,   112,     0,   541,   218,
     219,   220,   221,     0,     0,    43,     0,     0,     0,     0,
       0,    45,   549,     0,     0,   129,   136,     0,     0,     0,
       0,   169,   177,   178,   182,     0,     0,   195,     0,     0,
     360,     0,     0,   186,     0,     0,   349,   200,   172,   185,
     199,   205,   184,     0,   197,   204,     0,     0,     0,     0,
       0,     0,   482,     0,   481,     0,     0,     0,   293,     0,
       0,   294,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,   232,   231,     0,     0,     0,     0,     0,     0,
       0,     0,   222,     0,     0,   363,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   535,     0,   270,   269,
       0,     0,     0,     0,     0,     0,     0,   101,     0,     0,
      95,     0,     0,     0,   562,   568,   567,     0,   145,   147,
       0,   150,   151,   152,   102,   104,    96,    98,   107,   109,
       0,   115,     0,    85,    48,     0,     0,     0,   484,     0,
       0,     0,    32,     0,   143,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,   187,     0,   356,
     356,     0,   122,   123,   216,     0,   209,   210,     0,     0,
       0,     0,     0,     0,     0,   322,     0,     0,   216,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   212,   526,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   119,     0,     0,   346,     0,   103,   105,    97,    99,
      86,     0,   530,   531,     0,     0,   539,     0,    44,     0,
       0,     0,    46,    61,     0,     0,     0,   133,   131,   374,
     376,   375,   377,   378,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   337,     0,
       0,     0,   287,     0,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   534,   271,     0,
       0,   216,   393,     0,   146,     0,     0,   153,   113,     0,
       0,     0,     0,     0,   130,   137,   143,   143,     0,     0,
       0,     0,     0,   357,   367,     0,     0,   368,     0,   207,
       0,   308,     0,     0,   310,     0,     0,   312,     0,     0,
       0,   323,     0,   283,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   120,   267,
     343,     0,   140,     0,     0,    52,     0,    58,     0,     0,
       0,     0,     0,   167,   198,     0,   371,     0,   372,   373,
     479,   296,     0,     0,   303,   297,     0,     0,   305,   298,
       0,     0,   307,     0,     0,     0,   289,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   132,     0,
       0,     0,     0,   314,     0,   316,     0,   318,   324,   336,
     288,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,    49,     0,    56,
       0,     0,     0,     0,     0,     0,   299,     0,     0,   300,
       0,     0,   301,     0,     0,   227,   228,   229,   230,     0,
     224,     0,     0,     0,     0,     0,   347,     0,    50,     0,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,   266,     0,     0,   309,     0,   311,     0,   313,
       0,   225,     0,     0,     0,     0,    51,    53,     0,    54,
       0,     0,     0,     0,     0,     0,   510,   511,   512,   513,
       0,     0,    59,   369,   370,   315,   317,   319,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   100,  1060,   101,   102,   758,  1634,  1640,
    1048,  1275,  1847,  2087,  1049,  2023,  2128,  1050,  2089,  1051,
    1052,  1279,   384,   479,   202,   887,   103,   776,   491,  1774,
    1927,  1926,  1775,   492,  1841,  1243,  1448,  1244,  1451,   814,
     817,   820,   823,  1665,  1501,   740,   329,   455,   456,   106,
     107,   108,   109,   110,   111,   112,   113,   330,  1147,  1954,
    2042,   852,  1689,  1692,  1695,  1992,  1996,  2000,  2067,  2070,
    2073,  1143,  1144,   331,   940,   332,   117,  1322,  1103,   811,
     865,  1871,   118,   119,   120,   121,   333,   204,  1002,   548,
     279,  1481,   334,   335,   336,   620,   345,  1033,  1267,   489,
     484,  1003,   490,   366,   338
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1744
static const yytype_int16 yypact[] =
{
   10149,    63,    73, 10295, -1744, -1744,  3994,    26,    -9,  -127,
    -117,     9,   111,   115,   129,   160,  -107,   172,   195,   -15,
       2,   108,   108,   -91,    70,    85,    38,   123,   156,    14,
     190,   210,   223,   234,   174,   165,   273,   416,   253,   500,
     281,   298,   401,   432,   280,   442,   788,   410,   350,   335,
     473,   -62,   363,   -58,   -58,   400,   488,  1557, -1744, -1744,
   -1744, -1744, -1744,   293,   601,   493,    39,    28,   530,   611,
     392,   646,   708,   726,  6049,   729,   525,   556,   569,    49,
       7, -1744,   575,   581, -1744, -1744,   772,   826,   613, -1744,
    6368,   624,  6795,    -4,    47, -1744, -1744, -1744,  9996,   631,
   -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744,
   -1744, -1744, -1744, -1744, -1744,   -77, -1744, -1744, -1744, -1744,
      72, -1744,  -172,   288, -1744,    10, -1744, -1744, -1744, -1744,
   -1744,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   649,   656,   668,   108,
     108,   108,   108,   671,   108,   108,   108,   108,   108,   108,
     684, -1744,   108, -1744, -1744, -1744, -1744, -1744,   108,   108,
     887,   693,   700,   701,   108,   108,   710,   716, -1744, -1744,
   -1744, -1744,   679,  9996,  9996,  9996,  9147,  9214,    33,    12,
      36,   699,   712,   466, -1744,   723,   935,    78,   -73,   950,
    9996,  6585,  6585, -1744,  9996, -1744, -1744, -1744, -1744,  6585,
   -1744, -1744, -1744, -1744, -1744, -1744,  7012,    12,  9996,  8936,
    9996,  9996,   735,  9996,  8936,  9996,  9996,   750,  8936,  9996,
    9996,  9996,  9996,  6483,   751,   761, -1744,  8936,  6049,  6049,
    6049,  6585,  9996,   765,   794,  6049,  6049,  6049,   801,   804,
     805,   809,   813,  6700,  6917,  7134,   769,  4554,   997,  6483,
      49,   829,   838,   -58,   -58,   -58,  9996,  9996,  -164, -1744,
    -106,   -58,   839,   858,   859,  8653,   -45,   -56,   842,   876,
     906,   920,   939,   944,   949,  6049,  6049,  6483,   971,    31,
     903, -1744,   941,  1138,  1160, -1744,   979,   980,   983,  6049,
    6049,   981,  1014,  1020,  -150, -1744,   308,   108,   108,   108,
     108,    51,    16,    18,    25,   789,  7351,  9996,  4860, -1744,
   -1744,  1004, -1744,  1343, -1744,  1237, -1744,   243,   180,  1243,
    9996,  9996,  9996,   -57,  9996,  1039, -1744,  1092,  9996,  9996,
    9996, -1744, -1744,  9996,  1032,  1262,  1271,  1053, -1744, -1744,
    1276, -1744,  1277, -1744,  -114,  3013,   408,  6585,  9996, -1744,
   -1744,  6483,  6483,  9430,  9497,  1067,  1068,  7012, -1744, -1744,
   -1744, -1744, -1744, -1744,  6483,  1281,  1091,  9996,  9996,  1315,
    9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,
    9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,
    9996,  9996,  6585,  6585,  6585,  6585,  6585,  6585,  6585,  6585,
    6585,  6585,  6483,  6585,  6585,  9996,  6585,  6585,  6585,  6585,
    6585,  9996,  7012,  9996,  6585,  6585,  6585,  6585,  6585,    12,
    7012,    12,  1116,  1116,  1116,   137,  5114,   142, 11695,   292,
    1124,  1340,   108,  1134, -1744,  1127,  7189,  9996,  8936, -1744,
    9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,  9996,
    9996,  9996,  9996,  9996,  9996, -1744, -1744,  9996,  9996, -1744,
   -1744,   618,   582,   -32, -1744,   616, -1744,    -6,  9878, -1744,
     372,   163,   508,  1143,  1144, 12086,  8936,  4231, -1744,   437,
   12107, 12128,  9996, 12149,   463, 12170, 12191,  9996,   615, 12212,
   12233, 12254, 12275,  1362,  9996,  9996,   633,  1364,  1365,  1367,
    1156, 12296,  9996,  9996,  1371,  1372,  1372,  9996,  8725,  8725,
    8725,  8725,  9996,  1370,  9996,  1374,  9996,  1375,  8936,  8936,
    9553,  1163,  1377,  1174, -1744, -1744,   152, -1744, -1744, 10291,
   10317,   -58,   -58,    36,    36,   272,  9996,  9996,  9996,  8653,
    8653,  9996,  7189,   297, -1744,  9996,  9996,  9996,  9996,  9996,
    9996,  9996,  9996,  9996,  1393,  1395,  1397,  9996,  1396,  9996,
    9996,  1250, -1744, -1744,  8936,  8936,  8936,  1403,  1404,  9996,
    9996,  9996,  9996,  9996,  1407,   483,  7568,  7785,  9996,  9996,
    6585,  9996, -1744,  1350,  9996, -1744,  1351, -1744,  1352, -1744,
    1353,    52,    53,    54,    55,  8936,  1116, -1744, 12317, -1744,
     707,  9996,  8002, -1744,  9996,  9996,   627, -1744, 12338, 12359,
   12380,  1256, 10343, -1744,  1194,  4614, 12401, 12422, 11718, -1744,
   -1744,  8936, -1744,  2812, -1744,  2849,  9996,  9996, -1744,  9996,
    9996,  1199, 12443, 10024,  1202,   718,   196, 12464,   204, 11741,
    9996,  8936,  1419,  1421, -1744,  9996, 12485, 11764,   -43,  5743,
    5743,  5743,  5743,  5743,  5743,  5743,  5743,  5743,  5743,  5743,
   10369,  5743,  5743,  5743,  5743,  5743,  5743,  5743, 10395, 10421,
   10447,   663,   676,   663,  1210,  1211,  1207,   746,   746,  1213,
     746,  1219,  1222,  1224, 10473,   746,   746,   746,   418,   746,
   13115, -1744,   841,  1225,  1233,  1216,   689,   706,  1247,  1248,
    1241,  1437,  1438,  6483,   317,  1441,  1442,  6483,   279,  7012,
    9996,  1482,  1485,    34,   746, -1744,   -23,    50,    46,   141,
   -1744,  4981,   748,  4756,  1590,  2243,   942,   942,   443,   443,
     443,   443,   681,   681,  1116,  1116,  1116,  1116,    24, 12506,
   11787, -1744,  9996,  9996,  1486,    77,  8936,  9996,  9996,  1487,
    8936,  9996,  1488,  6585,  1489, -1744,    12,  1490,  6585,  9996,
    7012,  1484,  8936,  8936,  1334,  1491,  1493, 12527,  1495,  1341,
    1496,  1498, 12548,  1355,  1499,  1512,  1514,  1515,  9996, 12569,
    5222,  1298, -1744, -1744, -1744,  1518,  1519, 12590, 12611,  9996,
    6483,  1521,  1524, 12632,  1308, 13115,  1307,  1313, 13115,  1310,
    1316, 13115,  1312,  1318, 13115,  1338, 12653, -1744, 12674, -1744,
   12695, -1744,   749,   752,  8936,  1317, -1744, -1744,  2958,  3156,
     -58,  9996,  9996, -1744, -1744,  1337,  1339,  8653, 10499, 10525,
   10551,  9738,   776,   -58,  3402, 12716,  5262, 12737, 12758, 12779,
   12800, 12821, 12842, 12863,  9996,  1532, -1744,  9996, 12884, -1744,
   11810, 11833, -1744,   758,   763,   771, -1744, -1744, 11856, 11879,
   10577, 12905, 11902,   180, -1744, -1744,  8936, -1744,  8936,  4231,
    1349,  8936,  1348,   567, 10603, 10629,   746, 10655,  1346,  5499,
    1347,  1354,  1356, -1744,  8936, -1744,  8936, -1744,  8936, -1744,
    8936,   782, -1744, -1744,  4797,  8936,  1116, -1744, 12926, 11925,
    8936, -1744,  1566,  1567,  1568,  1358,  9996,  4044,  9996,  9996,
   -1744, -1744,     1,   783, -1744, -1744,  4156, -1744,  1571,  9713,
    1357,  1360,  6483,  1582,  1545,  1549,  6483,   317,  1556,  1558,
    6483,   317,  5572,   787, -1744, -1744, 11948,   173,  1051, -1744,
   -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744,
   -1744,  9996, -1744, -1744, -1744, -1744, -1744, -1744, -1744,  9996,
    9996,  9996, -1744,  8936, -1744, -1744, -1744, -1744,  6585, -1744,
   -1744,  9996, -1744,  6483,  6585,  6585,  6585, -1744, -1744, -1744,
   -1744, -1744, -1744, -1744, -1744,  9996,  6585, -1744,  6585, -1744,
    9996, -1744, -1744, -1744, -1744,   108,   108,  1595, -1744,  9996,
    1597,   108,   108,  1600,    37,  9996,  1601,  1602,  1011, -1744,
    1603,  1391,    49,  1606, -1744,  8936,  8936,  8936,  8936, -1744,
     746,  9996, -1744,  1398,  1399,  1388, -1744,  1608, -1744, -1744,
   -1744, -1744, -1744,   214,   370, 12947, 11971, -1744, -1744,  1410,
    6585,   547, 12968, 11994, -1744,   586, 10681, -1744, -1744, -1744,
      67, -1744, -1744,  5743,   746,   -58,  4231, -1744,   938,  6483,
    6483,  1626,  6483,   947,  6483,  6483,  1627,  1546,  6483,  6483,
    6483,  6483,  1186,  1632,  1633,  8936, -1744,  1417,  1636,  1637,
    2403, -1744, -1744,  1641, -1744,  1642,   208,  9996,   208,  9996,
     208,  9996,   208,  9996,  1648,  1649,  1652,  1653,  1654,   835,
    1658,  4696, -1744, -1744,   301, 10707, 10733, -1744, -1744,  5715,
    -116,   -58,   -58,   -58,  1659,  9785,  1440,  1660,  1456,    41,
      43,    56,    59,   -14, -1744,   315, -1744,   776,  1670,  1673,
    1677,  1678,  1679,  1684,  1686,  1687,  1690, 13115, -1744,  1420,
    1473,  1694,  1695,  1696,  1613,  1697,  1699,  1700,  9996,   180,
     -93,   844,   845, -1744,   848, -1744, -1744,  9996,  9996, -1744,
    9996,  9996, -1744,  9996,  9996,  9996,   849,   854,   867,   880,
   -1744,  9996,   881,   180,   180,   888,  6483,  6483,  6483,  1704,
   10759, -1744,  4819,   399,  1705,  1706,  1500, -1744,  1501, -1744,
    1726,  1508,  6483,  1509, -1744,   108,   108,  1707,  9996,  1708,
     108,   108,  1719,  9996,  1728, -1744,   746,  1733, -1744,  1736,
   -1744,  1737,  5743,  5743,  5743,  5743,   730,  1522,  9668,  1492,
     746,   746,  1525,   738,   742, 12989,  1523,   746,  5743,  1671,
    6585, -1744,  1780, -1744,  1671,  6585, -1744,   322,  1528,  1738,
    1909, -1744, -1744, -1744,    49,  9996, -1744,   889, -1744,   896,
     904,   905,   909,   208, 13115,  1494,  9996,  9996,  6483,  1526,
   -1744, -1744, -1744, -1744,  1531, -1744,  1748,    79, -1744, -1744,
    1749,  9996,  5542,  1537,  1538,  1752,  1755,    11,  1539,  1540,
    1655,  1655,  6483,  1757,  1542,  1547,  1762,  1764,  6483,  1551,
    1765,  1771,  1772,  1773, -1744,  1776,  6483,   910,  6483,  6483,
    6483,  1778,  1777, -1744,  6483,  6483, 13115,  6483, 13115,  6483,
   13115,  6483, 13115,  6483,  6483,  6483,  1559,  1562,  1782,   536,
   -1744,  9996,  9996,  9996,  1578,  1580,  -142,  -129,  -119,  1586,
   -1744,  2055,  6483, -1744,  9996, -1744,  1803, -1744,  1804, -1744,
    1807, -1744,  1809, -1744, -1744,  8653,   501,  6266, -1744,  1591,
    1593,  1594,  1596,  1598,  1604,  8219, -1744,  8936, -1744, -1744,
   -1744,  1610,  9996, -1744, -1744, 12017,  1821,   746,  1607,  1612,
   10785, 10811, 10837, 10863, 10889, 10915, 10941, -1744, -1744, -1744,
   -1744, 13115, -1744,   746,  1816,  1822,  1668, -1744,  9996,  9996,
    9996, -1744,  1825,   743,  7012, -1744, -1744, -1744,  1614,  1831,
    1671,  6585, -1744,  2352, -1744,  1671,  6585, -1744,  2429, -1744,
     208, -1744,   407, -1744, -1744, -1744, -1744, -1744, -1744,  6585,
    9996, -1744, -1744, -1744, -1744,  6585,  1835, -1744, -1744,    15,
   -1744, -1744, -1744, -1744, -1744, -1744,  1834,   663,   663, -1744,
    1836,   663,   663,  7012,  9996,  1837,  1840,    34, -1744,  1839,
   12040,    49, -1744,  1841,  1842,  1843,  1847,  6483,  9996, 10967,
   10993,   917, -1744,  9996,  1850, -1744, -1744,  6585, -1744, 11019,
    5084, 13115, -1744,  1848,  1849, -1744, -1744, -1744,  9996,  9996,
     -58,  1851,  1852,  1853, -1744,  9996,  9996, -1744, -1744,  1854,
    9996, -1744, -1744, -1744, -1744,  1856,  1857,  1643,   932,  1860,
    1709,  9996, -1744,  1863,  1864,  1865,  1867,  1868,  1869,  1159,
    1870,  8936,  8936,  9996, -1744,  8725,  5946, 13010,  1973,    36,
      36,   -58,  1871,   -58,  1875,   -58,  1876,  9996, -1744,   110,
    1661, 13031, -1744, -1744, -1744, -1744,  7031,   321, -1744,  1877,
    1878,  6483,   -58,   -58,   -58,   -58,   -58,  4336,  1881,   948,
    9996,  2559,  1882,   180, -1744, -1744, -1744,  9996,  9996,  9996,
    9996,  9996,  9996,  9996, -1744, -1744, -1744,  6483,  4446,   145,
   13052, -1744, -1744,  5615,  1665, 10024, 10024,  6483, -1744,  1885,
     663,   663, -1744,  1887,   663,   663, -1744,  6483, -1744,  1675,
    5743,   746,  5325,  5832,  7012, -1744,  1889,  1890, -1744,  1894,
    1895,  1896,  2811, -1744,  1897,  1900, -1744,  1688, -1744, -1744,
   -1744, -1744, -1744,  1902,   641, 13115,  9996,  9996,  6483,  1689,
     955, 13115, -1744,  1905,  9996, -1744, -1744,  1698,  1714,  7248,
    7288,   603, -1744, -1744, -1744,  7465,  7505, -1744,  7682,  1907,
   -1744,  6483,  1916, -1744,  1859,  1918, 13115, -1744, -1744, -1744,
   -1744, -1744, -1744,  1715, -1744, -1744,   960,   961,  9625,  2938,
    1935,  1717, -1744,  9996, -1744,  1718,  1722,   332, -1744,  1720,
     355, -1744,  1724,   365, -1744,  1725, 12063,  1945,  6483,  1946,
    1727,  9996, -1744, -1744,   964,   368,   405,   412,   425,   435,
    8436,   471, -1744,  1953,  7722, -1744, -1744,  5743,  5743, 11045,
   11071, 11097, 11123, 11149,  1802,  9996, -1744,  9996, -1744, -1744,
    8936,  3233,  1959,  7012,  1740,  1741,  1742, -1744,  1963,  1964,
   -1744,  1965,  1966,  1967, -1744, -1744, -1744,  4860, -1744, -1744,
    6585, 13115, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744,
      49, -1744,  1815, -1744, -1744,  9996, 11175, 11201, -1744,  6483,
    9996,  1971, -1744, 11227, -1744, -1744,  6483,  6483,  1987,  1988,
    1989,  1990,  1992,  1993,   972, -1744,  1775, -1744,  6483,   597,
     737,  8936, -1744, -1744,    36,  5021, -1744, -1744,  8653,   776,
    8653,   776,  8653,   776,  1995, -1744,   973,  6483, -1744,  7899,
    1996,  8936,   -58,   -58,   -58,   -58,   -58, -1744, -1744, -1744,
   -1744,  9996,  9996,  9996,  9996,  9996,  9996,  7939,  8116,   976,
   -1744, -1744,  1784,  1779, -1744,  1999, -1744, -1744, -1744, -1744,
   -1744,  1000,  1872,  2000,  1001,  2002, -1744,  1781, 13115,  9996,
    9996,  1009, 13115, -1744,  9996,  1015,  1024, -1744, -1744, -1744,
   -1744, -1744, -1744, -1744, -1744,  1785,  9996,  1030,  1791,   -58,
    6483,  2003,  1792,   -58,  2013,  1034,  1794,  9996, -1744,  8156,
     476,   614,  8333,   485,   651,  8373,   490,   724, -1744,  6483,
    2016,  1910,  5882,  1798, -1744,  1045,   502,   510,   514,   527,
     531, 11253, 11279, 11305, 11331, 11357,  3330, -1744, -1744,  2019,
    2020, -1744, -1744,  9996, -1744,  7012,    12, -1744, -1744,  9996,
   13073, 11383,    58, 11409, -1744, -1744, -1744, -1744,  9996,  8493,
    2021,   -58,    93, -1744, -1744,   -58,   122, -1744,  2023, -1744,
    8608,  2024,  9996,  2025,  2027,  9996,  2028,  2029,  9996,  2031,
    1812, -1744,  9996, -1744,   776, -1744,  2033,  8936,  8936,  8936,
    8936,  8436,  9996,  9996,  9996,  9996,  9996, -1744, -1744, -1744,
   10024,  3877, -1744,  1823,  1048, -1744,  9996, -1744,  6483,  9996,
    1062,  1076, 11435, -1744, -1744,   538, -1744,   548, -1744, -1744,
   -1744, -1744,  1817,  8682, -1744, -1744,  1820,  8833, -1744, -1744,
    1838,  8873, -1744,  2037,  3687,  1031,  6104, -1744,  1077,  1080,
    1083,  1084,   560,  1088, 11461, 11487, 11513, 11539, 11565,  1824,
    7012,  1845,  2056,  1844, 13094,  1094,  8987, -1744, -1744,  9996,
     -58,   -58,   776,  2061,   776,  2062,   776,  2080, -1744, -1744,
   -1744, -1744,   776,  2084,  2085,  2086,  2087,  8936,  2090,  9996,
    9996,  9996,  9996,  9996,  2091, -1744, -1744, -1744,  6585, -1744,
    1873,  2093,  9054,   568,   577,  1151, -1744,  1879,  1294, -1744,
    1898,  1314, -1744,  1899,  1333, -1744, -1744, -1744, -1744,  1099,
   -1744,  5743, 11591, 11617, 11643, 11669, -1744,  1103, -1744,  1903,
    6483, -1744,  2094,  9996,  9996,  2095,   776,  2096,   776,  2100,
     776, -1744,  2116, -1744,  9996,  9996,  9996,  9996,  6585,  2119,
    6585,  1128, -1744,  9096,  9172, -1744,  1369, -1744,  1452, -1744,
    1543, -1744,  9270,  9337,  9379,  9455, -1744, -1744,  1139, -1744,
    2121,  2123,  2124,  2125,  2126,  2127, -1744, -1744, -1744, -1744,
    6585,  2128, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1744, -1744, -1744, -1744,   852, -1744, -1744, -1744, -1744,   222,
   -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744,
   -1744, -1744,  -420,    13,  2359,  3257, -1744,  1650, -1744, -1744,
   -1744, -1744, -1744, -1744, -1744, -1743, -1744,   373, -1744, -1744,
   -1744, -1744, -1744, -1744,   846,  2140,    17,  -541,  -275, -1744,
   -1744, -1744, -1744, -1744, -1744, -1744, -1744,  2146, -1744, -1744,
   -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744, -1744,
   -1744, -1096, -1139,  2147, -1590,  2148, -1744, -1744, -1744,  1628,
   -1744,   362, -1744, -1744, -1744, -1744,  1818, -1744, -1744,   105,
   -1744, -1296,  2510,  -110,  2883,   926,  -268,   686, -1744,   131,
     285, -1744,  -405,    -3,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -550
static const yytype_int16 yytable[] =
{
     122,   360,   543,   207,  1364,  1734,  1735,   691,  1204,   693,
     562,   347,   845,   846,   386,   213,   354,  1497,   237,  1613,
     105,   605,  1518,   607,   708,   723,   581,   727,  1042,   730,
     609,  1855,   304,   123,   305,   578,   208,   449,  1031,   209,
     453,  1257,   232,   299,   551,   552,   373,  1355,   374,  1357,
     237,  1366,   362,   343,   232,   375,   602,   903,   905,   907,
     909,   553,  1359,   302,  1977,  1361,   551,   552,   592,     4,
     593,   337,   594,     5,  1292,   200,   302,   201,   370,   551,
     552,   210,  1541,  1058,  1542,  1486,   643,   302,   645,   551,
     552,   211,   551,   552,   653,  1543,   303,  1544,   270,  1986,
    1134,   212,   551,   552,   646,  1545,   647,  1546,   594,   346,
    1345,   219,   306,   201,   271,   272,  1135,   215,   621,   554,
     356,   216,   382,   383,  1136,  1137,  1138,   228,  1988,  1386,
    1139,  1140,  1141,  1142,   229,   217,   385,   205,   517,   518,
     519,   368,   382,   383,   721,   524,   525,   526,   369,   725,
     274,   275,  -543,  1727,    52,    53,    54,    55,   278,   280,
     276,   286,   565,   551,   552,   631,   218,   277,    65,   566,
     201,    68,   382,   383,  1043,  1044,  1045,  1046,   220,   606,
     564,   608,  -548,  1980,  1981,   574,   575,   765,   610,  1356,
    1614,  1358,   766,   450,   451,   228,   302,  1258,  1259,   587,
     588,   221,  1035,   944,  1360,   222,    99,  1362,   485,   485,
     300,   948,  1363,   769,   603,  1018,   485,   454,   770,   551,
     552,   361,   223,  1205,   302,   348,   337,  1364,   387,   452,
     388,   337,   389,    99,   214,   337,   946,   201,   950,   238,
     337,   486,   486,    99,   337,   337,   337,   337,   485,   486,
    1047,   579,   337,   337,   337,   244,   233,   494,   201,  1032,
     337,   337,   337,   234,   301,  1704,   337,   302,   233,   838,
     839,  1037,   363,   243,   344,  1036,   604,   904,   906,   908,
     910,   486,  1059,  1978,  1059,  1293,  1018,  1294,   230,   854,
     371,   206,   337,   337,   337,   377,   477,   372,   478,   729,
     346,   551,   552,   231,  1019,   375,   337,   337,  1025,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     622,   472,   473,   337,  1018,   337,   224,   474,   225,  1463,
     551,   552,   378,   379,   380,   722,  1697,   378,   379,   380,
     726,   235,   483,   487,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   927,   240,
     551,   552,   474,   245,   485,  1784,  1038,   255,   337,   337,
     256,  1728,   257,   936,   236,   355,   840,   359,   546,   547,
    2019,   337,   520,   295,   774,   296,   555,   775,   382,   383,
     563,   378,   379,   380,   945,   382,   383,   486,  -546,   378,
     379,   380,   949,   378,   379,   380,   381,  1410,   239,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   337,
     485,   485,   246,   485,   485,   485,   485,   485,   240,   382,
     383,   485,   485,   485,   485,   485,   302,   266,   302,  -547,
     267,   241,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   242,   486,   486,   337,   486,   486,   486,   486,
     486,   624,   731,   625,   486,   486,   486,   486,   486,   718,
     375,   720,   459,  1851,   378,   379,   380,   381,   247,   309,
     551,   552,   310,   378,   379,   380,   381,   378,   379,   380,
     381,   253,  1867,   337,   382,   383,   847,   263,   651,   251,
     264,  1024,   265,   382,   383,   551,   552,   382,   383,   551,
     552,   493,   378,   379,   380,   381,   252,   378,   379,   380,
     381,   853,   254,   551,   552,  1341,   596,  1218,   597,   551,
     552,  1223,   382,   383,   258,   337,   337,   382,   383,  1365,
     551,   552,  1534,  1535,   692,  1701,   694,   695,   696,   697,
     698,   699,   700,   268,   702,   703,  1798,   705,   706,   707,
     269,   709,  1121,   551,   552,   713,   714,   715,   716,   717,
     454,   454,   282,   551,   552,   283,   551,   552,   284,  1800,
     298,   337,   337,   337,   248,   382,   383,   249,   273,  1802,
     250,   772,  1811,   337,   337,  -545,   773,   485,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   337,   551,   552,  1134,   474,   307,  1411,   337,
     551,   552,   382,   383,   761,   281,   649,   893,   650,  1812,
     486,  1135,  -549,   551,   552,   375,  1813,  1000,   337,  1136,
    1137,  1138,   773,   551,   552,  1139,  1140,  1141,  1142,  1814,
     311,   469,   470,   471,   472,   473,   843,   844,   337,  1815,
     474,   783,   662,   784,   547,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   551,
     552,   959,  2025,   474,   551,   552,  1325,   783,  1327,   789,
    1329,   297,  1331,   551,   552,  1816,   274,   275,   551,   552,
    1942,   308,   884,  1881,   885,  1884,   276,  1887,   886,  1945,
     551,   552,   312,   285,  1948,  1868,  1869,   711,   551,   552,
     337,  1870,   551,   552,   337,   719,  1957,  1558,  1134,   777,
     313,   896,   775,   339,  1958,   551,   552,  1020,  1959,   551,
     552,  1026,  1364,   340,  1135,  1364,   551,   552,  1364,  1592,
    1593,  1960,  1136,  1137,  1138,  1961,   551,   552,  1139,  1140,
    1141,  1142,  2030,   337,  1266,  1134,  1287,   337,   551,   552,
     485,   783,  2031,   302,   341,   485,   551,   552,   351,   337,
     337,  1135,   382,   383,  2047,   551,   552,   342,  1176,  1136,
    1137,  1138,  2093,   349,  2111,  1139,  1140,  1141,  1142,   350,
     762,  2094,   763,   486,   764,  1290,  1070,   337,   486,   201,
     783,   551,   552,   816,   819,   822,   825,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   337,   352,   353,   767,   474,   768,  1464,  1134,   783,
    1943,   793,   357,   375,  1457,  1458,   884,  1004,   885,  1461,
    1462,   367,   920,  1477,  1135,  1872,  1873,   783,  2005,   801,
    1764,  1870,  1136,  1137,  1138,  1765,  1364,   415,  1139,  1140,
    1141,  1142,   259,   611,   416,   260,   612,  1946,   261,   613,
     262,   614,   884,   337,   885,   337,   417,   773,   337,   422,
    1134,   471,   472,   473,   433,   884,   959,   885,   474,   441,
     983,   337,   429,   337,  1068,   337,  1135,   337,   884,  1072,
     885,   434,   337,  1008,  1136,  1137,  1138,   337,   435,   436,
    1139,  1140,  1141,  1142,   457,   884,  1364,   885,   439,  1364,
    1010,   783,  1364,   913,   440,  1364,  2065,   458,  2068,   337,
    2071,   476,   942,   337,   943,  1124,  2074,   337,   475,   884,
    1949,   885,  1130,   502,   783,   485,   480,   884,  1145,   885,
    1219,   884,  1446,   885,  1224,   884,  1449,   885,   507,   514,
    1228,  1230,   783,   783,  1040,  1117,   783,  1364,  1118,  1364,
     337,  1364,   783,   522,  1163,   485,   515,   783,   486,  1164,
     337,   485,   485,   485,   538,   783,  1469,  1165,  1685,  1686,
    2116,   541,  2118,   485,  2120,   485,   783,   783,  1190,  1206,
    1607,   783,   523,  1226,  1027,  1600,  1601,  1263,   486,   527,
    1604,  1605,   528,   529,   486,   486,   486,   530,  1298,   302,
    1299,   531,   337,   337,   337,   337,   486,  1304,   486,  1305,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   544,   482,   126,   485,   474,   783,
     567,  1338,   346,   545,   556,  1074,  1281,  1282,   783,   783,
    1387,  1388,   783,   783,  1389,  1397,   337,   337,   783,   337,
    1398,   337,   337,   557,   558,   337,   337,   337,   337,  1231,
     486,   783,   337,  1399,   568,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   783,   783,  1400,  1402,   166,   167,
     168,   169,   783,  1471,  1403,  1472,   171,   172,   173,  1237,
     783,   174,  1473,   580,   569,  1240,  1241,  1242,   783,   783,
    1474,  1475,   179,   783,   783,  1476,  1517,  1246,   570,  1247,
    1595,  1638,  1596,  1639,   582,  1134,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   499,  1638,   571,  1662,   474,
     504,  1135,   572,  1673,   508,  1674,   583,   573,   375,  1136,
    1137,  1138,   783,   516,  1713,  1139,  1140,  1141,  1142,  1770,
    1297,  1771,  1228,  1230,   783,   783,  1789,  1790,  1638,   577,
    1810,  1286,  1314,   337,   337,   337,  1638,  1889,  1865,  1890,
     783,   589,  1909,  1628,   584,   585,  1281,  1282,   586,   337,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,  1913,   773,  1914,  1917,   474,   369,
     182,   183,   184,  1638,   590,  1922,  1346,  1347,  1348,  1446,
     591,  1924,   191,   623,   192,    99,   485,   485,  1449,   627,
    1925,   485,   485,  1876,  1638,   634,  1930,  2040,   783,   201,
    1938,   302,     7,     8,   633,  1134,   382,   383,   639,   783,
    1465,  1956,  1770,  1229,  2022,   337,  -544,   640,   641,   486,
     486,  1135,   642,   644,   486,   486,  1446,   664,  2027,  1136,
    1137,  1138,   660,   661,   346,  1139,  1140,  1141,  1142,   337,
    1446,   783,  2028,  2043,   783,   337,  2044,   783,   783,  2045,
    2046,   665,   783,   337,  2048,   337,   337,   337,  1638,   668,
    2060,   337,   337,   783,   337,  2102,   337,  2108,   337,  2109,
     337,   337,   337,   474,   736,    24,    25,   737,    27,    28,
     738,    30,   739,    32,    33,  1844,   732,   733,    34,   337,
      35,   621,  1638,   735,  2130,    40,    41,    42,    43,   200,
      45,    46,    47,  2140,   337,  2141,    50,   779,   780,   798,
     802,   803,   337,   804,   337,   805,   827,  2095,   809,   810,
     829,   831,   835,   836,   742,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   837,
     864,   866,   869,   474,   867,    76,    77,    78,  1134,   876,
     877,   883,   898,   900,   901,   902,   925,   485,   485,   928,
     937,   941,   485,   485,  1135,   954,  1376,   955,  1134,   986,
     987,   988,  1136,  1137,  1138,  1007,   485,   991,  1139,  1140,
    1141,  1142,   485,   993,  1135,  1608,   994,  1134,   995,  1005,
     486,   486,  1136,  1137,  1138,   486,   486,  1006,  1139,  1140,
    1141,  1142,  1014,  1135,   832,   833,  1012,  1013,   302,   486,
    1557,  1136,  1137,  1138,   337,   486,   872,  1139,  1140,  1141,
    1142,  1015,  1016,  1134,   485,  1021,  1022,   337,  1029,  1030,
    1057,  1075,  1845,  1064,  1067,  1069,  1071,  1078,  1079,  1135,
    1080,   346,  1082,  1084,  1083,  1085,  1088,  1136,  1137,  1138,
     873,   874,   875,  1139,  1140,  1141,  1142,   486,  1087,  1089,
    2097,  1090,  1091,  1095,  1096,  1102,  1097,  1106,   337,   337,
    1104,  1107,  1108,  1892,  1109,  1110,  1111,  1112,  1158,  1120,
    2099,   911,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   622,   472,   473,   454,   454,   337,  2101,
     474,   287,  1113,  1127,   337,  1128,  1134,   933,  1173,  1175,
    1609,  1181,  1183,  1196,  1197,  1198,  1611,  1492,  1208,  1184,
    1199,  1185,  1135,  1211,   337,  1212,  1608,   953,  1214,  1215,
    1136,  1137,  1138,  1216,   337,  2133,  1139,  1140,  1141,  1142,
    1220,  1251,  1221,  1253,   337,  1651,  1256,  1261,  1262,   337,
    1264,  1265,  1268,  1278,  1280,  1285,  1276,  1277,  1643,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,  1302,  1308,   337,  1970,   474,  1309,  1315,
    1316,   288,  1318,  1319,  1320,   289,  1687,  1323,  1690,  1324,
    1693,   290,   291,   292,   293,  1333,  1334,  1134,   337,  1335,
    1336,  1337,  1339,  1349,   294,  1352,  1353,  1705,  1706,  1707,
    1708,  1709,  1711,  1135,  1354,   482,   126,  1367,  2134,  1368,
    2006,  1136,  1137,  1138,  1369,  1370,  1371,  1139,  1140,  1141,
    1142,  1372,  1061,  1373,  1374,   337,  1065,  1375,  1377,  1594,
    1378,  1379,  1380,  1381,  1382,  1383,  1384,   337,  1407,  1412,
    1413,  1442,  1478,  1422,  1424,   153,   154,   155,   156,   157,
     158,   159,   160,   161,  1414,  1427,  1415,   337,   166,   167,
     168,   169,  1416,  1417,  1429,  1419,   171,   172,   173,  1431,
    1432,   174,  1453,  1433,   337,  1467,  1439,   485,  1621,  1445,
    1466,  1483,   179,  1484,  1485,  1488,  1493,   302,  1495,  1494,
    1119,  1496,  1500,  1504,  1498,  1499,   337,  1505,  1507,  2135,
    1508,  1511,  1506,   337,   337,  1646,  1510,  1512,  1513,  1514,
     486,  1515,  1521,  1522,  1531,   337,  1459,  1532,   337,  1533,
     346,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,  1539,   337,  1540,  1547,   474,   337,  1552,
    1553,   454,  1171,  1554,  1172,  1555,  1561,  1174,  1562,  1563,
    1680,  1564,  1585,  1565,   203,  1573,  1575,  1587,  1586,  1566,
    1186,  1591,  1187,  1576,  1188,  1570,  1189,  1598,  1597,  1612,
    1615,  1192,  1618,  1623,  1624,  1626,  1195,  1629,  1630,  1631,
     182,   183,   184,  1632,  1642,  1647,  1648,  1652,  1653,  1654,
    1657,  1659,   191,  1660,   192,    99,  1663,   337,  1661,  1667,
    1668,  1669,  1664,  1670,  1671,  1672,  1675,  1688,  1732,  1915,
     621,  1691,  1694,  1702,  1703,  1698,   337,  1712,  1716,  1733,
     884,  1737,   885,  1740,  1744,  1754,  1755,  1749,  1752,  1753,
    1756,  1757,  1758,  1880,  1760,  1883,  1761,  1886,  1763,  1236,
    1762,  1772,  1783,   302,  1769,  1468,   365,  1896,  1897,  1898,
    1899,  1900,  1785,  1776,  1787,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,  1777,
    1788,  1793,  1794,   474,  1796,  1799,  1973,  1786,  1797,  1801,
    1803,  1805,  1808,  1807,   337,   337,   337,   337,   337,  1817,
    1826,  1269,  1270,  1271,  1272,  1831,  1833,  1834,  1835,  1836,
    1837,  1838,  1839,  1840,  1932,   337,  1846,  1853,  1936,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,  1859,  1860,  1861,  1862,   474,  1863,  1864,
    1866,  1888,  1894,  1910,  1911,  1912,  1919,  1916,  1918,  1934,
    1928,   442,   443,   444,   446,   448,  1931,  1935,  1832,  1937,
    1939,  1317,  1951,  1955,  1952,  1968,  1969,  1984,   481,  1989,
    1991,  1994,   488,  1995,  1998,  1999,  1985,  2002,  2003,  2007,
    1987,  2021,  2032,  2038,   337,  2034,   495,   497,   500,   501,
    2054,   503,   497,   505,   506,   485,   497,   509,   510,   511,
     512,  1548,  2057,  2036,  2056,   497,  2012,  2066,  2069,  2058,
     521,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   782,   472,   473,   540,  2072,   337,   486,   474,
    2075,  2076,  2077,  2078,   549,   550,  2080,  2086,  2090,  2091,
    2112,  2115,  2117,   550,  2096,   485,  2119,   485,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,  2121,  2098,  2100,  2127,   474,  2142,  2110,  2143,
    2144,  2145,  2146,  2147,  2149,  2063,  2064,   485,   486,  1487,
     486,  1974,   778,   104,   616,   618,   497,  1502,  1856,   114,
     115,   116,  1874,  1625,   812,     0,     0,     0,   628,   629,
     630,     0,   632,     0,     0,     0,   635,   636,   637,     0,
     486,   638,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   652,     0,     0,  2088,
     474,   657,   659,     0,     0,     0,     0,  1683,     0,  1684,
    1972,     0,     0,     0,     0,   666,   667,     0,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2126,
       0,  2129,     0,   704,     0,     0,     0,     0,     0,   710,
       0,   712,     0,     0,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,  2148,   474,     0,     0,   741,   497,     0,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,     0,     0,   759,   760,     0,     0,     0,
       0,     0,     0,  1569,     0,  2055,     0,     0,     0,     0,
       0,     0,     0,     0,   616,     0,     0,     0,     0,     0,
     787,     0,     0,     0,     0,   792,     0,     0,     0,     0,
       0,     0,   799,   800,     0,     0,     0,     0,     0,     0,
     807,   808,     0,     0,     0,   813,   815,   818,   821,   824,
     826,     0,   828,     0,   830,     0,   497,   497,  1602,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   848,   849,   850,   442,   443,   851,
     226,   227,     0,   855,   856,   857,   858,   859,   860,   861,
     862,   863,     0,     0,     0,   868,     0,   870,   871,     0,
       0,     0,   497,   497,   497,     0,     0,   878,   879,   880,
     881,   882,     0,     0,   889,   889,   894,   895,     0,   897,
       0,     0,   899,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,  1606,     0,     0,     0,   914,
     916,     0,   918,   919,     0,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,  1676,  1677,   497,
     474,     0,     0,     0,   881,   882,     0,   918,   919,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   952,   497,
       0,   376,     0,   956,     0,     0,     0,     0,     0,     0,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,     0,     0,  1321,   418,   419,
     420,   421,     0,   423,   424,   425,   426,   427,   428,     0,
       0,   430,     0,     0,     0,     0,     0,   431,   432,     0,
       0,     0,     0,   437,   438,     0,     0,     0,  1028,     0,
       0,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,  1715,     0,     0,     0,   474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1055,  1056,     0,     0,   497,  1062,  1063,     0,   497,  1066,
       0,     0,     0,     0,     0,     0,     0,  1073,     0,     0,
     916,  1076,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,  1092,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1100,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,   497,     0,     0,     0,  1829,     0,     0,  1125,
    1126,     0,     0,     0,     0,  1129,     0,     0,     0,     0,
       0,     0,     0,   595,     0,     0,   598,   599,   600,   601,
       0,     0,  1157,     0,     0,  1159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   497,     0,     0,   497,
       0,     0,     0,     0,     0,     0,     0,  1875,     0,     0,
       0,     0,   497,     0,   497,     0,   497,     0,   497,     0,
       0,     0,     0,   497,     0,     0,     0,  1895,   497,     0,
       0,     0,     0,     0,  1200,     0,  1202,  1203,     0,     0,
       0,     0,     0,   513,     0,     0,     0,  1210,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,   533,   535,   537,   474,     0,     0,   542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1232,
       0,     0,     0,     0,     0,     0,     0,  1233,  1234,  1235,
       0,   497,     0,     0,     0,     0,     0,   576,     0,  1238,
       0,   734,     0,     0,     0,     0,     0,  1759,     0,     0,
       0,     0,     0,  1245,     7,     8,     0,     0,  1248,     0,
       0,     0,     0,     0,     0,     0,     0,  1252,     0,     0,
       0,     0,     0,  1260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,   497,   497,   497,     0,     0,  1274,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   654,   655,  2008,  2009,  2010,  2011,  2013,     0,     0,
       0,     0,     0,     0,   663,     0,   736,    24,    25,   737,
      27,    28,   738,    30,   739,    32,    33,     0,     0,     0,
      34,     0,    35,   497,     0,     0,     0,    40,    41,    42,
      43,     0,    45,    46,    47,  1326,     0,  1328,    50,  1330,
       0,  1332,   701,   736,    24,    25,   737,    27,    28,   738,
      30,   739,    32,    33,  1792,     0,     0,    34,     0,    35,
       0,     0,     0,  1351,    40,    41,    42,    43,     0,    45,
      46,    47,     0,     0,     0,    50,     0,    76,    77,    78,
       7,     8,     0,  2079,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1385,     0,     0,     0,
       0,     0,     0,     0,     0,  1390,  1391,     0,  1392,  1393,
       0,  1394,  1395,  1396,    76,    77,    78,     0,     0,  1401,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,     0,  1423,     0,   934,     0,
       0,  1428,   736,    24,    25,   737,    27,    28,   738,    30,
     739,    32,    33,     0,     0,     0,    34,     0,    35,     0,
       0,     0,     0,    40,    41,    42,    43,     0,    45,    46,
      47,     0,     0,     0,    50,   935,     0,     0,     0,     0,
       0,     0,     0,  1470,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1479,  1480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1489,
    1491,     0,   498,    76,    77,    78,     0,   498,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,     0,     0,  1536,
    1537,  1538,     0,     0,     0,     0,     0,     0,     7,     8,
    1549,     0,  1551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1556,  1122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,     0,     0,
    1571,     0,     0,     0,     0,     0,     0,     0,     0,   617,
       0,   498,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,  1588,  1589,  1590,     0,
     474,     0,     0,  1017,     0,     0,     0,  1023,   648,  1830,
     736,    24,    25,   737,    27,    28,   738,    30,   739,    32,
      33,     0,     0,     0,    34,     0,    35,     0,  1610,     0,
       0,    40,    41,    42,    43,     0,    45,    46,    47,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1622,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1635,     0,     0,     0,
       0,  1641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,     0,     0,  1649,  1650,     0,     0,
    1101,     0,     0,  1655,  1656,     0,     0,     0,  1658,     0,
       0,     0,     0,     0,     0,     0,  1967,     0,     0,  1666,
       0,   498,     0,     0,     0,     0,     0,     0,     0,   497,
     497,  1678,     0,  1679,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1696,     0,     0,     0,     0,
       0,     0,     0,     0,  1249,  1250,     0,     0,     0,   617,
    1254,  1255,  1123,     0,     0,   497,     0,     0,  1714,     0,
       0,     0,     0,     0,     0,  1717,  1718,  1719,  1720,  1721,
    1722,  1723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1731,     0,     0,     7,     8,     0,     0,     0,     0,
       0,   498,   498,     0,     0,     0,     0,     0,     0,     0,
       0,  1751,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,  1213,     0,  1766,  1767,  1217,     0,     0,     0,
    1222,     0,  1773,     0,     0,     0,     0,   498,   498,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   890,
     892,     0,     0,     0,     0,     0,   736,    24,    25,   737,
      27,    28,   738,    30,   739,    32,    33,     0,   498,     0,
      34,  1795,    35,  1239,     0,   917,     0,    40,    41,    42,
      43,     0,    45,    46,    47,     0,     0,     0,    50,  1809,
       0,     0,     0,     0,   498,     0,     0,     0,   616,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,  1827,   498,  1828,     0,   474,   497,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
       0,     0,     0,     0,     0,  1842,     0,     0,     0,     0,
       0,     0,     0,     0,  1420,  1421,     0,     0,     0,  1425,
    1426,     0,     0,  1848,     0,     0,     0,     0,  1852,  1300,
    1301,     0,  1303,     0,  1306,  1307,     0,     0,  1310,  1311,
    1312,  1313,     0,     0,     0,     0,     0,     0,     0,   497,
       0,     0,     0,     0,     0,     0,  1879,     0,  1882,     0,
    1885,     0,     0,     0,     0,     0,     0,     0,  1146,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1901,
    1902,  1903,  1904,  1905,  1906,     0,     0,     0,     0,   498,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   917,  1077,  1920,  1921,     0,
       0,     0,  1923,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1929,     0,     0,     0,     0,     0,
       0,     0,     0,  2039,     0,  1940,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1404,  1405,  1406,     0,
       0,     0,     0,     0,     0,     0,     0,   498,     0,     0,
       0,     0,  1418,     0,     0,     0,     0,     0,     0,     0,
       0,  1971,     0,     0,     0,     0,     0,  1641,     0,     0,
       0,     0,     0,     0,     0,     0,  1982,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1993,     0,     0,  1997,     0,     0,  2001,     0,     0,   498,
    2004,   498,     0,     0,   498,   497,   497,   497,   497,   497,
    2014,  2015,  2016,  2017,  2018,     0,     0,   498,  1482,   498,
       0,   498,     0,   498,  2024,     0,     0,  2026,   498,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,  1503,     0,     0,     0,     0,     0,  1509,     0,
       0,     0,     0,     0,     0,     0,  1516,     0,  1482,  1519,
    1520,     0,     0,     0,  1523,  1524,     0,  1525,     0,  1526,
       0,  1527,     0,  1528,  1529,  1530,     0,  2062,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1550,     0,     0,   497,   498,  2081,  2082,  2083,
    2084,  2085,     0,     0,     0,     0,     0,  1560,     0,     0,
       0,     0,     0,   921,  2020,  1568,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  2113,  2114,     0,     0,     0,     0,     0,   498,   498,
     498,   498,  2122,  2123,  2124,  2125,   960,   961,   962,   963,
     964,   965,   966,   967,   968,   969,   970,     0,   972,   973,
     974,   975,   976,   977,   978,     0,     0,     0,   982,   984,
     985,     0,     0,     0,   989,   990,     0,   992,     0,     0,
       0,     0,   997,   998,   999,     0,  1001,     0,     0,     0,
       0,     0,     0,  1009,  1011,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,  1633,     0,     0,
       0,  1034,     0,     0,     0,     0,     0,   124,   125,   126,
    1645,     0,     0,   127,   128,   129,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,     7,     8,     0,   171,
     172,   173,     0,     0,   174,     0,   175,   176,   177,     0,
       0,  1482,     0,     0,   178,   179,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,  1724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1743,     0,     0,
       0,     0,  1748,     0,     0,     0,     0,     0,   736,    24,
      25,   737,    27,    28,   738,    30,   739,    32,    33,     0,
       0,     0,    34,     0,    35,     0,     0,     0,  1768,    40,
      41,    42,    43,  1179,    45,    46,    47,     0,     0,     0,
      50,     0,     0,     0,     0,   180,     0,     0,     7,     8,
       0,  1482,   181,   182,   183,   184,   185,     0,     0,     0,
     186,   187,   188,   189,   190,   191,     0,   192,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,    78,   193,   194,     0,     0,     0,   195,  1806,     0,
       0,     0,   196,     0,   197,     0,   198,   199,     0,   200,
       0,   201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   621,
     736,    24,    25,   737,    27,    28,   738,    30,   739,    32,
      33,     0,     0,     0,    34,     0,    35,     0,     0,     0,
     498,    40,    41,    42,    43,     0,    45,    46,    47,     0,
    1201,     0,    50,     0,     0,     0,     0,     0,     0,  1482,
       0,     0,     0,     0,     0,     0,  1857,  1858,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1273,  1482,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,     0,     0,     0,  1891,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1295,  1296,     0,     0,     0,     0,     0,     0,     0,   124,
     314,     0,     0,     0,     0,   127,   128,   129,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   316,   317,   318,   319,   320,     0,     0,
    1933,     0,  1207,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,     0,     0,     0,     0,   170,     0,  1950,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,   498,   498,   178,     0,     0,     0,
     321,     0,     0,   322,     0,     0,   323,     0,   324,     0,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   782,   472,   473,     0,     0,     0,   325,   474,     0,
     498,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,    58,    59,    60,    61,    62,     0,     0,    65,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1430,     0,     0,     0,     0,  1482,  1434,
    1435,  1436,  1437,  1438,     0,  1441,     0,  1443,  1444,     0,
    1447,  1450,     0,     0,  1454,  1455,  1456,     0,     0,     0,
       0,  1460,     0,     0,   181,     0,     0,     0,   185,     0,
       0,     0,   186,   187,   188,   189,   190,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   559,  1710,     0,     0,     0,   195,
       0,     0,     0,     0,   561,     0,     0,   124,   364,   199,
       0,   277,   619,   127,   128,   129,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,   617,     0,     0,     0,     0,     0,     0,
    1482,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,     0,     0,   498,     0,   170,     0,     0,     0,     0,
       0,     0,   929,     0,     0,     0,   175,   176,   177,     0,
    1843,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1574,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
    1584,     0,     0,   474,     0,     0,     0,     0,     0,     0,
    1725,     0,  1726,     0,   498,     0,     0,  1599,     0,     0,
       0,     0,  1603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,  1616,  1617,     0,     0,  1619,  1620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,     0,     0,     0,   185,     0,     0,     0,
     186,   187,   188,   189,   190,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,   194,  1041,     0,     0,   195,     0,     0,
       0,     0,   327,     0,     0,     0,     0,   199,     0,   539,
     736,    24,    25,   737,    27,    28,   738,    30,   739,    32,
      33,     0,     0,     0,    34,     0,    35,     0,     0,     0,
       0,    40,    41,    42,    43,  1191,    45,    46,    47,     0,
       0,     0,    50,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,  1409,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,     0,     0,
     498,   498,   498,   498,   498,     0,     0,     0,     0,     0,
       0,    76,    77,    78,     0,     0,     0,  1738,  1739,     0,
       0,  1741,  1742,   124,   314,     0,     0,  1745,  1746,   127,
     128,   129,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   316,   317,   318,
     319,   320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,     0,     0,     0,
       0,   170,  1340,     0,     0,     0,     0,     0,     0,     0,
     498,     0,   175,   176,   177,     0,     0,     0,     0,     0,
     178,     0,     0,     0,   321,     0,     0,   322,     0,     0,
     323,     0,   324,     0,     0,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,   325,     0,   474,  1819,  1820,     0,     0,    52,    53,
      54,    55,    56,     0,     0,    58,    59,    60,    61,    62,
       0,     0,    65,     0,     0,    68,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,   181,     0,
       0,     0,   185,     0,     0,     0,   186,   187,   188,   189,
     190,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   496,
       0,     0,     0,   195,     0,     0,     0,     0,   327,     0,
       0,     0,     0,   199,     0,     0,   619,   124,   314,   126,
       0,     0,     0,   127,   128,   129,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   316,   317,   318,   319,   320,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,     0,     0,     0,   171,
     172,   173,     0,     0,   174,     0,   175,   176,   177,     0,
       0,     0,     0,     0,   178,   179,     0,     0,   321,     0,
       0,   322,     0,     0,   323,     0,   324,     0,     0,     0,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   325,     0,     0,   474,     0,
       0,     0,    52,    53,    54,    55,    56,  1039,     0,    58,
      59,    60,    61,    62,     0,     0,    65,     0,     0,    68,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1877,     0,  1878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,   183,   184,   185,     0,     0,     0,
     186,   187,   188,   189,   190,   191,     0,   192,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,   326,     0,     0,     0,   195,     0,     0,
       0,     0,   327,     0,     0,     0,     0,   199,     0,   328,
       0,     0,     0,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,   124,   314,
     126,   474,     0,   724,   127,   128,   129,     0,  2103,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   316,   317,   318,   319,   320,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
     171,   172,   173,     0,     0,   174,     0,   175,   176,   177,
       0,     0,     0,     0,     0,   178,   179,     0,     0,   321,
       0,     0,   322,     0,     0,   323,     0,   324,     0,     0,
       0,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   325,     0,     0,   474,
       0,     0,     0,    52,    53,    54,    55,    56,  1094,     0,
      58,    59,    60,    61,    62,     0,     0,    65,     0,     0,
      68,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,     0,     0,     0,     0,     0,     0,     0,  1149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,   184,   185,     0,     0,
       0,   186,   187,   188,   189,   190,   191,     0,   192,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,   326,     0,     0,     0,   195,     0,
       0,     0,     0,   327,     0,   124,   364,   126,   199,     0,
    1747,   127,   128,   129,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     0,     0,     0,   171,   172,   173,
       0,     0,   174,     0,   175,   176,   177,     0,   124,   364,
     126,     0,   178,   179,   127,   128,   129,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
     171,   172,   173,     0,     0,   174,     0,   175,   176,   177,
       0,     0,     0,     0,     0,   178,   179,     0,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
     181,   182,   183,   184,   185,  1182,     0,     0,   186,   187,
     188,   189,   190,   191,     0,   192,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,   194,     0,     0,     0,   195,     0,     0,     0,     0,
     327,     0,     0,     0,     0,   199,     0,  1490,     0,     0,
       0,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,     0,     0,   181,   182,   183,   184,   185,  1225,     0,
       0,   186,   187,   188,   189,   190,   191,     0,   192,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,   194,     0,     0,     0,   195,     0,
       0,     0,     0,   327,     0,   124,   364,   126,   199,     0,
    1730,   127,   128,   129,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     7,     8,     0,   171,   172,   173,
       0,     0,   174,     0,   175,   176,   177,     0,     0,     0,
       0,     0,   178,   179,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,     0,
       0,  1344,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,   884,     0,   885,     0,   736,    24,    25,   737,
      27,    28,   738,    30,   739,    32,    33,     0,     0,     0,
      34,     0,    35,     0,     0,     0,     0,    40,    41,    42,
      43,     0,    45,    46,    47,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,   183,   184,   185,     0,     0,     0,   186,   187,
     188,   189,   190,   191,     0,   192,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
     193,   194,     0,     0,     0,   195,     0,     0,     0,     0,
     327,     0,   124,   314,   315,   199,     0,  1750,   127,   128,
     129,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   316,   317,   318,   319,
     320,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,     0,     0,  1953,     0,
     170,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,   175,   176,   177,     0,     0,     0,     0,     0,   178,
       0,     0,     0,   321,     0,     0,   322,     0,     0,   323,
       0,   324,     0,     0,     0,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
     325,     0,     0,   474,     0,     0,     0,    52,    53,    54,
      55,    56,  1681,     0,    58,    59,    60,    61,    62,     0,
       0,    65,     0,     0,    68,     0,     0,     0,   736,    24,
      25,   737,    27,    28,   738,    30,   739,    32,    33,     0,
       0,     0,    34,     0,    35,     0,     0,     0,     0,    40,
      41,    42,    43,     0,    45,    46,    47,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,   185,     0,     0,     0,   186,   187,   188,   189,   190,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   326,    76,
      77,    78,   195,     0,     0,     0,     0,   327,     0,   124,
     314,  1559,   199,     0,   328,   127,   128,   129,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   316,   317,   318,   319,   320,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,     0,     0,     0,     0,   170,     0,     0,
    2041,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,     0,     0,   178,     0,     0,     0,
     321,     0,     0,   322,     0,     0,   323,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,   126,     0,     0,     0,   325,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,    58,    59,    60,    61,    62,     0,     0,    65,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,   166,   167,   168,   169,     0,
       0,     0,     0,   171,   172,   173,     0,     0,   174,     0,
       0,     0,     0,     0,   181,     0,     0,     0,   185,   179,
       0,     0,   186,   187,   188,   189,   190,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   326,     0,     0,     0,   195,
       0,     0,     0,     0,   327,     0,   124,   314,     0,   199,
       0,   328,   127,   128,   129,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     316,   317,   318,   319,   320,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
       0,     0,     0,     0,   170,     0,     0,   182,   183,   184,
       0,     0,     0,     0,     0,   175,   176,   177,     0,   191,
       0,   192,    99,   178,     0,     0,     0,   321,     0,     0,
     322,     0,     0,   323,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
     126,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,    56,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    65,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,   166,   167,   168,   169,     0,     0,     0,     0,
     171,   172,   173,     0,     0,   174,     0,     0,     0,     0,
       0,   181,     0,     0,     0,   185,   179,     0,     0,   186,
     187,   188,   189,   190,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   326,     0,     0,     0,   195,     0,     0,     0,
       0,   327,     0,   124,   314,     0,   199,     0,   328,   127,
     128,   129,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   316,   317,   318,
     319,   320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,     0,     0,     0,
       0,   170,     0,     0,   182,   183,   184,     0,     0,     0,
       0,     0,   175,   176,   177,     0,   191,     0,   192,    99,
     178,     0,     0,     0,   321,     0,     0,   322,     0,     0,
     323,     0,   324,     0,     0,     0,     0,     0,     0,   358,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,     0,     0,     0,     0,     0,     0,    52,    53,
      54,    55,    56,     0,     0,    58,    59,    60,    61,    62,
       0,     0,    65,     0,     0,    68,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,   166,   167,   168,   169,     0,     0,     0,     0,
     171,   172,   173,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,     0,   181,     0,
       0,     0,   185,     0,     0,     0,   186,   187,   188,   189,
     190,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   326,
       0,     0,     0,   195,     0,     0,     0,     0,   532,     0,
     124,   314,     0,   199,     0,   328,   127,   128,   129,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   316,   317,   318,   319,   320,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   182,   183,   184,     0,   170,     0,
       0,     0,     0,     0,     0,     0,   191,     0,   192,   175,
     176,   177,     0,     0,     0,     0,     0,   178,     0,     0,
       0,   321,     0,     0,   322,     0,     0,   323,     0,   324,
       0,     0,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   325,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    56,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    65,
       0,     0,    68,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,   166,
     167,   168,   169,     0,     0,     0,     0,   171,   172,   173,
       0,     0,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,   181,     0,     0,     0,   185,
       0,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,   326,     0,     0,     0,
     195,     0,     0,     0,     0,   534,     0,   124,   314,     0,
     199,     0,   328,   127,   128,   129,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   316,   317,   318,   319,   320,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   182,   183,   184,     0,   170,     0,     0,     0,     0,
       0,     7,     8,   191,     0,   192,   175,   176,   177,     0,
       0,     0,     0,     0,   178,     0,     0,     0,   321,     0,
       0,   322,     0,     0,   323,     0,   324,     0,     0,     0,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   325,     0,     0,   474,     0,
       0,     0,    52,    53,    54,    55,    56,  1700,     0,    58,
      59,    60,    61,    62,     0,     0,    65,     0,     0,    68,
       0,     0,     0,   736,    24,    25,   737,    27,    28,   738,
      30,   739,    32,    33,     0,     0,     0,    34,     0,    35,
       0,     0,     0,     0,    40,    41,    42,    43,     0,    45,
      46,    47,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,   181,     0,     0,     0,   185,     0,     0,     0,
     186,   187,   188,   189,   190,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,   326,    76,    77,    78,   195,     0,     0,
       0,     0,   536,     0,   124,   314,     0,   199,     0,   328,
     127,   128,   129,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   316,   317,
     318,   319,   320,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   176,   177,     0,     0,     0,     0,
       0,   178,     0,     0,     0,   321,     0,     0,   322,     0,
       0,   323,     0,   324,     0,     0,     0,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,   325,     0,     0,   474,     0,     0,     0,    52,
      53,    54,    55,    56,  1778,     0,    58,    59,    60,    61,
      62,     0,     0,    65,     0,     0,    68,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,     0,     0,  1779,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
       0,     0,     0,   185,     0,     0,     0,   186,   187,   188,
     189,   190,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
     496,     0,     0,     0,   195,     0,     0,     0,     0,   327,
       0,   124,   314,     0,   199,     0,   615,   127,   128,   129,
       0,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   316,   317,   318,   319,   320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,     0,     0,     0,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   176,   177,     0,     0,     0,     0,     0,   178,     0,
       0,     0,   321,     0,     0,   322,     0,     0,   323,     0,
     324,     0,     0,     0,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,   325,
       0,     0,   474,     0,     0,     0,    52,    53,    54,    55,
      56,  1780,     0,    58,    59,    60,    61,    62,     0,     0,
      65,     0,     0,    68,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,     0,
       0,  1781,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
     185,     0,     0,     0,   186,   187,   188,   189,   190,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,   496,     0,     0,
       0,   195,     0,     0,     0,     0,   327,     0,   124,   314,
       0,   199,     0,   888,   127,   128,   129,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   316,   317,   318,   319,   320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   176,   177,
       0,     0,     0,     0,     0,   178,     0,     0,     0,   321,
       0,     0,   322,     0,     0,   323,     0,   324,     0,     0,
       0,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,   325,     0,     0,   474,
       0,     0,     0,    52,    53,    54,    55,    56,  1782,     0,
      58,    59,    60,    61,    62,     0,     0,    65,     0,     0,
      68,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,     0,     0,     0,     0,     0,     0,     0,  1818,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   185,     0,     0,
       0,   186,   187,   188,   189,   190,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,   496,     0,     0,     0,   195,     0,
       0,     0,     0,   327,     0,   124,   314,     0,   199,     0,
     891,   127,   128,   129,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   316,
     317,   318,   319,   320,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   176,   177,     0,     0,     0,
       0,     0,   178,     0,     0,     0,   321,     0,     0,   322,
       0,     0,   323,     0,   324,     0,     0,     0,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,   325,     0,     0,   474,     0,     0,     0,
      52,    53,    54,    55,    56,  1893,     0,    58,    59,    60,
      61,    62,     0,     0,    65,     0,     0,    68,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,  1907,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,     0,     0,     0,   185,     0,     0,     0,   186,   187,
     188,   189,   190,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,   496,     0,     0,     0,   195,     0,     0,     0,     0,
     327,     0,   124,   314,     0,   199,     0,   915,   127,   128,
     129,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   316,   317,   318,   319,
     320,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,     0,     0,     0,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   176,   177,     0,     0,     0,     0,     0,   178,
       0,     0,     0,   321,     0,     0,   322,     0,     0,   323,
       0,   324,     0,     0,     0,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
     325,     0,     0,   474,     0,     0,     0,    52,    53,    54,
      55,    56,  1908,     0,    58,    59,    60,    61,    62,     0,
       0,    65,     0,     0,    68,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,  1941,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,   185,     0,     0,     0,   186,   187,   188,   189,   190,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   326,     0,
       0,     0,   195,     0,     0,     0,     0,   327,     0,   124,
     314,     0,   199,     0,  1567,   127,   128,   129,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   316,   317,   318,   319,   320,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,     0,     0,   178,     0,     0,     0,
     321,     0,     0,   322,     0,     0,   323,     0,   324,     0,
       0,     0,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,   325,     0,     0,
     474,     0,     0,     0,    52,    53,    54,    55,    56,  1944,
       0,    58,    59,    60,    61,    62,     0,     0,    65,     0,
       0,    68,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,  1947,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,     0,     0,   185,     0,
       0,     0,   186,   187,   188,   189,   190,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   559,  1710,     0,     0,     0,   195,
       0,     0,     0,     0,   561,     0,   124,   364,     0,   199,
       0,   277,   127,   128,   129,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   162,   163,   164,   165,
     474,     0,     0,     0,   170,     0,     0,     0,     0,  1983,
       0,     0,     0,     0,     0,   175,   176,   177,   124,   364,
     126,     0,     0,   178,   127,   128,   129,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
     171,   172,   173,     0,     0,   174,     0,   175,   176,   177,
       0,     0,     0,     0,     0,   178,   179,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,   181,     0,     0,  1990,   185,     0,     0,     0,   186,
     187,   188,   189,   190,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   559,   560,     0,     0,     0,   195,     0,     0,     0,
       0,   561,     0,     0,     0,     0,   199,     0,   277,     0,
       0,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,     0,     0,   181,   182,   183,   184,   185,  2033,     0,
       0,   186,   187,   188,   189,   190,   191,     0,   192,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,   194,     0,     0,     0,   195,   124,
     314,     0,     0,   327,     0,   127,   128,   129,   199,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   316,   317,   318,   319,   320,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,     0,     0,   178,     0,     0,     0,
     321,     0,     0,   322,     0,     0,   323,     0,   324,     0,
       0,     0,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,   325,     0,     0,
     474,     0,     0,     0,    52,    53,    54,    55,    56,  2035,
       0,    58,    59,    60,    61,    62,     0,     0,    65,     0,
       0,    68,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,  2037,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,     0,     0,   185,     0,
       0,     0,   186,   187,   188,   189,   190,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   496,     0,     0,     0,   195,
     124,   364,     0,     0,   327,     0,   127,   128,   129,   199,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     162,   163,   164,   165,   474,     0,     0,     0,   170,     0,
       0,     0,     0,  2061,     0,     0,     0,   124,   364,   175,
     176,   177,     0,   127,   128,   129,     0,   178,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   162,   163,   164,
     165,   474,     0,     0,     0,   170,     0,     0,     0,     0,
    2092,     0,     0,     0,     0,     0,   175,   176,   177,     0,
       0,     0,     0,     0,   178,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,  2131,     0,     0,   181,     0,     0,     0,   185,
       0,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,   194,     0,     0,     0,
     195,     0,     0,     0,     0,   327,   445,     0,     0,     0,
     199,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,     0,   181,     0,     0,     0,   185,     0,  2132,     0,
     186,   187,   188,   189,   190,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,   194,     0,     0,     0,   195,     0,     0,
       0,     0,   327,   124,   364,   447,     0,   199,     0,   127,
     128,   129,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   162,   163,   164,   165,   474,     0,     0,
       0,   170,     0,     0,     0,     0,  2136,     0,     0,     0,
     124,   364,   175,   176,   177,     0,   127,   128,   129,     0,
     178,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     162,   163,   164,   165,   474,     0,     0,     0,   170,     0,
       0,     0,     0,  2137,     0,     0,     0,     0,     0,   175,
     176,   177,     0,     0,     0,     0,     0,   178,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,  2138,     0,     0,   181,     0,
       0,     0,   185,     0,     0,     0,   186,   187,   188,   189,
     190,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   194,
       0,     0,     0,   195,     0,     0,     0,     0,   327,   656,
       0,     0,     0,   199,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,   181,     0,     0,     0,   185,
       0,  2139,     0,   186,   187,   188,   189,   190,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,   194,     0,     0,     0,
     195,     0,     0,     0,     0,   327,   124,   364,   658,  1209,
     199,     0,   127,   128,   129,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   162,   163,   164,   165,
     474,     0,     0,     0,   170,     0,     0,     0,   834,     0,
       0,     0,     0,     0,     0,   175,   176,   177,   124,   364,
       0,  1350,     0,   178,   127,   128,   129,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   162,   163,
     164,   165,   474,     0,     0,     0,   170,     0,     0,     0,
    1791,     0,     0,     0,     0,     0,     0,   175,   176,   177,
       0,     0,     0,     0,     0,   178,     0,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,   884,     0,   885,
       0,   181,  1440,     0,     0,   185,     0,     0,     0,   186,
     187,   188,   189,   190,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   194,     0,     0,     0,   195,     0,     0,     0,
       0,   327,     0,     0,     0,     0,   199,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,   912,     0,     0,
       0,     0,   841,   181,     0,     0,     0,   185,     0,     0,
       0,   186,   187,   188,   189,   190,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,   194,     0,     0,     0,   195,   124,
     364,     0,     0,   327,     0,   127,   128,   129,   199,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,     0,     0,   178,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   771,     0,     0,     0,     0,     0,   736,    24,
      25,   737,    27,    28,   738,    30,   739,    32,    33,     0,
       0,     0,    34,     0,    35,     0,     0,     0,     0,    40,
      41,    42,    43,     0,    45,    46,    47,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,   939,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,     0,     0,   185,    76,
      77,    78,   186,   187,   188,   189,   190,     0,     0,     0,
      99,    -4,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   194,     0,     0,     0,   195,
       0,    -4,    -4,    -4,   327,     0,     0,    -4,    -4,   199,
      -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,     0,     0,     0,     0,     0,    -4,     6,
       0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     9,    10,     0,
       0,    -4,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,    14,    15,     0,    16,     0,     0,     0,
      17,    18,     0,    19,    20,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,     0,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,     0,    71,    72,    73,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,    75,
      76,    77,    78,     0,     0,    79,     0,    80,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,     0,    99,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,   841,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,   842,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,   926,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,   971,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,   979,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,   980,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,   981,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,   996,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1131,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1132,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1133,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1168,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1177,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1178,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1180,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1291,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1342,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1343,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1408,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1577,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1578,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1579,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1580,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1581,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1582,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1583,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1636,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1637,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1644,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1821,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1822,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1823,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1824,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1825,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1849,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1850,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1854,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1962,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1963,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  1964,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  1965,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  1966,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  1976,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  1979,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  2029,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  2049,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  2050,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  2051,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  2052,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,     0,     0,     0,  2053,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  2104,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,  2105,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  2106,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,  2107,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,   728,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,     0,     0,   932,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,   951,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,     0,     0,   958,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,  1054,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,     0,
       0,  1161,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,  1162,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,     0,     0,  1166,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,     0,     0,
    1167,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,     0,     0,  1170,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,     0,     0,  1194,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,     0,     0,  1227,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
       0,     0,  1284,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,     0,     0,  1289,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,     0,     0,  1572,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,     0,
       0,  1627,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,     0,     0,  1804,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,   781,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,   785,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,   786,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,   788,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,   790,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
     791,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,   794,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,   795,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,   796,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,   797,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,   806,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,   912,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,   922,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,   923,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,   924,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
     930,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,   931,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,   938,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,   947,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,   957,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,  1053,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,  1081,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,  1086,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,  1093,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,  1098,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
    1099,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,  1105,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,  1114,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,  1115,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,  1116,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,  1148,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,  1150,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,  1151,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,  1152,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,  1153,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
    1154,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,  1155,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,  1156,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,  1160,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474,     0,  1169,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   474,     0,  1193,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,   474,     0,  1283,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,   474,     0,  1288,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,   474,     0,  1452,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,   474,     0,  1682,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,   474,     0,
    1699,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   474,
       0,  1729,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
     474,     0,  1975,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,   474,     0,  2059,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   474
};

static const yytype_int16 yycheck[] =
{
       3,     5,   270,     6,  1143,  1595,  1596,   412,     7,   414,
     285,     4,   553,   554,     4,     6,     4,     6,     4,     4,
       3,     5,  1318,     5,   429,   445,   301,   447,     4,   449,
       5,  1774,     4,     3,     6,     4,     6,     4,     4,    13,
       4,     4,     4,     4,   208,   209,   218,     6,   220,     6,
       4,  1147,     5,     4,     4,   227,     5,     5,     5,     5,
       5,   225,     6,    66,     6,     6,   208,   209,   218,     6,
     220,    74,   222,     0,     7,   225,    79,   227,     6,   208,
     209,    90,   224,     6,   226,     6,   361,    90,   363,   208,
     209,   218,   208,   209,   369,   224,    66,   226,   160,     6,
     114,   218,   208,   209,   218,   224,   220,   226,   222,    79,
     226,   218,    84,   227,   176,   177,   130,     6,     8,   225,
      90,     6,   215,   216,   138,   139,   140,   218,     6,   222,
     144,   145,   146,   147,   225,     6,   123,     6,   248,   249,
     250,   218,   215,   216,     7,   255,   256,   257,   225,     7,
     208,   209,   225,     8,   118,   119,   120,   121,    53,    54,
     218,    56,   218,   208,   209,   222,     6,   225,   132,   225,
     227,   135,   215,   216,   150,   151,   152,   153,     6,   163,
     225,   163,   225,  1926,  1927,   295,   296,   219,   163,   148,
     175,   148,   224,   160,   161,   218,   199,   160,   161,   309,
     310,     6,   225,     7,   148,   220,   194,   148,   211,   212,
     171,     7,   226,   219,   163,     7,   219,   200,   224,   208,
     209,   225,   220,   222,   227,   218,   229,  1366,   218,   199,
     220,   234,   222,   194,   225,   238,   656,   227,   658,   225,
     243,   211,   212,   194,   247,   248,   249,   250,   251,   219,
     226,   220,   255,   256,   257,    90,   218,   227,   227,   225,
     263,   264,   265,   225,   225,  1561,   269,   270,   218,   544,
     545,   225,   225,    99,   225,   225,   225,   225,   225,   225,
     225,   251,   205,   225,   205,   218,     7,   220,   218,   564,
     218,     6,   295,   296,   297,     7,   218,   225,   220,     7,
     270,   208,   209,   218,   724,   227,   309,   310,   728,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   326,     7,   328,   218,   217,   220,     7,
     208,   209,   195,   196,   197,   198,   226,   195,   196,   197,
     198,   218,   211,   212,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   633,   218,
     208,   209,   217,    90,   367,  1661,   225,    87,   371,   372,
      90,   226,    92,   648,   218,    90,   224,    92,   273,   274,
    1970,   384,   251,    90,   221,    92,   281,   224,   215,   216,
     285,   195,   196,   197,   198,   215,   216,   367,   225,   195,
     196,   197,   198,   195,   196,   197,   198,     8,   218,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,     6,   426,   427,   428,   429,   430,   218,   215,
     216,   434,   435,   436,   437,   438,   439,    87,   441,   225,
      90,   218,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   218,   423,   424,   458,   426,   427,   428,   429,
     430,   218,   449,   220,   434,   435,   436,   437,   438,   439,
     227,   441,     6,  1769,   195,   196,   197,   198,   225,    87,
     208,   209,    90,   195,   196,   197,   198,   195,   196,   197,
     198,    90,  1788,   496,   215,   216,   224,    87,   367,   218,
      90,   222,    92,   215,   216,   208,   209,   215,   216,   208,
     209,   226,   195,   196,   197,   198,   218,   195,   196,   197,
     198,   224,    90,   208,   209,   224,   218,   947,   220,   208,
     209,   951,   215,   216,    92,   538,   539,   215,   216,   224,
     208,   209,     6,     7,   413,   224,   415,   416,   417,   418,
     419,   420,   421,   218,   423,   424,   224,   426,   427,   428,
      87,   430,   837,   208,   209,   434,   435,   436,   437,   438,
     553,   554,    84,   208,   209,    87,   208,   209,    90,   224,
      87,   584,   585,   586,    84,   215,   216,    87,   225,   224,
      90,   219,   224,   596,   597,   225,   224,   600,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   615,   208,   209,   114,   217,    87,   219,   622,
     208,   209,   215,   216,     6,   225,   218,   597,   220,   224,
     600,   130,   225,   208,   209,   227,   224,   219,   641,   138,
     139,   140,   224,   208,   209,   144,   145,   146,   147,   224,
       4,   208,   209,   210,   211,   212,   551,   552,   661,   224,
     217,   224,   377,   226,   559,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   208,
     209,   668,  1978,   217,   208,   209,  1106,   224,  1108,   226,
    1110,    90,  1112,   208,   209,   224,   208,   209,   208,   209,
     224,    90,   219,  1799,   221,  1801,   218,  1803,   225,   224,
     208,   209,     4,   225,   224,   118,   119,   432,   208,   209,
     723,   124,   208,   209,   727,   440,   224,   226,   114,   221,
       4,   600,   224,     4,   224,   208,   209,   724,   224,   208,
     209,   728,  1881,   218,   130,  1884,   208,   209,  1887,     6,
       7,   224,   138,   139,   140,   224,   208,   209,   144,   145,
     146,   147,   224,   766,  1032,   114,   219,   770,   208,   209,
     773,   224,   224,   776,   218,   778,   208,   209,     6,   782,
     783,   130,   215,   216,   224,   208,   209,   218,   221,   138,
     139,   140,   224,   218,  2090,   144,   145,   146,   147,   218,
     218,   224,   220,   773,   222,   219,   776,   810,   778,   227,
     224,   208,   209,   528,   529,   530,   531,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   834,     6,   220,   218,   217,   220,  1257,   114,   224,
     226,   226,   218,   227,  1249,  1250,   219,     6,   221,  1254,
    1255,   220,   225,  1273,   130,   118,   119,   224,  1954,   226,
     219,   124,   138,   139,   140,   224,  2005,   218,   144,   145,
     146,   147,    84,    84,   218,    87,    87,   226,    90,    90,
      92,    92,   219,   886,   221,   888,   218,   224,   891,   218,
     114,   210,   211,   212,     7,   219,   883,   221,   217,   220,
     224,   904,   218,   906,   773,   908,   130,   910,   219,   778,
     221,   218,   915,   224,   138,   139,   140,   920,   218,   218,
     144,   145,   146,   147,   225,   219,  2065,   221,   218,  2068,
     224,   224,  2071,   226,   218,  2074,  2032,   225,  2034,   942,
    2036,     6,   224,   946,   226,   840,  2042,   950,   225,   219,
     226,   221,   847,   218,   224,   958,     6,   219,   853,   221,
     947,   219,   224,   221,   951,   219,   224,   221,   218,   218,
     957,   958,   224,   224,   226,   226,   224,  2116,   226,  2118,
     983,  2120,   224,   218,   226,   988,   225,   224,   958,   226,
     993,   994,   995,   996,   225,   224,  1264,   226,  1539,  1540,
    2096,     4,  2098,  1006,  2100,  1008,   224,   224,   226,   226,
    1430,   224,   218,   226,   729,  1420,  1421,     6,   988,   218,
    1425,  1426,   218,   218,   994,   995,   996,   218,    90,  1032,
      92,   218,  1035,  1036,  1037,  1038,  1006,    90,  1008,    92,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   225,     4,     5,  1060,   217,   224,
     218,   226,  1032,   225,   225,   780,  1053,  1054,   224,   224,
     226,   226,   224,   224,   226,   226,  1079,  1080,   224,  1082,
     226,  1084,  1085,   225,   225,  1088,  1089,  1090,  1091,   958,
    1060,   224,  1095,   226,   218,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   224,   224,   226,   226,    57,    58,
      59,    60,   224,   224,   226,   226,    65,    66,    67,   988,
     224,    70,   226,   220,   218,   994,   995,   996,   224,   224,
     226,   226,    81,   224,   224,   226,   226,  1006,   218,  1008,
    1415,   224,  1417,   226,     6,   114,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   229,   224,   218,   226,   217,
     234,   130,   218,     4,   238,     6,     6,   218,   227,   138,
     139,   140,   224,   247,   226,   144,   145,   146,   147,   224,
    1075,   226,  1169,  1170,   224,   224,   226,   226,   224,   218,
     226,  1060,     6,  1196,  1197,  1198,   224,   224,   226,   226,
     224,   220,   226,  1471,   225,   225,  1193,  1194,   225,  1212,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   224,   224,   226,   226,   217,   225,
     179,   180,   181,   224,   220,   226,  1131,  1132,  1133,   224,
     220,   226,   191,     6,   193,   194,  1249,  1250,   224,     6,
     226,  1254,  1255,  1794,   224,   163,   226,   226,   224,   227,
     226,  1264,    12,    13,   225,   114,   215,   216,     6,   224,
    1257,   226,   224,   222,   226,  1278,   225,     6,   225,  1249,
    1250,   130,     6,     6,  1254,  1255,   224,     6,   226,   138,
     139,   140,   225,   225,  1264,   144,   145,   146,   147,  1302,
     224,   224,   226,   226,   224,  1308,   226,   224,   224,   226,
     226,   220,   224,  1316,   226,  1318,  1319,  1320,   224,     4,
     226,  1324,  1325,   224,  1327,   226,  1329,   224,  1331,   226,
    1333,  1334,  1335,   217,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,  1750,   222,     7,    98,  1352,
     100,     8,   224,   226,   226,   105,   106,   107,   108,   225,
     110,   111,   112,   224,  1367,   226,   116,   224,   224,     7,
       6,     6,  1375,     6,  1377,   219,     6,   226,     7,     7,
       6,     6,   219,     6,   458,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   225,
       7,     6,     6,   217,     7,   155,   156,   157,   114,     6,
       6,     4,    62,    62,    62,    62,   160,  1420,  1421,   225,
     221,   219,  1425,  1426,   130,     6,     6,     6,   114,   219,
     219,   224,   138,   139,   140,   219,  1439,   224,   144,   145,
     146,   147,  1445,   224,   130,  1432,   224,   114,   224,   224,
    1420,  1421,   138,   139,   140,  1425,  1426,   224,   144,   145,
     146,   147,   221,   130,   538,   539,   219,   219,  1471,  1439,
    1365,   138,   139,   140,  1477,  1445,   226,   144,   145,   146,
     147,    44,    44,   114,  1487,    44,    44,  1490,     6,     4,
       4,     7,  1760,     6,     6,     6,     6,   163,     7,   130,
       7,  1471,     7,     7,   163,     7,     7,   138,   139,   140,
     584,   585,   586,   144,   145,   146,   147,  1487,   163,     7,
     226,     7,     7,   225,     6,     4,     7,   219,  1531,  1532,
       6,   224,   219,  1808,   224,   219,   224,   219,     6,   222,
     226,   615,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,  1539,  1540,  1561,   226,
     217,     4,   224,   226,  1567,   226,   114,   641,   219,   221,
    1439,   225,   225,     7,     7,     7,  1445,  1292,     7,   225,
     222,   225,   130,   226,  1587,   225,  1573,   661,     6,    44,
     138,   139,   140,    44,  1597,   226,   144,   145,   146,   147,
      44,     6,    44,     6,  1607,  1500,     6,     6,     6,  1612,
       7,   220,     6,   225,     6,   205,   218,   218,  1487,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     7,     7,  1638,  1911,   217,    92,     7,
       7,    84,   225,     7,     7,    88,  1541,     6,  1543,     7,
    1545,    94,    95,    96,    97,     7,     7,   114,  1661,     7,
       7,     7,     4,     4,   107,   225,     6,  1562,  1563,  1564,
    1565,  1566,  1567,   130,   218,     4,     5,     7,   226,     6,
    1955,   138,   139,   140,     7,     7,     7,   144,   145,   146,
     147,     7,   766,     7,     7,  1698,   770,     7,   225,  1414,
       6,     6,     6,    90,     7,     6,     6,  1710,     4,     4,
       4,   219,   218,     6,     6,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   224,     6,   225,  1730,    57,    58,
      59,    60,     6,   225,     6,   226,    65,    66,    67,     6,
       4,    70,   219,     6,  1747,     7,   224,  1750,  1463,   224,
     222,   225,    81,   222,     6,     6,   219,  1760,     6,   221,
     834,     6,   107,     6,   225,   225,  1769,   225,     6,   226,
       6,     6,   225,  1776,  1777,  1490,   225,     6,     6,     6,
    1750,     5,     4,     6,   225,  1788,     6,   225,  1791,     7,
    1760,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   225,  1807,   225,   220,   217,  1811,     6,
       6,  1794,   886,     6,   888,     6,   225,   891,   225,   225,
    1535,   225,     6,   225,     6,     4,   219,   159,     6,   225,
     904,     6,   906,   221,   908,   225,   910,     6,   224,     4,
       6,   915,     6,     6,     4,     6,   920,     6,     6,     6,
     179,   180,   181,     6,     4,     7,     7,     6,     6,     6,
       6,     5,   191,     6,   193,   194,     6,  1870,   225,     6,
       6,     6,   163,     6,     6,     6,     6,     6,  1593,     7,
       8,     6,     6,     6,     6,   224,  1889,     6,     6,   224,
     219,     6,   221,     6,   219,     6,     6,  1612,  1613,  1614,
       6,     6,     6,  1798,     7,  1800,     6,  1802,     6,   983,
     222,     6,     5,  1916,   225,     6,    98,  1812,  1813,  1814,
    1815,  1816,     6,   225,     6,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   225,
     225,     6,   225,   217,   226,   225,  1916,    88,   226,   225,
     225,     6,   225,     7,  1957,  1958,  1959,  1960,  1961,     6,
     158,  1035,  1036,  1037,  1038,     6,   226,   226,   226,     6,
       6,     6,     6,     6,  1869,  1978,   161,     6,  1873,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     6,     6,     6,     6,   217,     6,     6,
     225,     6,     6,   219,   225,     6,   225,     7,     6,     6,
     225,   193,   194,   195,   196,   197,   225,   225,  1733,     6,
     226,  1095,     6,   225,   114,     6,     6,     6,   210,     6,
       6,     6,   214,     6,     6,     6,  1931,     6,   226,     6,
    1935,   218,   225,     6,  2047,   225,   228,   229,   230,   231,
     226,   233,   234,   235,   236,  2058,   238,   239,   240,   241,
     242,     6,     6,   225,   219,   247,  1961,     6,     6,   225,
     252,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   267,     6,  2090,  2058,   217,
       6,     6,     6,     6,   276,   277,     6,     6,   225,     6,
       6,     6,     6,   285,   225,  2108,     6,  2110,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     6,   225,   225,     6,   217,     6,   225,     6,
       6,     6,     6,     6,     6,  2030,  2031,  2140,  2108,  1287,
    2110,  1919,   492,     3,   326,   327,   328,  1301,  1775,     3,
       3,     3,  1790,  1467,   526,    -1,    -1,    -1,   340,   341,
     342,    -1,   344,    -1,    -1,    -1,   348,   349,   350,    -1,
    2140,   353,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   368,    -1,    -1,  2058,
     217,   373,   374,    -1,    -1,    -1,    -1,   224,    -1,   226,
    1915,    -1,    -1,    -1,    -1,   387,   388,    -1,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2108,
      -1,  2110,    -1,   425,    -1,    -1,    -1,    -1,    -1,   431,
      -1,   433,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,  2140,   217,    -1,    -1,   457,   458,    -1,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,    -1,    -1,   477,   478,    -1,    -1,    -1,
      -1,    -1,    -1,  1377,    -1,  2020,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,
     502,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,   514,   515,    -1,    -1,    -1,    -1,    -1,    -1,
     522,   523,    -1,    -1,    -1,   527,   528,   529,   530,   531,
     532,    -1,   534,    -1,   536,    -1,   538,   539,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   556,   557,   558,   559,   560,   561,
      21,    22,    -1,   565,   566,   567,   568,   569,   570,   571,
     572,   573,    -1,    -1,    -1,   577,    -1,   579,   580,    -1,
      -1,    -1,   584,   585,   586,    -1,    -1,   589,   590,   591,
     592,   593,    -1,    -1,   596,   597,   598,   599,    -1,   601,
      -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   615,    -1,     6,    -1,    -1,    -1,   621,
     622,    -1,   624,   625,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,  1531,  1532,   641,
     217,    -1,    -1,    -1,   646,   647,    -1,   649,   650,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   660,   661,
      -1,   122,    -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,   114,   159,   160,
     161,   162,    -1,   164,   165,   166,   167,   168,   169,    -1,
      -1,   172,    -1,    -1,    -1,    -1,    -1,   178,   179,    -1,
      -1,    -1,    -1,   184,   185,    -1,    -1,    -1,   730,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     6,    -1,    -1,    -1,   217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     762,   763,    -1,    -1,   766,   767,   768,    -1,   770,   771,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,
     782,   783,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   798,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   809,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,   834,    -1,    -1,    -1,  1730,    -1,    -1,   841,
     842,    -1,    -1,    -1,    -1,   847,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    -1,    -1,   317,   318,   319,   320,
      -1,    -1,   864,    -1,    -1,   867,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   886,    -1,   888,    -1,    -1,   891,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,    -1,    -1,
      -1,    -1,   904,    -1,   906,    -1,   908,    -1,   910,    -1,
      -1,    -1,    -1,   915,    -1,    -1,    -1,  1811,   920,    -1,
      -1,    -1,    -1,    -1,   926,    -1,   928,   929,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,   939,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,   263,   264,   265,   217,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   971,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,   980,   981,
      -1,   983,    -1,    -1,    -1,    -1,    -1,   297,    -1,   991,
      -1,   452,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,  1005,    12,    13,    -1,    -1,  1010,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1019,    -1,    -1,
      -1,    -1,    -1,  1025,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1035,  1036,  1037,  1038,    -1,    -1,  1041,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,   372,  1957,  1958,  1959,  1960,  1961,    -1,    -1,
      -1,    -1,    -1,    -1,   384,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,  1095,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,  1107,    -1,  1109,   116,  1111,
      -1,  1113,   422,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     6,    -1,    -1,    98,    -1,   100,
      -1,    -1,    -1,  1135,   105,   106,   107,   108,    -1,   110,
     111,   112,    -1,    -1,    -1,   116,    -1,   155,   156,   157,
      12,    13,    -1,  2047,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1177,  1178,    -1,  1180,  1181,
      -1,  1183,  1184,  1185,   155,   156,   157,    -1,    -1,  1191,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1218,    -1,   226,    -1,
      -1,  1223,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,    -1,   116,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1276,  1277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,
    1292,    -1,   229,   155,   156,   157,    -1,   234,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,  1341,
    1342,  1343,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
    1352,    -1,  1354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1365,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1377,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   326,
      -1,   328,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,  1408,  1409,  1410,    -1,
     217,    -1,    -1,   723,    -1,    -1,    -1,   727,   225,     6,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,   100,    -1,  1440,    -1,
      -1,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1478,    -1,    -1,    -1,
      -1,  1483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   156,   157,    -1,    -1,  1498,  1499,    -1,    -1,
     810,    -1,    -1,  1505,  1506,    -1,    -1,    -1,  1510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  1521,
      -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1531,
    1532,  1533,    -1,  1535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1547,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1015,  1016,    -1,    -1,    -1,   496,
    1021,  1022,   226,    -1,    -1,  1567,    -1,    -1,  1570,    -1,
      -1,    -1,    -1,    -1,    -1,  1577,  1578,  1579,  1580,  1581,
    1582,  1583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1593,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,   538,   539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1613,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   942,    -1,  1636,  1637,   946,    -1,    -1,    -1,
     950,    -1,  1644,    -1,    -1,    -1,    -1,   584,   585,   586,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,
     597,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,   615,    -1,
      98,  1683,   100,   993,    -1,   622,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,    -1,    -1,   116,  1701,
      -1,    -1,    -1,    -1,   641,    -1,    -1,    -1,  1710,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,  1725,   661,  1727,    -1,   217,  1730,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1215,  1216,    -1,    -1,    -1,  1220,
    1221,    -1,    -1,  1765,    -1,    -1,    -1,    -1,  1770,  1079,
    1080,    -1,  1082,    -1,  1084,  1085,    -1,    -1,  1088,  1089,
    1090,  1091,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,
      -1,    -1,    -1,    -1,    -1,    -1,  1798,    -1,  1800,    -1,
    1802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,  1811,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1821,
    1822,  1823,  1824,  1825,  1826,    -1,    -1,    -1,    -1,   766,
      -1,    -1,    -1,   770,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   782,   783,  1849,  1850,    -1,
      -1,    -1,  1854,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1866,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,  1877,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1196,  1197,  1198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   834,    -1,    -1,
      -1,    -1,  1212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1913,    -1,    -1,    -1,    -1,    -1,  1919,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1928,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1942,    -1,    -1,  1945,    -1,    -1,  1948,    -1,    -1,   886,
    1952,   888,    -1,    -1,   891,  1957,  1958,  1959,  1960,  1961,
    1962,  1963,  1964,  1965,  1966,    -1,    -1,   904,  1278,   906,
      -1,   908,    -1,   910,  1976,    -1,    -1,  1979,   915,    -1,
      -1,    -1,    -1,   920,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1302,    -1,    -1,    -1,    -1,    -1,  1308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1316,    -1,  1318,  1319,
    1320,    -1,    -1,    -1,  1324,  1325,    -1,  1327,    -1,  1329,
      -1,  1331,    -1,  1333,  1334,  1335,    -1,  2029,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1352,    -1,    -1,  2047,   983,  2049,  2050,  2051,
    2052,  2053,    -1,    -1,    -1,    -1,    -1,  1367,    -1,    -1,
      -1,    -1,    -1,   626,     7,  1375,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,  2093,  2094,    -1,    -1,    -1,    -1,    -1,  1035,  1036,
    1037,  1038,  2104,  2105,  2106,  2107,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,    -1,   681,   682,
     683,   684,   685,   686,   687,    -1,    -1,    -1,   691,   692,
     693,    -1,    -1,    -1,   697,   698,    -1,   700,    -1,    -1,
      -1,    -1,   705,   706,   707,    -1,   709,    -1,    -1,    -1,
      -1,    -1,    -1,   716,   717,    -1,    -1,    -1,  1095,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1477,    -1,    -1,
      -1,   734,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
    1490,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    12,    13,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,  1561,    -1,    -1,    80,    81,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,  1587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1597,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,    -1,
      -1,    -1,  1612,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,  1638,   105,
     106,   107,   108,   896,   110,   111,   112,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,   171,    -1,    -1,    12,    13,
      -1,  1661,   178,   179,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,   157,   208,   209,    -1,    -1,    -1,   213,  1698,    -1,
      -1,    -1,   218,    -1,   220,    -1,   222,   223,    -1,   225,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,
    1377,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     226,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,  1769,
      -1,    -1,    -1,    -1,    -1,    -1,  1776,  1777,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1040,  1788,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   156,   157,    -1,    -1,    -1,  1807,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1073,  1074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
    1870,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,  1889,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,  1531,  1532,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,   111,   217,    -1,
    1567,    -1,    -1,    -1,   118,   119,   120,   121,   122,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1226,    -1,    -1,    -1,    -1,  1978,  1232,
    1233,  1234,  1235,  1236,    -1,  1238,    -1,  1240,  1241,    -1,
    1243,  1244,    -1,    -1,  1247,  1248,  1249,    -1,    -1,    -1,
      -1,  1254,    -1,    -1,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,   218,    -1,    -1,     3,     4,   223,
      -1,   225,   226,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,
    2090,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,  1730,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    72,    73,    74,    -1,
    1747,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1387,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
    1403,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,   226,    -1,  1791,    -1,    -1,  1420,    -1,    -1,
      -1,    -1,  1425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1811,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,  1457,  1458,    -1,    -1,  1461,  1462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
     186,   187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,     8,    -1,    -1,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,     8,   110,   111,   112,    -1,
      -1,    -1,   116,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     8,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1957,  1958,  1959,  1960,  1961,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   156,   157,    -1,    -1,    -1,  1600,  1601,    -1,
      -1,  1604,  1605,     3,     4,    -1,    -1,  1610,  1611,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2047,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   111,    -1,   217,  1717,  1718,    -1,    -1,   118,   119,
     120,   121,   122,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,   132,    -1,    -1,   135,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,   178,    -1,
      -1,    -1,   182,    -1,    -1,    -1,   186,   187,   188,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,   226,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,   111,    -1,    -1,   217,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   226,    -1,   125,
     126,   127,   128,   129,    -1,    -1,   132,    -1,    -1,   135,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
      -1,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,     3,     4,
       5,   217,    -1,   219,     9,    10,    11,    -1,  2081,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,   111,    -1,    -1,   217,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   226,    -1,
     125,   126,   127,   128,   129,    -1,    -1,   132,    -1,    -1,
     135,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,   218,    -1,     3,     4,     5,   223,    -1,
     225,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    72,    73,    74,    -1,     3,     4,
       5,    -1,    80,    81,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   226,    -1,    -1,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   178,   179,   180,   181,   182,   226,    -1,
      -1,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,   218,    -1,     3,     4,     5,   223,    -1,
     225,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    12,    13,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   219,    -1,   221,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,
     208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
     218,    -1,     3,     4,     5,   223,    -1,   225,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,   226,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
     111,    -1,    -1,   217,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   226,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,   182,    -1,    -1,    -1,   186,   187,   188,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   155,
     156,   157,   213,    -1,    -1,    -1,    -1,   218,    -1,     3,
       4,     5,   223,    -1,   225,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,    81,
      -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,   218,    -1,     3,     4,    -1,   223,
      -1,   225,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,   191,
      -1,   193,   194,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,   182,    81,    -1,    -1,   186,
     187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,   218,    -1,     3,     4,    -1,   223,    -1,   225,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,   191,    -1,   193,   194,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,   178,    -1,
      -1,    -1,   182,    -1,    -1,    -1,   186,   187,   188,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,   218,    -1,
       3,     4,    -1,   223,    -1,   225,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,   179,   180,   181,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,   218,    -1,     3,     4,    -1,
     223,    -1,   225,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,   179,   180,   181,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    12,    13,   191,    -1,   193,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,   111,    -1,    -1,   217,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   226,    -1,   125,
     126,   127,   128,   129,    -1,    -1,   132,    -1,    -1,   135,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,    -1,   110,
     111,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
     186,   187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,   155,   156,   157,   213,    -1,    -1,
      -1,    -1,   218,    -1,     3,     4,    -1,   223,    -1,   225,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,   111,    -1,    -1,   217,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   226,    -1,   125,   126,   127,   128,
     129,    -1,    -1,   132,    -1,    -1,   135,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   182,    -1,    -1,    -1,   186,   187,   188,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,   218,
      -1,     3,     4,    -1,   223,    -1,   225,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,   111,
      -1,    -1,   217,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   226,    -1,   125,   126,   127,   128,   129,    -1,    -1,
     132,    -1,    -1,   135,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
     182,    -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,   218,    -1,     3,     4,
      -1,   223,    -1,   225,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,   111,    -1,    -1,   217,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   226,    -1,
     125,   126,   127,   128,   129,    -1,    -1,   132,    -1,    -1,
     135,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   182,    -1,    -1,
      -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,   218,    -1,     3,     4,    -1,   223,    -1,
     225,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,   111,    -1,    -1,   217,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   226,    -1,   125,   126,   127,
     128,   129,    -1,    -1,   132,    -1,    -1,   135,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,   182,    -1,    -1,    -1,   186,   187,
     188,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
     218,    -1,     3,     4,    -1,   223,    -1,   225,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
     111,    -1,    -1,   217,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   226,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   132,    -1,    -1,   135,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,   182,    -1,    -1,    -1,   186,   187,   188,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,   218,    -1,     3,
       4,    -1,   223,    -1,   225,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,   111,    -1,    -1,
     217,    -1,    -1,    -1,   118,   119,   120,   121,   122,   226,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,    -1,
      -1,   135,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,   218,    -1,     3,     4,    -1,   223,
      -1,   225,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    53,    54,    55,    56,
     217,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,
       5,    -1,    -1,    80,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,   226,   182,    -1,    -1,    -1,   186,
     187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   178,   179,   180,   181,   182,   226,    -1,
      -1,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,     3,
       4,    -1,    -1,   218,    -1,     9,    10,    11,   223,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,   111,    -1,    -1,
     217,    -1,    -1,    -1,   118,   119,   120,   121,   122,   226,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,    -1,
      -1,   135,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,    -1,
      -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,
       3,     4,    -1,    -1,   218,    -1,     9,    10,    11,   223,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      53,    54,    55,    56,   217,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,     3,     4,    72,
      73,    74,    -1,     9,    10,    11,    -1,    80,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    53,    54,    55,
      56,   217,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,    -1,    -1,   178,    -1,    -1,    -1,   182,
      -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
     223,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,   178,    -1,    -1,    -1,   182,    -1,   226,    -1,
     186,   187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,   218,     3,     4,   221,    -1,   223,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    53,    54,    55,    56,   217,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
       3,     4,    72,    73,    74,    -1,     9,    10,    11,    -1,
      80,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      53,    54,    55,    56,   217,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,   178,    -1,
      -1,    -1,   182,    -1,    -1,    -1,   186,   187,   188,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,   223,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,   178,    -1,    -1,    -1,   182,
      -1,   226,    -1,   186,   187,   188,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,   218,     3,     4,   221,     6,
     223,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    53,    54,    55,    56,
     217,    -1,    -1,    -1,    61,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,
      -1,     6,    -1,    80,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    53,    54,
      55,    56,   217,    -1,    -1,    -1,    61,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,    -1,   221,
      -1,   178,   224,    -1,    -1,   182,    -1,    -1,    -1,   186,
     187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,   223,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,    -1,    -1,
      -1,    -1,   224,   178,    -1,    -1,    -1,   182,    -1,    -1,
      -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,     3,
       4,    -1,    -1,   218,    -1,     9,    10,    11,   223,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,   155,
     156,   157,   186,   187,   188,   189,   190,    -1,    -1,    -1,
     194,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,
      -1,    62,    63,    64,   218,    -1,    -1,    68,    69,   223,
      71,    -1,    -1,    -1,    75,    76,    -1,    78,    79,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,   149,     4,
      -1,    -1,    -1,   154,   155,   156,   157,    12,    13,   160,
      -1,   162,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,    -1,    -1,    42,    43,    -1,
      -1,   192,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    98,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,    -1,   141,   142,   143,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,    -1,    -1,   160,    -1,   162,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,    -1,   224,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,   221,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,   221,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,   221,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     221,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,   221,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,   221,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,   221,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
     219,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,   219,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   219,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,   219,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,   219,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
     219,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,   219,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   219,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,   219,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,   219,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
     219,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,   219,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   219,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,   219,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,   219,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
     219,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,   219,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   219,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,   219,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,    -1,   219,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,   219,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
     219,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
      -1,   219,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,    -1,   219,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,   219,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   229,   230,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   141,   142,   143,   149,   154,   155,   156,   157,   160,
     162,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   183,   184,   185,   192,   194,
     231,   233,   234,   254,   273,   274,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   301,   303,   304,   310,   311,
     312,   313,   331,   332,     3,     4,     5,     9,    10,    11,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    65,    66,    67,    70,    72,    73,    74,    80,    81,
     171,   178,   179,   180,   181,   182,   186,   187,   188,   189,
     190,   191,   193,   208,   209,   213,   218,   220,   222,   223,
     225,   227,   252,   314,   315,   327,   328,   331,   332,    13,
      90,   218,   218,     6,   225,     6,     6,     6,     6,   218,
       6,     6,   220,   220,   218,   220,   252,   252,   218,   225,
     218,   218,     4,   218,   225,   218,   218,     4,   225,   218,
     218,   218,   218,    99,    90,    90,     6,   225,    84,    87,
      90,   218,   218,    90,    90,    87,    90,    92,    92,    84,
      87,    90,    92,    87,    90,    92,    87,    90,   218,    87,
     160,   176,   177,   225,   208,   209,   218,   225,   317,   318,
     317,   225,    84,    87,    90,   225,   317,     4,    84,    88,
      94,    95,    96,    97,   107,    90,    92,    90,    87,     4,
     171,   225,   331,   332,     4,     6,    84,    87,    90,    87,
      90,     4,     4,     4,     4,     5,    37,    38,    39,    40,
      41,    84,    87,    90,    92,   111,   209,   218,   225,   274,
     285,   301,   303,   314,   320,   321,   322,   331,   332,     4,
     218,   218,   218,     4,   225,   324,   332,     4,   218,   218,
     218,     6,     6,   220,     4,   328,   332,   218,     4,   328,
       5,   225,     5,   225,     4,   314,   331,   220,   218,   225,
       6,   218,   225,   218,   220,   227,   252,     7,   195,   196,
     197,   198,   215,   216,   250,   251,     4,   218,   220,   222,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   218,   218,   218,   252,   252,
     252,   252,   218,   252,   252,   252,   252,   252,   252,   218,
     252,   252,   252,     7,   218,   218,   218,   252,   252,   218,
     218,   220,   314,   314,   314,   219,   314,   221,   314,     4,
     160,   161,   332,     4,   274,   275,   276,   225,   225,     6,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   217,   225,     6,   218,   220,   251,
       6,   314,     4,   327,   328,   331,   332,   327,   314,   327,
     330,   256,   261,   328,   332,   314,   209,   314,   322,   323,
     314,   314,   218,   314,   323,   314,   314,   218,   323,   314,
     314,   314,   314,   320,   218,   225,   323,   321,   321,   321,
     327,   314,   218,   218,   321,   321,   321,   218,   218,   218,
     218,   218,   218,   320,   218,   320,   218,   320,   225,   225,
     314,     4,   320,   324,   225,   225,   317,   317,   317,   314,
     314,   208,   209,   225,   225,   317,   225,   225,   225,   208,
     209,   218,   276,   317,   225,   218,   225,   218,   218,   218,
     218,   218,   218,   218,   321,   321,   320,   218,     4,   220,
     220,   276,     6,     6,   225,   225,   225,   321,   321,   220,
     220,   220,   218,   220,   222,   252,   218,   220,   252,   252,
     252,   252,     5,   163,   225,     5,   163,     5,   163,     5,
     163,    84,    87,    90,    92,   225,   314,   322,   314,   226,
     323,     8,   210,     6,   218,   220,   252,     6,   314,   314,
     314,   222,   314,   225,   163,   314,   314,   314,   314,     6,
       6,   225,     6,   276,     6,   276,   218,   220,   225,   218,
     220,   327,   314,   276,   320,   320,   219,   314,   221,   314,
     225,   225,   328,   320,     6,   220,   314,   314,     4,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   330,   327,   330,   327,   327,   327,   327,   327,   327,
     327,   320,   327,   327,   314,   327,   327,   327,   330,   327,
     314,   328,   314,   327,   327,   327,   327,   327,   332,   328,
     332,     7,   198,   250,   219,     7,   198,   250,   221,     7,
     250,   251,   222,     7,   252,   226,    84,    87,    90,    92,
     273,   314,   323,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   235,   314,
     314,     6,   218,   220,   222,   219,   224,   218,   220,   219,
     224,   224,   219,   224,   221,   224,   255,   221,   255,   224,
     224,   219,   210,   224,   226,   219,   219,   314,   219,   226,
     219,   219,   314,   226,   219,   219,   219,   219,     7,   314,
     314,   226,     6,     6,     6,   219,   219,   314,   314,     7,
       7,   307,   307,   314,   267,   314,   328,   268,   314,   328,
     269,   314,   328,   270,   314,   328,   314,     6,   314,     6,
     314,     6,   323,   323,   225,   219,     6,   225,   276,   276,
     224,   224,   224,   317,   317,   275,   275,   224,   314,   314,
     314,   314,   289,   224,   276,   314,   314,   314,   314,   314,
     314,   314,   314,   314,     7,   308,     6,     7,   314,     6,
     314,   314,   226,   323,   323,   323,     6,     6,   314,   314,
     314,   314,   314,     4,   219,   221,   225,   253,   225,   314,
     322,   225,   322,   332,   314,   314,   327,   314,    62,   314,
      62,    62,    62,     5,   225,     5,   225,     5,   225,     5,
     225,   323,   219,   226,   314,   225,   314,   322,   314,   314,
     225,   253,   219,   219,   219,   160,   224,   276,   225,     8,
     219,   219,   221,   323,   226,   226,   276,   221,   219,   133,
     302,   219,   224,   226,     7,   198,   250,   219,     7,   198,
     250,   221,   314,   323,     6,     6,   314,   219,   221,   251,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   224,   253,   253,   253,   253,   253,   253,   253,   224,
     224,   224,   253,   224,   253,   253,   219,   219,   224,   253,
     253,   224,   253,   224,   224,   224,   224,   253,   253,   253,
     219,   253,   316,   329,     6,   224,   224,   219,   224,   253,
     224,   253,   219,   219,   221,    44,    44,   320,     7,   250,
     251,    44,    44,   320,   222,   250,   251,   328,   314,     6,
       4,     4,   225,   325,   253,   225,   225,   225,   225,   226,
     226,     8,     4,   150,   151,   152,   153,   226,   238,   242,
     245,   247,   248,   219,   221,   314,   314,     4,     6,   205,
     232,   323,   314,   314,     6,   323,   314,     6,   327,     6,
     332,     6,   327,   314,   328,     7,   314,   322,   163,     7,
       7,   219,     7,   163,     7,     7,   219,   163,     7,     7,
       7,     7,   314,   219,   226,   225,     6,     7,   219,   219,
     314,   320,     4,   306,     6,   219,   219,   224,   219,   224,
     219,   224,   219,   224,   219,   219,   219,   226,   226,   323,
     222,   276,   226,   226,   317,   314,   314,   226,   226,   314,
     317,   224,   224,   224,   114,   130,   138,   139,   140,   144,
     145,   146,   147,   299,   300,   317,   226,   286,   219,   226,
     219,   219,   219,   219,   219,   219,   219,   314,     6,   314,
     219,   221,   221,   226,   226,   226,   221,   221,   224,   219,
     221,   323,   323,   219,   323,   221,   221,   224,   224,   253,
     224,   225,   226,   225,   225,   225,   323,   323,   323,   323,
     226,     8,   323,   219,   221,   323,     7,     7,     7,   222,
     314,   226,   314,   314,     7,   222,   226,   226,     7,     6,
     314,   226,   225,   320,     6,    44,    44,   320,   250,   251,
      44,    44,   320,   250,   251,   226,   226,   221,   251,   222,
     251,   327,   314,   314,   314,   314,   323,   327,   314,   320,
     327,   327,   327,   263,   265,   314,   327,   327,   314,   252,
     252,     6,   314,     6,   252,   252,     6,     4,   160,   161,
     314,     6,     6,     6,     7,   220,   324,   326,     6,   323,
     323,   323,   323,   253,   314,   239,   218,   218,   225,   249,
       6,   251,   251,   219,   221,   205,   327,   219,   219,   221,
     219,   224,     7,   218,   220,   253,   253,   317,    90,    92,
     320,   320,     7,   320,    90,    92,   320,   320,     7,    92,
     320,   320,   320,   320,     6,     7,     7,   323,   225,     7,
       7,   114,   305,     6,     7,   250,   314,   250,   314,   250,
     314,   250,   314,     7,     7,     7,     7,     7,   226,     4,
     226,   224,   224,   224,   226,   226,   317,   317,   317,     4,
       6,   314,   225,     6,   218,     6,   148,     6,   148,     6,
     148,     6,   148,   226,   300,   224,   299,     7,     6,     7,
       7,     7,     7,     7,     7,     7,     6,   225,     6,     6,
       6,    90,     7,     6,     6,   314,   222,   226,   226,   226,
     314,   314,   314,   314,   314,   314,   314,   226,   226,   226,
     226,   314,   226,   226,   320,   320,   320,     4,   224,     8,
       8,   219,     4,     4,   224,   225,     6,   225,   320,   226,
     252,   252,     6,   314,     6,   252,   252,     6,   314,     6,
     253,     6,     4,     6,   253,   253,   253,   253,   253,   224,
     224,   253,   219,   253,   253,   224,   224,   253,   264,   224,
     253,   266,   219,   219,   253,   253,   253,   330,   330,     6,
     253,   330,   330,     7,   250,   251,   222,     7,     6,   324,
     314,   224,   226,   226,   226,   226,   226,   250,   218,   314,
     314,   319,   320,   225,   222,     6,     6,   232,     6,   314,
     225,   314,   328,   219,   221,     6,     6,     6,   225,   225,
     107,   272,   272,   320,     6,   225,   225,     6,     6,   320,
     225,     6,     6,     6,     6,     5,   320,   226,   319,   320,
     320,     4,     6,   320,   320,   320,   320,   320,   320,   320,
     320,   225,   225,     7,     6,     7,   314,   314,   314,   225,
     225,   224,   226,   224,   226,   224,   226,   220,     6,   314,
     320,   314,     6,     6,     6,     6,   314,   317,   226,     5,
     320,   225,   225,   225,   225,   225,   225,   225,   320,   323,
     225,   314,   221,     4,   253,   219,   221,   224,   224,   224,
     224,   224,   224,   224,   253,     6,     6,   159,   314,   314,
     314,     6,     6,     7,   328,   276,   276,   224,     6,   253,
     330,   330,     6,   253,   330,   330,     6,   250,   251,   327,
     314,   327,     4,     4,   175,     6,   253,   253,     6,   253,
     253,   328,   314,     6,     4,   325,     6,   221,   324,     6,
       6,     6,     6,   320,   236,   314,   224,   224,   224,   226,
     237,   314,     4,   327,   224,   320,   328,     7,     7,   314,
     314,   317,     6,     6,     6,   314,   314,     6,   314,     5,
       6,   225,   226,     6,   163,   271,   314,     6,     6,     6,
       6,     6,     6,     4,     6,     6,   323,   323,   314,   314,
     328,   226,   219,   224,   226,   275,   275,   317,     6,   290,
     317,     6,   291,   317,     6,   292,   314,   226,   224,   219,
     226,   224,     6,     6,   319,   317,   317,   317,   317,   317,
     209,   317,     6,   226,   314,     6,     6,   314,   314,   314,
     314,   314,   314,   314,   320,   224,   226,     8,   226,   219,
     225,   314,   328,   224,   302,   302,   320,     6,   253,   253,
       6,   253,   253,   320,   219,   253,   253,   225,   320,   328,
     225,   314,   328,   328,     6,     6,     6,     6,     6,     6,
       7,     6,   222,     6,   219,   224,   314,   314,   320,   225,
     224,   226,     6,   314,   257,   260,   225,   225,   226,   226,
     226,   226,   226,     5,   319,     6,    88,     6,   225,   226,
     226,   225,     6,     6,   225,   314,   226,   226,   224,   225,
     224,   225,   224,   225,   221,     6,   320,     7,   225,   314,
     226,   224,   224,   224,   224,   224,   224,     6,   226,   253,
     253,   224,   224,   224,   224,   224,   158,   314,   314,   323,
       6,     6,   328,   226,   226,   226,     6,     6,     6,     6,
       6,   262,   314,   322,   330,   324,   161,   240,   314,   224,
     224,   319,   314,     6,   224,   263,   265,   320,   320,     6,
       6,     6,     6,     6,     6,   226,   225,   319,   118,   119,
     124,   309,   118,   119,   309,   323,   275,   224,   226,   314,
     317,   299,   314,   317,   299,   314,   317,   299,     6,   224,
     226,   320,   276,   226,     6,   323,   317,   317,   317,   317,
     317,   314,   314,   314,   314,   314,   314,   226,   226,   226,
     219,   225,     6,   224,   226,     7,     7,   226,     6,   225,
     314,   314,   226,   314,   226,   226,   259,   258,   225,   314,
     226,   225,   317,   320,     6,   225,   317,     6,   226,   226,
     314,   226,   224,   226,   226,   224,   226,   226,   224,   226,
     320,     6,   114,   226,   287,   225,   226,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,     6,     6,     6,
     276,   314,   328,   332,   237,   219,   224,     6,   225,   224,
     263,   263,   314,   226,     6,   317,     6,   317,     6,     6,
     226,     6,   293,   314,     6,     6,   294,   314,     6,     6,
     295,   314,     6,   226,   314,   299,   276,     6,   323,   323,
     323,   323,   317,   323,   314,   314,   314,   314,   314,   302,
       7,   218,   226,   243,   314,   319,   314,   226,   226,   224,
     224,   224,   225,   226,   225,   226,   225,   226,     6,     6,
     226,   226,   288,   226,   226,   226,   226,   224,   226,   224,
     224,   224,   224,   224,   226,   328,   219,     6,   225,   219,
     226,   226,   314,   317,   317,   299,     6,   296,   299,     6,
     297,   299,     6,   298,   299,     6,     6,     6,     6,   323,
       6,   314,   314,   314,   314,   314,     6,   241,   327,   246,
     225,     6,   226,   224,   224,   226,   225,   226,   225,   226,
     225,   226,   226,   253,   224,   224,   224,   224,   224,   226,
     225,   319,     6,   314,   314,     6,   299,     6,   299,     6,
     299,     6,   314,   314,   314,   314,   327,     6,   244,   327,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     224,   226,     6,     6,     6,     6,     6,     6,   327,     6
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
#line 210 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 225 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 228 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 229 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 230 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 231 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 235 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 237 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 238 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 239 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 244 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 248 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 255 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 260 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 265 "Gmsh.y"
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

  case 30:
#line 279 "Gmsh.y"
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

  case 31:
#line 292 "Gmsh.y"
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

  case 32:
#line 305 "Gmsh.y"
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

  case 33:
#line 333 "Gmsh.y"
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

  case 34:
#line 347 "Gmsh.y"
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

  case 35:
#line 360 "Gmsh.y"
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

  case 36:
#line 373 "Gmsh.y"
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

  case 37:
#line 391 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 43:
#line 405 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 44:
#line 407 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 45:
#line 412 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 46:
#line 414 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 47:
#line 419 "Gmsh.y"
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

  case 48:
#line 523 "Gmsh.y"
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

  case 49:
#line 533 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 50:
#line 542 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 549 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 559 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 53:
#line 568 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 54:
#line 577 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 584 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 594 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 57:
#line 602 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 58:
#line 612 "Gmsh.y"
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

  case 59:
#line 631 "Gmsh.y"
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

  case 60:
#line 650 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 61:
#line 656 "Gmsh.y"
    {
    ;}
    break;

  case 62:
#line 663 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 63:
#line 664 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 665 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 65:
#line 666 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 66:
#line 667 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 67:
#line 671 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 672 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 69:
#line 678 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 70:
#line 678 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 71:
#line 679 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 72:
#line 679 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 75:
#line 688 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 76:
#line 693 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 77:
#line 699 "Gmsh.y"
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
        else{
          // list of expressions; this is not recommended (should use [] or ()
          // notation instead)
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

  case 78:
#line 761 "Gmsh.y"
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

  case 79:
#line 778 "Gmsh.y"
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

  case 80:
#line 807 "Gmsh.y"
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

  case 81:
#line 836 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 82:
#line 841 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 846 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 84:
#line 851 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 856 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:
#line 863 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 87:
#line 873 "Gmsh.y"
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

  case 88:
#line 902 "Gmsh.y"
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

  case 89:
#line 931 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 90:
#line 936 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 91:
#line 941 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 92:
#line 946 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 954 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 94:
#line 963 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 95:
#line 969 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 96:
#line 975 "Gmsh.y"
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)] = s;
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 97:
#line 988 "Gmsh.y"
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)] = s;
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 98:
#line 1001 "Gmsh.y"
    {
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (9)].c))){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
          gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (9)].c));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 99:
#line 1016 "Gmsh.y"
    {
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (9)].c))){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
          gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (9)].c));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 100:
#line 1033 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 101:
#line 1039 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 102:
#line 1045 "Gmsh.y"
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)] = s;
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 103:
#line 1058 "Gmsh.y"
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)] = s;
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 104:
#line 1071 "Gmsh.y"
    {
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (9)].c))){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
          gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (9)].c));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 105:
#line 1086 "Gmsh.y"
    {
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (9)].c))){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
          gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (9)].c));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 106:
#line 1103 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 107:
#line 1109 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 108:
#line 1118 "Gmsh.y"
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

  case 109:
#line 1136 "Gmsh.y"
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

  case 110:
#line 1154 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 111:
#line 1163 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 112:
#line 1175 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 113:
#line 1180 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 114:
#line 1188 "Gmsh.y"
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

  case 115:
#line 1208 "Gmsh.y"
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

  case 116:
#line 1231 "Gmsh.y"
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

  case 117:
#line 1242 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 118:
#line 1250 "Gmsh.y"
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

  case 119:
#line 1272 "Gmsh.y"
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

  case 120:
#line 1295 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  if (option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	      double id;
	      List_Read((yyvsp[(9) - (11)].l), i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	      double id;
	      List_Read((yyvsp[(9) - (11)].l), i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
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

  case 121:
#line 1333 "Gmsh.y"
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

  case 122:
#line 1354 "Gmsh.y"
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

  case 123:
#line 1366 "Gmsh.y"
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

  case 127:
#line 1384 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 128:
#line 1393 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 129:
#line 1402 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 130:
#line 1404 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(6) - (9)].l)) != 1)
	yymsg(1, "List notation should be used to define list '%s[]'", (yyvsp[(3) - (9)].c));
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[(6) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(6) - (9)].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 131:
#line 1422 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1424 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (11)].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (11)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (11)].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (11)].c));
      Free((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 133:
#line 1440 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 134:
#line 1442 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (11)].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (11)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (11)].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (11)].c));
      Free((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 135:
#line 1458 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 136:
#line 1467 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 137:
#line 1469 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 139:
#line 1483 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 140:
#line 1491 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 141:
#line 1497 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 142:
#line 1502 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      int n = List_Nbr((yyvsp[(1) - (5)].l));
      if(!gmsh_yystringsymbols.count((yyvsp[(3) - (5)].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(3) - (5)].c));
      }
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[(3) - (5)].c)]);
        int m = s.size();
        if(n == m){
          for(int i = 0; i < n; i++){
            double d;
            List_Read((yyvsp[(1) - (5)].l), i, &d);
            doubleXstring v = {d, strsave((char*)s[i].c_str())};
            List_Add((yyval.l), &v);
          }
        }
        else{
          yymsg(0, "Size mismatch in enumeration: %d != %d", n, m);
        }
      }
      List_Delete((yyvsp[(1) - (5)].l));
    ;}
    break;

  case 145:
#line 1533 "Gmsh.y"
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

  case 146:
#line 1544 "Gmsh.y"
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

  case 147:
#line 1559 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 150:
#line 1575 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 151:
#line 1583 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1592 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 153:
#line 1600 "Gmsh.y"
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

  case 154:
#line 1618 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 155:
#line 1622 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 156:
#line 1628 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 157:
#line 1636 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1640 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 159:
#line 1646 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1654 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 161:
#line 1658 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 162:
#line 1664 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 163:
#line 1672 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 164:
#line 1676 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 165:
#line 1682 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 166:
#line 1690 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 167:
#line 1694 "Gmsh.y"
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

  case 168:
#line 1706 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 169:
#line 1710 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 170:
#line 1718 "Gmsh.y"
    {
      // FIXME: when changing to OpenCASCADE, get maxTag for all dimensions
      // and add that info in OCC_Internals - same in the other direction
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 171:
#line 1728 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
        yymsg(0, "Point %d already exists", num);
      }
      else{
        double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
        double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
        double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          GModel::current()->getOCCInternals()->addVertex(num, x, y, z);
        }
        else{
          double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
          if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
          Vertex *v;
          if(!myGmshSurface)
            v = Create_Vertex(num, x, y, z, lc, 1.0);
          else
            v = Create_Vertex(num, x, y, myGmshSurface, lc);
          Tree_Add(GModel::current()->getGEOInternals()->Points, &v);
        }
        AddToTemporaryBoundingBox(x, y, z);
      }
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 172:
#line 1756 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exist", num);
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
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalPoint(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1799 "Gmsh.y"
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
    ;}
    break;

  case 174:
#line 1822 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          if(List_Nbr((yyvsp[(6) - (7)].l)) == 2){
            double d[3];
            List_Read((yyvsp[(6) - (7)].l), 0, &d[0]); List_Read((yyvsp[(6) - (7)].l), 1, &d[1]);
            GModel::current()->getOCCInternals()->addLine(num, (int)d[0], (int)d[1]);
          }
          else
            yymsg(0, "OpenCASCADE line only takes 2 points");
        }
        else{
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
          Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
                                  -1, -1, 0., 1.);
          Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
          CreateReversedCurve(c);
          List_Delete(temp);
        }
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 175:
#line 1851 "Gmsh.y"
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

  case 176:
#line 1872 "Gmsh.y"
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

  case 177:
#line 1890 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          if(List_Nbr((yyvsp[(6) - (8)].l)) == 3){
            double d[3];
            List_Read((yyvsp[(6) - (8)].l), 0, &d[0]); List_Read((yyvsp[(6) - (8)].l), 1, &d[1]); List_Read((yyvsp[(6) - (8)].l), 2, &d[2]);
            GModel::current()->getOCCInternals()->addCircleArc
              (num, (int)d[0], (int)d[1], (int)d[2]);
          }
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
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 178:
#line 1930 "Gmsh.y"
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

  case 179:
#line 1960 "Gmsh.y"
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

  case 180:
#line 1978 "Gmsh.y"
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

  case 181:
#line 1997 "Gmsh.y"
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

  case 182:
#line 2023 "Gmsh.y"
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

  case 183:
#line 2042 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 184:
#line 2047 "Gmsh.y"
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

  case 185:
#line 2065 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exist", num);
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
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalLine(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2111 "Gmsh.y"
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

  case 187:
#line 2129 "Gmsh.y"
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

  case 188:
#line 2168 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2174 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2180 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2187 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 4){ // solid sphere (volume)
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x; List_Read((yyvsp[(6) - (7)].l), 0, &x);
          double y; List_Read((yyvsp[(6) - (7)].l), 1, &y);
          double z; List_Read((yyvsp[(6) - (7)].l), 2, &z);
          double r; List_Read((yyvsp[(6) - (7)].l), 3, &r);
          GModel::current()->getOCCInternals()->addSphere(num, x, y, z, r);
        }
        else{
          yymsg(0, "Sphere only available with OpenCASCADE factory");
        }
        (yyval.s).Type = MSH_VOLUME;
      }
      else{
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
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2228 "Gmsh.y"
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2254 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 6){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x1; List_Read((yyvsp[(6) - (7)].l), 0, &x1);
          double y1; List_Read((yyvsp[(6) - (7)].l), 1, &y1);
          double z1; List_Read((yyvsp[(6) - (7)].l), 2, &z1);
          double x2; List_Read((yyvsp[(6) - (7)].l), 3, &x2);
          double y2; List_Read((yyvsp[(6) - (7)].l), 4, &y2);
          double z2; List_Read((yyvsp[(6) - (7)].l), 5, &z2);
          GModel::current()->getOCCInternals()->addBlock(num, x1, y1, z1, x2, y2, z2);
        }
        else{
          yymsg(0, "Block only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Block has to be defined using 2 points");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 194:
#line 2278 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 7){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x1; List_Read((yyvsp[(6) - (7)].l), 0, &x1);
          double y1; List_Read((yyvsp[(6) - (7)].l), 1, &y1);
          double z1; List_Read((yyvsp[(6) - (7)].l), 2, &z1);
          double x2; List_Read((yyvsp[(6) - (7)].l), 3, &x2);
          double y2; List_Read((yyvsp[(6) - (7)].l), 4, &y2);
          double z2; List_Read((yyvsp[(6) - (7)].l), 5, &z2);
          double r; List_Read((yyvsp[(6) - (7)].l), 6, &r);
          GModel::current()->getOCCInternals()->addCylinder(num, x1, y1, z1, x2, y2, z2, r);
        }
        else{
          yymsg(0, "Cylinder only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Cylinder has to be defined using 2 points and a radius");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 195:
#line 2303 "Gmsh.y"
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

  case 196:
#line 2320 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 197:
#line 2324 "Gmsh.y"
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
	setSurfaceGeneratrices(s, (List_T*) 0);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 198:
#line 2344 "Gmsh.y"
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

  case 199:
#line 2377 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exist", num);
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
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalSurface(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 200:
#line 2424 "Gmsh.y"
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

  case 201:
#line 2442 "Gmsh.y"
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

  case 202:
#line 2459 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<std::vector<int> > edges;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
            List_T *l; List_Read((yyvsp[(7) - (9)].l), i, &l);
            std::vector<int> v;
            for(int j = 0; j < List_Nbr(l); j++){
              double d = 0; List_Read(l, j, &d); v.push_back(d);
            }
            edges.push_back(v);
          }
          GModel::current()->getOCCInternals()->addThruSections(num, edges);
        }
        else{
          yymsg(0, "ThruSections only available with OpenCASCADE factory");
        }
      }
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(7) - (9)].l), i));
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 203:
#line 2488 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 3 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 204:
#line 2492 "Gmsh.y"
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

  case 205:
#line 2508 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exist", num);
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
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalVolume(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 206:
#line 2556 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Translate");
      }
      else{
        TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 207:
#line 2566 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Rotate");
      }
      else{
        RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 208:
#line 2576 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Symmetry");
      }
      else{
        SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 209:
#line 2586 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Dilate");
      }
      else{
        DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 210:
#line 2596 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Dilate");
      }
      else{
        DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 211:
#line 2606 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
            Msg::Error("TODO OCC Copy");
          }
          else{
            CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          }
          List_Add((yyval.l), &TheShape);
        }
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "Boundary") || !strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary")){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> in[4], out[4];
          Shape TheShape;
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
            List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
            int dim = TheShape.Type / 100 - 1;
            if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
          }
          GModel::current()->getOCCInternals()->getBoundary
            (in, out, !strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary") ? true : false);
          for(int dim = 0; dim < 4; dim++){
            TheShape.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            for(unsigned int i = 0; i < out[dim].size(); i++){
              TheShape.Num = out[dim][i];
              List_Add((yyval.l), &TheShape);
            }
          }
        }
        else{
          BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), !strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary") ? true : false);
        }
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 212:
#line 2653 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect Line not available with OpenCASCADE");
      }
      else{
        IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      }
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 213:
#line 2664 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE");
      }
      else{
        List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
        SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
        List_Delete(tmp);
      }
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 214:
#line 2679 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 215:
#line 2680 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2685 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 217:
#line 2689 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 218:
#line 2693 "Gmsh.y"
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
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_POINT_FROM_GMODEL;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown point %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 219:
#line 2722 "Gmsh.y"
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
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_SEGM_FROM_GMODEL;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown curve %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 220:
#line 2751 "Gmsh.y"
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
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_SURF_FROM_GMODEL;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown surface %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 221:
#line 2780 "Gmsh.y"
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
	  else{
            if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
              TheShape.Type = MSH_VOLUME_FROM_GMODEL;
              List_Add((yyval.l), &TheShape);
            }
            else
              yymsg(1, "Unknown volume %d", TheShape.Num);
          }
	}
      }
    ;}
    break;

  case 222:
#line 2814 "Gmsh.y"
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
      List_Delete((yyvsp[(7) - (8)].l));
#endif
    ;}
    break;

  case 223:
#line 2836 "Gmsh.y"
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

  case 224:
#line 2863 "Gmsh.y"
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
      List_Delete((yyvsp[(12) - (14)].l));
#endif
    ;}
    break;

  case 225:
#line 2885 "Gmsh.y"
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
      List_Delete((yyvsp[(14) - (16)].l));
#endif
    ;}
    break;

  case 226:
#line 2907 "Gmsh.y"
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
      List_Delete((yyvsp[(10) - (12)].l));
#endif
    ;}
    break;

  case 227:
#line 2929 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 1){
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
      else if(List_Nbr((yyvsp[(12) - (14)].l)) == 2){
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
      else if(List_Nbr((yyvsp[(12) - (14)].l)) == 3){
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
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
      List_Delete((yyvsp[(12) - (14)].l));
#endif
    ;}
    break;

  case 228:
#line 2985 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 1){
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
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
      List_Delete((yyvsp[(12) - (14)].l));
#endif
    ;}
    break;

  case 229:
#line 3009 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 3){
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
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
      List_Delete((yyvsp[(12) - (14)].l));
#endif
    ;}
    break;

  case 230:
#line 3034 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 5){
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
      List_Delete((yyvsp[(12) - (14)].l));
#endif
    ;}
    break;

  case 231:
#line 3059 "Gmsh.y"
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
      List_Delete((yyvsp[(7) - (8)].l));
#endif
    ;}
    break;

  case 232:
#line 3172 "Gmsh.y"
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

  case 233:
#line 3191 "Gmsh.y"
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

  case 234:
#line 3234 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          Msg::Error("TODO OCC Delete");
        }
        else{
          DeleteShape(TheShape.Type, TheShape.Num);
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 235:
#line 3248 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 236:
#line 3254 "Gmsh.y"
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

  case 237:
#line 3269 "Gmsh.y"
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
    ;}
    break;

  case 238:
#line 3297 "Gmsh.y"
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

  case 239:
#line 3314 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 3323 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 241:
#line 3337 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3351 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 243:
#line 3357 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 244:
#line 3363 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 245:
#line 3372 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 246:
#line 3381 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 247:
#line 3390 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 248:
#line 3404 "Gmsh.y"
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
        // sync model with new DB here, so that if we e.g. import a STEP file,
        // we have the correct entity tags and the numberings don't clash
	GModel::current()->importGEOInternals();
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "OptimizeMesh")){
        GModel::current()->optimizeMesh((yyvsp[(2) - (3)].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3466 "Gmsh.y"
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
    ;}
    break;

  case 250:
#line 3484 "Gmsh.y"
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

  case 251:
#line 3501 "Gmsh.y"
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

  case 252:
#line 3516 "Gmsh.y"
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetOrder")){
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "PartitionMesh")){
        GModel::current()->partitionMesh((yyvsp[(2) - (3)].d));
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 253:
#line 3545 "Gmsh.y"
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

  case 254:
#line 3557 "Gmsh.y"
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

  case 255:
#line 3581 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 256:
#line 3585 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 257:
#line 3590 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 258:
#line 3598 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 259:
#line 3603 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 260:
#line 3609 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 261:
#line 3614 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 262:
#line 3620 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 263:
#line 3628 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 264:
#line 3632 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 265:
#line 3636 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 266:
#line 3642 "Gmsh.y"
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
          if(List_Nbr((yyvsp[(9) - (16)].l)) != (int)f.size()){
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

  case 267:
#line 3701 "Gmsh.y"
    {
#if defined(HAVE_POPPLER)
       std::vector<int> is;
       for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
	 double d;
	 List_Read((yyvsp[(4) - (11)].l), i, &d);
	 is.push_back ((int) d);
       }
       gmshPopplerWrapper::instance()->setMacroForPages(is, (yyvsp[(7) - (11)].c), (yyvsp[(9) - (11)].c) );
#endif
     ;}
    break;

  case 268:
#line 3717 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
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
    ;}
    break;

  case 269:
#line 3734 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
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
    ;}
    break;

  case 270:
#line 3751 "Gmsh.y"
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
      Free((yyvsp[(2) - (8)].c));
    ;}
    break;

  case 271:
#line 3773 "Gmsh.y"
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
      Free((yyvsp[(2) - (10)].c));
    ;}
    break;

  case 272:
#line 3795 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
        std::string name = LoopControlVariablesNameTab[ImbricatedLoop - 1];
        if(name.size()){
          if(!gmsh_yysymbols.count(name))
            yymsg(0, "Unknown loop variable '%s'", name.c_str());
          else{
            gmsh_yysymbol &s(gmsh_yysymbols[name]);
            if(!s.list && s.value.size()){
              s.value[0] += step;
              LoopControlVariablesTab[ImbricatedLoop - 1][0] = s.value[0];
            }
            else
              yymsg(0, "Bad loop variable %s", name.c_str());
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
    ;}
    break;

  case 273:
#line 3830 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 274:
#line 3838 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 275:
#line 3846 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 276:
#line 3852 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 277:
#line 3859 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 278:
#line 3866 "Gmsh.y"
    {
      ImbricatedTest++;
      if(ImbricatedTest > MAX_RECUR_TESTS-1){
	yymsg(0, "Reached maximum number of imbricated tests");
        ImbricatedTest = MAX_RECUR_TESTS-1;
      }

      if((yyvsp[(3) - (4)].d)){
        // Current test is true
        statusImbricatedTests[ImbricatedTest] = 1;
      }
      else{
        statusImbricatedTests[ImbricatedTest] = 0;
        // Go after the next ElseIf or Else or EndIf
        int type_until2 = 0;
        skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
        if(!type_until2) ImbricatedTest--; // EndIf reached
      }
    ;}
    break;

  case 279:
#line 3886 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip_until("If", "EndIf");
          ImbricatedTest--;
        }
        else{
          // Previous test(s) (If and ElseIf) not yet true
          if((yyvsp[(3) - (4)].d)){
            statusImbricatedTests[ImbricatedTest] = 1;
          }
          else{
            // Current test still not true: statusImbricatedTests[ImbricatedTest] = 0;
            // Go after the next ElseIf or Else or EndIf
            int type_until2 = 0;
            skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
            if(!type_until2) ImbricatedTest--;
          }
        }
      }
      else{
	yymsg(0, "Orphan ElseIf");
      }
    ;}
    break;

  case 280:
#line 3912 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          skip_until("If", "EndIf");
          ImbricatedTest--;
        }
      }
      else{
	yymsg(0, "Orphan Else");
      }
    ;}
    break;

  case 281:
#line 3924 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 282:
#line 3936 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 283:
#line 3944 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 284:
#line 3952 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 285:
#line 3960 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3966 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 287:
#line 3974 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 288:
#line 3980 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 289:
#line 3988 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3994 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 291:
#line 4002 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 4008 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 293:
#line 4016 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 294:
#line 4023 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 295:
#line 4030 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 296:
#line 4037 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 297:
#line 4044 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 298:
#line 4051 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 299:
#line 4058 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 300:
#line 4065 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 301:
#line 4072 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4079 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 303:
#line 4085 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 304:
#line 4092 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 4098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 306:
#line 4105 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 4111 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 308:
#line 4118 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4131 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4137 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4144 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4150 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4157 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4170 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4183 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4189 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4200 "Gmsh.y"
    {
    ;}
    break;

  case 321:
#line 4203 "Gmsh.y"
    {
    ;}
    break;

  case 322:
#line 4209 "Gmsh.y"
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

  case 323:
#line 4221 "Gmsh.y"
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

  case 324:
#line 4241 "Gmsh.y"
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

  case 325:
#line 4265 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 326:
#line 4269 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 327:
#line 4273 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 328:
#line 4277 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 329:
#line 4281 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 330:
#line 4285 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 331:
#line 4291 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 332:
#line 4297 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 333:
#line 4301 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 334:
#line 4305 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 335:
#line 4309 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 336:
#line 4313 "Gmsh.y"
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

  case 337:
#line 4332 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 338:
#line 4344 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 339:
#line 4345 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 340:
#line 4346 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 341:
#line 4347 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 342:
#line 4348 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 343:
#line 4352 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 344:
#line 4353 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 345:
#line 4354 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 346:
#line 4359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(3) - (9)].l), i, &s); shape[3].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (9)].l), i, &s); tool[3].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), shape, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        for(unsigned int i = 0; i < out[3].size(); i++){
          Shape s;
          s.Num = out[3][i];
          s.Type = MSH_VOLUME;
          List_Add((yyval.l), &s);
        }
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 347:
#line 4387 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (14)].l), i, &s); shape[3].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(11) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(11) - (14)].l), i, &s); tool[3].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), shape, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 348:
#line 4407 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 349:
#line 4411 "Gmsh.y"
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

  case 350:
#line 4426 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 351:
#line 4430 "Gmsh.y"
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

  case 352:
#line 4446 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 353:
#line 4450 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 354:
#line 4455 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 355:
#line 4459 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 356:
#line 4465 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 357:
#line 4469 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 358:
#line 4476 "Gmsh.y"
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
          for(int sig = -1; sig <= 1; sig += 2){
            Curve *c = FindCurve(sig * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
              c->typeTransfinite = type * gmsh_sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sig * j);
              if(ge){
                ge->meshAttributes.method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
                ge->meshAttributes.typeTransfinite = type * gmsh_sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sig > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete((yyvsp[(3) - (7)].l));
      }
    ;}
    break;

  case 359:
#line 4532 "Gmsh.y"
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

  case 360:
#line 4602 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 361:
#line 4607 "Gmsh.y"
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

  case 362:
#line 4674 "Gmsh.y"
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
    ;}
    break;

  case 363:
#line 4710 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 364:
#line 4718 "Gmsh.y"
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

  case 365:
#line 4761 "Gmsh.y"
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

  case 366:
#line 4800 "Gmsh.y"
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

  case 367:
#line 4821 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[(10) - (11)].l)) != 0) {
          if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr((yyvsp[(10) - (11)].l)));
          }
          else {
            transfo.resize(List_Nbr((yyvsp[(10) - (11)].l)));
            for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++)
              List_Read((yyvsp[(10) - (11)].l), i, &transfo[i]);
          }
        }
        for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (11)].l), i, &d_master);
          List_Read((yyvsp[(4) - (11)].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          addPeriodicEdge(j_slave, j_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 368:
#line 4853 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
        }
        else {
          std::vector<double> transfo(16,0);
          for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++)
            List_Read((yyvsp[(10) - (11)].l), i, &transfo[i]);
          for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
            double d_master, d_slave;
            List_Read((yyvsp[(8) - (11)].l), i, &d_master);
            List_Read((yyvsp[(4) - (11)].l), i, &d_slave);
            addPeriodicFace(d_slave, d_master, transfo);
          }
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 369:
#line 4880 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (18)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (18)].l), i, &d_master);
          List_Read((yyvsp[(4) - (18)].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    ;}
    break;

  case 370:
#line 4906 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (18)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (18)].l), i, &d_master);
          List_Read((yyvsp[(4) - (18)].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    ;}
    break;

  case 371:
#line 4932 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (12)].l), i, &d_master);
          List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    ;}
    break;

  case 372:
#line 4958 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (12)].l), i, &d_master);
          List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    ;}
    break;

  case 373:
#line 4984 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
          double ds,dm;
          List_Read((yyvsp[(5) - (12)].l),i,&ds);
          List_Read((yyvsp[(10) - (12)].l),i,&dm);
          edgeCounterParts[(int) ds] = (int) dm;
        }
        addPeriodicFace(j_slave, j_master, edgeCounterParts);
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 374:
#line 5005 "Gmsh.y"
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
    ;}
    break;

  case 375:
#line 5033 "Gmsh.y"
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
    ;}
    break;

  case 376:
#line 5061 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedPoints(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iPoint = (int)d;
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(!gv){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              gv = GModel::current()->getVertexByTag(iPoint);
            }
            if(gv)
              gr->addEmbeddedVertex(gv);
            else
              yymsg(0, "Unknown Point %d", iPoint);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 377:
#line 5089 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedCurves(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iLine = (int)d;
            GEdge *ge = GModel::current()->getEdgeByTag(iLine);
            if(!ge){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              ge = GModel::current()->getEdgeByTag(iLine);
            }
            if(ge)
              gr->addEmbeddedEdge(ge);
            else
              yymsg(0, "Unknown Curve %d", iLine);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 378:
#line 5117 "Gmsh.y"
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
    ;}
    break;

  case 379:
#line 5145 "Gmsh.y"
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

  case 380:
#line 5184 "Gmsh.y"
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

  case 381:
#line 5223 "Gmsh.y"
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

  case 382:
#line 5244 "Gmsh.y"
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

  case 383:
#line 5265 "Gmsh.y"
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

  case 384:
#line 5292 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 385:
#line 5296 "Gmsh.y"
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

  case 386:
#line 5306 "Gmsh.y"
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

  case 387:
#line 5340 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 388:
#line 5341 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 389:
#line 5342 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 390:
#line 5347 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 391:
#line 5353 "Gmsh.y"
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

  case 392:
#line 5365 "Gmsh.y"
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

  case 393:
#line 5383 "Gmsh.y"
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

  case 394:
#line 5410 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 395:
#line 5411 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 396:
#line 5412 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 397:
#line 5413 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 398:
#line 5414 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 399:
#line 5415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 400:
#line 5416 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 401:
#line 5417 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 402:
#line 5419 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 403:
#line 5425 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 404:
#line 5426 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 405:
#line 5427 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 406:
#line 5428 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5429 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5430 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5431 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5432 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5433 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5434 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5435 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 414:
#line 5436 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 415:
#line 5437 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 416:
#line 5438 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 417:
#line 5439 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5440 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 419:
#line 5441 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5442 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5443 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5444 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5445 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5446 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 425:
#line 5447 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5448 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5449 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5450 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5451 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 430:
#line 5452 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5453 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 432:
#line 5454 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 433:
#line 5455 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 434:
#line 5456 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 435:
#line 5457 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 436:
#line 5466 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 437:
#line 5467 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 438:
#line 5468 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 439:
#line 5469 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 440:
#line 5470 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 441:
#line 5471 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 442:
#line 5472 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 443:
#line 5473 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 444:
#line 5474 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 445:
#line 5475 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 446:
#line 5476 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 447:
#line 5481 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 448:
#line 5483 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 449:
#line 5489 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 450:
#line 5494 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 451:
#line 5499 "Gmsh.y"
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

  case 452:
#line 5516 "Gmsh.y"
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

  case 453:
#line 5534 "Gmsh.y"
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

  case 454:
#line 5552 "Gmsh.y"
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

  case 455:
#line 5570 "Gmsh.y"
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

  case 456:
#line 5588 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 457:
#line 5593 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 458:
#line 5599 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (4)].c)]);
	(yyval.d) = s.value.size();
      }
      else if(gmsh_yystringsymbols.count((yyvsp[(2) - (4)].c))){
	(yyval.d) = gmsh_yystringsymbols[(yyvsp[(2) - (4)].c)].size();
      }
      else{
        yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 459:
#line 5614 "Gmsh.y"
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
        else{
          (yyval.d) = s.value[0];
          s.value[0] += (yyvsp[(2) - (2)].i);
        }
      }
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 460:
#line 5633 "Gmsh.y"
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
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[(5) - (5)].i);
        }
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 461:
#line 5653 "Gmsh.y"
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
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[(5) - (5)].i);
        }
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 462:
#line 5673 "Gmsh.y"
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
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[(5) - (5)].i);
        }
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 463:
#line 5693 "Gmsh.y"
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
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[(5) - (5)].i);
        }
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 464:
#line 5716 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 465:
#line 5721 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 466:
#line 5726 "Gmsh.y"
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

  case 467:
#line 5736 "Gmsh.y"
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

  case 468:
#line 5746 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 469:
#line 5751 "Gmsh.y"
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (6)].l), i, &d);
        matches += List_Search((yyvsp[(5) - (6)].l), &d, fcmp_double);
      }
      (yyval.d) = matches;
      Free((yyvsp[(3) - (6)].l)); Free((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 470:
#line 5762 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 471:
#line 5771 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 472:
#line 5776 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 473:
#line 5781 "Gmsh.y"
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

  case 474:
#line 5808 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 475:
#line 5812 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 476:
#line 5816 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 477:
#line 5820 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 478:
#line 5824 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 479:
#line 5831 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 480:
#line 5835 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 481:
#line 5839 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 482:
#line 5843 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 483:
#line 5850 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 484:
#line 5855 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 485:
#line 5862 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 486:
#line 5867 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 487:
#line 5871 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 488:
#line 5876 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 489:
#line 5880 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 490:
#line 5888 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 491:
#line 5899 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 492:
#line 5903 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 493:
#line 5915 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 494:
#line 5923 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 495:
#line 5931 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 496:
#line 5938 "Gmsh.y"
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

  case 497:
#line 5948 "Gmsh.y"
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
    ;}
    break;

  case 498:
#line 5977 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 499:
#line 5981 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 500:
#line 5985 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 501:
#line 5989 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 502:
#line 5993 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 503:
#line 5997 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 504:
#line 6001 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 505:
#line 6005 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 506:
#line 6009 "Gmsh.y"
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
    ;}
    break;

  case 507:
#line 6038 "Gmsh.y"
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
    ;}
    break;

  case 508:
#line 6067 "Gmsh.y"
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
    ;}
    break;

  case 509:
#line 6096 "Gmsh.y"
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
    ;}
    break;

  case 510:
#line 6126 "Gmsh.y"
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
    ;}
    break;

  case 511:
#line 6139 "Gmsh.y"
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
    ;}
    break;

  case 512:
#line 6152 "Gmsh.y"
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
    ;}
    break;

  case 513:
#line 6165 "Gmsh.y"
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
    ;}
    break;

  case 514:
#line 6177 "Gmsh.y"
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

  case 515:
#line 6187 "Gmsh.y"
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

  case 516:
#line 6197 "Gmsh.y"
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

  case 517:
#line 6207 "Gmsh.y"
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

  case 518:
#line 6219 "Gmsh.y"
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

  case 519:
#line 6232 "Gmsh.y"
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

  case 520:
#line 6244 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 521:
#line 6248 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 522:
#line 6252 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 523:
#line 6256 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 524:
#line 6260 "Gmsh.y"
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

  case 525:
#line 6278 "Gmsh.y"
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

  case 526:
#line 6296 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 527:
#line 6304 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 528:
#line 6312 "Gmsh.y"
    {
      Msg::Barrier();
      FILE *File;
      (yyval.l) = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      if(!(File = Fopen(tmp.c_str(), "rb"))){
        yymsg(0, "Could not open file '%s'", (yyvsp[(3) - (4)].c));
      }
      else{
	double d;
	while(!feof(File)){
          int ret = fscanf(File, "%lf", &d);
	  if(ret == 1){
	    List_Add((yyval.l), &d);
          }
          else if(ret == EOF){
            break;
          }
          else{
            char dummy[1024];
            fscanf(File, "%s", dummy);
            yymsg(0, "Ignoring '%s' in file '%s'", dummy, (yyvsp[(3) - (4)].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 529:
#line 6341 "Gmsh.y"
    {
      double x0 = (yyvsp[(3) - (14)].d), x1 = (yyvsp[(5) - (14)].d), y0 = (yyvsp[(7) - (14)].d), y1 = (yyvsp[(9) - (14)].d), ys = (yyvsp[(11) - (14)].d);
      int N = (int)(yyvsp[(13) - (14)].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    ;}
    break;

  case 530:
#line 6354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 531:
#line 6359 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 532:
#line 6363 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 533:
#line 6367 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 534:
#line 6379 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 535:
#line 6383 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 536:
#line 6395 "Gmsh.y"
    {
      int flag = 0;
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c))){
        if(gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)].size()){
          (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)][0].c_str(), &flag);
        }
        else{
          yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
          (yyval.u) = 0;
        }
      }
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 537:
#line 6412 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 538:
#line 6422 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 539:
#line 6426 "Gmsh.y"
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

  case 540:
#line 6441 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 541:
#line 6446 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 542:
#line 6453 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 543:
#line 6457 "Gmsh.y"
    {
      std::string val;
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (1)].c));
      else if(gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)].size() == 1)
        val = gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)][0];
      else
        yymsg(0, "Expected single valued string variable '%s'", (yyvsp[(1) - (1)].c));
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 544:
#line 6470 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (4)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (4)].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 545:
#line 6484 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (4)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (4)].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 546:
#line 6498 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (4)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (4)].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 547:
#line 6512 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (4)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (4)].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 548:
#line 6526 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 549:
#line 6534 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 550:
#line 6545 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 551:
#line 6549 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 552:
#line 6553 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 553:
#line 6561 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 554:
#line 6567 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 555:
#line 6573 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 556:
#line 6581 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 557:
#line 6589 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 558:
#line 6596 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 559:
#line 6604 "Gmsh.y"
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
    ;}
    break;

  case 560:
#line 6619 "Gmsh.y"
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

  case 561:
#line 6633 "Gmsh.y"
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

  case 562:
#line 6647 "Gmsh.y"
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

  case 563:
#line 6659 "Gmsh.y"
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
    ;}
    break;

  case 564:
#line 6675 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 565:
#line 6684 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 6693 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        if (i > 0 && (yyvsp[(3) - (4)].c)[i-1] != '_')
          (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 567:
#line 6703 "Gmsh.y"
    {
      if((yyvsp[(3) - (8)].d)){
        (yyval.c) = (yyvsp[(5) - (8)].c);
        Free((yyvsp[(7) - (8)].c));
      }
      else{
        (yyval.c) = (yyvsp[(7) - (8)].c);
        Free((yyvsp[(5) - (8)].c));
      }
    ;}
    break;

  case 568:
#line 6714 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 569:
#line 6722 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 570:
#line 6730 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 571:
#line 6734 "Gmsh.y"
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

  case 572:
#line 6753 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 573:
#line 6760 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 574:
#line 6766 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 575:
#line 6773 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6780 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 577:
#line 6782 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 578:
#line 6793 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 579:
#line 6798 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 580:
#line 6804 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 581:
#line 6813 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 582:
#line 6826 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 583:
#line 6829 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 584:
#line 6833 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13860 "Gmsh.tab.cpp"
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


#line 6836 "Gmsh.y"


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
  for(std::map<std::string, std::vector<std::string> >::iterator it =
        gmsh_yystringsymbols.begin(); it != gmsh_yystringsymbols.end(); it++){
    if(it->second.size() == 1)
      vec.push_back(it->first + " = \"" + it->second[0] + "\";");
    else{
      std::string s = it->first + "[] = Str(";
      for(unsigned int i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += ");";
      vec.push_back(s);
    }
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

void addPeriodicFace(int iTarget, int iSource,
                     const std::vector<double>& affineTransform)
{
  Surface *target = FindSurface(abs(iTarget));

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts.clear();
    mf.affineTransform = affineTransform;
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source) {
      Msg::Error("Could not find edge slave %d or master %d for periodic copy",
                 iTarget, iSource);
    }
    else target->setMeshMaster(source, affineTransform);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::map<int,int>& edgeCounterparts)
{
  Surface *target = FindSurface(abs(iTarget));

  Msg::Info("Encoding periodic connection between %d and %d", iTarget, iSource);
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts = edgeCounterparts;
    mf.affineTransform.clear();
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source) {
      Msg::Error("Could not find surface slave %d or master %d for periodic copy",
                 iTarget,iSource);
		}
		else target->setMeshMaster(source, edgeCounterparts);
  }
}

void addPeriodicEdge(int iTarget,int iSource,
                     const std::vector<double>& affineTransform)
{
  Curve *target = FindCurve(abs(iTarget));
  if (target) {
    GEO_Internals::MasterEdge& me =
      GModel::current()->getGEOInternals()->periodicEdges[iTarget];
    me.tag = iSource;
    me.affineTransform = affineTransform;
  }
  else{
    GEdge *target = GModel::current()->getEdgeByTag(abs(iTarget));
    GEdge *source = GModel::current()->getEdgeByTag(abs(iSource));
    if (!target || !source)
      Msg::Error("Could not find surface %d or %d for periodic copy",
                 iTarget,iSource);
    if (affineTransform.size() >= 12) {
      target->setMeshMaster(source, affineTransform);
    }
    else {
      target->setMeshMaster(source, iSource * iTarget < 0 ? -1 : 1);
    }
  }
}

void computeAffineTransformation(SPoint3& origin, SPoint3& axis,
                                 double angle, SPoint3& translation,
                                 std::vector<double>& tfo)
{
  tfo.resize(16,0.0);

  double ca = cos(angle);
  double sa = sin(angle);

  double ux = axis.x();
  double uy = axis.y();
  double uz = axis.z();

  tfo.resize(16);

  tfo[0*4+0] = ca + ux*ux*(1.-ca);
  tfo[0*4+1] = ux*uy*(1.-ca) - uz * sa;
  tfo[0*4+2] = ux*uz*(1.-ca) + uy * sa;

  tfo[1*4+0] = ux*uy*(1.-ca) + uz * sa;
  tfo[1*4+1] = ca + uy*uy*(1.-ca);
  tfo[1*4+2] = uy*uz*(1.-ca) - ux * sa;

  tfo[2*4+0] = ux*uz*(1.-ca) - uy * sa;
  tfo[2*4+1] = uy*uz*(1.-ca) + ux * sa;
  tfo[2*4+2] = ca + uz*uz*(1.-ca);

  int idx = 0;
  for (size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i*4+3;
    tfo[tIdx] = origin[i] + translation[i];
    for (int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for (int i = 0; i < 4; i++) tfo[12+i] = 0;
  tfo[15] = 1;
}

