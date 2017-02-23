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
     tTorus = 351,
     tEllipsoid = 352,
     tQuadric = 353,
     tShapeFromFile = 354,
     tRectangle = 355,
     tDisk = 356,
     tWire = 357,
     tCharacteristic = 358,
     tLength = 359,
     tParametric = 360,
     tElliptic = 361,
     tRefineMesh = 362,
     tAdaptMesh = 363,
     tRelocateMesh = 364,
     tSetFactory = 365,
     tThruSections = 366,
     tWedge = 367,
     tFillet = 368,
     tChamfer = 369,
     tPlane = 370,
     tRuled = 371,
     tTransfinite = 372,
     tComplex = 373,
     tPhysical = 374,
     tCompound = 375,
     tPeriodic = 376,
     tUsing = 377,
     tPlugin = 378,
     tDegenerated = 379,
     tRecursive = 380,
     tRotate = 381,
     tTranslate = 382,
     tSymmetry = 383,
     tDilate = 384,
     tExtrude = 385,
     tLevelset = 386,
     tAffine = 387,
     tBooleanUnion = 388,
     tBooleanIntersection = 389,
     tBooleanDifference = 390,
     tBooleanSection = 391,
     tBooleanFragments = 392,
     tThickSolid = 393,
     tRecombine = 394,
     tSmoother = 395,
     tSplit = 396,
     tDelete = 397,
     tCoherence = 398,
     tIntersect = 399,
     tMeshAlgorithm = 400,
     tReverse = 401,
     tLayers = 402,
     tScaleLast = 403,
     tHole = 404,
     tAlias = 405,
     tAliasWithOptions = 406,
     tCopyOptions = 407,
     tQuadTriAddVerts = 408,
     tQuadTriNoNewVerts = 409,
     tRecombLaterals = 410,
     tTransfQuadTri = 411,
     tText2D = 412,
     tText3D = 413,
     tInterpolationScheme = 414,
     tTime = 415,
     tCombine = 416,
     tBSpline = 417,
     tBezier = 418,
     tNurbs = 419,
     tNurbsOrder = 420,
     tNurbsKnots = 421,
     tColor = 422,
     tColorTable = 423,
     tFor = 424,
     tIn = 425,
     tEndFor = 426,
     tIf = 427,
     tElseIf = 428,
     tElse = 429,
     tEndIf = 430,
     tExit = 431,
     tAbort = 432,
     tField = 433,
     tReturn = 434,
     tCall = 435,
     tSlide = 436,
     tMacro = 437,
     tShow = 438,
     tHide = 439,
     tGetValue = 440,
     tGetStringValue = 441,
     tGetEnv = 442,
     tGetString = 443,
     tGetNumber = 444,
     tUnique = 445,
     tHomology = 446,
     tCohomology = 447,
     tBetti = 448,
     tExists = 449,
     tFileExists = 450,
     tGMSH_MAJOR_VERSION = 451,
     tGMSH_MINOR_VERSION = 452,
     tGMSH_PATCH_VERSION = 453,
     tGmshExecutableName = 454,
     tSetPartition = 455,
     tNameToString = 456,
     tStringToName = 457,
     tAFFECTDIVIDE = 458,
     tAFFECTTIMES = 459,
     tAFFECTMINUS = 460,
     tAFFECTPLUS = 461,
     tOR = 462,
     tAND = 463,
     tNOTEQUAL = 464,
     tEQUAL = 465,
     tGREATEROREQUAL = 466,
     tLESSOREQUAL = 467,
     UNARYPREC = 468,
     tMINUSMINUS = 469,
     tPLUSPLUS = 470
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
#define tTorus 351
#define tEllipsoid 352
#define tQuadric 353
#define tShapeFromFile 354
#define tRectangle 355
#define tDisk 356
#define tWire 357
#define tCharacteristic 358
#define tLength 359
#define tParametric 360
#define tElliptic 361
#define tRefineMesh 362
#define tAdaptMesh 363
#define tRelocateMesh 364
#define tSetFactory 365
#define tThruSections 366
#define tWedge 367
#define tFillet 368
#define tChamfer 369
#define tPlane 370
#define tRuled 371
#define tTransfinite 372
#define tComplex 373
#define tPhysical 374
#define tCompound 375
#define tPeriodic 376
#define tUsing 377
#define tPlugin 378
#define tDegenerated 379
#define tRecursive 380
#define tRotate 381
#define tTranslate 382
#define tSymmetry 383
#define tDilate 384
#define tExtrude 385
#define tLevelset 386
#define tAffine 387
#define tBooleanUnion 388
#define tBooleanIntersection 389
#define tBooleanDifference 390
#define tBooleanSection 391
#define tBooleanFragments 392
#define tThickSolid 393
#define tRecombine 394
#define tSmoother 395
#define tSplit 396
#define tDelete 397
#define tCoherence 398
#define tIntersect 399
#define tMeshAlgorithm 400
#define tReverse 401
#define tLayers 402
#define tScaleLast 403
#define tHole 404
#define tAlias 405
#define tAliasWithOptions 406
#define tCopyOptions 407
#define tQuadTriAddVerts 408
#define tQuadTriNoNewVerts 409
#define tRecombLaterals 410
#define tTransfQuadTri 411
#define tText2D 412
#define tText3D 413
#define tInterpolationScheme 414
#define tTime 415
#define tCombine 416
#define tBSpline 417
#define tBezier 418
#define tNurbs 419
#define tNurbsOrder 420
#define tNurbsKnots 421
#define tColor 422
#define tColorTable 423
#define tFor 424
#define tIn 425
#define tEndFor 426
#define tIf 427
#define tElseIf 428
#define tElse 429
#define tEndIf 430
#define tExit 431
#define tAbort 432
#define tField 433
#define tReturn 434
#define tCall 435
#define tSlide 436
#define tMacro 437
#define tShow 438
#define tHide 439
#define tGetValue 440
#define tGetStringValue 441
#define tGetEnv 442
#define tGetString 443
#define tGetNumber 444
#define tUnique 445
#define tHomology 446
#define tCohomology 447
#define tBetti 448
#define tExists 449
#define tFileExists 450
#define tGMSH_MAJOR_VERSION 451
#define tGMSH_MINOR_VERSION 452
#define tGMSH_PATCH_VERSION 453
#define tGmshExecutableName 454
#define tSetPartition 455
#define tNameToString 456
#define tStringToName 457
#define tAFFECTDIVIDE 458
#define tAFFECTTIMES 459
#define tAFFECTMINUS 460
#define tAFFECTPLUS 461
#define tOR 462
#define tAND 463
#define tNOTEQUAL 464
#define tEQUAL 465
#define tGREATEROREQUAL 466
#define tLESSOREQUAL 467
#define UNARYPREC 468
#define tMINUSMINUS 469
#define tPLUSPLUS 470




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
#include "GModelIO_GEO.h"
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
void ListOfDouble2Vector(List_T *list, std::vector<int> &v);
void ListOfDouble2Vector(List_T *list, std::vector<double> &v);

void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int,int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&, std::vector<double>&);
void addEmbedded(int dim, std::vector<int> tags, int dim2, int tag2);

