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
     tQuadTriSngl = 410,
     tQuadTriDbl = 411,
     tRecombLaterals = 412,
     tTransfQuadTri = 413,
     tText2D = 414,
     tText3D = 415,
     tInterpolationScheme = 416,
     tTime = 417,
     tCombine = 418,
     tBSpline = 419,
     tBezier = 420,
     tNurbs = 421,
     tNurbsOrder = 422,
     tNurbsKnots = 423,
     tColor = 424,
     tColorTable = 425,
     tFor = 426,
     tIn = 427,
     tEndFor = 428,
     tIf = 429,
     tElseIf = 430,
     tElse = 431,
     tEndIf = 432,
     tExit = 433,
     tAbort = 434,
     tField = 435,
     tReturn = 436,
     tCall = 437,
     tSlide = 438,
     tMacro = 439,
     tShow = 440,
     tHide = 441,
     tGetValue = 442,
     tGetStringValue = 443,
     tGetEnv = 444,
     tGetString = 445,
     tGetNumber = 446,
     tUnique = 447,
     tHomology = 448,
     tCohomology = 449,
     tBetti = 450,
     tExists = 451,
     tFileExists = 452,
     tGMSH_MAJOR_VERSION = 453,
     tGMSH_MINOR_VERSION = 454,
     tGMSH_PATCH_VERSION = 455,
     tGmshExecutableName = 456,
     tSetPartition = 457,
     tNameToString = 458,
     tStringToName = 459,
     tAFFECTDIVIDE = 460,
     tAFFECTTIMES = 461,
     tAFFECTMINUS = 462,
     tAFFECTPLUS = 463,
     tOR = 464,
     tAND = 465,
     tNOTEQUAL = 466,
     tEQUAL = 467,
     tGREATEROREQUAL = 468,
     tLESSOREQUAL = 469,
     UNARYPREC = 470,
     tMINUSMINUS = 471,
     tPLUSPLUS = 472
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
#define tQuadTriSngl 410
#define tQuadTriDbl 411
#define tRecombLaterals 412
#define tTransfQuadTri 413
#define tText2D 414
#define tText3D 415
#define tInterpolationScheme 416
#define tTime 417
#define tCombine 418
#define tBSpline 419
#define tBezier 420
#define tNurbs 421
#define tNurbsOrder 422
#define tNurbsKnots 423
#define tColor 424
#define tColorTable 425
#define tFor 426
#define tIn 427
#define tEndFor 428
#define tIf 429
#define tElseIf 430
#define tElse 431
#define tEndIf 432
#define tExit 433
#define tAbort 434
#define tField 435
#define tReturn 436
#define tCall 437
#define tSlide 438
#define tMacro 439
#define tShow 440
#define tHide 441
#define tGetValue 442
#define tGetStringValue 443
#define tGetEnv 444
#define tGetString 445
#define tGetNumber 446
#define tUnique 447
#define tHomology 448
#define tCohomology 449
#define tBetti 450
#define tExists 451
#define tFileExists 452
#define tGMSH_MAJOR_VERSION 453
#define tGMSH_MINOR_VERSION 454
#define tGMSH_PATCH_VERSION 455
#define tGmshExecutableName 456
#define tSetPartition 457
#define tNameToString 458
#define tStringToName 459
#define tAFFECTDIVIDE 460
#define tAFFECTTIMES 461
#define tAFFECTMINUS 462
#define tAFFECTPLUS 463
#define tOR 464
#define tAND 465
#define tNOTEQUAL 466
#define tEQUAL 467
#define tGREATEROREQUAL 468
#define tLESSOREQUAL 469
#define UNARYPREC 470
#define tMINUSMINUS 471
#define tPLUSPLUS 472




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
#line 119 "Gmsh.y"
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
#line 666 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 679 "Gmsh.tab.cpp"

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
#define YYLAST   15024

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  599
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   472

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   223,     2,   233,     2,   222,     2,     2,
     228,   229,   220,   218,   234,   219,   232,   221,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     214,     2,   215,   209,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   230,     2,   231,   227,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   235,     2,   236,   237,     2,     2,     2,
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
     205,   206,   207,   208,   210,   211,   212,   213,   216,   217,
     224,   225,   226
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
     872,   875,   883,   891,   896,   904,   913,   922,   930,   938,
     950,   959,   967,   976,   985,   994,  1004,  1008,  1013,  1024,
    1032,  1040,  1048,  1056,  1064,  1072,  1080,  1088,  1096,  1104,
    1113,  1126,  1135,  1143,  1152,  1160,  1169,  1178,  1187,  1196,
    1205,  1214,  1220,  1232,  1238,  1248,  1258,  1263,  1273,  1283,
    1285,  1287,  1288,  1291,  1298,  1305,  1312,  1319,  1328,  1339,
    1354,  1371,  1384,  1399,  1414,  1429,  1444,  1453,  1462,  1469,
    1474,  1481,  1488,  1492,  1497,  1503,  1510,  1516,  1520,  1524,
    1529,  1535,  1540,  1546,  1550,  1556,  1564,  1572,  1576,  1584,
    1588,  1591,  1594,  1597,  1600,  1603,  1619,  1622,  1625,  1628,
    1631,  1634,  1651,  1663,  1670,  1679,  1688,  1699,  1701,  1704,
    1707,  1709,  1713,  1717,  1722,  1727,  1729,  1731,  1737,  1749,
    1763,  1764,  1772,  1773,  1787,  1788,  1804,  1805,  1812,  1822,
    1825,  1829,  1840,  1849,  1858,  1867,  1880,  1893,  1906,  1921,
    1936,  1951,  1952,  1965,  1966,  1979,  1980,  1993,  1994,  2011,
    2012,  2029,  2030,  2047,  2048,  2067,  2068,  2087,  2088,  2107,
    2109,  2112,  2118,  2126,  2136,  2139,  2142,  2146,  2149,  2153,
    2156,  2160,  2163,  2167,  2170,  2174,  2184,  2191,  2193,  2195,
    2197,  2199,  2201,  2202,  2205,  2209,  2219,  2224,  2239,  2240,
    2244,  2245,  2247,  2248,  2251,  2252,  2255,  2256,  2259,  2266,
    2274,  2281,  2290,  2296,  2300,  2309,  2315,  2320,  2327,  2339,
    2351,  2370,  2389,  2402,  2415,  2428,  2439,  2450,  2461,  2472,
    2483,  2488,  2493,  2498,  2503,  2508,  2513,  2518,  2523,  2526,
    2530,  2537,  2539,  2541,  2543,  2546,  2552,  2560,  2571,  2573,
    2577,  2580,  2583,  2586,  2590,  2594,  2598,  2602,  2606,  2610,
    2614,  2618,  2622,  2626,  2630,  2634,  2638,  2642,  2648,  2653,
    2658,  2663,  2668,  2673,  2678,  2683,  2688,  2693,  2698,  2705,
    2710,  2715,  2720,  2725,  2730,  2735,  2740,  2747,  2754,  2761,
    2766,  2768,  2770,  2772,  2774,  2776,  2778,  2780,  2782,  2784,
    2786,  2788,  2789,  2796,  2801,  2808,  2810,  2815,  2820,  2825,
    2830,  2835,  2840,  2845,  2848,  2854,  2860,  2866,  2872,  2876,
    2883,  2888,  2896,  2903,  2910,  2917,  2922,  2929,  2934,  2936,
    2939,  2942,  2946,  2950,  2962,  2972,  2980,  2988,  2990,  2994,
    2996,  2998,  3001,  3005,  3010,  3016,  3018,  3020,  3023,  3027,
    3031,  3037,  3042,  3045,  3048,  3051,  3054,  3058,  3062,  3066,
    3070,  3076,  3082,  3088,  3094,  3111,  3128,  3145,  3162,  3164,
    3166,  3168,  3172,  3176,  3181,  3186,  3191,  3198,  3205,  3212,
    3219,  3228,  3237,  3242,  3257,  3262,  3264,  3266,  3270,  3274,
    3284,  3292,  3294,  3300,  3304,  3311,  3313,  3317,  3319,  3321,
    3326,  3331,  3336,  3341,  3345,  3352,  3354,  3359,  3361,  3363,
    3365,  3370,  3377,  3382,  3389,  3394,  3399,  3404,  3413,  3418,
    3423,  3428,  3433,  3442,  3451,  3458,  3463,  3470,  3475,  3477,
    3482,  3487,  3488,  3495,  3497,  3501,  3507,  3513,  3515,  3517
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     239,     0,    -1,   240,    -1,     1,     6,    -1,    -1,   240,
     241,    -1,   243,    -1,   244,    -1,   264,    -1,   110,   228,
     337,   229,     6,    -1,   283,    -1,   284,    -1,   288,    -1,
     289,    -1,   290,    -1,   291,    -1,   295,    -1,   313,    -1,
     314,    -1,   320,    -1,   321,    -1,   294,    -1,   293,    -1,
     292,    -1,   287,    -1,   323,    -1,   215,    -1,   215,   215,
      -1,    42,   228,   337,   229,     6,    -1,    43,   228,   337,
     229,     6,    -1,    42,   228,   337,   229,   242,   337,     6,
      -1,    42,   228,   337,   234,   333,   229,     6,    -1,    43,
     228,   337,   234,   333,   229,     6,    -1,    42,   228,   337,
     234,   333,   229,   242,   337,     6,    -1,     4,   337,   235,
     245,   236,     6,    -1,   150,     4,   230,   324,   231,     6,
      -1,   151,     4,   230,   324,   231,     6,    -1,   152,     4,
     230,   324,   234,   324,   231,     6,    -1,    -1,   245,   248,
      -1,   245,   252,    -1,   245,   255,    -1,   245,   257,    -1,
     245,   258,    -1,   324,    -1,   246,   234,   324,    -1,   324,
      -1,   247,   234,   324,    -1,    -1,    -1,     4,   249,   228,
     246,   229,   250,   235,   247,   236,     6,    -1,   337,    -1,
     251,   234,   337,    -1,    -1,   159,   228,   324,   234,   324,
     234,   324,   229,   253,   235,   251,   236,     6,    -1,   337,
      -1,   254,   234,   337,    -1,    -1,   160,   228,   324,   234,
     324,   234,   324,   234,   324,   229,   256,   235,   254,   236,
       6,    -1,   161,   235,   329,   236,   235,   329,   236,     6,
      -1,   161,   235,   329,   236,   235,   329,   236,   235,   329,
     236,   235,   329,   236,     6,    -1,    -1,   162,   259,   235,
     247,   236,     6,    -1,     7,    -1,   208,    -1,   207,    -1,
     206,    -1,   205,    -1,   226,    -1,   225,    -1,   228,    -1,
     230,    -1,   229,    -1,   231,    -1,    78,   230,   266,   231,
       6,    -1,    79,   230,   271,   231,     6,    -1,    82,   262,
     338,   234,   324,   263,     6,    -1,    83,   262,   342,   234,
     338,   263,     6,    -1,   342,   260,   330,     6,    -1,   342,
     261,     6,    -1,     4,   230,   231,   260,   330,     6,    -1,
     341,   230,   231,   260,   330,     6,    -1,     4,   230,   324,
     231,   260,   324,     6,    -1,   341,   230,   324,   231,   260,
     324,     6,    -1,     4,   230,   324,   231,   261,     6,    -1,
     341,   230,   324,   231,   261,     6,    -1,     4,   262,   235,
     333,   236,   263,   260,   330,     6,    -1,   341,   262,   235,
     333,   236,   263,   260,   330,     6,    -1,     4,   228,   229,
     260,   330,     6,    -1,   341,   228,   229,   260,   330,     6,
      -1,     4,   228,   324,   229,   260,   324,     6,    -1,   341,
     228,   324,   229,   260,   324,     6,    -1,     4,   228,   324,
     229,   261,     6,    -1,   341,   228,   324,   229,   261,     6,
      -1,   342,     7,   338,     6,    -1,     4,   230,   231,     7,
      44,   262,   263,     6,    -1,   341,   230,   231,     7,    44,
     262,   263,     6,    -1,     4,   230,   231,     7,    44,   262,
     340,   263,     6,    -1,   341,   230,   231,     7,    44,   262,
     340,   263,     6,    -1,     4,   230,   231,   208,    44,   262,
     340,   263,     6,    -1,   341,   230,   231,   208,    44,   262,
     340,   263,     6,    -1,     4,   228,   229,     7,    44,   262,
     263,     6,    -1,   341,   228,   229,     7,    44,   262,   263,
       6,    -1,     4,   228,   229,     7,    44,   262,   340,   263,
       6,    -1,   341,   228,   229,     7,    44,   262,   340,   263,
       6,    -1,     4,   228,   229,   208,    44,   262,   340,   263,
       6,    -1,   341,   228,   229,   208,    44,   262,   340,   263,
       6,    -1,     4,   232,     4,     7,   338,     6,    -1,     4,
     230,   324,   231,   232,     4,     7,   338,     6,    -1,     4,
     232,     4,   260,   324,     6,    -1,     4,   230,   324,   231,
     232,     4,   260,   324,     6,    -1,     4,   232,     4,   261,
       6,    -1,     4,   230,   324,   231,   232,     4,   261,     6,
      -1,     4,   232,   169,   232,     4,     7,   334,     6,    -1,
       4,   230,   324,   231,   232,   169,   232,     4,     7,   334,
       6,    -1,     4,   232,   170,     7,   335,     6,    -1,     4,
     230,   324,   231,   232,   170,     7,   335,     6,    -1,     4,
     180,     7,   324,     6,    -1,   180,   230,   324,   231,     7,
       4,     6,    -1,   180,   230,   324,   231,   232,     4,     7,
     324,     6,    -1,   180,   230,   324,   231,   232,     4,     7,
     338,     6,    -1,   180,   230,   324,   231,   232,     4,     7,
     235,   333,   236,     6,    -1,   180,   230,   324,   231,   232,
       4,     6,    -1,   123,   228,     4,   229,   232,     4,     7,
     324,     6,    -1,   123,   228,     4,   229,   232,     4,     7,
     338,     6,    -1,    -1,   234,    -1,    -1,   266,   265,   342,
      -1,   266,   265,   342,     7,   324,    -1,    -1,   266,   265,
     342,     7,   235,   330,   267,   273,   236,    -1,    -1,   266,
     265,   342,   230,   231,     7,   235,   330,   268,   273,   236,
      -1,    -1,   266,   265,   342,   228,   229,     7,   235,   330,
     269,   273,   236,    -1,   266,   265,   342,     7,   338,    -1,
      -1,   266,   265,   342,     7,   235,   338,   270,   275,   236,
      -1,    -1,   271,   265,   337,    -1,   324,     7,   338,    -1,
     272,   234,   324,     7,   338,    -1,   332,     7,   342,   228,
     229,    -1,    -1,   273,   274,    -1,   234,     4,   330,    -1,
     234,     4,   235,   272,   236,    -1,   234,     4,   338,    -1,
      -1,   275,   276,    -1,   234,     4,   324,    -1,   234,     4,
     338,    -1,   234,   184,   338,    -1,   234,     4,   235,   340,
     236,    -1,   324,    -1,   338,    -1,   338,   234,   324,    -1,
     324,    -1,   338,    -1,   338,   234,   324,    -1,   324,    -1,
     338,    -1,   338,   234,   324,    -1,   324,    -1,   338,    -1,
     338,   234,   324,    -1,    -1,   172,    88,   235,   324,   236,
      -1,    -1,   115,   327,    -1,    84,   228,   324,   229,     7,
     327,     6,    -1,    87,   228,   324,   229,     7,   330,     6,
      -1,   124,    87,   330,     6,    -1,    91,   228,   324,   229,
       7,   330,     6,    -1,    85,   228,   324,   229,     7,   330,
     282,     6,    -1,    86,   228,   324,   229,     7,   330,   282,
       6,    -1,   164,   228,   324,   229,     7,   330,     6,    -1,
     165,   228,   324,   229,     7,   330,     6,    -1,   166,   228,
     324,   229,     7,   330,   168,   330,   167,   324,     6,    -1,
     120,    87,   228,   324,   229,     7,   330,     6,    -1,   102,
     228,   324,   229,     7,   330,     6,    -1,    87,     4,   228,
     324,   229,     7,   330,     6,    -1,   115,    90,   228,   324,
     229,     7,   330,     6,    -1,    90,   228,   324,   229,     7,
     330,   281,     6,    -1,   116,    90,   228,   324,   229,     7,
     330,   281,     6,    -1,    12,    13,     6,    -1,    13,    90,
     324,     6,    -1,   105,    90,   228,   324,   229,     7,     5,
       5,     5,     6,    -1,    88,   228,   324,   229,     7,   330,
       6,    -1,    89,   228,   324,   229,     7,   330,     6,    -1,
      93,   228,   324,   229,     7,   330,     6,    -1,    96,   228,
     324,   229,     7,   330,     6,    -1,   100,   228,   324,   229,
       7,   330,     6,    -1,   101,   228,   324,   229,     7,   330,
       6,    -1,    94,   228,   324,   229,     7,   330,     6,    -1,
      95,   228,   324,   229,     7,   330,     6,    -1,   112,   228,
     324,   229,     7,   330,     6,    -1,   138,   228,   324,   229,
       7,   330,     6,    -1,   120,    90,   228,   324,   229,     7,
     330,     6,    -1,   120,    90,   228,   324,   229,     7,   330,
       4,   235,   329,   236,     6,    -1,    90,     4,   228,   324,
     229,     7,   330,     6,    -1,    92,   228,   324,   229,     7,
     330,     6,    -1,   118,    92,   228,   324,   229,     7,   330,
       6,    -1,   111,   228,   324,   229,     7,   330,     6,    -1,
     116,   111,   228,   324,   229,     7,   330,     6,    -1,   120,
      92,   228,   324,   229,     7,   330,     6,    -1,   119,    84,
     228,   277,   229,   260,   330,     6,    -1,   119,    87,   228,
     278,   229,   260,   330,     6,    -1,   119,    90,   228,   279,
     229,   260,   330,     6,    -1,   119,    92,   228,   280,   229,
     260,   330,     6,    -1,   127,   327,   235,   285,   236,    -1,
     126,   235,   327,   234,   327,   234,   324,   236,   235,   285,
     236,    -1,   128,   327,   235,   285,   236,    -1,   129,   235,
     327,   234,   324,   236,   235,   285,   236,    -1,   129,   235,
     327,   234,   327,   236,   235,   285,   236,    -1,     4,   235,
     285,   236,    -1,   144,    87,   235,   333,   236,    90,   235,
     324,   236,    -1,   141,    87,   228,   324,   229,   235,   333,
     236,     6,    -1,   286,    -1,   284,    -1,    -1,   286,   283,
      -1,   286,    84,   235,   333,   236,     6,    -1,   286,    87,
     235,   333,   236,     6,    -1,   286,    90,   235,   333,   236,
       6,    -1,   286,    92,   235,   333,   236,     6,    -1,   131,
     115,   228,   324,   229,     7,   330,     6,    -1,   131,    84,
     228,   324,   229,     7,   235,   329,   236,     6,    -1,   131,
     115,   228,   324,   229,     7,   235,   327,   234,   327,   234,
     333,   236,     6,    -1,   131,   115,   228,   324,   229,     7,
     235,   327,   234,   327,   234,   327,   234,   333,   236,     6,
      -1,   131,    88,   228,   324,   229,     7,   235,   327,   234,
     333,   236,     6,    -1,   131,    94,   228,   324,   229,     7,
     235,   327,   234,   327,   234,   333,   236,     6,    -1,   131,
      95,   228,   324,   229,     7,   235,   327,   234,   327,   234,
     333,   236,     6,    -1,   131,    97,   228,   324,   229,     7,
     235,   327,   234,   327,   234,   333,   236,     6,    -1,   131,
      98,   228,   324,   229,     7,   235,   327,   234,   327,   234,
     333,   236,     6,    -1,   131,     4,   228,   324,   229,     7,
     330,     6,    -1,   131,     4,   228,   324,   229,     7,     5,
       6,    -1,   131,     4,   235,   324,   236,     6,    -1,   142,
     235,   286,   236,    -1,   142,   180,   230,   324,   231,     6,
      -1,   142,     4,   230,   324,   231,     6,    -1,   142,   342,
       6,    -1,   142,     4,     4,     6,    -1,   169,   334,   235,
     286,   236,    -1,   125,   169,   334,   235,   286,   236,    -1,
     202,   324,   235,   286,   236,    -1,   185,     5,     6,    -1,
     186,     5,     6,    -1,   185,   235,   286,   236,    -1,   125,
     185,   235,   286,   236,    -1,   186,   235,   286,   236,    -1,
     125,   186,   235,   286,   236,    -1,     4,   338,     6,    -1,
      71,   228,   340,   229,     6,    -1,     4,     4,   230,   324,
     231,   337,     6,    -1,     4,     4,     4,   230,   324,   231,
       6,    -1,     4,   324,     6,    -1,   123,   228,     4,   229,
     232,     4,     6,    -1,   163,     4,     6,    -1,   178,     6,
      -1,   179,     6,    -1,    68,     6,    -1,    69,     6,    -1,
      62,     6,    -1,    62,   235,   324,   234,   324,   234,   324,
     234,   324,   234,   324,   234,   324,   236,     6,    -1,    63,
       6,    -1,    64,     6,    -1,    75,     6,    -1,    76,     6,
      -1,   107,     6,    -1,   108,   235,   333,   236,   235,   333,
     236,   235,   329,   236,   235,   324,   234,   324,   236,     6,
      -1,   183,   228,   235,   333,   236,   234,   338,   234,   338,
     229,     6,    -1,   171,   228,   324,     8,   324,   229,    -1,
     171,   228,   324,     8,   324,     8,   324,   229,    -1,   171,
       4,   172,   235,   324,     8,   324,   236,    -1,   171,     4,
     172,   235,   324,     8,   324,     8,   324,   236,    -1,   173,
      -1,   184,     4,    -1,   184,   338,    -1,   181,    -1,   182,
     342,     6,    -1,   182,   338,     6,    -1,   174,   228,   324,
     229,    -1,   175,   228,   324,   229,    -1,   176,    -1,   177,
      -1,   130,   327,   235,   286,   236,    -1,   130,   235,   327,
     234,   327,   234,   324,   236,   235,   286,   236,    -1,   130,
     235,   327,   234,   327,   234,   327,   234,   324,   236,   235,
     286,   236,    -1,    -1,   130,   327,   235,   286,   296,   309,
     236,    -1,    -1,   130,   235,   327,   234,   327,   234,   324,
     236,   235,   286,   297,   309,   236,    -1,    -1,   130,   235,
     327,   234,   327,   234,   327,   234,   324,   236,   235,   286,
     298,   309,   236,    -1,    -1,   130,   235,   286,   299,   309,
     236,    -1,   130,   235,   286,   236,   122,   102,   235,   324,
     236,    -1,   111,   330,    -1,   116,   111,   330,    -1,   113,
     235,   333,   236,   235,   333,   236,   235,   324,   236,    -1,
     130,    84,   235,   324,   234,   327,   236,     6,    -1,   130,
      87,   235,   324,   234,   327,   236,     6,    -1,   130,    90,
     235,   324,   234,   327,   236,     6,    -1,   130,    84,   235,
     324,   234,   327,   234,   327,   234,   324,   236,     6,    -1,
     130,    87,   235,   324,   234,   327,   234,   327,   234,   324,
     236,     6,    -1,   130,    90,   235,   324,   234,   327,   234,
     327,   234,   324,   236,     6,    -1,   130,    84,   235,   324,
     234,   327,   234,   327,   234,   327,   234,   324,   236,     6,
      -1,   130,    87,   235,   324,   234,   327,   234,   327,   234,
     327,   234,   324,   236,     6,    -1,   130,    90,   235,   324,
     234,   327,   234,   327,   234,   327,   234,   324,   236,     6,
      -1,    -1,   130,    84,   235,   324,   234,   327,   236,   300,
     235,   309,   236,     6,    -1,    -1,   130,    87,   235,   324,
     234,   327,   236,   301,   235,   309,   236,     6,    -1,    -1,
     130,    90,   235,   324,   234,   327,   236,   302,   235,   309,
     236,     6,    -1,    -1,   130,    84,   235,   324,   234,   327,
     234,   327,   234,   324,   236,   303,   235,   309,   236,     6,
      -1,    -1,   130,    87,   235,   324,   234,   327,   234,   327,
     234,   324,   236,   304,   235,   309,   236,     6,    -1,    -1,
     130,    90,   235,   324,   234,   327,   234,   327,   234,   324,
     236,   305,   235,   309,   236,     6,    -1,    -1,   130,    84,
     235,   324,   234,   327,   234,   327,   234,   327,   234,   324,
     236,   306,   235,   309,   236,     6,    -1,    -1,   130,    87,
     235,   324,   234,   327,   234,   327,   234,   327,   234,   324,
     236,   307,   235,   309,   236,     6,    -1,    -1,   130,    90,
     235,   324,   234,   327,   234,   327,   234,   327,   234,   324,
     236,   308,   235,   309,   236,     6,    -1,   310,    -1,   309,
     310,    -1,   147,   235,   324,   236,     6,    -1,   147,   235,
     330,   234,   330,   236,     6,    -1,   147,   235,   330,   234,
     330,   234,   330,   236,     6,    -1,   148,     6,    -1,   139,
       6,    -1,   139,   324,     6,    -1,   155,     6,    -1,   155,
     157,     6,    -1,   156,     6,    -1,   156,   157,     6,    -1,
     153,     6,    -1,   153,   157,     6,    -1,   154,     6,    -1,
     154,   157,     6,    -1,   149,   228,   324,   229,     7,   330,
     122,   324,     6,    -1,   122,     4,   230,   324,   231,     6,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,    -1,   142,     6,    -1,   142,   324,     6,    -1,   311,
     235,   286,   312,   236,   235,   286,   312,   236,    -1,    99,
     228,   337,   229,    -1,   311,   228,   324,   229,     7,   235,
     286,   312,   236,   235,   286,   312,   236,     6,    -1,    -1,
     122,     4,   324,    -1,    -1,     4,    -1,    -1,     7,   330,
      -1,    -1,     7,   324,    -1,    -1,   132,   330,    -1,   103,
     104,   330,     7,   324,     6,    -1,   117,    87,   331,     7,
     324,   315,     6,    -1,   117,    90,   331,   317,   316,     6,
      -1,   106,    90,   235,   324,   236,     7,   330,     6,    -1,
     117,    92,   331,   317,     6,    -1,   158,   331,     6,    -1,
     145,    90,   235,   333,   236,     7,   324,     6,    -1,   139,
      90,   331,   318,     6,    -1,   139,    92,   331,     6,    -1,
     140,    90,   330,     7,   324,     6,    -1,   121,    87,   235,
     333,   236,     7,   235,   333,   236,   319,     6,    -1,   121,
      90,   235,   333,   236,     7,   235,   333,   236,   319,     6,
      -1,   121,    87,   235,   333,   236,     7,   235,   333,   236,
     126,   235,   327,   234,   327,   234,   324,   236,     6,    -1,
     121,    90,   235,   333,   236,     7,   235,   333,   236,   126,
     235,   327,   234,   327,   234,   324,   236,     6,    -1,   121,
      87,   235,   333,   236,     7,   235,   333,   236,   127,   327,
       6,    -1,   121,    90,   235,   333,   236,     7,   235,   333,
     236,   127,   327,     6,    -1,   121,    90,   324,   235,   333,
     236,     7,   324,   235,   333,   236,     6,    -1,    84,   235,
     333,   236,   172,    90,   235,   324,   236,     6,    -1,    87,
     235,   333,   236,   172,    90,   235,   324,   236,     6,    -1,
      84,   235,   333,   236,   172,    92,   235,   324,   236,     6,
      -1,    87,   235,   333,   236,   172,    92,   235,   324,   236,
       6,    -1,    90,   235,   333,   236,   172,    92,   235,   324,
     236,     6,    -1,   146,    90,   331,     6,    -1,   146,    87,
     331,     6,    -1,   109,    84,   331,     6,    -1,   109,    87,
     331,     6,    -1,   109,    90,   331,     6,    -1,   120,    87,
     330,     6,    -1,   120,    90,   330,     6,    -1,   120,    92,
     330,     6,    -1,   143,     6,    -1,   143,     4,     6,    -1,
     143,    84,   235,   333,   236,     6,    -1,   193,    -1,   194,
      -1,   195,    -1,   322,     6,    -1,   322,   235,   330,   236,
       6,    -1,   322,   235,   330,   234,   330,   236,     6,    -1,
     322,   228,   330,   229,   235,   330,   234,   330,   236,     6,
      -1,   325,    -1,   228,   324,   229,    -1,   219,   324,    -1,
     218,   324,    -1,   223,   324,    -1,   324,   219,   324,    -1,
     324,   218,   324,    -1,   324,   220,   324,    -1,   324,   221,
     324,    -1,   324,   222,   324,    -1,   324,   227,   324,    -1,
     324,   214,   324,    -1,   324,   215,   324,    -1,   324,   217,
     324,    -1,   324,   216,   324,    -1,   324,   213,   324,    -1,
     324,   212,   324,    -1,   324,   211,   324,    -1,   324,   210,
     324,    -1,   324,   209,   324,     8,   324,    -1,    15,   262,
     324,   263,    -1,    16,   262,   324,   263,    -1,    17,   262,
     324,   263,    -1,    18,   262,   324,   263,    -1,    19,   262,
     324,   263,    -1,    20,   262,   324,   263,    -1,    21,   262,
     324,   263,    -1,    22,   262,   324,   263,    -1,    23,   262,
     324,   263,    -1,    25,   262,   324,   263,    -1,    26,   262,
     324,   234,   324,   263,    -1,    27,   262,   324,   263,    -1,
      28,   262,   324,   263,    -1,    29,   262,   324,   263,    -1,
      30,   262,   324,   263,    -1,    31,   262,   324,   263,    -1,
      32,   262,   324,   263,    -1,    33,   262,   324,   263,    -1,
      34,   262,   324,   234,   324,   263,    -1,    35,   262,   324,
     234,   324,   263,    -1,    36,   262,   324,   234,   324,   263,
      -1,    24,   262,   324,   263,    -1,     3,    -1,     9,    -1,
      14,    -1,    10,    -1,    11,    -1,   198,    -1,   199,    -1,
     200,    -1,    72,    -1,    73,    -1,    74,    -1,    -1,    80,
     262,   324,   326,   273,   263,    -1,   191,   262,   337,   263,
      -1,   191,   262,   337,   234,   324,   263,    -1,   342,    -1,
       4,   230,   324,   231,    -1,     4,   228,   324,   229,    -1,
     341,   230,   324,   231,    -1,   341,   228,   324,   229,    -1,
     196,   228,   342,   229,    -1,   197,   228,   338,   229,    -1,
     233,   342,   262,   263,    -1,   342,   261,    -1,     4,   230,
     324,   231,   261,    -1,     4,   228,   324,   229,   261,    -1,
     341,   230,   324,   231,   261,    -1,   341,   228,   324,   229,
     261,    -1,     4,   232,     4,    -1,     4,   230,   324,   231,
     232,     4,    -1,     4,   232,     4,   261,    -1,     4,   230,
     324,   231,   232,     4,   261,    -1,   187,   228,   337,   234,
     324,   229,    -1,    54,   228,   330,   234,   330,   229,    -1,
      55,   262,   337,   234,   337,   263,    -1,    53,   262,   337,
     263,    -1,    56,   262,   337,   234,   337,   263,    -1,    61,
     228,   340,   229,    -1,   328,    -1,   219,   327,    -1,   218,
     327,    -1,   327,   219,   327,    -1,   327,   218,   327,    -1,
     235,   324,   234,   324,   234,   324,   234,   324,   234,   324,
     236,    -1,   235,   324,   234,   324,   234,   324,   234,   324,
     236,    -1,   235,   324,   234,   324,   234,   324,   236,    -1,
     228,   324,   234,   324,   234,   324,   229,    -1,   330,    -1,
     329,   234,   330,    -1,   324,    -1,   332,    -1,   235,   236,
      -1,   235,   333,   236,    -1,   219,   235,   333,   236,    -1,
     324,   220,   235,   333,   236,    -1,   330,    -1,     5,    -1,
     219,   332,    -1,   324,   220,   332,    -1,   324,     8,   324,
      -1,   324,     8,   324,     8,   324,    -1,    84,   235,   324,
     236,    -1,    84,     5,    -1,    87,     5,    -1,    90,     5,
      -1,    92,     5,    -1,   119,    84,     5,    -1,   119,    87,
       5,    -1,   119,    90,     5,    -1,   119,    92,     5,    -1,
     119,    84,   235,   333,   236,    -1,   119,    87,   235,   333,
     236,    -1,   119,    90,   235,   333,   236,    -1,   119,    92,
     235,   333,   236,    -1,    84,   172,    62,   235,   324,   234,
     324,   234,   324,   234,   324,   234,   324,   234,   324,   236,
      -1,    87,   172,    62,   235,   324,   234,   324,   234,   324,
     234,   324,   234,   324,   234,   324,   236,    -1,    90,   172,
      62,   235,   324,   234,   324,   234,   324,   234,   324,   234,
     324,   234,   324,   236,    -1,    92,   172,    62,   235,   324,
     234,   324,   234,   324,   234,   324,   234,   324,   234,   324,
     236,    -1,   284,    -1,   295,    -1,   313,    -1,     4,   262,
     263,    -1,   341,   262,   263,    -1,    37,   230,   342,   231,
      -1,    37,   230,   332,   231,    -1,    37,   228,   332,   229,
      -1,    37,   230,   235,   333,   236,   231,    -1,    37,   228,
     235,   333,   236,   229,    -1,     4,   262,   235,   333,   236,
     263,    -1,   341,   262,   235,   333,   236,   263,    -1,    38,
     262,   324,   234,   324,   234,   324,   263,    -1,    39,   262,
     324,   234,   324,   234,   324,   263,    -1,    40,   262,   337,
     263,    -1,    41,   262,   324,   234,   324,   234,   324,   234,
     324,   234,   324,   234,   324,   263,    -1,   192,   262,   332,
     263,    -1,   324,    -1,   332,    -1,   333,   234,   324,    -1,
     333,   234,   332,    -1,   235,   324,   234,   324,   234,   324,
     234,   324,   236,    -1,   235,   324,   234,   324,   234,   324,
     236,    -1,   342,    -1,     4,   232,   169,   232,     4,    -1,
     235,   336,   236,    -1,     4,   230,   324,   231,   232,   170,
      -1,   334,    -1,   336,   234,   334,    -1,   338,    -1,   342,
      -1,     4,   230,   324,   231,    -1,   341,   230,   324,   231,
      -1,     4,   228,   324,   229,    -1,   341,   228,   324,   229,
      -1,     4,   232,     4,    -1,     4,   230,   324,   231,   232,
       4,    -1,     5,    -1,   203,   230,   342,   231,    -1,    65,
      -1,   201,    -1,    70,    -1,   189,   228,   337,   229,    -1,
     188,   228,   337,   234,   337,   229,    -1,   190,   262,   337,
     263,    -1,   190,   262,   337,   234,   337,   263,    -1,    46,
     262,   340,   263,    -1,    47,   228,   337,   229,    -1,    48,
     228,   337,   229,    -1,    49,   228,   337,   234,   337,   234,
     337,   229,    -1,    44,   262,   340,   263,    -1,    58,   262,
     337,   263,    -1,    59,   262,   337,   263,    -1,    60,   262,
     337,   263,    -1,    57,   262,   324,   234,   337,   234,   337,
     263,    -1,    52,   262,   337,   234,   324,   234,   324,   263,
      -1,    52,   262,   337,   234,   324,   263,    -1,    45,   262,
     337,   263,    -1,    45,   262,   337,   234,   333,   263,    -1,
      66,   262,   337,   263,    -1,    67,    -1,    51,   262,   337,
     263,    -1,    50,   262,   337,   263,    -1,    -1,    81,   262,
     338,   339,   275,   263,    -1,   337,    -1,   340,   234,   337,
      -1,     4,   237,   235,   324,   236,    -1,   341,   237,   235,
     324,   236,    -1,     4,    -1,   341,    -1,   204,   230,   337,
     231,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   212,   212,   213,   218,   220,   224,   225,   226,   227,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   253,   257,   264,   269,
     274,   288,   301,   314,   342,   356,   369,   382,   401,   406,
     407,   408,   409,   410,   414,   416,   421,   423,   429,   533,
     428,   551,   558,   569,   568,   586,   593,   604,   603,   620,
     637,   660,   659,   673,   674,   675,   676,   677,   681,   682,
     688,   688,   689,   689,   695,   696,   697,   702,   708,   770,
     787,   816,   845,   850,   855,   860,   865,   872,   882,   911,
     940,   945,   950,   955,   963,   972,   978,   984,   997,  1010,
    1025,  1042,  1048,  1054,  1067,  1080,  1095,  1112,  1118,  1127,
    1145,  1163,  1172,  1184,  1189,  1197,  1217,  1240,  1251,  1259,
    1281,  1304,  1342,  1363,  1375,  1389,  1389,  1391,  1393,  1402,
    1412,  1411,  1432,  1431,  1450,  1449,  1467,  1477,  1476,  1490,
    1492,  1500,  1506,  1511,  1537,  1538,  1542,  1553,  1568,  1578,
    1579,  1584,  1592,  1601,  1609,  1627,  1631,  1637,  1645,  1649,
    1655,  1663,  1667,  1673,  1681,  1685,  1691,  1700,  1703,  1710,
    1713,  1720,  1741,  1755,  1776,  1790,  1824,  1861,  1875,  1889,
    1909,  1918,  1932,  1947,  1961,  1980,  1990,  1996,  2002,  2009,
    2036,  2051,  2071,  2092,  2113,  2134,  2156,  2178,  2199,  2222,
    2231,  2252,  2267,  2281,  2296,  2311,  2326,  2335,  2378,  2421,
    2464,  2512,  2529,  2547,  2557,  2567,  2577,  2640,  2651,  2667,
    2668,  2673,  2676,  2680,  2709,  2738,  2767,  2801,  2823,  2849,
    2871,  2894,  2915,  2971,  2995,  3020,  3046,  3159,  3178,  3221,
    3242,  3248,  3263,  3291,  3308,  3317,  3331,  3345,  3351,  3357,
    3366,  3375,  3384,  3398,  3460,  3478,  3495,  3510,  3539,  3551,
    3575,  3579,  3584,  3592,  3597,  3603,  3608,  3614,  3622,  3626,
    3630,  3635,  3695,  3711,  3728,  3745,  3767,  3789,  3824,  3832,
    3840,  3846,  3853,  3860,  3880,  3906,  3918,  3930,  3960,  3991,
    4000,  3999,  4014,  4013,  4028,  4027,  4042,  4041,  4054,  4081,
    4100,  4119,  4145,  4152,  4159,  4166,  4173,  4180,  4187,  4194,
    4201,  4209,  4208,  4222,  4221,  4235,  4234,  4248,  4247,  4261,
    4260,  4274,  4273,  4287,  4286,  4300,  4299,  4313,  4312,  4329,
    4332,  4338,  4350,  4370,  4394,  4398,  4402,  4406,  4410,  4414,
    4420,  4426,  4430,  4434,  4438,  4442,  4461,  4474,  4475,  4476,
    4477,  4478,  4482,  4483,  4484,  4487,  4521,  4547,  4571,  4574,
    4590,  4593,  4610,  4613,  4619,  4622,  4629,  4632,  4639,  4656,
    4712,  4782,  4787,  4854,  4890,  4898,  4941,  4980,  5000,  5032,
    5059,  5085,  5111,  5137,  5163,  5185,  5213,  5241,  5269,  5297,
    5325,  5364,  5403,  5424,  5445,  5466,  5472,  5478,  5490,  5494,
    5504,  5539,  5540,  5541,  5545,  5551,  5563,  5581,  5609,  5610,
    5611,  5612,  5613,  5614,  5615,  5616,  5617,  5624,  5625,  5626,
    5627,  5628,  5629,  5630,  5631,  5632,  5633,  5634,  5635,  5636,
    5637,  5638,  5639,  5640,  5641,  5642,  5643,  5644,  5645,  5646,
    5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,  5655,  5656,
    5665,  5666,  5667,  5668,  5669,  5670,  5671,  5672,  5673,  5674,
    5675,  5680,  5679,  5687,  5692,  5697,  5714,  5732,  5750,  5768,
    5786,  5791,  5797,  5812,  5831,  5851,  5871,  5891,  5914,  5919,
    5924,  5934,  5944,  5949,  5960,  5969,  5974,  5979,  6006,  6010,
    6014,  6018,  6022,  6029,  6033,  6037,  6041,  6048,  6053,  6060,
    6065,  6069,  6074,  6078,  6086,  6097,  6101,  6113,  6121,  6129,
    6136,  6146,  6175,  6179,  6183,  6187,  6191,  6195,  6199,  6203,
    6207,  6236,  6265,  6294,  6323,  6336,  6349,  6362,  6375,  6385,
    6395,  6405,  6417,  6430,  6442,  6446,  6450,  6454,  6458,  6476,
    6494,  6502,  6510,  6539,  6549,  6568,  6573,  6577,  6581,  6593,
    6597,  6609,  6626,  6636,  6640,  6655,  6660,  6667,  6671,  6684,
    6698,  6712,  6726,  6740,  6748,  6759,  6763,  6767,  6775,  6781,
    6787,  6795,  6803,  6810,  6818,  6833,  6847,  6861,  6873,  6889,
    6898,  6907,  6917,  6928,  6936,  6944,  6948,  6967,  6974,  6980,
    6987,  6995,  6994,  7007,  7012,  7018,  7027,  7040,  7043,  7047
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
  "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tElseIf", "tElse", "tEndIf", "tExit", "tAbort", "tField", "tReturn",
  "tCall", "tSlide", "tMacro", "tShow", "tHide", "tGetValue",
  "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber", "tUnique",
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,    63,
     464,   465,   466,   467,    60,    62,   468,   469,    43,    45,
      42,    47,    37,    33,   470,   471,   472,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   238,   239,   239,   240,   240,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   242,   242,   243,   243,
     243,   243,   243,   243,   244,   244,   244,   244,   245,   245,
     245,   245,   245,   245,   246,   246,   247,   247,   249,   250,
     248,   251,   251,   253,   252,   254,   254,   256,   255,   257,
     257,   259,   258,   260,   260,   260,   260,   260,   261,   261,
     262,   262,   263,   263,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   265,   265,   266,   266,   266,
     267,   266,   268,   266,   269,   266,   266,   270,   266,   271,
     271,   272,   272,   272,   273,   273,   274,   274,   274,   275,
     275,   276,   276,   276,   276,   277,   277,   277,   278,   278,
     278,   279,   279,   279,   280,   280,   280,   281,   281,   282,
     282,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   284,   284,   284,   284,   284,   284,   285,
     285,   286,   286,   286,   286,   286,   286,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   288,
     288,   288,   288,   288,   289,   289,   290,   291,   291,   291,
     291,   291,   291,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   293,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   295,   295,   295,
     296,   295,   297,   295,   298,   295,   299,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   300,   295,   301,   295,   302,   295,   303,   295,   304,
     295,   305,   295,   306,   295,   307,   295,   308,   295,   309,
     309,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   311,   311,   311,
     311,   311,   312,   312,   312,   313,   313,   314,   315,   315,
     316,   316,   317,   317,   318,   318,   319,   319,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   321,
     321,   322,   322,   322,   323,   323,   323,   323,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   326,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   327,   327,
     327,   327,   327,   328,   328,   328,   328,   329,   329,   330,
     330,   330,   330,   330,   330,   331,   331,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   333,   333,   333,   333,   334,
     334,   334,   334,   335,   335,   336,   336,   337,   337,   337,
     337,   337,   337,   337,   337,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   339,   338,   340,   340,   341,   341,   342,   342,   342
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
       2,     7,     7,     4,     7,     8,     8,     7,     7,    11,
       8,     7,     8,     8,     8,     9,     3,     4,    10,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     8,
      12,     8,     7,     8,     7,     8,     8,     8,     8,     8,
       8,     5,    11,     5,     9,     9,     4,     9,     9,     1,
       1,     0,     2,     6,     6,     6,     6,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       6,     6,     3,     4,     5,     6,     5,     3,     3,     4,
       5,     4,     5,     3,     5,     7,     7,     3,     7,     3,
       2,     2,     2,     2,     2,    15,     2,     2,     2,     2,
       2,    16,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     2,
       3,    10,     8,     8,     8,    12,    12,    12,    14,    14,
      14,     0,    12,     0,    12,     0,    12,     0,    16,     0,
      16,     0,    16,     0,    18,     0,    18,     0,    18,     1,
       2,     5,     7,     9,     2,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     9,     6,     1,     1,     1,
       1,     1,     0,     2,     3,     9,     4,    14,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     6,     7,
       6,     8,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,    10,    10,    10,    10,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     3,
       6,     1,     1,     1,     2,     5,     7,    10,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     4,     6,     1,     4,     4,     4,     4,
       4,     4,     4,     2,     5,     5,     5,     5,     3,     6,
       4,     7,     6,     6,     6,     4,     6,     4,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     3,     3,     3,     3,
       5,     5,     5,     5,    16,    16,    16,    16,     1,     1,
       1,     3,     3,     4,     4,     4,     6,     6,     6,     6,
       8,     8,     4,    14,     4,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     4,
       4,     4,     4,     3,     6,     1,     4,     1,     1,     1,
       4,     6,     4,     6,     4,     4,     4,     8,     4,     4,
       4,     4,     8,     8,     6,     4,     6,     4,     1,     4,
       4,     0,     6,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   347,   348,   349,   350,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,   285,   286,     0,     0,     0,   280,     0,
       0,     0,     0,     0,   401,   402,   403,     0,     0,     5,
       6,     7,     8,    10,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,   598,     0,   450,   597,   565,   451,   453,   454,   452,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     567,     0,   588,   569,   458,   459,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,   456,   457,
     568,     0,     0,     0,     0,    70,    71,     0,     0,   221,
       0,     0,     0,   408,     0,   557,   598,   465,     0,     0,
       0,     0,   264,     0,   266,   267,   262,   263,     0,   268,
     269,   127,   139,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,   529,     0,   530,   499,
     299,   500,   598,   465,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   597,     0,   221,   598,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,   505,     0,     0,     0,     0,     0,   597,     0,     0,
     551,     0,     0,     0,     0,   260,   261,     0,   597,     0,
       0,     0,   278,   279,     0,   221,     0,   221,   597,     0,
     598,     0,     0,   221,   404,     0,     0,    70,    71,     0,
       0,    63,    67,    66,    65,    64,    69,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   411,   410,   412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
     219,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
     253,     0,     0,   473,   186,     0,   597,     0,   557,   598,
     558,     0,     0,   593,     0,   125,   125,     0,     0,     0,
       0,   545,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,   512,     0,     0,   513,     0,   514,     0,   515,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   507,
       0,   501,     0,     0,     0,    70,    71,     0,     0,     0,
       0,     0,     0,   300,     0,   362,   362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,   221,     0,   490,   489,     0,
       0,     0,     0,   221,   221,     0,     0,     0,     0,     0,
       0,     0,   296,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,     0,     0,     0,     0,
       0,     0,     0,   242,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   373,   259,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,   282,   281,     0,
     247,     0,   248,     0,     0,     0,   221,     0,     0,     0,
       0,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,   478,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   461,   591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,   409,    63,    64,     0,     0,    63,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
       0,   222,     0,     0,     0,   426,   425,   424,   423,   419,
     420,   422,   421,   414,   413,   415,   416,   417,   418,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,     0,     0,     0,     0,     0,     0,     0,
     392,   393,   394,     0,     0,     0,   478,    72,    73,     0,
     531,     0,     0,     0,     0,     0,   465,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   516,     0,   517,     0,
     518,     0,   519,     0,     0,     0,   409,   502,   509,     0,
     415,   508,     0,     0,     0,   532,     0,     0,     0,     0,
       0,     0,     0,   360,     0,     0,     0,   155,   156,     0,
     158,   159,     0,   161,   162,     0,   164,   165,     0,   395,
       0,   396,     0,   397,     0,     0,     0,     0,   173,   221,
       0,     0,     0,     0,     0,   492,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,     0,     0,   243,     0,     0,   239,     0,     0,     0,
     391,   390,     0,     0,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,   283,   284,     0,     0,   249,   251,
       0,   599,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,    63,    64,     0,     0,     0,     0,    94,    78,
       0,   467,   466,   480,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   449,   437,     0,   439,   440,   441,   442,
     443,   444,   445,     0,     0,     0,   578,     0,   585,   574,
     575,   576,     0,   590,   589,     0,   485,     0,     0,     0,
       0,   579,   580,   581,   487,   587,   144,   149,   117,     0,
       0,   570,     0,   572,     0,   463,   470,   471,   566,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   595,     0,
       0,    48,     0,     0,     0,    61,     0,    39,    40,    41,
      42,    43,   469,   468,     0,     0,   563,    28,    26,     0,
       0,     0,     0,    29,     0,     0,   254,   594,    74,   128,
      75,   140,     0,     0,     0,   547,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,   467,   466,     0,     0,   535,     0,   534,   533,
       0,     0,   542,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,   544,   503,     0,     0,     0,   469,   468,
       0,     0,     0,     0,     0,   409,   358,   363,   361,     0,
     372,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     409,   409,   409,     0,     0,     0,     0,     0,   250,   252,
       0,     0,     0,   211,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,     0,   287,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,   375,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,   246,     0,
     353,     0,     0,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   596,     0,     0,   475,
       0,   474,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,    92,     0,     0,    80,     0,     0,
       0,     0,    84,   107,   109,     0,     0,   555,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     427,     0,     0,     0,     0,     0,    34,   477,   476,   561,
     559,    27,     0,     0,   562,   560,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   169,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   520,   521,   522,   523,     0,   510,   504,     0,     0,
       0,     0,     0,     0,     0,     0,   370,     0,     0,   157,
       0,   160,     0,   163,     0,   166,     0,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   335,     0,     0,   334,     0,   341,
       0,   343,     0,   337,     0,   339,     0,   297,   330,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,   377,     0,   241,   240,   400,     0,     0,    35,    36,
       0,     0,     0,     0,   552,     0,     0,     0,   273,     0,
       0,     0,   221,   354,   221,     0,     0,     0,     0,    89,
       0,    93,     0,     0,    81,     0,    85,     0,   256,   479,
     255,   438,   446,   447,   448,   586,     0,     0,   584,   483,
     484,   486,     0,     0,   462,   145,     0,   592,   150,   482,
     571,   573,   464,     0,     0,     0,    90,     0,     0,     0,
      63,     0,     0,     0,     0,    82,     0,     0,     0,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,     0,    30,    31,     0,
      32,     0,     0,   129,   136,     0,     0,    76,    77,   171,
       0,     0,     0,     0,     0,     0,   172,     0,     0,   189,
     190,     0,     0,     0,     0,   174,   202,   191,   195,   196,
     192,   193,   194,   181,     0,     0,     0,   479,   538,   537,
     536,     0,     0,     0,     0,     0,     0,     0,   204,   539,
     197,     0,     0,   167,     0,     0,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
       0,     0,     0,   221,   221,     0,   311,     0,   313,     0,
     315,     0,     0,   336,   499,     0,     0,   342,   344,   338,
     340,     0,     0,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,   177,
     178,     0,     0,     0,     0,   118,   122,     0,     0,   352,
     352,     0,   406,     0,     0,     0,    91,     0,     0,     0,
      83,     0,   481,     0,     0,     0,     0,     0,     0,   101,
       0,     0,    95,     0,     0,     0,     0,   112,     0,     0,
     113,     0,   556,   223,   224,   225,   226,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,    46,
     564,     0,     0,   130,   137,     0,     0,     0,     0,   170,
     175,   176,   182,     0,     0,   201,     0,   184,     0,     0,
     371,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,     0,   205,   359,   203,   207,   208,   209,   210,   180,
       0,   199,   206,     0,     0,     0,     0,     0,     0,   496,
       0,   495,     0,     0,     0,   302,     0,     0,   303,     0,
       0,   304,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   236,     0,     0,     0,     0,     0,     0,     0,     0,
     227,     0,     0,   374,    37,     0,     0,   550,     0,   275,
     274,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,    96,     0,     0,     0,   577,   583,   582,     0,   146,
     148,     0,   151,   152,   153,   103,   105,    97,    99,   108,
     110,     0,   116,     0,    86,    49,     0,     0,     0,   498,
       0,     0,     0,    33,     0,   144,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   540,   541,     0,
       0,     0,     0,     0,     0,   185,     0,   366,   366,     0,
     123,   124,   221,     0,   214,   215,     0,     0,     0,     0,
       0,     0,   298,     0,   331,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,   218,   217,     0,     0,
       0,     0,   119,   120,     0,     0,   355,     0,   104,   106,
      98,   100,    87,     0,   545,   546,     0,     0,   554,     0,
      45,     0,     0,     0,    47,    62,     0,     0,     0,   134,
     132,   385,   387,   386,   388,     0,   389,   188,     0,     0,
       0,     0,     0,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   346,     0,     0,     0,
     292,     0,   228,     0,     0,     0,     0,     0,     0,     0,
     549,   276,     0,     0,   221,   407,     0,   147,     0,     0,
     154,   114,     0,     0,     0,     0,     0,   131,   138,   144,
     144,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   378,     0,     0,   379,     0,   212,     0,   317,
       0,     0,   319,     0,     0,   321,     0,     0,     0,   332,
       0,   288,     0,   221,     0,     0,     0,     0,     0,     0,
     179,   121,   272,   352,     0,   141,     0,     0,    53,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,   382,     0,   383,   384,   493,   305,     0,
       0,   312,   306,     0,     0,   314,   307,     0,     0,   316,
       0,     0,     0,   294,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     323,     0,   325,     0,   327,   333,   345,   293,   289,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,    50,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,   309,     0,     0,   310,
       0,     0,   232,   233,   234,   235,     0,   229,   357,     0,
      51,     0,     0,   265,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,   271,     0,     0,     0,     0,     0,
       0,   318,     0,   320,     0,   322,     0,   230,    52,    54,
       0,    55,     0,   524,   525,   526,   527,     0,     0,     0,
       0,     0,     0,     0,    60,   380,   381,   324,   326,   328,
      56,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   109,  1119,   110,   111,   799,  1742,  1748,
    1107,  1351,  1959,  2199,  1108,  2135,  2240,  1109,  2201,  1110,
    1111,  1355,   408,   503,   211,   860,   112,   817,   515,  1885,
    2040,  2039,  1886,   516,  1953,  1314,  1535,  1315,  1538,   906,
     909,   912,   915,  1603,  1593,   781,   285,   479,   480,   115,
     116,   117,   118,   119,   120,   121,   122,   286,  1244,  2072,
    2159,   945,  1806,  1809,  1812,  2109,  2113,  2117,  2184,  2187,
    2190,  1240,  1241,   287,   994,   288,   126,  1425,  1199,   903,
     959,  1989,   127,   128,   129,   130,   289,   213,  1056,   618,
     323,  1573,   361,   362,   291,   582,   369,  1087,  1338,   513,
     508,  1057,   514,   390,   293
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1827
static const yytype_int16 yypact[] =
{
   11338,    52,    86, 11487, -1827, -1827,  4967,    56,   -62,  -196,
    -121,    49,   188,   209,   240,   294,  -115,   397,   440,   -77,
     -14,   190,   190,   132,   244,   257,    14,   282,   295,    15,
     311,   317,   318,   330,   352,   367,   370,   385,   392,   445,
     128,    72,   476,   563,   456,   432,   471,  6652,   475,   492,
     638,   -57,   559,   658,   -11,   817,    96,   542,   691,   -29,
     546,   290,   290,   594,   296,    70, -1827, -1827, -1827, -1827,
   -1827,   585,   547,   733,   743,    19,    61,   753,   765,   204,
     856,   862,   883,  6198,   897,   697,   701,   702,    16,    59,
   -1827,   706,   726, -1827, -1827,   899,   951,   731, -1827,  3724,
     736,  4165,    33,    35, -1827, -1827, -1827, 10716,   737, -1827,
   -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827,
   -1827, -1827, -1827, -1827,   143, -1827, -1827, -1827, -1827,     3,
   -1827,   117,   201, -1827,    39, -1827, -1827, -1827, -1827, -1827,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   757,   763,   767,   190,   190,
     190,   190,   771,   190,   190,   190,   190,   190,   190,   787,
   -1827,   190, -1827, -1827, -1827, -1827, -1827,   190,   190,  1009,
     792,   803,   804,   190,   190,   814,   827, -1827, -1827, -1827,
   -1827,   797, 10716, 10716, 10716,  4585,  4875,   147,    23,   349,
     808,   838,   578, -1827,   839,  1073,   138,   -66,  1078, 10716,
    3792,  3792, -1827, 10716, -1827, -1827, -1827, -1827,  3792, -1827,
   -1827, -1827, -1827, -1827, -1827,  5065,    23, 10716,  9903, 10716,
   10716,   868, 10716,  9903, 10716, 10716,   871, 10716,  9903, 10716,
   10716, 10716, 10716, 10716, 10716,  3792, 10716, 10716, 10716,  6879,
     906,   879, -1827,  9903,  6198,  6198,  6198,  3792,   768,   410,
     190,   190,   190,   190,    20,    26,    32,    34,  6879,  1028,
      28,   190,  7106, 10716,  5510, -1827, -1827,   952, -1827,  2120,
   -1827, -1827,   187,  -180, 10716,  9903,   931,   934,  7333,  6198,
    6198,  6198,   967,   973,  1002,  1017,  1030,  7560,  7787,  8014,
     998,  1935,  1258,  6879,    16,  1032,  1046,   290,   290,   290,
   10716, 10716,   154, -1827,   179,   290,  1062,  1063,  1077,  4482,
     234,   156,  1035,  1064,  1088,  1102,  1106,  1107,  1128, 10716,
    6198,  6198,  6879,  1129,     4,  1041, -1827,  1136,  1373,  1382,
   -1827,  1188,  1191,  1197,  6198,  6198,  1163,  1186,  1192, -1827,
   10716, -1827,  1439,  1445, 10716, 10716, 10716,  -111, 10716,  1242,
   -1827,  1310, 10716, 10716, 10716, -1827, -1827, 10716,  1249,  1481,
    1496,  1268, -1827, -1827,  1501, -1827,  1502, -1827,   587,  5024,
     195,  3792, 10716, -1827, -1827,  6879,  6879,  9782, 10197,  1276,
    1277,  5065, -1827, -1827, -1827, -1827, -1827, -1827,  6879,  1507,
    1284, 10716, 10716,  1511, 10716, 10716, 10716, 10716, 10716, 10716,
   10716, 10716, 10716, 10716, 10716, 10716, 10716, 10716, 10716, 10716,
   10716, 10716, 10716, 10716, 10716, 10716,  3792,  3792,  3792,  3792,
    3792,  3792,  3792,  3792,  3792,  3792,  6879,  3792,  3792, 10716,
    3792,  3792,  3792,  3792,  3792, 10716,  5065, 10716,  3792,  3792,
    3792,  3792,  3792,    23,  5065,    23,  1289,  1289,  1289,   107,
   13453,   120, 13062,   205,  1285,  1513,   190,  1283, -1827,  1288,
    4641, 10716,  9903, -1827, 10716, 10716, 10716, 10716, 10716, 10716,
   10716, 10716, 10716, 10716, 10716, 10716, 10716, 10716, 10716, -1827,
   -1827, 10716, 10716, -1827, -1827,   760,   703,   161, -1827,   283,
   -1827,   237, 11609, -1827,   343,   239,   250,  1291,  1293, 13474,
    9903,  3314, -1827,   425, 13495, 13516, 10716, 13537,   490, 13558,
   13579, 10716, 13600,   527, 13621, 13642, 13663, 13684, 13705, 13726,
    1299, 13747, 13768, 13789,  1523, 10716, 10716,   602,  1526,  1527,
    1528,  1306, 10716, 10716,  1532,   347,  8241,  8468, 10716, 10716,
    3792, 10716, -1827,  1475, 10716, -1827,  1476, -1827,  1477, -1827,
    1478,  6879,    43,    45,    47,    48,  9903,  9903,  1289, -1827,
   13810, -1827,   641, 10716,  8695, 10716, 10716,   522, 13831,   645,
   10716, 10716, 10716, -1827,  1536,  1537,  1537, 10716, 10124, 10124,
   10124, 10124, 10716,  1539, 10716,  1541, 10716,  1544,  9903,  9903,
   11147,  1322,  1546,  1318, -1827, -1827,   246, -1827, -1827, 11635,
   11661,   290,   290,   349,   349,   249, 10716, 10716, 10716,  4482,
    4482, 10716,  2900,   331, -1827, 10716, 10716, 10716, 10716, 10716,
   10716, 10716, 10716, 10716, 13852,  1553,  1548,  1554, 10716,  1561,
   10716, 10716,  3019, -1827, -1827,  9903,  9903,  9903,  1563,  1564,
   10716, 10716, 10716, 13873, -1827, -1827, 13894, 13915, 13936,  1402,
   11687, -1827,  1337,  3334, 13957, 13978, 13085, -1827, -1827,  9903,
   -1827,  3283, -1827,  5334, 10716, 10716, -1827, 10716, 10716,  1344,
   13999, 11622,  1348,   683,   194, 14020,   281, 13108, 10716,  9903,
    1588,  1590, -1827, 10716, 14041, 13131,   431, 13039, 13039, 13039,
   13039, 13039, 13039, 13039, 13039, 13039, 13039, 13039, 11713, 13039,
   13039, 13039, 13039, 13039, 13039, 13039, 11739, 11765, 11791,  -147,
     -68,  -147,  1368,  1370,  1367,   710,   710,  1372,   710,  1374,
    1379,  1380, 11817,   710,   710,   710,   450,   710, 14797, -1827,
     891,  1381,  1383,  1378,   101,   773,  1387,  1389,  1388,  1593,
    1594,  6879,   322,  1595,  1596,  6879,   116,  5065, 10716,  1640,
    1643,    22,   710, -1827,   159,    30,    31,   226,  1420,   -54,
     927, -1827,  2285,   758,  3355,  2213,   848,  1222,  1222,   728,
     728,   728,   728,   626,   626,  1289,  1289,  1289,  1289,    11,
   14062, 13154, -1827, 10716, 10716,  1645,    24,  9903, 10716, 10716,
    1644,  9903, 10716,  1647,  3792,  1648, -1827,    23,  1649,  3792,
   10716,  5065,  1651,  9903,  9903,  1487,  1653,  1656, 14083,  1658,
    1494,  1661,  1663, 14104,  1664,  1500,  1667,  1669,  1670,  1671,
    1673,  1675, -1827,  1676,  1677,  1678, 10716, 14125,  3721,  1452,
   -1827, -1827, -1827,  1683, 14146, 13177,  -180, -1827, -1827,  9903,
   -1827,  9903,  3314,  1461,  9903,  1460,   727, 11843, 11869,   710,
   11895,  1462,  4181,  1469,  1470,  1474, -1827,  9903, -1827,  9903,
   -1827,  9903, -1827,  9903,   710,   801,  1704, -1827,  3442,  9903,
    1289, -1827, 14167, 13200,  9903, -1827,  1705,  1479, 14188, 14209,
   14230, 10716,  6879,  1712,  1711, 14251,  1492, 14797,  1488,  1512,
   14797,  1495,  1515, 14797,  1508,  1516, 14797,  1529, 14272, -1827,
   14293, -1827, 14314, -1827,   802,   815,  9903,  1498, -1827, -1827,
   10744, 10866,   290, 10716, 10716, -1827, -1827,  1510,  1530,  4482,
   11921, 11947, 11973, 10677,  1625,   -56,   290, 10924, 14335,  4705,
   14356, 14377, 14398, 14419, 14440, 14461, 14482,  1757, 10716,  1759,
   -1827, 10716, 14503, -1827, 13223, 13246, -1827,   818,   822,   844,
   -1827, -1827, 13269, 13292, 11999, -1827,  1762,  1763,  1764,  1542,
   10716, 10980, 10716, 10716, -1827, -1827,    54,   858, -1827, -1827,
   11037, -1827,  1766, 10423,  1543,  1545,  6879,  1769,  1733,  1734,
    6879,   322,  1737,  1738,  6879,   322,  4996,   881, -1827, -1827,
   13315,   439,   130, -1827, -1827, -1827, -1827, -1827, -1827, -1827,
   -1827, -1827, -1827, -1827, -1827, 10716, -1827, -1827, -1827, -1827,
   -1827, -1827, -1827, 10716, 10716, 10716, -1827,  9903, -1827, -1827,
   -1827, -1827,  3792, -1827, -1827, 10716, -1827,  6879,  3792,  3792,
    3792, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, 10716,
    3792, -1827,  3792, -1827, 10716, -1827, -1827, -1827, -1827,   190,
     190,  1778, -1827, 10716,  1779,   190,   190,  1780,   180, 10716,
    1781,  1784,   910, -1827,  1785,  1565,    16,  1787, -1827,  9903,
    9903,  9903,  9903, 10716,  1566,  1568,  1570,  1572, -1827,   710,
   10716, -1827,  1573,  1574,  1556, -1827,  1793, -1827, -1827, -1827,
   -1827, -1827,   472,   577, 14524, 13338, -1827, -1827,  1589,  3792,
     466, 14545, 13361, -1827,   543, 12025, -1827, -1827, -1827,    71,
   -1827, -1827, 13039,   710,   290,  3314, -1827,  1001,  6879,  6879,
    1798,  6879,  1052,  6879,  6879,  1799,  6879,  1716,  6879,  6879,
    6879,  6879,  6879,  6879,  6879,  6879,  6879,   954,  1802,  1803,
    9903, -1827,  -180,   338,   920,   924, -1827,   944, -1827, -1827,
   10716, 10716, -1827, 10716, 10716, -1827, 10716, 10716, 10716,   949,
     950,   956,   960, -1827, -1827,  6879, 10716,   966,  -180,  -180,
     970,  6879,  9903,  1804,  1805,  1807,  2688, -1827, -1827,  1809,
   -1827,  1810,   329, 10716,   329, 10716,   329, 10716,   329, 10716,
    1811,  1812,  1814,  1815,  1816,   971,  1824, 11093, -1827, -1827,
     333, 12051, 12077, -1827, -1827,  5446,  -130,   290,   290,   290,
    1714,  1826, 10495,  1597,  1825,  1605,    36,    64,    65,    69,
     -45, -1827,   337, -1827,   -56,  1827,  1829,  1830,  1832,  1833,
    1834,  1836,  1838,  1840,  6879, 14797, -1827,  1005,  1601,  1843,
    1845,  1846,  1767,  1849,  1847,  1854, 10716,  6879,  6879,  6879,
    1857, 12103, -1827,  3479,   525,  1859,  1860,  1631, -1827,  1632,
   -1827,  1127,  1634,  6879,  1630, -1827,   190,   190,  1864, 10716,
    1865,   190,   190,  1866, 10716,  1867, -1827,   710,  1868, -1827,
    1871, -1827,  1870, 13039, 13039, 13039, 13039,   795,  1646, 11583,
    1650,   710,   710,  1652,   799,   819, 14566,  1654,   710, 13039,
    2650,  3792, -1827,  1149, -1827,  2650,  3792, -1827,   336,  1655,
    1874,  1187, -1827, -1827, -1827,    16, 10716, -1827,   976, -1827,
     995,  1000,  1007,  1008, 14587, 10716, 10716, 10716, 10716,   329,
   14797,  1660, 10716, 10716,  6879,  1662, -1827, -1827, -1827, -1827,
    1657, -1827,  1872,    58, -1827, -1827,  1876, 10716,  9376,  1672,
    1659,  1890,  1892,    10,  1665,  1674,  1789,  1789,  6879,  1893,
    1679,  1680,  1896,  1899,  6879,  1735,  1681,  1902,  1905,  1906,
    1907,  1911,  1912,  1913,  1914,  1915, -1827,  1917,  6879,  1014,
    1920,   710,  1696,  1695, 12129, 12155, 12181, 12207, 12233, 12259,
   12285, -1827, -1827, -1827, -1827,  1922, 14797, -1827,   710,  1923,
    1020,  6879,  6879,  6879,  1926,  1925, -1827,  6879,  6879, 14797,
    6879, 14797,  6879, 14797,  6879, 14797,  6879,  6879,  6879,  1697,
    1698,  1927,   118, -1827, 10716, 10716, 10716,  1700,  1701,   -90,
     140,   145,  1702,  1710, -1827,  1279,  6879, -1827, 10716, -1827,
    1936, -1827,  1937, -1827,  1941, -1827,  1942, -1827, -1827,  4482,
     -17,  6425, -1827,  1706,  1739,  1740,  1741,  1742,  1743,  8922,
    1966, -1827,  9903, -1827, -1827, -1827,  1744, 10716, -1827, -1827,
   13384,  1967,  1974,  1813, -1827, 10716, 10716, 10716, -1827,  1976,
     196,  5065, -1827, -1827, -1827,  1749,  1978,  2650,  3792, -1827,
    1371, -1827,  2650,  3792, -1827,  1540, -1827,   329, -1827,   677,
   -1827, -1827, -1827, -1827, -1827, -1827,  3792, 10716, -1827, -1827,
   -1827, -1827,  3792,  1982, -1827, -1827,    25, -1827, -1827, -1827,
   -1827, -1827, -1827,  1981,  -147,  -147, -1827,  1986,  -147,  -147,
    5065, 10716,  1987,  1991,    22, -1827,  1992, 13407,    16, -1827,
    1993,  1994,  1995,  1997,  1704, 14608, 14629, 14650, 14671,  6879,
   10716, 12311, 12337,  1021, -1827, 10716,  2001, -1827, -1827,  3792,
   -1827, 12363,  5744, 14797, -1827,  1990,  1999, -1827, -1827, -1827,
   10716, 10716,   290,  2005,  2006,  2007, -1827, 10716, 10716, -1827,
   -1827,  2008,  1928,  2011, 10716, -1827, -1827, -1827, -1827, -1827,
   -1827, -1827, -1827, -1827,  2013,  2015,  1788,  -180, -1827, -1827,
   -1827, 10716, 10716, 10716, 10716, 10716, 10716, 10716, -1827, -1827,
   -1827,  1790,  2016,  1735,  2018, 10716, -1827,  2021,  2022,  2023,
    2038,  2039,  2041,  1255,  2043,  9903,  9903, 10716, -1827, 10124,
    5680, 14692,  3750,   349,   349,   290,  2044,   290,  2045,   290,
    2047, 10716, 10716, -1827,   285,  1828, 14713, -1827, -1827, -1827,
   -1827,  5907,   341, -1827,  2052,  2053,  6879,   290,   290,   290,
     290,   290,  5269,  2054, -1827,  1036, 10716,  1821,  2055, -1827,
   -1827,  6879,  3901,   414, 14734, -1827, -1827,  9449,  1835, 11622,
   11622,  6879, -1827,  2057,  -147,  -147, -1827,  2058,  -147,  -147,
   -1827,  6879, -1827,  1837, 13039,   710,  5971,  9676,  5065, -1827,
    2059,  2061, -1827,  2062,  2064,  2065,  1888, -1827,  2012,  2071,
   -1827,  1848, -1827, -1827, -1827, -1827, -1827,  1807,  1811,  1812,
    1814,  2072,   684, 14797, 10716, 10716,  6879,  1844,  1042, 14797,
   -1827,  2076, 10716, -1827, -1827,  1850,  1851,  6134,  6361,   210,
   -1827, -1827, -1827,  6588,  6815, -1827,  1852, -1827,  7042,  2078,
   -1827,  6879, 13039, 13039, 12389, 12415, 12441, 12467, 12493, 10716,
   -1827,  2083, -1827, 14797, -1827, -1827, -1827, -1827, -1827, -1827,
    1855, -1827, -1827,  1043,  1048, 11556,  2046,  2085,  1858, -1827,
   10716, -1827,  1856,  1875,   424, -1827,  1861,   426, -1827,  1877,
     429, -1827,  1878,  7269, 13430,  2088,  6879,  2077,  1879, 10716,
   -1827, -1827,  1053,   449,   451,   459,   483,   486,  9149,   530,
   -1827,  2110,  7496, -1827, -1827,  1950, 10716, -1827, 10716, -1827,
   -1827,  9903,  2075,  2112,  5065,  1883,  1884,  1885, -1827,  2117,
    2118, -1827,  2121,  2123,  2124, -1827, -1827, -1827,  5510, -1827,
   -1827,  3792, 14797, -1827, -1827, -1827, -1827, -1827, -1827, -1827,
   -1827,    16, -1827,  1968, -1827, -1827, 10716, 12519, 12545, -1827,
    6879, 10716,  2130, -1827, 12571, -1827, -1827,  6879,  6879,  2131,
    2134,  2135,  2136, 10716,  2137,  2138,  1054, -1827, -1827, 10716,
   10716, 10716, 10716, 10716,  7723, -1827,  6879,   857,   886,  9903,
   -1827, -1827,   349,  3966, -1827, -1827,  4482,   -56,  4482,   -56,
    4482,   -56, -1827,  2139, -1827,  1057,  6879, -1827,  7950,  2140,
    9903,   290,   290,   290,   290,   290, -1827, -1827, 10716,  8177,
    8404,  1070, -1827, -1827,  1918,  1916, -1827,  2146, -1827, -1827,
   -1827, -1827, -1827,  1071,  1245,  2148,  1074,  2153, -1827,  1929,
   14797, 10716, 10716,  1075, 14797, -1827, 10716,  1090,  1091, -1827,
   -1827, -1827, -1827, -1827, -1827,  8631, -1827, -1827,  1930, 12597,
   12623, 12649, 12675, 12701, -1827,  1116,  1931,   290,  6879,  2156,
    1934,   290,  2165,  1119,  1938, 10716, -1827,  8858,   537,    -6,
    9085,   541,   533,  9322,   549,   679, -1827,  6879,  2166,  2051,
   11150,  1940, -1827,  1138,   588,   591,   623,   625,   631,  2530,
   -1827, -1827,  2170,  2171, -1827, -1827, 10716, -1827,  5065,    23,
   -1827, -1827, 10716, 14755, 12727,    50, 12753, -1827, -1827, -1827,
   -1827, -1827, 10716, 10716, 10716, 10716, 10716, 10716,  2173,   290,
      84, -1827, -1827,   290,    89, -1827,  2174, -1827,  9405,  2175,
   10716,  2176,  2177, 10716,  2178,  2179, 10716,  2180,  1951, -1827,
   10716, -1827,   -56, -1827,  2182,  9903,  9903,  9903,  9903,  9149,
   -1827, -1827, -1827, 11622,  1414, -1827,  1961,  1144, -1827, 10716,
   -1827,  6879, 10716,  1148,  1151, 12779, 12805, 12831, 12857, 12883,
   12909, -1827,   633, -1827,   654, -1827, -1827, -1827, -1827,  1960,
    9551, -1827, -1827,  1962,  9612, -1827, -1827,  1963,  9839, -1827,
    2190,  3092,   715, 11206, -1827,  1155,  1158,  1176,  1177,   664,
    1181,  1964,  5065,  1972,  2196,  1969, 14776,  1212, 10027, -1827,
   -1827, 10716, 10716, 10716, 10716, 10716, 10716,   290,   290,   -56,
    2197,   -56,  2199,   -56,  2200, -1827, -1827, -1827, -1827,   -56,
    2202,  2203,  2204,  2206,  9903,  2207,  2208, -1827, -1827, -1827,
    3792, -1827,  1980,  2210, 10069, 13039, 12935, 12961, 12987, 13013,
     666,   674,   789, -1827,  1983,  1147, -1827,  1985,  1409, -1827,
    1989,  1456, -1827, -1827, -1827, -1827,  1216, -1827, -1827,  1237,
   -1827,  2017,  6879, -1827,  2215, -1827, 10716, 10716, 10716, 10716,
   10716, 10716,  2216,   -56,  2217,   -56,  2223,   -56, -1827,  2228,
    3792,  2237,  3792,  1244, -1827, 10149, 10253, 10325, 10367, 10448,
   10588, -1827,  1547, -1827,  1571, -1827,  1584, -1827, -1827, -1827,
    1247, -1827,  2241, -1827, -1827, -1827, -1827,  2242,  2244,  2247,
    2248,  2263,  3792,  2268, -1827, -1827, -1827, -1827, -1827, -1827,
   -1827, -1827
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1827, -1827, -1827, -1827,   912, -1827, -1827, -1827, -1827,   245,
   -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827,
   -1827, -1827,  -422,   -91,  4301,  3556, -1827,  1760, -1827, -1827,
   -1827, -1827, -1827, -1827, -1827, -1826, -1827,   393, -1827, -1827,
   -1827, -1827, -1827,   647,   901,  2278,    -2,  -613,  -325, -1827,
   -1827, -1827, -1827, -1827, -1827, -1827, -1827,  2295, -1827, -1827,
   -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827, -1827,
   -1827, -1227, -1226,  2297, -1687,  2298, -1827, -1827, -1827,  1707,
   -1827,   396, -1827, -1827, -1827, -1827,  1988, -1827, -1827,  1831,
   -1827, -1670,  2951,   974,   965,  2080,  -312,   751, -1827,   271,
      18, -1827,  -431,    -3,   149
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -565
static const yytype_int16 yytable[] =
{
     131,   114,   613,   216,   632,   729,  1822,   731,   649,   394,
     937,   938,  1845,  1846,  1468,  1101,  1589,  1470,   241,   246,
     367,   652,   746,   344,   215,   562,  1085,   378,   219,  1717,
    1117,   565,   220,   297,   241,   246,   297,   567,   384,   569,
     386,   409,  1459,   410,   292,   406,   407,   761,   876,   765,
     878,   768,   880,   882,   298,   222,  2090,  1094,     4,  1967,
     681,  1275,   683,   371,  1578,   349,  1231,   350,   691,   218,
    1461,  1463,   347,   303,   331,  1465,   304,  1231,  1368,   305,
     292,   306,   857,  1232,   858,   347,     5,   814,   621,   622,
    2103,  1233,  1234,  1235,  1232,  2105,   347,  1236,  1237,  1238,
    1239,  1896,  1233,  1234,  1235,  1231,  1448,   221,  1236,  1237,
    1238,  1239,   572,   228,   759,   573,  1231,   379,   574,   383,
     575,   669,  1232,  1072,  1648,  1649,   210,   763,   621,   622,
    1233,  1234,  1235,  1232,   506,   135,  1236,  1237,  1238,  1239,
     314,  1233,  1234,  1235,  1655,   351,  1656,  1236,  1237,  1238,
    1239,   473,   132,   231,   332,   217,   315,   316,   333,   406,
     407,   857,   260,   858,   334,   335,  1037,   336,   337,  -558,
    1102,  1103,  1104,  1105,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   310,  1328,   338,   311,   175,   176,   177,
     178,  1467,   563,  1460,   224,   180,   181,   182,   566,   345,
     183,   998,  1696,  1697,   568,   347,   570,   478,   401,  1718,
    1963,   188,   767,  2093,  2094,   225,   232,   509,   509,  1673,
     108,  1462,  1464,   108,   348,   509,  1466,   108,   621,   622,
    2061,   395,   259,   347,   650,   292,  1985,   370,   396,  1118,
     292,   210,   242,   247,  1468,   292,   226,  1106,   380,   243,
     248,   368,   509,   517,   346,   564,   292,  1086,   242,   247,
     292,   292,   292,   292,   509,  1090,  1091,   411,   385,   412,
     387,   413,  1000,  1118,  1004,   292,   210,   214,   877,   292,
     879,   292,   881,   883,   223,  2091,  1276,   372,  1002,   930,
     931,   354,   292,   583,   355,   292,   292,   292,   292,  1369,
     227,  1370,   621,   622,   292,   292,   292,   621,   622,   947,
     292,   347,   402,   403,   404,   760,   474,   475,   191,   192,
     193,   402,   403,   404,   405,   402,   403,   404,   764,  1072,
     857,   200,   858,   201,   108,  1062,  1072,   292,   292,   292,
    1073,   406,   407,  1550,  1079,   397,   981,   398,  1078,  1329,
    1330,   292,   292,   477,   399,   406,   407,   476,   621,   622,
     237,   990,  1300,   621,   622,  -559,   501,   238,   502,   510,
     510,   392,   621,   622,  1657,   399,  1658,   510,   393,  1659,
     326,  1660,   769,   327,   635,   518,   328,   237,   509,   623,
     806,   636,   292,   292,  1089,   807,  2131,   621,   622,   402,
     403,   404,   999,   229,   510,   292,   402,   403,   404,   405,
     402,   403,   404,   405,   624,   585,   510,   586,   233,   700,
     234,  2137,  1838,   687,   399,   688,   406,   407,   621,   622,
     406,   407,   399,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   292,   509,   509,   230,   509,   509,   509,
     509,   509,   621,   622,   250,   509,   509,   509,   509,   509,
     347,  1092,   347,   370,   621,   622,   810,   621,   622,   634,
     815,   811,   239,   816,   749,    60,    61,    62,    63,   292,
     932,   818,   757,   939,   816,   240,   402,   403,   404,  1003,
      74,   507,   511,    77,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   584,   496,   497,   318,   319,
     244,   808,   498,   809,   318,   319,   264,   292,   320,   265,
     399,  1815,   266,   245,   320,   321,   540,   402,   403,   404,
     405,   329,  2223,  1497,   402,   403,   404,   405,   551,   249,
     510,   402,   403,   404,   405,   250,   251,   406,   407,   621,
     622,   621,   622,   292,   292,   621,   622,   509,   252,   621,
     622,   406,   407,   406,   407,   946,   261,  1444,   292,   262,
    1400,  1469,   813,   292,   292,  1819,   857,   814,   858,  1289,
     253,   292,   859,  1294,   483,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   254,   510,   510,   255,   510,
     510,   510,   510,   510,  1217,   292,   292,   510,   510,   510,
     510,   510,   756,   256,   758,  1013,   908,   911,   914,   917,
     257,   478,   478,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   340,   556,   341,
     557,   498,   621,   622,   621,   622,   299,   621,   622,   300,
    1839,   301,   292,   292,   292,  1231,   406,   407,  1916,   824,
    1918,   825,   689,  1920,   406,   407,  -563,   621,   622,   621,
     622,  1074,  1232,   258,  -561,  1080,   292,   621,   622,  1054,
    1233,  1234,  1235,  1930,   814,  1931,  1236,  1237,  1238,  1239,
    1999,   263,  2002,  1932,  2005,  1363,   292,   406,   407,   267,
     824,   621,   622,   294,   621,   622,   866,  -562,   730,   510,
     732,   733,   734,   735,   736,   737,   738,  1933,   740,   741,
    1934,   743,   744,   745,   824,   747,   830,   295,   296,   751,
     752,   753,   754,   755,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   621,   622,
     302,   857,   498,   858,  1498,   621,   622,   894,   292,   621,
     622,   824,   292,   835,  1935,  1013,   802,   621,   622,  2064,
     312,  2060,  1366,  1468,  1337,  2063,  1468,   824,   313,  1468,
    1428,   317,  1430,  2066,  1432,  1081,  1434,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,  1231,   406,   407,   292,   498,   621,   622,   292,   621,
     622,   509,  -560,   339,   347,   684,   509,   685,  1232,   554,
     292,   292,  2075,   342,   210,  2076,  1233,  1234,  1235,   325,
     343,   869,  1236,  1237,  1238,  1239,   824,  1231,   849,  1133,
     352,   621,   622,   621,   622,  2122,   495,   496,   497,   621,
     622,   621,   622,   498,  1232,   353,   292,  2077,   292,  2078,
     356,   292,  1233,  1234,  1235,  2079,   357,  2147,  1236,  1237,
    1238,  1239,   621,   622,   292,   824,   292,   887,   292,   824,
     292,   897,   621,   622,   621,   622,   292,   358,  2148,  1544,
    1545,   292,   621,   622,  1548,  1549,  1468,  1058,  2164,   292,
    2210,   363,   406,   407,   307,   375,  1551,   308,  2211,   309,
    1290,  1231,  -564,  1875,  1295,  2067,  1334,   996,  1876,   997,
    1299,  1301,  2182,   292,  2185,   364,  2188,  1569,  1232,   365,
     366,   803,  2191,   804,   373,   805,  1233,  1234,  1235,   857,
     210,   858,  1236,  1237,  1238,  1239,   493,   494,   495,   496,
     497,  2157,   406,   407,   374,   498,  1468,   376,  1169,  1468,
    1396,   377,  1468,   510,   381,  1468,  1129,   391,   510,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,  1986,  1987,   439,  2232,   498,  2234,  1988,
    2236,   440,   824,   292,  1099,   441,   552,   292,   553,   446,
     554,   292,   857,   209,   858,   210,  1468,  1064,  1468,   509,
    1468,  1481,  1990,  1991,  1095,   453,   457,  1096,  1988,  1097,
     458,  1357,  1358,  1556,   857,  2212,   858,   465,   857,   824,
     858,   459,   460,  1533,   292,   824,   824,  1184,  1213,   509,
    1802,  1803,   463,   481,   292,   509,   509,   509,   857,   824,
     858,  1214,   824,  1536,  1261,   464,   824,   509,  1262,   509,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,  1299,  1301,   482,   499,   498,  1704,  1705,   824,   500,
    1263,  1708,  1709,   347,   504,  1127,   292,   292,   292,   292,
    1131,  1374,   824,  1375,  1277,  1711,   526,  1357,  1358,   531,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   546,   824,   509,  1297,   498,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,  1503,   545,   292,   292,   498,   292,   571,
     292,   292,  1380,   292,  1381,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   824,  1546,  1401,   292,   824,   590,
    1402,   510,   591,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,  1699,   824,  1700,
    1403,   498,   292,   824,   824,  1411,  1412,   393,   292,   292,
     824,   510,  1413,  1555,   824,   597,  1414,   510,   510,   510,
     824,   598,  1417,   522,   824,   824,  1418,  1441,   522,   510,
    1558,   510,  1559,   522,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   522,   824,
     599,  1560,   498,   608,   824,   370,  1561,  1552,   548,   549,
     550,   824,   824,  1562,  1563,   600,  1732,   579,   824,   522,
    1616,   292,  2028,   583,   824,  1746,  1631,  1747,   601,  1790,
     522,  1791,   611,   637,   292,   292,   292,   614,   510,  1231,
     824,   651,  1831,   594,   595,   596,  1881,   824,  1882,  1907,
     292,   615,   824,  1302,  1908,  1663,  1232,  1746,  1746,  1929,
    1978,  2007,   638,  2008,  1233,  1234,  1235,   626,   627,  1994,
    1236,  1237,  1238,  1239,   824,  2026,  2022,  2027,   814,  1746,
    2030,  2035,   628,  1308,   645,   646,   639,   509,   509,  1311,
    1312,  1313,   509,   509,  1533,  1536,  2037,  2038,   658,   659,
     640,  1317,   347,  1318,   641,   642,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
    1746,   292,  2048,   824,   498,  2056,   643,   648,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   824,   399,  2074,   292,   498,  1706,  1881,   653,
    2134,   292,  1533,  2214,  2139,  1533,  1584,  2140,   654,   824,
    1362,  2160,   824,   660,  2161,   292,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     824,   824,  2162,  2163,   498,   824,   661,  2165,   292,   292,
     292,  2132,   662,   655,   292,   292,   656,   292,  1712,   292,
    1956,   292,   657,   292,   292,   292,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   664,  1746,   522,  2172,   498,
     824,   665,  2219,   292,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   823,   496,   497,   292,   510,
     510,  2220,   498,  2221,   510,   510,   292,   671,  1746,   292,
    2242,  2252,   672,  2253,   370,   579,   210,   677,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   678,   679,   509,   509,   498,   680,   682,   509,
     509,   698,   699,   702,   703,   706,   498,   770,   209,  1698,
     771,   863,   865,   509,   773,   820,  1712,   821,   842,   509,
     846,  1231,   850,   851,   852,   853,   856,   871,   873,   874,
     875,   884,   522,   901,   902,   919,  1710,   921,  1232,   891,
     923,   927,   928,   929,   960,   347,  1233,  1234,  1235,  1957,
     958,   961,  1236,  1237,  1238,  1239,   292,   963,  1725,   970,
     971,   979,   982,   522,   522,   991,   509,   995,  1231,   292,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,  1008,  1232,  1009,  1040,   498,  1041,
    1754,  1042,  2010,  1233,  1234,  1235,  1045,  1061,  1047,  1236,
    1237,  1238,  1239,  1048,  1049,  1059,  1066,  1060,  1067,  1068,
     522,   522,   522,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,  1069,  1070,  1075,
    1076,   498,   292,   292,   522,  2216,  1083,  1084,  1093,  1116,
    1123,   478,   478,  1126,  1128,  1130,   510,   510,  1134,  1137,
    1138,   510,   510,  1139,   522,  1141,  1142,  1797,  1143,  1231,
    1144,  1146,  1147,   292,  1148,   510,  1149,  1150,  1151,   292,
    1152,   510,  1153,  1154,  1155,  1156,  1232,  1160,   292,  1161,
    1166,  1168,  2218,  1231,  1233,  1234,  1235,  1174,   292,  2083,
    1236,  1237,  1238,  1239,  1176,  1177,  1231,   370,   292,  1178,
    1232,  1185,  1191,   292,  1192,  1843,  1198,  1200,  1233,  1234,
    1235,  1202,  1203,  1232,  1236,  1237,  1238,  1239,   510,  1205,
    1216,  1233,  1234,  1235,  1860,  1863,  1864,  1236,  1237,  1238,
    1239,  1204,  1207,   292,  1206,  1208,  1223,  1230,  2123,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,  1209,  1254,  1256,  1224,   498,   292,  1267,
    1268,  1269,   522,  1279,  1270,  1285,   522,  1286,  1287,  1282,
    1283,  1291,  1292,  2249,  1322,  1324,  1327,  1332,   891,  1136,
    1333,  1354,  1335,  1339,  1345,  1336,  1346,  1713,  1347,  1356,
    1348,  1352,  1353,  1715,  1361,  1378,  1384,  2250,  1386,  1397,
    1398,  1421,  1422,   292,  1423,  1426,  1452,  1427,  1436,  1437,
    2251,  1438,  1439,  1440,   522,   292,   522,  1833,  1442,   522,
    1453,  1457,  1456,  1458,  1471,  1472,  1482,  1473,   292,  1474,
    1475,  1476,   522,  1477,   522,  1478,   522,  1479,   522,  1483,
    1751,  1484,  1485,  1488,   522,   292,  1487,  1486,   509,   522,
    1489,  1494,  1944,  1499,  1500,  1501,  1506,  1502,   347,  1504,
    1509,  1511,  1514,  1516,  1518,  1519,  1520,   292,  1577,  1529,
    1526,  1554,  1580,  1540,   292,   292,  1532,  1553,  1570,  1576,
    1586,   522,   322,   324,  1870,   330,  1587,  1575,  1588,  1596,
    1590,  1585,  1599,   292,  1592,  1600,   292,  1602,  1605,  1591,
     478,  1606,  1607,  1608,  1597,  1598,  1604,  1609,  1610,  1611,
    1612,  1613,  1614,   292,  1617,  1619,  1620,   292,  1628,  1630,
    1635,  1636,  1645,  1646,  1647,  1653,  1654,  1661,   133,   388,
    1662,  1676,  1667,  1668,   136,   137,   138,  1669,  1670,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,  1684,  1689,  1677,  1678,  1679,  1680,  1681,  1686,
    1690,  1691,  1695,  1701,  1702,   292,  1716,  1719,   171,   172,
     173,   174,  1722,  1727,   212,  1728,   179,  1755,  1730,  1733,
    1734,  1735,   522,  1736,   292,  1750,  1756,   184,   185,   186,
     510,  1760,  1761,  1762,  1765,   187,  1766,  1767,  1769,  1871,
     370,  1770,  1780,  1771,  1782,  1779,   347,  1784,  1785,  1786,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,  1787,  1788,  2085,  1789,   498,  1792,
    1805,  1808,  1910,  1811,   522,   522,   522,   522,  1820,  1821,
    1830,  1834,  1816,  1848,  1851,  1865,  1855,  1866,  1867,  1844,
    1868,  1869,   292,   292,   292,   292,   292,  1872,  1874,  1880,
    1873,  1942,  1883,  1895,  1926,  1887,  1888,  1893,   292,  1905,
    1906,  1911,  1914,  1912,  1924,   389,  1917,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,  1915,  1919,  1921,  1927,   498,  1936,  1938,  1943,  1945,
    1946,  1947,   190,  1948,  1949,   522,   194,  1950,   583,  1951,
    1952,   195,   196,   197,   198,   199,  1965,  1971,  1958,   108,
    1972,  1973,  1974,  1976,  1977,  2006,  2012,  2023,   616,   617,
    2167,  2024,  2025,   202,   203,  2029,   625,   522,   204,  2031,
     633,   292,  2052,   360,  2032,  2042,  2049,   509,   208,  2053,
     609,  2055,  2069,  2070,  2057,  2073,  2081,  2082,  2086,  2101,
    2106,  2108,  2111,  2112,  2115,  2116,  2119,  2120,  2124,  2133,
     466,   467,   468,   470,   472,  2149,  2155,  2151,  2153,   292,
    2166,  2168,  2169,  2183,  2170,  2186,  2189,   505,  2192,  2193,
    2194,   512,  2195,  2197,  2198,  2202,  2203,   509,  2213,   509,
    2215,  2224,  2231,  2233,  2217,   519,   521,   524,   525,  2235,
     527,   521,   529,   530,  2237,   532,   521,   534,   535,   536,
     537,   538,   539,  2239,   541,   542,   543,  2254,  2255,   509,
    2256,   521,  2222,  2257,  2258,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,  2259,
     578,   580,   521,   498,  2261,  1579,   819,  2087,  1594,  1968,
    1781,   113,   588,   521,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   123,   610,
     124,   125,   498,   904,  1992,  1729,     0,     0,   619,   620,
       0,     0,     0,     0,     0,     0,     0,   620,   523,   510,
       0,     0,     0,   528,     0,     0,     0,   644,   533,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     584,   496,   497,   547,     0,     0,     0,   498,   663,     0,
       0,     0,   666,   667,   668,     0,   670,     0,     0,     0,
     673,   674,   675,     0,     0,   676,     0,     0,     0,   510,
       0,   510,     0,     0,     0,   589,     0,     0,     0,     0,
     690,     0,     0,     0,     0,   695,   697,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   704,
     705,   510,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,   742,     0,     0,
     498,  2200,     0,   748,     0,   750,     0,   522,     0,     0,
       0,     0,   935,   936,     0,     0,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,     0,     0,     0,   782,
     521,     0,   784,   785,   786,   787,   788,   789,   790,   791,
     792,   793,   794,   795,   796,   797,   798,     0,     0,   800,
     801,  2238,     0,  2241,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   578,     0,
       0,     0,   498,     0,   828,     0,     0,     0,     0,   833,
       0,  1098,     0,  2260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   847,   848,     0,  2080,     0,     0,     0,
     854,   855,     0,     0,   862,   862,   867,   868,     0,   870,
       0,     0,   872,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   783,     0,   862,   521,     0,     0,     0,     0,
       0,   888,   890,   892,   893,     0,     0,     0,   898,   899,
     900,     0,     0,     0,     0,   905,   907,   910,   913,   916,
     918,     0,   920,     0,   922,     0,   521,   521,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,   522,     0,     0,   940,   941,   942,   466,   467,   943,
       0,     0,     0,   948,   949,   950,   951,   952,   953,   954,
     955,   956,     0,     0,     0,     0,   962,     0,   964,   965,
       0,     0,     0,   521,   521,   521,     0,   522,   972,   973,
     974,     0,     0,     0,   506,   135,     0,   885,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,     0,     0,
       0,     0,   854,   855,     0,   892,   893,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1006,   521,   924,   925,
       0,  1010,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,     0,     0,     0,     0,   175,   176,   177,
     178,     0,     0,     0,     0,   180,   181,   182,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,   967,   968,   969,     0,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,  1082,   498,     0,   987,
       0,     0,     0,  1220,     0,     0,     0,     0,     0,     0,
    1226,     0,     0,     0,     0,     0,     0,  1242,     0,  1007,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,  1115,   579,     0,   521,  1121,  1122,     0,   521,
    1125,     0,     0,     0,     0,     0,   522,     0,  1132,     0,
    1424,   890,  1135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1955,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1157,     0,     0,     0,   191,   192,
     193,     0,     0,     0,     0,     0,     0,   521,     0,   521,
       0,   200,   521,   201,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,     0,   521,     0,   521,
       0,   521,     0,     0,   522,     0,     0,   521,     0,   857,
       0,   858,   521,     0,     0,     0,     0,  1120,     0,  1196,
       0,  1124,     0,     0,     0,   522,     0,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     7,     8,   521,   498,     0,     0,     0,     0,
       0,  1221,  1222,     0,     0,     0,     0,  1225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1164,
       0,  1165,     0,     0,  1167,     0,  1255,     0,     0,  1257,
       0,     0,     0,     0,     0,     0,     0,  1179,     0,  1180,
       0,  1181,     0,  1182,     0,  1373,     0,     0,  1271,  1187,
    1273,  1274,     0,     0,  1190,     0,     0,     0,     0,     0,
       0,  1281,     0,     0,   774,    24,    25,   775,    27,    28,
     776,    30,   777,    32,    33,    34,    35,     0,   290,     0,
      37,    38,    39,     0,     0,    41,  1215,     0,     0,     0,
       0,   778,    48,  1303,     0,    50,   779,     0,    53,    54,
     780,  1304,  1305,  1306,    58,   521,     0,     0,     0,     0,
       0,     7,     8,  1309,     0,     0,     0,     0,    71,     0,
     522,   522,   522,   522,   522,     0,     0,  1316,     0,     0,
       0,     0,  1319,     0,     0,     0,     0,     0,  1449,  1450,
    1451,  1323,     0,     0,    85,    86,    87,  1331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,   521,   521,
     521,  1344,     0,     0,     0,     0,     0,     0,  1350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2156,     0,
       0,     0,     0,   774,    24,    25,   775,    27,    28,   776,
      30,   777,    32,    33,    34,    35,     0,  1307,     0,    37,
      38,    39,     0,     0,    41,     0,     0,     0,     0,   522,
     778,    48,     0,     0,    50,   779,   944,    53,    54,   780,
       0,     0,     0,    58,     0,     0,     0,     0,   521,     0,
       0,     0,     0,     0,     0,     0,     0,    71,  1404,  1405,
       0,  1406,  1407,     0,  1408,  1409,  1410,     0,     0,  1340,
    1341,  1342,  1343,     0,  1416,     0,     0,     0,     0,     0,
     521,     0,     0,    85,    86,    87,     0,     0,     0,     0,
       0,  1429,     0,  1431,     0,  1433,     0,  1435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     544,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1455,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1399,     0,     0,     0,     0,     0,     0,     0,     0,   593,
       0,     0,     0,     0,  1490,   966,     0,     0,   603,   605,
     607,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,  1420,     0,     0,     0,     0,  1510,     0,     0,
       0,     0,  1515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   647,     0,     7,     8,     0,     0,     0,
    1672,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,   583,     0,  1557,     0,     0,     0,     0,     0,
       0,     0,     0,  1565,  1566,  1567,  1568,     0,     0,     0,
    1571,  1572,   983,     0,     0,     0,   692,   693,     0,     0,
       0,     0,     0,     0,     0,  1581,  1583,     0,     0,   701,
       0,     0,     0,  1100,     0,     0,     0,   774,    24,    25,
     775,    27,    28,   776,    30,   777,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,     0,     0,    41,     0,
       0,     0,     0,     0,   778,    48,     0,   739,    50,   779,
       0,    53,    54,   780,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     0,  1759,     0,     0,     0,     0,     0,     0,
       0,     0,  1650,  1651,  1652,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1664,     0,  1666,    85,    86,    87,
    1186,     0,     0,     0,     0,     0,     0,  1671,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     521,     0,     0,     0,     0,  1687,     0,     0,     0,     0,
       0,     0,     0,  1692,  1693,  1694,  1804,  1496,  1807,     0,
    1810,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1823,  1824,
    1825,  1826,  1827,  1829,     0,  1714,     0,     0,     0,   988,
       0,     0,   593,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   823,   496,   497,     0,     0,  1726,
       0,   498,     0,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,  1743,     0,
       0,   498,  1685,  1749,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,  1757,  1758,
       0,     0,   498,     0,     0,  1763,  1764,     0,     0,     0,
       0,     0,  1768,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,     0,     0,     0,     0,
       0,     0,     0,  1783,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,   521,  1795,     0,  1796,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1813,
    1814,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
     521,     0,     0,     0,  1832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1842,     0,     0,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,  1862,   498,     0,     0,     0,
       0,     0,  1071,     0,     0,     0,  1077,     0,     0,     0,
       0,     0,     0,     0,     0,  1793,  1794,     0,   378,   135,
       0,     0,  1877,  1878,     0,     0,     0,     0,     0,     0,
    1884,     0,     0,     0,     0,     0,     0,  1998,     0,  2001,
       0,  2004,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2014,  2015,  2016,  2017,  2018,  1904,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,   175,   176,   177,   178,     0,     0,     0,  1913,   180,
     181,   182,     0,     0,   183,     0,   506,   135,     0,     0,
       0,     0,     0,     0,     0,   188,     0,  1928,     0,     0,
       0,     0,     0,     0,     0,     0,   578,     0,  2050,     0,
       0,     0,  2054,     0,  1939,     0,  1940,     0,     0,   521,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,     0,  1954,     0,     0,   175,
     176,   177,   178,  1197,     0,     0,     0,   180,   181,   182,
       0,     0,   183,     0,  1960,     0,     0,     0,     0,  1964,
       0,     0,     0,   188,     0,     0,     0,     0,     0,     0,
    2102,  1975,     0,     0,  2104,     0,     0,  1979,  1980,  1981,
    1982,  1983,     0,     0,     0,     0,     0,   521,     0,     0,
       0,     0,     0,     0,  1997,     0,  2000,     0,  2003,     0,
    2129,     0,   191,   192,   193,     0,     0,     0,   521,     0,
       0,  1941,     0,     0,     0,   200,  2019,   201,   108,     0,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,  1284,   498,  2033,
    2034,  1288,     0,     0,  2036,  1293,     0,  1159,     0,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,  2180,  2181,
     191,   192,   193,  2058,  1800,     0,  1801,     0,     0,  1993,
       0,     0,     0,   200,     0,   201,   108,     0,  1310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2013,     0,     0,     0,  2084,     0,     0,     0,     0,     0,
    1749,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2095,  2096,  2097,  2098,  2099,  2100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2110,     0,
       0,  2114,     0,     0,  2118,     0,     0,     0,  2121,     0,
       0,     0,     0,   521,   521,   521,   521,   521,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2136,     0,     0,
    2138,     0,     0,     0,     0,     0,     0,     0,     0,  1376,
    1377,     0,  1379,     0,  1382,  1383,     0,  1385,     0,  1387,
    1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,     0,     0,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,  2174,
    2175,  2176,  2177,  2178,  2179,  1836,  1415,  1837,     0,     0,
       0,     0,  1419,   895,     0,     0,     0,     0,     0,     0,
       0,     0,   521,     0,     0,  2125,  2126,  2127,  2128,  2130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   382,
     135,     0,     0,     0,     0,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,  2225,  2226,  2227,  2228,  2229,  2230,
    1995,     0,  1996,     0,     0,  1480,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,  1491,  1492,
    1493,     0,   175,   176,   177,   178,     0,     0,     0,     0,
     180,   181,   182,     0,  1505,   183,     0,     0,     0,     0,
       0,     0,     0,     0,  2196,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,     0,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,     0,     0,     0,  1036,  1038,  1039,     0,     0,
       0,  1043,  1044,     0,  1046,     0,     0,     0,     0,  1051,
    1052,  1053,     0,  1055,     0,  1574,     0,     0,     0,     0,
    1063,  1065,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,     0,     0,     0,     0,  1088,  1595,
       0,     0,     0,     0,     0,  1601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1615,
       0,     0,     0,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,   201,     0,
       0,     0,  1632,  1633,  1634,     0,     0,     0,  1637,  1638,
       0,  1639,     0,  1640,     0,  1641,     0,  1642,  1643,  1644,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,  1665,   498,     0,
       0,     0,     0,     0,     0,     0,     0,  1175,     0,     0,
       0,     0,  1675,     0,     0,  1172,     0,     0,     0,     0,
    1683,     0,   400,     0,     0,     0,     0,     0,     0,     0,
    1183,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,   442,
     443,   444,   445,     0,   447,   448,   449,   450,   451,   452,
       0,     0,   454,     0,     0,   133,   388,     0,   455,   456,
       0,   136,   137,   138,   461,   462,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
    1741,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1753,     0,   171,   172,   173,   174,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,   555,
       0,   558,   559,   560,   561,     0,     0,     0,     0,     0,
       0,     0,   576,     0,     0,     0,     0,     0,   133,   388,
       0,     0,     0,   587,   136,   137,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,  1574,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
     173,   174,  1835,     0,     0,     0,   179,     0,     0,     0,
       0,     0,  1847,     7,     8,  1349,     0,   184,   185,   186,
       0,     0,  1854,     0,     0,   187,     0,  1859,     0,   190,
       0,     0,     0,   194,     0,     0,     0,     0,   195,   196,
     197,   198,   199,     0,     0,     0,   108,     0,  1371,  1372,
       0,     0,     0,     0,     0,     0,     0,  1879,     0,     0,
     629,   630,     0,     0,     0,   204,     0,     0,     0,     0,
     631,     0,     0,     0,     0,   208,     0,   321,     0,     0,
       0,     0,  1574,     0,     0,   774,    24,    25,   775,    27,
      28,   776,    30,   777,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,     0,    41,     0,     0,     0,
       0,     0,   778,    48,     0,     0,    50,   779,     0,    53,
      54,   780,     0,     0,     0,    58,     0,  1925,     0,     0,
       0,     0,   190,     0,     0,     0,   194,   772,     0,    71,
       0,   195,   196,   197,   198,   199,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,    85,    86,    87,   204,     0,
       0,     0,     0,   360,   469,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1574,     0,     0,     0,     0,     0,     0,  1969,  1970,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1517,     0,     0,     0,  1574,     0,  1521,
    1522,  1523,  1524,  1525,     0,  1528,     0,  1530,  1531,     0,
    1534,  1537,     0,     0,  1541,  1542,  1543,  2009,   133,   388,
       0,  1547,     0,     0,   136,   137,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   171,   172,
     173,   174,   498,     0,     0,     0,   179,     0,     0,  2051,
       0,  1246,     0,     0,     0,     0,     0,   184,   185,   186,
       0,     0,     0,     0,     0,   187,     0,  1618,  2068,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   134,   135,     0,  1629,     0,   136,   137,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     0,
       0,     0,   180,   181,   182,     0,     0,   183,     0,   184,
     185,   186,  1574,     0,     0,     0,     0,   187,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,  1703,     0,     0,   194,     0,  1707,     0,
     135,   195,   196,   197,   198,   199,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,     0,     0,     0,   204,     0,
    1720,  1721,     0,   360,  1723,  1724,   471,     0,   208,   162,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     0,
       0,     0,   175,   176,   177,   178,     0,     0,     0,     0,
     180,   181,   182,     0,     0,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   189,     0,     0,
       0,     0,     0,  1574,   190,   191,   192,   193,   194,     0,
       0,     0,     0,   195,   196,   197,   198,   199,   200,     0,
     201,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,     0,     0,     0,
     204,     0,     0,     0,     0,   205,     0,   206,     0,   207,
     208,     0,   209,     0,   210,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,  1296,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   191,   192,   193,     0,     0,     0,   686,
    1849,  1850,     0,     0,  1852,  1853,   200,     0,   201,     0,
    1856,  1857,   133,   268,     0,     0,     0,     0,   136,   137,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   269,   270,   271,   272,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,   173,   174,     0,     0,  1897,  1898,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,     0,     0,     7,     8,     0,   187,
       0,     0,     0,   274,     0,     0,   275,     0,     0,   276,
       0,   277,     0,     0,     0,     0,     0,     0,    36,     0,
    1320,  1321,     0,     0,     0,     0,  1325,  1326,     0,     0,
     278,     0,    49,     0,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
      74,     0,     0,    77,     0,     0,     0,     0,   774,    24,
      25,   775,    27,    28,   776,    30,   777,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,     0,     0,    41,
       0,     0,     0,     0,     0,   778,    48,     0,     0,    50,
     779,     0,    53,    54,   780,     0,   190,     0,    58,     0,
     194,   281,     0,     0,     0,   195,   196,   197,   198,   199,
       0,     0,    71,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   629,  1828,     0,
       0,     0,   204,     0,     0,     0,     0,   631,    85,    86,
      87,     0,   208,     0,   321,   581,     0,     0,     0,     0,
       0,     0,     0,   133,   268,     0,     0,     0,     0,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   269,   270,   271,
     272,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,     0,     0,     0,
     989,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,     0,     0,  1507,  1508,     0,
     187,     0,  1512,  1513,   274,     0,     0,   275,     0,     0,
     276,     0,   277,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,    49,     0,     0,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,  1447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,     0,     0,
       0,   194,   281,     0,     0,     0,   195,   196,   197,   198,
     199,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   520,
       0,  2205,     0,   204,     0,     0,     0,     0,   360,     0,
       0,     0,     0,   208,     0,     0,   581,   133,   268,   135,
       0,     0,     0,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   269,   270,   271,   272,   273,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,   180,
     181,   182,     0,     0,   183,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,   188,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,   277,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,    49,     0,     0,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,  1798,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,   191,   192,   193,   194,   281,     0,     0,     0,
     195,   196,   197,   198,   199,   200,     0,   201,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   282,     0,     0,     0,   204,     0,     0,
       0,     0,   360,     0,   133,   268,   135,   208,     0,   284,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   269,   270,
     271,   272,   273,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,   180,   181,   182,     0,
       0,   183,     0,   184,   185,   186,     0,     0,     0,     0,
       0,   187,   188,     0,     0,   274,     0,     0,   275,     0,
       0,   276,     0,   277,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,    49,     0,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,    74,     0,     0,    77,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,  1818,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,   200,     0,   201,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     282,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,   359,   208,     0,  1858,   136,   137,   138,
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
    1889,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,     0,     0,   194,
     281,     0,     0,     0,   195,   196,   197,   198,   199,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   282,     0,     0,
       0,   204,     0,     0,     0,     0,   360,     0,   133,   268,
    1674,   208,     0,   284,   136,   137,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   269,   270,   271,   272,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
     173,   174,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   274,
       0,     0,   275,     0,     0,   276,     0,   277,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,     0,    49,     0,
       0,   279,     0,     0,   280,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,     0,     0,    66,    67,
      68,    69,    70,     0,     0,     0,    74,     0,     0,    77,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,  1890,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,     0,     0,   194,   281,     0,     0,
       0,   195,   196,   197,   198,   199,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   282,     0,     0,     0,   204,     0,
       0,     0,     0,   360,     0,   133,   268,     0,   208,     0,
     284,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   269,
     270,   271,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   274,     0,     0,   275,
       0,     0,   276,     0,   277,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,    49,     0,     0,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,     0,  1891,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,   194,   281,     0,     0,     0,   195,   196,
     197,   198,   199,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   282,     0,     0,     0,   204,     0,     0,     0,     0,
     283,     0,   133,   268,     0,   208,     0,   284,   136,   137,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   269,   270,   271,   272,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,   173,   174,     0,     0,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   274,     0,     0,   275,     0,     0,   276,
       0,   277,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,     0,    49,     0,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
      74,     0,     0,    77,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,  1892,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
     194,   281,     0,     0,     0,   195,   196,   197,   198,   199,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   282,     0,
       0,     0,   204,     0,     0,     0,     0,   360,     0,   133,
     268,     0,   208,     0,   284,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   269,   270,   271,   272,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,     0,     0,     0,
     274,     0,     0,   275,     0,     0,   276,     0,   277,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,    49,
       0,     0,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,  1894,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   194,   281,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   520,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,     0,   208,
       0,   577,   136,   137,   138,     0,     0,   139,   140,   141,
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
       0,     0,     0,     0,     0,  1922,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,   194,   281,     0,     0,     0,   195,
     196,   197,   198,   199,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   282,     0,     0,     0,   204,     0,     0,     0,
       0,   592,     0,   133,   268,     0,   208,     0,   284,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   269,   270,   271,
     272,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,     0,     0,     0,   274,     0,     0,   275,     0,     0,
     276,     0,   277,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,    49,     0,     0,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,  1937,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,     0,     0,
       0,   194,   281,     0,     0,     0,   195,   196,   197,   198,
     199,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   282,
       0,     0,     0,   204,     0,     0,     0,     0,   602,     0,
     133,   268,     0,   208,     0,   284,   136,   137,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   269,   270,   271,   272,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   172,   173,   174,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     185,   186,     0,     0,     0,     0,     0,   187,     0,     0,
       0,   274,     0,     0,   275,     0,     0,   276,     0,   277,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,     0,
      49,     0,     0,   279,     0,     0,   280,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,     0,     0,
      66,    67,    68,    69,    70,     0,     0,     0,    74,     0,
       0,    77,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,  1984,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,     0,     0,   194,   281,
       0,     0,     0,   195,   196,   197,   198,   199,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   282,     0,     0,     0,
     204,     0,     0,     0,     0,   604,     0,   133,   268,     0,
     208,     0,   284,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   269,   270,   271,   272,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,     0,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,   277,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,    49,     0,     0,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,  2011,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,     0,     0,     0,   194,   281,     0,     0,     0,
     195,   196,   197,   198,   199,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   282,     0,     0,     0,   204,     0,     0,
       0,     0,   606,     0,   133,   268,     0,   208,     0,   284,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   269,   270,
     271,   272,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,     0,     0,
       0,     0,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   184,   185,   186,     0,     0,     0,     0,
       0,   187,     0,     0,     0,   274,     0,     0,   275,     0,
       0,   276,     0,   277,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,    49,     0,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,    74,     0,     0,    77,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,  2020,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,   194,   281,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     520,     0,     0,     0,   204,     0,     0,     0,     0,   360,
       0,   133,   268,     0,   208,     0,   861,   136,   137,   138,
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
    2021,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,     0,     0,   194,
     281,     0,     0,     0,   195,   196,   197,   198,   199,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   520,     0,     0,
       0,   204,     0,     0,     0,     0,   360,     0,   133,   268,
       0,   208,     0,   864,   136,   137,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   269,   270,   271,   272,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
     173,   174,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   274,
       0,     0,   275,     0,     0,   276,     0,   277,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,     0,    49,     0,
       0,   279,     0,     0,   280,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,     0,     0,    66,    67,
      68,    69,    70,     0,     0,     0,    74,     0,     0,    77,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,  2041,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,     0,     0,   194,   281,     0,     0,
       0,   195,   196,   197,   198,   199,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   520,     0,     0,     0,   204,     0,
       0,     0,     0,   360,     0,   133,   268,     0,   208,     0,
     889,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   269,
     270,   271,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   274,     0,     0,   275,
       0,     0,   276,     0,   277,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,    49,     0,     0,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,     0,  2059,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,   194,   281,     0,     0,     0,   195,   196,
     197,   198,   199,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   282,     0,     0,     0,   204,     0,     0,     0,     0,
     360,     0,   133,   268,     0,   208,     0,  1682,   136,   137,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   269,   270,   271,   272,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,   173,   174,     0,     0,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   274,     0,     0,   275,     0,     0,   276,
       0,   277,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,     0,    49,     0,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
      74,     0,     0,    77,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,  2062,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
     194,   281,     0,     0,     0,   195,   196,   197,   198,   199,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   629,  1828,     0,
       0,     0,   204,     0,     0,     0,     0,   631,     0,   133,
     388,   135,   208,     0,   321,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,   180,   181,   182,     0,     0,   183,     0,   184,   185,
     186,     0,   133,   388,   135,     0,   187,   188,   136,   137,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     0,   180,   181,   182,     0,     0,   183,
       0,   184,   185,   186,     0,     0,     0,     0,     0,   187,
     188,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,  2065,     0,
       0,     0,     0,   190,   191,   192,   193,   194,     0,     0,
       0,     0,   195,   196,   197,   198,   199,   200,     0,   201,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   203,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,     0,     0,     0,   208,
       0,  1582,     0,     0,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,   190,   191,   192,   193,
     194,  2107,     0,     0,     0,   195,   196,   197,   198,   199,
     200,     0,   201,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,     0,
       0,     0,   204,     0,     0,     0,     0,   360,     0,   133,
     388,   135,   208,     0,  1841,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,   180,   181,   182,     0,     0,   183,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,   188,     0,     0,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,   133,   388,  2150,     0,     0,
       0,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
       0,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   171,   172,   173,   174,   498,
       0,     0,     0,   179,     0,     0,     0,     0,  2152,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,   190,   191,   192,   193,   194,     0,     0,
       0,     0,   195,   196,   197,   198,   199,   200,     0,   201,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   203,     0,     0,     0,   204,
       0,     0,     0,     0,   360,     0,   133,   268,     0,   208,
       0,  1861,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     269,   270,   271,   272,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,   190,
       0,     0,     0,   194,     0,   184,   185,   186,   195,   196,
     197,   198,   199,   187,     0,     0,   108,   274,     0,     0,
     275,     0,     0,   276,     0,   277,     0,     0,     0,     0,
     202,   203,    36,     0,     0,   204,     0,     0,     0,     0,
     360,   694,     0,     0,   278,   208,    49,     0,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,   194,   281,     0,     0,     0,   195,
     196,   197,   198,   199,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   520,     0,     0,     0,   204,   133,   388,   135,
       0,   360,     0,   136,   137,   138,   208,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,   180,
     181,   182,     0,     0,   183,     0,   184,   185,   186,     0,
     133,   388,     0,     0,   187,   188,   136,   137,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     171,   172,   173,   174,   498,     0,     0,     0,   179,     0,
       0,     0,     0,  2173,     0,     0,     0,     0,     0,   184,
     185,   186,     0,     0,     0,     0,     0,   187,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,  2204,     0,     0,     0,     0,
       0,   190,   191,   192,   193,   194,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,     0,   201,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,     0,     0,     0,   204,     0,     0,
       0,     0,   360,     0,     0,     0,     0,   208,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,   190,  2243,     0,     0,   194,     0,
       0,     0,     0,   195,   196,   197,   198,   199,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,     0,     0,     0,
     204,     0,     0,     0,     0,   360,   133,   388,   696,  1280,
     208,     0,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   171,   172,   173,   174,
     498,     0,     0,     0,   179,     0,     0,     0,     0,  2244,
       0,     0,     0,     0,     0,   184,   185,   186,   133,   388,
       0,  1454,     0,   187,   136,   137,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   171,   172,
     173,   174,   498,     0,     0,     0,   179,     0,     0,     0,
       0,  2245,     0,     0,     0,     0,     0,   184,   185,   186,
       0,     0,     0,     0,     0,   187,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,  2246,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,   194,     0,     0,     0,     0,   195,
     196,   197,   198,   199,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,     0,     0,     0,   204,     0,     0,     0,
       0,   360,     0,     0,     0,     0,   208,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,   190,     0,  2247,     0,   194,     0,     0,     0,
       0,   195,   196,   197,   198,   199,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,     0,     0,     0,   204,   133,
     388,     0,     0,   360,     0,   136,   137,   138,   208,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,     0,  2248,     0,     0,     0,   774,    24,
      25,   775,    27,    28,   776,    30,   777,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,     0,     0,    41,
       0,     0,     0,     0,     0,   778,    48,     0,     0,    50,
     779,     0,    53,    54,   780,     0,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,    71,     0,     0,     0,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,   190,   498,     0,   975,   194,    85,    86,
      87,   933,   195,   196,   197,   198,   199,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   203,     7,     8,     0,   204,
       0,     0,     0,     0,   360,     0,     0,     0,     0,   208,
     774,    24,    25,   775,    27,    28,   776,    30,   777,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,     0,
       0,    41,     0,     0,     0,     0,     0,   778,    48,     0,
    1218,    50,   779,     0,    53,    54,   780,     0,     0,     0,
      58,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     0,     0,     0,   774,    24,
      25,   775,    27,    28,   776,    30,   777,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,     0,     0,    41,
      85,    86,    87,     0,     0,   778,    48,     0,     0,    50,
     779,     0,    53,    54,   780,     0,     0,     0,    58,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,   774,    24,    25,   775,    27,    28,
     776,    30,   777,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,     0,    41,     0,     0,    85,    86,
      87,   778,    48,     0,     0,    50,   779,     0,    53,    54,
     780,     0,  1219,     0,    58,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
       0,   774,    24,    25,   775,    27,    28,   776,    30,   777,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,     0,    41,     0,    85,    86,    87,     0,   778,    48,
       0,     0,    50,   779,     0,    53,    54,   780,     0,     0,
    1243,    58,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,   774,    24,    25,
     775,    27,    28,   776,    30,   777,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,     0,     0,    41,     0,
       0,    85,    86,    87,   778,    48,     0,     0,    50,   779,
       0,    53,    54,   780,     0,     0,  1272,    58,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     0,     0,   774,    24,    25,   775,    27,    28,
     776,    30,   777,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,     0,    41,     0,    85,    86,    87,
       0,   778,    48,     0,     0,    50,   779,     0,    53,    54,
     780,     0,     0,  1278,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
     774,    24,    25,   775,    27,    28,   776,    30,   777,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,     0,
       0,    41,     0,     0,    85,    86,    87,   778,    48,     0,
       0,    50,   779,     0,    53,    54,   780,     0,     0,  1443,
      58,     0,     0,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,    71,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,     0,     0,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
      85,    86,    87,     0,   498,     0,     0,     0,     0,     0,
      -4,    -4,   926,     0,     0,     0,  2071,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,     0,    -4,
       0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,  2158,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     6,     0,     0,     0,     0,    -4,     0,     0,     7,
       8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,     0,     9,
      10,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,    14,    15,     0,    16,     0,
       0,     0,    17,    18,     0,    19,    20,     0,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     7,     8,     0,    80,    81,    82,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
      84,    85,    86,    87,     0,     0,    88,     0,    89,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   107,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   774,    24,    25,   775,
      27,    28,   776,    30,   777,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,     0,     0,    41,     0,     0,
       0,     0,     0,   778,    48,     0,     0,    50,   779,     0,
      53,    54,   780,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,     0,     0,   993,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,    85,    86,    87,     0,
       0,  1909,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,   857,     0,   858,     0,     0,  1527,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,   812,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,   933,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,   934,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,   980,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1025,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1033,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1034,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1035,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1050,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1170,   484,   485,
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
       0,     0,     0,  1266,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1367,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1445,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1446,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1495,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1621,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1622,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1623,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1624,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1625,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1626,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1627,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1744,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1745,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1752,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1899,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1900,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1901,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  1902,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1903,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  1961,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  1962,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  1966,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2043,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2044,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  2045,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2046,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  2047,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2089,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2092,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  2141,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2142,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  2143,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2144,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2145,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,  2146,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2206,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,  2207,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,  2208,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  2209,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   857,     0,
     858,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,   766,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,   986,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,  1005,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,  1012,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,  1113,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,  1163,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,  1189,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,     0,     0,  1259,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,     0,     0,  1260,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,     0,     0,
    1264,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,     0,     0,  1265,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,     0,     0,  1298,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,     0,     0,  1360,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
       0,     0,  1365,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,     0,     0,  1688,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,     0,     0,  1731,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,     0,
       0,  1923,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,   762,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   822,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,   826,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,   827,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,   829,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   831,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   832,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,   834,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
     836,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,   837,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,   838,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   839,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,   840,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,   841,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,   843,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   844,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   845,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,   886,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
     896,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,   957,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,   975,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,   976,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,   977,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,   978,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,   984,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,   985,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,   992,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1001,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1011,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1112,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1140,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1145,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1158,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  1162,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  1188,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,  1193,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,  1194,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1195,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1201,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1210,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1211,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1212,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1245,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  1247,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  1248,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,  1249,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,  1250,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1251,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1252,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1253,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1258,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1359,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  1364,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  1539,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498,     0,  1564,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,     0,     0,     0,     0,   498,     0,  1737,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,     0,     0,     0,     0,   498,     0,  1738,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,   498,     0,  1739,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,     0,     0,     0,   498,     0,
    1740,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,     0,     0,     0,     0,   498,
       0,  1799,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,     0,     0,     0,
     498,     0,  1817,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,     0,     0,     0,
       0,   498,     0,  1840,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
       0,     0,   498,     0,  2088,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,     0,
       0,     0,     0,   498,     0,  2171,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
       0,     0,     0,     0,   498
};

static const yytype_int16 yycheck[] =
{
       3,     3,   314,     6,   329,   436,  1676,   438,     4,     6,
     623,   624,  1699,  1700,  1240,     4,     6,  1244,     4,     4,
       4,   346,   453,     4,     6,     5,     4,     4,    90,     4,
       6,     5,   228,    90,     4,     4,    90,     5,     5,     5,
       5,   132,     6,     4,    47,   225,   226,   469,     5,   471,
       5,   473,     5,     5,   111,     6,     6,   111,     6,  1885,
     385,     7,   387,     4,     6,     4,   122,     6,   393,    13,
       6,     6,    75,    84,     4,     6,    87,   122,     7,    90,
      83,    92,   229,   139,   231,    88,     0,   234,   218,   219,
       6,   147,   148,   149,   139,     6,    99,   153,   154,   155,
     156,  1771,   147,   148,   149,   122,   236,   228,   153,   154,
     155,   156,    84,   228,     7,    87,   122,    99,    90,   101,
      92,   232,   139,     7,     6,     7,   237,     7,   218,   219,
     147,   148,   149,   139,     4,     5,   153,   154,   155,   156,
     169,   147,   148,   149,   234,    84,   236,   153,   154,   155,
     156,     4,     3,   230,    84,     6,   185,   186,    88,   225,
     226,   229,    90,   231,    94,    95,   234,    97,    98,   235,
     159,   160,   161,   162,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    87,     4,   115,    90,    57,    58,    59,
      60,   236,   172,   157,     6,    65,    66,    67,   172,   180,
      70,     7,     6,     7,   172,   208,   172,   209,     7,   184,
    1880,    81,     7,  2039,  2040,     6,   230,   220,   221,   236,
     204,   157,   157,   204,    75,   228,   157,   204,   218,   219,
     236,   228,   104,   236,   230,   238,  1906,    88,   235,   215,
     243,   237,   228,   228,  1470,   248,     6,   236,    99,   235,
     235,   235,   255,   235,   235,   235,   259,   235,   228,   228,
     263,   264,   265,   266,   267,   235,   235,   228,   235,   230,
     235,   232,   694,   215,   696,   278,   237,     6,   235,   282,
     235,   284,   235,   235,   235,   235,   232,   228,     7,   614,
     615,    87,   295,     8,    90,   298,   299,   300,   301,   228,
       6,   230,   218,   219,   307,   308,   309,   218,   219,   634,
     313,   314,   205,   206,   207,   208,   169,   170,   188,   189,
     190,   205,   206,   207,   208,   205,   206,   207,   208,     7,
     229,   201,   231,   203,   204,   234,     7,   340,   341,   342,
     762,   225,   226,     7,   766,   228,   671,   230,   232,   169,
     170,   354,   355,     4,   237,   225,   226,   208,   218,   219,
     228,   686,   232,   218,   219,   235,   228,   235,   230,   220,
     221,   228,   218,   219,   234,   237,   236,   228,   235,   234,
      84,   236,   473,    87,   228,   236,    90,   228,   391,   235,
     229,   235,   395,   396,   235,   234,  2083,   218,   219,   205,
     206,   207,   208,     6,   255,   408,   205,   206,   207,   208,
     205,   206,   207,   208,   235,   228,   267,   230,   228,   401,
     230,  2091,     8,   228,   237,   230,   225,   226,   218,   219,
     225,   226,   237,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     6,   450,   451,   452,
     453,   454,   218,   219,   228,   458,   459,   460,   461,   462,
     463,   235,   465,   314,   218,   219,   229,   218,   219,   235,
     231,   234,   228,   234,   456,   126,   127,   128,   129,   482,
     234,   231,   464,   234,   234,   228,   205,   206,   207,   208,
     141,   220,   221,   144,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   218,   219,
     228,   228,   227,   230,   218,   219,    84,   520,   228,    87,
     237,   236,    90,   228,   228,   235,   255,   205,   206,   207,
     208,   235,  2202,     8,   205,   206,   207,   208,   267,   228,
     391,   205,   206,   207,   208,   228,   228,   225,   226,   218,
     219,   218,   219,   556,   557,   218,   219,   560,   228,   218,
     219,   225,   226,   225,   226,   234,    90,   234,   571,     6,
     232,   234,   229,   576,   577,   234,   229,   234,   231,  1001,
     228,   584,   235,  1005,     6,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   228,   447,   448,   228,   450,
     451,   452,   453,   454,   929,   608,   609,   458,   459,   460,
     461,   462,   463,   228,   465,   706,   598,   599,   600,   601,
     228,   623,   624,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    90,   228,    92,
     230,   227,   218,   219,   218,   219,    87,   218,   219,    90,
     236,    92,   655,   656,   657,   122,   225,   226,   234,   234,
     234,   236,   391,   234,   225,   226,   235,   218,   219,   218,
     219,   762,   139,   228,   235,   766,   679,   218,   219,   229,
     147,   148,   149,   234,   234,   234,   153,   154,   155,   156,
    1917,   235,  1919,   234,  1921,   229,   699,   225,   226,   228,
     234,   218,   219,   228,   218,   219,   557,   235,   437,   560,
     439,   440,   441,   442,   443,   444,   445,   234,   447,   448,
     234,   450,   451,   452,   234,   454,   236,   235,    90,   458,
     459,   460,   461,   462,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   218,   219,
      92,   229,   227,   231,   229,   218,   219,   235,   761,   218,
     219,   234,   765,   236,   234,   856,     6,   218,   219,   236,
     228,   234,   229,  1999,  1086,   234,  2002,   234,    87,  2005,
    1202,   235,  1204,   234,  1206,   767,  1208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   122,   225,   226,   807,   227,   218,   219,   811,   218,
     219,   814,   235,   228,   817,   228,   819,   230,   139,   232,
     823,   824,   234,    90,   237,   234,   147,   148,   149,   235,
      87,   560,   153,   154,   155,   156,   234,   122,   236,   821,
      87,   218,   219,   218,   219,  2072,   220,   221,   222,   218,
     219,   218,   219,   227,   139,    90,   859,   234,   861,   234,
       4,   864,   147,   148,   149,   234,     4,   234,   153,   154,
     155,   156,   218,   219,   877,   234,   879,   236,   881,   234,
     883,   236,   218,   219,   218,   219,   889,     4,   234,  1320,
    1321,   894,   218,   219,  1325,  1326,  2122,     6,   234,   902,
     234,     4,   225,   226,    87,     6,  1328,    90,   234,    92,
    1001,   122,   235,   229,  1005,   236,     6,   234,   234,   236,
    1011,  1012,  2149,   926,  2151,   228,  2153,  1349,   139,   228,
     228,   228,  2159,   230,   228,   232,   147,   148,   149,   229,
     237,   231,   153,   154,   155,   156,   218,   219,   220,   221,
     222,   236,   225,   226,   228,   227,  2182,     6,   231,  2185,
       6,   230,  2188,   814,   228,  2191,   817,   230,   819,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   126,   127,   228,  2213,   227,  2215,   132,
    2217,   228,   234,   996,   236,   228,   228,  1000,   230,   228,
     232,  1004,   229,   235,   231,   237,  2232,   234,  2234,  1012,
    2236,     6,   126,   127,    87,   228,     7,    90,   132,    92,
     228,  1112,  1113,  1335,   229,   236,   231,   230,   229,   234,
     231,   228,   228,   234,  1037,   234,   234,   236,   236,  1042,
    1653,  1654,   228,   235,  1047,  1048,  1049,  1050,   229,   234,
     231,   236,   234,   234,   236,   228,   234,  1060,   236,  1062,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,  1162,  1163,   235,   235,   227,  1507,  1508,   234,     6,
     236,  1512,  1513,  1086,     6,   814,  1089,  1090,  1091,  1092,
     819,    90,   234,    92,   236,  1517,   228,  1188,  1189,   228,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   235,   234,  1119,   236,   227,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     6,   228,  1138,  1139,   227,  1141,   111,
    1143,  1144,    90,  1146,    92,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,   234,     6,   236,  1160,   234,   228,
     236,  1012,   228,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,  1502,   234,  1504,
     236,   227,  1185,   234,   234,   236,   236,   235,  1191,  1192,
     234,  1042,   236,     6,   234,   228,   236,  1048,  1049,  1050,
     234,   228,   236,   238,   234,   234,   236,   236,   243,  1060,
     234,  1062,   236,   248,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   263,   234,
     228,   236,   227,   235,   234,  1086,   236,  1328,   264,   265,
     266,   234,   234,   236,   236,   228,  1558,   282,   234,   284,
     236,  1254,     7,     8,   234,   234,   236,   236,   228,     4,
     295,     6,     4,   228,  1267,  1268,  1269,   235,  1119,   122,
     234,   230,   236,   299,   300,   301,   234,   234,   236,   236,
    1283,   235,   234,  1012,   236,     6,   139,   234,   234,   236,
     236,   234,   228,   236,   147,   148,   149,   235,   235,  1912,
     153,   154,   155,   156,   234,   234,   236,   236,   234,   234,
     236,   236,   235,  1042,   340,   341,   228,  1320,  1321,  1048,
    1049,  1050,  1325,  1326,   234,   234,   236,   236,   354,   355,
     228,  1060,  1335,  1062,   228,   228,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     234,  1354,   236,   234,   227,   236,   228,   228,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   234,   237,   236,  1378,   227,     6,   234,     6,
     236,  1384,   234,   236,   236,   234,  1368,   236,     6,   234,
    1119,   236,   234,   230,   236,  1398,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     234,   234,   236,   236,   227,   234,   230,   236,  1421,  1422,
    1423,     7,   230,   235,  1427,  1428,   235,  1430,  1519,  1432,
    1861,  1434,   235,  1436,  1437,  1438,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     6,   234,   482,   236,   227,
     234,     6,   236,  1456,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,  1471,  1320,
    1321,   234,   227,   236,  1325,  1326,  1479,   235,   234,  1482,
     236,   234,   172,   236,  1335,   520,   237,     6,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,     6,   235,  1507,  1508,   227,     6,     6,  1512,
    1513,   235,   235,     6,   230,     4,   227,   232,   235,  1501,
       7,   556,   557,  1526,   236,   234,  1617,   234,   229,  1532,
       7,   122,     6,     6,     6,   229,     4,    62,    62,    62,
      62,   576,   577,     7,     7,     6,     6,     6,   139,   584,
       6,   229,     6,   235,     6,  1558,   147,   148,   149,  1871,
       7,     7,   153,   154,   155,   156,  1569,     6,  1550,     6,
       6,   169,   235,   608,   609,   231,  1579,   229,   122,  1582,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     6,   139,     6,   229,   227,   229,
    1582,   234,  1927,   147,   148,   149,   234,   229,   234,   153,
     154,   155,   156,   234,   234,   234,   229,   234,   229,   231,
     655,   656,   657,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    44,    44,    44,
      44,   227,  1645,  1646,   679,   236,     6,     4,   228,     4,
       6,  1653,  1654,     6,     6,     6,  1507,  1508,     7,   172,
       7,  1512,  1513,     7,   699,     7,   172,  1649,     7,   122,
       7,     7,   172,  1676,     7,  1526,     7,     7,     7,  1682,
       7,  1532,     7,     7,     7,     7,   139,   235,  1691,     6,
     229,   231,   236,   122,   147,   148,   149,   235,  1701,  2024,
     153,   154,   155,   156,   235,   235,   122,  1558,  1711,   235,
     139,     7,     7,  1716,   235,  1697,     4,     6,   147,   148,
     149,   229,   234,   139,   153,   154,   155,   156,  1579,   234,
     232,   147,   148,   149,  1716,  1717,  1718,   153,   154,   155,
     156,   229,   234,  1746,   229,   229,   236,   122,  2073,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   234,     7,     6,   236,   227,  1771,     7,
       7,     7,   807,     7,   232,     6,   811,    44,    44,   236,
     235,    44,    44,   236,     6,     6,     6,     6,   823,   824,
       6,   235,     7,     6,   228,   230,   228,  1526,   228,     6,
     228,   228,   228,  1532,   215,     7,     7,   236,    92,     7,
       7,     7,     7,  1816,     7,     6,   102,     7,     7,     7,
     236,     7,     7,     7,   859,  1828,   861,     6,     4,   864,
       4,     6,   235,   228,     7,     6,   235,     7,  1841,     7,
       7,     7,   877,     7,   879,     7,   881,     7,   883,     6,
    1579,     6,     6,     6,   889,  1858,     7,    90,  1861,   894,
       6,     4,  1844,     4,     4,   234,   236,   235,  1871,   235,
       6,     6,     6,     6,     6,     4,     6,  1880,     6,   229,
     234,     7,     6,   229,  1887,  1888,   234,   232,   228,   232,
     231,   926,    61,    62,     6,    64,     6,   235,     6,     6,
     235,   229,     6,  1906,   115,     6,  1909,   172,     6,   235,
    1912,     6,     6,     6,   235,   235,   235,     6,     6,     6,
       6,     6,     5,  1926,     4,   229,   231,  1930,     6,     6,
       4,     6,   235,   235,     7,   235,   235,   235,     3,     4,
     230,   235,     6,     6,     9,    10,    11,     6,     6,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     6,     6,   235,   235,   235,   235,   235,   235,
       6,   168,     6,   234,     6,  1988,     4,     6,    53,    54,
      55,    56,     6,     6,     6,     4,    61,     7,     6,     6,
       6,     6,  1037,     6,  2007,     4,     7,    72,    73,    74,
    1861,     6,     6,     6,     6,    80,    88,     6,     5,     7,
    1871,     6,     6,   235,     6,   235,  2029,     6,     6,     6,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     6,     6,  2028,     6,   227,     6,
       6,     6,     6,     6,  1089,  1090,  1091,  1092,     6,     6,
       6,     6,   234,     6,     6,     6,   229,     6,     6,   234,
       6,     6,  2075,  2076,  2077,  2078,  2079,     6,     6,   235,
     232,     6,     6,     5,     7,   235,   235,   235,  2091,     6,
     235,     6,   236,   235,     6,   107,   235,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   236,   235,   235,   235,   227,     6,   167,     6,   236,
     236,   236,   187,     6,     6,  1160,   191,     6,     8,     6,
       6,   196,   197,   198,   199,   200,     6,     6,   170,   204,
       6,     6,     6,     6,     6,     6,     6,   229,   317,   318,
    2132,   235,     6,   218,   219,     7,   325,  1192,   223,     6,
     329,  2164,     6,   228,   235,   235,   235,  2170,   233,   235,
     235,     6,     6,   122,   236,   235,     6,     6,  2029,     6,
       6,     6,     6,     6,     6,     6,     6,   236,     6,   228,
     202,   203,   204,   205,   206,   235,     6,   235,   235,  2202,
     236,   229,     6,     6,   235,     6,     6,   219,     6,     6,
       6,   223,     6,     6,     6,   235,     6,  2220,   235,  2222,
     235,     6,     6,     6,   235,   237,   238,   239,   240,     6,
     242,   243,   244,   245,     6,   247,   248,   249,   250,   251,
     252,   253,   254,     6,   256,   257,   258,     6,     6,  2252,
       6,   263,   235,     6,     6,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     6,
     282,   283,   284,   227,     6,  1363,   516,  2032,  1377,  1886,
    1633,     3,   294,   295,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,     3,   311,
       3,     3,   227,   596,  1908,  1554,    -1,    -1,   320,   321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   329,   238,  2170,
      -1,    -1,    -1,   243,    -1,    -1,    -1,   339,   248,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   263,    -1,    -1,    -1,   227,   360,    -1,
      -1,    -1,   364,   365,   366,    -1,   368,    -1,    -1,    -1,
     372,   373,   374,    -1,    -1,   377,    -1,    -1,    -1,  2220,
      -1,  2222,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,   397,   398,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,
     412,  2252,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,   449,    -1,    -1,
     227,  2170,    -1,   455,    -1,   457,    -1,  1482,    -1,    -1,
      -1,    -1,   621,   622,    -1,    -1,    -1,    -1,    -1,    -1,
     629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,
     482,    -1,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,    -1,    -1,   501,
     502,  2220,    -1,  2222,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   520,    -1,
      -1,    -1,   227,    -1,   526,    -1,    -1,    -1,    -1,   531,
      -1,   236,    -1,  2252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,   546,    -1,     6,    -1,    -1,    -1,
     552,   553,    -1,    -1,   556,   557,   558,   559,    -1,   561,
      -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   482,    -1,   576,   577,    -1,    -1,    -1,    -1,
      -1,   583,   584,   585,   586,    -1,    -1,    -1,   590,   591,
     592,    -1,    -1,    -1,    -1,   597,   598,   599,   600,   601,
     602,    -1,   604,    -1,   606,    -1,   608,   609,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1645,  1646,    -1,    -1,   626,   627,   628,   629,   630,   631,
      -1,    -1,    -1,   635,   636,   637,   638,   639,   640,   641,
     642,   643,    -1,    -1,    -1,    -1,   648,    -1,   650,   651,
      -1,    -1,    -1,   655,   656,   657,    -1,  1682,   660,   661,
     662,    -1,    -1,    -1,     4,     5,    -1,   577,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,
      -1,    -1,   684,   685,    -1,   687,   688,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   698,   699,   608,   609,
      -1,   703,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,   655,   656,   657,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,   768,   227,    -1,   679,
      -1,    -1,    -1,   932,    -1,    -1,    -1,    -1,    -1,    -1,
     939,    -1,    -1,    -1,    -1,    -1,    -1,   946,    -1,   699,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   803,   804,  1828,    -1,   807,   808,   809,    -1,   811,
     812,    -1,    -1,    -1,    -1,    -1,  1841,    -1,   820,    -1,
     122,   823,   824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1858,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   846,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   859,    -1,   861,
      -1,   201,   864,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   877,    -1,   879,    -1,   881,
      -1,   883,    -1,    -1,  1909,    -1,    -1,   889,    -1,   229,
      -1,   231,   894,    -1,    -1,    -1,    -1,   807,    -1,   901,
      -1,   811,    -1,    -1,    -1,  1930,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    12,    13,   926,   227,    -1,    -1,    -1,    -1,
      -1,   933,   934,    -1,    -1,    -1,    -1,   939,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   859,
      -1,   861,    -1,    -1,   864,    -1,   958,    -1,    -1,   961,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,    -1,   879,
      -1,   881,    -1,   883,    -1,  1134,    -1,    -1,   980,   889,
     982,   983,    -1,    -1,   894,    -1,    -1,    -1,    -1,    -1,
      -1,   993,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    47,    -1,
     100,   101,   102,    -1,    -1,   105,   926,    -1,    -1,    -1,
      -1,   111,   112,  1025,    -1,   115,   116,    -1,   118,   119,
     120,  1033,  1034,  1035,   124,  1037,    -1,    -1,    -1,    -1,
      -1,    12,    13,  1045,    -1,    -1,    -1,    -1,   138,    -1,
    2075,  2076,  2077,  2078,  2079,    -1,    -1,  1059,    -1,    -1,
      -1,    -1,  1064,    -1,    -1,    -1,    -1,    -1,  1227,  1228,
    1229,  1073,    -1,    -1,   164,   165,   166,  1079,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1089,  1090,  1091,
    1092,  1093,    -1,    -1,    -1,    -1,    -1,    -1,  1100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,  1037,    -1,   100,
     101,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,  2164,
     111,   112,    -1,    -1,   115,   116,   236,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,  1160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,  1170,  1171,
      -1,  1173,  1174,    -1,  1176,  1177,  1178,    -1,    -1,  1089,
    1090,  1091,  1092,    -1,  1186,    -1,    -1,    -1,    -1,    -1,
    1192,    -1,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,  1203,    -1,  1205,    -1,  1207,    -1,  1209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,
      -1,    -1,    -1,    -1,  1266,   236,    -1,    -1,   307,   308,
     309,    -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1192,    -1,    -1,    -1,    -1,  1289,    -1,    -1,
      -1,    -1,  1294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   342,    -1,    12,    13,    -1,    -1,    -1,
    1469,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,     8,    -1,  1336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1345,  1346,  1347,  1348,    -1,    -1,    -1,
    1352,  1353,     8,    -1,    -1,    -1,   395,   396,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1367,  1368,    -1,    -1,   408,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,   446,   115,   116,
      -1,   118,   119,   120,    -1,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,  1592,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1444,  1445,  1446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1456,    -1,  1458,   164,   165,   166,
       8,    -1,    -1,    -1,    -1,    -1,    -1,  1469,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1482,    -1,    -1,    -1,    -1,  1487,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1495,  1496,  1497,  1655,     8,  1657,    -1,
    1659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,  1678,
    1679,  1680,  1681,  1682,    -1,  1527,    -1,    -1,    -1,   236,
      -1,    -1,   571,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,  1551,
      -1,   227,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,  1570,    -1,
      -1,   227,  1482,  1575,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,  1590,  1591,
      -1,    -1,   227,    -1,    -1,  1597,  1598,    -1,    -1,    -1,
      -1,    -1,  1604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,
    1622,  1623,  1624,  1625,  1626,  1627,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1635,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1645,  1646,  1647,    -1,  1649,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1661,
    1662,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
    1682,    -1,    -1,    -1,  1686,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1697,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,  1717,   227,    -1,    -1,    -1,
      -1,    -1,   761,    -1,    -1,    -1,   765,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1645,  1646,    -1,     4,     5,
      -1,    -1,  1744,  1745,    -1,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,  1916,    -1,  1918,
      -1,  1920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1931,  1932,  1933,  1934,  1935,  1779,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,  1800,    65,
      66,    67,    -1,    -1,    70,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,  1819,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1828,    -1,  1987,    -1,
      -1,    -1,  1991,    -1,  1836,    -1,  1838,    -1,    -1,  1841,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,  1858,    -1,    -1,    57,
      58,    59,    60,   902,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,  1876,    -1,    -1,    -1,    -1,  1881,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
    2049,  1893,    -1,    -1,  2053,    -1,    -1,  1899,  1900,  1901,
    1902,  1903,    -1,    -1,    -1,    -1,    -1,  1909,    -1,    -1,
      -1,    -1,    -1,    -1,  1916,    -1,  1918,    -1,  1920,    -1,
    2079,    -1,   188,   189,   190,    -1,    -1,    -1,  1930,    -1,
      -1,  1841,    -1,    -1,    -1,   201,  1938,   203,   204,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,   996,   227,  1961,
    1962,  1000,    -1,    -1,  1966,  1004,    -1,   236,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,  2147,  2148,
     188,   189,   190,  1995,   234,    -1,   236,    -1,    -1,  1909,
      -1,    -1,    -1,   201,    -1,   203,   204,    -1,  1047,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1930,    -1,    -1,    -1,  2026,    -1,    -1,    -1,    -1,    -1,
    2032,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2042,  2043,  2044,  2045,  2046,  2047,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2060,    -1,
      -1,  2063,    -1,    -1,  2066,    -1,    -1,    -1,  2070,    -1,
      -1,    -1,    -1,  2075,  2076,  2077,  2078,  2079,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2089,    -1,    -1,
    2092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1138,
    1139,    -1,  1141,    -1,  1143,  1144,    -1,  1146,    -1,  1148,
    1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,  2141,
    2142,  2143,  2144,  2145,  2146,   234,  1185,   236,    -1,    -1,
      -1,    -1,  1191,   587,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2164,    -1,    -1,  2075,  2076,  2077,  2078,  2079,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,  2206,  2207,  2208,  2209,  2210,  2211,
     234,    -1,   236,    -1,    -1,  1254,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,  1267,  1268,
    1269,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,  1283,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2164,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   707,   708,   709,   710,   711,   712,   713,
     714,   715,   716,   717,    -1,   719,   720,   721,   722,   723,
     724,   725,    -1,    -1,    -1,   729,   730,   731,    -1,    -1,
      -1,   735,   736,    -1,   738,    -1,    -1,    -1,    -1,   743,
     744,   745,    -1,   747,    -1,  1354,    -1,    -1,    -1,    -1,
     754,   755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,   772,  1378,
      -1,    -1,    -1,    -1,    -1,  1384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1398,
      -1,    -1,    -1,   188,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,   203,    -1,
      -1,    -1,  1421,  1422,  1423,    -1,    -1,    -1,  1427,  1428,
      -1,  1430,    -1,  1432,    -1,  1434,    -1,  1436,  1437,  1438,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,  1456,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,  1471,    -1,    -1,   869,    -1,    -1,    -1,    -1,
    1479,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     884,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,   168,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
      -1,    -1,   181,    -1,    -1,     3,     4,    -1,   187,   188,
      -1,     9,    10,    11,   193,   194,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
    1569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1582,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,   268,
      -1,   270,   271,   272,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,   292,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,  1691,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,  1701,    12,    13,  1099,    -1,    72,    73,    74,
      -1,    -1,  1711,    -1,    -1,    80,    -1,  1716,    -1,   187,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,   197,
     198,   199,   200,    -1,    -1,    -1,   204,    -1,  1132,  1133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1746,    -1,    -1,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,   233,    -1,   235,    -1,    -1,
      -1,    -1,  1771,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,  1816,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   476,    -1,   138,
      -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,   164,   165,   166,   223,    -1,
      -1,    -1,    -1,   228,   229,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1880,    -1,    -1,    -1,    -1,    -1,    -1,  1887,  1888,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1297,    -1,    -1,    -1,  1906,    -1,  1303,
    1304,  1305,  1306,  1307,    -1,  1309,    -1,  1311,  1312,    -1,
    1314,  1315,    -1,    -1,  1318,  1319,  1320,  1926,     3,     4,
      -1,  1325,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    53,    54,
      55,    56,   227,    -1,    -1,    -1,    61,    -1,    -1,  1988,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,  1401,  2007,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,  1418,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,  2091,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,  1507,    -1,    -1,   191,    -1,  1512,    -1,
       5,   196,   197,   198,   199,   200,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,
    1544,  1545,    -1,   228,  1548,  1549,   231,    -1,   233,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,   180,    -1,    -1,
      -1,    -1,    -1,  2202,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,   197,   198,   199,   200,   201,    -1,
     203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,   228,    -1,   230,    -1,   232,
     233,    -1,   235,    -1,   237,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   188,   189,   190,    -1,    -1,    -1,   235,
    1704,  1705,    -1,    -1,  1708,  1709,   201,    -1,   203,    -1,
    1714,  1715,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,  1772,  1773,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    12,    13,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
    1069,  1070,    -1,    -1,    -1,    -1,  1075,  1076,    -1,    -1,
     111,    -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
     141,    -1,    -1,   144,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,   115,
     116,    -1,   118,   119,   120,    -1,   187,    -1,   124,    -1,
     191,   192,    -1,    -1,    -1,   196,   197,   198,   199,   200,
      -1,    -1,   138,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,   228,   164,   165,
     166,    -1,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
     236,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,  1286,  1287,    -1,
      80,    -1,  1291,  1292,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,   113,    -1,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,   141,    -1,    -1,   144,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,   191,   192,    -1,    -1,    -1,   196,   197,   198,   199,
     200,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
      -1,  2175,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,   236,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,   141,    -1,    -1,   144,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
     196,   197,   198,   199,   200,   201,    -1,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,   228,    -1,     3,     4,     5,   233,    -1,   235,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,   113,    -1,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,   141,    -1,    -1,   144,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,   196,   197,   198,
     199,   200,   201,    -1,   203,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,
     219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   228,
      -1,     3,     4,     5,   233,    -1,   235,     9,    10,    11,
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
      -1,    -1,   144,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,   228,    -1,     3,     4,
       5,   233,    -1,   235,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,   141,    -1,    -1,   144,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   192,    -1,    -1,
      -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,   228,    -1,     3,     4,    -1,   233,    -1,
     235,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,   141,    -1,    -1,   144,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   196,   197,
     198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
     228,    -1,     3,     4,    -1,   233,    -1,   235,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
     141,    -1,    -1,   144,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,   192,    -1,    -1,    -1,   196,   197,   198,   199,   200,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,     3,
       4,    -1,   233,    -1,   235,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,
      -1,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,   141,    -1,    -1,
     144,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   192,    -1,
      -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,   228,    -1,     3,     4,    -1,   233,
      -1,   235,     9,    10,    11,    -1,    -1,    14,    15,    16,
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
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,     3,     4,    -1,   233,    -1,   235,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,   113,    -1,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,   141,    -1,    -1,   144,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,   191,   192,    -1,    -1,    -1,   196,   197,   198,   199,
     200,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,
       3,     4,    -1,   233,    -1,   235,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,   141,    -1,
      -1,   144,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   192,
      -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,   228,    -1,     3,     4,    -1,
     233,    -1,   235,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,   141,    -1,    -1,   144,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,
     196,   197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,   228,    -1,     3,     4,    -1,   233,    -1,   235,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,   113,    -1,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,   141,    -1,    -1,   144,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,   191,   192,    -1,    -1,    -1,   196,   197,   198,
     199,   200,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,
     219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   228,
      -1,     3,     4,    -1,   233,    -1,   235,     9,    10,    11,
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
      -1,    -1,   144,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,   228,    -1,     3,     4,
      -1,   233,    -1,   235,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,   141,    -1,    -1,   144,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   192,    -1,    -1,
      -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,   228,    -1,     3,     4,    -1,   233,    -1,
     235,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,   141,    -1,    -1,   144,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   196,   197,
     198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
     228,    -1,     3,     4,    -1,   233,    -1,   235,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,   113,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
     141,    -1,    -1,   144,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,   192,    -1,    -1,    -1,   196,   197,   198,   199,   200,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,     3,
       4,     5,   233,    -1,   235,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,     3,     4,     5,    -1,    80,    81,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,   197,   198,   199,   200,   201,    -1,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   233,
      -1,   235,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   187,   188,   189,   190,
     191,   236,    -1,    -1,    -1,   196,   197,   198,   199,   200,
     201,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,     3,
       4,     5,   233,    -1,   235,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   236,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    53,    54,    55,    56,   227,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,   197,   198,   199,   200,   201,    -1,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,   228,    -1,     3,     4,    -1,   233,
      -1,   235,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   191,    -1,    72,    73,    74,   196,   197,
     198,   199,   200,    80,    -1,    -1,   204,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
     218,   219,    99,    -1,    -1,   223,    -1,    -1,    -1,    -1,
     228,   229,    -1,    -1,   111,   233,   113,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,   141,    -1,    -1,   144,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,     3,     4,     5,
      -1,   228,    -1,     9,    10,    11,   233,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
       3,     4,    -1,    -1,    80,    81,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      53,    54,    55,    56,   227,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,   197,   198,   199,   200,   201,    -1,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,   233,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   236,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,   228,     3,     4,   231,     6,
     233,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    53,    54,    55,    56,
     227,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,
      -1,     6,    -1,    80,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    53,    54,
      55,    56,   227,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,   233,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,   236,    -1,   191,    -1,    -1,    -1,
      -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,     3,
       4,    -1,    -1,   228,    -1,     9,    10,    11,   233,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,   115,
     116,    -1,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,   138,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,   187,   227,    -1,   229,   191,   164,   165,
     166,   234,   196,   197,   198,   199,   200,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,    12,    13,    -1,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   233,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,
     236,   115,   116,    -1,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     164,   165,   166,    -1,    -1,   111,   112,    -1,    -1,   115,
     116,    -1,   118,   119,   120,    -1,    -1,    -1,   124,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,    -1,    -1,   164,   165,
     166,   111,   112,    -1,    -1,   115,   116,    -1,   118,   119,
     120,    -1,   236,    -1,   124,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,    -1,   164,   165,   166,    -1,   111,   112,
      -1,    -1,   115,   116,    -1,   118,   119,   120,    -1,    -1,
     236,   124,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,    -1,
      -1,   164,   165,   166,   111,   112,    -1,    -1,   115,   116,
      -1,   118,   119,   120,    -1,    -1,   236,   124,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,    -1,   164,   165,   166,
      -1,   111,   112,    -1,    -1,   115,   116,    -1,   118,   119,
     120,    -1,    -1,   236,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,    -1,    -1,   164,   165,   166,   111,   112,    -1,
      -1,   115,   116,    -1,   118,   119,   120,    -1,    -1,   236,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     164,   165,   166,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      42,    43,   235,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    -1,    71,
      -1,    -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,   101,
     102,   103,   236,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,   150,   151,
     152,     4,    -1,    -1,    -1,    -1,   158,    -1,    -1,    12,
      13,   163,   164,   165,   166,    -1,    -1,   169,    -1,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,    42,
      43,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,   101,   102,
     103,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    12,    13,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,    -1,    -1,   169,    -1,   171,    -1,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,   142,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,   164,   165,   166,    -1,
      -1,   235,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,    -1,   231,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,    -1,
     231,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,   231,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   231,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,   231,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   231,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   231,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
     231,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   231,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,   231,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,   231,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   231,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,   231,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
     229,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
     229,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
     229,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
     229,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
     229,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
     229,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,   229,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,   229,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   239,   240,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     103,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     115,   116,   117,   118,   119,   120,   121,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     150,   151,   152,   158,   163,   164,   165,   166,   169,   171,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   193,   194,   195,   202,   204,   241,
     243,   244,   264,   283,   284,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   311,   313,   314,   320,   321,   322,
     323,   341,   342,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      65,    66,    67,    70,    72,    73,    74,    80,    81,   180,
     187,   188,   189,   190,   191,   196,   197,   198,   199,   200,
     201,   203,   218,   219,   223,   228,   230,   232,   233,   235,
     237,   262,   324,   325,   337,   338,   341,   342,    13,    90,
     228,   228,     6,   235,     6,     6,     6,     6,   228,     6,
       6,   230,   230,   228,   230,   262,   262,   228,   235,   228,
     228,     4,   228,   235,   228,   228,     4,   228,   235,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   104,
      90,    90,     6,   235,    84,    87,    90,   228,     4,    37,
      38,    39,    40,    41,    84,    87,    90,    92,   111,   116,
     119,   192,   219,   228,   235,   284,   295,   311,   313,   324,
     330,   332,   341,   342,   228,   235,    90,    90,   111,    87,
      90,    92,    92,    84,    87,    90,    92,    87,    90,    92,
      87,    90,   228,    87,   169,   185,   186,   235,   218,   219,
     228,   235,   327,   328,   327,   235,    84,    87,    90,   235,
     327,     4,    84,    88,    94,    95,    97,    98,   115,   228,
      90,    92,    90,    87,     4,   180,   235,   341,   342,     4,
       6,    84,    87,    90,    87,    90,     4,     4,     4,     5,
     228,   330,   331,     4,   228,   228,   228,     4,   235,   334,
     342,     4,   228,   228,   228,     6,     6,   230,     4,   338,
     342,   228,     4,   338,     5,   235,     5,   235,     4,   324,
     341,   230,   228,   235,     6,   228,   235,   228,   230,   237,
     262,     7,   205,   206,   207,   208,   225,   226,   260,   261,
       4,   228,   230,   232,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   228,
     228,   228,   262,   262,   262,   262,   228,   262,   262,   262,
     262,   262,   262,   228,   262,   262,   262,     7,   228,   228,
     228,   262,   262,   228,   228,   230,   324,   324,   324,   229,
     324,   231,   324,     4,   169,   170,   342,     4,   284,   285,
     286,   235,   235,     6,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   227,   235,
       6,   228,   230,   261,     6,   324,     4,   337,   338,   341,
     342,   337,   324,   337,   340,   266,   271,   338,   342,   324,
     219,   324,   332,   333,   324,   324,   228,   324,   333,   324,
     324,   228,   324,   333,   324,   324,   324,   324,   324,   324,
     337,   324,   324,   324,   330,   228,   235,   333,   331,   331,
     331,   337,   228,   230,   232,   262,   228,   230,   262,   262,
     262,   262,     5,   172,   235,     5,   172,     5,   172,     5,
     172,   111,    84,    87,    90,    92,   262,   235,   324,   332,
     324,   236,   333,     8,   220,   228,   230,   262,   324,   333,
     228,   228,   228,   330,   331,   331,   331,   228,   228,   228,
     228,   228,   228,   330,   228,   330,   228,   330,   235,   235,
     324,     4,   330,   334,   235,   235,   327,   327,   327,   324,
     324,   218,   219,   235,   235,   327,   235,   235,   235,   218,
     219,   228,   286,   327,   235,   228,   235,   228,   228,   228,
     228,   228,   228,   228,   324,   331,   331,   330,   228,     4,
     230,   230,   286,     6,     6,   235,   235,   235,   331,   331,
     230,   230,   230,   324,     6,     6,   324,   324,   324,   232,
     324,   235,   172,   324,   324,   324,   324,     6,     6,   235,
       6,   286,     6,   286,   228,   230,   235,   228,   230,   337,
     324,   286,   330,   330,   229,   324,   231,   324,   235,   235,
     338,   330,     6,   230,   324,   324,     4,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   340,
     337,   340,   337,   337,   337,   337,   337,   337,   337,   330,
     337,   337,   324,   337,   337,   337,   340,   337,   324,   338,
     324,   337,   337,   337,   337,   337,   342,   338,   342,     7,
     208,   260,   229,     7,   208,   260,   231,     7,   260,   261,
     232,     7,   262,   236,    84,    87,    90,    92,   111,   116,
     120,   283,   324,   333,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   245,
     324,   324,     6,   228,   230,   232,   229,   234,   228,   230,
     229,   234,   234,   229,   234,   231,   234,   265,   231,   265,
     234,   234,   229,   220,   234,   236,   229,   229,   324,   229,
     236,   229,   229,   324,   229,   236,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,     7,   324,   324,   236,
       6,     6,     6,   229,   324,   324,     4,   229,   231,   235,
     263,   235,   324,   332,   235,   332,   342,   324,   324,   337,
     324,    62,   324,    62,    62,    62,     5,   235,     5,   235,
       5,   235,     5,   235,   332,   333,   229,   236,   324,   235,
     324,   332,   324,   324,   235,   263,   229,   236,   324,   324,
     324,     7,     7,   317,   317,   324,   277,   324,   338,   278,
     324,   338,   279,   324,   338,   280,   324,   338,   324,     6,
     324,     6,   324,     6,   333,   333,   235,   229,     6,   235,
     286,   286,   234,   234,   234,   327,   327,   285,   285,   234,
     324,   324,   324,   324,   236,   299,   234,   286,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   229,     7,   318,
       6,     7,   324,     6,   324,   324,   236,   333,   333,   333,
       6,     6,   324,   324,   324,   229,   229,   229,   229,   169,
     234,   286,   235,     8,   229,   229,   231,   333,   236,   236,
     286,   231,   229,   142,   312,   229,   234,   236,     7,   208,
     260,   229,     7,   208,   260,   231,   324,   333,     6,     6,
     324,   229,   231,   261,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   234,   263,   263,   263,   263,
     263,   263,   263,   234,   234,   234,   263,   234,   263,   263,
     229,   229,   234,   263,   263,   234,   263,   234,   234,   234,
     234,   263,   263,   263,   229,   263,   326,   339,     6,   234,
     234,   229,   234,   263,   234,   263,   229,   229,   231,    44,
      44,   330,     7,   260,   261,    44,    44,   330,   232,   260,
     261,   338,   324,     6,     4,     4,   235,   335,   263,   235,
     235,   235,   235,   228,   111,    87,    90,    92,   236,   236,
       8,     4,   159,   160,   161,   162,   236,   248,   252,   255,
     257,   258,   229,   231,   324,   324,     4,     6,   215,   242,
     333,   324,   324,     6,   333,   324,     6,   337,     6,   342,
       6,   337,   324,   338,     7,   324,   332,   172,     7,     7,
     229,     7,   172,     7,     7,   229,     7,   172,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   324,   229,   236,
     235,     6,   229,   231,   333,   333,   229,   333,   231,   231,
     234,   234,   263,   234,   235,   236,   235,   235,   235,   333,
     333,   333,   333,   263,   236,     7,     8,   333,   229,   231,
     333,     7,   235,   229,   229,   229,   324,   330,     4,   316,
       6,   229,   229,   234,   229,   234,   229,   234,   229,   234,
     229,   229,   229,   236,   236,   333,   232,   286,   236,   236,
     327,   324,   324,   236,   236,   324,   327,   234,   234,   234,
     122,   122,   139,   147,   148,   149,   153,   154,   155,   156,
     309,   310,   327,   236,   296,   229,   236,   229,   229,   229,
     229,   229,   229,   229,     7,   324,     6,   324,   229,   231,
     231,   236,   236,   236,   231,   231,   234,     7,     7,     7,
     232,   324,   236,   324,   324,     7,   232,   236,   236,     7,
       6,   324,   236,   235,   330,     6,    44,    44,   330,   260,
     261,    44,    44,   330,   260,   261,   236,   236,   231,   261,
     232,   261,   337,   324,   324,   324,   324,   333,   337,   324,
     330,   337,   337,   337,   273,   275,   324,   337,   337,   324,
     262,   262,     6,   324,     6,   262,   262,     6,     4,   169,
     170,   324,     6,     6,     6,     7,   230,   334,   336,     6,
     333,   333,   333,   333,   324,   228,   228,   228,   228,   263,
     324,   249,   228,   228,   235,   259,     6,   261,   261,   229,
     231,   215,   337,   229,   229,   231,   229,   234,     7,   228,
     230,   263,   263,   327,    90,    92,   330,   330,     7,   330,
      90,    92,   330,   330,     7,   330,    92,   330,   330,   330,
     330,   330,   330,   330,   330,   330,     6,     7,     7,   333,
     232,   236,   236,   236,   324,   324,   324,   324,   324,   324,
     324,   236,   236,   236,   236,   330,   324,   236,   236,   330,
     333,     7,     7,     7,   122,   315,     6,     7,   260,   324,
     260,   324,   260,   324,   260,   324,     7,     7,     7,     7,
       7,   236,     4,   236,   234,   234,   234,   236,   236,   327,
     327,   327,   102,     4,     6,   324,   235,     6,   228,     6,
     157,     6,   157,     6,   157,     6,   157,   236,   310,   234,
     309,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     330,     6,   235,     6,     6,     6,    90,     7,     6,     6,
     324,   330,   330,   330,     4,   234,     8,     8,   229,     4,
       4,   234,   235,     6,   235,   330,   236,   262,   262,     6,
     324,     6,   262,   262,     6,   324,     6,   263,     6,     4,
       6,   263,   263,   263,   263,   263,   234,   234,   263,   229,
     263,   263,   234,   234,   263,   274,   234,   263,   276,   229,
     229,   263,   263,   263,   340,   340,     6,   263,   340,   340,
       7,   260,   261,   232,     7,     6,   334,   324,   234,   236,
     236,   236,   236,   236,   229,   324,   324,   324,   324,   260,
     228,   324,   324,   329,   330,   235,   232,     6,     6,   242,
       6,   324,   235,   324,   338,   229,   231,     6,     6,     6,
     235,   235,   115,   282,   282,   330,     6,   235,   235,     6,
       6,   330,   172,   281,   235,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   330,   236,     4,   263,   229,
     231,   234,   234,   234,   234,   234,   234,   234,     6,   263,
       6,   236,   330,   330,   330,     4,     6,   330,   330,   330,
     330,   330,   330,   330,   330,   235,   235,     7,     6,     7,
     324,   324,   324,   235,   235,   234,   236,   234,   236,   234,
     236,   235,   230,     6,   324,   330,   324,     6,     6,     6,
       6,   324,   327,   236,     5,   330,   235,   235,   235,   235,
     235,   235,   235,   330,     6,   333,   235,   324,   231,     6,
       6,   168,   324,   324,   324,     6,     6,     7,   338,   286,
     286,   234,     6,   263,   340,   340,     6,   263,   340,   340,
       6,   260,   261,   337,   324,   337,     4,     4,   184,     6,
     263,   263,     6,   263,   263,   338,   324,     6,     4,   335,
       6,   231,   334,     6,     6,     6,     6,   229,   229,   229,
     229,   330,   246,   324,   234,   234,   234,   236,   247,   324,
       4,   337,   234,   330,   338,     7,     7,   324,   324,   327,
       6,     6,     6,   324,   324,     6,    88,     6,   324,     5,
       6,   235,   324,   324,   324,   324,   324,   324,   324,   235,
       6,   281,     6,   324,     6,     6,     6,     6,     6,     6,
       4,     6,     6,   333,   333,   324,   324,   338,   236,   229,
     234,   236,   285,   285,   327,     6,   300,   327,     6,   301,
     327,     6,   302,   324,   324,   236,   234,   229,   236,   234,
       6,     6,   329,   327,   327,   327,   327,   327,   219,   327,
       6,   236,   324,     6,     6,   330,   234,   236,     8,   236,
     229,   235,   324,   338,   234,   312,   312,   330,     6,   263,
     263,     6,   263,   263,   330,   229,   263,   263,   235,   330,
     338,   235,   324,   338,   338,     6,     6,     6,     6,     6,
       6,     7,     6,   232,     6,   229,   234,   324,   324,   330,
     235,   234,   236,     6,   324,   267,   270,   235,   235,   236,
     236,   236,   236,   235,   236,     5,   329,   263,   263,   234,
     234,   234,   234,   234,   324,     6,   235,   236,   236,   235,
       6,     6,   235,   324,   236,   236,   234,   235,   234,   235,
     234,   235,   236,   231,     6,   330,     7,   235,   324,   236,
     234,   234,   234,   234,   234,   234,     6,   236,   167,   324,
     324,   333,     6,     6,   338,   236,   236,   236,     6,     6,
       6,     6,     6,   272,   324,   332,   340,   334,   170,   250,
     324,   234,   234,   329,   324,     6,   234,   273,   275,   330,
     330,     6,     6,     6,     6,   324,     6,     6,   236,   324,
     324,   324,   324,   324,   236,   329,   126,   127,   132,   319,
     126,   127,   319,   333,   285,   234,   236,   324,   327,   309,
     324,   327,   309,   324,   327,   309,     6,   234,   236,   330,
     286,   236,     6,   333,   327,   327,   327,   327,   327,   324,
     236,   236,   236,   229,   235,     6,   234,   236,     7,     7,
     236,     6,   235,   324,   324,   236,   324,   236,   236,   269,
     268,   236,   235,   234,   234,   234,   234,   234,   236,   235,
     327,   330,     6,   235,   327,     6,   236,   236,   324,   236,
     234,   236,   236,   234,   236,   236,   234,   236,   330,     6,
     122,   236,   297,   235,   236,   234,   234,   234,   234,   234,
       6,     6,     6,   286,   324,   338,   342,   247,   229,   234,
       6,   235,   234,   273,   273,   324,   324,   324,   324,   324,
     324,     6,   327,     6,   327,     6,     6,   236,     6,   303,
     324,     6,     6,   304,   324,     6,     6,   305,   324,     6,
     236,   324,   309,   286,     6,   333,   333,   333,   333,   327,
     333,   312,     7,   228,   236,   253,   324,   329,   324,   236,
     236,   234,   234,   234,   234,   234,   234,   234,   234,   235,
     236,   235,   236,   235,   236,     6,     6,   236,   236,   298,
     236,   236,   236,   236,   234,   236,   236,   338,   229,     6,
     235,   229,   236,   236,   324,   324,   324,   324,   324,   324,
     327,   327,   309,     6,   306,   309,     6,   307,   309,     6,
     308,   309,     6,     6,     6,     6,   333,     6,     6,   251,
     337,   256,   235,     6,   236,   263,   234,   234,   234,   234,
     234,   234,   236,   235,   236,   235,   236,   235,   236,   236,
     234,   236,   235,   329,     6,   324,   324,   324,   324,   324,
     324,     6,   309,     6,   309,     6,   309,     6,   337,     6,
     254,   337,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   234,   236,     6,     6,     6,     6,     6,     6,
     337,     6
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
#line 213 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 225 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 228 "Gmsh.y"
    {
      // FIXME: when changing to OpenCASCADE, get maxTags from GEO_Internals and
      // add that info in OCC_Internals - same in the other direction
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 235 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 237 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 238 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 239 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 240 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 241 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 242 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 243 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 244 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 245 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 246 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 247 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 248 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 249 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 254 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 258 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 265 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 270 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 275 "Gmsh.y"
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
#line 289 "Gmsh.y"
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
#line 302 "Gmsh.y"
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
#line 315 "Gmsh.y"
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
#line 343 "Gmsh.y"
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
#line 357 "Gmsh.y"
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
#line 370 "Gmsh.y"
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
#line 383 "Gmsh.y"
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
#line 401 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 415 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 417 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 422 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 424 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 429 "Gmsh.y"
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
#line 533 "Gmsh.y"
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
#line 543 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 552 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 559 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 569 "Gmsh.y"
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
#line 578 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 587 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 594 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 604 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 612 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 622 "Gmsh.y"
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
#line 641 "Gmsh.y"
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
#line 660 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 666 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 673 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 674 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 675 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 676 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 677 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 681 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 682 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 688 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 688 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 689 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 689 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 76:
#line 698 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 77:
#line 703 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 78:
#line 709 "Gmsh.y"
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
#line 771 "Gmsh.y"
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
#line 788 "Gmsh.y"
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
#line 817 "Gmsh.y"
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
#line 846 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 851 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 856 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 861 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 866 "Gmsh.y"
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
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 88:
#line 883 "Gmsh.y"
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
#line 912 "Gmsh.y"
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
#line 941 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 91:
#line 946 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 951 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 956 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 94:
#line 964 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 95:
#line 973 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 96:
#line 979 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 985 "Gmsh.y"
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
#line 998 "Gmsh.y"
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
#line 1011 "Gmsh.y"
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
#line 1026 "Gmsh.y"
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
#line 1043 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 102:
#line 1049 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 103:
#line 1055 "Gmsh.y"
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
#line 1068 "Gmsh.y"
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
#line 1081 "Gmsh.y"
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
#line 1096 "Gmsh.y"
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
#line 1113 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 108:
#line 1119 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 109:
#line 1128 "Gmsh.y"
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
#line 1146 "Gmsh.y"
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
#line 1164 "Gmsh.y"
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
#line 1173 "Gmsh.y"
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
#line 1185 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 114:
#line 1190 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 115:
#line 1198 "Gmsh.y"
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
#line 1218 "Gmsh.y"
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
#line 1241 "Gmsh.y"
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
#line 1252 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 119:
#line 1260 "Gmsh.y"
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
#line 1282 "Gmsh.y"
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
#line 1305 "Gmsh.y"
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
#line 1343 "Gmsh.y"
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
#line 1364 "Gmsh.y"
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
#line 1376 "Gmsh.y"
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
#line 1394 "Gmsh.y"
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
#line 1403 "Gmsh.y"
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
#line 1412 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 131:
#line 1414 "Gmsh.y"
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
#line 1432 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 133:
#line 1434 "Gmsh.y"
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
#line 1450 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 135:
#line 1452 "Gmsh.y"
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
#line 1468 "Gmsh.y"
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
#line 1477 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 138:
#line 1479 "Gmsh.y"
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
#line 1493 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 141:
#line 1501 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 142:
#line 1507 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 143:
#line 1512 "Gmsh.y"
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
#line 1543 "Gmsh.y"
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
#line 1554 "Gmsh.y"
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
#line 1569 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 151:
#line 1585 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 152:
#line 1593 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 153:
#line 1602 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 154:
#line 1610 "Gmsh.y"
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
#line 1628 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 156:
#line 1632 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 157:
#line 1638 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 158:
#line 1646 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 159:
#line 1650 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 160:
#line 1656 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 161:
#line 1664 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 162:
#line 1668 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 163:
#line 1674 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 164:
#line 1682 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 165:
#line 1686 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 166:
#line 1692 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 167:
#line 1700 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 168:
#line 1704 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 169:
#line 1710 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 170:
#line 1714 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 171:
#line 1721 "Gmsh.y"
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
#line 1742 "Gmsh.y"
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
#line 1756 "Gmsh.y"
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

  case 174:
#line 1777 "Gmsh.y"
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

  case 175:
#line 1791 "Gmsh.y"
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
          double a1 = (param.size() >= 5) ? param[4] : 0.;
          double a2 = (param.size() >= 6) ? param[5] : 2.*M_PI;
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

  case 176:
#line 1825 "Gmsh.y"
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
          double a1 = (param.size() >= 6) ? param[5] : 0.;
          double a2 = (param.size() >= 7) ? param[6] : 2.*M_PI;
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

  case 177:
#line 1862 "Gmsh.y"
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

  case 178:
#line 1876 "Gmsh.y"
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

  case 179:
#line 1891 "Gmsh.y"
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

  case 180:
#line 1910 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1919 "Gmsh.y"
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

  case 182:
#line 1933 "Gmsh.y"
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

  case 183:
#line 1948 "Gmsh.y"
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

  case 184:
#line 1962 "Gmsh.y"
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

  case 185:
#line 1981 "Gmsh.y"
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

  case 186:
#line 1991 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 1997 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2003 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2010 "Gmsh.y"
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

  case 190:
#line 2037 "Gmsh.y"
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

  case 191:
#line 2052 "Gmsh.y"
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

  case 192:
#line 2072 "Gmsh.y"
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

  case 193:
#line 2093 "Gmsh.y"
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

  case 194:
#line 2114 "Gmsh.y"
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

  case 195:
#line 2135 "Gmsh.y"
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

  case 196:
#line 2157 "Gmsh.y"
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

  case 197:
#line 2179 "Gmsh.y"
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

  case 198:
#line 2200 "Gmsh.y"
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

  case 199:
#line 2223 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 200:
#line 2233 "Gmsh.y"
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

  case 201:
#line 2253 "Gmsh.y"
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

  case 202:
#line 2268 "Gmsh.y"
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

  case 203:
#line 2282 "Gmsh.y"
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

  case 204:
#line 2297 "Gmsh.y"
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

  case 205:
#line 2312 "Gmsh.y"
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

  case 206:
#line 2327 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 207:
#line 2336 "Gmsh.y"
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

  case 208:
#line 2379 "Gmsh.y"
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

  case 209:
#line 2422 "Gmsh.y"
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

  case 210:
#line 2465 "Gmsh.y"
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

  case 211:
#line 2513 "Gmsh.y"
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

  case 212:
#line 2530 "Gmsh.y"
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

  case 213:
#line 2548 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("TODO OCC Symmetry");
      }
      else{
        SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 214:
#line 2558 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("TODO OCC Dilate");
      }
      else{
        DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 215:
#line 2568 "Gmsh.y"
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("TODO OCC Dilate");
      }
      else{
        DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 216:
#line 2578 "Gmsh.y"
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

  case 217:
#line 2641 "Gmsh.y"
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

  case 218:
#line 2652 "Gmsh.y"
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

  case 219:
#line 2667 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2668 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 221:
#line 2673 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 222:
#line 2677 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 223:
#line 2681 "Gmsh.y"
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
            if(factory == "OpenCASCADE"){
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

  case 224:
#line 2710 "Gmsh.y"
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
            if(factory == "OpenCASCADE"){
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

  case 225:
#line 2739 "Gmsh.y"
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
            if(factory == "OpenCASCADE"){
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

  case 226:
#line 2768 "Gmsh.y"
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
            if(factory == "OpenCASCADE"){
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

  case 227:
#line 2802 "Gmsh.y"
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

  case 228:
#line 2824 "Gmsh.y"
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

  case 229:
#line 2851 "Gmsh.y"
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

  case 230:
#line 2873 "Gmsh.y"
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

  case 231:
#line 2895 "Gmsh.y"
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

  case 232:
#line 2917 "Gmsh.y"
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

  case 233:
#line 2973 "Gmsh.y"
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

  case 234:
#line 2997 "Gmsh.y"
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

  case 235:
#line 3022 "Gmsh.y"
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

  case 236:
#line 3047 "Gmsh.y"
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

  case 237:
#line 3160 "Gmsh.y"
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

  case 238:
#line 3179 "Gmsh.y"
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

  case 239:
#line 3222 "Gmsh.y"
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
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          DeleteShape(TheShape.Type, TheShape.Num);
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 240:
#line 3243 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 241:
#line 3249 "Gmsh.y"
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

  case 242:
#line 3264 "Gmsh.y"
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

  case 243:
#line 3292 "Gmsh.y"
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

  case 244:
#line 3309 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 245:
#line 3318 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 246:
#line 3332 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 247:
#line 3346 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3352 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3358 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 250:
#line 3367 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 3376 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 252:
#line 3385 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 253:
#line 3399 "Gmsh.y"
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

  case 254:
#line 3461 "Gmsh.y"
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

  case 255:
#line 3479 "Gmsh.y"
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

  case 256:
#line 3496 "Gmsh.y"
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

  case 257:
#line 3511 "Gmsh.y"
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

  case 258:
#line 3540 "Gmsh.y"
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

  case 259:
#line 3552 "Gmsh.y"
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

  case 260:
#line 3576 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 261:
#line 3580 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 262:
#line 3585 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 263:
#line 3593 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 264:
#line 3598 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 265:
#line 3604 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 266:
#line 3609 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 267:
#line 3615 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 268:
#line 3623 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 269:
#line 3627 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 270:
#line 3631 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 271:
#line 3637 "Gmsh.y"
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

  case 272:
#line 3696 "Gmsh.y"
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

  case 273:
#line 3712 "Gmsh.y"
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

  case 274:
#line 3729 "Gmsh.y"
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

  case 275:
#line 3746 "Gmsh.y"
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

  case 276:
#line 3768 "Gmsh.y"
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

  case 277:
#line 3790 "Gmsh.y"
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

  case 278:
#line 3825 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3833 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 3841 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 281:
#line 3847 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3854 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 3861 "Gmsh.y"
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

  case 284:
#line 3881 "Gmsh.y"
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

  case 285:
#line 3907 "Gmsh.y"
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

  case 286:
#line 3919 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 287:
#line 3931 "Gmsh.y"
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

  case 288:
#line 3961 "Gmsh.y"
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

  case 289:
#line 3992 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 290:
#line 4000 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 291:
#line 4006 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 292:
#line 4014 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 4020 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 294:
#line 4028 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 4034 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 296:
#line 4042 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 4048 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 298:
#line 4055 "Gmsh.y"
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

  case 299:
#line 4082 "Gmsh.y"
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

  case 300:
#line 4101 "Gmsh.y"
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

  case 301:
#line 4120 "Gmsh.y"
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

  case 302:
#line 4146 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 303:
#line 4153 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 304:
#line 4160 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4167 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 4195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 4202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 311:
#line 4209 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 312:
#line 4215 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 313:
#line 4222 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 4228 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 315:
#line 4235 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4241 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 317:
#line 4248 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 4254 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 319:
#line 4261 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 4267 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 321:
#line 4274 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4280 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 323:
#line 4287 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4293 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 325:
#line 4300 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4306 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 327:
#line 4313 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 328:
#line 4319 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 329:
#line 4330 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 4333 "Gmsh.y"
    {
    ;}
    break;

  case 331:
#line 4339 "Gmsh.y"
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

  case 332:
#line 4351 "Gmsh.y"
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

  case 333:
#line 4371 "Gmsh.y"
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

  case 334:
#line 4395 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 335:
#line 4399 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 336:
#line 4403 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 337:
#line 4407 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 338:
#line 4411 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 339:
#line 4415 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 340:
#line 4421 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 341:
#line 4427 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 342:
#line 4431 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 343:
#line 4435 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 344:
#line 4439 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 345:
#line 4443 "Gmsh.y"
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

  case 346:
#line 4462 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 347:
#line 4474 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 348:
#line 4475 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 349:
#line 4476 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 350:
#line 4477 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 351:
#line 4478 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 352:
#line 4482 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 353:
#line 4483 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 354:
#line 4484 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 355:
#line 4489 "Gmsh.y"
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

  case 356:
#line 4522 "Gmsh.y"
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

  case 357:
#line 4549 "Gmsh.y"
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

  case 358:
#line 4571 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 359:
#line 4575 "Gmsh.y"
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

  case 360:
#line 4590 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 361:
#line 4594 "Gmsh.y"
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

  case 362:
#line 4610 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 363:
#line 4614 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 364:
#line 4619 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 365:
#line 4623 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 366:
#line 4629 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 367:
#line 4633 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 368:
#line 4640 "Gmsh.y"
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
    ;}
    break;

  case 369:
#line 4657 "Gmsh.y"
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

  case 370:
#line 4713 "Gmsh.y"
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

  case 371:
#line 4783 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 372:
#line 4788 "Gmsh.y"
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

  case 373:
#line 4855 "Gmsh.y"
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

  case 374:
#line 4891 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 375:
#line 4899 "Gmsh.y"
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

  case 376:
#line 4942 "Gmsh.y"
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

  case 377:
#line 4981 "Gmsh.y"
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

  case 378:
#line 5002 "Gmsh.y"
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

  case 379:
#line 5034 "Gmsh.y"
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

  case 380:
#line 5061 "Gmsh.y"
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

  case 381:
#line 5087 "Gmsh.y"
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

  case 382:
#line 5113 "Gmsh.y"
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

  case 383:
#line 5139 "Gmsh.y"
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

  case 384:
#line 5165 "Gmsh.y"
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

  case 385:
#line 5186 "Gmsh.y"
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

  case 386:
#line 5214 "Gmsh.y"
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

  case 387:
#line 5242 "Gmsh.y"
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

  case 388:
#line 5270 "Gmsh.y"
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

  case 389:
#line 5298 "Gmsh.y"
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

  case 390:
#line 5326 "Gmsh.y"
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

  case 391:
#line 5365 "Gmsh.y"
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

  case 392:
#line 5404 "Gmsh.y"
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

  case 393:
#line 5425 "Gmsh.y"
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

  case 394:
#line 5446 "Gmsh.y"
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

  case 395:
#line 5467 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 396:
#line 5473 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 397:
#line 5479 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 398:
#line 5491 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 399:
#line 5495 "Gmsh.y"
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

  case 400:
#line 5505 "Gmsh.y"
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

  case 401:
#line 5539 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 402:
#line 5540 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 403:
#line 5541 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 404:
#line 5546 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 405:
#line 5552 "Gmsh.y"
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

  case 406:
#line 5564 "Gmsh.y"
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

  case 407:
#line 5582 "Gmsh.y"
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

  case 408:
#line 5609 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 409:
#line 5610 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 410:
#line 5611 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5612 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 412:
#line 5613 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 413:
#line 5614 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5615 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5616 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5618 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 417:
#line 5624 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 418:
#line 5625 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 419:
#line 5626 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 420:
#line 5627 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 421:
#line 5628 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5629 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5630 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5631 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5632 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5633 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5634 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 428:
#line 5635 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5636 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5637 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 431:
#line 5638 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5639 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5640 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5641 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5642 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5643 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 437:
#line 5644 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5645 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 439:
#line 5646 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5647 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5648 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5649 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5650 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 444:
#line 5651 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 445:
#line 5652 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 446:
#line 5653 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5654 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 448:
#line 5655 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 449:
#line 5656 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 450:
#line 5665 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 451:
#line 5666 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 452:
#line 5667 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 453:
#line 5668 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 454:
#line 5669 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 455:
#line 5670 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 456:
#line 5671 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 457:
#line 5672 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 458:
#line 5673 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 459:
#line 5674 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 460:
#line 5675 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 461:
#line 5680 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 462:
#line 5682 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 463:
#line 5688 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 464:
#line 5693 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 465:
#line 5698 "Gmsh.y"
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

  case 466:
#line 5715 "Gmsh.y"
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

  case 467:
#line 5733 "Gmsh.y"
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

  case 468:
#line 5751 "Gmsh.y"
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

  case 469:
#line 5769 "Gmsh.y"
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

  case 470:
#line 5787 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 471:
#line 5792 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 472:
#line 5798 "Gmsh.y"
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

  case 473:
#line 5813 "Gmsh.y"
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

  case 474:
#line 5832 "Gmsh.y"
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

  case 475:
#line 5852 "Gmsh.y"
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

  case 476:
#line 5872 "Gmsh.y"
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

  case 477:
#line 5892 "Gmsh.y"
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

  case 478:
#line 5915 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 479:
#line 5920 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 480:
#line 5925 "Gmsh.y"
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

  case 481:
#line 5935 "Gmsh.y"
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

  case 482:
#line 5945 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 483:
#line 5950 "Gmsh.y"
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

  case 484:
#line 5961 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 485:
#line 5970 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 486:
#line 5975 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 487:
#line 5980 "Gmsh.y"
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

  case 488:
#line 6007 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 489:
#line 6011 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 490:
#line 6015 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 491:
#line 6019 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 492:
#line 6023 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 493:
#line 6030 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 494:
#line 6034 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 495:
#line 6038 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 496:
#line 6042 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 497:
#line 6049 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 498:
#line 6054 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 499:
#line 6061 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 500:
#line 6066 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 501:
#line 6070 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 502:
#line 6075 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 503:
#line 6079 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 504:
#line 6087 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 505:
#line 6098 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 506:
#line 6102 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 507:
#line 6114 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 508:
#line 6122 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 509:
#line 6130 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 510:
#line 6137 "Gmsh.y"
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

  case 511:
#line 6147 "Gmsh.y"
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

  case 512:
#line 6176 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 513:
#line 6180 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 514:
#line 6184 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 515:
#line 6188 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 516:
#line 6192 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 517:
#line 6196 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 518:
#line 6200 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 519:
#line 6204 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 520:
#line 6208 "Gmsh.y"
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

  case 521:
#line 6237 "Gmsh.y"
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

  case 522:
#line 6266 "Gmsh.y"
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

  case 523:
#line 6295 "Gmsh.y"
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

  case 524:
#line 6325 "Gmsh.y"
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

  case 525:
#line 6338 "Gmsh.y"
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

  case 526:
#line 6351 "Gmsh.y"
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

  case 527:
#line 6364 "Gmsh.y"
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

  case 528:
#line 6376 "Gmsh.y"
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

  case 529:
#line 6386 "Gmsh.y"
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

  case 530:
#line 6396 "Gmsh.y"
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

  case 531:
#line 6406 "Gmsh.y"
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

  case 532:
#line 6418 "Gmsh.y"
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

  case 533:
#line 6431 "Gmsh.y"
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

  case 534:
#line 6443 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 535:
#line 6447 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 536:
#line 6451 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 537:
#line 6455 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 538:
#line 6459 "Gmsh.y"
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

  case 539:
#line 6477 "Gmsh.y"
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

  case 540:
#line 6495 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 541:
#line 6503 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 542:
#line 6511 "Gmsh.y"
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

  case 543:
#line 6540 "Gmsh.y"
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

  case 544:
#line 6550 "Gmsh.y"
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

  case 545:
#line 6569 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 546:
#line 6574 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 547:
#line 6578 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 548:
#line 6582 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 549:
#line 6594 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 550:
#line 6598 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 551:
#line 6610 "Gmsh.y"
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

  case 552:
#line 6627 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 553:
#line 6637 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 554:
#line 6641 "Gmsh.y"
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

  case 555:
#line 6656 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 556:
#line 6661 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 557:
#line 6668 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 558:
#line 6672 "Gmsh.y"
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

  case 559:
#line 6685 "Gmsh.y"
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

  case 560:
#line 6699 "Gmsh.y"
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

  case 561:
#line 6713 "Gmsh.y"
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

  case 562:
#line 6727 "Gmsh.y"
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

  case 563:
#line 6741 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 564:
#line 6749 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 565:
#line 6760 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 566:
#line 6764 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 567:
#line 6768 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 568:
#line 6776 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 569:
#line 6782 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 570:
#line 6788 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 571:
#line 6796 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 572:
#line 6804 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 573:
#line 6811 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 574:
#line 6819 "Gmsh.y"
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

  case 575:
#line 6834 "Gmsh.y"
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

  case 576:
#line 6848 "Gmsh.y"
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

  case 577:
#line 6862 "Gmsh.y"
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

  case 578:
#line 6874 "Gmsh.y"
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

  case 579:
#line 6890 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 580:
#line 6899 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 581:
#line 6908 "Gmsh.y"
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

  case 582:
#line 6918 "Gmsh.y"
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

  case 583:
#line 6929 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 584:
#line 6937 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 585:
#line 6945 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 586:
#line 6949 "Gmsh.y"
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

  case 587:
#line 6968 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6975 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 589:
#line 6981 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 590:
#line 6988 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 591:
#line 6995 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 592:
#line 6997 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 593:
#line 7008 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 594:
#line 7013 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 595:
#line 7019 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 596:
#line 7028 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 597:
#line 7041 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 598:
#line 7044 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 599:
#line 7048 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14548 "Gmsh.tab.cpp"
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


#line 7051 "Gmsh.y"


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

int NEWPOINT(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals())
    tag = GModel::current()->getGEOInternals()->MaxPointNum + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(0) + 1);
  return tag;
}

int NEWLINE(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxLineNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(1) + 1);
  return tag;
}

int NEWLINELOOP(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxLineLoopNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  return tag;
}

int NEWSURFACE(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxSurfaceNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(2) + 1);
  return tag;
}

int NEWSURFACELOOP(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxSurfaceLoopNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  return tag;
}

int NEWVOLUME(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxVolumeNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(3) + 1);
  return tag;
}

int NEWREG(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    tag = GModel::current()->getGEOInternals()->MaxLineNum;
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxLineLoopNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxSurfaceNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxSurfaceLoopNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxVolumeNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxPhysicalNum);
    tag += 1;
  }
  if(GModel::current()->getOCCInternals()){
    for(int i = -2; i < 4; i++)
      tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(i) + 1);
  }
  return tag;
}