char *strsave(char *ptr);

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
#line 121 "Gmsh.y"
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
#line 664 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 677 "Gmsh.tab.cpp"

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
#define YYLAST   14795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  236
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  595
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2254

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   470

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   221,     2,   231,     2,   220,     2,     2,
     226,   227,   218,   216,   232,   217,   230,   219,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     212,     2,   213,   207,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   228,     2,   229,   225,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   234,   235,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   208,   209,   210,   211,   214,   215,   222,   223,
     224
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      24,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    61,    67,
      73,    81,    89,    97,   107,   114,   121,   128,   137,   138,
     141,   144,   147,   150,   153,   155,   159,   161,   165,   166,
     167,   178,   180,   184,   185,   199,   201,   205,   206,   222,
     231,   246,   247,   254,   256,   258,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   282,   288,   296,   304,   309,
     313,   320,   327,   335,   343,   350,   357,   367,   377,   384,
     391,   399,   407,   414,   421,   426,   435,   444,   454,   464,
     474,   484,   493,   502,   512,   522,   532,   542,   549,   559,
     566,   576,   582,   591,   600,   612,   619,   629,   635,   643,
     653,   663,   675,   683,   693,   703,   704,   706,   707,   711,
     717,   718,   728,   729,   741,   742,   754,   760,   761,   771,
     772,   776,   780,   786,   792,   793,   796,   800,   806,   810,
     811,   814,   818,   822,   826,   832,   834,   836,   840,   842,
     844,   848,   850,   852,   856,   858,   860,   864,   865,   871,
     872,   875,   883,   891,   899,   908,   917,   925,   933,   945,
     954,   962,   971,   980,   989,   999,  1003,  1008,  1019,  1027,
    1035,  1043,  1051,  1059,  1067,  1075,  1083,  1091,  1099,  1108,
    1121,  1130,  1138,  1147,  1155,  1164,  1173,  1182,  1191,  1200,
    1209,  1215,  1227,  1233,  1243,  1253,  1258,  1268,  1278,  1280,
    1282,  1283,  1286,  1293,  1300,  1307,  1314,  1323,  1334,  1349,
    1366,  1379,  1394,  1409,  1424,  1439,  1448,  1457,  1464,  1469,
    1476,  1483,  1487,  1492,  1498,  1505,  1511,  1515,  1519,  1524,
    1530,  1535,  1541,  1545,  1551,  1559,  1567,  1571,  1579,  1583,
    1586,  1589,  1592,  1595,  1598,  1614,  1617,  1620,  1623,  1626,
    1629,  1646,  1658,  1665,  1674,  1683,  1694,  1696,  1699,  1702,
    1704,  1708,  1712,  1717,  1722,  1724,  1726,  1732,  1744,  1758,
    1759,  1767,  1768,  1782,  1783,  1799,  1800,  1807,  1817,  1820,
    1824,  1835,  1844,  1853,  1862,  1875,  1888,  1901,  1916,  1931,
    1946,  1947,  1960,  1961,  1974,  1975,  1988,  1989,  2006,  2007,
    2024,  2025,  2042,  2043,  2062,  2063,  2082,  2083,  2102,  2104,
    2107,  2113,  2121,  2131,  2134,  2137,  2141,  2144,  2148,  2151,
    2155,  2165,  2172,  2174,  2176,  2178,  2180,  2182,  2183,  2186,
    2190,  2200,  2205,  2220,  2221,  2225,  2226,  2228,  2229,  2232,
    2233,  2236,  2237,  2240,  2247,  2255,  2262,  2271,  2277,  2281,
    2290,  2296,  2301,  2308,  2320,  2332,  2351,  2370,  2383,  2396,
    2409,  2420,  2431,  2442,  2453,  2464,  2469,  2474,  2479,  2484,
    2489,  2494,  2499,  2504,  2509,  2512,  2516,  2523,  2525,  2527,
    2529,  2532,  2538,  2546,  2557,  2559,  2563,  2566,  2569,  2572,
    2576,  2580,  2584,  2588,  2592,  2596,  2600,  2604,  2608,  2612,
    2616,  2620,  2624,  2628,  2634,  2639,  2644,  2649,  2654,  2659,
    2664,  2669,  2674,  2679,  2684,  2691,  2696,  2701,  2706,  2711,
    2716,  2721,  2726,  2733,  2740,  2747,  2752,  2754,  2756,  2758,
    2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,  2775,  2782,
    2787,  2794,  2796,  2801,  2806,  2811,  2816,  2821,  2826,  2831,
    2834,  2840,  2846,  2852,  2858,  2862,  2869,  2874,  2882,  2889,
    2896,  2903,  2908,  2915,  2920,  2922,  2925,  2928,  2932,  2936,
    2948,  2958,  2966,  2974,  2976,  2980,  2982,  2984,  2987,  2991,
    2996,  3002,  3004,  3006,  3009,  3013,  3017,  3023,  3028,  3031,
    3034,  3037,  3040,  3044,  3048,  3052,  3056,  3062,  3068,  3074,
    3080,  3097,  3114,  3131,  3148,  3150,  3152,  3154,  3158,  3162,
    3167,  3172,  3177,  3184,  3191,  3198,  3205,  3214,  3223,  3228,
    3243,  3248,  3250,  3252,  3256,  3260,  3270,  3278,  3280,  3286,
    3290,  3297,  3299,  3303,  3305,  3307,  3312,  3317,  3322,  3327,
    3331,  3338,  3340,  3345,  3347,  3349,  3351,  3356,  3363,  3368,
    3375,  3380,  3385,  3390,  3399,  3404,  3409,  3414,  3419,  3428,
    3437,  3444,  3449,  3456,  3461,  3463,  3468,  3473,  3474,  3481,
    3483,  3487,  3493,  3499,  3501,  3503
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     237,     0,    -1,   238,    -1,     1,     6,    -1,    -1,   238,
     239,    -1,   241,    -1,   242,    -1,   262,    -1,   110,   226,
     335,   227,     6,    -1,   281,    -1,   282,    -1,   286,    -1,
     287,    -1,   288,    -1,   289,    -1,   293,    -1,   311,    -1,
     312,    -1,   318,    -1,   319,    -1,   292,    -1,   291,    -1,
     290,    -1,   285,    -1,   321,    -1,   213,    -1,   213,   213,
      -1,    42,   226,   335,   227,     6,    -1,    43,   226,   335,
     227,     6,    -1,    42,   226,   335,   227,   240,   335,     6,
      -1,    42,   226,   335,   232,   331,   227,     6,    -1,    43,
     226,   335,   232,   331,   227,     6,    -1,    42,   226,   335,
     232,   331,   227,   240,   335,     6,    -1,     4,   335,   233,
     243,   234,     6,    -1,   150,     4,   228,   322,   229,     6,
      -1,   151,     4,   228,   322,   229,     6,    -1,   152,     4,
     228,   322,   232,   322,   229,     6,    -1,    -1,   243,   246,
      -1,   243,   250,    -1,   243,   253,    -1,   243,   255,    -1,
     243,   256,    -1,   322,    -1,   244,   232,   322,    -1,   322,
      -1,   245,   232,   322,    -1,    -1,    -1,     4,   247,   226,
     244,   227,   248,   233,   245,   234,     6,    -1,   335,    -1,
     249,   232,   335,    -1,    -1,   157,   226,   322,   232,   322,
     232,   322,   227,   251,   233,   249,   234,     6,    -1,   335,
      -1,   252,   232,   335,    -1,    -1,   158,   226,   322,   232,
     322,   232,   322,   232,   322,   227,   254,   233,   252,   234,
       6,    -1,   159,   233,   327,   234,   233,   327,   234,     6,
      -1,   159,   233,   327,   234,   233,   327,   234,   233,   327,
     234,   233,   327,   234,     6,    -1,    -1,   160,   257,   233,
     245,   234,     6,    -1,     7,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   224,    -1,   223,    -1,   226,    -1,
     228,    -1,   227,    -1,   229,    -1,    78,   228,   264,   229,
       6,    -1,    79,   228,   269,   229,     6,    -1,    82,   260,
     336,   232,   322,   261,     6,    -1,    83,   260,   340,   232,
     336,   261,     6,    -1,   340,   258,   328,     6,    -1,   340,
     259,     6,    -1,     4,   228,   229,   258,   328,     6,    -1,
     339,   228,   229,   258,   328,     6,    -1,     4,   228,   322,
     229,   258,   322,     6,    -1,   339,   228,   322,   229,   258,
     322,     6,    -1,     4,   228,   322,   229,   259,     6,    -1,
     339,   228,   322,   229,   259,     6,    -1,     4,   260,   233,
     331,   234,   261,   258,   328,     6,    -1,   339,   260,   233,
     331,   234,   261,   258,   328,     6,    -1,     4,   226,   227,
     258,   328,     6,    -1,   339,   226,   227,   258,   328,     6,
      -1,     4,   226,   322,   227,   258,   322,     6,    -1,   339,
     226,   322,   227,   258,   322,     6,    -1,     4,   226,   322,
     227,   259,     6,    -1,   339,   226,   322,   227,   259,     6,
      -1,   340,     7,   336,     6,    -1,     4,   228,   229,     7,
      44,   260,   261,     6,    -1,   339,   228,   229,     7,    44,
     260,   261,     6,    -1,     4,   228,   229,     7,    44,   260,
     338,   261,     6,    -1,   339,   228,   229,     7,    44,   260,
     338,   261,     6,    -1,     4,   228,   229,   206,    44,   260,
     338,   261,     6,    -1,   339,   228,   229,   206,    44,   260,
     338,   261,     6,    -1,     4,   226,   227,     7,    44,   260,
     261,     6,    -1,   339,   226,   227,     7,    44,   260,   261,
       6,    -1,     4,   226,   227,     7,    44,   260,   338,   261,
       6,    -1,   339,   226,   227,     7,    44,   260,   338,   261,
       6,    -1,     4,   226,   227,   206,    44,   260,   338,   261,
       6,    -1,   339,   226,   227,   206,    44,   260,   338,   261,
       6,    -1,     4,   230,     4,     7,   336,     6,    -1,     4,
     228,   322,   229,   230,     4,     7,   336,     6,    -1,     4,
     230,     4,   258,   322,     6,    -1,     4,   228,   322,   229,
     230,     4,   258,   322,     6,    -1,     4,   230,     4,   259,
       6,    -1,     4,   228,   322,   229,   230,     4,   259,     6,
      -1,     4,   230,   167,   230,     4,     7,   332,     6,    -1,
       4,   228,   322,   229,   230,   167,   230,     4,     7,   332,
       6,    -1,     4,   230,   168,     7,   333,     6,    -1,     4,
     228,   322,   229,   230,   168,     7,   333,     6,    -1,     4,
     178,     7,   322,     6,    -1,   178,   228,   322,   229,     7,
       4,     6,    -1,   178,   228,   322,   229,   230,     4,     7,
     322,     6,    -1,   178,   228,   322,   229,   230,     4,     7,
     336,     6,    -1,   178,   228,   322,   229,   230,     4,     7,
     233,   331,   234,     6,    -1,   178,   228,   322,   229,   230,
       4,     6,    -1,   123,   226,     4,   227,   230,     4,     7,
     322,     6,    -1,   123,   226,     4,   227,   230,     4,     7,
     336,     6,    -1,    -1,   232,    -1,    -1,   264,   263,   340,
      -1,   264,   263,   340,     7,   322,    -1,    -1,   264,   263,
     340,     7,   233,   328,   265,   271,   234,    -1,    -1,   264,
     263,   340,   228,   229,     7,   233,   328,   266,   271,   234,
      -1,    -1,   264,   263,   340,   226,   227,     7,   233,   328,
     267,   271,   234,    -1,   264,   263,   340,     7,   336,    -1,
      -1,   264,   263,   340,     7,   233,   336,   268,   273,   234,
      -1,    -1,   269,   263,   335,    -1,   322,     7,   336,    -1,
     270,   232,   322,     7,   336,    -1,   330,     7,   340,   226,
     227,    -1,    -1,   271,   272,    -1,   232,     4,   328,    -1,
     232,     4,   233,   270,   234,    -1,   232,     4,   336,    -1,
      -1,   273,   274,    -1,   232,     4,   322,    -1,   232,     4,
     336,    -1,   232,   182,   336,    -1,   232,     4,   233,   338,
     234,    -1,   322,    -1,   336,    -1,   336,   232,   322,    -1,
     322,    -1,   336,    -1,   336,   232,   322,    -1,   322,    -1,
     336,    -1,   336,   232,   322,    -1,   322,    -1,   336,    -1,
     336,   232,   322,    -1,    -1,   170,    88,   233,   322,   234,
      -1,    -1,   115,   325,    -1,    84,   226,   322,   227,     7,
     325,     6,    -1,    87,   226,   322,   227,     7,   328,     6,
      -1,    91,   226,   322,   227,     7,   328,     6,    -1,    85,
     226,   322,   227,     7,   328,   280,     6,    -1,    86,   226,
     322,   227,     7,   328,   280,     6,    -1,   162,   226,   322,
     227,     7,   328,     6,    -1,   163,   226,   322,   227,     7,
     328,     6,    -1,   164,   226,   322,   227,     7,   328,   166,
     328,   165,   322,     6,    -1,   120,    87,   226,   322,   227,
       7,   328,     6,    -1,   102,   226,   322,   227,     7,   328,
       6,    -1,    87,     4,   226,   322,   227,     7,   328,     6,
      -1,   115,    90,   226,   322,   227,     7,   328,     6,    -1,
      90,   226,   322,   227,     7,   328,   279,     6,    -1,   116,
      90,   226,   322,   227,     7,   328,   279,     6,    -1,    12,
      13,     6,    -1,    13,    90,   322,     6,    -1,   105,    90,
     226,   322,   227,     7,     5,     5,     5,     6,    -1,    88,
     226,   322,   227,     7,   328,     6,    -1,    89,   226,   322,
     227,     7,   328,     6,    -1,    93,   226,   322,   227,     7,
     328,     6,    -1,    96,   226,   322,   227,     7,   328,     6,
      -1,   100,   226,   322,   227,     7,   328,     6,    -1,   101,
     226,   322,   227,     7,   328,     6,    -1,    94,   226,   322,
     227,     7,   328,     6,    -1,    95,   226,   322,   227,     7,
     328,     6,    -1,   112,   226,   322,   227,     7,   328,     6,
      -1,   138,   226,   322,   227,     7,   328,     6,    -1,   120,
      90,   226,   322,   227,     7,   328,     6,    -1,   120,    90,
     226,   322,   227,     7,   328,     4,   233,   327,   234,     6,
      -1,    90,     4,   226,   322,   227,     7,   328,     6,    -1,
      92,   226,   322,   227,     7,   328,     6,    -1,   118,    92,
     226,   322,   227,     7,   328,     6,    -1,   111,   226,   322,
     227,     7,   328,     6,    -1,   116,   111,   226,   322,   227,
       7,   328,     6,    -1,   120,    92,   226,   322,   227,     7,
     328,     6,    -1,   119,    84,   226,   275,   227,   258,   328,
       6,    -1,   119,    87,   226,   276,   227,   258,   328,     6,
      -1,   119,    90,   226,   277,   227,   258,   328,     6,    -1,
     119,    92,   226,   278,   227,   258,   328,     6,    -1,   127,
     325,   233,   283,   234,    -1,   126,   233,   325,   232,   325,
     232,   322,   234,   233,   283,   234,    -1,   128,   325,   233,
     283,   234,    -1,   129,   233,   325,   232,   322,   234,   233,
     283,   234,    -1,   129,   233,   325,   232,   325,   234,   233,
     283,   234,    -1,     4,   233,   283,   234,    -1,   144,    87,
     233,   331,   234,    90,   233,   322,   234,    -1,   141,    87,
     226,   322,   227,   233,   331,   234,     6,    -1,   284,    -1,
     282,    -1,    -1,   284,   281,    -1,   284,    84,   233,   331,
     234,     6,    -1,   284,    87,   233,   331,   234,     6,    -1,
     284,    90,   233,   331,   234,     6,    -1,   284,    92,   233,
     331,   234,     6,    -1,   131,   115,   226,   322,   227,     7,
     328,     6,    -1,   131,    84,   226,   322,   227,     7,   233,
     327,   234,     6,    -1,   131,   115,   226,   322,   227,     7,
     233,   325,   232,   325,   232,   331,   234,     6,    -1,   131,
     115,   226,   322,   227,     7,   233,   325,   232,   325,   232,
     325,   232,   331,   234,     6,    -1,   131,    88,   226,   322,
     227,     7,   233,   325,   232,   331,   234,     6,    -1,   131,
      94,   226,   322,   227,     7,   233,   325,   232,   325,   232,
     331,   234,     6,    -1,   131,    95,   226,   322,   227,     7,
     233,   325,   232,   325,   232,   331,   234,     6,    -1,   131,
      97,   226,   322,   227,     7,   233,   325,   232,   325,   232,
     331,   234,     6,    -1,   131,    98,   226,   322,   227,     7,
     233,   325,   232,   325,   232,   331,   234,     6,    -1,   131,
       4,   226,   322,   227,     7,   328,     6,    -1,   131,     4,
     226,   322,   227,     7,     5,     6,    -1,   131,     4,   233,
     322,   234,     6,    -1,   142,   233,   284,   234,    -1,   142,
     178,   228,   322,   229,     6,    -1,   142,     4,   228,   322,
     229,     6,    -1,   142,   340,     6,    -1,   142,     4,     4,
       6,    -1,   167,   332,   233,   284,   234,    -1,   125,   167,
     332,   233,   284,   234,    -1,   200,   322,   233,   284,   234,
      -1,   183,     5,     6,    -1,   184,     5,     6,    -1,   183,
     233,   284,   234,    -1,   125,   183,   233,   284,   234,    -1,
     184,   233,   284,   234,    -1,   125,   184,   233,   284,   234,
      -1,     4,   336,     6,    -1,    71,   226,   338,   227,     6,
      -1,     4,     4,   228,   322,   229,   335,     6,    -1,     4,
       4,     4,   228,   322,   229,     6,    -1,     4,   322,     6,
      -1,   123,   226,     4,   227,   230,     4,     6,    -1,   161,
       4,     6,    -1,   176,     6,    -1,   177,     6,    -1,    68,
       6,    -1,    69,     6,    -1,    62,     6,    -1,    62,   233,
     322,   232,   322,   232,   322,   232,   322,   232,   322,   232,
     322,   234,     6,    -1,    63,     6,    -1,    64,     6,    -1,
      75,     6,    -1,    76,     6,    -1,   107,     6,    -1,   108,
     233,   331,   234,   233,   331,   234,   233,   327,   234,   233,
     322,   232,   322,   234,     6,    -1,   181,   226,   233,   331,
     234,   232,   336,   232,   336,   227,     6,    -1,   169,   226,
     322,     8,   322,   227,    -1,   169,   226,   322,     8,   322,
       8,   322,   227,    -1,   169,     4,   170,   233,   322,     8,
     322,   234,    -1,   169,     4,   170,   233,   322,     8,   322,
       8,   322,   234,    -1,   171,    -1,   182,     4,    -1,   182,
     336,    -1,   179,    -1,   180,   340,     6,    -1,   180,   336,
       6,    -1,   172,   226,   322,   227,    -1,   173,   226,   322,
     227,    -1,   174,    -1,   175,    -1,   130,   325,   233,   284,
     234,    -1,   130,   233,   325,   232,   325,   232,   322,   234,
     233,   284,   234,    -1,   130,   233,   325,   232,   325,   232,
     325,   232,   322,   234,   233,   284,   234,    -1,    -1,   130,
     325,   233,   284,   294,   307,   234,    -1,    -1,   130,   233,
     325,   232,   325,   232,   322,   234,   233,   284,   295,   307,
     234,    -1,    -1,   130,   233,   325,   232,   325,   232,   325,
     232,   322,   234,   233,   284,   296,   307,   234,    -1,    -1,
     130,   233,   284,   297,   307,   234,    -1,   130,   233,   284,
     234,   122,   102,   233,   322,   234,    -1,   111,   328,    -1,
     116,   111,   328,    -1,   113,   233,   331,   234,   233,   331,
     234,   233,   322,   234,    -1,   130,    84,   233,   322,   232,
     325,   234,     6,    -1,   130,    87,   233,   322,   232,   325,
     234,     6,    -1,   130,    90,   233,   322,   232,   325,   234,
       6,    -1,   130,    84,   233,   322,   232,   325,   232,   325,
     232,   322,   234,     6,    -1,   130,    87,   233,   322,   232,
     325,   232,   325,   232,   322,   234,     6,    -1,   130,    90,
     233,   322,   232,   325,   232,   325,   232,   322,   234,     6,
      -1,   130,    84,   233,   322,   232,   325,   232,   325,   232,
     325,   232,   322,   234,     6,    -1,   130,    87,   233,   322,
     232,   325,   232,   325,   232,   325,   232,   322,   234,     6,
      -1,   130,    90,   233,   322,   232,   325,   232,   325,   232,
     325,   232,   322,   234,     6,    -1,    -1,   130,    84,   233,
     322,   232,   325,   234,   298,   233,   307,   234,     6,    -1,
      -1,   130,    87,   233,   322,   232,   325,   234,   299,   233,
     307,   234,     6,    -1,    -1,   130,    90,   233,   322,   232,
     325,   234,   300,   233,   307,   234,     6,    -1,    -1,   130,
      84,   233,   322,   232,   325,   232,   325,   232,   322,   234,
     301,   233,   307,   234,     6,    -1,    -1,   130,    87,   233,
     322,   232,   325,   232,   325,   232,   322,   234,   302,   233,
     307,   234,     6,    -1,    -1,   130,    90,   233,   322,   232,
     325,   232,   325,   232,   322,   234,   303,   233,   307,   234,
       6,    -1,    -1,   130,    84,   233,   322,   232,   325,   232,
     325,   232,   325,   232,   322,   234,   304,   233,   307,   234,
       6,    -1,    -1,   130,    87,   233,   322,   232,   325,   232,
     325,   232,   325,   232,   322,   234,   305,   233,   307,   234,
       6,    -1,    -1,   130,    90,   233,   322,   232,   325,   232,
     325,   232,   325,   232,   322,   234,   306,   233,   307,   234,
       6,    -1,   308,    -1,   307,   308,    -1,   147,   233,   322,
     234,     6,    -1,   147,   233,   328,   232,   328,   234,     6,
      -1,   147,   233,   328,   232,   328,   232,   328,   234,     6,
      -1,   148,     6,    -1,   139,     6,    -1,   139,   322,     6,
      -1,   153,     6,    -1,   153,   155,     6,    -1,   154,     6,
      -1,   154,   155,     6,    -1,   149,   226,   322,   227,     7,
     328,   122,   322,     6,    -1,   122,     4,   228,   322,   229,
       6,    -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,
     137,    -1,    -1,   142,     6,    -1,   142,   322,     6,    -1,
     309,   233,   284,   310,   234,   233,   284,   310,   234,    -1,
      99,   226,   335,   227,    -1,   309,   226,   322,   227,     7,
     233,   284,   310,   234,   233,   284,   310,   234,     6,    -1,
      -1,   122,     4,   322,    -1,    -1,     4,    -1,    -1,     7,
     328,    -1,    -1,     7,   322,    -1,    -1,   132,   328,    -1,
     103,   104,   328,     7,   322,     6,    -1,   117,    87,   329,
       7,   322,   313,     6,    -1,   117,    90,   329,   315,   314,
       6,    -1,   106,    90,   233,   322,   234,     7,   328,     6,
      -1,   117,    92,   329,   315,     6,    -1,   156,   329,     6,
      -1,   145,    90,   233,   331,   234,     7,   322,     6,    -1,
     139,    90,   329,   316,     6,    -1,   139,    92,   329,     6,
      -1,   140,    90,   329,     7,   322,     6,    -1,   121,    87,
     233,   331,   234,     7,   233,   331,   234,   317,     6,    -1,
     121,    90,   233,   331,   234,     7,   233,   331,   234,   317,
       6,    -1,   121,    87,   233,   331,   234,     7,   233,   331,
     234,   126,   233,   325,   232,   325,   232,   322,   234,     6,
      -1,   121,    90,   233,   331,   234,     7,   233,   331,   234,
     126,   233,   325,   232,   325,   232,   322,   234,     6,    -1,
     121,    87,   233,   331,   234,     7,   233,   331,   234,   127,
     325,     6,    -1,   121,    90,   233,   331,   234,     7,   233,
     331,   234,   127,   325,     6,    -1,   121,    90,   322,   233,
     331,   234,     7,   322,   233,   331,   234,     6,    -1,    84,
     233,   331,   234,   170,    90,   233,   322,   234,     6,    -1,
      87,   233,   331,   234,   170,    90,   233,   322,   234,     6,
      -1,    84,   233,   331,   234,   170,    92,   233,   322,   234,
       6,    -1,    87,   233,   331,   234,   170,    92,   233,   322,
     234,     6,    -1,    90,   233,   331,   234,   170,    92,   233,
     322,   234,     6,    -1,   146,    90,   329,     6,    -1,   146,
      87,   329,     6,    -1,   109,    84,   329,     6,    -1,   109,
      87,   329,     6,    -1,   109,    90,   329,     6,    -1,   124,
      87,   328,     6,    -1,   120,    87,   328,     6,    -1,   120,
      90,   328,     6,    -1,   120,    92,   328,     6,    -1,   143,
       6,    -1,   143,     4,     6,    -1,   143,    84,   233,   331,
     234,     6,    -1,   191,    -1,   192,    -1,   193,    -1,   320,
       6,    -1,   320,   233,   328,   234,     6,    -1,   320,   233,
     328,   232,   328,   234,     6,    -1,   320,   226,   328,   227,
     233,   328,   232,   328,   234,     6,    -1,   323,    -1,   226,
     322,   227,    -1,   217,   322,    -1,   216,   322,    -1,   221,
     322,    -1,   322,   217,   322,    -1,   322,   216,   322,    -1,
     322,   218,   322,    -1,   322,   219,   322,    -1,   322,   220,
     322,    -1,   322,   225,   322,    -1,   322,   212,   322,    -1,
     322,   213,   322,    -1,   322,   215,   322,    -1,   322,   214,
     322,    -1,   322,   211,   322,    -1,   322,   210,   322,    -1,
     322,   209,   322,    -1,   322,   208,   322,    -1,   322,   207,
     322,     8,   322,    -1,    15,   260,   322,   261,    -1,    16,
     260,   322,   261,    -1,    17,   260,   322,   261,    -1,    18,
     260,   322,   261,    -1,    19,   260,   322,   261,    -1,    20,
     260,   322,   261,    -1,    21,   260,   322,   261,    -1,    22,
     260,   322,   261,    -1,    23,   260,   322,   261,    -1,    25,
     260,   322,   261,    -1,    26,   260,   322,   232,   322,   261,
      -1,    27,   260,   322,   261,    -1,    28,   260,   322,   261,
      -1,    29,   260,   322,   261,    -1,    30,   260,   322,   261,
      -1,    31,   260,   322,   261,    -1,    32,   260,   322,   261,
      -1,    33,   260,   322,   261,    -1,    34,   260,   322,   232,
     322,   261,    -1,    35,   260,   322,   232,   322,   261,    -1,
      36,   260,   322,   232,   322,   261,    -1,    24,   260,   322,
     261,    -1,     3,    -1,     9,    -1,    14,    -1,    10,    -1,
      11,    -1,   196,    -1,   197,    -1,   198,    -1,    72,    -1,
      73,    -1,    74,    -1,    -1,    80,   260,   322,   324,   271,
     261,    -1,   189,   260,   335,   261,    -1,   189,   260,   335,
     232,   322,   261,    -1,   340,    -1,     4,   228,   322,   229,
      -1,     4,   226,   322,   227,    -1,   339,   228,   322,   229,
      -1,   339,   226,   322,   227,    -1,   194,   226,   340,   227,
      -1,   195,   226,   336,   227,    -1,   231,   340,   260,   261,
      -1,   340,   259,    -1,     4,   228,   322,   229,   259,    -1,
       4,   226,   322,   227,   259,    -1,   339,   228,   322,   229,
     259,    -1,   339,   226,   322,   227,   259,    -1,     4,   230,
       4,    -1,     4,   228,   322,   229,   230,     4,    -1,     4,
     230,     4,   259,    -1,     4,   228,   322,   229,   230,     4,
     259,    -1,   185,   226,   335,   232,   322,   227,    -1,    54,
     226,   328,   232,   328,   227,    -1,    55,   260,   335,   232,
     335,   261,    -1,    53,   260,   335,   261,    -1,    56,   260,
     335,   232,   335,   261,    -1,    61,   226,   338,   227,    -1,
     326,    -1,   217,   325,    -1,   216,   325,    -1,   325,   217,
     325,    -1,   325,   216,   325,    -1,   233,   322,   232,   322,
     232,   322,   232,   322,   232,   322,   234,    -1,   233,   322,
     232,   322,   232,   322,   232,   322,   234,    -1,   233,   322,
     232,   322,   232,   322,   234,    -1,   226,   322,   232,   322,
     232,   322,   227,    -1,   328,    -1,   327,   232,   328,    -1,
     322,    -1,   330,    -1,   233,   234,    -1,   233,   331,   234,
      -1,   217,   233,   331,   234,    -1,   322,   218,   233,   331,
     234,    -1,   328,    -1,     5,    -1,   217,   330,    -1,   322,
     218,   330,    -1,   322,     8,   322,    -1,   322,     8,   322,
       8,   322,    -1,    84,   233,   322,   234,    -1,    84,     5,
      -1,    87,     5,    -1,    90,     5,    -1,    92,     5,    -1,
     119,    84,     5,    -1,   119,    87,     5,    -1,   119,    90,
       5,    -1,   119,    92,     5,    -1,   119,    84,   233,   331,
     234,    -1,   119,    87,   233,   331,   234,    -1,   119,    90,
     233,   331,   234,    -1,   119,    92,   233,   331,   234,    -1,
      84,   170,    62,   233,   322,   232,   322,   232,   322,   232,
     322,   232,   322,   232,   322,   234,    -1,    87,   170,    62,
     233,   322,   232,   322,   232,   322,   232,   322,   232,   322,
     232,   322,   234,    -1,    90,   170,    62,   233,   322,   232,
     322,   232,   322,   232,   322,   232,   322,   232,   322,   234,
      -1,    92,   170,    62,   233,   322,   232,   322,   232,   322,
     232,   322,   232,   322,   232,   322,   234,    -1,   282,    -1,
     293,    -1,   311,    -1,     4,   260,   261,    -1,   339,   260,
     261,    -1,    37,   228,   340,   229,    -1,    37,   228,   330,
     229,    -1,    37,   226,   330,   227,    -1,    37,   228,   233,
     331,   234,   229,    -1,    37,   226,   233,   331,   234,   227,
      -1,     4,   260,   233,   331,   234,   261,    -1,   339,   260,
     233,   331,   234,   261,    -1,    38,   260,   322,   232,   322,
     232,   322,   261,    -1,    39,   260,   322,   232,   322,   232,
     322,   261,    -1,    40,   260,   335,   261,    -1,    41,   260,
     322,   232,   322,   232,   322,   232,   322,   232,   322,   232,
     322,   261,    -1,   190,   260,   330,   261,    -1,   322,    -1,
     330,    -1,   331,   232,   322,    -1,   331,   232,   330,    -1,
     233,   322,   232,   322,   232,   322,   232,   322,   234,    -1,
     233,   322,   232,   322,   232,   322,   234,    -1,   340,    -1,
       4,   230,   167,   230,     4,    -1,   233,   334,   234,    -1,
       4,   228,   322,   229,   230,   168,    -1,   332,    -1,   334,
     232,   332,    -1,   336,    -1,   340,    -1,     4,   228,   322,
     229,    -1,   339,   228,   322,   229,    -1,     4,   226,   322,
     227,    -1,   339,   226,   322,   227,    -1,     4,   230,     4,
      -1,     4,   228,   322,   229,   230,     4,    -1,     5,    -1,
     201,   228,   340,   229,    -1,    65,    -1,   199,    -1,    70,
      -1,   187,   226,   335,   227,    -1,   186,   226,   335,   232,
     335,   227,    -1,   188,   260,   335,   261,    -1,   188,   260,
     335,   232,   335,   261,    -1,    46,   260,   338,   261,    -1,
      47,   226,   335,   227,    -1,    48,   226,   335,   227,    -1,
      49,   226,   335,   232,   335,   232,   335,   227,    -1,    44,
     260,   338,   261,    -1,    58,   260,   335,   261,    -1,    59,
     260,   335,   261,    -1,    60,   260,   335,   261,    -1,    57,
     260,   322,   232,   335,   232,   335,   261,    -1,    52,   260,
     335,   232,   322,   232,   322,   261,    -1,    52,   260,   335,
     232,   322,   261,    -1,    45,   260,   335,   261,    -1,    45,
     260,   335,   232,   331,   261,    -1,    66,   260,   335,   261,
      -1,    67,    -1,    51,   260,   335,   261,    -1,    50,   260,
     335,   261,    -1,    -1,    81,   260,   336,   337,   273,   261,
      -1,   335,    -1,   338,   232,   335,    -1,     4,   235,   233,
     322,   234,    -1,   339,   235,   233,   322,   234,    -1,     4,
      -1,   339,    -1,   202,   228,   335,   229,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   214,   214,   215,   220,   222,   226,   227,   228,   229,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   255,   259,   266,   271,
     276,   290,   303,   316,   344,   358,   371,   384,   403,   408,
     409,   410,   411,   412,   416,   418,   423,   425,   431,   535,
     430,   553,   560,   571,   570,   588,   595,   606,   605,   622,
     639,   662,   661,   675,   676,   677,   678,   679,   683,   684,
     690,   690,   691,   691,   697,   698,   699,   704,   710,   772,
     789,   818,   847,   852,   857,   862,   867,   874,   884,   913,
     942,   947,   952,   957,   965,   974,   980,   986,   999,  1012,
    1027,  1044,  1050,  1056,  1069,  1082,  1097,  1114,  1120,  1129,
    1147,  1165,  1174,  1186,  1191,  1199,  1219,  1242,  1253,  1261,
    1283,  1306,  1344,  1365,  1377,  1391,  1391,  1393,  1395,  1404,
    1414,  1413,  1434,  1433,  1452,  1451,  1469,  1479,  1478,  1492,
    1494,  1502,  1508,  1513,  1539,  1540,  1544,  1555,  1570,  1580,
    1581,  1586,  1594,  1603,  1611,  1629,  1633,  1639,  1647,  1651,
    1657,  1665,  1669,  1675,  1683,  1687,  1693,  1702,  1705,  1712,
    1715,  1722,  1743,  1757,  1771,  1806,  1844,  1858,  1872,  1892,
    1901,  1915,  1930,  1944,  1963,  1973,  1979,  1985,  1992,  2019,
    2034,  2054,  2075,  2096,  2117,  2139,  2161,  2182,  2205,  2214,
    2235,  2250,  2264,  2279,  2294,  2309,  2318,  2361,  2404,  2447,
    2495,  2512,  2530,  2540,  2550,  2560,  2623,  2634,  2650,  2651,
    2656,  2659,  2663,  2674,  2685,  2696,  2712,  2734,  2760,  2782,
    2805,  2826,  2882,  2906,  2931,  2957,  3070,  3089,  3132,  3151,
    3157,  3172,  3200,  3217,  3226,  3240,  3254,  3260,  3266,  3275,
    3284,  3293,  3307,  3377,  3395,  3412,  3427,  3459,  3471,  3495,
    3499,  3504,  3510,  3515,  3524,  3529,  3535,  3543,  3547,  3551,
    3559,  3622,  3638,  3655,  3672,  3694,  3716,  3751,  3759,  3767,
    3773,  3780,  3787,  3807,  3833,  3845,  3857,  3887,  3918,  3927,
    3926,  3941,  3940,  3955,  3954,  3969,  3968,  3981,  4008,  4027,
    4046,  4072,  4079,  4086,  4093,  4100,  4107,  4114,  4121,  4128,
    4136,  4135,  4149,  4148,  4162,  4161,  4175,  4174,  4188,  4187,
    4201,  4200,  4214,  4213,  4227,  4226,  4240,  4239,  4256,  4259,
    4265,  4277,  4297,  4320,  4324,  4328,  4332,  4336,  4340,  4344,
    4348,  4357,  4370,  4371,  4372,  4373,  4374,  4378,  4379,  4380,
    4383,  4417,  4443,  4467,  4470,  4486,  4489,  4506,  4509,  4515,
    4518,  4525,  4528,  4535,  4551,  4591,  4634,  4639,  4677,  4701,
    4710,  4739,  4764,  4789,  4821,  4848,  4874,  4900,  4926,  4952,
    4974,  4980,  4986,  4992,  4998,  5004,  5029,  5054,  5071,  5088,
    5105,  5117,  5123,  5129,  5141,  5145,  5155,  5166,  5167,  5168,
    5172,  5178,  5190,  5208,  5236,  5237,  5238,  5239,  5240,  5241,
    5242,  5243,  5244,  5251,  5252,  5253,  5254,  5255,  5256,  5257,
    5258,  5259,  5260,  5261,  5262,  5263,  5264,  5265,  5266,  5267,
    5268,  5269,  5270,  5271,  5272,  5273,  5274,  5275,  5276,  5277,
    5278,  5279,  5280,  5281,  5282,  5283,  5292,  5293,  5294,  5295,
    5296,  5297,  5298,  5299,  5300,  5301,  5302,  5307,  5306,  5314,
    5319,  5324,  5341,  5359,  5377,  5395,  5413,  5418,  5424,  5439,
    5458,  5478,  5498,  5518,  5541,  5546,  5551,  5561,  5571,  5576,
    5587,  5596,  5601,  5606,  5633,  5637,  5641,  5645,  5649,  5656,
    5660,  5664,  5668,  5675,  5680,  5687,  5692,  5696,  5701,  5705,
    5713,  5724,  5728,  5740,  5748,  5756,  5763,  5773,  5795,  5799,
    5803,  5807,  5811,  5815,  5819,  5823,  5827,  5858,  5889,  5920,
    5951,  5967,  5983,  5999,  6015,  6025,  6035,  6045,  6057,  6070,
    6082,  6086,  6090,  6094,  6098,  6116,  6134,  6142,  6150,  6179,
    6189,  6208,  6213,  6217,  6221,  6233,  6237,  6249,  6266,  6276,
    6280,  6295,  6300,  6307,  6311,  6324,  6338,  6352,  6366,  6380,
    6388,  6399,  6403,  6407,  6415,  6421,  6427,  6435,  6443,  6450,
    6458,  6473,  6487,  6501,  6513,  6529,  6538,  6547,  6557,  6568,
    6576,  6584,  6588,  6607,  6614,  6620,  6627,  6635,  6634,  6647,
    6652,  6658,  6667,  6680,  6683,  6687
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
  "tCone", "tTorus", "tEllipsoid", "tQuadric", "tShapeFromFile",
  "tRectangle", "tDisk", "tWire", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh",
  "tSetFactory", "tThruSections", "tWedge", "tFillet", "tChamfer",
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRecursive",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tAffine", "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tRecombLaterals", "tTransfQuadTri", "tText2D",
  "tText3D", "tInterpolationScheme", "tTime", "tCombine", "tBSpline",
  "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tElseIf", "tElse",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tSlide",
  "tMacro", "tShow", "tHide", "tGetValue", "tGetStringValue", "tGetEnv",
  "tGetString", "tGetNumber", "tUnique", "tHomology", "tCohomology",
  "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "LP", "RP", "Affectation",
  "Comma", "DefineConstants", "@6", "@7", "@8", "@9", "UndefineConstants",
  "Enumeration", "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptions", "CharParameterOption", "PhysicalId0",
  "PhysicalId1", "PhysicalId2", "PhysicalId3", "InSphereCenter",
  "CircleOptions", "Shape", "Transform", "MultipleShape", "ListOfShapes",
  "LevelSet", "Delete", "Colorify", "SetPartition", "Visibility",
  "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12", "@13", "@14",
  "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    63,   462,   463,
     464,   465,    60,    62,   466,   467,    43,    45,    42,    47,
      37,    33,   468,   469,   470,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   236,   237,   237,   238,   238,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   240,   240,   241,   241,
     241,   241,   241,   241,   242,   242,   242,   242,   243,   243,
     243,   243,   243,   243,   244,   244,   245,   245,   247,   248,
     246,   249,   249,   251,   250,   252,   252,   254,   253,   255,
     255,   257,   256,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   263,   263,   264,   264,   264,
     265,   264,   266,   264,   267,   264,   264,   268,   264,   269,
     269,   270,   270,   270,   271,   271,   272,   272,   272,   273,
     273,   274,   274,   274,   274,   275,   275,   275,   276,   276,
     276,   277,   277,   277,   278,   278,   278,   279,   279,   280,
     280,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   283,   283,
     284,   284,   284,   284,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   286,   286,
     286,   286,   286,   287,   287,   288,   289,   289,   289,   289,
     289,   289,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   293,   293,   293,   294,
     293,   295,   293,   296,   293,   297,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     298,   293,   299,   293,   300,   293,   301,   293,   302,   293,
     303,   293,   304,   293,   305,   293,   306,   293,   307,   307,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   309,   309,   309,   309,   309,   310,   310,   310,
     311,   311,   312,   313,   313,   314,   314,   315,   315,   316,
     316,   317,   317,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   319,   319,   319,   320,   320,   320,
     321,   321,   321,   321,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   324,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   325,   325,   325,   325,   325,   326,
     326,   326,   326,   327,   327,   328,   328,   328,   328,   328,
     328,   329,   329,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   331,   331,   331,   331,   332,   332,   332,   332,   333,
     333,   334,   334,   335,   335,   335,   335,   335,   335,   335,
     335,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   337,   336,   338,
     338,   339,   339,   340,   340,   340
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       7,     7,     7,     9,     6,     6,     6,     8,     0,     2,
       2,     2,     2,     2,     1,     3,     1,     3,     0,     0,
      10,     1,     3,     0,    13,     1,     3,     0,    15,     8,
      14,     0,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     7,     7,     4,     3,
       6,     6,     7,     7,     6,     6,     9,     9,     6,     6,
       7,     7,     6,     6,     4,     8,     8,     9,     9,     9,
       9,     8,     8,     9,     9,     9,     9,     6,     9,     6,
       9,     5,     8,     8,    11,     6,     9,     5,     7,     9,
       9,    11,     7,     9,     9,     0,     1,     0,     3,     5,
       0,     9,     0,    11,     0,    11,     5,     0,     9,     0,
       3,     3,     5,     5,     0,     2,     3,     5,     3,     0,
       2,     3,     3,     3,     5,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     0,     5,     0,
       2,     7,     7,     7,     8,     8,     7,     7,    11,     8,
       7,     8,     8,     8,     9,     3,     4,    10,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     8,    12,
       8,     7,     8,     7,     8,     8,     8,     8,     8,     8,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,    14,    14,    14,    14,     8,     8,     6,     4,     6,
       6,     3,     4,     5,     6,     5,     3,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     9,     2,     3,
      10,     8,     8,     8,    12,    12,    12,    14,    14,    14,
       0,    12,     0,    12,     0,    12,     0,    16,     0,    16,
       0,    16,     0,    18,     0,    18,     0,    18,     1,     2,
       5,     7,     9,     2,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     6,     7,     6,     8,     5,     3,     8,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
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
       4,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     4,     4,     4,     4,     3,
       6,     1,     4,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     8,
       6,     4,     6,     4,     1,     4,     4,     0,     6,     1,
       3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   342,   343,   344,   345,
     346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,   284,   285,     0,     0,     0,   279,     0,
       0,     0,     0,     0,   397,   398,   399,     0,     0,     5,
       6,     7,     8,    10,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,   594,     0,   446,   593,   561,   447,   449,   450,   448,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     563,     0,   584,   565,   454,   455,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   451,   452,   453,
     564,     0,     0,     0,     0,    70,    71,     0,     0,   220,
       0,     0,     0,   404,     0,   553,   594,   461,     0,     0,
       0,     0,   263,     0,   265,   266,   261,   262,     0,   267,
     268,   127,   139,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,     0,     0,   593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,   525,     0,   526,   495,
     298,   496,   594,   461,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593,     0,   220,   594,     0,     0,
     394,     0,     0,     0,     0,     0,     0,     0,     0,   502,
       0,   501,     0,     0,     0,     0,     0,   593,     0,     0,
     547,     0,     0,     0,     0,   259,   260,     0,   593,     0,
       0,     0,   277,   278,     0,   220,     0,   220,   593,     0,
     594,     0,     0,   220,   400,     0,     0,    70,    71,     0,
       0,    63,    67,    66,    65,    64,    69,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,   406,   408,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
     218,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
     252,     0,     0,   469,   185,     0,   593,     0,   553,   594,
     554,     0,     0,   589,     0,   125,   125,     0,     0,     0,
       0,   541,   542,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,   508,     0,     0,   509,     0,   510,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,   406,   503,
       0,   497,     0,     0,     0,    70,    71,     0,     0,     0,
       0,     0,     0,   299,     0,   357,   357,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   220,     0,   486,   485,     0,
       0,     0,     0,   220,   220,     0,     0,     0,     0,     0,
       0,     0,   295,     0,   220,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,   241,   395,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   368,   258,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,   281,   280,     0,
     246,     0,   247,     0,     0,     0,   220,     0,     0,     0,
       0,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,   405,    63,    64,     0,     0,    63,     0,     0,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,   422,   421,   420,   419,   415,
     416,   418,   417,   410,   409,   411,   412,   413,   414,     0,
       0,     0,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   351,     0,     0,     0,     0,     0,     0,     0,
     387,   388,   389,     0,     0,     0,   474,    72,    73,     0,
     527,     0,     0,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,   513,     0,
     514,     0,   515,     0,     0,     0,   405,   498,   505,     0,
     411,   504,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,   355,     0,     0,     0,   155,   156,     0,
     158,   159,     0,   161,   162,     0,   164,   165,     0,   391,
       0,   392,     0,   393,     0,     0,     0,     0,   390,   220,
       0,     0,     0,     0,     0,   488,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     371,     0,     0,   242,     0,     0,   238,     0,     0,     0,
     386,   385,     0,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   283,     0,     0,   248,   250,
       0,   595,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,    63,    64,     0,     0,     0,     0,    94,    78,
       0,   463,   462,   476,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   445,   433,     0,   435,   436,   437,   438,
     439,   440,   441,     0,     0,     0,   574,     0,   581,   570,
     571,   572,     0,   586,   585,     0,   481,     0,     0,     0,
       0,   575,   576,   577,   483,   583,   144,   149,   117,     0,
       0,   566,     0,   568,     0,   459,   466,   467,   562,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,   468,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   591,     0,
       0,    48,     0,     0,     0,    61,     0,    39,    40,    41,
      42,    43,   465,   464,     0,     0,   559,    28,    26,     0,
       0,     0,     0,    29,     0,     0,   253,   590,    74,   128,
      75,   140,     0,     0,     0,   543,   544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,   463,   462,     0,     0,   531,     0,   530,   529,
       0,     0,   538,     0,     0,   507,     0,     0,     0,     0,
       0,     0,     0,   540,   499,     0,     0,     0,   465,   464,
       0,     0,     0,     0,     0,   405,   353,   358,   356,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     405,   405,   405,     0,     0,     0,     0,     0,   249,   251,
       0,     0,     0,   210,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,   370,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,     0,     0,     0,     0,   245,     0,   348,     0,
       0,     0,     0,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   592,     0,     0,   471,     0,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,    92,     0,     0,    80,     0,     0,     0,     0,
      84,   107,   109,     0,     0,   551,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   423,     0,
       0,     0,     0,     0,    34,   473,   472,   557,   555,    27,
       0,     0,   558,   556,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   169,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   516,
     517,   518,   519,     0,   506,   500,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,   157,     0,   160,
       0,   163,     0,   166,     0,     0,     0,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   334,     0,     0,   333,     0,   336,     0,   338,
       0,   296,   329,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,   372,     0,   240,   239,   396,
       0,     0,    35,    36,     0,     0,     0,     0,   548,     0,
       0,     0,   272,     0,     0,     0,   220,   349,   220,     0,
       0,     0,     0,    89,     0,    93,     0,     0,    81,     0,
      85,     0,   255,   475,   254,   434,   442,   443,   444,   582,
       0,     0,   580,   479,   480,   482,     0,     0,   458,   145,
       0,   588,   150,   478,   567,   569,   460,     0,     0,     0,
      90,     0,     0,     0,    63,     0,     0,     0,     0,    82,
       0,     0,     0,   549,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   493,     0,
       0,    30,    31,     0,    32,     0,     0,   129,   136,     0,
       0,    76,    77,   171,     0,     0,     0,     0,     0,     0,
     172,     0,     0,   188,   189,     0,     0,     0,     0,   173,
     201,   190,   194,   195,   191,   192,   193,   180,     0,     0,
       0,   475,   534,   533,   532,     0,     0,     0,     0,     0,
       0,     0,   203,   535,   196,     0,     0,   167,     0,     0,
     364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,   220,   220,     0,
     310,     0,   312,     0,   314,     0,     0,   335,   495,     0,
       0,   337,   339,     0,     0,   290,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,     0,     0,     0,
       0,   176,   177,     0,     0,     0,     0,   118,   122,     0,
       0,   347,   347,     0,   402,     0,     0,     0,    91,     0,
       0,     0,    83,     0,   477,     0,     0,     0,     0,     0,
       0,   101,     0,     0,    95,     0,     0,     0,     0,   112,
       0,     0,   113,     0,   552,   222,   223,   224,   225,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,    46,   560,     0,     0,   130,   137,     0,     0,     0,
       0,   170,   174,   175,   181,     0,     0,   200,     0,   183,
       0,     0,   366,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,   204,   354,   202,   206,   207,   208,
     209,   179,     0,   198,   205,     0,     0,     0,     0,     0,
       0,   492,     0,   491,     0,     0,     0,   301,     0,     0,
     302,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,   369,    37,     0,     0,   546,
       0,   274,   273,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,    96,     0,     0,     0,   573,   579,   578,
       0,   146,   148,     0,   151,   152,   153,   103,   105,    97,
      99,   108,   110,     0,   116,     0,    86,    49,     0,     0,
       0,   494,     0,     0,     0,    33,     0,   144,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
     537,     0,     0,     0,     0,     0,     0,   184,     0,   361,
     361,     0,   123,   124,   220,     0,   213,   214,     0,     0,
       0,     0,     0,     0,   297,     0,   330,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   216,
       0,     0,     0,     0,   119,   120,     0,     0,   350,     0,
     104,   106,    98,   100,    87,     0,   541,   542,     0,     0,
     550,     0,    45,     0,     0,     0,    47,    62,     0,     0,
       0,   134,   132,   380,   382,   381,   383,     0,   384,   187,
       0,     0,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   341,     0,
       0,     0,   291,     0,   227,     0,     0,     0,     0,     0,
       0,     0,   545,   275,     0,     0,   220,   403,     0,   147,
       0,     0,   154,   114,     0,     0,     0,     0,     0,   131,
     138,   144,   144,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   373,     0,     0,   374,     0,   211,
       0,   316,     0,     0,   318,     0,     0,   320,     0,     0,
       0,   331,     0,   287,     0,   220,     0,     0,     0,     0,
       0,     0,   178,   121,   271,   347,     0,   141,     0,     0,
      53,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,   377,     0,   378,   379,   489,
     304,     0,     0,   311,   305,     0,     0,   313,   306,     0,
       0,   315,     0,     0,     0,   293,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,   324,     0,   326,   332,   340,   292,
     288,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,    50,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   307,     0,     0,   308,     0,
       0,   309,     0,     0,   231,   232,   233,   234,     0,   228,
     352,     0,    51,     0,     0,   264,     0,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,   317,     0,   319,     0,   321,     0,   229,
      52,    54,     0,    55,     0,   520,   521,   522,   523,     0,
       0,     0,     0,     0,     0,     0,    60,   375,   376,   323,
     325,   327,    56,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   109,  1119,   110,   111,   799,  1734,  1740,
    1107,  1349,  1951,  2191,  1108,  2127,  2232,  1109,  2193,  1110,
    1111,  1353,   408,   503,   211,   860,   112,   817,   515,  1877,
    2032,  2031,  1878,   516,  1945,  1312,  1529,  1313,  1532,   906,
     909,   912,   915,  1597,  1587,   781,   285,   479,   480,   115,
     116,   117,   118,   119,   120,   121,   122,   286,  1242,  2064,
    2151,   945,  1798,  1801,  1804,  2101,  2105,  2109,  2176,  2179,
    2182,  1238,  1239,   287,   994,   288,   126,  1423,  1199,   903,
     959,  1981,   127,   128,   129,   130,   289,   213,  1056,   618,
     323,  1567,   361,   362,   291,   582,   369,  1087,  1336,   513,
     508,  1057,   514,   390,   293
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1819
static const yytype_int16 yypact[] =
{
   11570,    55,    27, 11715, -1819, -1819,  4920,    78,   -23,  -155,
    -123,    40,   107,   177,   218,   243,   -98,   247,   262,    56,
      79,   176,   176,  -195,   110,   114,    22,   144,   153,    32,
     163,   198,   206,   228,   237,   252,   255,   276,   286,   290,
     219,   258,   274,   389,   297,    74,   309,  6563,   330,   343,
     459,   -37,   488,   506,   895,   830,   201,   392,   541,   -53,
     415,  -128,  -128,   437,   523,    52, -1819, -1819, -1819, -1819,
   -1819,   412,   487,   612,   628,     6,    58,   631,   622,   316,
     725,   734,   743,  6113,   753,   550,   553,   568,    21,    12,
   -1819,   572,   584, -1819, -1819,   839,   845,   651, -1819,   448,
     640,  4394,    37,    38, -1819, -1819, -1819, 11133,   672, -1819,
   -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819,
   -1819, -1819, -1819, -1819,  -168, -1819, -1819, -1819, -1819,    57,
   -1819,  -153,   138, -1819,    16, -1819, -1819, -1819, -1819, -1819,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   684,   741,   751,   176,   176,
     176,   176,   754,   176,   176,   176,   176,   176,   176,   762,
   -1819,   176, -1819, -1819, -1819, -1819, -1819,   176,   176,   999,
     781,   849,   850,   176,   176,   855,   859, -1819, -1819, -1819,
   -1819,   710, 11133, 11133, 11133, 10270, 10489,    18,    14,   346,
     758,   785,   994, -1819,   829,  1008,   -73,   -67,  1019, 11133,
    4343,  4343, -1819, 11133, -1819, -1819, -1819, -1819,  4343, -1819,
   -1819, -1819, -1819, -1819, -1819,  2374,    14, 11133,  9978, 11133,
   11133,   864, 11133,  9978, 11133, 11133,   865, 11133,  9978, 11133,
   11133, 11133, 11133, 11133, 11133,  4343, 11133, 11133, 11133,  6788,
     882,   900, -1819,  9978,  6113,  6113,  6113,  4343,   735,   443,
     176,   176,   176,   176,    36,    28,    34,    42,  6788,   658,
     921,   176,  7013, 11133,  5424, -1819, -1819,   901, -1819,  3022,
   -1819, -1819,   332,   470, 11133,  9978,   911,   916,  7238,  6113,
    6113,  6113,   933,   941,   951,   971,   972,  7463,  7688,  7913,
     939,  9634,  1117,  6788,    21,  1003,  1021,  -128,  -128,  -128,
   11133, 11133,  -182, -1819,   -79,  -128,  1050,  1051,  1060,  9859,
     -65,    93,  1024,  1068,  1092,  1097,  1100,  1109,  1113, 11133,
    6113,  6113,  6113,  1121,    15,  1123, -1819,   891,  1241,  1346,
   -1819,  1138,  1149,  1161,  6113,  6113,  1159,  1167,  1169, -1819,
   11133, -1819,  1369,  1393, 11133, 11133, 11133,  -135, 11133,  1171,
   -1819,  1230, 11133, 11133, 11133, -1819, -1819, 11133,  1170,  1403,
    1404,  1178, -1819, -1819,  1408, -1819,  1409, -1819,   647, 10223,
     432,  4343, 11133, -1819, -1819,  6788,  6788, 10556, 10775,  1186,
    1187,  2374, -1819, -1819, -1819, -1819, -1819, -1819,  6788,  1415,
    1198, 11133, 11133,  1424, 11133, 11133, 11133, 11133, 11133, 11133,
   11133, 11133, 11133, 11133, 11133, 11133, 11133, 11133, 11133, 11133,
   11133, 11133, 11133, 11133, 11133, 11133,  4343,  4343,  4343,  4343,
    4343,  4343,  4343,  4343,  4343,  4343,  6788,  4343,  4343, 11133,
    4343,  4343,  4343,  4343,  4343, 11133,  2374, 11133,  4343,  4343,
    4343,  4343,  4343,    14,  2374,    14,  1209,  1209,  1209,    25,
   13226,   194,  4494,   265,  1220,  1445,   176,  1221, -1819,  1222,
    5223, 11133,  9978, -1819, 11133, 11133, 11133, 11133, 11133, 11133,
   11133, 11133, 11133, 11133, 11133, 11133, 11133, 11133, 11133, -1819,
   -1819, 11133, 11133, -1819, -1819,  1013,   746,     0, -1819,   591,
   -1819,   405, 10607, -1819,   424,   196,   232,  1223,  1225, 13247,
    9978,  3043, -1819,   531, 13268, 13289, 11133, 13310,   575, 13331,
   13352, 11133, 13373,   601, 13394, 13415, 13436, 13457, 13478, 13499,
    1232, 13520, 13541, 13562,  1451, 11133, 11133,   625,  1455,  1457,
    1458,  1238, 11133, 11133,  1462,   439,  8138,  8363, 11133, 11133,
    4343, 11133, -1819,  1405, 11133, -1819,  1406, -1819,  1407, -1819,
    1410,  6788,    43,    44,    45,    47,  9978,  9978,  1209, -1819,
   13583, -1819,   638, 11133,  8588, 11133, 11133,   596, 13604,   649,
   11133, 11133, 11133, -1819,  1464,  1482,  1482, 11133, 10197, 10197,
   10197, 10197, 11133,  1484, 11133,  1485, 11133,  1488,  9978,  9978,
   10321,  1268,  1490,  1264, -1819, -1819,   -84, -1819, -1819, 10679,
   10721,  -128,  -128,   346,   346,    98, 11133, 11133, 11133,  9859,
    9859, 11133,   840,   140, -1819, 11133, 11133, 11133, 11133, 11133,
   11133, 11133, 11133, 11133, 13625,  1495,  1500,  1501, 11133,  1503,
   11133, 11133,  2612, -1819, -1819,  9978,  9978,  9978,  1504,  1505,
   11133, 11133, 11133, 13646, -1819, -1819, 13667, 13688, 13709,  1340,
   10801, -1819,  1279,  3320, 13730, 13751, 11381, -1819, -1819,  9978,
   -1819,  3191, -1819,  3277, 11133, 11133, -1819, 11133, 11133,  1287,
   13772,  4669,  1291,   705,   342, 13793,   360, 12881, 11133,  9978,
    1515,  1516, -1819, 11133, 13814, 12904,   -64,  4155,  4155,  4155,
    4155,  4155,  4155,  4155,  4155,  4155,  4155,  4155, 10898,  4155,
    4155,  4155,  4155,  4155,  4155,  4155, 10965, 11007, 11091,   -88,
     595,   -88,  1298,  1299,  1295,   737,   737,  1296,   737,  1297,
    1300,  1301, 11289,   737,   737,   737,   586,   737, 14570, -1819,
    1089,  1302,  1304,  1303,   679,   757,  1310,  1311,  1321,  1487,
    1508,  6788,   318,  1513,  1514,  6788,    97,  2374, 11133,  1533,
    1560,    24,   737, -1819,   133,    33,    41,   148,  1339,   -33,
     856, -1819,  3772,   792,  3549,  1502,  1551,   836,   836,   630,
     630,   630,   630,     1,     1,  1209,  1209,  1209,  1209,    13,
   13835, 12927, -1819, 11133, 11133,  1563,     9,  9978, 11133, 11133,
    1562,  9978, 11133,  1565,  4343,  1566, -1819,    14,  1568,  4343,
   11133,  2374,  1569,  9978,  9978,  1399,  1586,  1587, 13856,  1588,
    1427,  1591,  1592, 13877,  1596,  1434,  1598,  1603,  1604,  1605,
    1607,  1608, -1819,  1613,  1614,  1618, 11133, 13898,  4655,  1342,
   -1819, -1819, -1819,  1620, 13919, 12950,   470, -1819, -1819,  9978,
   -1819,  9978,  3043,  1400,  9978,  1401,   391, 11410, 11711,   737,
   11737,  1395,  4812,  1396,  1398,  1402, -1819,  9978, -1819,  9978,
   -1819,  9978, -1819,  9978,   737,   798,  1625, -1819,  3568,  9978,
    1209, -1819, 13940, 12973,  9978, -1819,  1626,  1411, 13961, 13982,
   14003, 11133,  6788,  1630,  1632, 14024,  1412, 14570,  1416,  1414,
   14570,  1417,  1420, 14570,  1432,  1439, 14570,  1435, 14045, -1819,
   14066, -1819, 14087, -1819,   799,   826,  9978,  1413, -1819, -1819,
    3388,  3591,  -128, 11133, 11133, -1819, -1819,  1436,  1438,  9859,
   11763, 11789, 11815, 10515,  1520,   -29,  -128,  4578, 14108,  4840,
   14129, 14150, 14171, 14192, 14213, 14234, 14255,  1662, 11133,  1667,
   -1819, 11133, 14276, -1819, 12996, 13019, -1819,   831,   832,   837,
   -1819, -1819, 13042, 13065, 11841, -1819,  1668,  1669,  1672,  1444,
   11133,  5111, 11133, 11133, -1819, -1819,     7,   848, -1819, -1819,
   11281, -1819,  1674, 10847,  1452,  1454,  6788,  1679,  1634,  1647,
    6788,   318,  1648,  1649,  6788,   318,  4868,   869, -1819, -1819,
   13088,   122,   130, -1819, -1819, -1819, -1819, -1819, -1819, -1819,
   -1819, -1819, -1819, -1819, -1819, 11133, -1819, -1819, -1819, -1819,
   -1819, -1819, -1819, 11133, 11133, 11133, -1819,  9978, -1819, -1819,
   -1819, -1819,  4343, -1819, -1819, 11133, -1819,  6788,  4343,  4343,
    4343, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, 11133,
    4343, -1819,  4343, -1819, 11133, -1819, -1819, -1819, -1819,   176,
     176,  1688, -1819, 11133,  1693,   176,   176,  1695,    26, 11133,
    1696,  1697,  1228, -1819,  1699,  1480,    21,  1703, -1819,  9978,
    9978,  9978,  9978, 11133,  1498,  1506,  1507,  1524, -1819,   737,
   11133, -1819,  1525,  1526,  1493, -1819,  1722, -1819, -1819, -1819,
   -1819, -1819,   154,   303, 14297, 13111, -1819, -1819,  1517,  4343,
     633, 14318, 13134, -1819,   689, 11867, -1819, -1819, -1819,    59,
   -1819, -1819,  4155,   737,  -128,  3043, -1819,   978,  6788,  6788,
    1724,  6788,  1017,  6788,  6788,  1727,  6788,  1637,  6788,  6788,
    6788,  6788,  6788,  6788,  6788,  6788,  6788,  1267,  1748,  1749,
    9978, -1819,   470,   253,   880,   881, -1819,   885, -1819, -1819,
   11133, 11133, -1819, 11133, 11133, -1819, 11133, 11133, 11133,   886,
     893,   898,   924, -1819, -1819,  6788, 11133,   930,   470,   470,
     931,  6788,  9978,  1750,  1751,  1768,  3523, -1819, -1819,  1771,
   -1819,  1772,   366, 11133,   366, 11133,   366, 11133,   366, 11133,
    1773,  1774,  1775,  1776,  1779,   934,  1783, 11320, -1819, -1819,
     152, 11893, 11919, -1819, -1819,  5043,  -108,  -128,  -128,  -128,
    1676,  1784, 11066,  1558,  1786,  1567,    48,    54,   -32, -1819,
     159, -1819,   -29,  1787,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1797,  6788, 14570, -1819,  1371,  1573,  1801,  1802,  1804,
    1706,  1805,  1807,  1808, 11133,  6788,  6788,  6788,  1811, 11945,
   -1819,  3624,   202,  1812,  1814,  1579, -1819,  1589, -1819,  1443,
    1590,  6788,  1585, -1819,   176,   176,  1815, 11133,  1818,   176,
     176,  1819, 11133,  1820, -1819,   737,  1821, -1819,  1816, -1819,
    1822,  4155,  4155,  4155,  4155,   763,  1597, 10430,  1606,   737,
     737,  1599,   788,   811, 14339,  1609,   737,  4155,  1496,  4343,
   -1819,  1529, -1819,  1496,  4343, -1819,   328,  1602,  1827,  1671,
   -1819, -1819, -1819,    21, 11133, -1819,   946, -1819,   949,   952,
     953,   961, 14360, 11133, 11133, 11133, 11133,   366, 14570,  1611,
   11133, 11133,  6788,  1610, -1819, -1819, -1819, -1819,  1612, -1819,
    1832,    23, -1819, -1819,  1833, 11133,  9263,  1617,  1616,  1834,
    1835,    77,  1615,  1619,  1731,  1731,  6788,  1843,  1621,  1622,
    1845,  1847,  6788,  1687,  1629,  1852,  1853,  1857,  1858,  1859,
    1860,  1862,  1864,  1865, -1819,  1867,  6788,   962,  1869,   737,
    1665,  1645, 11971, 11997, 12023, 12049, 12075, 12101, 12127, -1819,
   -1819, -1819, -1819,  1887, 14570, -1819,   737,  1888,   983,  6788,
    6788,  6788,  1871,  1891, -1819,  6788,  6788, 14570,  6788, 14570,
    6788, 14570,  6788, 14570,  6788,  6788,  6788,  1666,  1670,  1894,
     185, -1819, 11133, 11133, 11133,  1673,  1675,  -148,  -140,  -105,
    1677,  1681, -1819,  1953,  6788, -1819, 11133, -1819,  1898, -1819,
    1899, -1819, -1819,  9859,   477,  6338, -1819,  1678,  1680,  1683,
    1684,  1685,  1689,  8813,  1901, -1819,  9978, -1819, -1819, -1819,
    1690, 11133, -1819, -1819, 13157,  1906,  1918,  1759, -1819, 11133,
   11133, 11133, -1819,  1923,   835,  2374, -1819, -1819, -1819,  1698,
    1954,  1496,  4343, -1819,  2114, -1819,  1496,  4343, -1819,  2151,
   -1819,   366, -1819,   582, -1819, -1819, -1819, -1819, -1819, -1819,
    4343, 11133, -1819, -1819, -1819, -1819,  4343,  1957, -1819, -1819,
      17, -1819, -1819, -1819, -1819, -1819, -1819,  1956,   -88,   -88,
   -1819,  1958,   -88,   -88,  2374, 11133,  1959,  1962,    24, -1819,
    1961, 13180,    21, -1819,  1963,  1968,  1969,  1970,  1625, 14381,
   14402, 14423, 14444,  6788, 11133, 12153, 12179,   984, -1819, 11133,
    1964, -1819, -1819,  4343, -1819, 12205,  5663, 14570, -1819,  1972,
    1973, -1819, -1819, -1819, 11133, 11133,  -128,  1975,  1976,  1977,
   -1819, 11133, 11133, -1819, -1819,  1978,  1875,  1979, 11133, -1819,
   -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819,  1982,  1986,
    1755,   470, -1819, -1819, -1819, 11133, 11133, 11133, 11133, 11133,
   11133, 11133, -1819, -1819, -1819,  1760,  1988,  1687,  1989, 11133,
   -1819,  1992,  1994,  1996,  1997,  1999,  2002,  1231,  2004,  9978,
    9978, 11133, -1819, 10197,  5155, 14465,  3912,   346,   346,  -128,
    2005,  -128,  2006,  -128,  2008, 11133, 11133, -1819,   375,  1785,
   14486, -1819, -1819,  5183,   169, -1819,  2009,  2013,  6788,  -128,
    -128,  -128,  -128,  -128,  1917,  2014, -1819,  1007, 11133,  2544,
    2015, -1819, -1819,  6788,  4354,   472, 14507, -1819, -1819,  9336,
    1799,  4669,  4669,  6788, -1819,  2016,   -88,   -88, -1819,  2017,
     -88,   -88, -1819,  6788, -1819,  1798,  4155,   737,  5888,  9561,
    2374, -1819,  2018,  2020, -1819,  2021,  2023,  2026,  2598, -1819,
    2027,  2029, -1819,  1809, -1819, -1819, -1819, -1819, -1819,  1768,
    1773,  1774,  1775,  2031,   730, 14570, 11133, 11133,  6788,  1823,
    1010, 14570, -1819,  2032, 11133, -1819, -1819,  1824,  1826,  5362,
    5601,   676, -1819, -1819, -1819,  5826,  6051, -1819,  1829, -1819,
    6276,  2035, -1819,  6788,  4155,  4155, 12231, 12257, 12283, 12309,
   12335, 11133, -1819,  2036, -1819, 14570, -1819, -1819, -1819, -1819,
   -1819, -1819,  1830, -1819, -1819,  1011,  1014, 10388,  2675,  2049,
    1836, -1819, 11133, -1819,  1837,  1838,   191, -1819,  1840,   214,
   -1819,  1841,   250, -1819,  1842,  6501, 13203,  2054,  6788,  2034,
    1844, 11133, -1819, -1819,  1023,   269,   293,   323,   327,   385,
    9038,   387, -1819,  2064,  6726, -1819, -1819,  1911, 11133, -1819,
   11133, -1819, -1819,  9978,  2715,  2072,  2374,  1848,  1849,  1851,
   -1819,  2073,  2075, -1819,  2080,  2082,  2083, -1819, -1819, -1819,
    5424, -1819, -1819,  4343, 14570, -1819, -1819, -1819, -1819, -1819,
   -1819, -1819, -1819,    21, -1819,  1922, -1819, -1819, 11133, 12361,
   12387, -1819,  6788, 11133,  2085, -1819, 12413, -1819, -1819,  6788,
    6788,  2086,  2087,  2088,  2089, 11133,  2090,  2091,  1026, -1819,
   -1819, 11133, 11133, 11133, 11133, 11133,  6951, -1819,  6788,   581,
     712,  9978, -1819, -1819,   346,  4627, -1819, -1819,  9859,   -29,
    9859,   -29,  9859,   -29, -1819,  2092, -1819,  1027,  6788, -1819,
    7176,  2093,  9978,  -128,  -128,  -128,  -128,  -128, -1819, -1819,
   11133,  7401,  7626,  1033, -1819, -1819,  1873,  1868, -1819,  2097,
   -1819, -1819, -1819, -1819, -1819,  1034,  2041,  2098,  1037,  2102,
   -1819,  1876, 14570, 11133, 11133,  1038, 14570, -1819, 11133,  1042,
    1043, -1819, -1819, -1819, -1819, -1819, -1819,  7851, -1819, -1819,
    1877, 12439, 12465, 12491, 12517, 12543, -1819,  1047,  1883,  -128,
    6788,  2111,  1885,  -128,  2115,  1048,  1870, 11133, -1819,  8076,
     395,   556,  8301,   423,   715,  8526,   425,   749, -1819,  6788,
    2116,  2001, 11375,  1892, -1819,  1057,   427,   429,   482,   484,
     534,  2736, -1819, -1819,  2118,  2120, -1819, -1819, 11133, -1819,
    2374,    14, -1819, -1819, 11133, 14528, 12569,    49, 12595, -1819,
   -1819, -1819, -1819, -1819, 11133, 11133, 11133, 11133, 11133, 11133,
    2121,  -128,    96, -1819, -1819,  -128,   117, -1819,  2122, -1819,
    8751,  2123, 11133,  2124,  2125, 11133,  2126,  2129, 11133,  2131,
    1905, -1819, 11133, -1819,   -29, -1819,  2134,  9978,  9978,  9978,
    9978,  9038, -1819, -1819, -1819,  4669,  1147, -1819,  1915,  1058,
   -1819, 11133, -1819,  6788, 11133,  1078,  1079, 12621, 12647, 12673,
   12699, 12725, 12751, -1819,   536, -1819,   538, -1819, -1819, -1819,
   -1819,  1909,  8976, -1819, -1819,  1912,  9211, -1819, -1819,  1914,
    9292, -1819,  2138,  2874,   765, 11440, -1819,  1085,  1090,  1102,
    1106,   543,  1112,  1920,  2374,  1925,  2143,  1941, 14549,  1116,
    9466, -1819, -1819, 11133, 11133, 11133, 11133, 11133, 11133,  -128,
    -128,   -29,  2149,   -29,  2150,   -29,  2152, -1819, -1819, -1819,
   -1819,   -29,  2169,  2170,  2171,  2173,  9978,  2174,  2175, -1819,
   -1819, -1819,  4343, -1819,  1960,  2181,  9508,  4155, 12777, 12803,
   12829, 12855,   555,   580,   888, -1819,  1965,   945, -1819,  1967,
     957, -1819,  1971,  1022, -1819, -1819, -1819, -1819,  1136, -1819,
   -1819,  1142, -1819,  1974,  6788, -1819,  2183, -1819, 11133, 11133,
   11133, 11133, 11133, 11133,  2184,   -29,  2186,   -29,  2188,   -29,
   -1819,  2189,  4343,  2190,  4343,  1146, -1819,  9588,  9691,  9733,
    9916, 10102, 10144, -1819,  1259, -1819,  1366, -1819,  1470, -1819,
   -1819, -1819,  1154, -1819,  2191, -1819, -1819, -1819, -1819,  2196,
    2199,  2200,  2202,  2204,  4343,  2206, -1819, -1819, -1819, -1819,
   -1819, -1819, -1819, -1819
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1819, -1819, -1819, -1819,   852, -1819, -1819, -1819, -1819,   190,
   -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819,
   -1819, -1819,  -372,    11,  4456,  3589, -1819,  1700, -1819, -1819,
   -1819, -1819, -1819, -1819, -1819, -1818, -1819,   337, -1819, -1819,
   -1819, -1819, -1819,   594,   851,  2232,    -2,  -619,  -306, -1819,
   -1819, -1819, -1819, -1819, -1819, -1819, -1819,  2236, -1819, -1819,
   -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819, -1819,
   -1819, -1236, -1230,  2237, -1679,  2239, -1819, -1819, -1819,  1650,
   -1819,   344, -1819, -1819, -1819, -1819,  1980, -1819, -1819,  1067,
   -1819, -1657,  2820,   987,  3344,  3400,  -312,   697, -1819,   341,
      64, -1819,  -429,    -3,   283
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -561
static const yytype_int16 yytable[] =
{
     131,   114,   613,   216,   937,   938,  1464,   729,  1462,   731,
     344,  1814,  1837,  1838,  1273,  1117,   371,  1101,   378,   649,
     410,  1709,   473,   632,   746,   367,   241,     5,  1085,  1572,
    1326,   237,   759,   565,   621,   622,   246,   241,   238,   567,
     652,   562,   384,   386,   292,   246,   222,   569,   876,   878,
     880,   623,   882,   297,  1457,  2082,   331,   297,   392,  1959,
    1459,     4,   349,   394,   350,   393,  1366,   219,   621,   622,
     215,   220,   347,   397,   298,   398,   621,   622,  1094,   681,
     292,   683,   399,  1583,  1649,   347,  1650,   691,   318,   319,
    1231,   218,  1651,  1231,  1652,   669,   347,   761,   320,   765,
     210,   768,  2095,   221,  1072,   321,  1888,  1232,   621,   622,
    1232,   621,   622,   224,   314,  1233,  1234,  1235,  1233,  1234,
    1235,  1236,  1237,  2097,  1236,  1237,  1446,  1653,   228,  1654,
     315,   316,   621,   622,   506,   135,   332,   621,   622,   857,
     333,   858,   351,   409,   814,   401,   334,   335,   932,   336,
     337,   621,   622,   501,   624,   502,   406,   407,   264,   406,
     407,   265,   399,   379,   266,   383,  -554,   338,   634,  -559,
    1102,  1103,  1104,  1105,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   225,   345,   474,   475,   175,   176,   177,
     178,  1642,  1643,  1327,  1328,   180,   181,   182,   566,  1710,
     183,   763,  1461,  1458,   568,   347,   563,   478,   108,  1460,
    1491,   188,   570,  2085,  2086,  1955,   108,   509,   509,   495,
     496,   497,  1118,   108,   226,   509,   498,   806,   402,   403,
     404,   760,   807,   347,  1462,   292,  1118,  1274,   372,   346,
     292,  1977,   411,   650,   412,   292,   413,  1106,   242,   227,
     210,   210,   509,   229,   368,   243,   292,  1086,   247,   242,
     292,   292,   292,   292,   509,   248,  1090,   247,   230,   564,
     385,   387,   767,   223,  1091,   292,   877,   879,   881,   292,
     883,   292,  2083,   395,   231,  1367,   132,  1368,   310,   217,
     396,   311,   292,   621,   622,   292,   292,   292,   292,   517,
     402,   403,   404,   405,   292,   292,   292,   232,   930,   931,
     292,   347,   621,   622,   621,   622,   191,   192,   193,   635,
     406,   407,  1000,   259,  1004,  1072,   636,  1078,   947,   200,
     939,   201,   108,   621,   622,  1544,   239,   292,   292,   292,
     240,   402,   403,   404,   405,   406,   407,   214,   260,   998,
     477,   292,   292,   406,   407,  -557,   621,   622,   348,   237,
    1298,   406,   407,  -555,   261,   981,  1089,  1002,   621,   622,
     244,   370,   946,  1072,   250,   621,   622,   406,   407,   245,
     990,  1092,   380,   583,  1442,   621,   622,  -558,   509,   249,
    1073,  1463,   292,   292,  1079,   262,  2123,   402,   403,   404,
     764,  1811,   233,   354,   234,   292,   355,   621,   622,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,  1908,   250,   815,  2129,   498,   816,  1492,
     621,   622,   251,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   292,   509,   509,  1910,   509,   509,   509,
     509,   509,   378,   135,   252,   509,   509,   509,   509,   509,
     347,   818,   347,   253,   816,   700,   621,   622,   402,   403,
     404,   405,    60,    61,    62,    63,   406,   407,   254,   292,
    1830,   255,  1912,  1398,   769,   621,   622,    74,   406,   407,
      77,   476,   162,   163,   164,   165,   166,   167,   168,   169,
     170,  1922,   256,   510,   510,   175,   176,   177,   178,   621,
     622,   510,   257,   180,   181,   182,   258,   292,   183,   518,
     749,   402,   403,   404,   405,  1923,   406,   407,   757,   188,
     263,   402,   403,   404,   405,   267,  -556,  2215,   510,   621,
     622,   406,   407,   621,   622,   402,   403,   404,   999,   296,
     510,   406,   407,   292,   292,  1924,   294,   509,   585,  1925,
     586,   507,   511,   402,   403,   404,  1003,   399,   292,   402,
     403,   404,   405,   292,   292,   299,   295,   340,   300,   341,
     301,   292,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   584,   496,   497,   540,   370,   302,  1231,
     498,   621,   622,   621,   622,   292,   292,   326,   551,  1807,
     327,   621,   622,   328,   406,   407,  1232,  1926,   312,  1927,
    1169,   478,   478,  1217,  1233,  1234,  1235,  2052,   313,  1287,
    1236,  1237,   810,  1292,   191,   192,   193,   811,   339,   621,
     622,   621,   622,   621,   622,   621,   622,   200,   317,   201,
     108,   813,   292,   292,   292,  2055,   814,  2058,   687,  2067,
     688,  2068,   908,   911,   914,   917,   857,   399,   858,   556,
     325,   557,   859,  1991,   510,  1994,   292,  1997,  1231,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   406,   407,  1232,   292,   498,   621,   622,
     621,   622,   342,  1233,  1234,  1235,  1831,  1978,  1979,  1236,
    1237,  1665,   353,  1980,  2069,   343,  2070,  1013,   352,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   356,
     510,   510,   689,   510,   510,   510,   510,   510,   357,   318,
     319,   510,   510,   510,   510,   510,   756,   358,   758,   320,
     621,   622,   621,   622,   621,   622,   329,   363,   292,   621,
     622,  1462,   292,   824,  1462,   825,  2071,  1462,  2139,   571,
    2140,   621,   622,  1074,  1335,  2156,   364,  1080,   730,   365,
     732,   733,   734,   735,   736,   737,   738,  2202,   740,   741,
    2053,   743,   744,   745,   366,   747,   621,   622,   373,   751,
     752,   753,   754,   755,   292,   406,   407,   824,   292,   830,
     374,   509,  2203,  1054,   347,  -560,   509,   808,   814,   809,
     292,   292,   857,   857,   858,   858,   399,  1037,  2114,   894,
    1426,  1081,  1428,   824,  1430,   835,  1432,  1231,  1982,  1983,
     866,  1688,  1689,   510,  1980,   375,   493,   494,   495,   496,
     497,   376,     7,     8,  1232,   498,   292,   824,   292,   849,
    1361,   292,  1233,  1234,  1235,   824,   381,  1013,  1236,  1237,
     824,  1231,   887,   684,   292,   685,   292,   554,   292,   377,
     292,   824,   210,   897,  1462,  1133,   292,  1231,  1232,  1538,
    1539,   292,   621,   622,  1542,  1543,  1233,  1234,  1235,   292,
     391,   869,  1236,  1237,  1232,  2174,   857,  2177,   858,  2180,
     439,  1062,  1233,  1234,  1235,  2183,  1364,   307,  1236,  1237,
     308,   824,   309,   292,   774,    24,    25,   775,    27,    28,
     776,    30,   777,    32,    33,    34,    35,   996,   465,   997,
      37,    38,    39,  1095,  1462,    41,  1096,  1462,  1097,  2056,
    1462,   778,    48,  1462,  1545,    50,   779,  1867,    53,    54,
     780,   552,  1868,   553,   857,   554,   858,   440,   209,  2224,
     210,  2226,   803,  2228,   804,  1563,   805,   441,    71,   303,
     446,   210,   304,  2059,   857,   305,   858,   306,   453,  1064,
     857,   481,   858,   292,  1462,   824,  1462,   292,  1462,  2149,
     483,   292,    85,    86,    87,   572,   457,   458,   573,   509,
    1231,   574,  1288,   575,   500,   857,  1293,   858,   482,   802,
    1527,  1550,  1297,  1299,   824,   504,  1099,  1232,  1794,  1795,
     824,   824,  1184,  1213,   292,  1233,  1234,  1235,   857,   509,
     858,  1236,  1237,  1530,   292,   509,   509,   509,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   509,   824,   509,
    1214,   498,   499,   824,   824,  1259,  1260,  1231,  1372,   824,
    1373,  1261,  1696,  1697,   944,   459,   460,  1700,  1701,  1231,
     824,   463,  1275,   347,  1232,   464,   292,   292,   292,   292,
     526,   531,  1233,  1234,  1235,  1058,  1232,   510,  1236,  1237,
    1129,   824,   510,  1295,  1233,  1234,  1235,  1378,   545,  1379,
    1236,  1237,   824,   824,  1399,  1400,   509,   824,   824,  1401,
    1409,   611,  2204,  1355,  1356,   824,   399,  1410,   322,   324,
     824,   330,  1411,   546,   393,   292,   292,   590,   292,  1703,
     292,   292,   591,   292,  1231,   292,   292,   292,   292,   292,
     292,   292,   292,   292,  2124,  1127,   824,   292,  1412,   597,
    1131,  1232,   824,   824,  1415,  1416,   824,   598,  1439,  1233,
    1234,  1235,   608,  1297,  1299,  1236,  1237,   599,  1552,  2206,
    1553,   824,   292,  1554,   824,   824,  1555,  1556,   292,   292,
    1691,  2208,  1692,   824,   824,  1557,  1610,   600,   601,  1355,
    1356,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   824,  1738,  1625,  1739,   498,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,  1332,  1782,   614,  1783,   498,   824,
    1724,  1823,  1873,   824,  1874,  1899,   824,   653,  1900,   292,
     637,   548,   549,   550,   615,  1738,  2210,  1921,  1738,  1999,
    1970,  2000,   292,   292,   292,   824,  2018,  2014,  2019,   814,
    1738,  2022,  2027,  1394,  1527,  1530,  2029,  2030,   292,  1738,
     824,  2040,  2048,   626,   627,  1986,   594,   595,   596,   824,
    1873,  2066,  2126,   628,   638,   510,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
    1527,  1527,  2131,  2132,   498,   509,   509,   824,   639,  2152,
     509,   509,   824,   640,  2153,   510,   641,   645,   646,   647,
     347,   510,   510,   510,   824,   642,  2154,  1546,   824,   643,
    2155,   658,   659,   510,   824,   510,  2157,   648,  1738,   292,
    2164,   651,   654,  1300,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   824,   370,
    2211,   655,   498,   292,  2212,   664,  2213,  1475,  1738,   292,
    2234,  1231,   656,  1306,   616,   617,  2244,   660,  2245,  1309,
    1310,  1311,   625,   292,   657,   661,   633,   662,  1232,   665,
     672,  1315,   510,  1316,   671,   210,  1233,  1234,  1235,   677,
     678,   679,  1236,  1237,   680,   682,   292,   292,   292,   698,
     699,   702,   292,   292,  1948,   292,   703,   292,   706,   292,
    1578,   292,   292,   292,   498,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,  1497,
     770,   292,   771,   498,   209,   820,   773,   821,   846,   842,
    1360,   850,   292,   851,   852,   853,   856,   871,   873,   874,
     292,   901,   875,   292,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,  1231,   902,
     919,   921,   498,  2241,   923,   927,   928,   929,   509,   509,
     506,   135,   958,   509,   509,  1232,   960,   979,   961,   963,
     970,   971,   982,  1233,  1234,  1235,   991,   509,   995,  1236,
    1237,  1008,  1009,   509,  1704,  1040,  1041,  1042,  1045,  1047,
    1061,  1069,  1048,  1049,  1059,  1540,  1060,  1066,  1067,  1083,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   347,
    1068,  1949,  1070,   175,   176,   177,   178,  1075,  1076,  1690,
     292,   180,   181,   182,  1084,  1093,   183,  1116,  1123,  1137,
     509,  1126,  1128,   292,  1130,  1160,  1134,   188,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,  1231,  1138,  1139,  1141,   498,  1142,  1143,  1144,
    2242,   510,   510,  1146,  1147,  1148,   510,   510,  1717,  1232,
    1149,  1150,  1151,  2002,  1152,  1153,   370,  1233,  1234,  1235,
    1154,  1155,  1704,  1236,  1237,  1156,  1161,  1166,  1174,  1176,
    1168,  1177,  1185,  1191,  1198,  1178,   292,   292,  1200,  1202,
    1746,  1204,  1230,  1216,  1192,   478,   478,  1206,  1203,  1205,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,  1207,   292,  1208,  1209,   498,  1252,
    1223,   292,  1224,  1254,  1268,  1265,  1266,  1549,  1284,  1267,
     292,  1277,   191,   192,   193,  1283,  1280,  1281,   935,   936,
     292,  1285,  1289,  1290,  1320,   200,   617,   201,   108,  1322,
     292,  1325,  1330,  1331,  2243,   292,  1333,  1789,  1334,  1337,
    2075,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   857,  1343,   858,  1352,   498,  1354,  1384,
    1359,  1376,  1344,  1345,  1382,   292,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
    1346,  1350,  1351,  1835,   498,  1395,  1396,  1419,  1420,  2115,
     292,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,  1852,  1855,  1856,  1421,   498,  1424,  1450,  1425,
    1434,  1435,  1436,  1437,   510,   510,  1438,  1440,  1451,   510,
     510,  1454,  1455,  1456,  1465,  1466,  1480,  1467,  1468,  1469,
    1470,  1471,  1472,   510,  1473,   292,  1476,  1477,  1478,   510,
    1479,  1495,  1481,  1482,  1483,  1488,  1493,   292,  1494,  1500,
    1513,  1503,  1496,  1498,  1505,  1508,  1510,  1512,  1514,  1520,
     292,  1526,  1547,  1523,  1548,   370,  1534,  1564,  1571,  1574,
    1581,  1582,  1570,  1569,  1579,  1580,  1586,   292,  1584,  1590,
     509,  1593,  1585,  1594,  1591,  1592,   510,  1596,  1599,  1600,
     347,  1705,  1598,  1601,  1602,  1603,  1604,  1707,  1605,   292,
    1606,  1607,  1608,  1611,  1614,  1629,   292,   292,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,  1613,  1622,  1624,   292,   498,  1630,   292,  1639,
    1936,  1641,   478,  1640,  1661,  1662,  1647,  1676,  1648,  1656,
    1655,  1668,  1681,  1669,  1743,   292,  1670,  1671,  1672,   292,
     133,   268,  1673,  1678,  1682,  1683,   136,   137,   138,  1687,
    1693,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   269,   270,   271,   272,   273,  1657,
    1694,  1708,  1711,  1758,  1714,  1719,  1720,  1722,  1742,  1725,
     171,   172,   173,   174,  1726,  1727,  1728,   292,   179,  1747,
    1748,  1752,  1753,  1754,  1757,  1759,   212,  1761,  1763,   184,
     185,   186,  1762,  1771,  1772,  1774,   292,   187,  1776,  1220,
    1777,   274,  1778,  1779,   275,  1780,  1226,   276,  1781,   277,
    1784,  1797,  1800,  1240,  1803,  1812,    36,  1808,   347,  1813,
    1822,  1826,  1840,  1843,  1857,  1847,  1858,  1859,   278,  1860,
      49,  1836,  1861,   279,  1863,  1864,   280,  1866,  1875,  1865,
    1887,  1918,  1897,    60,    61,    62,    63,    64,  2020,   583,
      66,    67,    68,    69,    70,  1903,  1872,  1879,    74,  1880,
    1916,    77,  1885,  1898,   292,   292,   292,   292,   292,  1904,
    1928,  1906,  1907,  1909,  1911,  1913,  1930,  1919,  1935,  1940,
     292,  1941,  1937,  1938,  2077,  1939,  1942,   389,  1943,  1944,
    1950,  1957,  1963,  1964,  1965,  1966,  1968,  1969,  1998,  2004,
    2015,  2016,   190,  2017,  2049,  2021,   194,   281,  2023,  2024,
    2034,   195,   196,   197,   198,   199,  2041,  2044,  2045,   108,
    1698,  2047,  2061,  2062,  2073,  2065,  2074,  2093,  2098,  2100,
    2103,  2104,  2107,   629,  1820,  2108,   510,  2111,   204,  2112,
    2116,  2125,  2141,   631,  2147,  2143,   370,  2145,   208,  2161,
     321,   581,  2160,   292,  2158,  2175,  2178,  1702,  2181,   509,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,  2162,  2184,  2185,  2186,   498,  2187,
    2189,  2190,   466,   467,   468,   470,   472,  2195,  2159,  2216,
    2223,   292,  2225,  2194,  2227,  2229,  2231,  2246,  2205,   505,
    2207,  1371,  2247,   512,  2209,  2248,  2249,  2214,  2250,   509,
    2251,   509,  2253,  1573,  2079,  1960,   819,   519,   521,   524,
     525,  1773,   527,   521,   529,   530,  1588,   532,   521,   534,
     535,   536,   537,   538,   539,   113,   541,   542,   543,   123,
     124,   509,   125,   521,  1984,  1721,   904,     0,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   823,
     496,   497,   578,   580,   521,     0,   498,     0,     0,     0,
       0,     0,     0,     0,   588,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,     0,     0,  1447,  1448,  1449,     0,     0,     0,
     619,   620,     0,     0,  2078,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   644,
       0,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
     663,     0,     0,     0,   666,   667,   668,     0,   670,     0,
       0,     0,   673,   674,   675,     0,     0,   676,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   690,     0,     0,     0,   498,   695,   697,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   704,   705,     0,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,   742,
       0,   175,   176,   177,   178,   748,     0,   750,     0,   180,
     181,   182,     0,     0,   183,   510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,     0,     0,     0,
       0,   782,   521,     0,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   796,   797,   798,     0,
       0,   800,   801,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,     0,   510,     0,     0,
     578,     0,     0,  2192,     0,     0,   828,     0,     0,     0,
       0,   833,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   847,   848,   510,     0,     0,
    1664,     0,   854,   855,     0,     0,   862,   862,   867,   868,
       0,   870,     0,     0,   872,     0,     0,     0,     0,     0,
    1825,     0,     0,  2230,     0,  2233,   862,   521,     0,     0,
     191,   192,   193,   888,   890,   892,   893,     0,     0,     0,
     898,   899,   900,   200,     0,   201,     0,   905,   907,   910,
     913,   916,   918,     0,   920,  2252,   922,     0,   521,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1862,     0,   940,   941,   942,   466,
     467,   943,     0,     0,     0,   948,   949,   950,   951,   952,
     953,   954,   955,   956,     7,     8,     0,     0,   962,     0,
     964,   965,     0,     0,     0,   521,   521,   521,     0,     0,
     972,   973,   974,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1751,     0,     0,     0,     0,     0,   521,
       0,     0,     0,     0,   854,   855,     0,   892,   893,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1006,   521,
       0,  1902,     0,  1010,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   774,    24,    25,   775,
      27,    28,   776,    30,   777,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,     0,  1796,    41,  1799,     0,
    1802,  1934,     0,   778,    48,     0,     0,    50,   779,     0,
      53,    54,   780,     0,     0,     0,  1815,  1816,  1817,  1818,
    1819,  1821,  2072,     0,     0,     0,     0,     0,  1082,     0,
      71,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,     0,    85,    86,    87,     0,     0,     0,
       0,     0,     0,  1114,  1115,     0,     0,   521,  1121,  1122,
       0,   521,  1125,     0,     0,     0,     0,     0,     0,     0,
    1132,     0,     0,   890,  1135,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,  1157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
       0,   521,     0,     0,   521,     0,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,     0,   521,
       0,   521,     0,   521,     0,     0,     0,   290,     0,   521,
       0,     0,     0,     0,   521,     0,     0,     0,     0,     0,
    2148,  1196,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,     0,     0,  1221,  1222,     0,     0,     0,     0,  1225,
       0,     0,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,  1253,     0,
     498,  1255,     0,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
    1269,   498,  1271,  1272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1279,     0,  1990,     0,  1993,     0,  1996,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2006,  2007,  2008,  2009,  2010,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1301,     0,     0,     0,     0,
       0,     0,     0,  1302,  1303,  1304,     0,   521,     0,     0,
       0,     0,     0,     0,     0,  1307,     0,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,     0,     0,  1314,
       0,     0,     0,     0,  1317,     0,  2042,     0,     0,     0,
    2046,   583,     0,  1321,     0,     0,     0,     0,     0,  1329,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
     521,   521,   521,  1342,     0,     0,     0,     0,     0,   544,
    1348,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,   290,   498,
       0,     0,     0,     0,     0,     0,     0,     0,  2094,     0,
       0,     0,  2096,     0,     0,     0,     0,     0,   593,     0,
       0,     0,     0,     0,     0,     0,     0,   603,   605,   607,
       0,     0,     0,   612,     0,     0,     0,     0,  2121,     0,
     521,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1402,  1403,     0,  1404,  1405,     0,  1406,  1407,  1408,     0,
       0,     0,     0,     0,     0,     0,  1414,     0,     0,     0,
       0,     0,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1427,     0,  1429,     0,  1431,     0,  1433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,  2172,  2173,     0,     0,
       0,     0,  1453,     0,     0,   692,   693,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   701,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     584,   496,   497,     0,  1484,     0,     0,   498,     0,     0,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   823,   496,   497,     0,     0,   739,  1504,   498,     0,
       0,     0,  1509,     0,     0,   774,    24,    25,   775,    27,
      28,   776,    30,   777,    32,    33,    34,    35,     0,     7,
       8,    37,    38,    39,     0,     0,    41,     0,     0,     0,
       0,     0,   778,    48,     0,     0,    50,   779,     0,    53,
      54,   780,     0,     0,  1551,     0,     0,     0,     0,     0,
       0,     0,     0,  1559,  1560,  1561,  1562,     0,   983,    71,
    1565,  1566,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1575,  1577,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,     0,     0,     0,
       0,   774,    24,    25,   775,    27,    28,   776,    30,   777,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,     0,    41,     0,     0,     0,     0,     0,   778,    48,
       0,   593,    50,   779,     0,    53,    54,   780,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,  1644,  1645,  1646,   988,     0,     0,     0,     0,
       0,     0,     0,     0,  1658,     0,  1660,     0,     0,    85,
      86,    87,     0,  1663,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,  1679,     0,     0,     0,     0,     0,     0,     0,  1684,
    1685,  1686,   774,    24,    25,   775,    27,    28,   776,    30,
     777,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,     0,    41,     0,     0,     0,     0,     0,   778,
      48,  1706,     0,    50,   779,     0,    53,    54,   780,     0,
       0,   989,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1718,    71,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,  1735,   498,     0,     0,     0,  1741,
      85,    86,    87,     0,     0,     0,     0,  1100,     0,     0,
       0,     0,     0,     0,  1749,  1750,     0,     0,     0,     0,
       0,  1755,  1756,     0,     0,     0,  1186,     0,  1760,     0,
       0,  1071,   522,     0,     0,  1077,     0,   522,     0,     0,
       0,     0,   522,     0,     0,  1764,  1765,  1766,  1767,  1768,
    1769,  1770,     0,     7,     8,     0,     0,   522,     0,  1775,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
     521,  1787,  1218,  1788,     0,     0,   579,     0,   522,     0,
       0,     0,  1490,     0,     0,  1805,  1806,     0,   523,   522,
       0,     0,     0,   528,     0,  1422,     0,     0,   533,     0,
       0,     0,     0,     0,   521,     0,     0,     0,  1824,     0,
       0,     0,     0,   547,     0,     0,     0,     0,     0,  1834,
       0,     0,     0,     0,     0,   774,    24,    25,   775,    27,
      28,   776,    30,   777,    32,    33,    34,    35,     0,  1854,
       0,    37,    38,    39,     0,   589,    41,     0,     0,     0,
       0,     0,   778,    48,     0,     0,    50,   779,     0,    53,
      54,   780,     0,     0,     0,     0,  1869,  1870,     0,     0,
       0,     0,  1197,     0,  1876,     0,     0,     0,     0,    71,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,  1896,     0,    85,    86,    87,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,  1905,     0,   498,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,  1920,     0,   498,     0,     0,     0,     0,     0,     0,
     578,     0,     0,     0,     0,     0,     0,     0,  1931,     0,
    1932,     0,     0,   521,     0,     0,  1282,     0,     0,     0,
    1286,     0,     0,     0,  1291,  1219,   522,     0,     0,     0,
    1946,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,  1952,   498,
       0,     0,     0,  1956,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   579,  1967,     0,  1308,     0,     0,
       0,  1971,  1972,  1973,  1974,  1975,     0,     0,     0,     0,
       0,   521,   783,     0,     0,     0,     0,     0,  1989,     0,
    1992,     0,  1995,     0,     0,     0,     0,     0,     0,     0,
     863,   865,   521,     0,     0,     0,     0,     0,     0,     0,
    2011,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     884,   522,     0,     0,     0,     0,     0,     0,   891,     0,
       0,     0,     0,  2025,  2026,     0,     0,     0,  2028,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   522,   522,     0,     0,     0,     0,  1374,  1375,
       0,  1377,     0,  1380,  1381,     0,  1383,  2050,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1392,  1393,   885,     0,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,  2076,   522,
     522,   522,     0,     0,  1741,  1413,  1098,     0,   924,   925,
       0,  1417,     0,     0,  2087,  2088,  2089,  2090,  2091,  2092,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,  2102,     0,     0,  2106,     0,     0,  2110,     0,
       0,     0,  2113,   522,     0,     0,     0,   521,   521,   521,
     521,   521,     0,     0,     0,   967,   968,   969,     0,     0,
       0,  2128,     0,     0,  2130,     0,     0,     0,     0,     0,
       0,     0,  1474,     0,     0,     0,     0,     0,     0,   987,
       0,     0,     0,     0,     0,  1485,  1486,  1487,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1007,
       0,  1499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2166,  2167,  2168,  2169,  2170,  2171,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,   521,   498,     0,     0,
       0,     0,     0,     0,  1792,     0,  1793,     0,     0,     0,
       0,   522,     0,     0,     0,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   891,  1136,     0,
       0,     0,  1568,     0,     0,     0,   895,     0,  2217,  2218,
    2219,  2220,  2221,  2222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1589,     0,     0,     0,
       0,     0,  1595,   522,     0,   522,     0,  1120,   522,     0,
       0,  1124,     0,     0,     0,     0,  1609,     0,     0,     0,
       0,   522,     0,   522,     0,   522,     0,   522,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,   522,  1626,
    1627,  1628,     0,     0,     0,  1631,  1632,     0,  1633,     0,
    1634,     0,  1635,     0,  1636,  1637,  1638,     0,     0,  1164,
       0,  1165,     0,     0,  1167,     0,     0,     0,     0,     0,
     522,     0,     0,     0,  1659,     0,     0,  1179,     0,  1180,
       0,  1181,     0,  1182,     0,  1667,     0,     0,     0,  1187,
       0,     0,     0,  1675,  1190,     0,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,     0,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,     0,     0,     0,  1036,  1038,
    1039,     0,     0,     0,  1043,  1044,  1215,  1046,     0,     0,
       0,     0,  1051,  1052,  1053,     0,  1055,     0,     0,     0,
       0,     0,     0,  1063,  1065,     0,     0,   506,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1088,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,   522,   857,  1733,   858,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,  1745,     0,   382,   135,
     175,   176,   177,   178,     0,     0,     0,     0,   180,   181,
     182,     0,     0,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,   522,   522,   522,   522,  1305,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,   175,   176,   177,   178,     0,     0,     0,  1172,   180,
     181,   182,     0,     0,   183,     0,     0,     0,     0,     0,
       0,     0,     0,  1183,     0,   188,     0,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1568,  1338,
    1339,  1340,  1341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1827,   522,     0,     0,     0,     0,     0,
       0,     0,     0,  1839,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1846,     0,     0,     0,     0,  1851,   191,
     192,   193,     0,     0,     0,     0,   522,     0,     0,     0,
       0,     0,   200,     0,   201,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1871,     0,
    1397,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
     191,   192,   193,  1568,     0,     0,  1828,   400,  1829,     0,
       7,     8,  1418,   200,     0,   201,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,   442,   443,   444,   445,  1917,   447,
     448,   449,   450,   451,   452,     0,     0,   454,     0,     0,
       0,     0,     0,   455,   456,     0,     0,     0,     0,   461,
     462,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   774,    24,    25,   775,    27,    28,   776,    30,
     777,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     7,     8,    41,     0,     0,     0,     0,  1347,   778,
      48,     0,  1568,    50,   779,     0,    53,    54,   780,  1961,
    1962,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,    71,     0,  1568,   498,
       0,  1369,  1370,   766,   555,     0,   558,   559,   560,   561,
       0,     0,     0,     0,     0,     0,     0,   576,  2001,     0,
      85,    86,    87,     0,     0,     0,     0,     0,   587,     0,
       0,     0,     0,   774,    24,    25,   775,    27,    28,   776,
      30,   777,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,     0,    41,     0,     0,     0,     0,     0,
     778,    48,     0,     0,    50,   779,     0,    53,    54,   780,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2043,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,   993,  1241,     0,     0,     0,     0,     0,     0,  2060,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1987,
       0,  1988,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,  1677,     0,     0,     0,
     498,     0,     0,     0,  1511,     0,     0,     0,     0,  1159,
    1515,  1516,  1517,  1518,  1519,     0,  1522,     0,  1524,  1525,
       0,  1528,  1531,  1568,     0,  1535,  1536,  1537,     0,     0,
       0,     0,  1541,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   133,   134,   135,     0,     0,     0,   136,
     137,   138,   772,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,   522,   522,   180,   181,   182,  1612,     0,
     183,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,   188,     0,     0,     0,  1623,     0,     0,     0,     0,
       0,     0,     0,     0,  1568,     0,     0,     0,   522,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1785,
    1786,     0,     0,     0,     0,     0,  1175,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,     0,  1244,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
    1695,     0,     0,   498,     0,  1699,     0,     0,   189,     0,
       0,     0,  1294,     0,     0,   190,   191,   192,   193,   194,
       0,     0,     0,     0,   195,   196,   197,   198,   199,   200,
       0,   201,   108,     7,     8,     0,     0,  1712,  1713,     0,
       0,  1715,  1716,     0,     0,     0,   202,   203,     0,     0,
       0,   204,     0,     0,     0,     0,   205,     0,   206,     0,
     207,   208,     0,   209,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   522,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1947,   774,    24,    25,   775,    27,
      28,   776,    30,   777,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,     0,    41,     0,     0,     0,
       0,     0,   778,    48,     0,     0,    50,   779,     0,    53,
      54,   780,     0,  1933,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     0,     0,     0,    71,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,   522,     0,   498,     0,
       0,     0,     0,    85,    86,    87,     0,  1445,     0,     0,
       0,     0,     0,     0,     0,  1841,  1842,     0,     0,  1844,
    1845,     0,     0,     0,     0,  1848,  1849,     0,     0,     0,
       0,  1985,     0,     0,     0,     0,     0,   774,    24,    25,
     775,    27,    28,   776,    30,   777,    32,    33,    34,    35,
       0,     0,  2005,    37,    38,    39,     0,     0,    41,     0,
       0,     0,     0,     0,   778,    48,     0,     0,    50,   779,
       0,    53,    54,   780,     0,  1270,     0,     0,     0,     0,
       0,     0,     0,  1889,  1890,     0,     0,     0,     0,     0,
       0,    71,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,    85,    86,    87,     0,  1790,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,   522,   522,   522,   522,   522,     0,  1810,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,   268,     0,
       0,     0,     0,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   269,   270,   271,   272,   273,     0,  2117,  2118,  2119,
    2120,  2122,     0,     0,     0,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
     522,     0,     0,     0,   187,     0,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,   277,     0,     0,     0,
       0,     0,     0,    36,     0,  1318,  1319,     0,     0,     0,
       0,  1323,  1324,     0,     0,   278,     0,    49,     0,     0,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,  2188,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,  1881,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,   194,   281,     0,     0,     0,   195,   196,
     197,   198,   199,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   520,     0,     0,     0,   204,     0,     0,     0,     0,
     360,     0,     0,     0,     0,   208,     0,     0,   581,     0,
       0,     0,     0,     0,     0,     0,   133,   268,   135,     0,
       0,     0,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,   180,   181,
     182,     0,     0,   183,     0,   184,   185,   186,     0,     0,
    1501,  1502,     0,   187,   188,  1506,  1507,   274,     0,     0,
     275,     0,     0,   276,     0,   277,  2197,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  1882,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,   200,     0,   201,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,   135,   208,     0,   284,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,     0,     0,   180,   181,   182,     0,     0,   183,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,   188,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    1883,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,   191,   192,   193,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,   200,     0,   201,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   282,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,   359,   208,
       0,  1850,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  1884,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,  1666,   208,     0,   284,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    1886,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   282,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,     0,   208,
       0,   284,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  1914,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   283,
       0,   133,   268,     0,   208,     0,   284,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    1929,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   282,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,     0,   208,
       0,   284,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  1976,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     520,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,     0,   208,     0,   577,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    2003,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   282,     0,     0,     0,   204,
       0,     0,     0,     0,   592,     0,   133,   268,     0,   208,
       0,   284,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2012,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   602,
       0,   133,   268,     0,   208,     0,   284,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    2013,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   282,     0,     0,     0,   204,
       0,     0,     0,     0,   604,     0,   133,   268,     0,   208,
       0,   284,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2033,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   606,
       0,   133,   268,     0,   208,     0,   284,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    2051,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   520,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,     0,   208,
       0,   861,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2054,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     520,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,     0,   208,     0,   864,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    2057,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   520,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,     0,   208,
       0,   889,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2099,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,     0,   208,     0,  1674,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,    49,     0,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    2142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,  1820,     0,     0,     0,   204,
       0,     0,     0,     0,   631,     0,   133,   388,   135,   208,
       0,   321,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,   180,   181,
     182,     0,     0,   183,     0,   184,   185,   186,     0,   133,
     388,   135,     0,   187,   188,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,   180,   181,   182,     0,     0,   183,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,   188,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2144,     0,     0,   190,   191,
     192,   193,   194,     0,     0,     0,     0,   195,   196,   197,
     198,   199,   200,     0,   201,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,     0,     0,     0,   208,     0,  1576,     0,     0,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,   190,   191,   192,   193,   194,  2146,     0,     0,     0,
     195,   196,   197,   198,   199,   200,     0,   201,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,     0,     0,     0,   204,     0,     0,
       0,     0,   360,     0,   133,   388,   135,   208,     0,  1833,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,   180,   181,   182,     0,
       0,   183,     0,   184,   185,   186,     0,   133,   388,     0,
       0,   187,   188,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   171,   172,   173,
     174,   498,     0,     0,     0,   179,     0,     0,     0,     0,
    2165,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,  2196,     0,     0,     0,   190,   191,   192,   193,
     194,     0,     0,     0,     0,   195,   196,   197,   198,   199,
     200,     0,   201,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,     0,
       0,     0,   204,     0,     0,     0,     0,   360,     0,     0,
       0,     0,   208,     0,  1853,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,   190,
       0,     0,  2235,   194,     0,     0,     0,     0,   195,   196,
     197,   198,   199,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   203,     0,     0,     0,   204,     0,     0,     0,     0,
     360,     0,   133,   388,     0,   208,     0,   609,   136,   137,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   171,   172,   173,   174,   498,     0,     0,     0,
     179,     0,     0,     0,     0,  2236,     0,     0,     0,     0,
       0,   184,   185,   186,     0,     0,     0,     0,     0,   187,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,  2237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   268,     0,     0,     0,     0,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   269,   270,   271,   272,   273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,   190,     0,     0,     0,   194,     0,
     184,   185,   186,   195,   196,   197,   198,   199,   187,     0,
       0,   108,   274,     0,     0,   275,     0,     0,   276,     0,
     277,     0,     0,     0,     0,   629,   630,    36,     0,     0,
     204,     0,     0,     0,     0,   631,     0,     0,     0,   278,
     208,    49,   321,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    2238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   520,     0,     0,     0,   204,
     133,   388,   135,     0,   360,     0,   136,   137,   138,   208,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     0,
       0,     0,   180,   181,   182,     0,     0,   183,     0,   184,
     185,   186,     0,   133,   388,     0,     0,   187,   188,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   171,   172,   173,   174,   498,     0,     0,
       0,   179,     0,     0,     0,     0,  2239,     0,     0,     0,
       0,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,  2240,     0,
       0,     0,   190,   191,   192,   193,   194,     0,     0,     0,
       0,   195,   196,   197,   198,   199,   200,     0,   201,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,     0,     0,     0,   204,     0,
       0,     0,     0,   360,     0,     0,     0,     0,   208,     0,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,   190,   686,     0,     0,   194,
       0,     0,     0,     0,   195,   196,   197,   198,   199,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   203,     0,     0,
       0,   204,   133,   388,     0,     0,   360,   469,   136,   137,
     138,   208,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   171,   172,   173,   174,   498,     0,     0,     0,
     179,     0,     0,     0,   926,     0,     0,     0,     0,   133,
     388,   184,   185,   186,     0,   136,   137,   138,     0,   187,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   171,
     172,   173,   174,   498,     0,     0,     0,   179,     0,     0,
       0,  1901,     0,     0,     0,     0,     0,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   857,     0,   858,
       0,     0,  1521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,     0,     0,   194,     0,
       0,     0,     0,   195,   196,   197,   198,   199,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,     0,     0,     0,
     204,     0,     0,     0,     0,   360,     0,     0,   471,     0,
     208,     0,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,   190,   975,     0,     0,   194,     0,   933,     0,     0,
     195,   196,   197,   198,   199,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,     0,     0,     0,   204,   133,   388,
       0,     0,   360,   694,   136,   137,   138,   208,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   171,   172,
     173,   174,   498,     0,     0,     0,   179,     0,     0,   812,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
     133,   388,     0,  1278,     0,   187,   136,   137,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     171,   172,   173,   174,   498,     0,     0,     0,   179,     0,
       0,   933,     0,     0,     0,     0,     0,     0,     0,   184,
     185,   186,     0,     0,     0,     0,     0,   187,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,   934,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,   194,     0,     0,     0,     0,   195,
     196,   197,   198,   199,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,     0,     0,     0,   204,     0,     0,     0,
       0,   360,     0,     0,   696,     0,   208,     0,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,   190,   980,     0,     0,   194,     0,     0,     0,
       0,   195,   196,   197,   198,   199,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,     0,     0,     0,   204,   133,
     388,     0,  1452,   360,     0,   136,   137,   138,   208,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   171,
     172,   173,   174,   498,     0,     0,     0,   179,     0,     0,
    1025,     0,     0,     0,     0,     0,   133,   388,   184,   185,
     186,     0,   136,   137,   138,     0,   187,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   171,   172,   173,   174,
     498,     0,     0,     0,   179,     0,     0,  1033,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1034,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,     0,     0,     0,   194,     0,     0,     0,     0,
     195,   196,   197,   198,   199,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,     0,     0,     0,   204,     0,     0,
       0,     0,   360,     7,     8,     0,     0,   208,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   190,     0,
       0,     0,   194,  1035,     0,     0,     0,   195,   196,   197,
     198,   199,     7,     8,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,     0,     0,     0,   208,   774,    24,    25,   775,    27,
      28,   776,    30,   777,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,     0,    41,     7,     8,     0,
       0,     0,   778,    48,     0,     0,    50,   779,     0,    53,
      54,   780,     0,     0,   774,    24,    25,   775,    27,    28,
     776,    30,   777,    32,    33,    34,    35,     0,     0,    71,
      37,    38,    39,     0,     0,    41,     0,     0,     0,     0,
       0,   778,    48,     0,     0,    50,   779,     0,    53,    54,
     780,     0,     0,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,    71,   774,
      24,    25,   775,    27,    28,   776,    30,   777,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,     0,     0,
      41,     0,    85,    86,    87,     0,   778,    48,     0,     0,
      50,   779,     0,    53,    54,   780,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,    71,   498,  1276,     0,     0,     0,     0,
       0,  1050,     0,     0,   774,    24,    25,   775,    27,    28,
     776,    30,   777,    32,    33,    34,    35,    85,    86,    87,
      37,    38,    39,     0,     0,    41,     0,     0,     0,     0,
       0,   778,    48,     0,  1441,    50,   779,     0,    53,    54,
     780,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,    71,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,    85,    86,    87,     0,   498,     0,     0,  2063,
     986,     0,    -4,    -4,     0,     0,     0,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,    -4,    -4,    -4,   498,     0,     0,    -4,    -4,
       0,    -4,  1170,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,  2150,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     6,
      -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     9,    10,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,    14,    15,     0,    16,     0,     0,     0,
      17,    18,     0,    19,    20,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    80,    81,    82,     0,     0,
       0,    83,     0,     0,     0,     0,    84,    85,    86,    87,
       0,     0,    88,     0,    89,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   107,     0,   108,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1171,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1173,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1227,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1228,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1229,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1264,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1365,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1443,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1444,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1489,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1615,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1616,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1617,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1618,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1619,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1620,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1621,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1736,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1737,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1744,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1891,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1892,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1893,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1894,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1895,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1953,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1954,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1958,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2035,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2036,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  2037,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2038,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  2039,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2081,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2084,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  2133,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2134,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  2135,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2136,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2137,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  2138,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2198,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  2199,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2200,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2201,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
    1005,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,  1012,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,  1113,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,  1163,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,  1189,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,  1257,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,  1258,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,  1262,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,  1263,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,  1296,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
    1358,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,  1363,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,  1680,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,  1723,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,  1915,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   762,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,   822,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,   826,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,   827,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   829,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   831,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,   832,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
     834,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,   836,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,   837,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   838,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,   839,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,   840,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,   841,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   843,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   844,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,   845,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
     886,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,   896,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,   957,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   975,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,   976,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,   977,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,   978,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   984,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   985,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,   992,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1001,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1011,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1112,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1140,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1145,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  1158,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  1162,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,  1188,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,  1193,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1194,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1195,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1201,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1210,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1211,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1212,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  1243,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  1245,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,  1246,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,  1247,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1248,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1249,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1250,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1251,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1256,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1357,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  1362,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  1533,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,  1558,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,  1729,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1730,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1731,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1732,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1791,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1809,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1832,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  2080,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  2163,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498
};

static const yytype_int16 yycheck[] =
{
       3,     3,   314,     6,   623,   624,  1242,   436,  1238,   438,
       4,  1668,  1691,  1692,     7,     6,     4,     4,     4,     4,
       4,     4,     4,   329,   453,     4,     4,     0,     4,     6,
       4,   226,     7,     5,   216,   217,     4,     4,   233,     5,
     346,     5,     5,     5,    47,     4,     6,     5,     5,     5,
       5,   233,     5,    90,     6,     6,     4,    90,   226,  1877,
       6,     6,     4,     6,     6,   233,     7,    90,   216,   217,
       6,   226,    75,   226,   111,   228,   216,   217,   111,   385,
      83,   387,   235,     6,   232,    88,   234,   393,   216,   217,
     122,    13,   232,   122,   234,   230,    99,   469,   226,   471,
     235,   473,     6,   226,     7,   233,  1763,   139,   216,   217,
     139,   216,   217,     6,   167,   147,   148,   149,   147,   148,
     149,   153,   154,     6,   153,   154,   234,   232,   226,   234,
     183,   184,   216,   217,     4,     5,    84,   216,   217,   227,
      88,   229,    84,   132,   232,     7,    94,    95,   232,    97,
      98,   216,   217,   226,   233,   228,   223,   224,    84,   223,
     224,    87,   235,    99,    90,   101,   233,   115,   233,   233,
     157,   158,   159,   160,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     6,   178,   167,   168,    57,    58,    59,
      60,     6,     7,   167,   168,    65,    66,    67,   170,   182,
      70,     7,   234,   155,   170,   208,   170,   209,   202,   155,
       8,    81,   170,  2031,  2032,  1872,   202,   220,   221,   218,
     219,   220,   213,   202,     6,   228,   225,   227,   203,   204,
     205,   206,   232,   236,  1464,   238,   213,   230,   226,   233,
     243,  1898,   226,   228,   228,   248,   230,   234,   226,     6,
     235,   235,   255,     6,   233,   233,   259,   233,   226,   226,
     263,   264,   265,   266,   267,   233,   233,   226,     6,   233,
     233,   233,     7,   233,   233,   278,   233,   233,   233,   282,
     233,   284,   233,   226,   228,   226,     3,   228,    87,     6,
     233,    90,   295,   216,   217,   298,   299,   300,   301,   235,
     203,   204,   205,   206,   307,   308,   309,   228,   614,   615,
     313,   314,   216,   217,   216,   217,   186,   187,   188,   226,
     223,   224,   694,   104,   696,     7,   233,   230,   634,   199,
     232,   201,   202,   216,   217,     7,   226,   340,   341,   342,
     226,   203,   204,   205,   206,   223,   224,     6,    90,     7,
       4,   354,   355,   223,   224,   233,   216,   217,    75,   226,
     230,   223,   224,   233,    90,   671,   233,     7,   216,   217,
     226,    88,   232,     7,   226,   216,   217,   223,   224,   226,
     686,   233,    99,     8,   232,   216,   217,   233,   391,   226,
     762,   232,   395,   396,   766,     6,  2075,   203,   204,   205,
     206,   232,   226,    87,   228,   408,    90,   216,   217,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   232,   226,   229,  2083,   225,   232,   227,
     216,   217,   226,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   232,   450,   451,   452,
     453,   454,     4,     5,   226,   458,   459,   460,   461,   462,
     463,   229,   465,   226,   232,   401,   216,   217,   203,   204,
     205,   206,   126,   127,   128,   129,   223,   224,   226,   482,
       8,   226,   232,   230,   473,   216,   217,   141,   223,   224,
     144,   208,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   232,   226,   220,   221,    57,    58,    59,    60,   216,
     217,   228,   226,    65,    66,    67,   226,   520,    70,   236,
     456,   203,   204,   205,   206,   232,   223,   224,   464,    81,
     233,   203,   204,   205,   206,   226,   233,  2194,   255,   216,
     217,   223,   224,   216,   217,   203,   204,   205,   206,    90,
     267,   223,   224,   556,   557,   232,   226,   560,   226,   232,
     228,   220,   221,   203,   204,   205,   206,   235,   571,   203,
     204,   205,   206,   576,   577,    87,   233,    90,    90,    92,
      92,   584,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   255,   314,    92,   122,
     225,   216,   217,   216,   217,   608,   609,    84,   267,   234,
      87,   216,   217,    90,   223,   224,   139,   232,   226,   232,
     229,   623,   624,   929,   147,   148,   149,   232,    87,  1001,
     153,   154,   227,  1005,   186,   187,   188,   232,   226,   216,
     217,   216,   217,   216,   217,   216,   217,   199,   233,   201,
     202,   227,   655,   656,   657,   232,   232,   232,   226,   232,
     228,   232,   598,   599,   600,   601,   227,   235,   229,   226,
     233,   228,   233,  1909,   391,  1911,   679,  1913,   122,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   223,   224,   139,   699,   225,   216,   217,
     216,   217,    90,   147,   148,   149,   234,   126,   127,   153,
     154,   234,    90,   132,   232,    87,   232,   706,    87,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,     4,
     447,   448,   391,   450,   451,   452,   453,   454,     4,   216,
     217,   458,   459,   460,   461,   462,   463,     4,   465,   226,
     216,   217,   216,   217,   216,   217,   233,     4,   761,   216,
     217,  1991,   765,   232,  1994,   234,   232,  1997,   232,   111,
     232,   216,   217,   762,  1086,   232,   226,   766,   437,   226,
     439,   440,   441,   442,   443,   444,   445,   232,   447,   448,
     234,   450,   451,   452,   226,   454,   216,   217,   226,   458,
     459,   460,   461,   462,   807,   223,   224,   232,   811,   234,
     226,   814,   232,   227,   817,   233,   819,   226,   232,   228,
     823,   824,   227,   227,   229,   229,   235,   232,  2064,   233,
    1202,   767,  1204,   232,  1206,   234,  1208,   122,   126,   127,
     557,     6,     7,   560,   132,     6,   216,   217,   218,   219,
     220,     6,    12,    13,   139,   225,   859,   232,   861,   234,
     227,   864,   147,   148,   149,   232,   226,   856,   153,   154,
     232,   122,   234,   226,   877,   228,   879,   230,   881,   228,
     883,   232,   235,   234,  2114,   821,   889,   122,   139,  1318,
    1319,   894,   216,   217,  1323,  1324,   147,   148,   149,   902,
     228,   560,   153,   154,   139,  2141,   227,  2143,   229,  2145,
     226,   232,   147,   148,   149,  2151,   227,    87,   153,   154,
      90,   232,    92,   926,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   232,   228,   234,
     100,   101,   102,    87,  2174,   105,    90,  2177,    92,   234,
    2180,   111,   112,  2183,  1326,   115,   116,   227,   118,   119,
     120,   226,   232,   228,   227,   230,   229,   226,   233,  2205,
     235,  2207,   226,  2209,   228,  1347,   230,   226,   138,    84,
     226,   235,    87,   234,   227,    90,   229,    92,   226,   232,
     227,   233,   229,   996,  2224,   232,  2226,  1000,  2228,   234,
       6,  1004,   162,   163,   164,    84,     7,   226,    87,  1012,
     122,    90,  1001,    92,     6,   227,  1005,   229,   233,     6,
     232,  1333,  1011,  1012,   232,     6,   234,   139,  1647,  1648,
     232,   232,   234,   234,  1037,   147,   148,   149,   227,  1042,
     229,   153,   154,   232,  1047,  1048,  1049,  1050,   212,   213,
     214,   215,   216,   217,   218,   219,   220,  1060,   232,  1062,
     234,   225,   233,   232,   232,   234,   234,   122,    90,   232,
      92,   234,  1501,  1502,   234,   226,   226,  1506,  1507,   122,
     232,   226,   234,  1086,   139,   226,  1089,  1090,  1091,  1092,
     226,   226,   147,   148,   149,     6,   139,   814,   153,   154,
     817,   232,   819,   234,   147,   148,   149,    90,   226,    92,
     153,   154,   232,   232,   234,   234,  1119,   232,   232,   234,
     234,     4,   234,  1112,  1113,   232,   235,   234,    61,    62,
     232,    64,   234,   233,   233,  1138,  1139,   226,  1141,  1511,
    1143,  1144,   226,  1146,   122,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,     7,   814,   232,  1160,   234,   226,
     819,   139,   232,   232,   234,   234,   232,   226,   234,   147,
     148,   149,   233,  1162,  1163,   153,   154,   226,   232,   234,
     234,   232,  1185,   234,   232,   232,   234,   234,  1191,  1192,
    1496,   234,  1498,   232,   232,   234,   234,   226,   226,  1188,
    1189,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   232,   232,   234,   234,   225,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     6,     4,   233,     6,   225,   232,
    1552,   234,   232,   232,   234,   234,   232,     6,   234,  1252,
     226,   264,   265,   266,   233,   232,   234,   234,   232,   232,
     234,   234,  1265,  1266,  1267,   232,   232,   234,   234,   232,
     232,   234,   234,     6,   232,   232,   234,   234,  1281,   232,
     232,   234,   234,   233,   233,  1904,   299,   300,   301,   232,
     232,   234,   234,   233,   226,  1012,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     232,   232,   234,   234,   225,  1318,  1319,   232,   226,   234,
    1323,  1324,   232,   226,   234,  1042,   226,   340,   341,   342,
    1333,  1048,  1049,  1050,   232,   226,   234,  1326,   232,   226,
     234,   354,   355,  1060,   232,  1062,   234,   226,   232,  1352,
     234,   228,     6,  1012,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   232,  1086,
     234,   233,   225,  1376,   232,     6,   234,     6,   232,  1382,
     234,   122,   233,  1042,   317,   318,   232,   228,   234,  1048,
    1049,  1050,   325,  1396,   233,   228,   329,   228,   139,     6,
     170,  1060,  1119,  1062,   233,   235,   147,   148,   149,     6,
       6,   233,   153,   154,     6,     6,  1419,  1420,  1421,   233,
     233,     6,  1425,  1426,  1853,  1428,   228,  1430,     4,  1432,
    1366,  1434,  1435,  1436,   225,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     6,
     230,  1454,     7,   225,   233,   232,   234,   232,     7,   227,
    1119,     6,  1465,     6,     6,   227,     4,    62,    62,    62,
    1473,     7,    62,  1476,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   122,     7,
       6,     6,   225,   234,     6,   227,     6,   233,  1501,  1502,
       4,     5,     7,  1506,  1507,   139,     6,   167,     7,     6,
       6,     6,   233,   147,   148,   149,   229,  1520,   227,   153,
     154,     6,     6,  1526,  1513,   227,   227,   232,   232,   232,
     227,    44,   232,   232,   232,     6,   232,   227,   227,     6,
      44,    45,    46,    47,    48,    49,    50,    51,    52,  1552,
     229,  1863,    44,    57,    58,    59,    60,    44,    44,  1495,
    1563,    65,    66,    67,     4,   226,    70,     4,     6,   170,
    1573,     6,     6,  1576,     6,   233,     7,    81,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   122,     7,     7,     7,   225,   170,     7,     7,
     234,  1318,  1319,     7,   170,     7,  1323,  1324,  1544,   139,
       7,     7,     7,  1919,     7,     7,  1333,   147,   148,   149,
       7,     7,  1611,   153,   154,     7,     6,   227,   233,   233,
     229,   233,     7,     7,     4,   233,  1639,  1640,     6,   227,
    1576,   227,   122,   230,   233,  1647,  1648,   227,   232,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   232,  1668,   227,   232,   225,     7,
     234,  1674,   234,     6,   230,     7,     7,     6,    44,     7,
    1683,     7,   186,   187,   188,     6,   234,   233,   621,   622,
    1693,    44,    44,    44,     6,   199,   629,   201,   202,     6,
    1703,     6,     6,     6,   234,  1708,     7,  1643,   228,     6,
    2016,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   227,   226,   229,   233,   225,     6,    92,
     213,     7,   226,   226,     7,  1738,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     226,   226,   226,  1689,   225,     7,     7,     7,     7,  2065,
    1763,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,  1708,  1709,  1710,     7,   225,     6,   102,     7,
       7,     7,     7,     7,  1501,  1502,     7,     4,     4,  1506,
    1507,   233,     6,   226,     7,     6,    90,     7,     7,     7,
       7,     7,     7,  1520,     7,  1808,   233,     6,     6,  1526,
       6,   232,     7,     6,     6,     4,     4,  1820,     4,   234,
       4,     6,   233,   233,     6,     6,     6,     6,     6,   232,
    1833,   232,   230,   227,     7,  1552,   227,   226,     6,     6,
       6,     6,   230,   233,   227,   229,   115,  1850,   233,     6,
    1853,     6,   233,     6,   233,   233,  1573,   170,     6,     6,
    1863,  1520,   233,     6,     6,     6,     6,  1526,     6,  1872,
       6,     6,     5,     4,   229,     4,  1879,  1880,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   227,     6,     6,  1898,   225,     6,  1901,   233,
    1836,     7,  1904,   233,     6,     6,   233,     6,   233,   228,
     233,   233,     6,   233,  1573,  1918,   233,   233,   233,  1922,
       3,     4,   233,   233,     6,   166,     9,    10,    11,     6,
     232,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     6,
       6,     4,     6,    88,     6,     6,     4,     6,     4,     6,
      53,    54,    55,    56,     6,     6,     6,  1980,    61,     7,
       7,     6,     6,     6,     6,     6,     6,     5,   233,    72,
      73,    74,     6,   233,     6,     6,  1999,    80,     6,   932,
       6,    84,     6,     6,    87,     6,   939,    90,     6,    92,
       6,     6,     6,   946,     6,     6,    99,   232,  2021,     6,
       6,     6,     6,     6,     6,   227,     6,     6,   111,     6,
     113,   232,     6,   116,     7,     6,   119,     6,     6,   230,
       5,     7,     6,   126,   127,   128,   129,   130,     7,     8,
     133,   134,   135,   136,   137,     6,   233,   233,   141,   233,
       6,   144,   233,   233,  2067,  2068,  2069,  2070,  2071,   233,
       6,   234,   234,   233,   233,   233,   165,   233,     6,     6,
    2083,     6,   234,   234,  2020,   234,     6,   107,     6,     6,
     168,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     227,   233,   185,     6,   234,     7,   189,   190,     6,   233,
     233,   194,   195,   196,   197,   198,   233,     6,   233,   202,
       6,     6,     6,   122,     6,   233,     6,     6,     6,     6,
       6,     6,     6,   216,   217,     6,  1853,     6,   221,   234,
       6,   226,   233,   226,     6,   233,  1863,   233,   231,     6,
     233,   234,   227,  2156,   234,     6,     6,     6,     6,  2162,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   233,     6,     6,     6,   225,     6,
       6,     6,   202,   203,   204,   205,   206,     6,  2124,     6,
       6,  2194,     6,   233,     6,     6,     6,     6,   233,   219,
     233,  1134,     6,   223,   233,     6,     6,   233,     6,  2212,
       6,  2214,     6,  1361,  2024,  1878,   516,   237,   238,   239,
     240,  1627,   242,   243,   244,   245,  1375,   247,   248,   249,
     250,   251,   252,   253,   254,     3,   256,   257,   258,     3,
       3,  2244,     3,   263,  1900,  1548,   596,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   282,   283,   284,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    -1,    -1,  1227,  1228,  1229,    -1,    -1,    -1,
     320,   321,    -1,    -1,  2021,    -1,    -1,    -1,    -1,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
     360,    -1,    -1,    -1,   364,   365,   366,    -1,   368,    -1,
      -1,    -1,   372,   373,   374,    -1,    -1,   377,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   392,    -1,    -1,    -1,   225,   397,   398,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   411,   412,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,   449,
      -1,    57,    58,    59,    60,   455,    -1,   457,    -1,    65,
      66,    67,    -1,    -1,    70,  2162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,   481,   482,    -1,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,    -1,
      -1,   501,   502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2212,    -1,  2214,    -1,    -1,
     520,    -1,    -1,  2162,    -1,    -1,   526,    -1,    -1,    -1,
      -1,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   545,   546,  2244,    -1,    -1,
    1463,    -1,   552,   553,    -1,    -1,   556,   557,   558,   559,
      -1,   561,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,  2212,    -1,  2214,   576,   577,    -1,    -1,
     186,   187,   188,   583,   584,   585,   586,    -1,    -1,    -1,
     590,   591,   592,   199,    -1,   201,    -1,   597,   598,   599,
     600,   601,   602,    -1,   604,  2244,   606,    -1,   608,   609,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,   626,   627,   628,   629,
     630,   631,    -1,    -1,    -1,   635,   636,   637,   638,   639,
     640,   641,   642,   643,    12,    13,    -1,    -1,   648,    -1,
     650,   651,    -1,    -1,    -1,   655,   656,   657,    -1,    -1,
     660,   661,   662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1586,    -1,    -1,    -1,    -1,    -1,   679,
      -1,    -1,    -1,    -1,   684,   685,    -1,   687,   688,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   698,   699,
      -1,     6,    -1,   703,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,  1649,   105,  1651,    -1,
    1653,     6,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,  1669,  1670,  1671,  1672,
    1673,  1674,     6,    -1,    -1,    -1,    -1,    -1,   768,    -1,
     138,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   803,   804,    -1,    -1,   807,   808,   809,
      -1,   811,   812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     820,    -1,    -1,   823,   824,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,    -1,   846,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   859,
      -1,   861,    -1,    -1,   864,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,    -1,   879,
      -1,   881,    -1,   883,    -1,    -1,    -1,    47,    -1,   889,
      -1,    -1,    -1,    -1,   894,    -1,    -1,    -1,    -1,    -1,
       6,   901,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,   926,    -1,    -1,    -1,
      -1,    -1,    -1,   933,   934,    -1,    -1,    -1,    -1,   939,
      -1,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,   958,    -1,
     225,   961,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
     980,   225,   982,   983,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   993,    -1,  1908,    -1,  1910,    -1,  1912,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1923,  1924,  1925,  1926,  1927,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1025,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1033,  1034,  1035,    -1,  1037,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1045,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1059,
      -1,    -1,    -1,    -1,  1064,    -1,  1979,    -1,    -1,    -1,
    1983,     8,    -1,  1073,    -1,    -1,    -1,    -1,    -1,  1079,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1089,
    1090,  1091,  1092,  1093,    -1,    -1,    -1,    -1,    -1,   259,
    1100,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,   278,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2041,    -1,
      -1,    -1,  2045,    -1,    -1,    -1,    -1,    -1,   298,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,   308,   309,
      -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,  2071,    -1,
    1160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1170,  1171,    -1,  1173,  1174,    -1,  1176,  1177,  1178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,    -1,    -1,
      -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1203,    -1,  1205,    -1,  1207,    -1,  1209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,  2139,  2140,    -1,    -1,
      -1,    -1,  1232,    -1,    -1,   395,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,  1264,    -1,    -1,   225,    -1,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,   446,  1287,   225,    -1,
      -1,    -1,  1292,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    12,
      13,   100,   101,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,   120,    -1,    -1,  1334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1343,  1344,  1345,  1346,    -1,     8,   138,
    1350,  1351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1365,  1366,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,
      -1,   571,   115,   116,    -1,   118,   119,   120,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,  1442,  1443,  1444,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1454,    -1,  1456,    -1,    -1,   162,
     163,   164,    -1,  1463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1476,    -1,    -1,    -1,
      -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1489,
    1490,  1491,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,  1521,    -1,   115,   116,    -1,   118,   119,   120,    -1,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1545,   138,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,  1564,   225,    -1,    -1,    -1,  1569,
     162,   163,   164,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,  1584,  1585,    -1,    -1,    -1,    -1,
      -1,  1591,  1592,    -1,    -1,    -1,     8,    -1,  1598,    -1,
      -1,   761,   238,    -1,    -1,   765,    -1,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,  1615,  1616,  1617,  1618,  1619,
    1620,  1621,    -1,    12,    13,    -1,    -1,   263,    -1,  1629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1639,
    1640,  1641,   234,  1643,    -1,    -1,   282,    -1,   284,    -1,
      -1,    -1,     8,    -1,    -1,  1655,  1656,    -1,   238,   295,
      -1,    -1,    -1,   243,    -1,   122,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,  1674,    -1,    -1,    -1,  1678,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,  1689,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,  1709,
      -1,   100,   101,   102,    -1,   295,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,    -1,  1736,  1737,    -1,    -1,
      -1,    -1,   902,    -1,  1744,    -1,    -1,    -1,    -1,   138,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,  1771,    -1,   162,   163,   164,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,  1792,    -1,   225,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,  1811,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
    1820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1828,    -1,
    1830,    -1,    -1,  1833,    -1,    -1,   996,    -1,    -1,    -1,
    1000,    -1,    -1,    -1,  1004,   234,   482,    -1,    -1,    -1,
    1850,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,  1868,   225,
      -1,    -1,    -1,  1873,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   520,  1885,    -1,  1047,    -1,    -1,
      -1,  1891,  1892,  1893,  1894,  1895,    -1,    -1,    -1,    -1,
      -1,  1901,   482,    -1,    -1,    -1,    -1,    -1,  1908,    -1,
    1910,    -1,  1912,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     556,   557,  1922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     576,   577,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,
      -1,    -1,    -1,  1953,  1954,    -1,    -1,    -1,  1958,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   608,   609,    -1,    -1,    -1,    -1,  1138,  1139,
      -1,  1141,    -1,  1143,  1144,    -1,  1146,  1987,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,   577,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,  2018,   655,
     656,   657,    -1,    -1,  2024,  1185,   234,    -1,   608,   609,
      -1,  1191,    -1,    -1,  2034,  2035,  2036,  2037,  2038,  2039,
      -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2052,    -1,    -1,  2055,    -1,    -1,  2058,    -1,
      -1,    -1,  2062,   699,    -1,    -1,    -1,  2067,  2068,  2069,
    2070,  2071,    -1,    -1,    -1,   655,   656,   657,    -1,    -1,
      -1,  2081,    -1,    -1,  2084,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1252,    -1,    -1,    -1,    -1,    -1,    -1,   679,
      -1,    -1,    -1,    -1,    -1,  1265,  1266,  1267,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   699,
      -1,  1281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2133,  2134,  2135,  2136,  2137,  2138,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,  2156,   225,    -1,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   234,    -1,    -1,    -1,
      -1,   807,    -1,    -1,    -1,   811,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   823,   824,    -1,
      -1,    -1,  1352,    -1,    -1,    -1,   587,    -1,  2198,  2199,
    2200,  2201,  2202,  2203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,    -1,    -1,
      -1,    -1,  1382,   859,    -1,   861,    -1,   807,   864,    -1,
      -1,   811,    -1,    -1,    -1,    -1,  1396,    -1,    -1,    -1,
      -1,   877,    -1,   879,    -1,   881,    -1,   883,    -1,    -1,
      -1,    -1,    -1,   889,    -1,    -1,    -1,    -1,   894,  1419,
    1420,  1421,    -1,    -1,    -1,  1425,  1426,    -1,  1428,    -1,
    1430,    -1,  1432,    -1,  1434,  1435,  1436,    -1,    -1,   859,
      -1,   861,    -1,    -1,   864,    -1,    -1,    -1,    -1,    -1,
     926,    -1,    -1,    -1,  1454,    -1,    -1,   877,    -1,   879,
      -1,   881,    -1,   883,    -1,  1465,    -1,    -1,    -1,   889,
      -1,    -1,    -1,  1473,   894,    -1,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,    -1,   719,   720,
     721,   722,   723,   724,   725,    -1,    -1,    -1,   729,   730,
     731,    -1,    -1,    -1,   735,   736,   926,   738,    -1,    -1,
      -1,    -1,   743,   744,   745,    -1,   747,    -1,    -1,    -1,
      -1,    -1,    -1,   754,   755,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   772,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,  1037,   227,  1563,   229,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,  1576,    -1,     4,     5,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1089,  1090,  1091,  1092,  1037,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,   869,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   884,    -1,    81,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,  1089,
    1090,  1091,  1092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1683,  1160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1693,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1703,    -1,    -1,    -1,    -1,  1708,   186,
     187,   188,    -1,    -1,    -1,    -1,  1192,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1738,    -1,
    1160,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
     186,   187,   188,  1763,    -1,    -1,   232,   131,   234,    -1,
      12,    13,  1192,   199,    -1,   201,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,   168,   169,   170,   171,  1808,   173,
     174,   175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,    -1,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    12,    13,   105,    -1,    -1,    -1,    -1,  1099,   111,
     112,    -1,  1872,   115,   116,    -1,   118,   119,   120,  1879,
    1880,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   138,    -1,  1898,   225,
      -1,  1132,  1133,   229,   268,    -1,   270,   271,   272,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,  1918,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,   292,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1980,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,   142,   234,    -1,    -1,    -1,    -1,    -1,    -1,  1999,
    1476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   234,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,  1476,    -1,    -1,    -1,
     225,    -1,    -1,    -1,  1295,    -1,    -1,    -1,    -1,   234,
    1301,  1302,  1303,  1304,  1305,    -1,  1307,    -1,  1309,  1310,
      -1,  1312,  1313,  2083,    -1,  1316,  1317,  1318,    -1,    -1,
      -1,    -1,  1323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,   476,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,  1639,  1640,    65,    66,    67,  1399,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,  1416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2194,    -1,    -1,    -1,  1674,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,  1639,
    1640,    -1,    -1,    -1,    -1,    -1,   234,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
    1501,    -1,    -1,   225,    -1,  1506,    -1,    -1,   178,    -1,
      -1,    -1,   234,    -1,    -1,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,   199,
      -1,   201,   202,    12,    13,    -1,    -1,  1538,  1539,    -1,
      -1,  1542,  1543,    -1,    -1,    -1,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,    -1,
     230,   231,    -1,   233,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1820,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1833,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1850,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,   120,    -1,  1833,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1901,    -1,    -1,    -1,   138,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,  1922,    -1,   225,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1696,  1697,    -1,    -1,  1700,
    1701,    -1,    -1,    -1,    -1,  1706,  1707,    -1,    -1,    -1,
      -1,  1901,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,  1922,   100,   101,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,   115,   116,
      -1,   118,   119,   120,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1764,  1765,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,   234,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,  2067,  2068,  2069,  2070,  2071,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,  2067,  2068,  2069,
    2070,  2071,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
    2156,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,  1069,  1070,    -1,    -1,    -1,
      -1,  1075,  1076,    -1,    -1,   111,    -1,   113,    -1,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,  2156,   133,   134,   135,
     136,   137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,
     196,   197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,   231,    -1,    -1,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
    1284,  1285,    -1,    80,    81,  1289,  1290,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,  2167,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,   199,    -1,   201,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,     5,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,   199,    -1,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,     5,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,     5,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,    -1,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,    -1,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,    -1,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,    -1,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,    -1,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,    -1,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,    -1,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,    -1,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,    -1,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,    -1,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,    -1,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,     3,     4,    -1,   231,    -1,   233,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,   226,    -1,     3,     4,     5,   231,
      -1,   233,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,     3,
       4,     5,    -1,    80,    81,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,   185,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,   195,   196,
     197,   198,   199,    -1,   201,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,    -1,   233,    -1,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,
      -1,   185,   186,   187,   188,   189,   234,    -1,    -1,    -1,
     194,   195,   196,   197,   198,   199,    -1,   201,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,   226,    -1,     3,     4,     5,   231,    -1,   233,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,     3,     4,    -1,
      -1,    80,    81,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    53,    54,    55,
      56,   225,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   234,    -1,    -1,    -1,   185,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,
     199,    -1,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,   231,    -1,   233,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,   234,   189,    -1,    -1,    -1,    -1,   194,   195,
     196,   197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
     226,    -1,     3,     4,    -1,   231,    -1,   233,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    53,    54,    55,    56,   225,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,    -1,
      72,    73,    74,   194,   195,   196,   197,   198,    80,    -1,
      -1,   202,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,   216,   217,    99,    -1,    -1,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   111,
     231,   113,   233,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,   141,
      -1,    -1,   144,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,
       3,     4,     5,    -1,   226,    -1,     9,    10,    11,   231,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,     3,     4,    -1,    -1,    80,    81,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    53,    54,    55,    56,   225,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,   185,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,   195,   196,   197,   198,   199,    -1,   201,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,   231,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   233,    -1,    -1,   189,
      -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,    -1,
      -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,    -1,    -1,
      -1,   221,     3,     4,    -1,    -1,   226,   227,     9,    10,
      11,   231,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    53,    54,    55,    56,   225,    -1,    -1,    -1,
      61,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,     3,
       4,    72,    73,    74,    -1,     9,    10,    11,    -1,    80,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    53,
      54,    55,    56,   225,    -1,    -1,    -1,    61,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,   229,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,    -1,
      -1,    -1,    -1,   194,   195,   196,   197,   198,    -1,    -1,
      -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,   229,    -1,
     231,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,   185,   227,    -1,    -1,   189,    -1,   232,    -1,    -1,
     194,   195,   196,   197,   198,    -1,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,    -1,    -1,    -1,   221,     3,     4,
      -1,    -1,   226,   227,     9,    10,    11,   231,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    53,    54,
      55,    56,   225,    -1,    -1,    -1,    61,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
       3,     4,    -1,     6,    -1,    80,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      53,    54,    55,    56,   225,    -1,    -1,    -1,    61,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,
     195,   196,   197,   198,    -1,    -1,    -1,   202,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,   229,    -1,   231,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,   185,   232,    -1,    -1,   189,    -1,    -1,    -1,
      -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,    -1,    -1,    -1,   221,     3,
       4,    -1,     6,   226,    -1,     9,    10,    11,   231,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    53,
      54,    55,    56,   225,    -1,    -1,    -1,    61,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,     3,     4,    72,    73,
      74,    -1,     9,    10,    11,    -1,    80,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    53,    54,    55,    56,
     225,    -1,    -1,    -1,    61,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,
     194,   195,   196,   197,   198,    -1,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,   226,    12,    13,    -1,    -1,   231,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   185,    -1,
      -1,    -1,   189,   232,    -1,    -1,    -1,   194,   195,   196,
     197,   198,    12,    13,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,    12,    13,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,   120,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,   138,
     100,   101,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,   119,
     120,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,   138,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,    -1,   162,   163,   164,    -1,   111,   112,    -1,    -1,
     115,   116,    -1,   118,   119,   120,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,   138,   225,   234,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   162,   163,   164,
     100,   101,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,    -1,   234,   115,   116,    -1,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,   138,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   162,   163,   164,    -1,   225,    -1,    -1,   234,
     229,    -1,    42,    43,    -1,    -1,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    62,    63,    64,   225,    -1,    -1,    68,    69,
      -1,    71,   232,    -1,    -1,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,   102,   103,   234,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,     4,
     150,   151,   152,    -1,    -1,    -1,   156,    12,    13,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,   169,
      -1,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,    -1,    -1,    42,    43,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,   202,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,   102,   103,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      -1,    -1,   167,    -1,   169,    -1,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,   202,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   232,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
     229,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,   229,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,   229,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,   229,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,   229,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,   229,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,   229,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,
      -1,   229,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,   229,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,   229,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
     229,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,   229,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,   229,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,   229,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,   229,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,   227,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,   227,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,   227,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,   227,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,   227,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,   227,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,   227,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,   227,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,   227,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,   227,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,   227,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,   227,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,    -1,   227,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,   227,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,   227,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,   225,    -1,   227,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   237,   238,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     103,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     115,   116,   117,   118,   119,   120,   121,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     150,   151,   152,   156,   161,   162,   163,   164,   167,   169,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   191,   192,   193,   200,   202,   239,
     241,   242,   262,   281,   282,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   309,   311,   312,   318,   319,   320,
     321,   339,   340,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      65,    66,    67,    70,    72,    73,    74,    80,    81,   178,
     185,   186,   187,   188,   189,   194,   195,   196,   197,   198,
     199,   201,   216,   217,   221,   226,   228,   230,   231,   233,
     235,   260,   322,   323,   335,   336,   339,   340,    13,    90,
     226,   226,     6,   233,     6,     6,     6,     6,   226,     6,
       6,   228,   228,   226,   228,   260,   260,   226,   233,   226,
     226,     4,   226,   233,   226,   226,     4,   226,   233,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   104,
      90,    90,     6,   233,    84,    87,    90,   226,     4,    37,
      38,    39,    40,    41,    84,    87,    90,    92,   111,   116,
     119,   190,   217,   226,   233,   282,   293,   309,   311,   322,
     328,   330,   339,   340,   226,   233,    90,    90,   111,    87,
      90,    92,    92,    84,    87,    90,    92,    87,    90,    92,
      87,    90,   226,    87,   167,   183,   184,   233,   216,   217,
     226,   233,   325,   326,   325,   233,    84,    87,    90,   233,
     325,     4,    84,    88,    94,    95,    97,    98,   115,   226,
      90,    92,    90,    87,     4,   178,   233,   339,   340,     4,
       6,    84,    87,    90,    87,    90,     4,     4,     4,     5,
     226,   328,   329,     4,   226,   226,   226,     4,   233,   332,
     340,     4,   226,   226,   226,     6,     6,   228,     4,   336,
     340,   226,     4,   336,     5,   233,     5,   233,     4,   322,
     339,   228,   226,   233,     6,   226,   233,   226,   228,   235,
     260,     7,   203,   204,   205,   206,   223,   224,   258,   259,
       4,   226,   228,   230,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   226,
     226,   226,   260,   260,   260,   260,   226,   260,   260,   260,
     260,   260,   260,   226,   260,   260,   260,     7,   226,   226,
     226,   260,   260,   226,   226,   228,   322,   322,   322,   227,
     322,   229,   322,     4,   167,   168,   340,     4,   282,   283,
     284,   233,   233,     6,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   225,   233,
       6,   226,   228,   259,     6,   322,     4,   335,   336,   339,
     340,   335,   322,   335,   338,   264,   269,   336,   340,   322,
     217,   322,   330,   331,   322,   322,   226,   322,   331,   322,
     322,   226,   322,   331,   322,   322,   322,   322,   322,   322,
     335,   322,   322,   322,   328,   226,   233,   331,   329,   329,
     329,   335,   226,   228,   230,   260,   226,   228,   260,   260,
     260,   260,     5,   170,   233,     5,   170,     5,   170,     5,
     170,   111,    84,    87,    90,    92,   260,   233,   322,   330,
     322,   234,   331,     8,   218,   226,   228,   260,   322,   331,
     226,   226,   226,   328,   329,   329,   329,   226,   226,   226,
     226,   226,   226,   328,   226,   328,   226,   328,   233,   233,
     322,     4,   328,   332,   233,   233,   325,   325,   325,   322,
     322,   216,   217,   233,   233,   325,   233,   233,   233,   216,
     217,   226,   284,   325,   233,   226,   233,   226,   226,   226,
     226,   226,   226,   226,   322,   329,   329,   329,   226,     4,
     228,   228,   284,     6,     6,   233,   233,   233,   329,   329,
     228,   228,   228,   322,     6,     6,   322,   322,   322,   230,
     322,   233,   170,   322,   322,   322,   322,     6,     6,   233,
       6,   284,     6,   284,   226,   228,   233,   226,   228,   335,
     322,   284,   328,   328,   227,   322,   229,   322,   233,   233,
     336,   328,     6,   228,   322,   322,     4,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   338,
     335,   338,   335,   335,   335,   335,   335,   335,   335,   328,
     335,   335,   322,   335,   335,   335,   338,   335,   322,   336,
     322,   335,   335,   335,   335,   335,   340,   336,   340,     7,
     206,   258,   227,     7,   206,   258,   229,     7,   258,   259,
     230,     7,   260,   234,    84,    87,    90,    92,   111,   116,
     120,   281,   322,   331,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   243,
     322,   322,     6,   226,   228,   230,   227,   232,   226,   228,
     227,   232,   232,   227,   232,   229,   232,   263,   229,   263,
     232,   232,   227,   218,   232,   234,   227,   227,   322,   227,
     234,   227,   227,   322,   227,   234,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,     7,   322,   322,   234,
       6,     6,     6,   227,   322,   322,     4,   227,   229,   233,
     261,   233,   322,   330,   233,   330,   340,   322,   322,   335,
     322,    62,   322,    62,    62,    62,     5,   233,     5,   233,
       5,   233,     5,   233,   330,   331,   227,   234,   322,   233,
     322,   330,   322,   322,   233,   261,   227,   234,   322,   322,
     322,     7,     7,   315,   315,   322,   275,   322,   336,   276,
     322,   336,   277,   322,   336,   278,   322,   336,   322,     6,
     322,     6,   322,     6,   331,   331,   233,   227,     6,   233,
     284,   284,   232,   232,   232,   325,   325,   283,   283,   232,
     322,   322,   322,   322,   234,   297,   232,   284,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   227,     7,   316,
       6,     7,   322,     6,   322,   322,   234,   331,   331,   331,
       6,     6,   322,   322,   322,   227,   227,   227,   227,   167,
     232,   284,   233,     8,   227,   227,   229,   331,   234,   234,
     284,   229,   227,   142,   310,   227,   232,   234,     7,   206,
     258,   227,     7,   206,   258,   229,   322,   331,     6,     6,
     322,   227,   229,   259,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   232,   261,   261,   261,   261,
     261,   261,   261,   232,   232,   232,   261,   232,   261,   261,
     227,   227,   232,   261,   261,   232,   261,   232,   232,   232,
     232,   261,   261,   261,   227,   261,   324,   337,     6,   232,
     232,   227,   232,   261,   232,   261,   227,   227,   229,    44,
      44,   328,     7,   258,   259,    44,    44,   328,   230,   258,
     259,   336,   322,     6,     4,     4,   233,   333,   261,   233,
     233,   233,   233,   226,   111,    87,    90,    92,   234,   234,
       8,     4,   157,   158,   159,   160,   234,   246,   250,   253,
     255,   256,   227,   229,   322,   322,     4,     6,   213,   240,
     331,   322,   322,     6,   331,   322,     6,   335,     6,   340,
       6,   335,   322,   336,     7,   322,   330,   170,     7,     7,
     227,     7,   170,     7,     7,   227,     7,   170,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   322,   227,   234,
     233,     6,   227,   229,   331,   331,   227,   331,   229,   229,
     232,   232,   261,   232,   233,   234,   233,   233,   233,   331,
     331,   331,   331,   261,   234,     7,     8,   331,   227,   229,
     331,     7,   233,   227,   227,   227,   322,   328,     4,   314,
       6,   227,   227,   232,   227,   232,   227,   232,   227,   232,
     227,   227,   227,   234,   234,   331,   230,   284,   234,   234,
     325,   322,   322,   234,   234,   322,   325,   232,   232,   232,
     122,   122,   139,   147,   148,   149,   153,   154,   307,   308,
     325,   234,   294,   227,   234,   227,   227,   227,   227,   227,
     227,   227,     7,   322,     6,   322,   227,   229,   229,   234,
     234,   234,   229,   229,   232,     7,     7,     7,   230,   322,
     234,   322,   322,     7,   230,   234,   234,     7,     6,   322,
     234,   233,   328,     6,    44,    44,   328,   258,   259,    44,
      44,   328,   258,   259,   234,   234,   229,   259,   230,   259,
     335,   322,   322,   322,   322,   331,   335,   322,   328,   335,
     335,   335,   271,   273,   322,   335,   335,   322,   260,   260,
       6,   322,     6,   260,   260,     6,     4,   167,   168,   322,
       6,     6,     6,     7,   228,   332,   334,     6,   331,   331,
     331,   331,   322,   226,   226,   226,   226,   261,   322,   247,
     226,   226,   233,   257,     6,   259,   259,   227,   229,   213,
     335,   227,   227,   229,   227,   232,     7,   226,   228,   261,
     261,   325,    90,    92,   328,   328,     7,   328,    90,    92,
     328,   328,     7,   328,    92,   328,   328,   328,   328,   328,
     328,   328,   328,   328,     6,     7,     7,   331,   230,   234,
     234,   234,   322,   322,   322,   322,   322,   322,   322,   234,
     234,   234,   234,   328,   322,   234,   234,   328,   331,     7,
       7,     7,   122,   313,     6,     7,   258,   322,   258,   322,
     258,   322,   258,   322,     7,     7,     7,     7,     7,   234,
       4,   234,   232,   232,   232,   234,   234,   325,   325,   325,
     102,     4,     6,   322,   233,     6,   226,     6,   155,     6,
     155,   234,   308,   232,   307,     7,     6,     7,     7,     7,
       7,     7,     7,     7,   328,     6,   233,     6,     6,     6,
      90,     7,     6,     6,   322,   328,   328,   328,     4,   232,
       8,     8,   227,     4,     4,   232,   233,     6,   233,   328,
     234,   260,   260,     6,   322,     6,   260,   260,     6,   322,
       6,   261,     6,     4,     6,   261,   261,   261,   261,   261,
     232,   232,   261,   227,   261,   261,   232,   232,   261,   272,
     232,   261,   274,   227,   227,   261,   261,   261,   338,   338,
       6,   261,   338,   338,     7,   258,   259,   230,     7,     6,
     332,   322,   232,   234,   234,   234,   234,   234,   227,   322,
     322,   322,   322,   258,   226,   322,   322,   327,   328,   233,
     230,     6,     6,   240,     6,   322,   233,   322,   336,   227,
     229,     6,     6,     6,   233,   233,   115,   280,   280,   328,
       6,   233,   233,     6,     6,   328,   170,   279,   233,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     5,   328,
     234,     4,   261,   227,   229,   232,   232,   232,   232,   232,
     232,   232,     6,   261,     6,   234,   328,   328,   328,     4,
       6,   328,   328,   328,   328,   328,   328,   328,   328,   233,
     233,     7,     6,     7,   322,   322,   322,   233,   233,   232,
     234,   232,   234,   232,   234,   233,   228,     6,   322,   328,
     322,     6,     6,   322,   325,   234,     5,   328,   233,   233,
     233,   233,   233,   233,   233,   328,     6,   331,   233,   322,
     229,     6,     6,   166,   322,   322,   322,     6,     6,     7,
     336,   284,   284,   232,     6,   261,   338,   338,     6,   261,
     338,   338,     6,   258,   259,   335,   322,   335,     4,     4,
     182,     6,   261,   261,     6,   261,   261,   336,   322,     6,
       4,   333,     6,   229,   332,     6,     6,     6,     6,   227,
     227,   227,   227,   328,   244,   322,   232,   232,   232,   234,
     245,   322,     4,   335,   232,   328,   336,     7,     7,   322,
     322,   325,     6,     6,     6,   322,   322,     6,    88,     6,
     322,     5,     6,   233,   322,   322,   322,   322,   322,   322,
     322,   233,     6,   279,     6,   322,     6,     6,     6,     6,
       6,     6,     4,     6,     6,   331,   331,   322,   322,   336,
     234,   227,   232,   234,   283,   283,   325,     6,   298,   325,
       6,   299,   325,     6,   300,   322,   322,   234,   232,   227,
     234,   232,     6,     6,   327,   325,   325,   325,   325,   325,
     217,   325,     6,   234,   322,     6,     6,   328,   232,   234,
       8,   234,   227,   233,   322,   336,   232,   310,   310,   328,
       6,   261,   261,     6,   261,   261,   328,   227,   261,   261,
     233,   328,   336,   233,   322,   336,   336,     6,     6,     6,
       6,     6,     6,     7,     6,   230,     6,   227,   232,   322,
     322,   328,   233,   232,   234,     6,   322,   265,   268,   233,
     233,   234,   234,   234,   234,   233,   234,     5,   327,   261,
     261,   232,   232,   232,   232,   232,   322,     6,   233,   234,
     234,   233,     6,     6,   233,   322,   234,   234,   232,   233,
     232,   233,   232,   233,   234,   229,     6,   328,     7,   233,
     322,   234,   232,   232,   232,   232,   232,   232,     6,   234,
     165,   322,   322,   331,     6,     6,   336,   234,   234,   234,
       6,     6,     6,     6,     6,   270,   322,   330,   338,   332,
     168,   248,   322,   232,   232,   327,   322,     6,   232,   271,
     273,   328,   328,     6,     6,     6,     6,   322,     6,     6,
     234,   322,   322,   322,   322,   322,   234,   327,   126,   127,
     132,   317,   126,   127,   317,   331,   283,   232,   234,   322,
     325,   307,   322,   325,   307,   322,   325,   307,     6,   232,
     234,   328,   284,   234,     6,   331,   325,   325,   325,   325,
     325,   322,   234,   234,   234,   227,   233,     6,   232,   234,
       7,     7,   234,     6,   233,   322,   322,   234,   322,   234,
     234,   267,   266,   234,   233,   232,   232,   232,   232,   232,
     234,   233,   325,   328,     6,   233,   325,     6,   234,   234,
     322,   234,   232,   234,   234,   232,   234,   234,   232,   234,
     328,     6,   122,   234,   295,   233,   234,   232,   232,   232,
     232,   232,     6,     6,     6,   284,   322,   336,   340,   245,
     227,   232,     6,   233,   232,   271,   271,   322,   322,   322,
     322,   322,   322,     6,   325,     6,   325,     6,     6,   234,
       6,   301,   322,     6,     6,   302,   322,     6,     6,   303,
     322,     6,   234,   322,   307,   284,     6,   331,   331,   331,
     331,   325,   331,   310,     7,   226,   234,   251,   322,   327,
     322,   234,   234,   232,   232,   232,   232,   232,   232,   232,
     232,   233,   234,   233,   234,   233,   234,     6,     6,   234,
     234,   296,   234,   234,   234,   234,   232,   234,   234,   336,
     227,     6,   233,   227,   234,   234,   322,   322,   322,   322,
     322,   322,   325,   325,   307,     6,   304,   307,     6,   305,
     307,     6,   306,   307,     6,     6,     6,     6,   331,     6,
       6,   249,   335,   254,   233,     6,   234,   261,   232,   232,
     232,   232,   232,   232,   234,   233,   234,   233,   234,   233,
     234,   234,   232,   234,   233,   327,     6,   322,   322,   322,
     322,   322,   322,     6,   307,     6,   307,     6,   307,     6,
     335,     6,   252,   335,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   232,   234,     6,     6,     6,     6,
       6,     6,   335,     6
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
#line 215 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 228 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 230 "Gmsh.y"
    {
      // FIXME: when changing to OpenCASCADE, get maxTags from GEO_Internals and
      // add that info in OCC_Internals - same in the other direction
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 237 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 238 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 239 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 240 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 241 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 242 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 243 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 244 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 245 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 246 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 247 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 248 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 249 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 250 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 251 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 256 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 260 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 267 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 272 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 277 "Gmsh.y"
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

  case 31:
#line 291 "Gmsh.y"
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

  case 32:
#line 304 "Gmsh.y"
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

  case 33:
#line 317 "Gmsh.y"
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

  case 34:
#line 345 "Gmsh.y"
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

  case 35:
#line 359 "Gmsh.y"
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

  case 36:
#line 372 "Gmsh.y"
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

  case 37:
#line 385 "Gmsh.y"
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

  case 38:
#line 403 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 417 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 419 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 424 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 426 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 431 "Gmsh.y"
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

  case 49:
#line 535 "Gmsh.y"
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

  case 50:
#line 545 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 554 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 561 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 571 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 54:
#line 580 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 589 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 596 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 606 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 614 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 624 "Gmsh.y"
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

  case 60:
#line 643 "Gmsh.y"
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

  case 61:
#line 662 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 668 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 675 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 676 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 677 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 678 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 679 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 683 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 684 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 690 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 690 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 691 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 691 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 76:
#line 700 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 77:
#line 705 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 78:
#line 711 "Gmsh.y"
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

  case 79:
#line 773 "Gmsh.y"
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

  case 80:
#line 790 "Gmsh.y"
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
#line 819 "Gmsh.y"
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

  case 82:
#line 848 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 853 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 858 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 863 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 868 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 87:
#line 875 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 88:
#line 885 "Gmsh.y"
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
#line 914 "Gmsh.y"
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

  case 90:
#line 943 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 91:
#line 948 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 953 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 958 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 94:
#line 966 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 95:
#line 975 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 96:
#line 981 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 987 "Gmsh.y"
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
#line 1000 "Gmsh.y"
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

  case 99:
#line 1013 "Gmsh.y"
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
#line 1028 "Gmsh.y"
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

  case 101:
#line 1045 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 102:
#line 1051 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 103:
#line 1057 "Gmsh.y"
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
#line 1070 "Gmsh.y"
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

  case 105:
#line 1083 "Gmsh.y"
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
#line 1098 "Gmsh.y"
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

  case 107:
#line 1115 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 108:
#line 1121 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 109:
#line 1130 "Gmsh.y"
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

  case 110:
#line 1148 "Gmsh.y"
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

  case 111:
#line 1166 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 112:
#line 1175 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 113:
#line 1187 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 114:
#line 1192 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 115:
#line 1200 "Gmsh.y"
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

  case 116:
#line 1220 "Gmsh.y"
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

  case 117:
#line 1243 "Gmsh.y"
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

  case 118:
#line 1254 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 119:
#line 1262 "Gmsh.y"
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

  case 120:
#line 1284 "Gmsh.y"
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

  case 121:
#line 1307 "Gmsh.y"
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

  case 122:
#line 1345 "Gmsh.y"
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

  case 123:
#line 1366 "Gmsh.y"
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

  case 124:
#line 1378 "Gmsh.y"
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

  case 128:
#line 1396 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 129:
#line 1405 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 130:
#line 1414 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 131:
#line 1416 "Gmsh.y"
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

  case 132:
#line 1434 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 133:
#line 1436 "Gmsh.y"
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

  case 134:
#line 1452 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 135:
#line 1454 "Gmsh.y"
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

  case 136:
#line 1470 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 137:
#line 1479 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 138:
#line 1481 "Gmsh.y"
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

  case 140:
#line 1495 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 141:
#line 1503 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 142:
#line 1509 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 143:
#line 1514 "Gmsh.y"
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

  case 146:
#line 1545 "Gmsh.y"
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

  case 147:
#line 1556 "Gmsh.y"
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

  case 148:
#line 1571 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 151:
#line 1587 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 152:
#line 1595 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 153:
#line 1604 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 154:
#line 1612 "Gmsh.y"
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

  case 155:
#line 1630 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 156:
#line 1634 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 157:
#line 1640 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 158:
#line 1648 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 159:
#line 1652 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 160:
#line 1658 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 161:
#line 1666 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 162:
#line 1670 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 163:
#line 1676 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 164:
#line 1684 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 165:
#line 1688 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 166:
#line 1694 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 167:
#line 1702 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 168:
#line 1706 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 169:
#line 1712 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 170:
#line 1716 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 171:
#line 1723 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addVertex(num, x, y, z, lc);
      }
      else{
        if(!myGmshSurface)
          GModel::current()->getGEOInternals()->addVertex(num, x, y, z, lc);
        else
          GModel::current()->getGEOInternals()->addVertex(num, x, y, myGmshSurface, lc);
      }
      AddToTemporaryBoundingBox(x, y, z);
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 172:
#line 1744 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1758 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Spline not available with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 174:
#line 1772 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      if(factory == "OpenCASCADE"){
        if(tags.size() == 3){
          GModel::current()->getOCCInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 4 && param.size() <= 6){
          double r = param[3];
          double a1 = (param.size() == 6) ? param[4] : 0.;
          double a2 = (param.size() == 6) ? param[5] :
            (param.size() == 5) ? param[4] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addCircle
            (num, param[0], param[1], param[2], r, a1, a2);
        }
        else{
          yymsg(0, "Circle requires 3 points or 4 to 6 parameters");
        }
      }
      else{
        if(tags.size() == 3){
          GModel::current()->getGEOInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 175:
#line 1807 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      if(factory == "OpenCASCADE"){
        if(tags.size() == 3){
          GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(tags.size() == 4){
          GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 or 4 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 4){
          GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 176:
#line 1845 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addBSpline(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1859 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 178:
#line 1874 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), knots);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Nurbs not available yet with OpenCASCADE factory");
      }
      else{
        int order = knots.size() - tags.size() - 1;
        if(order != (int)(yyvsp[(10) - (11)].d))
          yymsg(1, "Incompatible Nurbs order: using %d", order);
        GModel::current()->getGEOInternals()->addNurbs(num, tags, knots);
      }
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1893 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1902 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available using OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1916 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addLineLoop(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addLineLoop(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 182:
#line 1931 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 183:
#line 1945 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      if(factory == "OpenCASCADE"){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE face filling requires a single line loop");
        }
        else{
          GModel::current()->getOCCInternals()->addSurfaceFilling(num, wires[0]);
        }
      }
      else{
        GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(7) - (8)].i));
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 184:
#line 1964 "Gmsh.y"
    {
      yymsg(1, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(8) - (9)].i));
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 1974 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 1980 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 1986 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 1993 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      (yyval.s).Type = 0;
      if(param.size() == 4 || param.size() == 5){
        if(factory == "OpenCASCADE"){
          double alpha = (param.size() == 5) ? param[4] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addSphere
            (num, param[0], param[1], param[2], param[3], alpha);
        }
        else{
          yymsg(0, "Sphere only available with OpenCASCADE factory");
        }
        (yyval.s).Type = MSH_VOLUME;
      }
      else if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometrySphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "Sphere requires 2 points or 4 or 5 parameters");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2020 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometryPolarSphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "PolarSphere requires 2 points");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 190:
#line 2035 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 6){
          GModel::current()->getOCCInternals()->addBlock
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Block requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Block only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2055 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 5 || param.size() == 6){
          double alpha = (param.size() == 6) ? param[5] : 2*M_PI;
          GModel::current()->getOCCInternals()->addTorus
            (num, param[0], param[1], param[2], param[3], param[4], alpha);
        }
        else{
          yymsg(0, "Torus requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Torus only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2076 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 6 || param.size() == 7){
          double r = (param.size() == 7) ? param[6] : 0.;
          GModel::current()->getOCCInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4], param[5], r);
        }
        else{
          yymsg(0, "Rectangle requires 6 ou 7 parameters");
        }
      }
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2097 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 4 || param.size() == 5){
          double ry = (param.size() == 5) ? param[4] : param[3];
          GModel::current()->getOCCInternals()->addDisk
            (num, param[0], param[1], param[2], param[3], ry);
        }
        else{
          yymsg(0, "Disk requires 4 or 5 parameters");
        }
      }
      else{
        yymsg(0, "Disk only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 194:
#line 2118 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 7 || param.size() == 8){
          double angle = (param.size() == 8) ? param[7] : 2*M_PI;
          GModel::current()->getOCCInternals()->addCylinder
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], angle);
        }
        else{
          yymsg(0, "Cylinder requires 7 or 8 parameters");
        }
      }
      else{
        yymsg(0, "Cylinder only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 195:
#line 2140 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 8 || param.size() == 9){
          double alpha = (param.size() == 9) ? param[8] : 2*M_PI;
          GModel::current()->getOCCInternals()->addCone
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], param[7], alpha);
        }
        else{
          yymsg(0, "Cone requires 8 or 9 parameters");
        }
      }
      else{
        yymsg(0, "Cone only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2162 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 7){
          GModel::current()->getOCCInternals()->addWedge
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6]);
        }
        else{
          yymsg(0, "Wedge requires 7 parameters");
        }
      }
      else{
        yymsg(0, "Wedge only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 197:
#line 2183 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE"){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(unsigned int i = 2; i < param.size(); i++)
            exclude.push_back(param[i]);
          GModel::current()->getOCCInternals()->addThickSolid
            (num, in, exclude, offset);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 parameters");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
    ;}
    break;

  case 198:
#line 2206 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 199:
#line 2216 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (12)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (12)].l), tags);
      std::vector<int> bndTags[4];
      for(int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
        if(i < 4)
          ListOfDouble2Vector(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i), bndTags[i]);
        else
          break;
      }
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags, bndTags);
      List_Delete((yyvsp[(7) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
      List_Delete((yyvsp[(10) - (12)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 200:
#line 2236 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 201:
#line 2251 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 202:
#line 2265 "Gmsh.y"
    {
      yymsg(1, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 203:
#line 2280 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, out, true, false);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 204:
#line 2295 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, out, true, true);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 205:
#line 2310 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 206:
#line 2319 "Gmsh.y"
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

  case 207:
#line 2362 "Gmsh.y"
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

  case 208:
#line 2405 "Gmsh.y"
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

  case 209:
#line 2448 "Gmsh.y"
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

  case 210:
#line 2496 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
          List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->translate(in, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 211:
#line 2513 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++){
          List_Read((yyvsp[(10) - (11)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->rotate(in, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2],
                                                     (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 212:
#line 2531 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("Symmetry not implemented yet with OpenCASCADE factory");
      }
      else{
        SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 213:
#line 2541 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 214:
#line 2551 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 215:
#line 2561 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        if(factory == "OpenCASCADE"){
          std::vector<int> in[4], out[4];
          Shape TheShape;
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
            List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
            int dim = TheShape.Type / 100 - 1;
            if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
          }
          GModel::current()->getOCCInternals()->copy(in, out);
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
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
            Shape TheShape;
            List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
            CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
            List_Add((yyval.l), &TheShape);
          }
        }
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "Boundary") || !strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary")){
        if(factory == "OpenCASCADE"){
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

  case 216:
#line 2624 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        yymsg(0, "Intersect Line not available with OpenCASCADE");
      }
      else{
        IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      }
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 217:
#line 2635 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      if(factory == "OpenCASCADE"){
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

  case 218:
#line 2650 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 219:
#line 2651 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2656 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 221:
#line 2660 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 222:
#line 2664 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_POINT;
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 223:
#line 2675 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_SEGM_LINE;
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 224:
#line 2686 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_SURF_PLAN; // we don't care about the actual type
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 225:
#line 2697 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        s.Type = MSH_VOLUME;
        List_Add((yyval.l), &s);
      }
    ;}
    break;

  case 226:
#line 2713 "Gmsh.y"
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

  case 227:
#line 2735 "Gmsh.y"
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

  case 228:
#line 2762 "Gmsh.y"
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

  case 229:
#line 2784 "Gmsh.y"
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

  case 230:
#line 2806 "Gmsh.y"
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

  case 231:
#line 2828 "Gmsh.y"
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

  case 232:
#line 2884 "Gmsh.y"
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

  case 233:
#line 2908 "Gmsh.y"
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

  case 234:
#line 2933 "Gmsh.y"
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

  case 235:
#line 2958 "Gmsh.y"
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

  case 236:
#line 3071 "Gmsh.y"
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

  case 237:
#line 3090 "Gmsh.y"
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

  case 238:
#line 3133 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->remove(in);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        Shape TheShape;
        List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
        DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 3152 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 240:
#line 3158 "Gmsh.y"
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

  case 241:
#line 3173 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	GModel::current()->getGEOInternals()->resetPhysicalGroups();
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

  case 242:
#line 3201 "Gmsh.y"
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

  case 243:
#line 3218 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3227 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 245:
#line 3241 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 246:
#line 3255 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 247:
#line 3261 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3267 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 249:
#line 3276 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3285 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 251:
#line 3294 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3308 "Gmsh.y"
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
	// make sure we have the latest data from CAD internals in GModel (fixes
	// bug where we would have no geometry in the picture if the print
	// command is in the same file as the geometry)
        if(GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
        if(GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// sync CAD internals here, so that if we e.g. import a STEP file, we
        // have the correct entity tags and the numberings don't clash
        if(GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
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

  case 253:
#line 3378 "Gmsh.y"
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

  case 254:
#line 3396 "Gmsh.y"
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

  case 255:
#line 3413 "Gmsh.y"
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

  case 256:
#line 3428 "Gmsh.y"
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
        if(GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
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

  case 257:
#line 3460 "Gmsh.y"
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

  case 258:
#line 3472 "Gmsh.y"
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

  case 259:
#line 3496 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 260:
#line 3500 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 261:
#line 3505 "Gmsh.y"
    {
      // force sync
      GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 262:
#line 3511 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 263:
#line 3516 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    ;}
    break;

  case 264:
#line 3525 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 265:
#line 3530 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 266:
#line 3536 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 267:
#line 3544 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 268:
#line 3548 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 269:
#line 3552 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 270:
#line 3561 "Gmsh.y"
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
            if(GModel::current()->getOCCInternals()->getChanged())
              GModel::current()->getOCCInternals()->synchronize(GModel::current());
            if(GModel::current()->getGEOInternals()->getChanged())
              GModel::current()->getGEOInternals()->synchronize(GModel::current());
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

  case 271:
#line 3623 "Gmsh.y"
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

  case 272:
#line 3639 "Gmsh.y"
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

  case 273:
#line 3656 "Gmsh.y"
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

  case 274:
#line 3673 "Gmsh.y"
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

  case 275:
#line 3695 "Gmsh.y"
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

  case 276:
#line 3717 "Gmsh.y"
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

  case 277:
#line 3752 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 278:
#line 3760 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3768 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 280:
#line 3774 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 281:
#line 3781 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3788 "Gmsh.y"
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

  case 283:
#line 3808 "Gmsh.y"
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

  case 284:
#line 3834 "Gmsh.y"
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

  case 285:
#line 3846 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 286:
#line 3858 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4], out[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
          List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->extrude(-1, in, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], out);
        for(int dim = 0; dim < 4; dim++){
          for(unsigned int i = 0; i < out[dim].size(); i++){
            Shape s;
            s.Num = out[dim][i];
            s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            List_Add((yyval.l), &s);
          }
        }
      }
      else{
        ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
                      (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
                      NULL, (yyval.l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 287:
#line 3888 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4], out[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++){
          List_Read((yyvsp[(10) - (11)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->revolve(-1, in, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2],
                                                      (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), out);
        for(int dim = 0; dim < 4; dim++){
          for(unsigned int i = 0; i < out[dim].size(); i++){
            Shape s;
            s.Num = out[dim][i];
            s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            List_Add((yyval.l), &s);
          }
        }
      }
      else{
        ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
                      0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
                      NULL, (yyval.l));
      }
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 288:
#line 3919 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 289:
#line 3927 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3933 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 291:
#line 3941 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3947 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 293:
#line 3955 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3961 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 295:
#line 3969 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3975 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 297:
#line 3982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4], out[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
          List_Read((yyvsp[(3) - (9)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->addPipe(-1, in, (int)(yyvsp[(8) - (9)].d), out);
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
        yymsg(0, "Pipe only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 298:
#line 4009 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, false);
        for(unsigned int i = 0; i < out[2].size(); i++){
          Shape s;
          s.Type = MSH_SURF_FROM_GMODEL;
          s.Num = out[2][i];
          List_Add((yyval.l), &s);
        }
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 299:
#line 4028 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, true);
        for(unsigned int i = 0; i < out[2].size(); i++){
          Shape s;
          s.Type = MSH_SURF_REGL;
          s.Num = out[2][i];
          List_Add((yyval.l), &s);
        }
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 300:
#line 4047 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges, out[4];
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        GModel::current()->getOCCInternals()->fillet(regions, edges, radius, out);
        Shape TheShape;
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
        yymsg(0, "Fillet only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    ;}
    break;

  case 301:
#line 4073 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4080 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 303:
#line 4087 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 304:
#line 4094 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4101 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4108 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4115 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4122 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 4129 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 4136 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4142 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4149 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4155 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4162 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4168 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4175 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4188 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4194 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4201 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4207 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 322:
#line 4214 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4220 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 324:
#line 4227 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4233 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 326:
#line 4240 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 327:
#line 4246 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 328:
#line 4257 "Gmsh.y"
    {
    ;}
    break;

  case 329:
#line 4260 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 4266 "Gmsh.y"
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

  case 331:
#line 4278 "Gmsh.y"
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

  case 332:
#line 4298 "Gmsh.y"
    {
      yymsg(1, "Explicit region numbers in layers are deprecated");
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

  case 333:
#line 4321 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 334:
#line 4325 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 335:
#line 4329 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 336:
#line 4333 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 337:
#line 4337 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 338:
#line 4341 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 339:
#line 4345 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 340:
#line 4349 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 341:
#line 4358 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 342:
#line 4370 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 343:
#line 4371 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 344:
#line 4372 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 345:
#line 4373 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 346:
#line 4374 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 347:
#line 4378 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 348:
#line 4379 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 349:
#line 4380 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 350:
#line 4385 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(3) - (9)].l), i, &s); int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) shape[dim].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (9)].l), i, &s);int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) tool[dim].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), shape, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        for(int dim = 0; dim < 4; dim++){
          for(unsigned int i = 0; i < out[dim].size(); i++){
            Shape s;
            s.Num = out[dim][i];
            s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            List_Add((yyval.l), &s);
          }
        }
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 351:
#line 4418 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> out[4];
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        Shape s;
        for(int dim = 0; dim < 4; dim++){
          s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
            (dim == 2) ? MSH_SURF_FROM_GMODEL :
            (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
          for(unsigned int i = 0; i < out[dim].size(); i++){
            s.Num = out[dim][i];
            List_Add((yyval.l), &s);
          }
        }
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE factory");
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 352:
#line 4445 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (14)].l), i, &s); int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) shape[dim].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(11) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(11) - (14)].l), i, &s);int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) tool[dim].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), shape, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 353:
#line 4467 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 354:
#line 4471 "Gmsh.y"
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

  case 355:
#line 4486 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 356:
#line 4490 "Gmsh.y"
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

  case 357:
#line 4506 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 358:
#line 4510 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 359:
#line 4515 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 360:
#line 4519 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 361:
#line 4525 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 362:
#line 4529 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 363:
#line 4536 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 364:
#line 4552 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
      int npoints = ((int)(yyvsp[(5) - (7)].d) < 2) ? 2 : (int)(yyvsp[(5) - (7)].d);
      if(!(yyvsp[(3) - (7)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteLine
          (0, npoints, type, coef);
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
          (*it)->meshAttributes.nbPointsTransfinite = npoints;
          (*it)->meshAttributes.typeTransfinite = type;
          (*it)->meshAttributes.coeffTransfinite = coef;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (7)].l), i, &d);
          int j = (int)fabs(d);
          for(int sig = -1; sig <= 1; sig += 2){
            GModel::current()->getGEOInternals()->setTransfiniteLine
              (sig * j, npoints, type * gmsh_sign(d), coef);
            GEdge *ge = GModel::current()->getEdgeByTag(sig * j);
            if(ge){
              ge->meshAttributes.method = MESH_TRANSFINITE;
              ge->meshAttributes.nbPointsTransfinite = npoints;
              ge->meshAttributes.typeTransfinite = type * gmsh_sign(d);
              ge->meshAttributes.coeffTransfinite = coef;
            }
          }
        }
        List_Delete((yyvsp[(3) - (7)].l));
      }
    ;}
    break;

  case 365:
#line 4592 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector((yyvsp[(4) - (6)].l), corners);
      if(!(yyvsp[(3) - (6)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteSurface(0, (yyvsp[(5) - (6)].i), corners);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
          (*it)->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (6)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, (yyvsp[(5) - (6)].i), corners);
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.method = MESH_TRANSFINITE;
            gf->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
            if(corners.empty() || corners.size() == 3 || corners.size() == 4){
              for(unsigned int j = 0; j < corners.size(); j++){
                GVertex *gv = GModel::current()->getVertexByTag(std::abs(corners[j]));
                if(gv)
                  gf->meshAttributes.corners.push_back(gv);
                else
                  yymsg(0, "Unknown model vertex with tag %d", corners[j]);
              }
            }
            else{
              yymsg(0, "Transfinite surface requires 3 or 4 corners vertices");
            }
          }
        }
        List_Delete((yyvsp[(3) - (6)].l));
      }
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 366:
#line 4635 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 367:
#line 4640 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector((yyvsp[(4) - (5)].l), corners);
      if(!(yyvsp[(3) - (5)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteVolume(0, corners);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, corners);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr){
            gr->meshAttributes.method = MESH_TRANSFINITE;
            if(corners.empty() || corners.size() == 6 || corners.size() == 8){
              for(unsigned int i = 0; i < corners.size(); i++){
                GVertex *gv = GModel::current()->getVertexByTag(std::abs(corners[i]));
                if(gv)
                  gr->meshAttributes.corners.push_back(gv);
                else
                  yymsg(0, "Unknown model vertex with tag %d", corners[i]);
              }
            }
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 368:
#line 4678 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(2) - (3)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(0);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++)
          (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(2) - (3)].l)); i++){
          double d;
          List_Read((yyvsp[(2) - (3)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(tag);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    ;}
    break;

  case 369:
#line 4702 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 370:
#line 4711 "Gmsh.y"
    {
      // recombine constraints are also stored in GEO internals, as they can be
      // copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (5)].l)){
        GModel::current()->getGEOInternals()->setRecombine(2, 0, (yyvsp[(4) - (5)].i));
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.recombine = 1;
          (*it)->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(2, tag, (yyvsp[(4) - (5)].i));
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.recombine = 1;
            gf->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
    ;}
    break;

  case 371:
#line 4740 "Gmsh.y"
    {
      // recombine constraints are also stored in GEO internals, as they can be
      // copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setRecombine(3, 0, 0.);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.recombine3D = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(3, tag, 0.);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.recombine3D = 1;
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 372:
#line 4765 "Gmsh.y"
    {
      // smoothing constraints are also stored in GEO internals, as they can be
      // copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (6)].l)){
        GModel::current()->getGEOInternals()->setSmoothing(0, (int)(yyvsp[(5) - (6)].d));
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (6)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setSmoothing(tag, (int)(yyvsp[(5) - (6)].d));
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf) gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
        List_Delete((yyvsp[(3) - (6)].l));
      }
    ;}
    break;

  case 373:
#line 4791 "Gmsh.y"
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

  case 374:
#line 4823 "Gmsh.y"
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

  case 375:
#line 4850 "Gmsh.y"
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

  case 376:
#line 4876 "Gmsh.y"
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

  case 377:
#line 4902 "Gmsh.y"
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

  case 378:
#line 4928 "Gmsh.y"
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

  case 379:
#line 4954 "Gmsh.y"
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

  case 380:
#line 4975 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 381:
#line 4981 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 382:
#line 4987 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 383:
#line 4993 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 384:
#line 4999 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 385:
#line 5005 "Gmsh.y"
    {
      // reverse mesh constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setReverseMesh(2, 0);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.reverseMesh = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh(2, num);
          GFace *gf = GModel::current()->getFaceByTag(num);
          if(gf) gf->meshAttributes.reverseMesh = 1;
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 386:
#line 5030 "Gmsh.y"
    {
      // reverse mesh constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setReverseMesh(1, 0);
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++){
          (*it)->meshAttributes.reverseMesh = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh(1, num);
          GEdge *ge = GModel::current()->getEdgeByTag(num);
          if(ge) ge->meshAttributes.reverseMesh = 1;
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 387:
#line 5055 "Gmsh.y"
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
          if(gv) gv->relocateMeshVertices();
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 388:
#line 5072 "Gmsh.y"
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
          if(ge) ge->relocateMeshVertices();
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 389:
#line 5089 "Gmsh.y"
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
          if(gf) gf->relocateMeshVertices();
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 390:
#line 5106 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
	int num = (int)fabs(dnum);
        GModel::current()->getGEOInternals()->setDegenerated(1, num);
        GEdge *ge = GModel::current()->getEdgeByTag(num);
        if(ge) ge->setTooSmall(true);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 391:
#line 5118 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 392:
#line 5124 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 393:
#line 5130 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 394:
#line 5142 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 395:
#line 5146 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        GModel::current()->getGEOInternals()->removeAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 396:
#line 5156 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 397:
#line 5166 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 398:
#line 5167 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 399:
#line 5168 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 400:
#line 5173 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 401:
#line 5179 "Gmsh.y"
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

  case 402:
#line 5191 "Gmsh.y"
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

  case 403:
#line 5209 "Gmsh.y"
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

  case 404:
#line 5236 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 405:
#line 5237 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 406:
#line 5238 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 407:
#line 5239 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 408:
#line 5240 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5241 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 410:
#line 5242 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5243 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5245 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 413:
#line 5251 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 414:
#line 5252 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 415:
#line 5253 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5254 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 417:
#line 5255 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5256 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5257 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5258 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5259 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5260 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5261 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 424:
#line 5262 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 425:
#line 5263 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5264 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 427:
#line 5265 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5266 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5267 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5268 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5269 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5270 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5271 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5272 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 435:
#line 5273 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5274 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5275 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5276 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5277 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 440:
#line 5278 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5279 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 442:
#line 5280 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5281 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5282 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5283 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 446:
#line 5292 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 447:
#line 5293 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 448:
#line 5294 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 449:
#line 5295 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 450:
#line 5296 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 451:
#line 5297 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 452:
#line 5298 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 453:
#line 5299 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 454:
#line 5300 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 455:
#line 5301 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 456:
#line 5302 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 457:
#line 5307 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 458:
#line 5309 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 459:
#line 5315 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 460:
#line 5320 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 461:
#line 5325 "Gmsh.y"
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

  case 462:
#line 5342 "Gmsh.y"
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

  case 463:
#line 5360 "Gmsh.y"
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

  case 464:
#line 5378 "Gmsh.y"
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

  case 465:
#line 5396 "Gmsh.y"
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

  case 466:
#line 5414 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 467:
#line 5419 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 468:
#line 5425 "Gmsh.y"
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

  case 469:
#line 5440 "Gmsh.y"
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

  case 470:
#line 5459 "Gmsh.y"
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

  case 471:
#line 5479 "Gmsh.y"
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

  case 472:
#line 5499 "Gmsh.y"
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

  case 473:
#line 5519 "Gmsh.y"
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

  case 474:
#line 5542 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 475:
#line 5547 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 476:
#line 5552 "Gmsh.y"
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

  case 477:
#line 5562 "Gmsh.y"
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

  case 478:
#line 5572 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 479:
#line 5577 "Gmsh.y"
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

  case 480:
#line 5588 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 481:
#line 5597 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 482:
#line 5602 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 483:
#line 5607 "Gmsh.y"
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

  case 484:
#line 5634 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 485:
#line 5638 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 486:
#line 5642 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 487:
#line 5646 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 488:
#line 5650 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 489:
#line 5657 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 490:
#line 5661 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 491:
#line 5665 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 492:
#line 5669 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 493:
#line 5676 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 494:
#line 5681 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 495:
#line 5688 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 496:
#line 5693 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 497:
#line 5697 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 498:
#line 5702 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 499:
#line 5706 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 500:
#line 5714 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 501:
#line 5725 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 502:
#line 5729 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 503:
#line 5741 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 504:
#line 5749 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 505:
#line 5757 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 506:
#line 5764 "Gmsh.y"
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

  case 507:
#line 5774 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      int tag = (int)(yyvsp[(3) - (4)].d);
      double x = 0., y = 0., z = 0.;
      if(!GModel::current()->getGEOInternals()->getVertex(tag, x, y, z)){
        if(!GModel::current()->getOCCInternals()->getVertex(tag, x, y, z)){
          GVertex *gv = GModel::current()->getVertexByTag(tag);
          if(gv){
            x = gv->x();
            y = gv->y();
            z = gv->z();
          }
          else{
            yymsg(0, "Unknown model vertex with tag %d", tag);
          }
        }
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    ;}
    break;

  case 508:
#line 5796 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 509:
#line 5800 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 510:
#line 5804 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 511:
#line 5808 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 512:
#line 5812 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 513:
#line 5816 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 514:
#line 5820 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 515:
#line 5824 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 516:
#line 5828 "Gmsh.y"
    {
      // FIXME: physical groups should not be stored in GEO_Internals, but
      // directly in GModel
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

  case 517:
#line 5859 "Gmsh.y"
    {
      // FIXME: physical groups should not be stored in GEO_Internals, but
      // directly in GModel
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

  case 518:
#line 5890 "Gmsh.y"
    {
      // FIXME: physical groups should not be stored in GEO_Internals, but
      // directly in GModel
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

  case 519:
#line 5921 "Gmsh.y"
    {
      // FIXME: physical groups should not be stored in GEO_Internals, but
      // directly in GModel
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

  case 520:
#line 5953 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(10, 1, sizeof(double));
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 0);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 521:
#line 5969 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(10, 1, sizeof(double));
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 1);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 522:
#line 5985 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(10, 1, sizeof(double));
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 2);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 523:
#line 6001 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(10, 1, sizeof(double));
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 3);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 524:
#line 6016 "Gmsh.y"
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

  case 525:
#line 6026 "Gmsh.y"
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

  case 526:
#line 6036 "Gmsh.y"
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

  case 527:
#line 6046 "Gmsh.y"
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

  case 528:
#line 6058 "Gmsh.y"
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

  case 529:
#line 6071 "Gmsh.y"
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

  case 530:
#line 6083 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 531:
#line 6087 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 532:
#line 6091 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 533:
#line 6095 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 534:
#line 6099 "Gmsh.y"
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

  case 535:
#line 6117 "Gmsh.y"
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

  case 536:
#line 6135 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 537:
#line 6143 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 538:
#line 6151 "Gmsh.y"
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

  case 539:
#line 6180 "Gmsh.y"
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

  case 540:
#line 6190 "Gmsh.y"
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double d; List_Read((yyvsp[(3) - (4)].l), i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      std::vector<double>::iterator last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      for(unsigned int i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    ;}
    break;

  case 541:
#line 6209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 542:
#line 6214 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 543:
#line 6218 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 544:
#line 6222 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 545:
#line 6234 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 546:
#line 6238 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 547:
#line 6250 "Gmsh.y"
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

  case 548:
#line 6267 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 549:
#line 6277 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 550:
#line 6281 "Gmsh.y"
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

  case 551:
#line 6296 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 552:
#line 6301 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 553:
#line 6308 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 554:
#line 6312 "Gmsh.y"
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

  case 555:
#line 6325 "Gmsh.y"
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

  case 556:
#line 6339 "Gmsh.y"
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

  case 557:
#line 6353 "Gmsh.y"
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

  case 558:
#line 6367 "Gmsh.y"
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

  case 559:
#line 6381 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 560:
#line 6389 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 561:
#line 6400 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 562:
#line 6404 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 563:
#line 6408 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 564:
#line 6416 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 565:
#line 6422 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 566:
#line 6428 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 567:
#line 6436 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 568:
#line 6444 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 569:
#line 6451 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 570:
#line 6459 "Gmsh.y"
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

  case 571:
#line 6474 "Gmsh.y"
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

  case 572:
#line 6488 "Gmsh.y"
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

  case 573:
#line 6502 "Gmsh.y"
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

  case 574:
#line 6514 "Gmsh.y"
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

  case 575:
#line 6530 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 576:
#line 6539 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 577:
#line 6548 "Gmsh.y"
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

  case 578:
#line 6558 "Gmsh.y"
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

  case 579:
#line 6569 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 580:
#line 6577 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 581:
#line 6585 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 582:
#line 6589 "Gmsh.y"
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

  case 583:
#line 6608 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 584:
#line 6615 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 585:
#line 6621 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6628 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 6635 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 588:
#line 6637 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 589:
#line 6648 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 590:
#line 6653 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 591:
#line 6659 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 592:
#line 6668 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 593:
#line 6681 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 594:
#line 6684 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 595:
#line 6688 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14122 "Gmsh.tab.cpp"
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


#line 6691 "Gmsh.y"


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
  // Warning: this returns a fullMatrix copy, and deletes the input list
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

void ListOfDouble2Vector(List_T *list, std::vector<int> &v)
{
  v.clear();
  if(!list) return;
  v.reserve(List_Nbr(list));
  for(int i = 0; i < List_Nbr(list); i++){
    double d;
    List_Read(list, i, &d);
    v.push_back((int)d);
  }
}

void ListOfDouble2Vector(List_T *list, std::vector<double> &v)
{
  v.clear();
  if(!list) return;
  v.reserve(List_Nbr(list));
  for(int i = 0; i < List_Nbr(list); i++){
    double d;
    List_Read(list, i, &d);
    v.push_back(d);
  }
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
  if(GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(abs(iSource));
  if (!target || !source) {
    Msg::Error("Could not find edge slave %d or master %d for periodic copy",
               iTarget, iSource);
  }
  else target->setMeshMaster(source, affineTransform);
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::map<int,int>& edgeCounterparts)
{
  if(GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  Msg::Info("Encoding periodic connection between %d and %d", iTarget, iSource);
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(abs(iSource));
  if (!target || !source) {
    Msg::Error("Could not find surface slave %d or master %d for periodic copy",
               iTarget,iSource);
  }
  else target->setMeshMaster(source, edgeCounterparts);
}

void addPeriodicEdge(int iTarget,int iSource,
                     const std::vector<double>& affineTransform)
{
  if(GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

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

void addEmbedded(int dim, std::vector<int> tags, int dim2, int tag2)
{
  if(GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  if(dim2 == 2){
    GFace *gf = GModel::current()->getFaceByTag(tag2);
    if(!gf){
      yymsg(0, "Unknown model face with tag %d", tag2);
      return;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gf->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model vertex %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gf->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model edge %d", tags[i]);
      }
    }
  }
  else if(dim2 == 3){
    GRegion *gr = GModel::current()->getRegionByTag(tag2);
    if(!gr){
      yymsg(0, "Unknown model region with tag %d", tag2);
      return;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gr->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model vertex with tag %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gr->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model edge with tag %d", tags[i]);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(gf)
          gr->addEmbeddedFace(gf);
        else
          yymsg(0, "Unknown model face with tag %d", tags[i]);
      }
    }
  }
}

int NEWPOINT()
{
  int tag = GModel::current()->getGEOInternals()->getMaxTag(0) + 1;
  tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(0) + 1);
  return tag;
}

int NEWLINE()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(1) + 1;
  tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(1) + 1);
  return tag;
}

int NEWLINELOOP()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  return tag;
}

int NEWSURFACE()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(2) + 1;
  tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(2) + 1);
  return tag;
}

int NEWSURFACELOOP()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(-2) + 1;
  tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  return tag;
}

int NEWVOLUME()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->MaxVolumeNum + 1;
  tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(3) + 1);
  return tag;
}

int NEWREG()
{
  int tag = 0;
  tag = GModel::current()->getGEOInternals()->MaxLineNum;
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxLineLoopNum);
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxSurfaceNum);
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxSurfaceLoopNum);
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxVolumeNum);
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxPhysicalNum);
  tag += 1;
  for(int i = -2; i < 4; i++)
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(i) + 1);
  return tag;
}

int NEWFIELD()
{
#if defined(HAVE_MESH)
  return (GModel::current()->getFields()->maxId() + 1);
#else
  return 0;
#endif
}

int NEWPHYSICAL()
{
  if(CTX::instance()->geom.oldNewreg)
    return NEWREG();
  else
    return (GModel::current()->getGEOInternals()->MaxPhysicalNum + 1);
}

